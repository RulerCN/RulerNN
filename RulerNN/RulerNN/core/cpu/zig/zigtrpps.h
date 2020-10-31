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

#ifndef __CORE_CPU_ZIGTRPPS_H__
#define __CORE_CPU_ZIGTRPPS_H__

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

		// Specialize for float

		template <>
		constexpr size_t zigtrp_block_m<float>(void)
		{
			return static_cast<size_t>(8);
		}

		template <>
		constexpr size_t zigtrp_block_n<float>(void)
		{
			return static_cast<size_t>(8);
		}

		// Function template zigtrp_block

		template <>
		inline float* zigtrp_block<float>(float* b, const float* a, size_t lda)
		{
			const float* ptr_a0 = a;
			const float* ptr_a1 = a + lda;
			const float* ptr_a2 = a + lda * 2;
			const float* ptr_a3 = a + lda * 3;
			const float* ptr_a4 = a + lda * 4;
			const float* ptr_a5 = a + lda * 5;
			const float* ptr_a6 = a + lda * 6;
			const float* ptr_a7 = a + lda * 7;
			__m256 ymm_a0 = _mm256_castps128_ps256(_mm_loadu_ps(ptr_a0));
			__m256 ymm_a1 = _mm256_castps128_ps256(_mm_loadu_ps(ptr_a1));
			__m256 ymm_a2 = _mm256_castps128_ps256(_mm_loadu_ps(ptr_a2));
			__m256 ymm_a3 = _mm256_castps128_ps256(_mm_loadu_ps(ptr_a3));
			__m256 ymm_a4 = _mm256_castps128_ps256(_mm_loadu_ps(ptr_a0 + 4));
			__m256 ymm_a5 = _mm256_castps128_ps256(_mm_loadu_ps(ptr_a1 + 4));
			__m256 ymm_a6 = _mm256_castps128_ps256(_mm_loadu_ps(ptr_a2 + 4));
			__m256 ymm_a7 = _mm256_castps128_ps256(_mm_loadu_ps(ptr_a3 + 4));
			__m256 ymm_b0 = _mm256_insertf128_ps(ymm_a0, _mm_loadu_ps(ptr_a4), 1);
			__m256 ymm_b1 = _mm256_insertf128_ps(ymm_a1, _mm_loadu_ps(ptr_a5), 1);
			__m256 ymm_b2 = _mm256_insertf128_ps(ymm_a2, _mm_loadu_ps(ptr_a6), 1);
			__m256 ymm_b3 = _mm256_insertf128_ps(ymm_a3, _mm_loadu_ps(ptr_a7), 1);
			__m256 ymm_b4 = _mm256_insertf128_ps(ymm_a4, _mm_loadu_ps(ptr_a4 + 4), 1);
			__m256 ymm_b5 = _mm256_insertf128_ps(ymm_a5, _mm_loadu_ps(ptr_a5 + 4), 1);
			__m256 ymm_b6 = _mm256_insertf128_ps(ymm_a6, _mm_loadu_ps(ptr_a6 + 4), 1);
			__m256 ymm_b7 = _mm256_insertf128_ps(ymm_a7, _mm_loadu_ps(ptr_a7 + 4), 1);
			ymm_a0 = _mm256_shuffle_ps(ymm_b0, ymm_b1, _MM_SHUFFLE(1, 0, 1, 0));
			ymm_a1 = _mm256_shuffle_ps(ymm_b2, ymm_b3, _MM_SHUFFLE(1, 0, 1, 0));
			ymm_a2 = _mm256_shuffle_ps(ymm_b0, ymm_b1, _MM_SHUFFLE(3, 2, 3, 2));
			ymm_a3 = _mm256_shuffle_ps(ymm_b2, ymm_b3, _MM_SHUFFLE(3, 2, 3, 2));
			ymm_a4 = _mm256_shuffle_ps(ymm_b4, ymm_b5, _MM_SHUFFLE(1, 0, 1, 0));
			ymm_a5 = _mm256_shuffle_ps(ymm_b6, ymm_b7, _MM_SHUFFLE(1, 0, 1, 0));
			ymm_a6 = _mm256_shuffle_ps(ymm_b4, ymm_b5, _MM_SHUFFLE(3, 2, 3, 2));
			ymm_a7 = _mm256_shuffle_ps(ymm_b6, ymm_b7, _MM_SHUFFLE(3, 2, 3, 2));
			ymm_b0 = _mm256_shuffle_ps(ymm_a0, ymm_a1, _MM_SHUFFLE(2, 0, 2, 0));
			ymm_b1 = _mm256_shuffle_ps(ymm_a0, ymm_a1, _MM_SHUFFLE(3, 1, 3, 1));
			ymm_b2 = _mm256_shuffle_ps(ymm_a2, ymm_a3, _MM_SHUFFLE(2, 0, 2, 0));
			ymm_b3 = _mm256_shuffle_ps(ymm_a2, ymm_a3, _MM_SHUFFLE(3, 1, 3, 1));
			ymm_b4 = _mm256_shuffle_ps(ymm_a4, ymm_a5, _MM_SHUFFLE(2, 0, 2, 0));
			ymm_b5 = _mm256_shuffle_ps(ymm_a4, ymm_a5, _MM_SHUFFLE(3, 1, 3, 1));
			ymm_b6 = _mm256_shuffle_ps(ymm_a6, ymm_a7, _MM_SHUFFLE(2, 0, 2, 0));
			ymm_b7 = _mm256_shuffle_ps(ymm_a6, ymm_a7, _MM_SHUFFLE(3, 1, 3, 1));
			_mm256_storeu_ps(b,          ymm_b0);
			_mm256_storeu_ps(b + 0x0008, ymm_b1);
			_mm256_storeu_ps(b + 0x0010, ymm_b2);
			_mm256_storeu_ps(b + 0x0018, ymm_b3);
			_mm256_storeu_ps(b + 0x0020, ymm_b4);
			_mm256_storeu_ps(b + 0x0028, ymm_b5);
			_mm256_storeu_ps(b + 0x0030, ymm_b6);
			_mm256_storeu_ps(b + 0x0038, ymm_b7);
			return b + 0x0040;
		}

		// Function template zigtrp_tiny

		template <>
		inline float* zigtrp_tiny<float>(float* b, const float* a, size_t lda, size_t m, size_t n)
		{
			__m256 ymm_a = _mm256_setzero_ps();
			for (size_t i = 0; i < n; ++i)
			{
				switch (m)
				{
				case 8: reinterpret_cast<float*>(&ymm_a)[7] = a[lda * 7]; [[fallthrough]];
				case 7: reinterpret_cast<float*>(&ymm_a)[6] = a[lda * 6]; [[fallthrough]];
				case 6: reinterpret_cast<float*>(&ymm_a)[5] = a[lda * 5]; [[fallthrough]];
				case 5: reinterpret_cast<float*>(&ymm_a)[4] = a[lda * 4]; [[fallthrough]];
				case 4: reinterpret_cast<float*>(&ymm_a)[3] = a[lda * 3]; [[fallthrough]];
				case 3: reinterpret_cast<float*>(&ymm_a)[2] = a[lda * 2]; [[fallthrough]];
				case 2: reinterpret_cast<float*>(&ymm_a)[1] = a[lda];     [[fallthrough]];
				case 1: reinterpret_cast<float*>(&ymm_a)[0] = a[0];       [[fallthrough]];
				}
				_mm256_storeu_ps(b, ymm_a);
				a += 1;
				b += 8;
			}
			return b;
		}

	#elif defined(__SSE4_2__) || defined(__SSE4_1__) || defined(__SSSE3__) || defined(__SSE3__) || defined(__SSE2__) || defined(__SSE__)

		// Specialize for float

		template <>
		constexpr size_t zigtrp_block_m<float>(void)
		{
			return static_cast<size_t>(4);
		}

		template <>
		constexpr size_t zigtrp_block_n<float>(void)
		{
			return static_cast<size_t>(4);
		}

		// Function template zigtrp_block

		template <>
		inline float* zigtrp_block<float>(float* b, const float* a, size_t lda)
		{
			__m128 xmm_a0 = _mm_loadu_ps(a);
			__m128 xmm_a1 = _mm_loadu_ps(a + lda);
			__m128 xmm_a2 = _mm_loadu_ps(a + lda * 2);
			__m128 xmm_a3 = _mm_loadu_ps(a + lda * 3);
			__m128 xmm_b0 = _mm_shuffle_ps(xmm_a0, xmm_a1, _MM_SHUFFLE(1, 0, 1, 0));
			__m128 xmm_b1 = _mm_shuffle_ps(xmm_a2, xmm_a3, _MM_SHUFFLE(1, 0, 1, 0));
			__m128 xmm_b2 = _mm_shuffle_ps(xmm_a0, xmm_a1, _MM_SHUFFLE(3, 2, 3, 2));
			__m128 xmm_b3 = _mm_shuffle_ps(xmm_a2, xmm_a3, _MM_SHUFFLE(3, 2, 3, 2));
			xmm_a0 = _mm_shuffle_ps(xmm_b0, xmm_b1, _MM_SHUFFLE(2, 0, 2, 0));
			xmm_a1 = _mm_shuffle_ps(xmm_b0, xmm_b1, _MM_SHUFFLE(3, 1, 3, 1));
			xmm_a2 = _mm_shuffle_ps(xmm_b2, xmm_b3, _MM_SHUFFLE(2, 0, 2, 0));
			xmm_a3 = _mm_shuffle_ps(xmm_b2, xmm_b3, _MM_SHUFFLE(3, 1, 3, 1));
			_mm_storeu_ps(b,          xmm_a0);
			_mm_storeu_ps(b + 0x0004, xmm_a1);
			_mm_storeu_ps(b + 0x0008, xmm_a2);
			_mm_storeu_ps(b + 0x000C, xmm_a3);
			return b + 0x0010;
		}

		// Function template zigtrp_tiny

		template <>
		inline float* zigtrp_tiny<float>(float* b, const float* a, size_t lda, size_t m, size_t n)
		{
			__m128 xmm_a = _mm_setzero_ps();
			for (size_t i = 0; i < n; ++i)
			{
				switch (m)
				{
				case 4: reinterpret_cast<float*>(&xmm_a)[3] = a[lda * 3]; [[fallthrough]];
				case 3: reinterpret_cast<float*>(&xmm_a)[2] = a[lda * 2]; [[fallthrough]];
				case 2: reinterpret_cast<float*>(&xmm_a)[1] = a[lda];     [[fallthrough]];
				case 1: reinterpret_cast<float*>(&xmm_a)[0] = a[0];       [[fallthrough]];
				}
				_mm_storeu_ps(b, xmm_a);
				a += 1;
				b += 4;
			}
			return b;
		}

	#endif

	} // namespace cpu

} // namespace core

#endif
