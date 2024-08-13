/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:07:02 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/13 13:22:47 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H
# include "AMateria.hpp"

class Ice : virtual public AMateria
{
	public:
		Ice(void);
		Ice(const Ice& src);
		~Ice(void);
		Ice& operator=(const Ice& src);	

};

#endif