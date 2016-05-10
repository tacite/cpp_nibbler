/*
** LibHandler.cpp for nibbler in /home/bajeux_m/Documents/Teck2/cpp/nibbler/cpp_nibbler/Core
**
** Made by Maxime Bajeux
** Login   <bajeux_m@epitech.net>
**
** Started on  sam. avril 05 02:42:20 2014 Maxime Bajeux
// Last update Sat Apr  5 16:42:15 2014 Olivier STURBOIS
*/


#include		"LibHandler.hpp"
#include		"Exceptions.hpp"

LibHandler::LibHandler	(const std::string &libName) 
: _libName(libName)
{
}

LibHandler::~LibHandler	() {
}