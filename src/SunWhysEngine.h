
#ifndef SUNWHYSENGINE_H
#define SUNWHYSENGINE_H

#include <sol/sol.hpp>
#include <SFML/Graphics.hpp>

class SunWhysEngine {
public:
    SunWhysEngine();
    void m_addFile(const std::string& filename);
private:
    sol::state lua;
    void m_loadLibraries();
    void m_windowsBinding();
    void m_eventBinding();
    void m_colorBinding();
    void m_loadGameManager();
    void m_loadState();
    void m_keyboardBinding();
    void m_loadBehavior();
};


#endif //SUNWHYSENGINE_H
