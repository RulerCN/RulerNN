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
		inline void trp_block(T* dst, size_t dst_rs, const T* src, size_t src_rs)
		{
			T* ptr_dst0 = dst;
			T* ptr_dst1 = ptr_dst0 + dst_rs;
			T* ptr_dst2 = ptr_dst1 + dst_rs;
			T* ptr_dst3 = ptr_dst2 + dst_rs;
			T* ptr_dst4 = ptr_dst3 + dst_rs;
			T* ptr_dst5 = ptr_dst4 + dst_rs;
			T* ptr_dst6 = ptr_dst5 + dst_rs;
			T* ptr_dst7 = ptr_dst6 + dst_rs;
			ptr_dst0[0] = src[0];
			ptr_dst1[0] = src[1];
			ptr_dst2[0] = src[2];
			ptr_dst3[0] = src[3];
			ptr_dst4[0] = src[4];
			ptr_dst5[0] = src[5];
			ptr_dst6[0] = src[6];
			ptr_dst7[0] = src[7];
			src += src_rs;
			ptr_dst0[1] = src[0];
			ptr_dst1[1] = src[1];
			ptr_dst2[1] = src[2];
			ptr_dst3[1] = src[3];
			ptr_dst4[1] = src[4];
			ptr_dst5[1] = src[5];
			ptr_dst6[1] = src[6];
			ptr_dst7[1] = src[7];
			src += src_rs;
			ptr_dst0[2] = src[0];
			ptr_dst1[2] = src[1];
			ptr_dst2[2] = src[2];
			ptr_dst3[2] = src[3];
			ptr_dst4[2] = src[4];
			ptr_dst5[2] = src[5];
			ptr_dst6[2] = src[6];
			ptr_dst7[2] = src[7];
			src += src_rs;
			ptr_dst0[3] = src[0];
			ptr_dst1[3] = src[1];
			ptr_dst2[3] = src[2];
			ptr_dst3[3] = src[3];
			ptr_dst4[3] = src[4];
			ptr_dst5[3] = src[5];
			ptr_dst6[3] = src[6];
			ptr_dst7[3] = src[7];
			src += src_rs;
			ptr_dst0[4] = src[0];
			ptr_dst1[4] = src[1];
			ptr_dst2[4] = src[2];
			ptr_dst3[4] = src[3];
			ptr_dst4[4] = src[4];
			ptr_dst5[4] = src[5];
			ptr_dst6[4] = src[6];
			ptr_dst7[4] = src[7];
			src += src_rs;
			ptr_dst0[5] = src[0];
			ptr_dst1[5] = src[1];
			ptr_dst2[5] = src[2];
			ptr_dst3[5] = src[3];
			ptr_dst4[5] = src[4];
			ptr_dst5[5] = src[5];
			ptr_dst6[5] = src[6];
			ptr_dst7[5] = src[7];
			src += src_rs;
			ptr_dst0[6] = src[0];
			ptr_dst1[6] = src[1];
			ptr_dst2[6] = src[2];
			ptr_dst3[6] = src[3];
			ptr_dst4[6] = src[4];
			ptr_dst5[6] = src[5];
			ptr_dst6[6] = src[6];
			ptr_dst7[6] = src[7];
			src += src_rs;
			ptr_dst0[7] = src[0];
			ptr_dst1[7] = src[1];
			ptr_dst2[7] = src[2];
			ptr_dst3[7] = src[3];
			ptr_dst4[7] = src[4];
			ptr_dst5[7] = src[5];
			ptr_dst6[7] = src[6];
			ptr_dst7[7] = src[7];
		}

		// Function template trp_tiny

		template <class T>
		inline void trp_tiny(T* dst, size_t dst_rs, const T* src, size_t src_rs, size_t m, size_t n)
		{
			const size_t row0 = 0;
			const size_t row1 = dst_rs;
			const size_t row2 = row1 + dst_rs;
			const size_t row3 = row2 + dst_rs;
			const size_t row4 = row3 + dst_rs;
			const size_t row5 = row4 + dst_rs;
			const size_t row6 = row5 + dst_rs;
			const size_t row7 = row6 + dst_rs;

			for (size_t i = 0; i < m; ++i)
			{
				switch (n)
				{
				case 8: dst[row7 + i] = src[7];
				case 7: dst[row6 + i] = src[6];
				case 6: dst[row5 + i] = src[5];
				case 5: dst[row4 + i] = src[4];
				case 4: dst[row3 + i] = src[3];
				case 3: dst[row2 + i] = src[2];
				case 2: dst[row1 + i] = src[1];
				case 1: dst[row0 + i] = src[0];
					break;
				}
				src += src_rs;
			}
		}

		// Function template impl_trp

		template <class T>
		void impl_trp(T* dst, size_t dst_rs, const T* src, size_t src_rs, size_t m, size_t n)
		{
			constexpr size_t block_m = trp_block_m<T>();
			constexpr size_t block_n = trp_block_n<T>();
			std::stack<std::tuple<T*, const T*, size_t, size_t>> task;
			// Matrix transposition
			task.emplace(dst, src, m, n);
			while (!task.empty())
			{
				auto dst0 = std::get<0>(task.top());
				auto src0 = std::get<1>(task.top());
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
						task.emplace(dst1 + m1, src1 + n1, m0 - m1, n0 - n1);
						task.emplace(dst0 + m1, src1, m0 - m1, n1);
						task.emplace(dst1, src0 + n1, m1, n0 - n1);
						task.emplace(dst0, src0, m1, n1);
					}
					else
					{
						// Transpose of two submatrices
						task.emplace(dst0 + m1, src1, m0 - m1, n0);
						task.emplace(dst0, src0, m1, n0);
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
						task.emplace(dst1, src0 + n1, m0, n0 - n1);
						task.emplace(dst0, src0, m0, n1);
					}
					else
					{
						if (m0 == block_m && n0 == block_n)
							trp_block(dst0, dst_rs, src0, src_rs);
						else
							trp_tiny(dst0, dst_rs, src0, src_rs, m0, n0);
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
		//void impl_trp1(T* dst, size_t dst_rs, const T* src, size_t src_rs, size_t m, size_t n)
		//{
		//	for (size_t i = 0; i < m; i += 8)
		//		for (size_t j = 0; j < n; j += 8)
		//			if (i + 8 < m && j + 8 < n)
		//				trp_block(dst + j * dst_rs + i, dst_rs, src + i * src_rs + j, src_rs);
		//			else
		//				trp_tiny(dst + j * dst_rs + i, dst_rs, src + i * src_rs + j, src_rs, m - i, n - j);
		//}
		
		//template <class T>
		//void impl_trp2(T* dst, size_t dst_rs, const T* src, size_t src_rs, size_t m, size_t n)
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
		//			impl_trp(dst, dst_rs, src, src_rs, m1, n1);
		//			impl_trp(dst1, dst_rs, src + n1, src_rs, m1, n - n1);
		//			impl_trp(dst + m1, dst_rs, src1, src_rs, m - m1, n1);
		//			impl_trp(dst1 + m1, dst_rs, src1 + n1, src_rs, m - m1, n - n1);
		//		}
		//		else if (n > 0)
		//		{
		//			// Transpose of two submatrices
		//			impl_trp(dst, dst_rs, src, src_rs, m1, n);
		//			impl_trp(dst + m1, dst_rs, src1, src_rs, m - m1, n);
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
		//			impl_trp(dst, dst_rs, src, src_rs, m, n1);
		//			impl_trp(dst1, dst_rs, src + n1, src_rs, m, n - n1);
		//		}
		//		else
		//		{
		//			if (m == block_m && n == block_n)
		//				trp_block(dst, dst_rs, src, src_rs);
		//			else
		//				trp_tiny(dst, dst_rs, src, src_rs, m, n);
		//		}
		//	}
		//}

	} // namespace comm

} // namespace core

#endif
