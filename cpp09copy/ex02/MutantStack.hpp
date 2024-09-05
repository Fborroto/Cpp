/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:41:24 by fborroto          #+#    #+#             */
/*   Updated: 2024/08/31 07:54:00 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T> class MutantStack : public std::stack<T>
{
  private:
  public:
	MutantStack() : std::stack<T>(){};
	~MutantStack(){};
	MutantStack(const MutantStack &src) : std::stack<T>(src){};
	MutantStack &operator=(const MutantStack &src)
	{
		if (this != &src)
			std::stack<T>::operator=(src);
		return (*this);
	};
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin(void)
	{
		return (this->c.begin());
	}
	iterator end(void)
	{
		return (this->c.end());
	}
};

#endif