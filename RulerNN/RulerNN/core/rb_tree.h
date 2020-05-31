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

#ifndef __CORE_RB_TREE_H__
#define __CORE_RB_TREE_H__

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
	using rb_tree_color_type = bool;
	static constexpr rb_tree_color_type rb_tree_red   = false;
	static constexpr rb_tree_color_type rb_tree_black = true;

	using rb_tree_node_state = signed char;
	static constexpr rb_tree_node_state rb_tree_state_parent  = -0x10;
	static constexpr rb_tree_node_state rb_tree_state_sibling =  0x01;
	static constexpr rb_tree_node_state rb_tree_state_left    =  0x12;
	static constexpr rb_tree_node_state rb_tree_state_right   =  0x13;
	static constexpr rb_tree_node_state rb_tree_state_root    =  0x04;


	// Class template rb_tree_node
	template <class T>
	struct rb_tree_node
	{
		using node_type            = rb_tree_node<T>;
		using node_pointer         = node_type*;
		using const_node_pointer   = const node_type*;
		using node_reference       = node_type&;
		using const_node_reference = const node_type&;

		node_pointer               parent;
		node_pointer               left;
		node_pointer               right;
		rb_tree_color_type         color;
		T                          data;
	};


	// Class template rb_tree_type_traits

	template <class Tree, bool IsConst>
	struct rb_tree_type_traits
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
	struct rb_tree_type_traits<Tree, true>
	{
		using value_type      = typename Tree::value_type;
		using pointer         = typename Tree::const_pointer;
		using size_type       = typename Tree::size_type;
		using difference_type = typename Tree::difference_type;
		using node_type       = typename Tree::node_type;
		using node_pointer    = typename Tree::node_pointer;
		using reference       = const value_type&;
	};


	// Class template rb_tree_iterator
	template <class Tree, bool IsConst>
	class rb_tree_iterator
	{
	public:
		// types:

		using value_type        = typename rb_tree_type_traits<Tree, IsConst>::value_type;
		using pointer           = typename rb_tree_type_traits<Tree, IsConst>::pointer;
		using reference         = typename rb_tree_type_traits<Tree, IsConst>::reference;
		using size_type         = typename rb_tree_type_traits<Tree, IsConst>::size_type;
		using difference_type   = typename rb_tree_type_traits<Tree, IsConst>::difference_type;
		using node_type         = typename rb_tree_type_traits<Tree, IsConst>::node_type;
		using node_pointer      = typename rb_tree_type_traits<Tree, IsConst>::node_pointer;

		using iterator_type     = rb_tree_iterator<Tree, IsConst>;
		using iterator_category = std::bidirectional_iterator_tag;

		// construct/copy/destroy:

		rb_tree_iterator(void) noexcept
			: node(nullptr)
		{}
		explicit rb_tree_iterator(const node_pointer ptr) noexcept
			: node(ptr)
		{}
		rb_tree_iterator(const rb_tree_iterator<Tree, IsConst>& other) noexcept
			: node(other.get_pointer())
		{}

		rb_tree_iterator<Tree, IsConst>& operator=(const rb_tree_iterator<Tree, IsConst>& other) noexcept
		{
			if (this != &other)
				node = other.get_pointer();
			return (*this);
		}

		operator rb_tree_iterator<Tree, true>(void) const noexcept
		{
			return rb_tree_iterator<Tree, true>(node);
		}

		// rb_tree_iterator operations:

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

		rb_tree_color_type get_color(void) const noexcept
		{
			return node->color;
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

		rb_tree_iterator<Tree, IsConst>& operator++(void) noexcept
		{
			if (node->right != nullptr)
			{
				node = node->right;
				while (node->left != nullptr)
					node = node->left;
			}
			else
			{
				node_pointer ptr = node->parent;
				while (node == ptr->right)
				{
					node = ptr;
					ptr = ptr->parent;
				}
				if (node->right != ptr)
					node = ptr;
			}
			return (*this);
		}
		rb_tree_iterator<Tree, IsConst>& operator--(void) noexcept
		{
			if (node->color == rb_tree_red && node->parent->parent == node)
			{
				node = node->right;
			}
			else if (node->left != nullptr)
			{
				node_pointer ptr = node->left;
				while (ptr->right != nullptr)
					ptr = ptr->right;
				node = ptr;
			}
			else
			{
				node_pointer ptr = node->parent;
				while (node == ptr->left)
				{
					node = ptr;
					ptr = ptr->parent;
				}
				node = ptr;
			}
			return (*this);
		}
		rb_tree_iterator<Tree, IsConst> operator++(int) noexcept
		{
			iterator_type tmp(*this);
			this->operator++();
			return tmp;
		}
		rb_tree_iterator<Tree, IsConst> operator--(int) noexcept
		{
			iterator_type tmp(*this);
			this->operator--();
			return tmp;
		}

		// relational operators:

		template <bool is_const>
		bool operator==(const rb_tree_iterator<Tree, is_const>& rhs) const noexcept
		{
			return (node == rhs.get_pointer());
		}
		template <bool is_const>
		bool operator!=(const rb_tree_iterator<Tree, is_const>& rhs) const noexcept
		{
			return (node != rhs.get_pointer());
		}
	private:
		node_pointer node;
	};


	// Class template rb_tree_primitive_iterator
	template <class Tree, bool IsConst>
	class rb_tree_primitive_iterator
	{
	public:
		// types:

		using value_type        = typename rb_tree_type_traits<Tree, IsConst>::value_type;
		using pointer           = typename rb_tree_type_traits<Tree, IsConst>::pointer;
		using reference         = typename rb_tree_type_traits<Tree, IsConst>::reference;
		using size_type         = typename rb_tree_type_traits<Tree, IsConst>::size_type;
		using difference_type   = typename rb_tree_type_traits<Tree, IsConst>::difference_type;
		using node_type         = typename rb_tree_type_traits<Tree, IsConst>::node_type;
		using node_pointer      = typename rb_tree_type_traits<Tree, IsConst>::node_pointer;

		using iterator_type     = rb_tree_primitive_iterator<Tree, IsConst>;
		using iterator_category = std::bidirectional_iterator_tag;

		// construct/copy/destroy:

		rb_tree_primitive_iterator(void) noexcept
			: node(nullptr)
			, state(rb_tree_state_root)
		{}
		explicit rb_tree_primitive_iterator(const node_pointer ptr) noexcept
			: node(ptr)
			, state(rb_tree_state_root)
		{}
		rb_tree_primitive_iterator(const rb_tree_primitive_iterator<Tree, IsConst>& other) noexcept
			: node(other.get_pointer())
			, state(other.get_state())
		{}

		rb_tree_primitive_iterator<Tree, IsConst>& operator=(const rb_tree_primitive_iterator<Tree, IsConst>& other) noexcept
		{
			if (this != &other)
			{
				node = other.get_pointer();
				state = other.get_state();
			}
			return (*this);
		}

		operator rb_tree_primitive_iterator<Tree, true>(void) const noexcept
		{
			return rb_tree_primitive_iterator<Tree, true>(node);
		}

		// rb_tree_primitive_iterator operations:

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

		rb_tree_node_state get_state(void) const noexcept
		{
			return state;
		}

		intptr_t get_depth(void) const noexcept
		{
			return static_cast<intptr_t>(state >> 4);
		}

		rb_tree_color_type get_color(void) const noexcept
		{
			return node->color;
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

		rb_tree_primitive_iterator<Tree, IsConst>& operator++(void) noexcept
		{
			if (state != rb_tree_state_parent)
			{
				if (node->left != nullptr)
				{
					node = node->left;
					state = rb_tree_state_left;
				}
				else if (node->right != nullptr)
				{
					node = node->right;
					state = rb_tree_state_right;
				}
				else if (node != node->parent->parent && node != node->parent->right)
				{
					node = node->parent->right;
					state = rb_tree_state_sibling;
				}
				else
				{
					node = node->parent;
					state = rb_tree_state_parent;
				}
			}
			else
			{
				if (node != node->parent->parent && node != node->parent->right)
				{
					node = node->parent->right;
					state = rb_tree_state_sibling;
				}
				else
					node = node->parent;
			}
			return (*this);
		}
		rb_tree_primitive_iterator<Tree, IsConst>& operator--(void) noexcept
		{
			if (state != rb_tree_state_parent)
			{
				if (node->right != nullptr)
				{
					node = node->right;
					state = rb_tree_state_right;
				}
				else if (node->left != nullptr)
				{
					node = node->left;
					state = rb_tree_state_left;
				}
				else if (node != node->parent->parent && node != node->parent->left)
				{
					node = node->parent->left;
					state = rb_tree_state_sibling;
				}
				else
				{
					node = node->parent;
					state = rb_tree_state_parent;
				}
			}
			else
			{
				if (node != node->parent->parent && node != node->parent->left)
				{
					node = node->parent->left;
					state = rb_tree_state_sibling;
				}
				else
					node = node->parent;
			}
			return (*this);
		}
		rb_tree_primitive_iterator<Tree, IsConst> operator++(int) noexcept
		{
			iterator_type tmp(*this);
			this->operator++();
			return tmp;
		}
		rb_tree_primitive_iterator<Tree, IsConst> operator--(int) noexcept
		{
			iterator_type tmp(*this);
			this->operator--();
			return tmp;
		}

		// relational operators:

		template <bool is_const>
		bool operator==(const rb_tree_primitive_iterator<Tree, is_const>& rhs) const noexcept
		{
			return (node == rhs.get_pointer());
		}
		template <bool is_const>
		bool operator!=(const rb_tree_primitive_iterator<Tree, is_const>& rhs) const noexcept
		{
			return (node != rhs.get_pointer());
		}
	private:
		node_pointer       node;
		rb_tree_node_state state;
	};


	// Class template rb_tree_node_allocator
	template <class T, class Allocator>
	class rb_tree_node_allocator : public Allocator
	{
	public:
		// types:

		using allocator_type             = Allocator;
		using tree_node_type             = typename rb_tree_node<T>::node_type;
		using node_allocator_type        = typename Allocator::template rebind<tree_node_type>::other;
		using node_allocator_traits_type = std::allocator_traits<node_allocator_type>;
		using node_type                  = typename node_allocator_traits_type::value_type;
		using node_pointer               = typename node_allocator_traits_type::pointer;
		using node_size_type             = typename node_allocator_traits_type::size_type;
		using node_difference_type       = typename node_allocator_traits_type::difference_type;

		// construct/copy/destroy:

		rb_tree_node_allocator(void)
			: Allocator()
		{}
		explicit rb_tree_node_allocator(const Allocator& alloc)
			: Allocator(alloc)
		{}
		explicit rb_tree_node_allocator(Allocator&& alloc)
			: Allocator(std::forward<Allocator>(alloc))
		{}
		~rb_tree_node_allocator(void)
		{}

		// rb_tree_node_allocator operations:

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


	// Class template rb_tree
	template <class T, class Compare = std::less<T>, class Allocator = DEFAULT_ALLOCATOR(T)>
	class rb_tree : public rb_tree_node_allocator<T, Allocator>
	{
	public:
		// types:

		using compare_type                     = Compare;
		using allocator_type                   = Allocator;
		using tree_type                        = rb_tree<T, Compare, Allocator>;
		using node_allocator_type              = rb_tree_node_allocator<T, Allocator>;
		using allocator_traits_type            = std::allocator_traits<allocator_type>;
		using node_allocator_traits_type       = std::allocator_traits<node_allocator_type>;
		using value_type                       = typename allocator_traits_type::value_type;
		using pointer                          = typename allocator_traits_type::pointer;
		using const_pointer                    = typename allocator_traits_type::const_pointer;
		using size_type                        = typename allocator_traits_type::size_type;
		using difference_type                  = typename allocator_traits_type::difference_type;
		using node_type                        = typename node_allocator_type::node_type;
		using node_pointer                     = typename node_allocator_type::node_pointer;

		using iterator                         = rb_tree_iterator<tree_type, false>;
		using const_iterator                   = rb_tree_iterator<tree_type, true>;
		using primitive_iterator               = rb_tree_primitive_iterator<tree_type, false>;
		using const_primitive_iterator         = rb_tree_primitive_iterator<tree_type, true>;
		using reverse_iterator                 = std::reverse_iterator<iterator>;
		using const_reverse_iterator           = std::reverse_iterator<const_iterator>;
		using reverse_primitive_iterator       = std::reverse_iterator<primitive_iterator>;
		using const_reverse_primitive_iterator = std::reverse_iterator<const_primitive_iterator>;

		// construct/copy/destroy:

		explicit rb_tree(const Compare& comp = Compare(), const Allocator& alloc = Allocator())
			: node_allocator_type(alloc)
			, compare(comp)
			, header(nullptr)
			, count(0)
		{
			create_header();
		}
		explicit rb_tree(const Allocator& alloc)
			: node_allocator_type(alloc)
			, compare(Compare())
			, header(nullptr)
			, count(0)
		{
			create_header();
		}
		rb_tree(const rb_tree<T, Compare, Allocator>& other)
			: node_allocator_type(other.get_allocator())
			, compare(other.compare)
			, header(nullptr)
			, count(0)
		{
			create_header();
			if (other.header->parent != nullptr)
				copy_root(other.header->parent);
			count = other.count;
		}
		rb_tree(const rb_tree<T, Compare, Allocator>& other, const Allocator& alloc)
			: node_allocator_type(alloc)
			, compare(other.compare)
			, header(nullptr)
			, count(0)
		{
			create_header();
			if (other.header->parent != nullptr)
				copy_root(other.header->parent);
			count = other.count;
		}
		rb_tree(rb_tree<T, Compare, Allocator>&& other) noexcept
			: node_allocator_type(other.get_allocator())
			, compare(Compare())
			, header(nullptr)
			, count(0)
		{
			create_header();
			swap(other);
		}
		rb_tree(rb_tree<T, Compare, Allocator>&& other, const Allocator& alloc) noexcept
			: node_allocator_type(alloc)
			, compare(Compare())
			, header(nullptr)
			, count(0)
		{
			create_header();
			swap(other);
		}
		rb_tree(std::initializer_list<T> ilist, const Allocator& alloc = Allocator())
			: node_allocator_type(alloc)
			, compare(Compare())
			, header(nullptr)
			, count(0)
		{
			create_header();
			insert_unique(ilist.begin(), ilist.end());
		}
		~rb_tree(void)
		{
			clear();
			destroy_header();
		}
		rb_tree<T, Compare, Allocator>& operator=(const rb_tree<T, Compare, Allocator>& other)
		{
			if (this != &other)
			{
				clear();
				if (other.header->parent != nullptr)
					copy_root(other.header->parent);
				compare = other.compare;
				count = other.count;
			}
			return (*this);
		}
		rb_tree<T, Compare, Allocator>& operator=(rb_tree<T, Compare, Allocator>&& other)
		{
			if (this != &other)
				swap(other);
			return (*this);
		}
		void assign_equal(const_iterator first, const_iterator last)
		{
			clear();
			insert_equal(first, last);
		}
		void assign_equal(size_type n, const value_type& value)
		{
			clear();
			insert_equal(n, value);
		}
		void assign_equal(std::initializer_list<value_type> ilist)
		{
			clear();
			insert_equal(ilist.begin(), ilist.end());
		}
		void assign_unique(const_iterator first, const_iterator last)
		{
			clear();
			insert_unique(first, last);
		}
		void assign_unique(const value_type& value)
		{
			clear();
			insert_unique(value);
		}
		void assign_unique(std::initializer_list<value_type> ilist)
		{
			clear();
			insert_unique(ilist.begin(), ilist.end());
		}

		// iterators:

		iterator begin(void) noexcept
		{
			return iterator(header->left);
		}
		const_iterator begin(void) const noexcept
		{
			return const_iterator(header->left);
		}
		const_iterator cbegin(void) const noexcept
		{
			return const_iterator(header->left);
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
			return primitive_iterator(get_root());
		}
		const_primitive_iterator pbegin(void) const noexcept
		{
			return const_primitive_iterator(get_root());
		}
		const_primitive_iterator cpbegin(void) const noexcept
		{
			return const_primitive_iterator(get_root());
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

		// capacity:

		bool empty(void) const noexcept
		{
			return (count == 0);
		}

		size_type size(void) const noexcept
		{
			return count;
		}

		// observers:

		compare_type comp(void) const
		{
			return compare;
		}

		// modifiers:

		template <class... Args>
		iterator emplace_equal(Args&&... args)
		{
			return iterator(insert_equal_node(std::forward<Args>(args)...));
		}

		iterator insert_equal(const value_type& value)
		{
			return iterator(insert_equal_node(value));
		}

		iterator insert_equal(value_type&& value)
		{
			return iterator(insert_equal_node(std::forward<value_type>(value)));
		}

		void insert_equal(size_type n, const value_type& value)
		{
			for (; n > 0; --n)
				insert_equal_node(value);
		}

		template <class InputIt>
		void insert_equal(InputIt first, InputIt last)
		{
			for (; first != last; ++first)
				insert_equal_node(*first);
		}

		template <class InputIt>
		void insert_equal(std::initializer_list<value_type> ilist)
		{
			insert_equal(ilist.begin(), ilist.end());
		}

		template <class... Args>
		iterator emplace_unique(Args&&... args)
		{
			return iterator(insert_unique_node(std::forward<Args>(args)...));
		}

		iterator insert_unique(const value_type& value)
		{
			return iterator(insert_unique_node(value));
		}

		iterator insert_unique(value_type&& value)
		{
			return iterator(insert_unique_node(std::forward<value_type>(value)));
		}

		template <class InputIt>
		void insert_unique(InputIt first, InputIt last)
		{
			for (; first != last; ++first)
				insert_unique_node(*first);
		}

		void insert_unique(std::initializer_list<value_type> ilist)
		{
			insert_unique(ilist.begin(), ilist.end());
		}

		void erase(iterator position)
		{
			erase_node(position.get_pointer(), header->parent);
		}

		void erase(iterator first, iterator last)
		{
			if (first == begin() && last == end())
				clear();
			else
				while (first != last)
					erase(first++);
		}

		template <class KeyType>
		size_type erase(const KeyType& key)
		{
			size_type n = 0;
			iterator first = lower_bound(key);
			iterator last = upper_bound(key);
			while (first != last)
			{
				++n;
				erase(first++);
			}
			return n;
		}

		void swap(rb_tree<T, Compare, Allocator>& rhs) noexcept
		{
			if (this != &rhs)
			{
				std::swap(header, rhs.header);
				std::swap(compare, rhs.compare);
				std::swap(count, rhs.count);
			}
		}

		void clear(void)
		{
			if (header->parent != nullptr)
			{
				erase_root();
				header->parent = nullptr;
				header->left = header;
				header->right = header;
				count = 0;
			}
		}

		// operations:

		template <class KeyType>
		iterator find(const KeyType& key) noexcept
		{
			return iterator(find_node(key));
		}
		template <class KeyType>
		const_iterator find(const KeyType& key) const noexcept
		{
			return const_iterator(find_node(key));
		}

		template <class KeyType>
		iterator lower_bound(const KeyType& key) noexcept
		{
			return iterator(lower_bound_node(key));
		}
		template <class KeyType>
		const_iterator lower_bound(const KeyType& key) const noexcept
		{
			return const_iterator(lower_bound_node(key));
		}

		template <class KeyType>
		iterator upper_bound(const KeyType& key) noexcept
		{
			return iterator(upper_bound_node(key));
		}
		template <class KeyType>
		const_iterator upper_bound(const KeyType& key) const noexcept
		{
			return const_iterator(upper_bound_node(key));
		}
	private:
		node_pointer get_root(void) const noexcept
		{
			return (header->parent != nullptr ? header->parent : header);
		}

		node_pointer get_leftmost(const node_pointer parent) const noexcept
		{
			node_pointer leftmost = parent;
			while (leftmost->left)
				leftmost = leftmost->left;
			return leftmost;
		}

		node_pointer get_rightmost(const node_pointer parent) const noexcept
		{
			node_pointer rightmost = parent;
			while (rightmost->right)
				rightmost = rightmost->right;
			return rightmost;
		}

		void create_header(void)
		{
			if (header == nullptr)
			{
				header = this->create_node(value_type());
				header->color = rb_tree_red;
				header->parent = nullptr;
				header->left = header;
				header->right = header;
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

		template <class KeyType>
		node_pointer find_node(const KeyType& key) const noexcept
		{
			node_pointer pre = header;
			node_pointer cur = header->parent;
			while (cur != nullptr)
			{
				if (!compare(cur->data, key))
				{
					pre = cur;
					cur = cur->left;
				}
				else
					cur = cur->right;
			}
			if (pre == header || compare(key, pre->data))
			{
				pre = header;
			}
			return pre;
		}

		template <class KeyType>
		node_pointer lower_bound_node(const KeyType& key) const noexcept
		{
			node_pointer pre = header;
			node_pointer cur = header->parent;
			while (cur != nullptr)
			{
				if (!compare(cur->data, key))
				{
					pre = cur;
					cur = cur->left;
				}
				else
					cur = cur->right;
			}
			return pre;
		}

		template <class KeyType>
		node_pointer upper_bound_node(const KeyType& key) const noexcept
		{
			node_pointer pre = header;
			node_pointer cur = header->parent;
			while (cur != nullptr)
			{
				if (compare(key, cur->data))
				{
					pre = cur;
					cur = cur->left;
				}
				else
					cur = cur->right;
			}
			return pre;
		}

		template<class ...Args>
		node_pointer insert_equal_node(Args&&... args)
		{
			node_pointer node = this->create_node(std::forward<Args>(args)...);
			node->left = nullptr;
			node->right = nullptr;
			if (header->parent == nullptr)
			{
				node->parent = header;
				header->parent = node;
				header->left = node;
				header->right = node;
			}
			else
			{
				node_pointer ptr = header->parent;
				while (ptr != nullptr)
				{
					if (compare(node->data, ptr->data))
					{
						if (ptr->left != nullptr)
							ptr = ptr->left;
						else
						{
							node->parent = ptr;
							ptr->left = node;
							if (ptr == header->left)
								header->left = node;
							ptr = nullptr;
						}
					}
					else
					{
						if (ptr->right != nullptr)
							ptr = ptr->right;
						else
						{
							node->parent = ptr;
							ptr->right = node;
							if (ptr == header->right)
								header->right = node;
							ptr = nullptr;
						}
					}
				}
				insert_rebalance(node, header->parent);
			}
			++count;
			return node;
		}

		template<class ...Args>
		node_pointer insert_unique_node(Args&&... args)
		{
			node_pointer node = nullptr;
			value_type value = value_type(std::forward<Args>(args)...);
			if (header->parent == nullptr)
			{
				node = this->create_node(std::forward<value_type>(value));
				node->parent = header;
				node->left = nullptr;
				node->right = nullptr;
				header->parent = node;
				header->left = node;
				header->right = node;
			}
			else
			{
				node_pointer ptr = header->parent;
				while (ptr != nullptr)
				{
					if (compare(value, ptr->data))
					{
						if (ptr->left != nullptr)
							ptr = ptr->left;
						else
						{
							node = this->create_node(std::forward<value_type>(value));
							node->parent = ptr;
							node->left = nullptr;
							node->right = nullptr;
							ptr->left = node;
							if (ptr == header->left)
								header->left = node;
							ptr = nullptr;
						}
					}
					else
					{
						if (!compare(ptr->data, value))
							return ptr;
						if (ptr->right != nullptr)
							ptr = ptr->right;
						else
						{
							node = this->create_node(std::forward<value_type>(value));
							node->parent = ptr;
							node->left = nullptr;
							node->right = nullptr;
							ptr->right = node;
							if (ptr == header->right)
								header->right = node;
							ptr = nullptr;
						}
					}
				}
				insert_rebalance(node, header->parent);
			}
			++count;
			return node;
		}

		void erase_node(node_pointer position, node_pointer& root)
		{
			rb_tree_color_type color;
			node_pointer p = nullptr;
			node_pointer x = nullptr;
			node_pointer y = position;
			node_pointer z = position;
			if (y->left == nullptr || y->right == nullptr)
			{
				p = y->parent;
				x = (y->left == nullptr) ? y->right : y->left;
				if (x != nullptr)
					x->parent = y->parent;
				if (z == root)
					root = x;
				else if (z == z->parent->left)
					z->parent->left = x;
				else
					z->parent->right = x;
				if (z == header->left)
					header->left = (z->right == nullptr) ? z->parent : get_leftmost(x);
				if (z == header->right)
					header->right = (z->left == nullptr) ? z->parent : get_rightmost(x);
			}
			else
			{
				y = z->right;
				while (y->left != nullptr)
					y = y->left;
				x = y->right;
				if (y == z->right)
				{
					p = y;
					z->left->parent = y;
					y->left = z->left;
				}
				else
				{
					p = y->parent;
					z->left->parent = y;
					z->right->parent = y;
					y->left = z->left;
					y->right = z->right;
					y->parent->left = x;
					if (x != nullptr)
						x->parent = y->parent;
				}
				if (z == root)
					root = y;
				else if (z == z->parent->left)
					z->parent->left = y;
				else
					z->parent->right = y;
				y->parent = z->parent;
				color = y->color;
				y->color = z->color;
				z->color = color;
				y = z;
			}
			if (y->color != rb_tree_red)
				erase_rebalance(p, x, root);
			this->destroy_node(y);
			--count;
		}

		void copy_root(const node_pointer root)
		{
			node_pointer src = root;
			node_pointer dst = header;
			rb_tree_node_state state = rb_tree_state_root;
			node_pointer node = this->create_node(root->data);
			node->color = root->color;
			node->parent = dst;
			node->left = nullptr;
			node->right = nullptr;
			dst->parent = node;
			dst = node;
			do
			{
				if (state != rb_tree_state_parent)
				{
					if (src->left != nullptr)
					{
						src = src->left;
						state = rb_tree_state_left;
						node = this->create_node(src->data);
						node->color = src->color;
						node->parent = dst;
						node->left = nullptr;
						node->right = nullptr;
						dst->left = node;
						dst = node;
					}
					else if (src->right != nullptr)
					{
						src = src->right;
						state = rb_tree_state_right;
						node = this->create_node(src->data);
						node->color = src->color;
						node->parent = dst;
						node->left = nullptr;
						node->right = nullptr;
						dst->right = node;
						dst = node;
					}
					else if (src != src->parent->parent && src != src->parent->right)
					{
						src = src->parent->right;
						state = rb_tree_state_sibling;
						node = this->create_node(src->data);
						node->color = src->color;
						node->parent = dst->parent;
						node->left = nullptr;
						node->right = nullptr;
						dst->parent->right = node;
						dst = node;
					}
					else
					{
						src = src->parent;
						dst = dst->parent;
						state = rb_tree_state_parent;
					}
				}
				else
				{
					if (src != src->parent->parent && src != src->parent->right)
					{
						src = src->parent->right;
						state = rb_tree_state_sibling;
						node = this->create_node(src->data);
						node->color = src->color;
						node->parent = dst->parent;
						node->left = nullptr;
						node->right = nullptr;
						dst->parent->right = node;
						dst = node;
					}
					else
					{
						src = src->parent;
						dst = dst->parent;
					}
				}
			} while (src != root);
			header->left = get_leftmost(header->parent);
			header->right = get_rightmost(header->parent);
		}

		void erase_root(void)
		{
			node_pointer next = nullptr;
			node_pointer cur = header->parent;
			do
			{
				while (cur->left != nullptr)
					cur = cur->left;
				if (cur->right != nullptr)
					cur = cur->right;
				else
				{
					next = cur->parent;
					if (cur == next->left)
						next->left = nullptr;
					else
						next->right = nullptr;
					this->destroy_node(cur);
					cur = next;
				}
			} while (cur != header);
		}

		void rotate_left(node_pointer x, node_pointer& root) const noexcept
		{
			node_pointer y = x->right;
			x->right = y->left;
			if (y->left != nullptr)
				y->left->parent = x;
			y->parent = x->parent;
			if (x == root)
				root = y;
			else if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
			y->left = x;
			x->parent = y;
		}

		void rotate_right(node_pointer x, node_pointer& root) const noexcept
		{
			node_pointer y = x->left;
			x->left = y->right;
			if (y->right != nullptr)
				y->right->parent = x;
			y->parent = x->parent;
			if (x == root)
				root = y;
			else if (x == x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;
			y->right = x;
			x->parent = y;
		}

		void insert_rebalance(node_pointer x, node_pointer& root) const noexcept
		{
			x->color = rb_tree_red;
			while (x != root && x->parent->color == rb_tree_red)
			{
				if (x->parent == x->parent->parent->left)
				{
					node_pointer y = x->parent->parent->right;
					if (y && y->color == rb_tree_red)
					{
						x->parent->color = rb_tree_black;
						y->color = rb_tree_black;
						x->parent->parent->color = rb_tree_red;
						x = x->parent->parent;
					}
					else
					{
						if (x == x->parent->right)
						{
							x = x->parent;
							rotate_left(x, root);
						}
						x->parent->color = rb_tree_black;
						x->parent->parent->color = rb_tree_red;
						rotate_right(x->parent->parent, root);
					}
				}
				else
				{
					node_pointer y = x->parent->parent->left;
					if (y && y->color == rb_tree_red)
					{
						x->parent->color = rb_tree_black;
						y->color = rb_tree_black;
						x->parent->parent->color = rb_tree_red;
						x = x->parent->parent;
					}
					else
					{
						if (x == x->parent->left)
						{
							x = x->parent;
							rotate_right(x, root);
						}
						x->parent->color = rb_tree_black;
						x->parent->parent->color = rb_tree_red;
						rotate_left(x->parent->parent, root);
					}
				}
			}
			root->color = rb_tree_black;
		}

		void erase_rebalance(node_pointer p, node_pointer x, node_pointer& root) const noexcept
		{
			while (x != root && (x == nullptr || x->color == rb_tree_black))
			{
				if (x == p->left)
				{
					node_pointer s = p->right;
					if (s->color == rb_tree_red)
					{
						s->color = rb_tree_black;
						p->color = rb_tree_red;
						rotate_left(p, root);
						s = p->right;
					}
					if ((s->left == nullptr || s->left->color == rb_tree_black) &&
						(s->right == nullptr || s->right->color == rb_tree_black))
					{
						s->color = rb_tree_red;
						x = p;
						p = x->parent;
					}
					else
					{
						if (s->right == nullptr || s->right->color == rb_tree_black)
						{
							s->color = rb_tree_red;
							s->left->color = rb_tree_black;
							rotate_right(s, root);
							s = p->right;
						}
						s->color = p->color;
						p->color = rb_tree_black;
						s->right->color = rb_tree_black;
						rotate_left(p, root);
						break;
					}
				}
				else
				{
					node_pointer s = p->left;
					if (s->color == rb_tree_red)
					{
						s->color = rb_tree_black;
						p->color = rb_tree_red;
						rotate_right(p, root);
						s = p->left;
					}
					if ((s->right == nullptr || s->right->color == rb_tree_black) &&
						(s->left == nullptr || s->left->color == rb_tree_black))
					{
						s->color = rb_tree_red;
						x = p;
						p = x->parent;
					}
					else
					{
						if (s->left == nullptr || s->left->color == rb_tree_black)
						{
							s->color = rb_tree_red;
							s->right->color = rb_tree_black;
							rotate_left(s, root);
							s = p->left;
						}
						s->color = p->color;
						p->color = rb_tree_black;
						s->left->color = rb_tree_black;
						rotate_right(p, root);
						break;
					}
				}
			}
			if (x != nullptr)
				x->color = rb_tree_black;
		}
	private:
		compare_type compare;
		node_pointer header;
		size_type    count;
	};

} // namespace core

#endif
