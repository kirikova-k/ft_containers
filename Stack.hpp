#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include "Vector.hpp"
// #include <vector> //
// #include <deque> //

namespace ft
{
template <class T, class Container = ft::Vector<T> > //std replace ft

	class Stack
	{
		public:
		typedef T value_type;
		typedef Container container_type;
		typedef typename Container::size_type size_type;

		protected:
		container_type _container;

		public:

		explicit Stack(const container_type& cont = container_type()) : _container(cont){}

		Stack(const Stack& inst): _container(inst._container) {}

		Stack &operator=(const Stack &rhs)
		{
			_container = rhs._container;
			return *this;
		}

		bool empty() const
		{
			return _container.empty();
		}

		size_type size() const
		{
			return _container.size();
		}

		value_type &top()
		{
			return _container.back();
		}

		const value_type& top() const
		{
			return (_container.back());
		}

		void push (const value_type &val)
		{
			_container.push_back(val);
		}

		void pop()
		{
			_container.pop_back();
		}


		template <class A, class Cont>
			friend bool operator== (const Stack<A, Cont>& lhs, const Stack<A, Cont>& rhs)
		{
			return lhs._container == rhs._container;
		}

		template <class A, class Cont>
			friend bool operator!= (const Stack<A, Cont>& lhs, const Stack<A, Cont>& rhs)
		{
			return lhs._container != rhs._container;
		}

		template <class A, class Cont>
			friend bool operator< (const Stack<A, Cont>& lhs, const Stack<A, Cont>& rhs)
		{
			return lhs._container < rhs._container;
		}

		template <class A, class Cont>
			friend bool operator> (const Stack<A, Cont>& lhs, const Stack<A, Cont>& rhs)
		{
			return lhs._container > rhs._container;
		}

		template <class A, class Cont>
			friend bool operator<= (const Stack<A, Cont>& lhs, const Stack<A, Cont>& rhs)
		{
			return lhs._container <= rhs._container;
		}

		template <class A, class Cont>
			friend bool operator>= (const Stack<A, Cont>& lhs, const Stack<A, Cont>& rhs)
		{
			return lhs._container >= rhs._container;
		}
};


}
#endif
