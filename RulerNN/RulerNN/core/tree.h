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

#ifndef __CORE_TREE_H__
#define __CORE_TREE_H__

#include <memory>
#include <stdexcept>
#include <iterator>
#include <functional>
#include <utility>

#ifndef DEFAULT_ALLOCATOR
#define DEFAULT_ALLOCATOR(T) std::allocator<T>
#endif // !DEFAULT_ALLOCATOR

namespace core
{
	using tree_node_state = signed char;
	static constexpr tree_node_state tree_state_parent  = -0x10;
	static constexpr tree_node_state tree_state_sibling =  0x01;
	static constexpr tree_node_state tree_state_child   =  0x12;
	static constexpr tree_node_state tree_state_root    =  0x04;

	// Class template tree_node
	template <class T>
	struct tree_node
	{
		using node_type            = tree_node<T>;
		using node_pointer         = node_type*;
		using const_node_pointer   = const node_type*;
		using node_reference       = node_type&;
		using const_node_reference = const node_type&;

		node_pointer               parent;
		node_pointer               prev_sibling;
		node_pointer               next_sibling;
		node_pointer               first_child;
		node_pointer               last_child;
		T                          data;
	};


	// Class template tree_type_traits

	template <class Tree, bool IsConst>
	struct tree_type_traits
	{
		using value_type      = typename Tree::value_type;
		using pointer         = typename Tree::pointer;
		using size_type       = typename Tree::size_type;
		using difference_type = typename Tree::difference_type;
		using node_type       = typename Tree::node_type;
		using node_pointer    = typename Tree::node_pointer;
		using reference       = value_type&;
	};

	template <class Tree>
	struct tree_type_traits<Tree, true>
	{
		using value_type      = typename Tree::value_type;
		using pointer         = typename Tree::const_pointer;
		using size_type       = typename Tree::size_type;
		using difference_type = typename Tree::difference_type;
		using node_type       = typename Tree::node_type;
		using node_pointer    = typename Tree::node_pointer;
		using reference       = const value_type&;
	};


	// Class template tree_iterator
	template <class Tree, bool IsConst>
	class tree_iterator
	{
	public:
		// types:

		using value_type        = typename tree_type_traits<Tree, IsConst>::value_type;
		using pointer           = typename tree_type_traits<Tree, IsConst>::pointer;
		using reference         = typename tree_type_traits<Tree, IsConst>::reference;
		using size_type         = typename tree_type_traits<Tree, IsConst>::size_type;
		using difference_type   = typename tree_type_traits<Tree, IsConst>::difference_type;
		using node_type         = typename tree_type_traits<Tree, IsConst>::node_type;
		using node_pointer      = typename tree_type_traits<Tree, IsConst>::node_pointer;

		using iterator_type     = tree_iterator<Tree, IsConst>;
		using iterator_category = std::bidirectional_iterator_tag;

		// construct/copy/destroy:

		tree_iterator(void) noexcept
			: node(nullptr)
		{}
		explicit tree_iterator(const node_pointer ptr) noexcept
			: node(ptr)
		{}
		tree_iterator(const tree_iterator<Tree, IsConst>& other) noexcept
			: node(other.get_pointer())
		{}

		tree_iterator<Tree, IsConst>& operator=(const tree_iterator<Tree, IsConst>& other) noexcept
		{
			if (this != &other)
				node = other.get_pointer();
			return (*this);
		}

		operator tree_iterator<Tree, true>(void) const noexcept
		{
			return tree_iterator<Tree, true>(node);
		}

		// tree_iterator operations:

		node_pointer get_parent(void) noexcept
		{
			return node->parent;
		}

		const node_pointer get_parent(void) const noexcept
		{
			return node->parent;
		}

		node_pointer get_pointer(void) noexcept
		{
			return node;
		}

		const node_pointer get_pointer(void) const noexcept
		{
			return node;
		}

		reference operator*(void) const noexcept
		{
			return node->data;
		}

		pointer operator->(void) const noexcept
		{
			return &(operator*());
		}

		// increment / decrement

		tree_iterator<Tree, IsConst>& operator++(void) noexcept
		{
			if (node->first_child != node)
				node = node->first_child;
			else
			{
				while (node->next_sibling == node->parent)
					node = node->parent;
				node = node->next_sibling;
			}
			return (*this);
		}

		tree_iterator<Tree, IsConst>& operator--(void) noexcept
		{
			if (node->prev_sibling != node->parent)
			{
				node = node->prev_sibling;
				while (node->last_child != node)
					node = node->last_child;
			}
			else
				node = node->parent;
			return (*this);
		}

		tree_iterator<Tree, IsConst> operator++(int) noexcept
		{
			iterator_type tmp(*this);
			this->operator++();
			return tmp;
		}

		tree_iterator<Tree, IsConst> operator--(int) noexcept
		{
			iterator_type tmp(*this);
			this->operator--();
			return tmp;
		}

		// relational operators:

		template <bool is_const>
		bool operator==(const tree_iterator<Tree, is_const>& rhs) const noexcept
		{
			return (node == rhs.get_pointer());
		}

		template <bool is_const>
		bool operator!=(const tree_iterator<Tree, is_const>& rhs) const noexcept
		{
			return (node != rhs.get_pointer());
		}
	private:
		node_pointer node;
	};


	// Class template tree_primitive_iterator
	template <class Tree, bool IsConst>
	class tree_primitive_iterator
	{
	public:
		// types:

		using value_type        = typename tree_type_traits<Tree, IsConst>::value_type;
		using pointer           = typename tree_type_traits<Tree, IsConst>::pointer;
		using reference         = typename tree_type_traits<Tree, IsConst>::reference;
		using size_type         = typename tree_type_traits<Tree, IsConst>::size_type;
		using difference_type   = typename tree_type_traits<Tree, IsConst>::difference_type;
		using node_type         = typename tree_type_traits<Tree, IsConst>::node_type;
		using node_pointer      = typename tree_type_traits<Tree, IsConst>::node_pointer;

		using iterator_type     = tree_primitive_iterator<Tree, IsConst>;
		using iterator_category = std::bidirectional_iterator_tag;

		// construct/copy/destroy:

		tree_primitive_iterator(void) noexcept
			: node(nullptr)
			, state(tree_state_root)
		{}
		explicit tree_primitive_iterator(const node_pointer ptr) noexcept
			: node(ptr)
			, state(tree_state_root)
		{}
		tree_primitive_iterator(const tree_primitive_iterator<Tree, IsConst>& other) noexcept
			: node(other.get_pointer())
			, state(other.get_state())
		{}

		tree_primitive_iterator<Tree, IsConst>& operator=(const tree_primitive_iterator<Tree, IsConst>& other) noexcept
		{
			if (this != &other)
			{
				node = other.get_pointer();
				state = other.get_state();
			}
			return (*this);
		}

		operator tree_primitive_iterator<Tree, true>(void) const noexcept
		{
			return tree_primitive_iterator<Tree, true>(node);
		}

		// tree_primitive_iterator operations:

		node_pointer get_parent(void) noexcept
		{
			return node->parent;
		}
		const node_pointer get_parent(void) const noexcept
		{
			return node->parent;
		}

		node_pointer get_pointer(void) noexcept
		{
			return node;
		}
		const node_pointer get_pointer(void) const noexcept
		{
			return node;
		}

		tree_node_state get_state(void) const noexcept
		{
			return state;
		}

		intptr_t get_depth(void) const noexcept
		{
			return static_cast<intptr_t>(state >> 4);
		}

		reference operator*(void) const noexcept
		{
			return node->data;
		}
		pointer operator->(void) const noexcept
		{
			return &(operator*());
		}

		// increment / decrement

		tree_primitive_iterator<Tree, IsConst>& operator++(void) noexcept
		{
			if (state != tree_state_parent)
			{
				if (node->first_child != node)
				{
					node = node->first_child;
					state = tree_state_child;
				}
				else if (node->next_sibling != node->parent)
				{
					node = node->next_sibling;
					state = tree_state_sibling;
				}
				else
				{
					node = node->parent;
					state = tree_state_parent;
				}
			}
			else
			{
				if (node->next_sibling != node->parent)
				{
					node = node->next_sibling;
					state = tree_state_sibling;
				}
				else
					node = node->parent;
			}
			return (*this);
		}

		tree_primitive_iterator<Tree, IsConst>& operator--(void) noexcept
		{
			if (state != tree_state_parent)
			{
				if (node->last_child != node)
				{
					node = node->last_child;
					state = tree_state_child;
				}
				else if (node->prev_sibling != node->parent)
				{
					node = node->prev_sibling;
					state = tree_state_sibling;
				}
				else
				{
					node = node->parent;
					state = tree_state_parent;
				}
			}
			else
			{
				if (node->prev_sibling != node->parent)
				{
					node = node->prev_sibling;
					state = tree_state_sibling;
				}
				else
					node = node->parent;
			}
			return (*this);
		}

		tree_primitive_iterator<Tree, IsConst> operator++(int) noexcept
		{
			iterator_type tmp(*this);
			this->operator++();
			return tmp;
		}

		tree_primitive_iterator<Tree, IsConst> operator--(int) noexcept
		{
			iterator_type tmp(*this);
			this->operator--();
			return tmp;
		}

		// relational operators:

		template <bool is_const>
		bool operator==(const tree_primitive_iterator<Tree, is_const>& rhs) const noexcept
		{
			return (node == rhs.get_pointer());
		}

		template <bool is_const>
		bool operator!=(const tree_primitive_iterator<Tree, is_const>& rhs) const noexcept
		{
			return (node != rhs.get_pointer());
		}
	private:
		node_pointer    node;
		tree_node_state state;
	};


	// Class template tree_sibling_iterator
	template <class Tree, bool IsConst>
	class tree_sibling_iterator
	{
	public:
		// types:

		using value_type        = typename tree_type_traits<Tree, IsConst>::value_type;
		using pointer           = typename tree_type_traits<Tree, IsConst>::pointer;
		using reference         = typename tree_type_traits<Tree, IsConst>::reference;
		using size_type         = typename tree_type_traits<Tree, IsConst>::size_type;
		using difference_type   = typename tree_type_traits<Tree, IsConst>::difference_type;
		using node_type         = typename tree_type_traits<Tree, IsConst>::node_type;
		using node_pointer      = typename tree_type_traits<Tree, IsConst>::node_pointer;

		using iterator_type     = tree_sibling_iterator<Tree, IsConst>;
		using iterator_category = std::bidirectional_iterator_tag;

		// construct/copy/destroy:

		tree_sibling_iterator(void) noexcept
			: node(nullptr)
			, parent(nullptr)
		{}
		explicit tree_sibling_iterator(const node_pointer ptr) noexcept
			: node(ptr)
			, parent(ptr->parent)
		{}
		explicit tree_sibling_iterator(const node_pointer parent_ptr, const node_pointer ptr) noexcept
			: node(ptr)
			, parent(parent_ptr)
		{}
		tree_sibling_iterator(const tree_sibling_iterator<Tree, IsConst>& other) noexcept
			: node(other.get_pointer())
			, parent(other.get_parent())
		{}

		tree_sibling_iterator<Tree, IsConst>& operator=(const tree_sibling_iterator<Tree, IsConst>& other)
		{
			if (this != &other)
			{
				parent = other.get_parent();
				node = other.get_pointer();
			}
			return (*this);
		}

		operator tree_sibling_iterator<Tree, true>(void) const noexcept
		{
			return tree_sibling_iterator<Tree, true>(node);
		}

		// tree_sibling_iterator operations:

		node_pointer get_parent(void) noexcept
		{
			return parent;
		}

		const node_pointer get_parent(void) const noexcept
		{
			return parent;
		}

		node_pointer get_pointer(void) noexcept
		{
			return node;
		}

		const node_pointer get_pointer(void) const noexcept
		{
			return node;
		}

		reference operator*(void) const noexcept
		{
			return node->data;
		}

		pointer operator->(void) const noexcept
		{
			return &(operator*());
		}

		// increment / decrement

		tree_sibling_iterator<Tree, IsConst>& operator++(void) noexcept
		{
			if (node != parent)
				node = node->next_sibling;
			else
				node = node->first_child;
			return (*this);
		}

		tree_sibling_iterator<Tree, IsConst>& operator--(void) noexcept
		{
			if (node != parent)
				node = node->prev_sibling;
			else
				node = node->last_child;
			return (*this);
		}

		tree_sibling_iterator<Tree, IsConst> operator++(int) noexcept
		{
			iterator_type tmp(*this);
			this->operator++();
			return tmp;
		}

		tree_sibling_iterator<Tree, IsConst> operator--(int) noexcept
		{
			iterator_type tmp(*this);
			this->operator--();
			return tmp;
		}

		// relational operators:

		template <bool is_const>
		bool operator==(const tree_sibling_iterator<Tree, is_const>& rhs) const noexcept
		{
			return (node == rhs.get_pointer());
		}

		template <bool is_const>
		bool operator!=(const tree_sibling_iterator<Tree, is_const>& rhs) const noexcept
		{
			return (node != rhs.get_pointer());
		}
	private:
		node_pointer node;
		node_pointer parent;
	};


	// Class template tree_leaf_iterator
	template <class Tree, bool IsConst>
	class tree_leaf_iterator
	{
	public:
		// types:

		using value_type        = typename tree_type_traits<Tree, IsConst>::value_type;
		using pointer           = typename tree_type_traits<Tree, IsConst>::pointer;
		using reference         = typename tree_type_traits<Tree, IsConst>::reference;
		using size_type         = typename tree_type_traits<Tree, IsConst>::size_type;
		using difference_type   = typename tree_type_traits<Tree, IsConst>::difference_type;
		using node_type         = typename tree_type_traits<Tree, IsConst>::node_type;
		using node_pointer      = typename tree_type_traits<Tree, IsConst>::node_pointer;

		using iterator_type     = tree_leaf_iterator<Tree, IsConst>;
		using iterator_category = std::bidirectional_iterator_tag;

		// construct/copy/destroy:

		tree_leaf_iterator(void) noexcept
			: node(nullptr)
		{}
		explicit tree_leaf_iterator(const node_pointer ptr) noexcept
			: node(ptr)
		{}
		tree_leaf_iterator(const tree_leaf_iterator<Tree, IsConst>& other) noexcept
			: node(other.get_pointer())
		{}

		tree_leaf_iterator<Tree, IsConst>& operator=(const tree_leaf_iterator<Tree, IsConst>& other) noexcept
		{
			if (this != &other)
				node = other.get_pointer();
			return (*this);
		}

		operator tree_leaf_iterator<Tree, true>(void) const noexcept
		{
			return tree_leaf_iterator<Tree, true>(node);
		}

		// tree_leaf_iterator operations:

		node_pointer get_parent(void) noexcept
		{
			return node->parent;
		}

		const node_pointer get_parent(void) const noexcept
		{
			return node->parent;
		}

		node_pointer get_pointer(void) noexcept
		{
			return node;
		}

		const node_pointer get_pointer(void) const noexcept
		{
			return node;
		}

		reference operator*(void) const noexcept
		{
			return node->data;
		}

		pointer operator->(void) const noexcept
		{
			return &(operator*());
		}

		// increment / decrement

		tree_leaf_iterator<Tree, IsConst>& operator++(void) noexcept
		{
			if (node->first_child != node)
			{
				while (node->first_child != node)
					node = node->first_child;
			}
			else
			{
				while (node->next_sibling == node->parent)
					node = node->parent;
				if (node->next_sibling != node)
				{
					node = node->next_sibling;
					while (node->first_child != node)
						node = node->first_child;
				}
			}
			return (*this);
		}

		tree_leaf_iterator<Tree, IsConst>& operator--(void) noexcept
		{
			if (node->last_child != node)
			{
				while (node->last_child != node)
					node = node->last_child;
			}
			else
			{
				while (node->prev_sibling == node->parent)
					node = node->parent;
				if (node->prev_sibling != node)
				{
					node = node->prev_sibling;
					while (node->last_child != node)
						node = node->last_child;
				}
			}
			return (*this);
		}

		tree_leaf_iterator<Tree, IsConst> operator++(int) noexcept
		{
			iterator_type tmp(*this);
			this->operator++();
			return tmp;
		}

		tree_leaf_iterator<Tree, IsConst> operator--(int) noexcept
		{
			iterator_type tmp(*this);
			this->operator--();
			return tmp;
		}

		// relational operators:

		template <bool is_const>
		bool operator==(const tree_leaf_iterator<Tree, is_const>& rhs) const noexcept
		{
			return (node == rhs.get_pointer());
		}

		template <bool is_const>
		bool operator!=(const tree_leaf_iterator<Tree, is_const>& rhs) const noexcept
		{
			return (node != rhs.get_pointer());
		}
	private:
		node_pointer node;
	};


	// Class template tree_node_allocator
	template <class T, class Allocator>
	class tree_node_allocator : public Allocator
	{
	public:
		// types:

		using allocator_type             = Allocator;
		using tree_node_type             = typename tree_node<T>::node_type;
		using node_allocator_type        = typename Allocator::template rebind<tree_node_type>::other;
		using node_allocator_traits_type = std::allocator_traits<node_allocator_type>;
		using node_type                  = typename node_allocator_traits_type::value_type;
		using node_pointer               = typename node_allocator_traits_type::pointer;
		using node_size_type             = typename node_allocator_traits_type::size_type;
		using node_difference_type       = typename node_allocator_traits_type::difference_type;

		// construct/copy/destroy:

		tree_node_allocator(void)
			: Allocator()
		{}
		explicit tree_node_allocator(const Allocator& alloc)
			: Allocator(alloc)
		{}
		explicit tree_node_allocator(Allocator&& alloc)
			: Allocator(std::forward<Allocator>(alloc))
		{}
		~tree_node_allocator(void)
		{}

		// tree_node_allocator operations:

		allocator_type get_allocator(void) const noexcept
		{
			return *static_cast<const allocator_type*>(this);
		}
		node_size_type max_size(void) const noexcept
		{
			return node_alloc.max_size();
		}
	protected:
		template<class ...Args>
		node_pointer create_node(Args&&... args)
		{
			node_pointer p = node_alloc.allocate(1);
			get_allocator().construct(std::addressof(p->data), std::forward<Args>(args)...);
			return p;
		}
		void destroy_node(const node_pointer p)
		{
			get_allocator().destroy(std::addressof(p->data));
			node_alloc.deallocate(p, 1);
		}
	private:
		node_allocator_type node_alloc;
	};


	// Class template tree
	template <class T, class Allocator = DEFAULT_ALLOCATOR(T)>
	class tree : public tree_node_allocator<T, Allocator>
	{
	public:
		// types:

		using allocator_type                   = Allocator;
		using tree_type                        = tree<T, Allocator>;
		using node_allocator_type              = tree_node_allocator<T, Allocator>;
		using allocator_traits_type            = std::allocator_traits<allocator_type>;
		using node_allocator_traits_type       = std::allocator_traits<node_allocator_type>;
		using value_type                       = typename allocator_traits_type::value_type;
		using pointer                          = typename allocator_traits_type::pointer;
		using const_pointer                    = typename allocator_traits_type::const_pointer;
		using size_type                        = typename allocator_traits_type::size_type;
		using difference_type                  = typename allocator_traits_type::difference_type;
		using node_type                        = typename node_allocator_type::node_type;
		using node_pointer                     = typename node_allocator_type::node_pointer;

		using iterator                         = tree_iterator<tree_type, false>;
		using const_iterator                   = tree_iterator<tree_type, true>;
		using primitive_iterator               = tree_primitive_iterator<tree_type, false>;
		using const_primitive_iterator         = tree_primitive_iterator<tree_type, true>;
		using sibling_iterator                 = tree_sibling_iterator<tree_type, false>;
		using const_sibling_iterator           = tree_sibling_iterator<tree_type, true>;
		using leaf_iterator                    = tree_leaf_iterator<tree_type, false>;
		using const_leaf_iterator              = tree_leaf_iterator<tree_type, true>;
		using reverse_iterator                 = std::reverse_iterator<iterator>;
		using const_reverse_iterator           = std::reverse_iterator<const_iterator>;
		using reverse_primitive_iterator       = std::reverse_iterator<primitive_iterator>;
		using const_reverse_primitive_iterator = std::reverse_iterator<const_primitive_iterator>;
		using reverse_sibling_iterator         = std::reverse_iterator<sibling_iterator>;
		using const_reverse_sibling_iterator   = std::reverse_iterator<const_sibling_iterator>;
		using reverse_leaf_iterator            = std::reverse_iterator<leaf_iterator>;
		using const_reverse_leaf_iterator      = std::reverse_iterator<const_leaf_iterator>;

		// construct/copy/destroy:

		explicit tree(const Allocator& alloc = Allocator())
			: node_allocator_type(alloc)
			, header(nullptr)
			, count(0)
		{
			create_header();
		}
		explicit tree(size_type n, const Allocator& alloc = Allocator())
			: node_allocator_type(alloc)
			, header(nullptr)
			, count(0)
		{
			create_header();
			assign(n, value_type());
		}
		tree(size_type n, const T& value, const Allocator& alloc = Allocator())
			: node_allocator_type(alloc)
			, header(nullptr)
			, count(0)
		{
			create_header();
			assign(n, value);
		}
		template<class InputIt>
		tree(InputIt first, InputIt last, const Allocator& alloc = Allocator())
			: node_allocator_type(alloc)
			, header(nullptr)
			, count(0)
		{
			create_header();
			assign(first, last);
		}
		tree(const tree<T, Allocator>& other)
			: node_allocator_type(other.get_allocator())
			, header(nullptr)
			, count(0)
		{
			create_header();
			if (!other.empty())
				copy_child_node(header, other.header);
		}
		tree(const tree<T, Allocator>& other, const Allocator& alloc)
			: node_allocator_type(alloc)
			, header(nullptr)
			, count(0)
		{
			create_header();
			if (!other.empty())
				copy_child_node(header, other.header);
		}
		tree(tree<T, Allocator>&& other) noexcept
			: node_allocator_type(other.get_allocator())
			, header(nullptr)
			, count(0)
		{
			create_header();
			swap(other);
		}
		tree(tree<T, Allocator>&& other, const Allocator& alloc)
			: node_allocator_type(alloc)
			, header(nullptr)
			, count(0)
		{
			create_header();
			swap(other);
		}
		tree(std::initializer_list<T> ilist, const Allocator& alloc = Allocator())
			: node_allocator_type(alloc)
			, header(nullptr)
			, count(0)
		{
			create_header();
			assign(ilist);
		}
		~tree(void) noexcept
		{
			clear();
			destroy_header();
		}
		tree<T, Allocator>& operator=(const tree<T, Allocator>& other)
		{
			if (this != &other)
			{
				clear();
				if (!other.empty())
					copy_child_node(header, other.header);
			}
			return (*this);
		}
		tree<T, Allocator>& operator=(tree<T, Allocator>&& other)
		{
			if (this != &other)
				swap(other);
			return (*this);
		}
		tree<T, Allocator>& operator=(std::initializer_list<T> ilist)
		{
			clear();
			assign(ilist);
			return (*this);
		}

		void assign(size_type n, const T& value)
		{
			clear();
			for (; n > 0; --n)
				push_back(value);
		}

		template<class InputIt>
		void assign(InputIt first, InputIt last)
		{
			clear();
			for (; first != last; ++first)
				push_back(*first);
		}

		void assign(std::initializer_list<T> ilist)
		{
			assign(ilist.begin(), ilist.end());
		}

		// iterators:

		iterator begin(void) noexcept
		{
			return iterator(header->first_child);
		}
		const_iterator begin(void) const noexcept
		{
			return const_iterator(header->first_child);
		}
		const_iterator cbegin(void) const noexcept
		{
			return const_iterator(header->first_child);
		}
		iterator end(void) noexcept
		{
			return iterator(header);
		}
		const_iterator end(void) const noexcept
		{
			return const_iterator(header);
		}
		const_iterator cend(void) const noexcept
		{
			return const_iterator(header);
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

		primitive_iterator pbegin(void) noexcept
		{
			return primitive_iterator(header->first_child);
		}
		const_primitive_iterator pbegin(void) const noexcept
		{
			return const_primitive_iterator(header->first_child);
		}
		const_primitive_iterator cpbegin(void) const noexcept
		{
			return const_primitive_iterator(header->first_child);
		}
		primitive_iterator pend(void) noexcept
		{
			return primitive_iterator(header);
		}
		const_primitive_iterator pend(void) const noexcept
		{
			return const_primitive_iterator(header);
		}
		const_primitive_iterator cpend(void) const noexcept
		{
			return const_primitive_iterator(header);
		}
		reverse_primitive_iterator rpbegin(void) noexcept
		{
			return reverse_primitive_iterator(pend());
		}
		const_reverse_primitive_iterator rpbegin(void) const noexcept
		{
			return const_reverse_primitive_iterator(pend());
		}
		const_reverse_primitive_iterator crpbegin(void) const noexcept
		{
			return const_reverse_primitive_iterator(cpend());
		}
		reverse_primitive_iterator rpend(void) noexcept
		{
			return reverse_primitive_iterator(pbegin());
		}
		const_reverse_primitive_iterator rpend(void) const noexcept
		{
			return const_reverse_primitive_iterator(pbegin());
		}
		const_reverse_primitive_iterator crpend(void) const noexcept
		{
			return const_reverse_primitive_iterator(cpbegin());
		}
		template <class Iterator>
		primitive_iterator pbegin(Iterator node) noexcept
		{
			return primitive_iterator(node.get_pointer()->first_child);
		}
		template <class Iterator>
		const_primitive_iterator pbegin(Iterator node) const noexcept
		{
			return const_primitive_iterator(node.get_pointer()->first_child);
		}
		template <class Iterator>
		const_primitive_iterator cpbegin(Iterator node) const noexcept
		{
			return const_primitive_iterator(node.get_pointer()->first_child);
		}
		template <class Iterator>
		primitive_iterator pend(Iterator node) noexcept
		{
			return primitive_iterator(node.get_pointer());
		}
		template <class Iterator>
		const_primitive_iterator pend(Iterator node) const noexcept
		{
			return const_primitive_iterator(node.get_pointer());
		}
		template <class Iterator>
		const_primitive_iterator cpend(Iterator node) const noexcept
		{
			return const_primitive_iterator(node.get_pointer());
		}
		template <class Iterator>
		reverse_primitive_iterator rpbegin(Iterator node) noexcept
		{
			return reverse_primitive_iterator(pend(node));
		}
		template <class Iterator>
		const_reverse_primitive_iterator rpbegin(Iterator node) const noexcept
		{
			return const_reverse_primitive_iterator(pend(node));
		}
		template <class Iterator>
		const_reverse_primitive_iterator crpbegin(Iterator node) const noexcept
		{
			return const_reverse_primitive_iterator(cpend(node));
		}
		template <class Iterator>
		reverse_primitive_iterator rpend(Iterator node) noexcept
		{
			return reverse_primitive_iterator(pbegin(node));
		}
		template <class Iterator>
		const_reverse_primitive_iterator rpend(Iterator node) const noexcept
		{
			return const_reverse_primitive_iterator(pbegin(node));
		}
		template <class Iterator>
		const_reverse_primitive_iterator crpend(Iterator node) const noexcept
		{
			return const_reverse_primitive_iterator(cpbegin(node));
		}

		sibling_iterator sbegin(void) noexcept
		{
			return sibling_iterator(header, header->first_child);
		}
		const_sibling_iterator sbegin(void) const noexcept
		{
			return const_sibling_iterator(header, header->first_child);
		}
		const_sibling_iterator csbegin(void) const noexcept
		{
			return const_sibling_iterator(header, header->first_child);
		}
		sibling_iterator send(void) noexcept
		{
			return sibling_iterator(header, header);
		}
		const_sibling_iterator send(void) const noexcept
		{
			return const_sibling_iterator(header, header);
		}
		const_sibling_iterator csend(void) const noexcept
		{
			return const_sibling_iterator(header, header);
		}
		reverse_sibling_iterator rsbegin(void) noexcept
		{
			return reverse_sibling_iterator(send());
		}
		const_reverse_sibling_iterator rsbegin(void) const noexcept
		{
			return const_reverse_sibling_iterator(send());
		}
		const_reverse_sibling_iterator crsbegin(void) const noexcept
		{
			return const_reverse_sibling_iterator(csend());
		}
		reverse_sibling_iterator rsend(void) noexcept
		{
			return reverse_sibling_iterator(sbegin());
		}
		const_reverse_sibling_iterator rsend(void) const noexcept
		{
			return const_reverse_sibling_iterator(sbegin());
		}
		const_reverse_sibling_iterator crsend(void) const noexcept
		{
			return const_reverse_sibling_iterator(csbegin());
		}
		template <class Iterator>
		sibling_iterator sbegin(Iterator node) noexcept
		{
			return sibling_iterator(node.get_pointer(), node.get_pointer()->first_child);
		}
		template <class Iterator>
		const_sibling_iterator sbegin(Iterator node) const noexcept
		{
			return const_sibling_iterator(node.get_pointer(), node.get_pointer()->first_child);
		}
		template <class Iterator>
		const_sibling_iterator csbegin(Iterator node) const noexcept
		{
			return const_sibling_iterator(node.get_pointer(), node.get_pointer()->first_child);
		}
		template <class Iterator>
		sibling_iterator send(Iterator node) noexcept
		{
			return sibling_iterator(node.get_pointer(), node.get_pointer());
		}
		template <class Iterator>
		const_sibling_iterator send(Iterator node) const noexcept
		{
			return const_sibling_iterator(node.get_pointer(), node.get_pointer());
		}
		template <class Iterator>
		const_sibling_iterator csend(Iterator node) const noexcept
		{
			return const_sibling_iterator(node.get_pointer(), node.get_pointer());
		}
		template <class Iterator>
		reverse_sibling_iterator rsbegin(Iterator node) noexcept
		{
			return reverse_sibling_iterator(send(node));
		}
		template <class Iterator>
		const_reverse_sibling_iterator rsbegin(Iterator node) const noexcept
		{
			return const_reverse_sibling_iterator(send(node));
		}
		template <class Iterator>
		const_reverse_sibling_iterator crsbegin(Iterator node) const noexcept
		{
			return const_reverse_sibling_iterator(csend(node));
		}
		template <class Iterator>
		reverse_sibling_iterator rsend(Iterator node) noexcept
		{
			return reverse_sibling_iterator(sbegin(node));
		}
		template <class Iterator>
		const_reverse_sibling_iterator rsend(Iterator node) const noexcept
		{
			return const_reverse_sibling_iterator(sbegin(node));
		}
		template <class Iterator>
		const_reverse_sibling_iterator crsend(Iterator node) const noexcept
		{
			return const_reverse_sibling_iterator(csbegin(node));
		}

		leaf_iterator lbegin(void) noexcept
		{
			return leaf_iterator(get_leftmost(header));
		}
		const_leaf_iterator lbegin(void) const noexcept
		{
			return const_leaf_iterator(get_leftmost(header));
		}
		const_leaf_iterator clbegin(void) const noexcept
		{
			return const_leaf_iterator(get_leftmost(header));
		}
		leaf_iterator lend(void) noexcept
		{
			return leaf_iterator(header);
		}
		const_leaf_iterator lend(void) const noexcept
		{
			return const_leaf_iterator(header);
		}
		const_leaf_iterator clend(void) const noexcept
		{
			return const_leaf_iterator(header);
		}
		reverse_leaf_iterator rlbegin(void) noexcept
		{
			return reverse_leaf_iterator(lend());
		}
		const_reverse_leaf_iterator rlbegin() const noexcept
		{
			return const_reverse_leaf_iterator(lend());
		}
		const_reverse_leaf_iterator crlbegin() const noexcept
		{
			return const_reverse_leaf_iterator(clend());
		}
		reverse_leaf_iterator rlend(void) noexcept
		{
			return reverse_leaf_iterator(lbegin());
		}
		const_reverse_leaf_iterator rlend(void) const noexcept
		{
			return const_reverse_leaf_iterator(lbegin());
		}
		const_reverse_leaf_iterator crlend(void) const noexcept
		{
			return const_reverse_leaf_iterator(clbegin());
		}

		// capacity:

		bool empty(void) const noexcept
		{
			return (count == 0);
		}

		size_type size(void) const noexcept
		{
			return count;
		}

		// modifiers:

		template <class Iterator, class... Args>
		Iterator emplace(Iterator pos, Args&&... args)
		{
			node_pointer node = insert_node(pos.get_parent(), pos.get_pointer(), std::forward<Args>(args)...);
			++count;
			return Iterator(node);
		}

		template <class Iterator, class... Args>
		Iterator emplace_back(Iterator parent, Args&&... args)
		{
			node_pointer node = append_node(parent.get_pointer(), std::forward<Args>(args)...);
			++count;
			return Iterator(node);
		}

		template <class Iterator, class... Args>
		Iterator emplace_front(Iterator parent, Args&&... args)
		{
			node_pointer node = prepend_node(parent.get_pointer(), std::forward<Args>(args)...);
			++count;
			return Iterator(node);
		}

		template <class Iterator>
		Iterator push_back(Iterator parent, const value_type& value)
		{
			node_pointer node = append_node(parent.get_pointer(), value);
			++count;
			return Iterator(node);
		}

		template <class Iterator>
		Iterator push_back(Iterator parent, value_type&& value)
		{
			node_pointer node = append_node(parent.get_pointer(), std::forward<value_type>(value));
			++count;
			return Iterator(node);
		}

		template <class Iterator>
		void pop_back(Iterator parent)
		{
			erase_last_child(parent.get_pointer());
		}

		template <class Iterator>
		Iterator push_front(Iterator parent, const value_type& value)
		{
			node_pointer node = prepend_node(parent.get_pointer(), value);
			++count;
			return Iterator(node);
		}

		template <class Iterator>
		Iterator push_front(Iterator parent, value_type&& value)
		{
			node_pointer node = prepend_node(parent.get_pointer(), std::forward<value_type>(value));
			++count;
			return Iterator(node);
		}

		template <class Iterator>
		void pop_front(Iterator parent)
		{
			erase_first_child(parent.get_pointer());
		}

		template <class Iterator>
		Iterator insert(Iterator pos, const value_type& value)
		{
			node_pointer node = insert_node(pos.get_parent(), pos.get_pointer(), value);
			++count;
			return Iterator(node);
		}

		template <class Iterator>
		Iterator insert(Iterator pos, value_type&& value)
		{
			node_pointer node = insert_node(pos.get_parent(), pos.get_pointer(), std::forward<value_type>(value));
			++count;
			return Iterator(node);
		}

		template <class Iterator>
		sibling_iterator insert(Iterator pos, size_type n, const value_type& value)
		{
			sibling_iterator it(pos);
			--it;
			for (; n > 0; --n)
				insert_node(pos.get_parent(), pos.get_pointer(), value);
			count += n;
			++it;
			return it;
		}

		template <class Iterator, class InputIt>
		sibling_iterator insert(Iterator pos, InputIt first, InputIt last)
		{
			sibling_iterator it(pos);
			--it;
			for (; first != last; ++first)
				insert_node(pos.get_parent(), pos.get_pointer(), *first);
			count += std::distance(first, last);
			++it;
			return it;
		}

		template <class Iterator>
		sibling_iterator insert(Iterator pos, std::initializer_list<value_type> ilist)
		{
			return insert(pos, ilist.begin(), ilist.end());
		}

		template <class Iterator>
		sibling_iterator erase(Iterator pos)
		{
			sibling_iterator it(pos);
			++it;
			erase_node(pos.get_pointer());
			return it;
		}

		sibling_iterator erase(sibling_iterator first, sibling_iterator last)
		{
			if (first == sbegin() && last == send())
				clear();
			else
				for (; first != last; ++first)
					erase_node(first.get_pointer());
			return last;
		}

		sibling_iterator erase(const_sibling_iterator first, const_sibling_iterator last)
		{
			if (first == sbegin() && last == send())
				clear();
			else
				for (; first != last; ++first)
					erase_node(first.get_pointer());
			return sibling_iterator(last.get_pointer());
		}

		template <class Iterator>
		void erase_child(Iterator parent)
		{
			erase_child_node(parent.get_pointer());
		}

		void swap(tree<T, Allocator>& rhs) noexcept
		{
			if (this != &rhs)
			{
				std::swap(header, rhs.header);
				std::swap(count, rhs.count);
			}
		}

		void clear(void)
		{
			erase_child_node(header);
		}

		// Operations:

		template <class Iterator>
		tree<T, Allocator> sub_tree(Iterator pos) const
		{
			tree<T, Allocator> sub;
			sub.copy_child_node(sub.header, pos.get_pointer());
			return sub;
		}

		//template <class InputIt>
		//void splice(const_sibling_iterator pos, InputIt node)
		//{
		//	splice_node(pos.get_parent(), pos.get_pointer(), node.get_pointer());
		//}
		//void splice(const_sibling_iterator pos, const_sibling_iterator first, const_sibling_iterator last)
		//{
		//	splice_node(pos.get_parent(), pos.get_pointer(), first.get_pointer(), last.get_pointer());
		//}
		//
		//template <class Iterator, class InputIt>
		//void merge(Iterator pos, InputIt node)
		//{
		//	merge_node(pos.get_pointer(), node.get_pointer(), std::less<T>());
		//}
		//
		//template <class Iterator, class InputIt, class Compare>
		//void merge(Iterator pos, InputIt node, Compare comp)
		//{
		//	merge_node(pos.get_pointer(), node.get_pointer(), comp);
		//}
		//
		//void sort(bool deep)
		//{
		//	sort_node(header, deep, std::less<T>());
		//}
		//template <class Compare>
		//void sort(bool deep, Compare comp)
		//{
		//	sort_node(header, deep, comp);
		//}
		//template <class Iterator>
		//void sort(Iterator node, bool deep)
		//{
		//	sort_node(node.get_pointer(), deep, std::less<T>());
		//}
		//template <class Iterator, class Compare>
		//void sort(Iterator node, bool deep, Compare comp)
		//{
		//	sort_node(node.get_pointer(), deep, comp);
		//}
	private:
		void create_header(void)
		{
			if (header == nullptr)
			{
				header = this->create_node(value_type());
				header->parent = nullptr;
				header->prev_sibling = header;
				header->next_sibling = header;
				header->first_child = header;
				header->last_child = header;
			}
		}

		void destroy_header(void)
		{
			if (header != nullptr)
			{
				this->destroy_node(header);
				header = nullptr;
			}
		}

		node_pointer get_leftmost(const node_pointer parent) const noexcept
		{
			node_pointer node = parent;
			while (node->first_child != node)
				node = node->first_child;
			return node;
		}

		node_pointer get_rightmost(const node_pointer parent) const noexcept
		{
			node_pointer node = parent;
			while (node->last_child != node)
				node = node->last_child;
			return node;
		}

		template<class ...Args>
		node_pointer append_node(const node_pointer parent, Args&&... args)
		{
			node_pointer node = this->create_node(std::forward<Args>(args)...);
			node->parent = parent;
			node->prev_sibling = parent->last_child;
			node->next_sibling = parent;
			node->first_child = node;
			node->last_child = node;
			if (parent->last_child != parent)
				parent->last_child->next_sibling = node;
			else
				parent->first_child = node;
			parent->last_child = node;
			return node;
		}

		template<class ...Args>
		node_pointer prepend_node(const node_pointer parent, Args&&... args)
		{
			node_pointer node = this->create_node(std::forward<Args>(args)...);
			node->parent = parent;
			node->prev_sibling = parent;
			node->next_sibling = parent->first_child;
			node->first_child = node;
			node->last_child = node;
			if (parent->first_child != parent)
				parent->first_child->prev_sibling = node;
			else
				parent->last_child = node;
			parent->first_child = node;
			return node;
		}

		template<class ...Args>
		node_pointer insert_node(const node_pointer parent, const node_pointer pos, Args&&... args)
		{
			node_pointer node = this->create_node(std::forward<Args>(args)...);
			node->parent = parent;
			node->next_sibling = pos;
			node->first_child = node;
			node->last_child = node;
			if (pos == parent)
			{
				node->prev_sibling = parent->last_child;
				if (parent->last_child != parent)
					parent->last_child->next_sibling = node;
				else
					parent->first_child = node;
				parent->last_child = node;
			}
			else
			{
				node->prev_sibling = pos->prev_sibling;
				if (pos->prev_sibling != parent)
					pos->prev_sibling->next_sibling = node;
				else
					parent->first_child = node;
				pos->prev_sibling = node;
			}
			return node;
		}

		void erase_node(const node_pointer pos)
		{
			// erase all child nodes
			erase_child_node(pos);
			// remove the node from the tree
			node_pointer parent = pos->parent;
			if (pos->prev_sibling != parent)
				pos->prev_sibling->next_sibling = pos->next_sibling;
			else
				parent->first_child = pos->next_sibling;
			if (pos->next_sibling != parent)
				pos->next_sibling->prev_sibling = pos->prev_sibling;
			else
				parent->last_child = pos->prev_sibling;
			// destroy the node
			this->destroy_node(pos);
			--count;
		}

		void erase_first_child(const node_pointer parent)
		{
			node_pointer child = parent->first_child;
			if (child != parent)
			{
				// erase all child nodes
				erase_child_node(child);
				// remove the child node from the tree
				parent->first_child = child->next_sibling;
				if (child->next_sibling != parent)
					child->next_sibling->prev_sibling = parent;
				else
					parent->last_child = parent;
				// destroy the node
				this->destroy_node(child);
				--count;
			}
		}

		void erase_last_child(const node_pointer parent)
		{
			node_pointer child = parent->last_child;
			if (child != parent)
			{
				// erase all child nodes
				erase_child_node(child);
				// remove the child node from the tree
				parent->last_child = child->prev_sibling;
				if (child->prev_sibling != parent)
					child->prev_sibling->next_sibling = parent;
				else
					parent->first_child = parent;
				// destroy the node
				this->destroy_node(child);
				--count;
			}
		}

		void erase_child_node(const node_pointer parent)
		{
			node_pointer next = nullptr;
			node_pointer cur = parent->first_child;
			while (cur != parent)
			{
				while (cur->first_child != cur)
					cur = cur->first_child;
				next = cur->next_sibling;
				cur->parent->first_child = next;
				this->destroy_node(cur);
				--count;
				cur = next;
			}
			parent->first_child = parent;
			parent->last_child = parent;
		}

		void copy_child_node(const node_pointer pos, const node_pointer node)
		{
			node_pointer dst = pos;
			node_pointer src = node;
			tree_node_state state = tree_state_root;
			do
			{
				if (state != tree_state_parent)
				{
					if (src->first_child != src)
					{
						src = src->first_child;
						state = tree_state_child;
						dst = append_node(dst, src->data);
						++count;
					}
					else if (src->next_sibling != src->parent)
					{
						src = src->next_sibling;
						state = tree_state_sibling;
						dst = append_node(dst->parent, src->data);
						++count;
					}
					else
					{
						src = src->parent;
						dst = dst->parent;
						state = tree_state_parent;
					}
				}
				else
				{
					if (src->next_sibling != src->parent)
					{
						src = src->next_sibling;
						state = tree_state_sibling;
						dst = append_node(dst->parent, src->data);
						++count;
					}
					else
					{
						src = src->parent;
						dst = dst->parent;
					}
				}
			} while (src != node);
		}

		//void copy_child_node(const node_pointer pos, const node_pointer node)
		//{
		//	tree<T, Allocator> sub = sub_tree(node);
		//	// erase all the child nodes
		//	erase_child_node(pos);
		//	// replace the node
		//	replace_node(pos, sub.header);
		//	// update subtree root node
		//	sub.header = pos;
		//	// update count of nodes
		//	count += sub.count;
		//}

		//void replace_node(const node_pointer pos, const node_pointer node)
		//{
		//	node_pointer parent = pos->parent;
		//	if (parent != nullptr)
		//	{
		//		if (parent->first_child == parent)
		//			parent->first_child = node;
		//		if (parent->last_child == parent)
		//			parent->last_child = node;
		//	}
		//	node->parent = parent;
		//	if (pos->prev_sibling != parent)
		//		pos->prev_sibling->next_sibling = node;
		//	node->prev_sibling = pos->prev_sibling;
		//	if (pos->next_sibling != parent)
		//		pos->next_sibling->prev_sibling = node;
		//	node->next_sibling = pos->next_sibling;
		//}

		//void transfer_node(const node_pointer parent, const node_pointer pos, const node_pointer node)
		//{
		//	if (pos != node && pos != node->next_sibling)
		//	{
		//		if (node->prev_sibling != node->parent)
		//			node->prev_sibling->next_sibling = node->next_sibling;
		//		else
		//			node->parent->first_child = node->next_sibling;
		//		if (node->next_sibling != node->parent)
		//			node->next_sibling->prev_sibling = node->prev_sibling;
		//		else
		//			node->parent->last_child = node->prev_sibling;
		//		if (pos == parent)
		//		{
		//			node->prev_sibling = parent->last_child;
		//			node->next_sibling = nullptr;
		//			if (parent->last_child != nullptr)
		//				parent->last_child->next_sibling = node;
		//			else
		//				parent->first_child = node;
		//			parent->last_child = node;
		//		}
		//		else
		//		{
		//			node->prev_sibling = pos->prev_sibling;
		//			node->next_sibling = pos;
		//			if (pos->prev_sibling != nullptr)
		//				pos->prev_sibling->next_sibling = node;
		//			else
		//				parent->first_child = node;
		//			pos->prev_sibling = node;
		//		}
		//	}
		//}

		//void transfer_node(const node_pointer parent, const node_pointer pos, const node_pointer first, const node_pointer last)
		//{
		//	node_pointer node = (last != first->parent) ? last->prev_sibling : last->last_child;
		//	if (pos != first && pos != node->next_sibling)
		//	{
		//		if (first->prev_sibling != nullptr)
		//			first->prev_sibling->next_sibling = node->next_sibling;
		//		else
		//			first->parent->first_child = node->next_sibling;
		//		if (node->next_sibling != nullptr)
		//			node->next_sibling->prev_sibling = first->prev_sibling;
		//		else
		//			first->parent->last_child = first->prev_sibling;
		//		if (pos == parent)
		//		{
		//			first->prev_sibling = parent->last_child;
		//			node->next_sibling = nullptr;
		//			if (parent->last_child != nullptr)
		//				parent->last_child->next_sibling = first;
		//			else
		//				parent->first_child = first;
		//			parent->last_child = node;
		//		}
		//		else
		//		{
		//			first->prev_sibling = pos->prev_sibling;
		//			node->next_sibling = pos;
		//			if (pos->prev_sibling != nullptr)
		//				pos->prev_sibling->next_sibling = first;
		//			else
		//				parent->first_child = first;
		//			pos->prev_sibling = node;
		//		}
		//	}
		//}

		//void splice_node(const node_pointer parent, const node_pointer pos, const node_pointer node)
		//{
		//	transfer_node(parent, pos, node);
		//	node->parent = parent;
		//}

		//void splice_node(const node_pointer parent, const node_pointer pos, const node_pointer first, const node_pointer last)
		//{
		//	transfer_node(parent, pos, first, last);
		//	if (parent != first->parent)
		//		for (node_pointer p = first; p != nullptr && p != last; p = p->next_sibling)
		//			p->parent = parent;
		//}

		//template <class Compare>
		//void merge_node(const node_pointer pos, const node_pointer node, Compare comp)
		//{
		//	if (pos != node)
		//	{
		//		node_pointer dst = pos->first_child;
		//		node_pointer src = node->first_child;

		//		while (dst != nullptr && src != nullptr)
		//		{
		//			if (comp(src->data, dst->data))
		//			{
		//				node_pointer next = src->next_sibling;
		//				splice_node(pos, dst, src);
		//				src = next;
		//			}
		//			else
		//				dst = dst->next_sibling;
		//		}
		//		if (src != nullptr)
		//			splice_node(pos, pos, src, node);
		//	}
		//}

		//template <class Compare>
		//void sort_node(const node_pointer parent, bool deep, Compare comp)
		//{
		//	tree<T, Allocator> carry;
		//	tree<T, Allocator> counter[64];
		//	if (deep)
		//	{
		//		node_pointer node = parent;
		//		do
		//		{
		//			if (node->first_child != nullptr)
		//				node = node->first_child;
		//			else
		//			{
		//				while (node != parent && node->next_sibling == nullptr)
		//				{
		//					node = node->parent;
		//					sort_single_node(carry, counter, node, comp);
		//				}
		//				node = node->next_sibling;
		//			}
		//		} while (node != parent);
		//	}
		//	else
		//		sort_single_node(carry, counter, parent, comp);
		//}

		//template <class Compare>
		//void sort_single_node(tree<T, Allocator>&carry, tree<T, Allocator>* counter, const node_pointer parent, Compare comp)
		//{
		//	if (parent->first_child == nullptr || parent->first_child == parent->last_child)
		//		return;
		//	int fill = 0;
		//	while (parent->first_child != nullptr)
		//	{
		//		int i = 0;
		//		carry.splice_node(carry.header, carry.header, parent->first_child);
		//		while (i < fill && !counter[i].empty())
		//		{
		//			counter[i].merge_node(counter[i].header, carry.header, comp);
		//			carry.swap(counter[i++]);
		//		}
		//		carry.swap(counter[i]);
		//		if (i == fill)
		//			++fill;
		//	}
		//	for (int i = 1; i < fill; ++i)
		//		counter[i].merge_node(counter[i].header, counter[i - 1].header, comp);
		//	splice_node(parent, parent, counter[fill - 1].header->first_child, counter[fill - 1].header);
		//}
	private:
		node_pointer header;
		size_type    count;
	};

} // namespace core

#endif
