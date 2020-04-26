#include <iostream>
#include <string>
#include <fstream>
#include "SunWhysEngine.h"

void loader() {
    SunWhysEngine sunWhysEngine;

    std::ifstream file("./loader.tf");

    if (file.is_open()) {
        std::string line;

        while (std::getline(file, line)) {
            std::cout << "Loading the " << line << " file" << std::endl;
            sunWhysEngine.m_addFile(line);
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
