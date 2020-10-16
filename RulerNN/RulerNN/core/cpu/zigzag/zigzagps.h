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

#ifndef __CORE_CPU_ZIGZAGPS_H__
#define __CORE_CPU_ZIGZAGPS_H__

#include "../simd.h"

namespace core
{
	namespace cpu
	{
		// Function template zigzag_block_m
		template <class T> constexpr size_t zigzag_block_m(void);

		// Function template zigzag_block_n
		template <class T> constexpr size_t zigzag_block_n(void);

		// Function template zigzag_block
		template <class T> inline void zigzag_block(T* dst, const T* src, size_t src_rs);

	#if defined(__AVX2__) || defined(__AVX__)

		// Specialize for float

		template <>
		constexpr size_t zigzag_block_m<float>(void)
		{
			return static_cast<size_t>(8);
		}

		template <>
		constexpr size_t zigzag_block_n<float>(void)
		{
			return static_cast<size_t>(8);
		}

		// Function template zigzag_block

		template <>
		inline float* zigzag_block<float>(float* b, const float* a, size_t lda)
		{
			const __m256 ymm_a0 = _mm256_loadu_ps(a);
			const __m256 ymm_a1 = _mm256_loadu_ps(a + lda);
			const __m256 ymm_a2 = _mm256_loadu_ps(a + lda * 2);
			const __m256 ymm_a3 = _mm256_loadu_ps(a + lda * 3);
			const __m256 ymm_a4 = _mm256_loadu_ps(a + lda * 4);
			const __m256 ymm_a5 = _mm256_loadu_ps(a + lda * 5);
			const __m256 ymm_a6 = _mm256_loadu_ps(a + lda * 6);
			const __m256 ymm_a7 = _mm256_loadu_ps(a + lda * 7);
			_mm256_storeu_ps(b,      ymm_a0);
			_mm256_storeu_ps(b + 8,  ymm_a1);
			_mm256_storeu_ps(b + 16, ymm_a2);
			_mm256_storeu_ps(b + 24, ymm_a3);
			_mm256_storeu_ps(b + 32, ymm_a4);
			_mm256_storeu_ps(b + 40, ymm_a5);
			_mm256_storeu_ps(b + 48, ymm_a6);
			_mm256_storeu_ps(b + 56, ymm_a7);
			return b + 64;
		}

		// Function template zigzag_tiny

		template <>
		inline float* zigzag_tiny<float>(float* b, const float* a, size_t lda, size_t m, size_t n)
		{
			__m256 ymm_a = _mm256_setzero_ps();
			for (size_t i = 0; i < m; ++i)
			{
				switch (n)
				{
				case 8: reinterpret_cast<float*>(&ymm_a)[7] = a[7];
				case 7: reinterpret_cast<float*>(&ymm_a)[6] = a[6];
				case 6: reinterpret_cast<float*>(&ymm_a)[5] = a[5];
				case 5: reinterpret_cast<float*>(&ymm_a)[4] = a[4];
				case 4: reinterpret_cast<float*>(&ymm_a)[3] = a[3];
				case 3: reinterpret_cast<float*>(&ymm_a)[2] = a[2];
				case 2: reinterpret_cast<float*>(&ymm_a)[1] = a[1];
				case 1: reinterpret_cast<float*>(&ymm_a)[0] = a[0];
				}
				_mm256_storeu_ps(b, ymm_a);
				a += lda;
				b += 8;
			}
			return b;
		}

	#endif

	} // namespace cpu

} // namespace core

#endif
