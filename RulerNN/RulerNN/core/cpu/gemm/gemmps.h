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

#ifndef __CORE_CPU_GEMMPS_H__
#define __CORE_CPU_GEMMPS_H__

#include "../simd.h"


namespace core
{
	namespace cpu
	{
		// Function template gemm_block_m
		template <class T> constexpr size_t gemm_block_m(void);

		// Function template gemm_block_p
		template <class T> constexpr size_t gemm_block_p(void);

		// Function template gemm_block_n
		template <class T> constexpr size_t gemm_block_n(void);

		// Function template add_dot_block
		template <class T> inline void add_dot_block(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t p);

		// Function template add_dot_4x4
		template <class T> inline void add_dot_4x4(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t p);

		// Function template add_dot_4x3
		template <class T> inline void add_dot_4x3(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t p);

		// Function template add_dot_4x2
		template <class T> inline void add_dot_4x2(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t p);

		// Function template add_dot_4x1
		template <class T> inline void add_dot_4x1(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t p);

		// Function template add_dot_3x4
		template <class T> inline void add_dot_3x4(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t p);

		// Function template add_dot_3x3
		template <class T> inline void add_dot_3x3(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t p);

		// Function template add_dot_3x2
		template <class T> inline void add_dot_3x2(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t p);

		// Function template add_dot_3x1
		template <class T> inline void add_dot_3x1(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t p);

		// Function template add_dot_2x4
		template <class T> inline void add_dot_2x4(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t p);

		// Function template add_dot_2x3
		template <class T> inline void add_dot_2x3(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t p);

		// Function template add_dot_2x2
		template <class T> inline void add_dot_2x2(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t p);

		// Function template add_dot_2x1
		template <class T> inline void add_dot_2x1(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t p);

		// Function template add_dot_1x4
		template <class T> inline void add_dot_1x4(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t p);

		// Function template add_dot_1x3
		template <class T> inline void add_dot_1x3(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t p);

		// Function template add_dot_1x2
		template <class T> inline void add_dot_1x2(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t p);

		// Function template add_dot_1x1
		template <class T> inline void add_dot_1x1(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t p);

	#if defined(__AVX2__) || defined(__AVX__)

		// Specialize for float

		template <>
		constexpr size_t gemm_block_m<float>(void)
		{
			return static_cast<size_t>(8);
		}

		template <>
		constexpr size_t gemm_block_p<float>(void)
		{
			return static_cast<size_t>(8);
		}

		template <>
		constexpr size_t gemm_block_n<float>(void)
		{
			return static_cast<size_t>(8);
		}

		// Function template add_dot_block

		template <>
		inline void add_dot_block<float>(float* c, size_t ldc, const float* a, size_t lda, const float* b, size_t ldb, size_t p)
		{
			const __m256 ymm_b0 = _mm256_loadu_ps(b);
			const __m256 ymm_b1 = _mm256_loadu_ps(b + ldb);
			const __m256 ymm_b2 = _mm256_loadu_ps(b + ldb * 2);
			const __m256 ymm_b3 = _mm256_loadu_ps(b + ldb * 3);
			const __m256 ymm_b4 = _mm256_loadu_ps(b + ldb * 4);
			const __m256 ymm_b5 = _mm256_loadu_ps(b + ldb * 5);
			const __m256 ymm_b6 = _mm256_loadu_ps(b + ldb * 6);
			const __m256 ymm_b7 = _mm256_loadu_ps(b + ldb * 7);

			for (size_t m = 0; m < 8; ++m)
			{
				// load data from memory
				__m256 ymm_a0 = _mm256_set1_ps(a[0]);
				__m256 ymm_a1 = _mm256_set1_ps(a[1]);
				__m256 ymm_a2 = _mm256_set1_ps(a[2]);
				__m256 ymm_a3 = _mm256_set1_ps(a[3]);
				__m256 ymm_a4 = _mm256_set1_ps(a[4]);
				__m256 ymm_a5 = _mm256_set1_ps(a[5]);
				__m256 ymm_a6 = _mm256_set1_ps(a[6]);
				__m256 ymm_a7 = _mm256_set1_ps(a[7]);
				__m256 ymm_c0 = _mm256_loadu_ps(c);
				// calculate inner product
				ymm_a0 = _mm256_mul_ps(ymm_a0, ymm_b0);
				ymm_a1 = _mm256_mul_ps(ymm_a1, ymm_b1);
				ymm_a2 = _mm256_mul_ps(ymm_a2, ymm_b2);
				ymm_a3 = _mm256_mul_ps(ymm_a3, ymm_b3);
				ymm_a4 = _mm256_mul_ps(ymm_a4, ymm_b4);
				ymm_a5 = _mm256_mul_ps(ymm_a5, ymm_b5);
				ymm_a6 = _mm256_mul_ps(ymm_a6, ymm_b6);
				ymm_a7 = _mm256_mul_ps(ymm_a7, ymm_b7);
				ymm_a0 = _mm256_add_ps(ymm_a0, ymm_a1);
				ymm_a2 = _mm256_add_ps(ymm_a2, ymm_a3);
				ymm_a4 = _mm256_add_ps(ymm_a4, ymm_a5);
				ymm_a6 = _mm256_add_ps(ymm_a6, ymm_a7);
				ymm_a0 = _mm256_add_ps(ymm_a0, ymm_a2);
				ymm_a4 = _mm256_add_ps(ymm_a4, ymm_a6);
				ymm_a0 = _mm256_add_ps(ymm_a0, ymm_a4);
				ymm_c0 = _mm256_add_ps(ymm_c0, ymm_a0);
				// store data into memory
				_mm256_storeu_ps(c, ymm_c0);
				a += lda;
				c += ldc;
			}
		}

		//template <>
		//inline void add_dot_block<float>(float* c, size_t ldc, const float* a, size_t lda, const float* b, size_t ldb, size_t p)
		//{
		//	const float* ptr_b0 = b;
		//	const float* ptr_b1 = b + ldb;
		//	const float* ptr_b2 = ptr_b1 + ldb;
		//	const float* ptr_b3 = ptr_b2 + ldb;
		//	const float* ptr_b4 = ptr_b3 + ldb;
		//	const float* ptr_b5 = ptr_b4 + ldb;
		//	const float* ptr_b6 = ptr_b5 + ldb;
		//	const float* ptr_b7 = ptr_b6 + ldb;
		//	__m256 ymm_c[8] = {
		//		_mm256_setzero_ps(),
		//		_mm256_setzero_ps(),
		//		_mm256_setzero_ps(),
		//		_mm256_setzero_ps(),
		//		_mm256_setzero_ps(),
		//		_mm256_setzero_ps(),
		//		_mm256_setzero_ps(),
		//		_mm256_setzero_ps()};

		//	for (size_t k = 0; k < p; k += 8)
		//	{
		//		const float* ptr_a = a + k;
		//		const __m256 ymm_b0 = _mm256_loadu_ps(ptr_b0);
		//		const __m256 ymm_b1 = _mm256_loadu_ps(ptr_b1);
		//		const __m256 ymm_b2 = _mm256_loadu_ps(ptr_b2);
		//		const __m256 ymm_b3 = _mm256_loadu_ps(ptr_b3);
		//		const __m256 ymm_b4 = _mm256_loadu_ps(ptr_b4);
		//		const __m256 ymm_b5 = _mm256_loadu_ps(ptr_b5);
		//		const __m256 ymm_b6 = _mm256_loadu_ps(ptr_b6);
		//		const __m256 ymm_b7 = _mm256_loadu_ps(ptr_b7);
		//		for (size_t m = 0; m < 8; ++m)
		//		{
		//			// load data from memory
		//			__m256 ymm_a0 = _mm256_set1_ps(ptr_a[0]);
		//			__m256 ymm_a1 = _mm256_set1_ps(ptr_a[1]);
		//			__m256 ymm_a2 = _mm256_set1_ps(ptr_a[2]);
		//			__m256 ymm_a3 = _mm256_set1_ps(ptr_a[3]);
		//			__m256 ymm_a4 = _mm256_set1_ps(ptr_a[4]);
		//			__m256 ymm_a5 = _mm256_set1_ps(ptr_a[5]);
		//			__m256 ymm_a6 = _mm256_set1_ps(ptr_a[6]);
		//			__m256 ymm_a7 = _mm256_set1_ps(ptr_a[7]);

		//			// Fetch the line of data from memory.
		//			_mm_prefetch(reinterpret_cast<const char*>(ptr_a + lda), _MM_HINT_NTA);

		//			// calculate inner product
		//			ymm_a0 = _mm256_mul_ps(ymm_a0, ymm_b0);
		//			ymm_a1 = _mm256_mul_ps(ymm_a1, ymm_b1);
		//			ymm_a2 = _mm256_mul_ps(ymm_a2, ymm_b2);
		//			ymm_a3 = _mm256_mul_ps(ymm_a3, ymm_b3);
		//			ymm_a4 = _mm256_mul_ps(ymm_a4, ymm_b4);
		//			ymm_a5 = _mm256_mul_ps(ymm_a5, ymm_b5);
		//			ymm_a6 = _mm256_mul_ps(ymm_a6, ymm_b6);
		//			ymm_a7 = _mm256_mul_ps(ymm_a7, ymm_b7);
		//			ymm_a0 = _mm256_add_ps(ymm_a0, ymm_a1);
		//			ymm_a2 = _mm256_add_ps(ymm_a2, ymm_a3);
		//			ymm_a4 = _mm256_add_ps(ymm_a4, ymm_a5);
		//			ymm_a6 = _mm256_add_ps(ymm_a6, ymm_a7);
		//			ymm_a0 = _mm256_add_ps(ymm_a0, ymm_a2);
		//			ymm_a4 = _mm256_add_ps(ymm_a4, ymm_a6);
		//			ymm_a0 = _mm256_add_ps(ymm_a0, ymm_a4);
		//			ymm_c[m] = _mm256_add_ps(ymm_c[m], ymm_a0);
		//			ptr_a += lda;
		//		}
		//		ptr_b0 += ldb;
		//		ptr_b1 += ldb;
		//		ptr_b2 += ldb;
		//		ptr_b3 += ldb;
		//		ptr_b4 += ldb;
		//		ptr_b5 += ldb;
		//		ptr_b6 += ldb;
		//		ptr_b7 += ldb;
		//	}
		//	// store data into memory
		//	ymm_c[0] = _mm256_add_ps(ymm_c[0], _mm256_loadu_ps(c)); _mm256_storeu_ps(c, ymm_c[0]); c += ldc;
		//	ymm_c[1] = _mm256_add_ps(ymm_c[1], _mm256_loadu_ps(c));	_mm256_storeu_ps(c, ymm_c[1]); c += ldc;
		//	ymm_c[2] = _mm256_add_ps(ymm_c[2], _mm256_loadu_ps(c)); _mm256_storeu_ps(c, ymm_c[2]); c += ldc;
		//	ymm_c[3] = _mm256_add_ps(ymm_c[3], _mm256_loadu_ps(c));	_mm256_storeu_ps(c, ymm_c[3]); c += ldc;
		//	ymm_c[4] = _mm256_add_ps(ymm_c[4], _mm256_loadu_ps(c)); _mm256_storeu_ps(c, ymm_c[4]); c += ldc;
		//	ymm_c[5] = _mm256_add_ps(ymm_c[5], _mm256_loadu_ps(c));	_mm256_storeu_ps(c, ymm_c[5]); c += ldc;
		//	ymm_c[6] = _mm256_add_ps(ymm_c[6], _mm256_loadu_ps(c)); _mm256_storeu_ps(c, ymm_c[6]); c += ldc;
		//	ymm_c[7] = _mm256_add_ps(ymm_c[7], _mm256_loadu_ps(c));	_mm256_storeu_ps(c, ymm_c[7]); c += ldc;
		//}

		//template <>
		//inline void add_dot_block<float>(float* c, size_t ldc, const float* a, size_t lda, const float* b, size_t ldb, size_t p)
		//{
		//	float* ptr_c = c;
		//	

		//	for (size_t m = 0; m < 8; ++m)
		//	{
		//		const float* ptr_a = a + m * lda;
		//		const float* ptr_b0 = b;
		//		const float* ptr_b1 = b + ldb;
		//		const float* ptr_b2 = ptr_b1 + ldb;
		//		const float* ptr_b3 = ptr_b2 + ldb;
		//		const float* ptr_b4 = ptr_b3 + ldb;
		//		const float* ptr_b5 = ptr_b4 + ldb;
		//		const float* ptr_b6 = ptr_b5 + ldb;
		//		const float* ptr_b7 = ptr_b6 + ldb;
		//		__m256 ymm_c = _mm256_setzero_ps();

		//		for (size_t k = 0; k < p; k += 8)
		//		{
		//			// load data from memory
		//			__m256 ymm_a0 = _mm256_set1_ps(ptr_a[0]);
		//			__m256 ymm_a1 = _mm256_set1_ps(ptr_a[1]);
		//			__m256 ymm_a2 = _mm256_set1_ps(ptr_a[2]);
		//			__m256 ymm_a3 = _mm256_set1_ps(ptr_a[3]);
		//			__m256 ymm_a4 = _mm256_set1_ps(ptr_a[4]);
		//			__m256 ymm_a5 = _mm256_set1_ps(ptr_a[5]);
		//			__m256 ymm_a6 = _mm256_set1_ps(ptr_a[6]);
		//			__m256 ymm_a7 = _mm256_set1_ps(ptr_a[7]);
		//			const __m256 ymm_b0 = _mm256_loadu_ps(ptr_b0);
		//			const __m256 ymm_b1 = _mm256_loadu_ps(ptr_b1);
		//			const __m256 ymm_b2 = _mm256_loadu_ps(ptr_b2);
		//			const __m256 ymm_b3 = _mm256_loadu_ps(ptr_b3);
		//			const __m256 ymm_b4 = _mm256_loadu_ps(ptr_b4);
		//			const __m256 ymm_b5 = _mm256_loadu_ps(ptr_b5);
		//			const __m256 ymm_b6 = _mm256_loadu_ps(ptr_b6);
		//			const __m256 ymm_b7 = _mm256_loadu_ps(ptr_b7);

		//			//// Fetch the line of data from memory.
		//			//_mm_prefetch(reinterpret_cast<const char*>(ptr_b0 + ldb), _MM_HINT_NTA);
		//			//_mm_prefetch(reinterpret_cast<const char*>(ptr_b1 + ldb), _MM_HINT_NTA);
		//			//_mm_prefetch(reinterpret_cast<const char*>(ptr_b2 + ldb), _MM_HINT_NTA);
		//			//_mm_prefetch(reinterpret_cast<const char*>(ptr_b3 + ldb), _MM_HINT_NTA);
		//			//_mm_prefetch(reinterpret_cast<const char*>(ptr_b4 + ldb), _MM_HINT_NTA);
		//			//_mm_prefetch(reinterpret_cast<const char*>(ptr_b5 + ldb), _MM_HINT_NTA);
		//			//_mm_prefetch(reinterpret_cast<const char*>(ptr_b6 + ldb), _MM_HINT_NTA);
		//			//_mm_prefetch(reinterpret_cast<const char*>(ptr_b7 + ldb), _MM_HINT_NTA);

		//			// calculate inner product
		//			ymm_a0 = _mm256_mul_ps(ymm_a0, ymm_b0);
		//			ymm_a1 = _mm256_mul_ps(ymm_a1, ymm_b1);
		//			ymm_a2 = _mm256_mul_ps(ymm_a2, ymm_b2);
		//			ymm_a3 = _mm256_mul_ps(ymm_a3, ymm_b3);
		//			ymm_a4 = _mm256_mul_ps(ymm_a4, ymm_b4);
		//			ymm_a5 = _mm256_mul_ps(ymm_a5, ymm_b5);
		//			ymm_a6 = _mm256_mul_ps(ymm_a6, ymm_b6);
		//			ymm_a7 = _mm256_mul_ps(ymm_a7, ymm_b7);
		//			ymm_a0 = _mm256_add_ps(ymm_a0, ymm_a1);
		//			ymm_a2 = _mm256_add_ps(ymm_a2, ymm_a3);
		//			ymm_a4 = _mm256_add_ps(ymm_a4, ymm_a5);
		//			ymm_a6 = _mm256_add_ps(ymm_a6, ymm_a7);
		//			ymm_a0 = _mm256_add_ps(ymm_a0, ymm_a2);
		//			ymm_a4 = _mm256_add_ps(ymm_a4, ymm_a6);
		//			ymm_a0 = _mm256_add_ps(ymm_a0, ymm_a4);
		//			ymm_c = _mm256_add_ps(ymm_c, ymm_a0);

		//			ptr_a += 8;
		//			ptr_b0 += ldb;
		//			ptr_b1 += ldb;
		//			ptr_b2 += ldb;
		//			ptr_b3 += ldb;
		//			ptr_b4 += ldb;
		//			ptr_b5 += ldb;
		//			ptr_b6 += ldb;
		//			ptr_b7 += ldb;
		//		}

		//		ymm_c = _mm256_add_ps(ymm_c, _mm256_loadu_ps(c));
		//		// store data into memory
		//		_mm256_storeu_ps(c, ymm_c);

		//		ptr_a += lda;
		//		ptr_c += ldc;
		//	}
		//}

	#endif

	} // namespace cpu

} // namespace core

#endif
