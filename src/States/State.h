#ifndef SUNWHYSENGINE_STATE_H
#define SUNWHYSENGINE_STATE_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>
#include <sol/function.hpp>

class State {
public:
  State(const std::string& title, const sol::function& initialization, const sol::function& update, const sol::function &render);

  std::string title;
  sol::function initialization;
  sol::function update;
  sol::function render;
 };


#endif //SUNWHYSENGINE_STATE_H
