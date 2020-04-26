#include "SunWhysEngine.h"
#include <iostream>
#include "States/GameManager.h"
#include "Behaviors/Behavior.h"

SunWhysEngine::SunWhysEngine() {
    m_loadLibraries();
    std::cout << "Load Lua" << std::endl;

    m_windowsBinding();
    std::cout << "Load Window" << std::endl;

    m_eventBinding();
    std::cout << "Load Event" << std::endl;

    m_colorBinding();
    std::cout << "Load Color" << std::endl;

    m_loadGameManager();
    std::cout << "Load GameManager" << std::endl;

    m_loadState();
    std::cout << "Load State" << std::endl;

    m_keyboardBinding();
    std::cout << "Load Keyboard" << std::endl;

    m_loadBehavior();
    std::cout << "Load Behaviors" << std::endl;
}

void SunWhysEngine::m_addFile(const std::string& filename) { lua.script_file("./scripts/" + filename); }

void SunWhysEngine::m_loadLibraries() { lua.open_libraries(sol::lib::base, sol::lib::package, sol::lib::math, sol::lib::table); }

void SunWhysEngine::m_windowsBinding() {
    lua.new_usertype<sf::VideoMode>("VideoMode", sol::constructors<sf::VideoMode(float, float)>());

    lua.new_usertype<sf::RenderWindow>("Window", sol::constructors<sf::RenderWindow(sf::VideoMode, std::string)>(),
            "open", &sf::RenderWindow::isOpen,
            "display", &sf::RenderWindow::display,
            "close", &sf::RenderWindow::close,
            "clear", &sf::RenderWindow::clear,
            "event", &sf::RenderWindow::pollEvent);
}

void SunWhysEngine::m_eventBinding() {
    auto event = lua.new_usertype<sf::Event>("Event", sol::constructors<sf::Event>());

    event.set("type", sol::readonly(&sf::Event::type));
    event.set("key", sol::readonly(&sf::Event::key));

    lua["EventType"] = lua.create_table_with("Close", sf::Event::Closed, "KeyPressed", sf::Event::KeyPressed, "KeyReleased", sf::Event::KeyReleased);

    auto classKeyEvent = lua.new_usertype<sf::Event::KeyEvent>("KeyEvent", sol::constructors<sf::Event::KeyEvent>());
    classKeyEvent.set("code", &sf::Event::KeyEvent::code);
}

void SunWhysEngine::m_colorBinding() {
    lua.new_enum("Color",
            "Black", sf::Color::Black,
            "White", sf::Color::White,
            "Red", sf::Color::Red,
            "Green", sf::Color::Green,
            "Blue", sf::Color::Blue,
            "Yellow", sf::Color::Yellow,
            "Magenta", sf::Color::Magenta,
            "Cyan", sf::Color::Cyan,
            "Transparent", sf::Color::Transparent
    );
}

void SunWhysEngine::m_loadGameManager() {
    lua.new_usertype<GameManager>("GameManager", sol::constructors<GameManager>(),
            "push", &GameManager::pushState,
            "close", &GameManager::close,
            "goToScene", &GameManager::goToScene,
            "render", &GameManager::render,
            "update", &GameManager::update);
}

void SunWhysEngine::m_loadState() { lua.new_usertype<State>("State", sol::constructors<State(std::string&, sol::function&, sol::function&, sol::function&)>()); }

void SunWhysEngine::m_keyboardBinding() {

    lua.new_enum("Keyboard",
                 "A", sf::Keyboard::Key::A,
                 "B", sf::Keyboard::Key::B,
                 "C", sf::Keyboard::Key::C,
                 "D", sf::Keyboard::Key::D,
                 "E", sf::Keyboard::Key::E,
                 "F", sf::Keyboard::Key::F,
                 "G", sf::Keyboard::Key::G,
                 "H", sf::Keyboard::Key::H,
                 "I", sf::Keyboard::Key::I,
                 "J", sf::Keyboard::Key::J,
                 "K", sf::Keyboard::Key::K,
                 "L", sf::Keyboard::Key::L,
                 "M", sf::Keyboard::Key::M,
                 "N", sf::Keyboard::Key::N,
                 "O", sf::Keyboard::Key::O,
                 "P", sf::Keyboard::Key::P,
                 "Q", sf::Keyboard::Key::Q,
                 "R", sf::Keyboard::Key::R,
                 "S", sf::Keyboard::Key::S,
                 "T", sf::Keyboard::Key::T,
                 "U", sf::Keyboard::Key::U,
                 "V", sf::Keyboard::Key::V,
                 "W", sf::Keyboard::Key::W,
                 "X", sf::Keyboard::Key::X,
                 "Y", sf::Keyboard::Key::Y,
                 "Z", sf::Keyboard::Key::Z,
                 "Num0", sf::Keyboard::Key::Num0,
                 "Num1", sf::Keyboard::Key::Num1,
                 "Num2", sf::Keyboard::Key::Num2,
                 "Num3", sf::Keyboard::Key::Num3,
                 "Num4", sf::Keyboard::Key::Num4,
                 "Num5", sf::Keyboard::Key::Num5,
                 "Num6", sf::Keyboard::Key::Num6,
                 "Num7", sf::Keyboard::Key::Num7,
                 "Num8", sf::Keyboard::Key::Num8,
                 "Num9", sf::Keyboard::Key::Num9,
                 "Escape", sf::Keyboard::Key::Escape,
                 "LControl", sf::Keyboard::Key::LControl,
                 "LShift", sf::Keyboard::Key::LShift,
                 "LAlt", sf::Keyboard::Key::LAlt,
                 "LSystem", sf::Keyboard::Key::LSystem,
                 "RControl", sf::Keyboard::Key::RControl,
                 "RShift", sf::Keyboard::Key::RShift,
                 "RAlt", sf::Keyboard::Key::RAlt,
                 "RSystem", sf::Keyboard::Key::RSystem,
                 "Menu", sf::Keyboard::Key::Menu,
                 "LBracket", sf::Keyboard::Key::LBracket,
                 "RBracket", sf::Keyboard::Key::RBracket,
                 "Semicolon", sf::Keyboard::Key::Semicolon,
                 "Comma", sf::Keyboard::Key::Comma,
                 "Period", sf::Keyboard::Key::Period,
                 "Quote", sf::Keyboard::Key::Quote,
                 "Slash", sf::Keyboard::Key::Slash,
                 "Backslash", sf::Keyboard::Key::Backslash,
                 "Tilde", sf::Keyboard::Key::Tilde,
                 "Equal", sf::Keyboard::Key::Equal,
                 "Hyphen", sf::Keyboard::Key::Hyphen,
                 "Space", sf::Keyboard::Key::Space,
                 "Enter", sf::Keyboard::Key::Enter,
                 "Backspace", sf::Keyboard::Key::Backspace,
                 "Tab", sf::Keyboard::Key::Tab,
                 "PageUp", sf::Keyboard::Key::PageUp,
                 "PageDown", sf::Keyboard::Key::PageDown,
                 "End", sf::Keyboard::Key::End,
                 "Home", sf::Keyboard::Key::Home,
                 "Insert", sf::Keyboard::Key::Insert,
                 "Delete", sf::Keyboard::Key::Delete,
                 "Add", sf::Keyboard::Key::Add,
                 "Subtract", sf::Keyboard::Key::Subtract,
                 "Multiply", sf::Keyboard::Key::Multiply,
                 "Divide", sf::Keyboard::Key::Divide,
                 "Left", sf::Keyboard::Key::Left,
                 "Right", sf::Keyboard::Key::Right,
                 "Up",   sf::Keyboard::Key::Up,
                 "Down", sf::Keyboard::Key::Down,
                 "Numpad0", sf::Keyboard::Key::Numpad0,
                 "Numpad1", sf::Keyboard::Key::Numpad1,
                 "Numpad2", sf::Keyboard::Key::Numpad2,
                 "Numpad3", sf::Keyboard::Key::Numpad3,
                 "Numpad4", sf::Keyboard::Key::Numpad4,
                 "Numpad5", sf::Keyboard::Key::Numpad5,
                 "Numpad6", sf::Keyboard::Key::Numpad6,
                 "Numpad7", sf::Keyboard::Key::Numpad7,
                 "Numpad8", sf::Keyboard::Key::Numpad8,
                 "Numpad9", sf::Keyboard::Key::Numpad9,
                 "F1",    sf::Keyboard::Key::F1,
                 "F2",    sf::Keyboard::Key::F2,
                 "F3",    sf::Keyboard::Key::F3,
                 "F4",    sf::Keyboard::Key::F4,
                 "F5",    sf::Keyboard::Key::F5,
                 "F6",    sf::Keyboard::Key::F6,
                 "F7",    sf::Keyboard::Key::F7,
                 "F8",    sf::Keyboard::Key::F8,
                 "F9",    sf::Keyboard::Key::F9,
                 "F10",   sf::Keyboard::Key::F10,
                 "F11",   sf::Keyboard::Key::F11,
                 "F12",   sf::Keyboard::Key::F12,
                 "F13",   sf::Keyboard::Key::F13,
                 "F14",   sf::Keyboard::Key::F14,
                 "F15",   sf::Keyboard::Key::F15,
                 "Pause", sf::Keyboard::Key::Pause);
}

void SunWhysEngine::m_loadBehavior() {
    auto behavior = lua.new_usertype<Behavior>("Behavior", sol::constructors<Behavior(sf::RenderWindow, std::string, float, float)>(),
                               "draw", &Behavior::draw);

    behavior.set("x", &Behavior::m_x);
    behavior.set("y", &Behavior::m_y);

    lua.new_usertype<sf::Sprite>("Sprite", sol::constructors<sf::Sprite>());
}

