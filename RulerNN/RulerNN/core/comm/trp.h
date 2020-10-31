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

#ifndef __CORE_COMM_TRP_H__
#define __CORE_COMM_TRP_H__

#include <stack>
#include <tuple>

namespace core
{
	namespace comm
	{
		// Function template trp_block_m

		template <class T>
		constexpr size_t trp_block_m(void)
		{
			return static_cast<size_t>(8);
		}

		// Function template trp_block_n

		template <class T>
		constexpr size_t trp_block_n(void)
		{
			return static_cast<size_t>(8);
		}

		// Function template trp_block

		template <class T>
		inline void trp_block(T* b, size_t ldb, const T* a, size_t lda)
		{
			T* ptr_b0 = b;
			T* ptr_b1 = ptr_b0 + ldb;
			T* ptr_b2 = ptr_b1 + ldb;
			T* ptr_b3 = ptr_b2 + ldb;
			T* ptr_b4 = ptr_b3 + ldb;
			T* ptr_b5 = ptr_b4 + ldb;
			T* ptr_b6 = ptr_b5 + ldb;
			T* ptr_b7 = ptr_b6 + ldb;
			ptr_b0[0] = a[0];
			ptr_b1[0] = a[1];
			ptr_b2[0] = a[2];
			ptr_b3[0] = a[3];
			ptr_b4[0] = a[4];
			ptr_b5[0] = a[5];
			ptr_b6[0] = a[6];
			ptr_b7[0] = a[7];
			a += lda;
			ptr_b0[1] = a[0];
			ptr_b1[1] = a[1];
			ptr_b2[1] = a[2];
			ptr_b3[1] = a[3];
			ptr_b4[1] = a[4];
			ptr_b5[1] = a[5];
			ptr_b6[1] = a[6];
			ptr_b7[1] = a[7];
			a += lda;
			ptr_b0[2] = a[0];
			ptr_b1[2] = a[1];
			ptr_b2[2] = a[2];
			ptr_b3[2] = a[3];
			ptr_b4[2] = a[4];
			ptr_b5[2] = a[5];
			ptr_b6[2] = a[6];
			ptr_b7[2] = a[7];
			a += lda;
			ptr_b0[3] = a[0];
			ptr_b1[3] = a[1];
			ptr_b2[3] = a[2];
			ptr_b3[3] = a[3];
			ptr_b4[3] = a[4];
			ptr_b5[3] = a[5];
			ptr_b6[3] = a[6];
			ptr_b7[3] = a[7];
			a += lda;
			ptr_b0[4] = a[0];
			ptr_b1[4] = a[1];
			ptr_b2[4] = a[2];
			ptr_b3[4] = a[3];
			ptr_b4[4] = a[4];
			ptr_b5[4] = a[5];
			ptr_b6[4] = a[6];
			ptr_b7[4] = a[7];
			a += lda;
			ptr_b0[5] = a[0];
			ptr_b1[5] = a[1];
			ptr_b2[5] = a[2];
			ptr_b3[5] = a[3];
			ptr_b4[5] = a[4];
			ptr_b5[5] = a[5];
			ptr_b6[5] = a[6];
			ptr_b7[5] = a[7];
			a += lda;
			ptr_b0[6] = a[0];
			ptr_b1[6] = a[1];
			ptr_b2[6] = a[2];
			ptr_b3[6] = a[3];
			ptr_b4[6] = a[4];
			ptr_b5[6] = a[5];
			ptr_b6[6] = a[6];
			ptr_b7[6] = a[7];
			a += lda;
			ptr_b0[7] = a[0];
			ptr_b1[7] = a[1];
			ptr_b2[7] = a[2];
			ptr_b3[7] = a[3];
			ptr_b4[7] = a[4];
			ptr_b5[7] = a[5];
			ptr_b6[7] = a[6];
			ptr_b7[7] = a[7];
		}

		// Function template trp_tiny

		template <class T>
		inline void trp_tiny(T* b, size_t ldb, const T* a, size_t lda, size_t m, size_t n)
		{
			const size_t row0 = 0;
			const size_t row1 = ldb;
			const size_t row2 = row1 + ldb;
			const size_t row3 = row2 + ldb;
			const size_t row4 = row3 + ldb;
			const size_t row5 = row4 + ldb;
			const size_t row6 = row5 + ldb;
			const size_t row7 = row6 + ldb;

			for (size_t i = 0; i < m; ++i)
			{
				switch (n)
				{
				case 8: b[row7 + i] = a[7];
				case 7: b[row6 + i] = a[6];
				case 6: b[row5 + i] = a[5];
				case 5: b[row4 + i] = a[4];
				case 4: b[row3 + i] = a[3];
				case 3: b[row2 + i] = a[2];
				case 2: b[row1 + i] = a[1];
				case 1: b[row0 + i] = a[0];
					break;
				}
				a += lda;
			}
		}

		// Function template impl_trp

		template <class T>
		void impl_trp(T* b, size_t ldb, const T* a, size_t lda, size_t m, size_t n)
		{
			constexpr size_t block_m = trp_block_m<T>();
			constexpr size_t block_n = trp_block_n<T>();
			std::stack<std::tuple<T*, const T*, size_t, size_t>> task;
			// Matrix transposition
			task.emplace(b, a, m, n);
			while (!task.empty())
			{
				auto b0 = std::get<0>(task.top());
				auto a0 = std::get<1>(task.top());
				size_t m0 = std::get<2>(task.top());
				size_t n0 = std::get<3>(task.top());
				task.pop();
				if (m0 > block_m)
				{
					// Calculate: exp = log2(m0 - 1)
					float tmp = static_cast<float>(m0 - 1);
					size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
					// Calculate: m1 = pow(2, exp)
					size_t m1 = static_cast<size_t>(1) << exp;
					auto a1 = a0 + m1 * lda;
					if (n0 > block_n)
					{
						// Calculate: exp = log2(n0 - 1)
						float tmp = static_cast<float>(n0 - 1);
						size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
						// Calculate: n1 = pow(2, exp)
						size_t n1 = static_cast<size_t>(1) << exp;
						auto b1 = b0 + n1 * ldb;
						// Transpose of four submatrices
						task.emplace(b1 + m1, a1 + n1, m0 - m1, n0 - n1);
						task.emplace(b0 + m1, a1, m0 - m1, n1);
						task.emplace(b1, a0 + n1, m1, n0 - n1);
						task.emplace(b0, a0, m1, n1);
					}
					else
					{
						// Transpose of two submatrices
						task.emplace(b0 + m1, a1, m0 - m1, n0);
						task.emplace(b0, a0, m1, n0);
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
						auto b1 = b0 + n1 * ldb;
						// Transpose of two submatrices
						task.emplace(b1, a0 + n1, m0, n0 - n1);
						task.emplace(b0, a0, m0, n1);
					}
					else
					{
						if (m0 == block_m && n0 == block_n)
							trp_block(b0, ldb, a0, lda);
						else
							trp_tiny(b0, ldb, a0, lda, m0, n0);
					}
				}
			}
		}

		//template <class T>
		//void impl_trp0(T* b, size_t ldb, const T* a, size_t lda, size_t m, size_t n)
		//{
		//	for (size_t i = 0; i < m; ++i)
		//		for (size_t j = 0; j < n; ++j)
		//			b[j * ldb + i] = a[i * lda + j];
		//}

		//template <class T>
		//void impl_trp1(T* b, size_t ldb, const T* a, size_t lda, size_t m, size_t n)
		//{
		//	for (size_t i = 0; i < m; i += 8)
		//		for (size_t j = 0; j < n; j += 8)
		//			if (i + 8 < m && j + 8 < n)
		//				trp_block(b + j * ldb + i, ldb, a + i * lda + j, lda);
		//			else
		//				trp_tiny(b + j * ldb + i, ldb, a + i * lda + j, lda, m - i, n - j);
		//}
		
		//template <class T>
		//void impl_trp2(T* b, size_t ldb, const T* a, size_t lda, size_t m, size_t n)
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
		//		auto a1 = a + m1 * lda;
		//		if (n > block_n)
		//		{
		//			// Calculate: exp = log2(n - 1)
		//			float tmp = static_cast<float>(n - 1);
		//			size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
		//			// Calculate: n1 = pow(2, exp)
		//			size_t n1 = static_cast<size_t>(1) << exp;
		//			auto b1 = b + n1 * ldb;
		//			// Transpose of four submatrices
		//			impl_trp(b, ldb, a, lda, m1, n1);
		//			impl_trp(b1, ldb, a + n1, lda, m1, n - n1);
		//			impl_trp(b + m1, ldb, a1, lda, m - m1, n1);
		//			impl_trp(b1 + m1, ldb, a1 + n1, lda, m - m1, n - n1);
		//		}
		//		else if (n > 0)
		//		{
		//			// Transpose of two submatrices
		//			impl_trp(b, ldb, a, lda, m1, n);
		//			impl_trp(b + m1, ldb, a1, lda, m - m1, n);
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
		//			auto b1 = b + n1 * ldb;
		//			// Transpose of two submatrices
		//			impl_trp(b, ldb, a, lda, m, n1);
		//			impl_trp(b1, ldb, a + n1, lda, m, n - n1);
		//		}
		//		else
		//		{
		//			if (m == block_m && n == block_n)
		//				trp_block(b, ldb, a, lda);
		//			else
		//				trp_tiny(b, ldb, a, lda, m, n);
		//		}
		//	}
		//}

	} // namespace comm

} // namespace core

#endif
