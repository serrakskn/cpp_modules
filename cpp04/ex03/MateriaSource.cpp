/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:19:15 by sekeskin          #+#    #+#             */
/*   Updated: 2025/01/17 18:00:58 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        _materias[i] = NULL;
    }
}

MateriaSource::MateriaSource(MateriaSource const &copy) {
    for (int i = 0; i < 4; ++i) {
        if (copy._materias[i])
            _materias[i] = copy._materias[i]->clone();
        else
            _materias[i] = NULL;
    }
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        if (_materias[i]) {
            delete _materias[i];
            _materias[i] = NULL;
        }
    }
}

MateriaSource &MateriaSource::operator=(MateriaSource const &copy) {
    if (this != &copy) {
        for (int i = 0; i < 4; ++i) {
            if (_materias[i]) {
                delete _materias[i];
            }
            if (copy._materias[i])
                _materias[i] = copy._materias[i]->clone();
            else
                _materias[i] = NULL;
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m)
        return;
    for (int i = 0; i < 4; ++i) {
        if (!_materias[i]) {
            _materias[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; ++i) {
        if (_materias[i] && _materias[i]->getType() == type) {
            return _materias[i]->clone();
        }
    }
    return NULL;
}
