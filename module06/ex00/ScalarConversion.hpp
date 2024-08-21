/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:50:48 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/21 10:55:15 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERSION_H
# define SCALARCONVERSION_H
# include <string>

class ScalarConversion
{
	public:
		~ScalarConversion(void);
		ScalarConversion& operator=(ScalarConversion const& src);

		static void convert(std::string string);
	protected:
		ScalarConversion(void);
		ScalarConversion(ScalarConversion const& src);
};

#endif