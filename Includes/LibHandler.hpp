/*
** LibHandler.hpp for nibbler in /home/bajeux_m/Documents/Teck2/cpp/nibbler/cpp_nibbler/Includes
**
** Made by Maxime Bajeux
** Login   <bajeux_m@epitech.net>
**
** Started on  sam. avril 05 02:43:07 2014 Maxime Bajeux
// Last update Sat Apr  5 17:34:22 2014 Olivier STURBOIS
*/


#ifndef			LIB_HANDLER_H_
# define		LIB_HANDLER_H_

# include		<dlfcn.h>
# include		<list>
# include		<iostream>
# include		"Exceptions.hpp"
# include		"IGraph.hpp"


class			LibHandler
{
public:			/* CORE */
  LibHandler		(const std::string&);
  ~LibHandler		();

  template              <typename functype>
  functype              *getFunction(std::string const &funcName) const
  {
    functype            *func;
    void		*hdl;

    hdl = dlopen(this->_libName.c_str(), RTLD_LAZY);
    if (!hdl)
      throw LibException(dlerror());
    func = reinterpret_cast<functype*> (dlsym(hdl, funcName.c_str()));
    if (!func)
      throw LibException(dlerror());
    return func;
  }

private:
  const std::string	_libName;

};

#endif			/* LIB_HANDLER_H_ */
