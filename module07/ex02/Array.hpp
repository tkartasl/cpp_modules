/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:55:03 by tkartasl          #+#    #+#             */
/*   Updated: 2024/09/02 16:11:33 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H
# include <exception>

template<typename T>
class Array
{
	public:
		Array<T>(void);
		Array<T>(unsigned int n);
		Array<T>(Array<T> const& src);
		~Array<T>(void);
		
		Array<T>& operator=(Array<T> const& src);
		T& operator[](int index);
		const T& operator[](int index) const;
		
		int	size(void) const {return this->_size;}
	private:
		T* _arr;
		int _size;
};

template<typename T>
Array<T>::Array(void)
{
	this->_arr = new T[0];
	this->_size = 0;
}

template<typename T>	
Array<T>::Array(unsigned int n) 
{
	this->_arr = new T[n];
	this->_size = n;
}

template<typename T>
Array<T>::Array(Array const& src) 
{
	this->_size = src._size;
	this->_arr = new T[this->_size];
	for (int i = 0; i < this->_size; i++)
	{
		this->_arr[i] = src._arr[i];
	}
}

template<typename T>
Array<T>& Array<T>::operator=(Array const& src)
{
	if (this != &src)
	{
		this->_size = src._size;			
		this->_arr = new T[this->_size];
		for (int i = 0; i < this->_size; i++)
		{
			this->_arr[i] = src._arr[i];
			}
	}
	return *this;
}

template<typename T>
T& Array<T>::operator[](int index)
{
	if (index >= this->_size || index < 0)
		throw std::exception();
	return this->_arr[index];
}

template<typename T>
const T& Array<T>::operator[](int index) const
{
	if (index >= this->_size || index < 0)
		throw std::exception();
	return this->_arr[index];
}

template<typename T>
Array<T>::~Array<T>(void)
{
	delete [] this->_arr;
}
#endif