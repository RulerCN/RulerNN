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

#ifndef __CORE_CPU_SLICE_H__
#define __CORE_CPU_SLICE_H__

#include "slice/slice_cpyi8.h"
#include "slice/slice_cpyi16.h"
#include "slice/slice_cpyi32.h"
#include "slice/slice_cpyu8.h"
#include "slice/slice_cpyu16.h"
#include "slice/slice_cpyu32.h"
#include "slice/slice_cpyps.h"
#include "slice/slice_cpypd.h"
#include "slice/slice_trpi8.h"
#include "slice/slice_trpi16.h"
#include "slice/slice_trpi32.h"
#include "slice/slice_trpu8.h"
#include "slice/slice_trpu16.h"
#include "slice/slice_trpu32.h"
#include "slice/slice_trpps.h"
#include "slice/slice_trppd.h"


namespace core
{
	namespace cpu
	{

		// Function template slice_cpy_block_m
		template <class T>
		constexpr size_t slice_cpy_block_m(void)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		// Function template slice_cpy_block_n
		template <class T>
		constexpr size_t slice_cpy_block_n(void)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		// Function template slice_cpy_block
		template <class T>
		inline void slice_cpy_block(T* b, size_t ldb, const T* a, size_t lda)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		// Function template slice_cpy_panel
		template <class T>
		inline void slice_cpy_panel(T* b, size_t ldb, const T* a, size_t lda, size_t m)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		// Function template slice_cpy_tiny
		template <class T>
		inline void slice_cpy_tiny(T* b, size_t ldb, const T* a, size_t lda, size_t m, size_t n)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		// Function template slice_trp_block_m
		template <class T>
		constexpr size_t slice_trp_block_m(void)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		// Function template slice_trp_block_n
		template <class T>
		constexpr size_t slice_trp_block_n(void)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		// Function template slice_trp_block
		template <class T>
		inline void slice_trp_block(T* b, size_t ldb, const T* a, size_t lda)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		// Function template slice_trp_panel
		template <class T>
		inline void slice_trp_panel(T* b, size_t ldb, const T* a, size_t lda, size_t m)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		// Function template slice_trp_tiny
		template <class T>
		inline void slice_trp_tiny(T* b, size_t ldb, const T* a, size_t lda, size_t m, size_t n)
		{
			throw std::domain_error(UNIMPLEMENTED_FUNCTION);
		}

		// Function template impl_slice
		template <class T>
		void impl_slice(T* b, size_t ldb, const T* a, size_t lda, size_t m, size_t n, size_t rows, size_t cols)
		{
			return (transpose ?
				impl_slice_trp(b, ldb, a, lda, m, n, rows, cols) :
				impl_slice_cpy(b, ldb, a, lda, m, n, rows, cols));
		}

		// Function template impl_slice_cpy
		template <class T>
		void impl_slice_cpy(T* b, size_t ldb, const T* a, size_t lda, size_t m, size_t n, size_t rows, size_t cols)
		{
			constexpr size_t block_m = slice_cpy_block_m<T>();
			constexpr size_t block_n = slice_cpy_block_n<T>();
			const size_t block_lda = block_m * lda;
			const size_t block_ldb = block_m * ldb;
			const size_t aligned_m = rows & ~(block_m - 1);
			const size_t surplus_m = rows - aligned_m;
			const size_t aligned_n = cols & ~(block_n - 1);
			const size_t surplus_n = cols - aligned_n;

			a += m * lda + n;
			for (size_t i = 0; i < aligned_m; i += block_m)
			{
				for (size_t j = 0; j < aligned_n; j += block_n)
					slice_cpy_block(b + j, ldb, a + j, lda);
				if (surplus_n > 0)
					slice_cpy_tiny(b + aligned_n, ldb, a + aligned_n, lda, block_m, surplus_n);
				a += block_lda;
				b += block_ldb;
			}
			if (surplus_m > 0)
			{
				for (size_t j = 0; j < aligned_n; j += block_n)
					slice_cpy_panel(b + j, ldb, a + j, lda, surplus_m);
				if (surplus_n > 0)
					slice_cpy_tiny(b + aligned_n, ldb, a + aligned_n, lda, surplus_m, surplus_n);
			}
		}

		// Function template impl_slice_trp
		template <class T>
		void impl_slice_trp(T* b, size_t ldb, const T* a, size_t lda, size_t m, size_t n, size_t rows, size_t cols)
		{
			constexpr size_t block_m = slice_trp_block_m<T>();
			constexpr size_t block_n = slice_trp_block_n<T>();
			const size_t block_lda = block_m * lda;
			const size_t block_ldb = block_m * ldb;
			const size_t aligned_m = rows & ~(block_m - 1);
			const size_t surplus_m = rows - aligned_m;
			const size_t aligned_n = cols & ~(block_n - 1);
			const size_t surplus_n = cols - aligned_n;

			a += m * lda + n;
			for (size_t i = 0; i < aligned_m; i += block_m)
			{
				for (size_t j = 0; j < aligned_n; j += block_n)
					slice_trp_block(b + j, ldb, a + j, lda);
				if (surplus_n > 0)
					slice_trp_tiny(b + aligned_n, ldb, a + aligned_n, lda, block_m, surplus_n);
				a += block_lda;
				b += block_ldb;
			}
			if (surplus_m > 0)
			{
				for (size_t j = 0; j < aligned_n; j += block_n)
					slice_trp_panel(b + j, ldb, a + j, lda, surplus_m);
				if (surplus_n > 0)
					slice_trp_tiny(b + aligned_n, ldb, a + aligned_n, lda, surplus_m, surplus_n);
			}
		}

	} // namespace cpu

} // namespace core

#endif
