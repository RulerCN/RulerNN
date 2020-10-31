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

#ifndef __CORE_CPU_CVTI8_H__
#define __CORE_CPU_CVTI8_H__

#include <cstddef>
#include <cstdint>
#include <cstring>
#include "../simd.h"

namespace core
{
	namespace cpu
	{
		template<class T>
		inline void cvti8_tiny(T* b, const signed char* a, size_t n)
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

	#ifdef __AVX2__

		// Function template cvti8_avx2_8

		template <class T>
		inline void cvti8_avx2_8(T* b, const signed char* a)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		inline void cvti8_avx2_8<signed short>(signed short* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
			__m256i ymm_b0 = _mm256_cvtepi8_epi16(xmm_a0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
		}

		template <>
		inline void cvti8_avx2_8<unsigned short>(unsigned short* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
			__m256i ymm_b0 = _mm256_cvtepi8_epi16(xmm_a0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), _mm256_castsi256_si128(ymm_b0));
		}

		template <>
		inline void cvti8_avx2_8<signed int>(signed int* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
			__m256i ymm_b0 = _mm256_cvtepi8_epi32(xmm_a0);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b), ymm_b0);
		}

		template <>
		inline void cvti8_avx2_8<unsigned int>(unsigned int* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
			__m256i ymm_b0 = _mm256_cvtepi8_epi32(xmm_a0);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b), ymm_b0);
		}

		template <>
		inline void cvti8_avx2_8<float>(float* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
			__m256i ymm_a0 = _mm256_cvtepi8_epi32(xmm_a0);
			__m256 ymm_b0 = _mm256_cvtepi32_ps(ymm_a0);
			_mm256_storeu_ps(b, ymm_b0);
		}

		template <>
		inline void cvti8_avx2_8<double>(double* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
			__m256i ymm_a0 = _mm256_cvtepi8_epi32(xmm_a0);
			__m256d ymm_b0 = _mm256_cvtepi32_pd(_mm256_castsi256_si128(ymm_a0));
			__m256d ymm_b1 = _mm256_cvtepi32_pd(_mm256_extracti128_si256(ymm_a0, 1));
			_mm256_storeu_pd(b, ymm_b0);
			_mm256_storeu_pd(b + 4, ymm_b1);
		}

		// Function template cvti8_avx2_16

		template <class T>
		inline void cvti8_avx2_16(T* b, const signed char* a)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		inline void cvti8_avx2_16<signed short>(signed short* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a));
			__m256i ymm_b0 = _mm256_cvtepi8_epi16(xmm_a0);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b), ymm_b0);
		}

		template <>
		inline void cvti8_avx2_16<unsigned short>(unsigned short* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a));
			__m256i ymm_b0 = _mm256_cvtepi8_epi16(xmm_a0);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b), ymm_b0);
		}

		template <>
		inline void cvti8_avx2_16<signed int>(signed int* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a1 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 8));
			__m256i ymm_b0 = _mm256_cvtepi8_epi32(xmm_a0);
			__m256i ymm_b1 = _mm256_cvtepi8_epi32(xmm_a1);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b), ymm_b0);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 1, ymm_b1);
		}

		template <>
		inline void cvti8_avx2_16<unsigned int>(unsigned int* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a1 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 8));
			__m256i ymm_b0 = _mm256_cvtepi8_epi32(xmm_a0);
			__m256i ymm_b1 = _mm256_cvtepi8_epi32(xmm_a1);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b), ymm_b0);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 1, ymm_b1);
		}

		template <>
		inline void cvti8_avx2_16<float>(float* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a1 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 8));
			__m256i ymm_a0 = _mm256_cvtepi8_epi32(xmm_a0);
			__m256i ymm_a1 = _mm256_cvtepi8_epi32(xmm_a1);
			__m256 ymm_b0 = _mm256_cvtepi32_ps(ymm_a0);
			__m256 ymm_b1 = _mm256_cvtepi32_ps(ymm_a1);
			_mm256_storeu_ps(b, ymm_b0);
			_mm256_storeu_ps(b + 8, ymm_b1);
		}

		template <>
		inline void cvti8_avx2_16<double>(double* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a1 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 8));
			__m256i ymm_a0 = _mm256_cvtepi8_epi32(xmm_a0);
			__m256i ymm_a1 = _mm256_cvtepi8_epi32(xmm_a1);
			__m256d ymm_b0 = _mm256_cvtepi32_pd(_mm256_castsi256_si128(ymm_a0));
			__m256d ymm_b1 = _mm256_cvtepi32_pd(_mm256_extracti128_si256(ymm_a0, 1));
			__m256d ymm_b2 = _mm256_cvtepi32_pd(_mm256_castsi256_si128(ymm_a1));
			__m256d ymm_b3 = _mm256_cvtepi32_pd(_mm256_extracti128_si256(ymm_a1, 1));
			_mm256_storeu_pd(b, ymm_b0);
			_mm256_storeu_pd(b + 4, ymm_b1);
			_mm256_storeu_pd(b + 8, ymm_b2);
			_mm256_storeu_pd(b + 12, ymm_b3);
		}

		// Function template cvti8_avx2_32

		template <class T>
		inline void cvti8_avx2_32(T* b, const signed char* a)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		inline void cvti8_avx2_32<signed short>(signed short* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 1);
			__m256i ymm_b0 = _mm256_cvtepi8_epi16(xmm_a0);
			__m256i ymm_b1 = _mm256_cvtepi8_epi16(xmm_a1);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b), ymm_b0);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 1, ymm_b1);
		}

		template <>
		inline void cvti8_avx2_32<unsigned short>(unsigned short* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 1);
			__m256i ymm_b0 = _mm256_cvtepi8_epi16(xmm_a0);
			__m256i ymm_b1 = _mm256_cvtepi8_epi16(xmm_a1);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b), ymm_b0);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 1, ymm_b1);
		}

		template <>
		inline void cvti8_avx2_32<signed int>(signed int* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a1 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 8));
			__m128i xmm_a2 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 16));
			__m128i xmm_a3 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 24));
			__m256i ymm_b0 = _mm256_cvtepi8_epi32(xmm_a0);
			__m256i ymm_b1 = _mm256_cvtepi8_epi32(xmm_a1);
			__m256i ymm_b2 = _mm256_cvtepi8_epi32(xmm_a2);
			__m256i ymm_b3 = _mm256_cvtepi8_epi32(xmm_a3);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b), ymm_b0);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 1, ymm_b1);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 2, ymm_b2);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 3, ymm_b3);
		}

		template <>
		inline void cvti8_avx2_32<unsigned int>(unsigned int* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a1 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 8));
			__m128i xmm_a2 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 16));
			__m128i xmm_a3 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 24));
			__m256i ymm_b0 = _mm256_cvtepi8_epi32(xmm_a0);
			__m256i ymm_b1 = _mm256_cvtepi8_epi32(xmm_a1);
			__m256i ymm_b2 = _mm256_cvtepi8_epi32(xmm_a2);
			__m256i ymm_b3 = _mm256_cvtepi8_epi32(xmm_a3);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b), ymm_b0);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 1, ymm_b1);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 2, ymm_b2);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 3, ymm_b3);
		}

		template <>
		inline void cvti8_avx2_32<float>(float* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a1 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 8));
			__m128i xmm_a2 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 16));
			__m128i xmm_a3 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 24));
			__m256i ymm_a0 = _mm256_cvtepi8_epi32(xmm_a0);
			__m256i ymm_a1 = _mm256_cvtepi8_epi32(xmm_a1);
			__m256i ymm_a2 = _mm256_cvtepi8_epi32(xmm_a2);
			__m256i ymm_a3 = _mm256_cvtepi8_epi32(xmm_a3);
			__m256 ymm_b0 = _mm256_cvtepi32_ps(ymm_a0);
			__m256 ymm_b1 = _mm256_cvtepi32_ps(ymm_a1);
			__m256 ymm_b2 = _mm256_cvtepi32_ps(ymm_a2);
			__m256 ymm_b3 = _mm256_cvtepi32_ps(ymm_a3);
			_mm256_storeu_ps(b, ymm_b0);
			_mm256_storeu_ps(b + 8, ymm_b1);
			_mm256_storeu_ps(b + 16, ymm_b2);
			_mm256_storeu_ps(b + 24, ymm_b3);
		}

		template <>
		inline void cvti8_avx2_32<double>(double* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a1 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 8));
			__m128i xmm_a2 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 16));
			__m128i xmm_a3 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 24));
			__m256i ymm_a0 = _mm256_cvtepi8_epi32(xmm_a0);
			__m256i ymm_a1 = _mm256_cvtepi8_epi32(xmm_a1);
			__m256i ymm_a2 = _mm256_cvtepi8_epi32(xmm_a2);
			__m256i ymm_a3 = _mm256_cvtepi8_epi32(xmm_a3);
			__m256d ymm_b0 = _mm256_cvtepi32_pd(_mm256_castsi256_si128(ymm_a0));
			__m256d ymm_b1 = _mm256_cvtepi32_pd(_mm256_extracti128_si256(ymm_a0, 1));
			__m256d ymm_b2 = _mm256_cvtepi32_pd(_mm256_castsi256_si128(ymm_a1));
			__m256d ymm_b3 = _mm256_cvtepi32_pd(_mm256_extracti128_si256(ymm_a1, 1));
			__m256d ymm_b4 = _mm256_cvtepi32_pd(_mm256_castsi256_si128(ymm_a2));
			__m256d ymm_b5 = _mm256_cvtepi32_pd(_mm256_extracti128_si256(ymm_a2, 1));
			__m256d ymm_b6 = _mm256_cvtepi32_pd(_mm256_castsi256_si128(ymm_a3));
			__m256d ymm_b7 = _mm256_cvtepi32_pd(_mm256_extracti128_si256(ymm_a3, 1));
			_mm256_storeu_pd(b, ymm_b0);
			_mm256_storeu_pd(b + 4, ymm_b1);
			_mm256_storeu_pd(b + 8, ymm_b2);
			_mm256_storeu_pd(b + 12, ymm_b3);
			_mm256_storeu_pd(b + 16, ymm_b4);
			_mm256_storeu_pd(b + 20, ymm_b5);
			_mm256_storeu_pd(b + 24, ymm_b6);
			_mm256_storeu_pd(b + 28, ymm_b7);
		}

		// Function template cvti8_avx2_64

		template <class T>
		inline void cvti8_avx2_64(T* b, const signed char* a)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		inline void cvti8_avx2_64<signed short>(signed short* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 1);
			__m128i xmm_a2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 2);
			__m128i xmm_a3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 3);
			__m256i ymm_b0 = _mm256_cvtepi8_epi16(xmm_a0);
			__m256i ymm_b1 = _mm256_cvtepi8_epi16(xmm_a1);
			__m256i ymm_b2 = _mm256_cvtepi8_epi16(xmm_a2);
			__m256i ymm_b3 = _mm256_cvtepi8_epi16(xmm_a3);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b), ymm_b0);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 1, ymm_b1);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 2, ymm_b2);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 3, ymm_b3);
		}

		template <>
		inline void cvti8_avx2_64<unsigned short>(unsigned short* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 1);
			__m128i xmm_a2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 2);
			__m128i xmm_a3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 3);
			__m256i ymm_b0 = _mm256_cvtepi8_epi16(xmm_a0);
			__m256i ymm_b1 = _mm256_cvtepi8_epi16(xmm_a1);
			__m256i ymm_b2 = _mm256_cvtepi8_epi16(xmm_a2);
			__m256i ymm_b3 = _mm256_cvtepi8_epi16(xmm_a3);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b), ymm_b0);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 1, ymm_b1);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 2, ymm_b2);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 3, ymm_b3);
		}

		template <>
		inline void cvti8_avx2_64<signed int>(signed int* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a1 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 8));
			__m128i xmm_a2 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 16));
			__m128i xmm_a3 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 24));
			__m128i xmm_a4 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 32));
			__m128i xmm_a5 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 40));
			__m128i xmm_a6 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 48));
			__m128i xmm_a7 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 56));
			__m256i ymm_b0 = _mm256_cvtepi8_epi32(xmm_a0);
			__m256i ymm_b1 = _mm256_cvtepi8_epi32(xmm_a1);
			__m256i ymm_b2 = _mm256_cvtepi8_epi32(xmm_a2);
			__m256i ymm_b3 = _mm256_cvtepi8_epi32(xmm_a3);
			__m256i ymm_b4 = _mm256_cvtepi8_epi32(xmm_a4);
			__m256i ymm_b5 = _mm256_cvtepi8_epi32(xmm_a5);
			__m256i ymm_b6 = _mm256_cvtepi8_epi32(xmm_a6);
			__m256i ymm_b7 = _mm256_cvtepi8_epi32(xmm_a7);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b), ymm_b0);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 1, ymm_b1);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 2, ymm_b2);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 3, ymm_b3);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 4, ymm_b4);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 5, ymm_b5);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 6, ymm_b6);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 7, ymm_b7);
		}

		template <>
		inline void cvti8_avx2_64<unsigned int>(unsigned int* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a1 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 8));
			__m128i xmm_a2 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 16));
			__m128i xmm_a3 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 24));
			__m128i xmm_a4 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 32));
			__m128i xmm_a5 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 40));
			__m128i xmm_a6 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 48));
			__m128i xmm_a7 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 56));
			__m256i ymm_b0 = _mm256_cvtepi8_epi32(xmm_a0);
			__m256i ymm_b1 = _mm256_cvtepi8_epi32(xmm_a1);
			__m256i ymm_b2 = _mm256_cvtepi8_epi32(xmm_a2);
			__m256i ymm_b3 = _mm256_cvtepi8_epi32(xmm_a3);
			__m256i ymm_b4 = _mm256_cvtepi8_epi32(xmm_a4);
			__m256i ymm_b5 = _mm256_cvtepi8_epi32(xmm_a5);
			__m256i ymm_b6 = _mm256_cvtepi8_epi32(xmm_a6);
			__m256i ymm_b7 = _mm256_cvtepi8_epi32(xmm_a7);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b), ymm_b0);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 1, ymm_b1);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 2, ymm_b2);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 3, ymm_b3);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 4, ymm_b4);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 5, ymm_b5);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 6, ymm_b6);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 7, ymm_b7);
		}

		template <>
		inline void cvti8_avx2_64<float>(float* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a1 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 8));
			__m128i xmm_a2 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 16));
			__m128i xmm_a3 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 24));
			__m128i xmm_a4 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 32));
			__m128i xmm_a5 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 40));
			__m128i xmm_a6 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 48));
			__m128i xmm_a7 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 56));
			__m256i ymm_a0 = _mm256_cvtepi8_epi32(xmm_a0);
			__m256i ymm_a1 = _mm256_cvtepi8_epi32(xmm_a1);
			__m256i ymm_a2 = _mm256_cvtepi8_epi32(xmm_a2);
			__m256i ymm_a3 = _mm256_cvtepi8_epi32(xmm_a3);
			__m256i ymm_a4 = _mm256_cvtepi8_epi32(xmm_a4);
			__m256i ymm_a5 = _mm256_cvtepi8_epi32(xmm_a5);
			__m256i ymm_a6 = _mm256_cvtepi8_epi32(xmm_a6);
			__m256i ymm_a7 = _mm256_cvtepi8_epi32(xmm_a7);
			__m256 ymm_b0 = _mm256_cvtepi32_ps(ymm_a0);
			__m256 ymm_b1 = _mm256_cvtepi32_ps(ymm_a1);
			__m256 ymm_b2 = _mm256_cvtepi32_ps(ymm_a2);
			__m256 ymm_b3 = _mm256_cvtepi32_ps(ymm_a3);
			__m256 ymm_b4 = _mm256_cvtepi32_ps(ymm_a4);
			__m256 ymm_b5 = _mm256_cvtepi32_ps(ymm_a5);
			__m256 ymm_b6 = _mm256_cvtepi32_ps(ymm_a6);
			__m256 ymm_b7 = _mm256_cvtepi32_ps(ymm_a7);
			_mm256_storeu_ps(b, ymm_b0);
			_mm256_storeu_ps(b + 8, ymm_b1);
			_mm256_storeu_ps(b + 16, ymm_b2);
			_mm256_storeu_ps(b + 24, ymm_b3);
			_mm256_storeu_ps(b + 32, ymm_b4);
			_mm256_storeu_ps(b + 40, ymm_b5);
			_mm256_storeu_ps(b + 48, ymm_b6);
			_mm256_storeu_ps(b + 56, ymm_b7);
		}

		template <>
		inline void cvti8_avx2_64<double>(double* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a1 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 8));
			__m128i xmm_a2 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 16));
			__m128i xmm_a3 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 24));
			__m128i xmm_a4 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 32));
			__m128i xmm_a5 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 40));
			__m128i xmm_a6 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 48));
			__m128i xmm_a7 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 56));
			__m256i ymm_a0 = _mm256_cvtepi8_epi32(xmm_a0);
			__m256i ymm_a1 = _mm256_cvtepi8_epi32(xmm_a1);
			__m256i ymm_a2 = _mm256_cvtepi8_epi32(xmm_a2);
			__m256i ymm_a3 = _mm256_cvtepi8_epi32(xmm_a3);
			__m256i ymm_a4 = _mm256_cvtepi8_epi32(xmm_a4);
			__m256i ymm_a5 = _mm256_cvtepi8_epi32(xmm_a5);
			__m256i ymm_a6 = _mm256_cvtepi8_epi32(xmm_a6);
			__m256i ymm_a7 = _mm256_cvtepi8_epi32(xmm_a7);
			__m256d ymm_b0 = _mm256_cvtepi32_pd(_mm256_castsi256_si128(ymm_a0));
			__m256d ymm_b1 = _mm256_cvtepi32_pd(_mm256_extracti128_si256(ymm_a0, 1));
			__m256d ymm_b2 = _mm256_cvtepi32_pd(_mm256_castsi256_si128(ymm_a1));
			__m256d ymm_b3 = _mm256_cvtepi32_pd(_mm256_extracti128_si256(ymm_a1, 1));
			__m256d ymm_b4 = _mm256_cvtepi32_pd(_mm256_castsi256_si128(ymm_a2));
			__m256d ymm_b5 = _mm256_cvtepi32_pd(_mm256_extracti128_si256(ymm_a2, 1));
			__m256d ymm_b6 = _mm256_cvtepi32_pd(_mm256_castsi256_si128(ymm_a3));
			__m256d ymm_b7 = _mm256_cvtepi32_pd(_mm256_extracti128_si256(ymm_a3, 1));
			__m256d ymm_b8 = _mm256_cvtepi32_pd(_mm256_castsi256_si128(ymm_a4));
			__m256d ymm_b9 = _mm256_cvtepi32_pd(_mm256_extracti128_si256(ymm_a4, 1));
			__m256d ymm_ba = _mm256_cvtepi32_pd(_mm256_castsi256_si128(ymm_a5));
			__m256d ymm_bb = _mm256_cvtepi32_pd(_mm256_extracti128_si256(ymm_a5, 1));
			__m256d ymm_bc = _mm256_cvtepi32_pd(_mm256_castsi256_si128(ymm_a6));
			__m256d ymm_bd = _mm256_cvtepi32_pd(_mm256_extracti128_si256(ymm_a6, 1));
			__m256d ymm_be = _mm256_cvtepi32_pd(_mm256_castsi256_si128(ymm_a7));
			__m256d ymm_bf = _mm256_cvtepi32_pd(_mm256_extracti128_si256(ymm_a7, 1));
			_mm256_storeu_pd(b, ymm_b0);
			_mm256_storeu_pd(b + 4, ymm_b1);
			_mm256_storeu_pd(b + 8, ymm_b2);
			_mm256_storeu_pd(b + 12, ymm_b3);
			_mm256_storeu_pd(b + 16, ymm_b4);
			_mm256_storeu_pd(b + 20, ymm_b5);
			_mm256_storeu_pd(b + 24, ymm_b6);
			_mm256_storeu_pd(b + 28, ymm_b7);
			_mm256_storeu_pd(b + 32, ymm_b8);
			_mm256_storeu_pd(b + 36, ymm_b9);
			_mm256_storeu_pd(b + 40, ymm_ba);
			_mm256_storeu_pd(b + 44, ymm_bb);
			_mm256_storeu_pd(b + 48, ymm_bc);
			_mm256_storeu_pd(b + 52, ymm_bd);
			_mm256_storeu_pd(b + 56, ymm_be);
			_mm256_storeu_pd(b + 60, ymm_bf);
		}

		// Function template cvti8_avx2_small

		template <class T>
		inline void cvti8_avx2_small(T* b, const signed char* a, size_t n)
		{
			switch (n >> 3)
			{
			case 8:
				cvti8_avx2_64(b, a);
			case 0:
				break;
			case 9:
				cvti8_avx2_64(b, a);
				a += 64;
				b += 64;
			case 1:
				cvti8_avx2_8(b, a);
				break;
			case 10:
				cvti8_avx2_64(b, a);
				a += 64;
				b += 64;
			case 2:
				cvti8_avx2_16(b, a);
				break;
			case 11:
				cvti8_avx2_64(b, a);
				a += 64;
				b += 64;
			case 3:
				cvti8_avx2_16(b, a);
				a += 16;
				b += 16;
				cvti8_avx2_8(b, a);
				break;
			case 12:
				cvti8_avx2_64(b, a);
				a += 64;
				b += 64;
			case 4:
				cvti8_avx2_32(b, a);
				break;
			case 13:
				cvti8_avx2_64(b, a);
				a += 64;
				b += 64;
			case 5:
				cvti8_avx2_32(b, a);
				a += 32;
				b += 32;
				cvti8_avx2_8(b, a);
				break;
			case 14:
				cvti8_avx2_64(b, a);
				a += 64;
				b += 64;
			case 6:
				cvti8_avx2_32(b, a);
				a += 32;
				b += 32;
				cvti8_avx2_16(b, a);
				break;
			case 15:
				cvti8_avx2_64(b, a);
				a += 64;
				b += 64;
			case 7:
				cvti8_avx2_32(b, a);
				a += 32;
				b += 32;
				cvti8_avx2_16(b, a);
				a += 16;
				b += 16;
				cvti8_avx2_8(b, a);
				break;
			}
			cvti8_tiny(b, a, n & 7);
		}

		// Function template cvti8_avx2_medium

		template <class T>
		void cvti8_avx2_medium(T* b, const signed char* a, size_t n)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		void cvti8_avx2_medium<signed short>(signed short* b, const signed char* a, size_t n)
		{
			__m128i xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m256i ymm_b0, ymm_b1, ymm_b2, ymm_b3, ymm_b4, ymm_b5, ymm_b6, ymm_b7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 128; n -= 128)
			{
				xmm_a0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a));
				xmm_a1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 1);
				xmm_a2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 2);
				xmm_a3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 3);
				xmm_a4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 4);
				xmm_a5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 5);
				xmm_a6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 6);
				xmm_a7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 7);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 128), _MM_HINT_NTA);
				ymm_b0 = _mm256_cvtepi8_epi16(xmm_a0);
				ymm_b1 = _mm256_cvtepi8_epi16(xmm_a1);
				ymm_b2 = _mm256_cvtepi8_epi16(xmm_a2);
				ymm_b3 = _mm256_cvtepi8_epi16(xmm_a3);
				ymm_b4 = _mm256_cvtepi8_epi16(xmm_a4);
				ymm_b5 = _mm256_cvtepi8_epi16(xmm_a5);
				ymm_b6 = _mm256_cvtepi8_epi16(xmm_a6);
				ymm_b7 = _mm256_cvtepi8_epi16(xmm_a7);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(b), ymm_b0);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 1, ymm_b1);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 2, ymm_b2);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 3, ymm_b3);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 4, ymm_b4);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 5, ymm_b5);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 6, ymm_b6);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 7, ymm_b7);
				a += 128;
				b += 128;
			}
		}

		template <>
		void cvti8_avx2_medium<unsigned short>(unsigned short* b, const signed char* a, size_t n)
		{
			__m128i xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m256i ymm_b0, ymm_b1, ymm_b2, ymm_b3, ymm_b4, ymm_b5, ymm_b6, ymm_b7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 128; n -= 128)
			{
				xmm_a0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a));
				xmm_a1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 1);
				xmm_a2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 2);
				xmm_a3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 3);
				xmm_a4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 4);
				xmm_a5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 5);
				xmm_a6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 6);
				xmm_a7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 7);
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 128), _MM_HINT_NTA);
				ymm_b0 = _mm256_cvtepi8_epi16(xmm_a0);
				ymm_b1 = _mm256_cvtepi8_epi16(xmm_a1);
				ymm_b2 = _mm256_cvtepi8_epi16(xmm_a2);
				ymm_b3 = _mm256_cvtepi8_epi16(xmm_a3);
				ymm_b4 = _mm256_cvtepi8_epi16(xmm_a4);
				ymm_b5 = _mm256_cvtepi8_epi16(xmm_a5);
				ymm_b6 = _mm256_cvtepi8_epi16(xmm_a6);
				ymm_b7 = _mm256_cvtepi8_epi16(xmm_a7);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(b), ymm_b0);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 1, ymm_b1);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 2, ymm_b2);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 3, ymm_b3);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 4, ymm_b4);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 5, ymm_b5);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 6, ymm_b6);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 7, ymm_b7);
				a += 128;
				b += 128;
			}
		}

		template <>
		void cvti8_avx2_medium<signed int>(signed int* b, const signed char* a, size_t n)
		{
			__m128i xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m256i ymm_b0, ymm_b1, ymm_b2, ymm_b3, ymm_b4, ymm_b5, ymm_b6, ymm_b7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 64; n -= 64)
			{
				xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
				xmm_a1 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 8));
				xmm_a2 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 16));
				xmm_a3 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 24));
				xmm_a4 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 32));
				xmm_a5 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 40));
				xmm_a6 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 48));
				xmm_a7 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 56));
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 64), _MM_HINT_NTA);
				ymm_b0 = _mm256_cvtepi8_epi32(xmm_a0);
				ymm_b1 = _mm256_cvtepi8_epi32(xmm_a1);
				ymm_b2 = _mm256_cvtepi8_epi32(xmm_a2);
				ymm_b3 = _mm256_cvtepi8_epi32(xmm_a3);
				ymm_b4 = _mm256_cvtepi8_epi32(xmm_a4);
				ymm_b5 = _mm256_cvtepi8_epi32(xmm_a5);
				ymm_b6 = _mm256_cvtepi8_epi32(xmm_a6);
				ymm_b7 = _mm256_cvtepi8_epi32(xmm_a7);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(b), ymm_b0);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 1, ymm_b1);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 2, ymm_b2);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 3, ymm_b3);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 4, ymm_b4);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 5, ymm_b5);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 6, ymm_b6);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 7, ymm_b7);
				a += 64;
				b += 64;
			}
		}

		template <>
		void cvti8_avx2_medium<unsigned int>(unsigned int* b, const signed char* a, size_t n)
		{
			__m128i xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m256i ymm_b0, ymm_b1, ymm_b2, ymm_b3, ymm_b4, ymm_b5, ymm_b6, ymm_b7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 64; n -= 64)
			{
				xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
				xmm_a1 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 8));
				xmm_a2 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 16));
				xmm_a3 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 24));
				xmm_a4 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 32));
				xmm_a5 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 40));
				xmm_a6 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 48));
				xmm_a7 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 56));
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 64), _MM_HINT_NTA);
				ymm_b0 = _mm256_cvtepi8_epi32(xmm_a0);
				ymm_b1 = _mm256_cvtepi8_epi32(xmm_a1);
				ymm_b2 = _mm256_cvtepi8_epi32(xmm_a2);
				ymm_b3 = _mm256_cvtepi8_epi32(xmm_a3);
				ymm_b4 = _mm256_cvtepi8_epi32(xmm_a4);
				ymm_b5 = _mm256_cvtepi8_epi32(xmm_a5);
				ymm_b6 = _mm256_cvtepi8_epi32(xmm_a6);
				ymm_b7 = _mm256_cvtepi8_epi32(xmm_a7);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(b), ymm_b0);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 1, ymm_b1);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 2, ymm_b2);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 3, ymm_b3);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 4, ymm_b4);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 5, ymm_b5);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 6, ymm_b6);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(b) + 7, ymm_b7);
				a += 64;
				b += 64;
			}
		}

		template <>
		void cvti8_avx2_medium<float>(float* b, const signed char* a, size_t n)
		{
			__m128i xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m256i ymm_a0, ymm_a1, ymm_a2, ymm_a3, ymm_a4, ymm_a5, ymm_a6, ymm_a7;
			__m256 ymm_b0, ymm_b1, ymm_b2, ymm_b3, ymm_b4, ymm_b5, ymm_b6, ymm_b7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 64; n -= 64)
			{
				xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
				xmm_a1 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 8));
				xmm_a2 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 16));
				xmm_a3 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 24));
				xmm_a4 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 32));
				xmm_a5 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 40));
				xmm_a6 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 48));
				xmm_a7 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 56));
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 64), _MM_HINT_NTA);
				ymm_a0 = _mm256_cvtepi8_epi32(xmm_a0);
				ymm_a1 = _mm256_cvtepi8_epi32(xmm_a1);
				ymm_a2 = _mm256_cvtepi8_epi32(xmm_a2);
				ymm_a3 = _mm256_cvtepi8_epi32(xmm_a3);
				ymm_a4 = _mm256_cvtepi8_epi32(xmm_a4);
				ymm_a5 = _mm256_cvtepi8_epi32(xmm_a5);
				ymm_a6 = _mm256_cvtepi8_epi32(xmm_a6);
				ymm_a7 = _mm256_cvtepi8_epi32(xmm_a7);
				ymm_b0 = _mm256_cvtepi32_ps(ymm_a0);
				ymm_b1 = _mm256_cvtepi32_ps(ymm_a1);
				ymm_b2 = _mm256_cvtepi32_ps(ymm_a2);
				ymm_b3 = _mm256_cvtepi32_ps(ymm_a3);
				ymm_b4 = _mm256_cvtepi32_ps(ymm_a4);
				ymm_b5 = _mm256_cvtepi32_ps(ymm_a5);
				ymm_b6 = _mm256_cvtepi32_ps(ymm_a6);
				ymm_b7 = _mm256_cvtepi32_ps(ymm_a7);
				_mm256_storeu_ps(b, ymm_b0);
				_mm256_storeu_ps(b + 8, ymm_b1);
				_mm256_storeu_ps(b + 16, ymm_b2);
				_mm256_storeu_ps(b + 24, ymm_b3);
				_mm256_storeu_ps(b + 32, ymm_b4);
				_mm256_storeu_ps(b + 40, ymm_b5);
				_mm256_storeu_ps(b + 48, ymm_b6);
				_mm256_storeu_ps(b + 56, ymm_b7);
				a += 64;
				b += 64;
			}
		}

		template <>
		void cvti8_avx2_medium<double>(double* b, const signed char* a, size_t n)
		{
			__m128i xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m256i ymm_a0, ymm_a1, ymm_a2, ymm_a3, ymm_a4, ymm_a5, ymm_a6, ymm_a7;
			__m256d ymm_b0, ymm_b1, ymm_b2, ymm_b3, ymm_b4, ymm_b5, ymm_b6, ymm_b7;
			__m256d ymm_b8, ymm_b9, ymm_ba, ymm_bb, ymm_bc, ymm_bd, ymm_be, ymm_bf;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 64; n -= 64)
			{
				xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
				xmm_a1 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 8));
				xmm_a2 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 16));
				xmm_a3 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 24));
				xmm_a4 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 32));
				xmm_a5 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 40));
				xmm_a6 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 48));
				xmm_a7 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 56));
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 64), _MM_HINT_NTA);
				ymm_a0 = _mm256_cvtepi8_epi32(xmm_a0);
				ymm_a1 = _mm256_cvtepi8_epi32(xmm_a1);
				ymm_a2 = _mm256_cvtepi8_epi32(xmm_a2);
				ymm_a3 = _mm256_cvtepi8_epi32(xmm_a3);
				ymm_a4 = _mm256_cvtepi8_epi32(xmm_a4);
				ymm_a5 = _mm256_cvtepi8_epi32(xmm_a5);
				ymm_a6 = _mm256_cvtepi8_epi32(xmm_a6);
				ymm_a7 = _mm256_cvtepi8_epi32(xmm_a7);
				ymm_b0 = _mm256_cvtepi32_pd(_mm256_castsi256_si128(ymm_a0));
				ymm_b1 = _mm256_cvtepi32_pd(_mm256_extracti128_si256(ymm_a0, 1));
				ymm_b2 = _mm256_cvtepi32_pd(_mm256_castsi256_si128(ymm_a1));
				ymm_b3 = _mm256_cvtepi32_pd(_mm256_extracti128_si256(ymm_a1, 1));
				ymm_b4 = _mm256_cvtepi32_pd(_mm256_castsi256_si128(ymm_a2));
				ymm_b5 = _mm256_cvtepi32_pd(_mm256_extracti128_si256(ymm_a2, 1));
				ymm_b6 = _mm256_cvtepi32_pd(_mm256_castsi256_si128(ymm_a3));
				ymm_b7 = _mm256_cvtepi32_pd(_mm256_extracti128_si256(ymm_a3, 1));
				ymm_b8 = _mm256_cvtepi32_pd(_mm256_castsi256_si128(ymm_a4));
				ymm_b9 = _mm256_cvtepi32_pd(_mm256_extracti128_si256(ymm_a4, 1));
				ymm_ba = _mm256_cvtepi32_pd(_mm256_castsi256_si128(ymm_a5));
				ymm_bb = _mm256_cvtepi32_pd(_mm256_extracti128_si256(ymm_a5, 1));
				ymm_bc = _mm256_cvtepi32_pd(_mm256_castsi256_si128(ymm_a6));
				ymm_bd = _mm256_cvtepi32_pd(_mm256_extracti128_si256(ymm_a6, 1));
				ymm_be = _mm256_cvtepi32_pd(_mm256_castsi256_si128(ymm_a7));
				ymm_bf = _mm256_cvtepi32_pd(_mm256_extracti128_si256(ymm_a7, 1));
				_mm256_storeu_pd(b, ymm_b0);
				_mm256_storeu_pd(b + 4, ymm_b1);
				_mm256_storeu_pd(b + 8, ymm_b2);
				_mm256_storeu_pd(b + 12, ymm_b3);
				_mm256_storeu_pd(b + 16, ymm_b4);
				_mm256_storeu_pd(b + 20, ymm_b5);
				_mm256_storeu_pd(b + 24, ymm_b6);
				_mm256_storeu_pd(b + 28, ymm_b7);
				_mm256_storeu_pd(b + 32, ymm_b8);
				_mm256_storeu_pd(b + 36, ymm_b9);
				_mm256_storeu_pd(b + 40, ymm_ba);
				_mm256_storeu_pd(b + 44, ymm_bb);
				_mm256_storeu_pd(b + 48, ymm_bc);
				_mm256_storeu_pd(b + 52, ymm_bd);
				_mm256_storeu_pd(b + 56, ymm_be);
				_mm256_storeu_pd(b + 60, ymm_bf);
				a += 64;
				b += 64;
			}
		}

		// Function template cvti8_avx2_large

		template <class T>
		void cvti8_avx2_large(T* b, const signed char* a, size_t n)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		void cvti8_avx2_large<signed short>(signed short* b, const signed char* a, size_t n)
		{
			const size_t padding = 16 - (reinterpret_cast<size_t>(b) & 15);
			__m128i xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m256i ymm_b0, ymm_b1, ymm_b2, ymm_b3, ymm_b4, ymm_b5, ymm_b6, ymm_b7;

			// Align the destination to a 32-byte boundary.
			xmm_a0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a));
			ymm_b0 = _mm256_cvtepi8_epi16(xmm_a0);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b), ymm_b0);
			b += padding;
			a += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			// If the source is aligned on a 16-byte boundary.
			if ((reinterpret_cast<size_t>(a) & 15) == 0)
			{
				for (; n >= 128; n -= 128)
				{
					xmm_a0 = _mm_load_si128(reinterpret_cast<const __m128i*>(a));
					xmm_a1 = _mm_load_si128(reinterpret_cast<const __m128i*>(a) + 1);
					xmm_a2 = _mm_load_si128(reinterpret_cast<const __m128i*>(a) + 2);
					xmm_a3 = _mm_load_si128(reinterpret_cast<const __m128i*>(a) + 3);
					xmm_a4 = _mm_load_si128(reinterpret_cast<const __m128i*>(a) + 4);
					xmm_a5 = _mm_load_si128(reinterpret_cast<const __m128i*>(a) + 5);
					xmm_a6 = _mm_load_si128(reinterpret_cast<const __m128i*>(a) + 6);
					xmm_a7 = _mm_load_si128(reinterpret_cast<const __m128i*>(a) + 7);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(a + 128), _MM_HINT_NTA);
					ymm_b0 = _mm256_cvtepi8_epi16(xmm_a0);
					ymm_b1 = _mm256_cvtepi8_epi16(xmm_a1);
					ymm_b2 = _mm256_cvtepi8_epi16(xmm_a2);
					ymm_b3 = _mm256_cvtepi8_epi16(xmm_a3);
					ymm_b4 = _mm256_cvtepi8_epi16(xmm_a4);
					ymm_b5 = _mm256_cvtepi8_epi16(xmm_a5);
					ymm_b6 = _mm256_cvtepi8_epi16(xmm_a6);
					ymm_b7 = _mm256_cvtepi8_epi16(xmm_a7);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(b), ymm_b0);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 1, ymm_b1);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 2, ymm_b2);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 3, ymm_b3);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 4, ymm_b4);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 5, ymm_b5);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 6, ymm_b6);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 7, ymm_b7);
					a += 128;
					b += 128;
				}
			}
			else
			{
				for (; n >= 128; n -= 128)
				{
					xmm_a0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a));
					xmm_a1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 1);
					xmm_a2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 2);
					xmm_a3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 3);
					xmm_a4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 4);
					xmm_a5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 5);
					xmm_a6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 6);
					xmm_a7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 7);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(a + 128), _MM_HINT_NTA);
					ymm_b0 = _mm256_cvtepi8_epi16(xmm_a0);
					ymm_b1 = _mm256_cvtepi8_epi16(xmm_a1);
					ymm_b2 = _mm256_cvtepi8_epi16(xmm_a2);
					ymm_b3 = _mm256_cvtepi8_epi16(xmm_a3);
					ymm_b4 = _mm256_cvtepi8_epi16(xmm_a4);
					ymm_b5 = _mm256_cvtepi8_epi16(xmm_a5);
					ymm_b6 = _mm256_cvtepi8_epi16(xmm_a6);
					ymm_b7 = _mm256_cvtepi8_epi16(xmm_a7);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(b), ymm_b0);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 1, ymm_b1);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 2, ymm_b2);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 3, ymm_b3);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 4, ymm_b4);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 5, ymm_b5);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 6, ymm_b6);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 7, ymm_b7);
					a += 128;
					b += 128;
				}
			}
		}

		template <>
		void cvti8_avx2_large<unsigned short>(unsigned short* b, const signed char* a, size_t n)
		{
			const size_t padding = 16 - (reinterpret_cast<size_t>(b) & 15);
			__m128i xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m256i ymm_b0, ymm_b1, ymm_b2, ymm_b3, ymm_b4, ymm_b5, ymm_b6, ymm_b7;

			// Align the destination to a 32-byte boundary.
			xmm_a0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a));
			ymm_b0 = _mm256_cvtepi8_epi16(xmm_a0);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b), ymm_b0);
			b += padding;
			a += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			// If the source is aligned on a 16-byte boundary.
			if ((reinterpret_cast<size_t>(a) & 15) == 0)
			{
				for (; n >= 128; n -= 128)
				{
					xmm_a0 = _mm_load_si128(reinterpret_cast<const __m128i*>(a));
					xmm_a1 = _mm_load_si128(reinterpret_cast<const __m128i*>(a) + 1);
					xmm_a2 = _mm_load_si128(reinterpret_cast<const __m128i*>(a) + 2);
					xmm_a3 = _mm_load_si128(reinterpret_cast<const __m128i*>(a) + 3);
					xmm_a4 = _mm_load_si128(reinterpret_cast<const __m128i*>(a) + 4);
					xmm_a5 = _mm_load_si128(reinterpret_cast<const __m128i*>(a) + 5);
					xmm_a6 = _mm_load_si128(reinterpret_cast<const __m128i*>(a) + 6);
					xmm_a7 = _mm_load_si128(reinterpret_cast<const __m128i*>(a) + 7);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(a + 128), _MM_HINT_NTA);
					ymm_b0 = _mm256_cvtepi8_epi16(xmm_a0);
					ymm_b1 = _mm256_cvtepi8_epi16(xmm_a1);
					ymm_b2 = _mm256_cvtepi8_epi16(xmm_a2);
					ymm_b3 = _mm256_cvtepi8_epi16(xmm_a3);
					ymm_b4 = _mm256_cvtepi8_epi16(xmm_a4);
					ymm_b5 = _mm256_cvtepi8_epi16(xmm_a5);
					ymm_b6 = _mm256_cvtepi8_epi16(xmm_a6);
					ymm_b7 = _mm256_cvtepi8_epi16(xmm_a7);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(b), ymm_b0);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 1, ymm_b1);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 2, ymm_b2);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 3, ymm_b3);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 4, ymm_b4);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 5, ymm_b5);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 6, ymm_b6);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 7, ymm_b7);
					a += 128;
					b += 128;
				}
			}
			else
			{
				for (; n >= 128; n -= 128)
				{
					xmm_a0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a));
					xmm_a1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 1);
					xmm_a2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 2);
					xmm_a3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 3);
					xmm_a4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 4);
					xmm_a5 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 5);
					xmm_a6 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 6);
					xmm_a7 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a) + 7);
					// Fetch the line of data from memory.
					_mm_prefetch(reinterpret_cast<const char*>(a + 128), _MM_HINT_NTA);
					ymm_b0 = _mm256_cvtepi8_epi16(xmm_a0);
					ymm_b1 = _mm256_cvtepi8_epi16(xmm_a1);
					ymm_b2 = _mm256_cvtepi8_epi16(xmm_a2);
					ymm_b3 = _mm256_cvtepi8_epi16(xmm_a3);
					ymm_b4 = _mm256_cvtepi8_epi16(xmm_a4);
					ymm_b5 = _mm256_cvtepi8_epi16(xmm_a5);
					ymm_b6 = _mm256_cvtepi8_epi16(xmm_a6);
					ymm_b7 = _mm256_cvtepi8_epi16(xmm_a7);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(b), ymm_b0);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 1, ymm_b1);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 2, ymm_b2);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 3, ymm_b3);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 4, ymm_b4);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 5, ymm_b5);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 6, ymm_b6);
					_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 7, ymm_b7);
					a += 128;
					b += 128;
				}
			}
		}

		template <>
		void cvti8_avx2_large<signed int>(signed int* b, const signed char* a, size_t n)
		{
			const size_t padding = 8 - (reinterpret_cast<size_t>(b) & 7);
			__m128i xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m256i ymm_b0, ymm_b1, ymm_b2, ymm_b3, ymm_b4, ymm_b5, ymm_b6, ymm_b7;

			// Align the destination to a 32-byte boundary.
			xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
			ymm_b0 = _mm256_cvtepi8_epi32(xmm_a0);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b), ymm_b0);
			b += padding;
			a += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 64; n -= 64)
			{
				xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
				xmm_a1 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 8));
				xmm_a2 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 16));
				xmm_a3 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 24));
				xmm_a4 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 32));
				xmm_a5 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 40));
				xmm_a6 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 48));
				xmm_a7 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 56));
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 64), _MM_HINT_NTA);
				ymm_b0 = _mm256_cvtepi8_epi32(xmm_a0);
				ymm_b1 = _mm256_cvtepi8_epi32(xmm_a1);
				ymm_b2 = _mm256_cvtepi8_epi32(xmm_a2);
				ymm_b3 = _mm256_cvtepi8_epi32(xmm_a3);
				ymm_b4 = _mm256_cvtepi8_epi32(xmm_a4);
				ymm_b5 = _mm256_cvtepi8_epi32(xmm_a5);
				ymm_b6 = _mm256_cvtepi8_epi32(xmm_a6);
				ymm_b7 = _mm256_cvtepi8_epi32(xmm_a7);
				_mm256_stream_si256(reinterpret_cast<__m256i*>(b), ymm_b0);
				_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 1, ymm_b1);
				_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 2, ymm_b2);
				_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 3, ymm_b3);
				_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 4, ymm_b4);
				_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 5, ymm_b5);
				_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 6, ymm_b6);
				_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 7, ymm_b7);
				a += 64;
				b += 64;
			}
		}

		template <>
		void cvti8_avx2_large<unsigned int>(unsigned int* b, const signed char* a, size_t n)
		{
			const size_t padding = 8 - (reinterpret_cast<size_t>(b) & 7);
			__m128i xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m256i ymm_b0, ymm_b1, ymm_b2, ymm_b3, ymm_b4, ymm_b5, ymm_b6, ymm_b7;

			// Align the destination to a 32-byte boundary.
			xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
			ymm_b0 = _mm256_cvtepi8_epi32(xmm_a0);
			_mm256_storeu_si256(reinterpret_cast<__m256i*>(b), ymm_b0);
			b += padding;
			a += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 64; n -= 64)
			{
				xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
				xmm_a1 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 8));
				xmm_a2 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 16));
				xmm_a3 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 24));
				xmm_a4 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 32));
				xmm_a5 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 40));
				xmm_a6 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 48));
				xmm_a7 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 56));
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 64), _MM_HINT_NTA);
				ymm_b0 = _mm256_cvtepi8_epi32(xmm_a0);
				ymm_b1 = _mm256_cvtepi8_epi32(xmm_a1);
				ymm_b2 = _mm256_cvtepi8_epi32(xmm_a2);
				ymm_b3 = _mm256_cvtepi8_epi32(xmm_a3);
				ymm_b4 = _mm256_cvtepi8_epi32(xmm_a4);
				ymm_b5 = _mm256_cvtepi8_epi32(xmm_a5);
				ymm_b6 = _mm256_cvtepi8_epi32(xmm_a6);
				ymm_b7 = _mm256_cvtepi8_epi32(xmm_a7);
				_mm256_stream_si256(reinterpret_cast<__m256i*>(b), ymm_b0);
				_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 1, ymm_b1);
				_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 2, ymm_b2);
				_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 3, ymm_b3);
				_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 4, ymm_b4);
				_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 5, ymm_b5);
				_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 6, ymm_b6);
				_mm256_stream_si256(reinterpret_cast<__m256i*>(b) + 7, ymm_b7);
				a += 64;
				b += 64;
			}
		}

		template <>
		void cvti8_avx2_large<float>(float* b, const signed char* a, size_t n)
		{
			const size_t padding = 8 - (reinterpret_cast<size_t>(b) & 7);
			__m128i xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m256i ymm_a0, ymm_a1, ymm_a2, ymm_a3, ymm_a4, ymm_a5, ymm_a6, ymm_a7;
			__m256 ymm_b0, ymm_b1, ymm_b2, ymm_b3, ymm_b4, ymm_b5, ymm_b6, ymm_b7;

			// Align the destination to a 32-byte boundary.
			xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
			ymm_a0 = _mm256_cvtepi8_epi32(xmm_a0);
			ymm_b0 = _mm256_cvtepi32_ps(ymm_a0);
			_mm256_storeu_ps(b, ymm_b0);
			b += padding;
			a += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 64; n -= 64)
			{
				xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
				xmm_a1 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 8));
				xmm_a2 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 16));
				xmm_a3 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 24));
				xmm_a4 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 32));
				xmm_a5 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 40));
				xmm_a6 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 48));
				xmm_a7 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 56));
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 64), _MM_HINT_NTA);
				ymm_a0 = _mm256_cvtepi8_epi32(xmm_a0);
				ymm_a1 = _mm256_cvtepi8_epi32(xmm_a1);
				ymm_a2 = _mm256_cvtepi8_epi32(xmm_a2);
				ymm_a3 = _mm256_cvtepi8_epi32(xmm_a3);
				ymm_a4 = _mm256_cvtepi8_epi32(xmm_a4);
				ymm_a5 = _mm256_cvtepi8_epi32(xmm_a5);
				ymm_a6 = _mm256_cvtepi8_epi32(xmm_a6);
				ymm_a7 = _mm256_cvtepi8_epi32(xmm_a7);
				ymm_b0 = _mm256_cvtepi32_ps(ymm_a0);
				ymm_b1 = _mm256_cvtepi32_ps(ymm_a1);
				ymm_b2 = _mm256_cvtepi32_ps(ymm_a2);
				ymm_b3 = _mm256_cvtepi32_ps(ymm_a3);
				ymm_b4 = _mm256_cvtepi32_ps(ymm_a4);
				ymm_b5 = _mm256_cvtepi32_ps(ymm_a5);
				ymm_b6 = _mm256_cvtepi32_ps(ymm_a6);
				ymm_b7 = _mm256_cvtepi32_ps(ymm_a7);
				_mm256_stream_ps(b, ymm_b0);
				_mm256_stream_ps(b + 8, ymm_b1);
				_mm256_stream_ps(b + 16, ymm_b2);
				_mm256_stream_ps(b + 24, ymm_b3);
				_mm256_stream_ps(b + 32, ymm_b4);
				_mm256_stream_ps(b + 40, ymm_b5);
				_mm256_stream_ps(b + 48, ymm_b6);
				_mm256_stream_ps(b + 56, ymm_b7);
				a += 64;
				b += 64;
			}
		}

		template <>
		void cvti8_avx2_large<double>(double* b, const signed char* a, size_t n)
		{
			const size_t padding = 4 - (reinterpret_cast<size_t>(b) & 3);
			__m128i xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m256i ymm_a0, ymm_a1, ymm_a2, ymm_a3, ymm_a4, ymm_a5, ymm_a6, ymm_a7;
			__m256d ymm_b0, ymm_b1, ymm_b2, ymm_b3, ymm_b4, ymm_b5, ymm_b6, ymm_b7;
			__m256d ymm_b8, ymm_b9, ymm_ba, ymm_bb, ymm_bc, ymm_bd, ymm_be, ymm_bf;

			// Align the destination to a 32-byte boundary.
			xmm_a0 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a));
			ymm_a0 = _mm256_cvtepi8_epi32(xmm_a0);
			ymm_b0 = _mm256_cvtepi32_pd(_mm256_castsi256_si128(ymm_a0));
			_mm256_storeu_pd(b, ymm_b0);
			b += padding;
			a += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 64; n -= 64)
			{
				xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
				xmm_a1 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 8));
				xmm_a2 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 16));
				xmm_a3 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 24));
				xmm_a4 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 32));
				xmm_a5 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 40));
				xmm_a6 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 48));
				xmm_a7 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 56));
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 64), _MM_HINT_NTA);
				ymm_a0 = _mm256_cvtepi8_epi32(xmm_a0);
				ymm_a1 = _mm256_cvtepi8_epi32(xmm_a1);
				ymm_a2 = _mm256_cvtepi8_epi32(xmm_a2);
				ymm_a3 = _mm256_cvtepi8_epi32(xmm_a3);
				ymm_a4 = _mm256_cvtepi8_epi32(xmm_a4);
				ymm_a5 = _mm256_cvtepi8_epi32(xmm_a5);
				ymm_a6 = _mm256_cvtepi8_epi32(xmm_a6);
				ymm_a7 = _mm256_cvtepi8_epi32(xmm_a7);
				ymm_b0 = _mm256_cvtepi32_pd(_mm256_castsi256_si128(ymm_a0));
				ymm_b1 = _mm256_cvtepi32_pd(_mm256_extracti128_si256(ymm_a0, 1));
				ymm_b2 = _mm256_cvtepi32_pd(_mm256_castsi256_si128(ymm_a1));
				ymm_b3 = _mm256_cvtepi32_pd(_mm256_extracti128_si256(ymm_a1, 1));
				ymm_b4 = _mm256_cvtepi32_pd(_mm256_castsi256_si128(ymm_a2));
				ymm_b5 = _mm256_cvtepi32_pd(_mm256_extracti128_si256(ymm_a2, 1));
				ymm_b6 = _mm256_cvtepi32_pd(_mm256_castsi256_si128(ymm_a3));
				ymm_b7 = _mm256_cvtepi32_pd(_mm256_extracti128_si256(ymm_a3, 1));
				ymm_b8 = _mm256_cvtepi32_pd(_mm256_castsi256_si128(ymm_a4));
				ymm_b9 = _mm256_cvtepi32_pd(_mm256_extracti128_si256(ymm_a4, 1));
				ymm_ba = _mm256_cvtepi32_pd(_mm256_castsi256_si128(ymm_a5));
				ymm_bb = _mm256_cvtepi32_pd(_mm256_extracti128_si256(ymm_a5, 1));
				ymm_bc = _mm256_cvtepi32_pd(_mm256_castsi256_si128(ymm_a6));
				ymm_bd = _mm256_cvtepi32_pd(_mm256_extracti128_si256(ymm_a6, 1));
				ymm_be = _mm256_cvtepi32_pd(_mm256_castsi256_si128(ymm_a7));
				ymm_bf = _mm256_cvtepi32_pd(_mm256_extracti128_si256(ymm_a7, 1));
				_mm256_stream_pd(b, ymm_b0);
				_mm256_stream_pd(b + 4, ymm_b1);
				_mm256_stream_pd(b + 8, ymm_b2);
				_mm256_stream_pd(b + 12, ymm_b3);
				_mm256_stream_pd(b + 16, ymm_b4);
				_mm256_stream_pd(b + 20, ymm_b5);
				_mm256_stream_pd(b + 24, ymm_b6);
				_mm256_stream_pd(b + 28, ymm_b7);
				_mm256_stream_pd(b + 32, ymm_b8);
				_mm256_stream_pd(b + 36, ymm_b9);
				_mm256_stream_pd(b + 40, ymm_ba);
				_mm256_stream_pd(b + 44, ymm_bb);
				_mm256_stream_pd(b + 48, ymm_bc);
				_mm256_stream_pd(b + 52, ymm_bd);
				_mm256_stream_pd(b + 56, ymm_be);
				_mm256_stream_pd(b + 60, ymm_bf);
				a += 64;
				b += 64;
			}
		}

		// Function template impl_cvti8

		template <class T>
		inline void impl_cvti8(T* b, const signed char* a, size_t n)
		{
			constexpr size_t threshold = simd::l2_cache_size / sizeof(signed char);
			// Small amount of data type conversion.
			if (n < 128)
				cvti8_avx2_small(b, a, n);
			// Medium amount data type conversion.
			else if (n < threshold)
			{
				cvti8_avx2_medium(b, a, n);
				cvti8_avx2_small(b, a, n);
			}
			// Large amount data type conversion.
			else
			{
				cvti8_avx2_large(b, a, n);
				cvti8_avx2_small(b, a, n);
			}
		}

	#elif defined(__AVX__) || defined(__SSE4_2__) || defined(__SSE4_1__)

		// Function template cvti8_sse41_8

		template <class T>
		inline void cvti8_sse41_8(T* b, const signed char* a)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		inline void cvti8_sse41_8<signed short>(signed short* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_b0 = _mm_cvtepi8_epi16(xmm_a0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
		}

		template <>
		inline void cvti8_sse41_8<unsigned short>(unsigned short* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_b0 = _mm_cvtepi8_epi16(xmm_a0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
		}

		template <>
		inline void cvti8_sse41_8<signed int>(signed int* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a1 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 4));
			__m128i xmm_b0 = _mm_cvtepi8_epi32(xmm_a0);
			__m128i xmm_b1 = _mm_cvtepi8_epi32(xmm_a1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b1);
		}

		template <>
		inline void cvti8_sse41_8<unsigned int>(unsigned int* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a1 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 4));
			__m128i xmm_b0 = _mm_cvtepi8_epi32(xmm_a0);
			__m128i xmm_b1 = _mm_cvtepi8_epi32(xmm_a1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b1);
		}

		template <>
		inline void cvti8_sse41_8<float>(float* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a1 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 4));
			xmm_a0 = _mm_cvtepi8_epi32(xmm_a0);
			xmm_a1 = _mm_cvtepi8_epi32(xmm_a1);
			__m128 xmm_b0 = _mm_cvtepi32_ps(xmm_a0);
			__m128 xmm_b1 = _mm_cvtepi32_ps(xmm_a1);
			_mm_storeu_ps(b, xmm_b0);
			_mm_storeu_ps(b + 4, xmm_b1);
		}

		template <>
		inline void cvti8_sse41_8<double>(double* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a2 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 4));
			xmm_a0 = _mm_cvtepi8_epi32(xmm_a0);
			xmm_a2 = _mm_cvtepi8_epi32(xmm_a2);
			__m128i xmm_a1 = _mm_shuffle_epi32(xmm_a0, _MM_SHUFFLE(1, 0, 3, 2));
			__m128i xmm_a3 = _mm_shuffle_epi32(xmm_a2, _MM_SHUFFLE(1, 0, 3, 2));
			__m128d xmm_b0 = _mm_cvtepi32_pd(xmm_a0);
			__m128d xmm_b1 = _mm_cvtepi32_pd(xmm_a1);
			__m128d xmm_b2 = _mm_cvtepi32_pd(xmm_a2);
			__m128d xmm_b3 = _mm_cvtepi32_pd(xmm_a3);
			_mm_storeu_pd(b, xmm_b0);
			_mm_storeu_pd(b + 2, xmm_b1);
			_mm_storeu_pd(b + 4, xmm_b2);
			_mm_storeu_pd(b + 6, xmm_b3);
		}

		// Function template cvti8_sse41_16

		template <class T>
		inline void cvti8_sse41_16(T* b, const signed char* a)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		inline void cvti8_sse41_16<signed short>(signed short* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a1 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 8));
			__m128i xmm_b0 = _mm_cvtepi8_epi16(xmm_a0);
			__m128i xmm_b1 = _mm_cvtepi8_epi16(xmm_a1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b1);
		}

		template <>
		inline void cvti8_sse41_16<unsigned short>(unsigned short* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a1 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 8));
			__m128i xmm_b0 = _mm_cvtepi8_epi16(xmm_a0);
			__m128i xmm_b1 = _mm_cvtepi8_epi16(xmm_a1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b1);
		}

		template <>
		inline void cvti8_sse41_16<signed int>(signed int* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a1 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 4));
			__m128i xmm_a2 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 8));
			__m128i xmm_a3 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 12));
			__m128i xmm_b0 = _mm_cvtepi8_epi32(xmm_a0);
			__m128i xmm_b1 = _mm_cvtepi8_epi32(xmm_a1);
			__m128i xmm_b2 = _mm_cvtepi8_epi32(xmm_a2);
			__m128i xmm_b3 = _mm_cvtepi8_epi32(xmm_a3);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 2, xmm_b2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 3, xmm_b3);
		}

		template <>
		inline void cvti8_sse41_16<unsigned int>(unsigned int* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a1 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 4));
			__m128i xmm_a2 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 8));
			__m128i xmm_a3 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 12));
			__m128i xmm_b0 = _mm_cvtepi8_epi32(xmm_a0);
			__m128i xmm_b1 = _mm_cvtepi8_epi32(xmm_a1);
			__m128i xmm_b2 = _mm_cvtepi8_epi32(xmm_a2);
			__m128i xmm_b3 = _mm_cvtepi8_epi32(xmm_a3);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 2, xmm_b2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 3, xmm_b3);
		}

		template <>
		inline void cvti8_sse41_16<float>(float* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a1 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 4));
			__m128i xmm_a2 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 8));
			__m128i xmm_a3 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 12));
			xmm_a0 = _mm_cvtepi8_epi32(xmm_a0);
			xmm_a1 = _mm_cvtepi8_epi32(xmm_a1);
			xmm_a2 = _mm_cvtepi8_epi32(xmm_a2);
			xmm_a3 = _mm_cvtepi8_epi32(xmm_a3);
			__m128 xmm_b0 = _mm_cvtepi32_ps(xmm_a0);
			__m128 xmm_b1 = _mm_cvtepi32_ps(xmm_a1);
			__m128 xmm_b2 = _mm_cvtepi32_ps(xmm_a2);
			__m128 xmm_b3 = _mm_cvtepi32_ps(xmm_a3);
			_mm_storeu_ps(b, xmm_b0);
			_mm_storeu_ps(b + 4, xmm_b1);
			_mm_storeu_ps(b + 8, xmm_b2);
			_mm_storeu_ps(b + 12, xmm_b3);
		}

		template <>
		inline void cvti8_sse41_16<double>(double* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a2 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 4));
			__m128i xmm_a4 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 8));
			__m128i xmm_a6 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 12));
			xmm_a0 = _mm_cvtepi8_epi32(xmm_a0);
			xmm_a2 = _mm_cvtepi8_epi32(xmm_a2);
			xmm_a4 = _mm_cvtepi8_epi32(xmm_a4);
			xmm_a6 = _mm_cvtepi8_epi32(xmm_a6);
			__m128i xmm_a1 = _mm_shuffle_epi32(xmm_a0, _MM_SHUFFLE(1, 0, 3, 2));
			__m128i xmm_a3 = _mm_shuffle_epi32(xmm_a2, _MM_SHUFFLE(1, 0, 3, 2));
			__m128i xmm_a5 = _mm_shuffle_epi32(xmm_a4, _MM_SHUFFLE(1, 0, 3, 2));
			__m128i xmm_a7 = _mm_shuffle_epi32(xmm_a6, _MM_SHUFFLE(1, 0, 3, 2));
			__m128d xmm_b0 = _mm_cvtepi32_pd(xmm_a0);
			__m128d xmm_b1 = _mm_cvtepi32_pd(xmm_a1);
			__m128d xmm_b2 = _mm_cvtepi32_pd(xmm_a2);
			__m128d xmm_b3 = _mm_cvtepi32_pd(xmm_a3);
			__m128d xmm_b4 = _mm_cvtepi32_pd(xmm_a4);
			__m128d xmm_b5 = _mm_cvtepi32_pd(xmm_a5);
			__m128d xmm_b6 = _mm_cvtepi32_pd(xmm_a6);
			__m128d xmm_b7 = _mm_cvtepi32_pd(xmm_a7);
			_mm_storeu_pd(b, xmm_b0);
			_mm_storeu_pd(b + 2, xmm_b1);
			_mm_storeu_pd(b + 4, xmm_b2);
			_mm_storeu_pd(b + 6, xmm_b3);
			_mm_storeu_pd(b + 8, xmm_b4);
			_mm_storeu_pd(b + 10, xmm_b5);
			_mm_storeu_pd(b + 12, xmm_b6);
			_mm_storeu_pd(b + 14, xmm_b7);
		}

		// Function template cvti8_sse41_32

		template <class T>
		inline void cvti8_sse41_32(T* b, const signed char* a)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		inline void cvti8_sse41_32<signed short>(signed short* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a1 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 8));
			__m128i xmm_a2 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 16));
			__m128i xmm_a3 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 24));
			__m128i xmm_b0 = _mm_cvtepi8_epi16(xmm_a0);
			__m128i xmm_b1 = _mm_cvtepi8_epi16(xmm_a1);
			__m128i xmm_b2 = _mm_cvtepi8_epi16(xmm_a2);
			__m128i xmm_b3 = _mm_cvtepi8_epi16(xmm_a3);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 2, xmm_b2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 3, xmm_b3);
		}

		template <>
		inline void cvti8_sse41_32<unsigned short>(unsigned short* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a1 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 8));
			__m128i xmm_a2 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 16));
			__m128i xmm_a3 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 24));
			__m128i xmm_b0 = _mm_cvtepi8_epi16(xmm_a0);
			__m128i xmm_b1 = _mm_cvtepi8_epi16(xmm_a1);
			__m128i xmm_b2 = _mm_cvtepi8_epi16(xmm_a2);
			__m128i xmm_b3 = _mm_cvtepi8_epi16(xmm_a3);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 2, xmm_b2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 3, xmm_b3);
		}

		template <>
		inline void cvti8_sse41_32<signed int>(signed int* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a1 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 4));
			__m128i xmm_a2 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 8));
			__m128i xmm_a3 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 12));
			__m128i xmm_a4 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 16));
			__m128i xmm_a5 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 20));
			__m128i xmm_a6 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 24));
			__m128i xmm_a7 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 28));
			__m128i xmm_b0 = _mm_cvtepi8_epi32(xmm_a0);
			__m128i xmm_b1 = _mm_cvtepi8_epi32(xmm_a1);
			__m128i xmm_b2 = _mm_cvtepi8_epi32(xmm_a2);
			__m128i xmm_b3 = _mm_cvtepi8_epi32(xmm_a3);
			__m128i xmm_b4 = _mm_cvtepi8_epi32(xmm_a4);
			__m128i xmm_b5 = _mm_cvtepi8_epi32(xmm_a5);
			__m128i xmm_b6 = _mm_cvtepi8_epi32(xmm_a6);
			__m128i xmm_b7 = _mm_cvtepi8_epi32(xmm_a7);
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
		inline void cvti8_sse41_32<unsigned int>(unsigned int* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a1 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 4));
			__m128i xmm_a2 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 8));
			__m128i xmm_a3 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 12));
			__m128i xmm_a4 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 16));
			__m128i xmm_a5 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 20));
			__m128i xmm_a6 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 24));
			__m128i xmm_a7 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 28));
			__m128i xmm_b0 = _mm_cvtepi8_epi32(xmm_a0);
			__m128i xmm_b1 = _mm_cvtepi8_epi32(xmm_a1);
			__m128i xmm_b2 = _mm_cvtepi8_epi32(xmm_a2);
			__m128i xmm_b3 = _mm_cvtepi8_epi32(xmm_a3);
			__m128i xmm_b4 = _mm_cvtepi8_epi32(xmm_a4);
			__m128i xmm_b5 = _mm_cvtepi8_epi32(xmm_a5);
			__m128i xmm_b6 = _mm_cvtepi8_epi32(xmm_a6);
			__m128i xmm_b7 = _mm_cvtepi8_epi32(xmm_a7);
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
		inline void cvti8_sse41_32<float>(float* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a1 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 4));
			__m128i xmm_a2 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 8));
			__m128i xmm_a3 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 12));
			__m128i xmm_a4 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 16));
			__m128i xmm_a5 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 20));
			__m128i xmm_a6 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 24));
			__m128i xmm_a7 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 28));
			xmm_a0 = _mm_cvtepi8_epi32(xmm_a0);
			xmm_a1 = _mm_cvtepi8_epi32(xmm_a1);
			xmm_a2 = _mm_cvtepi8_epi32(xmm_a2);
			xmm_a3 = _mm_cvtepi8_epi32(xmm_a3);
			xmm_a4 = _mm_cvtepi8_epi32(xmm_a4);
			xmm_a5 = _mm_cvtepi8_epi32(xmm_a5);
			xmm_a6 = _mm_cvtepi8_epi32(xmm_a6);
			xmm_a7 = _mm_cvtepi8_epi32(xmm_a7);
			__m128 xmm_b0 = _mm_cvtepi32_ps(xmm_a0);
			__m128 xmm_b1 = _mm_cvtepi32_ps(xmm_a1);
			__m128 xmm_b2 = _mm_cvtepi32_ps(xmm_a2);
			__m128 xmm_b3 = _mm_cvtepi32_ps(xmm_a3);
			__m128 xmm_b4 = _mm_cvtepi32_ps(xmm_a4);
			__m128 xmm_b5 = _mm_cvtepi32_ps(xmm_a5);
			__m128 xmm_b6 = _mm_cvtepi32_ps(xmm_a6);
			__m128 xmm_b7 = _mm_cvtepi32_ps(xmm_a7);
			_mm_storeu_ps(b, xmm_b0);
			_mm_storeu_ps(b + 4, xmm_b1);
			_mm_storeu_ps(b + 8, xmm_b2);
			_mm_storeu_ps(b + 12, xmm_b3);
			_mm_storeu_ps(b + 16, xmm_b4);
			_mm_storeu_ps(b + 20, xmm_b5);
			_mm_storeu_ps(b + 24, xmm_b6);
			_mm_storeu_ps(b + 28, xmm_b7);
		}

		template <>
		inline void cvti8_sse41_32<double>(double* b, const signed char* a)
		{
			__m128i xmm_a0 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a));
			__m128i xmm_a2 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 4));
			__m128i xmm_a4 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 8));
			__m128i xmm_a6 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 12));
			__m128i xmm_a8 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 16));
			__m128i xmm_aa = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 20));
			__m128i xmm_ac = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 24));
			__m128i xmm_ae = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 28));
			xmm_a0 = _mm_cvtepi8_epi32(xmm_a0);
			xmm_a2 = _mm_cvtepi8_epi32(xmm_a2);
			xmm_a4 = _mm_cvtepi8_epi32(xmm_a4);
			xmm_a6 = _mm_cvtepi8_epi32(xmm_a6);
			xmm_a8 = _mm_cvtepi8_epi32(xmm_a8);
			xmm_aa = _mm_cvtepi8_epi32(xmm_aa);
			xmm_ac = _mm_cvtepi8_epi32(xmm_ac);
			xmm_ae = _mm_cvtepi8_epi32(xmm_ae);
			__m128i xmm_a1 = _mm_shuffle_epi32(xmm_a0, _MM_SHUFFLE(1, 0, 3, 2));
			__m128i xmm_a3 = _mm_shuffle_epi32(xmm_a2, _MM_SHUFFLE(1, 0, 3, 2));
			__m128i xmm_a5 = _mm_shuffle_epi32(xmm_a4, _MM_SHUFFLE(1, 0, 3, 2));
			__m128i xmm_a7 = _mm_shuffle_epi32(xmm_a6, _MM_SHUFFLE(1, 0, 3, 2));
			__m128i xmm_a9 = _mm_shuffle_epi32(xmm_a8, _MM_SHUFFLE(1, 0, 3, 2));
			__m128i xmm_ab = _mm_shuffle_epi32(xmm_aa, _MM_SHUFFLE(1, 0, 3, 2));
			__m128i xmm_ad = _mm_shuffle_epi32(xmm_ac, _MM_SHUFFLE(1, 0, 3, 2));
			__m128i xmm_af = _mm_shuffle_epi32(xmm_ae, _MM_SHUFFLE(1, 0, 3, 2));
			__m128d xmm_b0 = _mm_cvtepi32_pd(xmm_a0);
			__m128d xmm_b1 = _mm_cvtepi32_pd(xmm_a1);
			__m128d xmm_b2 = _mm_cvtepi32_pd(xmm_a2);
			__m128d xmm_b3 = _mm_cvtepi32_pd(xmm_a3);
			__m128d xmm_b4 = _mm_cvtepi32_pd(xmm_a4);
			__m128d xmm_b5 = _mm_cvtepi32_pd(xmm_a5);
			__m128d xmm_b6 = _mm_cvtepi32_pd(xmm_a6);
			__m128d xmm_b7 = _mm_cvtepi32_pd(xmm_a7);
			__m128d xmm_b8 = _mm_cvtepi32_pd(xmm_a8);
			__m128d xmm_b9 = _mm_cvtepi32_pd(xmm_a9);
			__m128d xmm_ba = _mm_cvtepi32_pd(xmm_aa);
			__m128d xmm_bb = _mm_cvtepi32_pd(xmm_ab);
			__m128d xmm_bc = _mm_cvtepi32_pd(xmm_ac);
			__m128d xmm_bd = _mm_cvtepi32_pd(xmm_ad);
			__m128d xmm_be = _mm_cvtepi32_pd(xmm_ae);
			__m128d xmm_bf = _mm_cvtepi32_pd(xmm_af);
			_mm_storeu_pd(b, xmm_b0);
			_mm_storeu_pd(b + 2, xmm_b1);
			_mm_storeu_pd(b + 4, xmm_b2);
			_mm_storeu_pd(b + 6, xmm_b3);
			_mm_storeu_pd(b + 8, xmm_b4);
			_mm_storeu_pd(b + 10, xmm_b5);
			_mm_storeu_pd(b + 12, xmm_b6);
			_mm_storeu_pd(b + 14, xmm_b7);
			_mm_storeu_pd(b + 16, xmm_b8);
			_mm_storeu_pd(b + 18, xmm_b9);
			_mm_storeu_pd(b + 20, xmm_ba);
			_mm_storeu_pd(b + 22, xmm_bb);
			_mm_storeu_pd(b + 24, xmm_bc);
			_mm_storeu_pd(b + 26, xmm_bd);
			_mm_storeu_pd(b + 28, xmm_be);
			_mm_storeu_pd(b + 30, xmm_bf);
		}

		// Function template cvti8_sse41_small

		template <class T>
		inline void cvti8_sse41_small(T* b, const signed char* a, size_t n)
		{
			switch (n >> 3)
			{
			case 4:
				cvti8_sse41_32(b, a);
			case 0:
				break;
			case 5:
				cvti8_sse41_32(b, a);
				a += 32;
				b += 32;
			case 1:
				cvti8_sse41_8(b, a);
				break;
			case 6:
				cvti8_sse41_32(b, a);
				a += 32;
				b += 32;
			case 2:
				cvti8_sse41_16(b, a);
				break;
			case 7:
				cvti8_sse41_32(b, a);
				a += 32;
				b += 32;
			case 3:
				cvti8_sse41_16(b, a);
				a += 16;
				b += 16;
				cvti8_sse41_8(b, a);
				break;
			}
			cvti8_tiny(b, a, n & 7);
		}

		// Function template cvti8_sse41_medium

		template <class T>
		void cvti8_sse41_medium(T* b, const signed char* a, size_t n)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		void cvti8_sse41_medium<signed short>(signed short* b, const signed char* a, size_t n)
		{
			__m128i xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m128i xmm_b0, xmm_b1, xmm_b2, xmm_b3, xmm_b4, xmm_b5, xmm_b6, xmm_b7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 64; n -= 64)
			{
				xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
				xmm_a1 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 8));
				xmm_a2 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 16));
				xmm_a3 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 24));
				xmm_a4 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 32));
				xmm_a5 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 40));
				xmm_a6 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 48));
				xmm_a7 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 56));
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 64), _MM_HINT_NTA);
				xmm_b0 = _mm_cvtepi8_epi16(xmm_a0);
				xmm_b1 = _mm_cvtepi8_epi16(xmm_a1);
				xmm_b2 = _mm_cvtepi8_epi16(xmm_a2);
				xmm_b3 = _mm_cvtepi8_epi16(xmm_a3);
				xmm_b4 = _mm_cvtepi8_epi16(xmm_a4);
				xmm_b5 = _mm_cvtepi8_epi16(xmm_a5);
				xmm_b6 = _mm_cvtepi8_epi16(xmm_a6);
				xmm_b7 = _mm_cvtepi8_epi16(xmm_a7);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b1);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 2, xmm_b2);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 3, xmm_b3);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 4, xmm_b4);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 5, xmm_b5);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 6, xmm_b6);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 7, xmm_b7);
				a += 64;
				b += 64;
			}
		}

		template <>
		void cvti8_sse41_medium<unsigned short>(unsigned short* b, const signed char* a, size_t n)
		{
			__m128i xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m128i xmm_b0, xmm_b1, xmm_b2, xmm_b3, xmm_b4, xmm_b5, xmm_b6, xmm_b7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 64; n -= 64)
			{
				xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
				xmm_a1 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 8));
				xmm_a2 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 16));
				xmm_a3 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 24));
				xmm_a4 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 32));
				xmm_a5 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 40));
				xmm_a6 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 48));
				xmm_a7 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 56));
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 64), _MM_HINT_NTA);
				xmm_b0 = _mm_cvtepi8_epi16(xmm_a0);
				xmm_b1 = _mm_cvtepi8_epi16(xmm_a1);
				xmm_b2 = _mm_cvtepi8_epi16(xmm_a2);
				xmm_b3 = _mm_cvtepi8_epi16(xmm_a3);
				xmm_b4 = _mm_cvtepi8_epi16(xmm_a4);
				xmm_b5 = _mm_cvtepi8_epi16(xmm_a5);
				xmm_b6 = _mm_cvtepi8_epi16(xmm_a6);
				xmm_b7 = _mm_cvtepi8_epi16(xmm_a7);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b1);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 2, xmm_b2);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 3, xmm_b3);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 4, xmm_b4);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 5, xmm_b5);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 6, xmm_b6);
				_mm_storeu_si128(reinterpret_cast<__m128i*>(b) + 7, xmm_b7);
				a += 64;
				b += 64;
			}
		}

		template <>
		void cvti8_sse41_medium<signed int>(signed int* b, const signed char* a, size_t n)
		{
			__m128i xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m128i xmm_b0, xmm_b1, xmm_b2, xmm_b3, xmm_b4, xmm_b5, xmm_b6, xmm_b7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				xmm_a0 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a));
				xmm_a1 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 4));
				xmm_a2 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 8));
				xmm_a3 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 12));
				xmm_a4 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 16));
				xmm_a5 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 20));
				xmm_a6 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 24));
				xmm_a7 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 28));
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
				xmm_b0 = _mm_cvtepi8_epi32(xmm_a0);
				xmm_b1 = _mm_cvtepi8_epi32(xmm_a1);
				xmm_b2 = _mm_cvtepi8_epi32(xmm_a2);
				xmm_b3 = _mm_cvtepi8_epi32(xmm_a3);
				xmm_b4 = _mm_cvtepi8_epi32(xmm_a4);
				xmm_b5 = _mm_cvtepi8_epi32(xmm_a5);
				xmm_b6 = _mm_cvtepi8_epi32(xmm_a6);
				xmm_b7 = _mm_cvtepi8_epi32(xmm_a7);
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
		void cvti8_sse41_medium<unsigned int>(unsigned int* b, const signed char* a, size_t n)
		{
			__m128i xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m128i xmm_b0, xmm_b1, xmm_b2, xmm_b3, xmm_b4, xmm_b5, xmm_b6, xmm_b7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				xmm_a0 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a));
				xmm_a1 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 4));
				xmm_a2 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 8));
				xmm_a3 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 12));
				xmm_a4 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 16));
				xmm_a5 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 20));
				xmm_a6 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 24));
				xmm_a7 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 28));
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
				xmm_b0 = _mm_cvtepi8_epi32(xmm_a0);
				xmm_b1 = _mm_cvtepi8_epi32(xmm_a1);
				xmm_b2 = _mm_cvtepi8_epi32(xmm_a2);
				xmm_b3 = _mm_cvtepi8_epi32(xmm_a3);
				xmm_b4 = _mm_cvtepi8_epi32(xmm_a4);
				xmm_b5 = _mm_cvtepi8_epi32(xmm_a5);
				xmm_b6 = _mm_cvtepi8_epi32(xmm_a6);
				xmm_b7 = _mm_cvtepi8_epi32(xmm_a7);
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
		void cvti8_sse41_medium<float>(float* b, const signed char* a, size_t n)
		{
			__m128i xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m128 xmm_b0, xmm_b1, xmm_b2, xmm_b3, xmm_b4, xmm_b5, xmm_b6, xmm_b7;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				xmm_a0 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a));
				xmm_a1 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 4));
				xmm_a2 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 8));
				xmm_a3 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 12));
				xmm_a4 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 16));
				xmm_a5 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 20));
				xmm_a6 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 24));
				xmm_a7 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 28));
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
				xmm_a0 = _mm_cvtepi8_epi32(xmm_a0);
				xmm_a1 = _mm_cvtepi8_epi32(xmm_a1);
				xmm_a2 = _mm_cvtepi8_epi32(xmm_a2);
				xmm_a3 = _mm_cvtepi8_epi32(xmm_a3);
				xmm_a4 = _mm_cvtepi8_epi32(xmm_a4);
				xmm_a5 = _mm_cvtepi8_epi32(xmm_a5);
				xmm_a6 = _mm_cvtepi8_epi32(xmm_a6);
				xmm_a7 = _mm_cvtepi8_epi32(xmm_a7);
				xmm_b0 = _mm_cvtepi32_ps(xmm_a0);
				xmm_b1 = _mm_cvtepi32_ps(xmm_a1);
				xmm_b2 = _mm_cvtepi32_ps(xmm_a2);
				xmm_b3 = _mm_cvtepi32_ps(xmm_a3);
				xmm_b4 = _mm_cvtepi32_ps(xmm_a4);
				xmm_b5 = _mm_cvtepi32_ps(xmm_a5);
				xmm_b6 = _mm_cvtepi32_ps(xmm_a6);
				xmm_b7 = _mm_cvtepi32_ps(xmm_a7);
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

		template <>
		void cvti8_sse41_medium<double>(double* b, const signed char* a, size_t n)
		{
			__m128i xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m128i xmm_a8, xmm_a9, xmm_aa, xmm_ab, xmm_ac, xmm_ad, xmm_ae, xmm_af;
			__m128d xmm_b0, xmm_b1, xmm_b2, xmm_b3, xmm_b4, xmm_b5, xmm_b6, xmm_b7;
			__m128d xmm_b8, xmm_b9, xmm_ba, xmm_bb, xmm_bc, xmm_bd, xmm_be, xmm_bf;

			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				xmm_a0 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a));
				xmm_a2 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 4));
				xmm_a4 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 8));
				xmm_a6 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 12));
				xmm_a8 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 16));
				xmm_aa = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 20));
				xmm_ac = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 24));
				xmm_ae = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 28));
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
				xmm_a0 = _mm_cvtepi8_epi32(xmm_a0);
				xmm_a2 = _mm_cvtepi8_epi32(xmm_a2);
				xmm_a4 = _mm_cvtepi8_epi32(xmm_a4);
				xmm_a6 = _mm_cvtepi8_epi32(xmm_a6);
				xmm_a8 = _mm_cvtepi8_epi32(xmm_a8);
				xmm_aa = _mm_cvtepi8_epi32(xmm_aa);
				xmm_ac = _mm_cvtepi8_epi32(xmm_ac);
				xmm_ae = _mm_cvtepi8_epi32(xmm_ae);
				xmm_a1 = _mm_shuffle_epi32(xmm_a0, _MM_SHUFFLE(1, 0, 3, 2));
				xmm_a3 = _mm_shuffle_epi32(xmm_a2, _MM_SHUFFLE(1, 0, 3, 2));
				xmm_a5 = _mm_shuffle_epi32(xmm_a4, _MM_SHUFFLE(1, 0, 3, 2));
				xmm_a7 = _mm_shuffle_epi32(xmm_a6, _MM_SHUFFLE(1, 0, 3, 2));
				xmm_a9 = _mm_shuffle_epi32(xmm_a8, _MM_SHUFFLE(1, 0, 3, 2));
				xmm_ab = _mm_shuffle_epi32(xmm_aa, _MM_SHUFFLE(1, 0, 3, 2));
				xmm_ad = _mm_shuffle_epi32(xmm_ac, _MM_SHUFFLE(1, 0, 3, 2));
				xmm_af = _mm_shuffle_epi32(xmm_ae, _MM_SHUFFLE(1, 0, 3, 2));
				xmm_b0 = _mm_cvtepi32_pd(xmm_a0);
				xmm_b1 = _mm_cvtepi32_pd(xmm_a1);
				xmm_b2 = _mm_cvtepi32_pd(xmm_a2);
				xmm_b3 = _mm_cvtepi32_pd(xmm_a3);
				xmm_b4 = _mm_cvtepi32_pd(xmm_a4);
				xmm_b5 = _mm_cvtepi32_pd(xmm_a5);
				xmm_b6 = _mm_cvtepi32_pd(xmm_a6);
				xmm_b7 = _mm_cvtepi32_pd(xmm_a7);
				xmm_b8 = _mm_cvtepi32_pd(xmm_a8);
				xmm_b9 = _mm_cvtepi32_pd(xmm_a9);
				xmm_ba = _mm_cvtepi32_pd(xmm_aa);
				xmm_bb = _mm_cvtepi32_pd(xmm_ab);
				xmm_bc = _mm_cvtepi32_pd(xmm_ac);
				xmm_bd = _mm_cvtepi32_pd(xmm_ad);
				xmm_be = _mm_cvtepi32_pd(xmm_ae);
				xmm_bf = _mm_cvtepi32_pd(xmm_af);
				_mm_storeu_pd(b, xmm_b0);
				_mm_storeu_pd(b + 2, xmm_b1);
				_mm_storeu_pd(b + 4, xmm_b2);
				_mm_storeu_pd(b + 6, xmm_b3);
				_mm_storeu_pd(b + 8, xmm_b4);
				_mm_storeu_pd(b + 10, xmm_b5);
				_mm_storeu_pd(b + 12, xmm_b6);
				_mm_storeu_pd(b + 14, xmm_b7);
				_mm_storeu_pd(b + 16, xmm_b8);
				_mm_storeu_pd(b + 18, xmm_b9);
				_mm_storeu_pd(b + 20, xmm_ba);
				_mm_storeu_pd(b + 22, xmm_bb);
				_mm_storeu_pd(b + 24, xmm_bc);
				_mm_storeu_pd(b + 26, xmm_bd);
				_mm_storeu_pd(b + 28, xmm_be);
				_mm_storeu_pd(b + 30, xmm_bf);
				a += 32;
				b += 32;
			}
		}

		// Function template cvti8_sse41_large

		template <class T>
		void cvti8_sse41_large(T* b, const signed char* a, size_t n)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		template <>
		void cvti8_sse41_large<signed short>(signed short* b, const signed char* a, size_t n)
		{
			const size_t padding = 8 - (reinterpret_cast<size_t>(b) & 7);
			__m128i xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m128i xmm_b0, xmm_b1, xmm_b2, xmm_b3, xmm_b4, xmm_b5, xmm_b6, xmm_b7;

			// Align the destination to a 16-byte boundary.
			xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
			xmm_b0 = _mm_cvtepi8_epi16(xmm_a0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			b += padding;
			a += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 64; n -= 64)
			{
				xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
				xmm_a1 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 8));
				xmm_a2 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 16));
				xmm_a3 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 24));
				xmm_a4 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 32));
				xmm_a5 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 40));
				xmm_a6 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 48));
				xmm_a7 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 56));
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 64), _MM_HINT_NTA);
				xmm_b0 = _mm_cvtepi8_epi16(xmm_a0);
				xmm_b1 = _mm_cvtepi8_epi16(xmm_a1);
				xmm_b2 = _mm_cvtepi8_epi16(xmm_a2);
				xmm_b3 = _mm_cvtepi8_epi16(xmm_a3);
				xmm_b4 = _mm_cvtepi8_epi16(xmm_a4);
				xmm_b5 = _mm_cvtepi8_epi16(xmm_a5);
				xmm_b6 = _mm_cvtepi8_epi16(xmm_a6);
				xmm_b7 = _mm_cvtepi8_epi16(xmm_a7);
				_mm_stream_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
				_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b1);
				_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 2, xmm_b2);
				_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 3, xmm_b3);
				_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 4, xmm_b4);
				_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 5, xmm_b5);
				_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 6, xmm_b6);
				_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 7, xmm_b7);
				a += 64;
				b += 64;
			}
		}

		template <>
		void cvti8_sse41_large<unsigned short>(unsigned short* b, const signed char* a, size_t n)
		{
			const size_t padding = 8 - (reinterpret_cast<size_t>(b) & 7);
			__m128i xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m128i xmm_b0, xmm_b1, xmm_b2, xmm_b3, xmm_b4, xmm_b5, xmm_b6, xmm_b7;

			// Align the destination to a 16-byte boundary.
			xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
			xmm_b0 = _mm_cvtepi8_epi16(xmm_a0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			b += padding;
			a += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 64; n -= 64)
			{
				xmm_a0 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a));
				xmm_a1 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 8));
				xmm_a2 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 16));
				xmm_a3 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 24));
				xmm_a4 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 32));
				xmm_a5 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 40));
				xmm_a6 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 48));
				xmm_a7 = _mm_loadu_si64(reinterpret_cast<const __m128i*>(a + 56));
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 64), _MM_HINT_NTA);
				xmm_b0 = _mm_cvtepi8_epi16(xmm_a0);
				xmm_b1 = _mm_cvtepi8_epi16(xmm_a1);
				xmm_b2 = _mm_cvtepi8_epi16(xmm_a2);
				xmm_b3 = _mm_cvtepi8_epi16(xmm_a3);
				xmm_b4 = _mm_cvtepi8_epi16(xmm_a4);
				xmm_b5 = _mm_cvtepi8_epi16(xmm_a5);
				xmm_b6 = _mm_cvtepi8_epi16(xmm_a6);
				xmm_b7 = _mm_cvtepi8_epi16(xmm_a7);
				_mm_stream_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
				_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 1, xmm_b1);
				_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 2, xmm_b2);
				_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 3, xmm_b3);
				_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 4, xmm_b4);
				_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 5, xmm_b5);
				_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 6, xmm_b6);
				_mm_stream_si128(reinterpret_cast<__m128i*>(b) + 7, xmm_b7);
				a += 64;
				b += 64;
			}
		}

		template <>
		void cvti8_sse41_large<signed int>(signed int* b, const signed char* a, size_t n)
		{
			const size_t padding = 4 - (reinterpret_cast<size_t>(b) & 3);
			__m128i xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m128i xmm_b0, xmm_b1, xmm_b2, xmm_b3, xmm_b4, xmm_b5, xmm_b6, xmm_b7;

			// Align the destination to a 16-byte boundary.
			xmm_a0 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a));
			xmm_b0 = _mm_cvtepi8_epi32(xmm_a0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			b += padding;
			a += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				xmm_a0 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a));
				xmm_a1 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 8));
				xmm_a2 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 16));
				xmm_a3 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 24));
				xmm_a4 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 32));
				xmm_a5 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 40));
				xmm_a6 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 48));
				xmm_a7 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 56));
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
				xmm_b0 = _mm_cvtepi8_epi32(xmm_a0);
				xmm_b1 = _mm_cvtepi8_epi32(xmm_a1);
				xmm_b2 = _mm_cvtepi8_epi32(xmm_a2);
				xmm_b3 = _mm_cvtepi8_epi32(xmm_a3);
				xmm_b4 = _mm_cvtepi8_epi32(xmm_a4);
				xmm_b5 = _mm_cvtepi8_epi32(xmm_a5);
				xmm_b6 = _mm_cvtepi8_epi32(xmm_a6);
				xmm_b7 = _mm_cvtepi8_epi32(xmm_a7);
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

		template <>
		void cvti8_sse41_large<unsigned int>(unsigned int* b, const signed char* a, size_t n)
		{
			const size_t padding = 4 - (reinterpret_cast<size_t>(b) & 3);
			__m128i xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m128i xmm_b0, xmm_b1, xmm_b2, xmm_b3, xmm_b4, xmm_b5, xmm_b6, xmm_b7;

			// Align the destination to a 16-byte boundary.
			xmm_a0 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a));
			xmm_b0 = _mm_cvtepi8_epi32(xmm_a0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(b), xmm_b0);
			b += padding;
			a += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				xmm_a0 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a));
				xmm_a1 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 8));
				xmm_a2 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 16));
				xmm_a3 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 24));
				xmm_a4 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 32));
				xmm_a5 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 40));
				xmm_a6 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 48));
				xmm_a7 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 56));
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
				xmm_b0 = _mm_cvtepi8_epi32(xmm_a0);
				xmm_b1 = _mm_cvtepi8_epi32(xmm_a1);
				xmm_b2 = _mm_cvtepi8_epi32(xmm_a2);
				xmm_b3 = _mm_cvtepi8_epi32(xmm_a3);
				xmm_b4 = _mm_cvtepi8_epi32(xmm_a4);
				xmm_b5 = _mm_cvtepi8_epi32(xmm_a5);
				xmm_b6 = _mm_cvtepi8_epi32(xmm_a6);
				xmm_b7 = _mm_cvtepi8_epi32(xmm_a7);
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

		template <>
		void cvti8_sse41_large<float>(float* b, const signed char* a, size_t n)
		{
			const size_t padding = 4 - (reinterpret_cast<size_t>(b) & 3);
			__m128i xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m128 xmm_b0, xmm_b1, xmm_b2, xmm_b3, xmm_b4, xmm_b5, xmm_b6, xmm_b7;

			// Align the destination to a 16-byte boundary.
			xmm_a0 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a));
			xmm_a0 = _mm_cvtepi8_epi32(xmm_a0);
			xmm_b0 = _mm_cvtepi32_ps(xmm_a0);
			_mm_storeu_ps(b, xmm_b0);
			b += padding;
			a += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				xmm_a0 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a));
				xmm_a1 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 8));
				xmm_a2 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 16));
				xmm_a3 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 24));
				xmm_a4 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 32));
				xmm_a5 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 40));
				xmm_a6 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 48));
				xmm_a7 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 56));
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
				xmm_a0 = _mm_cvtepi8_epi32(xmm_a0);
				xmm_a1 = _mm_cvtepi8_epi32(xmm_a1);
				xmm_a2 = _mm_cvtepi8_epi32(xmm_a2);
				xmm_a3 = _mm_cvtepi8_epi32(xmm_a3);
				xmm_a4 = _mm_cvtepi8_epi32(xmm_a4);
				xmm_a5 = _mm_cvtepi8_epi32(xmm_a5);
				xmm_a6 = _mm_cvtepi8_epi32(xmm_a6);
				xmm_a7 = _mm_cvtepi8_epi32(xmm_a7);
				xmm_b0 = _mm_cvtepi32_ps(xmm_a0);
				xmm_b1 = _mm_cvtepi32_ps(xmm_a1);
				xmm_b2 = _mm_cvtepi32_ps(xmm_a2);
				xmm_b3 = _mm_cvtepi32_ps(xmm_a3);
				xmm_b4 = _mm_cvtepi32_ps(xmm_a4);
				xmm_b5 = _mm_cvtepi32_ps(xmm_a5);
				xmm_b6 = _mm_cvtepi32_ps(xmm_a6);
				xmm_b7 = _mm_cvtepi32_ps(xmm_a7);
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

		template <>
		void cvti8_sse41_large<double>(double* b, const signed char* a, size_t n)
		{
			const size_t padding = 2 - (reinterpret_cast<size_t>(b) & 1);
			__m128i xmm_a0, xmm_a1, xmm_a2, xmm_a3, xmm_a4, xmm_a5, xmm_a6, xmm_a7;
			__m128i xmm_a8, xmm_a9, xmm_aa, xmm_ab, xmm_ac, xmm_ad, xmm_ae, xmm_af;
			__m128d xmm_b0, xmm_b1, xmm_b2, xmm_b3, xmm_b4, xmm_b5, xmm_b6, xmm_b7;
			__m128d xmm_b8, xmm_b9, xmm_ba, xmm_bb, xmm_bc, xmm_bd, xmm_be, xmm_bf;

			// Align the destination to a 16-byte boundary.
			xmm_a0 = _mm_loadu_si16(reinterpret_cast<const __m128i*>(a));
			xmm_a0 = _mm_cvtepi8_epi32(xmm_a0);
			xmm_b0 = _mm_cvtepi32_pd(xmm_a0);
			_mm_storeu_pd(b, xmm_b0);
			b += padding;
			a += padding;
			n -= padding;
			// Fetch the line of data from memory.
			_mm_prefetch(reinterpret_cast<const char*>(a), _MM_HINT_NTA);
			for (; n >= 32; n -= 32)
			{
				xmm_a0 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a));
				xmm_a2 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 8));
				xmm_a4 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 16));
				xmm_a6 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 24));
				xmm_a8 = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 32));
				xmm_aa = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 40));
				xmm_ac = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 48));
				xmm_ae = _mm_loadu_si32(reinterpret_cast<const __m128i*>(a + 56));
				// Fetch the line of data from memory.
				_mm_prefetch(reinterpret_cast<const char*>(a + 32), _MM_HINT_NTA);
				xmm_a0 = _mm_cvtepi8_epi32(xmm_a0);
				xmm_a2 = _mm_cvtepi8_epi32(xmm_a2);
				xmm_a4 = _mm_cvtepi8_epi32(xmm_a4);
				xmm_a6 = _mm_cvtepi8_epi32(xmm_a6);
				xmm_a8 = _mm_cvtepi8_epi32(xmm_a8);
				xmm_aa = _mm_cvtepi8_epi32(xmm_aa);
				xmm_ac = _mm_cvtepi8_epi32(xmm_ac);
				xmm_ae = _mm_cvtepi8_epi32(xmm_ae);
				xmm_a1 = _mm_shuffle_epi32(xmm_a0, _MM_SHUFFLE(1, 0, 3, 2));
				xmm_a3 = _mm_shuffle_epi32(xmm_a2, _MM_SHUFFLE(1, 0, 3, 2));
				xmm_a5 = _mm_shuffle_epi32(xmm_a4, _MM_SHUFFLE(1, 0, 3, 2));
				xmm_a7 = _mm_shuffle_epi32(xmm_a6, _MM_SHUFFLE(1, 0, 3, 2));
				xmm_a9 = _mm_shuffle_epi32(xmm_a8, _MM_SHUFFLE(1, 0, 3, 2));
				xmm_ab = _mm_shuffle_epi32(xmm_aa, _MM_SHUFFLE(1, 0, 3, 2));
				xmm_ad = _mm_shuffle_epi32(xmm_ac, _MM_SHUFFLE(1, 0, 3, 2));
				xmm_af = _mm_shuffle_epi32(xmm_ae, _MM_SHUFFLE(1, 0, 3, 2));
				xmm_b0 = _mm_cvtepi32_pd(xmm_a0);
				xmm_b1 = _mm_cvtepi32_pd(xmm_a1);
				xmm_b2 = _mm_cvtepi32_pd(xmm_a2);
				xmm_b3 = _mm_cvtepi32_pd(xmm_a3);
				xmm_b4 = _mm_cvtepi32_pd(xmm_a4);
				xmm_b5 = _mm_cvtepi32_pd(xmm_a5);
				xmm_b6 = _mm_cvtepi32_pd(xmm_a6);
				xmm_b7 = _mm_cvtepi32_pd(xmm_a7);
				xmm_b8 = _mm_cvtepi32_pd(xmm_a8);
				xmm_b9 = _mm_cvtepi32_pd(xmm_a9);
				xmm_ba = _mm_cvtepi32_pd(xmm_aa);
				xmm_bb = _mm_cvtepi32_pd(xmm_ab);
				xmm_bc = _mm_cvtepi32_pd(xmm_ac);
				xmm_bd = _mm_cvtepi32_pd(xmm_ad);
				xmm_be = _mm_cvtepi32_pd(xmm_ae);
				xmm_bf = _mm_cvtepi32_pd(xmm_af);
				_mm_stream_pd(b, xmm_b0);
				_mm_stream_pd(b + 2, xmm_b1);
				_mm_stream_pd(b + 4, xmm_b2);
				_mm_stream_pd(b + 6, xmm_b3);
				_mm_stream_pd(b + 8, xmm_b4);
				_mm_stream_pd(b + 10, xmm_b5);
				_mm_stream_pd(b + 12, xmm_b6);
				_mm_stream_pd(b + 14, xmm_b7);
				_mm_stream_pd(b + 16, xmm_b8);
				_mm_stream_pd(b + 18, xmm_b9);
				_mm_stream_pd(b + 20, xmm_ba);
				_mm_stream_pd(b + 22, xmm_bb);
				_mm_stream_pd(b + 24, xmm_bc);
				_mm_stream_pd(b + 26, xmm_bd);
				_mm_stream_pd(b + 28, xmm_be);
				_mm_stream_pd(b + 30, xmm_bf);
				a += 32;
				b += 32;
			}
		}

		// Function template impl_cvti8

		template <class T>
		inline void impl_cvti8(T* b, const signed char* a, size_t n)
		{
			constexpr size_t threshold = simd::l2_cache_size / sizeof(signed char);
			// Small amount of data type conversion.
			if (n < 64)
				cvti8_sse41_small(b, a, n);
			// Medium amount data type conversion.
			else if (n < threshold)
			{
				cvti8_sse41_medium(b, a, n);
				cvti8_sse41_small(b, a, n);
			}
			// Large amount data type conversion.
			else
			{
				cvti8_sse41_large(b, a, n);
				cvti8_sse41_small(b, a, n);
			}
		}

	#else

		// Function template impl_cvti8

		template <class T>
		void impl_cvti8(T* b, const signed char* a, size_t n)
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

	#endif

		template <>
		inline void impl_cvti8<signed char>(signed char* b, const signed char* a, size_t n)
		{
			std::memcpy(b, a, n);
		}

		template <>
		inline void impl_cvti8<unsigned char>(unsigned char* b, const signed char* a, size_t n)
		{
			std::memcpy(b, a, n);
		}

	} // namespace cpu

} // namespace core

#endif
