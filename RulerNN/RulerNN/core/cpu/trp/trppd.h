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

#ifndef __CORE_CPU_TRPPD_H__
#define __CORE_CPU_TRPPD_H__

#include "../simd.h"


namespace core
{
	namespace cpu
	{
		// Function template trp_block_m
		template <class T> constexpr size_t trp_block_m(void);

		// Function template trp_block_n
		template <class T> constexpr size_t trp_block_n(void);

		// Function template trp_block
		template <class T> inline void trp_block(T* b, size_t ldb, const T* a, size_t lda);

		// Function template trp_tiny
		template <class T> inline void trp_tiny(T* b, size_t ldb, const T* a, size_t lda, size_t m, size_t n);

	#if defined(__AVX2__) || defined(__AVX__)

		// Specialize for double

		template <>
		constexpr size_t trp_block_m<double>(void)
		{
			return static_cast<size_t>(4);
		}

		template <>
		constexpr size_t trp_block_n<double>(void)
		{
			return static_cast<size_t>(4);
		}

		template <>
		inline void trp_block<double>(double* b, size_t ldb, const double* a, size_t lda)
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
			_mm256_storeu_pd(b,           ymm_a0);
			_mm256_storeu_pd(b + ldb,     ymm_a1);
			_mm256_storeu_pd(b + ldb * 2, ymm_a2);
			_mm256_storeu_pd(b + ldb * 3, ymm_a3);
		}

		template <>
		inline void trp_tiny<double>(double* b, size_t ldb, const double* a, size_t lda, size_t m, size_t n)
		{
			for (size_t i = 0; i < n; ++i)
			{
				switch (m)
				{
				case 4: b[3] = a[lda * 3]; [[fallthrough]];
				case 3: b[2] = a[lda * 2]; [[fallthrough]];
				case 2: b[1] = a[lda];     [[fallthrough]];
				case 1: b[0] = a[0];       [[fallthrough]];
				}
				a += 1;
				b += ldb;
			}
		}

	#elif defined(__SSE4_2__) || defined(__SSE4_1__) || defined(__SSSE3__) || defined(__SSE3__) || defined(__SSE2__)

		// Specialize for double

		template <>
		constexpr size_t trp_block_m<double>(void)
		{
			return static_cast<size_t>(2);
		}

		template <>
		constexpr size_t trp_block_n<double>(void)
		{
			return static_cast<size_t>(2);
		}

		template <>
		inline void trp_block<double>(double* b, size_t ldb, const double* a, size_t lda)
		{
			__m128d xmm_a0 = _mm_loadu_pd(a);
			__m128d xmm_a1 = _mm_loadu_pd(a + lda);
			__m128d xmm_b0 = _mm_shuffle_pd(xmm_a0, xmm_a1, _MM_SHUFFLE(0, 0, 0, 0));
			__m128d xmm_b1 = _mm_shuffle_pd(xmm_a0, xmm_a1, _MM_SHUFFLE(0, 0, 3, 3));
			_mm_storeu_pd(b,       xmm_b0);
			_mm_storeu_pd(b + ldb, xmm_b1);
		}

		template <>
		inline void trp_tiny<double>(double* b, size_t ldb, const double* a, size_t lda, size_t m, size_t n)
		{
			for (size_t i = 0; i < n; ++i)
			{
				switch (m)
				{
				case 2: b[1] = a[lda]; [[fallthrough]];
				case 1: b[0] = a[0];   [[fallthrough]];
				}
				a += 1;
				b += ldb;
			}
		}

	#endif

	} // namespace cpu

} // namespace core

#endif
