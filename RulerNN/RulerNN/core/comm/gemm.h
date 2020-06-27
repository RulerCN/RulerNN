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

#ifndef __CORE_COMM_GEMM_H__
#define __CORE_COMM_GEMM_H__

#include <stack>
#include <tuple>

// https://zhuanlan.zhihu.com/p/66958390

namespace core
{
	namespace comm
	{
		// Function template gemm_block_m

		template <class T>
		constexpr size_t gemm_block_m(void)
		{
			return static_cast<size_t>(4);
		}

		// Function template gemm_block_n

		template <class T>
		constexpr size_t gemm_block_n(void)
		{
			return static_cast<size_t>(4);
		}

		// Function template gemm_block_p

		template <class T>
		constexpr size_t gemm_block_p(void)
		{
			return static_cast<size_t>(4);
		}

		// Function template add_dot_block

		template <class T>
		inline void add_dot_block(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb)
		{
			T* ptr_c0 = c;
			T* ptr_c1 = ptr_c0 + ldc;
			T* ptr_c2 = ptr_c1 + ldc;
			T* ptr_c3 = ptr_c2 + ldc;
			const T* ptr_a0 = a;
			const T* ptr_a1 = ptr_a0 + lda;
			const T* ptr_a2 = ptr_a1 + lda;
			const T* ptr_a3 = ptr_a2 + lda;
			T c00 = 0, c01 = 0, c02 = 0, c03 = 0;
			T c10 = 0, c11 = 0, c12 = 0, c13 = 0;
			T c20 = 0, c21 = 0, c22 = 0, c23 = 0;
			T c30 = 0, c31 = 0, c32 = 0, c33 = 0;

			for (size_t k = 0; k < 4; ++k)
			{
				const T a0 = ptr_a0[k];
				const T a1 = ptr_a1[k];
				const T a2 = ptr_a2[k];
				const T a3 = ptr_a3[k];
				const T b0 = b[0];
				const T b1 = b[1];
				const T b2 = b[2];
				const T b3 = b[3];

				c00 += a0 * b0;
				c01 += a0 * b1;
				c02 += a0 * b2;
				c03 += a0 * b3;
				c10 += a1 * b0;
				c11 += a1 * b1;
				c12 += a1 * b2;
				c13 += a1 * b3;
				c20 += a2 * b0;
				c21 += a2 * b1;
				c22 += a2 * b2;
				c23 += a2 * b3;
				c30 += a3 * b0;
				c31 += a3 * b1;
				c32 += a3 * b2;
				c33 += a3 * b3;
				b += ldb;
			}
			ptr_c0[0] += c00;
			ptr_c0[1] += c01;
			ptr_c0[2] += c02;
			ptr_c0[3] += c03;
			ptr_c1[0] += c10;
			ptr_c1[1] += c11;
			ptr_c1[2] += c12;
			ptr_c1[3] += c13;
			ptr_c2[0] += c20;
			ptr_c2[1] += c21;
			ptr_c2[2] += c22;
			ptr_c2[3] += c23;
			ptr_c3[0] += c30;
			ptr_c3[1] += c31;
			ptr_c3[2] += c32;
			ptr_c3[3] += c33;
		}

		template <class T>
		inline void add_dot_4x4(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t p)
		{
			T* ptr_c0 = c;
			T* ptr_c1 = c + ldc;
			T* ptr_c2 = ptr_c1 + ldc;
			T* ptr_c3 = ptr_c2 + ldc;
			const T* ptr_a0 = a;
			const T* ptr_a1 = a + lda;
			const T* ptr_a2 = ptr_a1 + lda;
			const T* ptr_a3 = ptr_a2 + lda;
			T c00 = c01 = c02 = c03 = 0;
			T c10 = c11 = c12 = c13 = 0;
			T c20 = c21 = c22 = c23 = 0;
			T c30 = c31 = c32 = c33 = 0;

			for (size_t k = 0; k < p; ++k)
			{
				const T a0 = ptr_a0[k];
				const T a1 = ptr_a1[k];
				const T a2 = ptr_a2[k];
				const T a3 = ptr_a3[k];
				const T b0 = b[0];
				const T b1 = b[1];
				const T b2 = b[2];
				const T b3 = b[3];

				c00 += a0 * b0;
				c01 += a0 * b1;
				c02 += a0 * b2;
				c03 += a0 * b3;
				c10 += a1 * b0;
				c11 += a1 * b1;
				c12 += a1 * b2;
				c13 += a1 * b3;
				c20 += a2 * b0;
				c21 += a2 * b1;
				c22 += a2 * b2;
				c23 += a2 * b3;
				c30 += a3 * b0;
				c31 += a3 * b1;
				c32 += a3 * b2;
				c33 += a3 * b3;
				b += ldb;
			}
			ptr_c0[0] += c00;
			ptr_c0[1] += c01;
			ptr_c0[2] += c02;
			ptr_c0[3] += c03;
			ptr_c1[0] += c10;
			ptr_c1[1] += c11;
			ptr_c1[2] += c12;
			ptr_c1[3] += c13;
			ptr_c2[0] += c20;
			ptr_c2[1] += c21;
			ptr_c2[2] += c22;
			ptr_c2[3] += c23;
			ptr_c3[0] += c30;
			ptr_c3[1] += c31;
			ptr_c3[2] += c32;
			ptr_c3[3] += c33;
		}

		template <class T>
		inline void add_dot_4x3(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t p)
		{
			T* ptr_c0 = c;
			T* ptr_c1 = c + ldc;
			T* ptr_c2 = ptr_c1 + ldc;
			T* ptr_c3 = ptr_c2 + ldc;
			const T* ptr_a0 = a;
			const T* ptr_a1 = a + lda;
			const T* ptr_a2 = ptr_a1 + lda;
			const T* ptr_a3 = ptr_a2 + lda;
			T c00 = c01 = c02 = 0;
			T c10 = c11 = c12 = 0;
			T c20 = c21 = c22 = 0;
			T c30 = c31 = c32 = 0;

			for (size_t k = 0; k < p; ++k)
			{
				const T a0 = ptr_a0[k];
				const T a1 = ptr_a1[k];
				const T a2 = ptr_a2[k];
				const T a3 = ptr_a3[k];
				const T b0 = b[0];
				const T b1 = b[1];
				const T b2 = b[2];

				c00 += a0 * b0;
				c01 += a0 * b1;
				c02 += a0 * b2;
				c10 += a1 * b0;
				c11 += a1 * b1;
				c12 += a1 * b2;
				c20 += a2 * b0;
				c21 += a2 * b1;
				c22 += a2 * b2;
				c30 += a3 * b0;
				c31 += a3 * b1;
				c32 += a3 * b2;
				b += ldb;
			}
			ptr_c0[0] += c00;
			ptr_c0[1] += c01;
			ptr_c0[2] += c02;
			ptr_c1[0] += c10;
			ptr_c1[1] += c11;
			ptr_c1[2] += c12;
			ptr_c2[0] += c20;
			ptr_c2[1] += c21;
			ptr_c2[2] += c22;
			ptr_c3[0] += c30;
			ptr_c3[1] += c31;
			ptr_c3[2] += c32;
		}

		template <class T>
		inline void add_dot_4x2(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t p)
		{
			T* ptr_c0 = c;
			T* ptr_c1 = c + ldc;
			T* ptr_c2 = ptr_c1 + ldc;
			T* ptr_c3 = ptr_c2 + ldc;
			const T* ptr_a0 = a;
			const T* ptr_a1 = a + lda;
			const T* ptr_a2 = ptr_a1 + lda;
			const T* ptr_a3 = ptr_a2 + lda;
			T c00 = c01 = 0;
			T c10 = c11 = 0;
			T c20 = c21 = 0;
			T c30 = c31 = 0;

			for (size_t k = 0; k < p; ++k)
			{
				const T a0 = ptr_a0[k];
				const T a1 = ptr_a1[k];
				const T a2 = ptr_a2[k];
				const T a3 = ptr_a3[k];
				const T b0 = b[0];
				const T b1 = b[1];

				c00 += a0 * b0;
				c01 += a0 * b1;
				c10 += a1 * b0;
				c11 += a1 * b1;
				c20 += a2 * b0;
				c21 += a2 * b1;
				c30 += a3 * b0;
				c31 += a3 * b1;
				b += ldb;
			}
			ptr_c0[0] += c00;
			ptr_c0[1] += c01;
			ptr_c1[0] += c10;
			ptr_c1[1] += c11;
			ptr_c2[0] += c20;
			ptr_c2[1] += c21;
			ptr_c3[0] += c30;
			ptr_c3[1] += c31;
		}

		template <class T>
		inline void add_dot_4x1(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t p)
		{
			T* ptr_c0 = c;
			T* ptr_c1 = c + ldc;
			T* ptr_c2 = ptr_c1 + ldc;
			T* ptr_c3 = ptr_c2 + ldc;
			const T* ptr_a0 = a;
			const T* ptr_a1 = a + lda;
			const T* ptr_a2 = ptr_a1 + lda;
			const T* ptr_a3 = ptr_a2 + lda;
			T c00 = 0;
			T c10 = 0;
			T c20 = 0;
			T c30 = 0;

			for (size_t k = 0; k < p; ++k)
			{
				const T a0 = ptr_a0[k];
				const T a1 = ptr_a1[k];
				const T a2 = ptr_a2[k];
				const T a3 = ptr_a3[k];
				const T b0 = b[0];

				c00 += a0 * b0;
				c10 += a1 * b0;
				c20 += a2 * b0;
				c30 += a3 * b0;
				b += ldb;
			}
			ptr_c0[0] += c00;
			ptr_c1[0] += c10;
			ptr_c2[0] += c20;
			ptr_c3[0] += c30;
		}

		template <class T>
		inline void add_dot_3x4(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t p)
		{
			T* ptr_c0 = c;
			T* ptr_c1 = c + ldc;
			T* ptr_c2 = ptr_c1 + ldc;
			const T* ptr_a0 = a;
			const T* ptr_a1 = a + lda;
			const T* ptr_a2 = ptr_a1 + lda;
			T c00 = c01 = c02 = c03 = 0;
			T c10 = c11 = c12 = c13 = 0;
			T c20 = c21 = c22 = c23 = 0;

			for (size_t k = 0; k < p; ++k)
			{
				const T a0 = ptr_a0[k];
				const T a1 = ptr_a1[k];
				const T a2 = ptr_a2[k];
				const T b0 = b[0];
				const T b1 = b[1];
				const T b2 = b[2];
				const T b3 = b[3];

				c00 += a0 * b0;
				c01 += a0 * b1;
				c02 += a0 * b2;
				c03 += a0 * b3;
				c10 += a1 * b0;
				c11 += a1 * b1;
				c12 += a1 * b2;
				c13 += a1 * b3;
				c20 += a2 * b0;
				c21 += a2 * b1;
				c22 += a2 * b2;
				c23 += a2 * b3;
				b += ldb;
			}
			ptr_c0[0] += c00;
			ptr_c0[1] += c01;
			ptr_c0[2] += c02;
			ptr_c0[3] += c03;
			ptr_c1[0] += c10;
			ptr_c1[1] += c11;
			ptr_c1[2] += c12;
			ptr_c1[3] += c13;
			ptr_c2[0] += c20;
			ptr_c2[1] += c21;
			ptr_c2[2] += c22;
			ptr_c2[3] += c23;
		}

		template <class T>
		inline void add_dot_3x3(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t p)
		{
			T* ptr_c0 = c;
			T* ptr_c1 = c + ldc;
			T* ptr_c2 = ptr_c1 + ldc;
			const T* ptr_a0 = a;
			const T* ptr_a1 = a + lda;
			const T* ptr_a2 = ptr_a1 + lda;
			T c00 = c01 = c02 = 0;
			T c10 = c11 = c12 = 0;
			T c20 = c21 = c22 = 0;

			for (size_t k = 0; k < p; ++k)
			{
				const T a0 = ptr_a0[k];
				const T a1 = ptr_a1[k];
				const T a2 = ptr_a2[k];
				const T b0 = b[0];
				const T b1 = b[1];
				const T b2 = b[2];

				c00 += a0 * b0;
				c01 += a0 * b1;
				c02 += a0 * b2;
				c10 += a1 * b0;
				c11 += a1 * b1;
				c12 += a1 * b2;
				c20 += a2 * b0;
				c21 += a2 * b1;
				c22 += a2 * b2;
				b += ldb;
			}
			ptr_c0[0] += c00;
			ptr_c0[1] += c01;
			ptr_c0[2] += c02;
			ptr_c1[0] += c10;
			ptr_c1[1] += c11;
			ptr_c1[2] += c12;
			ptr_c2[0] += c20;
			ptr_c2[1] += c21;
			ptr_c2[2] += c22;
		}

		template <class T>
		inline void add_dot_3x2(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t p)
		{
			T* ptr_c0 = c;
			T* ptr_c1 = c + ldc;
			T* ptr_c2 = ptr_c1 + ldc;
			const T* ptr_a0 = a;
			const T* ptr_a1 = a + lda;
			const T* ptr_a2 = ptr_a1 + lda;
			T c00 = c01 = 0;
			T c10 = c11 = 0;
			T c20 = c21 = 0;

			for (size_t k = 0; k < p; ++k)
			{
				const T a0 = ptr_a0[k];
				const T a1 = ptr_a1[k];
				const T a2 = ptr_a2[k];
				const T b0 = b[0];
				const T b1 = b[1];

				c00 += a0 * b0;
				c01 += a0 * b1;
				c10 += a1 * b0;
				c11 += a1 * b1;
				c20 += a2 * b0;
				c21 += a2 * b1;
				b += ldb;
			}
			ptr_c0[0] += c00;
			ptr_c0[1] += c01;
			ptr_c1[0] += c10;
			ptr_c1[1] += c11;
			ptr_c2[0] += c20;
			ptr_c2[1] += c21;
		}

		template <class T>
		inline void add_dot_3x1(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t p)
		{
			T* ptr_c0 = c;
			T* ptr_c1 = c + ldc;
			T* ptr_c2 = ptr_c1 + ldc;
			const T* ptr_a0 = a;
			const T* ptr_a1 = a + lda;
			const T* ptr_a2 = ptr_a1 + lda;
			T c00 = 0;
			T c10 = 0;
			T c20 = 0;

			for (size_t k = 0; k < p; ++k)
			{
				const T a0 = ptr_a0[k];
				const T a1 = ptr_a1[k];
				const T a2 = ptr_a2[k];
				const T b0 = b[0];

				c00 += a0 * b0;
				c10 += a1 * b0;
				c20 += a2 * b0;
				b += ldb;
			}
			ptr_c0[0] += c00;
			ptr_c1[0] += c10;
			ptr_c2[0] += c20;
		}

		template <class T>
		inline void add_dot_2x4(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t p)
		{
			T* ptr_c0 = c;
			T* ptr_c1 = c + ldc;
			const T* ptr_a0 = a;
			const T* ptr_a1 = a + lda;
			T c00 = c01 = c02 = c03 = 0;
			T c10 = c11 = c12 = c13 = 0;

			for (size_t k = 0; k < p; ++k)
			{
				const T a0 = ptr_a0[k];
				const T a1 = ptr_a1[k];
				const T b0 = b[0];
				const T b1 = b[1];
				const T b2 = b[2];
				const T b3 = b[3];

				c00 += a0 * b0;
				c01 += a0 * b1;
				c02 += a0 * b2;
				c03 += a0 * b3;
				c10 += a1 * b0;
				c11 += a1 * b1;
				c12 += a1 * b2;
				c13 += a1 * b3;
				b += ldb;
			}
			ptr_c0[0] += c00;
			ptr_c0[1] += c01;
			ptr_c0[2] += c02;
			ptr_c0[3] += c03;
			ptr_c1[0] += c10;
			ptr_c1[1] += c11;
			ptr_c1[2] += c12;
			ptr_c1[3] += c13;
		}

		template <class T>
		inline void add_dot_2x3(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t p)
		{
			T* ptr_c0 = c;
			T* ptr_c1 = c + ldc;
			const T* ptr_a0 = a;
			const T* ptr_a1 = a + lda;
			T c00 = c01 = c02 = 0;
			T c10 = c11 = c12 = 0;

			for (size_t k = 0; k < p; ++k)
			{
				const T a0 = ptr_a0[k];
				const T a1 = ptr_a1[k];
				const T b0 = b[0];
				const T b1 = b[1];
				const T b2 = b[2];

				c00 += a0 * b0;
				c01 += a0 * b1;
				c02 += a0 * b2;
				c10 += a1 * b0;
				c11 += a1 * b1;
				c12 += a1 * b2;
				b += ldb;
			}
			ptr_c0[0] += c00;
			ptr_c0[1] += c01;
			ptr_c0[2] += c02;
			ptr_c1[0] += c10;
			ptr_c1[1] += c11;
			ptr_c1[2] += c12;
		}

		template <class T>
		inline void add_dot_2x2(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t p)
		{
			T* ptr_c0 = c;
			T* ptr_c1 = c + ldc;
			const T* ptr_a0 = a;
			const T* ptr_a1 = a + lda;
			T c00 = c01 = 0;
			T c10 = c11 = 0;

			for (size_t k = 0; k < p; ++k)
			{
				const T a0 = ptr_a0[k];
				const T a1 = ptr_a1[k];
				const T b0 = b[0];
				const T b1 = b[1];

				c00 += a0 * b0;
				c01 += a0 * b1;
				c10 += a1 * b0;
				c11 += a1 * b1;
				b += ldb;
			}
			ptr_c0[0] += c00;
			ptr_c0[1] += c01;
			ptr_c1[0] += c10;
			ptr_c1[1] += c11;
		}

		template <class T>
		inline void add_dot_2x1(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t p)
		{
			T* ptr_c0 = c;
			T* ptr_c1 = c + ldc;
			const T* ptr_a0 = a;
			const T* ptr_a1 = a + lda;
			T c00 = 0;
			T c10 = 0;

			for (size_t k = 0; k < p; ++k)
			{
				const T a0 = ptr_a0[k];
				const T a1 = ptr_a1[k];
				const T b0 = b[0];

				c00 += a0 * b0;
				c10 += a1 * b0;
				b += ldb;
			}
			ptr_c0[0] += c00;
			ptr_c1[0] += c10;
		}

		template <class T>
		inline void add_dot_1x4(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t p)
		{
			T c00 = c01 = c02 = c03 = 0;

			for (size_t k = 0; k < p; ++k)
			{
				const T a0 = a[k];
				const T b0 = b[0];
				const T b1 = b[1];
				const T b2 = b[2];
				const T b3 = b[3];

				c00 += a0 * b0;
				c01 += a0 * b1;
				c02 += a0 * b2;
				c03 += a0 * b3;
				b += ldb;
			}
			c[0] += c00;
			c[1] += c01;
			c[2] += c02;
			c[3] += c03;
		}

		template <class T>
		inline void add_dot_1x3(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t p)
		{
			T c00 = c01 = c02 = 0;

			for (size_t k = 0; k < p; ++k)
			{
				const T a0 = a[k];
				const T b0 = b[0];
				const T b1 = b[1];
				const T b2 = b[2];

				c00 += a0 * b0;
				c01 += a0 * b1;
				c02 += a0 * b2;
				b += ldb;
			}
			c[0] += c00;
			c[1] += c01;
			c[2] += c02;
		}

		template <class T>
		inline void add_dot_1x2(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t p)
		{
			T c00 = c01 = 0;

			for (size_t k = 0; k < p; ++k)
			{
				const T a0 = a[k];
				const T b0 = b[0];
				const T b1 = b[1];

				c00 += a0 * b0;
				c01 += a0 * b1;
				b += ldb;
			}
			ptr_c0[0] += c00;
			ptr_c0[1] += c01;
		}

		template <class T>
		inline void add_dot_1x1(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t p)
		{
			T c00 = 0;

			for (size_t k = 0; k < p; ++k)
			{
				const T a0 = a[k];
				const T b0 = b[0];

				c00 += a0 * b0;
				b += ldb;
			}
			ptr_c0[0] += c00;
		}

		// Function template add_dot_tiny

		template <class T>
		inline void add_dot_tiny(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t m, size_t n, size_t p)
		{
			switch (m)
			{
			case 4:
				switch (n)
				{
				case 4:
					add_dot_4x4(c, ldc, a, lda, b, ldb, p);
					break;
				case 3:
					add_dot_4x3(c, ldc, a, lda, b, ldb, p);
					break;
				case 2:
					add_dot_4x2(c, ldc, a, lda, b, ldb, p);
					break;
				case 1:
					add_dot_4x1(c, ldc, a, lda, b, ldb, p);
					break;
				}
				break;
			case 3:
				switch (n)
				{
				case 4:
					add_dot_3x4(c, ldc, a, lda, b, ldb, p);
					break;
				case 3:
					add_dot_3x3(c, ldc, a, lda, b, ldb, p);
					break;
				case 2:
					add_dot_3x2(c, ldc, a, lda, b, ldb, p);
					break;
				case 1:
					add_dot_3x1(c, ldc, a, lda, b, ldb, p);
					break;
				}
				break;
			case 2:
				switch (n)
				{
				case 4:
					add_dot_2x4(c, ldc, a, lda, b, ldb, p);
					break;
				case 3:
					add_dot_2x3(c, ldc, a, lda, b, ldb, p);
					break;
				case 2:
					add_dot_2x2(c, ldc, a, lda, b, ldb, p);
					break;
				case 1:
					add_dot_2x1(c, ldc, a, lda, b, ldb, p);
					break;
				}
				break;
			case 1:
				switch (n)
				{
				case 4:
					add_dot_1x4(c, ldc, a, lda, b, ldb, p);
					break;
				case 3:
					add_dot_1x3(c, ldc, a, lda, b, ldb, p);
					break;
				case 2:
					add_dot_1x2(c, ldc, a, lda, b, ldb, p);
					break;
				case 1:
					add_dot_1x1(c, ldc, a, lda, b, ldb, p);
					break;
				}
				break;
			}
		}

		// Function template impl_gemm

		template <class T>
		void impl_gemm(T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t m, size_t n, size_t p)
		{
			constexpr size_t block_m = gemm_block_m<T>();
			constexpr size_t block_n = gemm_block_n<T>();
			constexpr size_t block_p = gemm_block_p<T>();
			std::stack<std::tuple<T*, const T*, size_t, size_t>> task;
			// General matrix multiplication
			task.emplace(c, a, b, m, n, p);
			while (!task.empty())
			{
				auto c0 = std::get<0>(task.top());
				auto a0 = std::get<1>(task.top());
				auto b0 = std::get<2>(task.top());
				size_t m0 = std::get<3>(task.top());
				size_t n0 = std::get<4>(task.top());
				size_t p0 = std::get<5>(task.top());
				task.pop();
				if (m0 > block_m)
				{
					// Calculate: exp = log2(m0 - 1)
					float tmp = static_cast<float>(m0 - 1);
					size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
					// Calculate: m1 = pow(2, exp)
					size_t m1 = static_cast<size_t>(1) << exp;
					auto src1 = src0 + m1 * src_rs;
					if (n0 > block_n)
					{
						// Calculate: exp = log2(n0 - 1)
						float tmp = static_cast<float>(n0 - 1);
						size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
						// Calculate: n1 = pow(2, exp)
						size_t n1 = static_cast<size_t>(1) << exp;
						auto dst1 = dst0 + n1 * dst_rs;
						// Transpose of four submatrices
						//task.emplace(dst1 + m1, src1 + n1, m0 - m1, n0 - n1);
						//task.emplace(dst0 + m1, src1, m0 - m1, n1);
						//task.emplace(dst1, src0 + n1, m1, n0 - n1);
						//task.emplace(dst0, src0, m1, n1);
					}
					else
					{
						// Transpose of two submatrices
						//task.emplace(dst0 + m1, src1, m0 - m1, n0);
						//task.emplace(dst0, src0, m1, n0);
					}
				}
				else
				{
					if (n0 > block_n)
					{
						// Calculate: exp = log2(n0 - 1)
						float tmp = static_cast<float>(n0 - 1);
						size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
						// Calculate: n1 = pow(2, exp)
						size_t n1 = static_cast<size_t>(1) << exp;
						auto dst1 = dst0 + n1 * dst_rs;
						// Transpose of two submatrices
						//task.emplace(dst1, src0 + n1, m0, n0 - n1);
						//task.emplace(dst0, src0, m0, n1);
					}
					else
					{
						if (m0 == block_m && n0 == block_n && p0 == block_p)
							add_dot_block(c0, ldc, a0, lda, b0, ldb);
						else
							add_dot_tiny(c0, ldc, a0, lda, b0, ldb, m0, n0, p0);
					}
				}
			}
		}

		//template <class T>
		//void impl_gemm0(T* dst, size_t dst_rs, const T* src, size_t src_rs, size_t m, size_t n)
		//{
		//	for (size_t i = 0; i < m; ++i)
		//		for (size_t j = 0; j < n; ++j)
		//			dst[j * dst_rs + i] = src[i * src_rs + j];
		//}
		
		//template <class T>
		//void impl_gemm1(T* dst, size_t dst_rs, const T* src, size_t src_rs, size_t m, size_t n)
		//{
		//	for (size_t i = 0; i < m; i += 8)
		//		for (size_t j = 0; j < n; j += 8)
		//			if (i + 8 < m && j + 8 < n)
		//				gemm_block(dst + j * dst_rs + i, dst_rs, src + i * src_rs + j, src_rs);
		//			else
		//				gemm_tiny(dst + j * dst_rs + i, dst_rs, src + i * src_rs + j, src_rs, m - i, n - j);
		//}
		
		//template <class T>
		//void impl_gemm2(T* dst, size_t dst_rs, const T* src, size_t src_rs, size_t m, size_t n)
		//{
		//	constexpr size_t block_m = 8;
		//	constexpr size_t block_n = 8;

		//	if (m > block_m)
		//	{
		//		// Calculate: exp = log2(m - 1)
		//		float tmp = static_cast<float>(m - 1);
		//		size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
		//		// Calculate: m1 = pow(2, exp)
		//		size_t m1 = static_cast<size_t>(1) << exp;
		//		auto src1 = src + m1 * src_rs;
		//		if (n > block_n)
		//		{
		//			// Calculate: exp = log2(n - 1)
		//			float tmp = static_cast<float>(n - 1);
		//			size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
		//			// Calculate: n1 = pow(2, exp)
		//			size_t n1 = static_cast<size_t>(1) << exp;
		//			auto dst1 = dst + n1 * dst_rs;
		//			// Transpose of four submatrices
		//			impl_gemm(dst, dst_rs, src, src_rs, m1, n1);
		//			impl_gemm(dst1, dst_rs, src + n1, src_rs, m1, n - n1);
		//			impl_gemm(dst + m1, dst_rs, src1, src_rs, m - m1, n1);
		//			impl_gemm(dst1 + m1, dst_rs, src1 + n1, src_rs, m - m1, n - n1);
		//		}
		//		else if (n > 0)
		//		{
		//			// Transpose of two submatrices
		//			impl_gemm(dst, dst_rs, src, src_rs, m1, n);
		//			impl_gemm(dst + m1, dst_rs, src1, src_rs, m - m1, n);
		//		}
		//	}
		//	else
		//	{
		//		if (n > block_n)
		//		{
		//			// Calculate: exp = log2(n - 1)
		//			float tmp = static_cast<float>(n - 1);
		//			size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
		//			// Calculate: n1 = pow(2, exp)
		//			size_t n1 = static_cast<size_t>(1) << exp;
		//			auto dst1 = dst + n1 * dst_rs;
		//			// Transpose of two submatrices
		//			impl_gemm(dst, dst_rs, src, src_rs, m, n1);
		//			impl_gemm(dst1, dst_rs, src + n1, src_rs, m, n - n1);
		//		}
		//		else
		//		{
		//			if (m == block_m && n == block_n)
		//				gemm_block(dst, dst_rs, src, src_rs);
		//			else
		//				gemm_tiny(dst, dst_rs, src, src_rs, m, n);
		//		}
		//	}
		//}

	} // namespace comm

} // namespace core

#endif
