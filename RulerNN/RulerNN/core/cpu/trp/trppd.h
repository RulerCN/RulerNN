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
		template <class T> inline void trp_block(T* dst, size_t dst_rs, const T* src, size_t src_rs);

		// Function template trp_tiny
		template <class T> inline void trp_tiny(T* dst, size_t dst_rs, const T* src, size_t src_rs, size_t m, size_t n);

	#if defined(__AVX2__) || defined(__AVX__)

		// Specialize for double

		template <>
		constexpr size_t trp_block_m<double>(void)
		{
			return static_cast<size_t>(8);
		}

		template <>
		constexpr size_t trp_block_n<double>(void)
		{
			return static_cast<size_t>(4);
		}

		template <>
		inline void trp_block<double>(double* dst, size_t dst_rs, const double* src, size_t src_rs)
		{
			double* ptr_dst0 = dst;
			double* ptr_dst1 = ptr_dst0 + dst_rs;
			double* ptr_dst2 = ptr_dst1 + dst_rs;
			double* ptr_dst3 = ptr_dst2 + dst_rs;
			double* ptr_dst4 = ptr_dst3 + dst_rs;
			double* ptr_dst5 = ptr_dst4 + dst_rs;
			double* ptr_dst6 = ptr_dst5 + dst_rs;
			double* ptr_dst7 = ptr_dst6 + dst_rs;
			const double* ptr_src0 = src;
			const double* ptr_src1 = ptr_src0 + src_rs;
			const double* ptr_src2 = ptr_src1 + src_rs;
			const double* ptr_src3 = ptr_src2 + src_rs;
			const double* ptr_src4 = ptr_src3 + src_rs;
			const double* ptr_src5 = ptr_src4 + src_rs;
			const double* ptr_src6 = ptr_src5 + src_rs;
			const double* ptr_src7 = ptr_src6 + src_rs;
			__m256d ymm_src0 = _mm256_castpd128_pd256(_mm_loadu_pd(ptr_src0));
			__m256d ymm_src1 = _mm256_castpd128_pd256(_mm_loadu_pd(ptr_src1));
			__m256d ymm_src2 = _mm256_castpd128_pd256(_mm_loadu_pd(ptr_src0 + 2));
			__m256d ymm_src3 = _mm256_castpd128_pd256(_mm_loadu_pd(ptr_src1 + 2));
			__m256d ymm_src4 = _mm256_castpd128_pd256(_mm_loadu_pd(ptr_src4));
			__m256d ymm_src5 = _mm256_castpd128_pd256(_mm_loadu_pd(ptr_src5));
			__m256d ymm_src6 = _mm256_castpd128_pd256(_mm_loadu_pd(ptr_src4 + 2));
			__m256d ymm_src7 = _mm256_castpd128_pd256(_mm_loadu_pd(ptr_src5 + 2));
			__m256d ymm_dst0 = _mm256_insertf128_pd(ymm_src0, _mm_loadu_pd(ptr_src2), 1);
			__m256d ymm_dst1 = _mm256_insertf128_pd(ymm_src1, _mm_loadu_pd(ptr_src3), 1);
			__m256d ymm_dst2 = _mm256_insertf128_pd(ymm_src2, _mm_loadu_pd(ptr_src2 + 2), 1);
			__m256d ymm_dst3 = _mm256_insertf128_pd(ymm_src3, _mm_loadu_pd(ptr_src3 + 2), 1);
			__m256d ymm_dst4 = _mm256_insertf128_pd(ymm_src4, _mm_loadu_pd(ptr_src6), 1);
			__m256d ymm_dst5 = _mm256_insertf128_pd(ymm_src5, _mm_loadu_pd(ptr_src7), 1);
			__m256d ymm_dst6 = _mm256_insertf128_pd(ymm_src6, _mm_loadu_pd(ptr_src6 + 2), 1);
			__m256d ymm_dst7 = _mm256_insertf128_pd(ymm_src7, _mm_loadu_pd(ptr_src7 + 2), 1);
			ymm_src0 = _mm256_shuffle_pd(ymm_dst0, ymm_dst1, _MM_SHUFFLE(0, 0, 0, 0));
			ymm_src1 = _mm256_shuffle_pd(ymm_dst0, ymm_dst1, _MM_SHUFFLE(0, 0, 3, 3));
			ymm_src2 = _mm256_shuffle_pd(ymm_dst2, ymm_dst3, _MM_SHUFFLE(0, 0, 0, 0));
			ymm_src3 = _mm256_shuffle_pd(ymm_dst2, ymm_dst3, _MM_SHUFFLE(0, 0, 3, 3));
			ymm_src4 = _mm256_shuffle_pd(ymm_dst4, ymm_dst5, _MM_SHUFFLE(0, 0, 0, 0));
			ymm_src5 = _mm256_shuffle_pd(ymm_dst4, ymm_dst5, _MM_SHUFFLE(0, 0, 3, 3));
			ymm_src6 = _mm256_shuffle_pd(ymm_dst6, ymm_dst7, _MM_SHUFFLE(0, 0, 0, 0));
			ymm_src7 = _mm256_shuffle_pd(ymm_dst6, ymm_dst7, _MM_SHUFFLE(0, 0, 3, 3));
			_mm256_storeu_pd(ptr_dst0, ymm_src0);
			_mm256_storeu_pd(ptr_dst1, ymm_src1);
			_mm256_storeu_pd(ptr_dst2, ymm_src2);
			_mm256_storeu_pd(ptr_dst3, ymm_src3);
			_mm256_storeu_pd(ptr_dst0 + 4, ymm_src4);
			_mm256_storeu_pd(ptr_dst1 + 4, ymm_src5);
			_mm256_storeu_pd(ptr_dst2 + 4, ymm_src6);
			_mm256_storeu_pd(ptr_dst3 + 4, ymm_src7);
		}

		template <>
		inline void trp_tiny<double>(double* dst, size_t dst_rs, const double* src, size_t src_rs, size_t m, size_t n)
		{
			const size_t row0 = 0;
			const size_t row1 = dst_rs;
			const size_t row2 = row1 + dst_rs;
			const size_t row3 = row2 + dst_rs;

			for (size_t i = 0; i < m; ++i)
			{
				switch (n)
				{
				case 4: dst[row3 + i] = src[3];
				case 3: dst[row2 + i] = src[2];
				case 2: dst[row1 + i] = src[1];
				case 1: dst[row0 + i] = src[0];
					break;
				}
				src += src_rs;
			}
		}

	#elif defined(__SSE4_2__) || defined(__SSE4_1__) || defined(__SSSE3__) || defined(__SSE3__) || defined(__SSE2__)

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
		inline void trp_block<double>(double* dst, size_t dst_rs, const double* src, size_t src_rs)
		{
			double* ptr_dst0 = dst;
			double* ptr_dst1 = ptr_dst0 + dst_rs;
			double* ptr_dst2 = ptr_dst1 + dst_rs;
			double* ptr_dst3 = ptr_dst2 + dst_rs;
			const double* ptr_src0 = src;
			const double* ptr_src1 = ptr_src0 + src_rs;
			const double* ptr_src2 = ptr_src1 + src_rs;
			const double* ptr_src3 = ptr_src2 + src_rs;
			__m128d xmm_src0 = _mm_loadu_pd(ptr_src0);
			__m128d xmm_src1 = _mm_loadu_pd(ptr_src1);
			__m128d xmm_src2 = _mm_loadu_pd(ptr_src0 + 2);
			__m128d xmm_src3 = _mm_loadu_pd(ptr_src1 + 2);
			__m128d xmm_src4 = _mm_loadu_pd(ptr_src2);
			__m128d xmm_src5 = _mm_loadu_pd(ptr_src3);
			__m128d xmm_src6 = _mm_loadu_pd(ptr_src2 + 2);
			__m128d xmm_src7 = _mm_loadu_pd(ptr_src3 + 2);
			__m128d xmm_dst0 = _mm_shuffle_pd(xmm_src0, xmm_src1, _MM_SHUFFLE(0, 0, 0, 0));
			__m128d xmm_dst1 = _mm_shuffle_pd(xmm_src0, xmm_src1, _MM_SHUFFLE(0, 0, 3, 3));
			__m128d xmm_dst2 = _mm_shuffle_pd(xmm_src2, xmm_src3, _MM_SHUFFLE(0, 0, 0, 0));
			__m128d xmm_dst3 = _mm_shuffle_pd(xmm_src2, xmm_src3, _MM_SHUFFLE(0, 0, 3, 3));
			__m128d xmm_dst4 = _mm_shuffle_pd(xmm_src4, xmm_src5, _MM_SHUFFLE(0, 0, 0, 0));
			__m128d xmm_dst5 = _mm_shuffle_pd(xmm_src4, xmm_src5, _MM_SHUFFLE(0, 0, 3, 3));
			__m128d xmm_dst6 = _mm_shuffle_pd(xmm_src6, xmm_src7, _MM_SHUFFLE(0, 0, 0, 0));
			__m128d xmm_dst7 = _mm_shuffle_pd(xmm_src6, xmm_src7, _MM_SHUFFLE(0, 0, 3, 3));
			_mm_storeu_pd(ptr_dst0, xmm_dst0);
			_mm_storeu_pd(ptr_dst1, xmm_dst1);
			_mm_storeu_pd(ptr_dst2, xmm_dst2);
			_mm_storeu_pd(ptr_dst3, xmm_dst3);
			_mm_storeu_pd(ptr_dst0 + 2, xmm_dst4);
			_mm_storeu_pd(ptr_dst1 + 2, xmm_dst5);
			_mm_storeu_pd(ptr_dst2 + 2, xmm_dst6);
			_mm_storeu_pd(ptr_dst3 + 2, xmm_dst7);
		}

		template <>
		inline void trp_tiny<double>(double* dst, size_t dst_rs, const double* src, size_t src_rs, size_t m, size_t n)
		{
			const size_t row0 = 0;
			const size_t row1 = dst_rs;
			const size_t row2 = row1 + dst_rs;
			const size_t row3 = row2 + dst_rs;

			for (size_t i = 0; i < m; ++i)
			{
				switch (n)
				{
				case 4: dst[row3 + i] = src[3];
				case 3: dst[row2 + i] = src[2];
				case 2: dst[row1 + i] = src[1];
				case 1: dst[row0 + i] = src[0];
					break;
				}
				src += src_rs;
			}
		}

	#endif

	} // namespace cpu

} // namespace core

#endif
