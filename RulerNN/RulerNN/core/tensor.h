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

#ifndef __CORE_TENSOR_H__
#define __CORE_TENSOR_H__

#include <memory>
#include <stdexcept>
#include "define.h"
#include "scalar.h"
#include "vector.h"
#include "matrix.h"

#ifndef DEFAULT_ALLOCATOR
#define DEFAULT_ALLOCATOR(T) std::allocator<T>
#endif // !DEFAULT_ALLOCATOR

namespace core
{
	template <class T, class Allocator> class tensor;

	// Specialize for void
	template <class Allocator>
	class tensor<void, Allocator>
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
			using other = tensor<U, Allocator>;
		};
	};

	// Class template tensor_type_traits

	template <class Tensor, bool IsConst>
	struct tensor_type_traits
	{
		using value_type      = typename Tensor::value_type;
		using pointer         = typename Tensor::pointer;
		using size_type       = typename Tensor::size_type;
		using difference_type = typename Tensor::difference_type;
		using reference       = value_type&;
	};

	template <class Tensor>
	struct tensor_type_traits<Tensor, true>
	{
		using value_type      = typename Tensor::value_type;
		using pointer         = typename Tensor::const_pointer;
		using size_type       = typename Tensor::size_type;
		using difference_type = typename Tensor::difference_type;
		using reference       = const value_type&;
	};

	// Class template tensor_iterator
	template <class Tensor, bool IsConst>
	class tensor_iterator
	{
	public:
		// types:

		using value_type        = typename tensor_type_traits<Tensor, IsConst>::value_type;
		using pointer           = typename tensor_type_traits<Tensor, IsConst>::pointer;
		using reference         = typename tensor_type_traits<Tensor, IsConst>::reference;
		using size_type         = typename tensor_type_traits<Tensor, IsConst>::size_type;
		using difference_type   = typename tensor_type_traits<Tensor, IsConst>::difference_type;

		using iterator_type     = tensor_iterator<Tensor, IsConst>;
		using iterator_category = std::bidirectional_iterator_tag;

		// construct/copy/destroy:

		tensor_iterator(void) noexcept
			: step(0)
			, ptr(nullptr)
		{}
		explicit tensor_iterator(pointer p, size_type stride) noexcept
			: step(stride)
			, ptr(p)
		{}
		tensor_iterator(const tensor_iterator<Tensor, IsConst>& other) noexcept
			: step(other.step)
			, ptr(other.ptr)
		{}

		tensor_iterator<Tensor, IsConst>& operator=(const tensor_iterator<Tensor, IsConst>& other) noexcept
		{
			if (this != &other)
			{
				step = other.step;
				ptr = other.ptr;
			}
			return (*this);
		}

		operator tensor_iterator<Tensor, true>(void) const noexcept
		{
			return tensor_iterator<Tensor, true>(ptr, step);
		}

		// tensor_iterator operations:

		reference operator*(void) const noexcept
		{
			return static_cast<reference>(*ptr);
		}

		pointer operator->(void) const noexcept
		{
			return &(operator*());
		}

		// increment / decrement

		tensor_iterator<Tensor, IsConst>& operator++(void) noexcept
		{
			ptr += step;
			return *this;
		}
		tensor_iterator<Tensor, IsConst>& operator--(void) noexcept
		{
			ptr -= step;
			return *this;
		}
		tensor_iterator<Tensor, IsConst> operator++(int) noexcept
		{
			tensor_iterator tmp(*this);
			++(*this);
			return tmp;
		}
		tensor_iterator<Tensor, IsConst> operator--(int) noexcept
		{
			tensor_iterator tmp(*this);
			--(*this);
			return tmp;
		}
		tensor_iterator<Tensor, IsConst>& operator+=(difference_type n) noexcept
		{
			ptr += (n * step);
			return *this;
		}
		tensor_iterator<Tensor, IsConst>& operator-=(difference_type n) noexcept
		{
			ptr -= (n * step);
			return *this;
		}

		// relational operators:

		template <bool b>
		bool operator==(const tensor_iterator<Tensor, b>& rhs) const noexcept
		{
			return (ptr == rhs.operator->());
		}
		template <bool b>
		bool operator!=(const tensor_iterator<Tensor, b>& rhs) const noexcept
		{
			return (ptr != rhs.operator->());
		}
	private:
		size_type step;
		pointer   ptr;
	};

	// Class template tensor
	template <class T, class Allocator = DEFAULT_ALLOCATOR(T)>
	class tensor : public Allocator
	{
	public:
		// types:

		using allocator_type         = Allocator;
		using scalar_type            = core::scalar<T, Allocator>;
		using const_scalar_type      = const scalar_type;
		using vector_type            = core::vector<T, Allocator>;
		using const_vector_type      = const vector_type;
		using matrix_type            = core::matrix<T, Allocator>;
		using const_matrix_type      = const matrix_type;
		using allocator_traits_type  = std::allocator_traits<allocator_type>;
		using value_type             = typename allocator_traits_type::value_type;
		using pointer                = typename allocator_traits_type::pointer;
		using const_pointer          = typename allocator_traits_type::const_pointer;
		using size_type              = typename allocator_traits_type::size_type;
		using difference_type        = typename allocator_traits_type::difference_type;

		using iterator               = tensor_iterator<tensor<T, Allocator>, false>;
		using const_iterator         = tensor_iterator<tensor<T, Allocator>, true>;
		using reverse_iterator       = std::reverse_iterator<iterator>;
		using const_reverse_iterator = std::reverse_iterator<const_iterator>;

		template <class U>
		struct rebind
		{
			using other = tensor<U, Allocator>;
		};

		// construct/copy/destroy:

		explicit tensor(const Allocator& alloc = Allocator())
			: Allocator(alloc)
			, _owner(true)
			, _dim(0)
			, _cols(0)
			, _rows(0)
			, _num(0)
			, _line(0)
			, _plane(0)
			, _count(0)
			, _data(nullptr)
		{}
		explicit tensor(size_type num, size_type rows, size_type cols, size_type dim)
			: Allocator()
			, _owner(true)
			, _dim(0)
			, _cols(0)
			, _rows(0)
			, _num(0)
			, _line(0)
			, _plane(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(num, rows, cols, dim);
		}
		tensor(size_type num, size_type rows, size_type cols, size_type dim, const value_type& value, const Allocator& alloc = Allocator())
			: Allocator(alloc)
			, _owner(true)
			, _dim(0)
			, _cols(0)
			, _rows(0)
			, _num(0)
			, _line(0)
			, _plane(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(num, rows, cols, dim, value);
		}
		tensor(size_type num, size_type rows, size_type cols, size_type dim, const_pointer p, const Allocator& alloc = Allocator())
			: Allocator(alloc)
			, _owner(true)
			, _dim(0)
			, _cols(0)
			, _rows(0)
			, _num(0)
			, _line(0)
			, _plane(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(num, rows, cols, dim, p);
		}
		tensor(size_type num, size_type rows, size_type cols, size_type dim, pointer p, bool copy_data, const Allocator& alloc = Allocator())
			: Allocator(alloc)
			, _owner(true)
			, _dim(0)
			, _cols(0)
			, _rows(0)
			, _num(0)
			, _line(0)
			, _plane(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(num, rows, cols, dim, p, copy_data);
		}
		template <class InputIterator>
		tensor(size_type num, size_type rows, size_type cols, size_type dim, InputIterator first, InputIterator last, const Allocator& alloc = Allocator())
			: Allocator(alloc)
			, _owner(true)
			, _dim(0)
			, _cols(0)
			, _rows(0)
			, _num(0)
			, _line(0)
			, _plane(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(num, rows, cols, dim, last, last);
		}
		tensor(const tensor<T, Allocator>& other)
			: Allocator(other.get_allocator())
			, _owner(true)
			, _dim(0)
			, _cols(0)
			, _rows(0)
			, _num(0)
			, _line(0)
			, _plane(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(other, DEEP_COPY);
		}
		tensor(tensor<T, Allocator>& other, copy_mode_type copy_mode)
			: Allocator(other.get_allocator())
			, _owner(true)
			, _dim(0)
			, _cols(0)
			, _rows(0)
			, _num(0)
			, _line(0)
			, _plane(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(other, copy_mode);
		}
		tensor(tensor<T, Allocator>&& other)
			: Allocator(other.get_allocator())
			, _owner(true)
			, _dim(0)
			, _cols(0)
			, _rows(0)
			, _num(0)
			, _line(0)
			, _plane(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(std::forward<tensor<T, Allocator> >(other));
		}
		tensor(const tensor<T, Allocator>& other, const Allocator& alloc, copy_mode_type copy_mode = DEEP_COPY)
			: Allocator(alloc)
			, _owner(true)
			, _dim(0)
			, _cols(0)
			, _rows(0)
			, _num(0)
			, _line(0)
			, _plane(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(other, copy_mode);
		}
		tensor(tensor<T, Allocator>& other, const Allocator& alloc, copy_mode_type copy_mode = DEEP_COPY)
			: Allocator(alloc)
			, _owner(true)
			, _dim(0)
			, _cols(0)
			, _rows(0)
			, _num(0)
			, _line(0)
			, _plane(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(other, copy_mode);
		}
		tensor(tensor<T, Allocator>&& other, const Allocator& alloc)
			: Allocator(alloc)
			, _owner(true)
			, _dim(0)
			, _cols(0)
			, _rows(0)
			, _num(0)
			, _line(0)
			, _plane(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(std::forward<tensor<T, Allocator> >(other));
		}
		tensor(size_type num, size_type rows, size_type cols, size_type dim, std::initializer_list<T> il, const Allocator& alloc = Allocator())
			: Allocator(alloc)
			, _owner(true)
			, _dim(0)
			, _cols(0)
			, _rows(0)
			, _num(0)
			, _line(0)
			, _plane(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(num, rows, cols, dim, il);
		}
		~tensor(void)
		{
			clear();
		}
		tensor<T, Allocator>& operator=(const tensor<T, Allocator>& other)
		{
			if (this != &other)
			{
				clear();
				assign(other, DEEP_COPY);
			}
			return (*this);
		}
		tensor<T, Allocator>& operator=(tensor<T, Allocator>&& other)
		{
			if (this != &other)
				assign(std::forward<tensor<T, Allocator> >(other));
			return (*this);
		}

		void assign(size_type num, size_type rows, size_type cols, size_type dim)
		{
			if (!empty())
				throw std::domain_error(TENSOR_IS_INITIALIZED);
			if (num == 0 || rows == 0 || cols == 0 || dim == 0)
				throw std::invalid_argument(INVALID_TENSOR_SIZE);
			_owner = true;
			_dim = dim;
			_cols = cols;
			_rows = rows;
			_num = num;
			_line = _cols * _dim;
			_plane = _rows * _line;
			_count = _num * _plane;
			_data = this->allocate(_count);
			std::uninitialized_default_construct_n(_data, _count);
		}

		void assign(size_type num, size_type rows, size_type cols, size_type dim, const value_type& value)
		{
			if (!empty())
				throw std::domain_error(TENSOR_IS_INITIALIZED);
			if (num == 0 || rows == 0 || cols == 0 || dim == 0)
				throw std::invalid_argument(INVALID_TENSOR_SIZE);
			_owner = true;
			_dim = dim;
			_cols = cols;
			_rows = rows;
			_num = num;
			_line = _cols * _dim;
			_plane = _rows * _line;
			_count = _num * _plane;
			_data = this->allocate(_count);
			std::uninitialized_fill_n(_data, _count, value);
		}

		void assign(size_type num, size_type rows, size_type cols, size_type dim, const_pointer p)
		{
			if (!empty() && _owner == true)
				throw std::domain_error(TENSOR_IS_INITIALIZED);
			if (num == 0 || rows == 0 || cols == 0 || dim == 0)
				throw std::invalid_argument(INVALID_TENSOR_SIZE);
			_owner = true;
			_dim = dim;
			_cols = cols;
			_rows = rows;
			_num = num;
			_line = _cols * _dim;
			_plane = _rows * _line;
			_count = _num * _plane;
			_data = this->allocate(_count);
			std::uninitialized_copy(p, p + _count, _data);
		}

		void assign(size_type num, size_type rows, size_type cols, size_type dim, pointer p, bool copy_data)
		{
			if (!empty() && _owner == true)
				throw std::domain_error(TENSOR_IS_INITIALIZED);
			if (num == 0 || rows == 0 || cols == 0 || dim == 0)
				throw std::invalid_argument(INVALID_TENSOR_SIZE);
			_owner = copy_data;
			_dim = dim;
			_cols = cols;
			_rows = rows;
			_num = num;
			_line = _cols * _dim;
			_plane = _rows * _line;
			_count = _num * _plane;
			if (copy_data)
			{
				_data = this->allocate(_count);
				std::uninitialized_copy(p, p + _count, _data);
			}
			else
				_data = p;
		}

		template <class InputIterator>
		void assign(size_type num, size_type rows, size_type cols, size_type dim, InputIterator first, InputIterator last)
		{
			if (!empty())
				throw std::domain_error(TENSOR_IS_INITIALIZED);
			if (num == 0 || rows == 0 || cols == 0 || dim == 0)
				throw std::invalid_argument(INVALID_TENSOR_SIZE);
			if (std::distance(first, last) != num * rows * cols * dim)
				throw std::invalid_argument(INVALID_INITIALIZER_LIST);
			_owner = true;
			_dim = dim;
			_cols = cols;
			_rows = rows;
			_num = num;
			_line = _cols * _dim;
			_plane = _rows * _line;
			_count = _num * _plane;
			_data = this->allocate(_count);
			std::uninitialized_copy(first, last, _data);
		}

		void assign(size_type num, size_type rows, size_type cols, size_type dim, std::initializer_list<T> il)
		{
			assign(num, rows, cols, dim, il.begin(), il.end());
		}

		void assign(const tensor<T, Allocator>& other, copy_mode_type copy_mode)
		{
			if (!empty())
				throw std::domain_error(TENSOR_IS_INITIALIZED);
			if (other.empty())
				throw std::domain_error(TENSOR_NOT_INITIALIZED);
			if (copy_mode == SHALLOW_COPY)
				throw std::invalid_argument(INVALID_COPY_MODE);
			_owner = true;
			_dim = other._dim;
			_cols = other._cols;
			_rows = other._rows;
			_num = other._num;
			_line = other._line;
			_plane = other._plane;
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

		void assign(tensor<T, Allocator>& other, copy_mode_type copy_mode)
		{
			if (!empty())
				throw std::domain_error(TENSOR_IS_INITIALIZED);
			if (other.empty())
				throw std::domain_error(TENSOR_NOT_INITIALIZED);
			_dim = other._dim;
			_cols = other._cols;
			_rows = other._rows;
			_num = other._num;
			_line = other._line;
			_plane = other._plane;
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

		void assign(tensor<T, Allocator>&& other)
		{
			assign_rv(std::forward<tensor<T, Allocator> >(other), typename allocator_traits_type::propagate_on_container_move_assignment());
		}

		void reassign(size_type num, size_type rows, size_type cols, size_type dim)
		{
			if (num == 0 || rows == 0 || cols == 0 || dim == 0)
				throw std::invalid_argument(INVALID_TENSOR_SIZE);
			size_type line = cols * dim;
			size_type plane = rows * line;
			size_type count = num * plane;
			if (_owner && _count != count && _data != nullptr)
			{
				std::destroy_n(_data, _count);
				this->deallocate(_data, _count);
			}
			if (!_owner || _count != count)
			{
				_owner = true;
				_dim = dim;
				_cols = cols;
				_rows = rows;
				_num = num;
				_line = line;
				_plane = plane;
				_count = count;
				_data = this->allocate(_count);
				std::uninitialized_default_construct_n(_data, _count);
			}
		}

		void reassign(size_type num, size_type rows, size_type cols, size_type dim, const value_type& value)
		{
			if (num == 0 || rows == 0 || cols == 0 || dim == 0)
				throw std::invalid_argument(INVALID_TENSOR_SIZE);
			size_type line = cols * dim;
			size_type plane = rows * line;
			size_type count = num * plane;
			if (_owner && _count != count && _data != nullptr)
			{
				std::destroy_n(_data, _count);
				this->deallocate(_data, _count);
			}
			if (!_owner || _count != count)
			{
				_owner = true;
				_dim = dim;
				_cols = cols;
				_rows = rows;
				_num = num;
				_line = line;
				_plane = plane;
				_count = count;
				_data = this->allocate(_count);
				std::uninitialized_fill_n(_data, _count, value);
			}
			else
				std::fill_n(_data, _count, value);
		}

		void reassign(size_type num, size_type rows, size_type cols, size_type dim, const_pointer p)
		{
			if (num == 0 || rows == 0 || cols == 0 || dim == 0)
				throw std::invalid_argument(INVALID_TENSOR_SIZE);
			size_type line = cols * dim;
			size_type plane = rows * line;
			size_type count = num * plane;
			if (_owner && _count != count && _data != nullptr)
			{
				std::destroy_n(_data, _count);
				this->deallocate(_data, _count);
			}
			if (!_owner || _count != count)
			{
				_owner = true;
				_dim = dim;
				_cols = cols;
				_rows = rows;
				_num = num;
				_line = line;
				_plane = plane;
				_count = count;
				_data = this->allocate(_count);
				std::uninitialized_copy(p, p + _count, _data);
			}
			else
				std::copy(p, p + _count, _data);
		}

		void reassign(size_type num, size_type rows, size_type cols, size_type dim, pointer p, bool copy_data)
		{
			if (num == 0 || rows == 0 || cols == 0 || dim == 0)
				throw std::invalid_argument(INVALID_TENSOR_SIZE);
			size_type line = cols * dim;
			size_type plane = rows * line;
			size_type count = num * plane;
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
					_cols = cols;
					_rows = rows;
					_num = num;
					_line = line;
					_plane = plane;
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
				_cols = cols;
				_rows = rows;
				_num = num;
				_line = line;
				_plane = plane;
				_count = count;
				_data = p;
			}
		}

		template <class InputIterator>
		void reassign(size_type num, size_type rows, size_type cols, size_type dim, InputIterator first, InputIterator last)
		{
			if (num == 0 || rows == 0 || cols == 0 || dim == 0)
				throw std::invalid_argument(INVALID_TENSOR_SIZE);
			if (std::distance(first, last) != num * rows * cols * dim)
				throw std::invalid_argument(INVALID_INITIALIZER_LIST);
			size_type line = cols * dim;
			size_type plane = rows * line;
			size_type count = num * plane;
			if (_owner && _count != count && _data != nullptr)
			{
				std::destroy_n(_data, _count);
				this->deallocate(_data, _count);
			}
			if (!_owner || _count != count)
			{
				_owner = true;
				_dim = dim;
				_cols = cols;
				_rows = rows;
				_num = num;
				_line = line;
				_plane = plane;
				_count = count;
				_data = this->allocate(_count);
				std::uninitialized_copy(first, last, _data);
			}
			else
				std::copy(first, last, _data);
		}

		void reassign(size_type num, size_type rows, size_type cols, size_type dim, std::initializer_list<T> il)
		{
			reassign(num, rows, cols, dim, il.begin(), il.end());
		}

		void reassign(const tensor<T, Allocator>& other, copy_mode_type copy_mode)
		{
			if (other.empty())
				throw std::domain_error(TENSOR_NOT_INITIALIZED);
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
					_cols = other._cols;
					_rows = other._rows;
					_num = other._num;
					_line = other._line;
					_plane = other._plane;
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
					_cols = other._cols;
					_rows = other._rows;
					_num = other._num;
					_line = other._line;
					_plane = other._plane;
					_count = other._count;
					_data = this->allocate(_count);
					std::uninitialized_copy(other._data, other._data + _count, _data);
				}
				else
					std::copy(other._data, other._data + _count, _data);
				break;
			}
		}

		void reassign(tensor<T, Allocator>& other, copy_mode_type copy_mode)
		{
			if (other.empty())
				throw std::domain_error(TENSOR_NOT_INITIALIZED);
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
					_cols = other._cols;
					_rows = other._rows;
					_num = other._num;
					_line = other._line;
					_plane = other._plane;
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
				_cols = other._cols;
				_rows = other._rows;
				_num = other._num;
				_line = other._line;
				_plane = other._plane;
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
					_cols = other._cols;
					_rows = other._rows;
					_num = other._num;
					_line = other._line;
					_plane = other._plane;
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

		iterator mbegin(void) noexcept
		{
			return iterator(_data, _plane);
		}
		const_iterator mbegin(void) const noexcept
		{
			return const_iterator(_data, _plane);
		}
		const_iterator cmbegin(void) const noexcept
		{
			return const_iterator(_data, _plane);
		}
		iterator mend(void) noexcept
		{
			return iterator(_data + _count, _plane);
		}
		const_iterator mend(void) const noexcept
		{
			return const_iterator(_data + _count, _plane);
		}
		const_iterator cmend(void) const noexcept
		{
			return const_iterator(_data + _count, _plane);
		}
		reverse_iterator rmbegin(void) noexcept
		{
			return reverse_iterator(mend());
		}
		const_reverse_iterator rmbegin(void) const noexcept
		{
			return const_reverse_iterator(mend());
		}
		const_reverse_iterator crmbegin(void) const noexcept
		{
			return const_reverse_iterator(cmend());
		}
		reverse_iterator rmend(void) noexcept
		{
			return reverse_iterator(mbegin());
		}
		const_reverse_iterator rmend(void) const noexcept
		{
			return const_reverse_iterator(mbegin());
		}
		const_reverse_iterator crmend(void) const noexcept
		{
			return const_reverse_iterator(cmbegin());
		}

		iterator vbegin(iterator it) noexcept
		{
			return iterator(it.operator->(), _line);
		}
		iterator vbegin(reverse_iterator it) noexcept
		{
			return iterator(it.operator->(), _line);
		}
		const_iterator vbegin(const_iterator it) noexcept
		{
			return const_iterator(const_cast<pointer>(it.operator->()), _line);
		}
		const_iterator vbegin(const_reverse_iterator it) noexcept
		{
			return const_iterator(const_cast<pointer>(it.operator->()), _line);
		}
		const_iterator vbegin(const_iterator it) const noexcept
		{
			return const_iterator(const_cast<pointer>(it.operator->()), _line);
		}
		const_iterator vbegin(const_reverse_iterator it) const noexcept
		{
			return const_iterator(const_cast<pointer>(it.operator->()), _line);
		}
		const_iterator cvbegin(iterator it) noexcept
		{
			return const_iterator(it.operator->(), _line);
		}
		const_iterator cvbegin(reverse_iterator it) noexcept
		{
			return const_iterator(it.operator->(), _line);
		}
		const_iterator cvbegin(const_iterator it) noexcept
		{
			return const_iterator(const_cast<pointer>(it.operator->()), _line);
		}
		const_iterator cvbegin(const_reverse_iterator it) noexcept
		{
			return const_iterator(const_cast<pointer>(it.operator->()), _line);
		}
		const_iterator cvbegin(const_iterator it) const noexcept
		{
			return const_iterator(const_cast<pointer>(it.operator->()), _line);
		}
		const_iterator cvbegin(const_reverse_iterator it) const noexcept
		{
			return const_iterator(const_cast<pointer>(it.operator->()), _line);
		}
		iterator vend(iterator it) noexcept
		{
			return iterator(it.operator->() + _plane, _line);
		}
		iterator vend(reverse_iterator it) noexcept
		{
			return iterator(it.operator->() + _plane, _line);
		}
		const_iterator vend(const_iterator it) noexcept
		{
			return const_iterator(const_cast<pointer>(it.operator->() + _plane), _line);
		}
		const_iterator vend(const_reverse_iterator it) noexcept
		{
			return const_iterator(const_cast<pointer>(it.operator->() + _plane), _line);
		}
		const_iterator vend(const_iterator it) const noexcept
		{
			return const_iterator(const_cast<pointer>(it.operator->() + _plane), _line);
		}
		const_iterator vend(const_reverse_iterator it) const noexcept
		{
			return const_iterator(const_cast<pointer>(it.operator->() + _plane), _line);
		}
		const_iterator cvend(iterator it) noexcept
		{
			return const_iterator(it.operator->() + _plane, _line);
		}
		const_iterator cvend(reverse_iterator it) noexcept
		{
			return const_iterator(it.operator->() + _plane, _line);
		}
		const_iterator cvend(const_iterator it) noexcept
		{
			return const_iterator(const_cast<pointer>(it.operator->() + _plane), _line);
		}
		const_iterator cvend(const_reverse_iterator it) noexcept
		{
			return const_iterator(const_cast<pointer>(it.operator->() + _plane), _line);
		}
		const_iterator cvend(const_iterator it) const noexcept
		{
			return const_iterator(const_cast<pointer>(it.operator->() + _plane), _line);
		}
		const_iterator cvend(const_reverse_iterator it) const noexcept
		{
			return const_iterator(const_cast<pointer>(it.operator->() + _plane), _line);
		}
		reverse_iterator rvbegin(iterator it) noexcept
		{
			return reverse_iterator(vend(it));
		}
		reverse_iterator rvbegin(reverse_iterator it) noexcept
		{
			return reverse_iterator(vend(it));
		}
		const_reverse_iterator rvbegin(const_iterator it) noexcept
		{
			return const_reverse_iterator(vend(it));
		}
		const_reverse_iterator rvbegin(const_reverse_iterator it) noexcept
		{
			return const_reverse_iterator(vend(it));
		}
		const_reverse_iterator rvbegin(const_iterator it) const noexcept
		{
			return const_reverse_iterator(vend(it));
		}
		const_reverse_iterator rvbegin(const_reverse_iterator it) const noexcept
		{
			return const_reverse_iterator(vend(it));
		}
		const_reverse_iterator crvbegin(iterator it) noexcept
		{
			return const_reverse_iterator(cvend(it));
		}
		const_reverse_iterator crvbegin(reverse_iterator it) noexcept
		{
			return const_reverse_iterator(cvend(it));
		}
		const_reverse_iterator crvbegin(const_iterator it) noexcept
		{
			return const_reverse_iterator(cvend(it));
		}
		const_reverse_iterator crvbegin(const_reverse_iterator it) noexcept
		{
			return const_reverse_iterator(cvend(it));
		}
		const_reverse_iterator crvbegin(const_iterator it) const noexcept
		{
			return const_reverse_iterator(cvend(it));
		}
		const_reverse_iterator crvbegin(const_reverse_iterator it) const noexcept
		{
			return const_reverse_iterator(cvend(it));
		}
		reverse_iterator rvend(iterator it) noexcept
		{
			return reverse_iterator(vbegin(it));
		}
		reverse_iterator rvend(reverse_iterator it) noexcept
		{
			return reverse_iterator(vbegin(it));
		}
		const_reverse_iterator rvend(const_iterator it) noexcept
		{
			return const_reverse_iterator(vbegin(it));
		}
		const_reverse_iterator rvend(const_reverse_iterator it) noexcept
		{
			return const_reverse_iterator(vbegin(it));
		}
		const_reverse_iterator rvend(const_iterator it) const noexcept
		{
			return const_reverse_iterator(vbegin(it));
		}
		const_reverse_iterator rvend(const_reverse_iterator it) const noexcept
		{
			return const_reverse_iterator(vbegin(it));
		}
		const_reverse_iterator crvend(iterator it) noexcept
		{
			return const_reverse_iterator(cvbegin(it));
		}
		const_reverse_iterator crvend(reverse_iterator it) noexcept
		{
			return const_reverse_iterator(cvbegin(it));
		}
		const_reverse_iterator crvend(const_iterator it) noexcept
		{
			return const_reverse_iterator(cvbegin(it));
		}
		const_reverse_iterator crvend(const_reverse_iterator it) noexcept
		{
			return const_reverse_iterator(cvbegin(it));
		}
		const_reverse_iterator crvend(const_iterator it) const noexcept
		{
			return const_reverse_iterator(cvbegin(it));
		}
		const_reverse_iterator crvend(const_reverse_iterator it) const noexcept
		{
			return const_reverse_iterator(cvbegin(it));
		}

		iterator begin(iterator it) noexcept
		{
			return iterator(it.operator->(), _dim);
		}
		iterator begin(reverse_iterator it) noexcept
		{
			return iterator(it.operator->(), _dim);
		}
		const_iterator begin(const_iterator it) noexcept
		{
			return const_iterator(const_cast<pointer>(it.operator->()), _dim);
		}
		const_iterator begin(const_reverse_iterator it) noexcept
		{
			return const_iterator(const_cast<pointer>(it.operator->()), _dim);
		}
		const_iterator begin(const_iterator it) const noexcept
		{
			return const_iterator(const_cast<pointer>(it.operator->()), _dim);
		}
		const_iterator begin(const_reverse_iterator it) const noexcept
		{
			return const_iterator(const_cast<pointer>(it.operator->()), _dim);
		}
		const_iterator cbegin(iterator it) noexcept
		{
			return const_iterator(it.operator->(), _dim);
		}
		const_iterator cbegin(reverse_iterator it) noexcept
		{
			return const_iterator(it.operator->(), _dim);
		}
		const_iterator cbegin(const_iterator it) noexcept
		{
			return const_iterator(const_cast<pointer>(it.operator->()), _dim);
		}
		const_iterator cbegin(const_reverse_iterator it) noexcept
		{
			return const_iterator(const_cast<pointer>(it.operator->()), _dim);
		}
		const_iterator cbegin(const_iterator it) const noexcept
		{
			return const_iterator(const_cast<pointer>(it.operator->()), _dim);
		}
		const_iterator cbegin(const_reverse_iterator it) const noexcept
		{
			return const_iterator(const_cast<pointer>(it.operator->()), _dim);
		}
		iterator end(iterator it) noexcept
		{
			return iterator(it.operator->() + _line, _dim);
		}
		iterator end(reverse_iterator it) noexcept
		{
			return iterator(it.operator->() + _line, _dim);
		}
		const_iterator end(const_iterator it) noexcept
		{
			return const_iterator(const_cast<pointer>(it.operator->() + _line), _dim);
		}
		const_iterator end(const_reverse_iterator it) noexcept
		{
			return const_iterator(const_cast<pointer>(it.operator->() + _line), _dim);
		}
		const_iterator end(const_iterator it) const noexcept
		{
			return const_iterator(const_cast<pointer>(it.operator->() + _line), _dim);
		}
		const_iterator end(const_reverse_iterator it) const noexcept
		{
			return const_iterator(const_cast<pointer>(it.operator->() + _line), _dim);
		}
		const_iterator cend(iterator it) noexcept
		{
			return const_iterator(it.operator->() + _line, _dim);
		}
		const_iterator cend(reverse_iterator it) noexcept
		{
			return const_iterator(it.operator->() + _line, _dim);
		}
		const_iterator cend(const_iterator it) noexcept
		{
			return const_iterator(const_cast<pointer>(it.operator->() + _line), _dim);
		}
		const_iterator cend(const_reverse_iterator it) noexcept
		{
			return const_iterator(const_cast<pointer>(it.operator->() + _line), _dim);
		}
		const_iterator cend(const_iterator it) const noexcept
		{
			return const_iterator(const_cast<pointer>(it.operator->() + _line), _dim);
		}
		const_iterator cend(const_reverse_iterator it) const noexcept
		{
			return const_iterator(const_cast<pointer>(it.operator->() + _line), _dim);
		}
		reverse_iterator rbegin(iterator it) noexcept
		{
			return reverse_iterator(end(it));
		}
		reverse_iterator rbegin(reverse_iterator it) noexcept
		{
			return reverse_iterator(end(it));
		}
		const_reverse_iterator rbegin(const_iterator it) noexcept
		{
			return const_reverse_iterator(end(it));
		}
		const_reverse_iterator rbegin(const_reverse_iterator it) noexcept
		{
			return const_reverse_iterator(end(it));
		}
		const_reverse_iterator rbegin(const_iterator it) const noexcept
		{
			return const_reverse_iterator(end(it));
		}
		const_reverse_iterator rbegin(const_reverse_iterator it) const noexcept
		{
			return const_reverse_iterator(end(it));
		}
		const_reverse_iterator crbegin(iterator it) noexcept
		{
			return const_reverse_iterator(cend(it));
		}
		const_reverse_iterator crbegin(reverse_iterator it) noexcept
		{
			return const_reverse_iterator(cend(it));
		}
		const_reverse_iterator crbegin(const_iterator it) noexcept
		{
			return const_reverse_iterator(cend(it));
		}
		const_reverse_iterator crbegin(const_reverse_iterator it) noexcept
		{
			return const_reverse_iterator(cend(it));
		}
		const_reverse_iterator crbegin(const_iterator it) const noexcept
		{
			return const_reverse_iterator(cend(it));
		}
		const_reverse_iterator crbegin(const_reverse_iterator it) const noexcept
		{
			return const_reverse_iterator(cend(it));
		}
		reverse_iterator rend(iterator it) noexcept
		{
			return reverse_iterator(begin(it));
		}
		reverse_iterator rend(reverse_iterator it) noexcept
		{
			return reverse_iterator(begin(it));
		}
		const_reverse_iterator rend(const_iterator it) noexcept
		{
			return const_reverse_iterator(begin(it));
		}
		const_reverse_iterator rend(const_reverse_iterator it) noexcept
		{
			return const_reverse_iterator(begin(it));
		}
		const_reverse_iterator rend(const_iterator it) const noexcept
		{
			return const_reverse_iterator(begin(it));
		}
		const_reverse_iterator rend(const_reverse_iterator it) const noexcept
		{
			return const_reverse_iterator(begin(it));
		}
		const_reverse_iterator crend(iterator it) noexcept
		{
			return const_reverse_iterator(cbegin(it));
		}
		const_reverse_iterator crend(reverse_iterator it) noexcept
		{
			return const_reverse_iterator(cbegin(it));
		}
		const_reverse_iterator crend(const_iterator it) noexcept
		{
			return const_reverse_iterator(cbegin(it));
		}
		const_reverse_iterator crend(const_reverse_iterator it) noexcept
		{
			return const_reverse_iterator(cbegin(it));
		}
		const_reverse_iterator crend(const_iterator it) const noexcept
		{
			return const_reverse_iterator(cbegin(it));
		}
		const_reverse_iterator crend(const_reverse_iterator it) const noexcept
		{
			return const_reverse_iterator(cbegin(it));
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

		size_type cols(void) const noexcept
		{
			return _cols;
		}

		size_type rows(void) const noexcept
		{
			return _rows;
		}

		size_type num(void) const noexcept
		{
			return _num;
		}

		size_type area(void) const noexcept
		{
			return (_rows * _cols);
		}

		size_type volume(void) const noexcept
		{
			return (_num * _rows * _cols);
		}

		size_type row_size(void) const noexcept
		{
			return _line;
		}

		size_type matrix_size(void) const noexcept
		{
			return _plane;
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

		matrix_type operator[](size_type i) noexcept
		{
			return matrix_type(_rows, _cols, _dim, _data + i * _plane, false);
		}
		const_matrix_type operator[](size_type i) const noexcept
		{
			return const_matrix_type(_rows, _cols, _dim, _data + i * _plane, false);
		}

		matrix_type at(size_type i)
		{
			if (empty())
				throw std::domain_error(TENSOR_NOT_INITIALIZED);
			if (i >= _num)
				throw std::out_of_range(TENSOR_OUT_OF_RANGE);
			return matrix_type(_rows, _cols, _dim, _data + i * _plane, false);
		}
		const_matrix_type at(size_type i) const
		{
			if (empty())
				throw std::domain_error(TENSOR_NOT_INITIALIZED);
			if (i >= _num)
				throw std::out_of_range(TENSOR_OUT_OF_RANGE);
			return const_matrix_type(_rows, _cols, _dim, _data + i * _plane, false);
		}

		pointer data(void) noexcept
		{
			return static_cast<pointer>(_data);
		}
		const_pointer data(void) const noexcept
		{
			return static_cast<const_pointer>(_data);
		}
		pointer data(size_type num) noexcept
		{
			return static_cast<pointer>(_data + num * _plane);
		}
		const_pointer data(size_type num) const noexcept
		{
			return static_cast<const_pointer>(_data + num * _plane);
		}
		pointer data(size_type num, size_type row) noexcept
		{
			return static_cast<pointer>(_data + num * _plane + row * _line);
		}
		const_pointer data(size_type num, size_type row) const noexcept
		{
			return static_cast<const_pointer>(_data + num * _plane + row * _line);
		}
		pointer data(size_type num, size_type row, size_type column) noexcept
		{
			return static_cast<pointer>(_data + num * _plane + row * _line + column * _dim);
		}
		const_pointer data(size_type num, size_type row, size_type column) const noexcept
		{
			return static_cast<const_pointer>(_data + num * _plane + row * _line + column * _dim);
		}
		pointer data(size_type num, size_type row, size_type column, size_type dim) noexcept
		{
			return static_cast<pointer>(_data + num * _plane + row * _line + column * _dim + dim);
		}
		const_pointer data(size_type num, size_type row, size_type column, size_type dim) const noexcept
		{
			return static_cast<const_pointer>(_data + num * _plane + row * _line + column * _dim + dim);
		}

		scalar_type scalar(iterator it) noexcept
		{
			return scalar_type(_dim, it.operator->(), false);
		}
		scalar_type scalar(reverse_iterator it) noexcept
		{
			return scalar_type(_dim, it.operator->(), false);
		}
		const_scalar_type scalar(const_iterator it) noexcept
		{
			return const_scalar_type(_dim, const_cast<pointer>(it.operator->()), false);
		}
		const_scalar_type scalar(const_reverse_iterator it) noexcept
		{
			return const_scalar_type(_dim, const_cast<pointer>(it.operator->()), false);
		}
		const_scalar_type scalar(const_iterator it) const noexcept
		{
			return const_scalar_type(_dim, const_cast<pointer>(it.operator->()), false);
		}
		const_scalar_type scalar(const_reverse_iterator it) const noexcept
		{
			return const_scalar_type(_dim, const_cast<pointer>(it.operator->()), false);
		}

		vector_type vector(iterator it) noexcept
		{
			return vector_type(_cols, _dim, it.operator->(), false);
		}
		vector_type vector(reverse_iterator it) noexcept
		{
			return vector_type(_cols, _dim, it.operator->(), false);
		}
		const_vector_type vector(const_iterator it) noexcept
		{
			return const_vector_type(_cols, _dim, const_cast<pointer>(it.operator->()), false);
		}
		const_vector_type vector(const_reverse_iterator it) noexcept
		{
			return const_vector_type(_cols, _dim, const_cast<pointer>(it.operator->()), false);
		}
		const_vector_type vector(const_iterator it) const noexcept
		{
			return const_vector_type(_cols, _dim, const_cast<pointer>(it.operator->()), false);
		}
		const_vector_type vector(const_reverse_iterator it) const noexcept
		{
			return const_vector_type(_cols, _dim, const_cast<pointer>(it.operator->()), false);
		}

		matrix_type matrix(iterator it) noexcept
		{
			return matrix_type(_rows, _cols, _dim, it.operator->(), false);
		}
		matrix_type matrix(reverse_iterator it) noexcept
		{
			return matrix_type(_rows, _cols, _dim, it.operator->(), false);
		}
		const_matrix_type matrix(const_iterator it) noexcept
		{
			return const_matrix_type(_rows, _cols, _dim, const_cast<pointer>(it.operator->()), false);
		}
		const_matrix_type matrix(const_reverse_iterator it) noexcept
		{
			return const_matrix_type(_rows, _cols, _dim, const_cast<pointer>(it.operator->()), false);
		}
		const_matrix_type matrix(const_iterator it) const noexcept
		{
			return const_matrix_type(_rows, _cols, _dim, const_cast<pointer>(it.operator->()), false);
		}
		const_matrix_type matrix(const_reverse_iterator it) const noexcept
		{
			return const_matrix_type(_rows, _cols, _dim, const_cast<pointer>(it.operator->()), false);
		}

		// modifiers:

		void fill(const value_type& value)
		{
			if (empty())
				throw std::domain_error(TENSOR_NOT_INITIALIZED);
			std::fill_n(_data, _count, value);
		}

		void fill_n(size_type n, const value_type& value)
		{
			if (empty())
				throw std::domain_error(TENSOR_NOT_INITIALIZED);
			if (n == 0 || n > _count)
				throw std::invalid_argument(INVALID_LENGTH);
			std::fill_n(_data, n, value);
		}

		template <class InputIterator>
		void fill(InputIterator first, InputIterator last)
		{
			if (empty())
				throw std::domain_error(TENSOR_NOT_INITIALIZED);
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
				throw std::domain_error(TENSOR_NOT_INITIALIZED);
			if (scalar.empty())
				throw std::domain_error(SCALAR_NOT_INITIALIZED);
			if (scalar.size() != _dim)
				throw std::invalid_argument(INVALID_DIMENSION);
			pointer current = _data;
			size_type number = volume();
			const_pointer first = scalar.data();
			const_pointer last = first + scalar.size();
			for (size_type i = 0; i < number; ++i)
			{
				std::copy(first, last, current);
				current += _dim;
			}
		}

		void fill(const vector_type& vector)
		{
			if (empty())
				throw std::domain_error(TENSOR_NOT_INITIALIZED);
			if (vector.empty())
				throw std::domain_error(VECTOR_NOT_INITIALIZED);
			if (vector.size() != _line)
				throw std::invalid_argument(INVALID_SIZE);
			pointer current = _data;
			size_type number = _num * _rows;
			const_pointer first = vector.data();
			const_pointer last = first + vector.size();
			for (size_type i = 0; i < number; ++i)
			{
				std::copy(first, last, current);
				current += _line;
			}
		}

		void fill(const matrix_type& matrix)
		{
			if (empty())
				throw std::domain_error(TENSOR_NOT_INITIALIZED);
			if (matrix.empty())
				throw std::domain_error(MATRIX_NOT_INITIALIZED);
			if (matrix.size() != _plane)
				throw std::invalid_argument(INVALID_SIZE);
			pointer current = _data;
			const_pointer first = matrix.data();
			const_pointer last = first + matrix.size();
			for (size_type i = 0; i < _num; ++i)
			{
				std::copy(first, last, current);
				current += _plane;
			}
		}

		void fill(const tensor<T, Allocator>& other)
		{
			if (empty() || other.empty())
				throw std::domain_error(TENSOR_NOT_INITIALIZED);
			if (_count != other.size())
				throw std::invalid_argument(INVALID_SIZE);
			std::copy(other._data, other._data + _count, _data);
		}

		template<class Generator>
		void generate(Generator g)
		{
			if (empty())
				throw std::domain_error(TENSOR_NOT_INITIALIZED);
			for (size_type i = 0; i < _count; ++i)
				_data[i] = g();
		}

		void shape(size_type num, size_type rows, size_type cols, size_type dim)
		{
			if (empty())
				throw std::domain_error(TENSOR_NOT_INITIALIZED);
			if (num * rows * cols * dim != _count)
				throw std::invalid_argument(INVALID_TENSOR_SIZE);
			_dim = dim;
			_cols = cols;
			_rows = rows;
			_num = num;
			_line = _cols * _dim;
			_plane = _rows * _line;
			_count = _num * _plane;
		}

		tensor<T, Allocator> reshape(size_type num, size_type rows, size_type cols, size_type dim) const
		{
			if (empty())
				throw std::domain_error(TENSOR_NOT_INITIALIZED);
			if (num * rows * cols * dim != _count)
				throw std::invalid_argument(INVALID_TENSOR_SIZE);
			return tensor<T, Allocator>(num, rows, cols, dim, _data);
		}

		void swap(tensor<T, Allocator>& rhs) noexcept
		{
			if (this != &rhs)
			{
				std::swap(_owner, rhs._owner);
				std::swap(_dim, rhs._dim);
				std::swap(_cols, rhs._cols);
				std::swap(_rows, rhs._rows);
				std::swap(_num, rhs._num);
				std::swap(_line, rhs._line);
				std::swap(_plane, rhs._plane);
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
			_cols = 0;
			_rows = 0;
			_num = 0;
			_line = 0;
			_plane = 0;
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
		friend bool operator<(const tensor<T, Allocator>& lhs, const tensor<T, A>& rhs)
		{
			if (lhs.size() != rhs.size())
				throw std::invalid_argument(TENSOR_DIFFERENT_SIZE);
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
		friend bool operator>(const tensor<T, Allocator>& lhs, const tensor<T, A>& rhs)
		{
			return (rhs < lhs);
		}
		template <class A>
		friend bool operator<=(const tensor<T, Allocator>& lhs, const tensor<T, A>& rhs)
		{
			return !(lhs > rhs);
		}
		template <class A>
		friend bool operator>=(const tensor<T, Allocator>& lhs, const tensor<T, A>& rhs)
		{
			return !(lhs < rhs);
		}

		template <class A>
		friend bool operator==(const tensor<T, Allocator>& lhs, const tensor<T, A>& rhs)
		{
			if (lhs.size() != rhs.size())
				throw std::invalid_argument(TENSOR_DIFFERENT_SIZE);
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
		friend bool operator!=(const tensor<T, Allocator>& lhs, const tensor<T, A>& rhs)
		{
			return !(lhs == rhs);
		}
	private:
		void assign_rv(tensor<T, Allocator>&& right, std::true_type)
		{
			swap(right);
		}
		void assign_rv(tensor<T, Allocator>&& right, std::false_type)
		{
			if (get_allocator() == right.get_allocator())
				assign_rv(std::forward<tensor<T, Allocator> >(right), std::true_type());
			else
				assign(right, DEEP_COPY);
		}
	private:
		bool       _owner;
		size_type  _dim;
		size_type  _cols;
		size_type  _rows;
		size_type  _num;
		size_type  _line;
		size_type  _plane;
		size_type  _count;
		pointer    _data;
	};

} // namespace core

#endif
