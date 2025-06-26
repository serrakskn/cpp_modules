/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:41:50 by sekeskin          #+#    #+#             */
/*   Updated: 2024/12/23 20:38:50 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

bool replaceContent(const std::string& filename, const std::string& s1, const std::string& s2) {
    std::ifstream infile(filename.c_str());
    if (!infile.is_open()) {
        std::cerr << "Hata: Giriş dosyası açılamadı: " << filename << std::endl;
        return false;
    }

    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile.is_open()) {
        std::cerr << "Hata: Çıkış dosyası oluşturulamadı." << std::endl;
        return false;
    }

    std::string line;
	while (std::getline(infile, line)) {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
            pos += s2.length();
        }
        outfile << line << '\n';
    }

    infile.close();
    outfile.close();
	return true;
}

int main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << "Wrong number of parameter." << std::endl;
		return 1;
	}
	
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	if (filename.empty()) {
		std::cerr << "File is empty." << std::endl;
		return 1;
	}
	
	if (replaceContent(filename, s1, s2)) {
		std::cout << "Raplacement is complated." << std::endl;	
		return 0;
	}
	return 1;
}
