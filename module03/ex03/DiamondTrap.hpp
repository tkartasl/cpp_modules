/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:26:07 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/27 15:58:34 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap(void);
	DiamondTrap(const std::string& name);
	DiamondTrap(DiamondTrap const& src);
	DiamondTrap& operator=(DiamondTrap const& src);
	~DiamondTrap(void);

	using ScavTrap::attack;
	void	whoAmI(void);
private:
	std::string _name;
};

#endif