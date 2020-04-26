#include "GameManager.h"
#include <iostream>

GameManager::GameManager() = default;

std::vector<State> states;

void GameManager::pushState(const State& state) { states.push_back(state); }

void GameManager::goToScene(std::string title) {
    for (const auto& state : states)
        if (state.m_title == title) {
            state.m_initialization();
            m_currentState = std::move(title);
        }
}

void GameManager::render() {
    for (const auto& state : states)
        if (state.m_title == m_currentState)
            state.m_render();
}

void GameManager::update() {
    for (const auto& state : states)
        if (state.m_title == m_currentState)
            state.m_update();
}

void GameManager::close() {
    for (const auto& state : states)
        std::cout << "Close " << state.m_title << std::endl;
}
