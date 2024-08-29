/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:22:39 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/29 16:07:21 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H
# include <iostream>

class ClapTrap
{
public:
	ClapTrap(void);
	ClapTrap(const std::string& name);
	ClapTrap(ClapTrap const &src);
	~ClapTrap(void);
	ClapTrap & operator=(ClapTrap const &src);
	
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	
protected:
	std::string _name;
	int			_hitPoints;
	int			_attackDamage;
	int			_energyPoints;
};

#endif