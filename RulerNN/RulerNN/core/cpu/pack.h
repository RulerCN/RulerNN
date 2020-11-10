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

#ifndef __CORE_CPU_PACK_H__
#define __CORE_CPU_PACK_H__

#include "pack/packci8.h"
#include "pack/packci16.h"
#include "pack/packci32.h"
#include "pack/packcu8.h"
#include "pack/packcu16.h"
#include "pack/packcu32.h"
#include "pack/packcps.h"
#include "pack/packcpd.h"
#include "pack/packti8.h"
#include "pack/packti16.h"
#include "pack/packti32.h"
#include "pack/packtu8.h"
#include "pack/packtu16.h"
#include "pack/packtu32.h"
#include "pack/packtps.h"
#include "pack/packtpd.h"


namespace core
{
	namespace cpu
	{

		// Function template packc_block_m
		template <class T>
		constexpr size_t packc_block_m(void)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		// Function template packc_block_n
		template <class T>
		constexpr size_t packc_block_n(void)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		// Function template packc_block
		template <class T>
		inline void packc_block(T* b, size_t ldb, const T* a, size_t lda)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		// Function template packc_tiny
		template <class T>
		inline void packc_tiny(T* b, size_t ldb, const T* a, size_t lda, size_t m, size_t n)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		// Function template packt_block_m
		template <class T>
		constexpr size_t packt_block_m(void)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		// Function template packt_block_n
		template <class T>
		constexpr size_t packt_block_n(void)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		// Function template packt_block
		template <class T>
		inline void packt_block(T* b, size_t ldb, const T* a, size_t lda)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		// Function template packt_tiny
		template <class T>
		inline void packt_tiny(T* b, size_t ldb, const T* a, size_t lda, size_t m, size_t n)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		// Function template impl_pack
		template <class T>
		inline void impl_pack(T* b, size_t ldb, const T* a, size_t lda, size_t m, size_t n, bool transpose = false)
		{
			return (transpose ? impl_packt(b, ldb, a, lda, m, n) : impl_packc(b, ldb, a, lda, m, n));
		}

		// Function template impl_packvc
		template <class T>
		void impl_packvc(T* b, size_t ldb, const T* a, size_t lda, size_t m, size_t n)
		{
			constexpr size_t block_m = packc_block_m<T>();
			constexpr size_t block_n = packc_block_n<T>();
			const size_t aligned_m = m & ~(block_m - 1);
			const size_t aligned_n = n & ~(block_n - 1);
			const size_t surplus_m = m - aligned_m;
			const size_t surplus_n = n - aligned_n;

			for (size_t i = 0; i < aligned_m; i += block_m)
			{
				const __m256 ymm_a0 = _mm256_loadu_ps(ptr_a0 + k);
				const __m256 ymm_a1 = _mm256_loadu_ps(ptr_a1 + k);
				const __m256 ymm_a2 = _mm256_loadu_ps(ptr_a2 + k);
				const __m256 ymm_a3 = _mm256_loadu_ps(ptr_a3 + k);
				const __m256 ymm_a4 = _mm256_loadu_ps(ptr_a4 + k);
				const __m256 ymm_a5 = _mm256_loadu_ps(ptr_a5 + k);
				const __m256 ymm_a6 = _mm256_loadu_ps(ptr_a6 + k);
				const __m256 ymm_a7 = _mm256_loadu_ps(ptr_a7 + k);
				_mm256_stream_ps(to, ymm_a0);
				_mm256_stream_ps(to + 8, ymm_a1);
				_mm256_stream_ps(to + 16, ymm_a2);
				_mm256_stream_ps(to + 24, ymm_a3);
				_mm256_stream_ps(to + 32, ymm_a4);
				_mm256_stream_ps(to + 40, ymm_a5);
				_mm256_stream_ps(to + 48, ymm_a6);
				_mm256_stream_ps(to + 56, ymm_a7);
				to += 64;
			}
			for (size_t k = 0; k < surplus_p; ++k)
			{
				to[0] = ptr_a0[k];
				to[8] = ptr_a1[k];
				to[16] = ptr_a2[k];
				to[24] = ptr_a3[k];
				to[32] = ptr_a4[k];
				to[40] = ptr_a5[k];
				to[48] = ptr_a6[k];
				to[56] = ptr_a7[k];
				to++;
			}


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

	} // namespace cpu

} // namespace core

#endif
