#include "State.h"

State::State(const std::string& title, const sol::function& initialization, const sol::function& render, const sol::function& update) {
    m_title = title;
    m_initialization = initialization;
    m_update = update;
    m_render = render;
}
