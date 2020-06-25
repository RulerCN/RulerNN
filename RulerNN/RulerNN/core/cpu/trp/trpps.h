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

#ifndef __CORE_CPU_TRPPS_H__
#define __CORE_CPU_TRPPS_H__

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
		template <class T> inline void trp_block(T* dst, size_t dst_rs, const T* src, size_t src_rs);

	#ifdef __AVX2__

		// Specialize for float

		template <>
		constexpr size_t trp_block_m<float>(void)
		{
			return static_cast<size_t>(8);
		}

		template <>
		constexpr size_t trp_block_n<float>(void)
		{
			return static_cast<size_t>(8);
		}

		template <>
		inline void trp_block<float>(float* dst, size_t dst_rs, const float* src, size_t src_rs)
		{
			float* ptr_dst0 = dst;
			float* ptr_dst1 = ptr_dst0 + dst_rs;
			float* ptr_dst2 = ptr_dst1 + dst_rs;
			float* ptr_dst3 = ptr_dst2 + dst_rs;
			float* ptr_dst4 = ptr_dst3 + dst_rs;
			float* ptr_dst5 = ptr_dst4 + dst_rs;
			float* ptr_dst6 = ptr_dst5 + dst_rs;
			float* ptr_dst7 = ptr_dst6 + dst_rs;
			const float* ptr_src0 = src;
			const float* ptr_src1 = ptr_src0 + src_rs;
			const float* ptr_src2 = ptr_src1 + src_rs;
			const float* ptr_src3 = ptr_src2 + src_rs;
			const float* ptr_src4 = ptr_src3 + src_rs;
			const float* ptr_src5 = ptr_src4 + src_rs;
			const float* ptr_src6 = ptr_src5 + src_rs;
			const float* ptr_src7 = ptr_src6 + src_rs;
			__m256 ymm_src0 = _mm256_castps128_ps256(_mm_loadu_ps(ptr_src0));
			__m256 ymm_src1 = _mm256_castps128_ps256(_mm_loadu_ps(ptr_src1));
			__m256 ymm_src2 = _mm256_castps128_ps256(_mm_loadu_ps(ptr_src2));
			__m256 ymm_src3 = _mm256_castps128_ps256(_mm_loadu_ps(ptr_src3));
			__m256 ymm_src4 = _mm256_castps128_ps256(_mm_loadu_ps(ptr_src0 + 4));
			__m256 ymm_src5 = _mm256_castps128_ps256(_mm_loadu_ps(ptr_src1 + 4));
			__m256 ymm_src6 = _mm256_castps128_ps256(_mm_loadu_ps(ptr_src2 + 4));
			__m256 ymm_src7 = _mm256_castps128_ps256(_mm_loadu_ps(ptr_src3 + 4));
			__m256 ymm_dst0 = _mm256_insertf128_ps(ymm_src0, _mm_loadu_ps(ptr_src4), 1);
			__m256 ymm_dst1 = _mm256_insertf128_ps(ymm_src1, _mm_loadu_ps(ptr_src5), 1);
			__m256 ymm_dst2 = _mm256_insertf128_ps(ymm_src2, _mm_loadu_ps(ptr_src6), 1);
			__m256 ymm_dst3 = _mm256_insertf128_ps(ymm_src3, _mm_loadu_ps(ptr_src7), 1);
			__m256 ymm_dst4 = _mm256_insertf128_ps(ymm_src4, _mm_loadu_ps(ptr_src4 + 4), 1);
			__m256 ymm_dst5 = _mm256_insertf128_ps(ymm_src5, _mm_loadu_ps(ptr_src5 + 4), 1);
			__m256 ymm_dst6 = _mm256_insertf128_ps(ymm_src6, _mm_loadu_ps(ptr_src6 + 4), 1);
			__m256 ymm_dst7 = _mm256_insertf128_ps(ymm_src7, _mm_loadu_ps(ptr_src7 + 4), 1);
			ymm_src0 = _mm256_shuffle_ps(ymm_dst0, ymm_dst1, _MM_SHUFFLE(1, 0, 1, 0));
			ymm_src1 = _mm256_shuffle_ps(ymm_dst2, ymm_dst3, _MM_SHUFFLE(1, 0, 1, 0));
			ymm_src2 = _mm256_shuffle_ps(ymm_dst0, ymm_dst1, _MM_SHUFFLE(3, 2, 3, 2));
			ymm_src3 = _mm256_shuffle_ps(ymm_dst2, ymm_dst3, _MM_SHUFFLE(3, 2, 3, 2));
			ymm_src4 = _mm256_shuffle_ps(ymm_dst4, ymm_dst5, _MM_SHUFFLE(1, 0, 1, 0));
			ymm_src5 = _mm256_shuffle_ps(ymm_dst6, ymm_dst7, _MM_SHUFFLE(1, 0, 1, 0));
			ymm_src6 = _mm256_shuffle_ps(ymm_dst4, ymm_dst5, _MM_SHUFFLE(3, 2, 3, 2));
			ymm_src7 = _mm256_shuffle_ps(ymm_dst6, ymm_dst7, _MM_SHUFFLE(3, 2, 3, 2));
			ymm_dst0 = _mm256_shuffle_ps(ymm_src0, ymm_src1, _MM_SHUFFLE(2, 0, 2, 0));
			ymm_dst1 = _mm256_shuffle_ps(ymm_src0, ymm_src1, _MM_SHUFFLE(3, 1, 3, 1));
			ymm_dst2 = _mm256_shuffle_ps(ymm_src2, ymm_src3, _MM_SHUFFLE(2, 0, 2, 0));
			ymm_dst3 = _mm256_shuffle_ps(ymm_src2, ymm_src3, _MM_SHUFFLE(3, 1, 3, 1));
			ymm_dst4 = _mm256_shuffle_ps(ymm_src4, ymm_src5, _MM_SHUFFLE(2, 0, 2, 0));
			ymm_dst5 = _mm256_shuffle_ps(ymm_src4, ymm_src5, _MM_SHUFFLE(3, 1, 3, 1));
			ymm_dst6 = _mm256_shuffle_ps(ymm_src6, ymm_src7, _MM_SHUFFLE(2, 0, 2, 0));
			ymm_dst7 = _mm256_shuffle_ps(ymm_src6, ymm_src7, _MM_SHUFFLE(3, 1, 3, 1));
			_mm256_storeu_ps(ptr_dst0, ymm_dst0);
			_mm256_storeu_ps(ptr_dst1, ymm_dst1);
			_mm256_storeu_ps(ptr_dst2, ymm_dst2);
			_mm256_storeu_ps(ptr_dst3, ymm_dst3);
			_mm256_storeu_ps(ptr_dst4, ymm_dst4);
			_mm256_storeu_ps(ptr_dst5, ymm_dst5);
			_mm256_storeu_ps(ptr_dst6, ymm_dst6);
			_mm256_storeu_ps(ptr_dst7, ymm_dst7);
		}

	#elif defined(__AVX__) || defined(__SSE4_2__) || defined(__SSE4_1__) || defined(__SSSE3__) || defined(__SSE3__) || defined(__SSE2__)

		// Specialize for float

		template <>
		constexpr size_t trp_block_m<float>(void)
		{
			return static_cast<size_t>(4);
		}

		template <>
		constexpr size_t trp_block_n<float>(void)
		{
			return static_cast<size_t>(4);
		}

		template <>
		inline void trp_block<float>(float* dst, size_t dst_rs, const float* src, size_t src_rs)
		{
			float* ptr_dst0 = dst;
			float* ptr_dst1 = ptr_dst0 + dst_rs;
			float* ptr_dst2 = ptr_dst1 + dst_rs;
			float* ptr_dst3 = ptr_dst2 + dst_rs;
			const float* ptr_src0 = src;
			const float* ptr_src1 = ptr_src0 + src_rs;
			const float* ptr_src2 = ptr_src1 + src_rs;
			const float* ptr_src3 = ptr_src2 + src_rs;
			__m128 xmm_src0 = _mm_loadu_ps(ptr_src0);
			__m128 xmm_src1 = _mm_loadu_ps(ptr_src1);
			__m128 xmm_src2 = _mm_loadu_ps(ptr_src2);
			__m128 xmm_src3 = _mm_loadu_ps(ptr_src3);
			__m128 xmm_dst0 = _mm_shuffle_ps(xmm_src0, xmm_src1, _MM_SHUFFLE(1, 0, 1, 0));
			__m128 xmm_dst1 = _mm_shuffle_ps(xmm_src2, xmm_src3, _MM_SHUFFLE(1, 0, 1, 0));
			__m128 xmm_dst2 = _mm_shuffle_ps(xmm_src0, xmm_src1, _MM_SHUFFLE(3, 2, 3, 2));
			__m128 xmm_dst3 = _mm_shuffle_ps(xmm_src2, xmm_src3, _MM_SHUFFLE(3, 2, 3, 2));
			xmm_src0 = _mm_shuffle_ps(xmm_dst0, xmm_dst1, _MM_SHUFFLE(2, 0, 2, 0));
			xmm_src1 = _mm_shuffle_ps(xmm_dst0, xmm_dst1, _MM_SHUFFLE(3, 1, 3, 1));
			xmm_src2 = _mm_shuffle_ps(xmm_dst2, xmm_dst3, _MM_SHUFFLE(2, 0, 2, 0));
			xmm_src3 = _mm_shuffle_ps(xmm_dst2, xmm_dst3, _MM_SHUFFLE(3, 1, 3, 1));
			_mm_storeu_ps(ptr_dst0, xmm_src0);
			_mm_storeu_ps(ptr_dst1, xmm_src1);
			_mm_storeu_ps(ptr_dst2, xmm_src2);
			_mm_storeu_ps(ptr_dst3, xmm_src3);
		}

	#endif

	} // namespace cpu

} // namespace core

#endif
