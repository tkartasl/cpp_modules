/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:18:38 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/13 13:22:43 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
# define CURE_H
# include "AMateria.hpp"

class Cure : virtual public AMateria
{
	public:
		Cure(void);
		Cure(const Cure& src);
		~Cure(void);
		Cure& operator=(const Cure& src);	

};

#endif