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

namespace core
{
	namespace comm
	{
		// Function template trp_block

		template <class T>
		void trp_block(T* dst, size_t dst_rs, const T* src, size_t src_rs, size_t n)
		{
			constexpr size_t block = 4;
			const size_t dst_step = block * dst_rs;
			const T* ptr_src0 = src;
			const T* ptr_src1 = ptr_src0 + src_rs;
			const T* ptr_src2 = ptr_src1 + src_rs;
			const T* ptr_src3 = ptr_src2 + src_rs;
			T* ptr_dst0 = dst;
			T* ptr_dst1 = ptr_dst0 + dst_rs;
			T* ptr_dst2 = ptr_dst1 + dst_rs;
			T* ptr_dst3 = ptr_dst2 + dst_rs;

			for (; n >= block; n -= block)
			{
				ptr_dst0[0] = ptr_src0[0];
				ptr_dst1[0] = ptr_src0[1];
				ptr_dst2[0] = ptr_src0[2];
				ptr_dst3[0] = ptr_src0[3];
				ptr_dst0[1] = ptr_src1[0];
				ptr_dst1[1] = ptr_src1[1];
				ptr_dst2[1] = ptr_src1[2];
				ptr_dst3[1] = ptr_src1[3];
				ptr_dst0[2] = ptr_src2[0];
				ptr_dst1[2] = ptr_src2[1];
				ptr_dst2[2] = ptr_src2[2];
				ptr_dst3[2] = ptr_src2[3];
				ptr_dst0[3] = ptr_src3[0];
				ptr_dst1[3] = ptr_src3[1];
				ptr_dst2[3] = ptr_src3[2];
				ptr_dst3[3] = ptr_src3[3];
				ptr_src0 += block;
				ptr_src1 += block;
				ptr_src2 += block;
				ptr_src3 += block;
				ptr_dst0 += dst_step;
				ptr_dst1 += dst_step;
				ptr_dst2 += dst_step;
				ptr_dst3 += dst_step;
			}
			for (size_t i = 0; i < n; ++i)
			{
				ptr_dst0[0] = ptr_src0[i];
				ptr_dst0[1] = ptr_src1[i];
				ptr_dst0[2] = ptr_src2[i];
				ptr_dst0[3] = ptr_src3[i];
				ptr_dst0 += dst_rs;
			}
		}

		// Function template trp_line

		template <class T>
		inline void trp_line(T* dst, size_t dst_rs, const T* src, size_t src_rs, size_t n)
		{
			for (size_t i = 0; i < n; ++i)
			{
				*dst = src[i];
				dst += dst_rs;
			}
		}

		// Function template impl_trp

		template <class T>
		void impl_trp_(T* dst, size_t dst_rs, const T* src, size_t src_rs, size_t m, size_t n)
		{
			constexpr size_t block_m = 4;
			constexpr size_t block_n = 4;
			const size_t src_step = block_m * src_rs;

			for (; m >= block_m; m -= block_m)
			{
				trp_block(dst, dst_rs, src, src_rs, n);
				src += src_step;
				dst += block_m;
			}
			for (size_t i = 0; i < m; ++i)
			{
				trp_line(dst + i, dst_rs, src, src_rs, n);
				src += src_rs;
			}
		}

		template <class T>
		void impl_trp(T* dst, size_t dst_rs, const T* src, size_t src_rs, size_t m, size_t n)
		{
			constexpr size_t block_m = 4;
			constexpr size_t block_n = 4;
			size_t align_m = block_m;
			size_t align_n = block_n;

			if (m > block_m)
			{
				float tmp = static_cast<float>(m - 1);
				size_t exp = (*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFF;
				align_m = static_cast<size_t>(1) << (exp - 127);
			}
			if (n > block_n)
			{
				float tmp = static_cast<float>(n - 1);
				size_t exp = (*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFF;
				align_n = static_cast<size_t>(1) << (exp - 127);
			}
			if (m > align_m)
			{
				if (n > align_n)
				{
					impl_trp(dst, dst_rs, src, src_rs, align_m, align_n);
					impl_trp(dst + align_n * dst_rs, dst_rs, src + align_n, src_rs, align_m, n - align_n);
					impl_trp(dst + align_m, dst_rs, src + align_m * src_rs, src_rs, m - align_m, align_n);
					impl_trp(dst + align_n * dst_rs + align_m, dst_rs, src + align_m * src_rs + align_n, src_rs, m - align_m, n - align_n);
				}
				else if (n > 0)
				{
					impl_trp(dst, dst_rs, src, src_rs, align_m, n);
					impl_trp(dst + align_m, dst_rs, src + align_m * src_rs, src_rs, m - align_m, n);
				}
			}
			else
			{
				if (n > align_n)
				{
					impl_trp(dst, dst_rs, src, src_rs, m, align_n);
					impl_trp(dst + align_n * dst_rs, dst_rs, src + align_n, src_rs, m, n - align_n);
				}
				else
				{
					if (m == block_m && n == block_n)
						trp_block(dst, dst_rs, src, src_rs, block_n);
					//else
					//	for (size_t i = 0; i < m; ++i)
					//		trp_line(dst + i, dst_rs, src + i * src_rs, src_rs, n);
				}
			}
		}


	} // namespace comm

} // namespace core

#endif