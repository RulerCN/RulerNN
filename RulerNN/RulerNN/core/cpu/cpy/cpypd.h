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

#ifndef __CORE_CPU_CPYPD_H__
#define __CORE_CPU_CPYPD_H__

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

		// Specialize for double

		template <>
		constexpr size_t cpy_block_m<double>(void)
		{
			return static_cast<size_t>(4);
		}

		template <>
		constexpr size_t cpy_block_n<double>(void)
		{
			return static_cast<size_t>(4);
		}

		template <>
		inline void cpy_block<double>(double* b, size_t ldb, const double* a, size_t lda)
		{
			const __m256d ymm_a0 = _mm256_loadu_pd(a);
			const __m256d ymm_a1 = _mm256_loadu_pd(a + lda);
			const __m256d ymm_a2 = _mm256_loadu_pd(a + lda * 2);
			const __m256d ymm_a3 = _mm256_loadu_pd(a + lda * 3);
			_mm256_storeu_pd(b,           ymm_a0);
			_mm256_storeu_pd(b + ldb,     ymm_a1);
			_mm256_storeu_pd(b + ldb * 2, ymm_a2);
			_mm256_storeu_pd(b + ldb * 3, ymm_a3);
		}

		template <>
		inline void cpy_tiny<double>(double* b, size_t ldb, const double* a, size_t lda, size_t m, size_t n)
		{
			for (size_t i = 0; i < m; ++i)
			{
				switch (n)
				{
				case 4: b[3] = a[3]; [[fallthrough]];
				case 3: b[2] = a[2]; [[fallthrough]];
				case 2: b[1] = a[1]; [[fallthrough]];
				case 1: b[0] = a[0]; [[fallthrough]];
				}
				a += lda;
				b += ldb;
			}
		}

	#elif defined(__SSE4_2__) || defined(__SSE4_1__) || defined(__SSSE3__) || defined(__SSE3__) || defined(__SSE2__)

		// Specialize for double

		template <>
		constexpr size_t cpy_block_m<double>(void)
		{
			return static_cast<size_t>(2);
		}

		template <>
		constexpr size_t cpy_block_n<double>(void)
		{
			return static_cast<size_t>(2);
		}

		template <>
		inline void cpy_block<double>(double* b, size_t ldb, const double* a, size_t lda)
		{
			const __m128d xmm_a0 = _mm_loadu_pd(a);
			const __m128d xmm_a1 = _mm_loadu_pd(a + lda);
			_mm_storeu_pd(b,       xmm_a0);
			_mm_storeu_pd(b + ldb, xmm_a1);
		}

		template <>
		inline void cpy_tiny<double>(double* b, size_t ldb, const double* a, size_t lda, size_t m, size_t n)
		{
			for (size_t i = 0; i < m; ++i)
			{
				switch (n)
				{
				case 2: b[1] = a[1]; [[fallthrough]];
				case 1: b[0] = a[0]; [[fallthrough]];
				}
				a += lda;
				b += ldb;
			}
		}

	#endif

	} // namespace cpu

} // namespace core

#endif
