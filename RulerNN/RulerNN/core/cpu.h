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

#ifndef __CORE_CPU_H__
#define __CORE_CPU_H__

#ifdef __AVX2__
//	#defined __AVX2__
#elif defined ( __AVX__ )
//	#defined __AVX__
#elif (defined(_M_AMD64) || defined(_M_X64))
	#define __SSE2__
#elif _M_IX86_FP == 2
	#define __SSE2__
#elif _M_IX86_FP == 1
	#define __SSE__
#endif

#include "device.h"
#include "cpu/simd.h"
#include "cpu/cvt.h"
#include "cpu/trp.h"
#include "cpu/trp.h"
#include "cpu/slice.h"
#include "cpu/zig.h"
#include "cpu/gemm.h"

namespace core
{
	// Class device_cpu
	class device_cpu : public device
	{
	public:
		// types:

		// construct/copy/destroy:

		device_cpu(void)
			: device("cpu")
		{
		#ifdef __AVX2__
			if ((simd::simd_inst & CPU_INST_AVX2) != CPU_INST_AVX2)
				throw std::domain_error(NO_SUPPORT_AVX2);
		#elif defined __AVX__
			if ((simd::simd_inst & CPU_INST_AVX) != CPU_INST_AVX)
				throw std::domain_error(NO_SUPPORT_AVX);
		#elif defined __SSE4_2__
			if ((simd::simd_inst & CPU_INST_SSE42) != CPU_INST_SSE42)
				throw std::domain_error(NO_SUPPORT_SSE42);
		#elif defined __SSE4_1__
			if ((simd::simd_inst & CPU_INST_SSE41) != CPU_INST_SSE41)
				throw std::domain_error(NO_SUPPORT_SSE41);
		#elif defined __SSSE3__
			if ((simd::simd_inst & CPU_INST_SSSE3) != CPU_INST_SSSE3)
				throw std::domain_error(NO_SUPPORT_SSSE3);
		#elif defined __SSE3__
			if ((simd::simd_inst & CPU_INST_SSE3) != CPU_INST_SSE3)
				throw std::domain_error(NO_SUPPORT_SSE3);
		#elif defined __SSE2__
			if ((simd::simd_inst & CPU_INST_SSE2) != CPU_INST_SSE2)
				throw std::domain_error(NO_SUPPORT_SSE2);
		#elif defined __SSE__
			if ((simd::simd_inst & CPU_INST_SSE) != CPU_INST_SSE)
				throw std::domain_error(NO_SUPPORT_SSE);
		#endif
		}
		~device_cpu(void)
		{}

		// Converts data type with truncation.

		template <class T, class U, class A1, class A2>
		scalar<T, A1> cvt(scalar<T, A1>& b, const scalar<U, A1>& a)
		{
			if (a.empty() || b.empty())
				throw std::domain_error(SCALAR_NOT_INITIALIZED);
			if (a.size() != b.size())
				throw std::invalid_argument(INVALID_SIZE);
			cpu::impl_cvt(b.data(), a.data(), a.size());
			return b;
		}

		template <class T, class U, class A1, class A2>
		vector<T, A1> cvt(vector<T, A1>& b, const vector<U, A1>& a)
		{
			if (a.empty() || b.empty())
				throw std::domain_error(VECTOR_NOT_INITIALIZED);
			if (a.size() != b.size())
				throw std::invalid_argument(INVALID_SIZE);
			cpu::impl_cvt(b.data(), a.data(), a.size());
			return b;
		}

		template <class T, class U, class A1, class A2>
		matrix<T, A1>& cvt(matrix<T, A1>& b, const matrix<U, A2>& a)
		{
			if (a.empty() || b.empty())
				throw std::domain_error(MATRIX_NOT_INITIALIZED);
			if (a.size() != b.size())
				throw std::invalid_argument(INVALID_SIZE);
			cpu::impl_cvt(b.data(), a.data(), a.size());
			return b;
		}

		template <class T, class U, class A1, class A2>
		tensor<T, A1>& cvt(tensor<T, A1>& b, const tensor<U, A2>& a)
		{
			if (a.empty() || b.empty())
				throw std::domain_error(TENSOR_NOT_INITIALIZED);
			if (a.size() != b.size())
				throw std::invalid_argument(INVALID_SIZE);
			cpu::impl_cvt(b.data(), a.data(), a.size());
			return b;
		}

		template <class T, class U, class A>
		scalar<T, typename A::template rebind<T>::other> cvt(const scalar<U, A>& a)
		{
			if (a.empty())
				throw std::domain_error(SCALAR_NOT_INITIALIZED);
			using Allocator = typename A::template rebind<T>::other;
			scalar<T, Allocator> b(a.dim());
			cpu::impl_cvt(b.data(), a.data(), a.size());
			return b;
		}

		template <class T, class U, class A>
		vector<T, typename A::template rebind<T>::other> cvt(const vector<U, A>& a)
		{
			if (a.empty())
				throw std::domain_error(VECTOR_NOT_INITIALIZED);
			using Allocator = typename A::template rebind<T>::other;
			vector<T, Allocator> b(a.len(), a.dim());
			cpu::impl_cvt(b.data(), a.data(), a.size());
			return b;
		}

		template <class T, class U, class A>
		matrix<T, typename A::template rebind<T>::other> cvt(const matrix<U, A>& a)
		{
			if (a.empty())
				throw std::domain_error(MATRIX_NOT_INITIALIZED);
			using Allocator = typename A::template rebind<T>::other;
			matrix<T, Allocator> b(a.rows(), a.cols(), a.dim());
			cpu::impl_cvt(b.data(), a.data(), a.size());
			return b;
		}

		template <class T, class U, class A>
		tensor<T, typename A::template rebind<T>::other> cvt(const tensor<U, A>& a)
		{
			if (a.empty())
				throw std::domain_error(TENSOR_NOT_INITIALIZED);
			using Allocator = typename A::template rebind<T>::other;
			tensor<T, Allocator> b(a.num(), a.rows(), a.cols(), a.dim());
			cpu::impl_cvt(b.data(), a.data(), a.size());
			return b;
		}

		// Converts data type with saturation.

		template <class T, class U, class A1, class A2>
		scalar<T, A1> cvts(scalar<T, A1>& b, const scalar<U, A1>& a)
		{
			if (a.empty() || b.empty())
				throw std::domain_error(SCALAR_NOT_INITIALIZED);
			if (a.size() != b.size())
				throw std::invalid_argument(INVALID_SIZE);
			cpu::impl_cvts(b.data(), a.data(), a.size());
			return b;
		}

		template <class T, class U, class A1, class A2>
		vector<T, A1> cvts(vector<T, A1>& b, const vector<U, A1>& a)
		{
			if (a.empty() || b.empty())
				throw std::domain_error(VECTOR_NOT_INITIALIZED);
			if (a.size() != b.size())
				throw std::invalid_argument(INVALID_SIZE);
			cpu::impl_cvts(b.data(), a.data(), a.size());
			return b;
		}

		template <class T, class U, class A1, class A2>
		matrix<T, A1>& cvts(matrix<T, A1>& b, const matrix<U, A2>& a)
		{
			if (a.empty() || b.empty())
				throw std::domain_error(MATRIX_NOT_INITIALIZED);
			if (a.size() != b.size())
				throw std::invalid_argument(INVALID_SIZE);
			cpu::impl_cvts(b.data(), a.data(), a.size());
			return b;
		}

		template <class T, class U, class A1, class A2>
		tensor<T, A1>& cvts(tensor<T, A1>& b, const tensor<U, A2>& a)
		{
			if (a.empty() || b.empty())
				throw std::domain_error(TENSOR_NOT_INITIALIZED);
			if (a.size() != b.size())
				throw std::invalid_argument(INVALID_SIZE);
			cpu::impl_cvts(b.data(), a.data(), a.size());
			return b;
		}

		template <class T, class U, class A>
		scalar<T, typename A::template rebind<T>::other> cvts(const scalar<U, A>& a)
		{
			if (a.empty())
				throw std::domain_error(SCALAR_NOT_INITIALIZED);
			using Allocator = typename A::template rebind<T>::other;
			scalar<T, Allocator> b(a.dim());
			cpu::impl_cvts(b.data(), a.data(), a.size());
			return b;
		}

		template <class T, class U, class A>
		vector<T, typename A::template rebind<T>::other> cvts(const vector<U, A>& a)
		{
			if (a.empty())
				throw std::domain_error(VECTOR_NOT_INITIALIZED);
			using Allocator = typename A::template rebind<T>::other;
			vector<T, Allocator> b(a.len(), a.dim());
			cpu::impl_cvts(b.data(), a.data(), a.size());
			return b;
		}

		template <class T, class U, class A>
		matrix<T, typename A::template rebind<T>::other> cvts(const matrix<U, A>& a)
		{
			if (a.empty())
				throw std::domain_error(MATRIX_NOT_INITIALIZED);
			using Allocator = typename A::template rebind<T>::other;
			matrix<T, Allocator> b(a.rows(), a.cols(), a.dim());
			cpu::impl_cvts(b.data(), a.data(), a.size());
			return b;
		}

		template <class T, class U, class A>
		tensor<T, typename A::template rebind<T>::other> cvts(const tensor<U, A>& a)
		{
			if (a.empty())
				throw std::domain_error(TENSOR_NOT_INITIALIZED);
			using Allocator = typename A::template rebind<T>::other;
			tensor<T, Allocator> b(a.num(), a.rows(), a.cols(), a.dim());
			cpu::impl_cvts(b.data(), a.data(), a.size());
			return b;
		}

		// Matrix Transpose.

		template <class T, class A>
		matrix<T, A>& trp(matrix<T, A>& b, const matrix<T, A>& a)
		{
			if (a.empty() || b.empty())
				throw std::domain_error(MATRIX_NOT_INITIALIZED);
			if (a.rows() != b.line() || a.line() != b.rows())
				throw std::invalid_argument(INVALID_SHAPE);
			cpu::impl_trp(b.data(), b.line(), a.data(), a.line(), a.rows(), a.line());
			return b;
		}

		template <class T, class A>
		tensor<T, A>& trp(tensor<T, A>& b, const tensor<T, A>& a)
		{
			if (a.empty() || b.empty())
				throw std::domain_error(TENSOR_NOT_INITIALIZED);
			if (a.num() != b.num() || a.rows() != b.line() || a.line() != b.rows())
				throw std::invalid_argument(INVALID_SHAPE);
			auto a_itr = a.mbegin();
			auto b_itr = b.mbegin();
			while (a_itr != a.mend() && b_itr != b.mend())
			{
				cpu::impl_trp(b_itr->data(), b_itr->line(), a_itr->data(), a_itr->line(), a_itr->rows(), a_itr->line());
				++a_itr;
				++b_itr;
			}
			return b;
		}

		template <class T, class A>
		matrix<T, typename A::template rebind<T>::other> trp(const matrix<T, A>& a)
		{
			if (a.empty())
				throw std::domain_error(MATRIX_NOT_INITIALIZED);
			matrix<T, A> b(a.line(), a.rows(), static_cast<size_t>(1));
			cpu::impl_trp(b.data(), b.line(), a.data(), a.line(), a.rows(), a.line());
			return b;
		}

		template <class T, class A>
		tensor<T, typename A::template rebind<T>::other> trp(const tensor<T, A>& a)
		{
			if (a.empty())
				throw std::domain_error(TENSOR_NOT_INITIALIZED);
			tensor<T, A> b(a.num(), a.line(), a.rows(), static_cast<size_t>(1));
			auto a_itr = a.mbegin();
			auto b_itr = b.mbegin();
			while (a_itr != a.mend() && b_itr != b.mend())
			{
				cpu::impl_trp(b_itr->data(), b_itr->line(), a_itr->data(), a_itr->line(), a_itr->rows(), a_itr->line());
				++a_itr;
				++b_itr;
			}
			return b;
		}

		// General matrix multiplication.

		template <class T, class A>
		matrix<T, A>& gemm(matrix<T, A>& c, const matrix<T, A>& a, const matrix<T, A>& b)
		{
			if (a.empty() || b.empty() || c.empty())
				throw std::domain_error(MATRIX_NOT_INITIALIZED);
			if (c.rows() != a.rows() || c.line() != b.line() || a.line() != b.rows())
				throw std::invalid_argument(INVALID_SHAPE);
			cpu::impl_gemm(c.data(), c.line(), a.data(), a.line(), b.data(), b.line(), a.rows(), a.line(), b.line());
			return c;
		}

		template <class T, class A>
		tensor<T, A>& gemm(tensor<T, A>& c, const tensor<T, A>& a, const tensor<T, A>& b)
		{
			if (a.empty() || b.empty() || c.empty())
				throw std::domain_error(TENSOR_NOT_INITIALIZED);
			if (c.num() != a.num() || c.num() != b.num() || c.rows() != a.rows() || c.line() != b.line() || a.line() != b.rows())
				throw std::invalid_argument(INVALID_SHAPE);
			auto itr_a = a.mbegin();
			auto itr_b = b.mbegin();
			auto itr_c = c.mbegin();
			while (itr_a != a.mend() && itr_b != b.mend() && itr_c != c.mend())
			{
				cpu::impl_gemm(itr_c->data(), itr_c->line(), itr_a->data(), itr_a->line(), itr_b->data(), itr_b->line(), itr_a->rows(), itr_a->line(), itr_b->line());
				++itr_a;
				++itr_b;
				++itr_c;
			}
			return c;
		}

		template <class T, class A>
		matrix<T, A> gemm(const matrix<T, A>& a, const matrix<T, A>& b)
		{
			if (a.empty() || b.empty())
				throw std::domain_error(MATRIX_NOT_INITIALIZED);
			if (a.line() != b.rows())
				throw std::invalid_argument(INVALID_SHAPE);
			matrix<T, A> c(a.rows(), b.line(), static_cast<size_t>(1), 0);
			cpu::impl_gemm(c.data(), c.line(), a.data(), a.line(), b.data(), b.line(), a.rows(), a.line(), b.line());
			return c;
		}

		template <class T, class A>
		tensor<T, A> gemm(const tensor<T, A>& a, const tensor<T, A>& b)
		{
			if (a.empty() || b.empty())
				throw std::domain_error(TENSOR_NOT_INITIALIZED);
			if (a.num() != b.num() || a.line() != b.rows())
				throw std::invalid_argument(INVALID_SHAPE);
			tensor<T, A> c(a.num(), a.rows(), b.line(), static_cast<size_t>(1), 0);
			auto itr_a = a.mbegin();
			auto itr_b = b.mbegin();
			auto itr_c = c.mbegin();
			while (itr_a != a.mend() && itr_b != b.mend() && itr_c != c.mend())
			{
				cpu::impl_gemm(itr_c->data(), itr_c->line(), itr_a->data(), itr_a->line(), itr_b->data(), itr_b->line(), itr_a->rows(), itr_a->line(), itr_b->line());
				++itr_a;
				++itr_b;
				++itr_c;
			}
			return c;
		}

	};

} // namespace core

#endif
