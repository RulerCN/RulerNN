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

#ifndef __CORE_CPU_TRP_H__
#define __CORE_CPU_TRP_H__

#include "trp/trpi8.h"
#include "trp/trpi16.h"
#include "trp/trpi32.h"
#include "trp/trpu8.h"
#include "trp/trpu16.h"
#include "trp/trpu32.h"
#include "trp/trpps.h"
#include "trp/trppd.h"

namespace core
{
	namespace cpu
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
		void trp_block(T* b, size_t ldb, const T* a, size_t lda)
		{
			T* ptr_b0 = b;
			T* ptr_b1 = b + ldb;
			T* ptr_b2 = b + ldb * 2;
			T* ptr_b3 = b + ldb * 3;
			T* ptr_b4 = b + ldb * 4;
			T* ptr_b5 = b + ldb * 5;
			T* ptr_b6 = b + ldb * 6;
			T* ptr_b7 = b + ldb * 7;
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
			for (size_t i = 0; i < n; ++i)
			{
				switch (m)
				{
				case 8: b[7] = a[lda * 7]; [[fallthrough]];
				case 7: b[6] = a[lda * 6]; [[fallthrough]];
				case 6: b[5] = a[lda * 5]; [[fallthrough]];
				case 5: b[4] = a[lda * 4]; [[fallthrough]];
				case 4: b[3] = a[lda * 3]; [[fallthrough]];
				case 3: b[2] = a[lda * 2]; [[fallthrough]];
				case 2: b[1] = a[lda];     [[fallthrough]];
				case 1: b[0] = a[0];       [[fallthrough]];
				}
				a += 1;
				b += ldb;
			}
		}

		// Function template impl_trp

		template <class T>
		void impl_trp(T* b, size_t ldb, const T* a, size_t lda, size_t m, size_t n)
		{
			constexpr size_t block_m = trp_block_m<T>();
			constexpr size_t block_n = trp_block_n<T>();
			std::stack<std::tuple<T*, const T*, size_t, size_t>> task;
			// Transpose of a matrix
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

	} // namespace cpu

} // namespace core

#endif
