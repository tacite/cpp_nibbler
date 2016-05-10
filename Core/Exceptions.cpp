//
// Exceptions.cpp for Exceptions in /home/sturbo_o/depot_git/cpp_nibbler
// 
// Made by Olivier STURBOIS
// Login   <sturbo_o@epitech.net>
// 
// Started on  Thu Apr  3 12:12:09 2014 Olivier STURBOIS
// Last update Fri Apr  4 21:43:14 2014 Olivier STURBOIS
//

#include	"Exceptions.hpp"

GameException::GameException(const std::string& msg) throw()
: _msg(msg) {
}

GameException::~GameException() throw() {
}

const char	*GameException::what() const throw() {
  return (this->_msg.c_str());
}

LibException::LibException(const std::string& msg) throw()
: _msg(msg) {
}

LibException::~LibException() throw() {
}

const char	*LibException::what() const throw() {
  return (this->_msg.c_str());
}
