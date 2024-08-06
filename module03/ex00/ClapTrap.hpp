/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:22:39 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/06 15:10:44 by tkartasl         ###   ########.fr       */
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
	
	std::string		getName(void) const;
	int				getHitPoints(void) const;
	int				getAttackDamage(void) const;
	int				getEnergyPoints(void) const;
	void			setName(std::string newName);
	void			setHitPoints(int value);
	void			setAttackDamage(int value);
	void			setEnergyPoints(int value);
	
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	
private:
	std::string _name;
	int			_hitPoints;
	int			_attackDamage;
	int			_energyPoints;
};

#endif