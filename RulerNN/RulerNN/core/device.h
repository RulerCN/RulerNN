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

		// Converts data type.

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
