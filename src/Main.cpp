#include <iostream>
#include <string>
#include <fstream>
#include "Wrappers/LuaWrappers.h"
#include <string>
#include <sstream>
#include <vector>


void loader() {
    LuaWrappers luaWrappers;

    std::ifstream file("./loader.tf");
    int extension = -1;

    if (file.is_open()) {
        std::string line;

        while (std::getline(file, line)) {
            if (line == "lang=lua")
            {
                extension = 0;
                continue;
            }

            switch (extension) {
                case -1:
                    std::cout << "Extension not found" << std::endl;
                break;
                case 0:
                    std::cout << "Loading the " << line << " file" << std::endl;
                    luaWrappers.m_addFile(line);
                break;
            }
        }

        file.close();
    } else
        std::cout << "The loader file was not found." << std::endl;
}

int main() {
    loader();

    auto finish = 0;
    std::cin >> finish;

    return EXIT_SUCCESS;
}
