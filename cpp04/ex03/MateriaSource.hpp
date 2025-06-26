/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:59:36 by sekeskin          #+#    #+#             */
/*   Updated: 2025/01/14 20:09:15 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
	AMateria* _materias[4];

public:
	MateriaSource();
	MateriaSource(MateriaSource const &copy);
	~MateriaSource();
	
	MateriaSource &operator=(MateriaSource const &copy);

	void learnMateria(AMateria* m);
	AMateria* createMateria(std::string const & type);
};

#endif