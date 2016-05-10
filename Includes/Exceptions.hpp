//
// Exceptions.hpp for Exceptions in /home/sturbo_o/depot_git/cpp_nibbler
// 
// Made by Olivier STURBOIS
// Login   <sturbo_o@epitech.net>
// 
// Started on  Thu Apr  3 12:09:58 2014 Olivier STURBOIS
// Last update Thu Apr  3 15:47:56 2014 Olivier STURBOIS
//

#ifndef			__EXCEPTIONS__
# define		__EXCEPTIONS__

# include		<exception>
# include		<iostream>

class			GameException : public std::exception {
public:			/* CORE */
  GameException		(const std::string& msg) throw();
  virtual 		~GameException() throw();
  
public:			/* FUNCTIONS */
  virtual const char	*what() const throw();
  
private:		/* MEMBERS */
  std::string		_msg; 
};

class			LibException : public std::exception {
public:			/* CORE */
  LibException		(const std::string& msg) throw();
  virtual 		~LibException() throw();
  
public:			/* FUNCTIONS */
  virtual const char	*what() const throw();
  
private:		/* MEMBERS */
  std::string		_msg; 
};

#endif		/* __EXCEPTIONS__ */
