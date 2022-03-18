#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>

namespace ft
{
	template< typename T, typename Allocator = std::allocator<T> > class Vector
	{
		// template< typename T1>class RandomAccessIterator
		// {

		// };




	//Vector
	public:
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		typedef RandomAccesIterator<value_type> iterator;
		typedef RandomAccesIterator<const value_type> const_iterator;
		typedef reverse_iterator<iterator> reverse_iterator;
		typedef reverse_iterator<const_iterator> const_reverse_iterator;
		typedef std::ptrdiff_t difference_type;
		typedef std::size_t size_type;


	private:
		pointer		_first;
		size_type 	_size, _capacity;
		allocator_type	_allocator;

	public:

		//CONSTRUCTORS

		//default

		explicit Vector(const allocator_type &alloc = allocator_type())
		{
			_first = 0;
			_size = 0;
			_capacity = 0;
			_allocator = alloc;
		}

		//fill
		explicit Vector(size_type n, const value_type &val = value_type(),
				const allocator_type &alloc = allocator_type())
		{
			_size = n;
			_capacity = n;
			_allocator = alloc;
			_first = _allocator.allocate(n);
			for (size_type i = 0; i < n; i++)
				_allocator.construct(_first + i, val);
		}

		//range
		//...//

		//OPERATOR=
		Vector &operator=(const Vector &x)
		{
			if (this == &x)
				return *this;
			for (size_type i = 0; i < _size; i++)
				_allocator.destroy(_first + i);
			this->_size = x._size;
			if(_capacity < _size)
			{
				if (_capacity != 0)
					_allocator.deallocate(_first, _capacity);
				_capacity = _size;
				_first = _allocator.allocate(_capacity);
			}
			for (size_type i = 0; i < _size; i++)
				_allocator.construct(_first + i, x[i]);
			return *this;

		}

		//copy
		Vector(const Vector &x) : _size(0),_capacity(0)
		{
			*this = x;
		}

		//DESTRUCTOR
		~Vector()
		{
			for (size_type i = 0; i < _size; i++)
				_allocator.destroy(_first + i);
			if (_capacity)
				_allocator.deallocate(_first, _capacity);
		}


		//CAPACITY

		size_type size() const {return _size;}

		size_type max_size() const {return (_allocator.max_size());}

		//reserve...
		//resize...


		size_type capacity() const {return _capacity;}

		bool empty() const {return _size == 0;}


		//ELEMENT ACCESS


		reference operator[] (size_type n)
		{
			return(*(_first + n));
		}

		const_reference operator[] (size_type n) const
		{
			return(*(_first + n));
		}

		reference at (size_type n)
		{
			if(n > _capacity)
				throw std::out_of_range("vector at out of range");
			return(*(_first + n));
		}

		const_reference at (size_type n) const
		{
			if(n > _capacity)
				throw std::out_of_range("vector at out of range");
			return(*(_first + n));
		}

		reference front()
		{
			return(*_first);
		}

		const_reference front() const
		{
			return(*_first);
		}

		reference back()
		{
			return(*(_first + _size - 1));
		}

		const_reference back() const
		{
			return(*(_first + _size - 1));
		}



		void clear()
		{
			for (size_type i = 0; i < _size; i++)
				_allocator.destroy(_first + i);
			_size = 0;
		}

		//ALLOCATOR
		allocator_type get_allocator() const
		{
			return(_allocator);
		}





};





}


#endif
