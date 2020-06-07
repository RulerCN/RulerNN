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

#ifndef __CORE_CPU_CVTU32_H__
#define __CORE_CPU_CVTU32_H__

#include <cstddef>
#include <cstdint>
#include <cstring>
#include "../simd.h"

namespace core
{
	namespace cpu
	{
		template<class T>
		inline void cvtu32_tiny(T* dst, const unsigned int* src, size_t n)
		{
			switch (n)
			{
			case 7: dst[6] = static_cast<T>(src[6]);
			case 6: dst[5] = static_cast<T>(src[5]);
			case 5: dst[4] = static_cast<T>(src[4]);
			case 4: dst[3] = static_cast<T>(src[3]);
			case 3: dst[2] = static_cast<T>(src[2]);
			case 2: dst[1] = static_cast<T>(src[1]);
			case 1: dst[0] = static_cast<T>(src[0]);
				break;
			}
		}

	#ifdef __AVX2__

		// Function template cvtu32_avx2_8

		template <class T>
		inline void cvtu32_avx2_8(T* dst, const unsigned int* src)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		inline void cvtu32_avx2_8<signed char>(signed char* dst, const unsigned int* src)
		{
			const __m256i ymm_mask = _mm256_set_epi64x(0xffffffffffffffffi64, 0xffffffffffffffffi64, 0xffffffffffffffffi64, 0xffffffff0c080400i64);
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m256i ymm_dst0 = _mm256_shuffle_epi8(_mm256_castsi128_si256(xmm_src0), ymm_mask);
			__m256i ymm_dst1 = _mm256_shuffle_epi8(_mm256_castsi128_si256(xmm_src1), ymm_mask);
			ymm_dst0 = _mm256_unpacklo_epi32(ymm_dst0, ymm_dst1);
			_mm_storeu_si64(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
		}

		template <>
		inline void cvtu32_avx2_8<unsigned char>(unsigned char* dst, const unsigned int* src)
		{
			const __m256i ymm_mask = _mm256_set_epi64x(0xffffffffffffffffi64, 0xffffffffffffffffi64, 0xffffffffffffffffi64, 0xffffffff0c080400i64);
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m256i ymm_dst0 = _mm256_shuffle_epi8(_mm256_castsi128_si256(xmm_src0), ymm_mask);
			__m256i ymm_dst1 = _mm256_shuffle_epi8(_mm256_castsi128_si256(xmm_src1), ymm_mask);
			ymm_dst0 = _mm256_unpacklo_epi32(ymm_dst0, ymm_dst1);
			_mm_storeu_si64(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
		}

		template <>
		inline void cvtu32_avx2_8<signed short>(signed short* dst, const unsigned int* src)
		{
			const __m256i ymm_mask = _mm256_set_epi64x(0xffffffffffffffffi64, 0xffffffffffffffffi64, 0xffffffffffffffffi64, 0x0d0c090805040100i64);
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m256i ymm_dst0 = _mm256_shuffle_epi8(_mm256_castsi128_si256(xmm_src0), ymm_mask);
			__m256i ymm_dst1 = _mm256_shuffle_epi8(_mm256_castsi128_si256(xmm_src1), ymm_mask);
			ymm_dst0 = _mm256_unpacklo_epi64(ymm_dst0, ymm_dst1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
		}

		template <>
		inline void cvtu32_avx2_8<unsigned short>(unsigned short* dst, const unsigned int* src)
		{
			const __m256i ymm_mask = _mm256_set_epi64x(0xffffffffffffffffi64, 0xffffffffffffffffi64, 0xffffffffffffffffi64, 0x0d0c090805040100i64);
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m256i ymm_dst0 = _mm256_shuffle_epi8(_mm256_castsi128_si256(xmm_src0), ymm_mask);
			__m256i ymm_dst1 = _mm256_shuffle_epi8(_mm256_castsi128_si256(xmm_src1), ymm_mask);
			ymm_dst0 = _mm256_unpacklo_epi64(ymm_dst0, ymm_dst1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
		}

		template <>
		inline void cvtu32_avx2_8<float>(float* dst, const unsigned int* src)
		{
			const __m256 ymm_zero = _mm256_setzero_ps();
			const __m256 ymm_max = _mm256_castsi256_ps(_mm256_set1_epi32(0x4f800000));
			__m256i ymm_src0 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(src));
			__m256 ymm_dst0 = _mm256_cvtepi32_ps(ymm_src0);
			__m256 ymm_tmp0 = _mm256_cmp_ps(ymm_dst0, ymm_zero, _CMP_LT_OS);
			ymm_tmp0 = _mm256_and_ps(ymm_tmp0, ymm_max);
			ymm_dst0 = _mm256_add_ps(ymm_dst0, ymm_tmp0);
			_mm256_storeu_ps(dst, ymm_dst0);
		}

		template <>
		inline void cvtu32_avx2_8<double>(double* dst, const unsigned int* src)
		{
			const __m256d ymm_zero = _mm256_setzero_pd();
			const __m256d ymm_max = _mm256_castsi256_pd(_mm256_set1_epi64x(0x41f0000000000000));
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m256d ymm_dst0 = _mm256_cvtepi32_pd(xmm_src0);
			__m256d ymm_dst1 = _mm256_cvtepi32_pd(xmm_src1);
			__m256d ymm_tmp0 = _mm256_cmp_pd(ymm_dst0, ymm_zero, _CMP_LT_OS);
			__m256d ymm_tmp1 = _mm256_cmp_pd(ymm_dst1, ymm_zero, _CMP_LT_OS);
			ymm_tmp0 = _mm256_and_pd(ymm_tmp0, ymm_max);
			ymm_tmp1 = _mm256_and_pd(ymm_tmp1, ymm_max);
			ymm_dst0 = _mm256_add_pd(ymm_dst0, ymm_tmp0);
			ymm_dst1 = _mm256_add_pd(ymm_dst1, ymm_tmp1);
			_mm256_storeu_pd(dst, ymm_dst0);
			_mm256_storeu_pd(dst + 4, ymm_dst1);
		}

		// Function template cvtu32_avx2_16

		template <class T>
		inline void cvtu32_avx2_16(T* dst, const unsigned int* src)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		inline void cvtu32_avx2_16<signed char>(signed char* dst, const unsigned int* src)
		{
			const __m256i ymm_mask = _mm256_set_epi64x(0xffffffffffffffffi64, 0xffffffffffffffffi64, 0xffffffffffffffffi64, 0xffffffff0c080400i64);
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m128i xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
			__m128i xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
			__m256i ymm_dst0 = _mm256_shuffle_epi8(_mm256_castsi128_si256(xmm_src0), ymm_mask);
			__m256i ymm_dst1 = _mm256_shuffle_epi8(_mm256_castsi128_si256(xmm_src1), ymm_mask);
			__m256i ymm_dst2 = _mm256_shuffle_epi8(_mm256_castsi128_si256(xmm_src2), ymm_mask);
			__m256i ymm_dst3 = _mm256_shuffle_epi8(_mm256_castsi128_si256(xmm_src3), ymm_mask);
			ymm_dst0 = _mm256_unpacklo_epi32(ymm_dst0, ymm_dst1);
			ymm_dst1 = _mm256_unpacklo_epi32(ymm_dst2, ymm_dst3);
			ymm_dst0 = _mm256_unpacklo_epi64(ymm_dst0, ymm_dst1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
		}

		template <>
		inline void cvtu32_avx2_16<unsigned char>(unsigned char* dst, const unsigned int* src)
		{
			const __m256i ymm_mask = _mm256_set_epi64x(0xffffffffffffffffi64, 0xffffffffffffffffi64, 0xffffffffffffffffi64, 0xffffffff0c080400i64);
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m128i xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
			__m128i xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
			__m256i ymm_dst0 = _mm256_shuffle_epi8(_mm256_castsi128_si256(xmm_src0), ymm_mask);
			__m256i ymm_dst1 = _mm256_shuffle_epi8(_mm256_castsi128_si256(xmm_src1), ymm_mask);
			__m256i ymm_dst2 = _mm256_shuffle_epi8(_mm256_castsi128_si256(xmm_src2), ymm_mask);
			__m256i ymm_dst3 = _mm256_shuffle_epi8(_mm256_castsi128_si256(xmm_src3), ymm_mask);
			ymm_dst0 = _mm256_unpacklo_epi32(ymm_dst0, ymm_dst1);
			ymm_dst1 = _mm256_unpacklo_epi32(ymm_dst2, ymm_dst3);
			ymm_dst0 = _mm256_unpacklo_epi64(ymm_dst0, ymm_dst1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
		}

		template <>
		inline void cvtu32_avx2_16<signed short>(signed short* dst, const unsigned int* src)
		{
			const __m256i ymm_mask = _mm256_set_epi64x(0xffffffffffffffffi64, 0x0d0c090805040100i64, 0xffffffffffffffffi64, 0x0d0c090805040100i64);
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m128i xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
			__m128i xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
			__m256i ymm_src0 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src0), xmm_src2, 1);
			__m256i ymm_src1 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src1), xmm_src3, 1);
			__m256i ymm_dst0 = _mm256_shuffle_epi8(ymm_src0, ymm_mask);
			__m256i ymm_dst1 = _mm256_shuffle_epi8(ymm_src1, ymm_mask);
			ymm_dst0 = _mm256_unpacklo_epi64(ymm_dst0, ymm_dst1);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst), ymm_dst0);
		}

		template <>
		inline void cvtu32_avx2_16<unsigned short>(unsigned short* dst, const unsigned int* src)
		{
			const __m256i ymm_mask = _mm256_set_epi64x(0xffffffffffffffffi64, 0x0d0c090805040100i64, 0xffffffffffffffffi64, 0x0d0c090805040100i64);
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m128i xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
			__m128i xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
			__m256i ymm_src0 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src0), xmm_src2, 1);
			__m256i ymm_src1 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src1), xmm_src3, 1);
			__m256i ymm_dst0 = _mm256_shuffle_epi8(ymm_src0, ymm_mask);
			__m256i ymm_dst1 = _mm256_shuffle_epi8(ymm_src1, ymm_mask);
			ymm_dst0 = _mm256_unpacklo_epi64(ymm_dst0, ymm_dst1);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst), ymm_dst0);
		}

		template <>
		inline void cvtu32_avx2_16<float>(float* dst, const unsigned int* src)
		{
			const __m256 ymm_zero = _mm256_setzero_ps();
			const __m256 ymm_max = _mm256_castsi256_ps(_mm256_set1_epi32(0x4f800000));
			__m256i ymm_src0 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(src));
			__m256i ymm_src1 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(src) + 1);
			__m256 ymm_dst0 = _mm256_cvtepi32_ps(ymm_src0);
			__m256 ymm_dst1 = _mm256_cvtepi32_ps(ymm_src1);
			__m256 ymm_tmp0 = _mm256_cmp_ps(ymm_dst0, ymm_zero, _CMP_LT_OS);
			__m256 ymm_tmp1 = _mm256_cmp_ps(ymm_dst1, ymm_zero, _CMP_LT_OS);
			ymm_tmp0 = _mm256_and_ps(ymm_tmp0, ymm_max);
			ymm_tmp1 = _mm256_and_ps(ymm_tmp1, ymm_max);
			ymm_dst0 = _mm256_add_ps(ymm_dst0, ymm_tmp0);
			ymm_dst1 = _mm256_add_ps(ymm_dst1, ymm_tmp1);
			_mm256_storeu_ps(dst, ymm_dst0);
			_mm256_storeu_ps(dst + 8, ymm_dst1);
		}

		template <>
		inline void cvtu32_avx2_16<double>(double* dst, const unsigned int* src)
		{
			const __m256d ymm_zero = _mm256_setzero_pd();
			const __m256d ymm_max = _mm256_castsi256_pd(_mm256_set1_epi64x(0x41f0000000000000));
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m128i xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
			__m128i xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
			__m256d ymm_dst0 = _mm256_cvtepi32_pd(xmm_src0);
			__m256d ymm_dst1 = _mm256_cvtepi32_pd(xmm_src1);
			__m256d ymm_dst2 = _mm256_cvtepi32_pd(xmm_src2);
			__m256d ymm_dst3 = _mm256_cvtepi32_pd(xmm_src3);
			__m256d ymm_tmp0 = _mm256_cmp_pd(ymm_dst0, ymm_zero, _CMP_LT_OS);
			__m256d ymm_tmp1 = _mm256_cmp_pd(ymm_dst1, ymm_zero, _CMP_LT_OS);
			__m256d ymm_tmp2 = _mm256_cmp_pd(ymm_dst2, ymm_zero, _CMP_LT_OS);
			__m256d ymm_tmp3 = _mm256_cmp_pd(ymm_dst3, ymm_zero, _CMP_LT_OS);
			ymm_tmp0 = _mm256_and_pd(ymm_tmp0, ymm_max);
			ymm_tmp1 = _mm256_and_pd(ymm_tmp1, ymm_max);
			ymm_tmp2 = _mm256_and_pd(ymm_tmp2, ymm_max);
			ymm_tmp3 = _mm256_and_pd(ymm_tmp3, ymm_max);
			ymm_dst0 = _mm256_add_pd(ymm_dst0, ymm_tmp0);
			ymm_dst1 = _mm256_add_pd(ymm_dst1, ymm_tmp1);
			ymm_dst2 = _mm256_add_pd(ymm_dst2, ymm_tmp2);
			ymm_dst3 = _mm256_add_pd(ymm_dst3, ymm_tmp3);
			_mm256_storeu_pd(dst, ymm_dst0);
			_mm256_storeu_pd(dst + 4, ymm_dst1);
			_mm256_storeu_pd(dst + 8, ymm_dst2);
			_mm256_storeu_pd(dst + 12, ymm_dst3);
		}

		// Function template cvtu32_avx2_32

		template <class T>
		inline void cvtu32_avx2_32(T* dst, const unsigned int* src)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		inline void cvtu32_avx2_32<signed char>(signed char* dst, const unsigned int* src)
		{
			const __m256i ymm_mask = _mm256_set_epi64x(0xffffffffffffffffi64, 0xffffffff0c080400i64, 0xffffffffffffffffi64, 0xffffffff0c080400i64);
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m128i xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
			__m128i xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
			__m128i xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
			__m128i xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
			__m128i xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
			__m128i xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
			__m256i ymm_src0 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src0), xmm_src4, 1);
			__m256i ymm_src1 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src1), xmm_src5, 1);
			__m256i ymm_src2 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src2), xmm_src6, 1);
			__m256i ymm_src3 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src3), xmm_src7, 1);
			__m256i ymm_dst0 = _mm256_shuffle_epi8(ymm_src0, ymm_mask);
			__m256i ymm_dst1 = _mm256_shuffle_epi8(ymm_src1, ymm_mask);
			__m256i ymm_dst2 = _mm256_shuffle_epi8(ymm_src2, ymm_mask);
			__m256i ymm_dst3 = _mm256_shuffle_epi8(ymm_src3, ymm_mask);
			ymm_dst0 = _mm256_unpacklo_epi32(ymm_dst0, ymm_dst1);
			ymm_dst2 = _mm256_unpacklo_epi32(ymm_dst2, ymm_dst3);
			ymm_dst0 = _mm256_unpacklo_epi64(ymm_dst0, ymm_dst2);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst), ymm_dst0);
		}

		template <>
		inline void cvtu32_avx2_32<unsigned char>(unsigned char* dst, const unsigned int* src)
		{
			const __m256i ymm_mask = _mm256_set_epi64x(0xffffffffffffffffi64, 0xffffffff0c080400i64, 0xffffffffffffffffi64, 0xffffffff0c080400i64);
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m128i xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
			__m128i xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
			__m128i xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
			__m128i xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
			__m128i xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
			__m128i xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
			__m256i ymm_src0 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src0), xmm_src4, 1);
			__m256i ymm_src1 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src1), xmm_src5, 1);
			__m256i ymm_src2 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src2), xmm_src6, 1);
			__m256i ymm_src3 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src3), xmm_src7, 1);
			__m256i ymm_dst0 = _mm256_shuffle_epi8(ymm_src0, ymm_mask);
			__m256i ymm_dst1 = _mm256_shuffle_epi8(ymm_src1, ymm_mask);
			__m256i ymm_dst2 = _mm256_shuffle_epi8(ymm_src2, ymm_mask);
			__m256i ymm_dst3 = _mm256_shuffle_epi8(ymm_src3, ymm_mask);
			ymm_dst0 = _mm256_unpacklo_epi32(ymm_dst0, ymm_dst1);
			ymm_dst2 = _mm256_unpacklo_epi32(ymm_dst2, ymm_dst3);
			ymm_dst0 = _mm256_unpacklo_epi64(ymm_dst0, ymm_dst2);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst), ymm_dst0);
		}

		template <>
		inline void cvtu32_avx2_32<signed short>(signed short* dst, const unsigned int* src)
		{
			const __m256i ymm_mask = _mm256_set_epi64x(0xffffffffffffffffi64, 0x0d0c090805040100i64, 0xffffffffffffffffi64, 0x0d0c090805040100i64);
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m128i xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
			__m128i xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
			__m128i xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
			__m128i xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
			__m128i xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
			__m128i xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
			__m256i ymm_src0 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src0), xmm_src2, 1);
			__m256i ymm_src1 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src1), xmm_src3, 1);
			__m256i ymm_src2 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src4), xmm_src6, 1);
			__m256i ymm_src3 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src5), xmm_src7, 1);
			__m256i ymm_dst0 = _mm256_shuffle_epi8(ymm_src0, ymm_mask);
			__m256i ymm_dst1 = _mm256_shuffle_epi8(ymm_src1, ymm_mask);
			__m256i ymm_dst2 = _mm256_shuffle_epi8(ymm_src2, ymm_mask);
			__m256i ymm_dst3 = _mm256_shuffle_epi8(ymm_src3, ymm_mask);
			ymm_dst0 = _mm256_unpacklo_epi64(ymm_dst0, ymm_dst1);
			ymm_dst2 = _mm256_unpacklo_epi64(ymm_dst2, ymm_dst3);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst), ymm_dst0);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst) + 1, ymm_dst2);
		}

		template <>
		inline void cvtu32_avx2_32<unsigned short>(unsigned short* dst, const unsigned int* src)
		{
			const __m256i ymm_mask = _mm256_set_epi64x(0xffffffffffffffffi64, 0x0d0c090805040100i64, 0xffffffffffffffffi64, 0x0d0c090805040100i64);
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m128i xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
			__m128i xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
			__m128i xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
			__m128i xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
			__m128i xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
			__m128i xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
			__m256i ymm_src0 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src0), xmm_src2, 1);
			__m256i ymm_src1 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src1), xmm_src3, 1);
			__m256i ymm_src2 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src4), xmm_src6, 1);
			__m256i ymm_src3 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src5), xmm_src7, 1);
			__m256i ymm_dst0 = _mm256_shuffle_epi8(ymm_src0, ymm_mask);
			__m256i ymm_dst1 = _mm256_shuffle_epi8(ymm_src1, ymm_mask);
			__m256i ymm_dst2 = _mm256_shuffle_epi8(ymm_src2, ymm_mask);
			__m256i ymm_dst3 = _mm256_shuffle_epi8(ymm_src3, ymm_mask);
			ymm_dst0 = _mm256_unpacklo_epi64(ymm_dst0, ymm_dst1);
			ymm_dst2 = _mm256_unpacklo_epi64(ymm_dst2, ymm_dst3);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst), ymm_dst0);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst) + 1, ymm_dst2);
		}

		template <>
		inline void cvtu32_avx2_32<float>(float* dst, const unsigned int* src)
		{
			const __m256 ymm_zero = _mm256_setzero_ps();
			const __m256 ymm_max = _mm256_castsi256_ps(_mm256_set1_epi32(0x4f800000));
			__m256i xmm_src0 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(src));
			__m256i xmm_src1 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(src) + 1);
			__m256i xmm_src2 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(src) + 2);
			__m256i xmm_src3 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(src) + 3);
			__m256 ymm_dst0 = _mm256_cvtepi32_ps(xmm_src0);
			__m256 ymm_dst1 = _mm256_cvtepi32_ps(xmm_src1);
			__m256 ymm_dst2 = _mm256_cvtepi32_ps(xmm_src2);
			__m256 ymm_dst3 = _mm256_cvtepi32_ps(xmm_src3);
			__m256 ymm_tmp0 = _mm256_cmp_ps(ymm_dst0, ymm_zero, _CMP_LT_OS);
			__m256 ymm_tmp1 = _mm256_cmp_ps(ymm_dst1, ymm_zero, _CMP_LT_OS);
			__m256 ymm_tmp2 = _mm256_cmp_ps(ymm_dst2, ymm_zero, _CMP_LT_OS);
			__m256 ymm_tmp3 = _mm256_cmp_ps(ymm_dst3, ymm_zero, _CMP_LT_OS);
			ymm_tmp0 = _mm256_and_ps(ymm_tmp0, ymm_max);
			ymm_tmp1 = _mm256_and_ps(ymm_tmp1, ymm_max);
			ymm_tmp2 = _mm256_and_ps(ymm_tmp2, ymm_max);
			ymm_tmp3 = _mm256_and_ps(ymm_tmp3, ymm_max);
			ymm_dst0 = _mm256_add_ps(ymm_dst0, ymm_tmp0);
			ymm_dst1 = _mm256_add_ps(ymm_dst1, ymm_tmp1);
			ymm_dst2 = _mm256_add_ps(ymm_dst2, ymm_tmp2);
			ymm_dst3 = _mm256_add_ps(ymm_dst3, ymm_tmp3);
			_mm256_storeu_ps(dst, ymm_dst0);
			_mm256_storeu_ps(dst + 8, ymm_dst1);
			_mm256_storeu_ps(dst + 16, ymm_dst2);
			_mm256_storeu_ps(dst + 24, ymm_dst3);
		}

		template <>
		inline void cvtu32_avx2_32<double>(double* dst, const unsigned int* src)
		{
			const __m256d ymm_zero = _mm256_setzero_pd();
			const __m256d ymm_max = _mm256_castsi256_pd(_mm256_set1_epi64x(0x41f0000000000000));
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m128i xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
			__m128i xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
			__m128i xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
			__m128i xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
			__m128i xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
			__m128i xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
			__m256d ymm_dst0 = _mm256_cvtepi32_pd(xmm_src0);
			__m256d ymm_dst1 = _mm256_cvtepi32_pd(xmm_src1);
			__m256d ymm_dst2 = _mm256_cvtepi32_pd(xmm_src2);
			__m256d ymm_dst3 = _mm256_cvtepi32_pd(xmm_src3);
			__m256d ymm_dst4 = _mm256_cvtepi32_pd(xmm_src4);
			__m256d ymm_dst5 = _mm256_cvtepi32_pd(xmm_src5);
			__m256d ymm_dst6 = _mm256_cvtepi32_pd(xmm_src6);
			__m256d ymm_dst7 = _mm256_cvtepi32_pd(xmm_src7);
			__m256d ymm_tmp0 = _mm256_cmp_pd(ymm_dst0, ymm_zero, _CMP_LT_OS);
			__m256d ymm_tmp1 = _mm256_cmp_pd(ymm_dst1, ymm_zero, _CMP_LT_OS);
			__m256d ymm_tmp2 = _mm256_cmp_pd(ymm_dst2, ymm_zero, _CMP_LT_OS);
			__m256d ymm_tmp3 = _mm256_cmp_pd(ymm_dst3, ymm_zero, _CMP_LT_OS);
			__m256d ymm_tmp4 = _mm256_cmp_pd(ymm_dst4, ymm_zero, _CMP_LT_OS);
			__m256d ymm_tmp5 = _mm256_cmp_pd(ymm_dst5, ymm_zero, _CMP_LT_OS);
			__m256d ymm_tmp6 = _mm256_cmp_pd(ymm_dst6, ymm_zero, _CMP_LT_OS);
			__m256d ymm_tmp7 = _mm256_cmp_pd(ymm_dst7, ymm_zero, _CMP_LT_OS);
			ymm_tmp0 = _mm256_and_pd(ymm_tmp0, ymm_max);
			ymm_tmp1 = _mm256_and_pd(ymm_tmp1, ymm_max);
			ymm_tmp2 = _mm256_and_pd(ymm_tmp2, ymm_max);
			ymm_tmp3 = _mm256_and_pd(ymm_tmp3, ymm_max);
			ymm_tmp4 = _mm256_and_pd(ymm_tmp4, ymm_max);
			ymm_tmp5 = _mm256_and_pd(ymm_tmp5, ymm_max);
			ymm_tmp6 = _mm256_and_pd(ymm_tmp6, ymm_max);
			ymm_tmp7 = _mm256_and_pd(ymm_tmp7, ymm_max);
			ymm_dst0 = _mm256_add_pd(ymm_dst0, ymm_tmp0);
			ymm_dst1 = _mm256_add_pd(ymm_dst1, ymm_tmp1);
			ymm_dst2 = _mm256_add_pd(ymm_dst2, ymm_tmp2);
			ymm_dst3 = _mm256_add_pd(ymm_dst3, ymm_tmp3);
			ymm_dst4 = _mm256_add_pd(ymm_dst4, ymm_tmp4);
			ymm_dst5 = _mm256_add_pd(ymm_dst5, ymm_tmp5);
			ymm_dst6 = _mm256_add_pd(ymm_dst6, ymm_tmp6);
			ymm_dst7 = _mm256_add_pd(ymm_dst7, ymm_tmp7);
			_mm256_storeu_pd(dst, ymm_dst0);
			_mm256_storeu_pd(dst + 4, ymm_dst1);
			_mm256_storeu_pd(dst + 8, ymm_dst2);
			_mm256_storeu_pd(dst + 12, ymm_dst3);
			_mm256_storeu_pd(dst + 16, ymm_dst4);
			_mm256_storeu_pd(dst + 20, ymm_dst5);
			_mm256_storeu_pd(dst + 24, ymm_dst6);
			_mm256_storeu_pd(dst + 28, ymm_dst7);
		}

		// Function template cvtu32_avx2_64

		template <class T>
		inline void cvtu32_avx2_64(T* dst, const unsigned int* src)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		inline void cvtu32_avx2_64<signed char>(signed char* dst, const unsigned int* src)
		{
			const __m256i ymm_mask = _mm256_set_epi64x(0xffffffffffffffffi64, 0xffffffff0c080400i64, 0xffffffffffffffffi64, 0xffffffff0c080400i64);
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m128i xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
			__m128i xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
			__m128i xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
			__m128i xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
			__m128i xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
			__m128i xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
			__m128i xmm_src8 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 8);
			__m128i xmm_src9 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 9);
			__m128i xmm_srca = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 10);
			__m128i xmm_srcb = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 11);
			__m128i xmm_srcc = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 12);
			__m128i xmm_srcd = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 13);
			__m128i xmm_srce = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 14);
			__m128i xmm_srcf = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 15);
			__m256i ymm_src0 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src0), xmm_src4, 1);
			__m256i ymm_src1 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src1), xmm_src5, 1);
			__m256i ymm_src2 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src2), xmm_src6, 1);
			__m256i ymm_src3 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src3), xmm_src7, 1);
			__m256i ymm_src4 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src8), xmm_srcc, 1);
			__m256i ymm_src5 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src9), xmm_srcd, 1);
			__m256i ymm_src6 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_srca), xmm_srce, 1);
			__m256i ymm_src7 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_srcb), xmm_srcf, 1);
			__m256i ymm_dst0 = _mm256_shuffle_epi8(ymm_src0, ymm_mask);
			__m256i ymm_dst1 = _mm256_shuffle_epi8(ymm_src1, ymm_mask);
			__m256i ymm_dst2 = _mm256_shuffle_epi8(ymm_src2, ymm_mask);
			__m256i ymm_dst3 = _mm256_shuffle_epi8(ymm_src3, ymm_mask);
			__m256i ymm_dst4 = _mm256_shuffle_epi8(ymm_src4, ymm_mask);
			__m256i ymm_dst5 = _mm256_shuffle_epi8(ymm_src5, ymm_mask);
			__m256i ymm_dst6 = _mm256_shuffle_epi8(ymm_src6, ymm_mask);
			__m256i ymm_dst7 = _mm256_shuffle_epi8(ymm_src7, ymm_mask);
			ymm_dst0 = _mm256_unpacklo_epi32(ymm_dst0, ymm_dst1);
			ymm_dst2 = _mm256_unpacklo_epi32(ymm_dst2, ymm_dst3);
			ymm_dst4 = _mm256_unpacklo_epi32(ymm_dst4, ymm_dst5);
			ymm_dst6 = _mm256_unpacklo_epi32(ymm_dst6, ymm_dst7);
			ymm_dst0 = _mm256_unpacklo_epi64(ymm_dst0, ymm_dst2);
			ymm_dst4 = _mm256_unpacklo_epi64(ymm_dst4, ymm_dst6);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst), ymm_dst0);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst) + 1, ymm_dst4);
		}

		template <>
		inline void cvtu32_avx2_64<unsigned char>(unsigned char* dst, const unsigned int* src)
		{
			const __m256i ymm_mask = _mm256_set_epi64x(0xffffffffffffffffi64, 0xffffffff0c080400i64, 0xffffffffffffffffi64, 0xffffffff0c080400i64);
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m128i xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
			__m128i xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
			__m128i xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
			__m128i xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
			__m128i xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
			__m128i xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
			__m128i xmm_src8 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 8);
			__m128i xmm_src9 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 9);
			__m128i xmm_srca = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 10);
			__m128i xmm_srcb = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 11);
			__m128i xmm_srcc = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 12);
			__m128i xmm_srcd = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 13);
			__m128i xmm_srce = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 14);
			__m128i xmm_srcf = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 15);
			__m256i ymm_src0 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src0), xmm_src4, 1);
			__m256i ymm_src1 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src1), xmm_src5, 1);
			__m256i ymm_src2 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src2), xmm_src6, 1);
			__m256i ymm_src3 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src3), xmm_src7, 1);
			__m256i ymm_src4 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src8), xmm_srcc, 1);
			__m256i ymm_src5 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src9), xmm_srcd, 1);
			__m256i ymm_src6 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_srca), xmm_srce, 1);
			__m256i ymm_src7 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_srcb), xmm_srcf, 1);
			__m256i ymm_dst0 = _mm256_shuffle_epi8(ymm_src0, ymm_mask);
			__m256i ymm_dst1 = _mm256_shuffle_epi8(ymm_src1, ymm_mask);
			__m256i ymm_dst2 = _mm256_shuffle_epi8(ymm_src2, ymm_mask);
			__m256i ymm_dst3 = _mm256_shuffle_epi8(ymm_src3, ymm_mask);
			__m256i ymm_dst4 = _mm256_shuffle_epi8(ymm_src4, ymm_mask);
			__m256i ymm_dst5 = _mm256_shuffle_epi8(ymm_src5, ymm_mask);
			__m256i ymm_dst6 = _mm256_shuffle_epi8(ymm_src6, ymm_mask);
			__m256i ymm_dst7 = _mm256_shuffle_epi8(ymm_src7, ymm_mask);
			ymm_dst0 = _mm256_unpacklo_epi32(ymm_dst0, ymm_dst1);
			ymm_dst2 = _mm256_unpacklo_epi32(ymm_dst2, ymm_dst3);
			ymm_dst4 = _mm256_unpacklo_epi32(ymm_dst4, ymm_dst5);
			ymm_dst6 = _mm256_unpacklo_epi32(ymm_dst6, ymm_dst7);
			ymm_dst0 = _mm256_unpacklo_epi64(ymm_dst0, ymm_dst2);
			ymm_dst4 = _mm256_unpacklo_epi64(ymm_dst4, ymm_dst6);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst), ymm_dst0);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst) + 1, ymm_dst4);
		}

		template <>
		inline void cvtu32_avx2_64<signed short>(signed short* dst, const unsigned int* src)
		{
			const __m256i ymm_mask = _mm256_set_epi64x(0xffffffffffffffffi64, 0x0d0c090805040100i64, 0xffffffffffffffffi64, 0x0d0c090805040100i64);
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m128i xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
			__m128i xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
			__m128i xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
			__m128i xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
			__m128i xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
			__m128i xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
			__m128i xmm_src8 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 8);
			__m128i xmm_src9 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 9);
			__m128i xmm_srca = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 10);
			__m128i xmm_srcb = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 11);
			__m128i xmm_srcc = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 12);
			__m128i xmm_srcd = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 13);
			__m128i xmm_srce = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 14);
			__m128i xmm_srcf = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 15);
			__m256i ymm_src0 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src0), xmm_src2, 1);
			__m256i ymm_src1 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src1), xmm_src3, 1);
			__m256i ymm_src2 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src4), xmm_src6, 1);
			__m256i ymm_src3 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src5), xmm_src7, 1);
			__m256i ymm_src4 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src8), xmm_srca, 1);
			__m256i ymm_src5 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src9), xmm_srcb, 1);
			__m256i ymm_src6 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_srcc), xmm_srce, 1);
			__m256i ymm_src7 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_srcd), xmm_srcf, 1);
			__m256i ymm_dst0 = _mm256_shuffle_epi8(ymm_src0, ymm_mask);
			__m256i ymm_dst1 = _mm256_shuffle_epi8(ymm_src1, ymm_mask);
			__m256i ymm_dst2 = _mm256_shuffle_epi8(ymm_src2, ymm_mask);
			__m256i ymm_dst3 = _mm256_shuffle_epi8(ymm_src3, ymm_mask);
			__m256i ymm_dst4 = _mm256_shuffle_epi8(ymm_src4, ymm_mask);
			__m256i ymm_dst5 = _mm256_shuffle_epi8(ymm_src5, ymm_mask);
			__m256i ymm_dst6 = _mm256_shuffle_epi8(ymm_src6, ymm_mask);
			__m256i ymm_dst7 = _mm256_shuffle_epi8(ymm_src7, ymm_mask);
			ymm_dst0 = _mm256_unpacklo_epi64(ymm_dst0, ymm_dst1);
			ymm_dst2 = _mm256_unpacklo_epi64(ymm_dst2, ymm_dst3);
			ymm_dst4 = _mm256_unpacklo_epi64(ymm_dst4, ymm_dst5);
			ymm_dst6 = _mm256_unpacklo_epi64(ymm_dst6, ymm_dst7);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst), ymm_dst0);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst) + 1, ymm_dst2);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst) + 2, ymm_dst4);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst) + 3, ymm_dst6);
		}

		template <>
		inline void cvtu32_avx2_64<unsigned short>(unsigned short* dst, const unsigned int* src)
		{
			const __m256i ymm_mask = _mm256_set_epi64x(0xffffffffffffffffi64, 0x0d0c090805040100i64, 0xffffffffffffffffi64, 0x0d0c090805040100i64);
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m128i xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
			__m128i xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
			__m128i xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
			__m128i xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
			__m128i xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
			__m128i xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
			__m128i xmm_src8 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 8);
			__m128i xmm_src9 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 9);
			__m128i xmm_srca = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 10);
			__m128i xmm_srcb = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 11);
			__m128i xmm_srcc = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 12);
			__m128i xmm_srcd = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 13);
			__m128i xmm_srce = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 14);
			__m128i xmm_srcf = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 15);
			__m256i ymm_src0 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src0), xmm_src2, 1);
			__m256i ymm_src1 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src1), xmm_src3, 1);
			__m256i ymm_src2 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src4), xmm_src6, 1);
			__m256i ymm_src3 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src5), xmm_src7, 1);
			__m256i ymm_src4 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src8), xmm_srca, 1);
			__m256i ymm_src5 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src9), xmm_srcb, 1);
			__m256i ymm_src6 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_srcc), xmm_srce, 1);
			__m256i ymm_src7 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_srcd), xmm_srcf, 1);
			__m256i ymm_dst0 = _mm256_shuffle_epi8(ymm_src0, ymm_mask);
			__m256i ymm_dst1 = _mm256_shuffle_epi8(ymm_src1, ymm_mask);
			__m256i ymm_dst2 = _mm256_shuffle_epi8(ymm_src2, ymm_mask);
			__m256i ymm_dst3 = _mm256_shuffle_epi8(ymm_src3, ymm_mask);
			__m256i ymm_dst4 = _mm256_shuffle_epi8(ymm_src4, ymm_mask);
			__m256i ymm_dst5 = _mm256_shuffle_epi8(ymm_src5, ymm_mask);
			__m256i ymm_dst6 = _mm256_shuffle_epi8(ymm_src6, ymm_mask);
			__m256i ymm_dst7 = _mm256_shuffle_epi8(ymm_src7, ymm_mask);
			ymm_dst0 = _mm256_unpacklo_epi64(ymm_dst0, ymm_dst1);
			ymm_dst2 = _mm256_unpacklo_epi64(ymm_dst2, ymm_dst3);
			ymm_dst4 = _mm256_unpacklo_epi64(ymm_dst4, ymm_dst5);
			ymm_dst6 = _mm256_unpacklo_epi64(ymm_dst6, ymm_dst7);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst), ymm_dst0);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst) + 1, ymm_dst2);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst) + 2, ymm_dst4);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst) + 3, ymm_dst6);
		}

		template <>
		inline void cvtu32_avx2_64<float>(float* dst, const unsigned int* src)
		{
			const __m256 ymm_zero = _mm256_setzero_ps();
			const __m256 ymm_max = _mm256_castsi256_ps(_mm256_set1_epi32(0x4f800000));
			__m256i ymm_src0 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(src));
			__m256i ymm_src1 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(src) + 1);
			__m256i ymm_src2 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(src) + 2);
			__m256i ymm_src3 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(src) + 3);
			__m256i ymm_src4 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(src) + 4);
			__m256i ymm_src5 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(src) + 5);
			__m256i ymm_src6 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(src) + 6);
			__m256i ymm_src7 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(src) + 7);
			__m256 ymm_dst0 = _mm256_cvtepi32_ps(ymm_src0);
			__m256 ymm_dst1 = _mm256_cvtepi32_ps(ymm_src1);
			__m256 ymm_dst2 = _mm256_cvtepi32_ps(ymm_src2);
			__m256 ymm_dst3 = _mm256_cvtepi32_ps(ymm_src3);
			__m256 ymm_dst4 = _mm256_cvtepi32_ps(ymm_src4);
			__m256 ymm_dst5 = _mm256_cvtepi32_ps(ymm_src5);
			__m256 ymm_dst6 = _mm256_cvtepi32_ps(ymm_src6);
			__m256 ymm_dst7 = _mm256_cvtepi32_ps(ymm_src7);
			__m256 ymm_tmp0 = _mm256_cmp_ps(ymm_dst0, ymm_zero, _CMP_LT_OS);
			__m256 ymm_tmp1 = _mm256_cmp_ps(ymm_dst1, ymm_zero, _CMP_LT_OS);
			__m256 ymm_tmp2 = _mm256_cmp_ps(ymm_dst2, ymm_zero, _CMP_LT_OS);
			__m256 ymm_tmp3 = _mm256_cmp_ps(ymm_dst3, ymm_zero, _CMP_LT_OS);
			__m256 ymm_tmp4 = _mm256_cmp_ps(ymm_dst4, ymm_zero, _CMP_LT_OS);
			__m256 ymm_tmp5 = _mm256_cmp_ps(ymm_dst5, ymm_zero, _CMP_LT_OS);
			__m256 ymm_tmp6 = _mm256_cmp_ps(ymm_dst6, ymm_zero, _CMP_LT_OS);
			__m256 ymm_tmp7 = _mm256_cmp_ps(ymm_dst7, ymm_zero, _CMP_LT_OS);
			ymm_tmp0 = _mm256_and_ps(ymm_tmp0, ymm_max);
			ymm_tmp1 = _mm256_and_ps(ymm_tmp1, ymm_max);
			ymm_tmp2 = _mm256_and_ps(ymm_tmp2, ymm_max);
			ymm_tmp3 = _mm256_and_ps(ymm_tmp3, ymm_max);
			ymm_tmp4 = _mm256_and_ps(ymm_tmp4, ymm_max);
			ymm_tmp5 = _mm256_and_ps(ymm_tmp5, ymm_max);
			ymm_tmp6 = _mm256_and_ps(ymm_tmp6, ymm_max);
			ymm_tmp7 = _mm256_and_ps(ymm_tmp7, ymm_max);
			ymm_dst0 = _mm256_add_ps(ymm_dst0, ymm_tmp0);
			ymm_dst1 = _mm256_add_ps(ymm_dst1, ymm_tmp1);
			ymm_dst2 = _mm256_add_ps(ymm_dst2, ymm_tmp2);
			ymm_dst3 = _mm256_add_ps(ymm_dst3, ymm_tmp3);
			ymm_dst4 = _mm256_add_ps(ymm_dst4, ymm_tmp4);
			ymm_dst5 = _mm256_add_ps(ymm_dst5, ymm_tmp5);
			ymm_dst6 = _mm256_add_ps(ymm_dst6, ymm_tmp6);
			ymm_dst7 = _mm256_add_ps(ymm_dst7, ymm_tmp7);
			_mm256_storeu_ps(dst, ymm_dst0);
			_mm256_storeu_ps(dst + 8, ymm_dst1);
			_mm256_storeu_ps(dst + 16, ymm_dst2);
			_mm256_storeu_ps(dst + 24, ymm_dst3);
			_mm256_storeu_ps(dst + 32, ymm_dst4);
			_mm256_storeu_ps(dst + 40, ymm_dst5);
			_mm256_storeu_ps(dst + 48, ymm_dst6);
			_mm256_storeu_ps(dst + 56, ymm_dst7);
		}

		template <>
		inline void cvtu32_avx2_64<double>(double* dst, const unsigned int* src)
		{
			const __m256d ymm_zero = _mm256_setzero_pd();
			const __m256d ymm_max = _mm256_castsi256_pd(_mm256_set1_epi64x(0x41f0000000000000));
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m128i xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
			__m128i xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
			__m128i xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
			__m128i xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
			__m128i xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
			__m128i xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
			__m128i xmm_src8 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 8);
			__m128i xmm_src9 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 9);
			__m128i xmm_srca = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 10);
			__m128i xmm_srcb = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 11);
			__m128i xmm_srcc = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 12);
			__m128i xmm_srcd = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 13);
			__m128i xmm_srce = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 14);
			__m128i xmm_srcf = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 15);
			__m256d ymm_dst0 = _mm256_cvtepi32_pd(xmm_src0);
			__m256d ymm_dst1 = _mm256_cvtepi32_pd(xmm_src1);
			__m256d ymm_dst2 = _mm256_cvtepi32_pd(xmm_src2);
			__m256d ymm_dst3 = _mm256_cvtepi32_pd(xmm_src3);
			__m256d ymm_dst4 = _mm256_cvtepi32_pd(xmm_src4);
			__m256d ymm_dst5 = _mm256_cvtepi32_pd(xmm_src5);
			__m256d ymm_dst6 = _mm256_cvtepi32_pd(xmm_src6);
			__m256d ymm_dst7 = _mm256_cvtepi32_pd(xmm_src7);
			__m256d ymm_dst8 = _mm256_cvtepi32_pd(xmm_src8);
			__m256d ymm_dst9 = _mm256_cvtepi32_pd(xmm_src9);
			__m256d ymm_dsta = _mm256_cvtepi32_pd(xmm_srca);
			__m256d ymm_dstb = _mm256_cvtepi32_pd(xmm_srcb);
			__m256d ymm_dstc = _mm256_cvtepi32_pd(xmm_srcc);
			__m256d ymm_dstd = _mm256_cvtepi32_pd(xmm_srcd);
			__m256d ymm_dste = _mm256_cvtepi32_pd(xmm_srce);
			__m256d ymm_dstf = _mm256_cvtepi32_pd(xmm_srcf);
			__m256d ymm_tmp0 = _mm256_cmp_pd(ymm_dst0, ymm_zero, _CMP_LT_OS);
			__m256d ymm_tmp1 = _mm256_cmp_pd(ymm_dst1, ymm_zero, _CMP_LT_OS);
			__m256d ymm_tmp2 = _mm256_cmp_pd(ymm_dst2, ymm_zero, _CMP_LT_OS);
			__m256d ymm_tmp3 = _mm256_cmp_pd(ymm_dst3, ymm_zero, _CMP_LT_OS);
			__m256d ymm_tmp4 = _mm256_cmp_pd(ymm_dst4, ymm_zero, _CMP_LT_OS);
			__m256d ymm_tmp5 = _mm256_cmp_pd(ymm_dst5, ymm_zero, _CMP_LT_OS);
			__m256d ymm_tmp6 = _mm256_cmp_pd(ymm_dst6, ymm_zero, _CMP_LT_OS);
			__m256d ymm_tmp7 = _mm256_cmp_pd(ymm_dst7, ymm_zero, _CMP_LT_OS);
			__m256d ymm_tmp8 = _mm256_cmp_pd(ymm_dst8, ymm_zero, _CMP_LT_OS);
			__m256d ymm_tmp9 = _mm256_cmp_pd(ymm_dst9, ymm_zero, _CMP_LT_OS);
			__m256d ymm_tmpa = _mm256_cmp_pd(ymm_dsta, ymm_zero, _CMP_LT_OS);
			__m256d ymm_tmpb = _mm256_cmp_pd(ymm_dstb, ymm_zero, _CMP_LT_OS);
			__m256d ymm_tmpc = _mm256_cmp_pd(ymm_dstc, ymm_zero, _CMP_LT_OS);
			__m256d ymm_tmpd = _mm256_cmp_pd(ymm_dstd, ymm_zero, _CMP_LT_OS);
			__m256d ymm_tmpe = _mm256_cmp_pd(ymm_dste, ymm_zero, _CMP_LT_OS);
			__m256d ymm_tmpf = _mm256_cmp_pd(ymm_dstf, ymm_zero, _CMP_LT_OS);
			ymm_tmp0 = _mm256_and_pd(ymm_tmp0, ymm_max);
			ymm_tmp1 = _mm256_and_pd(ymm_tmp1, ymm_max);
			ymm_tmp2 = _mm256_and_pd(ymm_tmp2, ymm_max);
			ymm_tmp3 = _mm256_and_pd(ymm_tmp3, ymm_max);
			ymm_tmp4 = _mm256_and_pd(ymm_tmp4, ymm_max);
			ymm_tmp5 = _mm256_and_pd(ymm_tmp5, ymm_max);
			ymm_tmp6 = _mm256_and_pd(ymm_tmp6, ymm_max);
			ymm_tmp7 = _mm256_and_pd(ymm_tmp7, ymm_max);
			ymm_tmp8 = _mm256_and_pd(ymm_tmp8, ymm_max);
			ymm_tmp9 = _mm256_and_pd(ymm_tmp9, ymm_max);
			ymm_tmpa = _mm256_and_pd(ymm_tmpa, ymm_max);
			ymm_tmpb = _mm256_and_pd(ymm_tmpb, ymm_max);
			ymm_tmpc = _mm256_and_pd(ymm_tmpc, ymm_max);
			ymm_tmpd = _mm256_and_pd(ymm_tmpd, ymm_max);
			ymm_tmpe = _mm256_and_pd(ymm_tmpe, ymm_max);
			ymm_tmpf = _mm256_and_pd(ymm_tmpf, ymm_max);
			ymm_dst0 = _mm256_add_pd(ymm_dst0, ymm_tmp0);
			ymm_dst1 = _mm256_add_pd(ymm_dst1, ymm_tmp1);
			ymm_dst2 = _mm256_add_pd(ymm_dst2, ymm_tmp2);
			ymm_dst3 = _mm256_add_pd(ymm_dst3, ymm_tmp3);
			ymm_dst4 = _mm256_add_pd(ymm_dst4, ymm_tmp4);
			ymm_dst5 = _mm256_add_pd(ymm_dst5, ymm_tmp5);
			ymm_dst6 = _mm256_add_pd(ymm_dst6, ymm_tmp6);
			ymm_dst7 = _mm256_add_pd(ymm_dst7, ymm_tmp7);
			ymm_dst8 = _mm256_add_pd(ymm_dst8, ymm_tmp8);
			ymm_dst9 = _mm256_add_pd(ymm_dst9, ymm_tmp9);
			ymm_dsta = _mm256_add_pd(ymm_dsta, ymm_tmpa);
			ymm_dstb = _mm256_add_pd(ymm_dstb, ymm_tmpb);
			ymm_dstc = _mm256_add_pd(ymm_dstc, ymm_tmpc);
			ymm_dstd = _mm256_add_pd(ymm_dstd, ymm_tmpd);
			ymm_dste = _mm256_add_pd(ymm_dste, ymm_tmpe);
			ymm_dstf = _mm256_add_pd(ymm_dstf, ymm_tmpf);
			_mm256_storeu_pd(dst, ymm_dst0);
			_mm256_storeu_pd(dst + 4, ymm_dst1);
			_mm256_storeu_pd(dst + 8, ymm_dst2);
			_mm256_storeu_pd(dst + 12, ymm_dst3);
			_mm256_storeu_pd(dst + 16, ymm_dst4);
			_mm256_storeu_pd(dst + 20, ymm_dst5);
			_mm256_storeu_pd(dst + 24, ymm_dst6);
			_mm256_storeu_pd(dst + 28, ymm_dst7);
			_mm256_storeu_pd(dst + 32, ymm_dst8);
			_mm256_storeu_pd(dst + 36, ymm_dst9);
			_mm256_storeu_pd(dst + 40, ymm_dsta);
			_mm256_storeu_pd(dst + 44, ymm_dstb);
			_mm256_storeu_pd(dst + 48, ymm_dstc);
			_mm256_storeu_pd(dst + 52, ymm_dstd);
			_mm256_storeu_pd(dst + 56, ymm_dste);
			_mm256_storeu_pd(dst + 60, ymm_dstf);
		}

		// Function template cvtu32_avx2_small

		template <class T>
		inline void cvtu32_avx2_small(T* dst, const unsigned int* src, size_t n)
		{
			switch (n >> 3)
			{
			case 8:
				cvtu32_avx2_64(dst, src);
			case 0:
				break;
			case 9:
				cvtu32_avx2_64(dst, src);
				src += 64;
				dst += 64;
			case 1:
				cvtu32_avx2_8(dst, src);
				break;
			case 10:
				cvtu32_avx2_64(dst, src);
				src += 64;
				dst += 64;
			case 2:
				cvtu32_avx2_16(dst, src);
				break;
			case 11:
				cvtu32_avx2_64(dst, src);
				src += 64;
				dst += 64;
			case 3:
				cvtu32_avx2_16(dst, src);
				src += 16;
				dst += 16;
				cvtu32_avx2_8(dst, src);
				break;
			case 12:
				cvtu32_avx2_64(dst, src);
				src += 64;
				dst += 64;
			case 4:
				cvtu32_avx2_32(dst, src);
				break;
			case 13:
				cvtu32_avx2_64(dst, src);
				src += 64;
				dst += 64;
			case 5:
				cvtu32_avx2_32(dst, src);
				src += 32;
				dst += 32;
				cvtu32_avx2_8(dst, src);
				break;
			case 14:
				cvtu32_avx2_64(dst, src);
				src += 64;
				dst += 64;
			case 6:
				cvtu32_avx2_32(dst, src);
				src += 32;
				dst += 32;
				cvtu32_avx2_16(dst, src);
				break;
			case 15:
				cvtu32_avx2_64(dst, src);
				src += 64;
				dst += 64;
			case 7:
				cvtu32_avx2_32(dst, src);
				src += 32;
				dst += 32;
				cvtu32_avx2_16(dst, src);
				src += 16;
				dst += 16;
				cvtu32_avx2_8(dst, src);
				break;
			}
			cvtu32_tiny(dst, src, n & 7);
		}

		// Function template cvtu32_avx2_medium

		template <class T>
		inline void cvtu32_avx2_medium(T* dst, const unsigned int* src, size_t n)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		void cvtu32_avx2_medium<signed char>(signed char* dst, const unsigned int* src, size_t n)
		{
			const __m256i ymm_mask = _mm256_set_epi64x(0xffffffffffffffffi64, 0xffffffff0c080400i64, 0xffffffffffffffffi64, 0xffffffff0c080400i64);
			__m128i xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128i xmm_src8, xmm_src9, xmm_srca, xmm_srcb, xmm_srcc, xmm_srcd, xmm_srce, xmm_srcf;
			__m256i ymm_src0, ymm_src1, ymm_src2, ymm_src3, ymm_src4, ymm_src5, ymm_src6, ymm_src7;
			__m256i ymm_dst0, ymm_dst1, ymm_dst2, ymm_dst3, ymm_dst4, ymm_dst5, ymm_dst6, ymm_dst7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			for (; n >= 64; n -= 64)
			{
				xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
				xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
				xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
				xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
				xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
				xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
				xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
				xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
				xmm_src8 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 8);
				xmm_src9 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 9);
				xmm_srca = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 10);
				xmm_srcb = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 11);
				xmm_srcc = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 12);
				xmm_srcd = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 13);
				xmm_srce = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 14);
				xmm_srcf = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 15);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(src + 64), _MM_HINT_NTA);
				ymm_src0 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src0), xmm_src4, 1);
				ymm_src1 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src1), xmm_src5, 1);
				ymm_src2 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src2), xmm_src6, 1);
				ymm_src3 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src3), xmm_src7, 1);
				ymm_src4 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src8), xmm_srcc, 1);
				ymm_src5 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src9), xmm_srcd, 1);
				ymm_src6 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_srca), xmm_srce, 1);
				ymm_src7 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_srcb), xmm_srcf, 1);
				ymm_dst0 = _mm256_shuffle_epi8(ymm_src0, ymm_mask);
				ymm_dst1 = _mm256_shuffle_epi8(ymm_src1, ymm_mask);
				ymm_dst2 = _mm256_shuffle_epi8(ymm_src2, ymm_mask);
				ymm_dst3 = _mm256_shuffle_epi8(ymm_src3, ymm_mask);
				ymm_dst4 = _mm256_shuffle_epi8(ymm_src4, ymm_mask);
				ymm_dst5 = _mm256_shuffle_epi8(ymm_src5, ymm_mask);
				ymm_dst6 = _mm256_shuffle_epi8(ymm_src6, ymm_mask);
				ymm_dst7 = _mm256_shuffle_epi8(ymm_src7, ymm_mask);
				ymm_dst0 = _mm256_unpacklo_epi32(ymm_dst0, ymm_dst1);
				ymm_dst2 = _mm256_unpacklo_epi32(ymm_dst2, ymm_dst3);
				ymm_dst4 = _mm256_unpacklo_epi32(ymm_dst4, ymm_dst5);
				ymm_dst6 = _mm256_unpacklo_epi32(ymm_dst6, ymm_dst7);
				ymm_dst0 = _mm256_unpacklo_epi64(ymm_dst0, ymm_dst2);
				ymm_dst4 = _mm256_unpacklo_epi64(ymm_dst4, ymm_dst6);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst), ymm_dst0);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst) + 1, ymm_dst4);
				src += 64;
				dst += 64;
			}
		}

		template <>
		void cvtu32_avx2_medium<unsigned char>(unsigned char* dst, const unsigned int* src, size_t n)
		{
			const __m256i ymm_mask = _mm256_set_epi64x(0xffffffffffffffffi64, 0xffffffff0c080400i64, 0xffffffffffffffffi64, 0xffffffff0c080400i64);
			__m128i xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128i xmm_src8, xmm_src9, xmm_srca, xmm_srcb, xmm_srcc, xmm_srcd, xmm_srce, xmm_srcf;
			__m256i ymm_src0, ymm_src1, ymm_src2, ymm_src3, ymm_src4, ymm_src5, ymm_src6, ymm_src7;
			__m256i ymm_dst0, ymm_dst1, ymm_dst2, ymm_dst3, ymm_dst4, ymm_dst5, ymm_dst6, ymm_dst7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			for (; n >= 64; n -= 64)
			{
				xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
				xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
				xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
				xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
				xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
				xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
				xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
				xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
				xmm_src8 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 8);
				xmm_src9 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 9);
				xmm_srca = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 10);
				xmm_srcb = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 11);
				xmm_srcc = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 12);
				xmm_srcd = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 13);
				xmm_srce = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 14);
				xmm_srcf = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 15);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(src + 64), _MM_HINT_NTA);
				ymm_src0 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src0), xmm_src4, 1);
				ymm_src1 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src1), xmm_src5, 1);
				ymm_src2 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src2), xmm_src6, 1);
				ymm_src3 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src3), xmm_src7, 1);
				ymm_src4 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src8), xmm_srcc, 1);
				ymm_src5 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src9), xmm_srcd, 1);
				ymm_src6 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_srca), xmm_srce, 1);
				ymm_src7 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_srcb), xmm_srcf, 1);
				ymm_dst0 = _mm256_shuffle_epi8(ymm_src0, ymm_mask);
				ymm_dst1 = _mm256_shuffle_epi8(ymm_src1, ymm_mask);
				ymm_dst2 = _mm256_shuffle_epi8(ymm_src2, ymm_mask);
				ymm_dst3 = _mm256_shuffle_epi8(ymm_src3, ymm_mask);
				ymm_dst4 = _mm256_shuffle_epi8(ymm_src4, ymm_mask);
				ymm_dst5 = _mm256_shuffle_epi8(ymm_src5, ymm_mask);
				ymm_dst6 = _mm256_shuffle_epi8(ymm_src6, ymm_mask);
				ymm_dst7 = _mm256_shuffle_epi8(ymm_src7, ymm_mask);
				ymm_dst0 = _mm256_unpacklo_epi32(ymm_dst0, ymm_dst1);
				ymm_dst2 = _mm256_unpacklo_epi32(ymm_dst2, ymm_dst3);
				ymm_dst4 = _mm256_unpacklo_epi32(ymm_dst4, ymm_dst5);
				ymm_dst6 = _mm256_unpacklo_epi32(ymm_dst6, ymm_dst7);
				ymm_dst0 = _mm256_unpacklo_epi64(ymm_dst0, ymm_dst2);
				ymm_dst4 = _mm256_unpacklo_epi64(ymm_dst4, ymm_dst6);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst), ymm_dst0);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst) + 1, ymm_dst4);
				src += 64;
				dst += 64;
			}
		}

		template <>
		void cvtu32_avx2_medium<signed short>(signed short* dst, const unsigned int* src, size_t n)
		{
			const __m256i ymm_mask = _mm256_set_epi64x(0xffffffffffffffffi64, 0x0d0c090805040100i64, 0xffffffffffffffffi64, 0x0d0c090805040100i64);
			__m128i xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128i xmm_src8, xmm_src9, xmm_srca, xmm_srcb, xmm_srcc, xmm_srcd, xmm_srce, xmm_srcf;
			__m256i ymm_src0, ymm_src1, ymm_src2, ymm_src3, ymm_src4, ymm_src5, ymm_src6, ymm_src7;
			__m256i ymm_dst0, ymm_dst1, ymm_dst2, ymm_dst3, ymm_dst4, ymm_dst5, ymm_dst6, ymm_dst7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			for (; n >= 64; n -= 64)
			{
				xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
				xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
				xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
				xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
				xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
				xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
				xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
				xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
				xmm_src8 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 8);
				xmm_src9 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 9);
				xmm_srca = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 10);
				xmm_srcb = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 11);
				xmm_srcc = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 12);
				xmm_srcd = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 13);
				xmm_srce = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 14);
				xmm_srcf = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 15);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(src + 64), _MM_HINT_NTA);
				ymm_src0 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src0), xmm_src2, 1);
				ymm_src1 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src1), xmm_src3, 1);
				ymm_src2 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src4), xmm_src6, 1);
				ymm_src3 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src5), xmm_src7, 1);
				ymm_src4 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src8), xmm_srca, 1);
				ymm_src5 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src9), xmm_srcb, 1);
				ymm_src6 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_srcc), xmm_srce, 1);
				ymm_src7 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_srcd), xmm_srcf, 1);
				ymm_dst0 = _mm256_shuffle_epi8(ymm_src0, ymm_mask);
				ymm_dst1 = _mm256_shuffle_epi8(ymm_src1, ymm_mask);
				ymm_dst2 = _mm256_shuffle_epi8(ymm_src2, ymm_mask);
				ymm_dst3 = _mm256_shuffle_epi8(ymm_src3, ymm_mask);
				ymm_dst4 = _mm256_shuffle_epi8(ymm_src4, ymm_mask);
				ymm_dst5 = _mm256_shuffle_epi8(ymm_src5, ymm_mask);
				ymm_dst6 = _mm256_shuffle_epi8(ymm_src6, ymm_mask);
				ymm_dst7 = _mm256_shuffle_epi8(ymm_src7, ymm_mask);
				ymm_dst0 = _mm256_unpacklo_epi64(ymm_dst0, ymm_dst1);
				ymm_dst2 = _mm256_unpacklo_epi64(ymm_dst2, ymm_dst3);
				ymm_dst4 = _mm256_unpacklo_epi64(ymm_dst4, ymm_dst5);
				ymm_dst6 = _mm256_unpacklo_epi64(ymm_dst6, ymm_dst7);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst), ymm_dst0);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst) + 1, ymm_dst2);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst) + 2, ymm_dst4);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst) + 3, ymm_dst6);
				src += 64;
				dst += 64;
			}
		}

		template <>
		void cvtu32_avx2_medium<unsigned short>(unsigned short* dst, const unsigned int* src, size_t n)
		{
			const __m256i ymm_mask = _mm256_set_epi64x(0xffffffffffffffffi64, 0x0d0c090805040100i64, 0xffffffffffffffffi64, 0x0d0c090805040100i64);
			__m128i xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128i xmm_src8, xmm_src9, xmm_srca, xmm_srcb, xmm_srcc, xmm_srcd, xmm_srce, xmm_srcf;
			__m256i ymm_src0, ymm_src1, ymm_src2, ymm_src3, ymm_src4, ymm_src5, ymm_src6, ymm_src7;
			__m256i ymm_dst0, ymm_dst1, ymm_dst2, ymm_dst3, ymm_dst4, ymm_dst5, ymm_dst6, ymm_dst7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			for (; n >= 64; n -= 64)
			{
				xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
				xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
				xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
				xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
				xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
				xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
				xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
				xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
				xmm_src8 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 8);
				xmm_src9 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 9);
				xmm_srca = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 10);
				xmm_srcb = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 11);
				xmm_srcc = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 12);
				xmm_srcd = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 13);
				xmm_srce = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 14);
				xmm_srcf = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 15);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(src + 64), _MM_HINT_NTA);
				ymm_src0 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src0), xmm_src2, 1);
				ymm_src1 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src1), xmm_src3, 1);
				ymm_src2 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src4), xmm_src6, 1);
				ymm_src3 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src5), xmm_src7, 1);
				ymm_src4 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src8), xmm_srca, 1);
				ymm_src5 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src9), xmm_srcb, 1);
				ymm_src6 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_srcc), xmm_srce, 1);
				ymm_src7 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_srcd), xmm_srcf, 1);
				ymm_dst0 = _mm256_shuffle_epi8(ymm_src0, ymm_mask);
				ymm_dst1 = _mm256_shuffle_epi8(ymm_src1, ymm_mask);
				ymm_dst2 = _mm256_shuffle_epi8(ymm_src2, ymm_mask);
				ymm_dst3 = _mm256_shuffle_epi8(ymm_src3, ymm_mask);
				ymm_dst4 = _mm256_shuffle_epi8(ymm_src4, ymm_mask);
				ymm_dst5 = _mm256_shuffle_epi8(ymm_src5, ymm_mask);
				ymm_dst6 = _mm256_shuffle_epi8(ymm_src6, ymm_mask);
				ymm_dst7 = _mm256_shuffle_epi8(ymm_src7, ymm_mask);
				ymm_dst0 = _mm256_unpacklo_epi64(ymm_dst0, ymm_dst1);
				ymm_dst2 = _mm256_unpacklo_epi64(ymm_dst2, ymm_dst3);
				ymm_dst4 = _mm256_unpacklo_epi64(ymm_dst4, ymm_dst5);
				ymm_dst6 = _mm256_unpacklo_epi64(ymm_dst6, ymm_dst7);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst), ymm_dst0);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst) + 1, ymm_dst2);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst) + 2, ymm_dst4);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst) + 3, ymm_dst6);
				src += 64;
				dst += 64;
			}
		}

		template <>
		void cvtu32_avx2_medium<float>(float* dst, const unsigned int* src, size_t n)
		{
			const __m256 ymm_zero = _mm256_setzero_ps();
			const __m256 ymm_max = _mm256_castsi256_ps(_mm256_set1_epi32(0x4f800000));
			__m256i ymm_src0, ymm_src1, ymm_src2, ymm_src3, ymm_src4, ymm_src5, ymm_src6, ymm_src7;
			__m256 ymm_tmp0, ymm_tmp1, ymm_tmp2, ymm_tmp3, ymm_tmp4, ymm_tmp5, ymm_tmp6, ymm_tmp7;
			__m256 ymm_dst0, ymm_dst1, ymm_dst2, ymm_dst3, ymm_dst4, ymm_dst5, ymm_dst6, ymm_dst7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			for (; n >= 64; n -= 64)
			{
				ymm_src0 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(src));
				ymm_src1 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(src) + 1);
				ymm_src2 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(src) + 2);
				ymm_src3 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(src) + 3);
				ymm_src4 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(src) + 4);
				ymm_src5 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(src) + 5);
				ymm_src6 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(src) + 6);
				ymm_src7 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(src) + 7);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(src + 64), _MM_HINT_NTA);
				ymm_dst0 = _mm256_cvtepi32_ps(ymm_src0);
				ymm_dst1 = _mm256_cvtepi32_ps(ymm_src1);
				ymm_dst2 = _mm256_cvtepi32_ps(ymm_src2);
				ymm_dst3 = _mm256_cvtepi32_ps(ymm_src3);
				ymm_dst4 = _mm256_cvtepi32_ps(ymm_src4);
				ymm_dst5 = _mm256_cvtepi32_ps(ymm_src5);
				ymm_dst6 = _mm256_cvtepi32_ps(ymm_src6);
				ymm_dst7 = _mm256_cvtepi32_ps(ymm_src7);
				ymm_tmp0 = _mm256_cmp_ps(ymm_dst0, ymm_zero, _CMP_LT_OS);
				ymm_tmp1 = _mm256_cmp_ps(ymm_dst1, ymm_zero, _CMP_LT_OS);
				ymm_tmp2 = _mm256_cmp_ps(ymm_dst2, ymm_zero, _CMP_LT_OS);
				ymm_tmp3 = _mm256_cmp_ps(ymm_dst3, ymm_zero, _CMP_LT_OS);
				ymm_tmp4 = _mm256_cmp_ps(ymm_dst4, ymm_zero, _CMP_LT_OS);
				ymm_tmp5 = _mm256_cmp_ps(ymm_dst5, ymm_zero, _CMP_LT_OS);
				ymm_tmp6 = _mm256_cmp_ps(ymm_dst6, ymm_zero, _CMP_LT_OS);
				ymm_tmp7 = _mm256_cmp_ps(ymm_dst7, ymm_zero, _CMP_LT_OS);
				ymm_tmp0 = _mm256_and_ps(ymm_tmp0, ymm_max);
				ymm_tmp1 = _mm256_and_ps(ymm_tmp1, ymm_max);
				ymm_tmp2 = _mm256_and_ps(ymm_tmp2, ymm_max);
				ymm_tmp3 = _mm256_and_ps(ymm_tmp3, ymm_max);
				ymm_tmp4 = _mm256_and_ps(ymm_tmp4, ymm_max);
				ymm_tmp5 = _mm256_and_ps(ymm_tmp5, ymm_max);
				ymm_tmp6 = _mm256_and_ps(ymm_tmp6, ymm_max);
				ymm_tmp7 = _mm256_and_ps(ymm_tmp7, ymm_max);
				ymm_dst0 = _mm256_add_ps(ymm_dst0, ymm_tmp0);
				ymm_dst1 = _mm256_add_ps(ymm_dst1, ymm_tmp1);
				ymm_dst2 = _mm256_add_ps(ymm_dst2, ymm_tmp2);
				ymm_dst3 = _mm256_add_ps(ymm_dst3, ymm_tmp3);
				ymm_dst4 = _mm256_add_ps(ymm_dst4, ymm_tmp4);
				ymm_dst5 = _mm256_add_ps(ymm_dst5, ymm_tmp5);
				ymm_dst6 = _mm256_add_ps(ymm_dst6, ymm_tmp6);
				ymm_dst7 = _mm256_add_ps(ymm_dst7, ymm_tmp7);
				_mm256_storeu_ps(dst, ymm_dst0);
				_mm256_storeu_ps(dst + 8, ymm_dst1);
				_mm256_storeu_ps(dst + 16, ymm_dst2);
				_mm256_storeu_ps(dst + 24, ymm_dst3);
				_mm256_storeu_ps(dst + 32, ymm_dst4);
				_mm256_storeu_ps(dst + 40, ymm_dst5);
				_mm256_storeu_ps(dst + 48, ymm_dst6);
				_mm256_storeu_ps(dst + 56, ymm_dst7);
				src += 64;
				dst += 64;
			}
		}

		template <>
		void cvtu32_avx2_medium<double>(double* dst, const unsigned int* src, size_t n)
		{
			const __m256d ymm_zero = _mm256_setzero_pd();
			const __m256d ymm_max = _mm256_castsi256_pd(_mm256_set1_epi64x(0x41f0000000000000));
			__m128i xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128i xmm_src8, xmm_src9, xmm_srca, xmm_srcb, xmm_srcc, xmm_srcd, xmm_srce, xmm_srcf;
			__m256d ymm_tmp0, ymm_tmp1, ymm_tmp2, ymm_tmp3, ymm_tmp4, ymm_tmp5, ymm_tmp6, ymm_tmp7;
			__m256d ymm_tmp8, ymm_tmp9, ymm_tmpa, ymm_tmpb, ymm_tmpc, ymm_tmpd, ymm_tmpe, ymm_tmpf;
			__m256d ymm_dst0, ymm_dst1, ymm_dst2, ymm_dst3, ymm_dst4, ymm_dst5, ymm_dst6, ymm_dst7;
			__m256d ymm_dst8, ymm_dst9, ymm_dsta, ymm_dstb, ymm_dstc, ymm_dstd, ymm_dste, ymm_dstf;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			for (; n >= 64; n -= 64)
			{
				xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
				xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
				xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
				xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
				xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
				xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
				xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
				xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
				xmm_src8 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 8);
				xmm_src9 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 9);
				xmm_srca = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 10);
				xmm_srcb = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 11);
				xmm_srcc = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 12);
				xmm_srcd = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 13);
				xmm_srce = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 14);
				xmm_srcf = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 15);
				 // Fetch the line of data from memory.
				 _mm_prefetch(reinterpret_cast<const char*>(src + 64), _MM_HINT_NTA);
				 ymm_dst0 = _mm256_cvtepi32_pd(xmm_src0);
				 ymm_dst1 = _mm256_cvtepi32_pd(xmm_src1);
				 ymm_dst2 = _mm256_cvtepi32_pd(xmm_src2);
				 ymm_dst3 = _mm256_cvtepi32_pd(xmm_src3);
				 ymm_dst4 = _mm256_cvtepi32_pd(xmm_src4);
				 ymm_dst5 = _mm256_cvtepi32_pd(xmm_src5);
				 ymm_dst6 = _mm256_cvtepi32_pd(xmm_src6);
				 ymm_dst7 = _mm256_cvtepi32_pd(xmm_src7);
				 ymm_dst8 = _mm256_cvtepi32_pd(xmm_src8);
				 ymm_dst9 = _mm256_cvtepi32_pd(xmm_src9);
				 ymm_dsta = _mm256_cvtepi32_pd(xmm_srca);
				 ymm_dstb = _mm256_cvtepi32_pd(xmm_srcb);
				 ymm_dstc = _mm256_cvtepi32_pd(xmm_srcc);
				 ymm_dstd = _mm256_cvtepi32_pd(xmm_srcd);
				 ymm_dste = _mm256_cvtepi32_pd(xmm_srce);
				 ymm_dstf = _mm256_cvtepi32_pd(xmm_srcf);
				 ymm_tmp0 = _mm256_cmp_pd(ymm_dst0, ymm_zero, _CMP_LT_OS);
				 ymm_tmp1 = _mm256_cmp_pd(ymm_dst1, ymm_zero, _CMP_LT_OS);
				 ymm_tmp2 = _mm256_cmp_pd(ymm_dst2, ymm_zero, _CMP_LT_OS);
				 ymm_tmp3 = _mm256_cmp_pd(ymm_dst3, ymm_zero, _CMP_LT_OS);
				 ymm_tmp4 = _mm256_cmp_pd(ymm_dst4, ymm_zero, _CMP_LT_OS);
				 ymm_tmp5 = _mm256_cmp_pd(ymm_dst5, ymm_zero, _CMP_LT_OS);
				 ymm_tmp6 = _mm256_cmp_pd(ymm_dst6, ymm_zero, _CMP_LT_OS);
				 ymm_tmp7 = _mm256_cmp_pd(ymm_dst7, ymm_zero, _CMP_LT_OS);
				 ymm_tmp8 = _mm256_cmp_pd(ymm_dst8, ymm_zero, _CMP_LT_OS);
				 ymm_tmp9 = _mm256_cmp_pd(ymm_dst9, ymm_zero, _CMP_LT_OS);
				 ymm_tmpa = _mm256_cmp_pd(ymm_dsta, ymm_zero, _CMP_LT_OS);
				 ymm_tmpb = _mm256_cmp_pd(ymm_dstb, ymm_zero, _CMP_LT_OS);
				 ymm_tmpc = _mm256_cmp_pd(ymm_dstc, ymm_zero, _CMP_LT_OS);
				 ymm_tmpd = _mm256_cmp_pd(ymm_dstd, ymm_zero, _CMP_LT_OS);
				 ymm_tmpe = _mm256_cmp_pd(ymm_dste, ymm_zero, _CMP_LT_OS);
				 ymm_tmpf = _mm256_cmp_pd(ymm_dstf, ymm_zero, _CMP_LT_OS);
				 ymm_tmp0 = _mm256_and_pd(ymm_tmp0, ymm_max);
				 ymm_tmp1 = _mm256_and_pd(ymm_tmp1, ymm_max);
				 ymm_tmp2 = _mm256_and_pd(ymm_tmp2, ymm_max);
				 ymm_tmp3 = _mm256_and_pd(ymm_tmp3, ymm_max);
				 ymm_tmp4 = _mm256_and_pd(ymm_tmp4, ymm_max);
				 ymm_tmp5 = _mm256_and_pd(ymm_tmp5, ymm_max);
				 ymm_tmp6 = _mm256_and_pd(ymm_tmp6, ymm_max);
				 ymm_tmp7 = _mm256_and_pd(ymm_tmp7, ymm_max);
				 ymm_tmp8 = _mm256_and_pd(ymm_tmp8, ymm_max);
				 ymm_tmp9 = _mm256_and_pd(ymm_tmp9, ymm_max);
				 ymm_tmpa = _mm256_and_pd(ymm_tmpa, ymm_max);
				 ymm_tmpb = _mm256_and_pd(ymm_tmpb, ymm_max);
				 ymm_tmpc = _mm256_and_pd(ymm_tmpc, ymm_max);
				 ymm_tmpd = _mm256_and_pd(ymm_tmpd, ymm_max);
				 ymm_tmpe = _mm256_and_pd(ymm_tmpe, ymm_max);
				 ymm_tmpf = _mm256_and_pd(ymm_tmpf, ymm_max);
				 ymm_dst0 = _mm256_add_pd(ymm_dst0, ymm_tmp0);
				 ymm_dst1 = _mm256_add_pd(ymm_dst1, ymm_tmp1);
				 ymm_dst2 = _mm256_add_pd(ymm_dst2, ymm_tmp2);
				 ymm_dst3 = _mm256_add_pd(ymm_dst3, ymm_tmp3);
				 ymm_dst4 = _mm256_add_pd(ymm_dst4, ymm_tmp4);
				 ymm_dst5 = _mm256_add_pd(ymm_dst5, ymm_tmp5);
				 ymm_dst6 = _mm256_add_pd(ymm_dst6, ymm_tmp6);
				 ymm_dst7 = _mm256_add_pd(ymm_dst7, ymm_tmp7);
				 ymm_dst8 = _mm256_add_pd(ymm_dst8, ymm_tmp8);
				 ymm_dst9 = _mm256_add_pd(ymm_dst9, ymm_tmp9);
				 ymm_dsta = _mm256_add_pd(ymm_dsta, ymm_tmpa);
				 ymm_dstb = _mm256_add_pd(ymm_dstb, ymm_tmpb);
				 ymm_dstc = _mm256_add_pd(ymm_dstc, ymm_tmpc);
				 ymm_dstd = _mm256_add_pd(ymm_dstd, ymm_tmpd);
				 ymm_dste = _mm256_add_pd(ymm_dste, ymm_tmpe);
				 ymm_dstf = _mm256_add_pd(ymm_dstf, ymm_tmpf);
				_mm256_storeu_pd(dst, ymm_dst0);
				_mm256_storeu_pd(dst + 4, ymm_dst1);
				_mm256_storeu_pd(dst + 8, ymm_dst2);
				_mm256_storeu_pd(dst + 12, ymm_dst3);
				_mm256_storeu_pd(dst + 16, ymm_dst4);
				_mm256_storeu_pd(dst + 20, ymm_dst5);
				_mm256_storeu_pd(dst + 24, ymm_dst6);
				_mm256_storeu_pd(dst + 28, ymm_dst7);
				_mm256_storeu_pd(dst + 32, ymm_dst8);
				_mm256_storeu_pd(dst + 36, ymm_dst9);
				_mm256_storeu_pd(dst + 40, ymm_dsta);
				_mm256_storeu_pd(dst + 44, ymm_dstb);
				_mm256_storeu_pd(dst + 48, ymm_dstc);
				_mm256_storeu_pd(dst + 52, ymm_dstd);
				_mm256_storeu_pd(dst + 56, ymm_dste);
				_mm256_storeu_pd(dst + 60, ymm_dstf);
				src += 64;
				dst += 64;
			}
		}

		// Function template cvtu32_avx2_large

		template <class T>
		inline void cvtu32_avx2_large(T* dst, const unsigned int* src, size_t n)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		inline void cvtu32_avx2_large<signed char>(signed char* dst, const unsigned int* src, size_t n)
		{
			const size_t padding = 32 - (reinterpret_cast<size_t>(dst) & 31);
			const __m256i ymm_mask = _mm256_set_epi64x(0xffffffffffffffffi64, 0xffffffff0c080400i64, 0xffffffffffffffffi64, 0xffffffff0c080400i64);
			__m128i xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128i xmm_src8, xmm_src9, xmm_srca, xmm_srcb, xmm_srcc, xmm_srcd, xmm_srce, xmm_srcf;
			__m256i ymm_src0, ymm_src1, ymm_src2, ymm_src3, ymm_src4, ymm_src5, ymm_src6, ymm_src7;
			__m256i ymm_dst0, ymm_dst1, ymm_dst2, ymm_dst3, ymm_dst4, ymm_dst5, ymm_dst6, ymm_dst7;

			// Align the destination to a 32-byte boundary.
			xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
			xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
			xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
			xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
			xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
			xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
			ymm_src0 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src0), xmm_src4, 1);
			ymm_src1 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src1), xmm_src5, 1);
			ymm_src2 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src2), xmm_src6, 1);
			ymm_src3 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src3), xmm_src7, 1);
			ymm_dst0 = _mm256_shuffle_epi8(ymm_src0, ymm_mask);
			ymm_dst1 = _mm256_shuffle_epi8(ymm_src1, ymm_mask);
			ymm_dst2 = _mm256_shuffle_epi8(ymm_src2, ymm_mask);
			ymm_dst3 = _mm256_shuffle_epi8(ymm_src3, ymm_mask);
			ymm_dst0 = _mm256_unpacklo_epi32(ymm_dst0, ymm_dst1);
			ymm_dst2 = _mm256_unpacklo_epi32(ymm_dst2, ymm_dst3);
			ymm_dst0 = _mm256_unpacklo_epi64(ymm_dst0, ymm_dst2);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst), ymm_dst0);
			dst += padding;
			src += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			// If the source is aligned on a 16-byte boundary.
			if ((reinterpret_cast<size_t>(src) & 15) == 0)
			{
				for (; n >= 64; n -= 64)
				{
					xmm_src0 = _mm_load_si128(reinterpret_cast<const __m128i*>(src));
					xmm_src1 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 1);
					xmm_src2 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 2);
					xmm_src3 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 3);
					xmm_src4 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 4);
					xmm_src5 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 5);
					xmm_src6 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 6);
					xmm_src7 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 7);
					xmm_src8 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 8);
					xmm_src9 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 9);
					xmm_srca = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 10);
					xmm_srcb = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 11);
					xmm_srcc = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 12);
					xmm_srcd = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 13);
					xmm_srce = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 14);
					xmm_srcf = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 15);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 64), _MM_HINT_NTA);
					ymm_src0 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src0), xmm_src4, 1);
					ymm_src1 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src1), xmm_src5, 1);
					ymm_src2 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src2), xmm_src6, 1);
					ymm_src3 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src3), xmm_src7, 1);
					ymm_src4 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src8), xmm_srcc, 1);
					ymm_src5 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src9), xmm_srcd, 1);
					ymm_src6 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_srca), xmm_srce, 1);
					ymm_src7 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_srcb), xmm_srcf, 1);
					ymm_dst0 = _mm256_shuffle_epi8(ymm_src0, ymm_mask);
					ymm_dst1 = _mm256_shuffle_epi8(ymm_src1, ymm_mask);
					ymm_dst2 = _mm256_shuffle_epi8(ymm_src2, ymm_mask);
					ymm_dst3 = _mm256_shuffle_epi8(ymm_src3, ymm_mask);
					ymm_dst4 = _mm256_shuffle_epi8(ymm_src4, ymm_mask);
					ymm_dst5 = _mm256_shuffle_epi8(ymm_src5, ymm_mask);
					ymm_dst6 = _mm256_shuffle_epi8(ymm_src6, ymm_mask);
					ymm_dst7 = _mm256_shuffle_epi8(ymm_src7, ymm_mask);
					ymm_dst0 = _mm256_unpacklo_epi32(ymm_dst0, ymm_dst1);
					ymm_dst2 = _mm256_unpacklo_epi32(ymm_dst2, ymm_dst3);
					ymm_dst4 = _mm256_unpacklo_epi32(ymm_dst4, ymm_dst5);
					ymm_dst6 = _mm256_unpacklo_epi32(ymm_dst6, ymm_dst7);
					ymm_dst0 = _mm256_unpacklo_epi64(ymm_dst0, ymm_dst2);
					ymm_dst4 = _mm256_unpacklo_epi64(ymm_dst4, ymm_dst6);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(dst), ymm_dst0);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(dst) + 1, ymm_dst4);
					src += 64;
					dst += 64;
				}
			}
			else
			{
				for (; n >= 64; n -= 64)
				{
					xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
					xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
					xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
					xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
					xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
					xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
					xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
					xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
					xmm_src8 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 8);
					xmm_src9 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 9);
					xmm_srca = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 10);
					xmm_srcb = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 11);
					xmm_srcc = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 12);
					xmm_srcd = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 13);
					xmm_srce = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 14);
					xmm_srcf = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 15);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 64), _MM_HINT_NTA);
					ymm_src0 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src0), xmm_src4, 1);
					ymm_src1 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src1), xmm_src5, 1);
					ymm_src2 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src2), xmm_src6, 1);
					ymm_src3 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src3), xmm_src7, 1);
					ymm_src4 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src8), xmm_srcc, 1);
					ymm_src5 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src9), xmm_srcd, 1);
					ymm_src6 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_srca), xmm_srce, 1);
					ymm_src7 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_srcb), xmm_srcf, 1);
					ymm_dst0 = _mm256_shuffle_epi8(ymm_src0, ymm_mask);
					ymm_dst1 = _mm256_shuffle_epi8(ymm_src1, ymm_mask);
					ymm_dst2 = _mm256_shuffle_epi8(ymm_src2, ymm_mask);
					ymm_dst3 = _mm256_shuffle_epi8(ymm_src3, ymm_mask);
					ymm_dst4 = _mm256_shuffle_epi8(ymm_src4, ymm_mask);
					ymm_dst5 = _mm256_shuffle_epi8(ymm_src5, ymm_mask);
					ymm_dst6 = _mm256_shuffle_epi8(ymm_src6, ymm_mask);
					ymm_dst7 = _mm256_shuffle_epi8(ymm_src7, ymm_mask);
					ymm_dst0 = _mm256_unpacklo_epi32(ymm_dst0, ymm_dst1);
					ymm_dst2 = _mm256_unpacklo_epi32(ymm_dst2, ymm_dst3);
					ymm_dst4 = _mm256_unpacklo_epi32(ymm_dst4, ymm_dst5);
					ymm_dst6 = _mm256_unpacklo_epi32(ymm_dst6, ymm_dst7);
					ymm_dst0 = _mm256_unpacklo_epi64(ymm_dst0, ymm_dst2);
					ymm_dst4 = _mm256_unpacklo_epi64(ymm_dst4, ymm_dst6);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(dst), ymm_dst0);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(dst) + 1, ymm_dst4);
					src += 64;
					dst += 64;
				}
			}
		}

		template <>
		inline void cvtu32_avx2_large<unsigned char>(unsigned char* dst, const unsigned int* src, size_t n)
		{
			const size_t padding = 32 - (reinterpret_cast<size_t>(dst) & 31);
			const __m256i ymm_mask = _mm256_set_epi64x(0xffffffffffffffffi64, 0xffffffff0c080400i64, 0xffffffffffffffffi64, 0xffffffff0c080400i64);
			__m128i xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128i xmm_src8, xmm_src9, xmm_srca, xmm_srcb, xmm_srcc, xmm_srcd, xmm_srce, xmm_srcf;
			__m256i ymm_src0, ymm_src1, ymm_src2, ymm_src3, ymm_src4, ymm_src5, ymm_src6, ymm_src7;
			__m256i ymm_dst0, ymm_dst1, ymm_dst2, ymm_dst3, ymm_dst4, ymm_dst5, ymm_dst6, ymm_dst7;

			// Align the destination to a 32-byte boundary.
			xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
			xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
			xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
			xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
			xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
			xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
			ymm_src0 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src0), xmm_src4, 1);
			ymm_src1 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src1), xmm_src5, 1);
			ymm_src2 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src2), xmm_src6, 1);
			ymm_src3 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src3), xmm_src7, 1);
			ymm_dst0 = _mm256_shuffle_epi8(ymm_src0, ymm_mask);
			ymm_dst1 = _mm256_shuffle_epi8(ymm_src1, ymm_mask);
			ymm_dst2 = _mm256_shuffle_epi8(ymm_src2, ymm_mask);
			ymm_dst3 = _mm256_shuffle_epi8(ymm_src3, ymm_mask);
			ymm_dst0 = _mm256_unpacklo_epi32(ymm_dst0, ymm_dst1);
			ymm_dst2 = _mm256_unpacklo_epi32(ymm_dst2, ymm_dst3);
			ymm_dst0 = _mm256_unpacklo_epi64(ymm_dst0, ymm_dst2);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst), ymm_dst0);
			dst += padding;
			src += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			// If the source is aligned on a 16-byte boundary.
			if ((reinterpret_cast<size_t>(src) & 15) == 0)
			{
				for (; n >= 64; n -= 64)
				{
					xmm_src0 = _mm_load_si128(reinterpret_cast<const __m128i*>(src));
					xmm_src1 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 1);
					xmm_src2 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 2);
					xmm_src3 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 3);
					xmm_src4 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 4);
					xmm_src5 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 5);
					xmm_src6 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 6);
					xmm_src7 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 7);
					xmm_src8 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 8);
					xmm_src9 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 9);
					xmm_srca = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 10);
					xmm_srcb = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 11);
					xmm_srcc = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 12);
					xmm_srcd = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 13);
					xmm_srce = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 14);
					xmm_srcf = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 15);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 64), _MM_HINT_NTA);
					ymm_src0 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src0), xmm_src4, 1);
					ymm_src1 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src1), xmm_src5, 1);
					ymm_src2 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src2), xmm_src6, 1);
					ymm_src3 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src3), xmm_src7, 1);
					ymm_src4 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src8), xmm_srcc, 1);
					ymm_src5 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src9), xmm_srcd, 1);
					ymm_src6 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_srca), xmm_srce, 1);
					ymm_src7 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_srcb), xmm_srcf, 1);
					ymm_dst0 = _mm256_shuffle_epi8(ymm_src0, ymm_mask);
					ymm_dst1 = _mm256_shuffle_epi8(ymm_src1, ymm_mask);
					ymm_dst2 = _mm256_shuffle_epi8(ymm_src2, ymm_mask);
					ymm_dst3 = _mm256_shuffle_epi8(ymm_src3, ymm_mask);
					ymm_dst4 = _mm256_shuffle_epi8(ymm_src4, ymm_mask);
					ymm_dst5 = _mm256_shuffle_epi8(ymm_src5, ymm_mask);
					ymm_dst6 = _mm256_shuffle_epi8(ymm_src6, ymm_mask);
					ymm_dst7 = _mm256_shuffle_epi8(ymm_src7, ymm_mask);
					ymm_dst0 = _mm256_unpacklo_epi32(ymm_dst0, ymm_dst1);
					ymm_dst2 = _mm256_unpacklo_epi32(ymm_dst2, ymm_dst3);
					ymm_dst4 = _mm256_unpacklo_epi32(ymm_dst4, ymm_dst5);
					ymm_dst6 = _mm256_unpacklo_epi32(ymm_dst6, ymm_dst7);
					ymm_dst0 = _mm256_unpacklo_epi64(ymm_dst0, ymm_dst2);
					ymm_dst4 = _mm256_unpacklo_epi64(ymm_dst4, ymm_dst6);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(dst), ymm_dst0);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(dst) + 1, ymm_dst4);
					src += 64;
					dst += 64;
				}
			}
			else
			{
				for (; n >= 64; n -= 64)
				{
					xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
					xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
					xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
					xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
					xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
					xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
					xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
					xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
					xmm_src8 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 8);
					xmm_src9 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 9);
					xmm_srca = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 10);
					xmm_srcb = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 11);
					xmm_srcc = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 12);
					xmm_srcd = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 13);
					xmm_srce = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 14);
					xmm_srcf = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 15);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 64), _MM_HINT_NTA);
					ymm_src0 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src0), xmm_src4, 1);
					ymm_src1 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src1), xmm_src5, 1);
					ymm_src2 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src2), xmm_src6, 1);
					ymm_src3 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src3), xmm_src7, 1);
					ymm_src4 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src8), xmm_srcc, 1);
					ymm_src5 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src9), xmm_srcd, 1);
					ymm_src6 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_srca), xmm_srce, 1);
					ymm_src7 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_srcb), xmm_srcf, 1);
					ymm_dst0 = _mm256_shuffle_epi8(ymm_src0, ymm_mask);
					ymm_dst1 = _mm256_shuffle_epi8(ymm_src1, ymm_mask);
					ymm_dst2 = _mm256_shuffle_epi8(ymm_src2, ymm_mask);
					ymm_dst3 = _mm256_shuffle_epi8(ymm_src3, ymm_mask);
					ymm_dst4 = _mm256_shuffle_epi8(ymm_src4, ymm_mask);
					ymm_dst5 = _mm256_shuffle_epi8(ymm_src5, ymm_mask);
					ymm_dst6 = _mm256_shuffle_epi8(ymm_src6, ymm_mask);
					ymm_dst7 = _mm256_shuffle_epi8(ymm_src7, ymm_mask);
					ymm_dst0 = _mm256_unpacklo_epi32(ymm_dst0, ymm_dst1);
					ymm_dst2 = _mm256_unpacklo_epi32(ymm_dst2, ymm_dst3);
					ymm_dst4 = _mm256_unpacklo_epi32(ymm_dst4, ymm_dst5);
					ymm_dst6 = _mm256_unpacklo_epi32(ymm_dst6, ymm_dst7);
					ymm_dst0 = _mm256_unpacklo_epi64(ymm_dst0, ymm_dst2);
					ymm_dst4 = _mm256_unpacklo_epi64(ymm_dst4, ymm_dst6);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(dst), ymm_dst0);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(dst) + 1, ymm_dst4);
					src += 64;
					dst += 64;
				}
			}
		}

		template <>
		inline void cvtu32_avx2_large<signed short>(signed short* dst, const unsigned int* src, size_t n)
		{
			const size_t padding = 16 - (reinterpret_cast<size_t>(dst) & 15);
			const __m256i ymm_mask = _mm256_set_epi64x(0xffffffffffffffffi64, 0x0d0c090805040100i64, 0xffffffffffffffffi64, 0x0d0c090805040100i64);
			__m128i xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128i xmm_src8, xmm_src9, xmm_srca, xmm_srcb, xmm_srcc, xmm_srcd, xmm_srce, xmm_srcf;
			__m256i ymm_src0, ymm_src1, ymm_src2, ymm_src3, ymm_src4, ymm_src5, ymm_src6, ymm_src7;
			__m256i ymm_dst0, ymm_dst1, ymm_dst2, ymm_dst3, ymm_dst4, ymm_dst5, ymm_dst6, ymm_dst7;

			// Align the destination to a 32-byte boundary.
			xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
			xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
			ymm_src0 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src0), xmm_src2, 1);
			ymm_src1 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src1), xmm_src3, 1);
			ymm_dst0 = _mm256_shuffle_epi8(ymm_src0, ymm_mask);
			ymm_dst1 = _mm256_shuffle_epi8(ymm_src1, ymm_mask);
			ymm_dst0 = _mm256_unpacklo_epi64(ymm_dst0, ymm_dst1);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst), ymm_dst0);
			dst += padding;
			src += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			// If the source is aligned on a 16-byte boundary.
			if ((reinterpret_cast<size_t>(src) & 15) == 0)
			{
				for (; n >= 64; n -= 64)
				{
					xmm_src0 = _mm_load_si128(reinterpret_cast<const __m128i*>(src));
					xmm_src1 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 1);
					xmm_src2 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 2);
					xmm_src3 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 3);
					xmm_src4 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 4);
					xmm_src5 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 5);
					xmm_src6 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 6);
					xmm_src7 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 7);
					xmm_src8 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 8);
					xmm_src9 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 9);
					xmm_srca = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 10);
					xmm_srcb = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 11);
					xmm_srcc = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 12);
					xmm_srcd = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 13);
					xmm_srce = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 14);
					xmm_srcf = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 15);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 64), _MM_HINT_NTA);
					ymm_src0 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src0), xmm_src2, 1);
					ymm_src1 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src1), xmm_src3, 1);
					ymm_src2 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src4), xmm_src6, 1);
					ymm_src3 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src5), xmm_src7, 1);
					ymm_src4 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src8), xmm_srca, 1);
					ymm_src5 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src9), xmm_srcb, 1);
					ymm_src6 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_srcc), xmm_srce, 1);
					ymm_src7 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_srcd), xmm_srcf, 1);
					ymm_dst0 = _mm256_shuffle_epi8(ymm_src0, ymm_mask);
					ymm_dst1 = _mm256_shuffle_epi8(ymm_src1, ymm_mask);
					ymm_dst2 = _mm256_shuffle_epi8(ymm_src2, ymm_mask);
					ymm_dst3 = _mm256_shuffle_epi8(ymm_src3, ymm_mask);
					ymm_dst4 = _mm256_shuffle_epi8(ymm_src4, ymm_mask);
					ymm_dst5 = _mm256_shuffle_epi8(ymm_src5, ymm_mask);
					ymm_dst6 = _mm256_shuffle_epi8(ymm_src6, ymm_mask);
					ymm_dst7 = _mm256_shuffle_epi8(ymm_src7, ymm_mask);
					ymm_dst0 = _mm256_unpacklo_epi64(ymm_dst0, ymm_dst1);
					ymm_dst2 = _mm256_unpacklo_epi64(ymm_dst2, ymm_dst3);
					ymm_dst4 = _mm256_unpacklo_epi64(ymm_dst4, ymm_dst5);
					ymm_dst6 = _mm256_unpacklo_epi64(ymm_dst6, ymm_dst7);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(dst), ymm_dst0);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(dst) + 1, ymm_dst2);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(dst) + 2, ymm_dst4);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(dst) + 3, ymm_dst6);
					src += 64;
					dst += 64;
				}
			}
			else
			{
				for (; n >= 64; n -= 64)
				{
					xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
					xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
					xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
					xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
					xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
					xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
					xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
					xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
					xmm_src8 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 8);
					xmm_src9 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 9);
					xmm_srca = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 10);
					xmm_srcb = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 11);
					xmm_srcc = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 12);
					xmm_srcd = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 13);
					xmm_srce = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 14);
					xmm_srcf = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 15);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 64), _MM_HINT_NTA);
					ymm_src0 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src0), xmm_src2, 1);
					ymm_src1 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src1), xmm_src3, 1);
					ymm_src2 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src4), xmm_src6, 1);
					ymm_src3 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src5), xmm_src7, 1);
					ymm_src4 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src8), xmm_srca, 1);
					ymm_src5 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src9), xmm_srcb, 1);
					ymm_src6 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_srcc), xmm_srce, 1);
					ymm_src7 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_srcd), xmm_srcf, 1);
					ymm_dst0 = _mm256_shuffle_epi8(ymm_src0, ymm_mask);
					ymm_dst1 = _mm256_shuffle_epi8(ymm_src1, ymm_mask);
					ymm_dst2 = _mm256_shuffle_epi8(ymm_src2, ymm_mask);
					ymm_dst3 = _mm256_shuffle_epi8(ymm_src3, ymm_mask);
					ymm_dst4 = _mm256_shuffle_epi8(ymm_src4, ymm_mask);
					ymm_dst5 = _mm256_shuffle_epi8(ymm_src5, ymm_mask);
					ymm_dst6 = _mm256_shuffle_epi8(ymm_src6, ymm_mask);
					ymm_dst7 = _mm256_shuffle_epi8(ymm_src7, ymm_mask);
					ymm_dst0 = _mm256_unpacklo_epi64(ymm_dst0, ymm_dst1);
					ymm_dst2 = _mm256_unpacklo_epi64(ymm_dst2, ymm_dst3);
					ymm_dst4 = _mm256_unpacklo_epi64(ymm_dst4, ymm_dst5);
					ymm_dst6 = _mm256_unpacklo_epi64(ymm_dst6, ymm_dst7);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(dst), ymm_dst0);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(dst) + 1, ymm_dst2);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(dst) + 2, ymm_dst4);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(dst) + 3, ymm_dst6);
					src += 64;
					dst += 64;
				}
			}
		}

		template <>
		inline void cvtu32_avx2_large<unsigned short>(unsigned short* dst, const unsigned int* src, size_t n)
		{
			const size_t padding = 16 - (reinterpret_cast<size_t>(dst) & 15);
			const __m256i ymm_mask = _mm256_set_epi64x(0xffffffffffffffffi64, 0x0d0c090805040100i64, 0xffffffffffffffffi64, 0x0d0c090805040100i64);
			__m128i xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128i xmm_src8, xmm_src9, xmm_srca, xmm_srcb, xmm_srcc, xmm_srcd, xmm_srce, xmm_srcf;
			__m256i ymm_src0, ymm_src1, ymm_src2, ymm_src3, ymm_src4, ymm_src5, ymm_src6, ymm_src7;
			__m256i ymm_dst0, ymm_dst1, ymm_dst2, ymm_dst3, ymm_dst4, ymm_dst5, ymm_dst6, ymm_dst7;

			// Align the destination to a 32-byte boundary.
			xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
			xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
			ymm_src0 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src0), xmm_src2, 1);
			ymm_src1 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src1), xmm_src3, 1);
			ymm_dst0 = _mm256_shuffle_epi8(ymm_src0, ymm_mask);
			ymm_dst1 = _mm256_shuffle_epi8(ymm_src1, ymm_mask);
			ymm_dst0 = _mm256_unpacklo_epi64(ymm_dst0, ymm_dst1);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(dst), ymm_dst0);
			dst += padding;
			src += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			// If the source is aligned on a 16-byte boundary.
			if ((reinterpret_cast<size_t>(src) & 15) == 0)
			{
				for (; n >= 64; n -= 64)
				{
					xmm_src0 = _mm_load_si128(reinterpret_cast<const __m128i*>(src));
					xmm_src1 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 1);
					xmm_src2 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 2);
					xmm_src3 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 3);
					xmm_src4 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 4);
					xmm_src5 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 5);
					xmm_src6 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 6);
					xmm_src7 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 7);
					xmm_src8 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 8);
					xmm_src9 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 9);
					xmm_srca = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 10);
					xmm_srcb = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 11);
					xmm_srcc = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 12);
					xmm_srcd = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 13);
					xmm_srce = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 14);
					xmm_srcf = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 15);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 64), _MM_HINT_NTA);
					ymm_src0 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src0), xmm_src2, 1);
					ymm_src1 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src1), xmm_src3, 1);
					ymm_src2 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src4), xmm_src6, 1);
					ymm_src3 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src5), xmm_src7, 1);
					ymm_src4 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src8), xmm_srca, 1);
					ymm_src5 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src9), xmm_srcb, 1);
					ymm_src6 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_srcc), xmm_srce, 1);
					ymm_src7 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_srcd), xmm_srcf, 1);
					ymm_dst0 = _mm256_shuffle_epi8(ymm_src0, ymm_mask);
					ymm_dst1 = _mm256_shuffle_epi8(ymm_src1, ymm_mask);
					ymm_dst2 = _mm256_shuffle_epi8(ymm_src2, ymm_mask);
					ymm_dst3 = _mm256_shuffle_epi8(ymm_src3, ymm_mask);
					ymm_dst4 = _mm256_shuffle_epi8(ymm_src4, ymm_mask);
					ymm_dst5 = _mm256_shuffle_epi8(ymm_src5, ymm_mask);
					ymm_dst6 = _mm256_shuffle_epi8(ymm_src6, ymm_mask);
					ymm_dst7 = _mm256_shuffle_epi8(ymm_src7, ymm_mask);
					ymm_dst0 = _mm256_unpacklo_epi64(ymm_dst0, ymm_dst1);
					ymm_dst2 = _mm256_unpacklo_epi64(ymm_dst2, ymm_dst3);
					ymm_dst4 = _mm256_unpacklo_epi64(ymm_dst4, ymm_dst5);
					ymm_dst6 = _mm256_unpacklo_epi64(ymm_dst6, ymm_dst7);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(dst), ymm_dst0);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(dst) + 1, ymm_dst2);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(dst) + 2, ymm_dst4);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(dst) + 3, ymm_dst6);
					src += 64;
					dst += 64;
				}
			}
			else
			{
				for (; n >= 64; n -= 64)
				{
					xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
					xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
					xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
					xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
					xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
					xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
					xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
					xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
					xmm_src8 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 8);
					xmm_src9 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 9);
					xmm_srca = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 10);
					xmm_srcb = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 11);
					xmm_srcc = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 12);
					xmm_srcd = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 13);
					xmm_srce = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 14);
					xmm_srcf = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 15);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 64), _MM_HINT_NTA);
					ymm_src0 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src0), xmm_src2, 1);
					ymm_src1 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src1), xmm_src3, 1);
					ymm_src2 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src4), xmm_src6, 1);
					ymm_src3 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src5), xmm_src7, 1);
					ymm_src4 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src8), xmm_srca, 1);
					ymm_src5 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_src9), xmm_srcb, 1);
					ymm_src6 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_srcc), xmm_srce, 1);
					ymm_src7 = _mm256_insertf128_si256(_mm256_castsi128_si256(xmm_srcd), xmm_srcf, 1);
					ymm_dst0 = _mm256_shuffle_epi8(ymm_src0, ymm_mask);
					ymm_dst1 = _mm256_shuffle_epi8(ymm_src1, ymm_mask);
					ymm_dst2 = _mm256_shuffle_epi8(ymm_src2, ymm_mask);
					ymm_dst3 = _mm256_shuffle_epi8(ymm_src3, ymm_mask);
					ymm_dst4 = _mm256_shuffle_epi8(ymm_src4, ymm_mask);
					ymm_dst5 = _mm256_shuffle_epi8(ymm_src5, ymm_mask);
					ymm_dst6 = _mm256_shuffle_epi8(ymm_src6, ymm_mask);
					ymm_dst7 = _mm256_shuffle_epi8(ymm_src7, ymm_mask);
					ymm_dst0 = _mm256_unpacklo_epi64(ymm_dst0, ymm_dst1);
					ymm_dst2 = _mm256_unpacklo_epi64(ymm_dst2, ymm_dst3);
					ymm_dst4 = _mm256_unpacklo_epi64(ymm_dst4, ymm_dst5);
					ymm_dst6 = _mm256_unpacklo_epi64(ymm_dst6, ymm_dst7);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(dst), ymm_dst0);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(dst) + 1, ymm_dst2);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(dst) + 2, ymm_dst4);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(dst) + 3, ymm_dst6);
					src += 64;
					dst += 64;
				}
			}
		}

		template <>
		inline void cvtu32_avx2_large<float>(float* dst, const unsigned int* src, size_t n)
		{
			const size_t padding = 8 - (reinterpret_cast<size_t>(dst) & 7);
			const __m256 ymm_zero = _mm256_setzero_ps();
			const __m256 ymm_max = _mm256_castsi256_ps(_mm256_set1_epi32(0x4f800000));
			__m256i ymm_src0, ymm_src1, ymm_src2, ymm_src3, ymm_src4, ymm_src5, ymm_src6, ymm_src7;
			__m256 ymm_tmp0, ymm_tmp1, ymm_tmp2, ymm_tmp3, ymm_tmp4, ymm_tmp5, ymm_tmp6, ymm_tmp7;
			__m256 ymm_dst0, ymm_dst1, ymm_dst2, ymm_dst3, ymm_dst4, ymm_dst5, ymm_dst6, ymm_dst7;

			// Align the destination to a 32-byte boundary.
			ymm_src0 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(src));
			ymm_dst0 = _mm256_cvtepi32_ps(ymm_src0);
			ymm_tmp0 = _mm256_cmp_ps(ymm_dst0, ymm_zero, _CMP_LT_OS);
			ymm_tmp0 = _mm256_and_ps(ymm_tmp0, ymm_max);
			ymm_dst0 = _mm256_add_ps(ymm_dst0, ymm_tmp0);
			_mm256_storeu_ps(dst, ymm_dst0);
			dst += padding;
			src += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			// If the source is aligned on a 16-byte boundary.
			if ((reinterpret_cast<size_t>(src) & 31) == 0)
			{
				for (; n >= 64; n -= 64)
				{
					ymm_src0 = _mm256_load_si256(reinterpret_cast<const __m256i*>(src));
					ymm_src1 = _mm256_load_si256(reinterpret_cast<const __m256i*>(src) + 1);
					ymm_src2 = _mm256_load_si256(reinterpret_cast<const __m256i*>(src) + 2);
					ymm_src3 = _mm256_load_si256(reinterpret_cast<const __m256i*>(src) + 3);
					ymm_src4 = _mm256_load_si256(reinterpret_cast<const __m256i*>(src) + 4);
					ymm_src5 = _mm256_load_si256(reinterpret_cast<const __m256i*>(src) + 5);
					ymm_src6 = _mm256_load_si256(reinterpret_cast<const __m256i*>(src) + 6);
					ymm_src7 = _mm256_load_si256(reinterpret_cast<const __m256i*>(src) + 7);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 64), _MM_HINT_NTA);
					ymm_dst0 = _mm256_cvtepi32_ps(ymm_src0);
					ymm_dst1 = _mm256_cvtepi32_ps(ymm_src1);
					ymm_dst2 = _mm256_cvtepi32_ps(ymm_src2);
					ymm_dst3 = _mm256_cvtepi32_ps(ymm_src3);
					ymm_dst4 = _mm256_cvtepi32_ps(ymm_src4);
					ymm_dst5 = _mm256_cvtepi32_ps(ymm_src5);
					ymm_dst6 = _mm256_cvtepi32_ps(ymm_src6);
					ymm_dst7 = _mm256_cvtepi32_ps(ymm_src7);
					ymm_tmp0 = _mm256_cmp_ps(ymm_dst0, ymm_zero, _CMP_LT_OS);
					ymm_tmp1 = _mm256_cmp_ps(ymm_dst1, ymm_zero, _CMP_LT_OS);
					ymm_tmp2 = _mm256_cmp_ps(ymm_dst2, ymm_zero, _CMP_LT_OS);
					ymm_tmp3 = _mm256_cmp_ps(ymm_dst3, ymm_zero, _CMP_LT_OS);
					ymm_tmp4 = _mm256_cmp_ps(ymm_dst4, ymm_zero, _CMP_LT_OS);
					ymm_tmp5 = _mm256_cmp_ps(ymm_dst5, ymm_zero, _CMP_LT_OS);
					ymm_tmp6 = _mm256_cmp_ps(ymm_dst6, ymm_zero, _CMP_LT_OS);
					ymm_tmp7 = _mm256_cmp_ps(ymm_dst7, ymm_zero, _CMP_LT_OS);
					ymm_tmp0 = _mm256_and_ps(ymm_tmp0, ymm_max);
					ymm_tmp1 = _mm256_and_ps(ymm_tmp1, ymm_max);
					ymm_tmp2 = _mm256_and_ps(ymm_tmp2, ymm_max);
					ymm_tmp3 = _mm256_and_ps(ymm_tmp3, ymm_max);
					ymm_tmp4 = _mm256_and_ps(ymm_tmp4, ymm_max);
					ymm_tmp5 = _mm256_and_ps(ymm_tmp5, ymm_max);
					ymm_tmp6 = _mm256_and_ps(ymm_tmp6, ymm_max);
					ymm_tmp7 = _mm256_and_ps(ymm_tmp7, ymm_max);
					ymm_dst0 = _mm256_add_ps(ymm_dst0, ymm_tmp0);
					ymm_dst1 = _mm256_add_ps(ymm_dst1, ymm_tmp1);
					ymm_dst2 = _mm256_add_ps(ymm_dst2, ymm_tmp2);
					ymm_dst3 = _mm256_add_ps(ymm_dst3, ymm_tmp3);
					ymm_dst4 = _mm256_add_ps(ymm_dst4, ymm_tmp4);
					ymm_dst5 = _mm256_add_ps(ymm_dst5, ymm_tmp5);
					ymm_dst6 = _mm256_add_ps(ymm_dst6, ymm_tmp6);
					ymm_dst7 = _mm256_add_ps(ymm_dst7, ymm_tmp7);
					_mm256_stream_ps(dst, ymm_dst0);
					_mm256_stream_ps(dst + 8, ymm_dst1);
					_mm256_stream_ps(dst + 16, ymm_dst2);
					_mm256_stream_ps(dst + 24, ymm_dst3);
					_mm256_stream_ps(dst + 32, ymm_dst4);
					_mm256_stream_ps(dst + 40, ymm_dst5);
					_mm256_stream_ps(dst + 48, ymm_dst6);
					_mm256_stream_ps(dst + 56, ymm_dst7);
					src += 64;
					dst += 64;
				}
			}
			else
			{
				for (; n >= 64; n -= 64)
				{
					ymm_src0 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(src));
					ymm_src1 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(src) + 1);
					ymm_src2 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(src) + 2);
					ymm_src3 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(src) + 3);
					ymm_src4 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(src) + 4);
					ymm_src5 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(src) + 5);
					ymm_src6 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(src) + 6);
					ymm_src7 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(src) + 7);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 64), _MM_HINT_NTA);
					ymm_dst0 = _mm256_cvtepi32_ps(ymm_src0);
					ymm_dst1 = _mm256_cvtepi32_ps(ymm_src1);
					ymm_dst2 = _mm256_cvtepi32_ps(ymm_src2);
					ymm_dst3 = _mm256_cvtepi32_ps(ymm_src3);
					ymm_dst4 = _mm256_cvtepi32_ps(ymm_src4);
					ymm_dst5 = _mm256_cvtepi32_ps(ymm_src5);
					ymm_dst6 = _mm256_cvtepi32_ps(ymm_src6);
					ymm_dst7 = _mm256_cvtepi32_ps(ymm_src7);
					ymm_tmp0 = _mm256_cmp_ps(ymm_dst0, ymm_zero, _CMP_LT_OS);
					ymm_tmp1 = _mm256_cmp_ps(ymm_dst1, ymm_zero, _CMP_LT_OS);
					ymm_tmp2 = _mm256_cmp_ps(ymm_dst2, ymm_zero, _CMP_LT_OS);
					ymm_tmp3 = _mm256_cmp_ps(ymm_dst3, ymm_zero, _CMP_LT_OS);
					ymm_tmp4 = _mm256_cmp_ps(ymm_dst4, ymm_zero, _CMP_LT_OS);
					ymm_tmp5 = _mm256_cmp_ps(ymm_dst5, ymm_zero, _CMP_LT_OS);
					ymm_tmp6 = _mm256_cmp_ps(ymm_dst6, ymm_zero, _CMP_LT_OS);
					ymm_tmp7 = _mm256_cmp_ps(ymm_dst7, ymm_zero, _CMP_LT_OS);
					ymm_tmp0 = _mm256_and_ps(ymm_tmp0, ymm_max);
					ymm_tmp1 = _mm256_and_ps(ymm_tmp1, ymm_max);
					ymm_tmp2 = _mm256_and_ps(ymm_tmp2, ymm_max);
					ymm_tmp3 = _mm256_and_ps(ymm_tmp3, ymm_max);
					ymm_tmp4 = _mm256_and_ps(ymm_tmp4, ymm_max);
					ymm_tmp5 = _mm256_and_ps(ymm_tmp5, ymm_max);
					ymm_tmp6 = _mm256_and_ps(ymm_tmp6, ymm_max);
					ymm_tmp7 = _mm256_and_ps(ymm_tmp7, ymm_max);
					ymm_dst0 = _mm256_add_ps(ymm_dst0, ymm_tmp0);
					ymm_dst1 = _mm256_add_ps(ymm_dst1, ymm_tmp1);
					ymm_dst2 = _mm256_add_ps(ymm_dst2, ymm_tmp2);
					ymm_dst3 = _mm256_add_ps(ymm_dst3, ymm_tmp3);
					ymm_dst4 = _mm256_add_ps(ymm_dst4, ymm_tmp4);
					ymm_dst5 = _mm256_add_ps(ymm_dst5, ymm_tmp5);
					ymm_dst6 = _mm256_add_ps(ymm_dst6, ymm_tmp6);
					ymm_dst7 = _mm256_add_ps(ymm_dst7, ymm_tmp7);
					_mm256_stream_ps(dst, ymm_dst0);
					_mm256_stream_ps(dst + 8, ymm_dst1);
					_mm256_stream_ps(dst + 16, ymm_dst2);
					_mm256_stream_ps(dst + 24, ymm_dst3);
					_mm256_stream_ps(dst + 32, ymm_dst4);
					_mm256_stream_ps(dst + 40, ymm_dst5);
					_mm256_stream_ps(dst + 48, ymm_dst6);
					_mm256_stream_ps(dst + 56, ymm_dst7);
					src += 64;
					dst += 64;
				}
			}
		}

		template <>
		inline void cvtu32_avx2_large<double>(double* dst, const unsigned int* src, size_t n)
		{
			const size_t padding = 4 - (reinterpret_cast<size_t>(dst) & 3);
			const __m256d ymm_zero = _mm256_setzero_pd();
			const __m256d ymm_max = _mm256_castsi256_pd(_mm256_set1_epi64x(0x41f0000000000000));
			__m128i xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128i xmm_src8, xmm_src9, xmm_srca, xmm_srcb, xmm_srcc, xmm_srcd, xmm_srce, xmm_srcf;
			__m256d ymm_tmp0, ymm_tmp1, ymm_tmp2, ymm_tmp3, ymm_tmp4, ymm_tmp5, ymm_tmp6, ymm_tmp7;
			__m256d ymm_tmp8, ymm_tmp9, ymm_tmpa, ymm_tmpb, ymm_tmpc, ymm_tmpd, ymm_tmpe, ymm_tmpf;
			__m256d ymm_dst0, ymm_dst1, ymm_dst2, ymm_dst3, ymm_dst4, ymm_dst5, ymm_dst6, ymm_dst7;
			__m256d ymm_dst8, ymm_dst9, ymm_dsta, ymm_dstb, ymm_dstc, ymm_dstd, ymm_dste, ymm_dstf;

			// Align the destination to a 32-byte boundary.
			xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			ymm_dst0 = _mm256_cvtepi32_pd(xmm_src0);
			ymm_tmp0 = _mm256_cmp_pd(ymm_dst0, ymm_zero, _CMP_LT_OS);
			ymm_tmp0 = _mm256_and_pd(ymm_tmp0, ymm_max);
			ymm_dst0 = _mm256_add_pd(ymm_dst0, ymm_tmp0);
			_mm256_storeu_pd(dst, ymm_dst0);
			dst += padding;
			src += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			// If the source is aligned on a 16-byte boundary.
			if ((reinterpret_cast<size_t>(src) & 15) == 0)
			{
				for (; n >= 64; n -= 64)
				{
					xmm_src0 = _mm_load_si128(reinterpret_cast<const __m128i*>(src));
					xmm_src1 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 1);
					xmm_src2 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 2);
					xmm_src3 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 3);
					xmm_src4 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 4);
					xmm_src5 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 5);
					xmm_src6 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 6);
					xmm_src7 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 7);
					xmm_src8 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 8);
					xmm_src9 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 9);
					xmm_srca = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 10);
					xmm_srcb = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 11);
					xmm_srcc = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 12);
					xmm_srcd = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 13);
					xmm_srce = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 14);
					xmm_srcf = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 15);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 64), _MM_HINT_NTA);
					ymm_dst0 = _mm256_cvtepi32_pd(xmm_src0);
					ymm_dst1 = _mm256_cvtepi32_pd(xmm_src1);
					ymm_dst2 = _mm256_cvtepi32_pd(xmm_src2);
					ymm_dst3 = _mm256_cvtepi32_pd(xmm_src3);
					ymm_dst4 = _mm256_cvtepi32_pd(xmm_src4);
					ymm_dst5 = _mm256_cvtepi32_pd(xmm_src5);
					ymm_dst6 = _mm256_cvtepi32_pd(xmm_src6);
					ymm_dst7 = _mm256_cvtepi32_pd(xmm_src7);
					ymm_dst8 = _mm256_cvtepi32_pd(xmm_src8);
					ymm_dst9 = _mm256_cvtepi32_pd(xmm_src9);
					ymm_dsta = _mm256_cvtepi32_pd(xmm_srca);
					ymm_dstb = _mm256_cvtepi32_pd(xmm_srcb);
					ymm_dstc = _mm256_cvtepi32_pd(xmm_srcc);
					ymm_dstd = _mm256_cvtepi32_pd(xmm_srcd);
					ymm_dste = _mm256_cvtepi32_pd(xmm_srce);
					ymm_dstf = _mm256_cvtepi32_pd(xmm_srcf);
					ymm_tmp0 = _mm256_cmp_pd(ymm_dst0, ymm_zero, _CMP_LT_OS);
					ymm_tmp1 = _mm256_cmp_pd(ymm_dst1, ymm_zero, _CMP_LT_OS);
					ymm_tmp2 = _mm256_cmp_pd(ymm_dst2, ymm_zero, _CMP_LT_OS);
					ymm_tmp3 = _mm256_cmp_pd(ymm_dst3, ymm_zero, _CMP_LT_OS);
					ymm_tmp4 = _mm256_cmp_pd(ymm_dst4, ymm_zero, _CMP_LT_OS);
					ymm_tmp5 = _mm256_cmp_pd(ymm_dst5, ymm_zero, _CMP_LT_OS);
					ymm_tmp6 = _mm256_cmp_pd(ymm_dst6, ymm_zero, _CMP_LT_OS);
					ymm_tmp7 = _mm256_cmp_pd(ymm_dst7, ymm_zero, _CMP_LT_OS);
					ymm_tmp8 = _mm256_cmp_pd(ymm_dst8, ymm_zero, _CMP_LT_OS);
					ymm_tmp9 = _mm256_cmp_pd(ymm_dst9, ymm_zero, _CMP_LT_OS);
					ymm_tmpa = _mm256_cmp_pd(ymm_dsta, ymm_zero, _CMP_LT_OS);
					ymm_tmpb = _mm256_cmp_pd(ymm_dstb, ymm_zero, _CMP_LT_OS);
					ymm_tmpc = _mm256_cmp_pd(ymm_dstc, ymm_zero, _CMP_LT_OS);
					ymm_tmpd = _mm256_cmp_pd(ymm_dstd, ymm_zero, _CMP_LT_OS);
					ymm_tmpe = _mm256_cmp_pd(ymm_dste, ymm_zero, _CMP_LT_OS);
					ymm_tmpf = _mm256_cmp_pd(ymm_dstf, ymm_zero, _CMP_LT_OS);
					ymm_tmp0 = _mm256_and_pd(ymm_tmp0, ymm_max);
					ymm_tmp1 = _mm256_and_pd(ymm_tmp1, ymm_max);
					ymm_tmp2 = _mm256_and_pd(ymm_tmp2, ymm_max);
					ymm_tmp3 = _mm256_and_pd(ymm_tmp3, ymm_max);
					ymm_tmp4 = _mm256_and_pd(ymm_tmp4, ymm_max);
					ymm_tmp5 = _mm256_and_pd(ymm_tmp5, ymm_max);
					ymm_tmp6 = _mm256_and_pd(ymm_tmp6, ymm_max);
					ymm_tmp7 = _mm256_and_pd(ymm_tmp7, ymm_max);
					ymm_tmp8 = _mm256_and_pd(ymm_tmp8, ymm_max);
					ymm_tmp9 = _mm256_and_pd(ymm_tmp9, ymm_max);
					ymm_tmpa = _mm256_and_pd(ymm_tmpa, ymm_max);
					ymm_tmpb = _mm256_and_pd(ymm_tmpb, ymm_max);
					ymm_tmpc = _mm256_and_pd(ymm_tmpc, ymm_max);
					ymm_tmpd = _mm256_and_pd(ymm_tmpd, ymm_max);
					ymm_tmpe = _mm256_and_pd(ymm_tmpe, ymm_max);
					ymm_tmpf = _mm256_and_pd(ymm_tmpf, ymm_max);
					ymm_dst0 = _mm256_add_pd(ymm_dst0, ymm_tmp0);
					ymm_dst1 = _mm256_add_pd(ymm_dst1, ymm_tmp1);
					ymm_dst2 = _mm256_add_pd(ymm_dst2, ymm_tmp2);
					ymm_dst3 = _mm256_add_pd(ymm_dst3, ymm_tmp3);
					ymm_dst4 = _mm256_add_pd(ymm_dst4, ymm_tmp4);
					ymm_dst5 = _mm256_add_pd(ymm_dst5, ymm_tmp5);
					ymm_dst6 = _mm256_add_pd(ymm_dst6, ymm_tmp6);
					ymm_dst7 = _mm256_add_pd(ymm_dst7, ymm_tmp7);
					ymm_dst8 = _mm256_add_pd(ymm_dst8, ymm_tmp8);
					ymm_dst9 = _mm256_add_pd(ymm_dst9, ymm_tmp9);
					ymm_dsta = _mm256_add_pd(ymm_dsta, ymm_tmpa);
					ymm_dstb = _mm256_add_pd(ymm_dstb, ymm_tmpb);
					ymm_dstc = _mm256_add_pd(ymm_dstc, ymm_tmpc);
					ymm_dstd = _mm256_add_pd(ymm_dstd, ymm_tmpd);
					ymm_dste = _mm256_add_pd(ymm_dste, ymm_tmpe);
					ymm_dstf = _mm256_add_pd(ymm_dstf, ymm_tmpf);
					_mm256_stream_pd(dst, ymm_dst0);
					_mm256_stream_pd(dst + 4, ymm_dst1);
					_mm256_stream_pd(dst + 8, ymm_dst2);
					_mm256_stream_pd(dst + 12, ymm_dst3);
					_mm256_stream_pd(dst + 16, ymm_dst4);
					_mm256_stream_pd(dst + 20, ymm_dst5);
					_mm256_stream_pd(dst + 24, ymm_dst6);
					_mm256_stream_pd(dst + 28, ymm_dst7);
					_mm256_stream_pd(dst + 32, ymm_dst8);
					_mm256_stream_pd(dst + 36, ymm_dst9);
					_mm256_stream_pd(dst + 40, ymm_dsta);
					_mm256_stream_pd(dst + 44, ymm_dstb);
					_mm256_stream_pd(dst + 48, ymm_dstc);
					_mm256_stream_pd(dst + 52, ymm_dstd);
					_mm256_stream_pd(dst + 56, ymm_dste);
					_mm256_stream_pd(dst + 60, ymm_dstf);
					src += 64;
					dst += 64;
				}
			}
			else
			{
				for (; n >= 64; n -= 64)
				{
					xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
					xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
					xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
					xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
					xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
					xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
					xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
					xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
					xmm_src8 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 8);
					xmm_src9 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 9);
					xmm_srca = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 10);
					xmm_srcb = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 11);
					xmm_srcc = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 12);
					xmm_srcd = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 13);
					xmm_srce = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 14);
					xmm_srcf = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 15);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 64), _MM_HINT_NTA);
					ymm_dst0 = _mm256_cvtepi32_pd(xmm_src0);
					ymm_dst1 = _mm256_cvtepi32_pd(xmm_src1);
					ymm_dst2 = _mm256_cvtepi32_pd(xmm_src2);
					ymm_dst3 = _mm256_cvtepi32_pd(xmm_src3);
					ymm_dst4 = _mm256_cvtepi32_pd(xmm_src4);
					ymm_dst5 = _mm256_cvtepi32_pd(xmm_src5);
					ymm_dst6 = _mm256_cvtepi32_pd(xmm_src6);
					ymm_dst7 = _mm256_cvtepi32_pd(xmm_src7);
					ymm_dst8 = _mm256_cvtepi32_pd(xmm_src8);
					ymm_dst9 = _mm256_cvtepi32_pd(xmm_src9);
					ymm_dsta = _mm256_cvtepi32_pd(xmm_srca);
					ymm_dstb = _mm256_cvtepi32_pd(xmm_srcb);
					ymm_dstc = _mm256_cvtepi32_pd(xmm_srcc);
					ymm_dstd = _mm256_cvtepi32_pd(xmm_srcd);
					ymm_dste = _mm256_cvtepi32_pd(xmm_srce);
					ymm_dstf = _mm256_cvtepi32_pd(xmm_srcf);
					ymm_tmp0 = _mm256_cmp_pd(ymm_dst0, ymm_zero, _CMP_LT_OS);
					ymm_tmp1 = _mm256_cmp_pd(ymm_dst1, ymm_zero, _CMP_LT_OS);
					ymm_tmp2 = _mm256_cmp_pd(ymm_dst2, ymm_zero, _CMP_LT_OS);
					ymm_tmp3 = _mm256_cmp_pd(ymm_dst3, ymm_zero, _CMP_LT_OS);
					ymm_tmp4 = _mm256_cmp_pd(ymm_dst4, ymm_zero, _CMP_LT_OS);
					ymm_tmp5 = _mm256_cmp_pd(ymm_dst5, ymm_zero, _CMP_LT_OS);
					ymm_tmp6 = _mm256_cmp_pd(ymm_dst6, ymm_zero, _CMP_LT_OS);
					ymm_tmp7 = _mm256_cmp_pd(ymm_dst7, ymm_zero, _CMP_LT_OS);
					ymm_tmp8 = _mm256_cmp_pd(ymm_dst8, ymm_zero, _CMP_LT_OS);
					ymm_tmp9 = _mm256_cmp_pd(ymm_dst9, ymm_zero, _CMP_LT_OS);
					ymm_tmpa = _mm256_cmp_pd(ymm_dsta, ymm_zero, _CMP_LT_OS);
					ymm_tmpb = _mm256_cmp_pd(ymm_dstb, ymm_zero, _CMP_LT_OS);
					ymm_tmpc = _mm256_cmp_pd(ymm_dstc, ymm_zero, _CMP_LT_OS);
					ymm_tmpd = _mm256_cmp_pd(ymm_dstd, ymm_zero, _CMP_LT_OS);
					ymm_tmpe = _mm256_cmp_pd(ymm_dste, ymm_zero, _CMP_LT_OS);
					ymm_tmpf = _mm256_cmp_pd(ymm_dstf, ymm_zero, _CMP_LT_OS);
					ymm_tmp0 = _mm256_and_pd(ymm_tmp0, ymm_max);
					ymm_tmp1 = _mm256_and_pd(ymm_tmp1, ymm_max);
					ymm_tmp2 = _mm256_and_pd(ymm_tmp2, ymm_max);
					ymm_tmp3 = _mm256_and_pd(ymm_tmp3, ymm_max);
					ymm_tmp4 = _mm256_and_pd(ymm_tmp4, ymm_max);
					ymm_tmp5 = _mm256_and_pd(ymm_tmp5, ymm_max);
					ymm_tmp6 = _mm256_and_pd(ymm_tmp6, ymm_max);
					ymm_tmp7 = _mm256_and_pd(ymm_tmp7, ymm_max);
					ymm_tmp8 = _mm256_and_pd(ymm_tmp8, ymm_max);
					ymm_tmp9 = _mm256_and_pd(ymm_tmp9, ymm_max);
					ymm_tmpa = _mm256_and_pd(ymm_tmpa, ymm_max);
					ymm_tmpb = _mm256_and_pd(ymm_tmpb, ymm_max);
					ymm_tmpc = _mm256_and_pd(ymm_tmpc, ymm_max);
					ymm_tmpd = _mm256_and_pd(ymm_tmpd, ymm_max);
					ymm_tmpe = _mm256_and_pd(ymm_tmpe, ymm_max);
					ymm_tmpf = _mm256_and_pd(ymm_tmpf, ymm_max);
					ymm_dst0 = _mm256_add_pd(ymm_dst0, ymm_tmp0);
					ymm_dst1 = _mm256_add_pd(ymm_dst1, ymm_tmp1);
					ymm_dst2 = _mm256_add_pd(ymm_dst2, ymm_tmp2);
					ymm_dst3 = _mm256_add_pd(ymm_dst3, ymm_tmp3);
					ymm_dst4 = _mm256_add_pd(ymm_dst4, ymm_tmp4);
					ymm_dst5 = _mm256_add_pd(ymm_dst5, ymm_tmp5);
					ymm_dst6 = _mm256_add_pd(ymm_dst6, ymm_tmp6);
					ymm_dst7 = _mm256_add_pd(ymm_dst7, ymm_tmp7);
					ymm_dst8 = _mm256_add_pd(ymm_dst8, ymm_tmp8);
					ymm_dst9 = _mm256_add_pd(ymm_dst9, ymm_tmp9);
					ymm_dsta = _mm256_add_pd(ymm_dsta, ymm_tmpa);
					ymm_dstb = _mm256_add_pd(ymm_dstb, ymm_tmpb);
					ymm_dstc = _mm256_add_pd(ymm_dstc, ymm_tmpc);
					ymm_dstd = _mm256_add_pd(ymm_dstd, ymm_tmpd);
					ymm_dste = _mm256_add_pd(ymm_dste, ymm_tmpe);
					ymm_dstf = _mm256_add_pd(ymm_dstf, ymm_tmpf);
					_mm256_stream_pd(dst, ymm_dst0);
					_mm256_stream_pd(dst + 4, ymm_dst1);
					_mm256_stream_pd(dst + 8, ymm_dst2);
					_mm256_stream_pd(dst + 12, ymm_dst3);
					_mm256_stream_pd(dst + 16, ymm_dst4);
					_mm256_stream_pd(dst + 20, ymm_dst5);
					_mm256_stream_pd(dst + 24, ymm_dst6);
					_mm256_stream_pd(dst + 28, ymm_dst7);
					_mm256_stream_pd(dst + 32, ymm_dst8);
					_mm256_stream_pd(dst + 36, ymm_dst9);
					_mm256_stream_pd(dst + 40, ymm_dsta);
					_mm256_stream_pd(dst + 44, ymm_dstb);
					_mm256_stream_pd(dst + 48, ymm_dstc);
					_mm256_stream_pd(dst + 52, ymm_dstd);
					_mm256_stream_pd(dst + 56, ymm_dste);
					_mm256_stream_pd(dst + 60, ymm_dstf);
					src += 64;
					dst += 64;
				}
			}
		}

		// Function template impl_cvtu32

		template <class T>
		inline void impl_cvtu32(T* dst, const unsigned int* src, size_t n)
		{
			constexpr size_t threshold = simd::l2_cache_size / sizeof(unsigned int);
			// Small amount of data type conversion.
			if (n < 128)
				cvtu32_avx2_small(dst, src, n);
			// Medium amount data type conversion.
			else if (n < threshold)
				cvtu32_avx2_medium(dst, src, n);
			// Large amount data type conversion.
			else
				cvtu32_avx2_large(dst, src, n);
			// Small amount of data type conversion.
			cvtu32_avx2_small(dst, src, n & 127);
			// Zero the upper 128 bits of all YMM registers.
			_mm256_zeroupper();
		}

	#elif defined(__AVX__) || defined(__SSE4_2__) || defined(__SSE4_1__)

		// Function template cvtu32_sse41_8

		template <class T>
		inline void cvtu32_sse41_8(T* dst, const unsigned int* src)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		inline void cvtu32_sse41_8<signed char>(signed char* dst, const unsigned int* src)
		{
			const __m128i xmm_mask = _mm_set_epi64x(0xffffffffffffffffi64, 0xffffffff0c080400i64);
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m128i xmm_dst0 = _mm_shuffle_epi8(xmm_src0, xmm_mask);
			__m128i xmm_dst1 = _mm_shuffle_epi8(xmm_src1, xmm_mask);
			xmm_dst0 = _mm_unpacklo_epi32(xmm_dst0, xmm_dst1);
			_mm_storeu_si64(reinterpret_cast<__m128i*>(dst), xmm_dst0);
		}

		template <>
		inline void cvtu32_sse41_8<unsigned char>(unsigned char* dst, const unsigned int* src)
		{
			const __m128i xmm_mask = _mm_set_epi64x(0xffffffffffffffffi64, 0xffffffff0c080400i64);
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m128i xmm_dst0 = _mm_shuffle_epi8(xmm_src0, xmm_mask);
			__m128i xmm_dst1 = _mm_shuffle_epi8(xmm_src1, xmm_mask);
			xmm_dst0 = _mm_unpacklo_epi32(xmm_dst0, xmm_dst1);
			_mm_storeu_si64(reinterpret_cast<__m128i*>(dst), xmm_dst0);
		}

		template <>
		inline void cvtu32_sse41_8<signed short>(signed short* dst, const unsigned int* src)
		{
			const __m128i xmm_mask = _mm_set_epi64x(0xffffffffffffffffi64, 0x0d0c090805040100i64);
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m128i xmm_dst0 = _mm_shuffle_epi8(xmm_src0, xmm_mask);
			__m128i xmm_dst1 = _mm_shuffle_epi8(xmm_src1, xmm_mask);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
		}

		template <>
		inline void cvtu32_sse41_8<unsigned short>(unsigned short* dst, const unsigned int* src)
		{
			const __m128i xmm_mask = _mm_set_epi64x(0xffffffffffffffffi64, 0x0d0c090805040100i64);
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m128i xmm_dst0 = _mm_shuffle_epi8(xmm_src0, xmm_mask);
			__m128i xmm_dst1 = _mm_shuffle_epi8(xmm_src1, xmm_mask);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
		}

		template <>
		inline void cvtu32_sse41_8<float>(float* dst, const unsigned int* src)
		{
			const __m128 xmm_zero = _mm_setzero_ps();
			const __m128 xmm_max = _mm_castsi128_ps(_mm_set1_epi32(0x4f800000));
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m128 xmm_dst0 = _mm_cvtepi32_ps(xmm_src0);
			__m128 xmm_dst1 = _mm_cvtepi32_ps(xmm_src1);
			__m128 xmm_tmp0 = _mm_cmplt_ps(xmm_dst0, xmm_zero);
			__m128 xmm_tmp1 = _mm_cmplt_ps(xmm_dst1, xmm_zero);
			xmm_tmp0 = _mm_and_ps(xmm_tmp0, xmm_max);
			xmm_tmp1 = _mm_and_ps(xmm_tmp1, xmm_max);
			xmm_dst0 = _mm_add_ps(xmm_dst0, xmm_tmp0);
			xmm_dst1 = _mm_add_ps(xmm_dst1, xmm_tmp1);
			_mm_storeu_ps(dst, xmm_dst0);
			_mm_storeu_ps(dst + 4, xmm_dst1);
		}

		template <>
		inline void cvtu32_sse41_8<double>(double* dst, const unsigned int* src)
		{
			const __m128d xmm_zero = _mm_setzero_pd();
			const __m128d xmm_max = _mm_castsi128_pd(_mm_set1_epi64x(0x41f0000000000000));
			__m128i xmm_src0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 2));
			__m128i xmm_src2 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 4));
			__m128i xmm_src3 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 6));
			__m128d xmm_dst0 = _mm_cvtepi32_pd(xmm_src0);
			__m128d xmm_dst1 = _mm_cvtepi32_pd(xmm_src1);
			__m128d xmm_dst2 = _mm_cvtepi32_pd(xmm_src2);
			__m128d xmm_dst3 = _mm_cvtepi32_pd(xmm_src3);
			__m128d xmm_tmp0 = _mm_cmplt_pd(xmm_dst0, xmm_zero);
			__m128d xmm_tmp1 = _mm_cmplt_pd(xmm_dst1, xmm_zero);
			__m128d xmm_tmp2 = _mm_cmplt_pd(xmm_dst2, xmm_zero);
			__m128d xmm_tmp3 = _mm_cmplt_pd(xmm_dst3, xmm_zero);
			xmm_tmp0 = _mm_and_pd(xmm_tmp0, xmm_max);
			xmm_tmp1 = _mm_and_pd(xmm_tmp1, xmm_max);
			xmm_tmp2 = _mm_and_pd(xmm_tmp2, xmm_max);
			xmm_tmp3 = _mm_and_pd(xmm_tmp3, xmm_max);
			xmm_dst0 = _mm_add_pd(xmm_dst0, xmm_tmp0);
			xmm_dst1 = _mm_add_pd(xmm_dst1, xmm_tmp1);
			xmm_dst2 = _mm_add_pd(xmm_dst2, xmm_tmp2);
			xmm_dst3 = _mm_add_pd(xmm_dst3, xmm_tmp3);
			_mm_storeu_pd(dst, xmm_dst0);
			_mm_storeu_pd(dst + 2, xmm_dst1);
			_mm_storeu_pd(dst + 4, xmm_dst2);
			_mm_storeu_pd(dst + 6, xmm_dst3);
		}

		// Function template cvtu32_sse41_16

		template <class T>
		inline void cvtu32_sse41_16(T* dst, const unsigned int* src)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		inline void cvtu32_sse41_16<signed char>(signed char* dst, const unsigned int* src)
		{
			const __m128i xmm_mask = _mm_set_epi64x(0xffffffffffffffffi64, 0xffffffff0c080400i64);
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m128i xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
			__m128i xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
			__m128i xmm_dst0 = _mm_shuffle_epi8(xmm_src0, xmm_mask);
			__m128i xmm_dst1 = _mm_shuffle_epi8(xmm_src1, xmm_mask);
			__m128i xmm_dst2 = _mm_shuffle_epi8(xmm_src2, xmm_mask);
			__m128i xmm_dst3 = _mm_shuffle_epi8(xmm_src3, xmm_mask);
			xmm_dst0 = _mm_unpacklo_epi32(xmm_dst0, xmm_dst1);
			xmm_dst2 = _mm_unpacklo_epi32(xmm_dst2, xmm_dst3);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
		}

		template <>
		inline void cvtu32_sse41_16<unsigned char>(unsigned char* dst, const unsigned int* src)
		{
			const __m128i xmm_mask = _mm_set_epi64x(0xffffffffffffffffi64, 0xffffffff0c080400i64);
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m128i xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
			__m128i xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
			__m128i xmm_dst0 = _mm_shuffle_epi8(xmm_src0, xmm_mask);
			__m128i xmm_dst1 = _mm_shuffle_epi8(xmm_src1, xmm_mask);
			__m128i xmm_dst2 = _mm_shuffle_epi8(xmm_src2, xmm_mask);
			__m128i xmm_dst3 = _mm_shuffle_epi8(xmm_src3, xmm_mask);
			xmm_dst0 = _mm_unpacklo_epi32(xmm_dst0, xmm_dst1);
			xmm_dst2 = _mm_unpacklo_epi32(xmm_dst2, xmm_dst3);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
		}

		template <>
		inline void cvtu32_sse41_16<signed short>(signed short* dst, const unsigned int* src)
		{
			const __m128i xmm_mask = _mm_set_epi64x(0xffffffffffffffffi64, 0x0d0c090805040100i64);
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m128i xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
			__m128i xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
			__m128i xmm_dst0 = _mm_shuffle_epi8(xmm_src0, xmm_mask);
			__m128i xmm_dst1 = _mm_shuffle_epi8(xmm_src1, xmm_mask);
			__m128i xmm_dst2 = _mm_shuffle_epi8(xmm_src2, xmm_mask);
			__m128i xmm_dst3 = _mm_shuffle_epi8(xmm_src3, xmm_mask);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
			xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst2);
		}

		template <>
		inline void cvtu32_sse41_16<unsigned short>(unsigned short* dst, const unsigned int* src)
		{
			const __m128i xmm_mask = _mm_set_epi64x(0xffffffffffffffffi64, 0x0d0c090805040100i64);
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m128i xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
			__m128i xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
			__m128i xmm_dst0 = _mm_shuffle_epi8(xmm_src0, xmm_mask);
			__m128i xmm_dst1 = _mm_shuffle_epi8(xmm_src1, xmm_mask);
			__m128i xmm_dst2 = _mm_shuffle_epi8(xmm_src2, xmm_mask);
			__m128i xmm_dst3 = _mm_shuffle_epi8(xmm_src3, xmm_mask);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
			xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst2);
		}

		template <>
		inline void cvtu32_sse41_16<float>(float* dst, const unsigned int* src)
		{
			const __m128 xmm_zero = _mm_setzero_ps();
			const __m128 xmm_max = _mm_castsi128_ps(_mm_set1_epi32(0x4f800000));
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m128i xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
			__m128i xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
			__m128 xmm_dst0 = _mm_cvtepi32_ps(xmm_src0);
			__m128 xmm_dst1 = _mm_cvtepi32_ps(xmm_src1);
			__m128 xmm_dst2 = _mm_cvtepi32_ps(xmm_src2);
			__m128 xmm_dst3 = _mm_cvtepi32_ps(xmm_src3);
			__m128 xmm_tmp0 = _mm_cmplt_ps(xmm_dst0, xmm_zero);
			__m128 xmm_tmp1 = _mm_cmplt_ps(xmm_dst1, xmm_zero);
			__m128 xmm_tmp2 = _mm_cmplt_ps(xmm_dst2, xmm_zero);
			__m128 xmm_tmp3 = _mm_cmplt_ps(xmm_dst3, xmm_zero);
			xmm_tmp0 = _mm_and_ps(xmm_tmp0, xmm_max);
			xmm_tmp1 = _mm_and_ps(xmm_tmp1, xmm_max);
			xmm_tmp2 = _mm_and_ps(xmm_tmp2, xmm_max);
			xmm_tmp3 = _mm_and_ps(xmm_tmp3, xmm_max);
			xmm_dst0 = _mm_add_ps(xmm_dst0, xmm_tmp0);
			xmm_dst1 = _mm_add_ps(xmm_dst1, xmm_tmp1);
			xmm_dst2 = _mm_add_ps(xmm_dst2, xmm_tmp2);
			xmm_dst3 = _mm_add_ps(xmm_dst3, xmm_tmp3);
			_mm_storeu_ps(dst, xmm_dst0);
			_mm_storeu_ps(dst + 4, xmm_dst1);
			_mm_storeu_ps(dst + 8, xmm_dst2);
			_mm_storeu_ps(dst + 12, xmm_dst3);
		}

		template <>
		inline void cvtu32_sse41_16<double>(double* dst, const unsigned int* src)
		{
			const __m128d xmm_zero = _mm_setzero_pd();
			const __m128d xmm_max = _mm_castsi128_pd(_mm_set1_epi64x(0x41f0000000000000));
			__m128i xmm_src0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 2));
			__m128i xmm_src2 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 4));
			__m128i xmm_src3 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 6));
			__m128i xmm_src4 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 8));
			__m128i xmm_src5 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 10));
			__m128i xmm_src6 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 12));
			__m128i xmm_src7 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 14));
			__m128d xmm_dst0 = _mm_cvtepi32_pd(xmm_src0);
			__m128d xmm_dst1 = _mm_cvtepi32_pd(xmm_src1);
			__m128d xmm_dst2 = _mm_cvtepi32_pd(xmm_src2);
			__m128d xmm_dst3 = _mm_cvtepi32_pd(xmm_src3);
			__m128d xmm_dst4 = _mm_cvtepi32_pd(xmm_src4);
			__m128d xmm_dst5 = _mm_cvtepi32_pd(xmm_src5);
			__m128d xmm_dst6 = _mm_cvtepi32_pd(xmm_src6);
			__m128d xmm_dst7 = _mm_cvtepi32_pd(xmm_src7);
			__m128d xmm_tmp0 = _mm_cmplt_pd(xmm_dst0, xmm_zero);
			__m128d xmm_tmp1 = _mm_cmplt_pd(xmm_dst1, xmm_zero);
			__m128d xmm_tmp2 = _mm_cmplt_pd(xmm_dst2, xmm_zero);
			__m128d xmm_tmp3 = _mm_cmplt_pd(xmm_dst3, xmm_zero);
			__m128d xmm_tmp4 = _mm_cmplt_pd(xmm_dst4, xmm_zero);
			__m128d xmm_tmp5 = _mm_cmplt_pd(xmm_dst5, xmm_zero);
			__m128d xmm_tmp6 = _mm_cmplt_pd(xmm_dst6, xmm_zero);
			__m128d xmm_tmp7 = _mm_cmplt_pd(xmm_dst7, xmm_zero);
			xmm_tmp0 = _mm_and_pd(xmm_tmp0, xmm_max);
			xmm_tmp1 = _mm_and_pd(xmm_tmp1, xmm_max);
			xmm_tmp2 = _mm_and_pd(xmm_tmp2, xmm_max);
			xmm_tmp3 = _mm_and_pd(xmm_tmp3, xmm_max);
			xmm_tmp4 = _mm_and_pd(xmm_tmp4, xmm_max);
			xmm_tmp5 = _mm_and_pd(xmm_tmp5, xmm_max);
			xmm_tmp6 = _mm_and_pd(xmm_tmp6, xmm_max);
			xmm_tmp7 = _mm_and_pd(xmm_tmp7, xmm_max);
			xmm_dst0 = _mm_add_pd(xmm_dst0, xmm_tmp0);
			xmm_dst1 = _mm_add_pd(xmm_dst1, xmm_tmp1);
			xmm_dst2 = _mm_add_pd(xmm_dst2, xmm_tmp2);
			xmm_dst3 = _mm_add_pd(xmm_dst3, xmm_tmp3);
			xmm_dst4 = _mm_add_pd(xmm_dst4, xmm_tmp4);
			xmm_dst5 = _mm_add_pd(xmm_dst5, xmm_tmp5);
			xmm_dst6 = _mm_add_pd(xmm_dst6, xmm_tmp6);
			xmm_dst7 = _mm_add_pd(xmm_dst7, xmm_tmp7);
			_mm_storeu_pd(dst, xmm_dst0);
			_mm_storeu_pd(dst + 2, xmm_dst1);
			_mm_storeu_pd(dst + 4, xmm_dst2);
			_mm_storeu_pd(dst + 6, xmm_dst3);
			_mm_storeu_pd(dst + 8, xmm_dst4);
			_mm_storeu_pd(dst + 10, xmm_dst5);
			_mm_storeu_pd(dst + 12, xmm_dst6);
			_mm_storeu_pd(dst + 14, xmm_dst7);
		}

		// Function template cvtu32_sse41_32

		template <class T>
		inline void cvtu32_sse41_32(T* dst, const unsigned int* src)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		inline void cvtu32_sse41_32<signed char>(signed char* dst, const unsigned int* src)
		{
			const __m128i xmm_mask = _mm_set_epi64x(0xffffffffffffffffi64, 0xffffffff0c080400i64);
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m128i xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
			__m128i xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
			__m128i xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
			__m128i xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
			__m128i xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
			__m128i xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
			__m128i xmm_dst0 = _mm_shuffle_epi8(xmm_src0, xmm_mask);
			__m128i xmm_dst1 = _mm_shuffle_epi8(xmm_src1, xmm_mask);
			__m128i xmm_dst2 = _mm_shuffle_epi8(xmm_src2, xmm_mask);
			__m128i xmm_dst3 = _mm_shuffle_epi8(xmm_src3, xmm_mask);
			__m128i xmm_dst4 = _mm_shuffle_epi8(xmm_src4, xmm_mask);
			__m128i xmm_dst5 = _mm_shuffle_epi8(xmm_src5, xmm_mask);
			__m128i xmm_dst6 = _mm_shuffle_epi8(xmm_src6, xmm_mask);
			__m128i xmm_dst7 = _mm_shuffle_epi8(xmm_src7, xmm_mask);
			xmm_dst0 = _mm_unpacklo_epi32(xmm_dst0, xmm_dst1);
			xmm_dst2 = _mm_unpacklo_epi32(xmm_dst2, xmm_dst3);
			xmm_dst4 = _mm_unpacklo_epi32(xmm_dst4, xmm_dst5);
			xmm_dst6 = _mm_unpacklo_epi32(xmm_dst6, xmm_dst7);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst2);
			xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst6);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst4);
		}

		template <>
		inline void cvtu32_sse41_32<unsigned char>(unsigned char* dst, const unsigned int* src)
		{
			const __m128i xmm_mask = _mm_set_epi64x(0xffffffffffffffffi64, 0xffffffff0c080400i64);
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m128i xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
			__m128i xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
			__m128i xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
			__m128i xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
			__m128i xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
			__m128i xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
			__m128i xmm_dst0 = _mm_shuffle_epi8(xmm_src0, xmm_mask);
			__m128i xmm_dst1 = _mm_shuffle_epi8(xmm_src1, xmm_mask);
			__m128i xmm_dst2 = _mm_shuffle_epi8(xmm_src2, xmm_mask);
			__m128i xmm_dst3 = _mm_shuffle_epi8(xmm_src3, xmm_mask);
			__m128i xmm_dst4 = _mm_shuffle_epi8(xmm_src4, xmm_mask);
			__m128i xmm_dst5 = _mm_shuffle_epi8(xmm_src5, xmm_mask);
			__m128i xmm_dst6 = _mm_shuffle_epi8(xmm_src6, xmm_mask);
			__m128i xmm_dst7 = _mm_shuffle_epi8(xmm_src7, xmm_mask);
			xmm_dst0 = _mm_unpacklo_epi32(xmm_dst0, xmm_dst1);
			xmm_dst2 = _mm_unpacklo_epi32(xmm_dst2, xmm_dst3);
			xmm_dst4 = _mm_unpacklo_epi32(xmm_dst4, xmm_dst5);
			xmm_dst6 = _mm_unpacklo_epi32(xmm_dst6, xmm_dst7);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst2);
			xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst6);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst4);
		}

		template <>
		inline void cvtu32_sse41_32<signed short>(signed short* dst, const unsigned int* src)
		{
			const __m128i xmm_mask = _mm_set_epi64x(0xffffffffffffffffi64, 0x0d0c090805040100i64);
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m128i xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
			__m128i xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
			__m128i xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
			__m128i xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
			__m128i xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
			__m128i xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
			__m128i xmm_dst0 = _mm_shuffle_epi8(xmm_src0, xmm_mask);
			__m128i xmm_dst1 = _mm_shuffle_epi8(xmm_src1, xmm_mask);
			__m128i xmm_dst2 = _mm_shuffle_epi8(xmm_src2, xmm_mask);
			__m128i xmm_dst3 = _mm_shuffle_epi8(xmm_src3, xmm_mask);
			__m128i xmm_dst4 = _mm_shuffle_epi8(xmm_src4, xmm_mask);
			__m128i xmm_dst5 = _mm_shuffle_epi8(xmm_src5, xmm_mask);
			__m128i xmm_dst6 = _mm_shuffle_epi8(xmm_src6, xmm_mask);
			__m128i xmm_dst7 = _mm_shuffle_epi8(xmm_src7, xmm_mask);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
			xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
			xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
			xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 2, xmm_dst4);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 3, xmm_dst6);
		}

		template <>
		inline void cvtu32_sse41_32<unsigned short>(unsigned short* dst, const unsigned int* src)
		{
			const __m128i xmm_mask = _mm_set_epi64x(0xffffffffffffffffi64, 0x0d0c090805040100i64);
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m128i xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
			__m128i xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
			__m128i xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
			__m128i xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
			__m128i xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
			__m128i xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
			__m128i xmm_dst0 = _mm_shuffle_epi8(xmm_src0, xmm_mask);
			__m128i xmm_dst1 = _mm_shuffle_epi8(xmm_src1, xmm_mask);
			__m128i xmm_dst2 = _mm_shuffle_epi8(xmm_src2, xmm_mask);
			__m128i xmm_dst3 = _mm_shuffle_epi8(xmm_src3, xmm_mask);
			__m128i xmm_dst4 = _mm_shuffle_epi8(xmm_src4, xmm_mask);
			__m128i xmm_dst5 = _mm_shuffle_epi8(xmm_src5, xmm_mask);
			__m128i xmm_dst6 = _mm_shuffle_epi8(xmm_src6, xmm_mask);
			__m128i xmm_dst7 = _mm_shuffle_epi8(xmm_src7, xmm_mask);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
			xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
			xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
			xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 2, xmm_dst4);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 3, xmm_dst6);
		}

		template <>
		inline void cvtu32_sse41_32<float>(float* dst, const unsigned int* src)
		{
			const __m128 xmm_zero = _mm_setzero_ps();
			const __m128 xmm_max = _mm_castsi128_ps(_mm_set1_epi32(0x4f800000));
			__m128i xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			__m128i xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
			__m128i xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
			__m128i xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
			__m128i xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
			__m128i xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
			__m128i xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
			__m128 xmm_dst0 = _mm_cvtepi32_ps(xmm_src0);
			__m128 xmm_dst1 = _mm_cvtepi32_ps(xmm_src1);
			__m128 xmm_dst2 = _mm_cvtepi32_ps(xmm_src2);
			__m128 xmm_dst3 = _mm_cvtepi32_ps(xmm_src3);
			__m128 xmm_dst4 = _mm_cvtepi32_ps(xmm_src4);
			__m128 xmm_dst5 = _mm_cvtepi32_ps(xmm_src5);
			__m128 xmm_dst6 = _mm_cvtepi32_ps(xmm_src6);
			__m128 xmm_dst7 = _mm_cvtepi32_ps(xmm_src7);
			__m128 xmm_tmp0 = _mm_cmplt_ps(xmm_dst0, xmm_zero);
			__m128 xmm_tmp1 = _mm_cmplt_ps(xmm_dst1, xmm_zero);
			__m128 xmm_tmp2 = _mm_cmplt_ps(xmm_dst2, xmm_zero);
			__m128 xmm_tmp3 = _mm_cmplt_ps(xmm_dst3, xmm_zero);
			__m128 xmm_tmp4 = _mm_cmplt_ps(xmm_dst4, xmm_zero);
			__m128 xmm_tmp5 = _mm_cmplt_ps(xmm_dst5, xmm_zero);
			__m128 xmm_tmp6 = _mm_cmplt_ps(xmm_dst6, xmm_zero);
			__m128 xmm_tmp7 = _mm_cmplt_ps(xmm_dst7, xmm_zero);
			xmm_tmp0 = _mm_and_ps(xmm_tmp0, xmm_max);
			xmm_tmp1 = _mm_and_ps(xmm_tmp1, xmm_max);
			xmm_tmp2 = _mm_and_ps(xmm_tmp2, xmm_max);
			xmm_tmp3 = _mm_and_ps(xmm_tmp3, xmm_max);
			xmm_tmp4 = _mm_and_ps(xmm_tmp4, xmm_max);
			xmm_tmp5 = _mm_and_ps(xmm_tmp5, xmm_max);
			xmm_tmp6 = _mm_and_ps(xmm_tmp6, xmm_max);
			xmm_tmp7 = _mm_and_ps(xmm_tmp7, xmm_max);
			xmm_dst0 = _mm_add_ps(xmm_dst0, xmm_tmp0);
			xmm_dst1 = _mm_add_ps(xmm_dst1, xmm_tmp1);
			xmm_dst2 = _mm_add_ps(xmm_dst2, xmm_tmp2);
			xmm_dst3 = _mm_add_ps(xmm_dst3, xmm_tmp3);
			xmm_dst4 = _mm_add_ps(xmm_dst4, xmm_tmp4);
			xmm_dst5 = _mm_add_ps(xmm_dst5, xmm_tmp5);
			xmm_dst6 = _mm_add_ps(xmm_dst6, xmm_tmp6);
			xmm_dst7 = _mm_add_ps(xmm_dst7, xmm_tmp7);
			_mm_storeu_ps(dst, xmm_dst0);
			_mm_storeu_ps(dst + 4, xmm_dst1);
			_mm_storeu_ps(dst + 8, xmm_dst2);
			_mm_storeu_ps(dst + 12, xmm_dst3);
			_mm_storeu_ps(dst + 16, xmm_dst4);
			_mm_storeu_ps(dst + 20, xmm_dst5);
			_mm_storeu_ps(dst + 24, xmm_dst6);
			_mm_storeu_ps(dst + 28, xmm_dst7);
		}

		template <>
		inline void cvtu32_sse41_32<double>(double* dst, const unsigned int* src)
		{
			const __m128d xmm_zero = _mm_setzero_pd();
			const __m128d xmm_max = _mm_castsi128_pd(_mm_set1_epi64x(0x41f0000000000000));
			__m128i xmm_src0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src));
			__m128i xmm_src1 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 2));
			__m128i xmm_src2 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 4));
			__m128i xmm_src3 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 6));
			__m128i xmm_src4 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 8));
			__m128i xmm_src5 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 10));
			__m128i xmm_src6 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 12));
			__m128i xmm_src7 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 14));
			__m128i xmm_src8 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 16));
			__m128i xmm_src9 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 18));
			__m128i xmm_srca = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 20));
			__m128i xmm_srcb = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 22));
			__m128i xmm_srcc = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 24));
			__m128i xmm_srcd = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 26));
			__m128i xmm_srce = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 28));
			__m128i xmm_srcf = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 30));
			__m128d xmm_dst0 = _mm_cvtepi32_pd(xmm_src0);
			__m128d xmm_dst1 = _mm_cvtepi32_pd(xmm_src1);
			__m128d xmm_dst2 = _mm_cvtepi32_pd(xmm_src2);
			__m128d xmm_dst3 = _mm_cvtepi32_pd(xmm_src3);
			__m128d xmm_dst4 = _mm_cvtepi32_pd(xmm_src4);
			__m128d xmm_dst5 = _mm_cvtepi32_pd(xmm_src5);
			__m128d xmm_dst6 = _mm_cvtepi32_pd(xmm_src6);
			__m128d xmm_dst7 = _mm_cvtepi32_pd(xmm_src7);
			__m128d xmm_dst8 = _mm_cvtepi32_pd(xmm_src8);
			__m128d xmm_dst9 = _mm_cvtepi32_pd(xmm_src9);
			__m128d xmm_dsta = _mm_cvtepi32_pd(xmm_srca);
			__m128d xmm_dstb = _mm_cvtepi32_pd(xmm_srcb);
			__m128d xmm_dstc = _mm_cvtepi32_pd(xmm_srcc);
			__m128d xmm_dstd = _mm_cvtepi32_pd(xmm_srcd);
			__m128d xmm_dste = _mm_cvtepi32_pd(xmm_srce);
			__m128d xmm_dstf = _mm_cvtepi32_pd(xmm_srcf);
			__m128d xmm_tmp0 = _mm_cmplt_pd(xmm_dst0, xmm_zero);
			__m128d xmm_tmp1 = _mm_cmplt_pd(xmm_dst1, xmm_zero);
			__m128d xmm_tmp2 = _mm_cmplt_pd(xmm_dst2, xmm_zero);
			__m128d xmm_tmp3 = _mm_cmplt_pd(xmm_dst3, xmm_zero);
			__m128d xmm_tmp4 = _mm_cmplt_pd(xmm_dst4, xmm_zero);
			__m128d xmm_tmp5 = _mm_cmplt_pd(xmm_dst5, xmm_zero);
			__m128d xmm_tmp6 = _mm_cmplt_pd(xmm_dst6, xmm_zero);
			__m128d xmm_tmp7 = _mm_cmplt_pd(xmm_dst7, xmm_zero);
			__m128d xmm_tmp8 = _mm_cmplt_pd(xmm_dst8, xmm_zero);
			__m128d xmm_tmp9 = _mm_cmplt_pd(xmm_dst9, xmm_zero);
			__m128d xmm_tmpa = _mm_cmplt_pd(xmm_dsta, xmm_zero);
			__m128d xmm_tmpb = _mm_cmplt_pd(xmm_dstb, xmm_zero);
			__m128d xmm_tmpc = _mm_cmplt_pd(xmm_dstc, xmm_zero);
			__m128d xmm_tmpd = _mm_cmplt_pd(xmm_dstd, xmm_zero);
			__m128d xmm_tmpe = _mm_cmplt_pd(xmm_dste, xmm_zero);
			__m128d xmm_tmpf = _mm_cmplt_pd(xmm_dstf, xmm_zero);
			xmm_tmp0 = _mm_and_pd(xmm_tmp0, xmm_max);
			xmm_tmp1 = _mm_and_pd(xmm_tmp1, xmm_max);
			xmm_tmp2 = _mm_and_pd(xmm_tmp2, xmm_max);
			xmm_tmp3 = _mm_and_pd(xmm_tmp3, xmm_max);
			xmm_tmp4 = _mm_and_pd(xmm_tmp4, xmm_max);
			xmm_tmp5 = _mm_and_pd(xmm_tmp5, xmm_max);
			xmm_tmp6 = _mm_and_pd(xmm_tmp6, xmm_max);
			xmm_tmp7 = _mm_and_pd(xmm_tmp7, xmm_max);
			xmm_tmp8 = _mm_and_pd(xmm_tmp8, xmm_max);
			xmm_tmp9 = _mm_and_pd(xmm_tmp9, xmm_max);
			xmm_tmpa = _mm_and_pd(xmm_tmpa, xmm_max);
			xmm_tmpb = _mm_and_pd(xmm_tmpb, xmm_max);
			xmm_tmpc = _mm_and_pd(xmm_tmpc, xmm_max);
			xmm_tmpd = _mm_and_pd(xmm_tmpd, xmm_max);
			xmm_tmpe = _mm_and_pd(xmm_tmpe, xmm_max);
			xmm_tmpf = _mm_and_pd(xmm_tmpf, xmm_max);
			xmm_dst0 = _mm_add_pd(xmm_dst0, xmm_tmp0);
			xmm_dst1 = _mm_add_pd(xmm_dst1, xmm_tmp1);
			xmm_dst2 = _mm_add_pd(xmm_dst2, xmm_tmp2);
			xmm_dst3 = _mm_add_pd(xmm_dst3, xmm_tmp3);
			xmm_dst4 = _mm_add_pd(xmm_dst4, xmm_tmp4);
			xmm_dst5 = _mm_add_pd(xmm_dst5, xmm_tmp5);
			xmm_dst6 = _mm_add_pd(xmm_dst6, xmm_tmp6);
			xmm_dst7 = _mm_add_pd(xmm_dst7, xmm_tmp7);
			xmm_dst8 = _mm_add_pd(xmm_dst8, xmm_tmp8);
			xmm_dst9 = _mm_add_pd(xmm_dst9, xmm_tmp9);
			xmm_dsta = _mm_add_pd(xmm_dsta, xmm_tmpa);
			xmm_dstb = _mm_add_pd(xmm_dstb, xmm_tmpb);
			xmm_dstc = _mm_add_pd(xmm_dstc, xmm_tmpc);
			xmm_dstd = _mm_add_pd(xmm_dstd, xmm_tmpd);
			xmm_dste = _mm_add_pd(xmm_dste, xmm_tmpe);
			xmm_dstf = _mm_add_pd(xmm_dstf, xmm_tmpf);
			_mm_storeu_pd(dst, xmm_dst0);
			_mm_storeu_pd(dst + 2, xmm_dst1);
			_mm_storeu_pd(dst + 4, xmm_dst2);
			_mm_storeu_pd(dst + 6, xmm_dst3);
			_mm_storeu_pd(dst + 8, xmm_dst4);
			_mm_storeu_pd(dst + 10, xmm_dst5);
			_mm_storeu_pd(dst + 12, xmm_dst6);
			_mm_storeu_pd(dst + 14, xmm_dst7);
			_mm_storeu_pd(dst + 16, xmm_dst8);
			_mm_storeu_pd(dst + 18, xmm_dst9);
			_mm_storeu_pd(dst + 20, xmm_dsta);
			_mm_storeu_pd(dst + 22, xmm_dstb);
			_mm_storeu_pd(dst + 24, xmm_dstc);
			_mm_storeu_pd(dst + 26, xmm_dstd);
			_mm_storeu_pd(dst + 28, xmm_dste);
			_mm_storeu_pd(dst + 30, xmm_dstf);
		}

		// Function template cvtu32_sse41_small

		template <class T>
		void cvtu32_sse41_small(T* dst, const unsigned int* src, size_t n)
		{
			switch (n >> 3)
			{
			case 4:
				cvtu32_sse41_32(dst, src);
			case 0:
				break;
			case 5:
				cvtu32_sse41_32(dst, src);
				src += 32;
				dst += 32;
			case 1:
				cvtu32_sse41_8(dst, src);
				break;
			case 6:
				cvtu32_sse41_32(dst, src);
				src += 32;
				dst += 32;
			case 2:
				cvtu32_sse41_16(dst, src);
				break;
			case 7:
				cvtu32_sse41_32(dst, src);
				src += 32;
				dst += 32;
			case 3:
				cvtu32_sse41_16(dst, src);
				src += 16;
				dst += 16;
				cvtu32_sse41_8(dst, src);
				break;
			}
			cvtu32_tiny(dst, src, n & 7);
		}

		// Function template cvtu32_sse41_medium

		template <class T>
		inline void cvtu32_sse41_medium(T* dst, const unsigned int* src, size_t n)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		void cvtu32_sse41_medium<signed char>(signed char* dst, const unsigned int* src, size_t n)
		{
			const __m128i xmm_mask = _mm_set_epi64x(0xffffffffffffffffi64, 0xffffffff0c080400i64);
			__m128i xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128i xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3, xmm_dst4, xmm_dst5, xmm_dst6, xmm_dst7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
				xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
				xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
				xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
				xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
				xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
				xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
				xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
				xmm_dst0 = _mm_shuffle_epi8(xmm_src0, xmm_mask);
				xmm_dst1 = _mm_shuffle_epi8(xmm_src1, xmm_mask);
				xmm_dst2 = _mm_shuffle_epi8(xmm_src2, xmm_mask);
				xmm_dst3 = _mm_shuffle_epi8(xmm_src3, xmm_mask);
				xmm_dst4 = _mm_shuffle_epi8(xmm_src4, xmm_mask);
				xmm_dst5 = _mm_shuffle_epi8(xmm_src5, xmm_mask);
				xmm_dst6 = _mm_shuffle_epi8(xmm_src6, xmm_mask);
				xmm_dst7 = _mm_shuffle_epi8(xmm_src7, xmm_mask);
				xmm_dst0 = _mm_unpacklo_epi32(xmm_dst0, xmm_dst1);
				xmm_dst2 = _mm_unpacklo_epi32(xmm_dst2, xmm_dst3);
				xmm_dst4 = _mm_unpacklo_epi32(xmm_dst4, xmm_dst5);
				xmm_dst6 = _mm_unpacklo_epi32(xmm_dst6, xmm_dst7);
				xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst2);
				xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst6);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst4);
				src += 32;
				dst += 32;
			}
		}

		template <>
		void cvtu32_sse41_medium<unsigned char>(unsigned char* dst, const unsigned int* src, size_t n)
		{
			const __m128i xmm_mask = _mm_set_epi64x(0xffffffffffffffffi64, 0xffffffff0c080400i64);
			__m128i xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128i xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3, xmm_dst4, xmm_dst5, xmm_dst6, xmm_dst7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
				xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
				xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
				xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
				xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
				xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
				xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
				xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
				xmm_dst0 = _mm_shuffle_epi8(xmm_src0, xmm_mask);
				xmm_dst1 = _mm_shuffle_epi8(xmm_src1, xmm_mask);
				xmm_dst2 = _mm_shuffle_epi8(xmm_src2, xmm_mask);
				xmm_dst3 = _mm_shuffle_epi8(xmm_src3, xmm_mask);
				xmm_dst4 = _mm_shuffle_epi8(xmm_src4, xmm_mask);
				xmm_dst5 = _mm_shuffle_epi8(xmm_src5, xmm_mask);
				xmm_dst6 = _mm_shuffle_epi8(xmm_src6, xmm_mask);
				xmm_dst7 = _mm_shuffle_epi8(xmm_src7, xmm_mask);
				xmm_dst0 = _mm_unpacklo_epi32(xmm_dst0, xmm_dst1);
				xmm_dst2 = _mm_unpacklo_epi32(xmm_dst2, xmm_dst3);
				xmm_dst4 = _mm_unpacklo_epi32(xmm_dst4, xmm_dst5);
				xmm_dst6 = _mm_unpacklo_epi32(xmm_dst6, xmm_dst7);
				xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst2);
				xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst6);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst4);
				src += 32;
				dst += 32;
			}
		}

		template <>
		void cvtu32_sse41_medium<signed short>(signed short* dst, const unsigned int* src, size_t n)
		{
			const __m128i xmm_mask = _mm_set_epi64x(0xffffffffffffffffi64, 0x0d0c090805040100i64);
			__m128i xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128i xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3, xmm_dst4, xmm_dst5, xmm_dst6, xmm_dst7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
				xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
				xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
				xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
				xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
				xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
				xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
				xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
				xmm_dst0 = _mm_shuffle_epi8(xmm_src0, xmm_mask);
				xmm_dst1 = _mm_shuffle_epi8(xmm_src1, xmm_mask);
				xmm_dst2 = _mm_shuffle_epi8(xmm_src2, xmm_mask);
				xmm_dst3 = _mm_shuffle_epi8(xmm_src3, xmm_mask);
				xmm_dst4 = _mm_shuffle_epi8(xmm_src4, xmm_mask);
				xmm_dst5 = _mm_shuffle_epi8(xmm_src5, xmm_mask);
				xmm_dst6 = _mm_shuffle_epi8(xmm_src6, xmm_mask);
				xmm_dst7 = _mm_shuffle_epi8(xmm_src7, xmm_mask);
				xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
				xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
				xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
				xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst2);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 2, xmm_dst4);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 3, xmm_dst6);
				src += 32;
				dst += 32;
			}
		}

		template <>
		void cvtu32_sse41_medium<unsigned short>(unsigned short* dst, const unsigned int* src, size_t n)
		{
			const __m128i xmm_mask = _mm_set_epi64x(0xffffffffffffffffi64, 0x0d0c090805040100i64);
			__m128i xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128i xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3, xmm_dst4, xmm_dst5, xmm_dst6, xmm_dst7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
				xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
				xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
				xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
				xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
				xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
				xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
				xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
				xmm_dst0 = _mm_shuffle_epi8(xmm_src0, xmm_mask);
				xmm_dst1 = _mm_shuffle_epi8(xmm_src1, xmm_mask);
				xmm_dst2 = _mm_shuffle_epi8(xmm_src2, xmm_mask);
				xmm_dst3 = _mm_shuffle_epi8(xmm_src3, xmm_mask);
				xmm_dst4 = _mm_shuffle_epi8(xmm_src4, xmm_mask);
				xmm_dst5 = _mm_shuffle_epi8(xmm_src5, xmm_mask);
				xmm_dst6 = _mm_shuffle_epi8(xmm_src6, xmm_mask);
				xmm_dst7 = _mm_shuffle_epi8(xmm_src7, xmm_mask);
				xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
				xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
				xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
				xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst2);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 2, xmm_dst4);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 3, xmm_dst6);
				src += 32;
				dst += 32;
			}
		}

		template <>
		void cvtu32_sse41_medium<float>(float* dst, const unsigned int* src, size_t n)
		{
			const __m128 xmm_zero = _mm_setzero_ps();
			const __m128 xmm_max = _mm_castsi128_ps(_mm_set1_epi32(0x4f800000));
			__m128i xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128 xmm_tmp0, xmm_tmp1, xmm_tmp2, xmm_tmp3, xmm_tmp4, xmm_tmp5, xmm_tmp6, xmm_tmp7;
			__m128 xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3, xmm_dst4, xmm_dst5, xmm_dst6, xmm_dst7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
				xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
				xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
				xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
				xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
				xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
				xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
				xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
				xmm_dst0 = _mm_cvtepi32_ps(xmm_src0);
				xmm_dst1 = _mm_cvtepi32_ps(xmm_src1);
				xmm_dst2 = _mm_cvtepi32_ps(xmm_src2);
				xmm_dst3 = _mm_cvtepi32_ps(xmm_src3);
				xmm_dst4 = _mm_cvtepi32_ps(xmm_src4);
				xmm_dst5 = _mm_cvtepi32_ps(xmm_src5);
				xmm_dst6 = _mm_cvtepi32_ps(xmm_src6);
				xmm_dst7 = _mm_cvtepi32_ps(xmm_src7);
				xmm_tmp0 = _mm_cmplt_ps(xmm_dst0, xmm_zero);
				xmm_tmp1 = _mm_cmplt_ps(xmm_dst1, xmm_zero);
				xmm_tmp2 = _mm_cmplt_ps(xmm_dst2, xmm_zero);
				xmm_tmp3 = _mm_cmplt_ps(xmm_dst3, xmm_zero);
				xmm_tmp4 = _mm_cmplt_ps(xmm_dst4, xmm_zero);
				xmm_tmp5 = _mm_cmplt_ps(xmm_dst5, xmm_zero);
				xmm_tmp6 = _mm_cmplt_ps(xmm_dst6, xmm_zero);
				xmm_tmp7 = _mm_cmplt_ps(xmm_dst7, xmm_zero);
				xmm_tmp0 = _mm_and_ps(xmm_tmp0, xmm_max);
				xmm_tmp1 = _mm_and_ps(xmm_tmp1, xmm_max);
				xmm_tmp2 = _mm_and_ps(xmm_tmp2, xmm_max);
				xmm_tmp3 = _mm_and_ps(xmm_tmp3, xmm_max);
				xmm_tmp4 = _mm_and_ps(xmm_tmp4, xmm_max);
				xmm_tmp5 = _mm_and_ps(xmm_tmp5, xmm_max);
				xmm_tmp6 = _mm_and_ps(xmm_tmp6, xmm_max);
				xmm_tmp7 = _mm_and_ps(xmm_tmp7, xmm_max);
				xmm_dst0 = _mm_add_ps(xmm_dst0, xmm_tmp0);
				xmm_dst1 = _mm_add_ps(xmm_dst1, xmm_tmp1);
				xmm_dst2 = _mm_add_ps(xmm_dst2, xmm_tmp2);
				xmm_dst3 = _mm_add_ps(xmm_dst3, xmm_tmp3);
				xmm_dst4 = _mm_add_ps(xmm_dst4, xmm_tmp4);
				xmm_dst5 = _mm_add_ps(xmm_dst5, xmm_tmp5);
				xmm_dst6 = _mm_add_ps(xmm_dst6, xmm_tmp6);
				xmm_dst7 = _mm_add_ps(xmm_dst7, xmm_tmp7);
				_mm_storeu_ps(dst, xmm_dst0);
				_mm_storeu_ps(dst + 4, xmm_dst1);
				_mm_storeu_ps(dst + 8, xmm_dst2);
				_mm_storeu_ps(dst + 12, xmm_dst3);
				_mm_storeu_ps(dst + 16, xmm_dst4);
				_mm_storeu_ps(dst + 20, xmm_dst5);
				_mm_storeu_ps(dst + 24, xmm_dst6);
				_mm_storeu_ps(dst + 28, xmm_dst7);
				src += 32;
				dst += 32;
			}
		}

		template <>
		void cvtu32_sse41_medium<double>(double* dst, const unsigned int* src, size_t n)
		{
			const __m128d xmm_zero = _mm_setzero_pd();
			const __m128d xmm_max = _mm_castsi128_pd(_mm_set1_epi64x(0x41f0000000000000));
			__m128i xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128i xmm_src8, xmm_src9, xmm_srca, xmm_srcb, xmm_srcc, xmm_srcd, xmm_srce, xmm_srcf;
			__m128d xmm_tmp0, xmm_tmp1, xmm_tmp2, xmm_tmp3, xmm_tmp4, xmm_tmp5, xmm_tmp6, xmm_tmp7;
			__m128d xmm_tmp8, xmm_tmp9, xmm_tmpa, xmm_tmpb, xmm_tmpc, xmm_tmpd, xmm_tmpe, xmm_tmpf;
			__m128d xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3, xmm_dst4, xmm_dst5, xmm_dst6, xmm_dst7;
			__m128d xmm_dst8, xmm_dst9, xmm_dsta, xmm_dstb, xmm_dstc, xmm_dstd, xmm_dste, xmm_dstf;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				xmm_src0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src));
				xmm_src1 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 2));
				xmm_src2 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 4));
				xmm_src3 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 6));
				xmm_src4 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 8));
				xmm_src5 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 10));
				xmm_src6 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 12));
				xmm_src7 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 14));
				xmm_src8 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 16));
				xmm_src9 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 18));
				xmm_srca = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 20));
				xmm_srcb = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 22));
				xmm_srcc = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 24));
				xmm_srcd = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 26));
				xmm_srce = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 28));
				xmm_srcf = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 30));
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
				xmm_dst0 = _mm_cvtepi32_pd(xmm_src0);
				xmm_dst1 = _mm_cvtepi32_pd(xmm_src1);
				xmm_dst2 = _mm_cvtepi32_pd(xmm_src2);
				xmm_dst3 = _mm_cvtepi32_pd(xmm_src3);
				xmm_dst4 = _mm_cvtepi32_pd(xmm_src4);
				xmm_dst5 = _mm_cvtepi32_pd(xmm_src5);
				xmm_dst6 = _mm_cvtepi32_pd(xmm_src6);
				xmm_dst7 = _mm_cvtepi32_pd(xmm_src7);
				xmm_dst8 = _mm_cvtepi32_pd(xmm_src8);
				xmm_dst9 = _mm_cvtepi32_pd(xmm_src9);
				xmm_dsta = _mm_cvtepi32_pd(xmm_srca);
				xmm_dstb = _mm_cvtepi32_pd(xmm_srcb);
				xmm_dstc = _mm_cvtepi32_pd(xmm_srcc);
				xmm_dstd = _mm_cvtepi32_pd(xmm_srcd);
				xmm_dste = _mm_cvtepi32_pd(xmm_srce);
				xmm_dstf = _mm_cvtepi32_pd(xmm_srcf);
				xmm_tmp0 = _mm_cmplt_pd(xmm_dst0, xmm_zero);
				xmm_tmp1 = _mm_cmplt_pd(xmm_dst1, xmm_zero);
				xmm_tmp2 = _mm_cmplt_pd(xmm_dst2, xmm_zero);
				xmm_tmp3 = _mm_cmplt_pd(xmm_dst3, xmm_zero);
				xmm_tmp4 = _mm_cmplt_pd(xmm_dst4, xmm_zero);
				xmm_tmp5 = _mm_cmplt_pd(xmm_dst5, xmm_zero);
				xmm_tmp6 = _mm_cmplt_pd(xmm_dst6, xmm_zero);
				xmm_tmp7 = _mm_cmplt_pd(xmm_dst7, xmm_zero);
				xmm_tmp8 = _mm_cmplt_pd(xmm_dst8, xmm_zero);
				xmm_tmp9 = _mm_cmplt_pd(xmm_dst9, xmm_zero);
				xmm_tmpa = _mm_cmplt_pd(xmm_dsta, xmm_zero);
				xmm_tmpb = _mm_cmplt_pd(xmm_dstb, xmm_zero);
				xmm_tmpc = _mm_cmplt_pd(xmm_dstc, xmm_zero);
				xmm_tmpd = _mm_cmplt_pd(xmm_dstd, xmm_zero);
				xmm_tmpe = _mm_cmplt_pd(xmm_dste, xmm_zero);
				xmm_tmpf = _mm_cmplt_pd(xmm_dstf, xmm_zero);
				xmm_tmp0 = _mm_and_pd(xmm_tmp0, xmm_max);
				xmm_tmp1 = _mm_and_pd(xmm_tmp1, xmm_max);
				xmm_tmp2 = _mm_and_pd(xmm_tmp2, xmm_max);
				xmm_tmp3 = _mm_and_pd(xmm_tmp3, xmm_max);
				xmm_tmp4 = _mm_and_pd(xmm_tmp4, xmm_max);
				xmm_tmp5 = _mm_and_pd(xmm_tmp5, xmm_max);
				xmm_tmp6 = _mm_and_pd(xmm_tmp6, xmm_max);
				xmm_tmp7 = _mm_and_pd(xmm_tmp7, xmm_max);
				xmm_tmp8 = _mm_and_pd(xmm_tmp8, xmm_max);
				xmm_tmp9 = _mm_and_pd(xmm_tmp9, xmm_max);
				xmm_tmpa = _mm_and_pd(xmm_tmpa, xmm_max);
				xmm_tmpb = _mm_and_pd(xmm_tmpb, xmm_max);
				xmm_tmpc = _mm_and_pd(xmm_tmpc, xmm_max);
				xmm_tmpd = _mm_and_pd(xmm_tmpd, xmm_max);
				xmm_tmpe = _mm_and_pd(xmm_tmpe, xmm_max);
				xmm_tmpf = _mm_and_pd(xmm_tmpf, xmm_max);
				xmm_dst0 = _mm_add_pd(xmm_dst0, xmm_tmp0);
				xmm_dst1 = _mm_add_pd(xmm_dst1, xmm_tmp1);
				xmm_dst2 = _mm_add_pd(xmm_dst2, xmm_tmp2);
				xmm_dst3 = _mm_add_pd(xmm_dst3, xmm_tmp3);
				xmm_dst4 = _mm_add_pd(xmm_dst4, xmm_tmp4);
				xmm_dst5 = _mm_add_pd(xmm_dst5, xmm_tmp5);
				xmm_dst6 = _mm_add_pd(xmm_dst6, xmm_tmp6);
				xmm_dst7 = _mm_add_pd(xmm_dst7, xmm_tmp7);
				xmm_dst8 = _mm_add_pd(xmm_dst8, xmm_tmp8);
				xmm_dst9 = _mm_add_pd(xmm_dst9, xmm_tmp9);
				xmm_dsta = _mm_add_pd(xmm_dsta, xmm_tmpa);
				xmm_dstb = _mm_add_pd(xmm_dstb, xmm_tmpb);
				xmm_dstc = _mm_add_pd(xmm_dstc, xmm_tmpc);
				xmm_dstd = _mm_add_pd(xmm_dstd, xmm_tmpd);
				xmm_dste = _mm_add_pd(xmm_dste, xmm_tmpe);
				xmm_dstf = _mm_add_pd(xmm_dstf, xmm_tmpf);
				_mm_storeu_pd(dst, xmm_dst0);
				_mm_storeu_pd(dst + 2, xmm_dst1);
				_mm_storeu_pd(dst + 4, xmm_dst2);
				_mm_storeu_pd(dst + 6, xmm_dst3);
				_mm_storeu_pd(dst + 8, xmm_dst4);
				_mm_storeu_pd(dst + 10, xmm_dst5);
				_mm_storeu_pd(dst + 12, xmm_dst6);
				_mm_storeu_pd(dst + 14, xmm_dst7);
				_mm_storeu_pd(dst + 16, xmm_dst8);
				_mm_storeu_pd(dst + 18, xmm_dst9);
				_mm_storeu_pd(dst + 20, xmm_dsta);
				_mm_storeu_pd(dst + 22, xmm_dstb);
				_mm_storeu_pd(dst + 24, xmm_dstc);
				_mm_storeu_pd(dst + 26, xmm_dstd);
				_mm_storeu_pd(dst + 28, xmm_dste);
				_mm_storeu_pd(dst + 30, xmm_dstf);
				src += 32;
				dst += 32;
			}
		}

		// Function template cvtu32_sse41_large

		template <class T>
		inline void cvtu32_sse41_large(T* dst, const unsigned int* src, size_t n)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		void cvtu32_sse41_large<signed char>(signed char* dst, const unsigned int* src, size_t n)
		{
			const size_t padding = 16 - (reinterpret_cast<size_t>(dst) & 15);
			const __m128i xmm_mask = _mm_set_epi64x(0xffffffffffffffffi64, 0xffffffff0c080400i64);
			__m128i xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128i xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3, xmm_dst4, xmm_dst5, xmm_dst6, xmm_dst7;

			// Align the destination to a 16-byte boundary.
			xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
			xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
			xmm_dst0 = _mm_shuffle_epi8(xmm_src0, xmm_mask);
			xmm_dst1 = _mm_shuffle_epi8(xmm_src1, xmm_mask);
			xmm_dst2 = _mm_shuffle_epi8(xmm_src2, xmm_mask);
			xmm_dst3 = _mm_shuffle_epi8(xmm_src3, xmm_mask);
			xmm_dst0 = _mm_unpacklo_epi32(xmm_dst0, xmm_dst1);
			xmm_dst2 = _mm_unpacklo_epi32(xmm_dst2, xmm_dst3);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
			dst += padding;
			src += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			// If the source is aligned on a 16-byte boundary.
			if ((reinterpret_cast<size_t>(src) & 15) == 0)
			{
				for (; n >= 32; n -= 32)
				{
					xmm_src0 = _mm_load_si128(reinterpret_cast<const __m128i*>(src));
					xmm_src1 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 1);
					xmm_src2 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 2);
					xmm_src3 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 3);
					xmm_src4 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 4);
					xmm_src5 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 5);
					xmm_src6 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 6);
					xmm_src7 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 7);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					xmm_dst0 = _mm_shuffle_epi8(xmm_src0, xmm_mask);
					xmm_dst1 = _mm_shuffle_epi8(xmm_src1, xmm_mask);
					xmm_dst2 = _mm_shuffle_epi8(xmm_src2, xmm_mask);
					xmm_dst3 = _mm_shuffle_epi8(xmm_src3, xmm_mask);
					xmm_dst4 = _mm_shuffle_epi8(xmm_src4, xmm_mask);
					xmm_dst5 = _mm_shuffle_epi8(xmm_src5, xmm_mask);
					xmm_dst6 = _mm_shuffle_epi8(xmm_src6, xmm_mask);
					xmm_dst7 = _mm_shuffle_epi8(xmm_src7, xmm_mask);
					xmm_dst0 = _mm_unpacklo_epi32(xmm_dst0, xmm_dst1);
					xmm_dst2 = _mm_unpacklo_epi32(xmm_dst2, xmm_dst3);
					xmm_dst4 = _mm_unpacklo_epi32(xmm_dst4, xmm_dst5);
					xmm_dst6 = _mm_unpacklo_epi32(xmm_dst6, xmm_dst7);
					xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst2);
					xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst6);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst4);
					src += 32;
					dst += 32;
				}
			}
			else
			{
				for (; n >= 32; n -= 32)
				{
					xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
					xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
					xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
					xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
					xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
					xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
					xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
					xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					xmm_dst0 = _mm_shuffle_epi8(xmm_src0, xmm_mask);
					xmm_dst1 = _mm_shuffle_epi8(xmm_src1, xmm_mask);
					xmm_dst2 = _mm_shuffle_epi8(xmm_src2, xmm_mask);
					xmm_dst3 = _mm_shuffle_epi8(xmm_src3, xmm_mask);
					xmm_dst4 = _mm_shuffle_epi8(xmm_src4, xmm_mask);
					xmm_dst5 = _mm_shuffle_epi8(xmm_src5, xmm_mask);
					xmm_dst6 = _mm_shuffle_epi8(xmm_src6, xmm_mask);
					xmm_dst7 = _mm_shuffle_epi8(xmm_src7, xmm_mask);
					xmm_dst0 = _mm_unpacklo_epi32(xmm_dst0, xmm_dst1);
					xmm_dst2 = _mm_unpacklo_epi32(xmm_dst2, xmm_dst3);
					xmm_dst4 = _mm_unpacklo_epi32(xmm_dst4, xmm_dst5);
					xmm_dst6 = _mm_unpacklo_epi32(xmm_dst6, xmm_dst7);
					xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst2);
					xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst6);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst4);
					src += 32;
					dst += 32;
				}
			}
		}

		template <>
		void cvtu32_sse41_large<unsigned char>(unsigned char* dst, const unsigned int* src, size_t n)
		{
			const size_t padding = 16 - (reinterpret_cast<size_t>(dst) & 15);
			const __m128i xmm_mask = _mm_set_epi64x(0xffffffffffffffffi64, 0xffffffff0c080400i64);
			__m128i xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128i xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3, xmm_dst4, xmm_dst5, xmm_dst6, xmm_dst7;

			// Align the destination to a 16-byte boundary.
			xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
			xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
			xmm_dst0 = _mm_shuffle_epi8(xmm_src0, xmm_mask);
			xmm_dst1 = _mm_shuffle_epi8(xmm_src1, xmm_mask);
			xmm_dst2 = _mm_shuffle_epi8(xmm_src2, xmm_mask);
			xmm_dst3 = _mm_shuffle_epi8(xmm_src3, xmm_mask);
			xmm_dst0 = _mm_unpacklo_epi32(xmm_dst0, xmm_dst1);
			xmm_dst2 = _mm_unpacklo_epi32(xmm_dst2, xmm_dst3);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
			dst += padding;
			src += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			// If the source is aligned on a 16-byte boundary.
			if ((reinterpret_cast<size_t>(src) & 15) == 0)
			{
				for (; n >= 32; n -= 32)
				{
					xmm_src0 = _mm_load_si128(reinterpret_cast<const __m128i*>(src));
					xmm_src1 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 1);
					xmm_src2 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 2);
					xmm_src3 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 3);
					xmm_src4 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 4);
					xmm_src5 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 5);
					xmm_src6 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 6);
					xmm_src7 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 7);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					xmm_dst0 = _mm_shuffle_epi8(xmm_src0, xmm_mask);
					xmm_dst1 = _mm_shuffle_epi8(xmm_src1, xmm_mask);
					xmm_dst2 = _mm_shuffle_epi8(xmm_src2, xmm_mask);
					xmm_dst3 = _mm_shuffle_epi8(xmm_src3, xmm_mask);
					xmm_dst4 = _mm_shuffle_epi8(xmm_src4, xmm_mask);
					xmm_dst5 = _mm_shuffle_epi8(xmm_src5, xmm_mask);
					xmm_dst6 = _mm_shuffle_epi8(xmm_src6, xmm_mask);
					xmm_dst7 = _mm_shuffle_epi8(xmm_src7, xmm_mask);
					xmm_dst0 = _mm_unpacklo_epi32(xmm_dst0, xmm_dst1);
					xmm_dst2 = _mm_unpacklo_epi32(xmm_dst2, xmm_dst3);
					xmm_dst4 = _mm_unpacklo_epi32(xmm_dst4, xmm_dst5);
					xmm_dst6 = _mm_unpacklo_epi32(xmm_dst6, xmm_dst7);
					xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst2);
					xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst6);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst4);
					src += 32;
					dst += 32;
				}
			}
			else
			{
				for (; n >= 32; n -= 32)
				{
					xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
					xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
					xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
					xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
					xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
					xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
					xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
					xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					xmm_dst0 = _mm_shuffle_epi8(xmm_src0, xmm_mask);
					xmm_dst1 = _mm_shuffle_epi8(xmm_src1, xmm_mask);
					xmm_dst2 = _mm_shuffle_epi8(xmm_src2, xmm_mask);
					xmm_dst3 = _mm_shuffle_epi8(xmm_src3, xmm_mask);
					xmm_dst4 = _mm_shuffle_epi8(xmm_src4, xmm_mask);
					xmm_dst5 = _mm_shuffle_epi8(xmm_src5, xmm_mask);
					xmm_dst6 = _mm_shuffle_epi8(xmm_src6, xmm_mask);
					xmm_dst7 = _mm_shuffle_epi8(xmm_src7, xmm_mask);
					xmm_dst0 = _mm_unpacklo_epi32(xmm_dst0, xmm_dst1);
					xmm_dst2 = _mm_unpacklo_epi32(xmm_dst2, xmm_dst3);
					xmm_dst4 = _mm_unpacklo_epi32(xmm_dst4, xmm_dst5);
					xmm_dst6 = _mm_unpacklo_epi32(xmm_dst6, xmm_dst7);
					xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst2);
					xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst6);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst4);
					src += 32;
					dst += 32;
				}
			}
		}

		template <>
		void cvtu32_sse41_large<signed short>(signed short* dst, const unsigned int* src, size_t n)
		{
			const size_t padding = 8 - (reinterpret_cast<size_t>(dst) & 7);
			const __m128i xmm_mask = _mm_set_epi64x(0xffffffffffffffffi64, 0x0d0c090805040100i64);
			__m128i xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128i xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3, xmm_dst4, xmm_dst5, xmm_dst6, xmm_dst7;

			// Align the destination to a 16-byte boundary.
			xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			xmm_dst0 = _mm_shuffle_epi8(xmm_src0, xmm_mask);
			xmm_dst1 = _mm_shuffle_epi8(xmm_src1, xmm_mask);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
			dst += padding;
			src += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			// If the source is aligned on a 16-byte boundary.
			if ((reinterpret_cast<size_t>(src) & 15) == 0)
			{
				for (; n >= 32; n -= 32)
				{
					xmm_src0 = _mm_load_si128(reinterpret_cast<const __m128i*>(src));
					xmm_src1 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 1);
					xmm_src2 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 2);
					xmm_src3 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 3);
					xmm_src4 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 4);
					xmm_src5 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 5);
					xmm_src6 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 6);
					xmm_src7 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 7);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					xmm_dst0 = _mm_shuffle_epi8(xmm_src0, xmm_mask);
					xmm_dst1 = _mm_shuffle_epi8(xmm_src1, xmm_mask);
					xmm_dst2 = _mm_shuffle_epi8(xmm_src2, xmm_mask);
					xmm_dst3 = _mm_shuffle_epi8(xmm_src3, xmm_mask);
					xmm_dst4 = _mm_shuffle_epi8(xmm_src4, xmm_mask);
					xmm_dst5 = _mm_shuffle_epi8(xmm_src5, xmm_mask);
					xmm_dst6 = _mm_shuffle_epi8(xmm_src6, xmm_mask);
					xmm_dst7 = _mm_shuffle_epi8(xmm_src7, xmm_mask);
					xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
					xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
					xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
					xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst2);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 2, xmm_dst4);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 3, xmm_dst6);
					src += 32;
					dst += 32;
				}
			}
			else
			{
				for (; n >= 32; n -= 32)
				{
					xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
					xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
					xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
					xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
					xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
					xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
					xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
					xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					xmm_dst0 = _mm_shuffle_epi8(xmm_src0, xmm_mask);
					xmm_dst1 = _mm_shuffle_epi8(xmm_src1, xmm_mask);
					xmm_dst2 = _mm_shuffle_epi8(xmm_src2, xmm_mask);
					xmm_dst3 = _mm_shuffle_epi8(xmm_src3, xmm_mask);
					xmm_dst4 = _mm_shuffle_epi8(xmm_src4, xmm_mask);
					xmm_dst5 = _mm_shuffle_epi8(xmm_src5, xmm_mask);
					xmm_dst6 = _mm_shuffle_epi8(xmm_src6, xmm_mask);
					xmm_dst7 = _mm_shuffle_epi8(xmm_src7, xmm_mask);
					xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
					xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
					xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
					xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst2);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 2, xmm_dst4);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 3, xmm_dst6);
					src += 32;
					dst += 32;
				}
			}
		}

		template <>
		void cvtu32_sse41_large<unsigned short>(unsigned short* dst, const unsigned int* src, size_t n)
		{
			const size_t padding = 8 - (reinterpret_cast<size_t>(dst) & 7);
			const __m128i xmm_mask = _mm_set_epi64x(0xffffffffffffffffi64, 0x0d0c090805040100i64);
			__m128i xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128i xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3, xmm_dst4, xmm_dst5, xmm_dst6, xmm_dst7;

			// Align the destination to a 16-byte boundary.
			xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
			xmm_dst0 = _mm_shuffle_epi8(xmm_src0, xmm_mask);
			xmm_dst1 = _mm_shuffle_epi8(xmm_src1, xmm_mask);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
			dst += padding;
			src += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			// If the source is aligned on a 16-byte boundary.
			if ((reinterpret_cast<size_t>(src) & 15) == 0)
			{
				for (; n >= 32; n -= 32)
				{
					xmm_src0 = _mm_load_si128(reinterpret_cast<const __m128i*>(src));
					xmm_src1 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 1);
					xmm_src2 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 2);
					xmm_src3 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 3);
					xmm_src4 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 4);
					xmm_src5 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 5);
					xmm_src6 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 6);
					xmm_src7 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 7);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					xmm_dst0 = _mm_shuffle_epi8(xmm_src0, xmm_mask);
					xmm_dst1 = _mm_shuffle_epi8(xmm_src1, xmm_mask);
					xmm_dst2 = _mm_shuffle_epi8(xmm_src2, xmm_mask);
					xmm_dst3 = _mm_shuffle_epi8(xmm_src3, xmm_mask);
					xmm_dst4 = _mm_shuffle_epi8(xmm_src4, xmm_mask);
					xmm_dst5 = _mm_shuffle_epi8(xmm_src5, xmm_mask);
					xmm_dst6 = _mm_shuffle_epi8(xmm_src6, xmm_mask);
					xmm_dst7 = _mm_shuffle_epi8(xmm_src7, xmm_mask);
					xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
					xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
					xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
					xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst2);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 2, xmm_dst4);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 3, xmm_dst6);
					src += 32;
					dst += 32;
				}
			}
			else
			{
				for (; n >= 32; n -= 32)
				{
					xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
					xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
					xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
					xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
					xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
					xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
					xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
					xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					xmm_dst0 = _mm_shuffle_epi8(xmm_src0, xmm_mask);
					xmm_dst1 = _mm_shuffle_epi8(xmm_src1, xmm_mask);
					xmm_dst2 = _mm_shuffle_epi8(xmm_src2, xmm_mask);
					xmm_dst3 = _mm_shuffle_epi8(xmm_src3, xmm_mask);
					xmm_dst4 = _mm_shuffle_epi8(xmm_src4, xmm_mask);
					xmm_dst5 = _mm_shuffle_epi8(xmm_src5, xmm_mask);
					xmm_dst6 = _mm_shuffle_epi8(xmm_src6, xmm_mask);
					xmm_dst7 = _mm_shuffle_epi8(xmm_src7, xmm_mask);
					xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
					xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
					xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
					xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst2);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 2, xmm_dst4);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 3, xmm_dst6);
					src += 32;
					dst += 32;
				}
			}
		}

		template <>
		void cvtu32_sse41_large<float>(float* dst, const unsigned int* src, size_t n)
		{
			const size_t padding = 4 - (reinterpret_cast<size_t>(dst) & 3);
			const __m128 xmm_zero = _mm_setzero_ps();
			const __m128 xmm_max = _mm_castsi128_ps(_mm_set1_epi32(0x4f800000));
			__m128i xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128 xmm_tmp0, xmm_tmp1, xmm_tmp2, xmm_tmp3, xmm_tmp4, xmm_tmp5, xmm_tmp6, xmm_tmp7;
			__m128 xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3, xmm_dst4, xmm_dst5, xmm_dst6, xmm_dst7;

			// Align the destination to a 16-byte boundary.
			xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
			xmm_dst0 = _mm_cvtepi32_ps(xmm_src0);
			xmm_tmp0 = _mm_cmplt_ps(xmm_dst0, xmm_zero);
			xmm_tmp0 = _mm_and_ps(xmm_tmp0, xmm_max);
			xmm_dst0 = _mm_add_ps(xmm_dst0, xmm_tmp0);
			_mm_storeu_ps(dst, xmm_dst0);
			dst += padding;
			src += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			// If the source is aligned on a 16-byte boundary.
			if ((reinterpret_cast<size_t>(src) & 15) == 0)
			{
				for (; n >= 32; n -= 32)
				{
					xmm_src0 = _mm_load_si128(reinterpret_cast<const __m128i*>(src));
					xmm_src1 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 1);
					xmm_src2 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 2);
					xmm_src3 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 3);
					xmm_src4 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 4);
					xmm_src5 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 5);
					xmm_src6 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 6);
					xmm_src7 = _mm_load_si128(reinterpret_cast<const __m128i*>(src) + 7);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					xmm_dst0 = _mm_cvtepi32_ps(xmm_src0);
					xmm_dst1 = _mm_cvtepi32_ps(xmm_src1);
					xmm_dst2 = _mm_cvtepi32_ps(xmm_src2);
					xmm_dst3 = _mm_cvtepi32_ps(xmm_src3);
					xmm_dst4 = _mm_cvtepi32_ps(xmm_src4);
					xmm_dst5 = _mm_cvtepi32_ps(xmm_src5);
					xmm_dst6 = _mm_cvtepi32_ps(xmm_src6);
					xmm_dst7 = _mm_cvtepi32_ps(xmm_src7);
					xmm_tmp0 = _mm_cmplt_ps(xmm_dst0, xmm_zero);
					xmm_tmp1 = _mm_cmplt_ps(xmm_dst1, xmm_zero);
					xmm_tmp2 = _mm_cmplt_ps(xmm_dst2, xmm_zero);
					xmm_tmp3 = _mm_cmplt_ps(xmm_dst3, xmm_zero);
					xmm_tmp4 = _mm_cmplt_ps(xmm_dst4, xmm_zero);
					xmm_tmp5 = _mm_cmplt_ps(xmm_dst5, xmm_zero);
					xmm_tmp6 = _mm_cmplt_ps(xmm_dst6, xmm_zero);
					xmm_tmp7 = _mm_cmplt_ps(xmm_dst7, xmm_zero);
					xmm_tmp0 = _mm_and_ps(xmm_tmp0, xmm_max);
					xmm_tmp1 = _mm_and_ps(xmm_tmp1, xmm_max);
					xmm_tmp2 = _mm_and_ps(xmm_tmp2, xmm_max);
					xmm_tmp3 = _mm_and_ps(xmm_tmp3, xmm_max);
					xmm_tmp4 = _mm_and_ps(xmm_tmp4, xmm_max);
					xmm_tmp5 = _mm_and_ps(xmm_tmp5, xmm_max);
					xmm_tmp6 = _mm_and_ps(xmm_tmp6, xmm_max);
					xmm_tmp7 = _mm_and_ps(xmm_tmp7, xmm_max);
					xmm_dst0 = _mm_add_ps(xmm_dst0, xmm_tmp0);
					xmm_dst1 = _mm_add_ps(xmm_dst1, xmm_tmp1);
					xmm_dst2 = _mm_add_ps(xmm_dst2, xmm_tmp2);
					xmm_dst3 = _mm_add_ps(xmm_dst3, xmm_tmp3);
					xmm_dst4 = _mm_add_ps(xmm_dst4, xmm_tmp4);
					xmm_dst5 = _mm_add_ps(xmm_dst5, xmm_tmp5);
					xmm_dst6 = _mm_add_ps(xmm_dst6, xmm_tmp6);
					xmm_dst7 = _mm_add_ps(xmm_dst7, xmm_tmp7);
					_mm_stream_ps(dst, xmm_dst0);
					_mm_stream_ps(dst + 4, xmm_dst1);
					_mm_stream_ps(dst + 8, xmm_dst2);
					_mm_stream_ps(dst + 12, xmm_dst3);
					_mm_stream_ps(dst + 16, xmm_dst4);
					_mm_stream_ps(dst + 20, xmm_dst5);
					_mm_stream_ps(dst + 24, xmm_dst6);
					_mm_stream_ps(dst + 28, xmm_dst7);
					src += 32;
					dst += 32;
				}
			}
			else
			{
				for (; n >= 32; n -= 32)
				{
					xmm_src0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src));
					xmm_src1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 1);
					xmm_src2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 2);
					xmm_src3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 3);
					xmm_src4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 4);
					xmm_src5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 5);
					xmm_src6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 6);
					xmm_src7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src) + 7);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					xmm_dst0 = _mm_cvtepi32_ps(xmm_src0);
					xmm_dst1 = _mm_cvtepi32_ps(xmm_src1);
					xmm_dst2 = _mm_cvtepi32_ps(xmm_src2);
					xmm_dst3 = _mm_cvtepi32_ps(xmm_src3);
					xmm_dst4 = _mm_cvtepi32_ps(xmm_src4);
					xmm_dst5 = _mm_cvtepi32_ps(xmm_src5);
					xmm_dst6 = _mm_cvtepi32_ps(xmm_src6);
					xmm_dst7 = _mm_cvtepi32_ps(xmm_src7);
					xmm_tmp0 = _mm_cmplt_ps(xmm_dst0, xmm_zero);
					xmm_tmp1 = _mm_cmplt_ps(xmm_dst1, xmm_zero);
					xmm_tmp2 = _mm_cmplt_ps(xmm_dst2, xmm_zero);
					xmm_tmp3 = _mm_cmplt_ps(xmm_dst3, xmm_zero);
					xmm_tmp4 = _mm_cmplt_ps(xmm_dst4, xmm_zero);
					xmm_tmp5 = _mm_cmplt_ps(xmm_dst5, xmm_zero);
					xmm_tmp6 = _mm_cmplt_ps(xmm_dst6, xmm_zero);
					xmm_tmp7 = _mm_cmplt_ps(xmm_dst7, xmm_zero);
					xmm_tmp0 = _mm_and_ps(xmm_tmp0, xmm_max);
					xmm_tmp1 = _mm_and_ps(xmm_tmp1, xmm_max);
					xmm_tmp2 = _mm_and_ps(xmm_tmp2, xmm_max);
					xmm_tmp3 = _mm_and_ps(xmm_tmp3, xmm_max);
					xmm_tmp4 = _mm_and_ps(xmm_tmp4, xmm_max);
					xmm_tmp5 = _mm_and_ps(xmm_tmp5, xmm_max);
					xmm_tmp6 = _mm_and_ps(xmm_tmp6, xmm_max);
					xmm_tmp7 = _mm_and_ps(xmm_tmp7, xmm_max);
					xmm_dst0 = _mm_add_ps(xmm_dst0, xmm_tmp0);
					xmm_dst1 = _mm_add_ps(xmm_dst1, xmm_tmp1);
					xmm_dst2 = _mm_add_ps(xmm_dst2, xmm_tmp2);
					xmm_dst3 = _mm_add_ps(xmm_dst3, xmm_tmp3);
					xmm_dst4 = _mm_add_ps(xmm_dst4, xmm_tmp4);
					xmm_dst5 = _mm_add_ps(xmm_dst5, xmm_tmp5);
					xmm_dst6 = _mm_add_ps(xmm_dst6, xmm_tmp6);
					xmm_dst7 = _mm_add_ps(xmm_dst7, xmm_tmp7);
					_mm_stream_ps(dst, xmm_dst0);
					_mm_stream_ps(dst + 4, xmm_dst1);
					_mm_stream_ps(dst + 8, xmm_dst2);
					_mm_stream_ps(dst + 12, xmm_dst3);
					_mm_stream_ps(dst + 16, xmm_dst4);
					_mm_stream_ps(dst + 20, xmm_dst5);
					_mm_stream_ps(dst + 24, xmm_dst6);
					_mm_stream_ps(dst + 28, xmm_dst7);
					src += 32;
					dst += 32;
				}
			}
		}

		template <>
		void cvtu32_sse41_large<double>(double* dst, const unsigned int* src, size_t n)
		{
			const size_t padding = 2 - (reinterpret_cast<size_t>(dst) & 1);
			const __m128d xmm_zero = _mm_setzero_pd();
			const __m128d xmm_max = _mm_castsi128_pd(_mm_set1_epi64x(0x41f0000000000000));
			__m128i xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128i xmm_src8, xmm_src9, xmm_srca, xmm_srcb, xmm_srcc, xmm_srcd, xmm_srce, xmm_srcf;
			__m128d xmm_tmp0, xmm_tmp1, xmm_tmp2, xmm_tmp3, xmm_tmp4, xmm_tmp5, xmm_tmp6, xmm_tmp7;
			__m128d xmm_tmp8, xmm_tmp9, xmm_tmpa, xmm_tmpb, xmm_tmpc, xmm_tmpd, xmm_tmpe, xmm_tmpf;
			__m128d xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3, xmm_dst4, xmm_dst5, xmm_dst6, xmm_dst7;
			__m128d xmm_dst8, xmm_dst9, xmm_dsta, xmm_dstb, xmm_dstc, xmm_dstd, xmm_dste, xmm_dstf;

			// Align the destination to a 16-byte boundary.
			xmm_src0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src));
			xmm_dst0 = _mm_cvtepi32_pd(xmm_src0);
			xmm_tmp0 = _mm_cmplt_pd(xmm_dst0, xmm_zero);
			xmm_tmp0 = _mm_and_pd(xmm_tmp0, xmm_max);
			xmm_dst0 = _mm_add_pd(xmm_dst0, xmm_tmp0);
			_mm_storeu_pd(dst, xmm_dst0);
			dst += padding;
			src += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				xmm_src0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src));
				xmm_src1 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 2));
				xmm_src2 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 4));
				xmm_src3 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 6));
				xmm_src4 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 8));
				xmm_src5 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 10));
				xmm_src6 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 12));
				xmm_src7 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 14));
				xmm_src8 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 16));
				xmm_src9 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 18));
				xmm_srca = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 20));
				xmm_srcb = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 22));
				xmm_srcc = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 24));
				xmm_srcd = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 26));
				xmm_srce = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 28));
				xmm_srcf = _mm_loadu_si64(reinterpret_cast<const __m128i*>(src + 30));
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
				xmm_dst0 = _mm_cvtepi32_pd(xmm_src0);
				xmm_dst1 = _mm_cvtepi32_pd(xmm_src1);
				xmm_dst2 = _mm_cvtepi32_pd(xmm_src2);
				xmm_dst3 = _mm_cvtepi32_pd(xmm_src3);
				xmm_dst4 = _mm_cvtepi32_pd(xmm_src4);
				xmm_dst5 = _mm_cvtepi32_pd(xmm_src5);
				xmm_dst6 = _mm_cvtepi32_pd(xmm_src6);
				xmm_dst7 = _mm_cvtepi32_pd(xmm_src7);
				xmm_dst8 = _mm_cvtepi32_pd(xmm_src8);
				xmm_dst9 = _mm_cvtepi32_pd(xmm_src9);
				xmm_dsta = _mm_cvtepi32_pd(xmm_srca);
				xmm_dstb = _mm_cvtepi32_pd(xmm_srcb);
				xmm_dstc = _mm_cvtepi32_pd(xmm_srcc);
				xmm_dstd = _mm_cvtepi32_pd(xmm_srcd);
				xmm_dste = _mm_cvtepi32_pd(xmm_srce);
				xmm_dstf = _mm_cvtepi32_pd(xmm_srcf);
				xmm_tmp0 = _mm_cmplt_pd(xmm_dst0, xmm_zero);
				xmm_tmp1 = _mm_cmplt_pd(xmm_dst1, xmm_zero);
				xmm_tmp2 = _mm_cmplt_pd(xmm_dst2, xmm_zero);
				xmm_tmp3 = _mm_cmplt_pd(xmm_dst3, xmm_zero);
				xmm_tmp4 = _mm_cmplt_pd(xmm_dst4, xmm_zero);
				xmm_tmp5 = _mm_cmplt_pd(xmm_dst5, xmm_zero);
				xmm_tmp6 = _mm_cmplt_pd(xmm_dst6, xmm_zero);
				xmm_tmp7 = _mm_cmplt_pd(xmm_dst7, xmm_zero);
				xmm_tmp8 = _mm_cmplt_pd(xmm_dst8, xmm_zero);
				xmm_tmp9 = _mm_cmplt_pd(xmm_dst9, xmm_zero);
				xmm_tmpa = _mm_cmplt_pd(xmm_dsta, xmm_zero);
				xmm_tmpb = _mm_cmplt_pd(xmm_dstb, xmm_zero);
				xmm_tmpc = _mm_cmplt_pd(xmm_dstc, xmm_zero);
				xmm_tmpd = _mm_cmplt_pd(xmm_dstd, xmm_zero);
				xmm_tmpe = _mm_cmplt_pd(xmm_dste, xmm_zero);
				xmm_tmpf = _mm_cmplt_pd(xmm_dstf, xmm_zero);
				xmm_tmp0 = _mm_and_pd(xmm_tmp0, xmm_max);
				xmm_tmp1 = _mm_and_pd(xmm_tmp1, xmm_max);
				xmm_tmp2 = _mm_and_pd(xmm_tmp2, xmm_max);
				xmm_tmp3 = _mm_and_pd(xmm_tmp3, xmm_max);
				xmm_tmp4 = _mm_and_pd(xmm_tmp4, xmm_max);
				xmm_tmp5 = _mm_and_pd(xmm_tmp5, xmm_max);
				xmm_tmp6 = _mm_and_pd(xmm_tmp6, xmm_max);
				xmm_tmp7 = _mm_and_pd(xmm_tmp7, xmm_max);
				xmm_tmp8 = _mm_and_pd(xmm_tmp8, xmm_max);
				xmm_tmp9 = _mm_and_pd(xmm_tmp9, xmm_max);
				xmm_tmpa = _mm_and_pd(xmm_tmpa, xmm_max);
				xmm_tmpb = _mm_and_pd(xmm_tmpb, xmm_max);
				xmm_tmpc = _mm_and_pd(xmm_tmpc, xmm_max);
				xmm_tmpd = _mm_and_pd(xmm_tmpd, xmm_max);
				xmm_tmpe = _mm_and_pd(xmm_tmpe, xmm_max);
				xmm_tmpf = _mm_and_pd(xmm_tmpf, xmm_max);
				xmm_dst0 = _mm_add_pd(xmm_dst0, xmm_tmp0);
				xmm_dst1 = _mm_add_pd(xmm_dst1, xmm_tmp1);
				xmm_dst2 = _mm_add_pd(xmm_dst2, xmm_tmp2);
				xmm_dst3 = _mm_add_pd(xmm_dst3, xmm_tmp3);
				xmm_dst4 = _mm_add_pd(xmm_dst4, xmm_tmp4);
				xmm_dst5 = _mm_add_pd(xmm_dst5, xmm_tmp5);
				xmm_dst6 = _mm_add_pd(xmm_dst6, xmm_tmp6);
				xmm_dst7 = _mm_add_pd(xmm_dst7, xmm_tmp7);
				xmm_dst8 = _mm_add_pd(xmm_dst8, xmm_tmp8);
				xmm_dst9 = _mm_add_pd(xmm_dst9, xmm_tmp9);
				xmm_dsta = _mm_add_pd(xmm_dsta, xmm_tmpa);
				xmm_dstb = _mm_add_pd(xmm_dstb, xmm_tmpb);
				xmm_dstc = _mm_add_pd(xmm_dstc, xmm_tmpc);
				xmm_dstd = _mm_add_pd(xmm_dstd, xmm_tmpd);
				xmm_dste = _mm_add_pd(xmm_dste, xmm_tmpe);
				xmm_dstf = _mm_add_pd(xmm_dstf, xmm_tmpf);
				_mm_stream_pd(dst, xmm_dst0);
				_mm_stream_pd(dst + 2, xmm_dst1);
				_mm_stream_pd(dst + 4, xmm_dst2);
				_mm_stream_pd(dst + 6, xmm_dst3);
				_mm_stream_pd(dst + 8, xmm_dst4);
				_mm_stream_pd(dst + 10, xmm_dst5);
				_mm_stream_pd(dst + 12, xmm_dst6);
				_mm_stream_pd(dst + 14, xmm_dst7);
				_mm_stream_pd(dst + 16, xmm_dst8);
				_mm_stream_pd(dst + 18, xmm_dst9);
				_mm_stream_pd(dst + 20, xmm_dsta);
				_mm_stream_pd(dst + 22, xmm_dstb);
				_mm_stream_pd(dst + 24, xmm_dstc);
				_mm_stream_pd(dst + 26, xmm_dstd);
				_mm_stream_pd(dst + 28, xmm_dste);
				_mm_stream_pd(dst + 30, xmm_dstf);
				src += 32;
				dst += 32;
			}
		}

		// Function template impl_cvtu32

		template <class T>
		inline void impl_cvtu32(T* dst, const unsigned int* src, size_t n)
		{
			constexpr size_t threshold = simd::l2_cache_size / sizeof(unsigned int);
			// Small amount of data type conversion.
			if (n < 64)
				cvtu32_sse41_small(dst, src, n);
			// Medium amount data type conversion.
			else if (n < threshold)
				cvtu32_sse41_medium(dst, src, n);
			// Large amount data type conversion.
			else
				cvtu32_sse41_large(dst, src, n);
			// Small amount of data type conversion.
			cvtu32_sse41_small(dst, src, n & 127);
		}

	#else

		// Function template impl_cvtu32

		template <class T>
		void impl_cvtu32(T* dst, const unsigned int* src, size_t n)
		{
			constexpr size_t block = 8;
			while (n >= block)
			{
				dst[0] = static_cast<T>(src[0]);
				dst[1] = static_cast<T>(src[1]);
				dst[2] = static_cast<T>(src[2]);
				dst[3] = static_cast<T>(src[3]);
				dst[4] = static_cast<T>(src[4]);
				dst[5] = static_cast<T>(src[5]);
				dst[6] = static_cast<T>(src[6]);
				dst[7] = static_cast<T>(src[7]);
				src += block;
				dst += block;
				n -= block;
			}
			switch (n)
			{
			case 7: dst[6] = static_cast<T>(src[6]);
			case 6: dst[5] = static_cast<T>(src[5]);
			case 5: dst[4] = static_cast<T>(src[4]);
			case 4: dst[3] = static_cast<T>(src[3]);
			case 3: dst[2] = static_cast<T>(src[2]);
			case 2: dst[1] = static_cast<T>(src[1]);
			case 1: dst[0] = static_cast<T>(src[0]);
				break;
			}
		}

	#endif

		template <>
		void impl_cvtu32<signed int>(signed int* dst, const unsigned int* src, size_t n)
		{
			std::memcpy(dst, src, n * sizeof(unsigned int));
		}

		template <>
		void impl_cvtu32<unsigned int>(unsigned int* dst, const unsigned int* src, size_t n)
		{
			std::memcpy(dst, src, n * sizeof(unsigned int));
		}

	} // namespace cpu

} // namespace core

#endif
