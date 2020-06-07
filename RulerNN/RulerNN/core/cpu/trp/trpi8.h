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

#ifndef __CORE_CPU_TRPI8_H__
#define __CORE_CPU_TRPI8_H__

#include "../simd.h"

namespace core
{
	namespace cpu
	{
		void trpi8_tiny(signed char* dst, size_t dst_rs, const signed char* src, size_t src_rs, size_t n)
		{
			for (size_t j = 0; j < n; ++j)
			{
				*dst = src[j];
				dst += dst_rs;
			}
		}

	#ifdef __AVX2__

		// Function template trpi8_avx2

		void trpi8_avx2(signed char* dst, size_t dst_rs, const signed char* src, size_t src_rs, size_t n)
		{
			const size_t dst_step = 16 * dst_rs;
			signed char* ptr_dst[16] = { dst };
			const signed char* ptr_src[32] = { src };
			__m256i ymm_src0, ymm_src1, ymm_src2, ymm_src3, ymm_src4, ymm_src5, ymm_src6, ymm_src7;
			__m256i ymm_src8, ymm_src9, ymm_srca, ymm_srcb, ymm_srcc, ymm_srcd, ymm_srce, ymm_srcf;
			__m256i ymm_dst0, ymm_dst1, ymm_dst2, ymm_dst3, ymm_dst4, ymm_dst5, ymm_dst6, ymm_dst7;
			__m256i ymm_dst8, ymm_dst9, ymm_dsta, ymm_dstb, ymm_dstc, ymm_dstd, ymm_dste, ymm_dstf;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			for (size_t i = 1; i < 16; ++i)
			{
				ptr_src[i] = ptr_src[i - 1] + src_rs;
				ptr_dst[i] = ptr_dst[i - 1] + dst_rs;
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[i]), _MM_HINT_NTA);
			}
			for (size_t i = 16; i < 32; ++i)
			{
				ptr_src[i] = ptr_src[i - 1] + src_rs;
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[i]), _MM_HINT_NTA);
			}
			for (; n >= 16; n -= 16)
			{
				ymm_src0 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[0])));
				ymm_src1 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[1])));
				ymm_src2 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[2])));
				ymm_src3 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[3])));
				ymm_src4 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[4])));
				ymm_src5 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[5])));
				ymm_src6 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[6])));
				ymm_src7 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[7])));
				ymm_src8 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[8])));
				ymm_src9 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[9])));
				ymm_srca = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[10])));
				ymm_srcb = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[11])));
				ymm_srcc = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[12])));
				ymm_srcd = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[13])));
				ymm_srce = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[14])));
				ymm_srcf = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[15])));
				ymm_src0 = _mm256_insertf128_si256(ymm_src0, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[16])), 1);
				ymm_src1 = _mm256_insertf128_si256(ymm_src1, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[17])), 1);
				ymm_src2 = _mm256_insertf128_si256(ymm_src2, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[18])), 1);
				ymm_src3 = _mm256_insertf128_si256(ymm_src3, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[19])), 1);
				ymm_src4 = _mm256_insertf128_si256(ymm_src4, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[20])), 1);
				ymm_src5 = _mm256_insertf128_si256(ymm_src5, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[21])), 1);
				ymm_src6 = _mm256_insertf128_si256(ymm_src6, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[22])), 1);
				ymm_src7 = _mm256_insertf128_si256(ymm_src7, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[23])), 1);
				ymm_src8 = _mm256_insertf128_si256(ymm_src8, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[24])), 1);
				ymm_src9 = _mm256_insertf128_si256(ymm_src9, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[25])), 1);
				ymm_srca = _mm256_insertf128_si256(ymm_srca, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[26])), 1);
				ymm_srcb = _mm256_insertf128_si256(ymm_srcb, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[27])), 1);
				ymm_srcc = _mm256_insertf128_si256(ymm_srcc, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[28])), 1);
				ymm_srcd = _mm256_insertf128_si256(ymm_srcd, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[29])), 1);
				ymm_srce = _mm256_insertf128_si256(ymm_srce, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[30])), 1);
				ymm_srcf = _mm256_insertf128_si256(ymm_srcf, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[31])), 1);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[0]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[1]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[2]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[3]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[4]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[5]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[6]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[7]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[8]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[9]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[10]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[11]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[12]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[13]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[14]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[15]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[16]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[17]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[18]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[19]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[20]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[21]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[22]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[23]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[24]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[25]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[26]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[27]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[28]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[29]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[30]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[31]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_dst[0]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_dst[1]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_dst[2]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_dst[3]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_dst[4]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_dst[5]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_dst[6]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_dst[7]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_dst[8]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_dst[9]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_dst[10]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_dst[11]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_dst[12]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_dst[13]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_dst[14]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_dst[15]), _MM_HINT_NTA);
				ymm_dst0 = _mm256_unpacklo_epi8(ymm_src0, ymm_src1);
				ymm_dst1 = _mm256_unpacklo_epi8(ymm_src2, ymm_src3);
				ymm_dst2 = _mm256_unpacklo_epi8(ymm_src4, ymm_src5);
				ymm_dst3 = _mm256_unpacklo_epi8(ymm_src6, ymm_src7);
				ymm_dst4 = _mm256_unpacklo_epi8(ymm_src8, ymm_src9);
				ymm_dst5 = _mm256_unpacklo_epi8(ymm_srca, ymm_srcb);
				ymm_dst6 = _mm256_unpacklo_epi8(ymm_srcc, ymm_srcd);
				ymm_dst7 = _mm256_unpacklo_epi8(ymm_srce, ymm_srcf);
				ymm_dst8 = _mm256_unpackhi_epi8(ymm_src0, ymm_src1);
				ymm_dst9 = _mm256_unpackhi_epi8(ymm_src2, ymm_src3);
				ymm_dsta = _mm256_unpackhi_epi8(ymm_src4, ymm_src5);
				ymm_dstb = _mm256_unpackhi_epi8(ymm_src6, ymm_src7);
				ymm_dstc = _mm256_unpackhi_epi8(ymm_src8, ymm_src9);
				ymm_dstd = _mm256_unpackhi_epi8(ymm_srca, ymm_srcb);
				ymm_dste = _mm256_unpackhi_epi8(ymm_srcc, ymm_srcd);
				ymm_dstf = _mm256_unpackhi_epi8(ymm_srce, ymm_srcf);
				ymm_src0 = _mm256_unpacklo_epi16(ymm_dst0, ymm_dst1);
				ymm_src1 = _mm256_unpacklo_epi16(ymm_dst2, ymm_dst3);
				ymm_src2 = _mm256_unpacklo_epi16(ymm_dst4, ymm_dst5);
				ymm_src3 = _mm256_unpacklo_epi16(ymm_dst6, ymm_dst7);
				ymm_src4 = _mm256_unpackhi_epi16(ymm_dst0, ymm_dst1);
				ymm_src5 = _mm256_unpackhi_epi16(ymm_dst2, ymm_dst3);
				ymm_src6 = _mm256_unpackhi_epi16(ymm_dst4, ymm_dst5);
				ymm_src7 = _mm256_unpackhi_epi16(ymm_dst6, ymm_dst7);
				ymm_src8 = _mm256_unpacklo_epi16(ymm_dst8, ymm_dst9);
				ymm_src9 = _mm256_unpacklo_epi16(ymm_dsta, ymm_dstb);
				ymm_srca = _mm256_unpacklo_epi16(ymm_dstc, ymm_dstd);
				ymm_srcb = _mm256_unpacklo_epi16(ymm_dste, ymm_dstf);
				ymm_srcc = _mm256_unpackhi_epi16(ymm_dst8, ymm_dst9);
				ymm_srcd = _mm256_unpackhi_epi16(ymm_dsta, ymm_dstb);
				ymm_srce = _mm256_unpackhi_epi16(ymm_dstc, ymm_dstd);
				ymm_srcf = _mm256_unpackhi_epi16(ymm_dste, ymm_dstf);
				ymm_dst0 = _mm256_unpacklo_epi32(ymm_src0, ymm_src1);
				ymm_dst1 = _mm256_unpacklo_epi32(ymm_src2, ymm_src3);
				ymm_dst2 = _mm256_unpackhi_epi32(ymm_src0, ymm_src1);
				ymm_dst3 = _mm256_unpackhi_epi32(ymm_src2, ymm_src3);
				ymm_dst4 = _mm256_unpacklo_epi32(ymm_src4, ymm_src5);
				ymm_dst5 = _mm256_unpacklo_epi32(ymm_src6, ymm_src7);
				ymm_dst6 = _mm256_unpackhi_epi32(ymm_src4, ymm_src5);
				ymm_dst7 = _mm256_unpackhi_epi32(ymm_src6, ymm_src7);
				ymm_dst8 = _mm256_unpacklo_epi32(ymm_src8, ymm_src9);
				ymm_dst9 = _mm256_unpacklo_epi32(ymm_srca, ymm_srcb);
				ymm_dsta = _mm256_unpackhi_epi32(ymm_src8, ymm_src9);
				ymm_dstb = _mm256_unpackhi_epi32(ymm_srca, ymm_srcb);
				ymm_dstc = _mm256_unpacklo_epi32(ymm_srcc, ymm_srcd);
				ymm_dstd = _mm256_unpacklo_epi32(ymm_srce, ymm_srcf);
				ymm_dste = _mm256_unpackhi_epi32(ymm_srcc, ymm_srcd);
				ymm_dstf = _mm256_unpackhi_epi32(ymm_srce, ymm_srcf);
				ymm_src0 = _mm256_unpacklo_epi64(ymm_dst0, ymm_dst1);
				ymm_src1 = _mm256_unpackhi_epi64(ymm_dst0, ymm_dst1);
				ymm_src2 = _mm256_unpacklo_epi64(ymm_dst2, ymm_dst3);
				ymm_src3 = _mm256_unpackhi_epi64(ymm_dst2, ymm_dst3);
				ymm_src4 = _mm256_unpacklo_epi64(ymm_dst4, ymm_dst5);
				ymm_src5 = _mm256_unpackhi_epi64(ymm_dst4, ymm_dst5);
				ymm_src6 = _mm256_unpacklo_epi64(ymm_dst6, ymm_dst7);
				ymm_src7 = _mm256_unpackhi_epi64(ymm_dst6, ymm_dst7);
				ymm_src8 = _mm256_unpacklo_epi64(ymm_dst8, ymm_dst9);
				ymm_src9 = _mm256_unpackhi_epi64(ymm_dst8, ymm_dst9);
				ymm_srca = _mm256_unpacklo_epi64(ymm_dsta, ymm_dstb);
				ymm_srcb = _mm256_unpackhi_epi64(ymm_dsta, ymm_dstb);
				ymm_srcc = _mm256_unpacklo_epi64(ymm_dstc, ymm_dstd);
				ymm_srcd = _mm256_unpackhi_epi64(ymm_dstc, ymm_dstd);
				ymm_srce = _mm256_unpacklo_epi64(ymm_dste, ymm_dstf);
				ymm_srcf = _mm256_unpackhi_epi64(ymm_dste, ymm_dstf);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst[0]), ymm_src0);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst[1]), ymm_src1);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst[2]), ymm_src2);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst[3]), ymm_src3);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst[4]), ymm_src4);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst[5]), ymm_src5);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst[6]), ymm_src6);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst[7]), ymm_src7);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst[8]), ymm_src8);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst[9]), ymm_src9);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst[10]), ymm_srca);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst[11]), ymm_srcb);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst[12]), ymm_srcc);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst[13]), ymm_srcd);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst[14]), ymm_srce);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst[15]), ymm_srcf);
				ptr_src[0] += 16;
				ptr_src[1] += 16;
				ptr_src[2] += 16;
				ptr_src[3] += 16;
				ptr_src[4] += 16;
				ptr_src[5] += 16;
				ptr_src[6] += 16;
				ptr_src[7] += 16;
				ptr_src[8] += 16;
				ptr_src[9] += 16;
				ptr_src[10] += 16;
				ptr_src[11] += 16;
				ptr_src[12] += 16;
				ptr_src[13] += 16;
				ptr_src[14] += 16;
				ptr_src[15] += 16;
				ptr_src[16] += 16;
				ptr_src[17] += 16;
				ptr_src[18] += 16;
				ptr_src[19] += 16;
				ptr_src[20] += 16;
				ptr_src[21] += 16;
				ptr_src[22] += 16;
				ptr_src[23] += 16;
				ptr_src[24] += 16;
				ptr_src[25] += 16;
				ptr_src[26] += 16;
				ptr_src[27] += 16;
				ptr_src[28] += 16;
				ptr_src[29] += 16;
				ptr_src[30] += 16;
				ptr_src[31] += 16;
				ptr_dst[0] += dst_step;
				ptr_dst[1] += dst_step;
				ptr_dst[2] += dst_step;
				ptr_dst[3] += dst_step;
				ptr_dst[4] += dst_step;
				ptr_dst[5] += dst_step;
				ptr_dst[6] += dst_step;
				ptr_dst[7] += dst_step;
				ptr_dst[8] += dst_step;
				ptr_dst[9] += dst_step;
				ptr_dst[10] += dst_step;
				ptr_dst[11] += dst_step;
				ptr_dst[12] += dst_step;
				ptr_dst[13] += dst_step;
				ptr_dst[14] += dst_step;
				ptr_dst[15] += dst_step;
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

		// Function template impl_trpi8

		void impl_trpi8(signed char* dst, size_t dst_rs, const signed char* src, size_t src_rs, size_t m, size_t n)
		{
			constexpr size_t block_m = 32;
			constexpr size_t block_n = 16;
			const size_t src_step = block_m * src_rs;

			for (; m >= block_m; m -= block_m)
			{
				trpi8_avx2(dst, dst_rs, src, src_rs, n);
				src += src_step;
				dst += block_n;
			}
			for (size_t i = 0; i < m; ++i)
			{
				trpi8_tiny(dst + i, dst_rs, src, src_rs, n);
				src += src_rs;
			}
		}
		
	#elif defined(__AVX__) || defined(__SSE4_2__) || defined(__SSE4_1__) || defined(__SSSE3__) || defined(__SSE3__) || defined(__SSE2__)

		// Function template trpi8_sse2

		void trpi8_sse2(signed char* dst, size_t dst_rs, const signed char* src, size_t src_rs, size_t n)
		{
			const size_t dst_step = 16 * dst_rs;
			signed char* ptr_dst[16] = { dst };
			const signed char* ptr_src[16] = { src };
			__m128i xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128i xmm_src8, xmm_src9, xmm_srca, xmm_srcb, xmm_srcc, xmm_srcd, xmm_srce, xmm_srcf;
			__m128i xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3, xmm_dst4, xmm_dst5, xmm_dst6, xmm_dst7;
			__m128i xmm_dst8, xmm_dst9, xmm_dsta, xmm_dstb, xmm_dstc, xmm_dstd, xmm_dste, xmm_dstf;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			for (size_t i = 1; i < 16; ++i)
			{
				ptr_src[i] = ptr_src[i - 1] + src_rs;
				ptr_dst[i] = ptr_dst[i - 1] + dst_rs;
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[i]), _MM_HINT_NTA);
			}
			for (; n >= 16; n -= 16)
			{
				xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[0]));
				xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[1]));
				xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[2]));
				xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[3]));
				xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[4]));
				xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[5]));
				xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[6]));
				xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[7]));
				xmm_src8 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[8]));
				xmm_src9 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[9]));
				xmm_srca = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[10]));
				xmm_srcb = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[11]));
				xmm_srcc = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[12]));
				xmm_srcd = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[13]));
				xmm_srce = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[14]));
				xmm_srcf = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src[15]));
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[0]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[1]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[2]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[3]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[4]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[5]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[6]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[7]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[8]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[9]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[10]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[11]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[12]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[13]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[14]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_src[15]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_dst[0]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_dst[1]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_dst[2]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_dst[3]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_dst[4]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_dst[5]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_dst[6]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_dst[7]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_dst[8]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_dst[9]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_dst[10]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_dst[11]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_dst[12]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_dst[13]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_dst[14]), _MM_HINT_NTA);
				_mm_prefetch(reinterpret_cast<const char*>(ptr_dst[15]), _MM_HINT_NTA);
				xmm_dst0 = _mm_unpacklo_epi8(xmm_src0, xmm_src1);
				xmm_dst1 = _mm_unpacklo_epi8(xmm_src2, xmm_src3);
				xmm_dst2 = _mm_unpacklo_epi8(xmm_src4, xmm_src5);
				xmm_dst3 = _mm_unpacklo_epi8(xmm_src6, xmm_src7);
				xmm_dst4 = _mm_unpacklo_epi8(xmm_src8, xmm_src9);
				xmm_dst5 = _mm_unpacklo_epi8(xmm_srca, xmm_srcb);
				xmm_dst6 = _mm_unpacklo_epi8(xmm_srcc, xmm_srcd);
				xmm_dst7 = _mm_unpacklo_epi8(xmm_srce, xmm_srcf);
				xmm_dst8 = _mm_unpackhi_epi8(xmm_src0, xmm_src1);
				xmm_dst9 = _mm_unpackhi_epi8(xmm_src2, xmm_src3);
				xmm_dsta = _mm_unpackhi_epi8(xmm_src4, xmm_src5);
				xmm_dstb = _mm_unpackhi_epi8(xmm_src6, xmm_src7);
				xmm_dstc = _mm_unpackhi_epi8(xmm_src8, xmm_src9);
				xmm_dstd = _mm_unpackhi_epi8(xmm_srca, xmm_srcb);
				xmm_dste = _mm_unpackhi_epi8(xmm_srcc, xmm_srcd);
				xmm_dstf = _mm_unpackhi_epi8(xmm_srce, xmm_srcf);
				xmm_src0 = _mm_unpacklo_epi16(xmm_dst0, xmm_dst1);
				xmm_src1 = _mm_unpacklo_epi16(xmm_dst2, xmm_dst3);
				xmm_src2 = _mm_unpacklo_epi16(xmm_dst4, xmm_dst5);
				xmm_src3 = _mm_unpacklo_epi16(xmm_dst6, xmm_dst7);
				xmm_src4 = _mm_unpackhi_epi16(xmm_dst0, xmm_dst1);
				xmm_src5 = _mm_unpackhi_epi16(xmm_dst2, xmm_dst3);
				xmm_src6 = _mm_unpackhi_epi16(xmm_dst4, xmm_dst5);
				xmm_src7 = _mm_unpackhi_epi16(xmm_dst6, xmm_dst7);
				xmm_src8 = _mm_unpacklo_epi16(xmm_dst8, xmm_dst9);
				xmm_src9 = _mm_unpacklo_epi16(xmm_dsta, xmm_dstb);
				xmm_srca = _mm_unpacklo_epi16(xmm_dstc, xmm_dstd);
				xmm_srcb = _mm_unpacklo_epi16(xmm_dste, xmm_dstf);
				xmm_srcc = _mm_unpackhi_epi16(xmm_dst8, xmm_dst9);
				xmm_srcd = _mm_unpackhi_epi16(xmm_dsta, xmm_dstb);
				xmm_srce = _mm_unpackhi_epi16(xmm_dstc, xmm_dstd);
				xmm_srcf = _mm_unpackhi_epi16(xmm_dste, xmm_dstf);
				xmm_dst0 = _mm_unpacklo_epi32(xmm_src0, xmm_src1);
				xmm_dst1 = _mm_unpacklo_epi32(xmm_src2, xmm_src3);
				xmm_dst2 = _mm_unpackhi_epi32(xmm_src0, xmm_src1);
				xmm_dst3 = _mm_unpackhi_epi32(xmm_src2, xmm_src3);
				xmm_dst4 = _mm_unpacklo_epi32(xmm_src4, xmm_src5);
				xmm_dst5 = _mm_unpacklo_epi32(xmm_src6, xmm_src7);
				xmm_dst6 = _mm_unpackhi_epi32(xmm_src4, xmm_src5);
				xmm_dst7 = _mm_unpackhi_epi32(xmm_src6, xmm_src7);
				xmm_dst8 = _mm_unpacklo_epi32(xmm_src8, xmm_src9);
				xmm_dst9 = _mm_unpacklo_epi32(xmm_srca, xmm_srcb);
				xmm_dsta = _mm_unpackhi_epi32(xmm_src8, xmm_src9);
				xmm_dstb = _mm_unpackhi_epi32(xmm_srca, xmm_srcb);
				xmm_dstc = _mm_unpacklo_epi32(xmm_srcc, xmm_srcd);
				xmm_dstd = _mm_unpacklo_epi32(xmm_srce, xmm_srcf);
				xmm_dste = _mm_unpackhi_epi32(xmm_srcc, xmm_srcd);
				xmm_dstf = _mm_unpackhi_epi32(xmm_srce, xmm_srcf);
				xmm_src0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
				xmm_src1 = _mm_unpackhi_epi64(xmm_dst0, xmm_dst1);
				xmm_src2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
				xmm_src3 = _mm_unpackhi_epi64(xmm_dst2, xmm_dst3);
				xmm_src4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
				xmm_src5 = _mm_unpackhi_epi64(xmm_dst4, xmm_dst5);
				xmm_src6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
				xmm_src7 = _mm_unpackhi_epi64(xmm_dst6, xmm_dst7);
				xmm_src8 = _mm_unpacklo_epi64(xmm_dst8, xmm_dst9);
				xmm_src9 = _mm_unpackhi_epi64(xmm_dst8, xmm_dst9);
				xmm_srca = _mm_unpacklo_epi64(xmm_dsta, xmm_dstb);
				xmm_srcb = _mm_unpackhi_epi64(xmm_dsta, xmm_dstb);
				xmm_srcc = _mm_unpacklo_epi64(xmm_dstc, xmm_dstd);
				xmm_srcd = _mm_unpackhi_epi64(xmm_dstc, xmm_dstd);
				xmm_srce = _mm_unpacklo_epi64(xmm_dste, xmm_dstf);
				xmm_srcf = _mm_unpackhi_epi64(xmm_dste, xmm_dstf);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst[0]), xmm_src0);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst[1]), xmm_src1);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst[2]), xmm_src2);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst[3]), xmm_src3);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst[4]), xmm_src4);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst[5]), xmm_src5);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst[6]), xmm_src6);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst[7]), xmm_src7);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst[8]), xmm_src8);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst[9]), xmm_src9);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst[10]), xmm_srca);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst[11]), xmm_srcb);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst[12]), xmm_srcc);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst[13]), xmm_srcd);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst[14]), xmm_srce);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst[15]), xmm_srcf);
				ptr_src[0] += 16;
				ptr_src[1] += 16;
				ptr_src[2] += 16;
				ptr_src[3] += 16;
				ptr_src[4] += 16;
				ptr_src[5] += 16;
				ptr_src[6] += 16;
				ptr_src[7] += 16;
				ptr_src[8] += 16;
				ptr_src[9] += 16;
				ptr_src[10] += 16;
				ptr_src[11] += 16;
				ptr_src[12] += 16;
				ptr_src[13] += 16;
				ptr_src[14] += 16;
				ptr_src[15] += 16;
				ptr_dst[0] += dst_step;
				ptr_dst[1] += dst_step;
				ptr_dst[2] += dst_step;
				ptr_dst[3] += dst_step;
				ptr_dst[4] += dst_step;
				ptr_dst[5] += dst_step;
				ptr_dst[6] += dst_step;
				ptr_dst[7] += dst_step;
				ptr_dst[8] += dst_step;
				ptr_dst[9] += dst_step;
				ptr_dst[10] += dst_step;
				ptr_dst[11] += dst_step;
				ptr_dst[12] += dst_step;
				ptr_dst[13] += dst_step;
				ptr_dst[14] += dst_step;
				ptr_dst[15] += dst_step;
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

		// Function template impl_trpi8

		void impl_trpi8(signed char* dst, size_t dst_rs, const signed char* src, size_t src_rs, size_t m, size_t n)
		{
			constexpr size_t block_m = 16;
			constexpr size_t block_n = 16;
			const size_t src_step = block_m * src_rs;

			for (; m >= block_m; m -= block_m)
			{
				trpi8_sse2(dst, dst_rs, src, src_rs, n);
				src += src_step;
				dst += block_n;
			}
			for (size_t i = 0; i < m; ++i)
			{
				trpi8_tiny(dst + i, dst_rs, src, src_rs, n);
				src += src_rs;
			}
		}

	#else

		// Function template trpi8

		void trpi8(signed char* dst, size_t dst_rs, const signed char* src, size_t src_rs, size_t n)
		{
			const size_t dst_step = 4 * dst_rs;
			const signed char* ptr_src0 = src;
			const signed char* ptr_src1 = ptr_src0 + src_rs;
			const signed char* ptr_src2 = ptr_src1 + src_rs;
			const signed char* ptr_src3 = ptr_src2 + src_rs;
			signed char* ptr_dst0 = dst;
			signed char* ptr_dst1 = ptr_dst0 + dst_rs;
			signed char* ptr_dst2 = ptr_dst1 + dst_rs;
			signed char* ptr_dst3 = ptr_dst2 + dst_rs;

			for (; n >= 4; n -= 4)
			{
				ptr_dst0[0] = ptr_src0[0];
				ptr_dst1[0] = ptr_src0[1];
				ptr_dst2[0] = ptr_src0[2];
				ptr_dst3[0] = ptr_src0[3];
				ptr_dst0[1] = ptr_src1[0];
				ptr_dst1[1] = ptr_src1[1];
				ptr_dst2[1] = ptr_src1[2];
				ptr_dst3[1] = ptr_src1[3];
				ptr_dst0[2] = ptr_src2[0];
				ptr_dst1[2] = ptr_src2[1];
				ptr_dst2[2] = ptr_src2[2];
				ptr_dst3[2] = ptr_src2[3];
				ptr_dst0[3] = ptr_src3[0];
				ptr_dst1[3] = ptr_src3[1];
				ptr_dst2[3] = ptr_src3[2];
				ptr_dst3[3] = ptr_src3[3];
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

		// Function template impl_trpi8

		void impl_trpi8(signed char* dst, const signed char* src, size_t m, size_t n)
		{
			constexpr size_t block_m = 4;
			constexpr size_t block_n = 4;
			const size_t src_step = block_m * src_rs;

			for (; m >= block_m; m -= block_m)
			{
				trpi8(dst, dst_rs, src, src_rs, n);
				src += src_step;
				dst += block_n;
			}
			for (size_t i = 0; i < m; ++i)
			{
				trpi8_tiny(dst + i, dst_rs, src, src_rs, n);
				src += src_rs;
			}
		}

	#endif

	} // namespace cpu

} // namespace core

#endif
