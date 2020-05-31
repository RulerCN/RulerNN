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

#ifndef __CORE_VECTOR_H__
#define __CORE_VECTOR_H__

#include <memory>
#include <stdexcept>
#include "define.h"
#include "scalar.h"

#ifndef DEFAULT_ALLOCATOR
#define DEFAULT_ALLOCATOR(T) std::allocator<T>
#endif // !DEFAULT_ALLOCATOR

namespace core
{
	template <class T, class Allocator> class vector;

	// Specialize for void
	template <class Allocator>
	class vector<void, Allocator>
	{
	public:
		// types:

		using allocator_type        = Allocator;
		using allocator_traits_type = std::allocator_traits<allocator_type>;
		using value_type            = typename allocator_traits_type::value_type;
		using pointer               = typename allocator_traits_type::pointer;
		using const_pointer         = typename allocator_traits_type::const_pointer;
		using size_type             = typename allocator_traits_type::size_type;
		using difference_type       = typename allocator_traits_type::difference_type;

		template <class U>
		struct rebind
		{
			using other = vector<U, Allocator>;
		};
	};

	// Class template vector_type_traits

	template <class Vector, bool IsConst>
	struct vector_type_traits
	{
		using value_type      = typename Vector::value_type;
		using pointer         = typename Vector::pointer;
		using size_type       = typename Vector::size_type;
		using difference_type = typename Vector::difference_type;
		using reference       = value_type&;
	};

	template <class Vector>
	struct vector_type_traits<Vector, true>
	{
		using value_type      = typename Vector::value_type;
		using pointer         = typename Vector::const_pointer;
		using size_type       = typename Vector::size_type;
		using difference_type = typename Vector::difference_type;
		using reference       = const value_type&;
	};

	// Class template vector_iterator
	template <class Vector, bool IsConst>
	class vector_iterator
	{
	public:
		// types:

		using value_type        = typename vector_type_traits<Vector, IsConst>::value_type;
		using pointer           = typename vector_type_traits<Vector, IsConst>::pointer;
		using reference         = typename vector_type_traits<Vector, IsConst>::reference;
		using size_type         = typename vector_type_traits<Vector, IsConst>::size_type;
		using difference_type   = typename vector_type_traits<Vector, IsConst>::difference_type;

		using iterator_type     = vector_iterator<Vector, IsConst>;
		using iterator_category = std::bidirectional_iterator_tag;

		// construct/copy/destroy:

		vector_iterator(void) noexcept
			: step(0)
			, ptr(nullptr)
		{}
		explicit vector_iterator(pointer p, size_type stride) noexcept
			: step(stride)
			, ptr(p)
		{}
		vector_iterator(const vector_iterator<Vector, IsConst>& other) noexcept
			: step(other.step)
			, ptr(other.ptr)
		{}

		vector_iterator<Vector, IsConst>& operator=(const vector_iterator<Vector, IsConst>& other) noexcept
		{
			if (this != &other)
			{
				step = other.step;
				ptr = other.ptr;
			}
			return (*this);
		}

		operator vector_iterator<Vector, true>(void) const noexcept
		{
			return vector_iterator<Vector, true>(ptr, step);
		}

		// vector_iterator operations:

		reference operator[](size_type i) const noexcept
		{
			return static_cast<reference>(ptr[i]);
		}

		reference operator*(void) const noexcept
		{
			return static_cast<reference>(*ptr);
		}

		pointer operator->(void) const noexcept
		{
			return &(operator*());
		}

		size_type stride(void) const noexcept
		{
			return step;
		}

		// increment / decrement

		vector_iterator<Vector, IsConst>& operator++(void) noexcept
		{
			ptr += step;
			return *this;
		}
		vector_iterator<Vector, IsConst>& operator--(void) noexcept
		{
			ptr -= step;
			return *this;
		}
		vector_iterator<Vector, IsConst> operator++(int) noexcept
		{
			vector_iterator tmp(*this);
			++(*this);
			return tmp;
		}
		vector_iterator<Vector, IsConst> operator--(int) noexcept
		{
			vector_iterator tmp(*this);
			--(*this);
			return tmp;
		}
		vector_iterator<Vector, IsConst>& operator+=(difference_type n) noexcept
		{
			ptr += (n * step);
			return *this;
		}
		vector_iterator<Vector, IsConst>& operator-=(difference_type n) noexcept
		{
			ptr -= (n * step);
			return *this;
		}

		// relational operators:

		template <bool b>
		bool operator==(const vector_iterator<Vector, b>& rhs) const noexcept
		{
			return (ptr == rhs.operator->());
		}
		template <bool b>
		bool operator!=(const vector_iterator<Vector, b>& rhs) const noexcept
		{
			return (ptr != rhs.operator->());
		}
	private:
		size_type step;
		pointer   ptr;
	};

	// Class template vector
	template <class T, class Allocator = DEFAULT_ALLOCATOR(T)>
	class vector : public Allocator
	{
	public:
		// types:

		using allocator_type         = Allocator;
		using scalar_type            = core::scalar<T, Allocator>;
		using const_scalar_type      = const scalar_type;
		using allocator_traits_type  = std::allocator_traits<allocator_type>;
		using value_type             = typename allocator_traits_type::value_type;
		using pointer                = typename allocator_traits_type::pointer;
		using const_pointer          = typename allocator_traits_type::const_pointer;
		using size_type              = typename allocator_traits_type::size_type;
		using difference_type        = typename allocator_traits_type::difference_type;

		using iterator               = vector_iterator<vector<T, Allocator>, false>;
		using const_iterator         = vector_iterator<vector<T, Allocator>, true>;
		using reverse_iterator       = std::reverse_iterator<iterator>;
		using const_reverse_iterator = std::reverse_iterator<const_iterator>;

		template <class U>
		struct rebind
		{
			using other = vector<U, Allocator>;
		};

		// construct/copy/destroy:

		explicit vector(const Allocator& alloc = Allocator())
			: Allocator(alloc)
			, _owner(true)
			, _dim(0)
			, _len(0)
			, _count(0)
			, _data(nullptr)
		{}
		explicit vector(size_type len, size_type dim)
			: Allocator()
			, _owner(true)
			, _dim(0)
			, _len(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(len, dim);
		}
		vector(size_type len, size_type dim, const value_type& value, const Allocator& alloc = Allocator())
			: Allocator(alloc)
			, _owner(true)
			, _dim(0)
			, _len(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(len, dim, value);
		}
		vector(size_type len, size_type dim, const_pointer p, const Allocator& alloc = Allocator())
			: Allocator(alloc)
			, _owner(true)
			, _dim(0)
			, _len(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(len, dim, p);
		}
		vector(size_type len, size_type dim, pointer p, bool copy_data, const Allocator& alloc = Allocator())
			: Allocator(alloc)
			, _owner(true)
			, _dim(0)
			, _len(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(len, dim, p, copy_data);
		}
		template <class InputIterator>
		vector(size_type len, size_type dim, InputIterator first, InputIterator last, const Allocator& alloc = Allocator())
			: Allocator(alloc)
			, _owner(true)
			, _dim(0)
			, _len(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(len, dim, last, last);
		}
		vector(const vector<T, Allocator>& other)
			: Allocator(other.get_allocator())
			, _owner(true)
			, _dim(0)
			, _len(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(other, DEEP_COPY);
		}
		vector(vector<T, Allocator>& other, copy_mode_type copy_mode)
			: Allocator(other.get_allocator())
			, _owner(true)
			, _dim(0)
			, _len(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(other, copy_mode);
		}
		vector(vector<T, Allocator>&& other)
			: Allocator(other.get_allocator())
			, _owner(true)
			, _dim(0)
			, _len(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(std::forward<vector<T, Allocator> >(other));
		}
		vector(const vector<T, Allocator>& other, const Allocator& alloc, copy_mode_type copy_mode = DEEP_COPY)
			: Allocator(alloc)
			, _owner(true)
			, _dim(0)
			, _len(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(other, copy_mode);
		}
		vector(vector<T, Allocator>& other, const Allocator& alloc, copy_mode_type copy_mode = DEEP_COPY)
			: Allocator(alloc)
			, _owner(true)
			, _dim(0)
			, _len(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(other, copy_mode);
		}
		vector(vector<T, Allocator>&& other, const Allocator& alloc)
			: Allocator(alloc)
			, _owner(true)
			, _dim(0)
			, _len(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(std::forward<vector<T, Allocator> >(other));
		}
		vector(size_type len, size_type dim, std::initializer_list<T> il, const Allocator& alloc = Allocator())
			: Allocator(alloc)
			, _owner(true)
			, _dim(0)
			, _len(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(len, dim, il);
		}
		~vector(void)
		{
			clear();
		}
		vector<T, Allocator>& operator=(const vector<T, Allocator>& other)
		{
			if (this != &other)
			{
				clear();
				assign(other, DEEP_COPY);
			}
			return (*this);
		}
		vector<T, Allocator>& operator=(vector<T, Allocator>&& other)
		{
			if (this != &other)
				assign(std::forward<vector<T, Allocator> >(other));
			return (*this);
		}

		void assign(size_type len, size_type dim)
		{
			if (!empty())
				throw std::domain_error(VECTOR_IS_INITIALIZED);
			if (len == 0 || dim == 0)
				throw std::invalid_argument(INVALID_VECTOR_SIZE);
			_owner = true;
			_dim = dim;
			_len = len;
			_count = _len * _dim;
			_data = this->allocate(_count);
			std::uninitialized_default_construct_n(_data, _count);
		}

		void assign(size_type len, size_type dim, const value_type& value)
		{
			if (!empty())
				throw std::domain_error(VECTOR_IS_INITIALIZED);
			if (len == 0 || dim == 0)
				throw std::invalid_argument(INVALID_VECTOR_SIZE);
			_owner = true;
			_dim = dim;
			_len = len;
			_count = _len * _dim;
			_data = this->allocate(_count);
			std::uninitialized_fill_n(_data, _count, value);
		}

		void assign(size_type len, size_type dim, const_pointer p)
		{
			if (!empty())
				throw std::domain_error(VECTOR_IS_INITIALIZED);
			if (len == 0 || dim == 0)
				throw std::invalid_argument(INVALID_VECTOR_SIZE);
			_owner = true;
			_dim = dim;
			_len = len;
			_count = _len * _dim;
			_data = this->allocate(_count);
			std::uninitialized_copy(p, p + _count, _data);
		}

		void assign(size_type len, size_type dim, pointer p, bool copy_data)
		{
			if (!empty())
				throw std::domain_error(VECTOR_IS_INITIALIZED);
			if (len == 0 || dim == 0)
				throw std::invalid_argument(INVALID_VECTOR_SIZE);
			_owner = copy_data;
			_dim = dim;
			_len = len;
			_count = _len * _dim;
			if (copy_data)
			{
				_data = this->allocate(_count);
				std::uninitialized_copy(p, p + _count, _data);
			}
			else
				_data = p;
		}

		template <class InputIterator>
		void assign(size_type len, size_type dim, InputIterator first, InputIterator last)
		{
			if (!empty())
				throw std::domain_error(VECTOR_IS_INITIALIZED);
			if (len == 0 || dim == 0)
				throw std::invalid_argument(INVALID_VECTOR_SIZE);
			if (std::distance(first, last) != len * dim)
				throw std::invalid_argument(INVALID_INITIALIZER_LIST);
			_owner = true;
			_dim = dim;
			_len = len;
			_count = _len * _dim;
			_data = this->allocate(_count);
			std::uninitialized_copy(first, last, _data);
		}

		void assign(size_type len, size_type dim, std::initializer_list<T> il)
		{
			assign(len, dim, il.begin(), il.end());
		}

		void assign(const vector<T, Allocator>& other, copy_mode_type copy_mode)
		{
			if (!empty())
				throw std::domain_error(VECTOR_IS_INITIALIZED);
			if (other.empty())
				throw std::domain_error(VECTOR_NOT_INITIALIZED);
			if (copy_mode == SHALLOW_COPY)
				throw std::invalid_argument(INVALID_COPY_MODE);
			_owner = true;
			_dim = other._dim;
			_len = other._len;
			_count = other._count;
			switch (copy_mode)
			{
			case WITHOUT_COPY:
				_data = this->allocate(_count);
				std::uninitialized_default_construct_n(_data, _count);
				break;
			case DEEP_COPY:
				_data = this->allocate(_count);
				std::uninitialized_copy(other._data, other._data + _count, _data);
				break;
			}
		}

		void assign(vector<T, Allocator>& other, copy_mode_type copy_mode)
		{
			if (!empty())
				throw std::domain_error(VECTOR_IS_INITIALIZED);
			if (other.empty())
				throw std::domain_error(VECTOR_NOT_INITIALIZED);
			_dim = other._dim;
			_len = other._len;
			_count = other._count;
			switch (copy_mode)
			{
			case WITHOUT_COPY:
				_owner = true;
				_data = this->allocate(_count);
				std::uninitialized_default_construct_n(_data, _count);
				break;
			case SHALLOW_COPY:
				_owner = false;
				_data = other._data;
				break;
			case DEEP_COPY:
				_owner = true;
				_data = this->allocate(_count);
				std::uninitialized_copy(other._data, other._data + _count, _data);
				break;
			}
		}

		void assign(vector<T, Allocator>&& other)
		{
			assign_rv(std::forward<vector<T, Allocator> >(other), typename allocator_traits_type::propagate_on_container_move_assignment());
		}

		void reassign(size_type len, size_type dim)
		{
			if (len == 0 || dim == 0)
				throw std::invalid_argument(INVALID_VECTOR_SIZE);
			size_type count = len * dim;
			if (_owner && _count != count && _data != nullptr)
			{
				std::destroy_n(_data, _count);
				this->deallocate(_data, _count);
			}
			if (!_owner || _count != count)
			{
				_owner = true;
				_dim = dim;
				_len = len;
				_count = count;
				_data = this->allocate(_count);
				std::uninitialized_default_construct_n(_data, _count);
			}
		}

		void reassign(size_type len, size_type dim, const value_type& value)
		{
			if (len == 0 || dim == 0)
				throw std::invalid_argument(INVALID_VECTOR_SIZE);
			size_type count = len * dim;
			if (_owner && _count != count && _data != nullptr)
			{
				std::destroy_n(_data, _count);
				this->deallocate(_data, _count);
			}
			if (!_owner || _count != count)
			{
				_owner = true;
				_dim = dim;
				_len = len;
				_count = count;
				_data = this->allocate(_count);
				std::uninitialized_fill_n(_data, _count, value);
			}
			else
				std::fill_n(_data, _count, value);
		}

		void reassign(size_type len, size_type dim, const_pointer p)
		{
			if (len == 0 || dim == 0)
				throw std::invalid_argument(INVALID_VECTOR_SIZE);
			size_type count = len * dim;
			if (_owner && _count != count && _data != nullptr)
			{
				std::destroy_n(_data, _count);
				this->deallocate(_data, _count);
			}
			if (!_owner || _count != count)
			{
				_owner = true;
				_dim = dim;
				_len = len;
				_count = count;
				_data = this->allocate(_count);
				std::uninitialized_copy(p, p + _count, _data);
			}
			else
				std::copy(p, p + _count, _data);
		}

		void reassign(size_type len, size_type dim, pointer p, bool copy_data)
		{
			if (len == 0 || dim == 0)
				throw std::invalid_argument(INVALID_VECTOR_SIZE);
			size_type count = len * dim;
			if (copy_data)
			{
				if (_owner && _count != count && _data != nullptr)
				{
					std::destroy_n(_data, _count);
					this->deallocate(_data, _count);
				}
				if (!_owner || _count != count)
				{
					_owner = true;
					_dim = dim;
					_len = len;
					_count = count;
					_data = this->allocate(_count);
					std::uninitialized_copy(p, p + _count, _data);
				}
				else
					std::copy(p, p + _count, _data);
			}
			else
			{
				if (_owner && _data != nullptr)
				{
					std::destroy_n(_data, _count);
					this->deallocate(_data, _count);
				}
				_owner = false;
				_dim = dim;
				_len = len;
				_count = count;
				_data = p;
			}
		}

		template <class InputIterator>
		void reassign(size_type len, size_type dim, InputIterator first, InputIterator last)
		{
			if (len == 0 || dim == 0)
				throw std::invalid_argument(INVALID_VECTOR_SIZE);
			if (std::distance(first, last) != len * dim)
				throw std::invalid_argument(INVALID_INITIALIZER_LIST);
			size_type count = len * dim;
			if (_owner && _count != count && _data != nullptr)
			{
				std::destroy_n(_data, _count);
				this->deallocate(_data, _count);
			}
			if (!_owner || _count != count)
			{
				_owner = true;
				_dim = dim;
				_len = len;
				_count = count;
				_data = this->allocate(_count);
				std::uninitialized_copy(first, last, _data);
			}
			else
				std::copy(first, last, _data);
		}

		void reassign(size_type len, size_type dim, std::initializer_list<T> il)
		{
			reassign(len, dim, il.begin(), il.end());
		}

		void reassign(const vector<T, Allocator>& other, copy_mode_type copy_mode)
		{
			if (other.empty())
				throw std::domain_error(VECTOR_NOT_INITIALIZED);
			if (copy_mode == SHALLOW_COPY)
				throw std::invalid_argument(INVALID_COPY_MODE);
			switch (copy_mode)
			{
			case WITHOUT_COPY:
				if (_owner && _count != other._count && _data != nullptr)
				{
					std::destroy_n(_data, _count);
					this->deallocate(_data, _count);
				}
				if (!_owner || _count != other._count)
				{
					_owner = true;
					_dim = other._dim;
					_len = other._len;
					_count = other._count;
					_data = this->allocate(_count);
					std::uninitialized_default_construct_n(_data, _count);
				}
				break;
			case DEEP_COPY:
				if (_owner && _count != other._count && _data != nullptr)
				{
					std::destroy_n(_data, _count);
					this->deallocate(_data, _count);
				}
				if (!_owner || _count != other._count)
				{
					_owner = true;
					_dim = other._dim;
					_len = other._len;
					_count = other._count;
					_data = this->allocate(_count);
					std::uninitialized_copy(other._data, other._data + _count, _data);
				}
				else
					std::copy(other._data, other._data + _count, _data);
				break;
			}
		}

		void reassign(vector<T, Allocator>& other, copy_mode_type copy_mode)
		{
			if (other.empty())
				throw std::domain_error(VECTOR_NOT_INITIALIZED);
			switch (copy_mode)
			{
			case WITHOUT_COPY:
				if (_owner && _count != other._count && _data != nullptr)
				{
					std::destroy_n(_data, _count);
					this->deallocate(_data, _count);
				}
				if (!_owner || _count != other._count)
				{
					_owner = true;
					_dim = other._dim;
					_len = other._len;
					_count = other._count;
					_data = this->allocate(_count);
					std::uninitialized_default_construct_n(_data, _count);
				}
				break;
			case SHALLOW_COPY:
				if (_owner && _data != nullptr)
				{
					std::destroy_n(_data, _count);
					this->deallocate(_data, _count);
				}
				_owner = false;
				_dim = other._dim;
				_len = other._len;
				_count = other._count;
				_data = other._data;
				break;
			case DEEP_COPY:
				if (_owner && _count != other._count && _data != nullptr)
				{
					std::destroy_n(_data, _count);
					this->deallocate(_data, _count);
				}
				if (!_owner || _count != other._count)
				{
					_owner = true;
					_dim = other._dim;
					_len = other._len;
					_count = other._count;
					_data = this->allocate(_count);
					std::uninitialized_copy(other._data, other._data + _count, _data);
				}
				else
					std::copy(other._data, other._data + _count, _data);
				break;
			}
		}

		// iterators:

		iterator begin(void) noexcept
		{
			return iterator(_data, _dim);
		}
		const_iterator begin(void) const noexcept
		{
			return const_iterator(_data, _dim);
		}
		const_iterator cbegin(void) const noexcept
		{
			return const_iterator(_data, _dim);
		}
		iterator end(void) noexcept
		{
			return iterator(_data + _count, _dim);
		}
		const_iterator end(void) const noexcept
		{
			return const_iterator(_data + _count, _dim);
		}
		const_iterator cend(void) const noexcept
		{
			return const_iterator(_data + _count, _dim);
		}
		reverse_iterator rbegin(void) noexcept
		{
			return reverse_iterator(end());
		}
		const_reverse_iterator rbegin(void) const noexcept
		{
			return const_reverse_iterator(end());
		}
		const_reverse_iterator crbegin(void) const noexcept
		{
			return const_reverse_iterator(cend());
		}
		reverse_iterator rend(void) noexcept
		{
			return reverse_iterator(begin());
		}
		const_reverse_iterator rend(void) const noexcept
		{
			return const_reverse_iterator(begin());
		}
		const_reverse_iterator crend(void) const noexcept
		{
			return const_reverse_iterator(cbegin());
		}

		// capacity:

		bool empty(void) const noexcept
		{
			return (_data == nullptr);
		}

		size_type dim(void) const noexcept
		{
			return _dim;
		}

		size_type len(void) const noexcept
		{
			return _len;
		}

		size_type size(void) const noexcept
		{
			return _count;
		}

		size_type max_size(void) const noexcept
		{
			return this->max_size();
		}

		// element access:

		scalar_type operator[](size_type i) noexcept
		{
			return scalar_type(_dim, _data + i * _dim, false);
		}
		const_scalar_type operator[](size_type i) const noexcept
		{
			return const_scalar_type(_dim, _data + i * _dim, false);
		}

		scalar_type at(size_type i)
		{
			if (empty())
				throw std::domain_error(VECTOR_NOT_INITIALIZED);
			if (i >= _len)
				throw std::out_of_range(VECTOR_OUT_OF_RANGE);
			return scalar_type(_dim, _data + i * _dim, false);
		}
		const_scalar_type at(size_type i) const
		{
			if (empty())
				throw std::domain_error(VECTOR_NOT_INITIALIZED);
			if (i >= _len)
				throw std::out_of_range(VECTOR_OUT_OF_RANGE);
			return const_scalar_type(_dim, _data + i * _dim, false);
		}

		pointer data(void) noexcept
		{
			return static_cast<pointer>(_data);
		}
		const_pointer data(void) const noexcept
		{
			return static_cast<const_pointer>(_data);
		}
		pointer data(size_type pos) noexcept
		{
			return static_cast<pointer>(_data + pos * _dim);
		}
		const_pointer data(size_type pos) const noexcept
		{
			return static_cast<const_pointer>(_data + pos * _dim);
		}
		pointer data(size_type pos, size_type dim) noexcept
		{
			return static_cast<pointer>(_data + pos * _dim + dim);
		}
		const_pointer data(size_type pos, size_type dim) const noexcept
		{
			return static_cast<const_pointer>(_data + pos * _dim + dim);
		}

		// modifiers:

		void fill(const value_type& value)
		{
			if (empty())
				throw std::domain_error(VECTOR_NOT_INITIALIZED);
			std::fill_n(_data, _count, value);
		}

		void fill_n(size_type n, const value_type& value)
		{
			if (empty())
				throw std::domain_error(VECTOR_NOT_INITIALIZED);
			if (n == 0 || n > _count)
				throw std::invalid_argument(INVALID_LENGTH);
			std::fill_n(_data, n, value);
		}

		template <class InputIterator>
		void fill(InputIterator first, InputIterator last)
		{
			if (empty())
				throw std::domain_error(VECTOR_NOT_INITIALIZED);
			if (static_cast<size_type>(std::distance(first, last)) != _count)
				throw std::invalid_argument(INVALID_ITERATOR_DISTANCE);
			std::copy(first, last, _data);
		}

		void fill(std::initializer_list<T> il)
		{
			fill(il.begin(), il.end());
		}

		void fill(const scalar_type& scalar)
		{
			if (empty())
				throw std::domain_error(VECTOR_NOT_INITIALIZED);
			if (scalar.empty())
				throw std::domain_error(SCALAR_NOT_INITIALIZED);
			if (scalar.size() != _dim)
				throw std::invalid_argument(INVALID_DIMENSION);
			pointer current = _data;
			const_pointer first = scalar.data();
			const_pointer last = first + scalar.size();
			for (size_type i = 0; i < _len; ++i)
			{
				std::copy(first, last, current);
				current += _dim;
			}
		}

		void fill(const vector<T, Allocator>& other)
		{
			if (empty() || other.empty())
				throw std::domain_error(VECTOR_NOT_INITIALIZED);
			if (_count != other.size())
				throw std::invalid_argument(INVALID_SIZE);
			std::copy(other._data, other._data + _count, _data);
		}

		template<class Generator>
		void generate(Generator g)
		{
			if (empty())
				throw std::domain_error(VECTOR_NOT_INITIALIZED);
			for (size_type i = 0; i < _count; ++i)
				_data[i] = g();
		}

		void shape(size_type len, size_type dim)
		{
			if (empty())
				throw std::domain_error(VECTOR_NOT_INITIALIZED);
			if (len * dim != _count)
				throw std::invalid_argument(INVALID_VECTOR_SIZE);
			_dim = dim;
			_len = len;
			_count = _len * _dim;
		}

		vector<T, Allocator> reshape(size_type len, size_type dim) const
		{
			if (empty())
				throw std::domain_error(VECTOR_NOT_INITIALIZED);
			if (len * dim != _count)
				throw std::invalid_argument(INVALID_VECTOR_SIZE);
			return vector<T, Allocator>(len, dim, _data);
		}

		void swap(vector<T, Allocator>& rhs) noexcept
		{
			if (this != &rhs)
			{
				std::swap(_owner, rhs._owner);
				std::swap(_dim, rhs._dim);
				std::swap(_len, rhs._len);
				std::swap(_count, rhs._count);
				std::swap(_data, rhs._data);
			}
		}

		void clear(void) noexcept
		{
			if (_owner && _data != nullptr)
			{
				std::destroy_n(_data, _count);
				this->deallocate(_data, _count);
				_data = nullptr;
			}
			_owner = true;
			_dim = 0;
			_len = 0;
			_count = 0;
		}

		// allocator

		allocator_type get_allocator(void) const noexcept
		{
			return *static_cast<const allocator_type*>(this);
		}

	public:
		// operator:

		template <class A>
		friend bool operator<(const vector<T, Allocator>& lhs, const vector<T, A>& rhs)
		{
			if (lhs.size() != rhs.size())
				throw std::invalid_argument(VECTOR_DIFFERENT_SIZE);
			bool rst = true;
			const_pointer ptr1 = lhs.data();
			const_pointer ptr2 = rhs.data();
			for (size_t i = 0; i < lhs._count; ++i)
			{
				if (!(ptr1[i] < ptr2[i]))
				{
					rst = false;
					break;
				}
			}
			return rst;
		}
		template <class A>
		friend bool operator>(const vector<T, Allocator>& lhs, const vector<T, A>& rhs)
		{
			return (rhs < lhs);
		}
		template <class A>
		friend bool operator<=(const vector<T, Allocator>& lhs, const vector<T, A>& rhs)
		{
			return !(lhs > rhs);
		}
		template <class A>
		friend bool operator>=(const vector<T, Allocator>& lhs, const vector<T, A>& rhs)
		{
			return !(lhs < rhs);
		}

		template <class A>
		friend bool operator==(const vector<T, Allocator>& lhs, const vector<T, A>& rhs)
		{
			if (lhs.size() != rhs.size())
				throw std::invalid_argument(VECTOR_DIFFERENT_SIZE);
			bool rst = true;
			const_pointer ptr1 = lhs.data();
			const_pointer ptr2 = rhs.data();
			for (size_t i = 0; i < lhs._count; ++i)
			{
				if (!(ptr1[i] == ptr2[i]))
				{
					rst = false;
					break;
				}
			}
			return rst;
		}
		template <class A>
		friend bool operator!=(const vector<T, Allocator>& lhs, const vector<T, A>& rhs)
		{
			return !(lhs == rhs);
		}
	private:
		void assign_rv(vector<T, Allocator>&& right, std::true_type)
		{
			swap(right);
		}
		void assign_rv(vector<T, Allocator>&& right, std::false_type)
		{
			if (get_allocator() == right.get_allocator())
				assign_rv(std::forward<vector<T, Allocator> >(right), std::true_type());
			else
				assign(right, DEEP_COPY);
		}
	private:
		bool       _owner;
		size_type  _dim;
		size_type  _len;
		size_type  _count;
		pointer    _data;
	};

} // namespace core

#endif
