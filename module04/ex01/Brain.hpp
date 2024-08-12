/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:19:17 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/12 15:33:57 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H
# include <iostream>

class Brain
{
public:
	Brain(void);
	Brain(Brain const& src);
	virtual ~Brain(void);
	Brain& operator=(Brain const& src);
	void setIdeas(const std::string);
	std::string* getIdeas(void);
private:
	std::string _ideas[100];
};

#endif