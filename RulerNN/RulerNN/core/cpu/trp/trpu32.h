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

#ifndef __CORE_CPU_TRPU32_H__
#define __CORE_CPU_TRPU32_H__

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

	#ifdef __AVX2__

		// Specialize for unsigned int

		template <>
		constexpr size_t trp_block_m<unsigned int>(void)
		{
			return static_cast<size_t>(8);
		}

		template <>
		constexpr size_t trp_block_n<unsigned int>(void)
		{
			return static_cast<size_t>(8);
		}

		template <>
		inline void trp_block<unsigned int>(unsigned int* b, size_t ldb, const unsigned int* a, size_t lda)
		{
			const unsigned int* ptr_a0 = a;
			const unsigned int* ptr_a1 = a + lda;
			const unsigned int* ptr_a2 = a + lda * 2;
			const unsigned int* ptr_a3 = a + lda * 3;
			const unsigned int* ptr_a4 = a + lda * 4;
			const unsigned int* ptr_a5 = a + lda * 5;
			const unsigned int* ptr_a6 = a + lda * 6;
			const unsigned int* ptr_a7 = a + lda * 7;
			__m256i ymm_a0 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_a0)));
			__m256i ymm_a1 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_a1)));
			__m256i ymm_a2 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_a2)));
			__m256i ymm_a3 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_a3)));
			__m256i ymm_a4 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_a0) + 1));
			__m256i ymm_a5 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_a2) + 1));
			__m256i ymm_a6 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_a2) + 1));
			__m256i ymm_a7 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_a3) + 1));
			__m256i ymm_b0 = _mm256_insertf128_si256(ymm_a0, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_a4)), 1);
			__m256i ymm_b1 = _mm256_insertf128_si256(ymm_a1, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_a5)), 1);
			__m256i ymm_b2 = _mm256_insertf128_si256(ymm_a2, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_a6)), 1);
			__m256i ymm_b3 = _mm256_insertf128_si256(ymm_a3, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_a7)), 1);
			__m256i ymm_b4 = _mm256_insertf128_si256(ymm_a4, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_a4) + 1), 1);
			__m256i ymm_b5 = _mm256_insertf128_si256(ymm_a5, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_a5) + 1), 1);
			__m256i ymm_b6 = _mm256_insertf128_si256(ymm_a6, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_a6) + 1), 1);
			__m256i ymm_b7 = _mm256_insertf128_si256(ymm_a7, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_a7) + 1), 1);
			ymm_a0 = _mm256_unpacklo_epi32(ymm_b0, ymm_b1);
			ymm_a1 = _mm256_unpacklo_epi32(ymm_b2, ymm_b3);
			ymm_a2 = _mm256_unpackhi_epi32(ymm_b0, ymm_b1);
			ymm_a3 = _mm256_unpackhi_epi32(ymm_b2, ymm_b3);
			ymm_a4 = _mm256_unpacklo_epi32(ymm_b4, ymm_b5);
			ymm_a5 = _mm256_unpacklo_epi32(ymm_b6, ymm_b7);
			ymm_a6 = _mm256_unpackhi_epi32(ymm_b4, ymm_b5);
			ymm_a7 = _mm256_unpackhi_epi32(ymm_b6, ymm_b7);
			ymm_b0 = _mm256_unpacklo_epi64(ymm_a0, ymm_a1);
			ymm_b1 = _mm256_unpackhi_epi64(ymm_a0, ymm_a1);
			ymm_b2 = _mm256_unpacklo_epi64(ymm_a2, ymm_a3);
			ymm_b3 = _mm256_unpackhi_epi64(ymm_a2, ymm_a3);
			ymm_b4 = _mm256_unpacklo_epi64(ymm_a4, ymm_a5);
			ymm_b5 = _mm256_unpackhi_epi64(ymm_a4, ymm_a5);
			ymm_b6 = _mm256_unpacklo_epi64(ymm_a6, ymm_a7);
			ymm_b7 = _mm256_unpackhi_epi64(ymm_a6, ymm_a7);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b),           ymm_b0);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb),     ymm_b1);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 2), ymm_b2);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 3), ymm_b3);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 4), ymm_b4);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 5), ymm_b5);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 6), ymm_b6);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 7), ymm_b7);
		}

		template <>
		inline void trp_tiny<unsigned int>(unsigned int* b, size_t ldb, const unsigned int* a, size_t lda, size_t m, size_t n)
		{
			for (size_t i = 0; i < n; ++i)
			{
				switch (m)
				{
				case 8: b[7] = a[lda * 7]; [[fallthrough]];
				case 7: b[6] = a[lda * 6]; [[fallthrough]];
				case 6: b[5] = a[lda * 5]; [[fallthrough]];
				case 5: b[4] = a[lda * 4]; [[fallthrough]];
				case 4: b[3] = a[lda * 3]; [[fallthrough]];
				case 3: b[2] = a[lda * 2]; [[fallthrough]];
				case 2: b[1] = a[lda];     [[fallthrough]];
				case 1: b[0] = a[0];       [[fallthrough]];
				}
				a += 1;
				b += ldb;
			}
		}

	#elif defined(__AVX__) || defined(__SSE4_2__) || defined(__SSE4_1__) || defined(__SSSE3__) || defined(__SSE3__) || defined(__SSE2__)

		// Specialize for unsigned int

		template <>
		constexpr size_t trp_block_m<unsigned int>(void)
		{
			return static_cast<size_t>(4);
		}

		template <>
		constexpr size_t trp_block_n<unsigned int>(void)
		{
			return static_cast<size_t>(4);
		}

		template <>
		inline void trp_block<unsigned int>(unsigned int* b, size_t ldb, const unsigned int* a, size_t lda)
		{
			__m128i xmm_a0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda));
			__m128i xmm_a2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 2));
			__m128i xmm_a3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 3));
			__m128i xmm_b0 = _mm_unpacklo_epi32(xmm_a0, xmm_a1);
			__m128i xmm_b1 = _mm_unpacklo_epi32(xmm_a2, xmm_a3);
			__m128i xmm_b2 = _mm_unpackhi_epi32(xmm_a0, xmm_a1);
			__m128i xmm_b3 = _mm_unpackhi_epi32(xmm_a2, xmm_a3);
			xmm_a0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
			xmm_a1 = _mm_unpackhi_epi64(xmm_b0, xmm_b1);
			xmm_a2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
			xmm_a3 = _mm_unpackhi_epi64(xmm_b2, xmm_b3);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b),           xmm_a0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b + ldb),     xmm_a1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b + ldb * 2), xmm_a2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b + ldb * 3), xmm_a3);
		}

		template <>
		inline void trp_tiny<unsigned int>(unsigned int* b, size_t ldb, const unsigned int* a, size_t lda, size_t m, size_t n)
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

	#endif

	} // namespace cpu

} // namespace core

#endif
