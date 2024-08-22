/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:40:15 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/22 14:55:28 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

class Data
{
	public:
		Data(void);
		Data(Data const& src);
		~Data(void);
		Data& operator=(Data const& src);
		void print(void);
};

#endif