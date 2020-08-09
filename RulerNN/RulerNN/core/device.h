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

#ifndef __CORE_COMM_H__
#define __CORE_COMM_H__

#include <chrono>
#include <string>
#include "scalar.h"
#include "vector.h"
#include "matrix.h"
#include "tensor.h"
#include "comm/cvt.h"
#include "comm/trp.h"
#include "comm/gemm.h"

namespace core
{
	class device
	{
	public:
		// types:

		using system_clock      = std::chrono::system_clock;
		using steady_clock      = std::chrono::steady_clock;
		using system_time_point = std::chrono::time_point<system_clock>;
		using steady_time_point = std::chrono::time_point<steady_clock>;
		using microseconds      = std::chrono::microseconds;
		using milliseconds      = std::chrono::milliseconds;

		// construct/copy/destroy:

		device(void)
			: _type("unknown")
			, _count(0)
			, _number(0)
		{}
		device(const std::string& type, size_t count = 1, size_t number = 0)
			: _type(type)
			, _count(count)
			, _number(number)
		{}
		virtual ~device(void)
		{}

		// attribute:

		const std::string& type(void) const noexcept
		{
			return _type;
		}

		size_t size(void) const noexcept
		{
			return _count;
		}

		size_t number(void) const noexcept
		{
			return _number;
		}

		// Converts data type with truncation.

		template <class T, class U, class A1, class A2>
		scalar<T, A1> cvt(scalar<T, A1>& dst, const scalar<U, A1>& src)
		{
			if (src.empty() || dst.empty())
				throw std::domain_error(SCALAR_NOT_INITIALIZED);
			if (src.size() != dst.size())
				throw std::invalid_argument(INVALID_SIZE);
			comm::impl_cvt(dst.data(), src.data(), src.size());
			return dst;
		}

		template <class T, class U, class A1, class A2>
		vector<T, A1> cvt(vector<T, A1>& dst, const vector<U, A1>& src)
		{
			if (src.empty() || dst.empty())
				throw std::domain_error(VECTOR_NOT_INITIALIZED);
			if (src.size() != dst.size())
				throw std::invalid_argument(INVALID_SIZE);
			comm::impl_cvt(dst.data(), src.data(), src.size());
			return dst;
		}

		template <class T, class U, class A1, class A2>
		matrix<T, A1>& cvt(matrix<T, A1>& dst, const matrix<U, A2>& src)
		{
			if (src.empty() || dst.empty())
				throw std::domain_error(MATRIX_NOT_INITIALIZED);
			if (src.size() != dst.size())
				throw std::invalid_argument(INVALID_SIZE);
			comm::impl_cvt(dst.data(), src.data(), src.size());
			return dst;
		}

		template <class T, class U, class A1, class A2>
		tensor<T, A1>& cvt(tensor<T, A1>& dst, const tensor<U, A2>& src)
		{
			if (src.empty() || dst.empty())
				throw std::domain_error(TENSOR_NOT_INITIALIZED);
			if (src.size() != dst.size())
				throw std::invalid_argument(INVALID_SIZE);
			comm::impl_cvt(dst.data(), src.data(), src.size());
			return dst;
		}

		template <class T, class U, class A>
		scalar<T, typename A::template rebind<T>::other> cvt(const scalar<U, A>& src)
		{
			if (src.empty())
				throw std::domain_error(SCALAR_NOT_INITIALIZED);
			using Allocator = typename A::template rebind<T>::other;
			scalar<T, Allocator> dst(src.dim());
			comm::impl_cvt(dst.data(), src.data(), src.size());
			return dst;
		}

		template <class T, class U, class A>
		vector<T, typename A::template rebind<T>::other> cvt(const vector<U, A>& src)
		{
			if (src.empty())
				throw std::domain_error(VECTOR_NOT_INITIALIZED);
			using Allocator = typename A::template rebind<T>::other;
			vector<T, Allocator> dst(src.len(), src.dim());
			comm::impl_cvt(dst.data(), src.data(), src.size());
			return dst;
		}

		template <class T, class U, class A>
		matrix<T, typename A::template rebind<T>::other> cvt(const matrix<U, A>& src)
		{
			if (src.empty())
				throw std::domain_error(MATRIX_NOT_INITIALIZED);
			using Allocator = typename A::template rebind<T>::other;
			matrix<T, Allocator> dst(src.rows(), src.cols(), src.dim());
			comm::impl_cvt(dst.data(), src.data(), src.size());
			return dst;
		}

		template <class T, class U, class A>
		tensor<T, typename A::template rebind<T>::other> cvt(const tensor<U, A>& src)
		{
			if (src.empty())
				throw std::domain_error(TENSOR_NOT_INITIALIZED);
			using Allocator = typename A::template rebind<T>::other;
			tensor<T, Allocator> dst(src.num(), src.rows(), src.cols(), src.dim());
			comm::impl_cvt(dst.data(), src.data(), src.size());
			return dst;
		}

		// Converts data type with saturation.

		template <class T, class U, class A1, class A2>
		scalar<T, A1> cvts(scalar<T, A1>& dst, const scalar<U, A1>& src)
		{
			if (src.empty() || dst.empty())
				throw std::domain_error(SCALAR_NOT_INITIALIZED);
			if (src.size() != dst.size())
				throw std::invalid_argument(INVALID_SIZE);
			comm::impl_cvts(dst.data(), src.data(), src.size());
			return dst;
		}

		template <class T, class U, class A1, class A2>
		vector<T, A1> cvts(vector<T, A1>& dst, const vector<U, A1>& src)
		{
			if (src.empty() || dst.empty())
				throw std::domain_error(VECTOR_NOT_INITIALIZED);
			if (src.size() != dst.size())
				throw std::invalid_argument(INVALID_SIZE);
			comm::impl_cvts(dst.data(), src.data(), src.size());
			return dst;
		}

		template <class T, class U, class A1, class A2>
		matrix<T, A1>& cvts(matrix<T, A1>& dst, const matrix<U, A2>& src)
		{
			if (src.empty() || dst.empty())
				throw std::domain_error(MATRIX_NOT_INITIALIZED);
			if (src.size() != dst.size())
				throw std::invalid_argument(INVALID_SIZE);
			comm::impl_cvts(dst.data(), src.data(), src.size());
			return dst;
		}

		template <class T, class U, class A1, class A2>
		tensor<T, A1>& cvts(tensor<T, A1>& dst, const tensor<U, A2>& src)
		{
			if (src.empty() || dst.empty())
				throw std::domain_error(TENSOR_NOT_INITIALIZED);
			if (src.size() != dst.size())
				throw std::invalid_argument(INVALID_SIZE);
			comm::impl_cvts(dst.data(), src.data(), src.size());
			return dst;
		}

		template <class T, class U, class A>
		scalar<T, typename A::template rebind<T>::other> cvts(const scalar<U, A>& src)
		{
			if (src.empty())
				throw std::domain_error(SCALAR_NOT_INITIALIZED);
			using Allocator = typename A::template rebind<T>::other;
			scalar<T, Allocator> dst(src.dim());
			comm::impl_cvts(dst.data(), src.data(), src.size());
			return dst;
		}

		template <class T, class U, class A>
		vector<T, typename A::template rebind<T>::other> cvts(const vector<U, A>& src)
		{
			if (src.empty())
				throw std::domain_error(VECTOR_NOT_INITIALIZED);
			using Allocator = typename A::template rebind<T>::other;
			vector<T, Allocator> dst(src.len(), src.dim());
			comm::impl_cvts(dst.data(), src.data(), src.size());
			return dst;
		}

		template <class T, class U, class A>
		matrix<T, typename A::template rebind<T>::other> cvts(const matrix<U, A>& src)
		{
			if (src.empty())
				throw std::domain_error(MATRIX_NOT_INITIALIZED);
			using Allocator = typename A::template rebind<T>::other;
			matrix<T, Allocator> dst(src.rows(), src.cols(), src.dim());
			comm::impl_cvts(dst.data(), src.data(), src.size());
			return dst;
		}

		template <class T, class U, class A>
		tensor<T, typename A::template rebind<T>::other> cvts(const tensor<U, A>& src)
		{
			if (src.empty())
				throw std::domain_error(TENSOR_NOT_INITIALIZED);
			using Allocator = typename A::template rebind<T>::other;
			tensor<T, Allocator> dst(src.num(), src.rows(), src.cols(), src.dim());
			comm::impl_cvts(dst.data(), src.data(), src.size());
			return dst;
		}

		// Matrix transposition.

		template <class T, class A>
		matrix<T, A>& trp(matrix<T, A>& dst, const matrix<T, A>& src)
		{
			if (src.empty() || dst.empty())
				throw std::domain_error(MATRIX_NOT_INITIALIZED);
			if (src.rows() != dst.line() || src.line() != dst.rows())
				throw std::invalid_argument(INVALID_SHAPE);
			comm::impl_trp(dst.data(), dst.line(), src.data(), src.line(), src.rows(), src.line());
			return dst;
		}

		template <class T, class A>
		tensor<T, A>& trp(tensor<T, A>& dst, const tensor<T, A>& src)
		{
			if (src.empty() || dst.empty())
				throw std::domain_error(TENSOR_NOT_INITIALIZED);
			if (src.num() != dst.num() || src.rows() != dst.line() || src.line() != dst.rows())
				throw std::invalid_argument(INVALID_SHAPE);
			auto itr_src = src.mbegin();
			auto itr_dst = dst.mbegin();
			while (itr_src != src.mend() && itr_dst != dst.mend())
			{
				comm::impl_trp(itr_dst->data(), itr_dst->line(), itr_src->data(), itr_src->line(), itr_src->rows(), itr_src->line());
				++itr_src;
				++itr_dst;
			}
			return dst;
		}

		template <class T, class A>
		matrix<T, A> trp(const matrix<T, A>& src)
		{
			if (src.empty())
				throw std::domain_error(MATRIX_NOT_INITIALIZED);
			matrix<T, A> dst(src.line(), src.rows(), static_cast<size_t>(1));
			comm::impl_trp(dst.data(), dst.line(), src.data(), src.line(), src.rows(), src.line());
			return dst;
		}

		template <class T, class A>
		tensor<T, T> trp(const tensor<T, A>& src)
		{
			if (src.empty())
				throw std::domain_error(TENSOR_NOT_INITIALIZED);
			tensor<T, A> dst(src.num(), src.line(), src.rows(), static_cast<size_t>(1));
			auto itr_src = src.mbegin();
			auto itr_dst = dst.mbegin();
			while (itr_src != src.mend() && itr_dst != dst.mend())
			{
				comm::impl_trp(itr_dst->data(), itr_dst->line(), itr_src->data(), itr_src->line(), itr_src->rows(), itr_src->line());
				++itr_src;
				++itr_dst;
			}
			return dst;
		}

		// General matrix multiplication.

		template <class T, class A>
		matrix<T, A>& gemm(matrix<T, A>& c, const matrix<T, A>& a, const matrix<T, A>& b)
		{
			if (a.empty() || b.empty() || c.empty())
				throw std::domain_error(MATRIX_NOT_INITIALIZED);
			if (c.rows() != a.rows() || c.line() != b.line() || a.line() != b.rows())
				throw std::invalid_argument(INVALID_SHAPE);
			comm::impl_gemm(c.data(), c.line(), a.data(), a.line(), b.data(), b.line(), a.rows(), a.line(), b.line());
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
				comm::impl_gemm(itr_c->data(), itr_c->line(), itr_a->data(), itr_a->line(), itr_b->data(), itr_b->line(), itr_a->rows(), itr_a->line(), itr_b->line());
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
			matrix<T, A> c(a.rows(), b.line(), static_cast<size_t>(1));
			comm::impl_gemm(c.data(), c.line(), a.data(), a.line(), b.data(), b.line(), a.rows(), a.line(), b.line());
			return c;
		}

		template <class T, class A>
		tensor<T, A> gemm(const tensor<T, A>& a, const tensor<T, A>& b)
		{
			if (a.empty() || b.empty())
				throw std::domain_error(TENSOR_NOT_INITIALIZED);
			if (a.num() != b.num() || a.line() != b.rows())
				throw std::invalid_argument(INVALID_SHAPE);
			tensor<T, A> c(a.num(), a.rows(), b.line(), static_cast<size_t>(1));
			auto itr_a = a.mbegin();
			auto itr_b = b.mbegin();
			auto itr_c = c.mbegin();
			while (itr_a != a.mend() && itr_b != b.mend() && itr_c != c.mend())
			{
				comm::impl_gemm(itr_c->data(), itr_c->line(), itr_a->data(), itr_a->line(), itr_b->data(), itr_b->line(), itr_a->rows(), itr_a->line(), itr_b->line());
				++itr_a;
				++itr_b;
				++itr_c;
			}
			return c;
		}

		// static functions:

		static system_time_point system_time(void) noexcept
		{
			return system_clock::now();
		}

		static steady_time_point steady_time(void) noexcept
		{
			return steady_clock::now();
		}

		template <class T>
		static long long get_microseconds(const T& start, const T& end)
		{
			return std::chrono::duration_cast<microseconds>(end - start).count();
		}

		template <class T>
		static long long get_milliseconds(const T& start, const T& end)
		{
			return std::chrono::duration_cast<milliseconds>(end - start).count();
		}
	private:
		std::string _type;
		size_t      _count;
		size_t      _number;
	};

} // namespace core

#endif
