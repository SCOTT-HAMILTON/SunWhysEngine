#ifndef SUNWHYSENGINE_LUAWRAPPERS_H
#define SUNWHYSENGINE_LUAWRAPPERS_H

#include <sol/state.hpp>


class LuaWrappers {
public:
    LuaWrappers();
    void addFile(const std::string& filename);
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
    void m_loadPhysics();
};


#endif //SUNWHYSENGINE_LUAWRAPPERS_H
