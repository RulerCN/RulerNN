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

#ifndef __CORE_CPU_ZIGZAG_H__
#define __CORE_CPU_ZIGZAG_H__

//#include "zigzag/zigzagi8.h"
//#include "zigzag/zigzagi16.h"
//#include "zigzag/zigzagi32.h"
//#include "zigzag/zigzagu8.h"
//#include "zigzag/zigzagu16.h"
//#include "zigzag/zigzagu32.h"
#include "zigzag/zigzagps.h"
//#include "zigzag/zigzagpd.h"

namespace core
{
	namespace cpu
	{
		// Function template zigzag_block_m

		template <class T>
		constexpr size_t zigzag_block_m(void)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		// Function template zigzag_block_n

		template <class T>
		constexpr size_t zigzag_block_n(void)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		// Function template zigzag_block

		template <class T>
		inline T* zigzag_block(T* b, const T* a, size_t lda)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		// Function template zigzag_tiny

		template <class T>
		inline T* zigzag_tiny(T* b, const T* a, size_t lda, size_t m, size_t n)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		// Function template impl_zigzag

		template <class T>
		void impl_zigzag(T* b, const T* a, size_t lda, size_t m, size_t n)
		{
			constexpr size_t block_m = zigzag_block_m<T>();
			constexpr size_t block_n = zigzag_block_n<T>();
			size_t i = 0;
			size_t j = 0;
			std::stack<std::tuple<const T*, size_t, size_t, size_t, size_t>> task;
			for (;;)
			{
				if (m > block_m)
				{
					// exp = log2(m - 1)
					float tmp = static_cast<float>(m - 1);
					size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
					// m0 = pow(2, exp)
					size_t m0 = static_cast<size_t>(1) << exp;
					size_t m1 = m - m0;
					if (n > block_n)
					{
						// exp = log2(n - 1)
						float tmp = static_cast<float>(n - 1);
						size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
						// n0 = pow(2, exp)
						size_t n0 = static_cast<size_t>(1) << exp;
						size_t n1 = n - n0;
						// push the elements
						task.emplace(a,      i, j,      m0, n0);
						task.emplace(a + n0, i, j + n0, m0, n1);
						i += m0;
						a += m0 * lda;
						task.emplace(a,      i, j,      m1, n0);
						task.emplace(a + n0, i, j + n0, m1, n1);
					}
					else
					{
						task.emplace(a, i, j, m0, n);
						i += m0;
						a += m0 * lda;
						task.emplace(a, i, j, m1, n);
					}
				}
				else
				{
					if (n > block_n)
					{
						// exp = log2(n - 1)
						float tmp = static_cast<float>(n - 1);
						size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
						// n0 = pow(2, exp)
						size_t n0 = static_cast<size_t>(1) << exp;
						size_t n1 = n - n0;
						// push the elements
						task.emplace(a,      i, j,      m, n0);
						task.emplace(a + n0, i, j + n0, m, n1);
					}
					else
					{
						if (m == block_m && n == block_n)
						{
							b = zigzag_block(b, a, lda);
						}
						else
						{
							b = zigzag_tiny(b, a, lda, m, n);
						}
					}
				}
				if (task.empty())
					break;
				a = std::get<0>(task.top());
				i = std::get<1>(task.top());
				j = std::get<2>(task.top());
				m = std::get<3>(task.top());
				n = std::get<4>(task.top());
				task.pop();
			}
		}

	} // namespace cpu

} // namespace core

#endif
