/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:42:09 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/12 16:09:30 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : virtual public Animal
{
public:
	Cat(void);
	Cat(Cat const& src);
	~Cat(void);
	Cat& operator=(Cat const& src);

	std::string* getCatIdeas(void);
	void	setCatIdeas(std::string cat_idea);
	void	makeSound(void) const;
private:
	Brain* _brainPTR;
};

#endif