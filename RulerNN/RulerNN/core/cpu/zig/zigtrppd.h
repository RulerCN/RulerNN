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

#ifndef __CORE_CPU_ZIGTRPPD_H__
#define __CORE_CPU_ZIGTRPPD_H__

#include "../simd.h"


namespace core
{
	namespace cpu
	{
		// Function template zigtrp_block_m
		template <class T> constexpr size_t zigtrp_block_m(void);

		// Function template zigtrp_block_n
		template <class T> constexpr size_t zigtrp_block_n(void);

		// Function template zigtrp_block
		template <class T> inline T* zigtrp_block(T* b, const T* a, size_t lda);

		// Function template zigtrp_tiny
		template <class T> inline T* zigtrp_tiny(T* b, const T* a, size_t lda, size_t m, size_t n);

	#if defined(__AVX2__) || defined(__AVX__)

		// Specialize for double

		template <>
		constexpr size_t zigtrp_block_m<double>(void)
		{
			return static_cast<size_t>(4);
		}

		template <>
		constexpr size_t zigtrp_block_n<double>(void)
		{
			return static_cast<size_t>(4);
		}

		// Function template zigtrp_block

		template <>
		inline double* zigtrp_block<double>(double* b, const double* a, size_t lda)
		{
			const double* ptr_a0 = a;
			const double* ptr_a1 = a + lda;
			const double* ptr_a2 = a + lda * 2;
			const double* ptr_a3 = a + lda * 3;
			__m256d ymm_a0 = _mm256_castpd128_pd256(_mm_loadu_pd(ptr_a0));
			__m256d ymm_a1 = _mm256_castpd128_pd256(_mm_loadu_pd(ptr_a1));
			__m256d ymm_a2 = _mm256_castpd128_pd256(_mm_loadu_pd(ptr_a0 + 2));
			__m256d ymm_a3 = _mm256_castpd128_pd256(_mm_loadu_pd(ptr_a1 + 2));
			__m256d ymm_b0 = _mm256_insertf128_pd(ymm_a0, _mm_loadu_pd(ptr_a2), 1);
			__m256d ymm_b1 = _mm256_insertf128_pd(ymm_a1, _mm_loadu_pd(ptr_a3), 1);
			__m256d ymm_b2 = _mm256_insertf128_pd(ymm_a2, _mm_loadu_pd(ptr_a2 + 2), 1);
			__m256d ymm_b3 = _mm256_insertf128_pd(ymm_a3, _mm_loadu_pd(ptr_a3 + 2), 1);
			ymm_a0 = _mm256_shuffle_pd(ymm_b0, ymm_b1, _MM_SHUFFLE(0, 0, 0, 0));
			ymm_a1 = _mm256_shuffle_pd(ymm_b0, ymm_b1, _MM_SHUFFLE(0, 0, 3, 3));
			ymm_a2 = _mm256_shuffle_pd(ymm_b2, ymm_b3, _MM_SHUFFLE(0, 0, 0, 0));
			ymm_a3 = _mm256_shuffle_pd(ymm_b2, ymm_b3, _MM_SHUFFLE(0, 0, 3, 3));
			_mm256_storeu_pd(b,          ymm_a0);
			_mm256_storeu_pd(b + 0x0004, ymm_a1);
			_mm256_storeu_pd(b + 0x0008, ymm_a2);
			_mm256_storeu_pd(b + 0x000C, ymm_a3);
			return b + 0x0010;
		}

		// Function template zigtrp_tiny

		template <>
		inline double* zigtrp_tiny<double>(double* b, const double* a, size_t lda, size_t m, size_t n)
		{
			__m256d ymm_a = _mm256_setzero_pd();
			for (size_t i = 0; i < n; ++i)
			{
				switch (m)
				{
				case 4: reinterpret_cast<double*>(&ymm_a)[3] = a[lda * 3]; [[fallthrough]];
				case 3: reinterpret_cast<double*>(&ymm_a)[2] = a[lda * 2]; [[fallthrough]];
				case 2: reinterpret_cast<double*>(&ymm_a)[1] = a[lda];     [[fallthrough]];
				case 1: reinterpret_cast<double*>(&ymm_a)[0] = a[0];       [[fallthrough]];
				}
				_mm256_storeu_pd(b, ymm_a);
				a += 1;
				b += 4;
			}
			return b;
		}

	#elif defined(__SSE4_2__) || defined(__SSE4_1__) || defined(__SSSE3__) || defined(__SSE3__) || defined(__SSE2__) || defined(__SSE__)

		// Specialize for double

		template <>
		constexpr size_t zigtrp_block_m<double>(void)
		{
			return static_cast<size_t>(2);
		}

		template <>
		constexpr size_t zigtrp_block_n<double>(void)
		{
			return static_cast<size_t>(2);
		}

		// Function template zigtrp_block

		template <>
		inline double* zigtrp_block<double>(double* b, const double* a, size_t lda)
		{
			__m128d xmm_a0 = _mm_loadu_pd(a);
			__m128d xmm_a1 = _mm_loadu_pd(a + lda);
			__m128d xmm_b0 = _mm_shuffle_pd(xmm_a0, xmm_a1, _MM_SHUFFLE(0, 0, 0, 0));
			__m128d xmm_b1 = _mm_shuffle_pd(xmm_a0, xmm_a1, _MM_SHUFFLE(0, 0, 3, 3));
			_mm_storeu_pd(b,          xmm_b0);
			_mm_storeu_pd(b + 0x0002, xmm_b1);
			return b + 0x0004;
		}

		// Function template zigtrp_tiny

		template <>
		inline double* zigtrp_tiny<double>(double* b, const double* a, size_t lda, size_t m, size_t n)
		{
			__m128d xmm_a = _mm_setzero_pd();
			for (size_t i = 0; i < n; ++i)
			{
				switch (m)
				{
				case 2: reinterpret_cast<double*>(&xmm_a)[1] = a[lda]; [[fallthrough]];
				case 1: reinterpret_cast<double*>(&xmm_a)[0] = a[0];   [[fallthrough]];
				}
				_mm_storeu_pd(b, xmm_a);
				a += 1;
				b += 2;
			}
			return b;
		}

	#endif

	} // namespace cpu

} // namespace core

#endif
