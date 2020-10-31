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

#ifndef __CORE_CPU_CPYI8_H__
#define __CORE_CPU_CPYI8_H__

#include "../simd.h"


namespace core
{
	namespace cpu
	{
		// Function template cpy_block_m
		template <class T> constexpr size_t cpy_block_m(void);

		// Function template cpy_block_n
		template <class T> constexpr size_t cpy_block_n(void);

		// Function template cpy_block
		template <class T> inline void cpy_block(T* b, size_t ldb, const T* a, size_t lda);

		// Function template cpy_tiny
		template <class T> inline void cpy_tiny(T* b, size_t ldb, const T* a, size_t lda, size_t m, size_t n);

	#if defined(__AVX2__) || defined(__AVX__)

		// Specialize for signed char

		template <>
		constexpr size_t cpy_block_m<signed char>(void)
		{
			return static_cast<size_t>(16);
		}

		template <>
		constexpr size_t cpy_block_n<signed char>(void)
		{
			return static_cast<size_t>(32);
		}

		// Function template cpy_block

		template <>
		inline void cpy_block<signed char>(signed char* b, size_t ldb, const signed char* a, size_t lda)
		{
			const __m256i ymm_a0 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a));
			const __m256i ymm_a1 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + lda));
			const __m256i ymm_a2 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + lda * 2));
			const __m256i ymm_a3 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + lda * 3));
			const __m256i ymm_a4 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + lda * 4));
			const __m256i ymm_a5 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + lda * 5));
			const __m256i ymm_a6 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + lda * 6));
			const __m256i ymm_a7 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + lda * 7));
			const __m256i ymm_a8 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + lda * 8));
			const __m256i ymm_a9 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + lda * 9));
			const __m256i ymm_aa = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + lda * 10));
			const __m256i ymm_ab = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + lda * 11));
			const __m256i ymm_ac = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + lda * 12));
			const __m256i ymm_ad = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + lda * 13));
			const __m256i ymm_ae = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + lda * 14));
			const __m256i ymm_af = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + lda * 15));
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b),            ymm_a0);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb),      ymm_a1);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 2),  ymm_a2);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 3),  ymm_a3);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 4),  ymm_a4);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 5),  ymm_a5);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 6),  ymm_a6);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 7),  ymm_a7);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 8),  ymm_a8);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 9),  ymm_a9);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 10), ymm_aa);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 11), ymm_ab);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 12), ymm_ac);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 13), ymm_ad);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 14), ymm_ae);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 15), ymm_af);
		}

		// Function template cpy_tiny

		template <>
		inline void cpy_tiny<signed char>(signed char* b, size_t ldb, const signed char* a, size_t lda, size_t m, size_t n)
		{
			for (size_t i = 0; i < m; ++i)
			{
				switch (n)
				{
				case 32: b[31] = a[31]; [[fallthrough]];
				case 31: b[30] = a[30]; [[fallthrough]];
				case 30: b[29] = a[29]; [[fallthrough]];
				case 29: b[28] = a[28]; [[fallthrough]];
				case 28: b[27] = a[27]; [[fallthrough]];
				case 27: b[26] = a[26]; [[fallthrough]];
				case 26: b[25] = a[25]; [[fallthrough]];
				case 25: b[24] = a[24]; [[fallthrough]];
				case 24: b[23] = a[23]; [[fallthrough]];
				case 23: b[22] = a[22]; [[fallthrough]];
				case 22: b[21] = a[21]; [[fallthrough]];
				case 21: b[20] = a[20]; [[fallthrough]];
				case 20: b[19] = a[19]; [[fallthrough]];
				case 19: b[18] = a[18]; [[fallthrough]];
				case 18: b[17] = a[17]; [[fallthrough]];
				case 17: b[16] = a[16]; [[fallthrough]];
				case 16: b[15] = a[15]; [[fallthrough]];
				case 15: b[14] = a[14]; [[fallthrough]];
				case 14: b[13] = a[13]; [[fallthrough]];
				case 13: b[12] = a[12]; [[fallthrough]];
				case 12: b[11] = a[11]; [[fallthrough]];
				case 11: b[10] = a[10]; [[fallthrough]];
				case 10: b[9]  = a[9];  [[fallthrough]];
				case 9:  b[8]  = a[8];  [[fallthrough]];
				case 8:  b[7]  = a[7];  [[fallthrough]];
				case 7:  b[6]  = a[6];  [[fallthrough]];
				case 6:  b[5]  = a[5];  [[fallthrough]];
				case 5:  b[4]  = a[4];  [[fallthrough]];
				case 4:  b[3]  = a[3];  [[fallthrough]];
				case 3:  b[2]  = a[2];  [[fallthrough]];
				case 2:  b[1]  = a[1];  [[fallthrough]];
				case 1:  b[0]  = a[0];  [[fallthrough]];
				}
				a += lda;
				b += ldb;
			}
		}

	#elif defined(__SSE4_2__) || defined(__SSE4_1__) || defined(__SSSE3__) || defined(__SSE3__) || defined(__SSE2__) || defined(__SSE__)

		// Specialize for signed char

		template <>
		constexpr size_t cpy_block_m<signed char>(void)
		{
			return static_cast<size_t>(16);
		}

		template <>
		constexpr size_t cpy_block_n<signed char>(void)
		{
			return static_cast<size_t>(16);
		}

		// Function template cpy_block

		template <>
		inline void cpy_block<signed char>(signed char* b, size_t ldb, const signed char* a, size_t lda)
		{
			const __m128i xmm_a0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a));
			const __m128i xmm_a1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda));
			const __m128i xmm_a2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 2));
			const __m128i xmm_a3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 3));
			const __m128i xmm_a4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 4));
			const __m128i xmm_a5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 5));
			const __m128i xmm_a6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 6));
			const __m128i xmm_a7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 7));
			const __m128i xmm_a8 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 8));
			const __m128i xmm_a9 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 9));
			const __m128i xmm_aa = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 10));
			const __m128i xmm_ab = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 11));
			const __m128i xmm_ac = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 12));
			const __m128i xmm_ad = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 13));
			const __m128i xmm_ae = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 14));
			const __m128i xmm_af = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 15));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b),            xmm_a0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b + ldb),      xmm_a1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b + ldb * 2),  xmm_a2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b + ldb * 3),  xmm_a3);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b + ldb * 4),  xmm_a4);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b + ldb * 5),  xmm_a5);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b + ldb * 6),  xmm_a6);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b + ldb * 7),  xmm_a7);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b + ldb * 8),  xmm_a8);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b + ldb * 9),  xmm_a9);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b + ldb * 10), xmm_aa);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b + ldb * 11), xmm_ab);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b + ldb * 12), xmm_ac);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b + ldb * 13), xmm_ad);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b + ldb * 14), xmm_ae);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b + ldb * 15), xmm_af);
		}

		// Function template cpy_tiny

		template <>
		inline void cpy_tiny<signed char>(signed char* b, size_t ldb, const signed char* a, size_t lda, size_t m, size_t n)
		{
			for (size_t i = 0; i < m; ++i)
			{
				switch (n)
				{
				case 16: b[15] = a[15]; [[fallthrough]];
				case 15: b[14] = a[14]; [[fallthrough]];
				case 14: b[13] = a[13]; [[fallthrough]];
				case 13: b[12] = a[12]; [[fallthrough]];
				case 12: b[11] = a[11]; [[fallthrough]];
				case 11: b[10] = a[10]; [[fallthrough]];
				case 10: b[9]  = a[9];  [[fallthrough]];
				case 9:  b[8]  = a[8];  [[fallthrough]];
				case 8:  b[7]  = a[7];  [[fallthrough]];
				case 7:  b[6]  = a[6];  [[fallthrough]];
				case 6:  b[5]  = a[5];  [[fallthrough]];
				case 5:  b[4]  = a[4];  [[fallthrough]];
				case 4:  b[3]  = a[3];  [[fallthrough]];
				case 3:  b[2]  = a[2];  [[fallthrough]];
				case 2:  b[1]  = a[1];  [[fallthrough]];
				case 1:  b[0]  = a[0];  [[fallthrough]];
				}
				a += lda;
				b += ldb;
			}
		}

	#endif

	} // namespace cpu

} // namespace core

#endif
