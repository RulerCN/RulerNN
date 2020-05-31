/*====================================================================
BSD 2-Clause License

Copyright (c) 2020, Ruler
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
====================================================================*/
#pragma once

#ifndef __CORE_CPU_SIMD_H__
#define __CORE_CPU_SIMD_H__

#include "define.h"

// Microsoft Visual Studio
#if defined(_MSC_VER)
#include <intrin.h>
// GNU GCC/G++.
#elif defined(__GNUC__) || defined(__GNUG__)
#include <cpuid.h>
#include <x86intrin.h>
#endif

namespace core
{
	static constexpr signed int EDX_MMX   = 0x00800000;
	static constexpr signed int EDX_SSE   = 0x02000000;
	static constexpr signed int EDX_SSE2  = 0x04000000;
	static constexpr signed int ECX_SSE3  = 0x00000001;
	static constexpr signed int ECX_SSSE3 = 0x00000200;
	static constexpr signed int ECX_SSE41 = 0x00080000;
	static constexpr signed int ECX_SSE42 = 0x00100000;

	// Class simd
	class simd
	{
	public:
		// Detects L2 cache size in KB.
		static void detect_l2_cache(void)
		{
			std::cout << "L2 cache size: " << l2_cache_size << " byte\n";
			l2_cache_size = static_cast<size_t>(get_cpuid_field(CPUF_L2Size)) * 1024;
			std::cout << "L2 cache size: " << l2_cache_size << " byte\n";
		}

		// Detects SIMD instructions.
		static void detect_simd(void)
		{
			simd_inst = CPU_INST_IA32;
			simd_inst |= detect_mmx();
			simd_inst |= detect_sse();
			simd_inst |= detect_avx();
			simd_inst |= detect_fma();
		}
	private:
		// Get supported features and CPU type.
		static void get_cpuid(int info[4], int type)
		{
		#if (defined(_MSC_VER) && (defined(_M_IX86) || defined(_M_X64)))
			__cpuid(info, type);
		#elif (defined(__GNUC__) && (defined(__i386__) || defined(__x86_64__)))
			__cpuid(type, info[0], info[1], info[2], info[3]);
		#else
			info[0] = info[1] = info[2] = info[3] = 0;
		#endif
		}

		// Get supported features and CPU type.
		static void get_cpuidex(int info[4], int type, int value)
		{
		#if (defined(_MSC_VER) && (defined(_M_IX86) || defined(_M_X64)))
			__cpuidex(info, type, value);
		#elif (defined(__GNUC__) && (defined(__i386__) || defined(__x86_64__)))
			__cpuid_count(type, value, info[0], info[1], info[2], info[3]);
		#else
			info[0] = info[1] = info[2] = info[3] = 0;
		#endif
		}

		// Get CPUID field.
		static unsigned int get_cpuid_field(unsigned int cpu_field)
		{
			signed int info[4] = { 0 };
			get_cpuidex(info, CPUIDFIELD_FID(cpu_field), CPUIDFIELD_FIDSUB(cpu_field));
			return CPUID_GETBITS32(info[CPUIDFIELD_REG(cpu_field)], CPUIDFIELD_POS(cpu_field), CPUIDFIELD_LEN(cpu_field));
		}

		// Detects MMX instructions.
		static signed int detect_mmx(void)
		{
			signed int inst = CPU_INST_IA32;
			signed int info[4] = { 0 };
			get_cpuid(info, 1);
			if (info[3] & EDX_MMX)
				inst |= CPU_INST_MMX;
			if (inst > CPU_INST_IA32)
			{
#			if defined(_WIN64)
				inst = CPU_INST_IA32;
#			else
				try
				{
					_mm_empty();
				}
				catch (...)
				{
					inst = CPU_INST_IA32;
				}
#			endif
			}
			return inst;
		}

		// Detects SSE instructions.
		static signed int detect_sse(void)
		{
			signed int inst = CPU_INST_IA32;
			signed int info[4] = { 0 };
			get_cpuid(info, 1);
			if (info[3] & EDX_SSE)
				inst |= CPU_INST_SSE;
			if (info[3] & EDX_SSE2)
				inst |= CPU_INST_SSE2;
			if (info[2] & ECX_SSE3)
				inst |= CPU_INST_SSE3;
			if (info[2] & ECX_SSSE3)
				inst |= CPU_INST_SSSE3;
			if (info[2] & ECX_SSE41)
				inst |= CPU_INST_SSE41;
			if (info[2] & ECX_SSE42)
				inst |= CPU_INST_SSE42;
			if (inst > CPU_INST_IA32)
			{
				try
				{
					__m128 m = _mm_setzero_ps();
					signed int* p = reinterpret_cast<signed int*>(&m);
					if (*p != 0)
						inst = CPU_INST_IA32;
				}
				catch (...)
				{
					inst = CPU_INST_IA32;
				}
			}
			return inst;
		}

		// Detects AVX instructions.
		static signed int detect_avx(void)
		{
			signed int inst = CPU_INST_IA32;
			if (get_cpuid_field(CPUF_AVX))
				inst |= CPU_INST_AVX;
			if (get_cpuid_field(CPUF_AVX2))
				inst |= CPU_INST_AVX2;
			if (inst > CPU_INST_IA32)
			{
				if (get_cpuid_field(CPUF_OSXSAVE))
				{
					if ((get_cpuid_field(CPUF_XFeatureSupportedMaskLo) & 6) != 6)
						inst = CPU_INST_IA32;
				}
			}
			return inst;
		}

		// Detects FMA instructions.
		static signed int detect_fma(void)
		{
			signed int inst = CPU_INST_IA32;
			if (get_cpuid_field(CPUF_FMA))
				inst |= CPU_INST_FMA;
			if (get_cpuid_field(CPUF_FMA4))
				inst |= CPU_INST_FMA4;
			return inst;
		}
	public:
		static signed int simd_inst;
		static size_t     l2_cache_size;
	};

	// Initialize static variables.
	signed int simd::simd_inst = CPU_INST_IA32;
	size_t simd::l2_cache_size = 0x00200000;

} // namespace core

#endif
