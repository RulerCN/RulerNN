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

#ifndef __CORE_CPU_ZIG_H__
#define __CORE_CPU_ZIG_H__

#include <map>
#include <stack>
#include <tuple>
#include "zig/zigcpyi8.h"
#include "zig/zigcpyi16.h"
#include "zig/zigcpyi32.h"
#include "zig/zigcpyu8.h"
#include "zig/zigcpyu16.h"
#include "zig/zigcpyu32.h"
#include "zig/zigcpyps.h"
#include "zig/zigcpypd.h"
#include "zig/zigtrpi8.h"
#include "zig/zigtrpi16.h"
#include "zig/zigtrpi32.h"
#include "zig/zigtrpu8.h"
#include "zig/zigtrpu16.h"
#include "zig/zigtrpu32.h"
#include "zig/zigtrpps.h"
#include "zig/zigtrppd.h"


namespace core
{
	namespace cpu
	{
		// Function template zigcpy_block_m
		template <class T>
		constexpr size_t zigcpy_block_m(void)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		// Function template zigcpy_block_n
		template <class T>
		constexpr size_t zigcpy_block_n(void)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		// Function template zigtrp_block_m
		template <class T>
		constexpr size_t zigtrp_block_m(void)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		// Function template zigtrp_block_n
		template <class T>
		constexpr size_t zigtrp_block_n(void)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		// Function template zigcpy_block
		template <class T>
		inline T* zigcpy_block(T* b, const T* a, size_t lda)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		// Function template zigcpy_tiny
		template <class T>
		inline T* zigcpy_tiny(T* b, const T* a, size_t lda, size_t m, size_t n)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		// Function template zigtrp_block
		template <class T>
		inline T* zigtrp_block(T* b, const T* a, size_t lda)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		// Function template zigtrp_tiny
		template <class T>
		inline T* zigtrp_tiny(T* b, const T* a, size_t lda, size_t m, size_t n)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		// Function template impl_zig
		template <class T>
		inline std::map<std::tuple<size_t, size_t>, std::tuple<size_t, T*, size_t, size_t>>
			impl_zig(T* b, const T* a, size_t lda, size_t m, size_t n, bool transpose = false)
		{
			return (transpose ? impl_zigtrp(b, a, lda, m, n) : impl_zigcpy(b, a, lda, m, n));
		}

		// Function template impl_vzig
		template <class T>
		inline std::map<std::tuple<size_t, size_t>, std::tuple<size_t, T*, size_t, size_t>>
			impl_vzig(T* b, const T* a, size_t lda, size_t m, size_t n, bool transpose = false)
		{
			return (transpose ? impl_vzigtrp(b, a, lda, m, n) : impl_vzigcpy(b, a, lda, m, n));
		}

		// Function template impl_zigcpy
		template <class T>
		std::map<std::tuple<size_t, size_t>, std::tuple<size_t, T*, size_t, size_t>>
			impl_zigcpy(T* b, const T* a, size_t lda, size_t m, size_t n)
		{
			constexpr size_t block_m = zigcpy_block_m<T>();
			constexpr size_t block_n = zigcpy_block_n<T>();
			size_t i = 0, x = 0, y = 0;
			std::map<std::tuple<size_t, size_t>, std::tuple<size_t, T*, size_t, size_t>> block_list;
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
					const T* p = a + m0 * lda;
					if (n > block_n)
					{
						// exp = log2(n - 1)
						float tmp = static_cast<float>(n - 1);
						size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
						// n0 = pow(2, exp)
						size_t n0 = static_cast<size_t>(1) << exp;
						size_t n1 = n - n0;
						// push the elements
						task.emplace(p + n0, x + m0, y + n0, m1, n1);
						task.emplace(p, x + m0, y, m1, n0);
						task.emplace(a + n0, x, y + n0, m0, n1);
						task.emplace(a, x, y, m0, n0);
					}
					else
					{
						task.emplace(p, x + m0, y, m1, n);
						task.emplace(a, x, y, m0, n);
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
						task.emplace(a + n0, x, y + n0, m, n1);
						task.emplace(a, x, y, m, n0);
					}
					else
					{
						if (m == block_m && n == block_n)
							b = zigcpy_block(b, a, lda);
						else
							b = zigcpy_tiny(b, a, lda, m, n);
						block_list.emplace(std::make_pair(std::tuple<size_t, size_t>(x, y), std::tuple<size_t, T*, size_t, size_t>(i++, b, m, n)));
					}
				}
				if (task.empty())
					break;
				a = std::get<0>(task.top());
				x = std::get<1>(task.top());
				y = std::get<2>(task.top());
				m = std::get<3>(task.top());
				n = std::get<4>(task.top());
				task.pop();
			}
			return block_list;
		}

		// Function template impl_zigtrp
		template <class T>
		std::map<std::tuple<size_t, size_t>, std::tuple<size_t, T*, size_t, size_t>>
			impl_zigtrp(T* b, const T* a, size_t lda, size_t m, size_t n)
		{
			constexpr size_t block_m = zigtrp_block_m<T>();
			constexpr size_t block_n = zigtrp_block_n<T>();
			size_t i = 0, x = 0, y = 0;
			std::map<std::tuple<size_t, size_t>, std::tuple<size_t, T*, size_t, size_t>> block_list;
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
					const T* p = a + m0 * lda;
					if (n > block_n)
					{
						// exp = log2(n - 1)
						float tmp = static_cast<float>(n - 1);
						size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
						// n0 = pow(2, exp)
						size_t n0 = static_cast<size_t>(1) << exp;
						size_t n1 = n - n0;
						// push the elements
						task.emplace(p + n0, x + m0, y + n0, m1, n1);
						task.emplace(p, x + m0, y, m1, n0);
						task.emplace(a + n0, x, y + n0, m0, n1);
						task.emplace(a, x, y, m0, n0);
					}
					else
					{
						task.emplace(p, x + m0, y, m1, n);
						task.emplace(a, x, y, m0, n);
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
						task.emplace(a + n0, x, y + n0, m, n1);
						task.emplace(a, x, y, m, n0);
					}
					else
					{
						if (m == block_m && n == block_n)
							b = zigtrp_block(b, a, lda);
						else
							b = zigtrp_tiny(b, a, lda, m, n);
						block_list.emplace(std::make_pair(std::tuple<size_t, size_t>(x, y), std::tuple<size_t, T*, size_t, size_t>(i++, b, m, n)));
					}
				}
				if (task.empty())
					break;
				a = std::get<0>(task.top());
				x = std::get<1>(task.top());
				y = std::get<2>(task.top());
				m = std::get<3>(task.top());
				n = std::get<4>(task.top());
				task.pop();
			}
			return block_list;
		}

		// Function template impl_vzigcpy
		template <class T>
		std::map<std::tuple<size_t, size_t>, std::tuple<size_t, T*, size_t, size_t>>
			impl_vzigcpy(T* b, const T* a, size_t lda, size_t m, size_t n)
		{
			constexpr size_t block_m = zigcpy_block_m<T>();
			constexpr size_t block_n = zigcpy_block_n<T>();
			size_t i = 0, x = 0, y = 0;
			std::map<std::tuple<size_t, size_t>, std::tuple<size_t, T*, size_t, size_t>> block_list;
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
					const T* p = a + m0 * lda;
					if (n > block_n)
					{
						// exp = log2(n - 1)
						float tmp = static_cast<float>(n - 1);
						size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
						// n0 = pow(2, exp)
						size_t n0 = static_cast<size_t>(1) << exp;
						size_t n1 = n - n0;
						// push the elements
						task.emplace(p + n0, x + m0, y + n0, m1, n1);
						task.emplace(a + n0, x, y + n0, m0, n1);
						task.emplace(p, x + m0, y, m1, n0);
						task.emplace(a, x, y, m0, n0);
					}
					else
					{
						task.emplace(p, x + m0, y, m1, n);
						task.emplace(a, x, y, m0, n);
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
						task.emplace(a + n0, x, y + n0, m, n1);
						task.emplace(a, x, y, m, n0);
					}
					else
					{
						if (m == block_m && n == block_n)
							b = zigcpy_block(b, a, lda);
						else
							b = zigcpy_tiny(b, a, lda, m, n);
						block_list.emplace(std::make_pair(std::tuple<size_t, size_t>(x, y), std::tuple<size_t, T*, size_t, size_t>(i++, b, m, n)));
					}
				}
				if (task.empty())
					break;
				a = std::get<0>(task.top());
				x = std::get<1>(task.top());
				y = std::get<2>(task.top());
				m = std::get<3>(task.top());
				n = std::get<4>(task.top());
				task.pop();
			}
			return block_list;
		}

		// Function template impl_vzigcpy
		template <class T>
		std::map<std::tuple<size_t, size_t>, std::tuple<size_t, T*, size_t, size_t>>
			impl_vzigtrp(T* b, const T* a, size_t lda, size_t m, size_t n)
		{
			constexpr size_t block_m = zigtrp_block_m<T>();
			constexpr size_t block_n = zigtrp_block_n<T>();
			size_t i = 0, x = 0, y = 0;
			std::map<std::tuple<size_t, size_t>, std::tuple<size_t, T*, size_t, size_t>> block_list;
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
					const T* p = a + m0 * lda;
					if (n > block_n)
					{
						// exp = log2(n - 1)
						float tmp = static_cast<float>(n - 1);
						size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
						// n0 = pow(2, exp)
						size_t n0 = static_cast<size_t>(1) << exp;
						size_t n1 = n - n0;
						// push the elements
						task.emplace(p + n0, x + m0, y + n0, m1, n1);
						task.emplace(a + n0, x, y + n0, m0, n1);
						task.emplace(p, x + m0, y, m1, n0);
						task.emplace(a, x, y, m0, n0);
					}
					else
					{
						task.emplace(p, x + m0, y, m1, n);
						task.emplace(a, x, y, m0, n);
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
						task.emplace(a + n0, x, y + n0, m, n1);
						task.emplace(a, x, y, m, n0);
					}
					else
					{
						if (m == block_m && n == block_n)
							b = zigtrp_block(b, a, lda);
						else
							b = zigtrp_tiny(b, a, lda, m, n);
						block_list.emplace(std::make_pair(std::tuple<size_t, size_t>(x, y), std::tuple<size_t, T*, size_t, size_t>(i++, b, m, n)));
					}
				}
				if (task.empty())
					break;
				a = std::get<0>(task.top());
				x = std::get<1>(task.top());
				y = std::get<2>(task.top());
				m = std::get<3>(task.top());
				n = std::get<4>(task.top());
				task.pop();
			}
			return block_list;
		}

	} // namespace cpu

} // namespace core

#endif
