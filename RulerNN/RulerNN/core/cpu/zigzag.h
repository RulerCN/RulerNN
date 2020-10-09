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
		inline void zigzag_block(T* dst, const T* src, size_t src_rs)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		// Function template zigzag_tiny

		template <class T>
		inline void zigzag_tiny(T* dst, const T* src, size_t src_rs, size_t m, size_t n)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		// Function template impl_zigzag

		template <class T>
		void impl_zigzag(T* dst, size_t dst_rs, const T* src, size_t src_rs, size_t m, size_t n)
		{
			constexpr size_t block_m = zigzag_block_m<T>();
			constexpr size_t block_n = zigzag_block_n<T>();
			std::stack<std::tuple<T*, const T*, size_t, size_t>> task;
			// Zigzag Encode
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
							zigzag_block(dst0, dst_rs, src0, src_rs);
						else
							zigzag_tiny(dst0, dst_rs, src0, src_rs, m0, n0);
					}
				}
			}
		}

	} // namespace cpu

} // namespace core

#endif
