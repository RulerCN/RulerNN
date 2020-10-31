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
		// Function template trp_block_m
		template <class T> constexpr size_t trp_block_m(void);

		// Function template trp_block_n
		template <class T> constexpr size_t trp_block_n(void);

		// Function template trp_block
		template <class T> inline void trp_block(T* b, size_t ldb, const T* a, size_t lda);

		// Function template trp_tiny
		template <class T> inline void trp_tiny(T* b, size_t ldb, const T* a, size_t lda, size_t m, size_t n);

	#ifdef __AVX2__

		// Specialize for signed char

		template <>
		constexpr size_t trp_block_m<signed char>(void)
		{
			return static_cast<size_t>(32);
		}

		template <>
		constexpr size_t trp_block_n<signed char>(void)
		{
			return static_cast<size_t>(16);
		}

		template <>
		inline void trp_block<signed char>(signed char* b, size_t ldb, const signed char* a, size_t lda)
		{
			__m256i ymm_a0 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(a)));
			__m256i ymm_a1 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda)));
			__m256i ymm_a2 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 2)));
			__m256i ymm_a3 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 3)));
			__m256i ymm_a4 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 4)));
			__m256i ymm_a5 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 5)));
			__m256i ymm_a6 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 6)));
			__m256i ymm_a7 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 7)));
			__m256i ymm_a8 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 8)));
			__m256i ymm_a9 = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 9)));
			__m256i ymm_aa = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 10)));
			__m256i ymm_ab = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 11)));
			__m256i ymm_ac = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 12)));
			__m256i ymm_ad = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 13)));
			__m256i ymm_ae = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 14)));
			__m256i ymm_af = _mm256_castsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 15)));
			__m256i ymm_b0 = _mm256_insertf128_si256(ymm_a0, _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 16)), 1);
			__m256i ymm_b1 = _mm256_insertf128_si256(ymm_a1, _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 17)), 1);
			__m256i ymm_b2 = _mm256_insertf128_si256(ymm_a2, _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 18)), 1);
			__m256i ymm_b3 = _mm256_insertf128_si256(ymm_a3, _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 19)), 1);
			__m256i ymm_b4 = _mm256_insertf128_si256(ymm_a4, _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 20)), 1);
			__m256i ymm_b5 = _mm256_insertf128_si256(ymm_a5, _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 21)), 1);
			__m256i ymm_b6 = _mm256_insertf128_si256(ymm_a6, _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 22)), 1);
			__m256i ymm_b7 = _mm256_insertf128_si256(ymm_a7, _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 23)), 1);
			__m256i ymm_b8 = _mm256_insertf128_si256(ymm_a8, _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 24)), 1);
			__m256i ymm_b9 = _mm256_insertf128_si256(ymm_a9, _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 25)), 1);
			__m256i ymm_ba = _mm256_insertf128_si256(ymm_aa, _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 26)), 1);
			__m256i ymm_bb = _mm256_insertf128_si256(ymm_ab, _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 27)), 1);
			__m256i ymm_bc = _mm256_insertf128_si256(ymm_ac, _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 28)), 1);
			__m256i ymm_bd = _mm256_insertf128_si256(ymm_ad, _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 29)), 1);
			__m256i ymm_be = _mm256_insertf128_si256(ymm_ae, _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 30)), 1);
			__m256i ymm_bf = _mm256_insertf128_si256(ymm_af, _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 31)), 1);
			ymm_a0 = _mm256_unpacklo_epi8(ymm_b0, ymm_b1);
			ymm_a1 = _mm256_unpacklo_epi8(ymm_b2, ymm_b3);
			ymm_a2 = _mm256_unpacklo_epi8(ymm_b4, ymm_b5);
			ymm_a3 = _mm256_unpacklo_epi8(ymm_b6, ymm_b7);
			ymm_a4 = _mm256_unpacklo_epi8(ymm_b8, ymm_b9);
			ymm_a5 = _mm256_unpacklo_epi8(ymm_ba, ymm_bb);
			ymm_a6 = _mm256_unpacklo_epi8(ymm_bc, ymm_bd);
			ymm_a7 = _mm256_unpacklo_epi8(ymm_be, ymm_bf);
			ymm_a8 = _mm256_unpackhi_epi8(ymm_b0, ymm_b1);
			ymm_a9 = _mm256_unpackhi_epi8(ymm_b2, ymm_b3);
			ymm_aa = _mm256_unpackhi_epi8(ymm_b4, ymm_b5);
			ymm_ab = _mm256_unpackhi_epi8(ymm_b6, ymm_b7);
			ymm_ac = _mm256_unpackhi_epi8(ymm_b8, ymm_b9);
			ymm_ad = _mm256_unpackhi_epi8(ymm_ba, ymm_bb);
			ymm_ae = _mm256_unpackhi_epi8(ymm_bc, ymm_bd);
			ymm_af = _mm256_unpackhi_epi8(ymm_be, ymm_bf);
			ymm_b0 = _mm256_unpacklo_epi16(ymm_a0, ymm_a1);
			ymm_b1 = _mm256_unpacklo_epi16(ymm_a2, ymm_a3);
			ymm_b2 = _mm256_unpacklo_epi16(ymm_a4, ymm_a5);
			ymm_b3 = _mm256_unpacklo_epi16(ymm_a6, ymm_a7);
			ymm_b4 = _mm256_unpackhi_epi16(ymm_a0, ymm_a1);
			ymm_b5 = _mm256_unpackhi_epi16(ymm_a2, ymm_a3);
			ymm_b6 = _mm256_unpackhi_epi16(ymm_a4, ymm_a5);
			ymm_b7 = _mm256_unpackhi_epi16(ymm_a6, ymm_a7);
			ymm_b8 = _mm256_unpacklo_epi16(ymm_a8, ymm_a9);
			ymm_b9 = _mm256_unpacklo_epi16(ymm_aa, ymm_ab);
			ymm_ba = _mm256_unpacklo_epi16(ymm_ac, ymm_ad);
			ymm_bb = _mm256_unpacklo_epi16(ymm_ae, ymm_af);
			ymm_bc = _mm256_unpackhi_epi16(ymm_a8, ymm_a9);
			ymm_bd = _mm256_unpackhi_epi16(ymm_aa, ymm_ab);
			ymm_be = _mm256_unpackhi_epi16(ymm_ac, ymm_ad);
			ymm_bf = _mm256_unpackhi_epi16(ymm_ae, ymm_af);
			ymm_a0 = _mm256_unpacklo_epi32(ymm_b0, ymm_b1);
			ymm_a1 = _mm256_unpacklo_epi32(ymm_b2, ymm_b3);
			ymm_a2 = _mm256_unpackhi_epi32(ymm_b0, ymm_b1);
			ymm_a3 = _mm256_unpackhi_epi32(ymm_b2, ymm_b3);
			ymm_a4 = _mm256_unpacklo_epi32(ymm_b4, ymm_b5);
			ymm_a5 = _mm256_unpacklo_epi32(ymm_b6, ymm_b7);
			ymm_a6 = _mm256_unpackhi_epi32(ymm_b4, ymm_b5);
			ymm_a7 = _mm256_unpackhi_epi32(ymm_b6, ymm_b7);
			ymm_a8 = _mm256_unpacklo_epi32(ymm_b8, ymm_b9);
			ymm_a9 = _mm256_unpacklo_epi32(ymm_ba, ymm_bb);
			ymm_aa = _mm256_unpackhi_epi32(ymm_b8, ymm_b9);
			ymm_ab = _mm256_unpackhi_epi32(ymm_ba, ymm_bb);
			ymm_ac = _mm256_unpacklo_epi32(ymm_bc, ymm_bd);
			ymm_ad = _mm256_unpacklo_epi32(ymm_be, ymm_bf);
			ymm_ae = _mm256_unpackhi_epi32(ymm_bc, ymm_bd);
			ymm_af = _mm256_unpackhi_epi32(ymm_be, ymm_bf);
			ymm_b0 = _mm256_unpacklo_epi64(ymm_a0, ymm_a1);
			ymm_b1 = _mm256_unpackhi_epi64(ymm_a0, ymm_a1);
			ymm_b2 = _mm256_unpacklo_epi64(ymm_a2, ymm_a3);
			ymm_b3 = _mm256_unpackhi_epi64(ymm_a2, ymm_a3);
			ymm_b4 = _mm256_unpacklo_epi64(ymm_a4, ymm_a5);
			ymm_b5 = _mm256_unpackhi_epi64(ymm_a4, ymm_a5);
			ymm_b6 = _mm256_unpacklo_epi64(ymm_a6, ymm_a7);
			ymm_b7 = _mm256_unpackhi_epi64(ymm_a6, ymm_a7);
			ymm_b8 = _mm256_unpacklo_epi64(ymm_a8, ymm_a9);
			ymm_b9 = _mm256_unpackhi_epi64(ymm_a8, ymm_a9);
			ymm_ba = _mm256_unpacklo_epi64(ymm_aa, ymm_ab);
			ymm_bb = _mm256_unpackhi_epi64(ymm_aa, ymm_ab);
			ymm_bc = _mm256_unpacklo_epi64(ymm_ac, ymm_ad);
			ymm_bd = _mm256_unpackhi_epi64(ymm_ac, ymm_ad);
			ymm_be = _mm256_unpacklo_epi64(ymm_ae, ymm_af);
			ymm_bf = _mm256_unpackhi_epi64(ymm_ae, ymm_af);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b),            ymm_b0);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb),      ymm_b1);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 2),  ymm_b2);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 3),  ymm_b3);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 4),  ymm_b4);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 5),  ymm_b5);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 6),  ymm_b6);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 7),  ymm_b7);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 8),  ymm_b8);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 9),  ymm_b9);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 10), ymm_ba);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 11), ymm_bb);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 12), ymm_bc);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 13), ymm_bd);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 14), ymm_be);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b + ldb * 15), ymm_bf);
		}

		template <>
		inline void trp_tiny<signed char>(signed char* b, size_t ldb, const signed char* a, size_t lda, size_t m, size_t n)
		{
			for (size_t i = 0; i < n; ++i)
			{
				switch (m)
				{
				case 32: b[31] = a[lda * 31]; [[fallthrough]];
				case 31: b[30] = a[lda * 30]; [[fallthrough]];
				case 30: b[29] = a[lda * 29]; [[fallthrough]];
				case 29: b[28] = a[lda * 28]; [[fallthrough]];
				case 28: b[27] = a[lda * 27]; [[fallthrough]];
				case 27: b[26] = a[lda * 26]; [[fallthrough]];
				case 26: b[25] = a[lda * 25]; [[fallthrough]];
				case 25: b[24] = a[lda * 24]; [[fallthrough]];
				case 24: b[23] = a[lda * 23]; [[fallthrough]];
				case 23: b[22] = a[lda * 22]; [[fallthrough]];
				case 22: b[21] = a[lda * 21]; [[fallthrough]];
				case 21: b[20] = a[lda * 20]; [[fallthrough]];
				case 20: b[19] = a[lda * 19]; [[fallthrough]];
				case 19: b[18] = a[lda * 18]; [[fallthrough]];
				case 18: b[17] = a[lda * 17]; [[fallthrough]];
				case 17: b[16] = a[lda * 16]; [[fallthrough]];
				case 16: b[15] = a[lda * 15]; [[fallthrough]];
				case 15: b[14] = a[lda * 14]; [[fallthrough]];
				case 14: b[13] = a[lda * 13]; [[fallthrough]];
				case 13: b[12] = a[lda * 12]; [[fallthrough]];
				case 12: b[11] = a[lda * 11]; [[fallthrough]];
				case 11: b[10] = a[lda * 10]; [[fallthrough]];
				case 10: b[9]  = a[lda * 9];  [[fallthrough]];
				case 9:  b[8]  = a[lda * 8];  [[fallthrough]];
				case 8:  b[7]  = a[lda * 7];  [[fallthrough]];
				case 7:  b[6]  = a[lda * 6];  [[fallthrough]];
				case 6:  b[5]  = a[lda * 5];  [[fallthrough]];
				case 5:  b[4]  = a[lda * 4];  [[fallthrough]];
				case 4:  b[3]  = a[lda * 3];  [[fallthrough]];
				case 3:  b[2]  = a[lda * 2];  [[fallthrough]];
				case 2:  b[1]  = a[lda];      [[fallthrough]];
				case 1:  b[0]  = a[0];        [[fallthrough]];
				}
				a += 1;
				b += ldb;
			}
		}

	#elif defined(__AVX__) || defined(__SSE4_2__) || defined(__SSE4_1__) || defined(__SSSE3__) || defined(__SSE3__) || defined(__SSE2__)

		// Specialize for signed char

		template <>
		constexpr size_t trp_block_m<signed char>(void)
		{
			return static_cast<size_t>(16);
		}

		template <>
		constexpr size_t trp_block_n<signed char>(void)
		{
			return static_cast<size_t>(16);
		}

		template <>
		inline void trp_block<signed char>(signed char* b, size_t ldb, const signed char* a, size_t lda)
		{
			__m128i xmm_a0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda));
			__m128i xmm_a2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 2));
			__m128i xmm_a3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 3));
			__m128i xmm_a4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 4));
			__m128i xmm_a5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 5));
			__m128i xmm_a6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 6));
			__m128i xmm_a7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 7));
			__m128i xmm_a8 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 8));
			__m128i xmm_a9 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 9));
			__m128i xmm_aa = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 10));
			__m128i xmm_ab = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 11));
			__m128i xmm_ac = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 12));
			__m128i xmm_ad = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 13));
			__m128i xmm_ae = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 14));
			__m128i xmm_af = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + lda * 15));
			__m128i xmm_b0 = _mm_unpacklo_epi8(xmm_a0, xmm_a1);
			__m128i xmm_b1 = _mm_unpacklo_epi8(xmm_a2, xmm_a3);
			__m128i xmm_b2 = _mm_unpacklo_epi8(xmm_a4, xmm_a5);
			__m128i xmm_b3 = _mm_unpacklo_epi8(xmm_a6, xmm_a7);
			__m128i xmm_b4 = _mm_unpacklo_epi8(xmm_a8, xmm_a9);
			__m128i xmm_b5 = _mm_unpacklo_epi8(xmm_aa, xmm_ab);
			__m128i xmm_b6 = _mm_unpacklo_epi8(xmm_ac, xmm_ad);
			__m128i xmm_b7 = _mm_unpacklo_epi8(xmm_ae, xmm_af);
			__m128i xmm_b8 = _mm_unpackhi_epi8(xmm_a0, xmm_a1);
			__m128i xmm_b9 = _mm_unpackhi_epi8(xmm_a2, xmm_a3);
			__m128i xmm_ba = _mm_unpackhi_epi8(xmm_a4, xmm_a5);
			__m128i xmm_bb = _mm_unpackhi_epi8(xmm_a6, xmm_a7);
			__m128i xmm_bc = _mm_unpackhi_epi8(xmm_a8, xmm_a9);
			__m128i xmm_bd = _mm_unpackhi_epi8(xmm_aa, xmm_ab);
			__m128i xmm_be = _mm_unpackhi_epi8(xmm_ac, xmm_ad);
			__m128i xmm_bf = _mm_unpackhi_epi8(xmm_ae, xmm_af);
			xmm_a0 = _mm_unpacklo_epi16(xmm_b0, xmm_b1);
			xmm_a1 = _mm_unpacklo_epi16(xmm_b2, xmm_b3);
			xmm_a2 = _mm_unpacklo_epi16(xmm_b4, xmm_b5);
			xmm_a3 = _mm_unpacklo_epi16(xmm_b6, xmm_b7);
			xmm_a4 = _mm_unpackhi_epi16(xmm_b0, xmm_b1);
			xmm_a5 = _mm_unpackhi_epi16(xmm_b2, xmm_b3);
			xmm_a6 = _mm_unpackhi_epi16(xmm_b4, xmm_b5);
			xmm_a7 = _mm_unpackhi_epi16(xmm_b6, xmm_b7);
			xmm_a8 = _mm_unpacklo_epi16(xmm_b8, xmm_b9);
			xmm_a9 = _mm_unpacklo_epi16(xmm_ba, xmm_bb);
			xmm_aa = _mm_unpacklo_epi16(xmm_bc, xmm_bd);
			xmm_ab = _mm_unpacklo_epi16(xmm_be, xmm_bf);
			xmm_ac = _mm_unpackhi_epi16(xmm_b8, xmm_b9);
			xmm_ad = _mm_unpackhi_epi16(xmm_ba, xmm_bb);
			xmm_ae = _mm_unpackhi_epi16(xmm_bc, xmm_bd);
			xmm_af = _mm_unpackhi_epi16(xmm_be, xmm_bf);
			xmm_b0 = _mm_unpacklo_epi32(xmm_a0, xmm_a1);
			xmm_b1 = _mm_unpacklo_epi32(xmm_a2, xmm_a3);
			xmm_b2 = _mm_unpackhi_epi32(xmm_a0, xmm_a1);
			xmm_b3 = _mm_unpackhi_epi32(xmm_a2, xmm_a3);
			xmm_b4 = _mm_unpacklo_epi32(xmm_a4, xmm_a5);
			xmm_b5 = _mm_unpacklo_epi32(xmm_a6, xmm_a7);
			xmm_b6 = _mm_unpackhi_epi32(xmm_a4, xmm_a5);
			xmm_b7 = _mm_unpackhi_epi32(xmm_a6, xmm_a7);
			xmm_b8 = _mm_unpacklo_epi32(xmm_a8, xmm_a9);
			xmm_b9 = _mm_unpacklo_epi32(xmm_aa, xmm_ab);
			xmm_ba = _mm_unpackhi_epi32(xmm_a8, xmm_a9);
			xmm_bb = _mm_unpackhi_epi32(xmm_aa, xmm_ab);
			xmm_bc = _mm_unpacklo_epi32(xmm_ac, xmm_ad);
			xmm_bd = _mm_unpacklo_epi32(xmm_ae, xmm_af);
			xmm_be = _mm_unpackhi_epi32(xmm_ac, xmm_ad);
			xmm_bf = _mm_unpackhi_epi32(xmm_ae, xmm_af);
			xmm_a0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
			xmm_a1 = _mm_unpackhi_epi64(xmm_b0, xmm_b1);
			xmm_a2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
			xmm_a3 = _mm_unpackhi_epi64(xmm_b2, xmm_b3);
			xmm_a4 = _mm_unpacklo_epi64(xmm_b4, xmm_b5);
			xmm_a5 = _mm_unpackhi_epi64(xmm_b4, xmm_b5);
			xmm_a6 = _mm_unpacklo_epi64(xmm_b6, xmm_b7);
			xmm_a7 = _mm_unpackhi_epi64(xmm_b6, xmm_b7);
			xmm_a8 = _mm_unpacklo_epi64(xmm_b8, xmm_b9);
			xmm_a9 = _mm_unpackhi_epi64(xmm_b8, xmm_b9);
			xmm_aa = _mm_unpacklo_epi64(xmm_ba, xmm_bb);
			xmm_ab = _mm_unpackhi_epi64(xmm_ba, xmm_bb);
			xmm_ac = _mm_unpacklo_epi64(xmm_bc, xmm_bd);
			xmm_ad = _mm_unpackhi_epi64(xmm_bc, xmm_bd);
			xmm_ae = _mm_unpacklo_epi64(xmm_be, xmm_bf);
			xmm_af = _mm_unpackhi_epi64(xmm_be, xmm_bf);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b),            xmm_a0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b + ldb),      xmm_a1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b + ldb * 2),  xmm_a2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b + ldb * 3),  xmm_a3);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b + ldb * 4),  xmm_a4);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b + ldb * 5),  xmm_a5);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b + ldb * 6),  xmm_a6);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b + ldb * 7),  xmm_a7);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b + ldb * 8),  xmm_a8);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b + ldb * 9),  xmm_a9);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b + ldb * 0),  xmm_aa);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b + ldb * 11), xmm_ab);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b + ldb * 12), xmm_ac);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b + ldb * 13), xmm_ad);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b + ldb * 14), xmm_ae);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b + ldb * 15), xmm_af);
		}

		template <>
		inline void trp_tiny<signed char>(signed char* b, size_t ldb, const signed char* a, size_t lda, size_t m, size_t n)
		{
			for (size_t i = 0; i < n; ++i)
			{
				switch (m)
				{
				case 16: b[15] = a[lda * 15]; [[fallthrough]];
				case 15: b[14] = a[lda * 14]; [[fallthrough]];
				case 14: b[13] = a[lda * 13]; [[fallthrough]];
				case 13: b[12] = a[lda * 12]; [[fallthrough]];
				case 12: b[11] = a[lda * 11]; [[fallthrough]];
				case 11: b[10] = a[lda * 10]; [[fallthrough]];
				case 10: b[9]  = a[lda * 9];  [[fallthrough]];
				case 9:  b[8]  = a[lda * 8];  [[fallthrough]];
				case 8:  b[7]  = a[lda * 7];  [[fallthrough]];
				case 7:  b[6]  = a[lda * 6];  [[fallthrough]];
				case 6:  b[5]  = a[lda * 5];  [[fallthrough]];
				case 5:  b[4]  = a[lda * 4];  [[fallthrough]];
				case 4:  b[3]  = a[lda * 3];  [[fallthrough]];
				case 3:  b[2]  = a[lda * 2];  [[fallthrough]];
				case 2:  b[1]  = a[lda];      [[fallthrough]];
				case 1:  b[0]  = a[0];        [[fallthrough]];
				}
				a += 1;
				b += ldb;
			}
		}

	#endif

	} // namespace cpu

} // namespace core

#endif
