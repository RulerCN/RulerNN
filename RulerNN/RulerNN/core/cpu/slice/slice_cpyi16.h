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

#ifndef __CORE_CPU_SLICE_CPYI16_H__
#define __CORE_CPU_SLICE_CPYI16_H__

#include "../simd.h"


namespace core
{
	namespace cpu
	{
		// Function template slice_cpy_block_m
		template <class T> constexpr size_t slice_cpy_block_m(void);

		// Function template slice_cpy_block_n
		template <class T> constexpr size_t slice_cpy_block_n(void);

		// Function template slice_cpy_block
		template <class T> inline void slice_cpy_block(T* b, size_t ldb, const T* a, size_t lda);

		// Function template slice_cpy_panel
		template <class T> inline void slice_cpy_panel(T* b, size_t ldb, const T* a, size_t lda, size_t m);

		// Function template slice_cpy_tiny
		template <class T> inline void slice_cpy_tiny(T* b, size_t ldb, const T* a, size_t lda, size_t m, size_t n);

	#if defined(__AVX2__) || defined(__AVX__)

		// Specialize for signed short

		template <>
		constexpr size_t slice_cpy_block_m<signed short>(void)
		{
			return static_cast<size_t>(8);
		}

		template <>
		constexpr size_t slice_cpy_block_n<signed short>(void)
		{
			return static_cast<size_t>(16);
		}

		// Function template slice_cpy_block
		template <>
		inline void slice_cpy_block<signed short>(signed short* b, size_t ldb, const signed short* a, size_t lda)
		{
			const __m256i ymm_a0 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a));
			const __m256i ymm_a1 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + lda));
			const __m256i ymm_a2 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + lda * 2));
			const __m256i ymm_a3 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + lda * 3));
			const __m256i ymm_a4 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + lda * 4));
			const __m256i ymm_a5 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + lda * 5));
			const __m256i ymm_a6 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + lda * 6));
			const __m256i ymm_a7 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + lda * 7));
			_mm256_stream_si256(reinterpret_cast<__m256i*>(b),           ymm_a0);
			_mm256_stream_si256(reinterpret_cast<__m256i*>(b + ldb),     ymm_a1);
			_mm256_stream_si256(reinterpret_cast<__m256i*>(b + ldb * 2), ymm_a2);
			_mm256_stream_si256(reinterpret_cast<__m256i*>(b + ldb * 3), ymm_a3);
			_mm256_stream_si256(reinterpret_cast<__m256i*>(b + ldb * 4), ymm_a4);
			_mm256_stream_si256(reinterpret_cast<__m256i*>(b + ldb * 5), ymm_a5);
			_mm256_stream_si256(reinterpret_cast<__m256i*>(b + ldb * 6), ymm_a6);
			_mm256_stream_si256(reinterpret_cast<__m256i*>(b + ldb * 7), ymm_a7);
		}

		// Function template slice_cpy_panel
		template <>
		inline void slice_cpy_panel<signed short>(signed short* b, size_t ldb, const signed short* a, size_t lda, size_t m)
		{
			for (size_t i = 0; i < m; ++i)
			{
				const __m256i ymm_a = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + lda * i));
				_mm256_stream_si256(reinterpret_cast<__m256i*>(b + ldb * i), ymm_a);
			}
		}

		// Function template slice_cpy_tiny
		template <>
		inline void slice_cpy_tiny<signed short>(signed short* b, size_t ldb, const signed short* a, size_t lda, size_t m, size_t n)
		{
			__m256i ymm_a = _mm256_setzero_si256();
			for (size_t i = 0; i < m; ++i)
			{
				switch (n)
				{
				case 16: reinterpret_cast<signed short*>(&ymm_a)[15] = a[15]; [[fallthrough]];
				case 15: reinterpret_cast<signed short*>(&ymm_a)[14] = a[14]; [[fallthrough]];
				case 14: reinterpret_cast<signed short*>(&ymm_a)[13] = a[13]; [[fallthrough]];
				case 13: reinterpret_cast<signed short*>(&ymm_a)[12] = a[12]; [[fallthrough]];
				case 12: reinterpret_cast<signed short*>(&ymm_a)[11] = a[11]; [[fallthrough]];
				case 11: reinterpret_cast<signed short*>(&ymm_a)[10] = a[10]; [[fallthrough]];
				case 10: reinterpret_cast<signed short*>(&ymm_a)[9]  = a[9];  [[fallthrough]];
				case 9:  reinterpret_cast<signed short*>(&ymm_a)[8]  = a[8];  [[fallthrough]];
				case 8:  reinterpret_cast<signed short*>(&ymm_a)[7]  = a[7];  [[fallthrough]];
				case 7:  reinterpret_cast<signed short*>(&ymm_a)[6]  = a[6];  [[fallthrough]];
				case 6:  reinterpret_cast<signed short*>(&ymm_a)[5]  = a[5];  [[fallthrough]];
				case 5:  reinterpret_cast<signed short*>(&ymm_a)[4]  = a[4];  [[fallthrough]];
				case 4:  reinterpret_cast<signed short*>(&ymm_a)[3]  = a[3];  [[fallthrough]];
				case 3:  reinterpret_cast<signed short*>(&ymm_a)[2]  = a[2];  [[fallthrough]];
				case 2:  reinterpret_cast<signed short*>(&ymm_a)[1]  = a[1];  [[fallthrough]];
				case 1:  reinterpret_cast<signed short*>(&ymm_a)[0]  = a[0];  [[fallthrough]];
				}
				_mm256_stream_si256(reinterpret_cast<__m256i*>(b), ymm_a);
				a += lda;
				b += ldb;
			}
		}

	#elif defined(__SSE4_2__) || defined(__SSE4_1__) || defined(__SSSE3__) || defined(__SSE3__) || defined(__SSE2__) || defined(__SSE__)

		// Specialize for signed short

		template <>
		constexpr size_t slice_cpy_block_m<signed short>(void)
		{
			return static_cast<size_t>(8);
		}

		template <>
		constexpr size_t slice_cpy_block_n<signed short>(void)
		{
			return static_cast<size_t>(8);
		}

		// Function template slice_cpy_block
		template <>
		inline void slice_cpy_block<signed short>(signed short* b, size_t ldb, const signed short* a, size_t lda)
		{
			const __m128i xmm_a0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a));
			const __m128i xmm_a1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda));
			const __m128i xmm_a2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 2));
			const __m128i xmm_a3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 3));
			const __m128i xmm_a4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 4));
			const __m128i xmm_a5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 5));
			const __m128i xmm_a6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 6));
			const __m128i xmm_a7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 7));
			_mm_stream_si128(reinterpret_cast<__m128i*>(b),           xmm_a0);
			_mm_stream_si128(reinterpret_cast<__m128i*>(b + ldb),     xmm_a1);
			_mm_stream_si128(reinterpret_cast<__m128i*>(b + ldb * 2), xmm_a2);
			_mm_stream_si128(reinterpret_cast<__m128i*>(b + ldb * 3), xmm_a3);
			_mm_stream_si128(reinterpret_cast<__m128i*>(b + ldb * 4), xmm_a4);
			_mm_stream_si128(reinterpret_cast<__m128i*>(b + ldb * 5), xmm_a5);
			_mm_stream_si128(reinterpret_cast<__m128i*>(b + ldb * 6), xmm_a6);
			_mm_stream_si128(reinterpret_cast<__m128i*>(b + ldb * 7), xmm_a7);
		}

		// Function template slice_cpy_panel
		template <>
		inline void slice_cpy_panel<signed short>(signed short* b, size_t ldb, const signed short* a, size_t lda, size_t m)
		{
			for (size_t i = 0; i < m; ++i)
			{
				const __m128i xmm_a = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * i));
				_mm_stream_si128(reinterpret_cast<__m128i*>(b + ldb * i), xmm_a);
			}
		}

		// Function template slice_cpy_tiny
		template <>
		inline void slice_cpy_tiny<signed short>(signed short* b, size_t ldb, const signed short* a, size_t lda, size_t m, size_t n)
		{
			__m128i xmm_a = _mm_setzero_si128();
			for (size_t i = 0; i < m; ++i)
			{
				switch (n)
				{
				case 8: reinterpret_cast<signed short*>(&xmm_a)[7] = a[7]; [[fallthrough]];
				case 7: reinterpret_cast<signed short*>(&xmm_a)[6] = a[6]; [[fallthrough]];
				case 6: reinterpret_cast<signed short*>(&xmm_a)[5] = a[5]; [[fallthrough]];
				case 5: reinterpret_cast<signed short*>(&xmm_a)[4] = a[4]; [[fallthrough]];
				case 4: reinterpret_cast<signed short*>(&xmm_a)[3] = a[3]; [[fallthrough]];
				case 3: reinterpret_cast<signed short*>(&xmm_a)[2] = a[2]; [[fallthrough]];
				case 2: reinterpret_cast<signed short*>(&xmm_a)[1] = a[1]; [[fallthrough]];
				case 1: reinterpret_cast<signed short*>(&xmm_a)[0] = a[0]; [[fallthrough]];
				}
				_mm_stream_si128(reinterpret_cast<__m128i*>(b), xmm_a);
				a += lda;
				b += ldb;
			}
		}

	#endif

	} // namespace cpu

} // namespace core

#endif
