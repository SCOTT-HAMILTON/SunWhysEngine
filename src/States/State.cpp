#include "State.h"

State::State(const std::string& title, const sol::function& initialization, const sol::function& render, const sol::function& update) {
    this->title = title;
    this->initialization = initialization;
    this->update = update;
    this->render = render;
}
