#ifndef SUNWHYSENGINE_STATE_H
#define SUNWHYSENGINE_STATE_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>
#include <sol/function.hpp>

class State {
public:
    State(const std::string& title, const sol::function& initialization, const sol::function& update, const sol::function &render);

    std::string m_title;
    sol::function m_initialization;
    sol::function m_update;
    sol::function m_render;
 };


#endif //SUNWHYSENGINE_STATE_H
