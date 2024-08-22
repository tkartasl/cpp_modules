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
		static void convert(std::string string);
	private:
		ScalarConversion(void);
		ScalarConversion(ScalarConversion const& src);
		~ScalarConversion(void);
		ScalarConversion& operator=(ScalarConversion const& src);
};

#endif