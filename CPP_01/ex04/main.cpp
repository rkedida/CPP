/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:57:04 by rkedida           #+#    #+#             */
/*   Updated: 2023/01/15 15:28:46 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int errorHandling(std::string file, std::string s1, std::string s2)
{
	if (file.empty() || s1.empty() || s2.empty())
	{
		std::cout << "Error: Empty string." << std::endl;
		return (1);
	}
	return (0);
}

void replaceString(std::string &newFile, std::string& s1, std::string& s2)
{
	std::size_t pos = 0;

	while ((pos = newFile.find(s1, pos)) != std::string::npos)
	{
		newFile.erase(pos, s1.length());
		newFile.insert(pos, s2);
		pos += s2.length();
	}
}

void openFile(std::string fileName, std::string s1, std::string s2)
{
	std::fstream	file;
	std::fstream	newFile;
	std::string 	line;
	
	file.open(fileName, std::fstream::in);
	if (file.is_open())
	{
		newFile.open(fileName + ".replace", std::fstream::out);
		while (getline(file, line))
		{
			while (line.find(s1) != std::string::npos)
				replaceString(line, s1, s2);
			newFile << line << std::endl;
		}
		file.close();
		newFile.close();
	}
}

int main(int ac, char **av)
{
	if (ac == 4)
	{
		if (errorHandling(av[1], av[2], av[3]) == 1)
			return (-1);
		openFile(av[1], av[2], av[3]);
		
	}
	else
		std::cout << "Usage: ./replace [filename] [s1] [s2]" << std::endl;
	return (0);
}
