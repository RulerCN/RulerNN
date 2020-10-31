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
		inline void cvtspd_tiny(T* b, const double* a, size_t n)
		{
			switch (n)
			{
			case 7: b[6] = static_cast<T>(a[6]);
			case 6: b[5] = static_cast<T>(a[5]);
			case 5: b[4] = static_cast<T>(a[4]);
			case 4: b[3] = static_cast<T>(a[3]);
			case 3: b[2] = static_cast<T>(a[2]);
			case 2: b[1] = static_cast<T>(a[1]);
			case 1: b[0] = static_cast<T>(a[0]);
				break;
			}
		}

		template<>
		inline void cvtspd_tiny<signed char>(signed char* b, const double* a, size_t n)
		{
			constexpr double min = static_cast<double>(INT8_MIN);
			constexpr double max = static_cast<double>(INT8_MAX);
			switch (n)
			{
			case 7: b[6] = a[6] < min ? INT8_MIN : a[6] > max ? INT8_MAX : static_cast<signed char>(a[6]);
			case 6: b[5] = a[5] < min ? INT8_MIN : a[5] > max ? INT8_MAX : static_cast<signed char>(a[5]);
			case 5: b[4] = a[4] < min ? INT8_MIN : a[4] > max ? INT8_MAX : static_cast<signed char>(a[4]);
			case 4: b[3] = a[3] < min ? INT8_MIN : a[3] > max ? INT8_MAX : static_cast<signed char>(a[3]);
			case 3: b[2] = a[2] < min ? INT8_MIN : a[2] > max ? INT8_MAX : static_cast<signed char>(a[2]);
			case 2: b[1] = a[1] < min ? INT8_MIN : a[1] > max ? INT8_MAX : static_cast<signed char>(a[1]);
			case 1: b[0] = a[0] < min ? INT8_MIN : a[0] > max ? INT8_MAX : static_cast<signed char>(a[0]);
				break;
			}
		}

		template<>
		inline void cvtspd_tiny<unsigned char>(unsigned char* b, const double* a, size_t n)
		{
			constexpr double max = static_cast<double>(UINT8_MAX);
			switch (n)
			{
			case 7: b[6] = a[6] < 0 ? 0 : a[6] > max ? UINT8_MAX : static_cast<unsigned char>(a[6]);
			case 6: b[5] = a[5] < 0 ? 0 : a[5] > max ? UINT8_MAX : static_cast<unsigned char>(a[5]);
			case 5: b[4] = a[4] < 0 ? 0 : a[4] > max ? UINT8_MAX : static_cast<unsigned char>(a[4]);
			case 4: b[3] = a[3] < 0 ? 0 : a[3] > max ? UINT8_MAX : static_cast<unsigned char>(a[3]);
			case 3: b[2] = a[2] < 0 ? 0 : a[2] > max ? UINT8_MAX : static_cast<unsigned char>(a[2]);
			case 2: b[1] = a[1] < 0 ? 0 : a[1] > max ? UINT8_MAX : static_cast<unsigned char>(a[1]);
			case 1: b[0] = a[0] < 0 ? 0 : a[0] > max ? UINT8_MAX : static_cast<unsigned char>(a[0]);
				break;
			}
		}

		template<>
		inline void cvtspd_tiny<signed short>(signed short* b, const double* a, size_t n)
		{
			constexpr double min = static_cast<double>(INT16_MIN);
			constexpr double max = static_cast<double>(INT16_MAX);
			switch (n)
			{
			case 7: b[6] = a[6] < min ? INT16_MIN : a[6] > max ? INT16_MAX : static_cast<signed short>(a[6]);
			case 6: b[5] = a[5] < min ? INT16_MIN : a[5] > max ? INT16_MAX : static_cast<signed short>(a[5]);
			case 5: b[4] = a[4] < min ? INT16_MIN : a[4] > max ? INT16_MAX : static_cast<signed short>(a[4]);
			case 4: b[3] = a[3] < min ? INT16_MIN : a[3] > max ? INT16_MAX : static_cast<signed short>(a[3]);
			case 3: b[2] = a[2] < min ? INT16_MIN : a[2] > max ? INT16_MAX : static_cast<signed short>(a[2]);
			case 2: b[1] = a[1] < min ? INT16_MIN : a[1] > max ? INT16_MAX : static_cast<signed short>(a[1]);
			case 1: b[0] = a[0] < min ? INT16_MIN : a[0] > max ? INT16_MAX : static_cast<signed short>(a[0]);
				break;
			}
		}

		template<>
		inline void cvtspd_tiny<unsigned short>(unsigned short* b, const double* a, size_t n)
		{
			constexpr double max = static_cast<double>(UINT16_MAX);
			switch (n)
			{
			case 7: b[6] = a[6] < 0 ? 0 : a[6] > max ? UINT16_MAX : static_cast<unsigned short>(a[6]);
			case 6: b[5] = a[5] < 0 ? 0 : a[5] > max ? UINT16_MAX : static_cast<unsigned short>(a[5]);
			case 5: b[4] = a[4] < 0 ? 0 : a[4] > max ? UINT16_MAX : static_cast<unsigned short>(a[4]);
			case 4: b[3] = a[3] < 0 ? 0 : a[3] > max ? UINT16_MAX : static_cast<unsigned short>(a[3]);
			case 3: b[2] = a[2] < 0 ? 0 : a[2] > max ? UINT16_MAX : static_cast<unsigned short>(a[2]);
			case 2: b[1] = a[1] < 0 ? 0 : a[1] > max ? UINT16_MAX : static_cast<unsigned short>(a[1]);
			case 1: b[0] = a[0] < 0 ? 0 : a[0] > max ? UINT16_MAX : static_cast<unsigned short>(a[0]);
				break;
			}
		}

		template<>
		inline void cvtspd_tiny<signed int>(signed int* b, const double* a, size_t n)
		{
			constexpr double min = static_cast<double>(INT32_MIN);
			constexpr double max = static_cast<double>(INT32_MAX);
			switch (n)
			{
			case 7: b[6] = a[6] < min ? INT32_MIN : a[6] > max ? INT32_MAX : static_cast<signed int>(a[6]);
			case 6: b[5] = a[5] < min ? INT32_MIN : a[5] > max ? INT32_MAX : static_cast<signed int>(a[5]);
			case 5: b[4] = a[4] < min ? INT32_MIN : a[4] > max ? INT32_MAX : static_cast<signed int>(a[4]);
			case 4: b[3] = a[3] < min ? INT32_MIN : a[3] > max ? INT32_MAX : static_cast<signed int>(a[3]);
			case 3: b[2] = a[2] < min ? INT32_MIN : a[2] > max ? INT32_MAX : static_cast<signed int>(a[2]);
			case 2: b[1] = a[1] < min ? INT32_MIN : a[1] > max ? INT32_MAX : static_cast<signed int>(a[1]);
			case 1: b[0] = a[0] < min ? INT32_MIN : a[0] > max ? INT32_MAX : static_cast<signed int>(a[0]);
				break;
			}
		}

		template<>
		inline void cvtspd_tiny<unsigned int>(unsigned int* b, const double* a, size_t n)
		{
			constexpr double max = static_cast<double>(UINT32_MAX);
			switch (n)
			{
			case 7: b[6] = a[6] < 0 ? 0 : a[6] > max ? UINT32_MAX : static_cast<unsigned int>(a[6]);
			case 6: b[5] = a[5] < 0 ? 0 : a[5] > max ? UINT32_MAX : static_cast<unsigned int>(a[5]);
			case 5: b[4] = a[4] < 0 ? 0 : a[4] > max ? UINT32_MAX : static_cast<unsigned int>(a[4]);
			case 4: b[3] = a[3] < 0 ? 0 : a[3] > max ? UINT32_MAX : static_cast<unsigned int>(a[3]);
			case 3: b[2] = a[2] < 0 ? 0 : a[2] > max ? UINT32_MAX : static_cast<unsigned int>(a[2]);
			case 2: b[1] = a[1] < 0 ? 0 : a[1] > max ? UINT32_MAX : static_cast<unsigned int>(a[1]);
			case 1: b[0] = a[0] < 0 ? 0 : a[0] > max ? UINT32_MAX : static_cast<unsigned int>(a[0]);
				break;
			}
		}

	#ifdef __AVX2__

		// Function template cvtspd_avx2_8

		template <class T>
		inline void cvtspd_avx2_8(T* b, const double* a)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		inline void cvtspd_avx2_8<signed char>(signed char* b, const double* a)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT8_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT8_MAX));
			__m256d ymm_a0 = _mm256_loadu_pd(a);
			__m256d ymm_a1 = _mm256_loadu_pd(a + 4);
			ymm_a0 = _mm256_max_pd(ymm_a0, min);
			ymm_a1 = _mm256_max_pd(ymm_a1, min);
			ymm_a0 = _mm256_min_pd(ymm_a0, max);
			ymm_a1 = _mm256_min_pd(ymm_a1, max);
			__m256i ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
			__m256i ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
			ymm_b0 = _mm256_packs_epi32(ymm_b0, ymm_b1);
			ymm_b0 = _mm256_packs_epi16(ymm_b0, _mm256_setzero_si256());
			_mm_storeu_si64(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
		}

		template <>
		inline void cvtspd_avx2_8<unsigned char>(unsigned char* b, const double* a)
		{
			const __m256d min = _mm256_setzero_pd();
			const __m256d max = _mm256_set1_pd(static_cast<double>(UINT8_MAX));
			__m256d ymm_a0 = _mm256_loadu_pd(a);
			__m256d ymm_a1 = _mm256_loadu_pd(a + 4);
			ymm_a0 = _mm256_max_pd(ymm_a0, min);
			ymm_a1 = _mm256_max_pd(ymm_a1, min);
			ymm_a0 = _mm256_min_pd(ymm_a0, max);
			ymm_a1 = _mm256_min_pd(ymm_a1, max);
			__m256i ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
			__m256i ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
			ymm_b0 = _mm256_packus_epi32(ymm_b0, ymm_b1);
			ymm_b0 = _mm256_packus_epi16(ymm_b0, _mm256_setzero_si256());
			_mm_storeu_si64(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
		}

		template <>
		inline void cvtspd_avx2_8<signed short>(signed short* b, const double* a)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT16_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT16_MAX));
			__m256d ymm_a0 = _mm256_loadu_pd(a);
			__m256d ymm_a1 = _mm256_loadu_pd(a + 4);
			ymm_a0 = _mm256_max_pd(ymm_a0, min);
			ymm_a1 = _mm256_max_pd(ymm_a1, min);
			ymm_a0 = _mm256_min_pd(ymm_a0, max);
			ymm_a1 = _mm256_min_pd(ymm_a1, max);
			__m256i ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
			__m256i ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
			ymm_b0 = _mm256_packs_epi32(ymm_b0, ymm_b1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
		}

		template <>
		inline void cvtspd_avx2_8<unsigned short>(unsigned short* b, const double* a)
		{
			const __m256d min = _mm256_setzero_pd();
			const __m256d max = _mm256_set1_pd(static_cast<double>(UINT16_MAX));
			__m256d ymm_a0 = _mm256_loadu_pd(a);
			__m256d ymm_a1 = _mm256_loadu_pd(a + 4);
			ymm_a0 = _mm256_max_pd(ymm_a0, min);
			ymm_a1 = _mm256_max_pd(ymm_a1, min);
			ymm_a0 = _mm256_min_pd(ymm_a0, max);
			ymm_a1 = _mm256_min_pd(ymm_a1, max);
			__m256i ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
			__m256i ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
			ymm_b0 = _mm256_packus_epi32(ymm_b0, ymm_b1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
		}

		template <>
		inline void cvtspd_avx2_8<signed int>(signed int* b, const double* a)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT32_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT32_MAX));
			__m256d ymm_a0 = _mm256_loadu_pd(a);
			__m256d ymm_a1 = _mm256_loadu_pd(a + 4);
			ymm_a0 = _mm256_max_pd(ymm_a0, min);
			ymm_a1 = _mm256_max_pd(ymm_a1, min);
			ymm_a0 = _mm256_min_pd(ymm_a0, max);
			ymm_a1 = _mm256_min_pd(ymm_a1, max);
			__m128i xmm_b0 = _mm256_cvttpd_epi32(ymm_a0);
			__m128i xmm_b1 = _mm256_cvttpd_epi32(ymm_a1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b1);
		}

		template <>
		inline void cvtspd_avx2_8<unsigned int>(unsigned int* b, const double* a)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT32_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT32_MAX));
			const __m256d offset = _mm256_set1_pd(2.147483648e+9);
			const __m256i shift = _mm256_set1_epi32(2147483648);
			__m256d ymm_a0 = _mm256_loadu_pd(a);
			__m256d ymm_a1 = _mm256_loadu_pd(a + 4);
			ymm_a0 = _mm256_sub_pd(ymm_a0, offset);
			ymm_a1 = _mm256_sub_pd(ymm_a1, offset);
			ymm_a0 = _mm256_max_pd(ymm_a0, min);
			ymm_a1 = _mm256_max_pd(ymm_a1, min);
			ymm_a0 = _mm256_min_pd(ymm_a0, max);
			ymm_a1 = _mm256_min_pd(ymm_a1, max);
			__m256i ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
			__m256i ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
			ymm_b0 = _mm256_add_epi32(ymm_b0, shift);
			ymm_b1 = _mm256_add_epi32(ymm_b1, shift);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, _mm256_castsi256_si128(ymm_b1));
		}

		template <>
		inline void cvtspd_avx2_8<float>(float* b, const double* a)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(-FLT_MAX));
			const __m256d max = _mm256_set1_pd(static_cast<double>(FLT_MAX));
			__m256d ymm_a0 = _mm256_loadu_pd(a);
			__m256d ymm_a1 = _mm256_loadu_pd(a + 4);
			ymm_a0 = _mm256_max_pd(ymm_a0, min);
			ymm_a1 = _mm256_max_pd(ymm_a1, min);
			ymm_a0 = _mm256_min_pd(ymm_a0, max);
			ymm_a1 = _mm256_min_pd(ymm_a1, max);
			__m128 xmm_b0 = _mm256_cvtpd_ps(ymm_a0);
			__m128 xmm_b1 = _mm256_cvtpd_ps(ymm_a1);
			_mm_storeu_ps(b, xmm_b0);
			_mm_storeu_ps(b + 4, xmm_b1);
		}

		// Function template cvtspd_avx2_16

		template <class T>
		inline void cvtspd_avx2_16(T* b, const double* a)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		inline void cvtspd_avx2_16<signed char>(signed char* b, const double* a)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT8_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT8_MAX));
			__m256d ymm_a0 = _mm256_loadu_pd(a);
			__m256d ymm_a1 = _mm256_loadu_pd(a + 4);
			__m256d ymm_a2 = _mm256_loadu_pd(a + 8);
			__m256d ymm_a3 = _mm256_loadu_pd(a + 12);
			ymm_a0 = _mm256_max_pd(ymm_a0, min);
			ymm_a1 = _mm256_max_pd(ymm_a1, min);
			ymm_a2 = _mm256_max_pd(ymm_a2, min);
			ymm_a3 = _mm256_max_pd(ymm_a3, min);
			ymm_a0 = _mm256_min_pd(ymm_a0, max);
			ymm_a1 = _mm256_min_pd(ymm_a1, max);
			ymm_a2 = _mm256_min_pd(ymm_a2, max);
			ymm_a3 = _mm256_min_pd(ymm_a3, max);
			__m256i ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
			__m256i ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
			__m256i ymm_b2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a2));
			__m256i ymm_b3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a3));
			ymm_b0 = _mm256_packs_epi32(ymm_b0, ymm_b1);
			ymm_b2 = _mm256_packs_epi32(ymm_b2, ymm_b3);
			ymm_b0 = _mm256_packs_epi16(ymm_b0, ymm_b2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
		}

		template <>
		inline void cvtspd_avx2_16<unsigned char>(unsigned char* b, const double* a)
		{
			const __m256d min = _mm256_setzero_pd();
			const __m256d max = _mm256_set1_pd(static_cast<double>(UINT8_MAX));
			__m256d ymm_a0 = _mm256_loadu_pd(a);
			__m256d ymm_a1 = _mm256_loadu_pd(a + 4);
			__m256d ymm_a2 = _mm256_loadu_pd(a + 8);
			__m256d ymm_a3 = _mm256_loadu_pd(a + 12);
			ymm_a0 = _mm256_max_pd(ymm_a0, min);
			ymm_a1 = _mm256_max_pd(ymm_a1, min);
			ymm_a2 = _mm256_max_pd(ymm_a2, min);
			ymm_a3 = _mm256_max_pd(ymm_a3, min);
			ymm_a0 = _mm256_min_pd(ymm_a0, max);
			ymm_a1 = _mm256_min_pd(ymm_a1, max);
			ymm_a2 = _mm256_min_pd(ymm_a2, max);
			ymm_a3 = _mm256_min_pd(ymm_a3, max);
			__m256i ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
			__m256i ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
			__m256i ymm_b2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a2));
			__m256i ymm_b3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a3));
			ymm_b0 = _mm256_packus_epi32(ymm_b0, ymm_b1);
			ymm_b2 = _mm256_packus_epi32(ymm_b2, ymm_b3);
			ymm_b0 = _mm256_packus_epi16(ymm_b0, ymm_b2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
		}

		template <>
		inline void cvtspd_avx2_16<signed short>(signed short* b, const double* a)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT16_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT16_MAX));
			__m256d ymm_a0 = _mm256_loadu_pd(a);
			__m256d ymm_a1 = _mm256_loadu_pd(a + 4);
			__m256d ymm_a2 = _mm256_loadu_pd(a + 8);
			__m256d ymm_a3 = _mm256_loadu_pd(a + 12);
			ymm_a0 = _mm256_max_pd(ymm_a0, min);
			ymm_a1 = _mm256_max_pd(ymm_a1, min);
			ymm_a2 = _mm256_max_pd(ymm_a2, min);
			ymm_a3 = _mm256_max_pd(ymm_a3, min);
			ymm_a0 = _mm256_min_pd(ymm_a0, max);
			ymm_a1 = _mm256_min_pd(ymm_a1, max);
			ymm_a2 = _mm256_min_pd(ymm_a2, max);
			ymm_a3 = _mm256_min_pd(ymm_a3, max);
			__m256i ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
			__m256i ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
			__m256i ymm_b2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a2));
			__m256i ymm_b3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a3));
			ymm_b0 = _mm256_packs_epi32(ymm_b0, ymm_b1);
			ymm_b2 = _mm256_packs_epi32(ymm_b2, ymm_b3);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, _mm256_castsi256_si128(ymm_b2));
		}

		template <>
		inline void cvtspd_avx2_16<unsigned short>(unsigned short* b, const double* a)
		{
			const __m256d min = _mm256_setzero_pd();
			const __m256d max = _mm256_set1_pd(static_cast<double>(UINT16_MAX));
			__m256d ymm_a0 = _mm256_loadu_pd(a);
			__m256d ymm_a1 = _mm256_loadu_pd(a + 4);
			__m256d ymm_a2 = _mm256_loadu_pd(a + 8);
			__m256d ymm_a3 = _mm256_loadu_pd(a + 12);
			ymm_a0 = _mm256_max_pd(ymm_a0, min);
			ymm_a1 = _mm256_max_pd(ymm_a1, min);
			ymm_a2 = _mm256_max_pd(ymm_a2, min);
			ymm_a3 = _mm256_max_pd(ymm_a3, min);
			ymm_a0 = _mm256_min_pd(ymm_a0, max);
			ymm_a1 = _mm256_min_pd(ymm_a1, max);
			ymm_a2 = _mm256_min_pd(ymm_a2, max);
			ymm_a3 = _mm256_min_pd(ymm_a3, max);
			__m256i ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
			__m256i ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
			__m256i ymm_b2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a2));
			__m256i ymm_b3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a3));
			ymm_b0 = _mm256_packus_epi32(ymm_b0, ymm_b1);
			ymm_b2 = _mm256_packus_epi32(ymm_b2, ymm_b3);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, _mm256_castsi256_si128(ymm_b2));
		}

		template <>
		inline void cvtspd_avx2_16<signed int>(signed int* b, const double* a)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT32_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT32_MAX));
			__m256d ymm_a0 = _mm256_loadu_pd(a);
			__m256d ymm_a1 = _mm256_loadu_pd(a + 4);
			__m256d ymm_a2 = _mm256_loadu_pd(a + 8);
			__m256d ymm_a3 = _mm256_loadu_pd(a + 12);
			ymm_a0 = _mm256_max_pd(ymm_a0, min);
			ymm_a1 = _mm256_max_pd(ymm_a1, min);
			ymm_a2 = _mm256_max_pd(ymm_a2, min);
			ymm_a3 = _mm256_max_pd(ymm_a3, min);
			ymm_a0 = _mm256_min_pd(ymm_a0, max);
			ymm_a1 = _mm256_min_pd(ymm_a1, max);
			ymm_a2 = _mm256_min_pd(ymm_a2, max);
			ymm_a3 = _mm256_min_pd(ymm_a3, max);
			__m128i xmm_b0 = _mm256_cvttpd_epi32(ymm_a0);
			__m128i xmm_b1 = _mm256_cvttpd_epi32(ymm_a1);
			__m128i xmm_b2 = _mm256_cvttpd_epi32(ymm_a2);
			__m128i xmm_b3 = _mm256_cvttpd_epi32(ymm_a3);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 2, xmm_b2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 3, xmm_b3);
		}

		template <>
		inline void cvtspd_avx2_16<unsigned int>(unsigned int* b, const double* a)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT32_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT32_MAX));
			const __m256d offset = _mm256_set1_pd(2.147483648e+9);
			const __m256i shift = _mm256_set1_epi32(2147483648);
			__m256d ymm_a0 = _mm256_loadu_pd(a);
			__m256d ymm_a1 = _mm256_loadu_pd(a + 4);
			__m256d ymm_a2 = _mm256_loadu_pd(a + 8);
			__m256d ymm_a3 = _mm256_loadu_pd(a + 12);
			ymm_a0 = _mm256_sub_pd(ymm_a0, offset);
			ymm_a1 = _mm256_sub_pd(ymm_a1, offset);
			ymm_a2 = _mm256_sub_pd(ymm_a2, offset);
			ymm_a3 = _mm256_sub_pd(ymm_a3, offset);
			ymm_a0 = _mm256_max_pd(ymm_a0, min);
			ymm_a1 = _mm256_max_pd(ymm_a1, min);
			ymm_a2 = _mm256_max_pd(ymm_a2, min);
			ymm_a3 = _mm256_max_pd(ymm_a3, min);
			ymm_a0 = _mm256_min_pd(ymm_a0, max);
			ymm_a1 = _mm256_min_pd(ymm_a1, max);
			ymm_a2 = _mm256_min_pd(ymm_a2, max);
			ymm_a3 = _mm256_min_pd(ymm_a3, max);
			__m256i ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
			__m256i ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
			__m256i ymm_b2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a2));
			__m256i ymm_b3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a3));
			ymm_b0 = _mm256_add_epi32(ymm_b0, shift);
			ymm_b1 = _mm256_add_epi32(ymm_b1, shift);
			ymm_b2 = _mm256_add_epi32(ymm_b2, shift);
			ymm_b3 = _mm256_add_epi32(ymm_b3, shift);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, _mm256_castsi256_si128(ymm_b1));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 2, _mm256_castsi256_si128(ymm_b2));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 3, _mm256_castsi256_si128(ymm_b3));
		}

		template <>
		inline void cvtspd_avx2_16<float>(float* b, const double* a)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(-FLT_MAX));
			const __m256d max = _mm256_set1_pd(static_cast<double>(FLT_MAX));
			__m256d ymm_a0 = _mm256_loadu_pd(a);
			__m256d ymm_a1 = _mm256_loadu_pd(a + 4);
			__m256d ymm_a2 = _mm256_loadu_pd(a + 8);
			__m256d ymm_a3 = _mm256_loadu_pd(a + 12);
			ymm_a0 = _mm256_max_pd(ymm_a0, min);
			ymm_a1 = _mm256_max_pd(ymm_a1, min);
			ymm_a2 = _mm256_max_pd(ymm_a2, min);
			ymm_a3 = _mm256_max_pd(ymm_a3, min);
			ymm_a0 = _mm256_min_pd(ymm_a0, max);
			ymm_a1 = _mm256_min_pd(ymm_a1, max);
			ymm_a2 = _mm256_min_pd(ymm_a2, max);
			ymm_a3 = _mm256_min_pd(ymm_a3, max);
			__m128 xmm_b0 = _mm256_cvtpd_ps(ymm_a0);
			__m128 xmm_b1 = _mm256_cvtpd_ps(ymm_a1);
			__m128 xmm_b2 = _mm256_cvtpd_ps(ymm_a2);
			__m128 xmm_b3 = _mm256_cvtpd_ps(ymm_a3);
			_mm_storeu_ps(b, xmm_b0);
			_mm_storeu_ps(b + 4, xmm_b1);
			_mm_storeu_ps(b + 8, xmm_b2);
			_mm_storeu_ps(b + 12, xmm_b3);
		}

		// Function template cvtspd_avx2_32

		template <class T>
		inline void cvtspd_avx2_32(T* b, const double* a)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		inline void cvtspd_avx2_32<signed char>(signed char* b, const double* a)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT8_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT8_MAX));
			__m256d ymm_a0 = _mm256_loadu_pd(a);
			__m256d ymm_a1 = _mm256_loadu_pd(a + 4);
			__m256d ymm_a2 = _mm256_loadu_pd(a + 8);
			__m256d ymm_a3 = _mm256_loadu_pd(a + 12);
			__m256d ymm_a4 = _mm256_loadu_pd(a + 16);
			__m256d ymm_a5 = _mm256_loadu_pd(a + 20);
			__m256d ymm_a6 = _mm256_loadu_pd(a + 24);
			__m256d ymm_a7 = _mm256_loadu_pd(a + 28);
			ymm_a0 = _mm256_max_pd(ymm_a0, min);
			ymm_a1 = _mm256_max_pd(ymm_a1, min);
			ymm_a2 = _mm256_max_pd(ymm_a2, min);
			ymm_a3 = _mm256_max_pd(ymm_a3, min);
			ymm_a4 = _mm256_max_pd(ymm_a4, min);
			ymm_a5 = _mm256_max_pd(ymm_a5, min);
			ymm_a6 = _mm256_max_pd(ymm_a6, min);
			ymm_a7 = _mm256_max_pd(ymm_a7, min);
			ymm_a0 = _mm256_min_pd(ymm_a0, max);
			ymm_a1 = _mm256_min_pd(ymm_a1, max);
			ymm_a2 = _mm256_min_pd(ymm_a2, max);
			ymm_a3 = _mm256_min_pd(ymm_a3, max);
			ymm_a4 = _mm256_min_pd(ymm_a4, max);
			ymm_a5 = _mm256_min_pd(ymm_a5, max);
			ymm_a6 = _mm256_min_pd(ymm_a6, max);
			ymm_a7 = _mm256_min_pd(ymm_a7, max);
			__m256i ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
			__m256i ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
			__m256i ymm_b2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a2));
			__m256i ymm_b3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a3));
			__m256i ymm_b4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a4));
			__m256i ymm_b5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a5));
			__m256i ymm_b6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a6));
			__m256i ymm_b7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a7));
			ymm_b0 = _mm256_packs_epi32(ymm_b0, ymm_b1);
			ymm_b2 = _mm256_packs_epi32(ymm_b2, ymm_b3);
			ymm_b4 = _mm256_packs_epi32(ymm_b4, ymm_b5);
			ymm_b6 = _mm256_packs_epi32(ymm_b6, ymm_b7);
			ymm_b0 = _mm256_packs_epi16(ymm_b0, ymm_b2);
			ymm_b4 = _mm256_packs_epi16(ymm_b4, ymm_b6);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, _mm256_castsi256_si128(ymm_b4));
		}

		template <>
		inline void cvtspd_avx2_32<unsigned char>(unsigned char* b, const double* a)
		{
			const __m256d min = _mm256_setzero_pd();
			const __m256d max = _mm256_set1_pd(static_cast<double>(UINT8_MAX));
			__m256d ymm_a0 = _mm256_loadu_pd(a);
			__m256d ymm_a1 = _mm256_loadu_pd(a + 4);
			__m256d ymm_a2 = _mm256_loadu_pd(a + 8);
			__m256d ymm_a3 = _mm256_loadu_pd(a + 12);
			__m256d ymm_a4 = _mm256_loadu_pd(a + 16);
			__m256d ymm_a5 = _mm256_loadu_pd(a + 20);
			__m256d ymm_a6 = _mm256_loadu_pd(a + 24);
			__m256d ymm_a7 = _mm256_loadu_pd(a + 28);
			ymm_a0 = _mm256_max_pd(ymm_a0, min);
			ymm_a1 = _mm256_max_pd(ymm_a1, min);
			ymm_a2 = _mm256_max_pd(ymm_a2, min);
			ymm_a3 = _mm256_max_pd(ymm_a3, min);
			ymm_a4 = _mm256_max_pd(ymm_a4, min);
			ymm_a5 = _mm256_max_pd(ymm_a5, min);
			ymm_a6 = _mm256_max_pd(ymm_a6, min);
			ymm_a7 = _mm256_max_pd(ymm_a7, min);
			ymm_a0 = _mm256_min_pd(ymm_a0, max);
			ymm_a1 = _mm256_min_pd(ymm_a1, max);
			ymm_a2 = _mm256_min_pd(ymm_a2, max);
			ymm_a3 = _mm256_min_pd(ymm_a3, max);
			ymm_a4 = _mm256_min_pd(ymm_a4, max);
			ymm_a5 = _mm256_min_pd(ymm_a5, max);
			ymm_a6 = _mm256_min_pd(ymm_a6, max);
			ymm_a7 = _mm256_min_pd(ymm_a7, max);
			__m256i ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
			__m256i ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
			__m256i ymm_b2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a2));
			__m256i ymm_b3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a3));
			__m256i ymm_b4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a4));
			__m256i ymm_b5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a5));
			__m256i ymm_b6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a6));
			__m256i ymm_b7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a7));
			ymm_b0 = _mm256_packus_epi32(ymm_b0, ymm_b1);
			ymm_b2 = _mm256_packus_epi32(ymm_b2, ymm_b3);
			ymm_b4 = _mm256_packus_epi32(ymm_b4, ymm_b5);
			ymm_b6 = _mm256_packus_epi32(ymm_b6, ymm_b7);
			ymm_b0 = _mm256_packus_epi16(ymm_b0, ymm_b2);
			ymm_b4 = _mm256_packus_epi16(ymm_b4, ymm_b6);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, _mm256_castsi256_si128(ymm_b4));
		}

		template <>
		inline void cvtspd_avx2_32<signed short>(signed short* b, const double* a)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT16_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT16_MAX));
			__m256d ymm_a0 = _mm256_loadu_pd(a);
			__m256d ymm_a1 = _mm256_loadu_pd(a + 4);
			__m256d ymm_a2 = _mm256_loadu_pd(a + 8);
			__m256d ymm_a3 = _mm256_loadu_pd(a + 12);
			__m256d ymm_a4 = _mm256_loadu_pd(a + 16);
			__m256d ymm_a5 = _mm256_loadu_pd(a + 20);
			__m256d ymm_a6 = _mm256_loadu_pd(a + 24);
			__m256d ymm_a7 = _mm256_loadu_pd(a + 28);
			ymm_a0 = _mm256_max_pd(ymm_a0, min);
			ymm_a1 = _mm256_max_pd(ymm_a1, min);
			ymm_a2 = _mm256_max_pd(ymm_a2, min);
			ymm_a3 = _mm256_max_pd(ymm_a3, min);
			ymm_a4 = _mm256_max_pd(ymm_a4, min);
			ymm_a5 = _mm256_max_pd(ymm_a5, min);
			ymm_a6 = _mm256_max_pd(ymm_a6, min);
			ymm_a7 = _mm256_max_pd(ymm_a7, min);
			ymm_a0 = _mm256_min_pd(ymm_a0, max);
			ymm_a1 = _mm256_min_pd(ymm_a1, max);
			ymm_a2 = _mm256_min_pd(ymm_a2, max);
			ymm_a3 = _mm256_min_pd(ymm_a3, max);
			ymm_a4 = _mm256_min_pd(ymm_a4, max);
			ymm_a5 = _mm256_min_pd(ymm_a5, max);
			ymm_a6 = _mm256_min_pd(ymm_a6, max);
			ymm_a7 = _mm256_min_pd(ymm_a7, max);
			__m256i ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
			__m256i ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
			__m256i ymm_b2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a2));
			__m256i ymm_b3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a3));
			__m256i ymm_b4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a4));
			__m256i ymm_b5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a5));
			__m256i ymm_b6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a6));
			__m256i ymm_b7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a7));
			ymm_b0 = _mm256_packs_epi32(ymm_b0, ymm_b1);
			ymm_b2 = _mm256_packs_epi32(ymm_b2, ymm_b3);
			ymm_b4 = _mm256_packs_epi32(ymm_b4, ymm_b5);
			ymm_b6 = _mm256_packs_epi32(ymm_b6, ymm_b7);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, _mm256_castsi256_si128(ymm_b2));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 2, _mm256_castsi256_si128(ymm_b4));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 3, _mm256_castsi256_si128(ymm_b6));
		}

		template <>
		inline void cvtspd_avx2_32<unsigned short>(unsigned short* b, const double* a)
		{
			const __m256d min = _mm256_setzero_pd();
			const __m256d max = _mm256_set1_pd(static_cast<double>(UINT16_MAX));
			__m256d ymm_a0 = _mm256_loadu_pd(a);
			__m256d ymm_a1 = _mm256_loadu_pd(a + 4);
			__m256d ymm_a2 = _mm256_loadu_pd(a + 8);
			__m256d ymm_a3 = _mm256_loadu_pd(a + 12);
			__m256d ymm_a4 = _mm256_loadu_pd(a + 16);
			__m256d ymm_a5 = _mm256_loadu_pd(a + 20);
			__m256d ymm_a6 = _mm256_loadu_pd(a + 24);
			__m256d ymm_a7 = _mm256_loadu_pd(a + 28);
			ymm_a0 = _mm256_max_pd(ymm_a0, min);
			ymm_a1 = _mm256_max_pd(ymm_a1, min);
			ymm_a2 = _mm256_max_pd(ymm_a2, min);
			ymm_a3 = _mm256_max_pd(ymm_a3, min);
			ymm_a4 = _mm256_max_pd(ymm_a4, min);
			ymm_a5 = _mm256_max_pd(ymm_a5, min);
			ymm_a6 = _mm256_max_pd(ymm_a6, min);
			ymm_a7 = _mm256_max_pd(ymm_a7, min);
			ymm_a0 = _mm256_min_pd(ymm_a0, max);
			ymm_a1 = _mm256_min_pd(ymm_a1, max);
			ymm_a2 = _mm256_min_pd(ymm_a2, max);
			ymm_a3 = _mm256_min_pd(ymm_a3, max);
			ymm_a4 = _mm256_min_pd(ymm_a4, max);
			ymm_a5 = _mm256_min_pd(ymm_a5, max);
			ymm_a6 = _mm256_min_pd(ymm_a6, max);
			ymm_a7 = _mm256_min_pd(ymm_a7, max);
			__m256i ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
			__m256i ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
			__m256i ymm_b2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a2));
			__m256i ymm_b3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a3));
			__m256i ymm_b4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a4));
			__m256i ymm_b5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a5));
			__m256i ymm_b6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a6));
			__m256i ymm_b7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a7));
			ymm_b0 = _mm256_packus_epi32(ymm_b0, ymm_b1);
			ymm_b2 = _mm256_packus_epi32(ymm_b2, ymm_b3);
			ymm_b4 = _mm256_packus_epi32(ymm_b4, ymm_b5);
			ymm_b6 = _mm256_packus_epi32(ymm_b6, ymm_b7);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, _mm256_castsi256_si128(ymm_b2));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 2, _mm256_castsi256_si128(ymm_b4));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 3, _mm256_castsi256_si128(ymm_b6));
		}

		template <>
		inline void cvtspd_avx2_32<signed int>(signed int* b, const double* a)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT32_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT32_MAX));
			__m256d ymm_a0 = _mm256_loadu_pd(a);
			__m256d ymm_a1 = _mm256_loadu_pd(a + 4);
			__m256d ymm_a2 = _mm256_loadu_pd(a + 8);
			__m256d ymm_a3 = _mm256_loadu_pd(a + 12);
			__m256d ymm_a4 = _mm256_loadu_pd(a + 16);
			__m256d ymm_a5 = _mm256_loadu_pd(a + 20);
			__m256d ymm_a6 = _mm256_loadu_pd(a + 24);
			__m256d ymm_a7 = _mm256_loadu_pd(a + 28);
			ymm_a0 = _mm256_max_pd(ymm_a0, min);
			ymm_a1 = _mm256_max_pd(ymm_a1, min);
			ymm_a2 = _mm256_max_pd(ymm_a2, min);
			ymm_a3 = _mm256_max_pd(ymm_a3, min);
			ymm_a4 = _mm256_max_pd(ymm_a4, min);
			ymm_a5 = _mm256_max_pd(ymm_a5, min);
			ymm_a6 = _mm256_max_pd(ymm_a6, min);
			ymm_a7 = _mm256_max_pd(ymm_a7, min);
			ymm_a0 = _mm256_min_pd(ymm_a0, max);
			ymm_a1 = _mm256_min_pd(ymm_a1, max);
			ymm_a2 = _mm256_min_pd(ymm_a2, max);
			ymm_a3 = _mm256_min_pd(ymm_a3, max);
			ymm_a4 = _mm256_min_pd(ymm_a4, max);
			ymm_a5 = _mm256_min_pd(ymm_a5, max);
			ymm_a6 = _mm256_min_pd(ymm_a6, max);
			ymm_a7 = _mm256_min_pd(ymm_a7, max);
			__m128i xmm_b0 = _mm256_cvttpd_epi32(ymm_a0);
			__m128i xmm_b1 = _mm256_cvttpd_epi32(ymm_a1);
			__m128i xmm_b2 = _mm256_cvttpd_epi32(ymm_a2);
			__m128i xmm_b3 = _mm256_cvttpd_epi32(ymm_a3);
			__m128i xmm_b4 = _mm256_cvttpd_epi32(ymm_a4);
			__m128i xmm_b5 = _mm256_cvttpd_epi32(ymm_a5);
			__m128i xmm_b6 = _mm256_cvttpd_epi32(ymm_a6);
			__m128i xmm_b7 = _mm256_cvttpd_epi32(ymm_a7);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 2, xmm_b2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 3, xmm_b3);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 4, xmm_b4);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 5, xmm_b5);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 6, xmm_b6);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 7, xmm_b7);
		}

		template <>
		inline void cvtspd_avx2_32<unsigned int>(unsigned int* b, const double* a)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT32_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT32_MAX));
			const __m256d offset = _mm256_set1_pd(2.147483648e+9);
			const __m256i shift = _mm256_set1_epi32(2147483648);
			__m256d ymm_a0 = _mm256_loadu_pd(a);
			__m256d ymm_a1 = _mm256_loadu_pd(a + 4);
			__m256d ymm_a2 = _mm256_loadu_pd(a + 8);
			__m256d ymm_a3 = _mm256_loadu_pd(a + 12);
			__m256d ymm_a4 = _mm256_loadu_pd(a + 16);
			__m256d ymm_a5 = _mm256_loadu_pd(a + 20);
			__m256d ymm_a6 = _mm256_loadu_pd(a + 24);
			__m256d ymm_a7 = _mm256_loadu_pd(a + 28);
			ymm_a0 = _mm256_sub_pd(ymm_a0, offset);
			ymm_a1 = _mm256_sub_pd(ymm_a1, offset);
			ymm_a2 = _mm256_sub_pd(ymm_a2, offset);
			ymm_a3 = _mm256_sub_pd(ymm_a3, offset);
			ymm_a4 = _mm256_sub_pd(ymm_a4, offset);
			ymm_a5 = _mm256_sub_pd(ymm_a5, offset);
			ymm_a6 = _mm256_sub_pd(ymm_a6, offset);
			ymm_a7 = _mm256_sub_pd(ymm_a7, offset);
			ymm_a0 = _mm256_max_pd(ymm_a0, min);
			ymm_a1 = _mm256_max_pd(ymm_a1, min);
			ymm_a2 = _mm256_max_pd(ymm_a2, min);
			ymm_a3 = _mm256_max_pd(ymm_a3, min);
			ymm_a4 = _mm256_max_pd(ymm_a4, min);
			ymm_a5 = _mm256_max_pd(ymm_a5, min);
			ymm_a6 = _mm256_max_pd(ymm_a6, min);
			ymm_a7 = _mm256_max_pd(ymm_a7, min);
			ymm_a0 = _mm256_min_pd(ymm_a0, max);
			ymm_a1 = _mm256_min_pd(ymm_a1, max);
			ymm_a2 = _mm256_min_pd(ymm_a2, max);
			ymm_a3 = _mm256_min_pd(ymm_a3, max);
			ymm_a4 = _mm256_min_pd(ymm_a4, max);
			ymm_a5 = _mm256_min_pd(ymm_a5, max);
			ymm_a6 = _mm256_min_pd(ymm_a6, max);
			ymm_a7 = _mm256_min_pd(ymm_a7, max);
			__m256i ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
			__m256i ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
			__m256i ymm_b2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a2));
			__m256i ymm_b3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a3));
			__m256i ymm_b4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a4));
			__m256i ymm_b5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a5));
			__m256i ymm_b6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a6));
			__m256i ymm_b7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a7));
			ymm_b0 = _mm256_add_epi32(ymm_b0, shift);
			ymm_b1 = _mm256_add_epi32(ymm_b1, shift);
			ymm_b2 = _mm256_add_epi32(ymm_b2, shift);
			ymm_b3 = _mm256_add_epi32(ymm_b3, shift);
			ymm_b4 = _mm256_add_epi32(ymm_b4, shift);
			ymm_b5 = _mm256_add_epi32(ymm_b5, shift);
			ymm_b6 = _mm256_add_epi32(ymm_b6, shift);
			ymm_b7 = _mm256_add_epi32(ymm_b7, shift);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, _mm256_castsi256_si128(ymm_b1));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 2, _mm256_castsi256_si128(ymm_b2));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 3, _mm256_castsi256_si128(ymm_b3));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 4, _mm256_castsi256_si128(ymm_b4));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 5, _mm256_castsi256_si128(ymm_b5));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 6, _mm256_castsi256_si128(ymm_b6));
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 7, _mm256_castsi256_si128(ymm_b7));
		}

		template <>
		inline void cvtspd_avx2_32<float>(float* b, const double* a)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(-FLT_MAX));
			const __m256d max = _mm256_set1_pd(static_cast<double>(FLT_MAX));
			__m256d ymm_a0 = _mm256_loadu_pd(a);
			__m256d ymm_a1 = _mm256_loadu_pd(a + 4);
			__m256d ymm_a2 = _mm256_loadu_pd(a + 8);
			__m256d ymm_a3 = _mm256_loadu_pd(a + 12);
			__m256d ymm_a4 = _mm256_loadu_pd(a + 16);
			__m256d ymm_a5 = _mm256_loadu_pd(a + 20);
			__m256d ymm_a6 = _mm256_loadu_pd(a + 24);
			__m256d ymm_a7 = _mm256_loadu_pd(a + 28);
			ymm_a0 = _mm256_max_pd(ymm_a0, min);
			ymm_a1 = _mm256_max_pd(ymm_a1, min);
			ymm_a2 = _mm256_max_pd(ymm_a2, min);
			ymm_a3 = _mm256_max_pd(ymm_a3, min);
			ymm_a4 = _mm256_max_pd(ymm_a4, min);
			ymm_a5 = _mm256_max_pd(ymm_a5, min);
			ymm_a6 = _mm256_max_pd(ymm_a6, min);
			ymm_a7 = _mm256_max_pd(ymm_a7, min);
			ymm_a0 = _mm256_min_pd(ymm_a0, max);
			ymm_a1 = _mm256_min_pd(ymm_a1, max);
			ymm_a2 = _mm256_min_pd(ymm_a2, max);
			ymm_a3 = _mm256_min_pd(ymm_a3, max);
			ymm_a4 = _mm256_min_pd(ymm_a4, max);
			ymm_a5 = _mm256_min_pd(ymm_a5, max);
			ymm_a6 = _mm256_min_pd(ymm_a6, max);
			ymm_a7 = _mm256_min_pd(ymm_a7, max);
			__m128 xmm_b0 = _mm256_cvtpd_ps(ymm_a0);
			__m128 xmm_b1 = _mm256_cvtpd_ps(ymm_a1);
			__m128 xmm_b2 = _mm256_cvtpd_ps(ymm_a2);
			__m128 xmm_b3 = _mm256_cvtpd_ps(ymm_a3);
			__m128 xmm_b4 = _mm256_cvtpd_ps(ymm_a4);
			__m128 xmm_b5 = _mm256_cvtpd_ps(ymm_a5);
			__m128 xmm_b6 = _mm256_cvtpd_ps(ymm_a6);
			__m128 xmm_b7 = _mm256_cvtpd_ps(ymm_a7);
			_mm_storeu_ps(b, xmm_b0);
			_mm_storeu_ps(b + 4, xmm_b1);
			_mm_storeu_ps(b + 8, xmm_b2);
			_mm_storeu_ps(b + 12, xmm_b3);
			_mm_storeu_ps(b + 16, xmm_b4);
			_mm_storeu_ps(b + 20, xmm_b5);
			_mm_storeu_ps(b + 24, xmm_b6);
			_mm_storeu_ps(b + 28, xmm_b7);
		}

		// Function template cvtspd_avx2_small

		template <class T>
		inline void cvtspd_avx2_small(T* b, const double* a, size_t n)
		{
			switch (n >> 3)
			{
			case 4:
				cvtspd_avx2_32(b, a);
			case 0:
				break;
			case 5:
				cvtspd_avx2_32(b, a);
				a += 32;
				b += 32;
			case 1:
				cvtspd_avx2_8(b, a);
				break;
			case 6:
				cvtspd_avx2_32(b, a);
				a += 32;
				b += 32;
			case 2:
				cvtspd_avx2_16(b, a);
				break;
			case 7:
				cvtspd_avx2_32(b, a);
				a += 32;
				b += 32;
			case 3:
				cvtspd_avx2_16(b, a);
				a += 16;
				b += 16;
				cvtspd_avx2_8(b, a);
				break;
			}
			cvtspd_tiny(b, a, n & 7);
		}

		// Function template cvtspd_avx2_medium

		template <class T>
		inline void cvtspd_avx2_medium(T* b, const double* a, size_t n)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		void cvtspd_avx2_medium<signed char>(signed char* b, const double* a, size_t n)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT8_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT8_MAX));
			__m256d ymm_a0, ymm_a1, ymm_a2, ymm_a3, ymm_a4, ymm_a5, ymm_a6, ymm_a7;
			__m256i ymm_b0, ymm_b1, ymm_b2, ymm_b3, ymm_b4, ymm_b5, ymm_b6, ymm_b7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				ymm_a0 = _mm256_loadu_pd(a);
				ymm_a1 = _mm256_loadu_pd(a + 4);
				ymm_a2 = _mm256_loadu_pd(a + 8);
				ymm_a3 = _mm256_loadu_pd(a + 12);
				ymm_a4 = _mm256_loadu_pd(a + 16);
				ymm_a5 = _mm256_loadu_pd(a + 20);
				ymm_a6 = _mm256_loadu_pd(a + 24);
				ymm_a7 = _mm256_loadu_pd(a + 28);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
				ymm_a0 = _mm256_max_pd(ymm_a0, min);
				ymm_a1 = _mm256_max_pd(ymm_a1, min);
				ymm_a2 = _mm256_max_pd(ymm_a2, min);
				ymm_a3 = _mm256_max_pd(ymm_a3, min);
				ymm_a4 = _mm256_max_pd(ymm_a4, min);
				ymm_a5 = _mm256_max_pd(ymm_a5, min);
				ymm_a6 = _mm256_max_pd(ymm_a6, min);
				ymm_a7 = _mm256_max_pd(ymm_a7, min);
				ymm_a0 = _mm256_min_pd(ymm_a0, max);
				ymm_a1 = _mm256_min_pd(ymm_a1, max);
				ymm_a2 = _mm256_min_pd(ymm_a2, max);
				ymm_a3 = _mm256_min_pd(ymm_a3, max);
				ymm_a4 = _mm256_min_pd(ymm_a4, max);
				ymm_a5 = _mm256_min_pd(ymm_a5, max);
				ymm_a6 = _mm256_min_pd(ymm_a6, max);
				ymm_a7 = _mm256_min_pd(ymm_a7, max);
				ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
				ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
				ymm_b2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a2));
				ymm_b3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a3));
				ymm_b4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a4));
				ymm_b5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a5));
				ymm_b6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a6));
				ymm_b7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a7));
				ymm_b0 = _mm256_packs_epi32(ymm_b0, ymm_b1);
				ymm_b2 = _mm256_packs_epi32(ymm_b2, ymm_b3);
				ymm_b4 = _mm256_packs_epi32(ymm_b4, ymm_b5);
				ymm_b6 = _mm256_packs_epi32(ymm_b6, ymm_b7);
				ymm_b0 = _mm256_packs_epi16(ymm_b0, ymm_b2);
				ymm_b4 = _mm256_packs_epi16(ymm_b4, ymm_b6);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, _mm256_castsi256_si128(ymm_b4));
				a += 32;
				b += 32;
			}
		}

		template <>
		void cvtspd_avx2_medium<unsigned char>(unsigned char* b, const double* a, size_t n)
		{
			const __m256d min = _mm256_setzero_pd();
			const __m256d max = _mm256_set1_pd(static_cast<double>(UINT8_MAX));
			__m256d ymm_a0, ymm_a1, ymm_a2, ymm_a3, ymm_a4, ymm_a5, ymm_a6, ymm_a7;
			__m256i ymm_b0, ymm_b1, ymm_b2, ymm_b3, ymm_b4, ymm_b5, ymm_b6, ymm_b7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				ymm_a0 = _mm256_loadu_pd(a);
				ymm_a1 = _mm256_loadu_pd(a + 4);
				ymm_a2 = _mm256_loadu_pd(a + 8);
				ymm_a3 = _mm256_loadu_pd(a + 12);
				ymm_a4 = _mm256_loadu_pd(a + 16);
				ymm_a5 = _mm256_loadu_pd(a + 20);
				ymm_a6 = _mm256_loadu_pd(a + 24);
				ymm_a7 = _mm256_loadu_pd(a + 28);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
				ymm_a0 = _mm256_max_pd(ymm_a0, min);
				ymm_a1 = _mm256_max_pd(ymm_a1, min);
				ymm_a2 = _mm256_max_pd(ymm_a2, min);
				ymm_a3 = _mm256_max_pd(ymm_a3, min);
				ymm_a4 = _mm256_max_pd(ymm_a4, min);
				ymm_a5 = _mm256_max_pd(ymm_a5, min);
				ymm_a6 = _mm256_max_pd(ymm_a6, min);
				ymm_a7 = _mm256_max_pd(ymm_a7, min);
				ymm_a0 = _mm256_min_pd(ymm_a0, max);
				ymm_a1 = _mm256_min_pd(ymm_a1, max);
				ymm_a2 = _mm256_min_pd(ymm_a2, max);
				ymm_a3 = _mm256_min_pd(ymm_a3, max);
				ymm_a4 = _mm256_min_pd(ymm_a4, max);
				ymm_a5 = _mm256_min_pd(ymm_a5, max);
				ymm_a6 = _mm256_min_pd(ymm_a6, max);
				ymm_a7 = _mm256_min_pd(ymm_a7, max);
				ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
				ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
				ymm_b2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a2));
				ymm_b3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a3));
				ymm_b4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a4));
				ymm_b5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a5));
				ymm_b6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a6));
				ymm_b7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a7));
				ymm_b0 = _mm256_packus_epi32(ymm_b0, ymm_b1);
				ymm_b2 = _mm256_packus_epi32(ymm_b2, ymm_b3);
				ymm_b4 = _mm256_packus_epi32(ymm_b4, ymm_b5);
				ymm_b6 = _mm256_packus_epi32(ymm_b6, ymm_b7);
				ymm_b0 = _mm256_packus_epi16(ymm_b0, ymm_b2);
				ymm_b4 = _mm256_packus_epi16(ymm_b4, ymm_b6);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, _mm256_castsi256_si128(ymm_b4));
				a += 32;
				b += 32;
			}
		}

		template <>
		void cvtspd_avx2_medium<signed short>(signed short* b, const double* a, size_t n)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT16_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT16_MAX));
			__m256d ymm_a0, ymm_a1, ymm_a2, ymm_a3, ymm_a4, ymm_a5, ymm_a6, ymm_a7;
			__m256i ymm_b0, ymm_b1, ymm_b2, ymm_b3, ymm_b4, ymm_b5, ymm_b6, ymm_b7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				ymm_a0 = _mm256_loadu_pd(a);
				ymm_a1 = _mm256_loadu_pd(a + 4);
				ymm_a2 = _mm256_loadu_pd(a + 8);
				ymm_a3 = _mm256_loadu_pd(a + 12);
				ymm_a4 = _mm256_loadu_pd(a + 16);
				ymm_a5 = _mm256_loadu_pd(a + 20);
				ymm_a6 = _mm256_loadu_pd(a + 24);
				ymm_a7 = _mm256_loadu_pd(a + 28);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
				ymm_a0 = _mm256_max_pd(ymm_a0, min);
				ymm_a1 = _mm256_max_pd(ymm_a1, min);
				ymm_a2 = _mm256_max_pd(ymm_a2, min);
				ymm_a3 = _mm256_max_pd(ymm_a3, min);
				ymm_a4 = _mm256_max_pd(ymm_a4, min);
				ymm_a5 = _mm256_max_pd(ymm_a5, min);
				ymm_a6 = _mm256_max_pd(ymm_a6, min);
				ymm_a7 = _mm256_max_pd(ymm_a7, min);
				ymm_a0 = _mm256_min_pd(ymm_a0, max);
				ymm_a1 = _mm256_min_pd(ymm_a1, max);
				ymm_a2 = _mm256_min_pd(ymm_a2, max);
				ymm_a3 = _mm256_min_pd(ymm_a3, max);
				ymm_a4 = _mm256_min_pd(ymm_a4, max);
				ymm_a5 = _mm256_min_pd(ymm_a5, max);
				ymm_a6 = _mm256_min_pd(ymm_a6, max);
				ymm_a7 = _mm256_min_pd(ymm_a7, max);
				ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
				ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
				ymm_b2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a2));
				ymm_b3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a3));
				ymm_b4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a4));
				ymm_b5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a5));
				ymm_b6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a6));
				ymm_b7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a7));
				ymm_b0 = _mm256_packs_epi32(ymm_b0, ymm_b1);
				ymm_b2 = _mm256_packs_epi32(ymm_b2, ymm_b3);
				ymm_b4 = _mm256_packs_epi32(ymm_b4, ymm_b5);
				ymm_b6 = _mm256_packs_epi32(ymm_b6, ymm_b7);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, _mm256_castsi256_si128(ymm_b2));
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 2, _mm256_castsi256_si128(ymm_b4));
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 3, _mm256_castsi256_si128(ymm_b6));
				a += 32;
				b += 32;
			}
		}

		template <>
		void cvtspd_avx2_medium<unsigned short>(unsigned short* b, const double* a, size_t n)
		{
			const __m256d min = _mm256_setzero_pd();
			const __m256d max = _mm256_set1_pd(static_cast<double>(UINT16_MAX));
			__m256d ymm_a0, ymm_a1, ymm_a2, ymm_a3, ymm_a4, ymm_a5, ymm_a6, ymm_a7;
			__m256i ymm_b0, ymm_b1, ymm_b2, ymm_b3, ymm_b4, ymm_b5, ymm_b6, ymm_b7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				ymm_a0 = _mm256_loadu_pd(a);
				ymm_a1 = _mm256_loadu_pd(a + 4);
				ymm_a2 = _mm256_loadu_pd(a + 8);
				ymm_a3 = _mm256_loadu_pd(a + 12);
				ymm_a4 = _mm256_loadu_pd(a + 16);
				ymm_a5 = _mm256_loadu_pd(a + 20);
				ymm_a6 = _mm256_loadu_pd(a + 24);
				ymm_a7 = _mm256_loadu_pd(a + 28);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
				ymm_a0 = _mm256_max_pd(ymm_a0, min);
				ymm_a1 = _mm256_max_pd(ymm_a1, min);
				ymm_a2 = _mm256_max_pd(ymm_a2, min);
				ymm_a3 = _mm256_max_pd(ymm_a3, min);
				ymm_a4 = _mm256_max_pd(ymm_a4, min);
				ymm_a5 = _mm256_max_pd(ymm_a5, min);
				ymm_a6 = _mm256_max_pd(ymm_a6, min);
				ymm_a7 = _mm256_max_pd(ymm_a7, min);
				ymm_a0 = _mm256_min_pd(ymm_a0, max);
				ymm_a1 = _mm256_min_pd(ymm_a1, max);
				ymm_a2 = _mm256_min_pd(ymm_a2, max);
				ymm_a3 = _mm256_min_pd(ymm_a3, max);
				ymm_a4 = _mm256_min_pd(ymm_a4, max);
				ymm_a5 = _mm256_min_pd(ymm_a5, max);
				ymm_a6 = _mm256_min_pd(ymm_a6, max);
				ymm_a7 = _mm256_min_pd(ymm_a7, max);
				ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
				ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
				ymm_b2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a2));
				ymm_b3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a3));
				ymm_b4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a4));
				ymm_b5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a5));
				ymm_b6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a6));
				ymm_b7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a7));
				ymm_b0 = _mm256_packus_epi32(ymm_b0, ymm_b1);
				ymm_b2 = _mm256_packus_epi32(ymm_b2, ymm_b3);
				ymm_b4 = _mm256_packus_epi32(ymm_b4, ymm_b5);
				ymm_b6 = _mm256_packus_epi32(ymm_b6, ymm_b7);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, _mm256_castsi256_si128(ymm_b2));
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 2, _mm256_castsi256_si128(ymm_b4));
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 3, _mm256_castsi256_si128(ymm_b6));
				a += 32;
				b += 32;
			}
		}

		template <>
		void cvtspd_avx2_medium<signed int>(signed int* b, const double* a, size_t n)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT32_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT32_MAX));
			__m256d ymm_a0, ymm_a1, ymm_a2, ymm_a3, ymm_a4, ymm_a5, ymm_a6, ymm_a7;
			__m128i xmm_b0, xmm_b1, xmm_b2, xmm_b3, xmm_b4, xmm_b5, xmm_b6, xmm_b7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				ymm_a0 = _mm256_loadu_pd(a);
				ymm_a1 = _mm256_loadu_pd(a + 4);
				ymm_a2 = _mm256_loadu_pd(a + 8);
				ymm_a3 = _mm256_loadu_pd(a + 12);
				ymm_a4 = _mm256_loadu_pd(a + 16);
				ymm_a5 = _mm256_loadu_pd(a + 20);
				ymm_a6 = _mm256_loadu_pd(a + 24);
				ymm_a7 = _mm256_loadu_pd(a + 28);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
				ymm_a0 = _mm256_max_pd(ymm_a0, min);
				ymm_a1 = _mm256_max_pd(ymm_a1, min);
				ymm_a2 = _mm256_max_pd(ymm_a2, min);
				ymm_a3 = _mm256_max_pd(ymm_a3, min);
				ymm_a4 = _mm256_max_pd(ymm_a4, min);
				ymm_a5 = _mm256_max_pd(ymm_a5, min);
				ymm_a6 = _mm256_max_pd(ymm_a6, min);
				ymm_a7 = _mm256_max_pd(ymm_a7, min);
				ymm_a0 = _mm256_min_pd(ymm_a0, max);
				ymm_a1 = _mm256_min_pd(ymm_a1, max);
				ymm_a2 = _mm256_min_pd(ymm_a2, max);
				ymm_a3 = _mm256_min_pd(ymm_a3, max);
				ymm_a4 = _mm256_min_pd(ymm_a4, max);
				ymm_a5 = _mm256_min_pd(ymm_a5, max);
				ymm_a6 = _mm256_min_pd(ymm_a6, max);
				ymm_a7 = _mm256_min_pd(ymm_a7, max);
				xmm_b0 = _mm256_cvttpd_epi32(ymm_a0);
				xmm_b1 = _mm256_cvttpd_epi32(ymm_a1);
				xmm_b2 = _mm256_cvttpd_epi32(ymm_a2);
				xmm_b3 = _mm256_cvttpd_epi32(ymm_a3);
				xmm_b4 = _mm256_cvttpd_epi32(ymm_a4);
				xmm_b5 = _mm256_cvttpd_epi32(ymm_a5);
				xmm_b6 = _mm256_cvttpd_epi32(ymm_a6);
				xmm_b7 = _mm256_cvttpd_epi32(ymm_a7);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b1);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 2, xmm_b2);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 3, xmm_b3);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 4, xmm_b4);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 5, xmm_b5);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 6, xmm_b6);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 7, xmm_b7);
				a += 32;
				b += 32;
			}
		}

		template <>
		void cvtspd_avx2_medium<unsigned int>(unsigned int* b, const double* a, size_t n)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT32_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT32_MAX));
			const __m256d offset = _mm256_set1_pd(2.147483648e+9);
			const __m256i shift = _mm256_set1_epi32(2147483648);
			__m256d ymm_a0, ymm_a1, ymm_a2, ymm_a3, ymm_a4, ymm_a5, ymm_a6, ymm_a7;
			__m256i ymm_b0, ymm_b1, ymm_b2, ymm_b3, ymm_b4, ymm_b5, ymm_b6, ymm_b7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				ymm_a0 = _mm256_loadu_pd(a);
				ymm_a1 = _mm256_loadu_pd(a + 4);
				ymm_a2 = _mm256_loadu_pd(a + 8);
				ymm_a3 = _mm256_loadu_pd(a + 12);
				ymm_a4 = _mm256_loadu_pd(a + 16);
				ymm_a5 = _mm256_loadu_pd(a + 20);
				ymm_a6 = _mm256_loadu_pd(a + 24);
				ymm_a7 = _mm256_loadu_pd(a + 28);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
				ymm_a0 = _mm256_sub_pd(ymm_a0, offset);
				ymm_a1 = _mm256_sub_pd(ymm_a1, offset);
				ymm_a2 = _mm256_sub_pd(ymm_a2, offset);
				ymm_a3 = _mm256_sub_pd(ymm_a3, offset);
				ymm_a4 = _mm256_sub_pd(ymm_a4, offset);
				ymm_a5 = _mm256_sub_pd(ymm_a5, offset);
				ymm_a6 = _mm256_sub_pd(ymm_a6, offset);
				ymm_a7 = _mm256_sub_pd(ymm_a7, offset);
				ymm_a0 = _mm256_max_pd(ymm_a0, min);
				ymm_a1 = _mm256_max_pd(ymm_a1, min);
				ymm_a2 = _mm256_max_pd(ymm_a2, min);
				ymm_a3 = _mm256_max_pd(ymm_a3, min);
				ymm_a4 = _mm256_max_pd(ymm_a4, min);
				ymm_a5 = _mm256_max_pd(ymm_a5, min);
				ymm_a6 = _mm256_max_pd(ymm_a6, min);
				ymm_a7 = _mm256_max_pd(ymm_a7, min);
				ymm_a0 = _mm256_min_pd(ymm_a0, max);
				ymm_a1 = _mm256_min_pd(ymm_a1, max);
				ymm_a2 = _mm256_min_pd(ymm_a2, max);
				ymm_a3 = _mm256_min_pd(ymm_a3, max);
				ymm_a4 = _mm256_min_pd(ymm_a4, max);
				ymm_a5 = _mm256_min_pd(ymm_a5, max);
				ymm_a6 = _mm256_min_pd(ymm_a6, max);
				ymm_a7 = _mm256_min_pd(ymm_a7, max);
				ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
				ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
				ymm_b2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a2));
				ymm_b3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a3));
				ymm_b4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a4));
				ymm_b5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a5));
				ymm_b6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a6));
				ymm_b7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a7));
				ymm_b0 = _mm256_add_epi32(ymm_b0, shift);
				ymm_b1 = _mm256_add_epi32(ymm_b1, shift);
				ymm_b2 = _mm256_add_epi32(ymm_b2, shift);
				ymm_b3 = _mm256_add_epi32(ymm_b3, shift);
				ymm_b4 = _mm256_add_epi32(ymm_b4, shift);
				ymm_b5 = _mm256_add_epi32(ymm_b5, shift);
				ymm_b6 = _mm256_add_epi32(ymm_b6, shift);
				ymm_b7 = _mm256_add_epi32(ymm_b7, shift);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, _mm256_castsi256_si128(ymm_b1));
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 2, _mm256_castsi256_si128(ymm_b2));
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 3, _mm256_castsi256_si128(ymm_b3));
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 4, _mm256_castsi256_si128(ymm_b4));
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 5, _mm256_castsi256_si128(ymm_b5));
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 6, _mm256_castsi256_si128(ymm_b6));
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 7, _mm256_castsi256_si128(ymm_b7));
				a += 32;
				b += 32;
			}
		}

		template <>
		void cvtspd_avx2_medium<float>(float* b, const double* a, size_t n)
		{
			const __m256d min = _mm256_set1_pd(static_cast<double>(-FLT_MAX));
			const __m256d max = _mm256_set1_pd(static_cast<double>(FLT_MAX));
			__m256d ymm_a0, ymm_a1, ymm_a2, ymm_a3, ymm_a4, ymm_a5, ymm_a6, ymm_a7;
			__m128 xmm_b0, xmm_b1, xmm_b2, xmm_b3, xmm_b4, xmm_b5, xmm_b6, xmm_b7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				ymm_a0 = _mm256_loadu_pd(a);
				ymm_a1 = _mm256_loadu_pd(a + 4);
				ymm_a2 = _mm256_loadu_pd(a + 8);
				ymm_a3 = _mm256_loadu_pd(a + 12);
				ymm_a4 = _mm256_loadu_pd(a + 16);
				ymm_a5 = _mm256_loadu_pd(a + 20);
				ymm_a6 = _mm256_loadu_pd(a + 24);
				ymm_a7 = _mm256_loadu_pd(a + 28);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
				ymm_a0 = _mm256_max_pd(ymm_a0, min);
				ymm_a1 = _mm256_max_pd(ymm_a1, min);
				ymm_a2 = _mm256_max_pd(ymm_a2, min);
				ymm_a3 = _mm256_max_pd(ymm_a3, min);
				ymm_a4 = _mm256_max_pd(ymm_a4, min);
				ymm_a5 = _mm256_max_pd(ymm_a5, min);
				ymm_a6 = _mm256_max_pd(ymm_a6, min);
				ymm_a7 = _mm256_max_pd(ymm_a7, min);
				ymm_a0 = _mm256_min_pd(ymm_a0, max);
				ymm_a1 = _mm256_min_pd(ymm_a1, max);
				ymm_a2 = _mm256_min_pd(ymm_a2, max);
				ymm_a3 = _mm256_min_pd(ymm_a3, max);
				ymm_a4 = _mm256_min_pd(ymm_a4, max);
				ymm_a5 = _mm256_min_pd(ymm_a5, max);
				ymm_a6 = _mm256_min_pd(ymm_a6, max);
				ymm_a7 = _mm256_min_pd(ymm_a7, max);
				xmm_b0 = _mm256_cvtpd_ps(ymm_a0);
				xmm_b1 = _mm256_cvtpd_ps(ymm_a1);
				xmm_b2 = _mm256_cvtpd_ps(ymm_a2);
				xmm_b3 = _mm256_cvtpd_ps(ymm_a3);
				xmm_b4 = _mm256_cvtpd_ps(ymm_a4);
				xmm_b5 = _mm256_cvtpd_ps(ymm_a5);
				xmm_b6 = _mm256_cvtpd_ps(ymm_a6);
				xmm_b7 = _mm256_cvtpd_ps(ymm_a7);
				_mm_storeu_ps(b, xmm_b0);
				_mm_storeu_ps(b + 4, xmm_b1);
				_mm_storeu_ps(b + 8, xmm_b2);
				_mm_storeu_ps(b + 12, xmm_b3);
				_mm_storeu_ps(b + 16, xmm_b4);
				_mm_storeu_ps(b + 20, xmm_b5);
				_mm_storeu_ps(b + 24, xmm_b6);
				_mm_storeu_ps(b + 28, xmm_b7);
				a += 32;
				b += 32;
			}
		}

		// Function template cvtspd_avx2_large

		template <class T>
		inline void cvtspd_avx2_large(T* b, const double* a, size_t n)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		inline void cvtspd_avx2_large<signed char>(signed char* b, const double* a, size_t n)
		{
			const size_t padding = 16 - (reinterpret_cast<size_t>(b) & 15);
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT8_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT8_MAX));
			__m256d ymm_a0, ymm_a1, ymm_a2, ymm_a3, ymm_a4, ymm_a5, ymm_a6, ymm_a7;
			__m256i ymm_b0, ymm_b1, ymm_b2, ymm_b3, ymm_b4, ymm_b5, ymm_b6, ymm_b7;

			// Align the destination to a 16-byte boundary.
			ymm_a0 = _mm256_loadu_pd(a);
			ymm_a1 = _mm256_loadu_pd(a + 4);
			ymm_a2 = _mm256_loadu_pd(a + 8);
			ymm_a3 = _mm256_loadu_pd(a + 12);
			ymm_a0 = _mm256_max_pd(ymm_a0, min);
			ymm_a1 = _mm256_max_pd(ymm_a1, min);
			ymm_a2 = _mm256_max_pd(ymm_a2, min);
			ymm_a3 = _mm256_max_pd(ymm_a3, min);
			ymm_a0 = _mm256_min_pd(ymm_a0, max);
			ymm_a1 = _mm256_min_pd(ymm_a1, max);
			ymm_a2 = _mm256_min_pd(ymm_a2, max);
			ymm_a3 = _mm256_min_pd(ymm_a3, max);
			ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
			ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
			ymm_b2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a2));
			ymm_b3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a3));
			ymm_b0 = _mm256_packs_epi32(ymm_b0, ymm_b1);
			ymm_b2 = _mm256_packs_epi32(ymm_b2, ymm_b3);
			ymm_b0 = _mm256_packs_epi16(ymm_b0, ymm_b2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
			b += padding;
			a += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			// If the source is aligned on a 32-byte boundary.
			if ((reinterpret_cast<size_t>(a) & 31) == 0)
			{
				for (; n >= 32; n -= 32)
				{
					ymm_a0 = _mm256_load_pd(a);
					ymm_a1 = _mm256_load_pd(a + 4);
					ymm_a2 = _mm256_load_pd(a + 8);
					ymm_a3 = _mm256_load_pd(a + 12);
					ymm_a4 = _mm256_load_pd(a + 16);
					ymm_a5 = _mm256_load_pd(a + 20);
					ymm_a6 = _mm256_load_pd(a + 24);
					ymm_a7 = _mm256_load_pd(a + 28);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
					ymm_a0 = _mm256_max_pd(ymm_a0, min);
					ymm_a1 = _mm256_max_pd(ymm_a1, min);
					ymm_a2 = _mm256_max_pd(ymm_a2, min);
					ymm_a3 = _mm256_max_pd(ymm_a3, min);
					ymm_a4 = _mm256_max_pd(ymm_a4, min);
					ymm_a5 = _mm256_max_pd(ymm_a5, min);
					ymm_a6 = _mm256_max_pd(ymm_a6, min);
					ymm_a7 = _mm256_max_pd(ymm_a7, min);
					ymm_a0 = _mm256_min_pd(ymm_a0, max);
					ymm_a1 = _mm256_min_pd(ymm_a1, max);
					ymm_a2 = _mm256_min_pd(ymm_a2, max);
					ymm_a3 = _mm256_min_pd(ymm_a3, max);
					ymm_a4 = _mm256_min_pd(ymm_a4, max);
					ymm_a5 = _mm256_min_pd(ymm_a5, max);
					ymm_a6 = _mm256_min_pd(ymm_a6, max);
					ymm_a7 = _mm256_min_pd(ymm_a7, max);
					ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
					ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
					ymm_b2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a2));
					ymm_b3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a3));
					ymm_b4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a4));
					ymm_b5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a5));
					ymm_b6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a6));
					ymm_b7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a7));
					ymm_b0 = _mm256_packs_epi32(ymm_b0, ymm_b1);
					ymm_b2 = _mm256_packs_epi32(ymm_b2, ymm_b3);
					ymm_b4 = _mm256_packs_epi32(ymm_b4, ymm_b5);
					ymm_b6 = _mm256_packs_epi32(ymm_b6, ymm_b7);
					ymm_b0 = _mm256_packs_epi16(ymm_b0, ymm_b2);
					ymm_b4 = _mm256_packs_epi16(ymm_b4, ymm_b6);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 1, _mm256_castsi256_si128(ymm_b4));
					a += 32;
					b += 32;
				}
			}
			else
			{
				for (; n >= 32; n -= 32)
				{
					ymm_a0 = _mm256_loadu_pd(a);
					ymm_a1 = _mm256_loadu_pd(a + 4);
					ymm_a2 = _mm256_loadu_pd(a + 8);
					ymm_a3 = _mm256_loadu_pd(a + 12);
					ymm_a4 = _mm256_loadu_pd(a + 16);
					ymm_a5 = _mm256_loadu_pd(a + 20);
					ymm_a6 = _mm256_loadu_pd(a + 24);
					ymm_a7 = _mm256_loadu_pd(a + 28);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
					ymm_a0 = _mm256_max_pd(ymm_a0, min);
					ymm_a1 = _mm256_max_pd(ymm_a1, min);
					ymm_a2 = _mm256_max_pd(ymm_a2, min);
					ymm_a3 = _mm256_max_pd(ymm_a3, min);
					ymm_a4 = _mm256_max_pd(ymm_a4, min);
					ymm_a5 = _mm256_max_pd(ymm_a5, min);
					ymm_a6 = _mm256_max_pd(ymm_a6, min);
					ymm_a7 = _mm256_max_pd(ymm_a7, min);
					ymm_a0 = _mm256_min_pd(ymm_a0, max);
					ymm_a1 = _mm256_min_pd(ymm_a1, max);
					ymm_a2 = _mm256_min_pd(ymm_a2, max);
					ymm_a3 = _mm256_min_pd(ymm_a3, max);
					ymm_a4 = _mm256_min_pd(ymm_a4, max);
					ymm_a5 = _mm256_min_pd(ymm_a5, max);
					ymm_a6 = _mm256_min_pd(ymm_a6, max);
					ymm_a7 = _mm256_min_pd(ymm_a7, max);
					ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
					ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
					ymm_b2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a2));
					ymm_b3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a3));
					ymm_b4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a4));
					ymm_b5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a5));
					ymm_b6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a6));
					ymm_b7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a7));
					ymm_b0 = _mm256_packs_epi32(ymm_b0, ymm_b1);
					ymm_b2 = _mm256_packs_epi32(ymm_b2, ymm_b3);
					ymm_b4 = _mm256_packs_epi32(ymm_b4, ymm_b5);
					ymm_b6 = _mm256_packs_epi32(ymm_b6, ymm_b7);
					ymm_b0 = _mm256_packs_epi16(ymm_b0, ymm_b2);
					ymm_b4 = _mm256_packs_epi16(ymm_b4, ymm_b6);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 1, _mm256_castsi256_si128(ymm_b4));
					a += 32;
					b += 32;
				}
			}
		}

		template <>
		inline void cvtspd_avx2_large<unsigned char>(unsigned char* b, const double* a, size_t n)
		{
			const size_t padding = 16 - (reinterpret_cast<size_t>(b) & 15);
			const __m256d min = _mm256_setzero_pd();
			const __m256d max = _mm256_set1_pd(static_cast<double>(UINT8_MAX));
			__m256d ymm_a0, ymm_a1, ymm_a2, ymm_a3, ymm_a4, ymm_a5, ymm_a6, ymm_a7;
			__m256i ymm_b0, ymm_b1, ymm_b2, ymm_b3, ymm_b4, ymm_b5, ymm_b6, ymm_b7;

			// Align the destination to a 16-byte boundary.
			ymm_a0 = _mm256_loadu_pd(a);
			ymm_a1 = _mm256_loadu_pd(a + 4);
			ymm_a2 = _mm256_loadu_pd(a + 8);
			ymm_a3 = _mm256_loadu_pd(a + 12);
			ymm_a0 = _mm256_max_pd(ymm_a0, min);
			ymm_a1 = _mm256_max_pd(ymm_a1, min);
			ymm_a2 = _mm256_max_pd(ymm_a2, min);
			ymm_a3 = _mm256_max_pd(ymm_a3, min);
			ymm_a0 = _mm256_min_pd(ymm_a0, max);
			ymm_a1 = _mm256_min_pd(ymm_a1, max);
			ymm_a2 = _mm256_min_pd(ymm_a2, max);
			ymm_a3 = _mm256_min_pd(ymm_a3, max);
			ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
			ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
			ymm_b2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a2));
			ymm_b3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a3));
			ymm_b0 = _mm256_packus_epi32(ymm_b0, ymm_b1);
			ymm_b2 = _mm256_packus_epi32(ymm_b2, ymm_b3);
			ymm_b0 = _mm256_packus_epi16(ymm_b0, ymm_b2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
			b += padding;
			a += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			// If the source is aligned on a 32-byte boundary.
			if ((reinterpret_cast<size_t>(a) & 31) == 0)
			{
				for (; n >= 32; n -= 32)
				{
					ymm_a0 = _mm256_load_pd(a);
					ymm_a1 = _mm256_load_pd(a + 4);
					ymm_a2 = _mm256_load_pd(a + 8);
					ymm_a3 = _mm256_load_pd(a + 12);
					ymm_a4 = _mm256_load_pd(a + 16);
					ymm_a5 = _mm256_load_pd(a + 20);
					ymm_a6 = _mm256_load_pd(a + 24);
					ymm_a7 = _mm256_load_pd(a + 28);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
					ymm_a0 = _mm256_max_pd(ymm_a0, min);
					ymm_a1 = _mm256_max_pd(ymm_a1, min);
					ymm_a2 = _mm256_max_pd(ymm_a2, min);
					ymm_a3 = _mm256_max_pd(ymm_a3, min);
					ymm_a4 = _mm256_max_pd(ymm_a4, min);
					ymm_a5 = _mm256_max_pd(ymm_a5, min);
					ymm_a6 = _mm256_max_pd(ymm_a6, min);
					ymm_a7 = _mm256_max_pd(ymm_a7, min);
					ymm_a0 = _mm256_min_pd(ymm_a0, max);
					ymm_a1 = _mm256_min_pd(ymm_a1, max);
					ymm_a2 = _mm256_min_pd(ymm_a2, max);
					ymm_a3 = _mm256_min_pd(ymm_a3, max);
					ymm_a4 = _mm256_min_pd(ymm_a4, max);
					ymm_a5 = _mm256_min_pd(ymm_a5, max);
					ymm_a6 = _mm256_min_pd(ymm_a6, max);
					ymm_a7 = _mm256_min_pd(ymm_a7, max);
					ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
					ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
					ymm_b2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a2));
					ymm_b3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a3));
					ymm_b4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a4));
					ymm_b5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a5));
					ymm_b6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a6));
					ymm_b7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a7));
					ymm_b0 = _mm256_packus_epi32(ymm_b0, ymm_b1);
					ymm_b2 = _mm256_packus_epi32(ymm_b2, ymm_b3);
					ymm_b4 = _mm256_packus_epi32(ymm_b4, ymm_b5);
					ymm_b6 = _mm256_packus_epi32(ymm_b6, ymm_b7);
					ymm_b0 = _mm256_packus_epi16(ymm_b0, ymm_b2);
					ymm_b4 = _mm256_packus_epi16(ymm_b4, ymm_b6);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 1, _mm256_castsi256_si128(ymm_b4));
					a += 32;
					b += 32;
				}
			}
			else
			{
				for (; n >= 32; n -= 32)
				{
					ymm_a0 = _mm256_loadu_pd(a);
					ymm_a1 = _mm256_loadu_pd(a + 4);
					ymm_a2 = _mm256_loadu_pd(a + 8);
					ymm_a3 = _mm256_loadu_pd(a + 12);
					ymm_a4 = _mm256_loadu_pd(a + 16);
					ymm_a5 = _mm256_loadu_pd(a + 20);
					ymm_a6 = _mm256_loadu_pd(a + 24);
					ymm_a7 = _mm256_loadu_pd(a + 28);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
					ymm_a0 = _mm256_max_pd(ymm_a0, min);
					ymm_a1 = _mm256_max_pd(ymm_a1, min);
					ymm_a2 = _mm256_max_pd(ymm_a2, min);
					ymm_a3 = _mm256_max_pd(ymm_a3, min);
					ymm_a4 = _mm256_max_pd(ymm_a4, min);
					ymm_a5 = _mm256_max_pd(ymm_a5, min);
					ymm_a6 = _mm256_max_pd(ymm_a6, min);
					ymm_a7 = _mm256_max_pd(ymm_a7, min);
					ymm_a0 = _mm256_min_pd(ymm_a0, max);
					ymm_a1 = _mm256_min_pd(ymm_a1, max);
					ymm_a2 = _mm256_min_pd(ymm_a2, max);
					ymm_a3 = _mm256_min_pd(ymm_a3, max);
					ymm_a4 = _mm256_min_pd(ymm_a4, max);
					ymm_a5 = _mm256_min_pd(ymm_a5, max);
					ymm_a6 = _mm256_min_pd(ymm_a6, max);
					ymm_a7 = _mm256_min_pd(ymm_a7, max);
					ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
					ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
					ymm_b2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a2));
					ymm_b3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a3));
					ymm_b4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a4));
					ymm_b5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a5));
					ymm_b6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a6));
					ymm_b7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a7));
					ymm_b0 = _mm256_packus_epi32(ymm_b0, ymm_b1);
					ymm_b2 = _mm256_packus_epi32(ymm_b2, ymm_b3);
					ymm_b4 = _mm256_packus_epi32(ymm_b4, ymm_b5);
					ymm_b6 = _mm256_packus_epi32(ymm_b6, ymm_b7);
					ymm_b0 = _mm256_packus_epi16(ymm_b0, ymm_b2);
					ymm_b4 = _mm256_packus_epi16(ymm_b4, ymm_b6);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 1, _mm256_castsi256_si128(ymm_b4));
					a += 32;
					b += 32;
				}
			}
		}

		template <>
		inline void cvtspd_avx2_large<signed short>(signed short* b, const double* a, size_t n)
		{
			const size_t padding = 8 - (reinterpret_cast<size_t>(b) & 7);
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT16_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT16_MAX));
			__m256d ymm_a0, ymm_a1, ymm_a2, ymm_a3, ymm_a4, ymm_a5, ymm_a6, ymm_a7;
			__m256i ymm_b0, ymm_b1, ymm_b2, ymm_b3, ymm_b4, ymm_b5, ymm_b6, ymm_b7;

			// Align the destination to a 16-byte boundary.
			ymm_a0 = _mm256_loadu_pd(a);
			ymm_a1 = _mm256_loadu_pd(a + 4);
			ymm_a0 = _mm256_max_pd(ymm_a0, min);
			ymm_a1 = _mm256_max_pd(ymm_a1, min);
			ymm_a0 = _mm256_min_pd(ymm_a0, max);
			ymm_a1 = _mm256_min_pd(ymm_a1, max);
			ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
			ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
			ymm_b0 = _mm256_packs_epi32(ymm_b0, ymm_b1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
			b += padding;
			a += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			// If the source is aligned on a 32-byte boundary.
			if ((reinterpret_cast<size_t>(a) & 31) == 0)
			{
				for (; n >= 32; n -= 32)
				{
					ymm_a0 = _mm256_load_pd(a);
					ymm_a1 = _mm256_load_pd(a + 4);
					ymm_a2 = _mm256_load_pd(a + 8);
					ymm_a3 = _mm256_load_pd(a + 12);
					ymm_a4 = _mm256_load_pd(a + 16);
					ymm_a5 = _mm256_load_pd(a + 20);
					ymm_a6 = _mm256_load_pd(a + 24);
					ymm_a7 = _mm256_load_pd(a + 28);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
					ymm_a0 = _mm256_max_pd(ymm_a0, min);
					ymm_a1 = _mm256_max_pd(ymm_a1, min);
					ymm_a2 = _mm256_max_pd(ymm_a2, min);
					ymm_a3 = _mm256_max_pd(ymm_a3, min);
					ymm_a4 = _mm256_max_pd(ymm_a4, min);
					ymm_a5 = _mm256_max_pd(ymm_a5, min);
					ymm_a6 = _mm256_max_pd(ymm_a6, min);
					ymm_a7 = _mm256_max_pd(ymm_a7, min);
					ymm_a0 = _mm256_min_pd(ymm_a0, max);
					ymm_a1 = _mm256_min_pd(ymm_a1, max);
					ymm_a2 = _mm256_min_pd(ymm_a2, max);
					ymm_a3 = _mm256_min_pd(ymm_a3, max);
					ymm_a4 = _mm256_min_pd(ymm_a4, max);
					ymm_a5 = _mm256_min_pd(ymm_a5, max);
					ymm_a6 = _mm256_min_pd(ymm_a6, max);
					ymm_a7 = _mm256_min_pd(ymm_a7, max);
					ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
					ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
					ymm_b2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a2));
					ymm_b3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a3));
					ymm_b4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a4));
					ymm_b5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a5));
					ymm_b6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a6));
					ymm_b7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a7));
					ymm_b0 = _mm256_packs_epi32(ymm_b0, ymm_b1);
					ymm_b2 = _mm256_packs_epi32(ymm_b2, ymm_b3);
					ymm_b4 = _mm256_packs_epi32(ymm_b4, ymm_b5);
					ymm_b6 = _mm256_packs_epi32(ymm_b6, ymm_b7);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 1, _mm256_castsi256_si128(ymm_b2));
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 2, _mm256_castsi256_si128(ymm_b4));
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 3, _mm256_castsi256_si128(ymm_b6));
					a += 32;
					b += 32;
				}
			}
			else
			{
				for (; n >= 32; n -= 32)
				{
					ymm_a0 = _mm256_loadu_pd(a);
					ymm_a1 = _mm256_loadu_pd(a + 4);
					ymm_a2 = _mm256_loadu_pd(a + 8);
					ymm_a3 = _mm256_loadu_pd(a + 12);
					ymm_a4 = _mm256_loadu_pd(a + 16);
					ymm_a5 = _mm256_loadu_pd(a + 20);
					ymm_a6 = _mm256_loadu_pd(a + 24);
					ymm_a7 = _mm256_loadu_pd(a + 28);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
					ymm_a0 = _mm256_max_pd(ymm_a0, min);
					ymm_a1 = _mm256_max_pd(ymm_a1, min);
					ymm_a2 = _mm256_max_pd(ymm_a2, min);
					ymm_a3 = _mm256_max_pd(ymm_a3, min);
					ymm_a4 = _mm256_max_pd(ymm_a4, min);
					ymm_a5 = _mm256_max_pd(ymm_a5, min);
					ymm_a6 = _mm256_max_pd(ymm_a6, min);
					ymm_a7 = _mm256_max_pd(ymm_a7, min);
					ymm_a0 = _mm256_min_pd(ymm_a0, max);
					ymm_a1 = _mm256_min_pd(ymm_a1, max);
					ymm_a2 = _mm256_min_pd(ymm_a2, max);
					ymm_a3 = _mm256_min_pd(ymm_a3, max);
					ymm_a4 = _mm256_min_pd(ymm_a4, max);
					ymm_a5 = _mm256_min_pd(ymm_a5, max);
					ymm_a6 = _mm256_min_pd(ymm_a6, max);
					ymm_a7 = _mm256_min_pd(ymm_a7, max);
					ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
					ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
					ymm_b2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a2));
					ymm_b3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a3));
					ymm_b4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a4));
					ymm_b5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a5));
					ymm_b6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a6));
					ymm_b7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a7));
					ymm_b0 = _mm256_packs_epi32(ymm_b0, ymm_b1);
					ymm_b2 = _mm256_packs_epi32(ymm_b2, ymm_b3);
					ymm_b4 = _mm256_packs_epi32(ymm_b4, ymm_b5);
					ymm_b6 = _mm256_packs_epi32(ymm_b6, ymm_b7);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 1, _mm256_castsi256_si128(ymm_b2));
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 2, _mm256_castsi256_si128(ymm_b4));
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 3, _mm256_castsi256_si128(ymm_b6));
					a += 32;
					b += 32;
				}
			}
		}

		template <>
		inline void cvtspd_avx2_large<unsigned short>(unsigned short* b, const double* a, size_t n)
		{
			const size_t padding = 8 - (reinterpret_cast<size_t>(b) & 7);
			const __m256d min = _mm256_setzero_pd();
			const __m256d max = _mm256_set1_pd(static_cast<double>(UINT16_MAX));
			__m256d ymm_a0, ymm_a1, ymm_a2, ymm_a3, ymm_a4, ymm_a5, ymm_a6, ymm_a7;
			__m256i ymm_b0, ymm_b1, ymm_b2, ymm_b3, ymm_b4, ymm_b5, ymm_b6, ymm_b7;

			// Align the destination to a 16-byte boundary.
			ymm_a0 = _mm256_loadu_pd(a);
			ymm_a1 = _mm256_loadu_pd(a + 4);
			ymm_a0 = _mm256_max_pd(ymm_a0, min);
			ymm_a1 = _mm256_max_pd(ymm_a1, min);
			ymm_a0 = _mm256_min_pd(ymm_a0, max);
			ymm_a1 = _mm256_min_pd(ymm_a1, max);
			ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
			ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
			ymm_b0 = _mm256_packus_epi32(ymm_b0, ymm_b1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
			b += padding;
			a += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			// If the source is aligned on a 32-byte boundary.
			if ((reinterpret_cast<size_t>(a) & 31) == 0)
			{
				for (; n >= 32; n -= 32)
				{
					ymm_a0 = _mm256_load_pd(a);
					ymm_a1 = _mm256_load_pd(a + 4);
					ymm_a2 = _mm256_load_pd(a + 8);
					ymm_a3 = _mm256_load_pd(a + 12);
					ymm_a4 = _mm256_load_pd(a + 16);
					ymm_a5 = _mm256_load_pd(a + 20);
					ymm_a6 = _mm256_load_pd(a + 24);
					ymm_a7 = _mm256_load_pd(a + 28);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
					ymm_a0 = _mm256_max_pd(ymm_a0, min);
					ymm_a1 = _mm256_max_pd(ymm_a1, min);
					ymm_a2 = _mm256_max_pd(ymm_a2, min);
					ymm_a3 = _mm256_max_pd(ymm_a3, min);
					ymm_a4 = _mm256_max_pd(ymm_a4, min);
					ymm_a5 = _mm256_max_pd(ymm_a5, min);
					ymm_a6 = _mm256_max_pd(ymm_a6, min);
					ymm_a7 = _mm256_max_pd(ymm_a7, min);
					ymm_a0 = _mm256_min_pd(ymm_a0, max);
					ymm_a1 = _mm256_min_pd(ymm_a1, max);
					ymm_a2 = _mm256_min_pd(ymm_a2, max);
					ymm_a3 = _mm256_min_pd(ymm_a3, max);
					ymm_a4 = _mm256_min_pd(ymm_a4, max);
					ymm_a5 = _mm256_min_pd(ymm_a5, max);
					ymm_a6 = _mm256_min_pd(ymm_a6, max);
					ymm_a7 = _mm256_min_pd(ymm_a7, max);
					ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
					ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
					ymm_b2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a2));
					ymm_b3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a3));
					ymm_b4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a4));
					ymm_b5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a5));
					ymm_b6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a6));
					ymm_b7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a7));
					ymm_b0 = _mm256_packus_epi32(ymm_b0, ymm_b1);
					ymm_b2 = _mm256_packus_epi32(ymm_b2, ymm_b3);
					ymm_b4 = _mm256_packus_epi32(ymm_b4, ymm_b5);
					ymm_b6 = _mm256_packus_epi32(ymm_b6, ymm_b7);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 1, _mm256_castsi256_si128(ymm_b2));
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 2, _mm256_castsi256_si128(ymm_b4));
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 3, _mm256_castsi256_si128(ymm_b6));
					a += 32;
					b += 32;
				}
			}
			else
			{
				for (; n >= 32; n -= 32)
				{
					ymm_a0 = _mm256_loadu_pd(a);
					ymm_a1 = _mm256_loadu_pd(a + 4);
					ymm_a2 = _mm256_loadu_pd(a + 8);
					ymm_a3 = _mm256_loadu_pd(a + 12);
					ymm_a4 = _mm256_loadu_pd(a + 16);
					ymm_a5 = _mm256_loadu_pd(a + 20);
					ymm_a6 = _mm256_loadu_pd(a + 24);
					ymm_a7 = _mm256_loadu_pd(a + 28);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
					ymm_a0 = _mm256_max_pd(ymm_a0, min);
					ymm_a1 = _mm256_max_pd(ymm_a1, min);
					ymm_a2 = _mm256_max_pd(ymm_a2, min);
					ymm_a3 = _mm256_max_pd(ymm_a3, min);
					ymm_a4 = _mm256_max_pd(ymm_a4, min);
					ymm_a5 = _mm256_max_pd(ymm_a5, min);
					ymm_a6 = _mm256_max_pd(ymm_a6, min);
					ymm_a7 = _mm256_max_pd(ymm_a7, min);
					ymm_a0 = _mm256_min_pd(ymm_a0, max);
					ymm_a1 = _mm256_min_pd(ymm_a1, max);
					ymm_a2 = _mm256_min_pd(ymm_a2, max);
					ymm_a3 = _mm256_min_pd(ymm_a3, max);
					ymm_a4 = _mm256_min_pd(ymm_a4, max);
					ymm_a5 = _mm256_min_pd(ymm_a5, max);
					ymm_a6 = _mm256_min_pd(ymm_a6, max);
					ymm_a7 = _mm256_min_pd(ymm_a7, max);
					ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
					ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
					ymm_b2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a2));
					ymm_b3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a3));
					ymm_b4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a4));
					ymm_b5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a5));
					ymm_b6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a6));
					ymm_b7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a7));
					ymm_b0 = _mm256_packus_epi32(ymm_b0, ymm_b1);
					ymm_b2 = _mm256_packus_epi32(ymm_b2, ymm_b3);
					ymm_b4 = _mm256_packus_epi32(ymm_b4, ymm_b5);
					ymm_b6 = _mm256_packus_epi32(ymm_b6, ymm_b7);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 1, _mm256_castsi256_si128(ymm_b2));
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 2, _mm256_castsi256_si128(ymm_b4));
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 3, _mm256_castsi256_si128(ymm_b6));
					a += 32;
					b += 32;
				}
			}
		}

		template <>
		inline void cvtspd_avx2_large<signed int>(signed int* b, const double* a, size_t n)
		{
			const size_t padding = 4 - (reinterpret_cast<size_t>(b) & 3);
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT32_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT32_MAX));
			__m256d ymm_a0, ymm_a1, ymm_a2, ymm_a3, ymm_a4, ymm_a5, ymm_a6, ymm_a7;
			__m128i xmm_b0, xmm_b1, xmm_b2, xmm_b3, xmm_b4, xmm_b5, xmm_b6, xmm_b7;

			// Align the destination to a 16-byte boundary.
			ymm_a0 = _mm256_loadu_pd(a);
			ymm_a0 = _mm256_max_pd(ymm_a0, min);
			ymm_a0 = _mm256_min_pd(ymm_a0, max);
			xmm_b0 = _mm256_cvttpd_epi32(ymm_a0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			b += padding;
			a += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			// If the source is aligned on a 32-byte boundary.
			if ((reinterpret_cast<size_t>(a) & 31) == 0)
			{
				for (; n >= 32; n -= 32)
				{
					ymm_a0 = _mm256_load_pd(a);
					ymm_a1 = _mm256_load_pd(a + 4);
					ymm_a2 = _mm256_load_pd(a + 8);
					ymm_a3 = _mm256_load_pd(a + 12);
					ymm_a4 = _mm256_load_pd(a + 16);
					ymm_a5 = _mm256_load_pd(a + 20);
					ymm_a6 = _mm256_load_pd(a + 24);
					ymm_a7 = _mm256_load_pd(a + 28);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
					ymm_a0 = _mm256_max_pd(ymm_a0, min);
					ymm_a1 = _mm256_max_pd(ymm_a1, min);
					ymm_a2 = _mm256_max_pd(ymm_a2, min);
					ymm_a3 = _mm256_max_pd(ymm_a3, min);
					ymm_a4 = _mm256_max_pd(ymm_a4, min);
					ymm_a5 = _mm256_max_pd(ymm_a5, min);
					ymm_a6 = _mm256_max_pd(ymm_a6, min);
					ymm_a7 = _mm256_max_pd(ymm_a7, min);
					ymm_a0 = _mm256_min_pd(ymm_a0, max);
					ymm_a1 = _mm256_min_pd(ymm_a1, max);
					ymm_a2 = _mm256_min_pd(ymm_a2, max);
					ymm_a3 = _mm256_min_pd(ymm_a3, max);
					ymm_a4 = _mm256_min_pd(ymm_a4, max);
					ymm_a5 = _mm256_min_pd(ymm_a5, max);
					ymm_a6 = _mm256_min_pd(ymm_a6, max);
					ymm_a7 = _mm256_min_pd(ymm_a7, max);
					xmm_b0 = _mm256_cvttpd_epi32(ymm_a0);
					xmm_b1 = _mm256_cvttpd_epi32(ymm_a1);
					xmm_b2 = _mm256_cvttpd_epi32(ymm_a2);
					xmm_b3 = _mm256_cvttpd_epi32(ymm_a3);
					xmm_b4 = _mm256_cvttpd_epi32(ymm_a4);
					xmm_b5 = _mm256_cvttpd_epi32(ymm_a5);
					xmm_b6 = _mm256_cvttpd_epi32(ymm_a6);
					xmm_b7 = _mm256_cvttpd_epi32(ymm_a7);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b1);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 2, xmm_b2);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 3, xmm_b3);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 4, xmm_b4);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 5, xmm_b5);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 6, xmm_b6);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 7, xmm_b7);
					a += 32;
					b += 32;
				}
			}
			else
			{
				for (; n >= 32; n -= 32)
				{
					ymm_a0 = _mm256_loadu_pd(a);
					ymm_a1 = _mm256_loadu_pd(a + 4);
					ymm_a2 = _mm256_loadu_pd(a + 8);
					ymm_a3 = _mm256_loadu_pd(a + 12);
					ymm_a4 = _mm256_loadu_pd(a + 16);
					ymm_a5 = _mm256_loadu_pd(a + 20);
					ymm_a6 = _mm256_loadu_pd(a + 24);
					ymm_a7 = _mm256_loadu_pd(a + 28);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
					ymm_a0 = _mm256_max_pd(ymm_a0, min);
					ymm_a1 = _mm256_max_pd(ymm_a1, min);
					ymm_a2 = _mm256_max_pd(ymm_a2, min);
					ymm_a3 = _mm256_max_pd(ymm_a3, min);
					ymm_a4 = _mm256_max_pd(ymm_a4, min);
					ymm_a5 = _mm256_max_pd(ymm_a5, min);
					ymm_a6 = _mm256_max_pd(ymm_a6, min);
					ymm_a7 = _mm256_max_pd(ymm_a7, min);
					ymm_a0 = _mm256_min_pd(ymm_a0, max);
					ymm_a1 = _mm256_min_pd(ymm_a1, max);
					ymm_a2 = _mm256_min_pd(ymm_a2, max);
					ymm_a3 = _mm256_min_pd(ymm_a3, max);
					ymm_a4 = _mm256_min_pd(ymm_a4, max);
					ymm_a5 = _mm256_min_pd(ymm_a5, max);
					ymm_a6 = _mm256_min_pd(ymm_a6, max);
					ymm_a7 = _mm256_min_pd(ymm_a7, max);
					xmm_b0 = _mm256_cvttpd_epi32(ymm_a0);
					xmm_b1 = _mm256_cvttpd_epi32(ymm_a1);
					xmm_b2 = _mm256_cvttpd_epi32(ymm_a2);
					xmm_b3 = _mm256_cvttpd_epi32(ymm_a3);
					xmm_b4 = _mm256_cvttpd_epi32(ymm_a4);
					xmm_b5 = _mm256_cvttpd_epi32(ymm_a5);
					xmm_b6 = _mm256_cvttpd_epi32(ymm_a6);
					xmm_b7 = _mm256_cvttpd_epi32(ymm_a7);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b1);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 2, xmm_b2);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 3, xmm_b3);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 4, xmm_b4);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 5, xmm_b5);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 6, xmm_b6);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 7, xmm_b7);
					a += 32;
					b += 32;
				}
			}
		}

		template <>
		inline void cvtspd_avx2_large<unsigned int>(unsigned int* b, const double* a, size_t n)
		{
			const size_t padding = 4 - (reinterpret_cast<size_t>(b) & 3);
			const __m256d min = _mm256_set1_pd(static_cast<double>(INT32_MIN));
			const __m256d max = _mm256_set1_pd(static_cast<double>(INT32_MAX));
			const __m256d offset = _mm256_set1_pd(2.147483648e+9);
			const __m256i shift = _mm256_set1_epi32(2147483648);
			__m256d ymm_a0, ymm_a1, ymm_a2, ymm_a3, ymm_a4, ymm_a5, ymm_a6, ymm_a7;
			__m256i ymm_b0, ymm_b1, ymm_b2, ymm_b3, ymm_b4, ymm_b5, ymm_b6, ymm_b7;

			// Align the destination to a 16-byte boundary.
			ymm_a0 = _mm256_loadu_pd(a);
			ymm_a0 = _mm256_sub_pd(ymm_a0, offset);
			ymm_a0 = _mm256_max_pd(ymm_a0, min);
			ymm_a0 = _mm256_min_pd(ymm_a0, max);
			ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
			ymm_b0 = _mm256_add_epi32(ymm_b0, shift);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
			b += padding;
			a += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			// If the source is aligned on a 32-byte boundary.
			if ((reinterpret_cast<size_t>(a) & 31) == 0)
			{
				for (; n >= 32; n -= 32)
				{
					ymm_a0 = _mm256_load_pd(a);
					ymm_a1 = _mm256_load_pd(a + 4);
					ymm_a2 = _mm256_load_pd(a + 8);
					ymm_a3 = _mm256_load_pd(a + 12);
					ymm_a4 = _mm256_load_pd(a + 16);
					ymm_a5 = _mm256_load_pd(a + 20);
					ymm_a6 = _mm256_load_pd(a + 24);
					ymm_a7 = _mm256_load_pd(a + 28);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
					ymm_a0 = _mm256_sub_pd(ymm_a0, offset);
					ymm_a1 = _mm256_sub_pd(ymm_a1, offset);
					ymm_a2 = _mm256_sub_pd(ymm_a2, offset);
					ymm_a3 = _mm256_sub_pd(ymm_a3, offset);
					ymm_a4 = _mm256_sub_pd(ymm_a4, offset);
					ymm_a5 = _mm256_sub_pd(ymm_a5, offset);
					ymm_a6 = _mm256_sub_pd(ymm_a6, offset);
					ymm_a7 = _mm256_sub_pd(ymm_a7, offset);
					ymm_a0 = _mm256_max_pd(ymm_a0, min);
					ymm_a1 = _mm256_max_pd(ymm_a1, min);
					ymm_a2 = _mm256_max_pd(ymm_a2, min);
					ymm_a3 = _mm256_max_pd(ymm_a3, min);
					ymm_a4 = _mm256_max_pd(ymm_a4, min);
					ymm_a5 = _mm256_max_pd(ymm_a5, min);
					ymm_a6 = _mm256_max_pd(ymm_a6, min);
					ymm_a7 = _mm256_max_pd(ymm_a7, min);
					ymm_a0 = _mm256_min_pd(ymm_a0, max);
					ymm_a1 = _mm256_min_pd(ymm_a1, max);
					ymm_a2 = _mm256_min_pd(ymm_a2, max);
					ymm_a3 = _mm256_min_pd(ymm_a3, max);
					ymm_a4 = _mm256_min_pd(ymm_a4, max);
					ymm_a5 = _mm256_min_pd(ymm_a5, max);
					ymm_a6 = _mm256_min_pd(ymm_a6, max);
					ymm_a7 = _mm256_min_pd(ymm_a7, max);
					ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
					ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
					ymm_b2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a2));
					ymm_b3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a3));
					ymm_b4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a4));
					ymm_b5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a5));
					ymm_b6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a6));
					ymm_b7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a7));
					ymm_b0 = _mm256_add_epi32(ymm_b0, shift);
					ymm_b1 = _mm256_add_epi32(ymm_b1, shift);
					ymm_b2 = _mm256_add_epi32(ymm_b2, shift);
					ymm_b3 = _mm256_add_epi32(ymm_b3, shift);
					ymm_b4 = _mm256_add_epi32(ymm_b4, shift);
					ymm_b5 = _mm256_add_epi32(ymm_b5, shift);
					ymm_b6 = _mm256_add_epi32(ymm_b6, shift);
					ymm_b7 = _mm256_add_epi32(ymm_b7, shift);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 1, _mm256_castsi256_si128(ymm_b1));
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 2, _mm256_castsi256_si128(ymm_b2));
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 3, _mm256_castsi256_si128(ymm_b3));
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 4, _mm256_castsi256_si128(ymm_b4));
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 5, _mm256_castsi256_si128(ymm_b5));
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 6, _mm256_castsi256_si128(ymm_b6));
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 7, _mm256_castsi256_si128(ymm_b7));
					a += 32;
					b += 32;
				}
			}
			else
			{
				for (; n >= 32; n -= 32)
				{
					ymm_a0 = _mm256_loadu_pd(a);
					ymm_a1 = _mm256_loadu_pd(a + 4);
					ymm_a2 = _mm256_loadu_pd(a + 8);
					ymm_a3 = _mm256_loadu_pd(a + 12);
					ymm_a4 = _mm256_loadu_pd(a + 16);
					ymm_a5 = _mm256_loadu_pd(a + 20);
					ymm_a6 = _mm256_loadu_pd(a + 24);
					ymm_a7 = _mm256_loadu_pd(a + 28);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
					ymm_a0 = _mm256_sub_pd(ymm_a0, offset);
					ymm_a1 = _mm256_sub_pd(ymm_a1, offset);
					ymm_a2 = _mm256_sub_pd(ymm_a2, offset);
					ymm_a3 = _mm256_sub_pd(ymm_a3, offset);
					ymm_a4 = _mm256_sub_pd(ymm_a4, offset);
					ymm_a5 = _mm256_sub_pd(ymm_a5, offset);
					ymm_a6 = _mm256_sub_pd(ymm_a6, offset);
					ymm_a7 = _mm256_sub_pd(ymm_a7, offset);
					ymm_a0 = _mm256_max_pd(ymm_a0, min);
					ymm_a1 = _mm256_max_pd(ymm_a1, min);
					ymm_a2 = _mm256_max_pd(ymm_a2, min);
					ymm_a3 = _mm256_max_pd(ymm_a3, min);
					ymm_a4 = _mm256_max_pd(ymm_a4, min);
					ymm_a5 = _mm256_max_pd(ymm_a5, min);
					ymm_a6 = _mm256_max_pd(ymm_a6, min);
					ymm_a7 = _mm256_max_pd(ymm_a7, min);
					ymm_a0 = _mm256_min_pd(ymm_a0, max);
					ymm_a1 = _mm256_min_pd(ymm_a1, max);
					ymm_a2 = _mm256_min_pd(ymm_a2, max);
					ymm_a3 = _mm256_min_pd(ymm_a3, max);
					ymm_a4 = _mm256_min_pd(ymm_a4, max);
					ymm_a5 = _mm256_min_pd(ymm_a5, max);
					ymm_a6 = _mm256_min_pd(ymm_a6, max);
					ymm_a7 = _mm256_min_pd(ymm_a7, max);
					ymm_b0 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a0));
					ymm_b1 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a1));
					ymm_b2 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a2));
					ymm_b3 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a3));
					ymm_b4 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a4));
					ymm_b5 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a5));
					ymm_b6 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a6));
					ymm_b7 = _mm256_castsi128_si256(_mm256_cvttpd_epi32(ymm_a7));
					ymm_b0 = _mm256_add_epi32(ymm_b0, shift);
					ymm_b1 = _mm256_add_epi32(ymm_b1, shift);
					ymm_b2 = _mm256_add_epi32(ymm_b2, shift);
					ymm_b3 = _mm256_add_epi32(ymm_b3, shift);
					ymm_b4 = _mm256_add_epi32(ymm_b4, shift);
					ymm_b5 = _mm256_add_epi32(ymm_b5, shift);
					ymm_b6 = _mm256_add_epi32(ymm_b6, shift);
					ymm_b7 = _mm256_add_epi32(ymm_b7, shift);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 1, _mm256_castsi256_si128(ymm_b1));
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 2, _mm256_castsi256_si128(ymm_b2));
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 3, _mm256_castsi256_si128(ymm_b3));
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 4, _mm256_castsi256_si128(ymm_b4));
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 5, _mm256_castsi256_si128(ymm_b5));
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 6, _mm256_castsi256_si128(ymm_b6));
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 7, _mm256_castsi256_si128(ymm_b7));
					a += 32;
					b += 32;
				}
			}
		}

		template <>
		inline void cvtspd_avx2_large<float>(float* b, const double* a, size_t n)
		{
			const size_t padding = 4 - (reinterpret_cast<size_t>(b) & 3);
			const __m256d min = _mm256_set1_pd(static_cast<double>(-FLT_MAX));
			const __m256d max = _mm256_set1_pd(static_cast<double>(FLT_MAX));
			__m256d ymm_a0, ymm_a1, ymm_a2, ymm_a3, ymm_a4, ymm_a5, ymm_a6, ymm_a7;
			__m128 xmm_b0, xmm_b1, xmm_b2, xmm_b3, xmm_b4, xmm_b5, xmm_b6, xmm_b7;

			// Align the destination to a 16-byte boundary.
			ymm_a0 = _mm256_loadu_pd(a);
			ymm_a0 = _mm256_max_pd(ymm_a0, min);
			ymm_a0 = _mm256_min_pd(ymm_a0, max);
			xmm_b0 = _mm256_cvtpd_ps(ymm_a0);
			_mm_storeu_ps(b, xmm_b0);
			b += padding;
			a += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			// If the source is aligned on a 32-byte boundary.
			if ((reinterpret_cast<size_t>(a) & 31) == 0)
			{
				for (; n >= 32; n -= 32)
				{
					ymm_a0 = _mm256_load_pd(a);
					ymm_a1 = _mm256_load_pd(a + 4);
					ymm_a2 = _mm256_load_pd(a + 8);
					ymm_a3 = _mm256_load_pd(a + 12);
					ymm_a4 = _mm256_load_pd(a + 16);
					ymm_a5 = _mm256_load_pd(a + 20);
					ymm_a6 = _mm256_load_pd(a + 24);
					ymm_a7 = _mm256_load_pd(a + 28);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
					ymm_a0 = _mm256_max_pd(ymm_a0, min);
					ymm_a1 = _mm256_max_pd(ymm_a1, min);
					ymm_a2 = _mm256_max_pd(ymm_a2, min);
					ymm_a3 = _mm256_max_pd(ymm_a3, min);
					ymm_a4 = _mm256_max_pd(ymm_a4, min);
					ymm_a5 = _mm256_max_pd(ymm_a5, min);
					ymm_a6 = _mm256_max_pd(ymm_a6, min);
					ymm_a7 = _mm256_max_pd(ymm_a7, min);
					ymm_a0 = _mm256_min_pd(ymm_a0, max);
					ymm_a1 = _mm256_min_pd(ymm_a1, max);
					ymm_a2 = _mm256_min_pd(ymm_a2, max);
					ymm_a3 = _mm256_min_pd(ymm_a3, max);
					ymm_a4 = _mm256_min_pd(ymm_a4, max);
					ymm_a5 = _mm256_min_pd(ymm_a5, max);
					ymm_a6 = _mm256_min_pd(ymm_a6, max);
					ymm_a7 = _mm256_min_pd(ymm_a7, max);
					xmm_b0 = _mm256_cvtpd_ps(ymm_a0);
					xmm_b1 = _mm256_cvtpd_ps(ymm_a1);
					xmm_b2 = _mm256_cvtpd_ps(ymm_a2);
					xmm_b3 = _mm256_cvtpd_ps(ymm_a3);
					xmm_b4 = _mm256_cvtpd_ps(ymm_a4);
					xmm_b5 = _mm256_cvtpd_ps(ymm_a5);
					xmm_b6 = _mm256_cvtpd_ps(ymm_a6);
					xmm_b7 = _mm256_cvtpd_ps(ymm_a7);
					_mm_stream_ps(b, xmm_b0);
					_mm_stream_ps(b + 4, xmm_b1);
					_mm_stream_ps(b + 8, xmm_b2);
					_mm_stream_ps(b + 12, xmm_b3);
					_mm_stream_ps(b + 16, xmm_b4);
					_mm_stream_ps(b + 20, xmm_b5);
					_mm_stream_ps(b + 24, xmm_b6);
					_mm_stream_ps(b + 28, xmm_b7);
					a += 32;
					b += 32;
				}
			}
			else
			{
				for (; n >= 32; n -= 32)
				{
					ymm_a0 = _mm256_loadu_pd(a);
					ymm_a1 = _mm256_loadu_pd(a + 4);
					ymm_a2 = _mm256_loadu_pd(a + 8);
					ymm_a3 = _mm256_loadu_pd(a + 12);
					ymm_a4 = _mm256_loadu_pd(a + 16);
					ymm_a5 = _mm256_loadu_pd(a + 20);
					ymm_a6 = _mm256_loadu_pd(a + 24);
					ymm_a7 = _mm256_loadu_pd(a + 28);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
					ymm_a0 = _mm256_max_pd(ymm_a0, min);
					ymm_a1 = _mm256_max_pd(ymm_a1, min);
					ymm_a2 = _mm256_max_pd(ymm_a2, min);
					ymm_a3 = _mm256_max_pd(ymm_a3, min);
					ymm_a4 = _mm256_max_pd(ymm_a4, min);
					ymm_a5 = _mm256_max_pd(ymm_a5, min);
					ymm_a6 = _mm256_max_pd(ymm_a6, min);
					ymm_a7 = _mm256_max_pd(ymm_a7, min);
					ymm_a0 = _mm256_min_pd(ymm_a0, max);
					ymm_a1 = _mm256_min_pd(ymm_a1, max);
					ymm_a2 = _mm256_min_pd(ymm_a2, max);
					ymm_a3 = _mm256_min_pd(ymm_a3, max);
					ymm_a4 = _mm256_min_pd(ymm_a4, max);
					ymm_a5 = _mm256_min_pd(ymm_a5, max);
					ymm_a6 = _mm256_min_pd(ymm_a6, max);
					ymm_a7 = _mm256_min_pd(ymm_a7, max);
					xmm_b0 = _mm256_cvtpd_ps(ymm_a0);
					xmm_b1 = _mm256_cvtpd_ps(ymm_a1);
					xmm_b2 = _mm256_cvtpd_ps(ymm_a2);
					xmm_b3 = _mm256_cvtpd_ps(ymm_a3);
					xmm_b4 = _mm256_cvtpd_ps(ymm_a4);
					xmm_b5 = _mm256_cvtpd_ps(ymm_a5);
					xmm_b6 = _mm256_cvtpd_ps(ymm_a6);
					xmm_b7 = _mm256_cvtpd_ps(ymm_a7);
					_mm_stream_ps(b, xmm_b0);
					_mm_stream_ps(b + 4, xmm_b1);
					_mm_stream_ps(b + 8, xmm_b2);
					_mm_stream_ps(b + 12, xmm_b3);
					_mm_stream_ps(b + 16, xmm_b4);
					_mm_stream_ps(b + 20, xmm_b5);
					_mm_stream_ps(b + 24, xmm_b6);
					_mm_stream_ps(b + 28, xmm_b7);
					a += 32;
					b += 32;
				}
			}
		}

		// Function template impl_cvtspd

		template <class T>
		inline void impl_cvtspd(T* b, const double* a, size_t n)
		{
			constexpr size_t threshold = simd::l2_cache_size / sizeof(double);
			// Small amount of data type conversion.
			if (n < 64)
				cvtspd_avx2_small(b, a, n);
			// Medium amount data type conversion.
			else if (n < threshold)
			{
				cvtspd_avx2_medium(b, a, n);
				cvtspd_avx2_small(b, a, n);
			}
			// Large amount data type conversion.
			else
			{
				cvtspd_avx2_large(b, a, n);
				cvtspd_avx2_small(b, a, n);
			}
		}

	#elif defined(__AVX__) || defined(__SSE4_2__) || defined(__SSE4_1__)

		// Function template cvtspd_sse41_8

		template <class T>
		inline void cvtspd_sse41_8(T* b, const double* a)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		inline void cvtspd_sse41_8<signed char>(signed char* b, const double* a)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(INT8_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT8_MAX));
			__m128d xmm_a0 = _mm_loadu_pd(a);
			__m128d xmm_a1 = _mm_loadu_pd(a + 2);
			__m128d xmm_a2 = _mm_loadu_pd(a + 4);
			__m128d xmm_a3 = _mm_loadu_pd(a + 6);
			xmm_a0 = _mm_max_pd(xmm_a0, min);
			xmm_a1 = _mm_max_pd(xmm_a1, min);
			xmm_a2 = _mm_max_pd(xmm_a2, min);
			xmm_a3 = _mm_max_pd(xmm_a3, min);
			xmm_a0 = _mm_min_pd(xmm_a0, max);
			xmm_a1 = _mm_min_pd(xmm_a1, max);
			xmm_a2 = _mm_min_pd(xmm_a2, max);
			xmm_a3 = _mm_min_pd(xmm_a3, max);
			__m128i xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
			__m128i xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
			__m128i xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
			__m128i xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
			xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
			xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
			xmm_b0 = _mm_packs_epi32(xmm_b0, xmm_b2);
			xmm_b0 = _mm_packs_epi16(xmm_b0, _mm_setzero_si128());
			_mm_storeu_si64(reinterpret_cast<__m128i*>(b), xmm_b0);
		}

		template <>
		inline void cvtspd_sse41_8<unsigned char>(unsigned char* b, const double* a)
		{
			const __m128d min = _mm_setzero_pd();
			const __m128d max = _mm_set1_pd(static_cast<double>(UINT8_MAX));
			__m128d xmm_a0 = _mm_loadu_pd(a);
			__m128d xmm_a1 = _mm_loadu_pd(a + 2);
			__m128d xmm_a2 = _mm_loadu_pd(a + 4);
			__m128d xmm_a3 = _mm_loadu_pd(a + 6);
			xmm_a0 = _mm_max_pd(xmm_a0, min);
			xmm_a1 = _mm_max_pd(xmm_a1, min);
			xmm_a2 = _mm_max_pd(xmm_a2, min);
			xmm_a3 = _mm_max_pd(xmm_a3, min);
			xmm_a0 = _mm_min_pd(xmm_a0, max);
			xmm_a1 = _mm_min_pd(xmm_a1, max);
			xmm_a2 = _mm_min_pd(xmm_a2, max);
			xmm_a3 = _mm_min_pd(xmm_a3, max);
			__m128i xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
			__m128i xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
			__m128i xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
			__m128i xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
			xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
			xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
			xmm_b0 = _mm_packus_epi32(xmm_b0, xmm_b2);
			xmm_b0 = _mm_packus_epi16(xmm_b0, _mm_setzero_si128());
			_mm_storeu_si64(reinterpret_cast<__m128i*>(b), xmm_b0);
		}

		template <>
		inline void cvtspd_sse41_8<signed short>(signed short* b, const double* a)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(INT16_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT16_MAX));
			__m128d xmm_a0 = _mm_loadu_pd(a);
			__m128d xmm_a1 = _mm_loadu_pd(a + 2);
			__m128d xmm_a2 = _mm_loadu_pd(a + 4);
			__m128d xmm_a3 = _mm_loadu_pd(a + 6);
			xmm_a0 = _mm_max_pd(xmm_a0, min);
			xmm_a1 = _mm_max_pd(xmm_a1, min);
			xmm_a2 = _mm_max_pd(xmm_a2, min);
			xmm_a3 = _mm_max_pd(xmm_a3, min);
			xmm_a0 = _mm_min_pd(xmm_a0, max);
			xmm_a1 = _mm_min_pd(xmm_a1, max);
			xmm_a2 = _mm_min_pd(xmm_a2, max);
			xmm_a3 = _mm_min_pd(xmm_a3, max);
			__m128i xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
			__m128i xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
			__m128i xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
			__m128i xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
			xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
			xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
			xmm_b0 = _mm_packs_epi32(xmm_b0, xmm_b2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
		}

		template <>
		inline void cvtspd_sse41_8<unsigned short>(unsigned short* b, const double* a)
		{
			const __m128d min = _mm_setzero_pd();
			const __m128d max = _mm_set1_pd(static_cast<double>(UINT16_MAX));
			__m128d xmm_a0 = _mm_loadu_pd(a);
			__m128d xmm_a1 = _mm_loadu_pd(a + 2);
			__m128d xmm_a2 = _mm_loadu_pd(a + 4);
			__m128d xmm_a3 = _mm_loadu_pd(a + 6);
			xmm_a0 = _mm_max_pd(xmm_a0, min);
			xmm_a1 = _mm_max_pd(xmm_a1, min);
			xmm_a2 = _mm_max_pd(xmm_a2, min);
			xmm_a3 = _mm_max_pd(xmm_a3, min);
			xmm_a0 = _mm_min_pd(xmm_a0, max);
			xmm_a1 = _mm_min_pd(xmm_a1, max);
			xmm_a2 = _mm_min_pd(xmm_a2, max);
			xmm_a3 = _mm_min_pd(xmm_a3, max);
			__m128i xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
			__m128i xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
			__m128i xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
			__m128i xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
			xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
			xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
			xmm_b0 = _mm_packus_epi32(xmm_b0, xmm_b2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
		}

		template <>
		inline void cvtspd_sse41_8<signed int>(signed int* b, const double* a)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(INT32_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT32_MAX));
			__m128d xmm_a0 = _mm_loadu_pd(a);
			__m128d xmm_a1 = _mm_loadu_pd(a + 2);
			__m128d xmm_a2 = _mm_loadu_pd(a + 4);
			__m128d xmm_a3 = _mm_loadu_pd(a + 6);
			xmm_a0 = _mm_max_pd(xmm_a0, min);
			xmm_a1 = _mm_max_pd(xmm_a1, min);
			xmm_a2 = _mm_max_pd(xmm_a2, min);
			xmm_a3 = _mm_max_pd(xmm_a3, min);
			xmm_a0 = _mm_min_pd(xmm_a0, max);
			xmm_a1 = _mm_min_pd(xmm_a1, max);
			xmm_a2 = _mm_min_pd(xmm_a2, max);
			xmm_a3 = _mm_min_pd(xmm_a3, max);
			__m128i xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
			__m128i xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
			__m128i xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
			__m128i xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
			xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
			xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b2);
		}

		template <>
		inline void cvtspd_sse41_8<unsigned int>(unsigned int* b, const double* a)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(INT32_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT32_MAX));
			const __m128d offset = _mm_set1_pd(2.147483648e+9);
			const __m128i shift = _mm_set1_epi32(2147483648);
			__m128d xmm_a0 = _mm_loadu_pd(a);
			__m128d xmm_a1 = _mm_loadu_pd(a + 2);
			__m128d xmm_a2 = _mm_loadu_pd(a + 4);
			__m128d xmm_a3 = _mm_loadu_pd(a + 6);
			xmm_a0 = _mm_sub_pd(xmm_a0, offset);
			xmm_a1 = _mm_sub_pd(xmm_a1, offset);
			xmm_a2 = _mm_sub_pd(xmm_a2, offset);
			xmm_a3 = _mm_sub_pd(xmm_a3, offset);
			xmm_a0 = _mm_max_pd(xmm_a0, min);
			xmm_a1 = _mm_max_pd(xmm_a1, min);
			xmm_a2 = _mm_max_pd(xmm_a2, min);
			xmm_a3 = _mm_max_pd(xmm_a3, min);
			xmm_a0 = _mm_min_pd(xmm_a0, max);
			xmm_a1 = _mm_min_pd(xmm_a1, max);
			xmm_a2 = _mm_min_pd(xmm_a2, max);
			xmm_a3 = _mm_min_pd(xmm_a3, max);
			__m128i xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
			__m128i xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
			__m128i xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
			__m128i xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
			xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
			xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
			xmm_b0 = _mm_add_epi32(xmm_b0, shift);
			xmm_b2 = _mm_add_epi32(xmm_b2, shift);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b2);
		}

		template <>
		inline void cvtspd_sse41_8<float>(float* b, const double* a)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(-FLT_MAX));
			const __m128d max = _mm_set1_pd(static_cast<double>(FLT_MAX));
			__m128d xmm_a0 = _mm_loadu_pd(a);
			__m128d xmm_a1 = _mm_loadu_pd(a + 2);
			__m128d xmm_a2 = _mm_loadu_pd(a + 4);
			__m128d xmm_a3 = _mm_loadu_pd(a + 6);
			xmm_a0 = _mm_max_pd(xmm_a0, min);
			xmm_a1 = _mm_max_pd(xmm_a1, min);
			xmm_a2 = _mm_max_pd(xmm_a2, min);
			xmm_a3 = _mm_max_pd(xmm_a3, min);
			xmm_a0 = _mm_min_pd(xmm_a0, max);
			xmm_a1 = _mm_min_pd(xmm_a1, max);
			xmm_a2 = _mm_min_pd(xmm_a2, max);
			xmm_a3 = _mm_min_pd(xmm_a3, max);
			__m128 xmm_b0 = _mm_cvtpd_ps(xmm_a0);
			__m128 xmm_b1 = _mm_cvtpd_ps(xmm_a1);
			__m128 xmm_b2 = _mm_cvtpd_ps(xmm_a2);
			__m128 xmm_b3 = _mm_cvtpd_ps(xmm_a3);
			xmm_b0 = _mm_shuffle_ps(xmm_b0, xmm_b1, _MM_SHUFFLE(1, 0, 1, 0));
			xmm_b2 = _mm_shuffle_ps(xmm_b2, xmm_b3, _MM_SHUFFLE(1, 0, 1, 0));
			_mm_storeu_ps(b, xmm_b0);
			_mm_storeu_ps(b + 4, xmm_b2);
		}

		// Function template cvtspd_sse41_16

		template <class T>
		inline void cvtspd_sse41_16(T* b, const double* a)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		inline void cvtspd_sse41_16<signed char>(signed char* b, const double* a)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(INT8_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT8_MAX));
			__m128d xmm_a0 = _mm_loadu_pd(a);
			__m128d xmm_a1 = _mm_loadu_pd(a + 2);
			__m128d xmm_a2 = _mm_loadu_pd(a + 4);
			__m128d xmm_a3 = _mm_loadu_pd(a + 6);
			__m128d xmm_a4 = _mm_loadu_pd(a + 8);
			__m128d xmm_a5 = _mm_loadu_pd(a + 10);
			__m128d xmm_a6 = _mm_loadu_pd(a + 12);
			__m128d xmm_a7 = _mm_loadu_pd(a + 14);
			xmm_a0 = _mm_max_pd(xmm_a0, min);
			xmm_a1 = _mm_max_pd(xmm_a1, min);
			xmm_a2 = _mm_max_pd(xmm_a2, min);
			xmm_a3 = _mm_max_pd(xmm_a3, min);
			xmm_a4 = _mm_max_pd(xmm_a4, min);
			xmm_a5 = _mm_max_pd(xmm_a5, min);
			xmm_a6 = _mm_max_pd(xmm_a6, min);
			xmm_a7 = _mm_max_pd(xmm_a7, min);
			xmm_a0 = _mm_min_pd(xmm_a0, max);
			xmm_a1 = _mm_min_pd(xmm_a1, max);
			xmm_a2 = _mm_min_pd(xmm_a2, max);
			xmm_a3 = _mm_min_pd(xmm_a3, max);
			xmm_a4 = _mm_min_pd(xmm_a4, max);
			xmm_a5 = _mm_min_pd(xmm_a5, max);
			xmm_a6 = _mm_min_pd(xmm_a6, max);
			xmm_a7 = _mm_min_pd(xmm_a7, max);
			__m128i xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
			__m128i xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
			__m128i xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
			__m128i xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
			__m128i xmm_b4 = _mm_cvttpd_epi32(xmm_a4);
			__m128i xmm_b5 = _mm_cvttpd_epi32(xmm_a5);
			__m128i xmm_b6 = _mm_cvttpd_epi32(xmm_a6);
			__m128i xmm_b7 = _mm_cvttpd_epi32(xmm_a7);
			xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
			xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
			xmm_b4 = _mm_unpacklo_epi64(xmm_b4, xmm_b5);
			xmm_b6 = _mm_unpacklo_epi64(xmm_b6, xmm_b7);
			xmm_b0 = _mm_packs_epi32(xmm_b0, xmm_b2);
			xmm_b4 = _mm_packs_epi32(xmm_b4, xmm_b6);
			xmm_b0 = _mm_packs_epi16(xmm_b0, xmm_b4);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
		}

		template <>
		inline void cvtspd_sse41_16<unsigned char>(unsigned char* b, const double* a)
		{
			const __m128d min = _mm_setzero_pd();
			const __m128d max = _mm_set1_pd(static_cast<double>(UINT8_MAX));
			__m128d xmm_a0 = _mm_loadu_pd(a);
			__m128d xmm_a1 = _mm_loadu_pd(a + 2);
			__m128d xmm_a2 = _mm_loadu_pd(a + 4);
			__m128d xmm_a3 = _mm_loadu_pd(a + 6);
			__m128d xmm_a4 = _mm_loadu_pd(a + 8);
			__m128d xmm_a5 = _mm_loadu_pd(a + 10);
			__m128d xmm_a6 = _mm_loadu_pd(a + 12);
			__m128d xmm_a7 = _mm_loadu_pd(a + 14);
			xmm_a0 = _mm_max_pd(xmm_a0, min);
			xmm_a1 = _mm_max_pd(xmm_a1, min);
			xmm_a2 = _mm_max_pd(xmm_a2, min);
			xmm_a3 = _mm_max_pd(xmm_a3, min);
			xmm_a4 = _mm_max_pd(xmm_a4, min);
			xmm_a5 = _mm_max_pd(xmm_a5, min);
			xmm_a6 = _mm_max_pd(xmm_a6, min);
			xmm_a7 = _mm_max_pd(xmm_a7, min);
			xmm_a0 = _mm_min_pd(xmm_a0, max);
			xmm_a1 = _mm_min_pd(xmm_a1, max);
			xmm_a2 = _mm_min_pd(xmm_a2, max);
			xmm_a3 = _mm_min_pd(xmm_a3, max);
			xmm_a4 = _mm_min_pd(xmm_a4, max);
			xmm_a5 = _mm_min_pd(xmm_a5, max);
			xmm_a6 = _mm_min_pd(xmm_a6, max);
			xmm_a7 = _mm_min_pd(xmm_a7, max);
			__m128i xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
			__m128i xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
			__m128i xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
			__m128i xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
			__m128i xmm_b4 = _mm_cvttpd_epi32(xmm_a4);
			__m128i xmm_b5 = _mm_cvttpd_epi32(xmm_a5);
			__m128i xmm_b6 = _mm_cvttpd_epi32(xmm_a6);
			__m128i xmm_b7 = _mm_cvttpd_epi32(xmm_a7);
			xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
			xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
			xmm_b4 = _mm_unpacklo_epi64(xmm_b4, xmm_b5);
			xmm_b6 = _mm_unpacklo_epi64(xmm_b6, xmm_b7);
			xmm_b0 = _mm_packus_epi32(xmm_b0, xmm_b2);
			xmm_b4 = _mm_packus_epi32(xmm_b4, xmm_b6);
			xmm_b0 = _mm_packus_epi16(xmm_b0, xmm_b4);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
		}

		template <>
		inline void cvtspd_sse41_16<signed short>(signed short* b, const double* a)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(INT16_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT16_MAX));
			__m128d xmm_a0 = _mm_loadu_pd(a);
			__m128d xmm_a1 = _mm_loadu_pd(a + 2);
			__m128d xmm_a2 = _mm_loadu_pd(a + 4);
			__m128d xmm_a3 = _mm_loadu_pd(a + 6);
			__m128d xmm_a4 = _mm_loadu_pd(a + 8);
			__m128d xmm_a5 = _mm_loadu_pd(a + 10);
			__m128d xmm_a6 = _mm_loadu_pd(a + 12);
			__m128d xmm_a7 = _mm_loadu_pd(a + 14);
			xmm_a0 = _mm_max_pd(xmm_a0, min);
			xmm_a1 = _mm_max_pd(xmm_a1, min);
			xmm_a2 = _mm_max_pd(xmm_a2, min);
			xmm_a3 = _mm_max_pd(xmm_a3, min);
			xmm_a4 = _mm_max_pd(xmm_a4, min);
			xmm_a5 = _mm_max_pd(xmm_a5, min);
			xmm_a6 = _mm_max_pd(xmm_a6, min);
			xmm_a7 = _mm_max_pd(xmm_a7, min);
			xmm_a0 = _mm_min_pd(xmm_a0, max);
			xmm_a1 = _mm_min_pd(xmm_a1, max);
			xmm_a2 = _mm_min_pd(xmm_a2, max);
			xmm_a3 = _mm_min_pd(xmm_a3, max);
			xmm_a4 = _mm_min_pd(xmm_a4, max);
			xmm_a5 = _mm_min_pd(xmm_a5, max);
			xmm_a6 = _mm_min_pd(xmm_a6, max);
			xmm_a7 = _mm_min_pd(xmm_a7, max);
			__m128i xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
			__m128i xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
			__m128i xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
			__m128i xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
			__m128i xmm_b4 = _mm_cvttpd_epi32(xmm_a4);
			__m128i xmm_b5 = _mm_cvttpd_epi32(xmm_a5);
			__m128i xmm_b6 = _mm_cvttpd_epi32(xmm_a6);
			__m128i xmm_b7 = _mm_cvttpd_epi32(xmm_a7);
			xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
			xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
			xmm_b4 = _mm_unpacklo_epi64(xmm_b4, xmm_b5);
			xmm_b6 = _mm_unpacklo_epi64(xmm_b6, xmm_b7);
			xmm_b0 = _mm_packs_epi32(xmm_b0, xmm_b2);
			xmm_b4 = _mm_packs_epi32(xmm_b4, xmm_b6);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b4);
		}

		template <>
		inline void cvtspd_sse41_16<unsigned short>(unsigned short* b, const double* a)
		{
			const __m128d min = _mm_setzero_pd();
			const __m128d max = _mm_set1_pd(static_cast<double>(UINT16_MAX));
			__m128d xmm_a0 = _mm_loadu_pd(a);
			__m128d xmm_a1 = _mm_loadu_pd(a + 2);
			__m128d xmm_a2 = _mm_loadu_pd(a + 4);
			__m128d xmm_a3 = _mm_loadu_pd(a + 6);
			__m128d xmm_a4 = _mm_loadu_pd(a + 8);
			__m128d xmm_a5 = _mm_loadu_pd(a + 10);
			__m128d xmm_a6 = _mm_loadu_pd(a + 12);
			__m128d xmm_a7 = _mm_loadu_pd(a + 14);
			xmm_a0 = _mm_max_pd(xmm_a0, min);
			xmm_a1 = _mm_max_pd(xmm_a1, min);
			xmm_a2 = _mm_max_pd(xmm_a2, min);
			xmm_a3 = _mm_max_pd(xmm_a3, min);
			xmm_a4 = _mm_max_pd(xmm_a4, min);
			xmm_a5 = _mm_max_pd(xmm_a5, min);
			xmm_a6 = _mm_max_pd(xmm_a6, min);
			xmm_a7 = _mm_max_pd(xmm_a7, min);
			xmm_a0 = _mm_min_pd(xmm_a0, max);
			xmm_a1 = _mm_min_pd(xmm_a1, max);
			xmm_a2 = _mm_min_pd(xmm_a2, max);
			xmm_a3 = _mm_min_pd(xmm_a3, max);
			xmm_a4 = _mm_min_pd(xmm_a4, max);
			xmm_a5 = _mm_min_pd(xmm_a5, max);
			xmm_a6 = _mm_min_pd(xmm_a6, max);
			xmm_a7 = _mm_min_pd(xmm_a7, max);
			__m128i xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
			__m128i xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
			__m128i xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
			__m128i xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
			__m128i xmm_b4 = _mm_cvttpd_epi32(xmm_a4);
			__m128i xmm_b5 = _mm_cvttpd_epi32(xmm_a5);
			__m128i xmm_b6 = _mm_cvttpd_epi32(xmm_a6);
			__m128i xmm_b7 = _mm_cvttpd_epi32(xmm_a7);
			xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
			xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
			xmm_b4 = _mm_unpacklo_epi64(xmm_b4, xmm_b5);
			xmm_b6 = _mm_unpacklo_epi64(xmm_b6, xmm_b7);
			xmm_b0 = _mm_packus_epi32(xmm_b0, xmm_b2);
			xmm_b4 = _mm_packus_epi32(xmm_b4, xmm_b6);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b4);
		}

		template <>
		inline void cvtspd_sse41_16<signed int>(signed int* b, const double* a)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(INT32_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT32_MAX));
			__m128d xmm_a0 = _mm_loadu_pd(a);
			__m128d xmm_a1 = _mm_loadu_pd(a + 2);
			__m128d xmm_a2 = _mm_loadu_pd(a + 4);
			__m128d xmm_a3 = _mm_loadu_pd(a + 6);
			__m128d xmm_a4 = _mm_loadu_pd(a + 8);
			__m128d xmm_a5 = _mm_loadu_pd(a + 10);
			__m128d xmm_a6 = _mm_loadu_pd(a + 12);
			__m128d xmm_a7 = _mm_loadu_pd(a + 14);
			xmm_a0 = _mm_max_pd(xmm_a0, min);
			xmm_a1 = _mm_max_pd(xmm_a1, min);
			xmm_a2 = _mm_max_pd(xmm_a2, min);
			xmm_a3 = _mm_max_pd(xmm_a3, min);
			xmm_a4 = _mm_max_pd(xmm_a4, min);
			xmm_a5 = _mm_max_pd(xmm_a5, min);
			xmm_a6 = _mm_max_pd(xmm_a6, min);
			xmm_a7 = _mm_max_pd(xmm_a7, min);
			xmm_a0 = _mm_min_pd(xmm_a0, max);
			xmm_a1 = _mm_min_pd(xmm_a1, max);
			xmm_a2 = _mm_min_pd(xmm_a2, max);
			xmm_a3 = _mm_min_pd(xmm_a3, max);
			xmm_a4 = _mm_min_pd(xmm_a4, max);
			xmm_a5 = _mm_min_pd(xmm_a5, max);
			xmm_a6 = _mm_min_pd(xmm_a6, max);
			xmm_a7 = _mm_min_pd(xmm_a7, max);
			__m128i xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
			__m128i xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
			__m128i xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
			__m128i xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
			__m128i xmm_b4 = _mm_cvttpd_epi32(xmm_a4);
			__m128i xmm_b5 = _mm_cvttpd_epi32(xmm_a5);
			__m128i xmm_b6 = _mm_cvttpd_epi32(xmm_a6);
			__m128i xmm_b7 = _mm_cvttpd_epi32(xmm_a7);
			xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
			xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
			xmm_b4 = _mm_unpacklo_epi64(xmm_b4, xmm_b5);
			xmm_b6 = _mm_unpacklo_epi64(xmm_b6, xmm_b7);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 2, xmm_b4);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 3, xmm_b6);
		}

		template <>
		inline void cvtspd_sse41_16<unsigned int>(unsigned int* b, const double* a)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(INT32_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT32_MAX));
			const __m128d offset = _mm_set1_pd(2.147483648e+9);
			const __m128i shift = _mm_set1_epi32(2147483648);
			__m128d xmm_a0 = _mm_loadu_pd(a);
			__m128d xmm_a1 = _mm_loadu_pd(a + 2);
			__m128d xmm_a2 = _mm_loadu_pd(a + 4);
			__m128d xmm_a3 = _mm_loadu_pd(a + 6);
			__m128d xmm_a4 = _mm_loadu_pd(a + 8);
			__m128d xmm_a5 = _mm_loadu_pd(a + 10);
			__m128d xmm_a6 = _mm_loadu_pd(a + 12);
			__m128d xmm_a7 = _mm_loadu_pd(a + 14);
			xmm_a0 = _mm_sub_pd(xmm_a0, offset);
			xmm_a1 = _mm_sub_pd(xmm_a1, offset);
			xmm_a2 = _mm_sub_pd(xmm_a2, offset);
			xmm_a3 = _mm_sub_pd(xmm_a3, offset);
			xmm_a4 = _mm_sub_pd(xmm_a4, offset);
			xmm_a5 = _mm_sub_pd(xmm_a5, offset);
			xmm_a6 = _mm_sub_pd(xmm_a6, offset);
			xmm_a7 = _mm_sub_pd(xmm_a7, offset);
			xmm_a0 = _mm_max_pd(xmm_a0, min);
			xmm_a1 = _mm_max_pd(xmm_a1, min);
			xmm_a2 = _mm_max_pd(xmm_a2, min);
			xmm_a3 = _mm_max_pd(xmm_a3, min);
			xmm_a4 = _mm_max_pd(xmm_a4, min);
			xmm_a5 = _mm_max_pd(xmm_a5, min);
			xmm_a6 = _mm_max_pd(xmm_a6, min);
			xmm_a7 = _mm_max_pd(xmm_a7, min);
			xmm_a0 = _mm_min_pd(xmm_a0, max);
			xmm_a1 = _mm_min_pd(xmm_a1, max);
			xmm_a2 = _mm_min_pd(xmm_a2, max);
			xmm_a3 = _mm_min_pd(xmm_a3, max);
			xmm_a4 = _mm_min_pd(xmm_a4, max);
			xmm_a5 = _mm_min_pd(xmm_a5, max);
			xmm_a6 = _mm_min_pd(xmm_a6, max);
			xmm_a7 = _mm_min_pd(xmm_a7, max);
			__m128i xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
			__m128i xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
			__m128i xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
			__m128i xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
			__m128i xmm_b4 = _mm_cvttpd_epi32(xmm_a4);
			__m128i xmm_b5 = _mm_cvttpd_epi32(xmm_a5);
			__m128i xmm_b6 = _mm_cvttpd_epi32(xmm_a6);
			__m128i xmm_b7 = _mm_cvttpd_epi32(xmm_a7);
			xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
			xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
			xmm_b4 = _mm_unpacklo_epi64(xmm_b4, xmm_b5);
			xmm_b6 = _mm_unpacklo_epi64(xmm_b6, xmm_b7);
			xmm_b0 = _mm_add_epi32(xmm_b0, shift);
			xmm_b2 = _mm_add_epi32(xmm_b2, shift);
			xmm_b4 = _mm_add_epi32(xmm_b4, shift);
			xmm_b6 = _mm_add_epi32(xmm_b6, shift);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 2, xmm_b4);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 3, xmm_b6);
		}

		template <>
		inline void cvtspd_sse41_16<float>(float* b, const double* a)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(-FLT_MAX));
			const __m128d max = _mm_set1_pd(static_cast<double>(FLT_MAX));
			__m128d xmm_a0 = _mm_loadu_pd(a);
			__m128d xmm_a1 = _mm_loadu_pd(a + 2);
			__m128d xmm_a2 = _mm_loadu_pd(a + 4);
			__m128d xmm_a3 = _mm_loadu_pd(a + 6);
			__m128d xmm_a4 = _mm_loadu_pd(a + 8);
			__m128d xmm_a5 = _mm_loadu_pd(a + 10);
			__m128d xmm_a6 = _mm_loadu_pd(a + 12);
			__m128d xmm_a7 = _mm_loadu_pd(a + 14);
			xmm_a0 = _mm_max_pd(xmm_a0, min);
			xmm_a1 = _mm_max_pd(xmm_a1, min);
			xmm_a2 = _mm_max_pd(xmm_a2, min);
			xmm_a3 = _mm_max_pd(xmm_a3, min);
			xmm_a4 = _mm_max_pd(xmm_a4, min);
			xmm_a5 = _mm_max_pd(xmm_a5, min);
			xmm_a6 = _mm_max_pd(xmm_a6, min);
			xmm_a7 = _mm_max_pd(xmm_a7, min);
			xmm_a0 = _mm_min_pd(xmm_a0, max);
			xmm_a1 = _mm_min_pd(xmm_a1, max);
			xmm_a2 = _mm_min_pd(xmm_a2, max);
			xmm_a3 = _mm_min_pd(xmm_a3, max);
			xmm_a4 = _mm_min_pd(xmm_a4, max);
			xmm_a5 = _mm_min_pd(xmm_a5, max);
			xmm_a6 = _mm_min_pd(xmm_a6, max);
			xmm_a7 = _mm_min_pd(xmm_a7, max);
			__m128 xmm_b0 = _mm_cvtpd_ps(xmm_a0);
			__m128 xmm_b1 = _mm_cvtpd_ps(xmm_a1);
			__m128 xmm_b2 = _mm_cvtpd_ps(xmm_a2);
			__m128 xmm_b3 = _mm_cvtpd_ps(xmm_a3);
			__m128 xmm_b4 = _mm_cvtpd_ps(xmm_a4);
			__m128 xmm_b5 = _mm_cvtpd_ps(xmm_a5);
			__m128 xmm_b6 = _mm_cvtpd_ps(xmm_a6);
			__m128 xmm_b7 = _mm_cvtpd_ps(xmm_a7);
			xmm_b0 = _mm_shuffle_ps(xmm_b0, xmm_b1, _MM_SHUFFLE(1, 0, 1, 0));
			xmm_b2 = _mm_shuffle_ps(xmm_b2, xmm_b3, _MM_SHUFFLE(1, 0, 1, 0));
			xmm_b4 = _mm_shuffle_ps(xmm_b4, xmm_b5, _MM_SHUFFLE(1, 0, 1, 0));
			xmm_b6 = _mm_shuffle_ps(xmm_b6, xmm_b7, _MM_SHUFFLE(1, 0, 1, 0));
			_mm_storeu_ps(b, xmm_b0);
			_mm_storeu_ps(b + 4, xmm_b2);
			_mm_storeu_ps(b + 8, xmm_b4);
			_mm_storeu_ps(b + 12, xmm_b6);
		}

		// Function template cvtspd_sse41_32

		template <class T>
		inline void cvtspd_sse41_32(T* b, const double* a)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		inline void cvtspd_sse41_32<signed char>(signed char* b, const double* a)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(INT8_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT8_MAX));
			__m128d xmm_a0 = _mm_loadu_pd(a);
			__m128d xmm_a1 = _mm_loadu_pd(a + 2);
			__m128d xmm_a2 = _mm_loadu_pd(a + 4);
			__m128d xmm_a3 = _mm_loadu_pd(a + 6);
			__m128d xmm_a4 = _mm_loadu_pd(a + 8);
			__m128d xmm_a5 = _mm_loadu_pd(a + 10);
			__m128d xmm_a6 = _mm_loadu_pd(a + 12);
			__m128d xmm_a7 = _mm_loadu_pd(a + 14);
			__m128d xmm_a8 = _mm_loadu_pd(a + 16);
			__m128d xmm_a9 = _mm_loadu_pd(a + 18);
			__m128d xmm_aa = _mm_loadu_pd(a + 20);
			__m128d xmm_ab = _mm_loadu_pd(a + 22);
			__m128d xmm_ac = _mm_loadu_pd(a + 24);
			__m128d xmm_ad = _mm_loadu_pd(a + 26);
			__m128d xmm_ae = _mm_loadu_pd(a + 28);
			__m128d xmm_af = _mm_loadu_pd(a + 30);
			xmm_a0 = _mm_max_pd(xmm_a0, min);
			xmm_a1 = _mm_max_pd(xmm_a1, min);
			xmm_a2 = _mm_max_pd(xmm_a2, min);
			xmm_a3 = _mm_max_pd(xmm_a3, min);
			xmm_a4 = _mm_max_pd(xmm_a4, min);
			xmm_a5 = _mm_max_pd(xmm_a5, min);
			xmm_a6 = _mm_max_pd(xmm_a6, min);
			xmm_a7 = _mm_max_pd(xmm_a7, min);
			xmm_a8 = _mm_max_pd(xmm_a8, min);
			xmm_a9 = _mm_max_pd(xmm_a9, min);
			xmm_aa = _mm_max_pd(xmm_aa, min);
			xmm_ab = _mm_max_pd(xmm_ab, min);
			xmm_ac = _mm_max_pd(xmm_ac, min);
			xmm_ad = _mm_max_pd(xmm_ad, min);
			xmm_ae = _mm_max_pd(xmm_ae, min);
			xmm_af = _mm_max_pd(xmm_af, min);
			xmm_a0 = _mm_min_pd(xmm_a0, max);
			xmm_a1 = _mm_min_pd(xmm_a1, max);
			xmm_a2 = _mm_min_pd(xmm_a2, max);
			xmm_a3 = _mm_min_pd(xmm_a3, max);
			xmm_a4 = _mm_min_pd(xmm_a4, max);
			xmm_a5 = _mm_min_pd(xmm_a5, max);
			xmm_a6 = _mm_min_pd(xmm_a6, max);
			xmm_a7 = _mm_min_pd(xmm_a7, max);
			xmm_a8 = _mm_min_pd(xmm_a8, max);
			xmm_a9 = _mm_min_pd(xmm_a9, max);
			xmm_aa = _mm_min_pd(xmm_aa, max);
			xmm_ab = _mm_min_pd(xmm_ab, max);
			xmm_ac = _mm_min_pd(xmm_ac, max);
			xmm_ad = _mm_min_pd(xmm_ad, max);
			xmm_ae = _mm_min_pd(xmm_ae, max);
			xmm_af = _mm_min_pd(xmm_af, max);
			__m128i xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
			__m128i xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
			__m128i xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
			__m128i xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
			__m128i xmm_b4 = _mm_cvttpd_epi32(xmm_a4);
			__m128i xmm_b5 = _mm_cvttpd_epi32(xmm_a5);
			__m128i xmm_b6 = _mm_cvttpd_epi32(xmm_a6);
			__m128i xmm_b7 = _mm_cvttpd_epi32(xmm_a7);
			__m128i xmm_b8 = _mm_cvttpd_epi32(xmm_a8);
			__m128i xmm_b9 = _mm_cvttpd_epi32(xmm_a9);
			__m128i xmm_ba = _mm_cvttpd_epi32(xmm_aa);
			__m128i xmm_bb = _mm_cvttpd_epi32(xmm_ab);
			__m128i xmm_bc = _mm_cvttpd_epi32(xmm_ac);
			__m128i xmm_bd = _mm_cvttpd_epi32(xmm_ad);
			__m128i xmm_be = _mm_cvttpd_epi32(xmm_ae);
			__m128i xmm_bf = _mm_cvttpd_epi32(xmm_af);
			xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
			xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
			xmm_b4 = _mm_unpacklo_epi64(xmm_b4, xmm_b5);
			xmm_b6 = _mm_unpacklo_epi64(xmm_b6, xmm_b7);
			xmm_b8 = _mm_unpacklo_epi64(xmm_b8, xmm_b9);
			xmm_ba = _mm_unpacklo_epi64(xmm_ba, xmm_bb);
			xmm_bc = _mm_unpacklo_epi64(xmm_bc, xmm_bd);
			xmm_be = _mm_unpacklo_epi64(xmm_be, xmm_bf);
			xmm_b0 = _mm_packs_epi32(xmm_b0, xmm_b2);
			xmm_b4 = _mm_packs_epi32(xmm_b4, xmm_b6);
			xmm_b8 = _mm_packs_epi32(xmm_b8, xmm_ba);
			xmm_bc = _mm_packs_epi32(xmm_bc, xmm_be);
			xmm_b0 = _mm_packs_epi16(xmm_b0, xmm_b4);
			xmm_b8 = _mm_packs_epi16(xmm_b8, xmm_bc);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b8);
		}

		template <>
		inline void cvtspd_sse41_32<unsigned char>(unsigned char* b, const double* a)
		{
			const __m128d min = _mm_setzero_pd();
			const __m128d max = _mm_set1_pd(static_cast<double>(UINT8_MAX));
			__m128d xmm_a0 = _mm_loadu_pd(a);
			__m128d xmm_a1 = _mm_loadu_pd(a + 2);
			__m128d xmm_a2 = _mm_loadu_pd(a + 4);
			__m128d xmm_a3 = _mm_loadu_pd(a + 6);
			__m128d xmm_a4 = _mm_loadu_pd(a + 8);
			__m128d xmm_a5 = _mm_loadu_pd(a + 10);
			__m128d xmm_a6 = _mm_loadu_pd(a + 12);
			__m128d xmm_a7 = _mm_loadu_pd(a + 14);
			__m128d xmm_a8 = _mm_loadu_pd(a + 16);
			__m128d xmm_a9 = _mm_loadu_pd(a + 18);
			__m128d xmm_aa = _mm_loadu_pd(a + 20);
			__m128d xmm_ab = _mm_loadu_pd(a + 22);
			__m128d xmm_ac = _mm_loadu_pd(a + 24);
			__m128d xmm_ad = _mm_loadu_pd(a + 26);
			__m128d xmm_ae = _mm_loadu_pd(a + 28);
			__m128d xmm_af = _mm_loadu_pd(a + 30);
			xmm_a0 = _mm_max_pd(xmm_a0, min);
			xmm_a1 = _mm_max_pd(xmm_a1, min);
			xmm_a2 = _mm_max_pd(xmm_a2, min);
			xmm_a3 = _mm_max_pd(xmm_a3, min);
			xmm_a4 = _mm_max_pd(xmm_a4, min);
			xmm_a5 = _mm_max_pd(xmm_a5, min);
			xmm_a6 = _mm_max_pd(xmm_a6, min);
			xmm_a7 = _mm_max_pd(xmm_a7, min);
			xmm_a8 = _mm_max_pd(xmm_a8, min);
			xmm_a9 = _mm_max_pd(xmm_a9, min);
			xmm_aa = _mm_max_pd(xmm_aa, min);
			xmm_ab = _mm_max_pd(xmm_ab, min);
			xmm_ac = _mm_max_pd(xmm_ac, min);
			xmm_ad = _mm_max_pd(xmm_ad, min);
			xmm_ae = _mm_max_pd(xmm_ae, min);
			xmm_af = _mm_max_pd(xmm_af, min);
			xmm_a0 = _mm_min_pd(xmm_a0, max);
			xmm_a1 = _mm_min_pd(xmm_a1, max);
			xmm_a2 = _mm_min_pd(xmm_a2, max);
			xmm_a3 = _mm_min_pd(xmm_a3, max);
			xmm_a4 = _mm_min_pd(xmm_a4, max);
			xmm_a5 = _mm_min_pd(xmm_a5, max);
			xmm_a6 = _mm_min_pd(xmm_a6, max);
			xmm_a7 = _mm_min_pd(xmm_a7, max);
			xmm_a8 = _mm_min_pd(xmm_a8, max);
			xmm_a9 = _mm_min_pd(xmm_a9, max);
			xmm_aa = _mm_min_pd(xmm_aa, max);
			xmm_ab = _mm_min_pd(xmm_ab, max);
			xmm_ac = _mm_min_pd(xmm_ac, max);
			xmm_ad = _mm_min_pd(xmm_ad, max);
			xmm_ae = _mm_min_pd(xmm_ae, max);
			xmm_af = _mm_min_pd(xmm_af, max);
			__m128i xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
			__m128i xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
			__m128i xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
			__m128i xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
			__m128i xmm_b4 = _mm_cvttpd_epi32(xmm_a4);
			__m128i xmm_b5 = _mm_cvttpd_epi32(xmm_a5);
			__m128i xmm_b6 = _mm_cvttpd_epi32(xmm_a6);
			__m128i xmm_b7 = _mm_cvttpd_epi32(xmm_a7);
			__m128i xmm_b8 = _mm_cvttpd_epi32(xmm_a8);
			__m128i xmm_b9 = _mm_cvttpd_epi32(xmm_a9);
			__m128i xmm_ba = _mm_cvttpd_epi32(xmm_aa);
			__m128i xmm_bb = _mm_cvttpd_epi32(xmm_ab);
			__m128i xmm_bc = _mm_cvttpd_epi32(xmm_ac);
			__m128i xmm_bd = _mm_cvttpd_epi32(xmm_ad);
			__m128i xmm_be = _mm_cvttpd_epi32(xmm_ae);
			__m128i xmm_bf = _mm_cvttpd_epi32(xmm_af);
			xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
			xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
			xmm_b4 = _mm_unpacklo_epi64(xmm_b4, xmm_b5);
			xmm_b6 = _mm_unpacklo_epi64(xmm_b6, xmm_b7);
			xmm_b8 = _mm_unpacklo_epi64(xmm_b8, xmm_b9);
			xmm_ba = _mm_unpacklo_epi64(xmm_ba, xmm_bb);
			xmm_bc = _mm_unpacklo_epi64(xmm_bc, xmm_bd);
			xmm_be = _mm_unpacklo_epi64(xmm_be, xmm_bf);
			xmm_b0 = _mm_packus_epi32(xmm_b0, xmm_b2);
			xmm_b4 = _mm_packus_epi32(xmm_b4, xmm_b6);
			xmm_b8 = _mm_packus_epi32(xmm_b8, xmm_ba);
			xmm_bc = _mm_packus_epi32(xmm_bc, xmm_be);
			xmm_b0 = _mm_packus_epi16(xmm_b0, xmm_b4);
			xmm_b8 = _mm_packus_epi16(xmm_b8, xmm_bc);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b8);
		}

		template <>
		inline void cvtspd_sse41_32<signed short>(signed short* b, const double* a)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(INT16_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT16_MAX));
			__m128d xmm_a0 = _mm_loadu_pd(a);
			__m128d xmm_a1 = _mm_loadu_pd(a + 2);
			__m128d xmm_a2 = _mm_loadu_pd(a + 4);
			__m128d xmm_a3 = _mm_loadu_pd(a + 6);
			__m128d xmm_a4 = _mm_loadu_pd(a + 8);
			__m128d xmm_a5 = _mm_loadu_pd(a + 10);
			__m128d xmm_a6 = _mm_loadu_pd(a + 12);
			__m128d xmm_a7 = _mm_loadu_pd(a + 14);
			__m128d xmm_a8 = _mm_loadu_pd(a + 16);
			__m128d xmm_a9 = _mm_loadu_pd(a + 18);
			__m128d xmm_aa = _mm_loadu_pd(a + 20);
			__m128d xmm_ab = _mm_loadu_pd(a + 22);
			__m128d xmm_ac = _mm_loadu_pd(a + 24);
			__m128d xmm_ad = _mm_loadu_pd(a + 26);
			__m128d xmm_ae = _mm_loadu_pd(a + 28);
			__m128d xmm_af = _mm_loadu_pd(a + 30);
			xmm_a0 = _mm_max_pd(xmm_a0, min);
			xmm_a1 = _mm_max_pd(xmm_a1, min);
			xmm_a2 = _mm_max_pd(xmm_a2, min);
			xmm_a3 = _mm_max_pd(xmm_a3, min);
			xmm_a4 = _mm_max_pd(xmm_a4, min);
			xmm_a5 = _mm_max_pd(xmm_a5, min);
			xmm_a6 = _mm_max_pd(xmm_a6, min);
			xmm_a7 = _mm_max_pd(xmm_a7, min);
			xmm_a8 = _mm_max_pd(xmm_a8, min);
			xmm_a9 = _mm_max_pd(xmm_a9, min);
			xmm_aa = _mm_max_pd(xmm_aa, min);
			xmm_ab = _mm_max_pd(xmm_ab, min);
			xmm_ac = _mm_max_pd(xmm_ac, min);
			xmm_ad = _mm_max_pd(xmm_ad, min);
			xmm_ae = _mm_max_pd(xmm_ae, min);
			xmm_af = _mm_max_pd(xmm_af, min);
			xmm_a0 = _mm_min_pd(xmm_a0, max);
			xmm_a1 = _mm_min_pd(xmm_a1, max);
			xmm_a2 = _mm_min_pd(xmm_a2, max);
			xmm_a3 = _mm_min_pd(xmm_a3, max);
			xmm_a4 = _mm_min_pd(xmm_a4, max);
			xmm_a5 = _mm_min_pd(xmm_a5, max);
			xmm_a6 = _mm_min_pd(xmm_a6, max);
			xmm_a7 = _mm_min_pd(xmm_a7, max);
			xmm_a8 = _mm_min_pd(xmm_a8, max);
			xmm_a9 = _mm_min_pd(xmm_a9, max);
			xmm_aa = _mm_min_pd(xmm_aa, max);
			xmm_ab = _mm_min_pd(xmm_ab, max);
			xmm_ac = _mm_min_pd(xmm_ac, max);
			xmm_ad = _mm_min_pd(xmm_ad, max);
			xmm_ae = _mm_min_pd(xmm_ae, max);
			xmm_af = _mm_min_pd(xmm_af, max);
			__m128i xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
			__m128i xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
			__m128i xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
			__m128i xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
			__m128i xmm_b4 = _mm_cvttpd_epi32(xmm_a4);
			__m128i xmm_b5 = _mm_cvttpd_epi32(xmm_a5);
			__m128i xmm_b6 = _mm_cvttpd_epi32(xmm_a6);
			__m128i xmm_b7 = _mm_cvttpd_epi32(xmm_a7);
			__m128i xmm_b8 = _mm_cvttpd_epi32(xmm_a8);
			__m128i xmm_b9 = _mm_cvttpd_epi32(xmm_a9);
			__m128i xmm_ba = _mm_cvttpd_epi32(xmm_aa);
			__m128i xmm_bb = _mm_cvttpd_epi32(xmm_ab);
			__m128i xmm_bc = _mm_cvttpd_epi32(xmm_ac);
			__m128i xmm_bd = _mm_cvttpd_epi32(xmm_ad);
			__m128i xmm_be = _mm_cvttpd_epi32(xmm_ae);
			__m128i xmm_bf = _mm_cvttpd_epi32(xmm_af);
			xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
			xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
			xmm_b4 = _mm_unpacklo_epi64(xmm_b4, xmm_b5);
			xmm_b6 = _mm_unpacklo_epi64(xmm_b6, xmm_b7);
			xmm_b8 = _mm_unpacklo_epi64(xmm_b8, xmm_b9);
			xmm_ba = _mm_unpacklo_epi64(xmm_ba, xmm_bb);
			xmm_bc = _mm_unpacklo_epi64(xmm_bc, xmm_bd);
			xmm_be = _mm_unpacklo_epi64(xmm_be, xmm_bf);
			xmm_b0 = _mm_packs_epi32(xmm_b0, xmm_b2);
			xmm_b4 = _mm_packs_epi32(xmm_b4, xmm_b6);
			xmm_b8 = _mm_packs_epi32(xmm_b8, xmm_ba);
			xmm_bc = _mm_packs_epi32(xmm_bc, xmm_be);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b4);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 2, xmm_b8);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 3, xmm_bc);
		}

		template <>
		inline void cvtspd_sse41_32<unsigned short>(unsigned short* b, const double* a)
		{
			const __m128d min = _mm_setzero_pd();
			const __m128d max = _mm_set1_pd(static_cast<double>(UINT16_MAX));
			__m128d xmm_a0 = _mm_loadu_pd(a);
			__m128d xmm_a1 = _mm_loadu_pd(a + 2);
			__m128d xmm_a2 = _mm_loadu_pd(a + 4);
			__m128d xmm_a3 = _mm_loadu_pd(a + 6);
			__m128d xmm_a4 = _mm_loadu_pd(a + 8);
			__m128d xmm_a5 = _mm_loadu_pd(a + 10);
			__m128d xmm_a6 = _mm_loadu_pd(a + 12);
			__m128d xmm_a7 = _mm_loadu_pd(a + 14);
			__m128d xmm_a8 = _mm_loadu_pd(a + 16);
			__m128d xmm_a9 = _mm_loadu_pd(a + 18);
			__m128d xmm_aa = _mm_loadu_pd(a + 20);
			__m128d xmm_ab = _mm_loadu_pd(a + 22);
			__m128d xmm_ac = _mm_loadu_pd(a + 24);
			__m128d xmm_ad = _mm_loadu_pd(a + 26);
			__m128d xmm_ae = _mm_loadu_pd(a + 28);
			__m128d xmm_af = _mm_loadu_pd(a + 30);
			xmm_a0 = _mm_max_pd(xmm_a0, min);
			xmm_a1 = _mm_max_pd(xmm_a1, min);
			xmm_a2 = _mm_max_pd(xmm_a2, min);
			xmm_a3 = _mm_max_pd(xmm_a3, min);
			xmm_a4 = _mm_max_pd(xmm_a4, min);
			xmm_a5 = _mm_max_pd(xmm_a5, min);
			xmm_a6 = _mm_max_pd(xmm_a6, min);
			xmm_a7 = _mm_max_pd(xmm_a7, min);
			xmm_a8 = _mm_max_pd(xmm_a8, min);
			xmm_a9 = _mm_max_pd(xmm_a9, min);
			xmm_aa = _mm_max_pd(xmm_aa, min);
			xmm_ab = _mm_max_pd(xmm_ab, min);
			xmm_ac = _mm_max_pd(xmm_ac, min);
			xmm_ad = _mm_max_pd(xmm_ad, min);
			xmm_ae = _mm_max_pd(xmm_ae, min);
			xmm_af = _mm_max_pd(xmm_af, min);
			xmm_a0 = _mm_min_pd(xmm_a0, max);
			xmm_a1 = _mm_min_pd(xmm_a1, max);
			xmm_a2 = _mm_min_pd(xmm_a2, max);
			xmm_a3 = _mm_min_pd(xmm_a3, max);
			xmm_a4 = _mm_min_pd(xmm_a4, max);
			xmm_a5 = _mm_min_pd(xmm_a5, max);
			xmm_a6 = _mm_min_pd(xmm_a6, max);
			xmm_a7 = _mm_min_pd(xmm_a7, max);
			xmm_a8 = _mm_min_pd(xmm_a8, max);
			xmm_a9 = _mm_min_pd(xmm_a9, max);
			xmm_aa = _mm_min_pd(xmm_aa, max);
			xmm_ab = _mm_min_pd(xmm_ab, max);
			xmm_ac = _mm_min_pd(xmm_ac, max);
			xmm_ad = _mm_min_pd(xmm_ad, max);
			xmm_ae = _mm_min_pd(xmm_ae, max);
			xmm_af = _mm_min_pd(xmm_af, max);
			__m128i xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
			__m128i xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
			__m128i xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
			__m128i xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
			__m128i xmm_b4 = _mm_cvttpd_epi32(xmm_a4);
			__m128i xmm_b5 = _mm_cvttpd_epi32(xmm_a5);
			__m128i xmm_b6 = _mm_cvttpd_epi32(xmm_a6);
			__m128i xmm_b7 = _mm_cvttpd_epi32(xmm_a7);
			__m128i xmm_b8 = _mm_cvttpd_epi32(xmm_a8);
			__m128i xmm_b9 = _mm_cvttpd_epi32(xmm_a9);
			__m128i xmm_ba = _mm_cvttpd_epi32(xmm_aa);
			__m128i xmm_bb = _mm_cvttpd_epi32(xmm_ab);
			__m128i xmm_bc = _mm_cvttpd_epi32(xmm_ac);
			__m128i xmm_bd = _mm_cvttpd_epi32(xmm_ad);
			__m128i xmm_be = _mm_cvttpd_epi32(xmm_ae);
			__m128i xmm_bf = _mm_cvttpd_epi32(xmm_af);
			xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
			xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
			xmm_b4 = _mm_unpacklo_epi64(xmm_b4, xmm_b5);
			xmm_b6 = _mm_unpacklo_epi64(xmm_b6, xmm_b7);
			xmm_b8 = _mm_unpacklo_epi64(xmm_b8, xmm_b9);
			xmm_ba = _mm_unpacklo_epi64(xmm_ba, xmm_bb);
			xmm_bc = _mm_unpacklo_epi64(xmm_bc, xmm_bd);
			xmm_be = _mm_unpacklo_epi64(xmm_be, xmm_bf);
			xmm_b0 = _mm_packus_epi32(xmm_b0, xmm_b2);
			xmm_b4 = _mm_packus_epi32(xmm_b4, xmm_b6);
			xmm_b8 = _mm_packus_epi32(xmm_b8, xmm_ba);
			xmm_bc = _mm_packus_epi32(xmm_bc, xmm_be);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b4);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 2, xmm_b8);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 3, xmm_bc);
		}

		template <>
		inline void cvtspd_sse41_32<signed int>(signed int* b, const double* a)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(INT32_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT32_MAX));
			__m128d xmm_a0 = _mm_loadu_pd(a);
			__m128d xmm_a1 = _mm_loadu_pd(a + 2);
			__m128d xmm_a2 = _mm_loadu_pd(a + 4);
			__m128d xmm_a3 = _mm_loadu_pd(a + 6);
			__m128d xmm_a4 = _mm_loadu_pd(a + 8);
			__m128d xmm_a5 = _mm_loadu_pd(a + 10);
			__m128d xmm_a6 = _mm_loadu_pd(a + 12);
			__m128d xmm_a7 = _mm_loadu_pd(a + 14);
			__m128d xmm_a8 = _mm_loadu_pd(a + 16);
			__m128d xmm_a9 = _mm_loadu_pd(a + 18);
			__m128d xmm_aa = _mm_loadu_pd(a + 20);
			__m128d xmm_ab = _mm_loadu_pd(a + 22);
			__m128d xmm_ac = _mm_loadu_pd(a + 24);
			__m128d xmm_ad = _mm_loadu_pd(a + 26);
			__m128d xmm_ae = _mm_loadu_pd(a + 28);
			__m128d xmm_af = _mm_loadu_pd(a + 30);
			xmm_a0 = _mm_max_pd(xmm_a0, min);
			xmm_a1 = _mm_max_pd(xmm_a1, min);
			xmm_a2 = _mm_max_pd(xmm_a2, min);
			xmm_a3 = _mm_max_pd(xmm_a3, min);
			xmm_a4 = _mm_max_pd(xmm_a4, min);
			xmm_a5 = _mm_max_pd(xmm_a5, min);
			xmm_a6 = _mm_max_pd(xmm_a6, min);
			xmm_a7 = _mm_max_pd(xmm_a7, min);
			xmm_a8 = _mm_max_pd(xmm_a8, min);
			xmm_a9 = _mm_max_pd(xmm_a9, min);
			xmm_aa = _mm_max_pd(xmm_aa, min);
			xmm_ab = _mm_max_pd(xmm_ab, min);
			xmm_ac = _mm_max_pd(xmm_ac, min);
			xmm_ad = _mm_max_pd(xmm_ad, min);
			xmm_ae = _mm_max_pd(xmm_ae, min);
			xmm_af = _mm_max_pd(xmm_af, min);
			xmm_a0 = _mm_min_pd(xmm_a0, max);
			xmm_a1 = _mm_min_pd(xmm_a1, max);
			xmm_a2 = _mm_min_pd(xmm_a2, max);
			xmm_a3 = _mm_min_pd(xmm_a3, max);
			xmm_a4 = _mm_min_pd(xmm_a4, max);
			xmm_a5 = _mm_min_pd(xmm_a5, max);
			xmm_a6 = _mm_min_pd(xmm_a6, max);
			xmm_a7 = _mm_min_pd(xmm_a7, max);
			xmm_a8 = _mm_min_pd(xmm_a8, max);
			xmm_a9 = _mm_min_pd(xmm_a9, max);
			xmm_aa = _mm_min_pd(xmm_aa, max);
			xmm_ab = _mm_min_pd(xmm_ab, max);
			xmm_ac = _mm_min_pd(xmm_ac, max);
			xmm_ad = _mm_min_pd(xmm_ad, max);
			xmm_ae = _mm_min_pd(xmm_ae, max);
			xmm_af = _mm_min_pd(xmm_af, max);
			__m128i xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
			__m128i xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
			__m128i xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
			__m128i xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
			__m128i xmm_b4 = _mm_cvttpd_epi32(xmm_a4);
			__m128i xmm_b5 = _mm_cvttpd_epi32(xmm_a5);
			__m128i xmm_b6 = _mm_cvttpd_epi32(xmm_a6);
			__m128i xmm_b7 = _mm_cvttpd_epi32(xmm_a7);
			__m128i xmm_b8 = _mm_cvttpd_epi32(xmm_a8);
			__m128i xmm_b9 = _mm_cvttpd_epi32(xmm_a9);
			__m128i xmm_ba = _mm_cvttpd_epi32(xmm_aa);
			__m128i xmm_bb = _mm_cvttpd_epi32(xmm_ab);
			__m128i xmm_bc = _mm_cvttpd_epi32(xmm_ac);
			__m128i xmm_bd = _mm_cvttpd_epi32(xmm_ad);
			__m128i xmm_be = _mm_cvttpd_epi32(xmm_ae);
			__m128i xmm_bf = _mm_cvttpd_epi32(xmm_af);
			xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
			xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
			xmm_b4 = _mm_unpacklo_epi64(xmm_b4, xmm_b5);
			xmm_b6 = _mm_unpacklo_epi64(xmm_b6, xmm_b7);
			xmm_b8 = _mm_unpacklo_epi64(xmm_b8, xmm_b9);
			xmm_ba = _mm_unpacklo_epi64(xmm_ba, xmm_bb);
			xmm_bc = _mm_unpacklo_epi64(xmm_bc, xmm_bd);
			xmm_be = _mm_unpacklo_epi64(xmm_be, xmm_bf);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 2, xmm_b4);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 3, xmm_b6);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 4, xmm_b8);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 5, xmm_ba);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 6, xmm_bc);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 7, xmm_be);
		}

		template <>
		inline void cvtspd_sse41_32<unsigned int>(unsigned int* b, const double* a)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(INT32_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT32_MAX));
			const __m128d offset = _mm_set1_pd(2.147483648e+9);
			const __m128i shift = _mm_set1_epi32(2147483648);
			__m128d xmm_a0 = _mm_loadu_pd(a);
			__m128d xmm_a1 = _mm_loadu_pd(a + 2);
			__m128d xmm_a2 = _mm_loadu_pd(a + 4);
			__m128d xmm_a3 = _mm_loadu_pd(a + 6);
			__m128d xmm_a4 = _mm_loadu_pd(a + 8);
			__m128d xmm_a5 = _mm_loadu_pd(a + 10);
			__m128d xmm_a6 = _mm_loadu_pd(a + 12);
			__m128d xmm_a7 = _mm_loadu_pd(a + 14);
			__m128d xmm_a8 = _mm_loadu_pd(a + 16);
			__m128d xmm_a9 = _mm_loadu_pd(a + 18);
			__m128d xmm_aa = _mm_loadu_pd(a + 20);
			__m128d xmm_ab = _mm_loadu_pd(a + 22);
			__m128d xmm_ac = _mm_loadu_pd(a + 24);
			__m128d xmm_ad = _mm_loadu_pd(a + 26);
			__m128d xmm_ae = _mm_loadu_pd(a + 28);
			__m128d xmm_af = _mm_loadu_pd(a + 30);
			xmm_a0 = _mm_sub_pd(xmm_a0, offset);
			xmm_a1 = _mm_sub_pd(xmm_a1, offset);
			xmm_a2 = _mm_sub_pd(xmm_a2, offset);
			xmm_a3 = _mm_sub_pd(xmm_a3, offset);
			xmm_a4 = _mm_sub_pd(xmm_a4, offset);
			xmm_a5 = _mm_sub_pd(xmm_a5, offset);
			xmm_a6 = _mm_sub_pd(xmm_a6, offset);
			xmm_a7 = _mm_sub_pd(xmm_a7, offset);
			xmm_a8 = _mm_sub_pd(xmm_a8, offset);
			xmm_a9 = _mm_sub_pd(xmm_a9, offset);
			xmm_aa = _mm_sub_pd(xmm_aa, offset);
			xmm_ab = _mm_sub_pd(xmm_ab, offset);
			xmm_ac = _mm_sub_pd(xmm_ac, offset);
			xmm_ad = _mm_sub_pd(xmm_ad, offset);
			xmm_ae = _mm_sub_pd(xmm_ae, offset);
			xmm_af = _mm_sub_pd(xmm_af, offset);
			xmm_a0 = _mm_max_pd(xmm_a0, min);
			xmm_a1 = _mm_max_pd(xmm_a1, min);
			xmm_a2 = _mm_max_pd(xmm_a2, min);
			xmm_a3 = _mm_max_pd(xmm_a3, min);
			xmm_a4 = _mm_max_pd(xmm_a4, min);
			xmm_a5 = _mm_max_pd(xmm_a5, min);
			xmm_a6 = _mm_max_pd(xmm_a6, min);
			xmm_a7 = _mm_max_pd(xmm_a7, min);
			xmm_a8 = _mm_max_pd(xmm_a8, min);
			xmm_a9 = _mm_max_pd(xmm_a9, min);
			xmm_aa = _mm_max_pd(xmm_aa, min);
			xmm_ab = _mm_max_pd(xmm_ab, min);
			xmm_ac = _mm_max_pd(xmm_ac, min);
			xmm_ad = _mm_max_pd(xmm_ad, min);
			xmm_ae = _mm_max_pd(xmm_ae, min);
			xmm_af = _mm_max_pd(xmm_af, min);
			xmm_a0 = _mm_min_pd(xmm_a0, max);
			xmm_a1 = _mm_min_pd(xmm_a1, max);
			xmm_a2 = _mm_min_pd(xmm_a2, max);
			xmm_a3 = _mm_min_pd(xmm_a3, max);
			xmm_a4 = _mm_min_pd(xmm_a4, max);
			xmm_a5 = _mm_min_pd(xmm_a5, max);
			xmm_a6 = _mm_min_pd(xmm_a6, max);
			xmm_a7 = _mm_min_pd(xmm_a7, max);
			xmm_a8 = _mm_min_pd(xmm_a8, max);
			xmm_a9 = _mm_min_pd(xmm_a9, max);
			xmm_aa = _mm_min_pd(xmm_aa, max);
			xmm_ab = _mm_min_pd(xmm_ab, max);
			xmm_ac = _mm_min_pd(xmm_ac, max);
			xmm_ad = _mm_min_pd(xmm_ad, max);
			xmm_ae = _mm_min_pd(xmm_ae, max);
			xmm_af = _mm_min_pd(xmm_af, max);
			__m128i xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
			__m128i xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
			__m128i xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
			__m128i xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
			__m128i xmm_b4 = _mm_cvttpd_epi32(xmm_a4);
			__m128i xmm_b5 = _mm_cvttpd_epi32(xmm_a5);
			__m128i xmm_b6 = _mm_cvttpd_epi32(xmm_a6);
			__m128i xmm_b7 = _mm_cvttpd_epi32(xmm_a7);
			__m128i xmm_b8 = _mm_cvttpd_epi32(xmm_a8);
			__m128i xmm_b9 = _mm_cvttpd_epi32(xmm_a9);
			__m128i xmm_ba = _mm_cvttpd_epi32(xmm_aa);
			__m128i xmm_bb = _mm_cvttpd_epi32(xmm_ab);
			__m128i xmm_bc = _mm_cvttpd_epi32(xmm_ac);
			__m128i xmm_bd = _mm_cvttpd_epi32(xmm_ad);
			__m128i xmm_be = _mm_cvttpd_epi32(xmm_ae);
			__m128i xmm_bf = _mm_cvttpd_epi32(xmm_af);
			xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
			xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
			xmm_b4 = _mm_unpacklo_epi64(xmm_b4, xmm_b5);
			xmm_b6 = _mm_unpacklo_epi64(xmm_b6, xmm_b7);
			xmm_b8 = _mm_unpacklo_epi64(xmm_b8, xmm_b9);
			xmm_ba = _mm_unpacklo_epi64(xmm_ba, xmm_bb);
			xmm_bc = _mm_unpacklo_epi64(xmm_bc, xmm_bd);
			xmm_be = _mm_unpacklo_epi64(xmm_be, xmm_bf);
			xmm_b0 = _mm_add_epi32(xmm_b0, shift);
			xmm_b2 = _mm_add_epi32(xmm_b2, shift);
			xmm_b4 = _mm_add_epi32(xmm_b4, shift);
			xmm_b6 = _mm_add_epi32(xmm_b6, shift);
			xmm_b8 = _mm_add_epi32(xmm_b8, shift);
			xmm_ba = _mm_add_epi32(xmm_ba, shift);
			xmm_bc = _mm_add_epi32(xmm_bc, shift);
			xmm_be = _mm_add_epi32(xmm_be, shift);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 2, xmm_b4);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 3, xmm_b6);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 4, xmm_b8);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 5, xmm_ba);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 6, xmm_bc);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 7, xmm_be);
		}

		template <>
		inline void cvtspd_sse41_32<float>(float* b, const double* a)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(-FLT_MAX));
			const __m128d max = _mm_set1_pd(static_cast<double>(FLT_MAX));
			__m128d xmm_a0 = _mm_loadu_pd(a);
			__m128d xmm_a1 = _mm_loadu_pd(a + 2);
			__m128d xmm_a2 = _mm_loadu_pd(a + 4);
			__m128d xmm_a3 = _mm_loadu_pd(a + 6);
			__m128d xmm_a4 = _mm_loadu_pd(a + 8);
			__m128d xmm_a5 = _mm_loadu_pd(a + 10);
			__m128d xmm_a6 = _mm_loadu_pd(a + 12);
			__m128d xmm_a7 = _mm_loadu_pd(a + 14);
			__m128d xmm_a8 = _mm_loadu_pd(a + 16);
			__m128d xmm_a9 = _mm_loadu_pd(a + 18);
			__m128d xmm_aa = _mm_loadu_pd(a + 20);
			__m128d xmm_ab = _mm_loadu_pd(a + 22);
			__m128d xmm_ac = _mm_loadu_pd(a + 24);
			__m128d xmm_ad = _mm_loadu_pd(a + 26);
			__m128d xmm_ae = _mm_loadu_pd(a + 28);
			__m128d xmm_af = _mm_loadu_pd(a + 30);
			xmm_a0 = _mm_max_pd(xmm_a0, min);
			xmm_a1 = _mm_max_pd(xmm_a1, min);
			xmm_a2 = _mm_max_pd(xmm_a2, min);
			xmm_a3 = _mm_max_pd(xmm_a3, min);
			xmm_a4 = _mm_max_pd(xmm_a4, min);
			xmm_a5 = _mm_max_pd(xmm_a5, min);
			xmm_a6 = _mm_max_pd(xmm_a6, min);
			xmm_a7 = _mm_max_pd(xmm_a7, min);
			xmm_a8 = _mm_max_pd(xmm_a8, min);
			xmm_a9 = _mm_max_pd(xmm_a9, min);
			xmm_aa = _mm_max_pd(xmm_aa, min);
			xmm_ab = _mm_max_pd(xmm_ab, min);
			xmm_ac = _mm_max_pd(xmm_ac, min);
			xmm_ad = _mm_max_pd(xmm_ad, min);
			xmm_ae = _mm_max_pd(xmm_ae, min);
			xmm_af = _mm_max_pd(xmm_af, min);
			xmm_a0 = _mm_min_pd(xmm_a0, max);
			xmm_a1 = _mm_min_pd(xmm_a1, max);
			xmm_a2 = _mm_min_pd(xmm_a2, max);
			xmm_a3 = _mm_min_pd(xmm_a3, max);
			xmm_a4 = _mm_min_pd(xmm_a4, max);
			xmm_a5 = _mm_min_pd(xmm_a5, max);
			xmm_a6 = _mm_min_pd(xmm_a6, max);
			xmm_a7 = _mm_min_pd(xmm_a7, max);
			xmm_a8 = _mm_min_pd(xmm_a8, max);
			xmm_a9 = _mm_min_pd(xmm_a9, max);
			xmm_aa = _mm_min_pd(xmm_aa, max);
			xmm_ab = _mm_min_pd(xmm_ab, max);
			xmm_ac = _mm_min_pd(xmm_ac, max);
			xmm_ad = _mm_min_pd(xmm_ad, max);
			xmm_ae = _mm_min_pd(xmm_ae, max);
			xmm_af = _mm_min_pd(xmm_af, max);
			__m128 xmm_b0 = _mm_cvtpd_ps(xmm_a0);
			__m128 xmm_b1 = _mm_cvtpd_ps(xmm_a1);
			__m128 xmm_b2 = _mm_cvtpd_ps(xmm_a2);
			__m128 xmm_b3 = _mm_cvtpd_ps(xmm_a3);
			__m128 xmm_b4 = _mm_cvtpd_ps(xmm_a4);
			__m128 xmm_b5 = _mm_cvtpd_ps(xmm_a5);
			__m128 xmm_b6 = _mm_cvtpd_ps(xmm_a6);
			__m128 xmm_b7 = _mm_cvtpd_ps(xmm_a7);
			__m128 xmm_b8 = _mm_cvtpd_ps(xmm_a8);
			__m128 xmm_b9 = _mm_cvtpd_ps(xmm_a9);
			__m128 xmm_ba = _mm_cvtpd_ps(xmm_aa);
			__m128 xmm_bb = _mm_cvtpd_ps(xmm_ab);
			__m128 xmm_bc = _mm_cvtpd_ps(xmm_ac);
			__m128 xmm_bd = _mm_cvtpd_ps(xmm_ad);
			__m128 xmm_be = _mm_cvtpd_ps(xmm_ae);
			__m128 xmm_bf = _mm_cvtpd_ps(xmm_af);
			xmm_b0 = _mm_shuffle_ps(xmm_b0, xmm_b1, _MM_SHUFFLE(1, 0, 1, 0));
			xmm_b2 = _mm_shuffle_ps(xmm_b2, xmm_b3, _MM_SHUFFLE(1, 0, 1, 0));
			xmm_b4 = _mm_shuffle_ps(xmm_b4, xmm_b5, _MM_SHUFFLE(1, 0, 1, 0));
			xmm_b6 = _mm_shuffle_ps(xmm_b6, xmm_b7, _MM_SHUFFLE(1, 0, 1, 0));
			xmm_b8 = _mm_shuffle_ps(xmm_b8, xmm_b9, _MM_SHUFFLE(1, 0, 1, 0));
			xmm_ba = _mm_shuffle_ps(xmm_ba, xmm_bb, _MM_SHUFFLE(1, 0, 1, 0));
			xmm_bc = _mm_shuffle_ps(xmm_bc, xmm_bd, _MM_SHUFFLE(1, 0, 1, 0));
			xmm_be = _mm_shuffle_ps(xmm_be, xmm_bf, _MM_SHUFFLE(1, 0, 1, 0));
			_mm_storeu_ps(b, xmm_b0);
			_mm_storeu_ps(b + 4, xmm_b2);
			_mm_storeu_ps(b + 8, xmm_b4);
			_mm_storeu_ps(b + 12, xmm_b6);
			_mm_storeu_ps(b + 16, xmm_b8);
			_mm_storeu_ps(b + 20, xmm_ba);
			_mm_storeu_ps(b + 24, xmm_bc);
			_mm_storeu_ps(b + 28, xmm_be);
		}

		// Function template cvtspd_sse41_small

		template <class T>
		void cvtspd_sse41_small(T* b, const double* a, size_t n)
		{
			switch (n >> 3)
			{
			case 4:
				cvtspd_sse41_32(b, a);
			case 0:
				break;
			case 5:
				cvtspd_sse41_32(b, a);
				a += 32;
				b += 32;
			case 1:
				cvtspd_sse41_8(b, a);
				break;
			case 6:
				cvtspd_sse41_32(b, a);
				a += 32;
				b += 32;
			case 2:
				cvtspd_sse41_16(b, a);
				break;
			case 7:
				cvtspd_sse41_32(b, a);
				a += 32;
				b += 32;
			case 3:
				cvtspd_sse41_16(b, a);
				a += 16;
				b += 16;
				cvtspd_sse41_8(b, a);
				break;
			}
			cvtspd_tiny(b, a, n & 7);
		}

		// Function template cvtspd_sse41_medium

		template <class T>
		inline void cvtspd_sse41_medium(T* b, const double* a, size_t n)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		void cvtspd_sse41_medium<signed char>(signed char* b, const double* a, size_t n)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(INT8_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT8_MAX));
			__m128d xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m128d xmm_a8, xmm_a9, xmm_aa, xmm_ab, xmm_ac, xmm_ad, xmm_ae, xmm_af;
			__m128i xmm_b0, xmm_b1, xmm_b2, xmm_b3, xmm_b4, xmm_b5, xmm_b6, xmm_b7;
			__m128i xmm_b8, xmm_b9, xmm_ba, xmm_bb, xmm_bc, xmm_bd, xmm_be, xmm_bf;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				xmm_a0 = _mm_loadu_pd(a);
				xmm_a1 = _mm_loadu_pd(a + 2);
				xmm_a2 = _mm_loadu_pd(a + 4);
				xmm_a3 = _mm_loadu_pd(a + 6);
				xmm_a4 = _mm_loadu_pd(a + 8);
				xmm_a5 = _mm_loadu_pd(a + 10);
				xmm_a6 = _mm_loadu_pd(a + 12);
				xmm_a7 = _mm_loadu_pd(a + 14);
				xmm_a8 = _mm_loadu_pd(a + 16);
				xmm_a9 = _mm_loadu_pd(a + 18);
				xmm_aa = _mm_loadu_pd(a + 20);
				xmm_ab = _mm_loadu_pd(a + 22);
				xmm_ac = _mm_loadu_pd(a + 24);
				xmm_ad = _mm_loadu_pd(a + 26);
				xmm_ae = _mm_loadu_pd(a + 28);
				xmm_af = _mm_loadu_pd(a + 30);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
				xmm_a0 = _mm_max_pd(xmm_a0, min);
				xmm_a1 = _mm_max_pd(xmm_a1, min);
				xmm_a2 = _mm_max_pd(xmm_a2, min);
				xmm_a3 = _mm_max_pd(xmm_a3, min);
				xmm_a4 = _mm_max_pd(xmm_a4, min);
				xmm_a5 = _mm_max_pd(xmm_a5, min);
				xmm_a6 = _mm_max_pd(xmm_a6, min);
				xmm_a7 = _mm_max_pd(xmm_a7, min);
				xmm_a8 = _mm_max_pd(xmm_a8, min);
				xmm_a9 = _mm_max_pd(xmm_a9, min);
				xmm_aa = _mm_max_pd(xmm_aa, min);
				xmm_ab = _mm_max_pd(xmm_ab, min);
				xmm_ac = _mm_max_pd(xmm_ac, min);
				xmm_ad = _mm_max_pd(xmm_ad, min);
				xmm_ae = _mm_max_pd(xmm_ae, min);
				xmm_af = _mm_max_pd(xmm_af, min);
				xmm_a0 = _mm_min_pd(xmm_a0, max);
				xmm_a1 = _mm_min_pd(xmm_a1, max);
				xmm_a2 = _mm_min_pd(xmm_a2, max);
				xmm_a3 = _mm_min_pd(xmm_a3, max);
				xmm_a4 = _mm_min_pd(xmm_a4, max);
				xmm_a5 = _mm_min_pd(xmm_a5, max);
				xmm_a6 = _mm_min_pd(xmm_a6, max);
				xmm_a7 = _mm_min_pd(xmm_a7, max);
				xmm_a8 = _mm_min_pd(xmm_a8, max);
				xmm_a9 = _mm_min_pd(xmm_a9, max);
				xmm_aa = _mm_min_pd(xmm_aa, max);
				xmm_ab = _mm_min_pd(xmm_ab, max);
				xmm_ac = _mm_min_pd(xmm_ac, max);
				xmm_ad = _mm_min_pd(xmm_ad, max);
				xmm_ae = _mm_min_pd(xmm_ae, max);
				xmm_af = _mm_min_pd(xmm_af, max);
				xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
				xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
				xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
				xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
				xmm_b4 = _mm_cvttpd_epi32(xmm_a4);
				xmm_b5 = _mm_cvttpd_epi32(xmm_a5);
				xmm_b6 = _mm_cvttpd_epi32(xmm_a6);
				xmm_b7 = _mm_cvttpd_epi32(xmm_a7);
				xmm_b8 = _mm_cvttpd_epi32(xmm_a8);
				xmm_b9 = _mm_cvttpd_epi32(xmm_a9);
				xmm_ba = _mm_cvttpd_epi32(xmm_aa);
				xmm_bb = _mm_cvttpd_epi32(xmm_ab);
				xmm_bc = _mm_cvttpd_epi32(xmm_ac);
				xmm_bd = _mm_cvttpd_epi32(xmm_ad);
				xmm_be = _mm_cvttpd_epi32(xmm_ae);
				xmm_bf = _mm_cvttpd_epi32(xmm_af);
				xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
				xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
				xmm_b4 = _mm_unpacklo_epi64(xmm_b4, xmm_b5);
				xmm_b6 = _mm_unpacklo_epi64(xmm_b6, xmm_b7);
				xmm_b8 = _mm_unpacklo_epi64(xmm_b8, xmm_b9);
				xmm_ba = _mm_unpacklo_epi64(xmm_ba, xmm_bb);
				xmm_bc = _mm_unpacklo_epi64(xmm_bc, xmm_bd);
				xmm_be = _mm_unpacklo_epi64(xmm_be, xmm_bf);
				xmm_b0 = _mm_packs_epi32(xmm_b0, xmm_b2);
				xmm_b4 = _mm_packs_epi32(xmm_b4, xmm_b6);
				xmm_b8 = _mm_packs_epi32(xmm_b8, xmm_ba);
				xmm_bc = _mm_packs_epi32(xmm_bc, xmm_be);
				xmm_b0 = _mm_packs_epi16(xmm_b0, xmm_b4);
				xmm_b8 = _mm_packs_epi16(xmm_b8, xmm_bc);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b8);
				a += 32;
				b += 32;
			}
		}

		template <>
		void cvtspd_sse41_medium<unsigned char>(unsigned char* b, const double* a, size_t n)
		{
			const __m128d min = _mm_setzero_pd();
			const __m128d max = _mm_set1_pd(static_cast<double>(UINT8_MAX));
			__m128d xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m128d xmm_a8, xmm_a9, xmm_aa, xmm_ab, xmm_ac, xmm_ad, xmm_ae, xmm_af;
			__m128i xmm_b0, xmm_b1, xmm_b2, xmm_b3, xmm_b4, xmm_b5, xmm_b6, xmm_b7;
			__m128i xmm_b8, xmm_b9, xmm_ba, xmm_bb, xmm_bc, xmm_bd, xmm_be, xmm_bf;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				xmm_a0 = _mm_loadu_pd(a);
				xmm_a1 = _mm_loadu_pd(a + 2);
				xmm_a2 = _mm_loadu_pd(a + 4);
				xmm_a3 = _mm_loadu_pd(a + 6);
				xmm_a4 = _mm_loadu_pd(a + 8);
				xmm_a5 = _mm_loadu_pd(a + 10);
				xmm_a6 = _mm_loadu_pd(a + 12);
				xmm_a7 = _mm_loadu_pd(a + 14);
				xmm_a8 = _mm_loadu_pd(a + 16);
				xmm_a9 = _mm_loadu_pd(a + 18);
				xmm_aa = _mm_loadu_pd(a + 20);
				xmm_ab = _mm_loadu_pd(a + 22);
				xmm_ac = _mm_loadu_pd(a + 24);
				xmm_ad = _mm_loadu_pd(a + 26);
				xmm_ae = _mm_loadu_pd(a + 28);
				xmm_af = _mm_loadu_pd(a + 30);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
				xmm_a0 = _mm_max_pd(xmm_a0, min);
				xmm_a1 = _mm_max_pd(xmm_a1, min);
				xmm_a2 = _mm_max_pd(xmm_a2, min);
				xmm_a3 = _mm_max_pd(xmm_a3, min);
				xmm_a4 = _mm_max_pd(xmm_a4, min);
				xmm_a5 = _mm_max_pd(xmm_a5, min);
				xmm_a6 = _mm_max_pd(xmm_a6, min);
				xmm_a7 = _mm_max_pd(xmm_a7, min);
				xmm_a8 = _mm_max_pd(xmm_a8, min);
				xmm_a9 = _mm_max_pd(xmm_a9, min);
				xmm_aa = _mm_max_pd(xmm_aa, min);
				xmm_ab = _mm_max_pd(xmm_ab, min);
				xmm_ac = _mm_max_pd(xmm_ac, min);
				xmm_ad = _mm_max_pd(xmm_ad, min);
				xmm_ae = _mm_max_pd(xmm_ae, min);
				xmm_af = _mm_max_pd(xmm_af, min);
				xmm_a0 = _mm_min_pd(xmm_a0, max);
				xmm_a1 = _mm_min_pd(xmm_a1, max);
				xmm_a2 = _mm_min_pd(xmm_a2, max);
				xmm_a3 = _mm_min_pd(xmm_a3, max);
				xmm_a4 = _mm_min_pd(xmm_a4, max);
				xmm_a5 = _mm_min_pd(xmm_a5, max);
				xmm_a6 = _mm_min_pd(xmm_a6, max);
				xmm_a7 = _mm_min_pd(xmm_a7, max);
				xmm_a8 = _mm_min_pd(xmm_a8, max);
				xmm_a9 = _mm_min_pd(xmm_a9, max);
				xmm_aa = _mm_min_pd(xmm_aa, max);
				xmm_ab = _mm_min_pd(xmm_ab, max);
				xmm_ac = _mm_min_pd(xmm_ac, max);
				xmm_ad = _mm_min_pd(xmm_ad, max);
				xmm_ae = _mm_min_pd(xmm_ae, max);
				xmm_af = _mm_min_pd(xmm_af, max);
				xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
				xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
				xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
				xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
				xmm_b4 = _mm_cvttpd_epi32(xmm_a4);
				xmm_b5 = _mm_cvttpd_epi32(xmm_a5);
				xmm_b6 = _mm_cvttpd_epi32(xmm_a6);
				xmm_b7 = _mm_cvttpd_epi32(xmm_a7);
				xmm_b8 = _mm_cvttpd_epi32(xmm_a8);
				xmm_b9 = _mm_cvttpd_epi32(xmm_a9);
				xmm_ba = _mm_cvttpd_epi32(xmm_aa);
				xmm_bb = _mm_cvttpd_epi32(xmm_ab);
				xmm_bc = _mm_cvttpd_epi32(xmm_ac);
				xmm_bd = _mm_cvttpd_epi32(xmm_ad);
				xmm_be = _mm_cvttpd_epi32(xmm_ae);
				xmm_bf = _mm_cvttpd_epi32(xmm_af);
				xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
				xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
				xmm_b4 = _mm_unpacklo_epi64(xmm_b4, xmm_b5);
				xmm_b6 = _mm_unpacklo_epi64(xmm_b6, xmm_b7);
				xmm_b8 = _mm_unpacklo_epi64(xmm_b8, xmm_b9);
				xmm_ba = _mm_unpacklo_epi64(xmm_ba, xmm_bb);
				xmm_bc = _mm_unpacklo_epi64(xmm_bc, xmm_bd);
				xmm_be = _mm_unpacklo_epi64(xmm_be, xmm_bf);
				xmm_b0 = _mm_packus_epi32(xmm_b0, xmm_b2);
				xmm_b4 = _mm_packus_epi32(xmm_b4, xmm_b6);
				xmm_b8 = _mm_packus_epi32(xmm_b8, xmm_ba);
				xmm_bc = _mm_packus_epi32(xmm_bc, xmm_be);
				xmm_b0 = _mm_packus_epi16(xmm_b0, xmm_b4);
				xmm_b8 = _mm_packus_epi16(xmm_b8, xmm_bc);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b8);
				a += 32;
				b += 32;
			}
		}

		template <>
		void cvtspd_sse41_medium<signed short>(signed short* b, const double* a, size_t n)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(INT16_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT16_MAX));
			__m128d xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m128d xmm_a8, xmm_a9, xmm_aa, xmm_ab, xmm_ac, xmm_ad, xmm_ae, xmm_af;
			__m128i xmm_b0, xmm_b1, xmm_b2, xmm_b3, xmm_b4, xmm_b5, xmm_b6, xmm_b7;
			__m128i xmm_b8, xmm_b9, xmm_ba, xmm_bb, xmm_bc, xmm_bd, xmm_be, xmm_bf;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				xmm_a0 = _mm_loadu_pd(a);
				xmm_a1 = _mm_loadu_pd(a + 2);
				xmm_a2 = _mm_loadu_pd(a + 4);
				xmm_a3 = _mm_loadu_pd(a + 6);
				xmm_a4 = _mm_loadu_pd(a + 8);
				xmm_a5 = _mm_loadu_pd(a + 10);
				xmm_a6 = _mm_loadu_pd(a + 12);
				xmm_a7 = _mm_loadu_pd(a + 14);
				xmm_a8 = _mm_loadu_pd(a + 16);
				xmm_a9 = _mm_loadu_pd(a + 18);
				xmm_aa = _mm_loadu_pd(a + 20);
				xmm_ab = _mm_loadu_pd(a + 22);
				xmm_ac = _mm_loadu_pd(a + 24);
				xmm_ad = _mm_loadu_pd(a + 26);
				xmm_ae = _mm_loadu_pd(a + 28);
				xmm_af = _mm_loadu_pd(a + 30);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
				xmm_a0 = _mm_max_pd(xmm_a0, min);
				xmm_a1 = _mm_max_pd(xmm_a1, min);
				xmm_a2 = _mm_max_pd(xmm_a2, min);
				xmm_a3 = _mm_max_pd(xmm_a3, min);
				xmm_a4 = _mm_max_pd(xmm_a4, min);
				xmm_a5 = _mm_max_pd(xmm_a5, min);
				xmm_a6 = _mm_max_pd(xmm_a6, min);
				xmm_a7 = _mm_max_pd(xmm_a7, min);
				xmm_a8 = _mm_max_pd(xmm_a8, min);
				xmm_a9 = _mm_max_pd(xmm_a9, min);
				xmm_aa = _mm_max_pd(xmm_aa, min);
				xmm_ab = _mm_max_pd(xmm_ab, min);
				xmm_ac = _mm_max_pd(xmm_ac, min);
				xmm_ad = _mm_max_pd(xmm_ad, min);
				xmm_ae = _mm_max_pd(xmm_ae, min);
				xmm_af = _mm_max_pd(xmm_af, min);
				xmm_a0 = _mm_min_pd(xmm_a0, max);
				xmm_a1 = _mm_min_pd(xmm_a1, max);
				xmm_a2 = _mm_min_pd(xmm_a2, max);
				xmm_a3 = _mm_min_pd(xmm_a3, max);
				xmm_a4 = _mm_min_pd(xmm_a4, max);
				xmm_a5 = _mm_min_pd(xmm_a5, max);
				xmm_a6 = _mm_min_pd(xmm_a6, max);
				xmm_a7 = _mm_min_pd(xmm_a7, max);
				xmm_a8 = _mm_min_pd(xmm_a8, max);
				xmm_a9 = _mm_min_pd(xmm_a9, max);
				xmm_aa = _mm_min_pd(xmm_aa, max);
				xmm_ab = _mm_min_pd(xmm_ab, max);
				xmm_ac = _mm_min_pd(xmm_ac, max);
				xmm_ad = _mm_min_pd(xmm_ad, max);
				xmm_ae = _mm_min_pd(xmm_ae, max);
				xmm_af = _mm_min_pd(xmm_af, max);
				xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
				xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
				xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
				xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
				xmm_b4 = _mm_cvttpd_epi32(xmm_a4);
				xmm_b5 = _mm_cvttpd_epi32(xmm_a5);
				xmm_b6 = _mm_cvttpd_epi32(xmm_a6);
				xmm_b7 = _mm_cvttpd_epi32(xmm_a7);
				xmm_b8 = _mm_cvttpd_epi32(xmm_a8);
				xmm_b9 = _mm_cvttpd_epi32(xmm_a9);
				xmm_ba = _mm_cvttpd_epi32(xmm_aa);
				xmm_bb = _mm_cvttpd_epi32(xmm_ab);
				xmm_bc = _mm_cvttpd_epi32(xmm_ac);
				xmm_bd = _mm_cvttpd_epi32(xmm_ad);
				xmm_be = _mm_cvttpd_epi32(xmm_ae);
				xmm_bf = _mm_cvttpd_epi32(xmm_af);
				xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
				xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
				xmm_b4 = _mm_unpacklo_epi64(xmm_b4, xmm_b5);
				xmm_b6 = _mm_unpacklo_epi64(xmm_b6, xmm_b7);
				xmm_b8 = _mm_unpacklo_epi64(xmm_b8, xmm_b9);
				xmm_ba = _mm_unpacklo_epi64(xmm_ba, xmm_bb);
				xmm_bc = _mm_unpacklo_epi64(xmm_bc, xmm_bd);
				xmm_be = _mm_unpacklo_epi64(xmm_be, xmm_bf);
				xmm_b0 = _mm_packs_epi32(xmm_b0, xmm_b2);
				xmm_b4 = _mm_packs_epi32(xmm_b4, xmm_b6);
				xmm_b8 = _mm_packs_epi32(xmm_b8, xmm_ba);
				xmm_bc = _mm_packs_epi32(xmm_bc, xmm_be);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b4);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 2, xmm_b8);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 3, xmm_bc);
				a += 32;
				b += 32;
			}
		}

		template <>
		void cvtspd_sse41_medium<unsigned short>(unsigned short* b, const double* a, size_t n)
		{
			const __m128d min = _mm_setzero_pd();
			const __m128d max = _mm_set1_pd(static_cast<double>(UINT16_MAX));
			__m128d xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m128d xmm_a8, xmm_a9, xmm_aa, xmm_ab, xmm_ac, xmm_ad, xmm_ae, xmm_af;
			__m128i xmm_b0, xmm_b1, xmm_b2, xmm_b3, xmm_b4, xmm_b5, xmm_b6, xmm_b7;
			__m128i xmm_b8, xmm_b9, xmm_ba, xmm_bb, xmm_bc, xmm_bd, xmm_be, xmm_bf;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				xmm_a0 = _mm_loadu_pd(a);
				xmm_a1 = _mm_loadu_pd(a + 2);
				xmm_a2 = _mm_loadu_pd(a + 4);
				xmm_a3 = _mm_loadu_pd(a + 6);
				xmm_a4 = _mm_loadu_pd(a + 8);
				xmm_a5 = _mm_loadu_pd(a + 10);
				xmm_a6 = _mm_loadu_pd(a + 12);
				xmm_a7 = _mm_loadu_pd(a + 14);
				xmm_a8 = _mm_loadu_pd(a + 16);
				xmm_a9 = _mm_loadu_pd(a + 18);
				xmm_aa = _mm_loadu_pd(a + 20);
				xmm_ab = _mm_loadu_pd(a + 22);
				xmm_ac = _mm_loadu_pd(a + 24);
				xmm_ad = _mm_loadu_pd(a + 26);
				xmm_ae = _mm_loadu_pd(a + 28);
				xmm_af = _mm_loadu_pd(a + 30);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
				xmm_a0 = _mm_max_pd(xmm_a0, min);
				xmm_a1 = _mm_max_pd(xmm_a1, min);
				xmm_a2 = _mm_max_pd(xmm_a2, min);
				xmm_a3 = _mm_max_pd(xmm_a3, min);
				xmm_a4 = _mm_max_pd(xmm_a4, min);
				xmm_a5 = _mm_max_pd(xmm_a5, min);
				xmm_a6 = _mm_max_pd(xmm_a6, min);
				xmm_a7 = _mm_max_pd(xmm_a7, min);
				xmm_a8 = _mm_max_pd(xmm_a8, min);
				xmm_a9 = _mm_max_pd(xmm_a9, min);
				xmm_aa = _mm_max_pd(xmm_aa, min);
				xmm_ab = _mm_max_pd(xmm_ab, min);
				xmm_ac = _mm_max_pd(xmm_ac, min);
				xmm_ad = _mm_max_pd(xmm_ad, min);
				xmm_ae = _mm_max_pd(xmm_ae, min);
				xmm_af = _mm_max_pd(xmm_af, min);
				xmm_a0 = _mm_min_pd(xmm_a0, max);
				xmm_a1 = _mm_min_pd(xmm_a1, max);
				xmm_a2 = _mm_min_pd(xmm_a2, max);
				xmm_a3 = _mm_min_pd(xmm_a3, max);
				xmm_a4 = _mm_min_pd(xmm_a4, max);
				xmm_a5 = _mm_min_pd(xmm_a5, max);
				xmm_a6 = _mm_min_pd(xmm_a6, max);
				xmm_a7 = _mm_min_pd(xmm_a7, max);
				xmm_a8 = _mm_min_pd(xmm_a8, max);
				xmm_a9 = _mm_min_pd(xmm_a9, max);
				xmm_aa = _mm_min_pd(xmm_aa, max);
				xmm_ab = _mm_min_pd(xmm_ab, max);
				xmm_ac = _mm_min_pd(xmm_ac, max);
				xmm_ad = _mm_min_pd(xmm_ad, max);
				xmm_ae = _mm_min_pd(xmm_ae, max);
				xmm_af = _mm_min_pd(xmm_af, max);
				xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
				xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
				xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
				xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
				xmm_b4 = _mm_cvttpd_epi32(xmm_a4);
				xmm_b5 = _mm_cvttpd_epi32(xmm_a5);
				xmm_b6 = _mm_cvttpd_epi32(xmm_a6);
				xmm_b7 = _mm_cvttpd_epi32(xmm_a7);
				xmm_b8 = _mm_cvttpd_epi32(xmm_a8);
				xmm_b9 = _mm_cvttpd_epi32(xmm_a9);
				xmm_ba = _mm_cvttpd_epi32(xmm_aa);
				xmm_bb = _mm_cvttpd_epi32(xmm_ab);
				xmm_bc = _mm_cvttpd_epi32(xmm_ac);
				xmm_bd = _mm_cvttpd_epi32(xmm_ad);
				xmm_be = _mm_cvttpd_epi32(xmm_ae);
				xmm_bf = _mm_cvttpd_epi32(xmm_af);
				xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
				xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
				xmm_b4 = _mm_unpacklo_epi64(xmm_b4, xmm_b5);
				xmm_b6 = _mm_unpacklo_epi64(xmm_b6, xmm_b7);
				xmm_b8 = _mm_unpacklo_epi64(xmm_b8, xmm_b9);
				xmm_ba = _mm_unpacklo_epi64(xmm_ba, xmm_bb);
				xmm_bc = _mm_unpacklo_epi64(xmm_bc, xmm_bd);
				xmm_be = _mm_unpacklo_epi64(xmm_be, xmm_bf);
				xmm_b0 = _mm_packus_epi32(xmm_b0, xmm_b2);
				xmm_b4 = _mm_packus_epi32(xmm_b4, xmm_b6);
				xmm_b8 = _mm_packus_epi32(xmm_b8, xmm_ba);
				xmm_bc = _mm_packus_epi32(xmm_bc, xmm_be);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b4);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 2, xmm_b8);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 3, xmm_bc);
				a += 32;
				b += 32;
			}
		}

		template <>
		void cvtspd_sse41_medium<signed int>(signed int* b, const double* a, size_t n)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(INT32_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT32_MAX));
			__m128d xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m128d xmm_a8, xmm_a9, xmm_aa, xmm_ab, xmm_ac, xmm_ad, xmm_ae, xmm_af;
			__m128i xmm_b0, xmm_b1, xmm_b2, xmm_b3, xmm_b4, xmm_b5, xmm_b6, xmm_b7;
			__m128i xmm_b8, xmm_b9, xmm_ba, xmm_bb, xmm_bc, xmm_bd, xmm_be, xmm_bf;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				xmm_a0 = _mm_loadu_pd(a);
				xmm_a1 = _mm_loadu_pd(a + 2);
				xmm_a2 = _mm_loadu_pd(a + 4);
				xmm_a3 = _mm_loadu_pd(a + 6);
				xmm_a4 = _mm_loadu_pd(a + 8);
				xmm_a5 = _mm_loadu_pd(a + 10);
				xmm_a6 = _mm_loadu_pd(a + 12);
				xmm_a7 = _mm_loadu_pd(a + 14);
				xmm_a8 = _mm_loadu_pd(a + 16);
				xmm_a9 = _mm_loadu_pd(a + 18);
				xmm_aa = _mm_loadu_pd(a + 20);
				xmm_ab = _mm_loadu_pd(a + 22);
				xmm_ac = _mm_loadu_pd(a + 24);
				xmm_ad = _mm_loadu_pd(a + 26);
				xmm_ae = _mm_loadu_pd(a + 28);
				xmm_af = _mm_loadu_pd(a + 30);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
				xmm_a0 = _mm_max_pd(xmm_a0, min);
				xmm_a1 = _mm_max_pd(xmm_a1, min);
				xmm_a2 = _mm_max_pd(xmm_a2, min);
				xmm_a3 = _mm_max_pd(xmm_a3, min);
				xmm_a4 = _mm_max_pd(xmm_a4, min);
				xmm_a5 = _mm_max_pd(xmm_a5, min);
				xmm_a6 = _mm_max_pd(xmm_a6, min);
				xmm_a7 = _mm_max_pd(xmm_a7, min);
				xmm_a8 = _mm_max_pd(xmm_a8, min);
				xmm_a9 = _mm_max_pd(xmm_a9, min);
				xmm_aa = _mm_max_pd(xmm_aa, min);
				xmm_ab = _mm_max_pd(xmm_ab, min);
				xmm_ac = _mm_max_pd(xmm_ac, min);
				xmm_ad = _mm_max_pd(xmm_ad, min);
				xmm_ae = _mm_max_pd(xmm_ae, min);
				xmm_af = _mm_max_pd(xmm_af, min);
				xmm_a0 = _mm_min_pd(xmm_a0, max);
				xmm_a1 = _mm_min_pd(xmm_a1, max);
				xmm_a2 = _mm_min_pd(xmm_a2, max);
				xmm_a3 = _mm_min_pd(xmm_a3, max);
				xmm_a4 = _mm_min_pd(xmm_a4, max);
				xmm_a5 = _mm_min_pd(xmm_a5, max);
				xmm_a6 = _mm_min_pd(xmm_a6, max);
				xmm_a7 = _mm_min_pd(xmm_a7, max);
				xmm_a8 = _mm_min_pd(xmm_a8, max);
				xmm_a9 = _mm_min_pd(xmm_a9, max);
				xmm_aa = _mm_min_pd(xmm_aa, max);
				xmm_ab = _mm_min_pd(xmm_ab, max);
				xmm_ac = _mm_min_pd(xmm_ac, max);
				xmm_ad = _mm_min_pd(xmm_ad, max);
				xmm_ae = _mm_min_pd(xmm_ae, max);
				xmm_af = _mm_min_pd(xmm_af, max);
				xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
				xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
				xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
				xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
				xmm_b4 = _mm_cvttpd_epi32(xmm_a4);
				xmm_b5 = _mm_cvttpd_epi32(xmm_a5);
				xmm_b6 = _mm_cvttpd_epi32(xmm_a6);
				xmm_b7 = _mm_cvttpd_epi32(xmm_a7);
				xmm_b8 = _mm_cvttpd_epi32(xmm_a8);
				xmm_b9 = _mm_cvttpd_epi32(xmm_a9);
				xmm_ba = _mm_cvttpd_epi32(xmm_aa);
				xmm_bb = _mm_cvttpd_epi32(xmm_ab);
				xmm_bc = _mm_cvttpd_epi32(xmm_ac);
				xmm_bd = _mm_cvttpd_epi32(xmm_ad);
				xmm_be = _mm_cvttpd_epi32(xmm_ae);
				xmm_bf = _mm_cvttpd_epi32(xmm_af);
				xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
				xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
				xmm_b4 = _mm_unpacklo_epi64(xmm_b4, xmm_b5);
				xmm_b6 = _mm_unpacklo_epi64(xmm_b6, xmm_b7);
				xmm_b8 = _mm_unpacklo_epi64(xmm_b8, xmm_b9);
				xmm_ba = _mm_unpacklo_epi64(xmm_ba, xmm_bb);
				xmm_bc = _mm_unpacklo_epi64(xmm_bc, xmm_bd);
				xmm_be = _mm_unpacklo_epi64(xmm_be, xmm_bf);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b2);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 2, xmm_b4);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 3, xmm_b6);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 4, xmm_b8);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 5, xmm_ba);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 6, xmm_bc);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 7, xmm_be);
				a += 32;
				b += 32;
			}
		}

		template <>
		void cvtspd_sse41_medium<unsigned int>(unsigned int* b, const double* a, size_t n)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(INT32_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT32_MAX));
			const __m128d offset = _mm_set1_pd(2.147483648e+9);
			const __m128i shift = _mm_set1_epi32(2147483648);
			__m128d xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m128d xmm_a8, xmm_a9, xmm_aa, xmm_ab, xmm_ac, xmm_ad, xmm_ae, xmm_af;
			__m128i xmm_b0, xmm_b1, xmm_b2, xmm_b3, xmm_b4, xmm_b5, xmm_b6, xmm_b7;
			__m128i xmm_b8, xmm_b9, xmm_ba, xmm_bb, xmm_bc, xmm_bd, xmm_be, xmm_bf;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				xmm_a0 = _mm_loadu_pd(a);
				xmm_a1 = _mm_loadu_pd(a + 2);
				xmm_a2 = _mm_loadu_pd(a + 4);
				xmm_a3 = _mm_loadu_pd(a + 6);
				xmm_a4 = _mm_loadu_pd(a + 8);
				xmm_a5 = _mm_loadu_pd(a + 10);
				xmm_a6 = _mm_loadu_pd(a + 12);
				xmm_a7 = _mm_loadu_pd(a + 14);
				xmm_a8 = _mm_loadu_pd(a + 16);
				xmm_a9 = _mm_loadu_pd(a + 18);
				xmm_aa = _mm_loadu_pd(a + 20);
				xmm_ab = _mm_loadu_pd(a + 22);
				xmm_ac = _mm_loadu_pd(a + 24);
				xmm_ad = _mm_loadu_pd(a + 26);
				xmm_ae = _mm_loadu_pd(a + 28);
				xmm_af = _mm_loadu_pd(a + 30);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
				xmm_a0 = _mm_sub_pd(xmm_a0, offset);
				xmm_a1 = _mm_sub_pd(xmm_a1, offset);
				xmm_a2 = _mm_sub_pd(xmm_a2, offset);
				xmm_a3 = _mm_sub_pd(xmm_a3, offset);
				xmm_a4 = _mm_sub_pd(xmm_a4, offset);
				xmm_a5 = _mm_sub_pd(xmm_a5, offset);
				xmm_a6 = _mm_sub_pd(xmm_a6, offset);
				xmm_a7 = _mm_sub_pd(xmm_a7, offset);
				xmm_a8 = _mm_sub_pd(xmm_a8, offset);
				xmm_a9 = _mm_sub_pd(xmm_a9, offset);
				xmm_aa = _mm_sub_pd(xmm_aa, offset);
				xmm_ab = _mm_sub_pd(xmm_ab, offset);
				xmm_ac = _mm_sub_pd(xmm_ac, offset);
				xmm_ad = _mm_sub_pd(xmm_ad, offset);
				xmm_ae = _mm_sub_pd(xmm_ae, offset);
				xmm_af = _mm_sub_pd(xmm_af, offset);
				xmm_a0 = _mm_max_pd(xmm_a0, min);
				xmm_a1 = _mm_max_pd(xmm_a1, min);
				xmm_a2 = _mm_max_pd(xmm_a2, min);
				xmm_a3 = _mm_max_pd(xmm_a3, min);
				xmm_a4 = _mm_max_pd(xmm_a4, min);
				xmm_a5 = _mm_max_pd(xmm_a5, min);
				xmm_a6 = _mm_max_pd(xmm_a6, min);
				xmm_a7 = _mm_max_pd(xmm_a7, min);
				xmm_a8 = _mm_max_pd(xmm_a8, min);
				xmm_a9 = _mm_max_pd(xmm_a9, min);
				xmm_aa = _mm_max_pd(xmm_aa, min);
				xmm_ab = _mm_max_pd(xmm_ab, min);
				xmm_ac = _mm_max_pd(xmm_ac, min);
				xmm_ad = _mm_max_pd(xmm_ad, min);
				xmm_ae = _mm_max_pd(xmm_ae, min);
				xmm_af = _mm_max_pd(xmm_af, min);
				xmm_a0 = _mm_min_pd(xmm_a0, max);
				xmm_a1 = _mm_min_pd(xmm_a1, max);
				xmm_a2 = _mm_min_pd(xmm_a2, max);
				xmm_a3 = _mm_min_pd(xmm_a3, max);
				xmm_a4 = _mm_min_pd(xmm_a4, max);
				xmm_a5 = _mm_min_pd(xmm_a5, max);
				xmm_a6 = _mm_min_pd(xmm_a6, max);
				xmm_a7 = _mm_min_pd(xmm_a7, max);
				xmm_a8 = _mm_min_pd(xmm_a8, max);
				xmm_a9 = _mm_min_pd(xmm_a9, max);
				xmm_aa = _mm_min_pd(xmm_aa, max);
				xmm_ab = _mm_min_pd(xmm_ab, max);
				xmm_ac = _mm_min_pd(xmm_ac, max);
				xmm_ad = _mm_min_pd(xmm_ad, max);
				xmm_ae = _mm_min_pd(xmm_ae, max);
				xmm_af = _mm_min_pd(xmm_af, max);
				xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
				xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
				xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
				xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
				xmm_b4 = _mm_cvttpd_epi32(xmm_a4);
				xmm_b5 = _mm_cvttpd_epi32(xmm_a5);
				xmm_b6 = _mm_cvttpd_epi32(xmm_a6);
				xmm_b7 = _mm_cvttpd_epi32(xmm_a7);
				xmm_b8 = _mm_cvttpd_epi32(xmm_a8);
				xmm_b9 = _mm_cvttpd_epi32(xmm_a9);
				xmm_ba = _mm_cvttpd_epi32(xmm_aa);
				xmm_bb = _mm_cvttpd_epi32(xmm_ab);
				xmm_bc = _mm_cvttpd_epi32(xmm_ac);
				xmm_bd = _mm_cvttpd_epi32(xmm_ad);
				xmm_be = _mm_cvttpd_epi32(xmm_ae);
				xmm_bf = _mm_cvttpd_epi32(xmm_af);
				xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
				xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
				xmm_b4 = _mm_unpacklo_epi64(xmm_b4, xmm_b5);
				xmm_b6 = _mm_unpacklo_epi64(xmm_b6, xmm_b7);
				xmm_b8 = _mm_unpacklo_epi64(xmm_b8, xmm_b9);
				xmm_ba = _mm_unpacklo_epi64(xmm_ba, xmm_bb);
				xmm_bc = _mm_unpacklo_epi64(xmm_bc, xmm_bd);
				xmm_be = _mm_unpacklo_epi64(xmm_be, xmm_bf);
				xmm_b0 = _mm_add_epi32(xmm_b0, shift);
				xmm_b2 = _mm_add_epi32(xmm_b2, shift);
				xmm_b4 = _mm_add_epi32(xmm_b4, shift);
				xmm_b6 = _mm_add_epi32(xmm_b6, shift);
				xmm_b8 = _mm_add_epi32(xmm_b8, shift);
				xmm_ba = _mm_add_epi32(xmm_ba, shift);
				xmm_bc = _mm_add_epi32(xmm_bc, shift);
				xmm_be = _mm_add_epi32(xmm_be, shift);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b2);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 2, xmm_b4);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 3, xmm_b6);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 4, xmm_b8);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 5, xmm_ba);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 6, xmm_bc);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 7, xmm_be);
				a += 32;
				b += 32;
			}
		}

		template <>
		void cvtspd_sse41_medium<float>(float* b, const double* a, size_t n)
		{
			const __m128d min = _mm_set1_pd(static_cast<double>(-FLT_MAX));
			const __m128d max = _mm_set1_pd(static_cast<double>(FLT_MAX));
			__m128d xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m128d xmm_a8, xmm_a9, xmm_aa, xmm_ab, xmm_ac, xmm_ad, xmm_ae, xmm_af;
			__m128 xmm_b0, xmm_b1, xmm_b2, xmm_b3, xmm_b4, xmm_b5, xmm_b6, xmm_b7;
			__m128 xmm_b8, xmm_b9, xmm_ba, xmm_bb, xmm_bc, xmm_bd, xmm_be, xmm_bf;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				xmm_a0 = _mm_loadu_pd(a);
				xmm_a1 = _mm_loadu_pd(a + 2);
				xmm_a2 = _mm_loadu_pd(a + 4);
				xmm_a3 = _mm_loadu_pd(a + 6);
				xmm_a4 = _mm_loadu_pd(a + 8);
				xmm_a5 = _mm_loadu_pd(a + 10);
				xmm_a6 = _mm_loadu_pd(a + 12);
				xmm_a7 = _mm_loadu_pd(a + 14);
				xmm_a8 = _mm_loadu_pd(a + 16);
				xmm_a9 = _mm_loadu_pd(a + 18);
				xmm_aa = _mm_loadu_pd(a + 20);
				xmm_ab = _mm_loadu_pd(a + 22);
				xmm_ac = _mm_loadu_pd(a + 24);
				xmm_ad = _mm_loadu_pd(a + 26);
				xmm_ae = _mm_loadu_pd(a + 28);
				xmm_af = _mm_loadu_pd(a + 30);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
				xmm_a0 = _mm_max_pd(xmm_a0, min);
				xmm_a1 = _mm_max_pd(xmm_a1, min);
				xmm_a2 = _mm_max_pd(xmm_a2, min);
				xmm_a3 = _mm_max_pd(xmm_a3, min);
				xmm_a4 = _mm_max_pd(xmm_a4, min);
				xmm_a5 = _mm_max_pd(xmm_a5, min);
				xmm_a6 = _mm_max_pd(xmm_a6, min);
				xmm_a7 = _mm_max_pd(xmm_a7, min);
				xmm_a8 = _mm_max_pd(xmm_a8, min);
				xmm_a9 = _mm_max_pd(xmm_a9, min);
				xmm_aa = _mm_max_pd(xmm_aa, min);
				xmm_ab = _mm_max_pd(xmm_ab, min);
				xmm_ac = _mm_max_pd(xmm_ac, min);
				xmm_ad = _mm_max_pd(xmm_ad, min);
				xmm_ae = _mm_max_pd(xmm_ae, min);
				xmm_af = _mm_max_pd(xmm_af, min);
				xmm_a0 = _mm_min_pd(xmm_a0, max);
				xmm_a1 = _mm_min_pd(xmm_a1, max);
				xmm_a2 = _mm_min_pd(xmm_a2, max);
				xmm_a3 = _mm_min_pd(xmm_a3, max);
				xmm_a4 = _mm_min_pd(xmm_a4, max);
				xmm_a5 = _mm_min_pd(xmm_a5, max);
				xmm_a6 = _mm_min_pd(xmm_a6, max);
				xmm_a7 = _mm_min_pd(xmm_a7, max);
				xmm_a8 = _mm_min_pd(xmm_a8, max);
				xmm_a9 = _mm_min_pd(xmm_a9, max);
				xmm_aa = _mm_min_pd(xmm_aa, max);
				xmm_ab = _mm_min_pd(xmm_ab, max);
				xmm_ac = _mm_min_pd(xmm_ac, max);
				xmm_ad = _mm_min_pd(xmm_ad, max);
				xmm_ae = _mm_min_pd(xmm_ae, max);
				xmm_af = _mm_min_pd(xmm_af, max);
				xmm_b0 = _mm_cvtpd_ps(xmm_a0);
				xmm_b1 = _mm_cvtpd_ps(xmm_a1);
				xmm_b2 = _mm_cvtpd_ps(xmm_a2);
				xmm_b3 = _mm_cvtpd_ps(xmm_a3);
				xmm_b4 = _mm_cvtpd_ps(xmm_a4);
				xmm_b5 = _mm_cvtpd_ps(xmm_a5);
				xmm_b6 = _mm_cvtpd_ps(xmm_a6);
				xmm_b7 = _mm_cvtpd_ps(xmm_a7);
				xmm_b8 = _mm_cvtpd_ps(xmm_a8);
				xmm_b9 = _mm_cvtpd_ps(xmm_a9);
				xmm_ba = _mm_cvtpd_ps(xmm_aa);
				xmm_bb = _mm_cvtpd_ps(xmm_ab);
				xmm_bc = _mm_cvtpd_ps(xmm_ac);
				xmm_bd = _mm_cvtpd_ps(xmm_ad);
				xmm_be = _mm_cvtpd_ps(xmm_ae);
				xmm_bf = _mm_cvtpd_ps(xmm_af);
				xmm_b0 = _mm_shuffle_ps(xmm_b0, xmm_b1, _MM_SHUFFLE(1, 0, 1, 0));
				xmm_b2 = _mm_shuffle_ps(xmm_b2, xmm_b3, _MM_SHUFFLE(1, 0, 1, 0));
				xmm_b4 = _mm_shuffle_ps(xmm_b4, xmm_b5, _MM_SHUFFLE(1, 0, 1, 0));
				xmm_b6 = _mm_shuffle_ps(xmm_b6, xmm_b7, _MM_SHUFFLE(1, 0, 1, 0));
				xmm_b8 = _mm_shuffle_ps(xmm_b8, xmm_b9, _MM_SHUFFLE(1, 0, 1, 0));
				xmm_ba = _mm_shuffle_ps(xmm_ba, xmm_bb, _MM_SHUFFLE(1, 0, 1, 0));
				xmm_bc = _mm_shuffle_ps(xmm_bc, xmm_bd, _MM_SHUFFLE(1, 0, 1, 0));
				xmm_be = _mm_shuffle_ps(xmm_be, xmm_bf, _MM_SHUFFLE(1, 0, 1, 0));
				_mm_storeu_ps(b, xmm_b0);
				_mm_storeu_ps(b + 4, xmm_b2);
				_mm_storeu_ps(b + 8, xmm_b4);
				_mm_storeu_ps(b + 12, xmm_b6);
				_mm_storeu_ps(b + 16, xmm_b8);
				_mm_storeu_ps(b + 20, xmm_ba);
				_mm_storeu_ps(b + 24, xmm_bc);
				_mm_storeu_ps(b + 28, xmm_be);
				a += 32;
				b += 32;
			}
		}

		// Function template cvtspd_sse41_large

		template <class T>
		inline void cvtspd_sse41_large(T* b, const double* a, size_t n)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		void cvtspd_sse41_large<signed char>(signed char* b, const double* a, size_t n)
		{
			const size_t padding = 16 - (reinterpret_cast<size_t>(b) & 15);
			const __m128d min = _mm_set1_pd(static_cast<double>(INT8_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT8_MAX));
			__m128d xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m128d xmm_a8, xmm_a9, xmm_aa, xmm_ab, xmm_ac, xmm_ad, xmm_ae, xmm_af;
			__m128i xmm_b0, xmm_b1, xmm_b2, xmm_b3, xmm_b4, xmm_b5, xmm_b6, xmm_b7;
			__m128i xmm_b8, xmm_b9, xmm_ba, xmm_bb, xmm_bc, xmm_bd, xmm_be, xmm_bf;

			// Align the destination to a 16-byte boundary.
			xmm_a0 = _mm_loadu_pd(a);
			xmm_a1 = _mm_loadu_pd(a + 2);
			xmm_a2 = _mm_loadu_pd(a + 4);
			xmm_a3 = _mm_loadu_pd(a + 6);
			xmm_a4 = _mm_loadu_pd(a + 8);
			xmm_a5 = _mm_loadu_pd(a + 10);
			xmm_a6 = _mm_loadu_pd(a + 12);
			xmm_a7 = _mm_loadu_pd(a + 14);
			xmm_a0 = _mm_max_pd(xmm_a0, min);
			xmm_a1 = _mm_max_pd(xmm_a1, min);
			xmm_a2 = _mm_max_pd(xmm_a2, min);
			xmm_a3 = _mm_max_pd(xmm_a3, min);
			xmm_a4 = _mm_max_pd(xmm_a4, min);
			xmm_a5 = _mm_max_pd(xmm_a5, min);
			xmm_a6 = _mm_max_pd(xmm_a6, min);
			xmm_a7 = _mm_max_pd(xmm_a7, min);
			xmm_a0 = _mm_min_pd(xmm_a0, max);
			xmm_a1 = _mm_min_pd(xmm_a1, max);
			xmm_a2 = _mm_min_pd(xmm_a2, max);
			xmm_a3 = _mm_min_pd(xmm_a3, max);
			xmm_a4 = _mm_min_pd(xmm_a4, max);
			xmm_a5 = _mm_min_pd(xmm_a5, max);
			xmm_a6 = _mm_min_pd(xmm_a6, max);
			xmm_a7 = _mm_min_pd(xmm_a7, max);
			xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
			xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
			xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
			xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
			xmm_b4 = _mm_cvttpd_epi32(xmm_a4);
			xmm_b5 = _mm_cvttpd_epi32(xmm_a5);
			xmm_b6 = _mm_cvttpd_epi32(xmm_a6);
			xmm_b7 = _mm_cvttpd_epi32(xmm_a7);
			xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
			xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
			xmm_b4 = _mm_unpacklo_epi64(xmm_b4, xmm_b5);
			xmm_b6 = _mm_unpacklo_epi64(xmm_b6, xmm_b7);
			xmm_b0 = _mm_packs_epi32(xmm_b0, xmm_b2);
			xmm_b4 = _mm_packs_epi32(xmm_b4, xmm_b6);
			xmm_b0 = _mm_packs_epi16(xmm_b0, xmm_b4);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			b += padding;
			a += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			// If the source is aligned on a 16-byte boundary.
			if ((reinterpret_cast<size_t>(a) & 15) == 0)
			{
				for (; n >= 32; n -= 32)
				{
					xmm_a0 = _mm_load_pd(a);
					xmm_a1 = _mm_load_pd(a + 2);
					xmm_a2 = _mm_load_pd(a + 4);
					xmm_a3 = _mm_load_pd(a + 6);
					xmm_a4 = _mm_load_pd(a + 8);
					xmm_a5 = _mm_load_pd(a + 10);
					xmm_a6 = _mm_load_pd(a + 12);
					xmm_a7 = _mm_load_pd(a + 14);
					xmm_a8 = _mm_load_pd(a + 16);
					xmm_a9 = _mm_load_pd(a + 18);
					xmm_aa = _mm_load_pd(a + 20);
					xmm_ab = _mm_load_pd(a + 22);
					xmm_ac = _mm_load_pd(a + 24);
					xmm_ad = _mm_load_pd(a + 26);
					xmm_ae = _mm_load_pd(a + 28);
					xmm_af = _mm_load_pd(a + 30);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
					xmm_a0 = _mm_max_pd(xmm_a0, min);
					xmm_a1 = _mm_max_pd(xmm_a1, min);
					xmm_a2 = _mm_max_pd(xmm_a2, min);
					xmm_a3 = _mm_max_pd(xmm_a3, min);
					xmm_a4 = _mm_max_pd(xmm_a4, min);
					xmm_a5 = _mm_max_pd(xmm_a5, min);
					xmm_a6 = _mm_max_pd(xmm_a6, min);
					xmm_a7 = _mm_max_pd(xmm_a7, min);
					xmm_a8 = _mm_max_pd(xmm_a8, min);
					xmm_a9 = _mm_max_pd(xmm_a9, min);
					xmm_aa = _mm_max_pd(xmm_aa, min);
					xmm_ab = _mm_max_pd(xmm_ab, min);
					xmm_ac = _mm_max_pd(xmm_ac, min);
					xmm_ad = _mm_max_pd(xmm_ad, min);
					xmm_ae = _mm_max_pd(xmm_ae, min);
					xmm_af = _mm_max_pd(xmm_af, min);
					xmm_a0 = _mm_min_pd(xmm_a0, max);
					xmm_a1 = _mm_min_pd(xmm_a1, max);
					xmm_a2 = _mm_min_pd(xmm_a2, max);
					xmm_a3 = _mm_min_pd(xmm_a3, max);
					xmm_a4 = _mm_min_pd(xmm_a4, max);
					xmm_a5 = _mm_min_pd(xmm_a5, max);
					xmm_a6 = _mm_min_pd(xmm_a6, max);
					xmm_a7 = _mm_min_pd(xmm_a7, max);
					xmm_a8 = _mm_min_pd(xmm_a8, max);
					xmm_a9 = _mm_min_pd(xmm_a9, max);
					xmm_aa = _mm_min_pd(xmm_aa, max);
					xmm_ab = _mm_min_pd(xmm_ab, max);
					xmm_ac = _mm_min_pd(xmm_ac, max);
					xmm_ad = _mm_min_pd(xmm_ad, max);
					xmm_ae = _mm_min_pd(xmm_ae, max);
					xmm_af = _mm_min_pd(xmm_af, max);
					xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
					xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
					xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
					xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
					xmm_b4 = _mm_cvttpd_epi32(xmm_a4);
					xmm_b5 = _mm_cvttpd_epi32(xmm_a5);
					xmm_b6 = _mm_cvttpd_epi32(xmm_a6);
					xmm_b7 = _mm_cvttpd_epi32(xmm_a7);
					xmm_b8 = _mm_cvttpd_epi32(xmm_a8);
					xmm_b9 = _mm_cvttpd_epi32(xmm_a9);
					xmm_ba = _mm_cvttpd_epi32(xmm_aa);
					xmm_bb = _mm_cvttpd_epi32(xmm_ab);
					xmm_bc = _mm_cvttpd_epi32(xmm_ac);
					xmm_bd = _mm_cvttpd_epi32(xmm_ad);
					xmm_be = _mm_cvttpd_epi32(xmm_ae);
					xmm_bf = _mm_cvttpd_epi32(xmm_af);
					xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
					xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
					xmm_b4 = _mm_unpacklo_epi64(xmm_b4, xmm_b5);
					xmm_b6 = _mm_unpacklo_epi64(xmm_b6, xmm_b7);
					xmm_b8 = _mm_unpacklo_epi64(xmm_b8, xmm_b9);
					xmm_ba = _mm_unpacklo_epi64(xmm_ba, xmm_bb);
					xmm_bc = _mm_unpacklo_epi64(xmm_bc, xmm_bd);
					xmm_be = _mm_unpacklo_epi64(xmm_be, xmm_bf);
					xmm_b0 = _mm_packs_epi32(xmm_b0, xmm_b2);
					xmm_b4 = _mm_packs_epi32(xmm_b4, xmm_b6);
					xmm_b8 = _mm_packs_epi32(xmm_b8, xmm_ba);
					xmm_bc = _mm_packs_epi32(xmm_bc, xmm_be);
					xmm_b0 = _mm_packs_epi16(xmm_b0, xmm_b4);
					xmm_b8 = _mm_packs_epi16(xmm_b8, xmm_bc);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b8);
					a += 32;
					b += 32;
				}
			}
			else
			{
				for (; n >= 32; n -= 32)
				{
					xmm_a0 = _mm_loadu_pd(a);
					xmm_a1 = _mm_loadu_pd(a + 2);
					xmm_a2 = _mm_loadu_pd(a + 4);
					xmm_a3 = _mm_loadu_pd(a + 6);
					xmm_a4 = _mm_loadu_pd(a + 8);
					xmm_a5 = _mm_loadu_pd(a + 10);
					xmm_a6 = _mm_loadu_pd(a + 12);
					xmm_a7 = _mm_loadu_pd(a + 14);
					xmm_a8 = _mm_loadu_pd(a + 16);
					xmm_a9 = _mm_loadu_pd(a + 18);
					xmm_aa = _mm_loadu_pd(a + 20);
					xmm_ab = _mm_loadu_pd(a + 22);
					xmm_ac = _mm_loadu_pd(a + 24);
					xmm_ad = _mm_loadu_pd(a + 26);
					xmm_ae = _mm_loadu_pd(a + 28);
					xmm_af = _mm_loadu_pd(a + 30);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
					xmm_a0 = _mm_max_pd(xmm_a0, min);
					xmm_a1 = _mm_max_pd(xmm_a1, min);
					xmm_a2 = _mm_max_pd(xmm_a2, min);
					xmm_a3 = _mm_max_pd(xmm_a3, min);
					xmm_a4 = _mm_max_pd(xmm_a4, min);
					xmm_a5 = _mm_max_pd(xmm_a5, min);
					xmm_a6 = _mm_max_pd(xmm_a6, min);
					xmm_a7 = _mm_max_pd(xmm_a7, min);
					xmm_a8 = _mm_max_pd(xmm_a8, min);
					xmm_a9 = _mm_max_pd(xmm_a9, min);
					xmm_aa = _mm_max_pd(xmm_aa, min);
					xmm_ab = _mm_max_pd(xmm_ab, min);
					xmm_ac = _mm_max_pd(xmm_ac, min);
					xmm_ad = _mm_max_pd(xmm_ad, min);
					xmm_ae = _mm_max_pd(xmm_ae, min);
					xmm_af = _mm_max_pd(xmm_af, min);
					xmm_a0 = _mm_min_pd(xmm_a0, max);
					xmm_a1 = _mm_min_pd(xmm_a1, max);
					xmm_a2 = _mm_min_pd(xmm_a2, max);
					xmm_a3 = _mm_min_pd(xmm_a3, max);
					xmm_a4 = _mm_min_pd(xmm_a4, max);
					xmm_a5 = _mm_min_pd(xmm_a5, max);
					xmm_a6 = _mm_min_pd(xmm_a6, max);
					xmm_a7 = _mm_min_pd(xmm_a7, max);
					xmm_a8 = _mm_min_pd(xmm_a8, max);
					xmm_a9 = _mm_min_pd(xmm_a9, max);
					xmm_aa = _mm_min_pd(xmm_aa, max);
					xmm_ab = _mm_min_pd(xmm_ab, max);
					xmm_ac = _mm_min_pd(xmm_ac, max);
					xmm_ad = _mm_min_pd(xmm_ad, max);
					xmm_ae = _mm_min_pd(xmm_ae, max);
					xmm_af = _mm_min_pd(xmm_af, max);
					xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
					xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
					xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
					xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
					xmm_b4 = _mm_cvttpd_epi32(xmm_a4);
					xmm_b5 = _mm_cvttpd_epi32(xmm_a5);
					xmm_b6 = _mm_cvttpd_epi32(xmm_a6);
					xmm_b7 = _mm_cvttpd_epi32(xmm_a7);
					xmm_b8 = _mm_cvttpd_epi32(xmm_a8);
					xmm_b9 = _mm_cvttpd_epi32(xmm_a9);
					xmm_ba = _mm_cvttpd_epi32(xmm_aa);
					xmm_bb = _mm_cvttpd_epi32(xmm_ab);
					xmm_bc = _mm_cvttpd_epi32(xmm_ac);
					xmm_bd = _mm_cvttpd_epi32(xmm_ad);
					xmm_be = _mm_cvttpd_epi32(xmm_ae);
					xmm_bf = _mm_cvttpd_epi32(xmm_af);
					xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
					xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
					xmm_b4 = _mm_unpacklo_epi64(xmm_b4, xmm_b5);
					xmm_b6 = _mm_unpacklo_epi64(xmm_b6, xmm_b7);
					xmm_b8 = _mm_unpacklo_epi64(xmm_b8, xmm_b9);
					xmm_ba = _mm_unpacklo_epi64(xmm_ba, xmm_bb);
					xmm_bc = _mm_unpacklo_epi64(xmm_bc, xmm_bd);
					xmm_be = _mm_unpacklo_epi64(xmm_be, xmm_bf);
					xmm_b0 = _mm_packs_epi32(xmm_b0, xmm_b2);
					xmm_b4 = _mm_packs_epi32(xmm_b4, xmm_b6);
					xmm_b8 = _mm_packs_epi32(xmm_b8, xmm_ba);
					xmm_bc = _mm_packs_epi32(xmm_bc, xmm_be);
					xmm_b0 = _mm_packs_epi16(xmm_b0, xmm_b4);
					xmm_b8 = _mm_packs_epi16(xmm_b8, xmm_bc);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b8);
					a += 32;
					b += 32;
				}
			}
		}

		template <>
		void cvtspd_sse41_large<unsigned char>(unsigned char* b, const double* a, size_t n)
		{
			const size_t padding = 16 - (reinterpret_cast<size_t>(b) & 15);
			const __m128d min = _mm_setzero_pd();
			const __m128d max = _mm_set1_pd(static_cast<double>(UINT8_MAX));
			__m128d xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m128d xmm_a8, xmm_a9, xmm_aa, xmm_ab, xmm_ac, xmm_ad, xmm_ae, xmm_af;
			__m128i xmm_b0, xmm_b1, xmm_b2, xmm_b3, xmm_b4, xmm_b5, xmm_b6, xmm_b7;
			__m128i xmm_b8, xmm_b9, xmm_ba, xmm_bb, xmm_bc, xmm_bd, xmm_be, xmm_bf;

			// Align the destination to a 16-byte boundary.
			xmm_a0 = _mm_loadu_pd(a);
			xmm_a1 = _mm_loadu_pd(a + 2);
			xmm_a2 = _mm_loadu_pd(a + 4);
			xmm_a3 = _mm_loadu_pd(a + 6);
			xmm_a4 = _mm_loadu_pd(a + 8);
			xmm_a5 = _mm_loadu_pd(a + 10);
			xmm_a6 = _mm_loadu_pd(a + 12);
			xmm_a7 = _mm_loadu_pd(a + 14);
			xmm_a0 = _mm_max_pd(xmm_a0, min);
			xmm_a1 = _mm_max_pd(xmm_a1, min);
			xmm_a2 = _mm_max_pd(xmm_a2, min);
			xmm_a3 = _mm_max_pd(xmm_a3, min);
			xmm_a4 = _mm_max_pd(xmm_a4, min);
			xmm_a5 = _mm_max_pd(xmm_a5, min);
			xmm_a6 = _mm_max_pd(xmm_a6, min);
			xmm_a7 = _mm_max_pd(xmm_a7, min);
			xmm_a0 = _mm_min_pd(xmm_a0, max);
			xmm_a1 = _mm_min_pd(xmm_a1, max);
			xmm_a2 = _mm_min_pd(xmm_a2, max);
			xmm_a3 = _mm_min_pd(xmm_a3, max);
			xmm_a4 = _mm_min_pd(xmm_a4, max);
			xmm_a5 = _mm_min_pd(xmm_a5, max);
			xmm_a6 = _mm_min_pd(xmm_a6, max);
			xmm_a7 = _mm_min_pd(xmm_a7, max);
			xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
			xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
			xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
			xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
			xmm_b4 = _mm_cvttpd_epi32(xmm_a4);
			xmm_b5 = _mm_cvttpd_epi32(xmm_a5);
			xmm_b6 = _mm_cvttpd_epi32(xmm_a6);
			xmm_b7 = _mm_cvttpd_epi32(xmm_a7);
			xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
			xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
			xmm_b4 = _mm_unpacklo_epi64(xmm_b4, xmm_b5);
			xmm_b6 = _mm_unpacklo_epi64(xmm_b6, xmm_b7);
			xmm_b0 = _mm_packus_epi32(xmm_b0, xmm_b2);
			xmm_b4 = _mm_packus_epi32(xmm_b4, xmm_b6);
			xmm_b0 = _mm_packus_epi16(xmm_b0, xmm_b4);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			b += padding;
			a += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			// If the source is aligned on a 16-byte boundary.
			if ((reinterpret_cast<size_t>(a) & 15) == 0)
			{
				for (; n >= 32; n -= 32)
				{
					xmm_a0 = _mm_load_pd(a);
					xmm_a1 = _mm_load_pd(a + 2);
					xmm_a2 = _mm_load_pd(a + 4);
					xmm_a3 = _mm_load_pd(a + 6);
					xmm_a4 = _mm_load_pd(a + 8);
					xmm_a5 = _mm_load_pd(a + 10);
					xmm_a6 = _mm_load_pd(a + 12);
					xmm_a7 = _mm_load_pd(a + 14);
					xmm_a8 = _mm_load_pd(a + 16);
					xmm_a9 = _mm_load_pd(a + 18);
					xmm_aa = _mm_load_pd(a + 20);
					xmm_ab = _mm_load_pd(a + 22);
					xmm_ac = _mm_load_pd(a + 24);
					xmm_ad = _mm_load_pd(a + 26);
					xmm_ae = _mm_load_pd(a + 28);
					xmm_af = _mm_load_pd(a + 30);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
					xmm_a0 = _mm_max_pd(xmm_a0, min);
					xmm_a1 = _mm_max_pd(xmm_a1, min);
					xmm_a2 = _mm_max_pd(xmm_a2, min);
					xmm_a3 = _mm_max_pd(xmm_a3, min);
					xmm_a4 = _mm_max_pd(xmm_a4, min);
					xmm_a5 = _mm_max_pd(xmm_a5, min);
					xmm_a6 = _mm_max_pd(xmm_a6, min);
					xmm_a7 = _mm_max_pd(xmm_a7, min);
					xmm_a8 = _mm_max_pd(xmm_a8, min);
					xmm_a9 = _mm_max_pd(xmm_a9, min);
					xmm_aa = _mm_max_pd(xmm_aa, min);
					xmm_ab = _mm_max_pd(xmm_ab, min);
					xmm_ac = _mm_max_pd(xmm_ac, min);
					xmm_ad = _mm_max_pd(xmm_ad, min);
					xmm_ae = _mm_max_pd(xmm_ae, min);
					xmm_af = _mm_max_pd(xmm_af, min);
					xmm_a0 = _mm_min_pd(xmm_a0, max);
					xmm_a1 = _mm_min_pd(xmm_a1, max);
					xmm_a2 = _mm_min_pd(xmm_a2, max);
					xmm_a3 = _mm_min_pd(xmm_a3, max);
					xmm_a4 = _mm_min_pd(xmm_a4, max);
					xmm_a5 = _mm_min_pd(xmm_a5, max);
					xmm_a6 = _mm_min_pd(xmm_a6, max);
					xmm_a7 = _mm_min_pd(xmm_a7, max);
					xmm_a8 = _mm_min_pd(xmm_a8, max);
					xmm_a9 = _mm_min_pd(xmm_a9, max);
					xmm_aa = _mm_min_pd(xmm_aa, max);
					xmm_ab = _mm_min_pd(xmm_ab, max);
					xmm_ac = _mm_min_pd(xmm_ac, max);
					xmm_ad = _mm_min_pd(xmm_ad, max);
					xmm_ae = _mm_min_pd(xmm_ae, max);
					xmm_af = _mm_min_pd(xmm_af, max);
					xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
					xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
					xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
					xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
					xmm_b4 = _mm_cvttpd_epi32(xmm_a4);
					xmm_b5 = _mm_cvttpd_epi32(xmm_a5);
					xmm_b6 = _mm_cvttpd_epi32(xmm_a6);
					xmm_b7 = _mm_cvttpd_epi32(xmm_a7);
					xmm_b8 = _mm_cvttpd_epi32(xmm_a8);
					xmm_b9 = _mm_cvttpd_epi32(xmm_a9);
					xmm_ba = _mm_cvttpd_epi32(xmm_aa);
					xmm_bb = _mm_cvttpd_epi32(xmm_ab);
					xmm_bc = _mm_cvttpd_epi32(xmm_ac);
					xmm_bd = _mm_cvttpd_epi32(xmm_ad);
					xmm_be = _mm_cvttpd_epi32(xmm_ae);
					xmm_bf = _mm_cvttpd_epi32(xmm_af);
					xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
					xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
					xmm_b4 = _mm_unpacklo_epi64(xmm_b4, xmm_b5);
					xmm_b6 = _mm_unpacklo_epi64(xmm_b6, xmm_b7);
					xmm_b8 = _mm_unpacklo_epi64(xmm_b8, xmm_b9);
					xmm_ba = _mm_unpacklo_epi64(xmm_ba, xmm_bb);
					xmm_bc = _mm_unpacklo_epi64(xmm_bc, xmm_bd);
					xmm_be = _mm_unpacklo_epi64(xmm_be, xmm_bf);
					xmm_b0 = _mm_packus_epi32(xmm_b0, xmm_b2);
					xmm_b4 = _mm_packus_epi32(xmm_b4, xmm_b6);
					xmm_b8 = _mm_packus_epi32(xmm_b8, xmm_ba);
					xmm_bc = _mm_packus_epi32(xmm_bc, xmm_be);
					xmm_b0 = _mm_packus_epi16(xmm_b0, xmm_b4);
					xmm_b8 = _mm_packus_epi16(xmm_b8, xmm_bc);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b8);
					a += 32;
					b += 32;
				}
			}
			else
			{
				for (; n >= 32; n -= 32)
				{
					xmm_a0 = _mm_loadu_pd(a);
					xmm_a1 = _mm_loadu_pd(a + 2);
					xmm_a2 = _mm_loadu_pd(a + 4);
					xmm_a3 = _mm_loadu_pd(a + 6);
					xmm_a4 = _mm_loadu_pd(a + 8);
					xmm_a5 = _mm_loadu_pd(a + 10);
					xmm_a6 = _mm_loadu_pd(a + 12);
					xmm_a7 = _mm_loadu_pd(a + 14);
					xmm_a8 = _mm_loadu_pd(a + 16);
					xmm_a9 = _mm_loadu_pd(a + 18);
					xmm_aa = _mm_loadu_pd(a + 20);
					xmm_ab = _mm_loadu_pd(a + 22);
					xmm_ac = _mm_loadu_pd(a + 24);
					xmm_ad = _mm_loadu_pd(a + 26);
					xmm_ae = _mm_loadu_pd(a + 28);
					xmm_af = _mm_loadu_pd(a + 30);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
					xmm_a0 = _mm_max_pd(xmm_a0, min);
					xmm_a1 = _mm_max_pd(xmm_a1, min);
					xmm_a2 = _mm_max_pd(xmm_a2, min);
					xmm_a3 = _mm_max_pd(xmm_a3, min);
					xmm_a4 = _mm_max_pd(xmm_a4, min);
					xmm_a5 = _mm_max_pd(xmm_a5, min);
					xmm_a6 = _mm_max_pd(xmm_a6, min);
					xmm_a7 = _mm_max_pd(xmm_a7, min);
					xmm_a8 = _mm_max_pd(xmm_a8, min);
					xmm_a9 = _mm_max_pd(xmm_a9, min);
					xmm_aa = _mm_max_pd(xmm_aa, min);
					xmm_ab = _mm_max_pd(xmm_ab, min);
					xmm_ac = _mm_max_pd(xmm_ac, min);
					xmm_ad = _mm_max_pd(xmm_ad, min);
					xmm_ae = _mm_max_pd(xmm_ae, min);
					xmm_af = _mm_max_pd(xmm_af, min);
					xmm_a0 = _mm_min_pd(xmm_a0, max);
					xmm_a1 = _mm_min_pd(xmm_a1, max);
					xmm_a2 = _mm_min_pd(xmm_a2, max);
					xmm_a3 = _mm_min_pd(xmm_a3, max);
					xmm_a4 = _mm_min_pd(xmm_a4, max);
					xmm_a5 = _mm_min_pd(xmm_a5, max);
					xmm_a6 = _mm_min_pd(xmm_a6, max);
					xmm_a7 = _mm_min_pd(xmm_a7, max);
					xmm_a8 = _mm_min_pd(xmm_a8, max);
					xmm_a9 = _mm_min_pd(xmm_a9, max);
					xmm_aa = _mm_min_pd(xmm_aa, max);
					xmm_ab = _mm_min_pd(xmm_ab, max);
					xmm_ac = _mm_min_pd(xmm_ac, max);
					xmm_ad = _mm_min_pd(xmm_ad, max);
					xmm_ae = _mm_min_pd(xmm_ae, max);
					xmm_af = _mm_min_pd(xmm_af, max);
					xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
					xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
					xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
					xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
					xmm_b4 = _mm_cvttpd_epi32(xmm_a4);
					xmm_b5 = _mm_cvttpd_epi32(xmm_a5);
					xmm_b6 = _mm_cvttpd_epi32(xmm_a6);
					xmm_b7 = _mm_cvttpd_epi32(xmm_a7);
					xmm_b8 = _mm_cvttpd_epi32(xmm_a8);
					xmm_b9 = _mm_cvttpd_epi32(xmm_a9);
					xmm_ba = _mm_cvttpd_epi32(xmm_aa);
					xmm_bb = _mm_cvttpd_epi32(xmm_ab);
					xmm_bc = _mm_cvttpd_epi32(xmm_ac);
					xmm_bd = _mm_cvttpd_epi32(xmm_ad);
					xmm_be = _mm_cvttpd_epi32(xmm_ae);
					xmm_bf = _mm_cvttpd_epi32(xmm_af);
					xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
					xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
					xmm_b4 = _mm_unpacklo_epi64(xmm_b4, xmm_b5);
					xmm_b6 = _mm_unpacklo_epi64(xmm_b6, xmm_b7);
					xmm_b8 = _mm_unpacklo_epi64(xmm_b8, xmm_b9);
					xmm_ba = _mm_unpacklo_epi64(xmm_ba, xmm_bb);
					xmm_bc = _mm_unpacklo_epi64(xmm_bc, xmm_bd);
					xmm_be = _mm_unpacklo_epi64(xmm_be, xmm_bf);
					xmm_b0 = _mm_packus_epi32(xmm_b0, xmm_b2);
					xmm_b4 = _mm_packus_epi32(xmm_b4, xmm_b6);
					xmm_b8 = _mm_packus_epi32(xmm_b8, xmm_ba);
					xmm_bc = _mm_packus_epi32(xmm_bc, xmm_be);
					xmm_b0 = _mm_packus_epi16(xmm_b0, xmm_b4);
					xmm_b8 = _mm_packus_epi16(xmm_b8, xmm_bc);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b8);
					a += 32;
					b += 32;
				}
			}
		}

		template <>
		void cvtspd_sse41_large<signed short>(signed short* b, const double* a, size_t n)
		{
			const size_t padding = 8 - (reinterpret_cast<size_t>(b) & 7);
			const __m128d min = _mm_set1_pd(static_cast<double>(INT16_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT16_MAX));
			__m128d xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m128d xmm_a8, xmm_a9, xmm_aa, xmm_ab, xmm_ac, xmm_ad, xmm_ae, xmm_af;
			__m128i xmm_b0, xmm_b1, xmm_b2, xmm_b3, xmm_b4, xmm_b5, xmm_b6, xmm_b7;
			__m128i xmm_b8, xmm_b9, xmm_ba, xmm_bb, xmm_bc, xmm_bd, xmm_be, xmm_bf;

			// Align the destination to a 16-byte boundary.
			xmm_a0 = _mm_loadu_pd(a);
			xmm_a1 = _mm_loadu_pd(a + 2);
			xmm_a2 = _mm_loadu_pd(a + 4);
			xmm_a3 = _mm_loadu_pd(a + 6);
			xmm_a0 = _mm_max_pd(xmm_a0, min);
			xmm_a1 = _mm_max_pd(xmm_a1, min);
			xmm_a2 = _mm_max_pd(xmm_a2, min);
			xmm_a3 = _mm_max_pd(xmm_a3, min);
			xmm_a0 = _mm_min_pd(xmm_a0, max);
			xmm_a1 = _mm_min_pd(xmm_a1, max);
			xmm_a2 = _mm_min_pd(xmm_a2, max);
			xmm_a3 = _mm_min_pd(xmm_a3, max);
			xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
			xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
			xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
			xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
			xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
			xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
			xmm_b0 = _mm_packs_epi32(xmm_b0, xmm_b2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			b += padding;
			a += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			// If the source is aligned on a 16-byte boundary.
			if ((reinterpret_cast<size_t>(a) & 15) == 0)
			{
				for (; n >= 32; n -= 32)
				{
					xmm_a0 = _mm_load_pd(a);
					xmm_a1 = _mm_load_pd(a + 2);
					xmm_a2 = _mm_load_pd(a + 4);
					xmm_a3 = _mm_load_pd(a + 6);
					xmm_a4 = _mm_load_pd(a + 8);
					xmm_a5 = _mm_load_pd(a + 10);
					xmm_a6 = _mm_load_pd(a + 12);
					xmm_a7 = _mm_load_pd(a + 14);
					xmm_a8 = _mm_load_pd(a + 16);
					xmm_a9 = _mm_load_pd(a + 18);
					xmm_aa = _mm_load_pd(a + 20);
					xmm_ab = _mm_load_pd(a + 22);
					xmm_ac = _mm_load_pd(a + 24);
					xmm_ad = _mm_load_pd(a + 26);
					xmm_ae = _mm_load_pd(a + 28);
					xmm_af = _mm_load_pd(a + 30);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
					xmm_a0 = _mm_max_pd(xmm_a0, min);
					xmm_a1 = _mm_max_pd(xmm_a1, min);
					xmm_a2 = _mm_max_pd(xmm_a2, min);
					xmm_a3 = _mm_max_pd(xmm_a3, min);
					xmm_a4 = _mm_max_pd(xmm_a4, min);
					xmm_a5 = _mm_max_pd(xmm_a5, min);
					xmm_a6 = _mm_max_pd(xmm_a6, min);
					xmm_a7 = _mm_max_pd(xmm_a7, min);
					xmm_a8 = _mm_max_pd(xmm_a8, min);
					xmm_a9 = _mm_max_pd(xmm_a9, min);
					xmm_aa = _mm_max_pd(xmm_aa, min);
					xmm_ab = _mm_max_pd(xmm_ab, min);
					xmm_ac = _mm_max_pd(xmm_ac, min);
					xmm_ad = _mm_max_pd(xmm_ad, min);
					xmm_ae = _mm_max_pd(xmm_ae, min);
					xmm_af = _mm_max_pd(xmm_af, min);
					xmm_a0 = _mm_min_pd(xmm_a0, max);
					xmm_a1 = _mm_min_pd(xmm_a1, max);
					xmm_a2 = _mm_min_pd(xmm_a2, max);
					xmm_a3 = _mm_min_pd(xmm_a3, max);
					xmm_a4 = _mm_min_pd(xmm_a4, max);
					xmm_a5 = _mm_min_pd(xmm_a5, max);
					xmm_a6 = _mm_min_pd(xmm_a6, max);
					xmm_a7 = _mm_min_pd(xmm_a7, max);
					xmm_a8 = _mm_min_pd(xmm_a8, max);
					xmm_a9 = _mm_min_pd(xmm_a9, max);
					xmm_aa = _mm_min_pd(xmm_aa, max);
					xmm_ab = _mm_min_pd(xmm_ab, max);
					xmm_ac = _mm_min_pd(xmm_ac, max);
					xmm_ad = _mm_min_pd(xmm_ad, max);
					xmm_ae = _mm_min_pd(xmm_ae, max);
					xmm_af = _mm_min_pd(xmm_af, max);
					xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
					xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
					xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
					xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
					xmm_b4 = _mm_cvttpd_epi32(xmm_a4);
					xmm_b5 = _mm_cvttpd_epi32(xmm_a5);
					xmm_b6 = _mm_cvttpd_epi32(xmm_a6);
					xmm_b7 = _mm_cvttpd_epi32(xmm_a7);
					xmm_b8 = _mm_cvttpd_epi32(xmm_a8);
					xmm_b9 = _mm_cvttpd_epi32(xmm_a9);
					xmm_ba = _mm_cvttpd_epi32(xmm_aa);
					xmm_bb = _mm_cvttpd_epi32(xmm_ab);
					xmm_bc = _mm_cvttpd_epi32(xmm_ac);
					xmm_bd = _mm_cvttpd_epi32(xmm_ad);
					xmm_be = _mm_cvttpd_epi32(xmm_ae);
					xmm_bf = _mm_cvttpd_epi32(xmm_af);
					xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
					xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
					xmm_b4 = _mm_unpacklo_epi64(xmm_b4, xmm_b5);
					xmm_b6 = _mm_unpacklo_epi64(xmm_b6, xmm_b7);
					xmm_b8 = _mm_unpacklo_epi64(xmm_b8, xmm_b9);
					xmm_ba = _mm_unpacklo_epi64(xmm_ba, xmm_bb);
					xmm_bc = _mm_unpacklo_epi64(xmm_bc, xmm_bd);
					xmm_be = _mm_unpacklo_epi64(xmm_be, xmm_bf);
					xmm_b0 = _mm_packs_epi32(xmm_b0, xmm_b2);
					xmm_b4 = _mm_packs_epi32(xmm_b4, xmm_b6);
					xmm_b8 = _mm_packs_epi32(xmm_b8, xmm_ba);
					xmm_bc = _mm_packs_epi32(xmm_bc, xmm_be);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b4);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 2, xmm_b8);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 3, xmm_bc);
					a += 32;
					b += 32;
				}
			}
			else
			{
				for (; n >= 32; n -= 32)
				{
					xmm_a0 = _mm_loadu_pd(a);
					xmm_a1 = _mm_loadu_pd(a + 2);
					xmm_a2 = _mm_loadu_pd(a + 4);
					xmm_a3 = _mm_loadu_pd(a + 6);
					xmm_a4 = _mm_loadu_pd(a + 8);
					xmm_a5 = _mm_loadu_pd(a + 10);
					xmm_a6 = _mm_loadu_pd(a + 12);
					xmm_a7 = _mm_loadu_pd(a + 14);
					xmm_a8 = _mm_loadu_pd(a + 16);
					xmm_a9 = _mm_loadu_pd(a + 18);
					xmm_aa = _mm_loadu_pd(a + 20);
					xmm_ab = _mm_loadu_pd(a + 22);
					xmm_ac = _mm_loadu_pd(a + 24);
					xmm_ad = _mm_loadu_pd(a + 26);
					xmm_ae = _mm_loadu_pd(a + 28);
					xmm_af = _mm_loadu_pd(a + 30);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
					xmm_a0 = _mm_max_pd(xmm_a0, min);
					xmm_a1 = _mm_max_pd(xmm_a1, min);
					xmm_a2 = _mm_max_pd(xmm_a2, min);
					xmm_a3 = _mm_max_pd(xmm_a3, min);
					xmm_a4 = _mm_max_pd(xmm_a4, min);
					xmm_a5 = _mm_max_pd(xmm_a5, min);
					xmm_a6 = _mm_max_pd(xmm_a6, min);
					xmm_a7 = _mm_max_pd(xmm_a7, min);
					xmm_a8 = _mm_max_pd(xmm_a8, min);
					xmm_a9 = _mm_max_pd(xmm_a9, min);
					xmm_aa = _mm_max_pd(xmm_aa, min);
					xmm_ab = _mm_max_pd(xmm_ab, min);
					xmm_ac = _mm_max_pd(xmm_ac, min);
					xmm_ad = _mm_max_pd(xmm_ad, min);
					xmm_ae = _mm_max_pd(xmm_ae, min);
					xmm_af = _mm_max_pd(xmm_af, min);
					xmm_a0 = _mm_min_pd(xmm_a0, max);
					xmm_a1 = _mm_min_pd(xmm_a1, max);
					xmm_a2 = _mm_min_pd(xmm_a2, max);
					xmm_a3 = _mm_min_pd(xmm_a3, max);
					xmm_a4 = _mm_min_pd(xmm_a4, max);
					xmm_a5 = _mm_min_pd(xmm_a5, max);
					xmm_a6 = _mm_min_pd(xmm_a6, max);
					xmm_a7 = _mm_min_pd(xmm_a7, max);
					xmm_a8 = _mm_min_pd(xmm_a8, max);
					xmm_a9 = _mm_min_pd(xmm_a9, max);
					xmm_aa = _mm_min_pd(xmm_aa, max);
					xmm_ab = _mm_min_pd(xmm_ab, max);
					xmm_ac = _mm_min_pd(xmm_ac, max);
					xmm_ad = _mm_min_pd(xmm_ad, max);
					xmm_ae = _mm_min_pd(xmm_ae, max);
					xmm_af = _mm_min_pd(xmm_af, max);
					xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
					xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
					xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
					xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
					xmm_b4 = _mm_cvttpd_epi32(xmm_a4);
					xmm_b5 = _mm_cvttpd_epi32(xmm_a5);
					xmm_b6 = _mm_cvttpd_epi32(xmm_a6);
					xmm_b7 = _mm_cvttpd_epi32(xmm_a7);
					xmm_b8 = _mm_cvttpd_epi32(xmm_a8);
					xmm_b9 = _mm_cvttpd_epi32(xmm_a9);
					xmm_ba = _mm_cvttpd_epi32(xmm_aa);
					xmm_bb = _mm_cvttpd_epi32(xmm_ab);
					xmm_bc = _mm_cvttpd_epi32(xmm_ac);
					xmm_bd = _mm_cvttpd_epi32(xmm_ad);
					xmm_be = _mm_cvttpd_epi32(xmm_ae);
					xmm_bf = _mm_cvttpd_epi32(xmm_af);
					xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
					xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
					xmm_b4 = _mm_unpacklo_epi64(xmm_b4, xmm_b5);
					xmm_b6 = _mm_unpacklo_epi64(xmm_b6, xmm_b7);
					xmm_b8 = _mm_unpacklo_epi64(xmm_b8, xmm_b9);
					xmm_ba = _mm_unpacklo_epi64(xmm_ba, xmm_bb);
					xmm_bc = _mm_unpacklo_epi64(xmm_bc, xmm_bd);
					xmm_be = _mm_unpacklo_epi64(xmm_be, xmm_bf);
					xmm_b0 = _mm_packs_epi32(xmm_b0, xmm_b2);
					xmm_b4 = _mm_packs_epi32(xmm_b4, xmm_b6);
					xmm_b8 = _mm_packs_epi32(xmm_b8, xmm_ba);
					xmm_bc = _mm_packs_epi32(xmm_bc, xmm_be);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b4);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 2, xmm_b8);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 3, xmm_bc);
					a += 32;
					b += 32;
				}
			}
		}

		template <>
		void cvtspd_sse41_large<unsigned short>(unsigned short* b, const double* a, size_t n)
		{
			const size_t padding = 8 - (reinterpret_cast<size_t>(b) & 7);
			const __m128d min = _mm_setzero_pd();
			const __m128d max = _mm_set1_pd(static_cast<double>(UINT16_MAX));
			__m128d xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m128d xmm_a8, xmm_a9, xmm_aa, xmm_ab, xmm_ac, xmm_ad, xmm_ae, xmm_af;
			__m128i xmm_b0, xmm_b1, xmm_b2, xmm_b3, xmm_b4, xmm_b5, xmm_b6, xmm_b7;
			__m128i xmm_b8, xmm_b9, xmm_ba, xmm_bb, xmm_bc, xmm_bd, xmm_be, xmm_bf;

			// Align the destination to a 16-byte boundary.
			xmm_a0 = _mm_loadu_pd(a);
			xmm_a1 = _mm_loadu_pd(a + 2);
			xmm_a2 = _mm_loadu_pd(a + 4);
			xmm_a3 = _mm_loadu_pd(a + 6);
			xmm_a0 = _mm_max_pd(xmm_a0, min);
			xmm_a1 = _mm_max_pd(xmm_a1, min);
			xmm_a2 = _mm_max_pd(xmm_a2, min);
			xmm_a3 = _mm_max_pd(xmm_a3, min);
			xmm_a0 = _mm_min_pd(xmm_a0, max);
			xmm_a1 = _mm_min_pd(xmm_a1, max);
			xmm_a2 = _mm_min_pd(xmm_a2, max);
			xmm_a3 = _mm_min_pd(xmm_a3, max);
			xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
			xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
			xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
			xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
			xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
			xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
			xmm_b0 = _mm_packus_epi32(xmm_b0, xmm_b2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			b += padding;
			a += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			// If the source is aligned on a 16-byte boundary.
			if ((reinterpret_cast<size_t>(a) & 15) == 0)
			{
				for (; n >= 32; n -= 32)
				{
					xmm_a0 = _mm_load_pd(a);
					xmm_a1 = _mm_load_pd(a + 2);
					xmm_a2 = _mm_load_pd(a + 4);
					xmm_a3 = _mm_load_pd(a + 6);
					xmm_a4 = _mm_load_pd(a + 8);
					xmm_a5 = _mm_load_pd(a + 10);
					xmm_a6 = _mm_load_pd(a + 12);
					xmm_a7 = _mm_load_pd(a + 14);
					xmm_a8 = _mm_load_pd(a + 16);
					xmm_a9 = _mm_load_pd(a + 18);
					xmm_aa = _mm_load_pd(a + 20);
					xmm_ab = _mm_load_pd(a + 22);
					xmm_ac = _mm_load_pd(a + 24);
					xmm_ad = _mm_load_pd(a + 26);
					xmm_ae = _mm_load_pd(a + 28);
					xmm_af = _mm_load_pd(a + 30);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
					xmm_a0 = _mm_max_pd(xmm_a0, min);
					xmm_a1 = _mm_max_pd(xmm_a1, min);
					xmm_a2 = _mm_max_pd(xmm_a2, min);
					xmm_a3 = _mm_max_pd(xmm_a3, min);
					xmm_a4 = _mm_max_pd(xmm_a4, min);
					xmm_a5 = _mm_max_pd(xmm_a5, min);
					xmm_a6 = _mm_max_pd(xmm_a6, min);
					xmm_a7 = _mm_max_pd(xmm_a7, min);
					xmm_a8 = _mm_max_pd(xmm_a8, min);
					xmm_a9 = _mm_max_pd(xmm_a9, min);
					xmm_aa = _mm_max_pd(xmm_aa, min);
					xmm_ab = _mm_max_pd(xmm_ab, min);
					xmm_ac = _mm_max_pd(xmm_ac, min);
					xmm_ad = _mm_max_pd(xmm_ad, min);
					xmm_ae = _mm_max_pd(xmm_ae, min);
					xmm_af = _mm_max_pd(xmm_af, min);
					xmm_a0 = _mm_min_pd(xmm_a0, max);
					xmm_a1 = _mm_min_pd(xmm_a1, max);
					xmm_a2 = _mm_min_pd(xmm_a2, max);
					xmm_a3 = _mm_min_pd(xmm_a3, max);
					xmm_a4 = _mm_min_pd(xmm_a4, max);
					xmm_a5 = _mm_min_pd(xmm_a5, max);
					xmm_a6 = _mm_min_pd(xmm_a6, max);
					xmm_a7 = _mm_min_pd(xmm_a7, max);
					xmm_a8 = _mm_min_pd(xmm_a8, max);
					xmm_a9 = _mm_min_pd(xmm_a9, max);
					xmm_aa = _mm_min_pd(xmm_aa, max);
					xmm_ab = _mm_min_pd(xmm_ab, max);
					xmm_ac = _mm_min_pd(xmm_ac, max);
					xmm_ad = _mm_min_pd(xmm_ad, max);
					xmm_ae = _mm_min_pd(xmm_ae, max);
					xmm_af = _mm_min_pd(xmm_af, max);
					xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
					xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
					xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
					xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
					xmm_b4 = _mm_cvttpd_epi32(xmm_a4);
					xmm_b5 = _mm_cvttpd_epi32(xmm_a5);
					xmm_b6 = _mm_cvttpd_epi32(xmm_a6);
					xmm_b7 = _mm_cvttpd_epi32(xmm_a7);
					xmm_b8 = _mm_cvttpd_epi32(xmm_a8);
					xmm_b9 = _mm_cvttpd_epi32(xmm_a9);
					xmm_ba = _mm_cvttpd_epi32(xmm_aa);
					xmm_bb = _mm_cvttpd_epi32(xmm_ab);
					xmm_bc = _mm_cvttpd_epi32(xmm_ac);
					xmm_bd = _mm_cvttpd_epi32(xmm_ad);
					xmm_be = _mm_cvttpd_epi32(xmm_ae);
					xmm_bf = _mm_cvttpd_epi32(xmm_af);
					xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
					xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
					xmm_b4 = _mm_unpacklo_epi64(xmm_b4, xmm_b5);
					xmm_b6 = _mm_unpacklo_epi64(xmm_b6, xmm_b7);
					xmm_b8 = _mm_unpacklo_epi64(xmm_b8, xmm_b9);
					xmm_ba = _mm_unpacklo_epi64(xmm_ba, xmm_bb);
					xmm_bc = _mm_unpacklo_epi64(xmm_bc, xmm_bd);
					xmm_be = _mm_unpacklo_epi64(xmm_be, xmm_bf);
					xmm_b0 = _mm_packus_epi32(xmm_b0, xmm_b2);
					xmm_b4 = _mm_packus_epi32(xmm_b4, xmm_b6);
					xmm_b8 = _mm_packus_epi32(xmm_b8, xmm_ba);
					xmm_bc = _mm_packus_epi32(xmm_bc, xmm_be);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b4);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 2, xmm_b8);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 3, xmm_bc);
					a += 32;
					b += 32;
				}
			}
			else
			{
				for (; n >= 32; n -= 32)
				{
					xmm_a0 = _mm_loadu_pd(a);
					xmm_a1 = _mm_loadu_pd(a + 2);
					xmm_a2 = _mm_loadu_pd(a + 4);
					xmm_a3 = _mm_loadu_pd(a + 6);
					xmm_a4 = _mm_loadu_pd(a + 8);
					xmm_a5 = _mm_loadu_pd(a + 10);
					xmm_a6 = _mm_loadu_pd(a + 12);
					xmm_a7 = _mm_loadu_pd(a + 14);
					xmm_a8 = _mm_loadu_pd(a + 16);
					xmm_a9 = _mm_loadu_pd(a + 18);
					xmm_aa = _mm_loadu_pd(a + 20);
					xmm_ab = _mm_loadu_pd(a + 22);
					xmm_ac = _mm_loadu_pd(a + 24);
					xmm_ad = _mm_loadu_pd(a + 26);
					xmm_ae = _mm_loadu_pd(a + 28);
					xmm_af = _mm_loadu_pd(a + 30);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
					xmm_a0 = _mm_max_pd(xmm_a0, min);
					xmm_a1 = _mm_max_pd(xmm_a1, min);
					xmm_a2 = _mm_max_pd(xmm_a2, min);
					xmm_a3 = _mm_max_pd(xmm_a3, min);
					xmm_a4 = _mm_max_pd(xmm_a4, min);
					xmm_a5 = _mm_max_pd(xmm_a5, min);
					xmm_a6 = _mm_max_pd(xmm_a6, min);
					xmm_a7 = _mm_max_pd(xmm_a7, min);
					xmm_a8 = _mm_max_pd(xmm_a8, min);
					xmm_a9 = _mm_max_pd(xmm_a9, min);
					xmm_aa = _mm_max_pd(xmm_aa, min);
					xmm_ab = _mm_max_pd(xmm_ab, min);
					xmm_ac = _mm_max_pd(xmm_ac, min);
					xmm_ad = _mm_max_pd(xmm_ad, min);
					xmm_ae = _mm_max_pd(xmm_ae, min);
					xmm_af = _mm_max_pd(xmm_af, min);
					xmm_a0 = _mm_min_pd(xmm_a0, max);
					xmm_a1 = _mm_min_pd(xmm_a1, max);
					xmm_a2 = _mm_min_pd(xmm_a2, max);
					xmm_a3 = _mm_min_pd(xmm_a3, max);
					xmm_a4 = _mm_min_pd(xmm_a4, max);
					xmm_a5 = _mm_min_pd(xmm_a5, max);
					xmm_a6 = _mm_min_pd(xmm_a6, max);
					xmm_a7 = _mm_min_pd(xmm_a7, max);
					xmm_a8 = _mm_min_pd(xmm_a8, max);
					xmm_a9 = _mm_min_pd(xmm_a9, max);
					xmm_aa = _mm_min_pd(xmm_aa, max);
					xmm_ab = _mm_min_pd(xmm_ab, max);
					xmm_ac = _mm_min_pd(xmm_ac, max);
					xmm_ad = _mm_min_pd(xmm_ad, max);
					xmm_ae = _mm_min_pd(xmm_ae, max);
					xmm_af = _mm_min_pd(xmm_af, max);
					xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
					xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
					xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
					xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
					xmm_b4 = _mm_cvttpd_epi32(xmm_a4);
					xmm_b5 = _mm_cvttpd_epi32(xmm_a5);
					xmm_b6 = _mm_cvttpd_epi32(xmm_a6);
					xmm_b7 = _mm_cvttpd_epi32(xmm_a7);
					xmm_b8 = _mm_cvttpd_epi32(xmm_a8);
					xmm_b9 = _mm_cvttpd_epi32(xmm_a9);
					xmm_ba = _mm_cvttpd_epi32(xmm_aa);
					xmm_bb = _mm_cvttpd_epi32(xmm_ab);
					xmm_bc = _mm_cvttpd_epi32(xmm_ac);
					xmm_bd = _mm_cvttpd_epi32(xmm_ad);
					xmm_be = _mm_cvttpd_epi32(xmm_ae);
					xmm_bf = _mm_cvttpd_epi32(xmm_af);
					xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
					xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
					xmm_b4 = _mm_unpacklo_epi64(xmm_b4, xmm_b5);
					xmm_b6 = _mm_unpacklo_epi64(xmm_b6, xmm_b7);
					xmm_b8 = _mm_unpacklo_epi64(xmm_b8, xmm_b9);
					xmm_ba = _mm_unpacklo_epi64(xmm_ba, xmm_bb);
					xmm_bc = _mm_unpacklo_epi64(xmm_bc, xmm_bd);
					xmm_be = _mm_unpacklo_epi64(xmm_be, xmm_bf);
					xmm_b0 = _mm_packus_epi32(xmm_b0, xmm_b2);
					xmm_b4 = _mm_packus_epi32(xmm_b4, xmm_b6);
					xmm_b8 = _mm_packus_epi32(xmm_b8, xmm_ba);
					xmm_bc = _mm_packus_epi32(xmm_bc, xmm_be);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b4);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 2, xmm_b8);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 3, xmm_bc);
					a += 32;
					b += 32;
				}
			}
		}

		template <>
		void cvtspd_sse41_large<signed int>(signed int* b, const double* a, size_t n)
		{
			const size_t padding = 4 - (reinterpret_cast<size_t>(b) & 3);
			const __m128d min = _mm_set1_pd(static_cast<double>(INT32_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT32_MAX));
			__m128d xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m128d xmm_a8, xmm_a9, xmm_aa, xmm_ab, xmm_ac, xmm_ad, xmm_ae, xmm_af;
			__m128i xmm_b0, xmm_b1, xmm_b2, xmm_b3, xmm_b4, xmm_b5, xmm_b6, xmm_b7;
			__m128i xmm_b8, xmm_b9, xmm_ba, xmm_bb, xmm_bc, xmm_bd, xmm_be, xmm_bf;

			// Align the destination to a 16-byte boundary.
			xmm_a0 = _mm_loadu_pd(a);
			xmm_a1 = _mm_loadu_pd(a + 2);
			xmm_a0 = _mm_max_pd(xmm_a0, min);
			xmm_a1 = _mm_max_pd(xmm_a1, min);
			xmm_a0 = _mm_min_pd(xmm_a0, max);
			xmm_a1 = _mm_min_pd(xmm_a1, max);
			xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
			xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
			xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			b += padding;
			a += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			// If the source is aligned on a 16-byte boundary.
			if ((reinterpret_cast<size_t>(a) & 15) == 0)
			{
				for (; n >= 32; n -= 32)
				{
					xmm_a0 = _mm_load_pd(a);
					xmm_a1 = _mm_load_pd(a + 2);
					xmm_a2 = _mm_load_pd(a + 4);
					xmm_a3 = _mm_load_pd(a + 6);
					xmm_a4 = _mm_load_pd(a + 8);
					xmm_a5 = _mm_load_pd(a + 10);
					xmm_a6 = _mm_load_pd(a + 12);
					xmm_a7 = _mm_load_pd(a + 14);
					xmm_a8 = _mm_load_pd(a + 16);
					xmm_a9 = _mm_load_pd(a + 18);
					xmm_aa = _mm_load_pd(a + 20);
					xmm_ab = _mm_load_pd(a + 22);
					xmm_ac = _mm_load_pd(a + 24);
					xmm_ad = _mm_load_pd(a + 26);
					xmm_ae = _mm_load_pd(a + 28);
					xmm_af = _mm_load_pd(a + 30);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
					xmm_a0 = _mm_max_pd(xmm_a0, min);
					xmm_a1 = _mm_max_pd(xmm_a1, min);
					xmm_a2 = _mm_max_pd(xmm_a2, min);
					xmm_a3 = _mm_max_pd(xmm_a3, min);
					xmm_a4 = _mm_max_pd(xmm_a4, min);
					xmm_a5 = _mm_max_pd(xmm_a5, min);
					xmm_a6 = _mm_max_pd(xmm_a6, min);
					xmm_a7 = _mm_max_pd(xmm_a7, min);
					xmm_a8 = _mm_max_pd(xmm_a8, min);
					xmm_a9 = _mm_max_pd(xmm_a9, min);
					xmm_aa = _mm_max_pd(xmm_aa, min);
					xmm_ab = _mm_max_pd(xmm_ab, min);
					xmm_ac = _mm_max_pd(xmm_ac, min);
					xmm_ad = _mm_max_pd(xmm_ad, min);
					xmm_ae = _mm_max_pd(xmm_ae, min);
					xmm_af = _mm_max_pd(xmm_af, min);
					xmm_a0 = _mm_min_pd(xmm_a0, max);
					xmm_a1 = _mm_min_pd(xmm_a1, max);
					xmm_a2 = _mm_min_pd(xmm_a2, max);
					xmm_a3 = _mm_min_pd(xmm_a3, max);
					xmm_a4 = _mm_min_pd(xmm_a4, max);
					xmm_a5 = _mm_min_pd(xmm_a5, max);
					xmm_a6 = _mm_min_pd(xmm_a6, max);
					xmm_a7 = _mm_min_pd(xmm_a7, max);
					xmm_a8 = _mm_min_pd(xmm_a8, max);
					xmm_a9 = _mm_min_pd(xmm_a9, max);
					xmm_aa = _mm_min_pd(xmm_aa, max);
					xmm_ab = _mm_min_pd(xmm_ab, max);
					xmm_ac = _mm_min_pd(xmm_ac, max);
					xmm_ad = _mm_min_pd(xmm_ad, max);
					xmm_ae = _mm_min_pd(xmm_ae, max);
					xmm_af = _mm_min_pd(xmm_af, max);
					xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
					xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
					xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
					xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
					xmm_b4 = _mm_cvttpd_epi32(xmm_a4);
					xmm_b5 = _mm_cvttpd_epi32(xmm_a5);
					xmm_b6 = _mm_cvttpd_epi32(xmm_a6);
					xmm_b7 = _mm_cvttpd_epi32(xmm_a7);
					xmm_b8 = _mm_cvttpd_epi32(xmm_a8);
					xmm_b9 = _mm_cvttpd_epi32(xmm_a9);
					xmm_ba = _mm_cvttpd_epi32(xmm_aa);
					xmm_bb = _mm_cvttpd_epi32(xmm_ab);
					xmm_bc = _mm_cvttpd_epi32(xmm_ac);
					xmm_bd = _mm_cvttpd_epi32(xmm_ad);
					xmm_be = _mm_cvttpd_epi32(xmm_ae);
					xmm_bf = _mm_cvttpd_epi32(xmm_af);
					xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
					xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
					xmm_b4 = _mm_unpacklo_epi64(xmm_b4, xmm_b5);
					xmm_b6 = _mm_unpacklo_epi64(xmm_b6, xmm_b7);
					xmm_b8 = _mm_unpacklo_epi64(xmm_b8, xmm_b9);
					xmm_ba = _mm_unpacklo_epi64(xmm_ba, xmm_bb);
					xmm_bc = _mm_unpacklo_epi64(xmm_bc, xmm_bd);
					xmm_be = _mm_unpacklo_epi64(xmm_be, xmm_bf);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b2);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 2, xmm_b4);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 3, xmm_b6);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 4, xmm_b8);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 5, xmm_ba);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 6, xmm_bc);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 7, xmm_be);
					a += 32;
					b += 32;
				}
			}
			else
			{
				for (; n >= 32; n -= 32)
				{
					xmm_a0 = _mm_loadu_pd(a);
					xmm_a1 = _mm_loadu_pd(a + 2);
					xmm_a2 = _mm_loadu_pd(a + 4);
					xmm_a3 = _mm_loadu_pd(a + 6);
					xmm_a4 = _mm_loadu_pd(a + 8);
					xmm_a5 = _mm_loadu_pd(a + 10);
					xmm_a6 = _mm_loadu_pd(a + 12);
					xmm_a7 = _mm_loadu_pd(a + 14);
					xmm_a8 = _mm_loadu_pd(a + 16);
					xmm_a9 = _mm_loadu_pd(a + 18);
					xmm_aa = _mm_loadu_pd(a + 20);
					xmm_ab = _mm_loadu_pd(a + 22);
					xmm_ac = _mm_loadu_pd(a + 24);
					xmm_ad = _mm_loadu_pd(a + 26);
					xmm_ae = _mm_loadu_pd(a + 28);
					xmm_af = _mm_loadu_pd(a + 30);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
					xmm_a0 = _mm_max_pd(xmm_a0, min);
					xmm_a1 = _mm_max_pd(xmm_a1, min);
					xmm_a2 = _mm_max_pd(xmm_a2, min);
					xmm_a3 = _mm_max_pd(xmm_a3, min);
					xmm_a4 = _mm_max_pd(xmm_a4, min);
					xmm_a5 = _mm_max_pd(xmm_a5, min);
					xmm_a6 = _mm_max_pd(xmm_a6, min);
					xmm_a7 = _mm_max_pd(xmm_a7, min);
					xmm_a8 = _mm_max_pd(xmm_a8, min);
					xmm_a9 = _mm_max_pd(xmm_a9, min);
					xmm_aa = _mm_max_pd(xmm_aa, min);
					xmm_ab = _mm_max_pd(xmm_ab, min);
					xmm_ac = _mm_max_pd(xmm_ac, min);
					xmm_ad = _mm_max_pd(xmm_ad, min);
					xmm_ae = _mm_max_pd(xmm_ae, min);
					xmm_af = _mm_max_pd(xmm_af, min);
					xmm_a0 = _mm_min_pd(xmm_a0, max);
					xmm_a1 = _mm_min_pd(xmm_a1, max);
					xmm_a2 = _mm_min_pd(xmm_a2, max);
					xmm_a3 = _mm_min_pd(xmm_a3, max);
					xmm_a4 = _mm_min_pd(xmm_a4, max);
					xmm_a5 = _mm_min_pd(xmm_a5, max);
					xmm_a6 = _mm_min_pd(xmm_a6, max);
					xmm_a7 = _mm_min_pd(xmm_a7, max);
					xmm_a8 = _mm_min_pd(xmm_a8, max);
					xmm_a9 = _mm_min_pd(xmm_a9, max);
					xmm_aa = _mm_min_pd(xmm_aa, max);
					xmm_ab = _mm_min_pd(xmm_ab, max);
					xmm_ac = _mm_min_pd(xmm_ac, max);
					xmm_ad = _mm_min_pd(xmm_ad, max);
					xmm_ae = _mm_min_pd(xmm_ae, max);
					xmm_af = _mm_min_pd(xmm_af, max);
					xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
					xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
					xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
					xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
					xmm_b4 = _mm_cvttpd_epi32(xmm_a4);
					xmm_b5 = _mm_cvttpd_epi32(xmm_a5);
					xmm_b6 = _mm_cvttpd_epi32(xmm_a6);
					xmm_b7 = _mm_cvttpd_epi32(xmm_a7);
					xmm_b8 = _mm_cvttpd_epi32(xmm_a8);
					xmm_b9 = _mm_cvttpd_epi32(xmm_a9);
					xmm_ba = _mm_cvttpd_epi32(xmm_aa);
					xmm_bb = _mm_cvttpd_epi32(xmm_ab);
					xmm_bc = _mm_cvttpd_epi32(xmm_ac);
					xmm_bd = _mm_cvttpd_epi32(xmm_ad);
					xmm_be = _mm_cvttpd_epi32(xmm_ae);
					xmm_bf = _mm_cvttpd_epi32(xmm_af);
					xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
					xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
					xmm_b4 = _mm_unpacklo_epi64(xmm_b4, xmm_b5);
					xmm_b6 = _mm_unpacklo_epi64(xmm_b6, xmm_b7);
					xmm_b8 = _mm_unpacklo_epi64(xmm_b8, xmm_b9);
					xmm_ba = _mm_unpacklo_epi64(xmm_ba, xmm_bb);
					xmm_bc = _mm_unpacklo_epi64(xmm_bc, xmm_bd);
					xmm_be = _mm_unpacklo_epi64(xmm_be, xmm_bf);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b2);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 2, xmm_b4);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 3, xmm_b6);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 4, xmm_b8);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 5, xmm_ba);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 6, xmm_bc);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 7, xmm_be);
					a += 32;
					b += 32;
				}
			}
		}

		template <>
		void cvtspd_sse41_large<unsigned int>(unsigned int* b, const double* a, size_t n)
		{
			const size_t padding = 4 - (reinterpret_cast<size_t>(b) & 3);
			const __m128d min = _mm_set1_pd(static_cast<double>(INT32_MIN));
			const __m128d max = _mm_set1_pd(static_cast<double>(INT32_MAX));
			const __m128d offset = _mm_set1_pd(2.147483648e+9);
			const __m128i shift = _mm_set1_epi32(2147483648);
			__m128d xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m128d xmm_a8, xmm_a9, xmm_aa, xmm_ab, xmm_ac, xmm_ad, xmm_ae, xmm_af;
			__m128i xmm_b0, xmm_b1, xmm_b2, xmm_b3, xmm_b4, xmm_b5, xmm_b6, xmm_b7;
			__m128i xmm_b8, xmm_b9, xmm_ba, xmm_bb, xmm_bc, xmm_bd, xmm_be, xmm_bf;

			// Align the destination to a 16-byte boundary.
			xmm_a0 = _mm_loadu_pd(a);
			xmm_a1 = _mm_loadu_pd(a + 2);
			xmm_a0 = _mm_sub_pd(xmm_a0, offset);
			xmm_a1 = _mm_sub_pd(xmm_a1, offset);
			xmm_a0 = _mm_max_pd(xmm_a0, min);
			xmm_a1 = _mm_max_pd(xmm_a1, min);
			xmm_a0 = _mm_min_pd(xmm_a0, max);
			xmm_a1 = _mm_min_pd(xmm_a1, max);
			xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
			xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
			xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
			xmm_b0 = _mm_add_epi32(xmm_b0, shift);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			b += padding;
			a += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			// If the source is aligned on a 16-byte boundary.
			if ((reinterpret_cast<size_t>(a) & 15) == 0)
			{
				for (; n >= 32; n -= 32)
				{
					xmm_a0 = _mm_load_pd(a);
					xmm_a1 = _mm_load_pd(a + 2);
					xmm_a2 = _mm_load_pd(a + 4);
					xmm_a3 = _mm_load_pd(a + 6);
					xmm_a4 = _mm_load_pd(a + 8);
					xmm_a5 = _mm_load_pd(a + 10);
					xmm_a6 = _mm_load_pd(a + 12);
					xmm_a7 = _mm_load_pd(a + 14);
					xmm_a8 = _mm_load_pd(a + 16);
					xmm_a9 = _mm_load_pd(a + 18);
					xmm_aa = _mm_load_pd(a + 20);
					xmm_ab = _mm_load_pd(a + 22);
					xmm_ac = _mm_load_pd(a + 24);
					xmm_ad = _mm_load_pd(a + 26);
					xmm_ae = _mm_load_pd(a + 28);
					xmm_af = _mm_load_pd(a + 30);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
					xmm_a0 = _mm_sub_pd(xmm_a0, offset);
					xmm_a1 = _mm_sub_pd(xmm_a1, offset);
					xmm_a2 = _mm_sub_pd(xmm_a2, offset);
					xmm_a3 = _mm_sub_pd(xmm_a3, offset);
					xmm_a4 = _mm_sub_pd(xmm_a4, offset);
					xmm_a5 = _mm_sub_pd(xmm_a5, offset);
					xmm_a6 = _mm_sub_pd(xmm_a6, offset);
					xmm_a7 = _mm_sub_pd(xmm_a7, offset);
					xmm_a8 = _mm_sub_pd(xmm_a8, offset);
					xmm_a9 = _mm_sub_pd(xmm_a9, offset);
					xmm_aa = _mm_sub_pd(xmm_aa, offset);
					xmm_ab = _mm_sub_pd(xmm_ab, offset);
					xmm_ac = _mm_sub_pd(xmm_ac, offset);
					xmm_ad = _mm_sub_pd(xmm_ad, offset);
					xmm_ae = _mm_sub_pd(xmm_ae, offset);
					xmm_af = _mm_sub_pd(xmm_af, offset);
					xmm_a0 = _mm_max_pd(xmm_a0, min);
					xmm_a1 = _mm_max_pd(xmm_a1, min);
					xmm_a2 = _mm_max_pd(xmm_a2, min);
					xmm_a3 = _mm_max_pd(xmm_a3, min);
					xmm_a4 = _mm_max_pd(xmm_a4, min);
					xmm_a5 = _mm_max_pd(xmm_a5, min);
					xmm_a6 = _mm_max_pd(xmm_a6, min);
					xmm_a7 = _mm_max_pd(xmm_a7, min);
					xmm_a8 = _mm_max_pd(xmm_a8, min);
					xmm_a9 = _mm_max_pd(xmm_a9, min);
					xmm_aa = _mm_max_pd(xmm_aa, min);
					xmm_ab = _mm_max_pd(xmm_ab, min);
					xmm_ac = _mm_max_pd(xmm_ac, min);
					xmm_ad = _mm_max_pd(xmm_ad, min);
					xmm_ae = _mm_max_pd(xmm_ae, min);
					xmm_af = _mm_max_pd(xmm_af, min);
					xmm_a0 = _mm_min_pd(xmm_a0, max);
					xmm_a1 = _mm_min_pd(xmm_a1, max);
					xmm_a2 = _mm_min_pd(xmm_a2, max);
					xmm_a3 = _mm_min_pd(xmm_a3, max);
					xmm_a4 = _mm_min_pd(xmm_a4, max);
					xmm_a5 = _mm_min_pd(xmm_a5, max);
					xmm_a6 = _mm_min_pd(xmm_a6, max);
					xmm_a7 = _mm_min_pd(xmm_a7, max);
					xmm_a8 = _mm_min_pd(xmm_a8, max);
					xmm_a9 = _mm_min_pd(xmm_a9, max);
					xmm_aa = _mm_min_pd(xmm_aa, max);
					xmm_ab = _mm_min_pd(xmm_ab, max);
					xmm_ac = _mm_min_pd(xmm_ac, max);
					xmm_ad = _mm_min_pd(xmm_ad, max);
					xmm_ae = _mm_min_pd(xmm_ae, max);
					xmm_af = _mm_min_pd(xmm_af, max);
					xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
					xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
					xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
					xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
					xmm_b4 = _mm_cvttpd_epi32(xmm_a4);
					xmm_b5 = _mm_cvttpd_epi32(xmm_a5);
					xmm_b6 = _mm_cvttpd_epi32(xmm_a6);
					xmm_b7 = _mm_cvttpd_epi32(xmm_a7);
					xmm_b8 = _mm_cvttpd_epi32(xmm_a8);
					xmm_b9 = _mm_cvttpd_epi32(xmm_a9);
					xmm_ba = _mm_cvttpd_epi32(xmm_aa);
					xmm_bb = _mm_cvttpd_epi32(xmm_ab);
					xmm_bc = _mm_cvttpd_epi32(xmm_ac);
					xmm_bd = _mm_cvttpd_epi32(xmm_ad);
					xmm_be = _mm_cvttpd_epi32(xmm_ae);
					xmm_bf = _mm_cvttpd_epi32(xmm_af);
					xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
					xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
					xmm_b4 = _mm_unpacklo_epi64(xmm_b4, xmm_b5);
					xmm_b6 = _mm_unpacklo_epi64(xmm_b6, xmm_b7);
					xmm_b8 = _mm_unpacklo_epi64(xmm_b8, xmm_b9);
					xmm_ba = _mm_unpacklo_epi64(xmm_ba, xmm_bb);
					xmm_bc = _mm_unpacklo_epi64(xmm_bc, xmm_bd);
					xmm_be = _mm_unpacklo_epi64(xmm_be, xmm_bf);
					xmm_b0 = _mm_add_epi32(xmm_b0, shift);
					xmm_b2 = _mm_add_epi32(xmm_b2, shift);
					xmm_b4 = _mm_add_epi32(xmm_b4, shift);
					xmm_b6 = _mm_add_epi32(xmm_b6, shift);
					xmm_b8 = _mm_add_epi32(xmm_b8, shift);
					xmm_ba = _mm_add_epi32(xmm_ba, shift);
					xmm_bc = _mm_add_epi32(xmm_bc, shift);
					xmm_be = _mm_add_epi32(xmm_be, shift);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b2);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 2, xmm_b4);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 3, xmm_b6);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 4, xmm_b8);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 5, xmm_ba);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 6, xmm_bc);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 7, xmm_be);
					a += 32;
					b += 32;
				}
			}
			else
			{
				for (; n >= 32; n -= 32)
				{
					xmm_a0 = _mm_loadu_pd(a);
					xmm_a1 = _mm_loadu_pd(a + 2);
					xmm_a2 = _mm_loadu_pd(a + 4);
					xmm_a3 = _mm_loadu_pd(a + 6);
					xmm_a4 = _mm_loadu_pd(a + 8);
					xmm_a5 = _mm_loadu_pd(a + 10);
					xmm_a6 = _mm_loadu_pd(a + 12);
					xmm_a7 = _mm_loadu_pd(a + 14);
					xmm_a8 = _mm_loadu_pd(a + 16);
					xmm_a9 = _mm_loadu_pd(a + 18);
					xmm_aa = _mm_loadu_pd(a + 20);
					xmm_ab = _mm_loadu_pd(a + 22);
					xmm_ac = _mm_loadu_pd(a + 24);
					xmm_ad = _mm_loadu_pd(a + 26);
					xmm_ae = _mm_loadu_pd(a + 28);
					xmm_af = _mm_loadu_pd(a + 30);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
					xmm_a0 = _mm_sub_pd(xmm_a0, offset);
					xmm_a1 = _mm_sub_pd(xmm_a1, offset);
					xmm_a2 = _mm_sub_pd(xmm_a2, offset);
					xmm_a3 = _mm_sub_pd(xmm_a3, offset);
					xmm_a4 = _mm_sub_pd(xmm_a4, offset);
					xmm_a5 = _mm_sub_pd(xmm_a5, offset);
					xmm_a6 = _mm_sub_pd(xmm_a6, offset);
					xmm_a7 = _mm_sub_pd(xmm_a7, offset);
					xmm_a8 = _mm_sub_pd(xmm_a8, offset);
					xmm_a9 = _mm_sub_pd(xmm_a9, offset);
					xmm_aa = _mm_sub_pd(xmm_aa, offset);
					xmm_ab = _mm_sub_pd(xmm_ab, offset);
					xmm_ac = _mm_sub_pd(xmm_ac, offset);
					xmm_ad = _mm_sub_pd(xmm_ad, offset);
					xmm_ae = _mm_sub_pd(xmm_ae, offset);
					xmm_af = _mm_sub_pd(xmm_af, offset);
					xmm_a0 = _mm_max_pd(xmm_a0, min);
					xmm_a1 = _mm_max_pd(xmm_a1, min);
					xmm_a2 = _mm_max_pd(xmm_a2, min);
					xmm_a3 = _mm_max_pd(xmm_a3, min);
					xmm_a4 = _mm_max_pd(xmm_a4, min);
					xmm_a5 = _mm_max_pd(xmm_a5, min);
					xmm_a6 = _mm_max_pd(xmm_a6, min);
					xmm_a7 = _mm_max_pd(xmm_a7, min);
					xmm_a8 = _mm_max_pd(xmm_a8, min);
					xmm_a9 = _mm_max_pd(xmm_a9, min);
					xmm_aa = _mm_max_pd(xmm_aa, min);
					xmm_ab = _mm_max_pd(xmm_ab, min);
					xmm_ac = _mm_max_pd(xmm_ac, min);
					xmm_ad = _mm_max_pd(xmm_ad, min);
					xmm_ae = _mm_max_pd(xmm_ae, min);
					xmm_af = _mm_max_pd(xmm_af, min);
					xmm_a0 = _mm_min_pd(xmm_a0, max);
					xmm_a1 = _mm_min_pd(xmm_a1, max);
					xmm_a2 = _mm_min_pd(xmm_a2, max);
					xmm_a3 = _mm_min_pd(xmm_a3, max);
					xmm_a4 = _mm_min_pd(xmm_a4, max);
					xmm_a5 = _mm_min_pd(xmm_a5, max);
					xmm_a6 = _mm_min_pd(xmm_a6, max);
					xmm_a7 = _mm_min_pd(xmm_a7, max);
					xmm_a8 = _mm_min_pd(xmm_a8, max);
					xmm_a9 = _mm_min_pd(xmm_a9, max);
					xmm_aa = _mm_min_pd(xmm_aa, max);
					xmm_ab = _mm_min_pd(xmm_ab, max);
					xmm_ac = _mm_min_pd(xmm_ac, max);
					xmm_ad = _mm_min_pd(xmm_ad, max);
					xmm_ae = _mm_min_pd(xmm_ae, max);
					xmm_af = _mm_min_pd(xmm_af, max);
					xmm_b0 = _mm_cvttpd_epi32(xmm_a0);
					xmm_b1 = _mm_cvttpd_epi32(xmm_a1);
					xmm_b2 = _mm_cvttpd_epi32(xmm_a2);
					xmm_b3 = _mm_cvttpd_epi32(xmm_a3);
					xmm_b4 = _mm_cvttpd_epi32(xmm_a4);
					xmm_b5 = _mm_cvttpd_epi32(xmm_a5);
					xmm_b6 = _mm_cvttpd_epi32(xmm_a6);
					xmm_b7 = _mm_cvttpd_epi32(xmm_a7);
					xmm_b8 = _mm_cvttpd_epi32(xmm_a8);
					xmm_b9 = _mm_cvttpd_epi32(xmm_a9);
					xmm_ba = _mm_cvttpd_epi32(xmm_aa);
					xmm_bb = _mm_cvttpd_epi32(xmm_ab);
					xmm_bc = _mm_cvttpd_epi32(xmm_ac);
					xmm_bd = _mm_cvttpd_epi32(xmm_ad);
					xmm_be = _mm_cvttpd_epi32(xmm_ae);
					xmm_bf = _mm_cvttpd_epi32(xmm_af);
					xmm_b0 = _mm_unpacklo_epi64(xmm_b0, xmm_b1);
					xmm_b2 = _mm_unpacklo_epi64(xmm_b2, xmm_b3);
					xmm_b4 = _mm_unpacklo_epi64(xmm_b4, xmm_b5);
					xmm_b6 = _mm_unpacklo_epi64(xmm_b6, xmm_b7);
					xmm_b8 = _mm_unpacklo_epi64(xmm_b8, xmm_b9);
					xmm_ba = _mm_unpacklo_epi64(xmm_ba, xmm_bb);
					xmm_bc = _mm_unpacklo_epi64(xmm_bc, xmm_bd);
					xmm_be = _mm_unpacklo_epi64(xmm_be, xmm_bf);
					xmm_b0 = _mm_add_epi32(xmm_b0, shift);
					xmm_b2 = _mm_add_epi32(xmm_b2, shift);
					xmm_b4 = _mm_add_epi32(xmm_b4, shift);
					xmm_b6 = _mm_add_epi32(xmm_b6, shift);
					xmm_b8 = _mm_add_epi32(xmm_b8, shift);
					xmm_ba = _mm_add_epi32(xmm_ba, shift);
					xmm_bc = _mm_add_epi32(xmm_bc, shift);
					xmm_be = _mm_add_epi32(xmm_be, shift);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b2);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 2, xmm_b4);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 3, xmm_b6);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 4, xmm_b8);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 5, xmm_ba);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 6, xmm_bc);
					_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 7, xmm_be);
					a += 32;
					b += 32;
				}
			}
		}

		template <>
		void cvtspd_sse41_large<float>(float* b, const double* a, size_t n)
		{
			const size_t padding = 4 - (reinterpret_cast<size_t>(b) & 3);
			const __m128d min = _mm_set1_pd(static_cast<double>(-FLT_MAX));
			const __m128d max = _mm_set1_pd(static_cast<double>(FLT_MAX));
			__m128d xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m128d xmm_a8, xmm_a9, xmm_aa, xmm_ab, xmm_ac, xmm_ad, xmm_ae, xmm_af;
			__m128 xmm_b0, xmm_b1, xmm_b2, xmm_b3, xmm_b4, xmm_b5, xmm_b6, xmm_b7;
			__m128 xmm_b8, xmm_b9, xmm_ba, xmm_bb, xmm_bc, xmm_bd, xmm_be, xmm_bf;

			// Align the destination to a 16-byte boundary.
			xmm_a0 = _mm_loadu_pd(a);
			xmm_a1 = _mm_loadu_pd(a + 2);
			xmm_a0 = _mm_max_pd(xmm_a0, min);
			xmm_a1 = _mm_max_pd(xmm_a1, min);
			xmm_a0 = _mm_min_pd(xmm_a0, max);
			xmm_a1 = _mm_min_pd(xmm_a1, max);
			xmm_b0 = _mm_cvtpd_ps(xmm_a0);
			xmm_b1 = _mm_cvtpd_ps(xmm_a1);
			xmm_b0 = _mm_shuffle_ps(xmm_b0, xmm_b1, _MM_SHUFFLE(1, 0, 1, 0));
			_mm_storeu_ps(b, xmm_b0);
			b += padding;
			a += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			// If the source is aligned on a 16-byte boundary.
			if ((reinterpret_cast<size_t>(a) & 15) == 0)
			{
				for (; n >= 32; n -= 32)
				{
					xmm_a0 = _mm_load_pd(a);
					xmm_a1 = _mm_load_pd(a + 2);
					xmm_a2 = _mm_load_pd(a + 4);
					xmm_a3 = _mm_load_pd(a + 6);
					xmm_a4 = _mm_load_pd(a + 8);
					xmm_a5 = _mm_load_pd(a + 10);
					xmm_a6 = _mm_load_pd(a + 12);
					xmm_a7 = _mm_load_pd(a + 14);
					xmm_a8 = _mm_load_pd(a + 16);
					xmm_a9 = _mm_load_pd(a + 18);
					xmm_aa = _mm_load_pd(a + 20);
					xmm_ab = _mm_load_pd(a + 22);
					xmm_ac = _mm_load_pd(a + 24);
					xmm_ad = _mm_load_pd(a + 26);
					xmm_ae = _mm_load_pd(a + 28);
					xmm_af = _mm_load_pd(a + 30);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
					xmm_a0 = _mm_max_pd(xmm_a0, min);
					xmm_a1 = _mm_max_pd(xmm_a1, min);
					xmm_a2 = _mm_max_pd(xmm_a2, min);
					xmm_a3 = _mm_max_pd(xmm_a3, min);
					xmm_a4 = _mm_max_pd(xmm_a4, min);
					xmm_a5 = _mm_max_pd(xmm_a5, min);
					xmm_a6 = _mm_max_pd(xmm_a6, min);
					xmm_a7 = _mm_max_pd(xmm_a7, min);
					xmm_a8 = _mm_max_pd(xmm_a8, min);
					xmm_a9 = _mm_max_pd(xmm_a9, min);
					xmm_aa = _mm_max_pd(xmm_aa, min);
					xmm_ab = _mm_max_pd(xmm_ab, min);
					xmm_ac = _mm_max_pd(xmm_ac, min);
					xmm_ad = _mm_max_pd(xmm_ad, min);
					xmm_ae = _mm_max_pd(xmm_ae, min);
					xmm_af = _mm_max_pd(xmm_af, min);
					xmm_a0 = _mm_min_pd(xmm_a0, max);
					xmm_a1 = _mm_min_pd(xmm_a1, max);
					xmm_a2 = _mm_min_pd(xmm_a2, max);
					xmm_a3 = _mm_min_pd(xmm_a3, max);
					xmm_a4 = _mm_min_pd(xmm_a4, max);
					xmm_a5 = _mm_min_pd(xmm_a5, max);
					xmm_a6 = _mm_min_pd(xmm_a6, max);
					xmm_a7 = _mm_min_pd(xmm_a7, max);
					xmm_a8 = _mm_min_pd(xmm_a8, max);
					xmm_a9 = _mm_min_pd(xmm_a9, max);
					xmm_aa = _mm_min_pd(xmm_aa, max);
					xmm_ab = _mm_min_pd(xmm_ab, max);
					xmm_ac = _mm_min_pd(xmm_ac, max);
					xmm_ad = _mm_min_pd(xmm_ad, max);
					xmm_ae = _mm_min_pd(xmm_ae, max);
					xmm_af = _mm_min_pd(xmm_af, max);
					xmm_b0 = _mm_cvtpd_ps(xmm_a0);
					xmm_b1 = _mm_cvtpd_ps(xmm_a1);
					xmm_b2 = _mm_cvtpd_ps(xmm_a2);
					xmm_b3 = _mm_cvtpd_ps(xmm_a3);
					xmm_b4 = _mm_cvtpd_ps(xmm_a4);
					xmm_b5 = _mm_cvtpd_ps(xmm_a5);
					xmm_b6 = _mm_cvtpd_ps(xmm_a6);
					xmm_b7 = _mm_cvtpd_ps(xmm_a7);
					xmm_b8 = _mm_cvtpd_ps(xmm_a8);
					xmm_b9 = _mm_cvtpd_ps(xmm_a9);
					xmm_ba = _mm_cvtpd_ps(xmm_aa);
					xmm_bb = _mm_cvtpd_ps(xmm_ab);
					xmm_bc = _mm_cvtpd_ps(xmm_ac);
					xmm_bd = _mm_cvtpd_ps(xmm_ad);
					xmm_be = _mm_cvtpd_ps(xmm_ae);
					xmm_bf = _mm_cvtpd_ps(xmm_af);
					xmm_b0 = _mm_shuffle_ps(xmm_b0, xmm_b1, _MM_SHUFFLE(1, 0, 1, 0));
					xmm_b2 = _mm_shuffle_ps(xmm_b2, xmm_b3, _MM_SHUFFLE(1, 0, 1, 0));
					xmm_b4 = _mm_shuffle_ps(xmm_b4, xmm_b5, _MM_SHUFFLE(1, 0, 1, 0));
					xmm_b6 = _mm_shuffle_ps(xmm_b6, xmm_b7, _MM_SHUFFLE(1, 0, 1, 0));
					xmm_b8 = _mm_shuffle_ps(xmm_b8, xmm_b9, _MM_SHUFFLE(1, 0, 1, 0));
					xmm_ba = _mm_shuffle_ps(xmm_ba, xmm_bb, _MM_SHUFFLE(1, 0, 1, 0));
					xmm_bc = _mm_shuffle_ps(xmm_bc, xmm_bd, _MM_SHUFFLE(1, 0, 1, 0));
					xmm_be = _mm_shuffle_ps(xmm_be, xmm_bf, _MM_SHUFFLE(1, 0, 1, 0));
					_mm_stream_ps(b, xmm_b0);
					_mm_stream_ps(b + 4, xmm_b2);
					_mm_stream_ps(b + 8, xmm_b4);
					_mm_stream_ps(b + 12, xmm_b6);
					_mm_stream_ps(b + 16, xmm_b8);
					_mm_stream_ps(b + 20, xmm_ba);
					_mm_stream_ps(b + 24, xmm_bc);
					_mm_stream_ps(b + 28, xmm_be);
					a += 32;
					b += 32;
				}
			}
			else
			{
				for (; n >= 32; n -= 32)
				{
					xmm_a0 = _mm_loadu_pd(a);
					xmm_a1 = _mm_loadu_pd(a + 2);
					xmm_a2 = _mm_loadu_pd(a + 4);
					xmm_a3 = _mm_loadu_pd(a + 6);
					xmm_a4 = _mm_loadu_pd(a + 8);
					xmm_a5 = _mm_loadu_pd(a + 10);
					xmm_a6 = _mm_loadu_pd(a + 12);
					xmm_a7 = _mm_loadu_pd(a + 14);
					xmm_a8 = _mm_loadu_pd(a + 16);
					xmm_a9 = _mm_loadu_pd(a + 18);
					xmm_aa = _mm_loadu_pd(a + 20);
					xmm_ab = _mm_loadu_pd(a + 22);
					xmm_ac = _mm_loadu_pd(a + 24);
					xmm_ad = _mm_loadu_pd(a + 26);
					xmm_ae = _mm_loadu_pd(a + 28);
					xmm_af = _mm_loadu_pd(a + 30);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
					xmm_a0 = _mm_max_pd(xmm_a0, min);
					xmm_a1 = _mm_max_pd(xmm_a1, min);
					xmm_a2 = _mm_max_pd(xmm_a2, min);
					xmm_a3 = _mm_max_pd(xmm_a3, min);
					xmm_a4 = _mm_max_pd(xmm_a4, min);
					xmm_a5 = _mm_max_pd(xmm_a5, min);
					xmm_a6 = _mm_max_pd(xmm_a6, min);
					xmm_a7 = _mm_max_pd(xmm_a7, min);
					xmm_a8 = _mm_max_pd(xmm_a8, min);
					xmm_a9 = _mm_max_pd(xmm_a9, min);
					xmm_aa = _mm_max_pd(xmm_aa, min);
					xmm_ab = _mm_max_pd(xmm_ab, min);
					xmm_ac = _mm_max_pd(xmm_ac, min);
					xmm_ad = _mm_max_pd(xmm_ad, min);
					xmm_ae = _mm_max_pd(xmm_ae, min);
					xmm_af = _mm_max_pd(xmm_af, min);
					xmm_a0 = _mm_min_pd(xmm_a0, max);
					xmm_a1 = _mm_min_pd(xmm_a1, max);
					xmm_a2 = _mm_min_pd(xmm_a2, max);
					xmm_a3 = _mm_min_pd(xmm_a3, max);
					xmm_a4 = _mm_min_pd(xmm_a4, max);
					xmm_a5 = _mm_min_pd(xmm_a5, max);
					xmm_a6 = _mm_min_pd(xmm_a6, max);
					xmm_a7 = _mm_min_pd(xmm_a7, max);
					xmm_a8 = _mm_min_pd(xmm_a8, max);
					xmm_a9 = _mm_min_pd(xmm_a9, max);
					xmm_aa = _mm_min_pd(xmm_aa, max);
					xmm_ab = _mm_min_pd(xmm_ab, max);
					xmm_ac = _mm_min_pd(xmm_ac, max);
					xmm_ad = _mm_min_pd(xmm_ad, max);
					xmm_ae = _mm_min_pd(xmm_ae, max);
					xmm_af = _mm_min_pd(xmm_af, max);
					xmm_b0 = _mm_cvtpd_ps(xmm_a0);
					xmm_b1 = _mm_cvtpd_ps(xmm_a1);
					xmm_b2 = _mm_cvtpd_ps(xmm_a2);
					xmm_b3 = _mm_cvtpd_ps(xmm_a3);
					xmm_b4 = _mm_cvtpd_ps(xmm_a4);
					xmm_b5 = _mm_cvtpd_ps(xmm_a5);
					xmm_b6 = _mm_cvtpd_ps(xmm_a6);
					xmm_b7 = _mm_cvtpd_ps(xmm_a7);
					xmm_b8 = _mm_cvtpd_ps(xmm_a8);
					xmm_b9 = _mm_cvtpd_ps(xmm_a9);
					xmm_ba = _mm_cvtpd_ps(xmm_aa);
					xmm_bb = _mm_cvtpd_ps(xmm_ab);
					xmm_bc = _mm_cvtpd_ps(xmm_ac);
					xmm_bd = _mm_cvtpd_ps(xmm_ad);
					xmm_be = _mm_cvtpd_ps(xmm_ae);
					xmm_bf = _mm_cvtpd_ps(xmm_af);
					xmm_b0 = _mm_shuffle_ps(xmm_b0, xmm_b1, _MM_SHUFFLE(1, 0, 1, 0));
					xmm_b2 = _mm_shuffle_ps(xmm_b2, xmm_b3, _MM_SHUFFLE(1, 0, 1, 0));
					xmm_b4 = _mm_shuffle_ps(xmm_b4, xmm_b5, _MM_SHUFFLE(1, 0, 1, 0));
					xmm_b6 = _mm_shuffle_ps(xmm_b6, xmm_b7, _MM_SHUFFLE(1, 0, 1, 0));
					xmm_b8 = _mm_shuffle_ps(xmm_b8, xmm_b9, _MM_SHUFFLE(1, 0, 1, 0));
					xmm_ba = _mm_shuffle_ps(xmm_ba, xmm_bb, _MM_SHUFFLE(1, 0, 1, 0));
					xmm_bc = _mm_shuffle_ps(xmm_bc, xmm_bd, _MM_SHUFFLE(1, 0, 1, 0));
					xmm_be = _mm_shuffle_ps(xmm_be, xmm_bf, _MM_SHUFFLE(1, 0, 1, 0));
					_mm_stream_ps(b, xmm_b0);
					_mm_stream_ps(b + 4, xmm_b2);
					_mm_stream_ps(b + 8, xmm_b4);
					_mm_stream_ps(b + 12, xmm_b6);
					_mm_stream_ps(b + 16, xmm_b8);
					_mm_stream_ps(b + 20, xmm_ba);
					_mm_stream_ps(b + 24, xmm_bc);
					_mm_stream_ps(b + 28, xmm_be);
					a += 32;
					b += 32;
				}
			}
		}

		// Function template impl_cvtspd

		template <class T>
		inline void impl_cvtspd(T* b, const double* a, size_t n)
		{
			constexpr size_t threshold = simd::l2_cache_size / sizeof(double);
			// Small amount of data type conversion.
			if (n < 64)
				cvtspd_sse41_small(b, a, n);
			// Medium amount data type conversion.
			else if (n < threshold)
			{
				cvtspd_sse41_medium(b, a, n);
				cvtspd_sse41_small(b, a, n);
			}
			// Large amount data type conversion.
			else
			{
				cvtspd_sse41_large(b, a, n);
				cvtspd_sse41_small(b, a, n);
			}
		}

	#else

		// Function template impl_cvtspd

		template <class T>
		void impl_cvtspd(T* b, const double* a, size_t n)
		{
			constexpr size_t block = 8;
			while (n >= block)
			{
				b[0] = static_cast<T>(a[0]);
				b[1] = static_cast<T>(a[1]);
				b[2] = static_cast<T>(a[2]);
				b[3] = static_cast<T>(a[3]);
				b[4] = static_cast<T>(a[4]);
				b[5] = static_cast<T>(a[5]);
				b[6] = static_cast<T>(a[6]);
				b[7] = static_cast<T>(a[7]);
				a += block;
				b += block;
				n -= block;
			}
			switch (n)
			{
			case 7: b[6] = static_cast<T>(a[6]);
			case 6: b[5] = static_cast<T>(a[5]);
			case 5: b[4] = static_cast<T>(a[4]);
			case 4: b[3] = static_cast<T>(a[3]);
			case 3: b[2] = static_cast<T>(a[2]);
			case 2: b[1] = static_cast<T>(a[1]);
			case 1: b[0] = static_cast<T>(a[0]);
				break;
			}
		}

		template<>
		void impl_cvtspd<signed char>(signed char* b, const double* a, size_t n)
		{
			constexpr size_t block = 8;
			constexpr double min = static_cast<double>(INT8_MIN);
			constexpr double max = static_cast<double>(INT8_MAX);
			while (n >= block)
			{
				b[0] = a[0] < min ? INT8_MIN : a[0] > max ? INT8_MAX : static_cast<signed char>(a[0]);
				b[1] = a[1] < min ? INT8_MIN : a[1] > max ? INT8_MAX : static_cast<signed char>(a[1]);
				b[2] = a[2] < min ? INT8_MIN : a[2] > max ? INT8_MAX : static_cast<signed char>(a[2]);
				b[3] = a[3] < min ? INT8_MIN : a[3] > max ? INT8_MAX : static_cast<signed char>(a[3]);
				b[4] = a[4] < min ? INT8_MIN : a[4] > max ? INT8_MAX : static_cast<signed char>(a[4]);
				b[5] = a[5] < min ? INT8_MIN : a[5] > max ? INT8_MAX : static_cast<signed char>(a[5]);
				b[6] = a[6] < min ? INT8_MIN : a[6] > max ? INT8_MAX : static_cast<signed char>(a[6]);
				b[7] = a[7] < min ? INT8_MIN : a[7] > max ? INT8_MAX : static_cast<signed char>(a[7]);
				a += block;
				b += block;
				n -= block;
			}
			switch (n)
			{
			case 7: b[6] = a[6] < min ? INT8_MIN : a[6] > max ? INT8_MAX : static_cast<signed char>(a[6]);
			case 6: b[5] = a[5] < min ? INT8_MIN : a[5] > max ? INT8_MAX : static_cast<signed char>(a[5]);
			case 5: b[4] = a[4] < min ? INT8_MIN : a[4] > max ? INT8_MAX : static_cast<signed char>(a[4]);
			case 4: b[3] = a[3] < min ? INT8_MIN : a[3] > max ? INT8_MAX : static_cast<signed char>(a[3]);
			case 3: b[2] = a[2] < min ? INT8_MIN : a[2] > max ? INT8_MAX : static_cast<signed char>(a[2]);
			case 2: b[1] = a[1] < min ? INT8_MIN : a[1] > max ? INT8_MAX : static_cast<signed char>(a[1]);
			case 1: b[0] = a[0] < min ? INT8_MIN : a[0] > max ? INT8_MAX : static_cast<signed char>(a[0]);
				break;
			}
		}

		template<>
		void impl_cvtspd<unsigned char>(unsigned char* b, const double* a, size_t n)
		{
			constexpr size_t block = 8;
			constexpr double max = static_cast<double>(UINT8_MAX);
			while (n >= block)
			{
				b[0] = a[0] < 0 ? 0 : a[0] > max ? UINT8_MAX : static_cast<unsigned char>(a[0]);
				b[1] = a[1] < 0 ? 0 : a[1] > max ? UINT8_MAX : static_cast<unsigned char>(a[1]);
				b[2] = a[2] < 0 ? 0 : a[2] > max ? UINT8_MAX : static_cast<unsigned char>(a[2]);
				b[3] = a[3] < 0 ? 0 : a[3] > max ? UINT8_MAX : static_cast<unsigned char>(a[3]);
				b[4] = a[4] < 0 ? 0 : a[4] > max ? UINT8_MAX : static_cast<unsigned char>(a[4]);
				b[5] = a[5] < 0 ? 0 : a[5] > max ? UINT8_MAX : static_cast<unsigned char>(a[5]);
				b[6] = a[6] < 0 ? 0 : a[6] > max ? UINT8_MAX : static_cast<unsigned char>(a[6]);
				b[7] = a[7] < 0 ? 0 : a[7] > max ? UINT8_MAX : static_cast<unsigned char>(a[7]);
				a += block;
				b += block;
				n -= block;
			}
			switch (n)
			{
			case 7: b[6] = a[6] < 0 ? 0 : a[6] > max ? UINT8_MAX : static_cast<unsigned char>(a[6]);
			case 6: b[5] = a[5] < 0 ? 0 : a[5] > max ? UINT8_MAX : static_cast<unsigned char>(a[5]);
			case 5: b[4] = a[4] < 0 ? 0 : a[4] > max ? UINT8_MAX : static_cast<unsigned char>(a[4]);
			case 4: b[3] = a[3] < 0 ? 0 : a[3] > max ? UINT8_MAX : static_cast<unsigned char>(a[3]);
			case 3: b[2] = a[2] < 0 ? 0 : a[2] > max ? UINT8_MAX : static_cast<unsigned char>(a[2]);
			case 2: b[1] = a[1] < 0 ? 0 : a[1] > max ? UINT8_MAX : static_cast<unsigned char>(a[1]);
			case 1: b[0] = a[0] < 0 ? 0 : a[0] > max ? UINT8_MAX : static_cast<unsigned char>(a[0]);
				break;
			}
		}

		template<>
		void impl_cvtspd<signed short>(signed short* b, const double* a, size_t n)
		{
			constexpr size_t block = 8;
			constexpr double min = static_cast<double>(INT16_MIN);
			constexpr double max = static_cast<double>(INT16_MAX);
			while (n >= block)
			{
				b[0] = a[0] < min ? INT16_MIN : a[0] > max ? INT16_MAX : static_cast<signed short>(a[0]);
				b[1] = a[1] < min ? INT16_MIN : a[1] > max ? INT16_MAX : static_cast<signed short>(a[1]);
				b[2] = a[2] < min ? INT16_MIN : a[2] > max ? INT16_MAX : static_cast<signed short>(a[2]);
				b[3] = a[3] < min ? INT16_MIN : a[3] > max ? INT16_MAX : static_cast<signed short>(a[3]);
				b[4] = a[4] < min ? INT16_MIN : a[4] > max ? INT16_MAX : static_cast<signed short>(a[4]);
				b[5] = a[5] < min ? INT16_MIN : a[5] > max ? INT16_MAX : static_cast<signed short>(a[5]);
				b[6] = a[6] < min ? INT16_MIN : a[6] > max ? INT16_MAX : static_cast<signed short>(a[6]);
				b[7] = a[7] < min ? INT16_MIN : a[7] > max ? INT16_MAX : static_cast<signed short>(a[7]);
				a += block;
				b += block;
				n -= block;
			}
			switch (n)
			{
			case 7: b[6] = a[6] < min ? INT16_MIN : a[6] > max ? INT16_MAX : static_cast<signed short>(a[6]);
			case 6: b[5] = a[5] < min ? INT16_MIN : a[5] > max ? INT16_MAX : static_cast<signed short>(a[5]);
			case 5: b[4] = a[4] < min ? INT16_MIN : a[4] > max ? INT16_MAX : static_cast<signed short>(a[4]);
			case 4: b[3] = a[3] < min ? INT16_MIN : a[3] > max ? INT16_MAX : static_cast<signed short>(a[3]);
			case 3: b[2] = a[2] < min ? INT16_MIN : a[2] > max ? INT16_MAX : static_cast<signed short>(a[2]);
			case 2: b[1] = a[1] < min ? INT16_MIN : a[1] > max ? INT16_MAX : static_cast<signed short>(a[1]);
			case 1: b[0] = a[0] < min ? INT16_MIN : a[0] > max ? INT16_MAX : static_cast<signed short>(a[0]);
				break;
			}
		}

		template<>
		void impl_cvtspd<unsigned short>(unsigned short* b, const double* a, size_t n)
		{
			constexpr size_t block = 8;
			constexpr double max = static_cast<double>(UINT16_MAX);
			while (n >= block)
			{
				b[0] = a[0] < 0 ? 0 : a[0] > max ? UINT16_MAX : static_cast<unsigned short>(a[0]);
				b[1] = a[1] < 0 ? 0 : a[1] > max ? UINT16_MAX : static_cast<unsigned short>(a[1]);
				b[2] = a[2] < 0 ? 0 : a[2] > max ? UINT16_MAX : static_cast<unsigned short>(a[2]);
				b[3] = a[3] < 0 ? 0 : a[3] > max ? UINT16_MAX : static_cast<unsigned short>(a[3]);
				b[4] = a[4] < 0 ? 0 : a[4] > max ? UINT16_MAX : static_cast<unsigned short>(a[4]);
				b[5] = a[5] < 0 ? 0 : a[5] > max ? UINT16_MAX : static_cast<unsigned short>(a[5]);
				b[6] = a[6] < 0 ? 0 : a[6] > max ? UINT16_MAX : static_cast<unsigned short>(a[6]);
				b[7] = a[7] < 0 ? 0 : a[7] > max ? UINT16_MAX : static_cast<unsigned short>(a[7]);
				a += block;
				b += block;
				n -= block;
			}
			switch (n)
			{
			case 7: b[6] = a[6] < 0 ? 0 : a[6] > max ? UINT16_MAX : static_cast<unsigned short>(a[6]);
			case 6: b[5] = a[5] < 0 ? 0 : a[5] > max ? UINT16_MAX : static_cast<unsigned short>(a[5]);
			case 5: b[4] = a[4] < 0 ? 0 : a[4] > max ? UINT16_MAX : static_cast<unsigned short>(a[4]);
			case 4: b[3] = a[3] < 0 ? 0 : a[3] > max ? UINT16_MAX : static_cast<unsigned short>(a[3]);
			case 3: b[2] = a[2] < 0 ? 0 : a[2] > max ? UINT16_MAX : static_cast<unsigned short>(a[2]);
			case 2: b[1] = a[1] < 0 ? 0 : a[1] > max ? UINT16_MAX : static_cast<unsigned short>(a[1]);
			case 1: b[0] = a[0] < 0 ? 0 : a[0] > max ? UINT16_MAX : static_cast<unsigned short>(a[0]);
				break;
			}
		}

		template<>
		void impl_cvtspd<signed int>(signed int* b, const double* a, size_t n)
		{
			constexpr size_t block = 8;
			constexpr double min = -2.14748352e+9F;
			constexpr double max =  2.14748352e+9F;
			while (n >= block)
			{
				b[0] = a[0] < min ? INT32_MIN : a[0] > max ? INT32_MAX : static_cast<signed int>(a[0]);
				b[1] = a[1] < min ? INT32_MIN : a[1] > max ? INT32_MAX : static_cast<signed int>(a[1]);
				b[2] = a[2] < min ? INT32_MIN : a[2] > max ? INT32_MAX : static_cast<signed int>(a[2]);
				b[3] = a[3] < min ? INT32_MIN : a[3] > max ? INT32_MAX : static_cast<signed int>(a[3]);
				b[4] = a[4] < min ? INT32_MIN : a[4] > max ? INT32_MAX : static_cast<signed int>(a[4]);
				b[5] = a[5] < min ? INT32_MIN : a[5] > max ? INT32_MAX : static_cast<signed int>(a[5]);
				b[6] = a[6] < min ? INT32_MIN : a[6] > max ? INT32_MAX : static_cast<signed int>(a[6]);
				b[7] = a[7] < min ? INT32_MIN : a[7] > max ? INT32_MAX : static_cast<signed int>(a[7]);
				a += block;
				b += block;
				n -= block;
			}
			switch (n)
			{
			case 7: b[6] = a[6] < min ? INT32_MIN : a[6] > max ? INT32_MAX : static_cast<signed int>(a[6]);
			case 6: b[5] = a[5] < min ? INT32_MIN : a[5] > max ? INT32_MAX : static_cast<signed int>(a[5]);
			case 5: b[4] = a[4] < min ? INT32_MIN : a[4] > max ? INT32_MAX : static_cast<signed int>(a[4]);
			case 4: b[3] = a[3] < min ? INT32_MIN : a[3] > max ? INT32_MAX : static_cast<signed int>(a[3]);
			case 3: b[2] = a[2] < min ? INT32_MIN : a[2] > max ? INT32_MAX : static_cast<signed int>(a[2]);
			case 2: b[1] = a[1] < min ? INT32_MIN : a[1] > max ? INT32_MAX : static_cast<signed int>(a[1]);
			case 1: b[0] = a[0] < min ? INT32_MIN : a[0] > max ? INT32_MAX : static_cast<signed int>(a[0]);
				break;
			}
		}

		template<>
		void impl_cvtspd<unsigned int>(unsigned int* b, const double* a, size_t n)
		{
			constexpr size_t block = 8;
			constexpr double max = 4.294967167e+9F;
			while (n >= block)
			{
				b[0] = a[0] < 0 ? 0 : a[0] > max ? UINT32_MAX : static_cast<unsigned int>(a[0]);
				b[1] = a[1] < 0 ? 0 : a[1] > max ? UINT32_MAX : static_cast<unsigned int>(a[1]);
				b[2] = a[2] < 0 ? 0 : a[2] > max ? UINT32_MAX : static_cast<unsigned int>(a[2]);
				b[3] = a[3] < 0 ? 0 : a[3] > max ? UINT32_MAX : static_cast<unsigned int>(a[3]);
				b[4] = a[4] < 0 ? 0 : a[4] > max ? UINT32_MAX : static_cast<unsigned int>(a[4]);
				b[5] = a[5] < 0 ? 0 : a[5] > max ? UINT32_MAX : static_cast<unsigned int>(a[5]);
				b[6] = a[6] < 0 ? 0 : a[6] > max ? UINT32_MAX : static_cast<unsigned int>(a[6]);
				b[7] = a[7] < 0 ? 0 : a[7] > max ? UINT32_MAX : static_cast<unsigned int>(a[7]);
				a += block;
				b += block;
				n -= block;
			}
			switch (n)
			{
			case 7: b[6] = a[6] < 0 ? 0 : a[6] > max ? UINT32_MAX : static_cast<unsigned int>(a[6]);
			case 6: b[5] = a[5] < 0 ? 0 : a[5] > max ? UINT32_MAX : static_cast<unsigned int>(a[5]);
			case 5: b[4] = a[4] < 0 ? 0 : a[4] > max ? UINT32_MAX : static_cast<unsigned int>(a[4]);
			case 4: b[3] = a[3] < 0 ? 0 : a[3] > max ? UINT32_MAX : static_cast<unsigned int>(a[3]);
			case 3: b[2] = a[2] < 0 ? 0 : a[2] > max ? UINT32_MAX : static_cast<unsigned int>(a[2]);
			case 2: b[1] = a[1] < 0 ? 0 : a[1] > max ? UINT32_MAX : static_cast<unsigned int>(a[1]);
			case 1: b[0] = a[0] < 0 ? 0 : a[0] > max ? UINT32_MAX : static_cast<unsigned int>(a[0]);
				break;
			}
		}

		template<>
		void impl_cvtspd<float>(float* b, const double* a, size_t n)
		{
			constexpr size_t block = 8;
			constexpr double min = static_cast<double>(-FLT_MAX);
			constexpr double max = static_cast<double>(FLT_MAX);
			while (n >= block)
			{
				b[0] = a[0] < min ? -FLT_MAX : a[0] > max ? FLT_MAX : static_cast<float>(a[0]);
				b[1] = a[1] < min ? -FLT_MAX : a[1] > max ? FLT_MAX : static_cast<float>(a[1]);
				b[2] = a[2] < min ? -FLT_MAX : a[2] > max ? FLT_MAX : static_cast<float>(a[2]);
				b[3] = a[3] < min ? -FLT_MAX : a[3] > max ? FLT_MAX : static_cast<float>(a[3]);
				b[4] = a[4] < min ? -FLT_MAX : a[4] > max ? FLT_MAX : static_cast<float>(a[4]);
				b[5] = a[5] < min ? -FLT_MAX : a[5] > max ? FLT_MAX : static_cast<float>(a[5]);
				b[6] = a[6] < min ? -FLT_MAX : a[6] > max ? FLT_MAX : static_cast<float>(a[6]);
				b[7] = a[7] < min ? -FLT_MAX : a[7] > max ? FLT_MAX : static_cast<float>(a[7]);
				a += block;
				b += block;
				n -= block;
			}
			switch (n)
			{
			case 7: b[6] = a[6] < min ? -FLT_MAX : a[6] > max ? FLT_MAX : static_cast<float>(a[6]);
			case 6: b[5] = a[5] < min ? -FLT_MAX : a[5] > max ? FLT_MAX : static_cast<float>(a[5]);
			case 5: b[4] = a[4] < min ? -FLT_MAX : a[4] > max ? FLT_MAX : static_cast<float>(a[4]);
			case 4: b[3] = a[3] < min ? -FLT_MAX : a[3] > max ? FLT_MAX : static_cast<float>(a[3]);
			case 3: b[2] = a[2] < min ? -FLT_MAX : a[2] > max ? FLT_MAX : static_cast<float>(a[2]);
			case 2: b[1] = a[1] < min ? -FLT_MAX : a[1] > max ? FLT_MAX : static_cast<float>(a[1]);
			case 1: b[0] = a[0] < min ? -FLT_MAX : a[0] > max ? FLT_MAX : static_cast<float>(a[0]);
				break;
			}
		}

	#endif

		template <>
		void impl_cvtspd<double>(double* b, const double* a, size_t n)
		{
			std::memcpy(b, a, n * sizeof(double));
		}

	} // namespace cpu

} // namespace core

#endif
