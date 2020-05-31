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

#ifndef __CORE_MATRIX_H__
#define __CORE_MATRIX_H__

#include <memory>
#include <stdexcept>
#include "define.h"
#include "scalar.h"
#include "vector.h"

#ifndef DEFAULT_ALLOCATOR
#define DEFAULT_ALLOCATOR(T) std::allocator<T>
#endif // !DEFAULT_ALLOCATOR

namespace core
{
	template <class T, class Allocator> class matrix;

	// Specialize for void
	template <class Allocator>
	class matrix<void, Allocator>
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
			using other = matrix<U, Allocator>;
		};
	};

	// Class template matrix_type_traits

	template <class Matrix, bool IsConst>
	struct matrix_type_traits
	{
		using value_type      = typename Matrix::value_type;
		using pointer         = typename Matrix::pointer;
		using size_type       = typename Matrix::size_type;
		using difference_type = typename Matrix::difference_type;
		using reference       = value_type&;
	};

	template <class Matrix>
	struct matrix_type_traits<Matrix, true>
	{
		using value_type      = typename Matrix::value_type;
		using pointer         = typename Matrix::const_pointer;
		using size_type       = typename Matrix::size_type;
		using difference_type = typename Matrix::difference_type;
		using reference       = const value_type&;
	};

	// Class template matrix_iterator
	template <class Matrix, bool IsConst>
	class matrix_iterator
	{
	public:
		// types:

		using value_type        = typename matrix_type_traits<Matrix, IsConst>::value_type;
		using pointer           = typename matrix_type_traits<Matrix, IsConst>::pointer;
		using reference         = typename matrix_type_traits<Matrix, IsConst>::reference;
		using size_type         = typename matrix_type_traits<Matrix, IsConst>::size_type;
		using difference_type   = typename matrix_type_traits<Matrix, IsConst>::difference_type;

		using iterator_type     = matrix_iterator<Matrix, IsConst>;
		using iterator_category = std::bidirectional_iterator_tag;

		// construct/copy/destroy:

		matrix_iterator(void) noexcept
			: step(0)
			, ptr(nullptr)
		{}
		explicit matrix_iterator(pointer p, size_type stride) noexcept
			: step(stride)
			, ptr(p)
		{}
		matrix_iterator(const matrix_iterator<Matrix, IsConst>& other) noexcept
			: step(other.step)
			, ptr(other.ptr)
		{}

		matrix_iterator<Matrix, IsConst>& operator=(const matrix_iterator<Matrix, IsConst>& other) noexcept
		{
			if (this != &other)
			{
				step = other.step;
				ptr = other.ptr;
			}
			return (*this);
		}

		operator matrix_iterator<Matrix, true>(void) const noexcept
		{
			return matrix_iterator<Matrix, true>(ptr, step);
		}

		// matrix_iterator operations:

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

		// increment / decrement

		matrix_iterator<Matrix, IsConst>& operator++(void) noexcept
		{
			ptr += step;
			return *this;
		}
		matrix_iterator<Matrix, IsConst>& operator--(void) noexcept
		{
			ptr -= step;
			return *this;
		}
		matrix_iterator<Matrix, IsConst> operator++(int) noexcept
		{
			matrix_iterator tmp(*this);
			++(*this);
			return tmp;
		}
		matrix_iterator<Matrix, IsConst> operator--(int) noexcept
		{
			matrix_iterator tmp(*this);
			--(*this);
			return tmp;
		}
		matrix_iterator<Matrix, IsConst>& operator+=(difference_type n) noexcept
		{
			ptr += (n * step);
			return *this;
		}
		matrix_iterator<Matrix, IsConst>& operator-=(difference_type n) noexcept
		{
			ptr -= (n * step);
			return *this;
		}

		// relational operators:

		template <bool b>
		bool operator==(const matrix_iterator<Matrix, b>& rhs) const noexcept
		{
			return (ptr == rhs.operator->());
		}
		template <bool b>
		bool operator!=(const matrix_iterator<Matrix, b>& rhs) const noexcept
		{
			return (ptr != rhs.operator->());
		}
	private:
		size_type step;
		pointer   ptr;
	};

	// Class template matrix
	template <class T, class Allocator = DEFAULT_ALLOCATOR(T)>
	class matrix : public Allocator
	{
	public:
		// types:

		using allocator_type         = Allocator;
		using scalar_type            = core::scalar<T, Allocator>;
		using const_scalar_type      = const scalar_type;
		using vector_type            = core::vector<T, Allocator>;
		using const_vector_type      = const vector_type;
		using allocator_traits_type  = std::allocator_traits<allocator_type>;
		using value_type             = typename allocator_traits_type::value_type;
		using pointer                = typename allocator_traits_type::pointer;
		using const_pointer          = typename allocator_traits_type::const_pointer;
		using size_type              = typename allocator_traits_type::size_type;
		using difference_type        = typename allocator_traits_type::difference_type;

		using iterator               = matrix_iterator<matrix<T, Allocator>, false>;
		using const_iterator         = matrix_iterator<matrix<T, Allocator>, true>;
		using reverse_iterator       = std::reverse_iterator<iterator>;
		using const_reverse_iterator = std::reverse_iterator<const_iterator>;

		template <class U>
		struct rebind
		{
			using other = matrix<U, Allocator>;
		};

		// construct/copy/destroy:

		explicit matrix(const Allocator& alloc = Allocator())
			: Allocator(alloc)
			, _owner(true)
			, _dim(0)
			, _cols(0)
			, _rows(0)
			, _line(0)
			, _count(0)
			, _data(nullptr)
		{}
		explicit matrix(size_type rows, size_type cols, size_type dim)
			: Allocator()
			, _owner(true)
			, _dim(0)
			, _cols(0)
			, _rows(0)
			, _line(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(rows, cols, dim);
		}
		matrix(size_type rows, size_type cols, size_type dim, const value_type& value, const Allocator& alloc = Allocator())
			: Allocator(alloc)
			, _owner(true)
			, _dim(0)
			, _cols(0)
			, _rows(0)
			, _line(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(rows, cols, dim, value);
		}
		matrix(size_type rows, size_type cols, size_type dim, const_pointer p, const Allocator& alloc = Allocator())
			: Allocator(alloc)
			, _owner(true)
			, _dim(0)
			, _cols(0)
			, _rows(0)
			, _line(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(rows, cols, dim, p);
		}
		matrix(size_type rows, size_type cols, size_type dim, pointer p, bool copy_data, const Allocator& alloc = Allocator())
			: Allocator(alloc)
			, _owner(true)
			, _dim(0)
			, _cols(0)
			, _rows(0)
			, _line(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(rows, cols, dim, p, copy_data);
		}
		template <class InputIterator>
		matrix(size_type rows, size_type cols, size_type dim, InputIterator first, InputIterator last, const Allocator& alloc = Allocator())
			: Allocator(alloc)
			, _owner(true)
			, _dim(0)
			, _cols(0)
			, _rows(0)
			, _line(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(rows, cols, dim, last, last);
		}
		matrix(const matrix<T, Allocator>& other)
			: Allocator(other.get_allocator())
			, _owner(true)
			, _dim(0)
			, _cols(0)
			, _rows(0)
			, _line(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(other, DEEP_COPY);
		}
		matrix(matrix<T, Allocator>& other, copy_mode_type copy_mode)
			: Allocator(other.get_allocator())
			, _owner(true)
			, _dim(0)
			, _cols(0)
			, _rows(0)
			, _line(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(other, copy_mode);
		}
		matrix(matrix<T, Allocator>&& other)
			: Allocator(other.get_allocator())
			, _owner(true)
			, _dim(0)
			, _cols(0)
			, _rows(0)
			, _line(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(std::forward<matrix<T, Allocator> >(other));
		}
		matrix(const matrix<T, Allocator>& other, const Allocator& alloc, copy_mode_type copy_mode = DEEP_COPY)
			: Allocator(alloc)
			, _owner(true)
			, _dim(0)
			, _cols(0)
			, _rows(0)
			, _line(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(other, copy_mode);
		}
		matrix(matrix<T, Allocator>& other, const Allocator& alloc, copy_mode_type copy_mode = DEEP_COPY)
			: Allocator(alloc)
			, _owner(true)
			, _dim(0)
			, _cols(0)
			, _rows(0)
			, _line(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(other, copy_mode);
		}
		matrix(matrix<T, Allocator>&& other, const Allocator& alloc)
			: Allocator(alloc)
			, _owner(true)
			, _dim(0)
			, _cols(0)
			, _rows(0)
			, _line(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(std::forward<matrix<T, Allocator> >(other));
		}
		matrix(size_type rows, size_type cols, size_type dim, std::initializer_list<T> il, const Allocator& alloc = Allocator())
			: Allocator(alloc)
			, _owner(true)
			, _dim(0)
			, _cols(0)
			, _rows(0)
			, _line(0)
			, _count(0)
			, _data(nullptr)
		{
			assign(rows, cols, dim, il);
		}
		~matrix(void)
		{
			clear();
		}
		matrix<T, Allocator>& operator=(const matrix<T, Allocator>& other)
		{
			if (this != &other)
			{
				clear();
				assign(other, DEEP_COPY);
			}
			return (*this);
		}
		matrix<T, Allocator>& operator=(matrix<T, Allocator>&& other)
		{
			if (this != &other)
				assign(std::forward<matrix<T, Allocator> >(other));
			return (*this);
		}

		void assign(size_type rows, size_type cols, size_type dim)
		{
			if (!empty())
				throw std::domain_error(MATRIX_IS_INITIALIZED);
			if (rows == 0 || cols == 0 || dim == 0)
				throw std::invalid_argument(INVALID_MATRIX_SIZE);
			_owner = true;
			_dim = dim;
			_cols = cols;
			_rows = rows;
			_line = _cols * _dim;
			_count = _rows * _line;
			_data = this->allocate(_count);
			std::uninitialized_default_construct_n(_data, _count);
		}

		void assign(size_type rows, size_type cols, size_type dim, const value_type& value)
		{
			if (!empty())
				throw std::domain_error(MATRIX_IS_INITIALIZED);
			if (rows == 0 || cols == 0 || dim == 0)
				throw std::invalid_argument(INVALID_MATRIX_SIZE);
			_owner = true;
			_dim = dim;
			_cols = cols;
			_rows = rows;
			_line = _cols * _dim;
			_count = _rows * _line;
			_data = this->allocate(_count);
			std::uninitialized_fill_n(_data, _count, value);
		}

		void assign(size_type rows, size_type cols, size_type dim, const_pointer p)
		{
			if (!empty())
				throw std::domain_error(MATRIX_IS_INITIALIZED);
			if (rows == 0 || cols == 0 || dim == 0)
				throw std::invalid_argument(INVALID_MATRIX_SIZE);
			_owner = true;
			_dim = dim;
			_cols = cols;
			_rows = rows;
			_line = _cols * _dim;
			_count = _rows * _line;
			_data = this->allocate(_count);
			std::uninitialized_copy(p, p + _count, _data);
		}

		void assign(size_type rows, size_type cols, size_type dim, pointer p, bool copy_data)
		{
			if (!empty())
				throw std::domain_error(MATRIX_IS_INITIALIZED);
			if (rows == 0 || cols == 0 || dim == 0)
				throw std::invalid_argument(INVALID_MATRIX_SIZE);
			_owner = copy_data;
			_dim = dim;
			_cols = cols;
			_rows = rows;
			_line = _cols * _dim;
			_count = _rows * _line;
			if (copy_data)
			{
				_data = this->allocate(_count);
				std::uninitialized_copy(p, p + _count, _data);
			}
			else
				_data = p;
		}

		template <class InputIterator>
		void assign(size_type rows, size_type cols, size_type dim, InputIterator first, InputIterator last)
		{
			if (!empty())
				throw std::domain_error(MATRIX_IS_INITIALIZED);
			if (rows == 0 || cols == 0 || dim == 0)
				throw std::invalid_argument(INVALID_MATRIX_SIZE);
			if (std::distance(first, last) != rows * cols * dim)
				throw std::invalid_argument(INVALID_INITIALIZER_LIST);
			_owner = true;
			_dim = dim;
			_cols = cols;
			_rows = rows;
			_line = _cols * _dim;
			_count = _rows * _line;
			_data = this->allocate(_count);
			std::uninitialized_copy(first, last, _data);
		}

		void assign(size_type rows, size_type cols, size_type dim, std::initializer_list<T> il)
		{
			assign(rows, cols, dim, il.begin(), il.end());
		}

		void assign(const matrix<T, Allocator>& other, copy_mode_type copy_mode)
		{
			if (!empty())
				throw std::domain_error(MATRIX_IS_INITIALIZED);
			if (other.empty())
				throw std::domain_error(MATRIX_NOT_INITIALIZED);
			if (copy_mode == SHALLOW_COPY)
				throw std::invalid_argument(INVALID_COPY_MODE);
			_owner = true;
			_dim = other._dim;
			_cols = other._cols;
			_rows = other._rows;
			_line = other._line;
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

		void assign(matrix<T, Allocator>& other, copy_mode_type copy_mode)
		{
			if (!empty())
				throw std::domain_error(MATRIX_IS_INITIALIZED);
			if (other.empty())
				throw std::domain_error(MATRIX_NOT_INITIALIZED);
			_dim = other._dim;
			_cols = other._cols;
			_rows = other._rows;
			_line = other._line;
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

		void assign(matrix<T, Allocator>&& other)
		{
			assign_rv(std::forward<matrix<T, Allocator> >(other), typename allocator_traits_type::propagate_on_container_move_assignment());
		}

		void reassign(size_type rows, size_type cols, size_type dim)
		{
			if (rows == 0 || cols == 0 || dim == 0)
				throw std::invalid_argument(INVALID_MATRIX_SIZE);
			size_type line = cols * dim;
			size_type count = rows * line;
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
				_line = line;
				_count = count;
				_data = this->allocate(_count);
				std::uninitialized_default_construct_n(_data, _count);
			}
		}

		void reassign(size_type rows, size_type cols, size_type dim, const value_type& value)
		{
			if (rows == 0 || cols == 0 || dim == 0)
				throw std::invalid_argument(INVALID_MATRIX_SIZE);
			size_type line = cols * dim;
			size_type count = rows * line;
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
				_line = line;
				_count = count;
				_data = this->allocate(_count);
				std::uninitialized_fill_n(_data, _count, value);
			}
			else
				std::fill_n(_data, _count, value);
		}

		template <class InputIterator>
		void reassign(size_type rows, size_type cols, size_type dim, const_pointer p)
		{
			if (rows == 0 || cols == 0 || dim == 0)
				throw std::invalid_argument(INVALID_MATRIX_SIZE);
			size_type line = cols * dim;
			size_type count = rows * line;
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
				_line = line;
				_count = count;
				_data = this->allocate(_count);
				std::uninitialized_copy(p, p + _count, _data);
			}
			else
				std::copy(p, p + _count, _data);
		}

		template <class InputIterator>
		void reassign(size_type rows, size_type cols, size_type dim, pointer p, bool copy_data)
		{
			if (rows == 0 || cols == 0 || dim == 0)
				throw std::invalid_argument(INVALID_MATRIX_SIZE);
			size_type line = _cols * _dim;
			size_type count = _rows * _line;
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
					_line = line;
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
				_line = line;
				_count = count;
				_data = p;
			}
		}

		template <class InputIterator>
		void reassign(size_type rows, size_type cols, size_type dim, InputIterator first, InputIterator last)
		{
			if (rows == 0 || cols == 0 || dim == 0)
				throw std::invalid_argument(INVALID_MATRIX_SIZE);
			if (std::distance(first, last) != rows * cols * dim)
				throw std::invalid_argument(INVALID_INITIALIZER_LIST);
			size_type line = _cols * _dim;
			size_type count = _rows * _line;
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
				_line = line;
				_count = count;
				_data = this->allocate(_count);
				std::uninitialized_copy(first, last, _data);
			}
			else
				std::copy(first, last, _data);
		}

		void reassign(size_type rows, size_type cols, size_type dim, std::initializer_list<T> il)
		{
			reassign(rows, cols, dim, il.begin(), il.end());
		}

		void reassign(const matrix<T, Allocator>& other, copy_mode_type copy_mode)
		{
			if (other.empty())
				throw std::domain_error(MATRIX_NOT_INITIALIZED);
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
					_line = other._line;
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
					_line = other._line;
					_count = other._count;
					_data = this->allocate(_count);
					std::uninitialized_copy(other._data, other._data + _count, _data);
				}
				else
					std::copy(other._data, other._data + _count, _data);
				break;
			}
		}

		void reassign(matrix<T, Allocator>& other, copy_mode_type copy_mode)
		{
			if (other.empty())
				throw std::domain_error(MATRIX_NOT_INITIALIZED);
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
					_line = other._line;
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
				_line = other._line;
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
					_line = other._line;
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

		iterator vbegin(void) noexcept
		{
			return iterator(_data, _line);
		}
		const_iterator vbegin(void) const noexcept
		{
			return const_iterator(_data, _line);
		}
		const_iterator cvbegin(void) const noexcept
		{
			return const_iterator(_data, _line);
		}
		iterator vend(void) noexcept
		{
			return iterator(_data + _count, _line);
		}
		const_iterator vend(void) const noexcept
		{
			return const_iterator(_data + _count, _line);
		}
		const_iterator cvend(void) const noexcept
		{
			return const_iterator(_data + _count, _line);
		}
		reverse_iterator rvbegin(void) noexcept
		{
			return reverse_iterator(vend());
		}
		const_reverse_iterator rvbegin(void) const noexcept
		{
			return const_reverse_iterator(vend());
		}
		const_reverse_iterator crvbegin(void) const noexcept
		{
			return const_reverse_iterator(cvend());
		}
		reverse_iterator rvend(void) noexcept
		{
			return reverse_iterator(vbegin());
		}
		const_reverse_iterator rvend(void) const noexcept
		{
			return const_reverse_iterator(vbegin());
		}
		const_reverse_iterator crvend(void) const noexcept
		{
			return const_reverse_iterator(cvbegin());
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

		size_type area(void) const noexcept
		{
			return (_rows * _cols);
		}

		size_type line(void) const noexcept
		{
			return _line;
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

		vector_type operator[](size_type i) noexcept
		{
			return vector_type(_cols, _dim, _data + i * _line, false);
		}
		const_vector_type operator[](size_type i) const noexcept
		{
			return const_vector_type(_cols, _dim, _data + i * _line, false);
		}

		vector_type at(size_type i)
		{
			if (empty())
				throw std::domain_error(MATRIX_NOT_INITIALIZED);
			if (i >= _rows)
				throw std::out_of_range(MATRIX_OUT_OF_RANGE);
			return vector_type(_cols, _dim, _data + i * _line, false);
		}
		const_vector_type at(size_type i) const
		{
			if (empty())
				throw std::domain_error(MATRIX_NOT_INITIALIZED);
			if (i >= _rows)
				throw std::out_of_range(MATRIX_OUT_OF_RANGE);
			return const_vector_type(_cols, _dim, _data + i * _line, false);
		}

		pointer data(void) noexcept
		{
			return static_cast<pointer>(_data);
		}
		const_pointer data(void) const noexcept
		{
			return static_cast<const_pointer>(_data);
		}
		pointer data(size_type row) noexcept
		{
			return static_cast<pointer>(_data + row * _line);
		}
		const_pointer data(size_type row) const noexcept
		{
			return static_cast<const_pointer>(_data + row * _line);
		}
		pointer data(size_type row, size_type column) noexcept
		{
			return static_cast<pointer>(_data + row * _line + column * _dim);
		}
		const_pointer data(size_type row, size_type column) const noexcept
		{
			return static_cast<const_pointer>(_data + row * _line + column * _dim);
		}
		pointer data(size_type row, size_type column, size_type dim) noexcept
		{
			return static_cast<pointer>(_data + row * _line + column * _dim + dim);
		}
		const_pointer data(size_type row, size_type column, size_type dim) const noexcept
		{
			return static_cast<const_pointer>(_data + row * _line + column * _dim + dim);
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
			return const_scalar_type(_dim, const_cast<pointer>(it.operator->()));
		}
		const_scalar_type scalar(const_reverse_iterator it) noexcept
		{
			return const_scalar_type(_dim, const_cast<pointer>(it.operator->()));
		}
		const_scalar_type scalar(const_iterator it) const noexcept
		{
			return const_scalar_type(_dim, const_cast<pointer>(it.operator->()));
		}
		const_scalar_type scalar(const_reverse_iterator it) const noexcept
		{
			return const_scalar_type(_dim, const_cast<pointer>(it.operator->()));
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
			return const_vector_type(_cols, _dim, const_cast<pointer>(it.operator->()));
		}
		const_vector_type vector(const_reverse_iterator it) noexcept
		{
			return const_vector_type(_cols, _dim, const_cast<pointer>(it.operator->()));
		}
		const_vector_type vector(const_iterator it) const noexcept
		{
			return const_vector_type(_cols, _dim, const_cast<pointer>(it.operator->()));
		}
		const_vector_type vector(const_reverse_iterator it) const noexcept
		{
			return const_vector_type(_cols, _dim, const_cast<pointer>(it.operator->()));
		}

		// modifiers:

		void fill(const value_type& value)
		{
			if (empty())
				throw std::domain_error(MATRIX_NOT_INITIALIZED);
			std::fill_n(_data, _count, value);
		}

		void fill_n(size_type n, const value_type& value)
		{
			if (empty())
				throw std::domain_error(MATRIX_NOT_INITIALIZED);
			if (n == 0 || n > _count)
				throw std::invalid_argument(INVALID_LENGTH);
			std::fill_n(_data, n, value);
		}

		template <class InputIterator>
		void fill(InputIterator first, InputIterator last)
		{
			if (empty())
				throw std::domain_error(MATRIX_NOT_INITIALIZED);
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
				throw std::domain_error(MATRIX_NOT_INITIALIZED);
			if (scalar.empty())
				throw std::domain_error(SCALAR_NOT_INITIALIZED);
			if (scalar.size() != _dim)
				throw std::invalid_argument(INVALID_DIMENSION);
			pointer current = _data;
			size_type number = area();
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
				throw std::domain_error(MATRIX_NOT_INITIALIZED);
			if (vector.empty())
				throw std::domain_error(VECTOR_NOT_INITIALIZED);
			if (vector.size() != _line)
				throw std::invalid_argument(INVALID_SIZE);
			pointer current = _data;
			const_pointer first = vector.data();
			const_pointer last = first + vector.size();
			for (size_type i = 0; i < _rows; ++i)
			{
				std::copy(first, last, current);
				current += _line;
			}
		}

		void fill(const matrix<T, Allocator>& other)
		{
			if (empty() || other.empty())
				throw std::domain_error(MATRIX_NOT_INITIALIZED);
			if (_count != other.size())
				throw std::invalid_argument(INVALID_SIZE);
			std::copy(other._data, other._data + _count, _data);
		}

		template <class Generator>
		void generate(Generator g)
		{
			if (empty())
				throw std::domain_error(MATRIX_NOT_INITIALIZED);
			for (size_type i = 0; i < _count; ++i)
				_data[i] = g();
		}

		void shape(size_type rows, size_type cols, size_type dim)
		{
			if (empty())
				throw std::domain_error(MATRIX_NOT_INITIALIZED);
			if (rows * cols * dim != _count)
				throw std::invalid_argument(INVALID_MATRIX_SIZE);
			_dim = dim;
			_cols = cols;
			_rows = rows;
			_line = _cols * _dim;
			_count = _rows * _line;
		}

		matrix<T, Allocator> reshape(size_type rows, size_type cols, size_type dim) const
		{
			if (empty())
				throw std::domain_error(MATRIX_NOT_INITIALIZED);
			if (rows * cols * dim != _count)
				throw std::invalid_argument(INVALID_MATRIX_SIZE);
			return matrix<T, Allocator>(rows, cols, dim, _data);
		}

		void swap(matrix<T, Allocator>& rhs) noexcept
		{
			if (this != &rhs)
			{
				std::swap(_owner, rhs._owner);
				std::swap(_dim, rhs._dim);
				std::swap(_cols, rhs._cols);
				std::swap(_rows, rhs._rows);
				std::swap(_line, rhs._line);
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
			_line = 0;
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
		friend bool operator<(const matrix<T, Allocator>& lhs, const matrix<T, A>& rhs)
		{
			if (lhs.size() != rhs.size())
				throw std::invalid_argument(MATRIX_DIFFERENT_SIZE);
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
		friend bool operator>(const matrix<T, Allocator>& lhs, const matrix<T, A>& rhs)
		{
			return (rhs < lhs);
		}
		template <class A>
		friend bool operator<=(const matrix<T, Allocator>& lhs, const matrix<T, A>& rhs)
		{
			return !(lhs > rhs);
		}
		template <class A>
		friend bool operator>=(const matrix<T, Allocator>& lhs, const matrix<T, A>& rhs)
		{
			return !(lhs < rhs);
		}

		template <class A>
		friend bool operator==(const matrix<T, Allocator>& lhs, const matrix<T, A>& rhs)
		{
			if (lhs.size() != rhs.size())
				throw std::invalid_argument(MATRIX_DIFFERENT_SIZE);
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
		friend bool operator!=(const matrix<T, Allocator>& lhs, const matrix<T, A>& rhs)
		{
			return !(lhs == rhs);
		}
	private:
		void assign_rv(matrix<T, Allocator>&& right, std::true_type)
		{
			swap(right);
		}
		void assign_rv(matrix<T, Allocator>&& right, std::false_type)
		{
			if (get_allocator() == right.get_allocator())
				assign_rv(std::forward<matrix<T, Allocator> >(right), std::true_type());
			else
				assign(right, DEEP_COPY);
		}
	private:
		bool       _owner;
		size_type  _dim;
		size_type  _cols;
		size_type  _rows;
		size_type  _line;
		size_type  _count;
		pointer    _data;
	};

} // namespace core

#endif
