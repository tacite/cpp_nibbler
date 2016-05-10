//
// Item.hpp for Item in /home/sturbo_o/depot_git/cpp_nibbler/Includes
// 
// Made by Olivier STURBOIS
// Login   <sturbo_o@epitech.net>
// 
// Started on  Thu Apr  3 15:47:09 2014 Olivier STURBOIS
// Last update Thu Apr  3 15:52:24 2014 Olivier STURBOIS
//

#ifndef				__ITEM__
# define			__ITEM__

# include			<string>

typedef enum			e_type
{
  HEAD,
  BACK,
  BODY,
  FOOD,
  NONE,
}				item_type;

class				Item
{ 
public:				/* CORE */
    Item(int x, int y, item_type type);
    ~Item();

public:				/* GETTERS */
    int				getX() const;
    int				getY() const;
    item_type			getType() const;

public:				/* SETTERS */
    void			setType(item_type type);

private:			/* MEMBERS */
  item_type			_type;
  const std::pair<int, int>	_pos;
};

#endif
