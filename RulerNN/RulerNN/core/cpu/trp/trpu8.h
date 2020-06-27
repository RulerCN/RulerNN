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

#ifndef __CORE_CPU_TRPU8_H__
#define __CORE_CPU_TRPU8_H__

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

	#ifdef __AVX2__

		// Specialize for unsigned char

		template <>
		constexpr size_t trp_block_m<unsigned char>(void)
		{
			return static_cast<size_t>(32);
		}

		template <>
		constexpr size_t trp_block_n<unsigned char>(void)
		{
			return static_cast<size_t>(16);
		}

		template <>
		inline void trp_block<unsigned char>(unsigned char* dst, size_t dst_rs, const unsigned char* src, size_t src_rs)
		{
			unsigned char* ptr_dst0 = dst;
			unsigned char* ptr_dst1 = ptr_dst0 + dst_rs;
			unsigned char* ptr_dst2 = ptr_dst1 + dst_rs;
			unsigned char* ptr_dst3 = ptr_dst2 + dst_rs;
			unsigned char* ptr_dst4 = ptr_dst3 + dst_rs;
			unsigned char* ptr_dst5 = ptr_dst4 + dst_rs;
			unsigned char* ptr_dst6 = ptr_dst5 + dst_rs;
			unsigned char* ptr_dst7 = ptr_dst6 + dst_rs;
			unsigned char* ptr_dst8 = ptr_dst7 + dst_rs;
			unsigned char* ptr_dst9 = ptr_dst8 + dst_rs;
			unsigned char* ptr_dsta = ptr_dst9 + dst_rs;
			unsigned char* ptr_dstb = ptr_dsta + dst_rs;
			unsigned char* ptr_dstc = ptr_dstb + dst_rs;
			unsigned char* ptr_dstd = ptr_dstc + dst_rs;
			unsigned char* ptr_dste = ptr_dstd + dst_rs;
			unsigned char* ptr_dstf = ptr_dste + dst_rs;
			const unsigned char* ptr_src0 = src;
			const unsigned char* ptr_src1 = ptr_src0 + src_rs;
			const unsigned char* ptr_src2 = ptr_src1 + src_rs;
			const unsigned char* ptr_src3 = ptr_src2 + src_rs;
			const unsigned char* ptr_src4 = ptr_src3 + src_rs;
			const unsigned char* ptr_src5 = ptr_src4 + src_rs;
			const unsigned char* ptr_src6 = ptr_src5 + src_rs;
			const unsigned char* ptr_src7 = ptr_src6 + src_rs;
			const unsigned char* ptr_src8 = ptr_src7 + dst_rs;
			const unsigned char* ptr_src9 = ptr_src8 + dst_rs;
			const unsigned char* ptr_srca = ptr_src9 + dst_rs;
			const unsigned char* ptr_srcb = ptr_srca + dst_rs;
			const unsigned char* ptr_srcc = ptr_srcb + dst_rs;
			const unsigned char* ptr_srcd = ptr_srcc + dst_rs;
			const unsigned char* ptr_srce = ptr_srcd + dst_rs;
			const unsigned char* ptr_srcf = ptr_srce + dst_rs;
			const unsigned char* ptr_srcg = ptr_srcf + dst_rs;
			const unsigned char* ptr_srch = ptr_srcg + src_rs;
			const unsigned char* ptr_srci = ptr_srch + src_rs;
			const unsigned char* ptr_srcj = ptr_srci + src_rs;
			const unsigned char* ptr_srck = ptr_srcj + src_rs;
			const unsigned char* ptr_srcl = ptr_srck + src_rs;
			const unsigned char* ptr_srcm = ptr_srcl + src_rs;
			const unsigned char* ptr_srcn = ptr_srcm + src_rs;
			const unsigned char* ptr_srco = ptr_srcn + dst_rs;
			const unsigned char* ptr_srcp = ptr_srco + dst_rs;
			const unsigned char* ptr_srcq = ptr_srcp + dst_rs;
			const unsigned char* ptr_srcr = ptr_srcq + dst_rs;
			const unsigned char* ptr_srcs = ptr_srcr + dst_rs;
			const unsigned char* ptr_srct = ptr_srcs + dst_rs;
			const unsigned char* ptr_srcu = ptr_srct + dst_rs;
			const unsigned char* ptr_srcv = ptr_srcu + dst_rs;
			__m256i ymm_src0 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src0)));
			__m256i ymm_src1 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src1)));
			__m256i ymm_src2 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src2)));
			__m256i ymm_src3 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src3)));
			__m256i ymm_src4 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src4)));
			__m256i ymm_src5 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src5)));
			__m256i ymm_src6 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src6)));
			__m256i ymm_src7 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src7)));
			__m256i ymm_src8 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src8)));
			__m256i ymm_src9 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src9)));
			__m256i ymm_srca = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_srca)));
			__m256i ymm_srcb = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_srcb)));
			__m256i ymm_srcc = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_srcc)));
			__m256i ymm_srcd = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_srcd)));
			__m256i ymm_srce = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_srce)));
			__m256i ymm_srcf = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_srcf)));
			__m256i ymm_dst0 = _mm256_insertf128_si256(ymm_src0, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_srcg)), 1);
			__m256i ymm_dst1 = _mm256_insertf128_si256(ymm_src1, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_srch)), 1);
			__m256i ymm_dst2 = _mm256_insertf128_si256(ymm_src2, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_srci)), 1);
			__m256i ymm_dst3 = _mm256_insertf128_si256(ymm_src3, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_srcj)), 1);
			__m256i ymm_dst4 = _mm256_insertf128_si256(ymm_src4, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_srck)), 1);
			__m256i ymm_dst5 = _mm256_insertf128_si256(ymm_src5, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_srcl)), 1);
			__m256i ymm_dst6 = _mm256_insertf128_si256(ymm_src6, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_srcm)), 1);
			__m256i ymm_dst7 = _mm256_insertf128_si256(ymm_src7, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_srcn)), 1);
			__m256i ymm_dst8 = _mm256_insertf128_si256(ymm_src8, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_srco)), 1);
			__m256i ymm_dst9 = _mm256_insertf128_si256(ymm_src9, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_srcp)), 1);
			__m256i ymm_dsta = _mm256_insertf128_si256(ymm_srca, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_srcq)), 1);
			__m256i ymm_dstb = _mm256_insertf128_si256(ymm_srcb, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_srcr)), 1);
			__m256i ymm_dstc = _mm256_insertf128_si256(ymm_srcc, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_srcs)), 1);
			__m256i ymm_dstd = _mm256_insertf128_si256(ymm_srcd, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_srct)), 1);
			__m256i ymm_dste = _mm256_insertf128_si256(ymm_srce, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_srcu)), 1);
			__m256i ymm_dstf = _mm256_insertf128_si256(ymm_srcf, _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_srcv)), 1);
			ymm_src0 = _mm256_unpacklo_epi8(ymm_dst0, ymm_dst1);
			ymm_src1 = _mm256_unpacklo_epi8(ymm_dst2, ymm_dst3);
			ymm_src2 = _mm256_unpacklo_epi8(ymm_dst4, ymm_dst5);
			ymm_src3 = _mm256_unpacklo_epi8(ymm_dst6, ymm_dst7);
			ymm_src4 = _mm256_unpacklo_epi8(ymm_dst8, ymm_dst9);
			ymm_src5 = _mm256_unpacklo_epi8(ymm_dsta, ymm_dstb);
			ymm_src6 = _mm256_unpacklo_epi8(ymm_dstc, ymm_dstd);
			ymm_src7 = _mm256_unpacklo_epi8(ymm_dste, ymm_dstf);
			ymm_src8 = _mm256_unpackhi_epi8(ymm_dst0, ymm_dst1);
			ymm_src9 = _mm256_unpackhi_epi8(ymm_dst2, ymm_dst3);
			ymm_srca = _mm256_unpackhi_epi8(ymm_dst4, ymm_dst5);
			ymm_srcb = _mm256_unpackhi_epi8(ymm_dst6, ymm_dst7);
			ymm_srcc = _mm256_unpackhi_epi8(ymm_dst8, ymm_dst9);
			ymm_srcd = _mm256_unpackhi_epi8(ymm_dsta, ymm_dstb);
			ymm_srce = _mm256_unpackhi_epi8(ymm_dstc, ymm_dstd);
			ymm_srcf = _mm256_unpackhi_epi8(ymm_dste, ymm_dstf);
			ymm_dst0 = _mm256_unpacklo_epi16(ymm_src0, ymm_src1);
			ymm_dst1 = _mm256_unpacklo_epi16(ymm_src2, ymm_src3);
			ymm_dst2 = _mm256_unpacklo_epi16(ymm_src4, ymm_src5);
			ymm_dst3 = _mm256_unpacklo_epi16(ymm_src6, ymm_src7);
			ymm_dst4 = _mm256_unpackhi_epi16(ymm_src0, ymm_src1);
			ymm_dst5 = _mm256_unpackhi_epi16(ymm_src2, ymm_src3);
			ymm_dst6 = _mm256_unpackhi_epi16(ymm_src4, ymm_src5);
			ymm_dst7 = _mm256_unpackhi_epi16(ymm_src6, ymm_src7);
			ymm_dst8 = _mm256_unpacklo_epi16(ymm_src8, ymm_src9);
			ymm_dst9 = _mm256_unpacklo_epi16(ymm_srca, ymm_srcb);
			ymm_dsta = _mm256_unpacklo_epi16(ymm_srcc, ymm_srcd);
			ymm_dstb = _mm256_unpacklo_epi16(ymm_srce, ymm_srcf);
			ymm_dstc = _mm256_unpackhi_epi16(ymm_src8, ymm_src9);
			ymm_dstd = _mm256_unpackhi_epi16(ymm_srca, ymm_srcb);
			ymm_dste = _mm256_unpackhi_epi16(ymm_srcc, ymm_srcd);
			ymm_dstf = _mm256_unpackhi_epi16(ymm_srce, ymm_srcf);
			ymm_src0 = _mm256_unpacklo_epi32(ymm_dst0, ymm_dst1);
			ymm_src1 = _mm256_unpacklo_epi32(ymm_dst2, ymm_dst3);
			ymm_src2 = _mm256_unpackhi_epi32(ymm_dst0, ymm_dst1);
			ymm_src3 = _mm256_unpackhi_epi32(ymm_dst2, ymm_dst3);
			ymm_src4 = _mm256_unpacklo_epi32(ymm_dst4, ymm_dst5);
			ymm_src5 = _mm256_unpacklo_epi32(ymm_dst6, ymm_dst7);
			ymm_src6 = _mm256_unpackhi_epi32(ymm_dst4, ymm_dst5);
			ymm_src7 = _mm256_unpackhi_epi32(ymm_dst6, ymm_dst7);
			ymm_src8 = _mm256_unpacklo_epi32(ymm_dst8, ymm_dst9);
			ymm_src9 = _mm256_unpacklo_epi32(ymm_dsta, ymm_dstb);
			ymm_srca = _mm256_unpackhi_epi32(ymm_dst8, ymm_dst9);
			ymm_srcb = _mm256_unpackhi_epi32(ymm_dsta, ymm_dstb);
			ymm_srcc = _mm256_unpacklo_epi32(ymm_dstc, ymm_dstd);
			ymm_srcd = _mm256_unpacklo_epi32(ymm_dste, ymm_dstf);
			ymm_srce = _mm256_unpackhi_epi32(ymm_dstc, ymm_dstd);
			ymm_srcf = _mm256_unpackhi_epi32(ymm_dste, ymm_dstf);
			ymm_dst0 = _mm256_unpacklo_epi64(ymm_src0, ymm_src1);
			ymm_dst1 = _mm256_unpackhi_epi64(ymm_src0, ymm_src1);
			ymm_dst2 = _mm256_unpacklo_epi64(ymm_src2, ymm_src3);
			ymm_dst3 = _mm256_unpackhi_epi64(ymm_src2, ymm_src3);
			ymm_dst4 = _mm256_unpacklo_epi64(ymm_src4, ymm_src5);
			ymm_dst5 = _mm256_unpackhi_epi64(ymm_src4, ymm_src5);
			ymm_dst6 = _mm256_unpacklo_epi64(ymm_src6, ymm_src7);
			ymm_dst7 = _mm256_unpackhi_epi64(ymm_src6, ymm_src7);
			ymm_dst8 = _mm256_unpacklo_epi64(ymm_src8, ymm_src9);
			ymm_dst9 = _mm256_unpackhi_epi64(ymm_src8, ymm_src9);
			ymm_dsta = _mm256_unpacklo_epi64(ymm_srca, ymm_srcb);
			ymm_dstb = _mm256_unpackhi_epi64(ymm_srca, ymm_srcb);
			ymm_dstc = _mm256_unpacklo_epi64(ymm_srcc, ymm_srcd);
			ymm_dstd = _mm256_unpackhi_epi64(ymm_srcc, ymm_srcd);
			ymm_dste = _mm256_unpacklo_epi64(ymm_srce, ymm_srcf);
			ymm_dstf = _mm256_unpackhi_epi64(ymm_srce, ymm_srcf);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst0), ymm_dst0);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst1), ymm_dst1);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst2), ymm_dst2);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst3), ymm_dst3);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst4), ymm_dst4);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst5), ymm_dst5);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst6), ymm_dst6);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst7), ymm_dst7);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst8), ymm_dst8);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dst9), ymm_dst9);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dsta), ymm_dsta);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dstb), ymm_dstb);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dstc), ymm_dstc);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dstd), ymm_dstd);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dste), ymm_dste);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(ptr_dstf), ymm_dstf);
		}
		
		template <>
		inline void trp_tiny<unsigned char>(unsigned char* dst, size_t dst_rs, const unsigned char* src, size_t src_rs, size_t m, size_t n)
		{
			const size_t row0 = 0;
			const size_t row1 = dst_rs;
			const size_t row2 = row1 + dst_rs;
			const size_t row3 = row2 + dst_rs;
			const size_t row4 = row3 + dst_rs;
			const size_t row5 = row4 + dst_rs;
			const size_t row6 = row5 + dst_rs;
			const size_t row7 = row6 + dst_rs;
			const size_t row8 = row7 + dst_rs;
			const size_t row9 = row8 + dst_rs;
			const size_t rowa = row9 + dst_rs;
			const size_t rowb = rowa + dst_rs;
			const size_t rowc = rowb + dst_rs;
			const size_t rowd = rowc + dst_rs;
			const size_t rowe = rowd + dst_rs;
			const size_t rowf = rowe + dst_rs;

			for (size_t i = 0; i < m; ++i)
			{
				switch (n)
				{
				case 16: dst[rowf + i] = src[15];
				case 15: dst[rowe + i] = src[14];
				case 14: dst[rowd + i] = src[13];
				case 13: dst[rowc + i] = src[12];
				case 12: dst[rowb + i] = src[11];
				case 11: dst[rowa + i] = src[10];
				case 10: dst[row9 + i] = src[9];
				case 9:  dst[row8 + i] = src[8];
				case 8:  dst[row7 + i] = src[7];
				case 7:  dst[row6 + i] = src[6];
				case 6:  dst[row5 + i] = src[5];
				case 5:  dst[row4 + i] = src[4];
				case 4:  dst[row3 + i] = src[3];
				case 3:  dst[row2 + i] = src[2];
				case 2:  dst[row1 + i] = src[1];
				case 1:  dst[row0 + i] = src[0];
					break;
				}
				src += src_rs;
			}
		}

	#elif defined(__AVX__) || defined(__SSE4_2__) || defined(__SSE4_1__) || defined(__SSSE3__) || defined(__SSE3__) || defined(__SSE2__)

		// Specialize for unsigned char

		template <>
		constexpr size_t trp_block_m<unsigned char>(void)
		{
			return static_cast<size_t>(16);
		}

		template <>
		constexpr size_t trp_block_n<unsigned char>(void)
		{
			return static_cast<size_t>(16);
		}

		template <>
		inline void trp_block<unsigned char>(unsigned char* dst, size_t dst_rs, const unsigned char* src, size_t src_rs)
		{
			unsigned char* ptr_dst0 = dst;
			unsigned char* ptr_dst1 = ptr_dst0 + dst_rs;
			unsigned char* ptr_dst2 = ptr_dst1 + dst_rs;
			unsigned char* ptr_dst3 = ptr_dst2 + dst_rs;
			unsigned char* ptr_dst4 = ptr_dst3 + dst_rs;
			unsigned char* ptr_dst5 = ptr_dst4 + dst_rs;
			unsigned char* ptr_dst6 = ptr_dst5 + dst_rs;
			unsigned char* ptr_dst7 = ptr_dst6 + dst_rs;
			unsigned char* ptr_dst8 = ptr_dst7 + dst_rs;
			unsigned char* ptr_dst9 = ptr_dst8 + dst_rs;
			unsigned char* ptr_dsta = ptr_dst9 + dst_rs;
			unsigned char* ptr_dstb = ptr_dsta + dst_rs;
			unsigned char* ptr_dstc = ptr_dstb + dst_rs;
			unsigned char* ptr_dstd = ptr_dstc + dst_rs;
			unsigned char* ptr_dste = ptr_dstd + dst_rs;
			unsigned char* ptr_dstf = ptr_dste + dst_rs;
			const unsigned char* ptr_src0 = src;
			const unsigned char* ptr_src1 = ptr_src0 + src_rs;
			const unsigned char* ptr_src2 = ptr_src1 + src_rs;
			const unsigned char* ptr_src3 = ptr_src2 + src_rs;
			const unsigned char* ptr_src4 = ptr_src3 + src_rs;
			const unsigned char* ptr_src5 = ptr_src4 + src_rs;
			const unsigned char* ptr_src6 = ptr_src5 + src_rs;
			const unsigned char* ptr_src7 = ptr_src6 + src_rs;
			const unsigned char* ptr_src8 = ptr_src7 + dst_rs;
			const unsigned char* ptr_src9 = ptr_src8 + dst_rs;
			const unsigned char* ptr_srca = ptr_src9 + dst_rs;
			const unsigned char* ptr_srcb = ptr_srca + dst_rs;
			const unsigned char* ptr_srcc = ptr_srcb + dst_rs;
			const unsigned char* ptr_srcd = ptr_srcc + dst_rs;
			const unsigned char* ptr_srce = ptr_srcd + dst_rs;
			const unsigned char* ptr_srcf = ptr_srce + dst_rs;
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src0));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src1));
			__m128i xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src2));
			__m128i xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src3));
			__m128i xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src4));
			__m128i xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src5));
			__m128i xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src6));
			__m128i xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src7));
			__m128i xmm_src8 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src8));
			__m128i xmm_src9 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_src9));
			__m128i xmm_srca = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_srca));
			__m128i xmm_srcb = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_srcb));
			__m128i xmm_srcc = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_srcc));
			__m128i xmm_srcd = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_srcd));
			__m128i xmm_srce = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_srce));
			__m128i xmm_srcf = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr_srcf));
			__m128i xmm_dst0 = _mm_unpacklo_epi8(xmm_src0, xmm_src1);
			__m128i xmm_dst1 = _mm_unpacklo_epi8(xmm_src2, xmm_src3);
			__m128i xmm_dst2 = _mm_unpacklo_epi8(xmm_src4, xmm_src5);
			__m128i xmm_dst3 = _mm_unpacklo_epi8(xmm_src6, xmm_src7);
			__m128i xmm_dst4 = _mm_unpacklo_epi8(xmm_src8, xmm_src9);
			__m128i xmm_dst5 = _mm_unpacklo_epi8(xmm_srca, xmm_srcb);
			__m128i xmm_dst6 = _mm_unpacklo_epi8(xmm_srcc, xmm_srcd);
			__m128i xmm_dst7 = _mm_unpacklo_epi8(xmm_srce, xmm_srcf);
			__m128i xmm_dst8 = _mm_unpackhi_epi8(xmm_src0, xmm_src1);
			__m128i xmm_dst9 = _mm_unpackhi_epi8(xmm_src2, xmm_src3);
			__m128i xmm_dsta = _mm_unpackhi_epi8(xmm_src4, xmm_src5);
			__m128i xmm_dstb = _mm_unpackhi_epi8(xmm_src6, xmm_src7);
			__m128i xmm_dstc = _mm_unpackhi_epi8(xmm_src8, xmm_src9);
			__m128i xmm_dstd = _mm_unpackhi_epi8(xmm_srca, xmm_srcb);
			__m128i xmm_dste = _mm_unpackhi_epi8(xmm_srcc, xmm_srcd);
			__m128i xmm_dstf = _mm_unpackhi_epi8(xmm_srce, xmm_srcf);
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
			_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst0), xmm_src0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst1), xmm_src1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst2), xmm_src2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst3), xmm_src3);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst4), xmm_src4);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst5), xmm_src5);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst6), xmm_src6);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst7), xmm_src7);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst8), xmm_src8);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dst9), xmm_src9);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dsta), xmm_srca);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dstb), xmm_srcb);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dstc), xmm_srcc);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dstd), xmm_srcd);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dste), xmm_srce);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(ptr_dstf), xmm_srcf);
		}

		template <>
		inline void trp_tiny<unsigned char>(unsigned char* dst, size_t dst_rs, const unsigned char* src, size_t src_rs, size_t m, size_t n)
		{
			const size_t row0 = 0;
			const size_t row1 = dst_rs;
			const size_t row2 = row1 + dst_rs;
			const size_t row3 = row2 + dst_rs;
			const size_t row4 = row3 + dst_rs;
			const size_t row5 = row4 + dst_rs;
			const size_t row6 = row5 + dst_rs;
			const size_t row7 = row6 + dst_rs;
			const size_t row8 = row7 + dst_rs;
			const size_t row9 = row8 + dst_rs;
			const size_t rowa = row9 + dst_rs;
			const size_t rowb = rowa + dst_rs;
			const size_t rowc = rowb + dst_rs;
			const size_t rowd = rowc + dst_rs;
			const size_t rowe = rowd + dst_rs;
			const size_t rowf = rowe + dst_rs;

			for (size_t i = 0; i < m; ++i)
			{
				switch (n)
				{
				case 16: dst[rowf + i] = src[15];
				case 15: dst[rowe + i] = src[14];
				case 14: dst[rowd + i] = src[13];
				case 13: dst[rowc + i] = src[12];
				case 12: dst[rowb + i] = src[11];
				case 11: dst[rowa + i] = src[10];
				case 10: dst[row9 + i] = src[9];
				case 9:  dst[row8 + i] = src[8];
				case 8:  dst[row7 + i] = src[7];
				case 7:  dst[row6 + i] = src[6];
				case 6:  dst[row5 + i] = src[5];
				case 5:  dst[row4 + i] = src[4];
				case 4:  dst[row3 + i] = src[3];
				case 3:  dst[row2 + i] = src[2];
				case 2:  dst[row1 + i] = src[1];
				case 1:  dst[row0 + i] = src[0];
					break;
				}
				src += src_rs;
			}
		}

	#endif

	} // namespace cpu

} // namespace core

#endif
