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

#ifndef __CORE_CPU_TRPI16_H__
#define __CORE_CPU_TRPI16_H__

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

		void trp_block_avx2(signed short* dst, size_t dst_rs, const signed short* src, size_t src_rs, size_t n)
		{
			const size_t dst_step = 8 * dst_rs;
			signed short* ptr_dst[8] = { dst };
			const signed short* ptr_src[16] = { src };
			__m256i ymm_src0, ymm_src1, ymm_src2, ymm_src3, ymm_src4, ymm_src5, ymm_src6, ymm_src7;
			__m256i ymm_dst0, ymm_dst1, ymm_dst2, ymm_dst3, ymm_dst4, ymm_dst5, ymm_dst6, ymm_dst7;

			for (size_t i = 1; i < 8; ++i)
			{
				ptr_src[i] = ptr_src[i - 1] + src_rs;
				ptr_dst[i] = ptr_dst[i - 1] + dst_rs;
			}
			for (size_t i = 8; i < 16; ++i)
				ptr_src[i] = ptr_src[i - 1] + src_rs;
			for (; n >= 8; n -= 8)
			{
				ymm_src0 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[0])));
				ymm_src1 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[1])));
				ymm_src2 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[2])));
				ymm_src3 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[3])));
				ymm_src4 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[4])));
				ymm_src5 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[5])));
				ymm_src6 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[6])));
				ymm_src7 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[7])));
				ymm_src0 = _mm256_insertf128_si256(ymm_src0, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[8])), 1);
				ymm_src1 = _mm256_insertf128_si256(ymm_src1, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[9])), 1);
				ymm_src2 = _mm256_insertf128_si256(ymm_src2, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[10])), 1);
				ymm_src3 = _mm256_insertf128_si256(ymm_src3, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[11])), 1);
				ymm_src4 = _mm256_insertf128_si256(ymm_src4, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[12])), 1);
				ymm_src5 = _mm256_insertf128_si256(ymm_src5, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[13])), 1);
				ymm_src6 = _mm256_insertf128_si256(ymm_src6, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[14])), 1);
				ymm_src7 = _mm256_insertf128_si256(ymm_src7, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[15])), 1);
				ymm_dst0 = _mm256_unpacklo_epi16(ymm_src0, ymm_src1);
				ymm_dst1 = _mm256_unpacklo_epi16(ymm_src2, ymm_src3);
				ymm_dst2 = _mm256_unpacklo_epi16(ymm_src4, ymm_src5);
				ymm_dst3 = _mm256_unpacklo_epi16(ymm_src6, ymm_src7);
				ymm_dst4 = _mm256_unpackhi_epi16(ymm_src0, ymm_src1);
				ymm_dst5 = _mm256_unpackhi_epi16(ymm_src2, ymm_src3);
				ymm_dst6 = _mm256_unpackhi_epi16(ymm_src4, ymm_src5);
				ymm_dst7 = _mm256_unpackhi_epi16(ymm_src6, ymm_src7);
				ymm_src0 = _mm256_unpacklo_epi32(ymm_dst0, ymm_dst1);
				ymm_src1 = _mm256_unpacklo_epi32(ymm_dst2, ymm_dst3);
				ymm_src2 = _mm256_unpackhi_epi32(ymm_dst0, ymm_dst1);
				ymm_src3 = _mm256_unpackhi_epi32(ymm_dst2, ymm_dst3);
				ymm_src4 = _mm256_unpacklo_epi32(ymm_dst4, ymm_dst5);
				ymm_src5 = _mm256_unpacklo_epi32(ymm_dst6, ymm_dst7);
				ymm_src6 = _mm256_unpackhi_epi32(ymm_dst4, ymm_dst5);
				ymm_src7 = _mm256_unpackhi_epi32(ymm_dst6, ymm_dst7);
				ymm_dst0 = _mm256_unpacklo_epi64(ymm_src0, ymm_src1);
				ymm_dst1 = _mm256_unpackhi_epi64(ymm_src0, ymm_src1);
				ymm_dst2 = _mm256_unpacklo_epi64(ymm_src2, ymm_src3);
				ymm_dst3 = _mm256_unpackhi_epi64(ymm_src2, ymm_src3);
				ymm_dst4 = _mm256_unpacklo_epi64(ymm_src4, ymm_src5);
				ymm_dst5 = _mm256_unpackhi_epi64(ymm_src4, ymm_src5);
				ymm_dst6 = _mm256_unpacklo_epi64(ymm_src6, ymm_src7);
				ymm_dst7 = _mm256_unpackhi_epi64(ymm_src6, ymm_src7);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst[0]), ymm_dst0);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst[1]), ymm_dst1);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst[2]), ymm_dst2);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst[3]), ymm_dst3);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst[4]), ymm_dst4);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst[5]), ymm_dst5);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst[6]), ymm_dst6);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst[7]), ymm_dst7);
				ptr_src[0] += 8;
				ptr_src[1] += 8;
				ptr_src[2] += 8;
				ptr_src[3] += 8;
				ptr_src[4] += 8;
				ptr_src[5] += 8;
				ptr_src[6] += 8;
				ptr_src[7] += 8;
				ptr_src[8] += 8;
				ptr_src[9] += 8;
				ptr_src[10] += 8;
				ptr_src[11] += 8;
				ptr_src[12] += 8;
				ptr_src[13] += 8;
				ptr_src[14] += 8;
				ptr_src[15] += 8;
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
				ptr_dst[i][8] = ptr_src[8][i];
				ptr_dst[i][9] = ptr_src[9][i];
				ptr_dst[i][10] = ptr_src[10][i];
				ptr_dst[i][11] = ptr_src[11][i];
				ptr_dst[i][12] = ptr_src[12][i];
				ptr_dst[i][13] = ptr_src[13][i];
				ptr_dst[i][14] = ptr_src[14][i];
				ptr_dst[i][15] = ptr_src[15][i];
			}
		}

		// Function template impl_trp

		template <>
		void impl_trp<signed short>(signed short* dst, size_t dst_rs, const signed short* src, size_t src_rs, size_t m, size_t n)
		{
			constexpr size_t block_m = 16;
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

		void trp_block_sse2(signed short* dst, size_t dst_rs, const signed short* src, size_t src_rs, size_t n)
		{
			const size_t dst_step = 8 * dst_rs;
			signed short* ptr_dst[8] = { dst };
			const signed short* ptr_src[8] = { src };
			__m128i xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128i xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3, xmm_dst4, xmm_dst5, xmm_dst6, xmm_dst7;

			for (size_t i = 1; i < 8; ++i)
			{
				ptr_src[i] = ptr_src[i - 1] + src_rs;
				ptr_dst[i] = ptr_dst[i - 1] + dst_rs;
			}
			for (; n >= 8; n -= 8)
			{
				xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[0]));
				xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[1]));
				xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[2]));
				xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[3]));
				xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[4]));
				xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[5]));
				xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[6]));
				xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[7]));
				xmm_dst0 = _mm_unpacklo_epi16(xmm_src0, xmm_src1);
				xmm_dst1 = _mm_unpacklo_epi16(xmm_src2, xmm_src3);
				xmm_dst2 = _mm_unpacklo_epi16(xmm_src4, xmm_src5);
				xmm_dst3 = _mm_unpacklo_epi16(xmm_src6, xmm_src7);
				xmm_dst4 = _mm_unpackhi_epi16(xmm_src0, xmm_src1);
				xmm_dst5 = _mm_unpackhi_epi16(xmm_src2, xmm_src3);
				xmm_dst6 = _mm_unpackhi_epi16(xmm_src4, xmm_src5);
				xmm_dst7 = _mm_unpackhi_epi16(xmm_src6, xmm_src7);
				xmm_src0 = _mm_unpacklo_epi32(xmm_dst0, xmm_dst1);
				xmm_src1 = _mm_unpacklo_epi32(xmm_dst2, xmm_dst3);
				xmm_src2 = _mm_unpackhi_epi32(xmm_dst0, xmm_dst1);
				xmm_src3 = _mm_unpackhi_epi32(xmm_dst2, xmm_dst3);
				xmm_src4 = _mm_unpacklo_epi32(xmm_dst4, xmm_dst5);
				xmm_src5 = _mm_unpacklo_epi32(xmm_dst6, xmm_dst7);
				xmm_src6 = _mm_unpackhi_epi32(xmm_dst4, xmm_dst5);
				xmm_src7 = _mm_unpackhi_epi32(xmm_dst6, xmm_dst7);
				xmm_dst0 = _mm_unpacklo_epi64(xmm_src0, xmm_src1);
				xmm_dst1 = _mm_unpackhi_epi64(xmm_src0, xmm_src1);
				xmm_dst2 = _mm_unpacklo_epi64(xmm_src2, xmm_src3);
				xmm_dst3 = _mm_unpackhi_epi64(xmm_src2, xmm_src3);
				xmm_dst4 = _mm_unpacklo_epi64(xmm_src4, xmm_src5);
				xmm_dst5 = _mm_unpackhi_epi64(xmm_src4, xmm_src5);
				xmm_dst6 = _mm_unpacklo_epi64(xmm_src6, xmm_src7);
				xmm_dst7 = _mm_unpackhi_epi64(xmm_src6, xmm_src7);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst[0]), xmm_dst0);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst[1]), xmm_dst1);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst[2]), xmm_dst2);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst[3]), xmm_dst3);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst[4]), xmm_dst4);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst[5]), xmm_dst5);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst[6]), xmm_dst6);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst[7]), xmm_dst7);
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
		void impl_trp<signed short>(signed short* dst, size_t dst_rs, const signed short* src, size_t src_rs, size_t m, size_t n)
		{
			constexpr size_t block_m = 8;
			constexpr size_t block_n = 8;
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
