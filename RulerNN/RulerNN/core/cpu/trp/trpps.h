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
		template <class T>
		inline void trp_line(T* dst, size_t dst_rs, const T* src, size_t src_rs, size_t n);

		template <class T>
		void impl_trp(T* dst, size_t dst_rs, const T* src, size_t src_rs, size_t m, size_t n);

	#ifdef __AVX2__

		// Function trp_block_avx2

		void trp_block_avx2(float* dst, size_t dst_rs, const float* src, size_t src_rs, size_t n)
		{
			const size_t dst_step = 8 * dst_rs;
			float* ptr_dst[8] = { dst };
			const float* ptr_src[8] = { src };
			__m256 ymm_src0, ymm_src1, ymm_src2, ymm_src3, ymm_src4, ymm_src5, ymm_src6, ymm_src7;
			__m256 ymm_dst0, ymm_dst1, ymm_dst2, ymm_dst3, ymm_dst4, ymm_dst5, ymm_dst6, ymm_dst7;

			for (size_t i = 1; i < 8; ++i)
			{
				ptr_src[i] = ptr_src[i - 1] + src_rs;
				ptr_dst[i] = ptr_dst[i - 1] + dst_rs;
			}
			for (; n >= 8; n -= 8)
			{
				ymm_src0 = _mm256_castps128_ps256(_mm_loadu_ps(ptr_src[0]));
				ymm_src1 = _mm256_castps128_ps256(_mm_loadu_ps(ptr_src[1]));
				ymm_src2 = _mm256_castps128_ps256(_mm_loadu_ps(ptr_src[2]));
				ymm_src3 = _mm256_castps128_ps256(_mm_loadu_ps(ptr_src[3]));
				ymm_src4 = _mm256_castps128_ps256(_mm_loadu_ps(ptr_src[0] + 4));
				ymm_src5 = _mm256_castps128_ps256(_mm_loadu_ps(ptr_src[1] + 4));
				ymm_src6 = _mm256_castps128_ps256(_mm_loadu_ps(ptr_src[2] + 4));
				ymm_src7 = _mm256_castps128_ps256(_mm_loadu_ps(ptr_src[3] + 4));
				ymm_src0 = _mm256_insertf128_ps(ymm_src0, _mm_loadu_ps(ptr_src[4]), 1);
				ymm_src1 = _mm256_insertf128_ps(ymm_src1, _mm_loadu_ps(ptr_src[5]), 1);
				ymm_src2 = _mm256_insertf128_ps(ymm_src2, _mm_loadu_ps(ptr_src[6]), 1);
				ymm_src3 = _mm256_insertf128_ps(ymm_src3, _mm_loadu_ps(ptr_src[7]), 1);
				ymm_src4 = _mm256_insertf128_ps(ymm_src4, _mm_loadu_ps(ptr_src[4] + 4), 1);
				ymm_src5 = _mm256_insertf128_ps(ymm_src5, _mm_loadu_ps(ptr_src[5] + 4), 1);
				ymm_src6 = _mm256_insertf128_ps(ymm_src6, _mm_loadu_ps(ptr_src[6] + 4), 1);
				ymm_src7 = _mm256_insertf128_ps(ymm_src7, _mm_loadu_ps(ptr_src[7] + 4), 1);
				ymm_dst0 = _mm256_shuffle_ps(ymm_src0, ymm_src1, _MM_SHUFFLE(1, 0, 1, 0));
				ymm_dst1 = _mm256_shuffle_ps(ymm_src2, ymm_src3, _MM_SHUFFLE(1, 0, 1, 0));
				ymm_dst2 = _mm256_shuffle_ps(ymm_src0, ymm_src1, _MM_SHUFFLE(3, 2, 3, 2));
				ymm_dst3 = _mm256_shuffle_ps(ymm_src2, ymm_src3, _MM_SHUFFLE(3, 2, 3, 2));
				ymm_dst4 = _mm256_shuffle_ps(ymm_src4, ymm_src5, _MM_SHUFFLE(1, 0, 1, 0));
				ymm_dst5 = _mm256_shuffle_ps(ymm_src6, ymm_src7, _MM_SHUFFLE(1, 0, 1, 0));
				ymm_dst6 = _mm256_shuffle_ps(ymm_src4, ymm_src5, _MM_SHUFFLE(3, 2, 3, 2));
				ymm_dst7 = _mm256_shuffle_ps(ymm_src6, ymm_src7, _MM_SHUFFLE(3, 2, 3, 2));
				ymm_src0 = _mm256_shuffle_ps(ymm_dst0, ymm_dst1, _MM_SHUFFLE(2, 0, 2, 0));
				ymm_src1 = _mm256_shuffle_ps(ymm_dst0, ymm_dst1, _MM_SHUFFLE(3, 1, 3, 1));
				ymm_src2 = _mm256_shuffle_ps(ymm_dst2, ymm_dst3, _MM_SHUFFLE(2, 0, 2, 0));
				ymm_src3 = _mm256_shuffle_ps(ymm_dst2, ymm_dst3, _MM_SHUFFLE(3, 1, 3, 1));
				ymm_src4 = _mm256_shuffle_ps(ymm_dst4, ymm_dst5, _MM_SHUFFLE(2, 0, 2, 0));
				ymm_src5 = _mm256_shuffle_ps(ymm_dst4, ymm_dst5, _MM_SHUFFLE(3, 1, 3, 1));
				ymm_src6 = _mm256_shuffle_ps(ymm_dst6, ymm_dst7, _MM_SHUFFLE(2, 0, 2, 0));
				ymm_src7 = _mm256_shuffle_ps(ymm_dst6, ymm_dst7, _MM_SHUFFLE(3, 1, 3, 1));
				_mm256_storeu_ps(ptr_dst[0], ymm_src0);
				_mm256_storeu_ps(ptr_dst[1], ymm_src1);
				_mm256_storeu_ps(ptr_dst[2], ymm_src2);
				_mm256_storeu_ps(ptr_dst[3], ymm_src3);
				_mm256_storeu_ps(ptr_dst[4], ymm_src4);
				_mm256_storeu_ps(ptr_dst[5], ymm_src5);
				_mm256_storeu_ps(ptr_dst[6], ymm_src6);
				_mm256_storeu_ps(ptr_dst[7], ymm_src7);
				ptr_src[0] += 8;
				ptr_src[1] += 8;
				ptr_src[2] += 8;
				ptr_src[3] += 8;
				ptr_src[4] += 8;
				ptr_src[5] += 8;
				ptr_src[6] += 8;
				ptr_src[7] += 8;
				ptr_dst[0] += dst_step;
				ptr_dst[1] += dst_step;
				ptr_dst[2] += dst_step;
				ptr_dst[3] += dst_step;
				ptr_dst[4] += dst_step;
				ptr_dst[5] += dst_step;
				ptr_dst[6] += dst_step;
				ptr_dst[7] += dst_step;
			}
			for (size_t i = 0; i < n; ++i)
			{
				ptr_dst[i][0] = ptr_src[0][i];
				ptr_dst[i][1] = ptr_src[1][i];
				ptr_dst[i][2] = ptr_src[2][i];
				ptr_dst[i][3] = ptr_src[3][i];
				ptr_dst[i][4] = ptr_src[4][i];
				ptr_dst[i][5] = ptr_src[5][i];
				ptr_dst[i][6] = ptr_src[6][i];
				ptr_dst[i][7] = ptr_src[7][i];
			}
		}

		// Function template impl_trp

		template <>
		void impl_trp<float>(float* dst, size_t dst_rs, const float* src, size_t src_rs, size_t m, size_t n)
		{
			constexpr size_t block_m = 8;
			constexpr size_t block_n = 8;
			const size_t src_step = block_m * src_rs;

			for (; m >= block_m; m -= block_m)
			{
				trp_block_avx2(dst, dst_rs, src, src_rs, n);
				src += src_step;
				dst += block_m;
			}
			for (size_t i = 0; i < m; ++i)
			{
				trp_line(dst + i, dst_rs, src, src_rs, n);
				src += src_rs;
			}
		}
		
	#elif defined(__AVX__) || defined(__SSE4_2__) || defined(__SSE4_1__) || defined(__SSSE3__) || defined(__SSE3__) || defined(__SSE2__)

		// Function trp_block_sse2

		//void trp_block_sse2(float* dst, size_t dst_rs, const float* src, size_t src_rs, size_t n)
		//{
		//	const size_t dst_step = 4 * dst_rs;
		//	float* ptr_dst[4] = { dst };
		//	const float* ptr_src[4] = { src };
		//	__m128 xmm_src0, xmm_src1, xmm_src2, xmm_src3;
		//	__m128 xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3;

		//	for (size_t i = 1; i < 4; ++i)
		//	{
		//		ptr_src[i] = ptr_src[i - 1] + src_rs;
		//		ptr_dst[i] = ptr_dst[i - 1] + dst_rs;
		//	}
		//	for (; n >= 4; n -= 4)
		//	{
		//		xmm_src0 = _mm_loadu_ps(ptr_src[0]);
		//		xmm_src1 = _mm_loadu_ps(ptr_src[1]);
		//		xmm_src2 = _mm_loadu_ps(ptr_src[2]);
		//		xmm_src3 = _mm_loadu_ps(ptr_src[3]);
		//		xmm_dst0 = _mm_shuffle_ps(xmm_src0, xmm_src1, _MM_SHUFFLE(1, 0, 1, 0));
		//		xmm_dst1 = _mm_shuffle_ps(xmm_src2, xmm_src3, _MM_SHUFFLE(1, 0, 1, 0));
		//		xmm_dst2 = _mm_shuffle_ps(xmm_src0, xmm_src1, _MM_SHUFFLE(3, 2, 3, 2));
		//		xmm_dst3 = _mm_shuffle_ps(xmm_src2, xmm_src3, _MM_SHUFFLE(3, 2, 3, 2));
		//		xmm_src0 = _mm_shuffle_ps(xmm_dst0, xmm_dst1, _MM_SHUFFLE(2, 0, 2, 0));
		//		xmm_src1 = _mm_shuffle_ps(xmm_dst0, xmm_dst1, _MM_SHUFFLE(3, 1, 3, 1));
		//		xmm_src2 = _mm_shuffle_ps(xmm_dst2, xmm_dst3, _MM_SHUFFLE(2, 0, 2, 0));
		//		xmm_src3 = _mm_shuffle_ps(xmm_dst2, xmm_dst3, _MM_SHUFFLE(3, 1, 3, 1));
		//		_mm_storeu_ps(ptr_dst[0], xmm_src0);
		//		_mm_storeu_ps(ptr_dst[1], xmm_src1);
		//		_mm_storeu_ps(ptr_dst[2], xmm_src2);
		//		_mm_storeu_ps(ptr_dst[3], xmm_src3);
		//		ptr_src[0] += 4;
		//		ptr_src[1] += 4;
		//		ptr_src[2] += 4;
		//		ptr_src[3] += 4;
		//		ptr_dst[0] += dst_step;
		//		ptr_dst[1] += dst_step;
		//		ptr_dst[2] += dst_step;
		//		ptr_dst[3] += dst_step;
		//	}
		//	for (size_t i = 0; i < n; ++i)
		//	{
		//		ptr_dst[i][0] = ptr_src[0][i];
		//		ptr_dst[i][1] = ptr_src[1][i];
		//		ptr_dst[i][2] = ptr_src[2][i];
		//		ptr_dst[i][3] = ptr_src[3][i];
		//	}
		//}

		void trp_block_sse2(float* dst, size_t dst_rs, const float* src, size_t src_rs, size_t n)
		{
			const size_t dst_step = 4 * dst_rs;
			const float* ptr_src0 = src;
			const float* ptr_src1 = ptr_src0 + src_rs;
			const float* ptr_src2 = ptr_src1 + src_rs;
			const float* ptr_src3 = ptr_src2 + src_rs;
			float* ptr_dst0 = dst;
			float* ptr_dst1 = ptr_dst0 + dst_rs;
			float* ptr_dst2 = ptr_dst1 + dst_rs;
			float* ptr_dst3 = ptr_dst2 + dst_rs;
			__m128 xmm_src0, xmm_src1, xmm_src2, xmm_src3;
			__m128 xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3;

			for (; n >= 4; n -= 4)
			{
				xmm_src0 = _mm_loadu_ps(ptr_src0);
				xmm_src1 = _mm_loadu_ps(ptr_src1);
				xmm_src2 = _mm_loadu_ps(ptr_src2);
				xmm_src3 = _mm_loadu_ps(ptr_src3);
				xmm_dst0 = _mm_shuffle_ps(xmm_src0, xmm_src1, _MM_SHUFFLE(1, 0, 1, 0));
				xmm_dst1 = _mm_shuffle_ps(xmm_src2, xmm_src3, _MM_SHUFFLE(1, 0, 1, 0));
				xmm_dst2 = _mm_shuffle_ps(xmm_src0, xmm_src1, _MM_SHUFFLE(3, 2, 3, 2));
				xmm_dst3 = _mm_shuffle_ps(xmm_src2, xmm_src3, _MM_SHUFFLE(3, 2, 3, 2));
				xmm_src0 = _mm_shuffle_ps(xmm_dst0, xmm_dst1, _MM_SHUFFLE(2, 0, 2, 0));
				xmm_src1 = _mm_shuffle_ps(xmm_dst0, xmm_dst1, _MM_SHUFFLE(3, 1, 3, 1));
				xmm_src2 = _mm_shuffle_ps(xmm_dst2, xmm_dst3, _MM_SHUFFLE(2, 0, 2, 0));
				xmm_src3 = _mm_shuffle_ps(xmm_dst2, xmm_dst3, _MM_SHUFFLE(3, 1, 3, 1));
				_mm_storeu_ps(ptr_dst0, xmm_src0);
				_mm_storeu_ps(ptr_dst1, xmm_src1);
				_mm_storeu_ps(ptr_dst2, xmm_src2);
				_mm_storeu_ps(ptr_dst3, xmm_src3);
				ptr_src0 += 4;
				ptr_src1 += 4;
				ptr_src2 += 4;
				ptr_src3 += 4;
				ptr_dst0 += dst_step;
				ptr_dst1 += dst_step;
				ptr_dst2 += dst_step;
				ptr_dst3 += dst_step;
			}
			for (size_t i = 0; i < n; ++i)
			{
				ptr_dst0[0] = ptr_src0[i];
				ptr_dst0[1] = ptr_src1[i];
				ptr_dst0[2] = ptr_src2[i];
				ptr_dst0[3] = ptr_src3[i];
				ptr_dst0 += dst_rs;
			}
		}

		// Function template impl_trp

		template <>
		void impl_trp<float>(float* dst, size_t dst_rs, const float* src, size_t src_rs, size_t m, size_t n)
		{
			constexpr size_t block_m = 4;
			constexpr size_t block_n = 4;
			const size_t src_step = block_m * src_rs;

			for (; m >= block_m; m -= block_m)
			{
				trp_block_sse2(dst, dst_rs, src, src_rs, n);
				src += src_step;
				dst += block_m;
			}
			for (size_t i = 0; i < m; ++i)
			{
				trp_line(dst + i, dst_rs, src, src_rs, n);
				src += src_rs;
			}
		}

	#endif

	} // namespace cpu

} // namespace core

#endif
