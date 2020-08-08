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

#ifndef __CORE_CPU_CVTSPD_H__
#define __CORE_CPU_CVTSPD_H__

#include <cstddef>
#include <cstdint>
#include <cstring>
#include "../simd.h"

namespace core
{
	namespace cpu
	{
		template<class T>
		inline void cvtspd_tiny(T* dst, const double* src, size_t n)
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

		template<>
		inline void cvtspd_tiny<signed char>(signed char* dst, const double* src, size_t n)
		{
			constexpr double min = static_cast<double>(INT8_MIN);
			constexpr double max = static_cast<double>(INT8_MAX);
			switch (n)
			{
			case 7: dst[6] = src[6] < min ? INT8_MIN : src[6] > max ? INT8_MAX : static_cast<signed char>(src[6]);
			case 6: dst[5] = src[5] < min ? INT8_MIN : src[5] > max ? INT8_MAX : static_cast<signed char>(src[5]);
			case 5: dst[4] = src[4] < min ? INT8_MIN : src[4] > max ? INT8_MAX : static_cast<signed char>(src[4]);
			case 4: dst[3] = src[3] < min ? INT8_MIN : src[3] > max ? INT8_MAX : static_cast<signed char>(src[3]);
			case 3: dst[2] = src[2] < min ? INT8_MIN : src[2] > max ? INT8_MAX : static_cast<signed char>(src[2]);
			case 2: dst[1] = src[1] < min ? INT8_MIN : src[1] > max ? INT8_MAX : static_cast<signed char>(src[1]);
			case 1: dst[0] = src[0] < min ? INT8_MIN : src[0] > max ? INT8_MAX : static_cast<signed char>(src[0]);
				break;
			}
		}

		template<>
		inline void cvtspd_tiny<unsigned char>(unsigned char* dst, const double* src, size_t n)
		{
			constexpr double max = static_cast<double>(UINT8_MAX);
			switch (n)
			{
			case 7: dst[6] = src[6] < 0 ? 0 : src[6] > max ? UINT8_MAX : static_cast<unsigned char>(src[6]);
			case 6: dst[5] = src[5] < 0 ? 0 : src[5] > max ? UINT8_MAX : static_cast<unsigned char>(src[5]);
			case 5: dst[4] = src[4] < 0 ? 0 : src[4] > max ? UINT8_MAX : static_cast<unsigned char>(src[4]);
			case 4: dst[3] = src[3] < 0 ? 0 : src[3] > max ? UINT8_MAX : static_cast<unsigned char>(src[3]);
			case 3: dst[2] = src[2] < 0 ? 0 : src[2] > max ? UINT8_MAX : static_cast<unsigned char>(src[2]);
			case 2: dst[1] = src[1] < 0 ? 0 : src[1] > max ? UINT8_MAX : static_cast<unsigned char>(src[1]);
			case 1: dst[0] = src[0] < 0 ? 0 : src[0] > max ? UINT8_MAX : static_cast<unsigned char>(src[0]);
				break;
			}
		}

		template<>
		inline void cvtspd_tiny<signed short>(signed short* dst, const double* src, size_t n)
		{
			constexpr double min = static_cast<double>(INT16_MIN);
			constexpr double max = static_cast<double>(INT16_MAX);
			switch (n)
			{
			case 7: dst[6] = src[6] < min ? INT16_MIN : src[6] > max ? INT16_MAX : static_cast<signed short>(src[6]);
			case 6: dst[5] = src[5] < min ? INT16_MIN : src[5] > max ? INT16_MAX : static_cast<signed short>(src[5]);
			case 5: dst[4] = src[4] < min ? INT16_MIN : src[4] > max ? INT16_MAX : static_cast<signed short>(src[4]);
			case 4: dst[3] = src[3] < min ? INT16_MIN : src[3] > max ? INT16_MAX : static_cast<signed short>(src[3]);
			case 3: dst[2] = src[2] < min ? INT16_MIN : src[2] > max ? INT16_MAX : static_cast<signed short>(src[2]);
			case 2: dst[1] = src[1] < min ? INT16_MIN : src[1] > max ? INT16_MAX : static_cast<signed short>(src[1]);
			case 1: dst[0] = src[0] < min ? INT16_MIN : src[0] > max ? INT16_MAX : static_cast<signed short>(src[0]);
				break;
			}
		}

		template<>
		inline void cvtspd_tiny<unsigned short>(unsigned short* dst, const double* src, size_t n)
		{
			constexpr double max = static_cast<double>(UINT16_MAX);
			switch (n)
			{
			case 7: dst[6] = src[6] < 0 ? 0 : src[6] > max ? UINT16_MAX : static_cast<unsigned short>(src[6]);
			case 6: dst[5] = src[5] < 0 ? 0 : src[5] > max ? UINT16_MAX : static_cast<unsigned short>(src[5]);
			case 5: dst[4] = src[4] < 0 ? 0 : src[4] > max ? UINT16_MAX : static_cast<unsigned short>(src[4]);
			case 4: dst[3] = src[3] < 0 ? 0 : src[3] > max ? UINT16_MAX : static_cast<unsigned short>(src[3]);
			case 3: dst[2] = src[2] < 0 ? 0 : src[2] > max ? UINT16_MAX : static_cast<unsigned short>(src[2]);
			case 2: dst[1] = src[1] < 0 ? 0 : src[1] > max ? UINT16_MAX : static_cast<unsigned short>(src[1]);
			case 1: dst[0] = src[0] < 0 ? 0 : src[0] > max ? UINT16_MAX : static_cast<unsigned short>(src[0]);
				break;
			}
		}

		template<>
		inline void cvtspd_tiny<signed int>(signed int* dst, const double* src, size_t n)
		{
			constexpr double min = static_cast<double>(INT32_MIN);
			constexpr double max = static_cast<double>(INT32_MAX);
			switch (n)
			{
			case 7: dst[6] = src[6] < min ? INT32_MIN : src[6] > max ? INT32_MAX : static_cast<signed int>(src[6]);
			case 6: dst[5] = src[5] < min ? INT32_MIN : src[5] > max ? INT32_MAX : static_cast<signed int>(src[5]);
			case 5: dst[4] = src[4] < min ? INT32_MIN : src[4] > max ? INT32_MAX : static_cast<signed int>(src[4]);
			case 4: dst[3] = src[3] < min ? INT32_MIN : src[3] > max ? INT32_MAX : static_cast<signed int>(src[3]);
			case 3: dst[2] = src[2] < min ? INT32_MIN : src[2] > max ? INT32_MAX : static_cast<signed int>(src[2]);
			case 2: dst[1] = src[1] < min ? INT32_MIN : src[1] > max ? INT32_MAX : static_cast<signed int>(src[1]);
			case 1: dst[0] = src[0] < min ? INT32_MIN : src[0] > max ? INT32_MAX : static_cast<signed int>(src[0]);
				break;
			}
		}

		template<>
		inline void cvtspd_tiny<unsigned int>(unsigned int* dst, const double* src, size_t n)
		{
			constexpr double max = static_cast<double>(UINT32_MAX);
			switch (n)
			{
			case 7: dst[6] = src[6] < 0 ? 0 : src[6] > max ? UINT32_MAX : static_cast<unsigned int>(src[6]);
			case 6: dst[5] = src[5] < 0 ? 0 : src[5] > max ? UINT32_MAX : static_cast<unsigned int>(src[5]);
			case 5: dst[4] = src[4] < 0 ? 0 : src[4] > max ? UINT32_MAX : static_cast<unsigned int>(src[4]);
			case 4: dst[3] = src[3] < 0 ? 0 : src[3] > max ? UINT32_MAX : static_cast<unsigned int>(src[3]);
			case 3: dst[2] = src[2] < 0 ? 0 : src[2] > max ? UINT32_MAX : static_cast<unsigned int>(src[2]);
			case 2: dst[1] = src[1] < 0 ? 0 : src[1] > max ? UINT32_MAX : static_cast<unsigned int>(src[1]);
			case 1: dst[0] = src[0] < 0 ? 0 : src[0] > max ? UINT32_MAX : static_cast<unsigned int>(src[0]);
				break;
			}
		}

	#ifdef __AVX2__

		// Function template cvtspd_avx2_8

		template <class T>
		inline void cvtspd_avx2_8(T* dst, const double* src)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		inline void cvtspd_avx2_8<signed char>(signed char* dst, const double* src)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT8_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT8_MAX));
			__m256d ymm_src0 = _mm256_loadu_pd(src);
			__m256d ymm_src1 = _mm256_loadu_pd(src + 4);
			ymm_src0 = _mm256_max_pd(ymm_src0, min);
			ymm_src1 = _mm256_max_pd(ymm_src1, min);
			ymm_src0 = _mm256_min_pd(ymm_src0, max);
			ymm_src1 = _mm256_min_pd(ymm_src1, max);
			__m256i ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
			__m256i ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
			ymm_dst0 = _mm256_packs_epi32(ymm_dst0, ymm_dst1);
			ymm_dst0 = _mm256_packs_epi16(ymm_dst0, _mm256_setzero_si256());
			_mm_storeu_si64(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
		}

		template <>
		inline void cvtspd_avx2_8<unsigned char>(unsigned char* dst, const double* src)
		{
			const __m256d min = _mm256_setzero_pd();
			const __m256d max = _mm256_set1_pd(static_cast<double>(UINT8_MAX));
			__m256d ymm_src0 = _mm256_loadu_pd(src);
			__m256d ymm_src1 = _mm256_loadu_pd(src + 4);
			ymm_src0 = _mm256_max_pd(ymm_src0, min);
			ymm_src1 = _mm256_max_pd(ymm_src1, min);
			ymm_src0 = _mm256_min_pd(ymm_src0, max);
			ymm_src1 = _mm256_min_pd(ymm_src1, max);
			__m256i ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
			__m256i ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
			ymm_dst0 = _mm256_packus_epi32(ymm_dst0, ymm_dst1);
			ymm_dst0 = _mm256_packus_epi16(ymm_dst0, _mm256_setzero_si256());
			_mm_storeu_si64(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
		}

		template <>
		inline void cvtspd_avx2_8<signed short>(signed short* dst, const double* src)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT16_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT16_MAX));
			__m256d ymm_src0 = _mm256_loadu_pd(src);
			__m256d ymm_src1 = _mm256_loadu_pd(src + 4);
			ymm_src0 = _mm256_max_pd(ymm_src0, min);
			ymm_src1 = _mm256_max_pd(ymm_src1, min);
			ymm_src0 = _mm256_min_pd(ymm_src0, max);
			ymm_src1 = _mm256_min_pd(ymm_src1, max);
			__m256i ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
			__m256i ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
			ymm_dst0 = _mm256_packs_epi32(ymm_dst0, ymm_dst1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
		}

		template <>
		inline void cvtspd_avx2_8<unsigned short>(unsigned short* dst, const double* src)
		{
			const __m256d min = _mm256_setzero_pd();
			const __m256d max = _mm256_set1_pd(static_cast<double>(UINT16_MAX));
			__m256d ymm_src0 = _mm256_loadu_pd(src);
			__m256d ymm_src1 = _mm256_loadu_pd(src + 4);
			ymm_src0 = _mm256_max_pd(ymm_src0, min);
			ymm_src1 = _mm256_max_pd(ymm_src1, min);
			ymm_src0 = _mm256_min_pd(ymm_src0, max);
			ymm_src1 = _mm256_min_pd(ymm_src1, max);
			__m256i ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
			__m256i ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
			ymm_dst0 = _mm256_packus_epi32(ymm_dst0, ymm_dst1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
		}

		template <>
		inline void cvtspd_avx2_8<signed int>(signed int* dst, const double* src)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT32_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT32_MAX));
			__m256d ymm_src0 = _mm256_loadu_pd(src);
			__m256d ymm_src1 = _mm256_loadu_pd(src + 4);
			ymm_src0 = _mm256_max_pd(ymm_src0, min);
			ymm_src1 = _mm256_max_pd(ymm_src1, min);
			ymm_src0 = _mm256_min_pd(ymm_src0, max);
			ymm_src1 = _mm256_min_pd(ymm_src1, max);
			__m128i xmm_dst0 = _mm256_cvttpd_epi32(ymm_src0);
			__m128i xmm_dst1 = _mm256_cvttpd_epi32(ymm_src1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst1);
		}

		template <>
		inline void cvtspd_avx2_8<unsigned int>(unsigned int* dst, const double* src)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT32_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT32_MAX));
			const __m256d offset = _mm256_set1_pd(2.147483648e+9);
			const __m256i shift = _mm256_set1_epi32(2147483648);
			__m256d ymm_src0 = _mm256_loadu_pd(src);
			__m256d ymm_src1 = _mm256_loadu_pd(src + 4);
			ymm_src0 = _mm256_sub_pd(ymm_src0, offset);
			ymm_src1 = _mm256_sub_pd(ymm_src1, offset);
			ymm_src0 = _mm256_max_pd(ymm_src0, min);
			ymm_src1 = _mm256_max_pd(ymm_src1, min);
			ymm_src0 = _mm256_min_pd(ymm_src0, max);
			ymm_src1 = _mm256_min_pd(ymm_src1, max);
			__m256i ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
			__m256i ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
			ymm_dst0 = _mm256_add_epi32(ymm_dst0, shift);
			ymm_dst1 = _mm256_add_epi32(ymm_dst1, shift);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, _mm256_castsi256_si128(ymm_dst1));
		}

		template <>
		inline void cvtspd_avx2_8<float>(float* dst, const double* src)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(-FLT_MAX));
			const __m256d max = _mm256_set1_pd(static_cast<double>(FLT_MAX));
			__m256d ymm_src0 = _mm256_loadu_pd(src);
			__m256d ymm_src1 = _mm256_loadu_pd(src + 4);
			ymm_src0 = _mm256_max_pd(ymm_src0, min);
			ymm_src1 = _mm256_max_pd(ymm_src1, min);
			ymm_src0 = _mm256_min_pd(ymm_src0, max);
			ymm_src1 = _mm256_min_pd(ymm_src1, max);
			__m128 xmm_dst0 = _mm256_cvtpd_ps(ymm_src0);
			__m128 xmm_dst1 = _mm256_cvtpd_ps(ymm_src1);
			_mm_storeu_ps(dst, xmm_dst0);
			_mm_storeu_ps(dst + 4, xmm_dst1);
		}

		// Function template cvtspd_avx2_16

		template <class T>
		inline void cvtspd_avx2_16(T* dst, const double* src)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		inline void cvtspd_avx2_16<signed char>(signed char* dst, const double* src)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT8_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT8_MAX));
			__m256d ymm_src0 = _mm256_loadu_pd(src);
			__m256d ymm_src1 = _mm256_loadu_pd(src + 4);
			__m256d ymm_src2 = _mm256_loadu_pd(src + 8);
			__m256d ymm_src3 = _mm256_loadu_pd(src + 12);
			ymm_src0 = _mm256_max_pd(ymm_src0, min);
			ymm_src1 = _mm256_max_pd(ymm_src1, min);
			ymm_src2 = _mm256_max_pd(ymm_src2, min);
			ymm_src3 = _mm256_max_pd(ymm_src3, min);
			ymm_src0 = _mm256_min_pd(ymm_src0, max);
			ymm_src1 = _mm256_min_pd(ymm_src1, max);
			ymm_src2 = _mm256_min_pd(ymm_src2, max);
			ymm_src3 = _mm256_min_pd(ymm_src3, max);
			__m256i ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
			__m256i ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
			__m256i ymm_dst2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src2));
			__m256i ymm_dst3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src3));
			ymm_dst0 = _mm256_packs_epi32(ymm_dst0, ymm_dst1);
			ymm_dst2 = _mm256_packs_epi32(ymm_dst2, ymm_dst3);
			ymm_dst0 = _mm256_packs_epi16(ymm_dst0, ymm_dst2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
		}

		template <>
		inline void cvtspd_avx2_16<unsigned char>(unsigned char* dst, const double* src)
		{
			const __m256d min = _mm256_setzero_pd();
			const __m256d max = _mm256_set1_pd(static_cast<double>(UINT8_MAX));
			__m256d ymm_src0 = _mm256_loadu_pd(src);
			__m256d ymm_src1 = _mm256_loadu_pd(src + 4);
			__m256d ymm_src2 = _mm256_loadu_pd(src + 8);
			__m256d ymm_src3 = _mm256_loadu_pd(src + 12);
			ymm_src0 = _mm256_max_pd(ymm_src0, min);
			ymm_src1 = _mm256_max_pd(ymm_src1, min);
			ymm_src2 = _mm256_max_pd(ymm_src2, min);
			ymm_src3 = _mm256_max_pd(ymm_src3, min);
			ymm_src0 = _mm256_min_pd(ymm_src0, max);
			ymm_src1 = _mm256_min_pd(ymm_src1, max);
			ymm_src2 = _mm256_min_pd(ymm_src2, max);
			ymm_src3 = _mm256_min_pd(ymm_src3, max);
			__m256i ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
			__m256i ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
			__m256i ymm_dst2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src2));
			__m256i ymm_dst3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src3));
			ymm_dst0 = _mm256_packus_epi32(ymm_dst0, ymm_dst1);
			ymm_dst2 = _mm256_packus_epi32(ymm_dst2, ymm_dst3);
			ymm_dst0 = _mm256_packus_epi16(ymm_dst0, ymm_dst2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
		}

		template <>
		inline void cvtspd_avx2_16<signed short>(signed short* dst, const double* src)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT16_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT16_MAX));
			__m256d ymm_src0 = _mm256_loadu_pd(src);
			__m256d ymm_src1 = _mm256_loadu_pd(src + 4);
			__m256d ymm_src2 = _mm256_loadu_pd(src + 8);
			__m256d ymm_src3 = _mm256_loadu_pd(src + 12);
			ymm_src0 = _mm256_max_pd(ymm_src0, min);
			ymm_src1 = _mm256_max_pd(ymm_src1, min);
			ymm_src2 = _mm256_max_pd(ymm_src2, min);
			ymm_src3 = _mm256_max_pd(ymm_src3, min);
			ymm_src0 = _mm256_min_pd(ymm_src0, max);
			ymm_src1 = _mm256_min_pd(ymm_src1, max);
			ymm_src2 = _mm256_min_pd(ymm_src2, max);
			ymm_src3 = _mm256_min_pd(ymm_src3, max);
			__m256i ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
			__m256i ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
			__m256i ymm_dst2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src2));
			__m256i ymm_dst3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src3));
			ymm_dst0 = _mm256_packs_epi32(ymm_dst0, ymm_dst1);
			ymm_dst2 = _mm256_packs_epi32(ymm_dst2, ymm_dst3);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, _mm256_castsi256_si128(ymm_dst2));
		}

		template <>
		inline void cvtspd_avx2_16<unsigned short>(unsigned short* dst, const double* src)
		{
			const __m256d min = _mm256_setzero_pd();
			const __m256d max = _mm256_set1_pd(static_cast<double>(UINT16_MAX));
			__m256d ymm_src0 = _mm256_loadu_pd(src);
			__m256d ymm_src1 = _mm256_loadu_pd(src + 4);
			__m256d ymm_src2 = _mm256_loadu_pd(src + 8);
			__m256d ymm_src3 = _mm256_loadu_pd(src + 12);
			ymm_src0 = _mm256_max_pd(ymm_src0, min);
			ymm_src1 = _mm256_max_pd(ymm_src1, min);
			ymm_src2 = _mm256_max_pd(ymm_src2, min);
			ymm_src3 = _mm256_max_pd(ymm_src3, min);
			ymm_src0 = _mm256_min_pd(ymm_src0, max);
			ymm_src1 = _mm256_min_pd(ymm_src1, max);
			ymm_src2 = _mm256_min_pd(ymm_src2, max);
			ymm_src3 = _mm256_min_pd(ymm_src3, max);
			__m256i ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
			__m256i ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
			__m256i ymm_dst2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src2));
			__m256i ymm_dst3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src3));
			ymm_dst0 = _mm256_packus_epi32(ymm_dst0, ymm_dst1);
			ymm_dst2 = _mm256_packus_epi32(ymm_dst2, ymm_dst3);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, _mm256_castsi256_si128(ymm_dst2));
		}

		template <>
		inline void cvtspd_avx2_16<signed int>(signed int* dst, const double* src)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT32_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT32_MAX));
			__m256d ymm_src0 = _mm256_loadu_pd(src);
			__m256d ymm_src1 = _mm256_loadu_pd(src + 4);
			__m256d ymm_src2 = _mm256_loadu_pd(src + 8);
			__m256d ymm_src3 = _mm256_loadu_pd(src + 12);
			ymm_src0 = _mm256_max_pd(ymm_src0, min);
			ymm_src1 = _mm256_max_pd(ymm_src1, min);
			ymm_src2 = _mm256_max_pd(ymm_src2, min);
			ymm_src3 = _mm256_max_pd(ymm_src3, min);
			ymm_src0 = _mm256_min_pd(ymm_src0, max);
			ymm_src1 = _mm256_min_pd(ymm_src1, max);
			ymm_src2 = _mm256_min_pd(ymm_src2, max);
			ymm_src3 = _mm256_min_pd(ymm_src3, max);
			__m128i xmm_dst0 = _mm256_cvttpd_epi32(ymm_src0);
			__m128i xmm_dst1 = _mm256_cvttpd_epi32(ymm_src1);
			__m128i xmm_dst2 = _mm256_cvttpd_epi32(ymm_src2);
			__m128i xmm_dst3 = _mm256_cvttpd_epi32(ymm_src3);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 2, xmm_dst2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 3, xmm_dst3);
		}

		template <>
		inline void cvtspd_avx2_16<unsigned int>(unsigned int* dst, const double* src)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT32_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT32_MAX));
			const __m256d offset = _mm256_set1_pd(2.147483648e+9);
			const __m256i shift = _mm256_set1_epi32(2147483648);
			__m256d ymm_src0 = _mm256_loadu_pd(src);
			__m256d ymm_src1 = _mm256_loadu_pd(src + 4);
			__m256d ymm_src2 = _mm256_loadu_pd(src + 8);
			__m256d ymm_src3 = _mm256_loadu_pd(src + 12);
			ymm_src0 = _mm256_sub_pd(ymm_src0, offset);
			ymm_src1 = _mm256_sub_pd(ymm_src1, offset);
			ymm_src2 = _mm256_sub_pd(ymm_src2, offset);
			ymm_src3 = _mm256_sub_pd(ymm_src3, offset);
			ymm_src0 = _mm256_max_pd(ymm_src0, min);
			ymm_src1 = _mm256_max_pd(ymm_src1, min);
			ymm_src2 = _mm256_max_pd(ymm_src2, min);
			ymm_src3 = _mm256_max_pd(ymm_src3, min);
			ymm_src0 = _mm256_min_pd(ymm_src0, max);
			ymm_src1 = _mm256_min_pd(ymm_src1, max);
			ymm_src2 = _mm256_min_pd(ymm_src2, max);
			ymm_src3 = _mm256_min_pd(ymm_src3, max);
			__m256i ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
			__m256i ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
			__m256i ymm_dst2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src2));
			__m256i ymm_dst3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src3));
			ymm_dst0 = _mm256_add_epi32(ymm_dst0, shift);
			ymm_dst1 = _mm256_add_epi32(ymm_dst1, shift);
			ymm_dst2 = _mm256_add_epi32(ymm_dst2, shift);
			ymm_dst3 = _mm256_add_epi32(ymm_dst3, shift);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, _mm256_castsi256_si128(ymm_dst1));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 2, _mm256_castsi256_si128(ymm_dst2));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 3, _mm256_castsi256_si128(ymm_dst3));
		}

		template <>
		inline void cvtspd_avx2_16<float>(float* dst, const double* src)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(-FLT_MAX));
			const __m256d max = _mm256_set1_pd(static_cast<double>(FLT_MAX));
			__m256d ymm_src0 = _mm256_loadu_pd(src);
			__m256d ymm_src1 = _mm256_loadu_pd(src + 4);
			__m256d ymm_src2 = _mm256_loadu_pd(src + 8);
			__m256d ymm_src3 = _mm256_loadu_pd(src + 12);
			ymm_src0 = _mm256_max_pd(ymm_src0, min);
			ymm_src1 = _mm256_max_pd(ymm_src1, min);
			ymm_src2 = _mm256_max_pd(ymm_src2, min);
			ymm_src3 = _mm256_max_pd(ymm_src3, min);
			ymm_src0 = _mm256_min_pd(ymm_src0, max);
			ymm_src1 = _mm256_min_pd(ymm_src1, max);
			ymm_src2 = _mm256_min_pd(ymm_src2, max);
			ymm_src3 = _mm256_min_pd(ymm_src3, max);
			__m128 xmm_dst0 = _mm256_cvtpd_ps(ymm_src0);
			__m128 xmm_dst1 = _mm256_cvtpd_ps(ymm_src1);
			__m128 xmm_dst2 = _mm256_cvtpd_ps(ymm_src2);
			__m128 xmm_dst3 = _mm256_cvtpd_ps(ymm_src3);
			_mm_storeu_ps(dst, xmm_dst0);
			_mm_storeu_ps(dst + 4, xmm_dst1);
			_mm_storeu_ps(dst + 8, xmm_dst2);
			_mm_storeu_ps(dst + 12, xmm_dst3);
		}

		// Function template cvtspd_avx2_32

		template <class T>
		inline void cvtspd_avx2_32(T* dst, const double* src)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		inline void cvtspd_avx2_32<signed char>(signed char* dst, const double* src)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT8_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT8_MAX));
			__m256d ymm_src0 = _mm256_loadu_pd(src);
			__m256d ymm_src1 = _mm256_loadu_pd(src + 4);
			__m256d ymm_src2 = _mm256_loadu_pd(src + 8);
			__m256d ymm_src3 = _mm256_loadu_pd(src + 12);
			__m256d ymm_src4 = _mm256_loadu_pd(src + 16);
			__m256d ymm_src5 = _mm256_loadu_pd(src + 20);
			__m256d ymm_src6 = _mm256_loadu_pd(src + 24);
			__m256d ymm_src7 = _mm256_loadu_pd(src + 28);
			ymm_src0 = _mm256_max_pd(ymm_src0, min);
			ymm_src1 = _mm256_max_pd(ymm_src1, min);
			ymm_src2 = _mm256_max_pd(ymm_src2, min);
			ymm_src3 = _mm256_max_pd(ymm_src3, min);
			ymm_src4 = _mm256_max_pd(ymm_src4, min);
			ymm_src5 = _mm256_max_pd(ymm_src5, min);
			ymm_src6 = _mm256_max_pd(ymm_src6, min);
			ymm_src7 = _mm256_max_pd(ymm_src7, min);
			ymm_src0 = _mm256_min_pd(ymm_src0, max);
			ymm_src1 = _mm256_min_pd(ymm_src1, max);
			ymm_src2 = _mm256_min_pd(ymm_src2, max);
			ymm_src3 = _mm256_min_pd(ymm_src3, max);
			ymm_src4 = _mm256_min_pd(ymm_src4, max);
			ymm_src5 = _mm256_min_pd(ymm_src5, max);
			ymm_src6 = _mm256_min_pd(ymm_src6, max);
			ymm_src7 = _mm256_min_pd(ymm_src7, max);
			__m256i ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
			__m256i ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
			__m256i ymm_dst2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src2));
			__m256i ymm_dst3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src3));
			__m256i ymm_dst4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src4));
			__m256i ymm_dst5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src5));
			__m256i ymm_dst6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src6));
			__m256i ymm_dst7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src7));
			ymm_dst0 = _mm256_packs_epi32(ymm_dst0, ymm_dst1);
			ymm_dst2 = _mm256_packs_epi32(ymm_dst2, ymm_dst3);
			ymm_dst4 = _mm256_packs_epi32(ymm_dst4, ymm_dst5);
			ymm_dst6 = _mm256_packs_epi32(ymm_dst6, ymm_dst7);
			ymm_dst0 = _mm256_packs_epi16(ymm_dst0, ymm_dst2);
			ymm_dst4 = _mm256_packs_epi16(ymm_dst4, ymm_dst6);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, _mm256_castsi256_si128(ymm_dst4));
		}

		template <>
		inline void cvtspd_avx2_32<unsigned char>(unsigned char* dst, const double* src)
		{
			const __m256d min = _mm256_setzero_pd();
			const __m256d max = _mm256_set1_pd(static_cast<double>(UINT8_MAX));
			__m256d ymm_src0 = _mm256_loadu_pd(src);
			__m256d ymm_src1 = _mm256_loadu_pd(src + 4);
			__m256d ymm_src2 = _mm256_loadu_pd(src + 8);
			__m256d ymm_src3 = _mm256_loadu_pd(src + 12);
			__m256d ymm_src4 = _mm256_loadu_pd(src + 16);
			__m256d ymm_src5 = _mm256_loadu_pd(src + 20);
			__m256d ymm_src6 = _mm256_loadu_pd(src + 24);
			__m256d ymm_src7 = _mm256_loadu_pd(src + 28);
			ymm_src0 = _mm256_max_pd(ymm_src0, min);
			ymm_src1 = _mm256_max_pd(ymm_src1, min);
			ymm_src2 = _mm256_max_pd(ymm_src2, min);
			ymm_src3 = _mm256_max_pd(ymm_src3, min);
			ymm_src4 = _mm256_max_pd(ymm_src4, min);
			ymm_src5 = _mm256_max_pd(ymm_src5, min);
			ymm_src6 = _mm256_max_pd(ymm_src6, min);
			ymm_src7 = _mm256_max_pd(ymm_src7, min);
			ymm_src0 = _mm256_min_pd(ymm_src0, max);
			ymm_src1 = _mm256_min_pd(ymm_src1, max);
			ymm_src2 = _mm256_min_pd(ymm_src2, max);
			ymm_src3 = _mm256_min_pd(ymm_src3, max);
			ymm_src4 = _mm256_min_pd(ymm_src4, max);
			ymm_src5 = _mm256_min_pd(ymm_src5, max);
			ymm_src6 = _mm256_min_pd(ymm_src6, max);
			ymm_src7 = _mm256_min_pd(ymm_src7, max);
			__m256i ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
			__m256i ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
			__m256i ymm_dst2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src2));
			__m256i ymm_dst3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src3));
			__m256i ymm_dst4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src4));
			__m256i ymm_dst5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src5));
			__m256i ymm_dst6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src6));
			__m256i ymm_dst7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src7));
			ymm_dst0 = _mm256_packus_epi32(ymm_dst0, ymm_dst1);
			ymm_dst2 = _mm256_packus_epi32(ymm_dst2, ymm_dst3);
			ymm_dst4 = _mm256_packus_epi32(ymm_dst4, ymm_dst5);
			ymm_dst6 = _mm256_packus_epi32(ymm_dst6, ymm_dst7);
			ymm_dst0 = _mm256_packus_epi16(ymm_dst0, ymm_dst2);
			ymm_dst4 = _mm256_packus_epi16(ymm_dst4, ymm_dst6);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, _mm256_castsi256_si128(ymm_dst4));
		}

		template <>
		inline void cvtspd_avx2_32<signed short>(signed short* dst, const double* src)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT16_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT16_MAX));
			__m256d ymm_src0 = _mm256_loadu_pd(src);
			__m256d ymm_src1 = _mm256_loadu_pd(src + 4);
			__m256d ymm_src2 = _mm256_loadu_pd(src + 8);
			__m256d ymm_src3 = _mm256_loadu_pd(src + 12);
			__m256d ymm_src4 = _mm256_loadu_pd(src + 16);
			__m256d ymm_src5 = _mm256_loadu_pd(src + 20);
			__m256d ymm_src6 = _mm256_loadu_pd(src + 24);
			__m256d ymm_src7 = _mm256_loadu_pd(src + 28);
			ymm_src0 = _mm256_max_pd(ymm_src0, min);
			ymm_src1 = _mm256_max_pd(ymm_src1, min);
			ymm_src2 = _mm256_max_pd(ymm_src2, min);
			ymm_src3 = _mm256_max_pd(ymm_src3, min);
			ymm_src4 = _mm256_max_pd(ymm_src4, min);
			ymm_src5 = _mm256_max_pd(ymm_src5, min);
			ymm_src6 = _mm256_max_pd(ymm_src6, min);
			ymm_src7 = _mm256_max_pd(ymm_src7, min);
			ymm_src0 = _mm256_min_pd(ymm_src0, max);
			ymm_src1 = _mm256_min_pd(ymm_src1, max);
			ymm_src2 = _mm256_min_pd(ymm_src2, max);
			ymm_src3 = _mm256_min_pd(ymm_src3, max);
			ymm_src4 = _mm256_min_pd(ymm_src4, max);
			ymm_src5 = _mm256_min_pd(ymm_src5, max);
			ymm_src6 = _mm256_min_pd(ymm_src6, max);
			ymm_src7 = _mm256_min_pd(ymm_src7, max);
			__m256i ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
			__m256i ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
			__m256i ymm_dst2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src2));
			__m256i ymm_dst3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src3));
			__m256i ymm_dst4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src4));
			__m256i ymm_dst5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src5));
			__m256i ymm_dst6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src6));
			__m256i ymm_dst7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src7));
			ymm_dst0 = _mm256_packs_epi32(ymm_dst0, ymm_dst1);
			ymm_dst2 = _mm256_packs_epi32(ymm_dst2, ymm_dst3);
			ymm_dst4 = _mm256_packs_epi32(ymm_dst4, ymm_dst5);
			ymm_dst6 = _mm256_packs_epi32(ymm_dst6, ymm_dst7);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, _mm256_castsi256_si128(ymm_dst2));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 2, _mm256_castsi256_si128(ymm_dst4));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 3, _mm256_castsi256_si128(ymm_dst6));
		}

		template <>
		inline void cvtspd_avx2_32<unsigned short>(unsigned short* dst, const double* src)
		{
			const __m256d min = _mm256_setzero_pd();
			const __m256d max = _mm256_set1_pd(static_cast<double>(UINT16_MAX));
			__m256d ymm_src0 = _mm256_loadu_pd(src);
			__m256d ymm_src1 = _mm256_loadu_pd(src + 4);
			__m256d ymm_src2 = _mm256_loadu_pd(src + 8);
			__m256d ymm_src3 = _mm256_loadu_pd(src + 12);
			__m256d ymm_src4 = _mm256_loadu_pd(src + 16);
			__m256d ymm_src5 = _mm256_loadu_pd(src + 20);
			__m256d ymm_src6 = _mm256_loadu_pd(src + 24);
			__m256d ymm_src7 = _mm256_loadu_pd(src + 28);
			ymm_src0 = _mm256_max_pd(ymm_src0, min);
			ymm_src1 = _mm256_max_pd(ymm_src1, min);
			ymm_src2 = _mm256_max_pd(ymm_src2, min);
			ymm_src3 = _mm256_max_pd(ymm_src3, min);
			ymm_src4 = _mm256_max_pd(ymm_src4, min);
			ymm_src5 = _mm256_max_pd(ymm_src5, min);
			ymm_src6 = _mm256_max_pd(ymm_src6, min);
			ymm_src7 = _mm256_max_pd(ymm_src7, min);
			ymm_src0 = _mm256_min_pd(ymm_src0, max);
			ymm_src1 = _mm256_min_pd(ymm_src1, max);
			ymm_src2 = _mm256_min_pd(ymm_src2, max);
			ymm_src3 = _mm256_min_pd(ymm_src3, max);
			ymm_src4 = _mm256_min_pd(ymm_src4, max);
			ymm_src5 = _mm256_min_pd(ymm_src5, max);
			ymm_src6 = _mm256_min_pd(ymm_src6, max);
			ymm_src7 = _mm256_min_pd(ymm_src7, max);
			__m256i ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
			__m256i ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
			__m256i ymm_dst2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src2));
			__m256i ymm_dst3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src3));
			__m256i ymm_dst4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src4));
			__m256i ymm_dst5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src5));
			__m256i ymm_dst6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src6));
			__m256i ymm_dst7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src7));
			ymm_dst0 = _mm256_packus_epi32(ymm_dst0, ymm_dst1);
			ymm_dst2 = _mm256_packus_epi32(ymm_dst2, ymm_dst3);
			ymm_dst4 = _mm256_packus_epi32(ymm_dst4, ymm_dst5);
			ymm_dst6 = _mm256_packus_epi32(ymm_dst6, ymm_dst7);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, _mm256_castsi256_si128(ymm_dst2));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 2, _mm256_castsi256_si128(ymm_dst4));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 3, _mm256_castsi256_si128(ymm_dst6));
		}

		template <>
		inline void cvtspd_avx2_32<signed int>(signed int* dst, const double* src)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT32_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT32_MAX));
			__m256d ymm_src0 = _mm256_loadu_pd(src);
			__m256d ymm_src1 = _mm256_loadu_pd(src + 4);
			__m256d ymm_src2 = _mm256_loadu_pd(src + 8);
			__m256d ymm_src3 = _mm256_loadu_pd(src + 12);
			__m256d ymm_src4 = _mm256_loadu_pd(src + 16);
			__m256d ymm_src5 = _mm256_loadu_pd(src + 20);
			__m256d ymm_src6 = _mm256_loadu_pd(src + 24);
			__m256d ymm_src7 = _mm256_loadu_pd(src + 28);
			ymm_src0 = _mm256_max_pd(ymm_src0, min);
			ymm_src1 = _mm256_max_pd(ymm_src1, min);
			ymm_src2 = _mm256_max_pd(ymm_src2, min);
			ymm_src3 = _mm256_max_pd(ymm_src3, min);
			ymm_src4 = _mm256_max_pd(ymm_src4, min);
			ymm_src5 = _mm256_max_pd(ymm_src5, min);
			ymm_src6 = _mm256_max_pd(ymm_src6, min);
			ymm_src7 = _mm256_max_pd(ymm_src7, min);
			ymm_src0 = _mm256_min_pd(ymm_src0, max);
			ymm_src1 = _mm256_min_pd(ymm_src1, max);
			ymm_src2 = _mm256_min_pd(ymm_src2, max);
			ymm_src3 = _mm256_min_pd(ymm_src3, max);
			ymm_src4 = _mm256_min_pd(ymm_src4, max);
			ymm_src5 = _mm256_min_pd(ymm_src5, max);
			ymm_src6 = _mm256_min_pd(ymm_src6, max);
			ymm_src7 = _mm256_min_pd(ymm_src7, max);
			__m128i xmm_dst0 = _mm256_cvttpd_epi32(ymm_src0);
			__m128i xmm_dst1 = _mm256_cvttpd_epi32(ymm_src1);
			__m128i xmm_dst2 = _mm256_cvttpd_epi32(ymm_src2);
			__m128i xmm_dst3 = _mm256_cvttpd_epi32(ymm_src3);
			__m128i xmm_dst4 = _mm256_cvttpd_epi32(ymm_src4);
			__m128i xmm_dst5 = _mm256_cvttpd_epi32(ymm_src5);
			__m128i xmm_dst6 = _mm256_cvttpd_epi32(ymm_src6);
			__m128i xmm_dst7 = _mm256_cvttpd_epi32(ymm_src7);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 2, xmm_dst2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 3, xmm_dst3);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 4, xmm_dst4);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 5, xmm_dst5);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 6, xmm_dst6);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 7, xmm_dst7);
		}

		template <>
		inline void cvtspd_avx2_32<unsigned int>(unsigned int* dst, const double* src)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT32_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT32_MAX));
			const __m256d offset = _mm256_set1_pd(2.147483648e+9);
			const __m256i shift = _mm256_set1_epi32(2147483648);
			__m256d ymm_src0 = _mm256_loadu_pd(src);
			__m256d ymm_src1 = _mm256_loadu_pd(src + 4);
			__m256d ymm_src2 = _mm256_loadu_pd(src + 8);
			__m256d ymm_src3 = _mm256_loadu_pd(src + 12);
			__m256d ymm_src4 = _mm256_loadu_pd(src + 16);
			__m256d ymm_src5 = _mm256_loadu_pd(src + 20);
			__m256d ymm_src6 = _mm256_loadu_pd(src + 24);
			__m256d ymm_src7 = _mm256_loadu_pd(src + 28);
			ymm_src0 = _mm256_sub_pd(ymm_src0, offset);
			ymm_src1 = _mm256_sub_pd(ymm_src1, offset);
			ymm_src2 = _mm256_sub_pd(ymm_src2, offset);
			ymm_src3 = _mm256_sub_pd(ymm_src3, offset);
			ymm_src4 = _mm256_sub_pd(ymm_src4, offset);
			ymm_src5 = _mm256_sub_pd(ymm_src5, offset);
			ymm_src6 = _mm256_sub_pd(ymm_src6, offset);
			ymm_src7 = _mm256_sub_pd(ymm_src7, offset);
			ymm_src0 = _mm256_max_pd(ymm_src0, min);
			ymm_src1 = _mm256_max_pd(ymm_src1, min);
			ymm_src2 = _mm256_max_pd(ymm_src2, min);
			ymm_src3 = _mm256_max_pd(ymm_src3, min);
			ymm_src4 = _mm256_max_pd(ymm_src4, min);
			ymm_src5 = _mm256_max_pd(ymm_src5, min);
			ymm_src6 = _mm256_max_pd(ymm_src6, min);
			ymm_src7 = _mm256_max_pd(ymm_src7, min);
			ymm_src0 = _mm256_min_pd(ymm_src0, max);
			ymm_src1 = _mm256_min_pd(ymm_src1, max);
			ymm_src2 = _mm256_min_pd(ymm_src2, max);
			ymm_src3 = _mm256_min_pd(ymm_src3, max);
			ymm_src4 = _mm256_min_pd(ymm_src4, max);
			ymm_src5 = _mm256_min_pd(ymm_src5, max);
			ymm_src6 = _mm256_min_pd(ymm_src6, max);
			ymm_src7 = _mm256_min_pd(ymm_src7, max);
			__m256i ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
			__m256i ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
			__m256i ymm_dst2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src2));
			__m256i ymm_dst3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src3));
			__m256i ymm_dst4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src4));
			__m256i ymm_dst5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src5));
			__m256i ymm_dst6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src6));
			__m256i ymm_dst7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src7));
			ymm_dst0 = _mm256_add_epi32(ymm_dst0, shift);
			ymm_dst1 = _mm256_add_epi32(ymm_dst1, shift);
			ymm_dst2 = _mm256_add_epi32(ymm_dst2, shift);
			ymm_dst3 = _mm256_add_epi32(ymm_dst3, shift);
			ymm_dst4 = _mm256_add_epi32(ymm_dst4, shift);
			ymm_dst5 = _mm256_add_epi32(ymm_dst5, shift);
			ymm_dst6 = _mm256_add_epi32(ymm_dst6, shift);
			ymm_dst7 = _mm256_add_epi32(ymm_dst7, shift);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, _mm256_castsi256_si128(ymm_dst1));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 2, _mm256_castsi256_si128(ymm_dst2));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 3, _mm256_castsi256_si128(ymm_dst3));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 4, _mm256_castsi256_si128(ymm_dst4));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 5, _mm256_castsi256_si128(ymm_dst5));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 6, _mm256_castsi256_si128(ymm_dst6));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 7, _mm256_castsi256_si128(ymm_dst7));
		}

		template <>
		inline void cvtspd_avx2_32<float>(float* dst, const double* src)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(-FLT_MAX));
			const __m256d max = _mm256_set1_pd(static_cast<double>(FLT_MAX));
			__m256d ymm_src0 = _mm256_loadu_pd(src);
			__m256d ymm_src1 = _mm256_loadu_pd(src + 4);
			__m256d ymm_src2 = _mm256_loadu_pd(src + 8);
			__m256d ymm_src3 = _mm256_loadu_pd(src + 12);
			__m256d ymm_src4 = _mm256_loadu_pd(src + 16);
			__m256d ymm_src5 = _mm256_loadu_pd(src + 20);
			__m256d ymm_src6 = _mm256_loadu_pd(src + 24);
			__m256d ymm_src7 = _mm256_loadu_pd(src + 28);
			ymm_src0 = _mm256_max_pd(ymm_src0, min);
			ymm_src1 = _mm256_max_pd(ymm_src1, min);
			ymm_src2 = _mm256_max_pd(ymm_src2, min);
			ymm_src3 = _mm256_max_pd(ymm_src3, min);
			ymm_src4 = _mm256_max_pd(ymm_src4, min);
			ymm_src5 = _mm256_max_pd(ymm_src5, min);
			ymm_src6 = _mm256_max_pd(ymm_src6, min);
			ymm_src7 = _mm256_max_pd(ymm_src7, min);
			ymm_src0 = _mm256_min_pd(ymm_src0, max);
			ymm_src1 = _mm256_min_pd(ymm_src1, max);
			ymm_src2 = _mm256_min_pd(ymm_src2, max);
			ymm_src3 = _mm256_min_pd(ymm_src3, max);
			ymm_src4 = _mm256_min_pd(ymm_src4, max);
			ymm_src5 = _mm256_min_pd(ymm_src5, max);
			ymm_src6 = _mm256_min_pd(ymm_src6, max);
			ymm_src7 = _mm256_min_pd(ymm_src7, max);
			__m128 xmm_dst0 = _mm256_cvtpd_ps(ymm_src0);
			__m128 xmm_dst1 = _mm256_cvtpd_ps(ymm_src1);
			__m128 xmm_dst2 = _mm256_cvtpd_ps(ymm_src2);
			__m128 xmm_dst3 = _mm256_cvtpd_ps(ymm_src3);
			__m128 xmm_dst4 = _mm256_cvtpd_ps(ymm_src4);
			__m128 xmm_dst5 = _mm256_cvtpd_ps(ymm_src5);
			__m128 xmm_dst6 = _mm256_cvtpd_ps(ymm_src6);
			__m128 xmm_dst7 = _mm256_cvtpd_ps(ymm_src7);
			_mm_storeu_ps(dst, xmm_dst0);
			_mm_storeu_ps(dst + 4, xmm_dst1);
			_mm_storeu_ps(dst + 8, xmm_dst2);
			_mm_storeu_ps(dst + 12, xmm_dst3);
			_mm_storeu_ps(dst + 16, xmm_dst4);
			_mm_storeu_ps(dst + 20, xmm_dst5);
			_mm_storeu_ps(dst + 24, xmm_dst6);
			_mm_storeu_ps(dst + 28, xmm_dst7);
		}

		// Function template cvtspd_avx2_small

		template <class T>
		inline void cvtspd_avx2_small(T* dst, const double* src, size_t n)
		{
			switch (n >> 3)
			{
			case 4:
				cvtspd_avx2_32(dst, src);
			case 0:
				break;
			case 5:
				cvtspd_avx2_32(dst, src);
				src += 32;
				dst += 32;
			case 1:
				cvtspd_avx2_8(dst, src);
				break;
			case 6:
				cvtspd_avx2_32(dst, src);
				src += 32;
				dst += 32;
			case 2:
				cvtspd_avx2_16(dst, src);
				break;
			case 7:
				cvtspd_avx2_32(dst, src);
				src += 32;
				dst += 32;
			case 3:
				cvtspd_avx2_16(dst, src);
				src += 16;
				dst += 16;
				cvtspd_avx2_8(dst, src);
				break;
			}
			cvtspd_tiny(dst, src, n & 7);
		}

		// Function template cvtspd_avx2_medium

		template <class T>
		inline void cvtspd_avx2_medium(T* dst, const double* src, size_t n)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		void cvtspd_avx2_medium<signed char>(signed char* dst, const double* src, size_t n)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT8_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT8_MAX));
			__m256d ymm_src0, ymm_src1, ymm_src2, ymm_src3, ymm_src4, ymm_src5, ymm_src6, ymm_src7;
			__m256i ymm_dst0, ymm_dst1, ymm_dst2, ymm_dst3, ymm_dst4, ymm_dst5, ymm_dst6, ymm_dst7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				ymm_src0 = _mm256_loadu_pd(src);
				ymm_src1 = _mm256_loadu_pd(src + 4);
				ymm_src2 = _mm256_loadu_pd(src + 8);
				ymm_src3 = _mm256_loadu_pd(src + 12);
				ymm_src4 = _mm256_loadu_pd(src + 16);
				ymm_src5 = _mm256_loadu_pd(src + 20);
				ymm_src6 = _mm256_loadu_pd(src + 24);
				ymm_src7 = _mm256_loadu_pd(src + 28);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
				ymm_src0 = _mm256_max_pd(ymm_src0, min);
				ymm_src1 = _mm256_max_pd(ymm_src1, min);
				ymm_src2 = _mm256_max_pd(ymm_src2, min);
				ymm_src3 = _mm256_max_pd(ymm_src3, min);
				ymm_src4 = _mm256_max_pd(ymm_src4, min);
				ymm_src5 = _mm256_max_pd(ymm_src5, min);
				ymm_src6 = _mm256_max_pd(ymm_src6, min);
				ymm_src7 = _mm256_max_pd(ymm_src7, min);
				ymm_src0 = _mm256_min_pd(ymm_src0, max);
				ymm_src1 = _mm256_min_pd(ymm_src1, max);
				ymm_src2 = _mm256_min_pd(ymm_src2, max);
				ymm_src3 = _mm256_min_pd(ymm_src3, max);
				ymm_src4 = _mm256_min_pd(ymm_src4, max);
				ymm_src5 = _mm256_min_pd(ymm_src5, max);
				ymm_src6 = _mm256_min_pd(ymm_src6, max);
				ymm_src7 = _mm256_min_pd(ymm_src7, max);
				ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
				ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
				ymm_dst2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src2));
				ymm_dst3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src3));
				ymm_dst4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src4));
				ymm_dst5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src5));
				ymm_dst6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src6));
				ymm_dst7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src7));
				ymm_dst0 = _mm256_packs_epi32(ymm_dst0, ymm_dst1);
				ymm_dst2 = _mm256_packs_epi32(ymm_dst2, ymm_dst3);
				ymm_dst4 = _mm256_packs_epi32(ymm_dst4, ymm_dst5);
				ymm_dst6 = _mm256_packs_epi32(ymm_dst6, ymm_dst7);
				ymm_dst0 = _mm256_packs_epi16(ymm_dst0, ymm_dst2);
				ymm_dst4 = _mm256_packs_epi16(ymm_dst4, ymm_dst6);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, _mm256_castsi256_si128(ymm_dst4));
				src += 32;
				dst += 32;
			}
		}

		template <>
		void cvtspd_avx2_medium<unsigned char>(unsigned char* dst, const double* src, size_t n)
		{
			const __m256d min = _mm256_setzero_pd();
			const __m256d max = _mm256_set1_pd(static_cast<double>(UINT8_MAX));
			__m256d ymm_src0, ymm_src1, ymm_src2, ymm_src3, ymm_src4, ymm_src5, ymm_src6, ymm_src7;
			__m256i ymm_dst0, ymm_dst1, ymm_dst2, ymm_dst3, ymm_dst4, ymm_dst5, ymm_dst6, ymm_dst7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				ymm_src0 = _mm256_loadu_pd(src);
				ymm_src1 = _mm256_loadu_pd(src + 4);
				ymm_src2 = _mm256_loadu_pd(src + 8);
				ymm_src3 = _mm256_loadu_pd(src + 12);
				ymm_src4 = _mm256_loadu_pd(src + 16);
				ymm_src5 = _mm256_loadu_pd(src + 20);
				ymm_src6 = _mm256_loadu_pd(src + 24);
				ymm_src7 = _mm256_loadu_pd(src + 28);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
				ymm_src0 = _mm256_max_pd(ymm_src0, min);
				ymm_src1 = _mm256_max_pd(ymm_src1, min);
				ymm_src2 = _mm256_max_pd(ymm_src2, min);
				ymm_src3 = _mm256_max_pd(ymm_src3, min);
				ymm_src4 = _mm256_max_pd(ymm_src4, min);
				ymm_src5 = _mm256_max_pd(ymm_src5, min);
				ymm_src6 = _mm256_max_pd(ymm_src6, min);
				ymm_src7 = _mm256_max_pd(ymm_src7, min);
				ymm_src0 = _mm256_min_pd(ymm_src0, max);
				ymm_src1 = _mm256_min_pd(ymm_src1, max);
				ymm_src2 = _mm256_min_pd(ymm_src2, max);
				ymm_src3 = _mm256_min_pd(ymm_src3, max);
				ymm_src4 = _mm256_min_pd(ymm_src4, max);
				ymm_src5 = _mm256_min_pd(ymm_src5, max);
				ymm_src6 = _mm256_min_pd(ymm_src6, max);
				ymm_src7 = _mm256_min_pd(ymm_src7, max);
				ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
				ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
				ymm_dst2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src2));
				ymm_dst3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src3));
				ymm_dst4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src4));
				ymm_dst5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src5));
				ymm_dst6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src6));
				ymm_dst7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src7));
				ymm_dst0 = _mm256_packus_epi32(ymm_dst0, ymm_dst1);
				ymm_dst2 = _mm256_packus_epi32(ymm_dst2, ymm_dst3);
				ymm_dst4 = _mm256_packus_epi32(ymm_dst4, ymm_dst5);
				ymm_dst6 = _mm256_packus_epi32(ymm_dst6, ymm_dst7);
				ymm_dst0 = _mm256_packus_epi16(ymm_dst0, ymm_dst2);
				ymm_dst4 = _mm256_packus_epi16(ymm_dst4, ymm_dst6);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, _mm256_castsi256_si128(ymm_dst4));
				src += 32;
				dst += 32;
			}
		}

		template <>
		void cvtspd_avx2_medium<signed short>(signed short* dst, const double* src, size_t n)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT16_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT16_MAX));
			__m256d ymm_src0, ymm_src1, ymm_src2, ymm_src3, ymm_src4, ymm_src5, ymm_src6, ymm_src7;
			__m256i ymm_dst0, ymm_dst1, ymm_dst2, ymm_dst3, ymm_dst4, ymm_dst5, ymm_dst6, ymm_dst7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				ymm_src0 = _mm256_loadu_pd(src);
				ymm_src1 = _mm256_loadu_pd(src + 4);
				ymm_src2 = _mm256_loadu_pd(src + 8);
				ymm_src3 = _mm256_loadu_pd(src + 12);
				ymm_src4 = _mm256_loadu_pd(src + 16);
				ymm_src5 = _mm256_loadu_pd(src + 20);
				ymm_src6 = _mm256_loadu_pd(src + 24);
				ymm_src7 = _mm256_loadu_pd(src + 28);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
				ymm_src0 = _mm256_max_pd(ymm_src0, min);
				ymm_src1 = _mm256_max_pd(ymm_src1, min);
				ymm_src2 = _mm256_max_pd(ymm_src2, min);
				ymm_src3 = _mm256_max_pd(ymm_src3, min);
				ymm_src4 = _mm256_max_pd(ymm_src4, min);
				ymm_src5 = _mm256_max_pd(ymm_src5, min);
				ymm_src6 = _mm256_max_pd(ymm_src6, min);
				ymm_src7 = _mm256_max_pd(ymm_src7, min);
				ymm_src0 = _mm256_min_pd(ymm_src0, max);
				ymm_src1 = _mm256_min_pd(ymm_src1, max);
				ymm_src2 = _mm256_min_pd(ymm_src2, max);
				ymm_src3 = _mm256_min_pd(ymm_src3, max);
				ymm_src4 = _mm256_min_pd(ymm_src4, max);
				ymm_src5 = _mm256_min_pd(ymm_src5, max);
				ymm_src6 = _mm256_min_pd(ymm_src6, max);
				ymm_src7 = _mm256_min_pd(ymm_src7, max);
				ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
				ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
				ymm_dst2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src2));
				ymm_dst3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src3));
				ymm_dst4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src4));
				ymm_dst5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src5));
				ymm_dst6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src6));
				ymm_dst7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src7));
				ymm_dst0 = _mm256_packs_epi32(ymm_dst0, ymm_dst1);
				ymm_dst2 = _mm256_packs_epi32(ymm_dst2, ymm_dst3);
				ymm_dst4 = _mm256_packs_epi32(ymm_dst4, ymm_dst5);
				ymm_dst6 = _mm256_packs_epi32(ymm_dst6, ymm_dst7);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, _mm256_castsi256_si128(ymm_dst2));
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 2, _mm256_castsi256_si128(ymm_dst4));
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 3, _mm256_castsi256_si128(ymm_dst6));
				src += 32;
				dst += 32;
			}
		}

		template <>
		void cvtspd_avx2_medium<unsigned short>(unsigned short* dst, const double* src, size_t n)
		{
			const __m256d min = _mm256_setzero_pd();
			const __m256d max = _mm256_set1_pd(static_cast<double>(UINT16_MAX));
			__m256d ymm_src0, ymm_src1, ymm_src2, ymm_src3, ymm_src4, ymm_src5, ymm_src6, ymm_src7;
			__m256i ymm_dst0, ymm_dst1, ymm_dst2, ymm_dst3, ymm_dst4, ymm_dst5, ymm_dst6, ymm_dst7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				ymm_src0 = _mm256_loadu_pd(src);
				ymm_src1 = _mm256_loadu_pd(src + 4);
				ymm_src2 = _mm256_loadu_pd(src + 8);
				ymm_src3 = _mm256_loadu_pd(src + 12);
				ymm_src4 = _mm256_loadu_pd(src + 16);
				ymm_src5 = _mm256_loadu_pd(src + 20);
				ymm_src6 = _mm256_loadu_pd(src + 24);
				ymm_src7 = _mm256_loadu_pd(src + 28);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
				ymm_src0 = _mm256_max_pd(ymm_src0, min);
				ymm_src1 = _mm256_max_pd(ymm_src1, min);
				ymm_src2 = _mm256_max_pd(ymm_src2, min);
				ymm_src3 = _mm256_max_pd(ymm_src3, min);
				ymm_src4 = _mm256_max_pd(ymm_src4, min);
				ymm_src5 = _mm256_max_pd(ymm_src5, min);
				ymm_src6 = _mm256_max_pd(ymm_src6, min);
				ymm_src7 = _mm256_max_pd(ymm_src7, min);
				ymm_src0 = _mm256_min_pd(ymm_src0, max);
				ymm_src1 = _mm256_min_pd(ymm_src1, max);
				ymm_src2 = _mm256_min_pd(ymm_src2, max);
				ymm_src3 = _mm256_min_pd(ymm_src3, max);
				ymm_src4 = _mm256_min_pd(ymm_src4, max);
				ymm_src5 = _mm256_min_pd(ymm_src5, max);
				ymm_src6 = _mm256_min_pd(ymm_src6, max);
				ymm_src7 = _mm256_min_pd(ymm_src7, max);
				ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
				ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
				ymm_dst2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src2));
				ymm_dst3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src3));
				ymm_dst4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src4));
				ymm_dst5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src5));
				ymm_dst6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src6));
				ymm_dst7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src7));
				ymm_dst0 = _mm256_packus_epi32(ymm_dst0, ymm_dst1);
				ymm_dst2 = _mm256_packus_epi32(ymm_dst2, ymm_dst3);
				ymm_dst4 = _mm256_packus_epi32(ymm_dst4, ymm_dst5);
				ymm_dst6 = _mm256_packus_epi32(ymm_dst6, ymm_dst7);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, _mm256_castsi256_si128(ymm_dst2));
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 2, _mm256_castsi256_si128(ymm_dst4));
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 3, _mm256_castsi256_si128(ymm_dst6));
				src += 32;
				dst += 32;
			}
		}

		template <>
		void cvtspd_avx2_medium<signed int>(signed int* dst, const double* src, size_t n)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT32_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT32_MAX));
			__m256d ymm_src0, ymm_src1, ymm_src2, ymm_src3, ymm_src4, ymm_src5, ymm_src6, ymm_src7;
			__m128i xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3, xmm_dst4, xmm_dst5, xmm_dst6, xmm_dst7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				ymm_src0 = _mm256_loadu_pd(src);
				ymm_src1 = _mm256_loadu_pd(src + 4);
				ymm_src2 = _mm256_loadu_pd(src + 8);
				ymm_src3 = _mm256_loadu_pd(src + 12);
				ymm_src4 = _mm256_loadu_pd(src + 16);
				ymm_src5 = _mm256_loadu_pd(src + 20);
				ymm_src6 = _mm256_loadu_pd(src + 24);
				ymm_src7 = _mm256_loadu_pd(src + 28);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
				ymm_src0 = _mm256_max_pd(ymm_src0, min);
				ymm_src1 = _mm256_max_pd(ymm_src1, min);
				ymm_src2 = _mm256_max_pd(ymm_src2, min);
				ymm_src3 = _mm256_max_pd(ymm_src3, min);
				ymm_src4 = _mm256_max_pd(ymm_src4, min);
				ymm_src5 = _mm256_max_pd(ymm_src5, min);
				ymm_src6 = _mm256_max_pd(ymm_src6, min);
				ymm_src7 = _mm256_max_pd(ymm_src7, min);
				ymm_src0 = _mm256_min_pd(ymm_src0, max);
				ymm_src1 = _mm256_min_pd(ymm_src1, max);
				ymm_src2 = _mm256_min_pd(ymm_src2, max);
				ymm_src3 = _mm256_min_pd(ymm_src3, max);
				ymm_src4 = _mm256_min_pd(ymm_src4, max);
				ymm_src5 = _mm256_min_pd(ymm_src5, max);
				ymm_src6 = _mm256_min_pd(ymm_src6, max);
				ymm_src7 = _mm256_min_pd(ymm_src7, max);
				xmm_dst0 = _mm256_cvttpd_epi32(ymm_src0);
				xmm_dst1 = _mm256_cvttpd_epi32(ymm_src1);
				xmm_dst2 = _mm256_cvttpd_epi32(ymm_src2);
				xmm_dst3 = _mm256_cvttpd_epi32(ymm_src3);
				xmm_dst4 = _mm256_cvttpd_epi32(ymm_src4);
				xmm_dst5 = _mm256_cvttpd_epi32(ymm_src5);
				xmm_dst6 = _mm256_cvttpd_epi32(ymm_src6);
				xmm_dst7 = _mm256_cvttpd_epi32(ymm_src7);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst1);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 2, xmm_dst2);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 3, xmm_dst3);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 4, xmm_dst4);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 5, xmm_dst5);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 6, xmm_dst6);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 7, xmm_dst7);
				src += 32;
				dst += 32;
			}
		}

		template <>
		void cvtspd_avx2_medium<unsigned int>(unsigned int* dst, const double* src, size_t n)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT32_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT32_MAX));
			const __m256d offset = _mm256_set1_pd(2.147483648e+9);
			const __m256i shift = _mm256_set1_epi32(2147483648);
			__m256d ymm_src0, ymm_src1, ymm_src2, ymm_src3, ymm_src4, ymm_src5, ymm_src6, ymm_src7;
			__m256i ymm_dst0, ymm_dst1, ymm_dst2, ymm_dst3, ymm_dst4, ymm_dst5, ymm_dst6, ymm_dst7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				ymm_src0 = _mm256_loadu_pd(src);
				ymm_src1 = _mm256_loadu_pd(src + 4);
				ymm_src2 = _mm256_loadu_pd(src + 8);
				ymm_src3 = _mm256_loadu_pd(src + 12);
				ymm_src4 = _mm256_loadu_pd(src + 16);
				ymm_src5 = _mm256_loadu_pd(src + 20);
				ymm_src6 = _mm256_loadu_pd(src + 24);
				ymm_src7 = _mm256_loadu_pd(src + 28);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
				ymm_src0 = _mm256_sub_pd(ymm_src0, offset);
				ymm_src1 = _mm256_sub_pd(ymm_src1, offset);
				ymm_src2 = _mm256_sub_pd(ymm_src2, offset);
				ymm_src3 = _mm256_sub_pd(ymm_src3, offset);
				ymm_src4 = _mm256_sub_pd(ymm_src4, offset);
				ymm_src5 = _mm256_sub_pd(ymm_src5, offset);
				ymm_src6 = _mm256_sub_pd(ymm_src6, offset);
				ymm_src7 = _mm256_sub_pd(ymm_src7, offset);
				ymm_src0 = _mm256_max_pd(ymm_src0, min);
				ymm_src1 = _mm256_max_pd(ymm_src1, min);
				ymm_src2 = _mm256_max_pd(ymm_src2, min);
				ymm_src3 = _mm256_max_pd(ymm_src3, min);
				ymm_src4 = _mm256_max_pd(ymm_src4, min);
				ymm_src5 = _mm256_max_pd(ymm_src5, min);
				ymm_src6 = _mm256_max_pd(ymm_src6, min);
				ymm_src7 = _mm256_max_pd(ymm_src7, min);
				ymm_src0 = _mm256_min_pd(ymm_src0, max);
				ymm_src1 = _mm256_min_pd(ymm_src1, max);
				ymm_src2 = _mm256_min_pd(ymm_src2, max);
				ymm_src3 = _mm256_min_pd(ymm_src3, max);
				ymm_src4 = _mm256_min_pd(ymm_src4, max);
				ymm_src5 = _mm256_min_pd(ymm_src5, max);
				ymm_src6 = _mm256_min_pd(ymm_src6, max);
				ymm_src7 = _mm256_min_pd(ymm_src7, max);
				ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
				ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
				ymm_dst2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src2));
				ymm_dst3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src3));
				ymm_dst4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src4));
				ymm_dst5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src5));
				ymm_dst6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src6));
				ymm_dst7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src7));
				ymm_dst0 = _mm256_add_epi32(ymm_dst0, shift);
				ymm_dst1 = _mm256_add_epi32(ymm_dst1, shift);
				ymm_dst2 = _mm256_add_epi32(ymm_dst2, shift);
				ymm_dst3 = _mm256_add_epi32(ymm_dst3, shift);
				ymm_dst4 = _mm256_add_epi32(ymm_dst4, shift);
				ymm_dst5 = _mm256_add_epi32(ymm_dst5, shift);
				ymm_dst6 = _mm256_add_epi32(ymm_dst6, shift);
				ymm_dst7 = _mm256_add_epi32(ymm_dst7, shift);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, _mm256_castsi256_si128(ymm_dst1));
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 2, _mm256_castsi256_si128(ymm_dst2));
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 3, _mm256_castsi256_si128(ymm_dst3));
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 4, _mm256_castsi256_si128(ymm_dst4));
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 5, _mm256_castsi256_si128(ymm_dst5));
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 6, _mm256_castsi256_si128(ymm_dst6));
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 7, _mm256_castsi256_si128(ymm_dst7));
				src += 32;
				dst += 32;
			}
		}

		template <>
		void cvtspd_avx2_medium<float>(float* dst, const double* src, size_t n)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(-FLT_MAX));
			const __m256d max = _mm256_set1_pd(static_cast<double>(FLT_MAX));
			__m256d ymm_src0, ymm_src1, ymm_src2, ymm_src3, ymm_src4, ymm_src5, ymm_src6, ymm_src7;
			__m128 xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3, xmm_dst4, xmm_dst5, xmm_dst6, xmm_dst7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				ymm_src0 = _mm256_loadu_pd(src);
				ymm_src1 = _mm256_loadu_pd(src + 4);
				ymm_src2 = _mm256_loadu_pd(src + 8);
				ymm_src3 = _mm256_loadu_pd(src + 12);
				ymm_src4 = _mm256_loadu_pd(src + 16);
				ymm_src5 = _mm256_loadu_pd(src + 20);
				ymm_src6 = _mm256_loadu_pd(src + 24);
				ymm_src7 = _mm256_loadu_pd(src + 28);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
				ymm_src0 = _mm256_max_pd(ymm_src0, min);
				ymm_src1 = _mm256_max_pd(ymm_src1, min);
				ymm_src2 = _mm256_max_pd(ymm_src2, min);
				ymm_src3 = _mm256_max_pd(ymm_src3, min);
				ymm_src4 = _mm256_max_pd(ymm_src4, min);
				ymm_src5 = _mm256_max_pd(ymm_src5, min);
				ymm_src6 = _mm256_max_pd(ymm_src6, min);
				ymm_src7 = _mm256_max_pd(ymm_src7, min);
				ymm_src0 = _mm256_min_pd(ymm_src0, max);
				ymm_src1 = _mm256_min_pd(ymm_src1, max);
				ymm_src2 = _mm256_min_pd(ymm_src2, max);
				ymm_src3 = _mm256_min_pd(ymm_src3, max);
				ymm_src4 = _mm256_min_pd(ymm_src4, max);
				ymm_src5 = _mm256_min_pd(ymm_src5, max);
				ymm_src6 = _mm256_min_pd(ymm_src6, max);
				ymm_src7 = _mm256_min_pd(ymm_src7, max);
				xmm_dst0 = _mm256_cvtpd_ps(ymm_src0);
				xmm_dst1 = _mm256_cvtpd_ps(ymm_src1);
				xmm_dst2 = _mm256_cvtpd_ps(ymm_src2);
				xmm_dst3 = _mm256_cvtpd_ps(ymm_src3);
				xmm_dst4 = _mm256_cvtpd_ps(ymm_src4);
				xmm_dst5 = _mm256_cvtpd_ps(ymm_src5);
				xmm_dst6 = _mm256_cvtpd_ps(ymm_src6);
				xmm_dst7 = _mm256_cvtpd_ps(ymm_src7);
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

		// Function template cvtspd_avx2_large

		template <class T>
		inline void cvtspd_avx2_large(T* dst, const double* src, size_t n)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		inline void cvtspd_avx2_large<signed char>(signed char* dst, const double* src, size_t n)
		{
			const size_t padding = 16 - (reinterpret_cast<size_t>(dst) & 15);
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT8_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT8_MAX));
			__m256d ymm_src0, ymm_src1, ymm_src2, ymm_src3, ymm_src4, ymm_src5, ymm_src6, ymm_src7;
			__m256i ymm_dst0, ymm_dst1, ymm_dst2, ymm_dst3, ymm_dst4, ymm_dst5, ymm_dst6, ymm_dst7;

			// Align the destination to a 16-byte boundary.
			ymm_src0 = _mm256_loadu_pd(src);
			ymm_src1 = _mm256_loadu_pd(src + 4);
			ymm_src2 = _mm256_loadu_pd(src + 8);
			ymm_src3 = _mm256_loadu_pd(src + 12);
			ymm_src0 = _mm256_max_pd(ymm_src0, min);
			ymm_src1 = _mm256_max_pd(ymm_src1, min);
			ymm_src2 = _mm256_max_pd(ymm_src2, min);
			ymm_src3 = _mm256_max_pd(ymm_src3, min);
			ymm_src0 = _mm256_min_pd(ymm_src0, max);
			ymm_src1 = _mm256_min_pd(ymm_src1, max);
			ymm_src2 = _mm256_min_pd(ymm_src2, max);
			ymm_src3 = _mm256_min_pd(ymm_src3, max);
			ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
			ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
			ymm_dst2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src2));
			ymm_dst3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src3));
			ymm_dst0 = _mm256_packs_epi32(ymm_dst0, ymm_dst1);
			ymm_dst2 = _mm256_packs_epi32(ymm_dst2, ymm_dst3);
			ymm_dst0 = _mm256_packs_epi16(ymm_dst0, ymm_dst2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
			dst += padding;
			src += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			// If the source is aligned on a 32-byte boundary.
			if ((reinterpret_cast<size_t>(src) & 31) == 0)
			{
				for (; n >= 32; n -= 32)
				{
					ymm_src0 = _mm256_load_pd(src);
					ymm_src1 = _mm256_load_pd(src + 4);
					ymm_src2 = _mm256_load_pd(src + 8);
					ymm_src3 = _mm256_load_pd(src + 12);
					ymm_src4 = _mm256_load_pd(src + 16);
					ymm_src5 = _mm256_load_pd(src + 20);
					ymm_src6 = _mm256_load_pd(src + 24);
					ymm_src7 = _mm256_load_pd(src + 28);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					ymm_src0 = _mm256_max_pd(ymm_src0, min);
					ymm_src1 = _mm256_max_pd(ymm_src1, min);
					ymm_src2 = _mm256_max_pd(ymm_src2, min);
					ymm_src3 = _mm256_max_pd(ymm_src3, min);
					ymm_src4 = _mm256_max_pd(ymm_src4, min);
					ymm_src5 = _mm256_max_pd(ymm_src5, min);
					ymm_src6 = _mm256_max_pd(ymm_src6, min);
					ymm_src7 = _mm256_max_pd(ymm_src7, min);
					ymm_src0 = _mm256_min_pd(ymm_src0, max);
					ymm_src1 = _mm256_min_pd(ymm_src1, max);
					ymm_src2 = _mm256_min_pd(ymm_src2, max);
					ymm_src3 = _mm256_min_pd(ymm_src3, max);
					ymm_src4 = _mm256_min_pd(ymm_src4, max);
					ymm_src5 = _mm256_min_pd(ymm_src5, max);
					ymm_src6 = _mm256_min_pd(ymm_src6, max);
					ymm_src7 = _mm256_min_pd(ymm_src7, max);
					ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
					ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
					ymm_dst2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src2));
					ymm_dst3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src3));
					ymm_dst4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src4));
					ymm_dst5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src5));
					ymm_dst6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src6));
					ymm_dst7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src7));
					ymm_dst0 = _mm256_packs_epi32(ymm_dst0, ymm_dst1);
					ymm_dst2 = _mm256_packs_epi32(ymm_dst2, ymm_dst3);
					ymm_dst4 = _mm256_packs_epi32(ymm_dst4, ymm_dst5);
					ymm_dst6 = _mm256_packs_epi32(ymm_dst6, ymm_dst7);
					ymm_dst0 = _mm256_packs_epi16(ymm_dst0, ymm_dst2);
					ymm_dst4 = _mm256_packs_epi16(ymm_dst4, ymm_dst6);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 1, _mm256_castsi256_si128(ymm_dst4));
					src += 32;
					dst += 32;
				}
			}
			else
			{
				for (; n >= 32; n -= 32)
				{
					ymm_src0 = _mm256_loadu_pd(src);
					ymm_src1 = _mm256_loadu_pd(src + 4);
					ymm_src2 = _mm256_loadu_pd(src + 8);
					ymm_src3 = _mm256_loadu_pd(src + 12);
					ymm_src4 = _mm256_loadu_pd(src + 16);
					ymm_src5 = _mm256_loadu_pd(src + 20);
					ymm_src6 = _mm256_loadu_pd(src + 24);
					ymm_src7 = _mm256_loadu_pd(src + 28);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					ymm_src0 = _mm256_max_pd(ymm_src0, min);
					ymm_src1 = _mm256_max_pd(ymm_src1, min);
					ymm_src2 = _mm256_max_pd(ymm_src2, min);
					ymm_src3 = _mm256_max_pd(ymm_src3, min);
					ymm_src4 = _mm256_max_pd(ymm_src4, min);
					ymm_src5 = _mm256_max_pd(ymm_src5, min);
					ymm_src6 = _mm256_max_pd(ymm_src6, min);
					ymm_src7 = _mm256_max_pd(ymm_src7, min);
					ymm_src0 = _mm256_min_pd(ymm_src0, max);
					ymm_src1 = _mm256_min_pd(ymm_src1, max);
					ymm_src2 = _mm256_min_pd(ymm_src2, max);
					ymm_src3 = _mm256_min_pd(ymm_src3, max);
					ymm_src4 = _mm256_min_pd(ymm_src4, max);
					ymm_src5 = _mm256_min_pd(ymm_src5, max);
					ymm_src6 = _mm256_min_pd(ymm_src6, max);
					ymm_src7 = _mm256_min_pd(ymm_src7, max);
					ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
					ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
					ymm_dst2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src2));
					ymm_dst3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src3));
					ymm_dst4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src4));
					ymm_dst5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src5));
					ymm_dst6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src6));
					ymm_dst7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src7));
					ymm_dst0 = _mm256_packs_epi32(ymm_dst0, ymm_dst1);
					ymm_dst2 = _mm256_packs_epi32(ymm_dst2, ymm_dst3);
					ymm_dst4 = _mm256_packs_epi32(ymm_dst4, ymm_dst5);
					ymm_dst6 = _mm256_packs_epi32(ymm_dst6, ymm_dst7);
					ymm_dst0 = _mm256_packs_epi16(ymm_dst0, ymm_dst2);
					ymm_dst4 = _mm256_packs_epi16(ymm_dst4, ymm_dst6);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 1, _mm256_castsi256_si128(ymm_dst4));
					src += 32;
					dst += 32;
				}
			}
		}

		template <>
		inline void cvtspd_avx2_large<unsigned char>(unsigned char* dst, const double* src, size_t n)
		{
			const size_t padding = 16 - (reinterpret_cast<size_t>(dst) & 15);
			const __m256d min = _mm256_setzero_pd();
			const __m256d max = _mm256_set1_pd(static_cast<double>(UINT8_MAX));
			__m256d ymm_src0, ymm_src1, ymm_src2, ymm_src3, ymm_src4, ymm_src5, ymm_src6, ymm_src7;
			__m256i ymm_dst0, ymm_dst1, ymm_dst2, ymm_dst3, ymm_dst4, ymm_dst5, ymm_dst6, ymm_dst7;

			// Align the destination to a 16-byte boundary.
			ymm_src0 = _mm256_loadu_pd(src);
			ymm_src1 = _mm256_loadu_pd(src + 4);
			ymm_src2 = _mm256_loadu_pd(src + 8);
			ymm_src3 = _mm256_loadu_pd(src + 12);
			ymm_src0 = _mm256_max_pd(ymm_src0, min);
			ymm_src1 = _mm256_max_pd(ymm_src1, min);
			ymm_src2 = _mm256_max_pd(ymm_src2, min);
			ymm_src3 = _mm256_max_pd(ymm_src3, min);
			ymm_src0 = _mm256_min_pd(ymm_src0, max);
			ymm_src1 = _mm256_min_pd(ymm_src1, max);
			ymm_src2 = _mm256_min_pd(ymm_src2, max);
			ymm_src3 = _mm256_min_pd(ymm_src3, max);
			ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
			ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
			ymm_dst2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src2));
			ymm_dst3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src3));
			ymm_dst0 = _mm256_packus_epi32(ymm_dst0, ymm_dst1);
			ymm_dst2 = _mm256_packus_epi32(ymm_dst2, ymm_dst3);
			ymm_dst0 = _mm256_packus_epi16(ymm_dst0, ymm_dst2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
			dst += padding;
			src += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			// If the source is aligned on a 32-byte boundary.
			if ((reinterpret_cast<size_t>(src) & 31) == 0)
			{
				for (; n >= 32; n -= 32)
				{
					ymm_src0 = _mm256_load_pd(src);
					ymm_src1 = _mm256_load_pd(src + 4);
					ymm_src2 = _mm256_load_pd(src + 8);
					ymm_src3 = _mm256_load_pd(src + 12);
					ymm_src4 = _mm256_load_pd(src + 16);
					ymm_src5 = _mm256_load_pd(src + 20);
					ymm_src6 = _mm256_load_pd(src + 24);
					ymm_src7 = _mm256_load_pd(src + 28);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					ymm_src0 = _mm256_max_pd(ymm_src0, min);
					ymm_src1 = _mm256_max_pd(ymm_src1, min);
					ymm_src2 = _mm256_max_pd(ymm_src2, min);
					ymm_src3 = _mm256_max_pd(ymm_src3, min);
					ymm_src4 = _mm256_max_pd(ymm_src4, min);
					ymm_src5 = _mm256_max_pd(ymm_src5, min);
					ymm_src6 = _mm256_max_pd(ymm_src6, min);
					ymm_src7 = _mm256_max_pd(ymm_src7, min);
					ymm_src0 = _mm256_min_pd(ymm_src0, max);
					ymm_src1 = _mm256_min_pd(ymm_src1, max);
					ymm_src2 = _mm256_min_pd(ymm_src2, max);
					ymm_src3 = _mm256_min_pd(ymm_src3, max);
					ymm_src4 = _mm256_min_pd(ymm_src4, max);
					ymm_src5 = _mm256_min_pd(ymm_src5, max);
					ymm_src6 = _mm256_min_pd(ymm_src6, max);
					ymm_src7 = _mm256_min_pd(ymm_src7, max);
					ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
					ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
					ymm_dst2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src2));
					ymm_dst3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src3));
					ymm_dst4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src4));
					ymm_dst5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src5));
					ymm_dst6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src6));
					ymm_dst7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src7));
					ymm_dst0 = _mm256_packus_epi32(ymm_dst0, ymm_dst1);
					ymm_dst2 = _mm256_packus_epi32(ymm_dst2, ymm_dst3);
					ymm_dst4 = _mm256_packus_epi32(ymm_dst4, ymm_dst5);
					ymm_dst6 = _mm256_packus_epi32(ymm_dst6, ymm_dst7);
					ymm_dst0 = _mm256_packus_epi16(ymm_dst0, ymm_dst2);
					ymm_dst4 = _mm256_packus_epi16(ymm_dst4, ymm_dst6);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 1, _mm256_castsi256_si128(ymm_dst4));
					src += 32;
					dst += 32;
				}
			}
			else
			{
				for (; n >= 32; n -= 32)
				{
					ymm_src0 = _mm256_loadu_pd(src);
					ymm_src1 = _mm256_loadu_pd(src + 4);
					ymm_src2 = _mm256_loadu_pd(src + 8);
					ymm_src3 = _mm256_loadu_pd(src + 12);
					ymm_src4 = _mm256_loadu_pd(src + 16);
					ymm_src5 = _mm256_loadu_pd(src + 20);
					ymm_src6 = _mm256_loadu_pd(src + 24);
					ymm_src7 = _mm256_loadu_pd(src + 28);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					ymm_src0 = _mm256_max_pd(ymm_src0, min);
					ymm_src1 = _mm256_max_pd(ymm_src1, min);
					ymm_src2 = _mm256_max_pd(ymm_src2, min);
					ymm_src3 = _mm256_max_pd(ymm_src3, min);
					ymm_src4 = _mm256_max_pd(ymm_src4, min);
					ymm_src5 = _mm256_max_pd(ymm_src5, min);
					ymm_src6 = _mm256_max_pd(ymm_src6, min);
					ymm_src7 = _mm256_max_pd(ymm_src7, min);
					ymm_src0 = _mm256_min_pd(ymm_src0, max);
					ymm_src1 = _mm256_min_pd(ymm_src1, max);
					ymm_src2 = _mm256_min_pd(ymm_src2, max);
					ymm_src3 = _mm256_min_pd(ymm_src3, max);
					ymm_src4 = _mm256_min_pd(ymm_src4, max);
					ymm_src5 = _mm256_min_pd(ymm_src5, max);
					ymm_src6 = _mm256_min_pd(ymm_src6, max);
					ymm_src7 = _mm256_min_pd(ymm_src7, max);
					ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
					ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
					ymm_dst2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src2));
					ymm_dst3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src3));
					ymm_dst4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src4));
					ymm_dst5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src5));
					ymm_dst6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src6));
					ymm_dst7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src7));
					ymm_dst0 = _mm256_packus_epi32(ymm_dst0, ymm_dst1);
					ymm_dst2 = _mm256_packus_epi32(ymm_dst2, ymm_dst3);
					ymm_dst4 = _mm256_packus_epi32(ymm_dst4, ymm_dst5);
					ymm_dst6 = _mm256_packus_epi32(ymm_dst6, ymm_dst7);
					ymm_dst0 = _mm256_packus_epi16(ymm_dst0, ymm_dst2);
					ymm_dst4 = _mm256_packus_epi16(ymm_dst4, ymm_dst6);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 1, _mm256_castsi256_si128(ymm_dst4));
					src += 32;
					dst += 32;
				}
			}
		}

		template <>
		inline void cvtspd_avx2_large<signed short>(signed short* dst, const double* src, size_t n)
		{
			const size_t padding = 8 - (reinterpret_cast<size_t>(dst) & 7);
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT16_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT16_MAX));
			__m256d ymm_src0, ymm_src1, ymm_src2, ymm_src3, ymm_src4, ymm_src5, ymm_src6, ymm_src7;
			__m256i ymm_dst0, ymm_dst1, ymm_dst2, ymm_dst3, ymm_dst4, ymm_dst5, ymm_dst6, ymm_dst7;

			// Align the destination to a 16-byte boundary.
			ymm_src0 = _mm256_loadu_pd(src);
			ymm_src1 = _mm256_loadu_pd(src + 4);
			ymm_src0 = _mm256_max_pd(ymm_src0, min);
			ymm_src1 = _mm256_max_pd(ymm_src1, min);
			ymm_src0 = _mm256_min_pd(ymm_src0, max);
			ymm_src1 = _mm256_min_pd(ymm_src1, max);
			ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
			ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
			ymm_dst0 = _mm256_packs_epi32(ymm_dst0, ymm_dst1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
			dst += padding;
			src += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			// If the source is aligned on a 32-byte boundary.
			if ((reinterpret_cast<size_t>(src) & 31) == 0)
			{
				for (; n >= 32; n -= 32)
				{
					ymm_src0 = _mm256_load_pd(src);
					ymm_src1 = _mm256_load_pd(src + 4);
					ymm_src2 = _mm256_load_pd(src + 8);
					ymm_src3 = _mm256_load_pd(src + 12);
					ymm_src4 = _mm256_load_pd(src + 16);
					ymm_src5 = _mm256_load_pd(src + 20);
					ymm_src6 = _mm256_load_pd(src + 24);
					ymm_src7 = _mm256_load_pd(src + 28);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					ymm_src0 = _mm256_max_pd(ymm_src0, min);
					ymm_src1 = _mm256_max_pd(ymm_src1, min);
					ymm_src2 = _mm256_max_pd(ymm_src2, min);
					ymm_src3 = _mm256_max_pd(ymm_src3, min);
					ymm_src4 = _mm256_max_pd(ymm_src4, min);
					ymm_src5 = _mm256_max_pd(ymm_src5, min);
					ymm_src6 = _mm256_max_pd(ymm_src6, min);
					ymm_src7 = _mm256_max_pd(ymm_src7, min);
					ymm_src0 = _mm256_min_pd(ymm_src0, max);
					ymm_src1 = _mm256_min_pd(ymm_src1, max);
					ymm_src2 = _mm256_min_pd(ymm_src2, max);
					ymm_src3 = _mm256_min_pd(ymm_src3, max);
					ymm_src4 = _mm256_min_pd(ymm_src4, max);
					ymm_src5 = _mm256_min_pd(ymm_src5, max);
					ymm_src6 = _mm256_min_pd(ymm_src6, max);
					ymm_src7 = _mm256_min_pd(ymm_src7, max);
					ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
					ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
					ymm_dst2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src2));
					ymm_dst3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src3));
					ymm_dst4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src4));
					ymm_dst5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src5));
					ymm_dst6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src6));
					ymm_dst7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src7));
					ymm_dst0 = _mm256_packs_epi32(ymm_dst0, ymm_dst1);
					ymm_dst2 = _mm256_packs_epi32(ymm_dst2, ymm_dst3);
					ymm_dst4 = _mm256_packs_epi32(ymm_dst4, ymm_dst5);
					ymm_dst6 = _mm256_packs_epi32(ymm_dst6, ymm_dst7);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 1, _mm256_castsi256_si128(ymm_dst2));
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 2, _mm256_castsi256_si128(ymm_dst4));
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 3, _mm256_castsi256_si128(ymm_dst6));
					src += 32;
					dst += 32;
				}
			}
			else
			{
				for (; n >= 32; n -= 32)
				{
					ymm_src0 = _mm256_loadu_pd(src);
					ymm_src1 = _mm256_loadu_pd(src + 4);
					ymm_src2 = _mm256_loadu_pd(src + 8);
					ymm_src3 = _mm256_loadu_pd(src + 12);
					ymm_src4 = _mm256_loadu_pd(src + 16);
					ymm_src5 = _mm256_loadu_pd(src + 20);
					ymm_src6 = _mm256_loadu_pd(src + 24);
					ymm_src7 = _mm256_loadu_pd(src + 28);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					ymm_src0 = _mm256_max_pd(ymm_src0, min);
					ymm_src1 = _mm256_max_pd(ymm_src1, min);
					ymm_src2 = _mm256_max_pd(ymm_src2, min);
					ymm_src3 = _mm256_max_pd(ymm_src3, min);
					ymm_src4 = _mm256_max_pd(ymm_src4, min);
					ymm_src5 = _mm256_max_pd(ymm_src5, min);
					ymm_src6 = _mm256_max_pd(ymm_src6, min);
					ymm_src7 = _mm256_max_pd(ymm_src7, min);
					ymm_src0 = _mm256_min_pd(ymm_src0, max);
					ymm_src1 = _mm256_min_pd(ymm_src1, max);
					ymm_src2 = _mm256_min_pd(ymm_src2, max);
					ymm_src3 = _mm256_min_pd(ymm_src3, max);
					ymm_src4 = _mm256_min_pd(ymm_src4, max);
					ymm_src5 = _mm256_min_pd(ymm_src5, max);
					ymm_src6 = _mm256_min_pd(ymm_src6, max);
					ymm_src7 = _mm256_min_pd(ymm_src7, max);
					ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
					ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
					ymm_dst2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src2));
					ymm_dst3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src3));
					ymm_dst4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src4));
					ymm_dst5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src5));
					ymm_dst6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src6));
					ymm_dst7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src7));
					ymm_dst0 = _mm256_packs_epi32(ymm_dst0, ymm_dst1);
					ymm_dst2 = _mm256_packs_epi32(ymm_dst2, ymm_dst3);
					ymm_dst4 = _mm256_packs_epi32(ymm_dst4, ymm_dst5);
					ymm_dst6 = _mm256_packs_epi32(ymm_dst6, ymm_dst7);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 1, _mm256_castsi256_si128(ymm_dst2));
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 2, _mm256_castsi256_si128(ymm_dst4));
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 3, _mm256_castsi256_si128(ymm_dst6));
					src += 32;
					dst += 32;
				}
			}
		}

		template <>
		inline void cvtspd_avx2_large<unsigned short>(unsigned short* dst, const double* src, size_t n)
		{
			const size_t padding = 8 - (reinterpret_cast<size_t>(dst) & 7);
			const __m256d min = _mm256_setzero_pd();
			const __m256d max = _mm256_set1_pd(static_cast<double>(UINT16_MAX));
			__m256d ymm_src0, ymm_src1, ymm_src2, ymm_src3, ymm_src4, ymm_src5, ymm_src6, ymm_src7;
			__m256i ymm_dst0, ymm_dst1, ymm_dst2, ymm_dst3, ymm_dst4, ymm_dst5, ymm_dst6, ymm_dst7;

			// Align the destination to a 16-byte boundary.
			ymm_src0 = _mm256_loadu_pd(src);
			ymm_src1 = _mm256_loadu_pd(src + 4);
			ymm_src0 = _mm256_max_pd(ymm_src0, min);
			ymm_src1 = _mm256_max_pd(ymm_src1, min);
			ymm_src0 = _mm256_min_pd(ymm_src0, max);
			ymm_src1 = _mm256_min_pd(ymm_src1, max);
			ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
			ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
			ymm_dst0 = _mm256_packus_epi32(ymm_dst0, ymm_dst1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
			dst += padding;
			src += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			// If the source is aligned on a 32-byte boundary.
			if ((reinterpret_cast<size_t>(src) & 31) == 0)
			{
				for (; n >= 32; n -= 32)
				{
					ymm_src0 = _mm256_load_pd(src);
					ymm_src1 = _mm256_load_pd(src + 4);
					ymm_src2 = _mm256_load_pd(src + 8);
					ymm_src3 = _mm256_load_pd(src + 12);
					ymm_src4 = _mm256_load_pd(src + 16);
					ymm_src5 = _mm256_load_pd(src + 20);
					ymm_src6 = _mm256_load_pd(src + 24);
					ymm_src7 = _mm256_load_pd(src + 28);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					ymm_src0 = _mm256_max_pd(ymm_src0, min);
					ymm_src1 = _mm256_max_pd(ymm_src1, min);
					ymm_src2 = _mm256_max_pd(ymm_src2, min);
					ymm_src3 = _mm256_max_pd(ymm_src3, min);
					ymm_src4 = _mm256_max_pd(ymm_src4, min);
					ymm_src5 = _mm256_max_pd(ymm_src5, min);
					ymm_src6 = _mm256_max_pd(ymm_src6, min);
					ymm_src7 = _mm256_max_pd(ymm_src7, min);
					ymm_src0 = _mm256_min_pd(ymm_src0, max);
					ymm_src1 = _mm256_min_pd(ymm_src1, max);
					ymm_src2 = _mm256_min_pd(ymm_src2, max);
					ymm_src3 = _mm256_min_pd(ymm_src3, max);
					ymm_src4 = _mm256_min_pd(ymm_src4, max);
					ymm_src5 = _mm256_min_pd(ymm_src5, max);
					ymm_src6 = _mm256_min_pd(ymm_src6, max);
					ymm_src7 = _mm256_min_pd(ymm_src7, max);
					ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
					ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
					ymm_dst2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src2));
					ymm_dst3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src3));
					ymm_dst4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src4));
					ymm_dst5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src5));
					ymm_dst6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src6));
					ymm_dst7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src7));
					ymm_dst0 = _mm256_packus_epi32(ymm_dst0, ymm_dst1);
					ymm_dst2 = _mm256_packus_epi32(ymm_dst2, ymm_dst3);
					ymm_dst4 = _mm256_packus_epi32(ymm_dst4, ymm_dst5);
					ymm_dst6 = _mm256_packus_epi32(ymm_dst6, ymm_dst7);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 1, _mm256_castsi256_si128(ymm_dst2));
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 2, _mm256_castsi256_si128(ymm_dst4));
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 3, _mm256_castsi256_si128(ymm_dst6));
					src += 32;
					dst += 32;
				}
			}
			else
			{
				for (; n >= 32; n -= 32)
				{
					ymm_src0 = _mm256_loadu_pd(src);
					ymm_src1 = _mm256_loadu_pd(src + 4);
					ymm_src2 = _mm256_loadu_pd(src + 8);
					ymm_src3 = _mm256_loadu_pd(src + 12);
					ymm_src4 = _mm256_loadu_pd(src + 16);
					ymm_src5 = _mm256_loadu_pd(src + 20);
					ymm_src6 = _mm256_loadu_pd(src + 24);
					ymm_src7 = _mm256_loadu_pd(src + 28);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					ymm_src0 = _mm256_max_pd(ymm_src0, min);
					ymm_src1 = _mm256_max_pd(ymm_src1, min);
					ymm_src2 = _mm256_max_pd(ymm_src2, min);
					ymm_src3 = _mm256_max_pd(ymm_src3, min);
					ymm_src4 = _mm256_max_pd(ymm_src4, min);
					ymm_src5 = _mm256_max_pd(ymm_src5, min);
					ymm_src6 = _mm256_max_pd(ymm_src6, min);
					ymm_src7 = _mm256_max_pd(ymm_src7, min);
					ymm_src0 = _mm256_min_pd(ymm_src0, max);
					ymm_src1 = _mm256_min_pd(ymm_src1, max);
					ymm_src2 = _mm256_min_pd(ymm_src2, max);
					ymm_src3 = _mm256_min_pd(ymm_src3, max);
					ymm_src4 = _mm256_min_pd(ymm_src4, max);
					ymm_src5 = _mm256_min_pd(ymm_src5, max);
					ymm_src6 = _mm256_min_pd(ymm_src6, max);
					ymm_src7 = _mm256_min_pd(ymm_src7, max);
					ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
					ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
					ymm_dst2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src2));
					ymm_dst3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src3));
					ymm_dst4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src4));
					ymm_dst5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src5));
					ymm_dst6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src6));
					ymm_dst7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src7));
					ymm_dst0 = _mm256_packus_epi32(ymm_dst0, ymm_dst1);
					ymm_dst2 = _mm256_packus_epi32(ymm_dst2, ymm_dst3);
					ymm_dst4 = _mm256_packus_epi32(ymm_dst4, ymm_dst5);
					ymm_dst6 = _mm256_packus_epi32(ymm_dst6, ymm_dst7);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 1, _mm256_castsi256_si128(ymm_dst2));
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 2, _mm256_castsi256_si128(ymm_dst4));
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 3, _mm256_castsi256_si128(ymm_dst6));
					src += 32;
					dst += 32;
				}
			}
		}

		template <>
		inline void cvtspd_avx2_large<signed int>(signed int* dst, const double* src, size_t n)
		{
			const size_t padding = 4 - (reinterpret_cast<size_t>(dst) & 3);
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT32_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT32_MAX));
			__m256d ymm_src0, ymm_src1, ymm_src2, ymm_src3, ymm_src4, ymm_src5, ymm_src6, ymm_src7;
			__m128i xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3, xmm_dst4, xmm_dst5, xmm_dst6, xmm_dst7;

			// Align the destination to a 16-byte boundary.
			ymm_src0 = _mm256_loadu_pd(src);
			ymm_src0 = _mm256_max_pd(ymm_src0, min);
			ymm_src0 = _mm256_min_pd(ymm_src0, max);
			xmm_dst0 = _mm256_cvttpd_epi32(ymm_src0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
			dst += padding;
			src += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			// If the source is aligned on a 32-byte boundary.
			if ((reinterpret_cast<size_t>(src) & 31) == 0)
			{
				for (; n >= 32; n -= 32)
				{
					ymm_src0 = _mm256_load_pd(src);
					ymm_src1 = _mm256_load_pd(src + 4);
					ymm_src2 = _mm256_load_pd(src + 8);
					ymm_src3 = _mm256_load_pd(src + 12);
					ymm_src4 = _mm256_load_pd(src + 16);
					ymm_src5 = _mm256_load_pd(src + 20);
					ymm_src6 = _mm256_load_pd(src + 24);
					ymm_src7 = _mm256_load_pd(src + 28);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					ymm_src0 = _mm256_max_pd(ymm_src0, min);
					ymm_src1 = _mm256_max_pd(ymm_src1, min);
					ymm_src2 = _mm256_max_pd(ymm_src2, min);
					ymm_src3 = _mm256_max_pd(ymm_src3, min);
					ymm_src4 = _mm256_max_pd(ymm_src4, min);
					ymm_src5 = _mm256_max_pd(ymm_src5, min);
					ymm_src6 = _mm256_max_pd(ymm_src6, min);
					ymm_src7 = _mm256_max_pd(ymm_src7, min);
					ymm_src0 = _mm256_min_pd(ymm_src0, max);
					ymm_src1 = _mm256_min_pd(ymm_src1, max);
					ymm_src2 = _mm256_min_pd(ymm_src2, max);
					ymm_src3 = _mm256_min_pd(ymm_src3, max);
					ymm_src4 = _mm256_min_pd(ymm_src4, max);
					ymm_src5 = _mm256_min_pd(ymm_src5, max);
					ymm_src6 = _mm256_min_pd(ymm_src6, max);
					ymm_src7 = _mm256_min_pd(ymm_src7, max);
					xmm_dst0 = _mm256_cvttpd_epi32(ymm_src0);
					xmm_dst1 = _mm256_cvttpd_epi32(ymm_src1);
					xmm_dst2 = _mm256_cvttpd_epi32(ymm_src2);
					xmm_dst3 = _mm256_cvttpd_epi32(ymm_src3);
					xmm_dst4 = _mm256_cvttpd_epi32(ymm_src4);
					xmm_dst5 = _mm256_cvttpd_epi32(ymm_src5);
					xmm_dst6 = _mm256_cvttpd_epi32(ymm_src6);
					xmm_dst7 = _mm256_cvttpd_epi32(ymm_src7);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst1);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 2, xmm_dst2);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 3, xmm_dst3);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 4, xmm_dst4);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 5, xmm_dst5);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 6, xmm_dst6);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 7, xmm_dst7);
					src += 32;
					dst += 32;
				}
			}
			else
			{
				for (; n >= 32; n -= 32)
				{
					ymm_src0 = _mm256_loadu_pd(src);
					ymm_src1 = _mm256_loadu_pd(src + 4);
					ymm_src2 = _mm256_loadu_pd(src + 8);
					ymm_src3 = _mm256_loadu_pd(src + 12);
					ymm_src4 = _mm256_loadu_pd(src + 16);
					ymm_src5 = _mm256_loadu_pd(src + 20);
					ymm_src6 = _mm256_loadu_pd(src + 24);
					ymm_src7 = _mm256_loadu_pd(src + 28);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					ymm_src0 = _mm256_max_pd(ymm_src0, min);
					ymm_src1 = _mm256_max_pd(ymm_src1, min);
					ymm_src2 = _mm256_max_pd(ymm_src2, min);
					ymm_src3 = _mm256_max_pd(ymm_src3, min);
					ymm_src4 = _mm256_max_pd(ymm_src4, min);
					ymm_src5 = _mm256_max_pd(ymm_src5, min);
					ymm_src6 = _mm256_max_pd(ymm_src6, min);
					ymm_src7 = _mm256_max_pd(ymm_src7, min);
					ymm_src0 = _mm256_min_pd(ymm_src0, max);
					ymm_src1 = _mm256_min_pd(ymm_src1, max);
					ymm_src2 = _mm256_min_pd(ymm_src2, max);
					ymm_src3 = _mm256_min_pd(ymm_src3, max);
					ymm_src4 = _mm256_min_pd(ymm_src4, max);
					ymm_src5 = _mm256_min_pd(ymm_src5, max);
					ymm_src6 = _mm256_min_pd(ymm_src6, max);
					ymm_src7 = _mm256_min_pd(ymm_src7, max);
					xmm_dst0 = _mm256_cvttpd_epi32(ymm_src0);
					xmm_dst1 = _mm256_cvttpd_epi32(ymm_src1);
					xmm_dst2 = _mm256_cvttpd_epi32(ymm_src2);
					xmm_dst3 = _mm256_cvttpd_epi32(ymm_src3);
					xmm_dst4 = _mm256_cvttpd_epi32(ymm_src4);
					xmm_dst5 = _mm256_cvttpd_epi32(ymm_src5);
					xmm_dst6 = _mm256_cvttpd_epi32(ymm_src6);
					xmm_dst7 = _mm256_cvttpd_epi32(ymm_src7);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst1);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 2, xmm_dst2);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 3, xmm_dst3);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 4, xmm_dst4);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 5, xmm_dst5);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 6, xmm_dst6);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 7, xmm_dst7);
					src += 32;
					dst += 32;
				}
			}
		}

		template <>
		inline void cvtspd_avx2_large<unsigned int>(unsigned int* dst, const double* src, size_t n)
		{
			const size_t padding = 4 - (reinterpret_cast<size_t>(dst) & 3);
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT32_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT32_MAX));
			const __m256d offset = _mm256_set1_pd(2.147483648e+9);
			const __m256i shift = _mm256_set1_epi32(2147483648);
			__m256d ymm_src0, ymm_src1, ymm_src2, ymm_src3, ymm_src4, ymm_src5, ymm_src6, ymm_src7;
			__m256i ymm_dst0, ymm_dst1, ymm_dst2, ymm_dst3, ymm_dst4, ymm_dst5, ymm_dst6, ymm_dst7;

			// Align the destination to a 16-byte boundary.
			ymm_src0 = _mm256_loadu_pd(src);
			ymm_src0 = _mm256_sub_pd(ymm_src0, offset);
			ymm_src0 = _mm256_max_pd(ymm_src0, min);
			ymm_src0 = _mm256_min_pd(ymm_src0, max);
			ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
			ymm_dst0 = _mm256_add_epi32(ymm_dst0, shift);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
			dst += padding;
			src += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			// If the source is aligned on a 32-byte boundary.
			if ((reinterpret_cast<size_t>(src) & 31) == 0)
			{
				for (; n >= 32; n -= 32)
				{
					ymm_src0 = _mm256_load_pd(src);
					ymm_src1 = _mm256_load_pd(src + 4);
					ymm_src2 = _mm256_load_pd(src + 8);
					ymm_src3 = _mm256_load_pd(src + 12);
					ymm_src4 = _mm256_load_pd(src + 16);
					ymm_src5 = _mm256_load_pd(src + 20);
					ymm_src6 = _mm256_load_pd(src + 24);
					ymm_src7 = _mm256_load_pd(src + 28);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					ymm_src0 = _mm256_sub_pd(ymm_src0, offset);
					ymm_src1 = _mm256_sub_pd(ymm_src1, offset);
					ymm_src2 = _mm256_sub_pd(ymm_src2, offset);
					ymm_src3 = _mm256_sub_pd(ymm_src3, offset);
					ymm_src4 = _mm256_sub_pd(ymm_src4, offset);
					ymm_src5 = _mm256_sub_pd(ymm_src5, offset);
					ymm_src6 = _mm256_sub_pd(ymm_src6, offset);
					ymm_src7 = _mm256_sub_pd(ymm_src7, offset);
					ymm_src0 = _mm256_max_pd(ymm_src0, min);
					ymm_src1 = _mm256_max_pd(ymm_src1, min);
					ymm_src2 = _mm256_max_pd(ymm_src2, min);
					ymm_src3 = _mm256_max_pd(ymm_src3, min);
					ymm_src4 = _mm256_max_pd(ymm_src4, min);
					ymm_src5 = _mm256_max_pd(ymm_src5, min);
					ymm_src6 = _mm256_max_pd(ymm_src6, min);
					ymm_src7 = _mm256_max_pd(ymm_src7, min);
					ymm_src0 = _mm256_min_pd(ymm_src0, max);
					ymm_src1 = _mm256_min_pd(ymm_src1, max);
					ymm_src2 = _mm256_min_pd(ymm_src2, max);
					ymm_src3 = _mm256_min_pd(ymm_src3, max);
					ymm_src4 = _mm256_min_pd(ymm_src4, max);
					ymm_src5 = _mm256_min_pd(ymm_src5, max);
					ymm_src6 = _mm256_min_pd(ymm_src6, max);
					ymm_src7 = _mm256_min_pd(ymm_src7, max);
					ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
					ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
					ymm_dst2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src2));
					ymm_dst3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src3));
					ymm_dst4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src4));
					ymm_dst5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src5));
					ymm_dst6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src6));
					ymm_dst7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src7));
					ymm_dst0 = _mm256_add_epi32(ymm_dst0, shift);
					ymm_dst1 = _mm256_add_epi32(ymm_dst1, shift);
					ymm_dst2 = _mm256_add_epi32(ymm_dst2, shift);
					ymm_dst3 = _mm256_add_epi32(ymm_dst3, shift);
					ymm_dst4 = _mm256_add_epi32(ymm_dst4, shift);
					ymm_dst5 = _mm256_add_epi32(ymm_dst5, shift);
					ymm_dst6 = _mm256_add_epi32(ymm_dst6, shift);
					ymm_dst7 = _mm256_add_epi32(ymm_dst7, shift);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 1, _mm256_castsi256_si128(ymm_dst1));
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 2, _mm256_castsi256_si128(ymm_dst2));
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 3, _mm256_castsi256_si128(ymm_dst3));
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 4, _mm256_castsi256_si128(ymm_dst4));
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 5, _mm256_castsi256_si128(ymm_dst5));
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 6, _mm256_castsi256_si128(ymm_dst6));
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 7, _mm256_castsi256_si128(ymm_dst7));
					src += 32;
					dst += 32;
				}
			}
			else
			{
				for (; n >= 32; n -= 32)
				{
					ymm_src0 = _mm256_loadu_pd(src);
					ymm_src1 = _mm256_loadu_pd(src + 4);
					ymm_src2 = _mm256_loadu_pd(src + 8);
					ymm_src3 = _mm256_loadu_pd(src + 12);
					ymm_src4 = _mm256_loadu_pd(src + 16);
					ymm_src5 = _mm256_loadu_pd(src + 20);
					ymm_src6 = _mm256_loadu_pd(src + 24);
					ymm_src7 = _mm256_loadu_pd(src + 28);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					ymm_src0 = _mm256_sub_pd(ymm_src0, offset);
					ymm_src1 = _mm256_sub_pd(ymm_src1, offset);
					ymm_src2 = _mm256_sub_pd(ymm_src2, offset);
					ymm_src3 = _mm256_sub_pd(ymm_src3, offset);
					ymm_src4 = _mm256_sub_pd(ymm_src4, offset);
					ymm_src5 = _mm256_sub_pd(ymm_src5, offset);
					ymm_src6 = _mm256_sub_pd(ymm_src6, offset);
					ymm_src7 = _mm256_sub_pd(ymm_src7, offset);
					ymm_src0 = _mm256_max_pd(ymm_src0, min);
					ymm_src1 = _mm256_max_pd(ymm_src1, min);
					ymm_src2 = _mm256_max_pd(ymm_src2, min);
					ymm_src3 = _mm256_max_pd(ymm_src3, min);
					ymm_src4 = _mm256_max_pd(ymm_src4, min);
					ymm_src5 = _mm256_max_pd(ymm_src5, min);
					ymm_src6 = _mm256_max_pd(ymm_src6, min);
					ymm_src7 = _mm256_max_pd(ymm_src7, min);
					ymm_src0 = _mm256_min_pd(ymm_src0, max);
					ymm_src1 = _mm256_min_pd(ymm_src1, max);
					ymm_src2 = _mm256_min_pd(ymm_src2, max);
					ymm_src3 = _mm256_min_pd(ymm_src3, max);
					ymm_src4 = _mm256_min_pd(ymm_src4, max);
					ymm_src5 = _mm256_min_pd(ymm_src5, max);
					ymm_src6 = _mm256_min_pd(ymm_src6, max);
					ymm_src7 = _mm256_min_pd(ymm_src7, max);
					ymm_dst0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src0));
					ymm_dst1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src1));
					ymm_dst2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src2));
					ymm_dst3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src3));
					ymm_dst4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src4));
					ymm_dst5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src5));
					ymm_dst6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src6));
					ymm_dst7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_src7));
					ymm_dst0 = _mm256_add_epi32(ymm_dst0, shift);
					ymm_dst1 = _mm256_add_epi32(ymm_dst1, shift);
					ymm_dst2 = _mm256_add_epi32(ymm_dst2, shift);
					ymm_dst3 = _mm256_add_epi32(ymm_dst3, shift);
					ymm_dst4 = _mm256_add_epi32(ymm_dst4, shift);
					ymm_dst5 = _mm256_add_epi32(ymm_dst5, shift);
					ymm_dst6 = _mm256_add_epi32(ymm_dst6, shift);
					ymm_dst7 = _mm256_add_epi32(ymm_dst7, shift);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst), _mm256_castsi256_si128(ymm_dst0));
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 1, _mm256_castsi256_si128(ymm_dst1));
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 2, _mm256_castsi256_si128(ymm_dst2));
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 3, _mm256_castsi256_si128(ymm_dst3));
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 4, _mm256_castsi256_si128(ymm_dst4));
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 5, _mm256_castsi256_si128(ymm_dst5));
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 6, _mm256_castsi256_si128(ymm_dst6));
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 7, _mm256_castsi256_si128(ymm_dst7));
					src += 32;
					dst += 32;
				}
			}
		}

		template <>
		inline void cvtspd_avx2_large<float>(float* dst, const double* src, size_t n)
		{
			const size_t padding = 4 - (reinterpret_cast<size_t>(dst) & 3);
			const __m256d min = _mm256_set1_pd(static_cast<double>(-FLT_MAX));
			const __m256d max = _mm256_set1_pd(static_cast<double>(FLT_MAX));
			__m256d ymm_src0, ymm_src1, ymm_src2, ymm_src3, ymm_src4, ymm_src5, ymm_src6, ymm_src7;
			__m128 xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3, xmm_dst4, xmm_dst5, xmm_dst6, xmm_dst7;

			// Align the destination to a 16-byte boundary.
			ymm_src0 = _mm256_loadu_pd(src);
			ymm_src0 = _mm256_max_pd(ymm_src0, min);
			ymm_src0 = _mm256_min_pd(ymm_src0, max);
			xmm_dst0 = _mm256_cvtpd_ps(ymm_src0);
			_mm_storeu_ps(dst, xmm_dst0);
			dst += padding;
			src += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			// If the source is aligned on a 32-byte boundary.
			if ((reinterpret_cast<size_t>(src) & 31) == 0)
			{
				for (; n >= 32; n -= 32)
				{
					ymm_src0 = _mm256_load_pd(src);
					ymm_src1 = _mm256_load_pd(src + 4);
					ymm_src2 = _mm256_load_pd(src + 8);
					ymm_src3 = _mm256_load_pd(src + 12);
					ymm_src4 = _mm256_load_pd(src + 16);
					ymm_src5 = _mm256_load_pd(src + 20);
					ymm_src6 = _mm256_load_pd(src + 24);
					ymm_src7 = _mm256_load_pd(src + 28);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					ymm_src0 = _mm256_max_pd(ymm_src0, min);
					ymm_src1 = _mm256_max_pd(ymm_src1, min);
					ymm_src2 = _mm256_max_pd(ymm_src2, min);
					ymm_src3 = _mm256_max_pd(ymm_src3, min);
					ymm_src4 = _mm256_max_pd(ymm_src4, min);
					ymm_src5 = _mm256_max_pd(ymm_src5, min);
					ymm_src6 = _mm256_max_pd(ymm_src6, min);
					ymm_src7 = _mm256_max_pd(ymm_src7, min);
					ymm_src0 = _mm256_min_pd(ymm_src0, max);
					ymm_src1 = _mm256_min_pd(ymm_src1, max);
					ymm_src2 = _mm256_min_pd(ymm_src2, max);
					ymm_src3 = _mm256_min_pd(ymm_src3, max);
					ymm_src4 = _mm256_min_pd(ymm_src4, max);
					ymm_src5 = _mm256_min_pd(ymm_src5, max);
					ymm_src6 = _mm256_min_pd(ymm_src6, max);
					ymm_src7 = _mm256_min_pd(ymm_src7, max);
					xmm_dst0 = _mm256_cvtpd_ps(ymm_src0);
					xmm_dst1 = _mm256_cvtpd_ps(ymm_src1);
					xmm_dst2 = _mm256_cvtpd_ps(ymm_src2);
					xmm_dst3 = _mm256_cvtpd_ps(ymm_src3);
					xmm_dst4 = _mm256_cvtpd_ps(ymm_src4);
					xmm_dst5 = _mm256_cvtpd_ps(ymm_src5);
					xmm_dst6 = _mm256_cvtpd_ps(ymm_src6);
					xmm_dst7 = _mm256_cvtpd_ps(ymm_src7);
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
					ymm_src0 = _mm256_loadu_pd(src);
					ymm_src1 = _mm256_loadu_pd(src + 4);
					ymm_src2 = _mm256_loadu_pd(src + 8);
					ymm_src3 = _mm256_loadu_pd(src + 12);
					ymm_src4 = _mm256_loadu_pd(src + 16);
					ymm_src5 = _mm256_loadu_pd(src + 20);
					ymm_src6 = _mm256_loadu_pd(src + 24);
					ymm_src7 = _mm256_loadu_pd(src + 28);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					ymm_src0 = _mm256_max_pd(ymm_src0, min);
					ymm_src1 = _mm256_max_pd(ymm_src1, min);
					ymm_src2 = _mm256_max_pd(ymm_src2, min);
					ymm_src3 = _mm256_max_pd(ymm_src3, min);
					ymm_src4 = _mm256_max_pd(ymm_src4, min);
					ymm_src5 = _mm256_max_pd(ymm_src5, min);
					ymm_src6 = _mm256_max_pd(ymm_src6, min);
					ymm_src7 = _mm256_max_pd(ymm_src7, min);
					ymm_src0 = _mm256_min_pd(ymm_src0, max);
					ymm_src1 = _mm256_min_pd(ymm_src1, max);
					ymm_src2 = _mm256_min_pd(ymm_src2, max);
					ymm_src3 = _mm256_min_pd(ymm_src3, max);
					ymm_src4 = _mm256_min_pd(ymm_src4, max);
					ymm_src5 = _mm256_min_pd(ymm_src5, max);
					ymm_src6 = _mm256_min_pd(ymm_src6, max);
					ymm_src7 = _mm256_min_pd(ymm_src7, max);
					xmm_dst0 = _mm256_cvtpd_ps(ymm_src0);
					xmm_dst1 = _mm256_cvtpd_ps(ymm_src1);
					xmm_dst2 = _mm256_cvtpd_ps(ymm_src2);
					xmm_dst3 = _mm256_cvtpd_ps(ymm_src3);
					xmm_dst4 = _mm256_cvtpd_ps(ymm_src4);
					xmm_dst5 = _mm256_cvtpd_ps(ymm_src5);
					xmm_dst6 = _mm256_cvtpd_ps(ymm_src6);
					xmm_dst7 = _mm256_cvtpd_ps(ymm_src7);
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

		// Function template impl_cvtspd

		template <class T>
		inline void impl_cvtspd(T* dst, const double* src, size_t n)
		{
			constexpr size_t threshold = simd::l2_cache_size / sizeof(double);
			// Small amount of data type conversion.
			if (n < 64)
				cvtspd_avx2_small(dst, src, n);
			// Medium amount data type conversion.
			else if (n < threshold)
			{
				cvtspd_avx2_medium(dst, src, n);
				cvtspd_avx2_small(dst, src, n);
			}
			// Large amount data type conversion.
			else
			{
				cvtspd_avx2_large(dst, src, n);
				cvtspd_avx2_small(dst, src, n);
			}
		}

	#elif defined(__AVX__) || defined(__SSE4_2__) || defined(__SSE4_1__)

		// Function template cvtspd_sse41_8

		template <class T>
		inline void cvtspd_sse41_8(T* dst, const double* src)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		inline void cvtspd_sse41_8<signed char>(signed char* dst, const double* src)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(INT8_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT8_MAX));
			__m128d xmm_src0 = _mm_loadu_pd(src);
			__m128d xmm_src1 = _mm_loadu_pd(src + 2);
			__m128d xmm_src2 = _mm_loadu_pd(src + 4);
			__m128d xmm_src3 = _mm_loadu_pd(src + 6);
			xmm_src0 = _mm_max_pd(xmm_src0, min);
			xmm_src1 = _mm_max_pd(xmm_src1, min);
			xmm_src2 = _mm_max_pd(xmm_src2, min);
			xmm_src3 = _mm_max_pd(xmm_src3, min);
			xmm_src0 = _mm_min_pd(xmm_src0, max);
			xmm_src1 = _mm_min_pd(xmm_src1, max);
			xmm_src2 = _mm_min_pd(xmm_src2, max);
			xmm_src3 = _mm_min_pd(xmm_src3, max);
			__m128i xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
			__m128i xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
			__m128i xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
			__m128i xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
			xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
			xmm_dst0 = _mm_packs_epi32(xmm_dst0, xmm_dst2);
			xmm_dst0 = _mm_packs_epi16(xmm_dst0, _mm_setzero_si128());
			_mm_storeu_si64(reinterpret_cast<__m128i*>(dst), xmm_dst0);
		}

		template <>
		inline void cvtspd_sse41_8<unsigned char>(unsigned char* dst, const double* src)
		{
			const __m128d min = _mm_setzero_pd();
			const __m128d max = _mm_set1_pd(static_cast<double>(UINT8_MAX));
			__m128d xmm_src0 = _mm_loadu_pd(src);
			__m128d xmm_src1 = _mm_loadu_pd(src + 2);
			__m128d xmm_src2 = _mm_loadu_pd(src + 4);
			__m128d xmm_src3 = _mm_loadu_pd(src + 6);
			xmm_src0 = _mm_max_pd(xmm_src0, min);
			xmm_src1 = _mm_max_pd(xmm_src1, min);
			xmm_src2 = _mm_max_pd(xmm_src2, min);
			xmm_src3 = _mm_max_pd(xmm_src3, min);
			xmm_src0 = _mm_min_pd(xmm_src0, max);
			xmm_src1 = _mm_min_pd(xmm_src1, max);
			xmm_src2 = _mm_min_pd(xmm_src2, max);
			xmm_src3 = _mm_min_pd(xmm_src3, max);
			__m128i xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
			__m128i xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
			__m128i xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
			__m128i xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
			xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
			xmm_dst0 = _mm_packus_epi32(xmm_dst0, xmm_dst2);
			xmm_dst0 = _mm_packus_epi16(xmm_dst0, _mm_setzero_si128());
			_mm_storeu_si64(reinterpret_cast<__m128i*>(dst), xmm_dst0);
		}

		template <>
		inline void cvtspd_sse41_8<signed short>(signed short* dst, const double* src)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(INT16_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT16_MAX));
			__m128d xmm_src0 = _mm_loadu_pd(src);
			__m128d xmm_src1 = _mm_loadu_pd(src + 2);
			__m128d xmm_src2 = _mm_loadu_pd(src + 4);
			__m128d xmm_src3 = _mm_loadu_pd(src + 6);
			xmm_src0 = _mm_max_pd(xmm_src0, min);
			xmm_src1 = _mm_max_pd(xmm_src1, min);
			xmm_src2 = _mm_max_pd(xmm_src2, min);
			xmm_src3 = _mm_max_pd(xmm_src3, min);
			xmm_src0 = _mm_min_pd(xmm_src0, max);
			xmm_src1 = _mm_min_pd(xmm_src1, max);
			xmm_src2 = _mm_min_pd(xmm_src2, max);
			xmm_src3 = _mm_min_pd(xmm_src3, max);
			__m128i xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
			__m128i xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
			__m128i xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
			__m128i xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
			xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
			xmm_dst0 = _mm_packs_epi32(xmm_dst0, xmm_dst2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
		}

		template <>
		inline void cvtspd_sse41_8<unsigned short>(unsigned short* dst, const double* src)
		{
			const __m128d min = _mm_setzero_pd();
			const __m128d max = _mm_set1_pd(static_cast<double>(UINT16_MAX));
			__m128d xmm_src0 = _mm_loadu_pd(src);
			__m128d xmm_src1 = _mm_loadu_pd(src + 2);
			__m128d xmm_src2 = _mm_loadu_pd(src + 4);
			__m128d xmm_src3 = _mm_loadu_pd(src + 6);
			xmm_src0 = _mm_max_pd(xmm_src0, min);
			xmm_src1 = _mm_max_pd(xmm_src1, min);
			xmm_src2 = _mm_max_pd(xmm_src2, min);
			xmm_src3 = _mm_max_pd(xmm_src3, min);
			xmm_src0 = _mm_min_pd(xmm_src0, max);
			xmm_src1 = _mm_min_pd(xmm_src1, max);
			xmm_src2 = _mm_min_pd(xmm_src2, max);
			xmm_src3 = _mm_min_pd(xmm_src3, max);
			__m128i xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
			__m128i xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
			__m128i xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
			__m128i xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
			xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
			xmm_dst0 = _mm_packus_epi32(xmm_dst0, xmm_dst2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
		}

		template <>
		inline void cvtspd_sse41_8<signed int>(signed int* dst, const double* src)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(INT32_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT32_MAX));
			__m128d xmm_src0 = _mm_loadu_pd(src);
			__m128d xmm_src1 = _mm_loadu_pd(src + 2);
			__m128d xmm_src2 = _mm_loadu_pd(src + 4);
			__m128d xmm_src3 = _mm_loadu_pd(src + 6);
			xmm_src0 = _mm_max_pd(xmm_src0, min);
			xmm_src1 = _mm_max_pd(xmm_src1, min);
			xmm_src2 = _mm_max_pd(xmm_src2, min);
			xmm_src3 = _mm_max_pd(xmm_src3, min);
			xmm_src0 = _mm_min_pd(xmm_src0, max);
			xmm_src1 = _mm_min_pd(xmm_src1, max);
			xmm_src2 = _mm_min_pd(xmm_src2, max);
			xmm_src3 = _mm_min_pd(xmm_src3, max);
			__m128i xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
			__m128i xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
			__m128i xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
			__m128i xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
			xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst2);
		}

		template <>
		inline void cvtspd_sse41_8<unsigned int>(unsigned int* dst, const double* src)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(INT32_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT32_MAX));
			const __m128d offset = _mm_set1_pd(2.147483648e+9);
			const __m128i shift = _mm_set1_epi32(2147483648);
			__m128d xmm_src0 = _mm_loadu_pd(src);
			__m128d xmm_src1 = _mm_loadu_pd(src + 2);
			__m128d xmm_src2 = _mm_loadu_pd(src + 4);
			__m128d xmm_src3 = _mm_loadu_pd(src + 6);
			xmm_src0 = _mm_sub_pd(xmm_src0, offset);
			xmm_src1 = _mm_sub_pd(xmm_src1, offset);
			xmm_src2 = _mm_sub_pd(xmm_src2, offset);
			xmm_src3 = _mm_sub_pd(xmm_src3, offset);
			xmm_src0 = _mm_max_pd(xmm_src0, min);
			xmm_src1 = _mm_max_pd(xmm_src1, min);
			xmm_src2 = _mm_max_pd(xmm_src2, min);
			xmm_src3 = _mm_max_pd(xmm_src3, min);
			xmm_src0 = _mm_min_pd(xmm_src0, max);
			xmm_src1 = _mm_min_pd(xmm_src1, max);
			xmm_src2 = _mm_min_pd(xmm_src2, max);
			xmm_src3 = _mm_min_pd(xmm_src3, max);
			__m128i xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
			__m128i xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
			__m128i xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
			__m128i xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
			xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
			xmm_dst0 = _mm_add_epi32(xmm_dst0, shift);
			xmm_dst2 = _mm_add_epi32(xmm_dst2, shift);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst2);
		}

		template <>
		inline void cvtspd_sse41_8<float>(float* dst, const double* src)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(-FLT_MAX));
			const __m128d max = _mm_set1_pd(static_cast<double>(FLT_MAX));
			__m128d xmm_src0 = _mm_loadu_pd(src);
			__m128d xmm_src1 = _mm_loadu_pd(src + 2);
			__m128d xmm_src2 = _mm_loadu_pd(src + 4);
			__m128d xmm_src3 = _mm_loadu_pd(src + 6);
			xmm_src0 = _mm_max_pd(xmm_src0, min);
			xmm_src1 = _mm_max_pd(xmm_src1, min);
			xmm_src2 = _mm_max_pd(xmm_src2, min);
			xmm_src3 = _mm_max_pd(xmm_src3, min);
			xmm_src0 = _mm_min_pd(xmm_src0, max);
			xmm_src1 = _mm_min_pd(xmm_src1, max);
			xmm_src2 = _mm_min_pd(xmm_src2, max);
			xmm_src3 = _mm_min_pd(xmm_src3, max);
			__m128 xmm_dst0 = _mm_cvtpd_ps(xmm_src0);
			__m128 xmm_dst1 = _mm_cvtpd_ps(xmm_src1);
			__m128 xmm_dst2 = _mm_cvtpd_ps(xmm_src2);
			__m128 xmm_dst3 = _mm_cvtpd_ps(xmm_src3);
			xmm_dst0 = _mm_shuffle_ps(xmm_dst0, xmm_dst1, _MM_SHUFFLE(1, 0, 1, 0));
			xmm_dst2 = _mm_shuffle_ps(xmm_dst2, xmm_dst3, _MM_SHUFFLE(1, 0, 1, 0));
			_mm_storeu_ps(dst, xmm_dst0);
			_mm_storeu_ps(dst + 4, xmm_dst2);
		}

		// Function template cvtspd_sse41_16

		template <class T>
		inline void cvtspd_sse41_16(T* dst, const double* src)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		inline void cvtspd_sse41_16<signed char>(signed char* dst, const double* src)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(INT8_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT8_MAX));
			__m128d xmm_src0 = _mm_loadu_pd(src);
			__m128d xmm_src1 = _mm_loadu_pd(src + 2);
			__m128d xmm_src2 = _mm_loadu_pd(src + 4);
			__m128d xmm_src3 = _mm_loadu_pd(src + 6);
			__m128d xmm_src4 = _mm_loadu_pd(src + 8);
			__m128d xmm_src5 = _mm_loadu_pd(src + 10);
			__m128d xmm_src6 = _mm_loadu_pd(src + 12);
			__m128d xmm_src7 = _mm_loadu_pd(src + 14);
			xmm_src0 = _mm_max_pd(xmm_src0, min);
			xmm_src1 = _mm_max_pd(xmm_src1, min);
			xmm_src2 = _mm_max_pd(xmm_src2, min);
			xmm_src3 = _mm_max_pd(xmm_src3, min);
			xmm_src4 = _mm_max_pd(xmm_src4, min);
			xmm_src5 = _mm_max_pd(xmm_src5, min);
			xmm_src6 = _mm_max_pd(xmm_src6, min);
			xmm_src7 = _mm_max_pd(xmm_src7, min);
			xmm_src0 = _mm_min_pd(xmm_src0, max);
			xmm_src1 = _mm_min_pd(xmm_src1, max);
			xmm_src2 = _mm_min_pd(xmm_src2, max);
			xmm_src3 = _mm_min_pd(xmm_src3, max);
			xmm_src4 = _mm_min_pd(xmm_src4, max);
			xmm_src5 = _mm_min_pd(xmm_src5, max);
			xmm_src6 = _mm_min_pd(xmm_src6, max);
			xmm_src7 = _mm_min_pd(xmm_src7, max);
			__m128i xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
			__m128i xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
			__m128i xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
			__m128i xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
			__m128i xmm_dst4 = _mm_cvttpd_epi32(xmm_src4);
			__m128i xmm_dst5 = _mm_cvttpd_epi32(xmm_src5);
			__m128i xmm_dst6 = _mm_cvttpd_epi32(xmm_src6);
			__m128i xmm_dst7 = _mm_cvttpd_epi32(xmm_src7);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
			xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
			xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
			xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
			xmm_dst0 = _mm_packs_epi32(xmm_dst0, xmm_dst2);
			xmm_dst4 = _mm_packs_epi32(xmm_dst4, xmm_dst6);
			xmm_dst0 = _mm_packs_epi16(xmm_dst0, xmm_dst4);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
		}

		template <>
		inline void cvtspd_sse41_16<unsigned char>(unsigned char* dst, const double* src)
		{
			const __m128d min = _mm_setzero_pd();
			const __m128d max = _mm_set1_pd(static_cast<double>(UINT8_MAX));
			__m128d xmm_src0 = _mm_loadu_pd(src);
			__m128d xmm_src1 = _mm_loadu_pd(src + 2);
			__m128d xmm_src2 = _mm_loadu_pd(src + 4);
			__m128d xmm_src3 = _mm_loadu_pd(src + 6);
			__m128d xmm_src4 = _mm_loadu_pd(src + 8);
			__m128d xmm_src5 = _mm_loadu_pd(src + 10);
			__m128d xmm_src6 = _mm_loadu_pd(src + 12);
			__m128d xmm_src7 = _mm_loadu_pd(src + 14);
			xmm_src0 = _mm_max_pd(xmm_src0, min);
			xmm_src1 = _mm_max_pd(xmm_src1, min);
			xmm_src2 = _mm_max_pd(xmm_src2, min);
			xmm_src3 = _mm_max_pd(xmm_src3, min);
			xmm_src4 = _mm_max_pd(xmm_src4, min);
			xmm_src5 = _mm_max_pd(xmm_src5, min);
			xmm_src6 = _mm_max_pd(xmm_src6, min);
			xmm_src7 = _mm_max_pd(xmm_src7, min);
			xmm_src0 = _mm_min_pd(xmm_src0, max);
			xmm_src1 = _mm_min_pd(xmm_src1, max);
			xmm_src2 = _mm_min_pd(xmm_src2, max);
			xmm_src3 = _mm_min_pd(xmm_src3, max);
			xmm_src4 = _mm_min_pd(xmm_src4, max);
			xmm_src5 = _mm_min_pd(xmm_src5, max);
			xmm_src6 = _mm_min_pd(xmm_src6, max);
			xmm_src7 = _mm_min_pd(xmm_src7, max);
			__m128i xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
			__m128i xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
			__m128i xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
			__m128i xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
			__m128i xmm_dst4 = _mm_cvttpd_epi32(xmm_src4);
			__m128i xmm_dst5 = _mm_cvttpd_epi32(xmm_src5);
			__m128i xmm_dst6 = _mm_cvttpd_epi32(xmm_src6);
			__m128i xmm_dst7 = _mm_cvttpd_epi32(xmm_src7);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
			xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
			xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
			xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
			xmm_dst0 = _mm_packus_epi32(xmm_dst0, xmm_dst2);
			xmm_dst4 = _mm_packus_epi32(xmm_dst4, xmm_dst6);
			xmm_dst0 = _mm_packus_epi16(xmm_dst0, xmm_dst4);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
		}

		template <>
		inline void cvtspd_sse41_16<signed short>(signed short* dst, const double* src)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(INT16_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT16_MAX));
			__m128d xmm_src0 = _mm_loadu_pd(src);
			__m128d xmm_src1 = _mm_loadu_pd(src + 2);
			__m128d xmm_src2 = _mm_loadu_pd(src + 4);
			__m128d xmm_src3 = _mm_loadu_pd(src + 6);
			__m128d xmm_src4 = _mm_loadu_pd(src + 8);
			__m128d xmm_src5 = _mm_loadu_pd(src + 10);
			__m128d xmm_src6 = _mm_loadu_pd(src + 12);
			__m128d xmm_src7 = _mm_loadu_pd(src + 14);
			xmm_src0 = _mm_max_pd(xmm_src0, min);
			xmm_src1 = _mm_max_pd(xmm_src1, min);
			xmm_src2 = _mm_max_pd(xmm_src2, min);
			xmm_src3 = _mm_max_pd(xmm_src3, min);
			xmm_src4 = _mm_max_pd(xmm_src4, min);
			xmm_src5 = _mm_max_pd(xmm_src5, min);
			xmm_src6 = _mm_max_pd(xmm_src6, min);
			xmm_src7 = _mm_max_pd(xmm_src7, min);
			xmm_src0 = _mm_min_pd(xmm_src0, max);
			xmm_src1 = _mm_min_pd(xmm_src1, max);
			xmm_src2 = _mm_min_pd(xmm_src2, max);
			xmm_src3 = _mm_min_pd(xmm_src3, max);
			xmm_src4 = _mm_min_pd(xmm_src4, max);
			xmm_src5 = _mm_min_pd(xmm_src5, max);
			xmm_src6 = _mm_min_pd(xmm_src6, max);
			xmm_src7 = _mm_min_pd(xmm_src7, max);
			__m128i xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
			__m128i xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
			__m128i xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
			__m128i xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
			__m128i xmm_dst4 = _mm_cvttpd_epi32(xmm_src4);
			__m128i xmm_dst5 = _mm_cvttpd_epi32(xmm_src5);
			__m128i xmm_dst6 = _mm_cvttpd_epi32(xmm_src6);
			__m128i xmm_dst7 = _mm_cvttpd_epi32(xmm_src7);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
			xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
			xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
			xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
			xmm_dst0 = _mm_packs_epi32(xmm_dst0, xmm_dst2);
			xmm_dst4 = _mm_packs_epi32(xmm_dst4, xmm_dst6);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst4);
		}

		template <>
		inline void cvtspd_sse41_16<unsigned short>(unsigned short* dst, const double* src)
		{
			const __m128d min = _mm_setzero_pd();
			const __m128d max = _mm_set1_pd(static_cast<double>(UINT16_MAX));
			__m128d xmm_src0 = _mm_loadu_pd(src);
			__m128d xmm_src1 = _mm_loadu_pd(src + 2);
			__m128d xmm_src2 = _mm_loadu_pd(src + 4);
			__m128d xmm_src3 = _mm_loadu_pd(src + 6);
			__m128d xmm_src4 = _mm_loadu_pd(src + 8);
			__m128d xmm_src5 = _mm_loadu_pd(src + 10);
			__m128d xmm_src6 = _mm_loadu_pd(src + 12);
			__m128d xmm_src7 = _mm_loadu_pd(src + 14);
			xmm_src0 = _mm_max_pd(xmm_src0, min);
			xmm_src1 = _mm_max_pd(xmm_src1, min);
			xmm_src2 = _mm_max_pd(xmm_src2, min);
			xmm_src3 = _mm_max_pd(xmm_src3, min);
			xmm_src4 = _mm_max_pd(xmm_src4, min);
			xmm_src5 = _mm_max_pd(xmm_src5, min);
			xmm_src6 = _mm_max_pd(xmm_src6, min);
			xmm_src7 = _mm_max_pd(xmm_src7, min);
			xmm_src0 = _mm_min_pd(xmm_src0, max);
			xmm_src1 = _mm_min_pd(xmm_src1, max);
			xmm_src2 = _mm_min_pd(xmm_src2, max);
			xmm_src3 = _mm_min_pd(xmm_src3, max);
			xmm_src4 = _mm_min_pd(xmm_src4, max);
			xmm_src5 = _mm_min_pd(xmm_src5, max);
			xmm_src6 = _mm_min_pd(xmm_src6, max);
			xmm_src7 = _mm_min_pd(xmm_src7, max);
			__m128i xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
			__m128i xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
			__m128i xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
			__m128i xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
			__m128i xmm_dst4 = _mm_cvttpd_epi32(xmm_src4);
			__m128i xmm_dst5 = _mm_cvttpd_epi32(xmm_src5);
			__m128i xmm_dst6 = _mm_cvttpd_epi32(xmm_src6);
			__m128i xmm_dst7 = _mm_cvttpd_epi32(xmm_src7);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
			xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
			xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
			xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
			xmm_dst0 = _mm_packus_epi32(xmm_dst0, xmm_dst2);
			xmm_dst4 = _mm_packus_epi32(xmm_dst4, xmm_dst6);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst4);
		}

		template <>
		inline void cvtspd_sse41_16<signed int>(signed int* dst, const double* src)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(INT32_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT32_MAX));
			__m128d xmm_src0 = _mm_loadu_pd(src);
			__m128d xmm_src1 = _mm_loadu_pd(src + 2);
			__m128d xmm_src2 = _mm_loadu_pd(src + 4);
			__m128d xmm_src3 = _mm_loadu_pd(src + 6);
			__m128d xmm_src4 = _mm_loadu_pd(src + 8);
			__m128d xmm_src5 = _mm_loadu_pd(src + 10);
			__m128d xmm_src6 = _mm_loadu_pd(src + 12);
			__m128d xmm_src7 = _mm_loadu_pd(src + 14);
			xmm_src0 = _mm_max_pd(xmm_src0, min);
			xmm_src1 = _mm_max_pd(xmm_src1, min);
			xmm_src2 = _mm_max_pd(xmm_src2, min);
			xmm_src3 = _mm_max_pd(xmm_src3, min);
			xmm_src4 = _mm_max_pd(xmm_src4, min);
			xmm_src5 = _mm_max_pd(xmm_src5, min);
			xmm_src6 = _mm_max_pd(xmm_src6, min);
			xmm_src7 = _mm_max_pd(xmm_src7, min);
			xmm_src0 = _mm_min_pd(xmm_src0, max);
			xmm_src1 = _mm_min_pd(xmm_src1, max);
			xmm_src2 = _mm_min_pd(xmm_src2, max);
			xmm_src3 = _mm_min_pd(xmm_src3, max);
			xmm_src4 = _mm_min_pd(xmm_src4, max);
			xmm_src5 = _mm_min_pd(xmm_src5, max);
			xmm_src6 = _mm_min_pd(xmm_src6, max);
			xmm_src7 = _mm_min_pd(xmm_src7, max);
			__m128i xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
			__m128i xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
			__m128i xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
			__m128i xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
			__m128i xmm_dst4 = _mm_cvttpd_epi32(xmm_src4);
			__m128i xmm_dst5 = _mm_cvttpd_epi32(xmm_src5);
			__m128i xmm_dst6 = _mm_cvttpd_epi32(xmm_src6);
			__m128i xmm_dst7 = _mm_cvttpd_epi32(xmm_src7);
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
		inline void cvtspd_sse41_16<unsigned int>(unsigned int* dst, const double* src)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(INT32_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT32_MAX));
			const __m128d offset = _mm_set1_pd(2.147483648e+9);
			const __m128i shift = _mm_set1_epi32(2147483648);
			__m128d xmm_src0 = _mm_loadu_pd(src);
			__m128d xmm_src1 = _mm_loadu_pd(src + 2);
			__m128d xmm_src2 = _mm_loadu_pd(src + 4);
			__m128d xmm_src3 = _mm_loadu_pd(src + 6);
			__m128d xmm_src4 = _mm_loadu_pd(src + 8);
			__m128d xmm_src5 = _mm_loadu_pd(src + 10);
			__m128d xmm_src6 = _mm_loadu_pd(src + 12);
			__m128d xmm_src7 = _mm_loadu_pd(src + 14);
			xmm_src0 = _mm_sub_pd(xmm_src0, offset);
			xmm_src1 = _mm_sub_pd(xmm_src1, offset);
			xmm_src2 = _mm_sub_pd(xmm_src2, offset);
			xmm_src3 = _mm_sub_pd(xmm_src3, offset);
			xmm_src4 = _mm_sub_pd(xmm_src4, offset);
			xmm_src5 = _mm_sub_pd(xmm_src5, offset);
			xmm_src6 = _mm_sub_pd(xmm_src6, offset);
			xmm_src7 = _mm_sub_pd(xmm_src7, offset);
			xmm_src0 = _mm_max_pd(xmm_src0, min);
			xmm_src1 = _mm_max_pd(xmm_src1, min);
			xmm_src2 = _mm_max_pd(xmm_src2, min);
			xmm_src3 = _mm_max_pd(xmm_src3, min);
			xmm_src4 = _mm_max_pd(xmm_src4, min);
			xmm_src5 = _mm_max_pd(xmm_src5, min);
			xmm_src6 = _mm_max_pd(xmm_src6, min);
			xmm_src7 = _mm_max_pd(xmm_src7, min);
			xmm_src0 = _mm_min_pd(xmm_src0, max);
			xmm_src1 = _mm_min_pd(xmm_src1, max);
			xmm_src2 = _mm_min_pd(xmm_src2, max);
			xmm_src3 = _mm_min_pd(xmm_src3, max);
			xmm_src4 = _mm_min_pd(xmm_src4, max);
			xmm_src5 = _mm_min_pd(xmm_src5, max);
			xmm_src6 = _mm_min_pd(xmm_src6, max);
			xmm_src7 = _mm_min_pd(xmm_src7, max);
			__m128i xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
			__m128i xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
			__m128i xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
			__m128i xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
			__m128i xmm_dst4 = _mm_cvttpd_epi32(xmm_src4);
			__m128i xmm_dst5 = _mm_cvttpd_epi32(xmm_src5);
			__m128i xmm_dst6 = _mm_cvttpd_epi32(xmm_src6);
			__m128i xmm_dst7 = _mm_cvttpd_epi32(xmm_src7);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
			xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
			xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
			xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
			xmm_dst0 = _mm_add_epi32(xmm_dst0, shift);
			xmm_dst2 = _mm_add_epi32(xmm_dst2, shift);
			xmm_dst4 = _mm_add_epi32(xmm_dst4, shift);
			xmm_dst6 = _mm_add_epi32(xmm_dst6, shift);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 2, xmm_dst4);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 3, xmm_dst6);
		}

		template <>
		inline void cvtspd_sse41_16<float>(float* dst, const double* src)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(-FLT_MAX));
			const __m128d max = _mm_set1_pd(static_cast<double>(FLT_MAX));
			__m128d xmm_src0 = _mm_loadu_pd(src);
			__m128d xmm_src1 = _mm_loadu_pd(src + 2);
			__m128d xmm_src2 = _mm_loadu_pd(src + 4);
			__m128d xmm_src3 = _mm_loadu_pd(src + 6);
			__m128d xmm_src4 = _mm_loadu_pd(src + 8);
			__m128d xmm_src5 = _mm_loadu_pd(src + 10);
			__m128d xmm_src6 = _mm_loadu_pd(src + 12);
			__m128d xmm_src7 = _mm_loadu_pd(src + 14);
			xmm_src0 = _mm_max_pd(xmm_src0, min);
			xmm_src1 = _mm_max_pd(xmm_src1, min);
			xmm_src2 = _mm_max_pd(xmm_src2, min);
			xmm_src3 = _mm_max_pd(xmm_src3, min);
			xmm_src4 = _mm_max_pd(xmm_src4, min);
			xmm_src5 = _mm_max_pd(xmm_src5, min);
			xmm_src6 = _mm_max_pd(xmm_src6, min);
			xmm_src7 = _mm_max_pd(xmm_src7, min);
			xmm_src0 = _mm_min_pd(xmm_src0, max);
			xmm_src1 = _mm_min_pd(xmm_src1, max);
			xmm_src2 = _mm_min_pd(xmm_src2, max);
			xmm_src3 = _mm_min_pd(xmm_src3, max);
			xmm_src4 = _mm_min_pd(xmm_src4, max);
			xmm_src5 = _mm_min_pd(xmm_src5, max);
			xmm_src6 = _mm_min_pd(xmm_src6, max);
			xmm_src7 = _mm_min_pd(xmm_src7, max);
			__m128 xmm_dst0 = _mm_cvtpd_ps(xmm_src0);
			__m128 xmm_dst1 = _mm_cvtpd_ps(xmm_src1);
			__m128 xmm_dst2 = _mm_cvtpd_ps(xmm_src2);
			__m128 xmm_dst3 = _mm_cvtpd_ps(xmm_src3);
			__m128 xmm_dst4 = _mm_cvtpd_ps(xmm_src4);
			__m128 xmm_dst5 = _mm_cvtpd_ps(xmm_src5);
			__m128 xmm_dst6 = _mm_cvtpd_ps(xmm_src6);
			__m128 xmm_dst7 = _mm_cvtpd_ps(xmm_src7);
			xmm_dst0 = _mm_shuffle_ps(xmm_dst0, xmm_dst1, _MM_SHUFFLE(1, 0, 1, 0));
			xmm_dst2 = _mm_shuffle_ps(xmm_dst2, xmm_dst3, _MM_SHUFFLE(1, 0, 1, 0));
			xmm_dst4 = _mm_shuffle_ps(xmm_dst4, xmm_dst5, _MM_SHUFFLE(1, 0, 1, 0));
			xmm_dst6 = _mm_shuffle_ps(xmm_dst6, xmm_dst7, _MM_SHUFFLE(1, 0, 1, 0));
			_mm_storeu_ps(dst, xmm_dst0);
			_mm_storeu_ps(dst + 4, xmm_dst2);
			_mm_storeu_ps(dst + 8, xmm_dst4);
			_mm_storeu_ps(dst + 12, xmm_dst6);
		}

		// Function template cvtspd_sse41_32

		template <class T>
		inline void cvtspd_sse41_32(T* dst, const double* src)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		inline void cvtspd_sse41_32<signed char>(signed char* dst, const double* src)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(INT8_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT8_MAX));
			__m128d xmm_src0 = _mm_loadu_pd(src);
			__m128d xmm_src1 = _mm_loadu_pd(src + 2);
			__m128d xmm_src2 = _mm_loadu_pd(src + 4);
			__m128d xmm_src3 = _mm_loadu_pd(src + 6);
			__m128d xmm_src4 = _mm_loadu_pd(src + 8);
			__m128d xmm_src5 = _mm_loadu_pd(src + 10);
			__m128d xmm_src6 = _mm_loadu_pd(src + 12);
			__m128d xmm_src7 = _mm_loadu_pd(src + 14);
			__m128d xmm_src8 = _mm_loadu_pd(src + 16);
			__m128d xmm_src9 = _mm_loadu_pd(src + 18);
			__m128d xmm_srca = _mm_loadu_pd(src + 20);
			__m128d xmm_srcb = _mm_loadu_pd(src + 22);
			__m128d xmm_srcc = _mm_loadu_pd(src + 24);
			__m128d xmm_srcd = _mm_loadu_pd(src + 26);
			__m128d xmm_srce = _mm_loadu_pd(src + 28);
			__m128d xmm_srcf = _mm_loadu_pd(src + 30);
			xmm_src0 = _mm_max_pd(xmm_src0, min);
			xmm_src1 = _mm_max_pd(xmm_src1, min);
			xmm_src2 = _mm_max_pd(xmm_src2, min);
			xmm_src3 = _mm_max_pd(xmm_src3, min);
			xmm_src4 = _mm_max_pd(xmm_src4, min);
			xmm_src5 = _mm_max_pd(xmm_src5, min);
			xmm_src6 = _mm_max_pd(xmm_src6, min);
			xmm_src7 = _mm_max_pd(xmm_src7, min);
			xmm_src8 = _mm_max_pd(xmm_src8, min);
			xmm_src9 = _mm_max_pd(xmm_src9, min);
			xmm_srca = _mm_max_pd(xmm_srca, min);
			xmm_srcb = _mm_max_pd(xmm_srcb, min);
			xmm_srcc = _mm_max_pd(xmm_srcc, min);
			xmm_srcd = _mm_max_pd(xmm_srcd, min);
			xmm_srce = _mm_max_pd(xmm_srce, min);
			xmm_srcf = _mm_max_pd(xmm_srcf, min);
			xmm_src0 = _mm_min_pd(xmm_src0, max);
			xmm_src1 = _mm_min_pd(xmm_src1, max);
			xmm_src2 = _mm_min_pd(xmm_src2, max);
			xmm_src3 = _mm_min_pd(xmm_src3, max);
			xmm_src4 = _mm_min_pd(xmm_src4, max);
			xmm_src5 = _mm_min_pd(xmm_src5, max);
			xmm_src6 = _mm_min_pd(xmm_src6, max);
			xmm_src7 = _mm_min_pd(xmm_src7, max);
			xmm_src8 = _mm_min_pd(xmm_src8, max);
			xmm_src9 = _mm_min_pd(xmm_src9, max);
			xmm_srca = _mm_min_pd(xmm_srca, max);
			xmm_srcb = _mm_min_pd(xmm_srcb, max);
			xmm_srcc = _mm_min_pd(xmm_srcc, max);
			xmm_srcd = _mm_min_pd(xmm_srcd, max);
			xmm_srce = _mm_min_pd(xmm_srce, max);
			xmm_srcf = _mm_min_pd(xmm_srcf, max);
			__m128i xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
			__m128i xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
			__m128i xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
			__m128i xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
			__m128i xmm_dst4 = _mm_cvttpd_epi32(xmm_src4);
			__m128i xmm_dst5 = _mm_cvttpd_epi32(xmm_src5);
			__m128i xmm_dst6 = _mm_cvttpd_epi32(xmm_src6);
			__m128i xmm_dst7 = _mm_cvttpd_epi32(xmm_src7);
			__m128i xmm_dst8 = _mm_cvttpd_epi32(xmm_src8);
			__m128i xmm_dst9 = _mm_cvttpd_epi32(xmm_src9);
			__m128i xmm_dsta = _mm_cvttpd_epi32(xmm_srca);
			__m128i xmm_dstb = _mm_cvttpd_epi32(xmm_srcb);
			__m128i xmm_dstc = _mm_cvttpd_epi32(xmm_srcc);
			__m128i xmm_dstd = _mm_cvttpd_epi32(xmm_srcd);
			__m128i xmm_dste = _mm_cvttpd_epi32(xmm_srce);
			__m128i xmm_dstf = _mm_cvttpd_epi32(xmm_srcf);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
			xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
			xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
			xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
			xmm_dst8 = _mm_unpacklo_epi64(xmm_dst8, xmm_dst9);
			xmm_dsta = _mm_unpacklo_epi64(xmm_dsta, xmm_dstb);
			xmm_dstc = _mm_unpacklo_epi64(xmm_dstc, xmm_dstd);
			xmm_dste = _mm_unpacklo_epi64(xmm_dste, xmm_dstf);
			xmm_dst0 = _mm_packs_epi32(xmm_dst0, xmm_dst2);
			xmm_dst4 = _mm_packs_epi32(xmm_dst4, xmm_dst6);
			xmm_dst8 = _mm_packs_epi32(xmm_dst8, xmm_dsta);
			xmm_dstc = _mm_packs_epi32(xmm_dstc, xmm_dste);
			xmm_dst0 = _mm_packs_epi16(xmm_dst0, xmm_dst4);
			xmm_dst8 = _mm_packs_epi16(xmm_dst8, xmm_dstc);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst8);
		}

		template <>
		inline void cvtspd_sse41_32<unsigned char>(unsigned char* dst, const double* src)
		{
			const __m128d min = _mm_setzero_pd();
			const __m128d max = _mm_set1_pd(static_cast<double>(UINT8_MAX));
			__m128d xmm_src0 = _mm_loadu_pd(src);
			__m128d xmm_src1 = _mm_loadu_pd(src + 2);
			__m128d xmm_src2 = _mm_loadu_pd(src + 4);
			__m128d xmm_src3 = _mm_loadu_pd(src + 6);
			__m128d xmm_src4 = _mm_loadu_pd(src + 8);
			__m128d xmm_src5 = _mm_loadu_pd(src + 10);
			__m128d xmm_src6 = _mm_loadu_pd(src + 12);
			__m128d xmm_src7 = _mm_loadu_pd(src + 14);
			__m128d xmm_src8 = _mm_loadu_pd(src + 16);
			__m128d xmm_src9 = _mm_loadu_pd(src + 18);
			__m128d xmm_srca = _mm_loadu_pd(src + 20);
			__m128d xmm_srcb = _mm_loadu_pd(src + 22);
			__m128d xmm_srcc = _mm_loadu_pd(src + 24);
			__m128d xmm_srcd = _mm_loadu_pd(src + 26);
			__m128d xmm_srce = _mm_loadu_pd(src + 28);
			__m128d xmm_srcf = _mm_loadu_pd(src + 30);
			xmm_src0 = _mm_max_pd(xmm_src0, min);
			xmm_src1 = _mm_max_pd(xmm_src1, min);
			xmm_src2 = _mm_max_pd(xmm_src2, min);
			xmm_src3 = _mm_max_pd(xmm_src3, min);
			xmm_src4 = _mm_max_pd(xmm_src4, min);
			xmm_src5 = _mm_max_pd(xmm_src5, min);
			xmm_src6 = _mm_max_pd(xmm_src6, min);
			xmm_src7 = _mm_max_pd(xmm_src7, min);
			xmm_src8 = _mm_max_pd(xmm_src8, min);
			xmm_src9 = _mm_max_pd(xmm_src9, min);
			xmm_srca = _mm_max_pd(xmm_srca, min);
			xmm_srcb = _mm_max_pd(xmm_srcb, min);
			xmm_srcc = _mm_max_pd(xmm_srcc, min);
			xmm_srcd = _mm_max_pd(xmm_srcd, min);
			xmm_srce = _mm_max_pd(xmm_srce, min);
			xmm_srcf = _mm_max_pd(xmm_srcf, min);
			xmm_src0 = _mm_min_pd(xmm_src0, max);
			xmm_src1 = _mm_min_pd(xmm_src1, max);
			xmm_src2 = _mm_min_pd(xmm_src2, max);
			xmm_src3 = _mm_min_pd(xmm_src3, max);
			xmm_src4 = _mm_min_pd(xmm_src4, max);
			xmm_src5 = _mm_min_pd(xmm_src5, max);
			xmm_src6 = _mm_min_pd(xmm_src6, max);
			xmm_src7 = _mm_min_pd(xmm_src7, max);
			xmm_src8 = _mm_min_pd(xmm_src8, max);
			xmm_src9 = _mm_min_pd(xmm_src9, max);
			xmm_srca = _mm_min_pd(xmm_srca, max);
			xmm_srcb = _mm_min_pd(xmm_srcb, max);
			xmm_srcc = _mm_min_pd(xmm_srcc, max);
			xmm_srcd = _mm_min_pd(xmm_srcd, max);
			xmm_srce = _mm_min_pd(xmm_srce, max);
			xmm_srcf = _mm_min_pd(xmm_srcf, max);
			__m128i xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
			__m128i xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
			__m128i xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
			__m128i xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
			__m128i xmm_dst4 = _mm_cvttpd_epi32(xmm_src4);
			__m128i xmm_dst5 = _mm_cvttpd_epi32(xmm_src5);
			__m128i xmm_dst6 = _mm_cvttpd_epi32(xmm_src6);
			__m128i xmm_dst7 = _mm_cvttpd_epi32(xmm_src7);
			__m128i xmm_dst8 = _mm_cvttpd_epi32(xmm_src8);
			__m128i xmm_dst9 = _mm_cvttpd_epi32(xmm_src9);
			__m128i xmm_dsta = _mm_cvttpd_epi32(xmm_srca);
			__m128i xmm_dstb = _mm_cvttpd_epi32(xmm_srcb);
			__m128i xmm_dstc = _mm_cvttpd_epi32(xmm_srcc);
			__m128i xmm_dstd = _mm_cvttpd_epi32(xmm_srcd);
			__m128i xmm_dste = _mm_cvttpd_epi32(xmm_srce);
			__m128i xmm_dstf = _mm_cvttpd_epi32(xmm_srcf);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
			xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
			xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
			xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
			xmm_dst8 = _mm_unpacklo_epi64(xmm_dst8, xmm_dst9);
			xmm_dsta = _mm_unpacklo_epi64(xmm_dsta, xmm_dstb);
			xmm_dstc = _mm_unpacklo_epi64(xmm_dstc, xmm_dstd);
			xmm_dste = _mm_unpacklo_epi64(xmm_dste, xmm_dstf);
			xmm_dst0 = _mm_packus_epi32(xmm_dst0, xmm_dst2);
			xmm_dst4 = _mm_packus_epi32(xmm_dst4, xmm_dst6);
			xmm_dst8 = _mm_packus_epi32(xmm_dst8, xmm_dsta);
			xmm_dstc = _mm_packus_epi32(xmm_dstc, xmm_dste);
			xmm_dst0 = _mm_packus_epi16(xmm_dst0, xmm_dst4);
			xmm_dst8 = _mm_packus_epi16(xmm_dst8, xmm_dstc);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst8);
		}

		template <>
		inline void cvtspd_sse41_32<signed short>(signed short* dst, const double* src)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(INT16_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT16_MAX));
			__m128d xmm_src0 = _mm_loadu_pd(src);
			__m128d xmm_src1 = _mm_loadu_pd(src + 2);
			__m128d xmm_src2 = _mm_loadu_pd(src + 4);
			__m128d xmm_src3 = _mm_loadu_pd(src + 6);
			__m128d xmm_src4 = _mm_loadu_pd(src + 8);
			__m128d xmm_src5 = _mm_loadu_pd(src + 10);
			__m128d xmm_src6 = _mm_loadu_pd(src + 12);
			__m128d xmm_src7 = _mm_loadu_pd(src + 14);
			__m128d xmm_src8 = _mm_loadu_pd(src + 16);
			__m128d xmm_src9 = _mm_loadu_pd(src + 18);
			__m128d xmm_srca = _mm_loadu_pd(src + 20);
			__m128d xmm_srcb = _mm_loadu_pd(src + 22);
			__m128d xmm_srcc = _mm_loadu_pd(src + 24);
			__m128d xmm_srcd = _mm_loadu_pd(src + 26);
			__m128d xmm_srce = _mm_loadu_pd(src + 28);
			__m128d xmm_srcf = _mm_loadu_pd(src + 30);
			xmm_src0 = _mm_max_pd(xmm_src0, min);
			xmm_src1 = _mm_max_pd(xmm_src1, min);
			xmm_src2 = _mm_max_pd(xmm_src2, min);
			xmm_src3 = _mm_max_pd(xmm_src3, min);
			xmm_src4 = _mm_max_pd(xmm_src4, min);
			xmm_src5 = _mm_max_pd(xmm_src5, min);
			xmm_src6 = _mm_max_pd(xmm_src6, min);
			xmm_src7 = _mm_max_pd(xmm_src7, min);
			xmm_src8 = _mm_max_pd(xmm_src8, min);
			xmm_src9 = _mm_max_pd(xmm_src9, min);
			xmm_srca = _mm_max_pd(xmm_srca, min);
			xmm_srcb = _mm_max_pd(xmm_srcb, min);
			xmm_srcc = _mm_max_pd(xmm_srcc, min);
			xmm_srcd = _mm_max_pd(xmm_srcd, min);
			xmm_srce = _mm_max_pd(xmm_srce, min);
			xmm_srcf = _mm_max_pd(xmm_srcf, min);
			xmm_src0 = _mm_min_pd(xmm_src0, max);
			xmm_src1 = _mm_min_pd(xmm_src1, max);
			xmm_src2 = _mm_min_pd(xmm_src2, max);
			xmm_src3 = _mm_min_pd(xmm_src3, max);
			xmm_src4 = _mm_min_pd(xmm_src4, max);
			xmm_src5 = _mm_min_pd(xmm_src5, max);
			xmm_src6 = _mm_min_pd(xmm_src6, max);
			xmm_src7 = _mm_min_pd(xmm_src7, max);
			xmm_src8 = _mm_min_pd(xmm_src8, max);
			xmm_src9 = _mm_min_pd(xmm_src9, max);
			xmm_srca = _mm_min_pd(xmm_srca, max);
			xmm_srcb = _mm_min_pd(xmm_srcb, max);
			xmm_srcc = _mm_min_pd(xmm_srcc, max);
			xmm_srcd = _mm_min_pd(xmm_srcd, max);
			xmm_srce = _mm_min_pd(xmm_srce, max);
			xmm_srcf = _mm_min_pd(xmm_srcf, max);
			__m128i xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
			__m128i xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
			__m128i xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
			__m128i xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
			__m128i xmm_dst4 = _mm_cvttpd_epi32(xmm_src4);
			__m128i xmm_dst5 = _mm_cvttpd_epi32(xmm_src5);
			__m128i xmm_dst6 = _mm_cvttpd_epi32(xmm_src6);
			__m128i xmm_dst7 = _mm_cvttpd_epi32(xmm_src7);
			__m128i xmm_dst8 = _mm_cvttpd_epi32(xmm_src8);
			__m128i xmm_dst9 = _mm_cvttpd_epi32(xmm_src9);
			__m128i xmm_dsta = _mm_cvttpd_epi32(xmm_srca);
			__m128i xmm_dstb = _mm_cvttpd_epi32(xmm_srcb);
			__m128i xmm_dstc = _mm_cvttpd_epi32(xmm_srcc);
			__m128i xmm_dstd = _mm_cvttpd_epi32(xmm_srcd);
			__m128i xmm_dste = _mm_cvttpd_epi32(xmm_srce);
			__m128i xmm_dstf = _mm_cvttpd_epi32(xmm_srcf);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
			xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
			xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
			xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
			xmm_dst8 = _mm_unpacklo_epi64(xmm_dst8, xmm_dst9);
			xmm_dsta = _mm_unpacklo_epi64(xmm_dsta, xmm_dstb);
			xmm_dstc = _mm_unpacklo_epi64(xmm_dstc, xmm_dstd);
			xmm_dste = _mm_unpacklo_epi64(xmm_dste, xmm_dstf);
			xmm_dst0 = _mm_packs_epi32(xmm_dst0, xmm_dst2);
			xmm_dst4 = _mm_packs_epi32(xmm_dst4, xmm_dst6);
			xmm_dst8 = _mm_packs_epi32(xmm_dst8, xmm_dsta);
			xmm_dstc = _mm_packs_epi32(xmm_dstc, xmm_dste);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst4);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 2, xmm_dst8);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 3, xmm_dstc);
		}

		template <>
		inline void cvtspd_sse41_32<unsigned short>(unsigned short* dst, const double* src)
		{
			const __m128d min = _mm_setzero_pd();
			const __m128d max = _mm_set1_pd(static_cast<double>(UINT16_MAX));
			__m128d xmm_src0 = _mm_loadu_pd(src);
			__m128d xmm_src1 = _mm_loadu_pd(src + 2);
			__m128d xmm_src2 = _mm_loadu_pd(src + 4);
			__m128d xmm_src3 = _mm_loadu_pd(src + 6);
			__m128d xmm_src4 = _mm_loadu_pd(src + 8);
			__m128d xmm_src5 = _mm_loadu_pd(src + 10);
			__m128d xmm_src6 = _mm_loadu_pd(src + 12);
			__m128d xmm_src7 = _mm_loadu_pd(src + 14);
			__m128d xmm_src8 = _mm_loadu_pd(src + 16);
			__m128d xmm_src9 = _mm_loadu_pd(src + 18);
			__m128d xmm_srca = _mm_loadu_pd(src + 20);
			__m128d xmm_srcb = _mm_loadu_pd(src + 22);
			__m128d xmm_srcc = _mm_loadu_pd(src + 24);
			__m128d xmm_srcd = _mm_loadu_pd(src + 26);
			__m128d xmm_srce = _mm_loadu_pd(src + 28);
			__m128d xmm_srcf = _mm_loadu_pd(src + 30);
			xmm_src0 = _mm_max_pd(xmm_src0, min);
			xmm_src1 = _mm_max_pd(xmm_src1, min);
			xmm_src2 = _mm_max_pd(xmm_src2, min);
			xmm_src3 = _mm_max_pd(xmm_src3, min);
			xmm_src4 = _mm_max_pd(xmm_src4, min);
			xmm_src5 = _mm_max_pd(xmm_src5, min);
			xmm_src6 = _mm_max_pd(xmm_src6, min);
			xmm_src7 = _mm_max_pd(xmm_src7, min);
			xmm_src8 = _mm_max_pd(xmm_src8, min);
			xmm_src9 = _mm_max_pd(xmm_src9, min);
			xmm_srca = _mm_max_pd(xmm_srca, min);
			xmm_srcb = _mm_max_pd(xmm_srcb, min);
			xmm_srcc = _mm_max_pd(xmm_srcc, min);
			xmm_srcd = _mm_max_pd(xmm_srcd, min);
			xmm_srce = _mm_max_pd(xmm_srce, min);
			xmm_srcf = _mm_max_pd(xmm_srcf, min);
			xmm_src0 = _mm_min_pd(xmm_src0, max);
			xmm_src1 = _mm_min_pd(xmm_src1, max);
			xmm_src2 = _mm_min_pd(xmm_src2, max);
			xmm_src3 = _mm_min_pd(xmm_src3, max);
			xmm_src4 = _mm_min_pd(xmm_src4, max);
			xmm_src5 = _mm_min_pd(xmm_src5, max);
			xmm_src6 = _mm_min_pd(xmm_src6, max);
			xmm_src7 = _mm_min_pd(xmm_src7, max);
			xmm_src8 = _mm_min_pd(xmm_src8, max);
			xmm_src9 = _mm_min_pd(xmm_src9, max);
			xmm_srca = _mm_min_pd(xmm_srca, max);
			xmm_srcb = _mm_min_pd(xmm_srcb, max);
			xmm_srcc = _mm_min_pd(xmm_srcc, max);
			xmm_srcd = _mm_min_pd(xmm_srcd, max);
			xmm_srce = _mm_min_pd(xmm_srce, max);
			xmm_srcf = _mm_min_pd(xmm_srcf, max);
			__m128i xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
			__m128i xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
			__m128i xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
			__m128i xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
			__m128i xmm_dst4 = _mm_cvttpd_epi32(xmm_src4);
			__m128i xmm_dst5 = _mm_cvttpd_epi32(xmm_src5);
			__m128i xmm_dst6 = _mm_cvttpd_epi32(xmm_src6);
			__m128i xmm_dst7 = _mm_cvttpd_epi32(xmm_src7);
			__m128i xmm_dst8 = _mm_cvttpd_epi32(xmm_src8);
			__m128i xmm_dst9 = _mm_cvttpd_epi32(xmm_src9);
			__m128i xmm_dsta = _mm_cvttpd_epi32(xmm_srca);
			__m128i xmm_dstb = _mm_cvttpd_epi32(xmm_srcb);
			__m128i xmm_dstc = _mm_cvttpd_epi32(xmm_srcc);
			__m128i xmm_dstd = _mm_cvttpd_epi32(xmm_srcd);
			__m128i xmm_dste = _mm_cvttpd_epi32(xmm_srce);
			__m128i xmm_dstf = _mm_cvttpd_epi32(xmm_srcf);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
			xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
			xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
			xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
			xmm_dst8 = _mm_unpacklo_epi64(xmm_dst8, xmm_dst9);
			xmm_dsta = _mm_unpacklo_epi64(xmm_dsta, xmm_dstb);
			xmm_dstc = _mm_unpacklo_epi64(xmm_dstc, xmm_dstd);
			xmm_dste = _mm_unpacklo_epi64(xmm_dste, xmm_dstf);
			xmm_dst0 = _mm_packus_epi32(xmm_dst0, xmm_dst2);
			xmm_dst4 = _mm_packus_epi32(xmm_dst4, xmm_dst6);
			xmm_dst8 = _mm_packus_epi32(xmm_dst8, xmm_dsta);
			xmm_dstc = _mm_packus_epi32(xmm_dstc, xmm_dste);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst4);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 2, xmm_dst8);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 3, xmm_dstc);
		}

		template <>
		inline void cvtspd_sse41_32<signed int>(signed int* dst, const double* src)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(INT32_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT32_MAX));
			__m128d xmm_src0 = _mm_loadu_pd(src);
			__m128d xmm_src1 = _mm_loadu_pd(src + 2);
			__m128d xmm_src2 = _mm_loadu_pd(src + 4);
			__m128d xmm_src3 = _mm_loadu_pd(src + 6);
			__m128d xmm_src4 = _mm_loadu_pd(src + 8);
			__m128d xmm_src5 = _mm_loadu_pd(src + 10);
			__m128d xmm_src6 = _mm_loadu_pd(src + 12);
			__m128d xmm_src7 = _mm_loadu_pd(src + 14);
			__m128d xmm_src8 = _mm_loadu_pd(src + 16);
			__m128d xmm_src9 = _mm_loadu_pd(src + 18);
			__m128d xmm_srca = _mm_loadu_pd(src + 20);
			__m128d xmm_srcb = _mm_loadu_pd(src + 22);
			__m128d xmm_srcc = _mm_loadu_pd(src + 24);
			__m128d xmm_srcd = _mm_loadu_pd(src + 26);
			__m128d xmm_srce = _mm_loadu_pd(src + 28);
			__m128d xmm_srcf = _mm_loadu_pd(src + 30);
			xmm_src0 = _mm_max_pd(xmm_src0, min);
			xmm_src1 = _mm_max_pd(xmm_src1, min);
			xmm_src2 = _mm_max_pd(xmm_src2, min);
			xmm_src3 = _mm_max_pd(xmm_src3, min);
			xmm_src4 = _mm_max_pd(xmm_src4, min);
			xmm_src5 = _mm_max_pd(xmm_src5, min);
			xmm_src6 = _mm_max_pd(xmm_src6, min);
			xmm_src7 = _mm_max_pd(xmm_src7, min);
			xmm_src8 = _mm_max_pd(xmm_src8, min);
			xmm_src9 = _mm_max_pd(xmm_src9, min);
			xmm_srca = _mm_max_pd(xmm_srca, min);
			xmm_srcb = _mm_max_pd(xmm_srcb, min);
			xmm_srcc = _mm_max_pd(xmm_srcc, min);
			xmm_srcd = _mm_max_pd(xmm_srcd, min);
			xmm_srce = _mm_max_pd(xmm_srce, min);
			xmm_srcf = _mm_max_pd(xmm_srcf, min);
			xmm_src0 = _mm_min_pd(xmm_src0, max);
			xmm_src1 = _mm_min_pd(xmm_src1, max);
			xmm_src2 = _mm_min_pd(xmm_src2, max);
			xmm_src3 = _mm_min_pd(xmm_src3, max);
			xmm_src4 = _mm_min_pd(xmm_src4, max);
			xmm_src5 = _mm_min_pd(xmm_src5, max);
			xmm_src6 = _mm_min_pd(xmm_src6, max);
			xmm_src7 = _mm_min_pd(xmm_src7, max);
			xmm_src8 = _mm_min_pd(xmm_src8, max);
			xmm_src9 = _mm_min_pd(xmm_src9, max);
			xmm_srca = _mm_min_pd(xmm_srca, max);
			xmm_srcb = _mm_min_pd(xmm_srcb, max);
			xmm_srcc = _mm_min_pd(xmm_srcc, max);
			xmm_srcd = _mm_min_pd(xmm_srcd, max);
			xmm_srce = _mm_min_pd(xmm_srce, max);
			xmm_srcf = _mm_min_pd(xmm_srcf, max);
			__m128i xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
			__m128i xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
			__m128i xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
			__m128i xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
			__m128i xmm_dst4 = _mm_cvttpd_epi32(xmm_src4);
			__m128i xmm_dst5 = _mm_cvttpd_epi32(xmm_src5);
			__m128i xmm_dst6 = _mm_cvttpd_epi32(xmm_src6);
			__m128i xmm_dst7 = _mm_cvttpd_epi32(xmm_src7);
			__m128i xmm_dst8 = _mm_cvttpd_epi32(xmm_src8);
			__m128i xmm_dst9 = _mm_cvttpd_epi32(xmm_src9);
			__m128i xmm_dsta = _mm_cvttpd_epi32(xmm_srca);
			__m128i xmm_dstb = _mm_cvttpd_epi32(xmm_srcb);
			__m128i xmm_dstc = _mm_cvttpd_epi32(xmm_srcc);
			__m128i xmm_dstd = _mm_cvttpd_epi32(xmm_srcd);
			__m128i xmm_dste = _mm_cvttpd_epi32(xmm_srce);
			__m128i xmm_dstf = _mm_cvttpd_epi32(xmm_srcf);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
			xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
			xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
			xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
			xmm_dst8 = _mm_unpacklo_epi64(xmm_dst8, xmm_dst9);
			xmm_dsta = _mm_unpacklo_epi64(xmm_dsta, xmm_dstb);
			xmm_dstc = _mm_unpacklo_epi64(xmm_dstc, xmm_dstd);
			xmm_dste = _mm_unpacklo_epi64(xmm_dste, xmm_dstf);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 2, xmm_dst4);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 3, xmm_dst6);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 4, xmm_dst8);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 5, xmm_dsta);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 6, xmm_dstc);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 7, xmm_dste);
		}

		template <>
		inline void cvtspd_sse41_32<unsigned int>(unsigned int* dst, const double* src)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(INT32_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT32_MAX));
			const __m128d offset = _mm_set1_pd(2.147483648e+9);
			const __m128i shift = _mm_set1_epi32(2147483648);
			__m128d xmm_src0 = _mm_loadu_pd(src);
			__m128d xmm_src1 = _mm_loadu_pd(src + 2);
			__m128d xmm_src2 = _mm_loadu_pd(src + 4);
			__m128d xmm_src3 = _mm_loadu_pd(src + 6);
			__m128d xmm_src4 = _mm_loadu_pd(src + 8);
			__m128d xmm_src5 = _mm_loadu_pd(src + 10);
			__m128d xmm_src6 = _mm_loadu_pd(src + 12);
			__m128d xmm_src7 = _mm_loadu_pd(src + 14);
			__m128d xmm_src8 = _mm_loadu_pd(src + 16);
			__m128d xmm_src9 = _mm_loadu_pd(src + 18);
			__m128d xmm_srca = _mm_loadu_pd(src + 20);
			__m128d xmm_srcb = _mm_loadu_pd(src + 22);
			__m128d xmm_srcc = _mm_loadu_pd(src + 24);
			__m128d xmm_srcd = _mm_loadu_pd(src + 26);
			__m128d xmm_srce = _mm_loadu_pd(src + 28);
			__m128d xmm_srcf = _mm_loadu_pd(src + 30);
			xmm_src0 = _mm_sub_pd(xmm_src0, offset);
			xmm_src1 = _mm_sub_pd(xmm_src1, offset);
			xmm_src2 = _mm_sub_pd(xmm_src2, offset);
			xmm_src3 = _mm_sub_pd(xmm_src3, offset);
			xmm_src4 = _mm_sub_pd(xmm_src4, offset);
			xmm_src5 = _mm_sub_pd(xmm_src5, offset);
			xmm_src6 = _mm_sub_pd(xmm_src6, offset);
			xmm_src7 = _mm_sub_pd(xmm_src7, offset);
			xmm_src8 = _mm_sub_pd(xmm_src8, offset);
			xmm_src9 = _mm_sub_pd(xmm_src9, offset);
			xmm_srca = _mm_sub_pd(xmm_srca, offset);
			xmm_srcb = _mm_sub_pd(xmm_srcb, offset);
			xmm_srcc = _mm_sub_pd(xmm_srcc, offset);
			xmm_srcd = _mm_sub_pd(xmm_srcd, offset);
			xmm_srce = _mm_sub_pd(xmm_srce, offset);
			xmm_srcf = _mm_sub_pd(xmm_srcf, offset);
			xmm_src0 = _mm_max_pd(xmm_src0, min);
			xmm_src1 = _mm_max_pd(xmm_src1, min);
			xmm_src2 = _mm_max_pd(xmm_src2, min);
			xmm_src3 = _mm_max_pd(xmm_src3, min);
			xmm_src4 = _mm_max_pd(xmm_src4, min);
			xmm_src5 = _mm_max_pd(xmm_src5, min);
			xmm_src6 = _mm_max_pd(xmm_src6, min);
			xmm_src7 = _mm_max_pd(xmm_src7, min);
			xmm_src8 = _mm_max_pd(xmm_src8, min);
			xmm_src9 = _mm_max_pd(xmm_src9, min);
			xmm_srca = _mm_max_pd(xmm_srca, min);
			xmm_srcb = _mm_max_pd(xmm_srcb, min);
			xmm_srcc = _mm_max_pd(xmm_srcc, min);
			xmm_srcd = _mm_max_pd(xmm_srcd, min);
			xmm_srce = _mm_max_pd(xmm_srce, min);
			xmm_srcf = _mm_max_pd(xmm_srcf, min);
			xmm_src0 = _mm_min_pd(xmm_src0, max);
			xmm_src1 = _mm_min_pd(xmm_src1, max);
			xmm_src2 = _mm_min_pd(xmm_src2, max);
			xmm_src3 = _mm_min_pd(xmm_src3, max);
			xmm_src4 = _mm_min_pd(xmm_src4, max);
			xmm_src5 = _mm_min_pd(xmm_src5, max);
			xmm_src6 = _mm_min_pd(xmm_src6, max);
			xmm_src7 = _mm_min_pd(xmm_src7, max);
			xmm_src8 = _mm_min_pd(xmm_src8, max);
			xmm_src9 = _mm_min_pd(xmm_src9, max);
			xmm_srca = _mm_min_pd(xmm_srca, max);
			xmm_srcb = _mm_min_pd(xmm_srcb, max);
			xmm_srcc = _mm_min_pd(xmm_srcc, max);
			xmm_srcd = _mm_min_pd(xmm_srcd, max);
			xmm_srce = _mm_min_pd(xmm_srce, max);
			xmm_srcf = _mm_min_pd(xmm_srcf, max);
			__m128i xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
			__m128i xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
			__m128i xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
			__m128i xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
			__m128i xmm_dst4 = _mm_cvttpd_epi32(xmm_src4);
			__m128i xmm_dst5 = _mm_cvttpd_epi32(xmm_src5);
			__m128i xmm_dst6 = _mm_cvttpd_epi32(xmm_src6);
			__m128i xmm_dst7 = _mm_cvttpd_epi32(xmm_src7);
			__m128i xmm_dst8 = _mm_cvttpd_epi32(xmm_src8);
			__m128i xmm_dst9 = _mm_cvttpd_epi32(xmm_src9);
			__m128i xmm_dsta = _mm_cvttpd_epi32(xmm_srca);
			__m128i xmm_dstb = _mm_cvttpd_epi32(xmm_srcb);
			__m128i xmm_dstc = _mm_cvttpd_epi32(xmm_srcc);
			__m128i xmm_dstd = _mm_cvttpd_epi32(xmm_srcd);
			__m128i xmm_dste = _mm_cvttpd_epi32(xmm_srce);
			__m128i xmm_dstf = _mm_cvttpd_epi32(xmm_srcf);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
			xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
			xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
			xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
			xmm_dst8 = _mm_unpacklo_epi64(xmm_dst8, xmm_dst9);
			xmm_dsta = _mm_unpacklo_epi64(xmm_dsta, xmm_dstb);
			xmm_dstc = _mm_unpacklo_epi64(xmm_dstc, xmm_dstd);
			xmm_dste = _mm_unpacklo_epi64(xmm_dste, xmm_dstf);
			xmm_dst0 = _mm_add_epi32(xmm_dst0, shift);
			xmm_dst2 = _mm_add_epi32(xmm_dst2, shift);
			xmm_dst4 = _mm_add_epi32(xmm_dst4, shift);
			xmm_dst6 = _mm_add_epi32(xmm_dst6, shift);
			xmm_dst8 = _mm_add_epi32(xmm_dst8, shift);
			xmm_dsta = _mm_add_epi32(xmm_dsta, shift);
			xmm_dstc = _mm_add_epi32(xmm_dstc, shift);
			xmm_dste = _mm_add_epi32(xmm_dste, shift);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 2, xmm_dst4);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 3, xmm_dst6);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 4, xmm_dst8);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 5, xmm_dsta);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 6, xmm_dstc);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 7, xmm_dste);
		}

		template <>
		inline void cvtspd_sse41_32<float>(float* dst, const double* src)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(-FLT_MAX));
			const __m128d max = _mm_set1_pd(static_cast<double>(FLT_MAX));
			__m128d xmm_src0 = _mm_loadu_pd(src);
			__m128d xmm_src1 = _mm_loadu_pd(src + 2);
			__m128d xmm_src2 = _mm_loadu_pd(src + 4);
			__m128d xmm_src3 = _mm_loadu_pd(src + 6);
			__m128d xmm_src4 = _mm_loadu_pd(src + 8);
			__m128d xmm_src5 = _mm_loadu_pd(src + 10);
			__m128d xmm_src6 = _mm_loadu_pd(src + 12);
			__m128d xmm_src7 = _mm_loadu_pd(src + 14);
			__m128d xmm_src8 = _mm_loadu_pd(src + 16);
			__m128d xmm_src9 = _mm_loadu_pd(src + 18);
			__m128d xmm_srca = _mm_loadu_pd(src + 20);
			__m128d xmm_srcb = _mm_loadu_pd(src + 22);
			__m128d xmm_srcc = _mm_loadu_pd(src + 24);
			__m128d xmm_srcd = _mm_loadu_pd(src + 26);
			__m128d xmm_srce = _mm_loadu_pd(src + 28);
			__m128d xmm_srcf = _mm_loadu_pd(src + 30);
			xmm_src0 = _mm_max_pd(xmm_src0, min);
			xmm_src1 = _mm_max_pd(xmm_src1, min);
			xmm_src2 = _mm_max_pd(xmm_src2, min);
			xmm_src3 = _mm_max_pd(xmm_src3, min);
			xmm_src4 = _mm_max_pd(xmm_src4, min);
			xmm_src5 = _mm_max_pd(xmm_src5, min);
			xmm_src6 = _mm_max_pd(xmm_src6, min);
			xmm_src7 = _mm_max_pd(xmm_src7, min);
			xmm_src8 = _mm_max_pd(xmm_src8, min);
			xmm_src9 = _mm_max_pd(xmm_src9, min);
			xmm_srca = _mm_max_pd(xmm_srca, min);
			xmm_srcb = _mm_max_pd(xmm_srcb, min);
			xmm_srcc = _mm_max_pd(xmm_srcc, min);
			xmm_srcd = _mm_max_pd(xmm_srcd, min);
			xmm_srce = _mm_max_pd(xmm_srce, min);
			xmm_srcf = _mm_max_pd(xmm_srcf, min);
			xmm_src0 = _mm_min_pd(xmm_src0, max);
			xmm_src1 = _mm_min_pd(xmm_src1, max);
			xmm_src2 = _mm_min_pd(xmm_src2, max);
			xmm_src3 = _mm_min_pd(xmm_src3, max);
			xmm_src4 = _mm_min_pd(xmm_src4, max);
			xmm_src5 = _mm_min_pd(xmm_src5, max);
			xmm_src6 = _mm_min_pd(xmm_src6, max);
			xmm_src7 = _mm_min_pd(xmm_src7, max);
			xmm_src8 = _mm_min_pd(xmm_src8, max);
			xmm_src9 = _mm_min_pd(xmm_src9, max);
			xmm_srca = _mm_min_pd(xmm_srca, max);
			xmm_srcb = _mm_min_pd(xmm_srcb, max);
			xmm_srcc = _mm_min_pd(xmm_srcc, max);
			xmm_srcd = _mm_min_pd(xmm_srcd, max);
			xmm_srce = _mm_min_pd(xmm_srce, max);
			xmm_srcf = _mm_min_pd(xmm_srcf, max);
			__m128 xmm_dst0 = _mm_cvtpd_ps(xmm_src0);
			__m128 xmm_dst1 = _mm_cvtpd_ps(xmm_src1);
			__m128 xmm_dst2 = _mm_cvtpd_ps(xmm_src2);
			__m128 xmm_dst3 = _mm_cvtpd_ps(xmm_src3);
			__m128 xmm_dst4 = _mm_cvtpd_ps(xmm_src4);
			__m128 xmm_dst5 = _mm_cvtpd_ps(xmm_src5);
			__m128 xmm_dst6 = _mm_cvtpd_ps(xmm_src6);
			__m128 xmm_dst7 = _mm_cvtpd_ps(xmm_src7);
			__m128 xmm_dst8 = _mm_cvtpd_ps(xmm_src8);
			__m128 xmm_dst9 = _mm_cvtpd_ps(xmm_src9);
			__m128 xmm_dsta = _mm_cvtpd_ps(xmm_srca);
			__m128 xmm_dstb = _mm_cvtpd_ps(xmm_srcb);
			__m128 xmm_dstc = _mm_cvtpd_ps(xmm_srcc);
			__m128 xmm_dstd = _mm_cvtpd_ps(xmm_srcd);
			__m128 xmm_dste = _mm_cvtpd_ps(xmm_srce);
			__m128 xmm_dstf = _mm_cvtpd_ps(xmm_srcf);
			xmm_dst0 = _mm_shuffle_ps(xmm_dst0, xmm_dst1, _MM_SHUFFLE(1, 0, 1, 0));
			xmm_dst2 = _mm_shuffle_ps(xmm_dst2, xmm_dst3, _MM_SHUFFLE(1, 0, 1, 0));
			xmm_dst4 = _mm_shuffle_ps(xmm_dst4, xmm_dst5, _MM_SHUFFLE(1, 0, 1, 0));
			xmm_dst6 = _mm_shuffle_ps(xmm_dst6, xmm_dst7, _MM_SHUFFLE(1, 0, 1, 0));
			xmm_dst8 = _mm_shuffle_ps(xmm_dst8, xmm_dst9, _MM_SHUFFLE(1, 0, 1, 0));
			xmm_dsta = _mm_shuffle_ps(xmm_dsta, xmm_dstb, _MM_SHUFFLE(1, 0, 1, 0));
			xmm_dstc = _mm_shuffle_ps(xmm_dstc, xmm_dstd, _MM_SHUFFLE(1, 0, 1, 0));
			xmm_dste = _mm_shuffle_ps(xmm_dste, xmm_dstf, _MM_SHUFFLE(1, 0, 1, 0));
			_mm_storeu_ps(dst, xmm_dst0);
			_mm_storeu_ps(dst + 4, xmm_dst2);
			_mm_storeu_ps(dst + 8, xmm_dst4);
			_mm_storeu_ps(dst + 12, xmm_dst6);
			_mm_storeu_ps(dst + 16, xmm_dst8);
			_mm_storeu_ps(dst + 20, xmm_dsta);
			_mm_storeu_ps(dst + 24, xmm_dstc);
			_mm_storeu_ps(dst + 28, xmm_dste);
		}

		// Function template cvtspd_sse41_small

		template <class T>
		void cvtspd_sse41_small(T* dst, const double* src, size_t n)
		{
			switch (n >> 3)
			{
			case 4:
				cvtspd_sse41_32(dst, src);
			case 0:
				break;
			case 5:
				cvtspd_sse41_32(dst, src);
				src += 32;
				dst += 32;
			case 1:
				cvtspd_sse41_8(dst, src);
				break;
			case 6:
				cvtspd_sse41_32(dst, src);
				src += 32;
				dst += 32;
			case 2:
				cvtspd_sse41_16(dst, src);
				break;
			case 7:
				cvtspd_sse41_32(dst, src);
				src += 32;
				dst += 32;
			case 3:
				cvtspd_sse41_16(dst, src);
				src += 16;
				dst += 16;
				cvtspd_sse41_8(dst, src);
				break;
			}
			cvtspd_tiny(dst, src, n & 7);
		}

		// Function template cvtspd_sse41_medium

		template <class T>
		inline void cvtspd_sse41_medium(T* dst, const double* src, size_t n)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		void cvtspd_sse41_medium<signed char>(signed char* dst, const double* src, size_t n)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(INT8_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT8_MAX));
			__m128d xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128d xmm_src8, xmm_src9, xmm_srca, xmm_srcb, xmm_srcc, xmm_srcd, xmm_srce, xmm_srcf;
			__m128i xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3, xmm_dst4, xmm_dst5, xmm_dst6, xmm_dst7;
			__m128i xmm_dst8, xmm_dst9, xmm_dsta, xmm_dstb, xmm_dstc, xmm_dstd, xmm_dste, xmm_dstf;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				xmm_src0 = _mm_loadu_pd(src);
				xmm_src1 = _mm_loadu_pd(src + 2);
				xmm_src2 = _mm_loadu_pd(src + 4);
				xmm_src3 = _mm_loadu_pd(src + 6);
				xmm_src4 = _mm_loadu_pd(src + 8);
				xmm_src5 = _mm_loadu_pd(src + 10);
				xmm_src6 = _mm_loadu_pd(src + 12);
				xmm_src7 = _mm_loadu_pd(src + 14);
				xmm_src8 = _mm_loadu_pd(src + 16);
				xmm_src9 = _mm_loadu_pd(src + 18);
				xmm_srca = _mm_loadu_pd(src + 20);
				xmm_srcb = _mm_loadu_pd(src + 22);
				xmm_srcc = _mm_loadu_pd(src + 24);
				xmm_srcd = _mm_loadu_pd(src + 26);
				xmm_srce = _mm_loadu_pd(src + 28);
				xmm_srcf = _mm_loadu_pd(src + 30);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
				xmm_src0 = _mm_max_pd(xmm_src0, min);
				xmm_src1 = _mm_max_pd(xmm_src1, min);
				xmm_src2 = _mm_max_pd(xmm_src2, min);
				xmm_src3 = _mm_max_pd(xmm_src3, min);
				xmm_src4 = _mm_max_pd(xmm_src4, min);
				xmm_src5 = _mm_max_pd(xmm_src5, min);
				xmm_src6 = _mm_max_pd(xmm_src6, min);
				xmm_src7 = _mm_max_pd(xmm_src7, min);
				xmm_src8 = _mm_max_pd(xmm_src8, min);
				xmm_src9 = _mm_max_pd(xmm_src9, min);
				xmm_srca = _mm_max_pd(xmm_srca, min);
				xmm_srcb = _mm_max_pd(xmm_srcb, min);
				xmm_srcc = _mm_max_pd(xmm_srcc, min);
				xmm_srcd = _mm_max_pd(xmm_srcd, min);
				xmm_srce = _mm_max_pd(xmm_srce, min);
				xmm_srcf = _mm_max_pd(xmm_srcf, min);
				xmm_src0 = _mm_min_pd(xmm_src0, max);
				xmm_src1 = _mm_min_pd(xmm_src1, max);
				xmm_src2 = _mm_min_pd(xmm_src2, max);
				xmm_src3 = _mm_min_pd(xmm_src3, max);
				xmm_src4 = _mm_min_pd(xmm_src4, max);
				xmm_src5 = _mm_min_pd(xmm_src5, max);
				xmm_src6 = _mm_min_pd(xmm_src6, max);
				xmm_src7 = _mm_min_pd(xmm_src7, max);
				xmm_src8 = _mm_min_pd(xmm_src8, max);
				xmm_src9 = _mm_min_pd(xmm_src9, max);
				xmm_srca = _mm_min_pd(xmm_srca, max);
				xmm_srcb = _mm_min_pd(xmm_srcb, max);
				xmm_srcc = _mm_min_pd(xmm_srcc, max);
				xmm_srcd = _mm_min_pd(xmm_srcd, max);
				xmm_srce = _mm_min_pd(xmm_srce, max);
				xmm_srcf = _mm_min_pd(xmm_srcf, max);
				xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
				xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
				xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
				xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
				xmm_dst4 = _mm_cvttpd_epi32(xmm_src4);
				xmm_dst5 = _mm_cvttpd_epi32(xmm_src5);
				xmm_dst6 = _mm_cvttpd_epi32(xmm_src6);
				xmm_dst7 = _mm_cvttpd_epi32(xmm_src7);
				xmm_dst8 = _mm_cvttpd_epi32(xmm_src8);
				xmm_dst9 = _mm_cvttpd_epi32(xmm_src9);
				xmm_dsta = _mm_cvttpd_epi32(xmm_srca);
				xmm_dstb = _mm_cvttpd_epi32(xmm_srcb);
				xmm_dstc = _mm_cvttpd_epi32(xmm_srcc);
				xmm_dstd = _mm_cvttpd_epi32(xmm_srcd);
				xmm_dste = _mm_cvttpd_epi32(xmm_srce);
				xmm_dstf = _mm_cvttpd_epi32(xmm_srcf);
				xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
				xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
				xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
				xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
				xmm_dst8 = _mm_unpacklo_epi64(xmm_dst8, xmm_dst9);
				xmm_dsta = _mm_unpacklo_epi64(xmm_dsta, xmm_dstb);
				xmm_dstc = _mm_unpacklo_epi64(xmm_dstc, xmm_dstd);
				xmm_dste = _mm_unpacklo_epi64(xmm_dste, xmm_dstf);
				xmm_dst0 = _mm_packs_epi32(xmm_dst0, xmm_dst2);
				xmm_dst4 = _mm_packs_epi32(xmm_dst4, xmm_dst6);
				xmm_dst8 = _mm_packs_epi32(xmm_dst8, xmm_dsta);
				xmm_dstc = _mm_packs_epi32(xmm_dstc, xmm_dste);
				xmm_dst0 = _mm_packs_epi16(xmm_dst0, xmm_dst4);
				xmm_dst8 = _mm_packs_epi16(xmm_dst8, xmm_dstc);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst8);
				src += 32;
				dst += 32;
			}
		}

		template <>
		void cvtspd_sse41_medium<unsigned char>(unsigned char* dst, const double* src, size_t n)
		{
			const __m128d min = _mm_setzero_pd();
			const __m128d max = _mm_set1_pd(static_cast<double>(UINT8_MAX));
			__m128d xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128d xmm_src8, xmm_src9, xmm_srca, xmm_srcb, xmm_srcc, xmm_srcd, xmm_srce, xmm_srcf;
			__m128i xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3, xmm_dst4, xmm_dst5, xmm_dst6, xmm_dst7;
			__m128i xmm_dst8, xmm_dst9, xmm_dsta, xmm_dstb, xmm_dstc, xmm_dstd, xmm_dste, xmm_dstf;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				xmm_src0 = _mm_loadu_pd(src);
				xmm_src1 = _mm_loadu_pd(src + 2);
				xmm_src2 = _mm_loadu_pd(src + 4);
				xmm_src3 = _mm_loadu_pd(src + 6);
				xmm_src4 = _mm_loadu_pd(src + 8);
				xmm_src5 = _mm_loadu_pd(src + 10);
				xmm_src6 = _mm_loadu_pd(src + 12);
				xmm_src7 = _mm_loadu_pd(src + 14);
				xmm_src8 = _mm_loadu_pd(src + 16);
				xmm_src9 = _mm_loadu_pd(src + 18);
				xmm_srca = _mm_loadu_pd(src + 20);
				xmm_srcb = _mm_loadu_pd(src + 22);
				xmm_srcc = _mm_loadu_pd(src + 24);
				xmm_srcd = _mm_loadu_pd(src + 26);
				xmm_srce = _mm_loadu_pd(src + 28);
				xmm_srcf = _mm_loadu_pd(src + 30);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
				xmm_src0 = _mm_max_pd(xmm_src0, min);
				xmm_src1 = _mm_max_pd(xmm_src1, min);
				xmm_src2 = _mm_max_pd(xmm_src2, min);
				xmm_src3 = _mm_max_pd(xmm_src3, min);
				xmm_src4 = _mm_max_pd(xmm_src4, min);
				xmm_src5 = _mm_max_pd(xmm_src5, min);
				xmm_src6 = _mm_max_pd(xmm_src6, min);
				xmm_src7 = _mm_max_pd(xmm_src7, min);
				xmm_src8 = _mm_max_pd(xmm_src8, min);
				xmm_src9 = _mm_max_pd(xmm_src9, min);
				xmm_srca = _mm_max_pd(xmm_srca, min);
				xmm_srcb = _mm_max_pd(xmm_srcb, min);
				xmm_srcc = _mm_max_pd(xmm_srcc, min);
				xmm_srcd = _mm_max_pd(xmm_srcd, min);
				xmm_srce = _mm_max_pd(xmm_srce, min);
				xmm_srcf = _mm_max_pd(xmm_srcf, min);
				xmm_src0 = _mm_min_pd(xmm_src0, max);
				xmm_src1 = _mm_min_pd(xmm_src1, max);
				xmm_src2 = _mm_min_pd(xmm_src2, max);
				xmm_src3 = _mm_min_pd(xmm_src3, max);
				xmm_src4 = _mm_min_pd(xmm_src4, max);
				xmm_src5 = _mm_min_pd(xmm_src5, max);
				xmm_src6 = _mm_min_pd(xmm_src6, max);
				xmm_src7 = _mm_min_pd(xmm_src7, max);
				xmm_src8 = _mm_min_pd(xmm_src8, max);
				xmm_src9 = _mm_min_pd(xmm_src9, max);
				xmm_srca = _mm_min_pd(xmm_srca, max);
				xmm_srcb = _mm_min_pd(xmm_srcb, max);
				xmm_srcc = _mm_min_pd(xmm_srcc, max);
				xmm_srcd = _mm_min_pd(xmm_srcd, max);
				xmm_srce = _mm_min_pd(xmm_srce, max);
				xmm_srcf = _mm_min_pd(xmm_srcf, max);
				xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
				xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
				xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
				xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
				xmm_dst4 = _mm_cvttpd_epi32(xmm_src4);
				xmm_dst5 = _mm_cvttpd_epi32(xmm_src5);
				xmm_dst6 = _mm_cvttpd_epi32(xmm_src6);
				xmm_dst7 = _mm_cvttpd_epi32(xmm_src7);
				xmm_dst8 = _mm_cvttpd_epi32(xmm_src8);
				xmm_dst9 = _mm_cvttpd_epi32(xmm_src9);
				xmm_dsta = _mm_cvttpd_epi32(xmm_srca);
				xmm_dstb = _mm_cvttpd_epi32(xmm_srcb);
				xmm_dstc = _mm_cvttpd_epi32(xmm_srcc);
				xmm_dstd = _mm_cvttpd_epi32(xmm_srcd);
				xmm_dste = _mm_cvttpd_epi32(xmm_srce);
				xmm_dstf = _mm_cvttpd_epi32(xmm_srcf);
				xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
				xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
				xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
				xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
				xmm_dst8 = _mm_unpacklo_epi64(xmm_dst8, xmm_dst9);
				xmm_dsta = _mm_unpacklo_epi64(xmm_dsta, xmm_dstb);
				xmm_dstc = _mm_unpacklo_epi64(xmm_dstc, xmm_dstd);
				xmm_dste = _mm_unpacklo_epi64(xmm_dste, xmm_dstf);
				xmm_dst0 = _mm_packus_epi32(xmm_dst0, xmm_dst2);
				xmm_dst4 = _mm_packus_epi32(xmm_dst4, xmm_dst6);
				xmm_dst8 = _mm_packus_epi32(xmm_dst8, xmm_dsta);
				xmm_dstc = _mm_packus_epi32(xmm_dstc, xmm_dste);
				xmm_dst0 = _mm_packus_epi16(xmm_dst0, xmm_dst4);
				xmm_dst8 = _mm_packus_epi16(xmm_dst8, xmm_dstc);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst8);
				src += 32;
				dst += 32;
			}
		}

		template <>
		void cvtspd_sse41_medium<signed short>(signed short* dst, const double* src, size_t n)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(INT16_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT16_MAX));
			__m128d xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128d xmm_src8, xmm_src9, xmm_srca, xmm_srcb, xmm_srcc, xmm_srcd, xmm_srce, xmm_srcf;
			__m128i xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3, xmm_dst4, xmm_dst5, xmm_dst6, xmm_dst7;
			__m128i xmm_dst8, xmm_dst9, xmm_dsta, xmm_dstb, xmm_dstc, xmm_dstd, xmm_dste, xmm_dstf;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				xmm_src0 = _mm_loadu_pd(src);
				xmm_src1 = _mm_loadu_pd(src + 2);
				xmm_src2 = _mm_loadu_pd(src + 4);
				xmm_src3 = _mm_loadu_pd(src + 6);
				xmm_src4 = _mm_loadu_pd(src + 8);
				xmm_src5 = _mm_loadu_pd(src + 10);
				xmm_src6 = _mm_loadu_pd(src + 12);
				xmm_src7 = _mm_loadu_pd(src + 14);
				xmm_src8 = _mm_loadu_pd(src + 16);
				xmm_src9 = _mm_loadu_pd(src + 18);
				xmm_srca = _mm_loadu_pd(src + 20);
				xmm_srcb = _mm_loadu_pd(src + 22);
				xmm_srcc = _mm_loadu_pd(src + 24);
				xmm_srcd = _mm_loadu_pd(src + 26);
				xmm_srce = _mm_loadu_pd(src + 28);
				xmm_srcf = _mm_loadu_pd(src + 30);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
				xmm_src0 = _mm_max_pd(xmm_src0, min);
				xmm_src1 = _mm_max_pd(xmm_src1, min);
				xmm_src2 = _mm_max_pd(xmm_src2, min);
				xmm_src3 = _mm_max_pd(xmm_src3, min);
				xmm_src4 = _mm_max_pd(xmm_src4, min);
				xmm_src5 = _mm_max_pd(xmm_src5, min);
				xmm_src6 = _mm_max_pd(xmm_src6, min);
				xmm_src7 = _mm_max_pd(xmm_src7, min);
				xmm_src8 = _mm_max_pd(xmm_src8, min);
				xmm_src9 = _mm_max_pd(xmm_src9, min);
				xmm_srca = _mm_max_pd(xmm_srca, min);
				xmm_srcb = _mm_max_pd(xmm_srcb, min);
				xmm_srcc = _mm_max_pd(xmm_srcc, min);
				xmm_srcd = _mm_max_pd(xmm_srcd, min);
				xmm_srce = _mm_max_pd(xmm_srce, min);
				xmm_srcf = _mm_max_pd(xmm_srcf, min);
				xmm_src0 = _mm_min_pd(xmm_src0, max);
				xmm_src1 = _mm_min_pd(xmm_src1, max);
				xmm_src2 = _mm_min_pd(xmm_src2, max);
				xmm_src3 = _mm_min_pd(xmm_src3, max);
				xmm_src4 = _mm_min_pd(xmm_src4, max);
				xmm_src5 = _mm_min_pd(xmm_src5, max);
				xmm_src6 = _mm_min_pd(xmm_src6, max);
				xmm_src7 = _mm_min_pd(xmm_src7, max);
				xmm_src8 = _mm_min_pd(xmm_src8, max);
				xmm_src9 = _mm_min_pd(xmm_src9, max);
				xmm_srca = _mm_min_pd(xmm_srca, max);
				xmm_srcb = _mm_min_pd(xmm_srcb, max);
				xmm_srcc = _mm_min_pd(xmm_srcc, max);
				xmm_srcd = _mm_min_pd(xmm_srcd, max);
				xmm_srce = _mm_min_pd(xmm_srce, max);
				xmm_srcf = _mm_min_pd(xmm_srcf, max);
				xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
				xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
				xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
				xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
				xmm_dst4 = _mm_cvttpd_epi32(xmm_src4);
				xmm_dst5 = _mm_cvttpd_epi32(xmm_src5);
				xmm_dst6 = _mm_cvttpd_epi32(xmm_src6);
				xmm_dst7 = _mm_cvttpd_epi32(xmm_src7);
				xmm_dst8 = _mm_cvttpd_epi32(xmm_src8);
				xmm_dst9 = _mm_cvttpd_epi32(xmm_src9);
				xmm_dsta = _mm_cvttpd_epi32(xmm_srca);
				xmm_dstb = _mm_cvttpd_epi32(xmm_srcb);
				xmm_dstc = _mm_cvttpd_epi32(xmm_srcc);
				xmm_dstd = _mm_cvttpd_epi32(xmm_srcd);
				xmm_dste = _mm_cvttpd_epi32(xmm_srce);
				xmm_dstf = _mm_cvttpd_epi32(xmm_srcf);
				xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
				xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
				xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
				xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
				xmm_dst8 = _mm_unpacklo_epi64(xmm_dst8, xmm_dst9);
				xmm_dsta = _mm_unpacklo_epi64(xmm_dsta, xmm_dstb);
				xmm_dstc = _mm_unpacklo_epi64(xmm_dstc, xmm_dstd);
				xmm_dste = _mm_unpacklo_epi64(xmm_dste, xmm_dstf);
				xmm_dst0 = _mm_packs_epi32(xmm_dst0, xmm_dst2);
				xmm_dst4 = _mm_packs_epi32(xmm_dst4, xmm_dst6);
				xmm_dst8 = _mm_packs_epi32(xmm_dst8, xmm_dsta);
				xmm_dstc = _mm_packs_epi32(xmm_dstc, xmm_dste);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst4);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 2, xmm_dst8);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 3, xmm_dstc);
				src += 32;
				dst += 32;
			}
		}

		template <>
		void cvtspd_sse41_medium<unsigned short>(unsigned short* dst, const double* src, size_t n)
		{
			const __m128d min = _mm_setzero_pd();
			const __m128d max = _mm_set1_pd(static_cast<double>(UINT16_MAX));
			__m128d xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128d xmm_src8, xmm_src9, xmm_srca, xmm_srcb, xmm_srcc, xmm_srcd, xmm_srce, xmm_srcf;
			__m128i xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3, xmm_dst4, xmm_dst5, xmm_dst6, xmm_dst7;
			__m128i xmm_dst8, xmm_dst9, xmm_dsta, xmm_dstb, xmm_dstc, xmm_dstd, xmm_dste, xmm_dstf;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				xmm_src0 = _mm_loadu_pd(src);
				xmm_src1 = _mm_loadu_pd(src + 2);
				xmm_src2 = _mm_loadu_pd(src + 4);
				xmm_src3 = _mm_loadu_pd(src + 6);
				xmm_src4 = _mm_loadu_pd(src + 8);
				xmm_src5 = _mm_loadu_pd(src + 10);
				xmm_src6 = _mm_loadu_pd(src + 12);
				xmm_src7 = _mm_loadu_pd(src + 14);
				xmm_src8 = _mm_loadu_pd(src + 16);
				xmm_src9 = _mm_loadu_pd(src + 18);
				xmm_srca = _mm_loadu_pd(src + 20);
				xmm_srcb = _mm_loadu_pd(src + 22);
				xmm_srcc = _mm_loadu_pd(src + 24);
				xmm_srcd = _mm_loadu_pd(src + 26);
				xmm_srce = _mm_loadu_pd(src + 28);
				xmm_srcf = _mm_loadu_pd(src + 30);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
				xmm_src0 = _mm_max_pd(xmm_src0, min);
				xmm_src1 = _mm_max_pd(xmm_src1, min);
				xmm_src2 = _mm_max_pd(xmm_src2, min);
				xmm_src3 = _mm_max_pd(xmm_src3, min);
				xmm_src4 = _mm_max_pd(xmm_src4, min);
				xmm_src5 = _mm_max_pd(xmm_src5, min);
				xmm_src6 = _mm_max_pd(xmm_src6, min);
				xmm_src7 = _mm_max_pd(xmm_src7, min);
				xmm_src8 = _mm_max_pd(xmm_src8, min);
				xmm_src9 = _mm_max_pd(xmm_src9, min);
				xmm_srca = _mm_max_pd(xmm_srca, min);
				xmm_srcb = _mm_max_pd(xmm_srcb, min);
				xmm_srcc = _mm_max_pd(xmm_srcc, min);
				xmm_srcd = _mm_max_pd(xmm_srcd, min);
				xmm_srce = _mm_max_pd(xmm_srce, min);
				xmm_srcf = _mm_max_pd(xmm_srcf, min);
				xmm_src0 = _mm_min_pd(xmm_src0, max);
				xmm_src1 = _mm_min_pd(xmm_src1, max);
				xmm_src2 = _mm_min_pd(xmm_src2, max);
				xmm_src3 = _mm_min_pd(xmm_src3, max);
				xmm_src4 = _mm_min_pd(xmm_src4, max);
				xmm_src5 = _mm_min_pd(xmm_src5, max);
				xmm_src6 = _mm_min_pd(xmm_src6, max);
				xmm_src7 = _mm_min_pd(xmm_src7, max);
				xmm_src8 = _mm_min_pd(xmm_src8, max);
				xmm_src9 = _mm_min_pd(xmm_src9, max);
				xmm_srca = _mm_min_pd(xmm_srca, max);
				xmm_srcb = _mm_min_pd(xmm_srcb, max);
				xmm_srcc = _mm_min_pd(xmm_srcc, max);
				xmm_srcd = _mm_min_pd(xmm_srcd, max);
				xmm_srce = _mm_min_pd(xmm_srce, max);
				xmm_srcf = _mm_min_pd(xmm_srcf, max);
				xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
				xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
				xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
				xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
				xmm_dst4 = _mm_cvttpd_epi32(xmm_src4);
				xmm_dst5 = _mm_cvttpd_epi32(xmm_src5);
				xmm_dst6 = _mm_cvttpd_epi32(xmm_src6);
				xmm_dst7 = _mm_cvttpd_epi32(xmm_src7);
				xmm_dst8 = _mm_cvttpd_epi32(xmm_src8);
				xmm_dst9 = _mm_cvttpd_epi32(xmm_src9);
				xmm_dsta = _mm_cvttpd_epi32(xmm_srca);
				xmm_dstb = _mm_cvttpd_epi32(xmm_srcb);
				xmm_dstc = _mm_cvttpd_epi32(xmm_srcc);
				xmm_dstd = _mm_cvttpd_epi32(xmm_srcd);
				xmm_dste = _mm_cvttpd_epi32(xmm_srce);
				xmm_dstf = _mm_cvttpd_epi32(xmm_srcf);
				xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
				xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
				xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
				xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
				xmm_dst8 = _mm_unpacklo_epi64(xmm_dst8, xmm_dst9);
				xmm_dsta = _mm_unpacklo_epi64(xmm_dsta, xmm_dstb);
				xmm_dstc = _mm_unpacklo_epi64(xmm_dstc, xmm_dstd);
				xmm_dste = _mm_unpacklo_epi64(xmm_dste, xmm_dstf);
				xmm_dst0 = _mm_packus_epi32(xmm_dst0, xmm_dst2);
				xmm_dst4 = _mm_packus_epi32(xmm_dst4, xmm_dst6);
				xmm_dst8 = _mm_packus_epi32(xmm_dst8, xmm_dsta);
				xmm_dstc = _mm_packus_epi32(xmm_dstc, xmm_dste);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst4);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 2, xmm_dst8);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 3, xmm_dstc);
				src += 32;
				dst += 32;
			}
		}

		template <>
		void cvtspd_sse41_medium<signed int>(signed int* dst, const double* src, size_t n)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(INT32_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT32_MAX));
			__m128d xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128d xmm_src8, xmm_src9, xmm_srca, xmm_srcb, xmm_srcc, xmm_srcd, xmm_srce, xmm_srcf;
			__m128i xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3, xmm_dst4, xmm_dst5, xmm_dst6, xmm_dst7;
			__m128i xmm_dst8, xmm_dst9, xmm_dsta, xmm_dstb, xmm_dstc, xmm_dstd, xmm_dste, xmm_dstf;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				xmm_src0 = _mm_loadu_pd(src);
				xmm_src1 = _mm_loadu_pd(src + 2);
				xmm_src2 = _mm_loadu_pd(src + 4);
				xmm_src3 = _mm_loadu_pd(src + 6);
				xmm_src4 = _mm_loadu_pd(src + 8);
				xmm_src5 = _mm_loadu_pd(src + 10);
				xmm_src6 = _mm_loadu_pd(src + 12);
				xmm_src7 = _mm_loadu_pd(src + 14);
				xmm_src8 = _mm_loadu_pd(src + 16);
				xmm_src9 = _mm_loadu_pd(src + 18);
				xmm_srca = _mm_loadu_pd(src + 20);
				xmm_srcb = _mm_loadu_pd(src + 22);
				xmm_srcc = _mm_loadu_pd(src + 24);
				xmm_srcd = _mm_loadu_pd(src + 26);
				xmm_srce = _mm_loadu_pd(src + 28);
				xmm_srcf = _mm_loadu_pd(src + 30);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
				xmm_src0 = _mm_max_pd(xmm_src0, min);
				xmm_src1 = _mm_max_pd(xmm_src1, min);
				xmm_src2 = _mm_max_pd(xmm_src2, min);
				xmm_src3 = _mm_max_pd(xmm_src3, min);
				xmm_src4 = _mm_max_pd(xmm_src4, min);
				xmm_src5 = _mm_max_pd(xmm_src5, min);
				xmm_src6 = _mm_max_pd(xmm_src6, min);
				xmm_src7 = _mm_max_pd(xmm_src7, min);
				xmm_src8 = _mm_max_pd(xmm_src8, min);
				xmm_src9 = _mm_max_pd(xmm_src9, min);
				xmm_srca = _mm_max_pd(xmm_srca, min);
				xmm_srcb = _mm_max_pd(xmm_srcb, min);
				xmm_srcc = _mm_max_pd(xmm_srcc, min);
				xmm_srcd = _mm_max_pd(xmm_srcd, min);
				xmm_srce = _mm_max_pd(xmm_srce, min);
				xmm_srcf = _mm_max_pd(xmm_srcf, min);
				xmm_src0 = _mm_min_pd(xmm_src0, max);
				xmm_src1 = _mm_min_pd(xmm_src1, max);
				xmm_src2 = _mm_min_pd(xmm_src2, max);
				xmm_src3 = _mm_min_pd(xmm_src3, max);
				xmm_src4 = _mm_min_pd(xmm_src4, max);
				xmm_src5 = _mm_min_pd(xmm_src5, max);
				xmm_src6 = _mm_min_pd(xmm_src6, max);
				xmm_src7 = _mm_min_pd(xmm_src7, max);
				xmm_src8 = _mm_min_pd(xmm_src8, max);
				xmm_src9 = _mm_min_pd(xmm_src9, max);
				xmm_srca = _mm_min_pd(xmm_srca, max);
				xmm_srcb = _mm_min_pd(xmm_srcb, max);
				xmm_srcc = _mm_min_pd(xmm_srcc, max);
				xmm_srcd = _mm_min_pd(xmm_srcd, max);
				xmm_srce = _mm_min_pd(xmm_srce, max);
				xmm_srcf = _mm_min_pd(xmm_srcf, max);
				xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
				xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
				xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
				xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
				xmm_dst4 = _mm_cvttpd_epi32(xmm_src4);
				xmm_dst5 = _mm_cvttpd_epi32(xmm_src5);
				xmm_dst6 = _mm_cvttpd_epi32(xmm_src6);
				xmm_dst7 = _mm_cvttpd_epi32(xmm_src7);
				xmm_dst8 = _mm_cvttpd_epi32(xmm_src8);
				xmm_dst9 = _mm_cvttpd_epi32(xmm_src9);
				xmm_dsta = _mm_cvttpd_epi32(xmm_srca);
				xmm_dstb = _mm_cvttpd_epi32(xmm_srcb);
				xmm_dstc = _mm_cvttpd_epi32(xmm_srcc);
				xmm_dstd = _mm_cvttpd_epi32(xmm_srcd);
				xmm_dste = _mm_cvttpd_epi32(xmm_srce);
				xmm_dstf = _mm_cvttpd_epi32(xmm_srcf);
				xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
				xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
				xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
				xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
				xmm_dst8 = _mm_unpacklo_epi64(xmm_dst8, xmm_dst9);
				xmm_dsta = _mm_unpacklo_epi64(xmm_dsta, xmm_dstb);
				xmm_dstc = _mm_unpacklo_epi64(xmm_dstc, xmm_dstd);
				xmm_dste = _mm_unpacklo_epi64(xmm_dste, xmm_dstf);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst2);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 2, xmm_dst4);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 3, xmm_dst6);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 4, xmm_dst8);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 5, xmm_dsta);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 6, xmm_dstc);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 7, xmm_dste);
				src += 32;
				dst += 32;
			}
		}

		template <>
		void cvtspd_sse41_medium<unsigned int>(unsigned int* dst, const double* src, size_t n)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(INT32_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT32_MAX));
			const __m128d offset = _mm_set1_pd(2.147483648e+9);
			const __m128i shift = _mm_set1_epi32(2147483648);
			__m128d xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128d xmm_src8, xmm_src9, xmm_srca, xmm_srcb, xmm_srcc, xmm_srcd, xmm_srce, xmm_srcf;
			__m128i xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3, xmm_dst4, xmm_dst5, xmm_dst6, xmm_dst7;
			__m128i xmm_dst8, xmm_dst9, xmm_dsta, xmm_dstb, xmm_dstc, xmm_dstd, xmm_dste, xmm_dstf;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				xmm_src0 = _mm_loadu_pd(src);
				xmm_src1 = _mm_loadu_pd(src + 2);
				xmm_src2 = _mm_loadu_pd(src + 4);
				xmm_src3 = _mm_loadu_pd(src + 6);
				xmm_src4 = _mm_loadu_pd(src + 8);
				xmm_src5 = _mm_loadu_pd(src + 10);
				xmm_src6 = _mm_loadu_pd(src + 12);
				xmm_src7 = _mm_loadu_pd(src + 14);
				xmm_src8 = _mm_loadu_pd(src + 16);
				xmm_src9 = _mm_loadu_pd(src + 18);
				xmm_srca = _mm_loadu_pd(src + 20);
				xmm_srcb = _mm_loadu_pd(src + 22);
				xmm_srcc = _mm_loadu_pd(src + 24);
				xmm_srcd = _mm_loadu_pd(src + 26);
				xmm_srce = _mm_loadu_pd(src + 28);
				xmm_srcf = _mm_loadu_pd(src + 30);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
				xmm_src0 = _mm_sub_pd(xmm_src0, offset);
				xmm_src1 = _mm_sub_pd(xmm_src1, offset);
				xmm_src2 = _mm_sub_pd(xmm_src2, offset);
				xmm_src3 = _mm_sub_pd(xmm_src3, offset);
				xmm_src4 = _mm_sub_pd(xmm_src4, offset);
				xmm_src5 = _mm_sub_pd(xmm_src5, offset);
				xmm_src6 = _mm_sub_pd(xmm_src6, offset);
				xmm_src7 = _mm_sub_pd(xmm_src7, offset);
				xmm_src8 = _mm_sub_pd(xmm_src8, offset);
				xmm_src9 = _mm_sub_pd(xmm_src9, offset);
				xmm_srca = _mm_sub_pd(xmm_srca, offset);
				xmm_srcb = _mm_sub_pd(xmm_srcb, offset);
				xmm_srcc = _mm_sub_pd(xmm_srcc, offset);
				xmm_srcd = _mm_sub_pd(xmm_srcd, offset);
				xmm_srce = _mm_sub_pd(xmm_srce, offset);
				xmm_srcf = _mm_sub_pd(xmm_srcf, offset);
				xmm_src0 = _mm_max_pd(xmm_src0, min);
				xmm_src1 = _mm_max_pd(xmm_src1, min);
				xmm_src2 = _mm_max_pd(xmm_src2, min);
				xmm_src3 = _mm_max_pd(xmm_src3, min);
				xmm_src4 = _mm_max_pd(xmm_src4, min);
				xmm_src5 = _mm_max_pd(xmm_src5, min);
				xmm_src6 = _mm_max_pd(xmm_src6, min);
				xmm_src7 = _mm_max_pd(xmm_src7, min);
				xmm_src8 = _mm_max_pd(xmm_src8, min);
				xmm_src9 = _mm_max_pd(xmm_src9, min);
				xmm_srca = _mm_max_pd(xmm_srca, min);
				xmm_srcb = _mm_max_pd(xmm_srcb, min);
				xmm_srcc = _mm_max_pd(xmm_srcc, min);
				xmm_srcd = _mm_max_pd(xmm_srcd, min);
				xmm_srce = _mm_max_pd(xmm_srce, min);
				xmm_srcf = _mm_max_pd(xmm_srcf, min);
				xmm_src0 = _mm_min_pd(xmm_src0, max);
				xmm_src1 = _mm_min_pd(xmm_src1, max);
				xmm_src2 = _mm_min_pd(xmm_src2, max);
				xmm_src3 = _mm_min_pd(xmm_src3, max);
				xmm_src4 = _mm_min_pd(xmm_src4, max);
				xmm_src5 = _mm_min_pd(xmm_src5, max);
				xmm_src6 = _mm_min_pd(xmm_src6, max);
				xmm_src7 = _mm_min_pd(xmm_src7, max);
				xmm_src8 = _mm_min_pd(xmm_src8, max);
				xmm_src9 = _mm_min_pd(xmm_src9, max);
				xmm_srca = _mm_min_pd(xmm_srca, max);
				xmm_srcb = _mm_min_pd(xmm_srcb, max);
				xmm_srcc = _mm_min_pd(xmm_srcc, max);
				xmm_srcd = _mm_min_pd(xmm_srcd, max);
				xmm_srce = _mm_min_pd(xmm_srce, max);
				xmm_srcf = _mm_min_pd(xmm_srcf, max);
				xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
				xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
				xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
				xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
				xmm_dst4 = _mm_cvttpd_epi32(xmm_src4);
				xmm_dst5 = _mm_cvttpd_epi32(xmm_src5);
				xmm_dst6 = _mm_cvttpd_epi32(xmm_src6);
				xmm_dst7 = _mm_cvttpd_epi32(xmm_src7);
				xmm_dst8 = _mm_cvttpd_epi32(xmm_src8);
				xmm_dst9 = _mm_cvttpd_epi32(xmm_src9);
				xmm_dsta = _mm_cvttpd_epi32(xmm_srca);
				xmm_dstb = _mm_cvttpd_epi32(xmm_srcb);
				xmm_dstc = _mm_cvttpd_epi32(xmm_srcc);
				xmm_dstd = _mm_cvttpd_epi32(xmm_srcd);
				xmm_dste = _mm_cvttpd_epi32(xmm_srce);
				xmm_dstf = _mm_cvttpd_epi32(xmm_srcf);
				xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
				xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
				xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
				xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
				xmm_dst8 = _mm_unpacklo_epi64(xmm_dst8, xmm_dst9);
				xmm_dsta = _mm_unpacklo_epi64(xmm_dsta, xmm_dstb);
				xmm_dstc = _mm_unpacklo_epi64(xmm_dstc, xmm_dstd);
				xmm_dste = _mm_unpacklo_epi64(xmm_dste, xmm_dstf);
				xmm_dst0 = _mm_add_epi32(xmm_dst0, shift);
				xmm_dst2 = _mm_add_epi32(xmm_dst2, shift);
				xmm_dst4 = _mm_add_epi32(xmm_dst4, shift);
				xmm_dst6 = _mm_add_epi32(xmm_dst6, shift);
				xmm_dst8 = _mm_add_epi32(xmm_dst8, shift);
				xmm_dsta = _mm_add_epi32(xmm_dsta, shift);
				xmm_dstc = _mm_add_epi32(xmm_dstc, shift);
				xmm_dste = _mm_add_epi32(xmm_dste, shift);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst2);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 2, xmm_dst4);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 3, xmm_dst6);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 4, xmm_dst8);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 5, xmm_dsta);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 6, xmm_dstc);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst) + 7, xmm_dste);
				src += 32;
				dst += 32;
			}
		}

		template <>
		void cvtspd_sse41_medium<float>(float* dst, const double* src, size_t n)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(-FLT_MAX));
			const __m128d max = _mm_set1_pd(static_cast<double>(FLT_MAX));
			__m128d xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128d xmm_src8, xmm_src9, xmm_srca, xmm_srcb, xmm_srcc, xmm_srcd, xmm_srce, xmm_srcf;
			__m128 xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3, xmm_dst4, xmm_dst5, xmm_dst6, xmm_dst7;
			__m128 xmm_dst8, xmm_dst9, xmm_dsta, xmm_dstb, xmm_dstc, xmm_dstd, xmm_dste, xmm_dstf;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(src), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				xmm_src0 = _mm_loadu_pd(src);
				xmm_src1 = _mm_loadu_pd(src + 2);
				xmm_src2 = _mm_loadu_pd(src + 4);
				xmm_src3 = _mm_loadu_pd(src + 6);
				xmm_src4 = _mm_loadu_pd(src + 8);
				xmm_src5 = _mm_loadu_pd(src + 10);
				xmm_src6 = _mm_loadu_pd(src + 12);
				xmm_src7 = _mm_loadu_pd(src + 14);
				xmm_src8 = _mm_loadu_pd(src + 16);
				xmm_src9 = _mm_loadu_pd(src + 18);
				xmm_srca = _mm_loadu_pd(src + 20);
				xmm_srcb = _mm_loadu_pd(src + 22);
				xmm_srcc = _mm_loadu_pd(src + 24);
				xmm_srcd = _mm_loadu_pd(src + 26);
				xmm_srce = _mm_loadu_pd(src + 28);
				xmm_srcf = _mm_loadu_pd(src + 30);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
				xmm_src0 = _mm_max_pd(xmm_src0, min);
				xmm_src1 = _mm_max_pd(xmm_src1, min);
				xmm_src2 = _mm_max_pd(xmm_src2, min);
				xmm_src3 = _mm_max_pd(xmm_src3, min);
				xmm_src4 = _mm_max_pd(xmm_src4, min);
				xmm_src5 = _mm_max_pd(xmm_src5, min);
				xmm_src6 = _mm_max_pd(xmm_src6, min);
				xmm_src7 = _mm_max_pd(xmm_src7, min);
				xmm_src8 = _mm_max_pd(xmm_src8, min);
				xmm_src9 = _mm_max_pd(xmm_src9, min);
				xmm_srca = _mm_max_pd(xmm_srca, min);
				xmm_srcb = _mm_max_pd(xmm_srcb, min);
				xmm_srcc = _mm_max_pd(xmm_srcc, min);
				xmm_srcd = _mm_max_pd(xmm_srcd, min);
				xmm_srce = _mm_max_pd(xmm_srce, min);
				xmm_srcf = _mm_max_pd(xmm_srcf, min);
				xmm_src0 = _mm_min_pd(xmm_src0, max);
				xmm_src1 = _mm_min_pd(xmm_src1, max);
				xmm_src2 = _mm_min_pd(xmm_src2, max);
				xmm_src3 = _mm_min_pd(xmm_src3, max);
				xmm_src4 = _mm_min_pd(xmm_src4, max);
				xmm_src5 = _mm_min_pd(xmm_src5, max);
				xmm_src6 = _mm_min_pd(xmm_src6, max);
				xmm_src7 = _mm_min_pd(xmm_src7, max);
				xmm_src8 = _mm_min_pd(xmm_src8, max);
				xmm_src9 = _mm_min_pd(xmm_src9, max);
				xmm_srca = _mm_min_pd(xmm_srca, max);
				xmm_srcb = _mm_min_pd(xmm_srcb, max);
				xmm_srcc = _mm_min_pd(xmm_srcc, max);
				xmm_srcd = _mm_min_pd(xmm_srcd, max);
				xmm_srce = _mm_min_pd(xmm_srce, max);
				xmm_srcf = _mm_min_pd(xmm_srcf, max);
				xmm_dst0 = _mm_cvtpd_ps(xmm_src0);
				xmm_dst1 = _mm_cvtpd_ps(xmm_src1);
				xmm_dst2 = _mm_cvtpd_ps(xmm_src2);
				xmm_dst3 = _mm_cvtpd_ps(xmm_src3);
				xmm_dst4 = _mm_cvtpd_ps(xmm_src4);
				xmm_dst5 = _mm_cvtpd_ps(xmm_src5);
				xmm_dst6 = _mm_cvtpd_ps(xmm_src6);
				xmm_dst7 = _mm_cvtpd_ps(xmm_src7);
				xmm_dst8 = _mm_cvtpd_ps(xmm_src8);
				xmm_dst9 = _mm_cvtpd_ps(xmm_src9);
				xmm_dsta = _mm_cvtpd_ps(xmm_srca);
				xmm_dstb = _mm_cvtpd_ps(xmm_srcb);
				xmm_dstc = _mm_cvtpd_ps(xmm_srcc);
				xmm_dstd = _mm_cvtpd_ps(xmm_srcd);
				xmm_dste = _mm_cvtpd_ps(xmm_srce);
				xmm_dstf = _mm_cvtpd_ps(xmm_srcf);
				xmm_dst0 = _mm_shuffle_ps(xmm_dst0, xmm_dst1, _MM_SHUFFLE(1, 0, 1, 0));
				xmm_dst2 = _mm_shuffle_ps(xmm_dst2, xmm_dst3, _MM_SHUFFLE(1, 0, 1, 0));
				xmm_dst4 = _mm_shuffle_ps(xmm_dst4, xmm_dst5, _MM_SHUFFLE(1, 0, 1, 0));
				xmm_dst6 = _mm_shuffle_ps(xmm_dst6, xmm_dst7, _MM_SHUFFLE(1, 0, 1, 0));
				xmm_dst8 = _mm_shuffle_ps(xmm_dst8, xmm_dst9, _MM_SHUFFLE(1, 0, 1, 0));
				xmm_dsta = _mm_shuffle_ps(xmm_dsta, xmm_dstb, _MM_SHUFFLE(1, 0, 1, 0));
				xmm_dstc = _mm_shuffle_ps(xmm_dstc, xmm_dstd, _MM_SHUFFLE(1, 0, 1, 0));
				xmm_dste = _mm_shuffle_ps(xmm_dste, xmm_dstf, _MM_SHUFFLE(1, 0, 1, 0));
				_mm_storeu_ps(dst, xmm_dst0);
				_mm_storeu_ps(dst + 4, xmm_dst2);
				_mm_storeu_ps(dst + 8, xmm_dst4);
				_mm_storeu_ps(dst + 12, xmm_dst6);
				_mm_storeu_ps(dst + 16, xmm_dst8);
				_mm_storeu_ps(dst + 20, xmm_dsta);
				_mm_storeu_ps(dst + 24, xmm_dstc);
				_mm_storeu_ps(dst + 28, xmm_dste);
				src += 32;
				dst += 32;
			}
		}

		// Function template cvtspd_sse41_large

		template <class T>
		inline void cvtspd_sse41_large(T* dst, const double* src, size_t n)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		void cvtspd_sse41_large<signed char>(signed char* dst, const double* src, size_t n)
		{
			const size_t padding = 16 - (reinterpret_cast<size_t>(dst) & 15);
			const __m128d min = _mm_set1_pd(static_cast<double>(INT8_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT8_MAX));
			__m128d xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128d xmm_src8, xmm_src9, xmm_srca, xmm_srcb, xmm_srcc, xmm_srcd, xmm_srce, xmm_srcf;
			__m128i xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3, xmm_dst4, xmm_dst5, xmm_dst6, xmm_dst7;
			__m128i xmm_dst8, xmm_dst9, xmm_dsta, xmm_dstb, xmm_dstc, xmm_dstd, xmm_dste, xmm_dstf;

			// Align the destination to a 16-byte boundary.
			xmm_src0 = _mm_loadu_pd(src);
			xmm_src1 = _mm_loadu_pd(src + 2);
			xmm_src2 = _mm_loadu_pd(src + 4);
			xmm_src3 = _mm_loadu_pd(src + 6);
			xmm_src4 = _mm_loadu_pd(src + 8);
			xmm_src5 = _mm_loadu_pd(src + 10);
			xmm_src6 = _mm_loadu_pd(src + 12);
			xmm_src7 = _mm_loadu_pd(src + 14);
			xmm_src0 = _mm_max_pd(xmm_src0, min);
			xmm_src1 = _mm_max_pd(xmm_src1, min);
			xmm_src2 = _mm_max_pd(xmm_src2, min);
			xmm_src3 = _mm_max_pd(xmm_src3, min);
			xmm_src4 = _mm_max_pd(xmm_src4, min);
			xmm_src5 = _mm_max_pd(xmm_src5, min);
			xmm_src6 = _mm_max_pd(xmm_src6, min);
			xmm_src7 = _mm_max_pd(xmm_src7, min);
			xmm_src0 = _mm_min_pd(xmm_src0, max);
			xmm_src1 = _mm_min_pd(xmm_src1, max);
			xmm_src2 = _mm_min_pd(xmm_src2, max);
			xmm_src3 = _mm_min_pd(xmm_src3, max);
			xmm_src4 = _mm_min_pd(xmm_src4, max);
			xmm_src5 = _mm_min_pd(xmm_src5, max);
			xmm_src6 = _mm_min_pd(xmm_src6, max);
			xmm_src7 = _mm_min_pd(xmm_src7, max);
			xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
			xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
			xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
			xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
			xmm_dst4 = _mm_cvttpd_epi32(xmm_src4);
			xmm_dst5 = _mm_cvttpd_epi32(xmm_src5);
			xmm_dst6 = _mm_cvttpd_epi32(xmm_src6);
			xmm_dst7 = _mm_cvttpd_epi32(xmm_src7);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
			xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
			xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
			xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
			xmm_dst0 = _mm_packs_epi32(xmm_dst0, xmm_dst2);
			xmm_dst4 = _mm_packs_epi32(xmm_dst4, xmm_dst6);
			xmm_dst0 = _mm_packs_epi16(xmm_dst0, xmm_dst4);
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
					xmm_src0 = _mm_load_pd(src);
					xmm_src1 = _mm_load_pd(src + 2);
					xmm_src2 = _mm_load_pd(src + 4);
					xmm_src3 = _mm_load_pd(src + 6);
					xmm_src4 = _mm_load_pd(src + 8);
					xmm_src5 = _mm_load_pd(src + 10);
					xmm_src6 = _mm_load_pd(src + 12);
					xmm_src7 = _mm_load_pd(src + 14);
					xmm_src8 = _mm_load_pd(src + 16);
					xmm_src9 = _mm_load_pd(src + 18);
					xmm_srca = _mm_load_pd(src + 20);
					xmm_srcb = _mm_load_pd(src + 22);
					xmm_srcc = _mm_load_pd(src + 24);
					xmm_srcd = _mm_load_pd(src + 26);
					xmm_srce = _mm_load_pd(src + 28);
					xmm_srcf = _mm_load_pd(src + 30);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					xmm_src0 = _mm_max_pd(xmm_src0, min);
					xmm_src1 = _mm_max_pd(xmm_src1, min);
					xmm_src2 = _mm_max_pd(xmm_src2, min);
					xmm_src3 = _mm_max_pd(xmm_src3, min);
					xmm_src4 = _mm_max_pd(xmm_src4, min);
					xmm_src5 = _mm_max_pd(xmm_src5, min);
					xmm_src6 = _mm_max_pd(xmm_src6, min);
					xmm_src7 = _mm_max_pd(xmm_src7, min);
					xmm_src8 = _mm_max_pd(xmm_src8, min);
					xmm_src9 = _mm_max_pd(xmm_src9, min);
					xmm_srca = _mm_max_pd(xmm_srca, min);
					xmm_srcb = _mm_max_pd(xmm_srcb, min);
					xmm_srcc = _mm_max_pd(xmm_srcc, min);
					xmm_srcd = _mm_max_pd(xmm_srcd, min);
					xmm_srce = _mm_max_pd(xmm_srce, min);
					xmm_srcf = _mm_max_pd(xmm_srcf, min);
					xmm_src0 = _mm_min_pd(xmm_src0, max);
					xmm_src1 = _mm_min_pd(xmm_src1, max);
					xmm_src2 = _mm_min_pd(xmm_src2, max);
					xmm_src3 = _mm_min_pd(xmm_src3, max);
					xmm_src4 = _mm_min_pd(xmm_src4, max);
					xmm_src5 = _mm_min_pd(xmm_src5, max);
					xmm_src6 = _mm_min_pd(xmm_src6, max);
					xmm_src7 = _mm_min_pd(xmm_src7, max);
					xmm_src8 = _mm_min_pd(xmm_src8, max);
					xmm_src9 = _mm_min_pd(xmm_src9, max);
					xmm_srca = _mm_min_pd(xmm_srca, max);
					xmm_srcb = _mm_min_pd(xmm_srcb, max);
					xmm_srcc = _mm_min_pd(xmm_srcc, max);
					xmm_srcd = _mm_min_pd(xmm_srcd, max);
					xmm_srce = _mm_min_pd(xmm_srce, max);
					xmm_srcf = _mm_min_pd(xmm_srcf, max);
					xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
					xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
					xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
					xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
					xmm_dst4 = _mm_cvttpd_epi32(xmm_src4);
					xmm_dst5 = _mm_cvttpd_epi32(xmm_src5);
					xmm_dst6 = _mm_cvttpd_epi32(xmm_src6);
					xmm_dst7 = _mm_cvttpd_epi32(xmm_src7);
					xmm_dst8 = _mm_cvttpd_epi32(xmm_src8);
					xmm_dst9 = _mm_cvttpd_epi32(xmm_src9);
					xmm_dsta = _mm_cvttpd_epi32(xmm_srca);
					xmm_dstb = _mm_cvttpd_epi32(xmm_srcb);
					xmm_dstc = _mm_cvttpd_epi32(xmm_srcc);
					xmm_dstd = _mm_cvttpd_epi32(xmm_srcd);
					xmm_dste = _mm_cvttpd_epi32(xmm_srce);
					xmm_dstf = _mm_cvttpd_epi32(xmm_srcf);
					xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
					xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
					xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
					xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
					xmm_dst8 = _mm_unpacklo_epi64(xmm_dst8, xmm_dst9);
					xmm_dsta = _mm_unpacklo_epi64(xmm_dsta, xmm_dstb);
					xmm_dstc = _mm_unpacklo_epi64(xmm_dstc, xmm_dstd);
					xmm_dste = _mm_unpacklo_epi64(xmm_dste, xmm_dstf);
					xmm_dst0 = _mm_packs_epi32(xmm_dst0, xmm_dst2);
					xmm_dst4 = _mm_packs_epi32(xmm_dst4, xmm_dst6);
					xmm_dst8 = _mm_packs_epi32(xmm_dst8, xmm_dsta);
					xmm_dstc = _mm_packs_epi32(xmm_dstc, xmm_dste);
					xmm_dst0 = _mm_packs_epi16(xmm_dst0, xmm_dst4);
					xmm_dst8 = _mm_packs_epi16(xmm_dst8, xmm_dstc);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst8);
					src += 32;
					dst += 32;
				}
			}
			else
			{
				for (; n >= 32; n -= 32)
				{
					xmm_src0 = _mm_loadu_pd(src);
					xmm_src1 = _mm_loadu_pd(src + 2);
					xmm_src2 = _mm_loadu_pd(src + 4);
					xmm_src3 = _mm_loadu_pd(src + 6);
					xmm_src4 = _mm_loadu_pd(src + 8);
					xmm_src5 = _mm_loadu_pd(src + 10);
					xmm_src6 = _mm_loadu_pd(src + 12);
					xmm_src7 = _mm_loadu_pd(src + 14);
					xmm_src8 = _mm_loadu_pd(src + 16);
					xmm_src9 = _mm_loadu_pd(src + 18);
					xmm_srca = _mm_loadu_pd(src + 20);
					xmm_srcb = _mm_loadu_pd(src + 22);
					xmm_srcc = _mm_loadu_pd(src + 24);
					xmm_srcd = _mm_loadu_pd(src + 26);
					xmm_srce = _mm_loadu_pd(src + 28);
					xmm_srcf = _mm_loadu_pd(src + 30);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					xmm_src0 = _mm_max_pd(xmm_src0, min);
					xmm_src1 = _mm_max_pd(xmm_src1, min);
					xmm_src2 = _mm_max_pd(xmm_src2, min);
					xmm_src3 = _mm_max_pd(xmm_src3, min);
					xmm_src4 = _mm_max_pd(xmm_src4, min);
					xmm_src5 = _mm_max_pd(xmm_src5, min);
					xmm_src6 = _mm_max_pd(xmm_src6, min);
					xmm_src7 = _mm_max_pd(xmm_src7, min);
					xmm_src8 = _mm_max_pd(xmm_src8, min);
					xmm_src9 = _mm_max_pd(xmm_src9, min);
					xmm_srca = _mm_max_pd(xmm_srca, min);
					xmm_srcb = _mm_max_pd(xmm_srcb, min);
					xmm_srcc = _mm_max_pd(xmm_srcc, min);
					xmm_srcd = _mm_max_pd(xmm_srcd, min);
					xmm_srce = _mm_max_pd(xmm_srce, min);
					xmm_srcf = _mm_max_pd(xmm_srcf, min);
					xmm_src0 = _mm_min_pd(xmm_src0, max);
					xmm_src1 = _mm_min_pd(xmm_src1, max);
					xmm_src2 = _mm_min_pd(xmm_src2, max);
					xmm_src3 = _mm_min_pd(xmm_src3, max);
					xmm_src4 = _mm_min_pd(xmm_src4, max);
					xmm_src5 = _mm_min_pd(xmm_src5, max);
					xmm_src6 = _mm_min_pd(xmm_src6, max);
					xmm_src7 = _mm_min_pd(xmm_src7, max);
					xmm_src8 = _mm_min_pd(xmm_src8, max);
					xmm_src9 = _mm_min_pd(xmm_src9, max);
					xmm_srca = _mm_min_pd(xmm_srca, max);
					xmm_srcb = _mm_min_pd(xmm_srcb, max);
					xmm_srcc = _mm_min_pd(xmm_srcc, max);
					xmm_srcd = _mm_min_pd(xmm_srcd, max);
					xmm_srce = _mm_min_pd(xmm_srce, max);
					xmm_srcf = _mm_min_pd(xmm_srcf, max);
					xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
					xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
					xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
					xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
					xmm_dst4 = _mm_cvttpd_epi32(xmm_src4);
					xmm_dst5 = _mm_cvttpd_epi32(xmm_src5);
					xmm_dst6 = _mm_cvttpd_epi32(xmm_src6);
					xmm_dst7 = _mm_cvttpd_epi32(xmm_src7);
					xmm_dst8 = _mm_cvttpd_epi32(xmm_src8);
					xmm_dst9 = _mm_cvttpd_epi32(xmm_src9);
					xmm_dsta = _mm_cvttpd_epi32(xmm_srca);
					xmm_dstb = _mm_cvttpd_epi32(xmm_srcb);
					xmm_dstc = _mm_cvttpd_epi32(xmm_srcc);
					xmm_dstd = _mm_cvttpd_epi32(xmm_srcd);
					xmm_dste = _mm_cvttpd_epi32(xmm_srce);
					xmm_dstf = _mm_cvttpd_epi32(xmm_srcf);
					xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
					xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
					xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
					xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
					xmm_dst8 = _mm_unpacklo_epi64(xmm_dst8, xmm_dst9);
					xmm_dsta = _mm_unpacklo_epi64(xmm_dsta, xmm_dstb);
					xmm_dstc = _mm_unpacklo_epi64(xmm_dstc, xmm_dstd);
					xmm_dste = _mm_unpacklo_epi64(xmm_dste, xmm_dstf);
					xmm_dst0 = _mm_packs_epi32(xmm_dst0, xmm_dst2);
					xmm_dst4 = _mm_packs_epi32(xmm_dst4, xmm_dst6);
					xmm_dst8 = _mm_packs_epi32(xmm_dst8, xmm_dsta);
					xmm_dstc = _mm_packs_epi32(xmm_dstc, xmm_dste);
					xmm_dst0 = _mm_packs_epi16(xmm_dst0, xmm_dst4);
					xmm_dst8 = _mm_packs_epi16(xmm_dst8, xmm_dstc);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst8);
					src += 32;
					dst += 32;
				}
			}
		}

		template <>
		void cvtspd_sse41_large<unsigned char>(unsigned char* dst, const double* src, size_t n)
		{
			const size_t padding = 16 - (reinterpret_cast<size_t>(dst) & 15);
			const __m128d min = _mm_setzero_pd();
			const __m128d max = _mm_set1_pd(static_cast<double>(UINT8_MAX));
			__m128d xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128d xmm_src8, xmm_src9, xmm_srca, xmm_srcb, xmm_srcc, xmm_srcd, xmm_srce, xmm_srcf;
			__m128i xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3, xmm_dst4, xmm_dst5, xmm_dst6, xmm_dst7;
			__m128i xmm_dst8, xmm_dst9, xmm_dsta, xmm_dstb, xmm_dstc, xmm_dstd, xmm_dste, xmm_dstf;

			// Align the destination to a 16-byte boundary.
			xmm_src0 = _mm_loadu_pd(src);
			xmm_src1 = _mm_loadu_pd(src + 2);
			xmm_src2 = _mm_loadu_pd(src + 4);
			xmm_src3 = _mm_loadu_pd(src + 6);
			xmm_src4 = _mm_loadu_pd(src + 8);
			xmm_src5 = _mm_loadu_pd(src + 10);
			xmm_src6 = _mm_loadu_pd(src + 12);
			xmm_src7 = _mm_loadu_pd(src + 14);
			xmm_src0 = _mm_max_pd(xmm_src0, min);
			xmm_src1 = _mm_max_pd(xmm_src1, min);
			xmm_src2 = _mm_max_pd(xmm_src2, min);
			xmm_src3 = _mm_max_pd(xmm_src3, min);
			xmm_src4 = _mm_max_pd(xmm_src4, min);
			xmm_src5 = _mm_max_pd(xmm_src5, min);
			xmm_src6 = _mm_max_pd(xmm_src6, min);
			xmm_src7 = _mm_max_pd(xmm_src7, min);
			xmm_src0 = _mm_min_pd(xmm_src0, max);
			xmm_src1 = _mm_min_pd(xmm_src1, max);
			xmm_src2 = _mm_min_pd(xmm_src2, max);
			xmm_src3 = _mm_min_pd(xmm_src3, max);
			xmm_src4 = _mm_min_pd(xmm_src4, max);
			xmm_src5 = _mm_min_pd(xmm_src5, max);
			xmm_src6 = _mm_min_pd(xmm_src6, max);
			xmm_src7 = _mm_min_pd(xmm_src7, max);
			xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
			xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
			xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
			xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
			xmm_dst4 = _mm_cvttpd_epi32(xmm_src4);
			xmm_dst5 = _mm_cvttpd_epi32(xmm_src5);
			xmm_dst6 = _mm_cvttpd_epi32(xmm_src6);
			xmm_dst7 = _mm_cvttpd_epi32(xmm_src7);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
			xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
			xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
			xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
			xmm_dst0 = _mm_packus_epi32(xmm_dst0, xmm_dst2);
			xmm_dst4 = _mm_packus_epi32(xmm_dst4, xmm_dst6);
			xmm_dst0 = _mm_packus_epi16(xmm_dst0, xmm_dst4);
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
					xmm_src0 = _mm_load_pd(src);
					xmm_src1 = _mm_load_pd(src + 2);
					xmm_src2 = _mm_load_pd(src + 4);
					xmm_src3 = _mm_load_pd(src + 6);
					xmm_src4 = _mm_load_pd(src + 8);
					xmm_src5 = _mm_load_pd(src + 10);
					xmm_src6 = _mm_load_pd(src + 12);
					xmm_src7 = _mm_load_pd(src + 14);
					xmm_src8 = _mm_load_pd(src + 16);
					xmm_src9 = _mm_load_pd(src + 18);
					xmm_srca = _mm_load_pd(src + 20);
					xmm_srcb = _mm_load_pd(src + 22);
					xmm_srcc = _mm_load_pd(src + 24);
					xmm_srcd = _mm_load_pd(src + 26);
					xmm_srce = _mm_load_pd(src + 28);
					xmm_srcf = _mm_load_pd(src + 30);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					xmm_src0 = _mm_max_pd(xmm_src0, min);
					xmm_src1 = _mm_max_pd(xmm_src1, min);
					xmm_src2 = _mm_max_pd(xmm_src2, min);
					xmm_src3 = _mm_max_pd(xmm_src3, min);
					xmm_src4 = _mm_max_pd(xmm_src4, min);
					xmm_src5 = _mm_max_pd(xmm_src5, min);
					xmm_src6 = _mm_max_pd(xmm_src6, min);
					xmm_src7 = _mm_max_pd(xmm_src7, min);
					xmm_src8 = _mm_max_pd(xmm_src8, min);
					xmm_src9 = _mm_max_pd(xmm_src9, min);
					xmm_srca = _mm_max_pd(xmm_srca, min);
					xmm_srcb = _mm_max_pd(xmm_srcb, min);
					xmm_srcc = _mm_max_pd(xmm_srcc, min);
					xmm_srcd = _mm_max_pd(xmm_srcd, min);
					xmm_srce = _mm_max_pd(xmm_srce, min);
					xmm_srcf = _mm_max_pd(xmm_srcf, min);
					xmm_src0 = _mm_min_pd(xmm_src0, max);
					xmm_src1 = _mm_min_pd(xmm_src1, max);
					xmm_src2 = _mm_min_pd(xmm_src2, max);
					xmm_src3 = _mm_min_pd(xmm_src3, max);
					xmm_src4 = _mm_min_pd(xmm_src4, max);
					xmm_src5 = _mm_min_pd(xmm_src5, max);
					xmm_src6 = _mm_min_pd(xmm_src6, max);
					xmm_src7 = _mm_min_pd(xmm_src7, max);
					xmm_src8 = _mm_min_pd(xmm_src8, max);
					xmm_src9 = _mm_min_pd(xmm_src9, max);
					xmm_srca = _mm_min_pd(xmm_srca, max);
					xmm_srcb = _mm_min_pd(xmm_srcb, max);
					xmm_srcc = _mm_min_pd(xmm_srcc, max);
					xmm_srcd = _mm_min_pd(xmm_srcd, max);
					xmm_srce = _mm_min_pd(xmm_srce, max);
					xmm_srcf = _mm_min_pd(xmm_srcf, max);
					xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
					xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
					xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
					xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
					xmm_dst4 = _mm_cvttpd_epi32(xmm_src4);
					xmm_dst5 = _mm_cvttpd_epi32(xmm_src5);
					xmm_dst6 = _mm_cvttpd_epi32(xmm_src6);
					xmm_dst7 = _mm_cvttpd_epi32(xmm_src7);
					xmm_dst8 = _mm_cvttpd_epi32(xmm_src8);
					xmm_dst9 = _mm_cvttpd_epi32(xmm_src9);
					xmm_dsta = _mm_cvttpd_epi32(xmm_srca);
					xmm_dstb = _mm_cvttpd_epi32(xmm_srcb);
					xmm_dstc = _mm_cvttpd_epi32(xmm_srcc);
					xmm_dstd = _mm_cvttpd_epi32(xmm_srcd);
					xmm_dste = _mm_cvttpd_epi32(xmm_srce);
					xmm_dstf = _mm_cvttpd_epi32(xmm_srcf);
					xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
					xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
					xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
					xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
					xmm_dst8 = _mm_unpacklo_epi64(xmm_dst8, xmm_dst9);
					xmm_dsta = _mm_unpacklo_epi64(xmm_dsta, xmm_dstb);
					xmm_dstc = _mm_unpacklo_epi64(xmm_dstc, xmm_dstd);
					xmm_dste = _mm_unpacklo_epi64(xmm_dste, xmm_dstf);
					xmm_dst0 = _mm_packus_epi32(xmm_dst0, xmm_dst2);
					xmm_dst4 = _mm_packus_epi32(xmm_dst4, xmm_dst6);
					xmm_dst8 = _mm_packus_epi32(xmm_dst8, xmm_dsta);
					xmm_dstc = _mm_packus_epi32(xmm_dstc, xmm_dste);
					xmm_dst0 = _mm_packus_epi16(xmm_dst0, xmm_dst4);
					xmm_dst8 = _mm_packus_epi16(xmm_dst8, xmm_dstc);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst8);
					src += 32;
					dst += 32;
				}
			}
			else
			{
				for (; n >= 32; n -= 32)
				{
					xmm_src0 = _mm_loadu_pd(src);
					xmm_src1 = _mm_loadu_pd(src + 2);
					xmm_src2 = _mm_loadu_pd(src + 4);
					xmm_src3 = _mm_loadu_pd(src + 6);
					xmm_src4 = _mm_loadu_pd(src + 8);
					xmm_src5 = _mm_loadu_pd(src + 10);
					xmm_src6 = _mm_loadu_pd(src + 12);
					xmm_src7 = _mm_loadu_pd(src + 14);
					xmm_src8 = _mm_loadu_pd(src + 16);
					xmm_src9 = _mm_loadu_pd(src + 18);
					xmm_srca = _mm_loadu_pd(src + 20);
					xmm_srcb = _mm_loadu_pd(src + 22);
					xmm_srcc = _mm_loadu_pd(src + 24);
					xmm_srcd = _mm_loadu_pd(src + 26);
					xmm_srce = _mm_loadu_pd(src + 28);
					xmm_srcf = _mm_loadu_pd(src + 30);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					xmm_src0 = _mm_max_pd(xmm_src0, min);
					xmm_src1 = _mm_max_pd(xmm_src1, min);
					xmm_src2 = _mm_max_pd(xmm_src2, min);
					xmm_src3 = _mm_max_pd(xmm_src3, min);
					xmm_src4 = _mm_max_pd(xmm_src4, min);
					xmm_src5 = _mm_max_pd(xmm_src5, min);
					xmm_src6 = _mm_max_pd(xmm_src6, min);
					xmm_src7 = _mm_max_pd(xmm_src7, min);
					xmm_src8 = _mm_max_pd(xmm_src8, min);
					xmm_src9 = _mm_max_pd(xmm_src9, min);
					xmm_srca = _mm_max_pd(xmm_srca, min);
					xmm_srcb = _mm_max_pd(xmm_srcb, min);
					xmm_srcc = _mm_max_pd(xmm_srcc, min);
					xmm_srcd = _mm_max_pd(xmm_srcd, min);
					xmm_srce = _mm_max_pd(xmm_srce, min);
					xmm_srcf = _mm_max_pd(xmm_srcf, min);
					xmm_src0 = _mm_min_pd(xmm_src0, max);
					xmm_src1 = _mm_min_pd(xmm_src1, max);
					xmm_src2 = _mm_min_pd(xmm_src2, max);
					xmm_src3 = _mm_min_pd(xmm_src3, max);
					xmm_src4 = _mm_min_pd(xmm_src4, max);
					xmm_src5 = _mm_min_pd(xmm_src5, max);
					xmm_src6 = _mm_min_pd(xmm_src6, max);
					xmm_src7 = _mm_min_pd(xmm_src7, max);
					xmm_src8 = _mm_min_pd(xmm_src8, max);
					xmm_src9 = _mm_min_pd(xmm_src9, max);
					xmm_srca = _mm_min_pd(xmm_srca, max);
					xmm_srcb = _mm_min_pd(xmm_srcb, max);
					xmm_srcc = _mm_min_pd(xmm_srcc, max);
					xmm_srcd = _mm_min_pd(xmm_srcd, max);
					xmm_srce = _mm_min_pd(xmm_srce, max);
					xmm_srcf = _mm_min_pd(xmm_srcf, max);
					xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
					xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
					xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
					xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
					xmm_dst4 = _mm_cvttpd_epi32(xmm_src4);
					xmm_dst5 = _mm_cvttpd_epi32(xmm_src5);
					xmm_dst6 = _mm_cvttpd_epi32(xmm_src6);
					xmm_dst7 = _mm_cvttpd_epi32(xmm_src7);
					xmm_dst8 = _mm_cvttpd_epi32(xmm_src8);
					xmm_dst9 = _mm_cvttpd_epi32(xmm_src9);
					xmm_dsta = _mm_cvttpd_epi32(xmm_srca);
					xmm_dstb = _mm_cvttpd_epi32(xmm_srcb);
					xmm_dstc = _mm_cvttpd_epi32(xmm_srcc);
					xmm_dstd = _mm_cvttpd_epi32(xmm_srcd);
					xmm_dste = _mm_cvttpd_epi32(xmm_srce);
					xmm_dstf = _mm_cvttpd_epi32(xmm_srcf);
					xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
					xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
					xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
					xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
					xmm_dst8 = _mm_unpacklo_epi64(xmm_dst8, xmm_dst9);
					xmm_dsta = _mm_unpacklo_epi64(xmm_dsta, xmm_dstb);
					xmm_dstc = _mm_unpacklo_epi64(xmm_dstc, xmm_dstd);
					xmm_dste = _mm_unpacklo_epi64(xmm_dste, xmm_dstf);
					xmm_dst0 = _mm_packus_epi32(xmm_dst0, xmm_dst2);
					xmm_dst4 = _mm_packus_epi32(xmm_dst4, xmm_dst6);
					xmm_dst8 = _mm_packus_epi32(xmm_dst8, xmm_dsta);
					xmm_dstc = _mm_packus_epi32(xmm_dstc, xmm_dste);
					xmm_dst0 = _mm_packus_epi16(xmm_dst0, xmm_dst4);
					xmm_dst8 = _mm_packus_epi16(xmm_dst8, xmm_dstc);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst8);
					src += 32;
					dst += 32;
				}
			}
		}

		template <>
		void cvtspd_sse41_large<signed short>(signed short* dst, const double* src, size_t n)
		{
			const size_t padding = 8 - (reinterpret_cast<size_t>(dst) & 7);
			const __m128d min = _mm_set1_pd(static_cast<double>(INT16_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT16_MAX));
			__m128d xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128d xmm_src8, xmm_src9, xmm_srca, xmm_srcb, xmm_srcc, xmm_srcd, xmm_srce, xmm_srcf;
			__m128i xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3, xmm_dst4, xmm_dst5, xmm_dst6, xmm_dst7;
			__m128i xmm_dst8, xmm_dst9, xmm_dsta, xmm_dstb, xmm_dstc, xmm_dstd, xmm_dste, xmm_dstf;

			// Align the destination to a 16-byte boundary.
			xmm_src0 = _mm_loadu_pd(src);
			xmm_src1 = _mm_loadu_pd(src + 2);
			xmm_src2 = _mm_loadu_pd(src + 4);
			xmm_src3 = _mm_loadu_pd(src + 6);
			xmm_src0 = _mm_max_pd(xmm_src0, min);
			xmm_src1 = _mm_max_pd(xmm_src1, min);
			xmm_src2 = _mm_max_pd(xmm_src2, min);
			xmm_src3 = _mm_max_pd(xmm_src3, min);
			xmm_src0 = _mm_min_pd(xmm_src0, max);
			xmm_src1 = _mm_min_pd(xmm_src1, max);
			xmm_src2 = _mm_min_pd(xmm_src2, max);
			xmm_src3 = _mm_min_pd(xmm_src3, max);
			xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
			xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
			xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
			xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
			xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
			xmm_dst0 = _mm_packs_epi32(xmm_dst0, xmm_dst2);
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
					xmm_src0 = _mm_load_pd(src);
					xmm_src1 = _mm_load_pd(src + 2);
					xmm_src2 = _mm_load_pd(src + 4);
					xmm_src3 = _mm_load_pd(src + 6);
					xmm_src4 = _mm_load_pd(src + 8);
					xmm_src5 = _mm_load_pd(src + 10);
					xmm_src6 = _mm_load_pd(src + 12);
					xmm_src7 = _mm_load_pd(src + 14);
					xmm_src8 = _mm_load_pd(src + 16);
					xmm_src9 = _mm_load_pd(src + 18);
					xmm_srca = _mm_load_pd(src + 20);
					xmm_srcb = _mm_load_pd(src + 22);
					xmm_srcc = _mm_load_pd(src + 24);
					xmm_srcd = _mm_load_pd(src + 26);
					xmm_srce = _mm_load_pd(src + 28);
					xmm_srcf = _mm_load_pd(src + 30);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					xmm_src0 = _mm_max_pd(xmm_src0, min);
					xmm_src1 = _mm_max_pd(xmm_src1, min);
					xmm_src2 = _mm_max_pd(xmm_src2, min);
					xmm_src3 = _mm_max_pd(xmm_src3, min);
					xmm_src4 = _mm_max_pd(xmm_src4, min);
					xmm_src5 = _mm_max_pd(xmm_src5, min);
					xmm_src6 = _mm_max_pd(xmm_src6, min);
					xmm_src7 = _mm_max_pd(xmm_src7, min);
					xmm_src8 = _mm_max_pd(xmm_src8, min);
					xmm_src9 = _mm_max_pd(xmm_src9, min);
					xmm_srca = _mm_max_pd(xmm_srca, min);
					xmm_srcb = _mm_max_pd(xmm_srcb, min);
					xmm_srcc = _mm_max_pd(xmm_srcc, min);
					xmm_srcd = _mm_max_pd(xmm_srcd, min);
					xmm_srce = _mm_max_pd(xmm_srce, min);
					xmm_srcf = _mm_max_pd(xmm_srcf, min);
					xmm_src0 = _mm_min_pd(xmm_src0, max);
					xmm_src1 = _mm_min_pd(xmm_src1, max);
					xmm_src2 = _mm_min_pd(xmm_src2, max);
					xmm_src3 = _mm_min_pd(xmm_src3, max);
					xmm_src4 = _mm_min_pd(xmm_src4, max);
					xmm_src5 = _mm_min_pd(xmm_src5, max);
					xmm_src6 = _mm_min_pd(xmm_src6, max);
					xmm_src7 = _mm_min_pd(xmm_src7, max);
					xmm_src8 = _mm_min_pd(xmm_src8, max);
					xmm_src9 = _mm_min_pd(xmm_src9, max);
					xmm_srca = _mm_min_pd(xmm_srca, max);
					xmm_srcb = _mm_min_pd(xmm_srcb, max);
					xmm_srcc = _mm_min_pd(xmm_srcc, max);
					xmm_srcd = _mm_min_pd(xmm_srcd, max);
					xmm_srce = _mm_min_pd(xmm_srce, max);
					xmm_srcf = _mm_min_pd(xmm_srcf, max);
					xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
					xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
					xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
					xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
					xmm_dst4 = _mm_cvttpd_epi32(xmm_src4);
					xmm_dst5 = _mm_cvttpd_epi32(xmm_src5);
					xmm_dst6 = _mm_cvttpd_epi32(xmm_src6);
					xmm_dst7 = _mm_cvttpd_epi32(xmm_src7);
					xmm_dst8 = _mm_cvttpd_epi32(xmm_src8);
					xmm_dst9 = _mm_cvttpd_epi32(xmm_src9);
					xmm_dsta = _mm_cvttpd_epi32(xmm_srca);
					xmm_dstb = _mm_cvttpd_epi32(xmm_srcb);
					xmm_dstc = _mm_cvttpd_epi32(xmm_srcc);
					xmm_dstd = _mm_cvttpd_epi32(xmm_srcd);
					xmm_dste = _mm_cvttpd_epi32(xmm_srce);
					xmm_dstf = _mm_cvttpd_epi32(xmm_srcf);
					xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
					xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
					xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
					xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
					xmm_dst8 = _mm_unpacklo_epi64(xmm_dst8, xmm_dst9);
					xmm_dsta = _mm_unpacklo_epi64(xmm_dsta, xmm_dstb);
					xmm_dstc = _mm_unpacklo_epi64(xmm_dstc, xmm_dstd);
					xmm_dste = _mm_unpacklo_epi64(xmm_dste, xmm_dstf);
					xmm_dst0 = _mm_packs_epi32(xmm_dst0, xmm_dst2);
					xmm_dst4 = _mm_packs_epi32(xmm_dst4, xmm_dst6);
					xmm_dst8 = _mm_packs_epi32(xmm_dst8, xmm_dsta);
					xmm_dstc = _mm_packs_epi32(xmm_dstc, xmm_dste);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst4);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 2, xmm_dst8);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 3, xmm_dstc);
					src += 32;
					dst += 32;
				}
			}
			else
			{
				for (; n >= 32; n -= 32)
				{
					xmm_src0 = _mm_loadu_pd(src);
					xmm_src1 = _mm_loadu_pd(src + 2);
					xmm_src2 = _mm_loadu_pd(src + 4);
					xmm_src3 = _mm_loadu_pd(src + 6);
					xmm_src4 = _mm_loadu_pd(src + 8);
					xmm_src5 = _mm_loadu_pd(src + 10);
					xmm_src6 = _mm_loadu_pd(src + 12);
					xmm_src7 = _mm_loadu_pd(src + 14);
					xmm_src8 = _mm_loadu_pd(src + 16);
					xmm_src9 = _mm_loadu_pd(src + 18);
					xmm_srca = _mm_loadu_pd(src + 20);
					xmm_srcb = _mm_loadu_pd(src + 22);
					xmm_srcc = _mm_loadu_pd(src + 24);
					xmm_srcd = _mm_loadu_pd(src + 26);
					xmm_srce = _mm_loadu_pd(src + 28);
					xmm_srcf = _mm_loadu_pd(src + 30);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					xmm_src0 = _mm_max_pd(xmm_src0, min);
					xmm_src1 = _mm_max_pd(xmm_src1, min);
					xmm_src2 = _mm_max_pd(xmm_src2, min);
					xmm_src3 = _mm_max_pd(xmm_src3, min);
					xmm_src4 = _mm_max_pd(xmm_src4, min);
					xmm_src5 = _mm_max_pd(xmm_src5, min);
					xmm_src6 = _mm_max_pd(xmm_src6, min);
					xmm_src7 = _mm_max_pd(xmm_src7, min);
					xmm_src8 = _mm_max_pd(xmm_src8, min);
					xmm_src9 = _mm_max_pd(xmm_src9, min);
					xmm_srca = _mm_max_pd(xmm_srca, min);
					xmm_srcb = _mm_max_pd(xmm_srcb, min);
					xmm_srcc = _mm_max_pd(xmm_srcc, min);
					xmm_srcd = _mm_max_pd(xmm_srcd, min);
					xmm_srce = _mm_max_pd(xmm_srce, min);
					xmm_srcf = _mm_max_pd(xmm_srcf, min);
					xmm_src0 = _mm_min_pd(xmm_src0, max);
					xmm_src1 = _mm_min_pd(xmm_src1, max);
					xmm_src2 = _mm_min_pd(xmm_src2, max);
					xmm_src3 = _mm_min_pd(xmm_src3, max);
					xmm_src4 = _mm_min_pd(xmm_src4, max);
					xmm_src5 = _mm_min_pd(xmm_src5, max);
					xmm_src6 = _mm_min_pd(xmm_src6, max);
					xmm_src7 = _mm_min_pd(xmm_src7, max);
					xmm_src8 = _mm_min_pd(xmm_src8, max);
					xmm_src9 = _mm_min_pd(xmm_src9, max);
					xmm_srca = _mm_min_pd(xmm_srca, max);
					xmm_srcb = _mm_min_pd(xmm_srcb, max);
					xmm_srcc = _mm_min_pd(xmm_srcc, max);
					xmm_srcd = _mm_min_pd(xmm_srcd, max);
					xmm_srce = _mm_min_pd(xmm_srce, max);
					xmm_srcf = _mm_min_pd(xmm_srcf, max);
					xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
					xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
					xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
					xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
					xmm_dst4 = _mm_cvttpd_epi32(xmm_src4);
					xmm_dst5 = _mm_cvttpd_epi32(xmm_src5);
					xmm_dst6 = _mm_cvttpd_epi32(xmm_src6);
					xmm_dst7 = _mm_cvttpd_epi32(xmm_src7);
					xmm_dst8 = _mm_cvttpd_epi32(xmm_src8);
					xmm_dst9 = _mm_cvttpd_epi32(xmm_src9);
					xmm_dsta = _mm_cvttpd_epi32(xmm_srca);
					xmm_dstb = _mm_cvttpd_epi32(xmm_srcb);
					xmm_dstc = _mm_cvttpd_epi32(xmm_srcc);
					xmm_dstd = _mm_cvttpd_epi32(xmm_srcd);
					xmm_dste = _mm_cvttpd_epi32(xmm_srce);
					xmm_dstf = _mm_cvttpd_epi32(xmm_srcf);
					xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
					xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
					xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
					xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
					xmm_dst8 = _mm_unpacklo_epi64(xmm_dst8, xmm_dst9);
					xmm_dsta = _mm_unpacklo_epi64(xmm_dsta, xmm_dstb);
					xmm_dstc = _mm_unpacklo_epi64(xmm_dstc, xmm_dstd);
					xmm_dste = _mm_unpacklo_epi64(xmm_dste, xmm_dstf);
					xmm_dst0 = _mm_packs_epi32(xmm_dst0, xmm_dst2);
					xmm_dst4 = _mm_packs_epi32(xmm_dst4, xmm_dst6);
					xmm_dst8 = _mm_packs_epi32(xmm_dst8, xmm_dsta);
					xmm_dstc = _mm_packs_epi32(xmm_dstc, xmm_dste);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst4);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 2, xmm_dst8);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 3, xmm_dstc);
					src += 32;
					dst += 32;
				}
			}
		}

		template <>
		void cvtspd_sse41_large<unsigned short>(unsigned short* dst, const double* src, size_t n)
		{
			const size_t padding = 8 - (reinterpret_cast<size_t>(dst) & 7);
			const __m128d min = _mm_setzero_pd();
			const __m128d max = _mm_set1_pd(static_cast<double>(UINT16_MAX));
			__m128d xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128d xmm_src8, xmm_src9, xmm_srca, xmm_srcb, xmm_srcc, xmm_srcd, xmm_srce, xmm_srcf;
			__m128i xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3, xmm_dst4, xmm_dst5, xmm_dst6, xmm_dst7;
			__m128i xmm_dst8, xmm_dst9, xmm_dsta, xmm_dstb, xmm_dstc, xmm_dstd, xmm_dste, xmm_dstf;

			// Align the destination to a 16-byte boundary.
			xmm_src0 = _mm_loadu_pd(src);
			xmm_src1 = _mm_loadu_pd(src + 2);
			xmm_src2 = _mm_loadu_pd(src + 4);
			xmm_src3 = _mm_loadu_pd(src + 6);
			xmm_src0 = _mm_max_pd(xmm_src0, min);
			xmm_src1 = _mm_max_pd(xmm_src1, min);
			xmm_src2 = _mm_max_pd(xmm_src2, min);
			xmm_src3 = _mm_max_pd(xmm_src3, min);
			xmm_src0 = _mm_min_pd(xmm_src0, max);
			xmm_src1 = _mm_min_pd(xmm_src1, max);
			xmm_src2 = _mm_min_pd(xmm_src2, max);
			xmm_src3 = _mm_min_pd(xmm_src3, max);
			xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
			xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
			xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
			xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
			xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
			xmm_dst0 = _mm_packus_epi32(xmm_dst0, xmm_dst2);
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
					xmm_src0 = _mm_load_pd(src);
					xmm_src1 = _mm_load_pd(src + 2);
					xmm_src2 = _mm_load_pd(src + 4);
					xmm_src3 = _mm_load_pd(src + 6);
					xmm_src4 = _mm_load_pd(src + 8);
					xmm_src5 = _mm_load_pd(src + 10);
					xmm_src6 = _mm_load_pd(src + 12);
					xmm_src7 = _mm_load_pd(src + 14);
					xmm_src8 = _mm_load_pd(src + 16);
					xmm_src9 = _mm_load_pd(src + 18);
					xmm_srca = _mm_load_pd(src + 20);
					xmm_srcb = _mm_load_pd(src + 22);
					xmm_srcc = _mm_load_pd(src + 24);
					xmm_srcd = _mm_load_pd(src + 26);
					xmm_srce = _mm_load_pd(src + 28);
					xmm_srcf = _mm_load_pd(src + 30);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					xmm_src0 = _mm_max_pd(xmm_src0, min);
					xmm_src1 = _mm_max_pd(xmm_src1, min);
					xmm_src2 = _mm_max_pd(xmm_src2, min);
					xmm_src3 = _mm_max_pd(xmm_src3, min);
					xmm_src4 = _mm_max_pd(xmm_src4, min);
					xmm_src5 = _mm_max_pd(xmm_src5, min);
					xmm_src6 = _mm_max_pd(xmm_src6, min);
					xmm_src7 = _mm_max_pd(xmm_src7, min);
					xmm_src8 = _mm_max_pd(xmm_src8, min);
					xmm_src9 = _mm_max_pd(xmm_src9, min);
					xmm_srca = _mm_max_pd(xmm_srca, min);
					xmm_srcb = _mm_max_pd(xmm_srcb, min);
					xmm_srcc = _mm_max_pd(xmm_srcc, min);
					xmm_srcd = _mm_max_pd(xmm_srcd, min);
					xmm_srce = _mm_max_pd(xmm_srce, min);
					xmm_srcf = _mm_max_pd(xmm_srcf, min);
					xmm_src0 = _mm_min_pd(xmm_src0, max);
					xmm_src1 = _mm_min_pd(xmm_src1, max);
					xmm_src2 = _mm_min_pd(xmm_src2, max);
					xmm_src3 = _mm_min_pd(xmm_src3, max);
					xmm_src4 = _mm_min_pd(xmm_src4, max);
					xmm_src5 = _mm_min_pd(xmm_src5, max);
					xmm_src6 = _mm_min_pd(xmm_src6, max);
					xmm_src7 = _mm_min_pd(xmm_src7, max);
					xmm_src8 = _mm_min_pd(xmm_src8, max);
					xmm_src9 = _mm_min_pd(xmm_src9, max);
					xmm_srca = _mm_min_pd(xmm_srca, max);
					xmm_srcb = _mm_min_pd(xmm_srcb, max);
					xmm_srcc = _mm_min_pd(xmm_srcc, max);
					xmm_srcd = _mm_min_pd(xmm_srcd, max);
					xmm_srce = _mm_min_pd(xmm_srce, max);
					xmm_srcf = _mm_min_pd(xmm_srcf, max);
					xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
					xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
					xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
					xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
					xmm_dst4 = _mm_cvttpd_epi32(xmm_src4);
					xmm_dst5 = _mm_cvttpd_epi32(xmm_src5);
					xmm_dst6 = _mm_cvttpd_epi32(xmm_src6);
					xmm_dst7 = _mm_cvttpd_epi32(xmm_src7);
					xmm_dst8 = _mm_cvttpd_epi32(xmm_src8);
					xmm_dst9 = _mm_cvttpd_epi32(xmm_src9);
					xmm_dsta = _mm_cvttpd_epi32(xmm_srca);
					xmm_dstb = _mm_cvttpd_epi32(xmm_srcb);
					xmm_dstc = _mm_cvttpd_epi32(xmm_srcc);
					xmm_dstd = _mm_cvttpd_epi32(xmm_srcd);
					xmm_dste = _mm_cvttpd_epi32(xmm_srce);
					xmm_dstf = _mm_cvttpd_epi32(xmm_srcf);
					xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
					xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
					xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
					xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
					xmm_dst8 = _mm_unpacklo_epi64(xmm_dst8, xmm_dst9);
					xmm_dsta = _mm_unpacklo_epi64(xmm_dsta, xmm_dstb);
					xmm_dstc = _mm_unpacklo_epi64(xmm_dstc, xmm_dstd);
					xmm_dste = _mm_unpacklo_epi64(xmm_dste, xmm_dstf);
					xmm_dst0 = _mm_packus_epi32(xmm_dst0, xmm_dst2);
					xmm_dst4 = _mm_packus_epi32(xmm_dst4, xmm_dst6);
					xmm_dst8 = _mm_packus_epi32(xmm_dst8, xmm_dsta);
					xmm_dstc = _mm_packus_epi32(xmm_dstc, xmm_dste);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst4);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 2, xmm_dst8);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 3, xmm_dstc);
					src += 32;
					dst += 32;
				}
			}
			else
			{
				for (; n >= 32; n -= 32)
				{
					xmm_src0 = _mm_loadu_pd(src);
					xmm_src1 = _mm_loadu_pd(src + 2);
					xmm_src2 = _mm_loadu_pd(src + 4);
					xmm_src3 = _mm_loadu_pd(src + 6);
					xmm_src4 = _mm_loadu_pd(src + 8);
					xmm_src5 = _mm_loadu_pd(src + 10);
					xmm_src6 = _mm_loadu_pd(src + 12);
					xmm_src7 = _mm_loadu_pd(src + 14);
					xmm_src8 = _mm_loadu_pd(src + 16);
					xmm_src9 = _mm_loadu_pd(src + 18);
					xmm_srca = _mm_loadu_pd(src + 20);
					xmm_srcb = _mm_loadu_pd(src + 22);
					xmm_srcc = _mm_loadu_pd(src + 24);
					xmm_srcd = _mm_loadu_pd(src + 26);
					xmm_srce = _mm_loadu_pd(src + 28);
					xmm_srcf = _mm_loadu_pd(src + 30);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					xmm_src0 = _mm_max_pd(xmm_src0, min);
					xmm_src1 = _mm_max_pd(xmm_src1, min);
					xmm_src2 = _mm_max_pd(xmm_src2, min);
					xmm_src3 = _mm_max_pd(xmm_src3, min);
					xmm_src4 = _mm_max_pd(xmm_src4, min);
					xmm_src5 = _mm_max_pd(xmm_src5, min);
					xmm_src6 = _mm_max_pd(xmm_src6, min);
					xmm_src7 = _mm_max_pd(xmm_src7, min);
					xmm_src8 = _mm_max_pd(xmm_src8, min);
					xmm_src9 = _mm_max_pd(xmm_src9, min);
					xmm_srca = _mm_max_pd(xmm_srca, min);
					xmm_srcb = _mm_max_pd(xmm_srcb, min);
					xmm_srcc = _mm_max_pd(xmm_srcc, min);
					xmm_srcd = _mm_max_pd(xmm_srcd, min);
					xmm_srce = _mm_max_pd(xmm_srce, min);
					xmm_srcf = _mm_max_pd(xmm_srcf, min);
					xmm_src0 = _mm_min_pd(xmm_src0, max);
					xmm_src1 = _mm_min_pd(xmm_src1, max);
					xmm_src2 = _mm_min_pd(xmm_src2, max);
					xmm_src3 = _mm_min_pd(xmm_src3, max);
					xmm_src4 = _mm_min_pd(xmm_src4, max);
					xmm_src5 = _mm_min_pd(xmm_src5, max);
					xmm_src6 = _mm_min_pd(xmm_src6, max);
					xmm_src7 = _mm_min_pd(xmm_src7, max);
					xmm_src8 = _mm_min_pd(xmm_src8, max);
					xmm_src9 = _mm_min_pd(xmm_src9, max);
					xmm_srca = _mm_min_pd(xmm_srca, max);
					xmm_srcb = _mm_min_pd(xmm_srcb, max);
					xmm_srcc = _mm_min_pd(xmm_srcc, max);
					xmm_srcd = _mm_min_pd(xmm_srcd, max);
					xmm_srce = _mm_min_pd(xmm_srce, max);
					xmm_srcf = _mm_min_pd(xmm_srcf, max);
					xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
					xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
					xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
					xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
					xmm_dst4 = _mm_cvttpd_epi32(xmm_src4);
					xmm_dst5 = _mm_cvttpd_epi32(xmm_src5);
					xmm_dst6 = _mm_cvttpd_epi32(xmm_src6);
					xmm_dst7 = _mm_cvttpd_epi32(xmm_src7);
					xmm_dst8 = _mm_cvttpd_epi32(xmm_src8);
					xmm_dst9 = _mm_cvttpd_epi32(xmm_src9);
					xmm_dsta = _mm_cvttpd_epi32(xmm_srca);
					xmm_dstb = _mm_cvttpd_epi32(xmm_srcb);
					xmm_dstc = _mm_cvttpd_epi32(xmm_srcc);
					xmm_dstd = _mm_cvttpd_epi32(xmm_srcd);
					xmm_dste = _mm_cvttpd_epi32(xmm_srce);
					xmm_dstf = _mm_cvttpd_epi32(xmm_srcf);
					xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
					xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
					xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
					xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
					xmm_dst8 = _mm_unpacklo_epi64(xmm_dst8, xmm_dst9);
					xmm_dsta = _mm_unpacklo_epi64(xmm_dsta, xmm_dstb);
					xmm_dstc = _mm_unpacklo_epi64(xmm_dstc, xmm_dstd);
					xmm_dste = _mm_unpacklo_epi64(xmm_dste, xmm_dstf);
					xmm_dst0 = _mm_packus_epi32(xmm_dst0, xmm_dst2);
					xmm_dst4 = _mm_packus_epi32(xmm_dst4, xmm_dst6);
					xmm_dst8 = _mm_packus_epi32(xmm_dst8, xmm_dsta);
					xmm_dstc = _mm_packus_epi32(xmm_dstc, xmm_dste);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst4);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 2, xmm_dst8);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 3, xmm_dstc);
					src += 32;
					dst += 32;
				}
			}
		}

		template <>
		void cvtspd_sse41_large<signed int>(signed int* dst, const double* src, size_t n)
		{
			const size_t padding = 4 - (reinterpret_cast<size_t>(dst) & 3);
			const __m128d min = _mm_set1_pd(static_cast<double>(INT32_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT32_MAX));
			__m128d xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128d xmm_src8, xmm_src9, xmm_srca, xmm_srcb, xmm_srcc, xmm_srcd, xmm_srce, xmm_srcf;
			__m128i xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3, xmm_dst4, xmm_dst5, xmm_dst6, xmm_dst7;
			__m128i xmm_dst8, xmm_dst9, xmm_dsta, xmm_dstb, xmm_dstc, xmm_dstd, xmm_dste, xmm_dstf;

			// Align the destination to a 16-byte boundary.
			xmm_src0 = _mm_loadu_pd(src);
			xmm_src1 = _mm_loadu_pd(src + 2);
			xmm_src0 = _mm_max_pd(xmm_src0, min);
			xmm_src1 = _mm_max_pd(xmm_src1, min);
			xmm_src0 = _mm_min_pd(xmm_src0, max);
			xmm_src1 = _mm_min_pd(xmm_src1, max);
			xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
			xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
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
					xmm_src0 = _mm_load_pd(src);
					xmm_src1 = _mm_load_pd(src + 2);
					xmm_src2 = _mm_load_pd(src + 4);
					xmm_src3 = _mm_load_pd(src + 6);
					xmm_src4 = _mm_load_pd(src + 8);
					xmm_src5 = _mm_load_pd(src + 10);
					xmm_src6 = _mm_load_pd(src + 12);
					xmm_src7 = _mm_load_pd(src + 14);
					xmm_src8 = _mm_load_pd(src + 16);
					xmm_src9 = _mm_load_pd(src + 18);
					xmm_srca = _mm_load_pd(src + 20);
					xmm_srcb = _mm_load_pd(src + 22);
					xmm_srcc = _mm_load_pd(src + 24);
					xmm_srcd = _mm_load_pd(src + 26);
					xmm_srce = _mm_load_pd(src + 28);
					xmm_srcf = _mm_load_pd(src + 30);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					xmm_src0 = _mm_max_pd(xmm_src0, min);
					xmm_src1 = _mm_max_pd(xmm_src1, min);
					xmm_src2 = _mm_max_pd(xmm_src2, min);
					xmm_src3 = _mm_max_pd(xmm_src3, min);
					xmm_src4 = _mm_max_pd(xmm_src4, min);
					xmm_src5 = _mm_max_pd(xmm_src5, min);
					xmm_src6 = _mm_max_pd(xmm_src6, min);
					xmm_src7 = _mm_max_pd(xmm_src7, min);
					xmm_src8 = _mm_max_pd(xmm_src8, min);
					xmm_src9 = _mm_max_pd(xmm_src9, min);
					xmm_srca = _mm_max_pd(xmm_srca, min);
					xmm_srcb = _mm_max_pd(xmm_srcb, min);
					xmm_srcc = _mm_max_pd(xmm_srcc, min);
					xmm_srcd = _mm_max_pd(xmm_srcd, min);
					xmm_srce = _mm_max_pd(xmm_srce, min);
					xmm_srcf = _mm_max_pd(xmm_srcf, min);
					xmm_src0 = _mm_min_pd(xmm_src0, max);
					xmm_src1 = _mm_min_pd(xmm_src1, max);
					xmm_src2 = _mm_min_pd(xmm_src2, max);
					xmm_src3 = _mm_min_pd(xmm_src3, max);
					xmm_src4 = _mm_min_pd(xmm_src4, max);
					xmm_src5 = _mm_min_pd(xmm_src5, max);
					xmm_src6 = _mm_min_pd(xmm_src6, max);
					xmm_src7 = _mm_min_pd(xmm_src7, max);
					xmm_src8 = _mm_min_pd(xmm_src8, max);
					xmm_src9 = _mm_min_pd(xmm_src9, max);
					xmm_srca = _mm_min_pd(xmm_srca, max);
					xmm_srcb = _mm_min_pd(xmm_srcb, max);
					xmm_srcc = _mm_min_pd(xmm_srcc, max);
					xmm_srcd = _mm_min_pd(xmm_srcd, max);
					xmm_srce = _mm_min_pd(xmm_srce, max);
					xmm_srcf = _mm_min_pd(xmm_srcf, max);
					xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
					xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
					xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
					xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
					xmm_dst4 = _mm_cvttpd_epi32(xmm_src4);
					xmm_dst5 = _mm_cvttpd_epi32(xmm_src5);
					xmm_dst6 = _mm_cvttpd_epi32(xmm_src6);
					xmm_dst7 = _mm_cvttpd_epi32(xmm_src7);
					xmm_dst8 = _mm_cvttpd_epi32(xmm_src8);
					xmm_dst9 = _mm_cvttpd_epi32(xmm_src9);
					xmm_dsta = _mm_cvttpd_epi32(xmm_srca);
					xmm_dstb = _mm_cvttpd_epi32(xmm_srcb);
					xmm_dstc = _mm_cvttpd_epi32(xmm_srcc);
					xmm_dstd = _mm_cvttpd_epi32(xmm_srcd);
					xmm_dste = _mm_cvttpd_epi32(xmm_srce);
					xmm_dstf = _mm_cvttpd_epi32(xmm_srcf);
					xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
					xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
					xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
					xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
					xmm_dst8 = _mm_unpacklo_epi64(xmm_dst8, xmm_dst9);
					xmm_dsta = _mm_unpacklo_epi64(xmm_dsta, xmm_dstb);
					xmm_dstc = _mm_unpacklo_epi64(xmm_dstc, xmm_dstd);
					xmm_dste = _mm_unpacklo_epi64(xmm_dste, xmm_dstf);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst2);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 2, xmm_dst4);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 3, xmm_dst6);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 4, xmm_dst8);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 5, xmm_dsta);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 6, xmm_dstc);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 7, xmm_dste);
					src += 32;
					dst += 32;
				}
			}
			else
			{
				for (; n >= 32; n -= 32)
				{
					xmm_src0 = _mm_loadu_pd(src);
					xmm_src1 = _mm_loadu_pd(src + 2);
					xmm_src2 = _mm_loadu_pd(src + 4);
					xmm_src3 = _mm_loadu_pd(src + 6);
					xmm_src4 = _mm_loadu_pd(src + 8);
					xmm_src5 = _mm_loadu_pd(src + 10);
					xmm_src6 = _mm_loadu_pd(src + 12);
					xmm_src7 = _mm_loadu_pd(src + 14);
					xmm_src8 = _mm_loadu_pd(src + 16);
					xmm_src9 = _mm_loadu_pd(src + 18);
					xmm_srca = _mm_loadu_pd(src + 20);
					xmm_srcb = _mm_loadu_pd(src + 22);
					xmm_srcc = _mm_loadu_pd(src + 24);
					xmm_srcd = _mm_loadu_pd(src + 26);
					xmm_srce = _mm_loadu_pd(src + 28);
					xmm_srcf = _mm_loadu_pd(src + 30);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					xmm_src0 = _mm_max_pd(xmm_src0, min);
					xmm_src1 = _mm_max_pd(xmm_src1, min);
					xmm_src2 = _mm_max_pd(xmm_src2, min);
					xmm_src3 = _mm_max_pd(xmm_src3, min);
					xmm_src4 = _mm_max_pd(xmm_src4, min);
					xmm_src5 = _mm_max_pd(xmm_src5, min);
					xmm_src6 = _mm_max_pd(xmm_src6, min);
					xmm_src7 = _mm_max_pd(xmm_src7, min);
					xmm_src8 = _mm_max_pd(xmm_src8, min);
					xmm_src9 = _mm_max_pd(xmm_src9, min);
					xmm_srca = _mm_max_pd(xmm_srca, min);
					xmm_srcb = _mm_max_pd(xmm_srcb, min);
					xmm_srcc = _mm_max_pd(xmm_srcc, min);
					xmm_srcd = _mm_max_pd(xmm_srcd, min);
					xmm_srce = _mm_max_pd(xmm_srce, min);
					xmm_srcf = _mm_max_pd(xmm_srcf, min);
					xmm_src0 = _mm_min_pd(xmm_src0, max);
					xmm_src1 = _mm_min_pd(xmm_src1, max);
					xmm_src2 = _mm_min_pd(xmm_src2, max);
					xmm_src3 = _mm_min_pd(xmm_src3, max);
					xmm_src4 = _mm_min_pd(xmm_src4, max);
					xmm_src5 = _mm_min_pd(xmm_src5, max);
					xmm_src6 = _mm_min_pd(xmm_src6, max);
					xmm_src7 = _mm_min_pd(xmm_src7, max);
					xmm_src8 = _mm_min_pd(xmm_src8, max);
					xmm_src9 = _mm_min_pd(xmm_src9, max);
					xmm_srca = _mm_min_pd(xmm_srca, max);
					xmm_srcb = _mm_min_pd(xmm_srcb, max);
					xmm_srcc = _mm_min_pd(xmm_srcc, max);
					xmm_srcd = _mm_min_pd(xmm_srcd, max);
					xmm_srce = _mm_min_pd(xmm_srce, max);
					xmm_srcf = _mm_min_pd(xmm_srcf, max);
					xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
					xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
					xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
					xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
					xmm_dst4 = _mm_cvttpd_epi32(xmm_src4);
					xmm_dst5 = _mm_cvttpd_epi32(xmm_src5);
					xmm_dst6 = _mm_cvttpd_epi32(xmm_src6);
					xmm_dst7 = _mm_cvttpd_epi32(xmm_src7);
					xmm_dst8 = _mm_cvttpd_epi32(xmm_src8);
					xmm_dst9 = _mm_cvttpd_epi32(xmm_src9);
					xmm_dsta = _mm_cvttpd_epi32(xmm_srca);
					xmm_dstb = _mm_cvttpd_epi32(xmm_srcb);
					xmm_dstc = _mm_cvttpd_epi32(xmm_srcc);
					xmm_dstd = _mm_cvttpd_epi32(xmm_srcd);
					xmm_dste = _mm_cvttpd_epi32(xmm_srce);
					xmm_dstf = _mm_cvttpd_epi32(xmm_srcf);
					xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
					xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
					xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
					xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
					xmm_dst8 = _mm_unpacklo_epi64(xmm_dst8, xmm_dst9);
					xmm_dsta = _mm_unpacklo_epi64(xmm_dsta, xmm_dstb);
					xmm_dstc = _mm_unpacklo_epi64(xmm_dstc, xmm_dstd);
					xmm_dste = _mm_unpacklo_epi64(xmm_dste, xmm_dstf);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst2);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 2, xmm_dst4);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 3, xmm_dst6);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 4, xmm_dst8);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 5, xmm_dsta);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 6, xmm_dstc);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 7, xmm_dste);
					src += 32;
					dst += 32;
				}
			}
		}

		template <>
		void cvtspd_sse41_large<unsigned int>(unsigned int* dst, const double* src, size_t n)
		{
			const size_t padding = 4 - (reinterpret_cast<size_t>(dst) & 3);
			const __m128d min = _mm_set1_pd(static_cast<double>(INT32_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT32_MAX));
			const __m128d offset = _mm_set1_pd(2.147483648e+9);
			const __m128i shift = _mm_set1_epi32(2147483648);
			__m128d xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128d xmm_src8, xmm_src9, xmm_srca, xmm_srcb, xmm_srcc, xmm_srcd, xmm_srce, xmm_srcf;
			__m128i xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3, xmm_dst4, xmm_dst5, xmm_dst6, xmm_dst7;
			__m128i xmm_dst8, xmm_dst9, xmm_dsta, xmm_dstb, xmm_dstc, xmm_dstd, xmm_dste, xmm_dstf;

			// Align the destination to a 16-byte boundary.
			xmm_src0 = _mm_loadu_pd(src);
			xmm_src1 = _mm_loadu_pd(src + 2);
			xmm_src0 = _mm_sub_pd(xmm_src0, offset);
			xmm_src1 = _mm_sub_pd(xmm_src1, offset);
			xmm_src0 = _mm_max_pd(xmm_src0, min);
			xmm_src1 = _mm_max_pd(xmm_src1, min);
			xmm_src0 = _mm_min_pd(xmm_src0, max);
			xmm_src1 = _mm_min_pd(xmm_src1, max);
			xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
			xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
			xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
			xmm_dst0 = _mm_add_epi32(xmm_dst0, shift);
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
					xmm_src0 = _mm_load_pd(src);
					xmm_src1 = _mm_load_pd(src + 2);
					xmm_src2 = _mm_load_pd(src + 4);
					xmm_src3 = _mm_load_pd(src + 6);
					xmm_src4 = _mm_load_pd(src + 8);
					xmm_src5 = _mm_load_pd(src + 10);
					xmm_src6 = _mm_load_pd(src + 12);
					xmm_src7 = _mm_load_pd(src + 14);
					xmm_src8 = _mm_load_pd(src + 16);
					xmm_src9 = _mm_load_pd(src + 18);
					xmm_srca = _mm_load_pd(src + 20);
					xmm_srcb = _mm_load_pd(src + 22);
					xmm_srcc = _mm_load_pd(src + 24);
					xmm_srcd = _mm_load_pd(src + 26);
					xmm_srce = _mm_load_pd(src + 28);
					xmm_srcf = _mm_load_pd(src + 30);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					xmm_src0 = _mm_sub_pd(xmm_src0, offset);
					xmm_src1 = _mm_sub_pd(xmm_src1, offset);
					xmm_src2 = _mm_sub_pd(xmm_src2, offset);
					xmm_src3 = _mm_sub_pd(xmm_src3, offset);
					xmm_src4 = _mm_sub_pd(xmm_src4, offset);
					xmm_src5 = _mm_sub_pd(xmm_src5, offset);
					xmm_src6 = _mm_sub_pd(xmm_src6, offset);
					xmm_src7 = _mm_sub_pd(xmm_src7, offset);
					xmm_src8 = _mm_sub_pd(xmm_src8, offset);
					xmm_src9 = _mm_sub_pd(xmm_src9, offset);
					xmm_srca = _mm_sub_pd(xmm_srca, offset);
					xmm_srcb = _mm_sub_pd(xmm_srcb, offset);
					xmm_srcc = _mm_sub_pd(xmm_srcc, offset);
					xmm_srcd = _mm_sub_pd(xmm_srcd, offset);
					xmm_srce = _mm_sub_pd(xmm_srce, offset);
					xmm_srcf = _mm_sub_pd(xmm_srcf, offset);
					xmm_src0 = _mm_max_pd(xmm_src0, min);
					xmm_src1 = _mm_max_pd(xmm_src1, min);
					xmm_src2 = _mm_max_pd(xmm_src2, min);
					xmm_src3 = _mm_max_pd(xmm_src3, min);
					xmm_src4 = _mm_max_pd(xmm_src4, min);
					xmm_src5 = _mm_max_pd(xmm_src5, min);
					xmm_src6 = _mm_max_pd(xmm_src6, min);
					xmm_src7 = _mm_max_pd(xmm_src7, min);
					xmm_src8 = _mm_max_pd(xmm_src8, min);
					xmm_src9 = _mm_max_pd(xmm_src9, min);
					xmm_srca = _mm_max_pd(xmm_srca, min);
					xmm_srcb = _mm_max_pd(xmm_srcb, min);
					xmm_srcc = _mm_max_pd(xmm_srcc, min);
					xmm_srcd = _mm_max_pd(xmm_srcd, min);
					xmm_srce = _mm_max_pd(xmm_srce, min);
					xmm_srcf = _mm_max_pd(xmm_srcf, min);
					xmm_src0 = _mm_min_pd(xmm_src0, max);
					xmm_src1 = _mm_min_pd(xmm_src1, max);
					xmm_src2 = _mm_min_pd(xmm_src2, max);
					xmm_src3 = _mm_min_pd(xmm_src3, max);
					xmm_src4 = _mm_min_pd(xmm_src4, max);
					xmm_src5 = _mm_min_pd(xmm_src5, max);
					xmm_src6 = _mm_min_pd(xmm_src6, max);
					xmm_src7 = _mm_min_pd(xmm_src7, max);
					xmm_src8 = _mm_min_pd(xmm_src8, max);
					xmm_src9 = _mm_min_pd(xmm_src9, max);
					xmm_srca = _mm_min_pd(xmm_srca, max);
					xmm_srcb = _mm_min_pd(xmm_srcb, max);
					xmm_srcc = _mm_min_pd(xmm_srcc, max);
					xmm_srcd = _mm_min_pd(xmm_srcd, max);
					xmm_srce = _mm_min_pd(xmm_srce, max);
					xmm_srcf = _mm_min_pd(xmm_srcf, max);
					xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
					xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
					xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
					xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
					xmm_dst4 = _mm_cvttpd_epi32(xmm_src4);
					xmm_dst5 = _mm_cvttpd_epi32(xmm_src5);
					xmm_dst6 = _mm_cvttpd_epi32(xmm_src6);
					xmm_dst7 = _mm_cvttpd_epi32(xmm_src7);
					xmm_dst8 = _mm_cvttpd_epi32(xmm_src8);
					xmm_dst9 = _mm_cvttpd_epi32(xmm_src9);
					xmm_dsta = _mm_cvttpd_epi32(xmm_srca);
					xmm_dstb = _mm_cvttpd_epi32(xmm_srcb);
					xmm_dstc = _mm_cvttpd_epi32(xmm_srcc);
					xmm_dstd = _mm_cvttpd_epi32(xmm_srcd);
					xmm_dste = _mm_cvttpd_epi32(xmm_srce);
					xmm_dstf = _mm_cvttpd_epi32(xmm_srcf);
					xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
					xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
					xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
					xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
					xmm_dst8 = _mm_unpacklo_epi64(xmm_dst8, xmm_dst9);
					xmm_dsta = _mm_unpacklo_epi64(xmm_dsta, xmm_dstb);
					xmm_dstc = _mm_unpacklo_epi64(xmm_dstc, xmm_dstd);
					xmm_dste = _mm_unpacklo_epi64(xmm_dste, xmm_dstf);
					xmm_dst0 = _mm_add_epi32(xmm_dst0, shift);
					xmm_dst2 = _mm_add_epi32(xmm_dst2, shift);
					xmm_dst4 = _mm_add_epi32(xmm_dst4, shift);
					xmm_dst6 = _mm_add_epi32(xmm_dst6, shift);
					xmm_dst8 = _mm_add_epi32(xmm_dst8, shift);
					xmm_dsta = _mm_add_epi32(xmm_dsta, shift);
					xmm_dstc = _mm_add_epi32(xmm_dstc, shift);
					xmm_dste = _mm_add_epi32(xmm_dste, shift);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst2);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 2, xmm_dst4);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 3, xmm_dst6);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 4, xmm_dst8);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 5, xmm_dsta);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 6, xmm_dstc);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 7, xmm_dste);
					src += 32;
					dst += 32;
				}
			}
			else
			{
				for (; n >= 32; n -= 32)
				{
					xmm_src0 = _mm_loadu_pd(src);
					xmm_src1 = _mm_loadu_pd(src + 2);
					xmm_src2 = _mm_loadu_pd(src + 4);
					xmm_src3 = _mm_loadu_pd(src + 6);
					xmm_src4 = _mm_loadu_pd(src + 8);
					xmm_src5 = _mm_loadu_pd(src + 10);
					xmm_src6 = _mm_loadu_pd(src + 12);
					xmm_src7 = _mm_loadu_pd(src + 14);
					xmm_src8 = _mm_loadu_pd(src + 16);
					xmm_src9 = _mm_loadu_pd(src + 18);
					xmm_srca = _mm_loadu_pd(src + 20);
					xmm_srcb = _mm_loadu_pd(src + 22);
					xmm_srcc = _mm_loadu_pd(src + 24);
					xmm_srcd = _mm_loadu_pd(src + 26);
					xmm_srce = _mm_loadu_pd(src + 28);
					xmm_srcf = _mm_loadu_pd(src + 30);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					xmm_src0 = _mm_sub_pd(xmm_src0, offset);
					xmm_src1 = _mm_sub_pd(xmm_src1, offset);
					xmm_src2 = _mm_sub_pd(xmm_src2, offset);
					xmm_src3 = _mm_sub_pd(xmm_src3, offset);
					xmm_src4 = _mm_sub_pd(xmm_src4, offset);
					xmm_src5 = _mm_sub_pd(xmm_src5, offset);
					xmm_src6 = _mm_sub_pd(xmm_src6, offset);
					xmm_src7 = _mm_sub_pd(xmm_src7, offset);
					xmm_src8 = _mm_sub_pd(xmm_src8, offset);
					xmm_src9 = _mm_sub_pd(xmm_src9, offset);
					xmm_srca = _mm_sub_pd(xmm_srca, offset);
					xmm_srcb = _mm_sub_pd(xmm_srcb, offset);
					xmm_srcc = _mm_sub_pd(xmm_srcc, offset);
					xmm_srcd = _mm_sub_pd(xmm_srcd, offset);
					xmm_srce = _mm_sub_pd(xmm_srce, offset);
					xmm_srcf = _mm_sub_pd(xmm_srcf, offset);
					xmm_src0 = _mm_max_pd(xmm_src0, min);
					xmm_src1 = _mm_max_pd(xmm_src1, min);
					xmm_src2 = _mm_max_pd(xmm_src2, min);
					xmm_src3 = _mm_max_pd(xmm_src3, min);
					xmm_src4 = _mm_max_pd(xmm_src4, min);
					xmm_src5 = _mm_max_pd(xmm_src5, min);
					xmm_src6 = _mm_max_pd(xmm_src6, min);
					xmm_src7 = _mm_max_pd(xmm_src7, min);
					xmm_src8 = _mm_max_pd(xmm_src8, min);
					xmm_src9 = _mm_max_pd(xmm_src9, min);
					xmm_srca = _mm_max_pd(xmm_srca, min);
					xmm_srcb = _mm_max_pd(xmm_srcb, min);
					xmm_srcc = _mm_max_pd(xmm_srcc, min);
					xmm_srcd = _mm_max_pd(xmm_srcd, min);
					xmm_srce = _mm_max_pd(xmm_srce, min);
					xmm_srcf = _mm_max_pd(xmm_srcf, min);
					xmm_src0 = _mm_min_pd(xmm_src0, max);
					xmm_src1 = _mm_min_pd(xmm_src1, max);
					xmm_src2 = _mm_min_pd(xmm_src2, max);
					xmm_src3 = _mm_min_pd(xmm_src3, max);
					xmm_src4 = _mm_min_pd(xmm_src4, max);
					xmm_src5 = _mm_min_pd(xmm_src5, max);
					xmm_src6 = _mm_min_pd(xmm_src6, max);
					xmm_src7 = _mm_min_pd(xmm_src7, max);
					xmm_src8 = _mm_min_pd(xmm_src8, max);
					xmm_src9 = _mm_min_pd(xmm_src9, max);
					xmm_srca = _mm_min_pd(xmm_srca, max);
					xmm_srcb = _mm_min_pd(xmm_srcb, max);
					xmm_srcc = _mm_min_pd(xmm_srcc, max);
					xmm_srcd = _mm_min_pd(xmm_srcd, max);
					xmm_srce = _mm_min_pd(xmm_srce, max);
					xmm_srcf = _mm_min_pd(xmm_srcf, max);
					xmm_dst0 = _mm_cvttpd_epi32(xmm_src0);
					xmm_dst1 = _mm_cvttpd_epi32(xmm_src1);
					xmm_dst2 = _mm_cvttpd_epi32(xmm_src2);
					xmm_dst3 = _mm_cvttpd_epi32(xmm_src3);
					xmm_dst4 = _mm_cvttpd_epi32(xmm_src4);
					xmm_dst5 = _mm_cvttpd_epi32(xmm_src5);
					xmm_dst6 = _mm_cvttpd_epi32(xmm_src6);
					xmm_dst7 = _mm_cvttpd_epi32(xmm_src7);
					xmm_dst8 = _mm_cvttpd_epi32(xmm_src8);
					xmm_dst9 = _mm_cvttpd_epi32(xmm_src9);
					xmm_dsta = _mm_cvttpd_epi32(xmm_srca);
					xmm_dstb = _mm_cvttpd_epi32(xmm_srcb);
					xmm_dstc = _mm_cvttpd_epi32(xmm_srcc);
					xmm_dstd = _mm_cvttpd_epi32(xmm_srcd);
					xmm_dste = _mm_cvttpd_epi32(xmm_srce);
					xmm_dstf = _mm_cvttpd_epi32(xmm_srcf);
					xmm_dst0 = _mm_unpacklo_epi64(xmm_dst0, xmm_dst1);
					xmm_dst2 = _mm_unpacklo_epi64(xmm_dst2, xmm_dst3);
					xmm_dst4 = _mm_unpacklo_epi64(xmm_dst4, xmm_dst5);
					xmm_dst6 = _mm_unpacklo_epi64(xmm_dst6, xmm_dst7);
					xmm_dst8 = _mm_unpacklo_epi64(xmm_dst8, xmm_dst9);
					xmm_dsta = _mm_unpacklo_epi64(xmm_dsta, xmm_dstb);
					xmm_dstc = _mm_unpacklo_epi64(xmm_dstc, xmm_dstd);
					xmm_dste = _mm_unpacklo_epi64(xmm_dste, xmm_dstf);
					xmm_dst0 = _mm_add_epi32(xmm_dst0, shift);
					xmm_dst2 = _mm_add_epi32(xmm_dst2, shift);
					xmm_dst4 = _mm_add_epi32(xmm_dst4, shift);
					xmm_dst6 = _mm_add_epi32(xmm_dst6, shift);
					xmm_dst8 = _mm_add_epi32(xmm_dst8, shift);
					xmm_dsta = _mm_add_epi32(xmm_dsta, shift);
					xmm_dstc = _mm_add_epi32(xmm_dstc, shift);
					xmm_dste = _mm_add_epi32(xmm_dste, shift);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst), xmm_dst0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 1, xmm_dst2);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 2, xmm_dst4);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 3, xmm_dst6);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 4, xmm_dst8);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 5, xmm_dsta);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 6, xmm_dstc);
					_mm_stream_si128(reinterpret_cast<__m128i*>(dst) + 7, xmm_dste);
					src += 32;
					dst += 32;
				}
			}
		}

		template <>
		void cvtspd_sse41_large<float>(float* dst, const double* src, size_t n)
		{
			const size_t padding = 4 - (reinterpret_cast<size_t>(dst) & 3);
			const __m128d min = _mm_set1_pd(static_cast<double>(-FLT_MAX));
			const __m128d max = _mm_set1_pd(static_cast<double>(FLT_MAX));
			__m128d xmm_src0, xmm_src1, xmm_src2, xmm_src3, xmm_src4, xmm_src5, xmm_src6, xmm_src7;
			__m128d xmm_src8, xmm_src9, xmm_srca, xmm_srcb, xmm_srcc, xmm_srcd, xmm_srce, xmm_srcf;
			__m128 xmm_dst0, xmm_dst1, xmm_dst2, xmm_dst3, xmm_dst4, xmm_dst5, xmm_dst6, xmm_dst7;
			__m128 xmm_dst8, xmm_dst9, xmm_dsta, xmm_dstb, xmm_dstc, xmm_dstd, xmm_dste, xmm_dstf;

			// Align the destination to a 16-byte boundary.
			xmm_src0 = _mm_loadu_pd(src);
			xmm_src1 = _mm_loadu_pd(src + 2);
			xmm_src0 = _mm_max_pd(xmm_src0, min);
			xmm_src1 = _mm_max_pd(xmm_src1, min);
			xmm_src0 = _mm_min_pd(xmm_src0, max);
			xmm_src1 = _mm_min_pd(xmm_src1, max);
			xmm_dst0 = _mm_cvtpd_ps(xmm_src0);
			xmm_dst1 = _mm_cvtpd_ps(xmm_src1);
			xmm_dst0 = _mm_shuffle_ps(xmm_dst0, xmm_dst1, _MM_SHUFFLE(1, 0, 1, 0));
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
					xmm_src0 = _mm_load_pd(src);
					xmm_src1 = _mm_load_pd(src + 2);
					xmm_src2 = _mm_load_pd(src + 4);
					xmm_src3 = _mm_load_pd(src + 6);
					xmm_src4 = _mm_load_pd(src + 8);
					xmm_src5 = _mm_load_pd(src + 10);
					xmm_src6 = _mm_load_pd(src + 12);
					xmm_src7 = _mm_load_pd(src + 14);
					xmm_src8 = _mm_load_pd(src + 16);
					xmm_src9 = _mm_load_pd(src + 18);
					xmm_srca = _mm_load_pd(src + 20);
					xmm_srcb = _mm_load_pd(src + 22);
					xmm_srcc = _mm_load_pd(src + 24);
					xmm_srcd = _mm_load_pd(src + 26);
					xmm_srce = _mm_load_pd(src + 28);
					xmm_srcf = _mm_load_pd(src + 30);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					xmm_src0 = _mm_max_pd(xmm_src0, min);
					xmm_src1 = _mm_max_pd(xmm_src1, min);
					xmm_src2 = _mm_max_pd(xmm_src2, min);
					xmm_src3 = _mm_max_pd(xmm_src3, min);
					xmm_src4 = _mm_max_pd(xmm_src4, min);
					xmm_src5 = _mm_max_pd(xmm_src5, min);
					xmm_src6 = _mm_max_pd(xmm_src6, min);
					xmm_src7 = _mm_max_pd(xmm_src7, min);
					xmm_src8 = _mm_max_pd(xmm_src8, min);
					xmm_src9 = _mm_max_pd(xmm_src9, min);
					xmm_srca = _mm_max_pd(xmm_srca, min);
					xmm_srcb = _mm_max_pd(xmm_srcb, min);
					xmm_srcc = _mm_max_pd(xmm_srcc, min);
					xmm_srcd = _mm_max_pd(xmm_srcd, min);
					xmm_srce = _mm_max_pd(xmm_srce, min);
					xmm_srcf = _mm_max_pd(xmm_srcf, min);
					xmm_src0 = _mm_min_pd(xmm_src0, max);
					xmm_src1 = _mm_min_pd(xmm_src1, max);
					xmm_src2 = _mm_min_pd(xmm_src2, max);
					xmm_src3 = _mm_min_pd(xmm_src3, max);
					xmm_src4 = _mm_min_pd(xmm_src4, max);
					xmm_src5 = _mm_min_pd(xmm_src5, max);
					xmm_src6 = _mm_min_pd(xmm_src6, max);
					xmm_src7 = _mm_min_pd(xmm_src7, max);
					xmm_src8 = _mm_min_pd(xmm_src8, max);
					xmm_src9 = _mm_min_pd(xmm_src9, max);
					xmm_srca = _mm_min_pd(xmm_srca, max);
					xmm_srcb = _mm_min_pd(xmm_srcb, max);
					xmm_srcc = _mm_min_pd(xmm_srcc, max);
					xmm_srcd = _mm_min_pd(xmm_srcd, max);
					xmm_srce = _mm_min_pd(xmm_srce, max);
					xmm_srcf = _mm_min_pd(xmm_srcf, max);
					xmm_dst0 = _mm_cvtpd_ps(xmm_src0);
					xmm_dst1 = _mm_cvtpd_ps(xmm_src1);
					xmm_dst2 = _mm_cvtpd_ps(xmm_src2);
					xmm_dst3 = _mm_cvtpd_ps(xmm_src3);
					xmm_dst4 = _mm_cvtpd_ps(xmm_src4);
					xmm_dst5 = _mm_cvtpd_ps(xmm_src5);
					xmm_dst6 = _mm_cvtpd_ps(xmm_src6);
					xmm_dst7 = _mm_cvtpd_ps(xmm_src7);
					xmm_dst8 = _mm_cvtpd_ps(xmm_src8);
					xmm_dst9 = _mm_cvtpd_ps(xmm_src9);
					xmm_dsta = _mm_cvtpd_ps(xmm_srca);
					xmm_dstb = _mm_cvtpd_ps(xmm_srcb);
					xmm_dstc = _mm_cvtpd_ps(xmm_srcc);
					xmm_dstd = _mm_cvtpd_ps(xmm_srcd);
					xmm_dste = _mm_cvtpd_ps(xmm_srce);
					xmm_dstf = _mm_cvtpd_ps(xmm_srcf);
					xmm_dst0 = _mm_shuffle_ps(xmm_dst0, xmm_dst1, _MM_SHUFFLE(1, 0, 1, 0));
					xmm_dst2 = _mm_shuffle_ps(xmm_dst2, xmm_dst3, _MM_SHUFFLE(1, 0, 1, 0));
					xmm_dst4 = _mm_shuffle_ps(xmm_dst4, xmm_dst5, _MM_SHUFFLE(1, 0, 1, 0));
					xmm_dst6 = _mm_shuffle_ps(xmm_dst6, xmm_dst7, _MM_SHUFFLE(1, 0, 1, 0));
					xmm_dst8 = _mm_shuffle_ps(xmm_dst8, xmm_dst9, _MM_SHUFFLE(1, 0, 1, 0));
					xmm_dsta = _mm_shuffle_ps(xmm_dsta, xmm_dstb, _MM_SHUFFLE(1, 0, 1, 0));
					xmm_dstc = _mm_shuffle_ps(xmm_dstc, xmm_dstd, _MM_SHUFFLE(1, 0, 1, 0));
					xmm_dste = _mm_shuffle_ps(xmm_dste, xmm_dstf, _MM_SHUFFLE(1, 0, 1, 0));
					_mm_stream_ps(dst, xmm_dst0);
					_mm_stream_ps(dst + 4, xmm_dst2);
					_mm_stream_ps(dst + 8, xmm_dst4);
					_mm_stream_ps(dst + 12, xmm_dst6);
					_mm_stream_ps(dst + 16, xmm_dst8);
					_mm_stream_ps(dst + 20, xmm_dsta);
					_mm_stream_ps(dst + 24, xmm_dstc);
					_mm_stream_ps(dst + 28, xmm_dste);
					src += 32;
					dst += 32;
				}
			}
			else
			{
				for (; n >= 32; n -= 32)
				{
					xmm_src0 = _mm_loadu_pd(src);
					xmm_src1 = _mm_loadu_pd(src + 2);
					xmm_src2 = _mm_loadu_pd(src + 4);
					xmm_src3 = _mm_loadu_pd(src + 6);
					xmm_src4 = _mm_loadu_pd(src + 8);
					xmm_src5 = _mm_loadu_pd(src + 10);
					xmm_src6 = _mm_loadu_pd(src + 12);
					xmm_src7 = _mm_loadu_pd(src + 14);
					xmm_src8 = _mm_loadu_pd(src + 16);
					xmm_src9 = _mm_loadu_pd(src + 18);
					xmm_srca = _mm_loadu_pd(src + 20);
					xmm_srcb = _mm_loadu_pd(src + 22);
					xmm_srcc = _mm_loadu_pd(src + 24);
					xmm_srcd = _mm_loadu_pd(src + 26);
					xmm_srce = _mm_loadu_pd(src + 28);
					xmm_srcf = _mm_loadu_pd(src + 30);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(src + 32), _MM_HINT_NTA);
					xmm_src0 = _mm_max_pd(xmm_src0, min);
					xmm_src1 = _mm_max_pd(xmm_src1, min);
					xmm_src2 = _mm_max_pd(xmm_src2, min);
					xmm_src3 = _mm_max_pd(xmm_src3, min);
					xmm_src4 = _mm_max_pd(xmm_src4, min);
					xmm_src5 = _mm_max_pd(xmm_src5, min);
					xmm_src6 = _mm_max_pd(xmm_src6, min);
					xmm_src7 = _mm_max_pd(xmm_src7, min);
					xmm_src8 = _mm_max_pd(xmm_src8, min);
					xmm_src9 = _mm_max_pd(xmm_src9, min);
					xmm_srca = _mm_max_pd(xmm_srca, min);
					xmm_srcb = _mm_max_pd(xmm_srcb, min);
					xmm_srcc = _mm_max_pd(xmm_srcc, min);
					xmm_srcd = _mm_max_pd(xmm_srcd, min);
					xmm_srce = _mm_max_pd(xmm_srce, min);
					xmm_srcf = _mm_max_pd(xmm_srcf, min);
					xmm_src0 = _mm_min_pd(xmm_src0, max);
					xmm_src1 = _mm_min_pd(xmm_src1, max);
					xmm_src2 = _mm_min_pd(xmm_src2, max);
					xmm_src3 = _mm_min_pd(xmm_src3, max);
					xmm_src4 = _mm_min_pd(xmm_src4, max);
					xmm_src5 = _mm_min_pd(xmm_src5, max);
					xmm_src6 = _mm_min_pd(xmm_src6, max);
					xmm_src7 = _mm_min_pd(xmm_src7, max);
					xmm_src8 = _mm_min_pd(xmm_src8, max);
					xmm_src9 = _mm_min_pd(xmm_src9, max);
					xmm_srca = _mm_min_pd(xmm_srca, max);
					xmm_srcb = _mm_min_pd(xmm_srcb, max);
					xmm_srcc = _mm_min_pd(xmm_srcc, max);
					xmm_srcd = _mm_min_pd(xmm_srcd, max);
					xmm_srce = _mm_min_pd(xmm_srce, max);
					xmm_srcf = _mm_min_pd(xmm_srcf, max);
					xmm_dst0 = _mm_cvtpd_ps(xmm_src0);
					xmm_dst1 = _mm_cvtpd_ps(xmm_src1);
					xmm_dst2 = _mm_cvtpd_ps(xmm_src2);
					xmm_dst3 = _mm_cvtpd_ps(xmm_src3);
					xmm_dst4 = _mm_cvtpd_ps(xmm_src4);
					xmm_dst5 = _mm_cvtpd_ps(xmm_src5);
					xmm_dst6 = _mm_cvtpd_ps(xmm_src6);
					xmm_dst7 = _mm_cvtpd_ps(xmm_src7);
					xmm_dst8 = _mm_cvtpd_ps(xmm_src8);
					xmm_dst9 = _mm_cvtpd_ps(xmm_src9);
					xmm_dsta = _mm_cvtpd_ps(xmm_srca);
					xmm_dstb = _mm_cvtpd_ps(xmm_srcb);
					xmm_dstc = _mm_cvtpd_ps(xmm_srcc);
					xmm_dstd = _mm_cvtpd_ps(xmm_srcd);
					xmm_dste = _mm_cvtpd_ps(xmm_srce);
					xmm_dstf = _mm_cvtpd_ps(xmm_srcf);
					xmm_dst0 = _mm_shuffle_ps(xmm_dst0, xmm_dst1, _MM_SHUFFLE(1, 0, 1, 0));
					xmm_dst2 = _mm_shuffle_ps(xmm_dst2, xmm_dst3, _MM_SHUFFLE(1, 0, 1, 0));
					xmm_dst4 = _mm_shuffle_ps(xmm_dst4, xmm_dst5, _MM_SHUFFLE(1, 0, 1, 0));
					xmm_dst6 = _mm_shuffle_ps(xmm_dst6, xmm_dst7, _MM_SHUFFLE(1, 0, 1, 0));
					xmm_dst8 = _mm_shuffle_ps(xmm_dst8, xmm_dst9, _MM_SHUFFLE(1, 0, 1, 0));
					xmm_dsta = _mm_shuffle_ps(xmm_dsta, xmm_dstb, _MM_SHUFFLE(1, 0, 1, 0));
					xmm_dstc = _mm_shuffle_ps(xmm_dstc, xmm_dstd, _MM_SHUFFLE(1, 0, 1, 0));
					xmm_dste = _mm_shuffle_ps(xmm_dste, xmm_dstf, _MM_SHUFFLE(1, 0, 1, 0));
					_mm_stream_ps(dst, xmm_dst0);
					_mm_stream_ps(dst + 4, xmm_dst2);
					_mm_stream_ps(dst + 8, xmm_dst4);
					_mm_stream_ps(dst + 12, xmm_dst6);
					_mm_stream_ps(dst + 16, xmm_dst8);
					_mm_stream_ps(dst + 20, xmm_dsta);
					_mm_stream_ps(dst + 24, xmm_dstc);
					_mm_stream_ps(dst + 28, xmm_dste);
					src += 32;
					dst += 32;
				}
			}
		}

		// Function template impl_cvtspd

		template <class T>
		inline void impl_cvtspd(T* dst, const double* src, size_t n)
		{
			constexpr size_t threshold = simd::l2_cache_size / sizeof(double);
			// Small amount of data type conversion.
			if (n < 64)
				cvtspd_sse41_small(dst, src, n);
			// Medium amount data type conversion.
			else if (n < threshold)
			{
				cvtspd_sse41_medium(dst, src, n);
				cvtspd_sse41_small(dst, src, n);
			}
			// Large amount data type conversion.
			else
			{
				cvtspd_sse41_large(dst, src, n);
				cvtspd_sse41_small(dst, src, n);
			}
		}

	#else

		// Function template impl_cvtspd

		template <class T>
		void impl_cvtspd(T* dst, const double* src, size_t n)
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

		template<>
		void impl_cvtspd<signed char>(signed char* dst, const double* src, size_t n)
		{
			constexpr size_t block = 8;
			constexpr double min = static_cast<double>(INT8_MIN);
			constexpr double max = static_cast<double>(INT8_MAX);
			while (n >= block)
			{
				dst[0] = src[0] < min ? INT8_MIN : src[0] > max ? INT8_MAX : static_cast<signed char>(src[0]);
				dst[1] = src[1] < min ? INT8_MIN : src[1] > max ? INT8_MAX : static_cast<signed char>(src[1]);
				dst[2] = src[2] < min ? INT8_MIN : src[2] > max ? INT8_MAX : static_cast<signed char>(src[2]);
				dst[3] = src[3] < min ? INT8_MIN : src[3] > max ? INT8_MAX : static_cast<signed char>(src[3]);
				dst[4] = src[4] < min ? INT8_MIN : src[4] > max ? INT8_MAX : static_cast<signed char>(src[4]);
				dst[5] = src[5] < min ? INT8_MIN : src[5] > max ? INT8_MAX : static_cast<signed char>(src[5]);
				dst[6] = src[6] < min ? INT8_MIN : src[6] > max ? INT8_MAX : static_cast<signed char>(src[6]);
				dst[7] = src[7] < min ? INT8_MIN : src[7] > max ? INT8_MAX : static_cast<signed char>(src[7]);
				src += block;
				dst += block;
				n -= block;
			}
			switch (n)
			{
			case 7: dst[6] = src[6] < min ? INT8_MIN : src[6] > max ? INT8_MAX : static_cast<signed char>(src[6]);
			case 6: dst[5] = src[5] < min ? INT8_MIN : src[5] > max ? INT8_MAX : static_cast<signed char>(src[5]);
			case 5: dst[4] = src[4] < min ? INT8_MIN : src[4] > max ? INT8_MAX : static_cast<signed char>(src[4]);
			case 4: dst[3] = src[3] < min ? INT8_MIN : src[3] > max ? INT8_MAX : static_cast<signed char>(src[3]);
			case 3: dst[2] = src[2] < min ? INT8_MIN : src[2] > max ? INT8_MAX : static_cast<signed char>(src[2]);
			case 2: dst[1] = src[1] < min ? INT8_MIN : src[1] > max ? INT8_MAX : static_cast<signed char>(src[1]);
			case 1: dst[0] = src[0] < min ? INT8_MIN : src[0] > max ? INT8_MAX : static_cast<signed char>(src[0]);
				break;
			}
		}

		template<>
		void impl_cvtspd<unsigned char>(unsigned char* dst, const double* src, size_t n)
		{
			constexpr size_t block = 8;
			constexpr double max = static_cast<double>(UINT8_MAX);
			while (n >= block)
			{
				dst[0] = src[0] < 0 ? 0 : src[0] > max ? UINT8_MAX : static_cast<unsigned char>(src[0]);
				dst[1] = src[1] < 0 ? 0 : src[1] > max ? UINT8_MAX : static_cast<unsigned char>(src[1]);
				dst[2] = src[2] < 0 ? 0 : src[2] > max ? UINT8_MAX : static_cast<unsigned char>(src[2]);
				dst[3] = src[3] < 0 ? 0 : src[3] > max ? UINT8_MAX : static_cast<unsigned char>(src[3]);
				dst[4] = src[4] < 0 ? 0 : src[4] > max ? UINT8_MAX : static_cast<unsigned char>(src[4]);
				dst[5] = src[5] < 0 ? 0 : src[5] > max ? UINT8_MAX : static_cast<unsigned char>(src[5]);
				dst[6] = src[6] < 0 ? 0 : src[6] > max ? UINT8_MAX : static_cast<unsigned char>(src[6]);
				dst[7] = src[7] < 0 ? 0 : src[7] > max ? UINT8_MAX : static_cast<unsigned char>(src[7]);
				src += block;
				dst += block;
				n -= block;
			}
			switch (n)
			{
			case 7: dst[6] = src[6] < 0 ? 0 : src[6] > max ? UINT8_MAX : static_cast<unsigned char>(src[6]);
			case 6: dst[5] = src[5] < 0 ? 0 : src[5] > max ? UINT8_MAX : static_cast<unsigned char>(src[5]);
			case 5: dst[4] = src[4] < 0 ? 0 : src[4] > max ? UINT8_MAX : static_cast<unsigned char>(src[4]);
			case 4: dst[3] = src[3] < 0 ? 0 : src[3] > max ? UINT8_MAX : static_cast<unsigned char>(src[3]);
			case 3: dst[2] = src[2] < 0 ? 0 : src[2] > max ? UINT8_MAX : static_cast<unsigned char>(src[2]);
			case 2: dst[1] = src[1] < 0 ? 0 : src[1] > max ? UINT8_MAX : static_cast<unsigned char>(src[1]);
			case 1: dst[0] = src[0] < 0 ? 0 : src[0] > max ? UINT8_MAX : static_cast<unsigned char>(src[0]);
				break;
			}
		}

		template<>
		void impl_cvtspd<signed short>(signed short* dst, const double* src, size_t n)
		{
			constexpr size_t block = 8;
			constexpr double min = static_cast<double>(INT16_MIN);
			constexpr double max = static_cast<double>(INT16_MAX);
			while (n >= block)
			{
				dst[0] = src[0] < min ? INT16_MIN : src[0] > max ? INT16_MAX : static_cast<signed short>(src[0]);
				dst[1] = src[1] < min ? INT16_MIN : src[1] > max ? INT16_MAX : static_cast<signed short>(src[1]);
				dst[2] = src[2] < min ? INT16_MIN : src[2] > max ? INT16_MAX : static_cast<signed short>(src[2]);
				dst[3] = src[3] < min ? INT16_MIN : src[3] > max ? INT16_MAX : static_cast<signed short>(src[3]);
				dst[4] = src[4] < min ? INT16_MIN : src[4] > max ? INT16_MAX : static_cast<signed short>(src[4]);
				dst[5] = src[5] < min ? INT16_MIN : src[5] > max ? INT16_MAX : static_cast<signed short>(src[5]);
				dst[6] = src[6] < min ? INT16_MIN : src[6] > max ? INT16_MAX : static_cast<signed short>(src[6]);
				dst[7] = src[7] < min ? INT16_MIN : src[7] > max ? INT16_MAX : static_cast<signed short>(src[7]);
				src += block;
				dst += block;
				n -= block;
			}
			switch (n)
			{
			case 7: dst[6] = src[6] < min ? INT16_MIN : src[6] > max ? INT16_MAX : static_cast<signed short>(src[6]);
			case 6: dst[5] = src[5] < min ? INT16_MIN : src[5] > max ? INT16_MAX : static_cast<signed short>(src[5]);
			case 5: dst[4] = src[4] < min ? INT16_MIN : src[4] > max ? INT16_MAX : static_cast<signed short>(src[4]);
			case 4: dst[3] = src[3] < min ? INT16_MIN : src[3] > max ? INT16_MAX : static_cast<signed short>(src[3]);
			case 3: dst[2] = src[2] < min ? INT16_MIN : src[2] > max ? INT16_MAX : static_cast<signed short>(src[2]);
			case 2: dst[1] = src[1] < min ? INT16_MIN : src[1] > max ? INT16_MAX : static_cast<signed short>(src[1]);
			case 1: dst[0] = src[0] < min ? INT16_MIN : src[0] > max ? INT16_MAX : static_cast<signed short>(src[0]);
				break;
			}
		}

		template<>
		void impl_cvtspd<unsigned short>(unsigned short* dst, const double* src, size_t n)
		{
			constexpr size_t block = 8;
			constexpr double max = static_cast<double>(UINT16_MAX);
			while (n >= block)
			{
				dst[0] = src[0] < 0 ? 0 : src[0] > max ? UINT16_MAX : static_cast<unsigned short>(src[0]);
				dst[1] = src[1] < 0 ? 0 : src[1] > max ? UINT16_MAX : static_cast<unsigned short>(src[1]);
				dst[2] = src[2] < 0 ? 0 : src[2] > max ? UINT16_MAX : static_cast<unsigned short>(src[2]);
				dst[3] = src[3] < 0 ? 0 : src[3] > max ? UINT16_MAX : static_cast<unsigned short>(src[3]);
				dst[4] = src[4] < 0 ? 0 : src[4] > max ? UINT16_MAX : static_cast<unsigned short>(src[4]);
				dst[5] = src[5] < 0 ? 0 : src[5] > max ? UINT16_MAX : static_cast<unsigned short>(src[5]);
				dst[6] = src[6] < 0 ? 0 : src[6] > max ? UINT16_MAX : static_cast<unsigned short>(src[6]);
				dst[7] = src[7] < 0 ? 0 : src[7] > max ? UINT16_MAX : static_cast<unsigned short>(src[7]);
				src += block;
				dst += block;
				n -= block;
			}
			switch (n)
			{
			case 7: dst[6] = src[6] < 0 ? 0 : src[6] > max ? UINT16_MAX : static_cast<unsigned short>(src[6]);
			case 6: dst[5] = src[5] < 0 ? 0 : src[5] > max ? UINT16_MAX : static_cast<unsigned short>(src[5]);
			case 5: dst[4] = src[4] < 0 ? 0 : src[4] > max ? UINT16_MAX : static_cast<unsigned short>(src[4]);
			case 4: dst[3] = src[3] < 0 ? 0 : src[3] > max ? UINT16_MAX : static_cast<unsigned short>(src[3]);
			case 3: dst[2] = src[2] < 0 ? 0 : src[2] > max ? UINT16_MAX : static_cast<unsigned short>(src[2]);
			case 2: dst[1] = src[1] < 0 ? 0 : src[1] > max ? UINT16_MAX : static_cast<unsigned short>(src[1]);
			case 1: dst[0] = src[0] < 0 ? 0 : src[0] > max ? UINT16_MAX : static_cast<unsigned short>(src[0]);
				break;
			}
		}

		template<>
		void impl_cvtspd<signed int>(signed int* dst, const double* src, size_t n)
		{
			constexpr size_t block = 8;
			constexpr double min = -2.14748352e+9F;
			constexpr double max =  2.14748352e+9F;
			while (n >= block)
			{
				dst[0] = src[0] < min ? INT32_MIN : src[0] > max ? INT32_MAX : static_cast<signed int>(src[0]);
				dst[1] = src[1] < min ? INT32_MIN : src[1] > max ? INT32_MAX : static_cast<signed int>(src[1]);
				dst[2] = src[2] < min ? INT32_MIN : src[2] > max ? INT32_MAX : static_cast<signed int>(src[2]);
				dst[3] = src[3] < min ? INT32_MIN : src[3] > max ? INT32_MAX : static_cast<signed int>(src[3]);
				dst[4] = src[4] < min ? INT32_MIN : src[4] > max ? INT32_MAX : static_cast<signed int>(src[4]);
				dst[5] = src[5] < min ? INT32_MIN : src[5] > max ? INT32_MAX : static_cast<signed int>(src[5]);
				dst[6] = src[6] < min ? INT32_MIN : src[6] > max ? INT32_MAX : static_cast<signed int>(src[6]);
				dst[7] = src[7] < min ? INT32_MIN : src[7] > max ? INT32_MAX : static_cast<signed int>(src[7]);
				src += block;
				dst += block;
				n -= block;
			}
			switch (n)
			{
			case 7: dst[6] = src[6] < min ? INT32_MIN : src[6] > max ? INT32_MAX : static_cast<signed int>(src[6]);
			case 6: dst[5] = src[5] < min ? INT32_MIN : src[5] > max ? INT32_MAX : static_cast<signed int>(src[5]);
			case 5: dst[4] = src[4] < min ? INT32_MIN : src[4] > max ? INT32_MAX : static_cast<signed int>(src[4]);
			case 4: dst[3] = src[3] < min ? INT32_MIN : src[3] > max ? INT32_MAX : static_cast<signed int>(src[3]);
			case 3: dst[2] = src[2] < min ? INT32_MIN : src[2] > max ? INT32_MAX : static_cast<signed int>(src[2]);
			case 2: dst[1] = src[1] < min ? INT32_MIN : src[1] > max ? INT32_MAX : static_cast<signed int>(src[1]);
			case 1: dst[0] = src[0] < min ? INT32_MIN : src[0] > max ? INT32_MAX : static_cast<signed int>(src[0]);
				break;
			}
		}

		template<>
		void impl_cvtspd<unsigned int>(unsigned int* dst, const double* src, size_t n)
		{
			constexpr size_t block = 8;
			constexpr double max = 4.294967167e+9F;
			while (n >= block)
			{
				dst[0] = src[0] < 0 ? 0 : src[0] > max ? UINT32_MAX : static_cast<unsigned int>(src[0]);
				dst[1] = src[1] < 0 ? 0 : src[1] > max ? UINT32_MAX : static_cast<unsigned int>(src[1]);
				dst[2] = src[2] < 0 ? 0 : src[2] > max ? UINT32_MAX : static_cast<unsigned int>(src[2]);
				dst[3] = src[3] < 0 ? 0 : src[3] > max ? UINT32_MAX : static_cast<unsigned int>(src[3]);
				dst[4] = src[4] < 0 ? 0 : src[4] > max ? UINT32_MAX : static_cast<unsigned int>(src[4]);
				dst[5] = src[5] < 0 ? 0 : src[5] > max ? UINT32_MAX : static_cast<unsigned int>(src[5]);
				dst[6] = src[6] < 0 ? 0 : src[6] > max ? UINT32_MAX : static_cast<unsigned int>(src[6]);
				dst[7] = src[7] < 0 ? 0 : src[7] > max ? UINT32_MAX : static_cast<unsigned int>(src[7]);
				src += block;
				dst += block;
				n -= block;
			}
			switch (n)
			{
			case 7: dst[6] = src[6] < 0 ? 0 : src[6] > max ? UINT32_MAX : static_cast<unsigned int>(src[6]);
			case 6: dst[5] = src[5] < 0 ? 0 : src[5] > max ? UINT32_MAX : static_cast<unsigned int>(src[5]);
			case 5: dst[4] = src[4] < 0 ? 0 : src[4] > max ? UINT32_MAX : static_cast<unsigned int>(src[4]);
			case 4: dst[3] = src[3] < 0 ? 0 : src[3] > max ? UINT32_MAX : static_cast<unsigned int>(src[3]);
			case 3: dst[2] = src[2] < 0 ? 0 : src[2] > max ? UINT32_MAX : static_cast<unsigned int>(src[2]);
			case 2: dst[1] = src[1] < 0 ? 0 : src[1] > max ? UINT32_MAX : static_cast<unsigned int>(src[1]);
			case 1: dst[0] = src[0] < 0 ? 0 : src[0] > max ? UINT32_MAX : static_cast<unsigned int>(src[0]);
				break;
			}
		}

		template<>
		void impl_cvtspd<float>(float* dst, const double* src, size_t n)
		{
			constexpr size_t block = 8;
			constexpr double min = static_cast<double>(-FLT_MAX);
			constexpr double max = static_cast<double>(FLT_MAX);
			while (n >= block)
			{
				dst[0] = src[0] < min ? -FLT_MAX : src[0] > max ? FLT_MAX : static_cast<float>(src[0]);
				dst[1] = src[1] < min ? -FLT_MAX : src[1] > max ? FLT_MAX : static_cast<float>(src[1]);
				dst[2] = src[2] < min ? -FLT_MAX : src[2] > max ? FLT_MAX : static_cast<float>(src[2]);
				dst[3] = src[3] < min ? -FLT_MAX : src[3] > max ? FLT_MAX : static_cast<float>(src[3]);
				dst[4] = src[4] < min ? -FLT_MAX : src[4] > max ? FLT_MAX : static_cast<float>(src[4]);
				dst[5] = src[5] < min ? -FLT_MAX : src[5] > max ? FLT_MAX : static_cast<float>(src[5]);
				dst[6] = src[6] < min ? -FLT_MAX : src[6] > max ? FLT_MAX : static_cast<float>(src[6]);
				dst[7] = src[7] < min ? -FLT_MAX : src[7] > max ? FLT_MAX : static_cast<float>(src[7]);
				src += block;
				dst += block;
				n -= block;
			}
			switch (n)
			{
			case 7: dst[6] = src[6] < min ? -FLT_MAX : src[6] > max ? FLT_MAX : static_cast<float>(src[6]);
			case 6: dst[5] = src[5] < min ? -FLT_MAX : src[5] > max ? FLT_MAX : static_cast<float>(src[5]);
			case 5: dst[4] = src[4] < min ? -FLT_MAX : src[4] > max ? FLT_MAX : static_cast<float>(src[4]);
			case 4: dst[3] = src[3] < min ? -FLT_MAX : src[3] > max ? FLT_MAX : static_cast<float>(src[3]);
			case 3: dst[2] = src[2] < min ? -FLT_MAX : src[2] > max ? FLT_MAX : static_cast<float>(src[2]);
			case 2: dst[1] = src[1] < min ? -FLT_MAX : src[1] > max ? FLT_MAX : static_cast<float>(src[1]);
			case 1: dst[0] = src[0] < min ? -FLT_MAX : src[0] > max ? FLT_MAX : static_cast<float>(src[0]);
				break;
			}
		}

	#endif

		template <>
		void impl_cvtspd<double>(double* dst, const double* src, size_t n)
		{
			std::memcpy(dst, src, n * sizeof(double));
		}

	} // namespace cpu

} // namespace core

#endif
