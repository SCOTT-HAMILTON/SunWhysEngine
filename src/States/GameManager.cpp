#include "GameManager.h"
#include <iostream>

GameManager::GameManager() : 
    lastUpdateTime(std::chrono::high_resolution_clock::now())

{}

std::vector<State> states;

void GameManager::pushState(const State& state) { states.push_back(state); }

void GameManager::goToScene(std::string title) {
    for (const auto& state : states)
        if (state.title == title) {
            state.initialization();
            m_currentState = std::move(title);
        }
}

void GameManager::render() {
    for (const auto& state : states)
        if (state.title == m_currentState)
            state.render();
}

void GameManager::update() {
    auto now = std::chrono::high_resolution_clock::now();
    float dt = (now-lastUpdateTime).count()/10'000'000.0;
    lastUpdateTime = now;


    for (const auto& state : states)
        if (state.title == m_currentState)
            state.update(dt);
}

void GameManager::close() {
    for (const auto& state : states)
        std::cout << "Close " << state.title << std::endl;
}
