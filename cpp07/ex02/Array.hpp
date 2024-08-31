/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:41:24 by fborroto          #+#    #+#             */
/*   Updated: 2024/08/22 03:38:51 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <stdlib.h>     
#include <time.h>     

template <class T>
class Array
{
    private:
        T   *arrayValues;
        unsigned int arraySize;
        
    public:
        Array(): arrayValues(NULL), arraySize(0) {};
        Array(unsigned int n) : arrayValues(new T[n]), arraySize(n){};
        Array(const Array &src) : arrayValues(new T[src.arraySize]), arraySize(src.arraySize){
            for (unsigned int i = 0; i < arraySize; i++)
            {
                arrayValues[i] = src.arrayValues[i];
            }
        };
        
        ~Array(){
            delete [] arrayValues;
        };
        Array &operator=(const Array &src)
        {
            if(this != src)
            {
                delete [] arrayValues;
                arrayValues = new T(src.arraySize);
                arraySize = src.arraySize;
                for (size_t i = 0; i <  src.arraySize; i++)
                    arrayValues[i] = src.arrayValues[i];
            }
            return *this;
        }
        
        unsigned int size () const {return arraySize;};
        
        T& operator[](unsigned int index) const
        {
            if(index >= arraySize)
                throw OutOfRangeException();
            return  arrayValues[index];
        }
        
        class OutOfRangeException : public std::exception {
            public :
                virtual const char* what() const throw(){ return "index out of range";}
        };
    };

template <typename T>

std::ostream &operator<<(std::ostream &out, const Array<T> &array)
{
    for (size_t i = 0; i < array.arraySize; i++)
    {
        out << array[i] << " ";
    }
    return out;
    
}

#endif