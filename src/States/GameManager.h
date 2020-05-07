#ifndef SUNWHYSENGINE_GAMEMANAGER_H
#define SUNWHYSENGINE_GAMEMANAGER_H

#include <chrono>
#include <memory>
#include <vector>
#include <sol/function.hpp>
#include "State.h"

class GameManager {
private:
    std::vector<State> states;
    std::string m_currentState;
public:
    GameManager();
    void goToScene(std::string title);
    void render();
    void update();
    void pushState(const State& state);
    void close();

private:
    std::chrono::high_resolution_clock::time_point lastUpdateTime;
};


#endif //SUNWHYSENGINE_GAMEMANAGER_H
