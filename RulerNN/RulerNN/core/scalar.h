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

#ifndef __CORE_SCALAR_H__
#define __CORE_SCALAR_H__

#include <memory>
#include <stdexcept>
#include "define.h"

#ifndef DEFAULT_ALLOCATOR
#define DEFAULT_ALLOCATOR(T) std::allocator<T>
#endif // !DEFAULT_ALLOCATOR

namespace core
{
	template <class T, class Allocator> class scalar;

	// Specialize for void
	template <class Allocator>
	class scalar<void, Allocator>
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
			using other = scalar<U, Allocator>;
		};
	};

	// Class template scalar
	template <class T, class Allocator = DEFAULT_ALLOCATOR(T)>
	class scalar : public Allocator
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
			using other = scalar<U, Allocator>;
		};

		// construct/copy/destroy:

		explicit scalar(const Allocator& alloc = Allocator())
			: Allocator(alloc)
			, _owner(true)
			, _count(0)
			, _data(nullptr)
		{}
		explicit scalar(size_type n)
			: Allocator()
			, _owner(true)
			, _count(0)
			, _data(nullptr)
		{
			assign(n);
		}
		scalar(size_type n, const value_type& value, const Allocator& alloc = Allocator())
			: Allocator(alloc)
			, _owner(true)
			, _count(0)
			, _data(nullptr)
		{
			assign(n, value);
		}
		scalar(size_type n, const_pointer p, const Allocator& alloc = Allocator())
			: Allocator(alloc)
			, _owner(true)
			, _count(0)
			, _data(nullptr)
		{
			assign(n, p);
		}
		scalar(size_type n, pointer p, bool copy_data, const Allocator& alloc = Allocator())
			: Allocator(alloc)
			, _owner(true)
			, _count(0)
			, _data(nullptr)
		{
			assign(n, p, copy_data);
		}
		template <class InputIterator>
		scalar(InputIterator first, InputIterator last, const Allocator& alloc = Allocator())
			: Allocator(alloc)
			, _owner(true)
			, _count(0)
			, _data(nullptr)
		{
			assign(last, last);
		}
		scalar(const scalar<T, Allocator>& other)
			: Allocator(other.get_allocator())
			, _owner(true)
			, _count(0)
			, _data(nullptr)
		{
			assign(other, DEEP_COPY);
		}
		scalar(scalar<T, Allocator>& other, copy_mode_type copy_mode)
			: Allocator(other.get_allocator())
			, _owner(true)
			, _count(0)
			, _data(nullptr)
		{
			assign(other, copy_mode);
		}
		scalar(scalar<T, Allocator>&& other)
			: Allocator(other.get_allocator())
			, _owner(true)
			, _count(0)
			, _data(nullptr)
		{
			assign(std::forward<scalar<T, Allocator> >(other));
		}
		scalar(const scalar<T, Allocator>& other, const Allocator& alloc, copy_mode_type copy_mode = DEEP_COPY)
			: Allocator(alloc)
			, _owner(true)
			, _count(0)
			, _data(nullptr)
		{
			assign(other, copy_mode);
		}
		scalar(scalar<T, Allocator>& other, const Allocator& alloc, copy_mode_type copy_mode = DEEP_COPY)
			: Allocator(alloc)
			, _owner(true)
			, _count(0)
			, _data(nullptr)
		{
			assign(other, copy_mode);
		}
		scalar(scalar<T, Allocator>&& other, const Allocator& alloc)
			: Allocator(alloc)
			, _owner(true)
			, _count(0)
			, _data(nullptr)
		{
			assign(std::forward<scalar<T, Allocator> >(other));
		}
		scalar(std::initializer_list<T> il, const Allocator& alloc = Allocator())
			: Allocator(alloc)
			, _owner(true)
			, _count(0)
			, _data(nullptr)
		{
			assign(il);
		}
		~scalar(void)
		{
			clear();
		}
		scalar<T, Allocator>& operator=(const scalar<T, Allocator>& other)
		{
			if (this != &other)
			{
				clear();
				assign(other, DEEP_COPY);
			}
			return (*this);
		}
		scalar<T, Allocator>& operator=(scalar<T, Allocator>&& other)
		{
			if (this != &other)
				assign(std::forward<scalar<T, Allocator> >(other));
			return (*this);
		}
		scalar<T, Allocator>& operator=(std::initializer_list<T> il)
		{
			clear();
			assign(il);
			return (*this);
		}

		void assign(size_type n)
		{
			if (!empty())
				throw std::domain_error(SCALAR_IS_INITIALIZED);
			if (n == 0)
				throw std::invalid_argument(INVALID_SCALAR_SIZE);
			_owner = true;
			_count = n;
			_data = this->allocate(_count);
			std::uninitialized_default_construct_n(_data, _count);
		}

		void assign(size_type n, const value_type& value)
		{
			if (!empty())
				throw std::domain_error(SCALAR_IS_INITIALIZED);
			if (n == 0)
				throw std::invalid_argument(INVALID_SCALAR_SIZE);
			_owner = true;
			_count = n;
			_data = this->allocate(_count);
			std::uninitialized_fill_n(_data, _count, value);
		}

		void assign(size_type n, const_pointer p)
		{
			if (!empty())
				throw std::domain_error(SCALAR_IS_INITIALIZED);
			if (n == 0)
				throw std::invalid_argument(INVALID_SCALAR_SIZE);
			_owner = true;
			_count = n;
			_data = this->allocate(_count);
			std::uninitialized_copy(p, p + _count, _data);
		}

		void assign(size_type n, pointer p, bool copy_data)
		{
			if (!empty())
				throw std::domain_error(SCALAR_IS_INITIALIZED);
			if (n == 0)
				throw std::invalid_argument(INVALID_SCALAR_SIZE);
			_owner = copy_data;
			_count = n;
			if (copy_data)
			{
				_data = this->allocate(_count);
				std::uninitialized_copy(p, p + _count, _data);
			}
			else
				_data = p;
		}

		template <class InputIterator>
		void assign(InputIterator first, InputIterator last)
		{
			if (!empty())
				throw std::domain_error(SCALAR_IS_INITIALIZED);
			if (std::distance(first, last) <= 0)
				throw std::invalid_argument(INVALID_INITIALIZER_LIST);
			_owner = true;
			_count = static_cast<size_type>(std::distance(first, last));
			_data = this->allocate(_count);
			std::uninitialized_copy(first, last, _data);
		}

		void assign(std::initializer_list<T> il)
		{
			assign(il.begin(), il.end());
		}

		void assign(const scalar<T, Allocator>& other, copy_mode_type copy_mode)
		{
			if (!empty())
				throw std::domain_error(SCALAR_IS_INITIALIZED);
			if (other.empty())
				throw std::domain_error(SCALAR_NOT_INITIALIZED);
			if (copy_mode == SHALLOW_COPY)
				throw std::invalid_argument(INVALID_COPY_MODE);
			_owner = true;
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

		void assign(scalar<T, Allocator>& other, copy_mode_type copy_mode)
		{
			if (!empty())
				throw std::domain_error(SCALAR_IS_INITIALIZED);
			if (other.empty())
				throw std::domain_error(SCALAR_NOT_INITIALIZED);
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

		void assign(scalar<T, Allocator>&& other)
		{
			assign_rv(std::forward<scalar<T, Allocator> >(other), typename allocator_traits_type::propagate_on_container_move_assignment());
		}

		void reassign(size_type n)
		{
			if (n == 0)
				throw std::invalid_argument(INVALID_SCALAR_SIZE);
			if (_owner && _count != n && _data != nullptr)
			{
				std::destroy_n(_data, _count);
				this->deallocate(_data, _count);
			}
			if (!_owner || _count != n)
			{
				_owner = true;
				_count = n;
				_data = this->allocate(_count);
				std::uninitialized_default_construct_n(_data, _count);
			}
		}

		void reassign(size_type n, const value_type& value)
		{
			if (n == 0)
				throw std::invalid_argument(INVALID_SCALAR_SIZE);
			if (_owner && _count != n && _data != nullptr)
			{
				std::destroy_n(_data, _count);
				this->deallocate(_data, _count);
			}
			if (!_owner || _count != n)
			{
				_owner = true;
				_count = n;
				_data = this->allocate(_count);
				std::uninitialized_fill_n(_data, _count, value);
			}
			else
				std::fill_n(_data, _count, value);
		}

		void reassign(size_type n, const_pointer p)
		{
			if (n == 0)
				throw std::invalid_argument(INVALID_SCALAR_SIZE);
			if (_owner && _count != n && _data != nullptr)
			{
				std::destroy_n(_data, _count);
				this->deallocate(_data, _count);
			}
			if (!_owner || _count != n)
			{
				_owner = true;
				_count = n;
				_data = this->allocate(_count);
				std::uninitialized_copy(p, p + _count, _data);
			}
			else
				std::copy(p, p + _count, _data);
		}

		void reassign(size_type n, pointer p, bool copy_data)
		{
			if (n == 0)
				throw std::invalid_argument(INVALID_SCALAR_SIZE);
			if (copy_data)
			{
				if (_owner && _count != n && _data != nullptr)
				{
					std::destroy_n(_data, _count);
					this->deallocate(_data, _count);
				}
				if (!_owner || _count != n)
				{
					_owner = true;
					_count = n;
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
				_count = n;
				_data = p;
			}
		}

		template <class InputIterator>
		void reassign(InputIterator first, InputIterator last)
		{
			if (std::distance(first, last) == 0)
				throw std::invalid_argument(INVALID_INITIALIZER_LIST);
			size_type count = std::distance(first, last);
			if (_owner && _count != count && _data != nullptr)
			{
				std::destroy_n(_data, _count);
				this->deallocate(_data, _count);
			}
			if (!_owner || _count != count)
			{
				_owner = true;
				_count = count;
				_data = this->allocate(_count);
				std::uninitialized_copy(first, last, _data);
			}
			else
				std::copy(first, last, _data);
		}

		void reassign(std::initializer_list<T> il)
		{
			reassign(il.begin(), il.end());
		}

		void reassign(const scalar<T, Allocator>& other, copy_mode_type copy_mode)
		{
			if (other.empty())
				throw std::domain_error(SCALAR_NOT_INITIALIZED);
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
					_count = other._count;
					_data = this->allocate(_count);
					std::uninitialized_copy(other._data, other._data + _count, _data);
				}
				else
					std::copy(other._data, other._data + _count, _data);
				break;
			}
		}

		void reassign(scalar<T, Allocator>& other, copy_mode_type copy_mode)
		{
			if (other.empty())
				throw std::domain_error(SCALAR_NOT_INITIALIZED);
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
					_count = other._count;
					_data = this->allocate(_count);
					std::uninitialized_copy(other._data, other._data + _count, _data);
				}
				else
					std::copy(other._data, other._data + _count, _data);
				break;
			}
		}

		// capacity:

		bool empty(void) const noexcept
		{
			return (_data == nullptr);
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

		value_type& operator[](size_type idx) noexcept
		{
			return _data[idx];
		}
		const value_type& operator[](size_type idx) const noexcept
		{
			return _data[idx];
		}

		value_type& at(size_type idx)
		{
			if (empty())
				throw std::domain_error(SCALAR_NOT_INITIALIZED);
			if (idx >= _count)
				throw std::out_of_range(SCALAR_OUT_OF_RANGE);
			return _data[idx];
		}
		const value_type& at(size_type idx) const
		{
			if (empty())
				throw std::domain_error(SCALAR_NOT_INITIALIZED);
			if (idx >= _count)
				throw std::out_of_range(SCALAR_OUT_OF_RANGE);
			return _data[idx];
		}

		pointer data(void) noexcept
		{
			return static_cast<pointer>(_data);
		}
		const_pointer data(void) const noexcept
		{
			return static_cast<const_pointer>(_data);
		}

		// modifiers:

		void fill(const value_type& value)
		{
			if (empty())
				throw std::domain_error(SCALAR_NOT_INITIALIZED);
			std::fill_n(_data, _count, value);
		}

		void fill_n(size_type n, const value_type& value)
		{
			if (empty())
				throw std::domain_error(SCALAR_NOT_INITIALIZED);
			if (n == 0 || n > _count)
				throw std::invalid_argument(INVALID_LENGTH);
			std::fill_n(_data, n, value);
		}

		template <class InputIterator>
		void fill(InputIterator first, InputIterator last)
		{
			if (empty())
				throw std::domain_error(SCALAR_NOT_INITIALIZED);
			if (static_cast<size_t>(std::distance(first, last)) != _count)
				throw std::invalid_argument(INVALID_ITERATOR_DISTANCE);
			std::copy(first, last, _data);
		}

		void fill(std::initializer_list<T> il)
		{
			fill(il.begin(), il.end());
		}

		void fill(const scalar<T, Allocator>& other)
		{
			if (empty() || other.empty())
				throw std::domain_error(SCALAR_NOT_INITIALIZED);
			if (_count != other.size())
				throw std::invalid_argument(INVALID_SIZE);
			std::copy(other._data, other._data + _count, _data);
		}

		template<class Generator>
		void generate(Generator g)
		{
			if (empty())
				throw std::domain_error(SCALAR_NOT_INITIALIZED);
			for (size_type i = 0; i < _count; ++i)
				_data[i] = g();
		}

		void swap(scalar<T, Allocator>& rhs) noexcept
		{
			if (this != &rhs)
			{
				std::swap(_owner, rhs._owner);
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
		friend bool operator<(const scalar<T, Allocator>& lhs, const scalar<T, A>& rhs)
		{
			if (lhs.size() != rhs.size())
				throw std::invalid_argument(SCALAR_DIFFERENT_SIZE);
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
		friend bool operator>(const scalar<T, Allocator>& lhs, const scalar<T, A>& rhs)
		{
			return (rhs < lhs);
		}
		template <class A>
		friend bool operator<=(const scalar<T, Allocator>& lhs, const scalar<T, A>& rhs)
		{
			return !(lhs > rhs);
		}
		template <class A>
		friend bool operator>=(const scalar<T, Allocator>& lhs, const scalar<T, A>& rhs)
		{
			return !(lhs < rhs);
		}

		template <class A>
		friend bool operator==(const scalar<T, Allocator>& lhs, const scalar<T, A>& rhs)
		{
			if (lhs.size() != rhs.size())
				throw std::invalid_argument(SCALAR_DIFFERENT_SIZE);
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
		friend bool operator!=(const scalar<T, Allocator>& lhs, const scalar<T, A>& rhs)
		{
			return !(lhs == rhs);
		}
	private:
		void assign_rv(scalar<T, Allocator>&& right, std::true_type)
		{
			swap(right);
		}
		void assign_rv(scalar<T, Allocator>&& right, std::false_type)
		{
			if (get_allocator() == right.get_allocator())
				assign_rv(std::forward<scalar<T, Allocator> >(right), std::true_type());
			else
				assign(right, DEEP_COPY);
		}
	private:
		bool       _owner;
		size_type  _count;
		pointer    _data;
	};

} // namespace core

#endif
