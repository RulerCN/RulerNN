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

#ifndef __CORE_CPU_PACKTI16_H__
#define __CORE_CPU_PACKTI16_H__

#include "../simd.h"


namespace core
{
	namespace cpu
	{
		// Function template packt_block_m
		template <class T> constexpr size_t packt_block_m(void);

		// Function template packt_block_n
		template <class T> constexpr size_t packt_block_n(void);

		// Function template packt_block
		template <class T> inline void packt_block(T* b, size_t ldb, const T* a, size_t lda);

		// Function template packt_tiny
		template <class T> inline void packt_tiny(T* b, size_t ldb, const T* a, size_t lda, size_t m, size_t n);

	#if defined(__AVX2__)

		// Specialize for signed short

		template <>
		constexpr size_t packt_block_m<signed short>(void)
		{
			return static_cast<size_t>(16);
		}

		template <>
		constexpr size_t packt_block_n<signed short>(void)
		{
			return static_cast<size_t>(8);
		}

		// Function template packt_block

		template <>
		inline void packt_block<signed short>(signed short* b, size_t ldb, const signed short* a, size_t lda)
		{
			__m256i ymm_a0 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(a)));
			__m256i ymm_a1 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda)));
			__m256i ymm_a2 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 2)));
			__m256i ymm_a3 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 3)));
			__m256i ymm_a4 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 4)));
			__m256i ymm_a5 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 5)));
			__m256i ymm_a6 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 6)));
			__m256i ymm_a7 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 7)));
			__m256i ymm_b0 = _mm256_insertf128_si256(ymm_a0, _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 8 )), 1);
			__m256i ymm_b1 = _mm256_insertf128_si256(ymm_a1, _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 9 )), 1);
			__m256i ymm_b2 = _mm256_insertf128_si256(ymm_a2, _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 10)), 1);
			__m256i ymm_b3 = _mm256_insertf128_si256(ymm_a3, _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 11)), 1);
			__m256i ymm_b4 = _mm256_insertf128_si256(ymm_a4, _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 12)), 1);
			__m256i ymm_b5 = _mm256_insertf128_si256(ymm_a5, _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 13)), 1);
			__m256i ymm_b6 = _mm256_insertf128_si256(ymm_a6, _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 14)), 1);
			__m256i ymm_b7 = _mm256_insertf128_si256(ymm_a7, _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 15)), 1);
			ymm_a0 = _mm256_unpacklo_epi16(ymm_b0, ymm_b1);
			ymm_a1 = _mm256_unpacklo_epi16(ymm_b2, ymm_b3);
			ymm_a2 = _mm256_unpacklo_epi16(ymm_b4, ymm_b5);
			ymm_a3 = _mm256_unpacklo_epi16(ymm_b6, ymm_b7);
			ymm_a4 = _mm256_unpackhi_epi16(ymm_b0, ymm_b1);
			ymm_a5 = _mm256_unpackhi_epi16(ymm_b2, ymm_b3);
			ymm_a6 = _mm256_unpackhi_epi16(ymm_b4, ymm_b5);
			ymm_a7 = _mm256_unpackhi_epi16(ymm_b6, ymm_b7);
			ymm_b0 = _mm256_unpacklo_epi32(ymm_a0, ymm_a1);
			ymm_b1 = _mm256_unpacklo_epi32(ymm_a2, ymm_a3);
			ymm_b2 = _mm256_unpackhi_epi32(ymm_a0, ymm_a1);
			ymm_b3 = _mm256_unpackhi_epi32(ymm_a2, ymm_a3);
			ymm_b4 = _mm256_unpacklo_epi32(ymm_a4, ymm_a5);
			ymm_b5 = _mm256_unpacklo_epi32(ymm_a6, ymm_a7);
			ymm_b6 = _mm256_unpackhi_epi32(ymm_a4, ymm_a5);
			ymm_b7 = _mm256_unpackhi_epi32(ymm_a6, ymm_a7);
			ymm_a0 = _mm256_unpacklo_epi64(ymm_b0, ymm_b1);
			ymm_a1 = _mm256_unpackhi_epi64(ymm_b0, ymm_b1);
			ymm_a2 = _mm256_unpacklo_epi64(ymm_b2, ymm_b3);
			ymm_a3 = _mm256_unpackhi_epi64(ymm_b2, ymm_b3);
			ymm_a4 = _mm256_unpacklo_epi64(ymm_b4, ymm_b5);
			ymm_a5 = _mm256_unpackhi_epi64(ymm_b4, ymm_b5);
			ymm_a6 = _mm256_unpacklo_epi64(ymm_b6, ymm_b7);
			ymm_a7 = _mm256_unpackhi_epi64(ymm_b6, ymm_b7);
			_mm256_stream_si256(reinterpret_cast<__m256i*>(b),           ymm_a0);
			_mm256_stream_si256(reinterpret_cast<__m256i*>(b + ldb),     ymm_a1);
			_mm256_stream_si256(reinterpret_cast<__m256i*>(b + ldb * 2), ymm_a2);
			_mm256_stream_si256(reinterpret_cast<__m256i*>(b + ldb * 3), ymm_a3);
			_mm256_stream_si256(reinterpret_cast<__m256i*>(b + ldb * 4), ymm_a4);
			_mm256_stream_si256(reinterpret_cast<__m256i*>(b + ldb * 5), ymm_a5);
			_mm256_stream_si256(reinterpret_cast<__m256i*>(b + ldb * 6), ymm_a6);
			_mm256_stream_si256(reinterpret_cast<__m256i*>(b + ldb * 7), ymm_a7);
		}

		// Function template packt_tiny

		template <>
		inline void packt_tiny<signed short>(signed short* b, size_t ldb, const signed short* a, size_t lda, size_t m, size_t n)
		{
			__m256i ymm_a = _mm256_setzero_si256();
			for (size_t i = 0; i < n; ++i)
			{
				switch (m)
				{
				case 16: reinterpret_cast<signed short*>(&ymm_a)[15] = a[lda * 15]; [[fallthrough]];
				case 15: reinterpret_cast<signed short*>(&ymm_a)[14] = a[lda * 14]; [[fallthrough]];
				case 14: reinterpret_cast<signed short*>(&ymm_a)[13] = a[lda * 13]; [[fallthrough]];
				case 13: reinterpret_cast<signed short*>(&ymm_a)[12] = a[lda * 12]; [[fallthrough]];
				case 12: reinterpret_cast<signed short*>(&ymm_a)[11] = a[lda * 11]; [[fallthrough]];
				case 11: reinterpret_cast<signed short*>(&ymm_a)[10] = a[lda * 10]; [[fallthrough]];
				case 10: reinterpret_cast<signed short*>(&ymm_a)[9]  = a[lda * 9];  [[fallthrough]];
				case 9:  reinterpret_cast<signed short*>(&ymm_a)[8]  = a[lda * 8];  [[fallthrough]];
				case 8:  reinterpret_cast<signed short*>(&ymm_a)[7]  = a[lda * 7];  [[fallthrough]];
				case 7:  reinterpret_cast<signed short*>(&ymm_a)[6]  = a[lda * 6];  [[fallthrough]];
				case 6:  reinterpret_cast<signed short*>(&ymm_a)[5]  = a[lda * 5];  [[fallthrough]];
				case 5:  reinterpret_cast<signed short*>(&ymm_a)[4]  = a[lda * 4];  [[fallthrough]];
				case 4:  reinterpret_cast<signed short*>(&ymm_a)[3]  = a[lda * 3];  [[fallthrough]];
				case 3:  reinterpret_cast<signed short*>(&ymm_a)[2]  = a[lda * 2];  [[fallthrough]];
				case 2:  reinterpret_cast<signed short*>(&ymm_a)[1]  = a[lda];      [[fallthrough]];
				case 1:  reinterpret_cast<signed short*>(&ymm_a)[0]  = a[0];        [[fallthrough]];
				}
				_mm256_stream_si256(reinterpret_cast<__m256i*>(b), ymm_a);
				a += 1;
				b += ldb;
			}
		}

	#elif defined(__AVX__) || defined(__SSE4_2__) || defined(__SSE4_1__) || defined(__SSSE3__) || defined(__SSE3__) || defined(__SSE2__)

		// Specialize for signed short

		template <>
		constexpr size_t packt_block_m<signed short>(void)
		{
			return static_cast<size_t>(8);
		}

		template <>
		constexpr size_t packt_block_n<signed short>(void)
		{
			return static_cast<size_t>(8);
		}

		// Function template packt_block

		template <>
		inline void packt_block<signed short>(signed short* b, size_t ldb, const signed short* a, size_t lda)
		{
			__m128i xmm_a0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda));
			__m128i xmm_a2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 2));
			__m128i xmm_a3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 3));
			__m128i xmm_a4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 4));
			__m128i xmm_a5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 5));
			__m128i xmm_a6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 6));
			__m128i xmm_a7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 7));
			__m128i xmm_b0 = _mm_unpacklo_epi16(xmm_a0, xmm_a1);
			__m128i xmm_b1 = _mm_unpacklo_epi16(xmm_a2, xmm_a3);
			__m128i xmm_b2 = _mm_unpacklo_epi16(xmm_a4, xmm_a5);
			__m128i xmm_b3 = _mm_unpacklo_epi16(xmm_a6, xmm_a7);
			__m128i xmm_b4 = _mm_unpackhi_epi16(xmm_a0, xmm_a1);
			__m128i xmm_b5 = _mm_unpackhi_epi16(xmm_a2, xmm_a3);
			__m128i xmm_b6 = _mm_unpackhi_epi16(xmm_a4, xmm_a5);
			__m128i xmm_b7 = _mm_unpackhi_epi16(xmm_a6, xmm_a7);
			xmm_a0 = _mm_unpacklo_epi32(xmm_b0, xmm_b1);
			xmm_a1 = _mm_unpacklo_epi32(xmm_b2, xmm_b3);
			xmm_a2 = _mm_unpackhi_epi32(xmm_b0, xmm_b1);
			xmm_a3 = _mm_unpackhi_epi32(xmm_b2, xmm_b3);
			xmm_a4 = _mm_unpacklo_epi32(xmm_b4, xmm_b5);
			xmm_a5 = _mm_unpacklo_epi32(xmm_b6, xmm_b7);
			xmm_a6 = _mm_unpackhi_epi32(xmm_b4, xmm_b5);
			xmm_a7 = _mm_unpackhi_epi32(xmm_b6, xmm_b7);
			xmm_b0 = _mm_unpacklo_epi64(xmm_a0, xmm_a1);
			xmm_b1 = _mm_unpackhi_epi64(xmm_a0, xmm_a1);
			xmm_b2 = _mm_unpacklo_epi64(xmm_a2, xmm_a3);
			xmm_b3 = _mm_unpackhi_epi64(xmm_a2, xmm_a3);
			xmm_b4 = _mm_unpacklo_epi64(xmm_a4, xmm_a5);
			xmm_b5 = _mm_unpackhi_epi64(xmm_a4, xmm_a5);
			xmm_b6 = _mm_unpacklo_epi64(xmm_a6, xmm_a7);
			xmm_b7 = _mm_unpackhi_epi64(xmm_a6, xmm_a7);
			_mm_stream_si128(reinterpret_cast<__m128i*>(b),           xmm_b0);
			_mm_stream_si128(reinterpret_cast<__m128i*>(b + ldb),     xmm_b1);
			_mm_stream_si128(reinterpret_cast<__m128i*>(b + ldb * 2), xmm_b2);
			_mm_stream_si128(reinterpret_cast<__m128i*>(b + ldb * 3), xmm_b3);
			_mm_stream_si128(reinterpret_cast<__m128i*>(b + ldb * 4), xmm_b4);
			_mm_stream_si128(reinterpret_cast<__m128i*>(b + ldb * 5), xmm_b5);
			_mm_stream_si128(reinterpret_cast<__m128i*>(b + ldb * 6), xmm_b6);
			_mm_stream_si128(reinterpret_cast<__m128i*>(b + ldb * 7), xmm_b7);
		}

		// Function template packt_tiny

		template <>
		inline void packt_tiny<signed short>(signed short* b, size_t ldb, const signed short* a, size_t lda, size_t m, size_t n)
		{
			__m128i xmm_a = _mm_setzero_si128();
			for (size_t i = 0; i < n; ++i)
			{
				switch (m)
				{
				case 8: reinterpret_cast<signed short*>(&xmm_a)[7] = a[lda * 7]; [[fallthrough]];
				case 7: reinterpret_cast<signed short*>(&xmm_a)[6] = a[lda * 6]; [[fallthrough]];
				case 6: reinterpret_cast<signed short*>(&xmm_a)[5] = a[lda * 5]; [[fallthrough]];
				case 5: reinterpret_cast<signed short*>(&xmm_a)[4] = a[lda * 4]; [[fallthrough]];
				case 4: reinterpret_cast<signed short*>(&xmm_a)[3] = a[lda * 3]; [[fallthrough]];
				case 3: reinterpret_cast<signed short*>(&xmm_a)[2] = a[lda * 2]; [[fallthrough]];
				case 2: reinterpret_cast<signed short*>(&xmm_a)[1] = a[lda];     [[fallthrough]];
				case 1: reinterpret_cast<signed short*>(&xmm_a)[0] = a[0];       [[fallthrough]];
				}
				_mm_stream_si128(reinterpret_cast<__m128i*>(b), xmm_a);
				a += 1;
				b += ldb;
			}
		}

	#endif

	} // namespace cpu

} // namespace core

#endif
