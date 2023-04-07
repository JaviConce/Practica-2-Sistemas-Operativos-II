#ifndef MYFILES_H
#define MYFILES_H

#include <iostream>
#include <thread>
#include <fstream>
#include <iostream>
#include <fstream>

//Devuele un objeto tipo td::fstream, que representa un archivo abierto en modo lectura (std::ios::in)
std::fstream openFileRead(std::string file_path) {
    std::fstream file;
    file.open(file_path, std::ios::in);
    

    if (!file) {
        std::cout << "Error opening file" << std::endl;
        file.close();
    }

    return file;
}

//Devuelve el numero de lineas de un archivo
int countLines(std::fstream& file) {
    int count = 0;
    std::string line;
    while (std::getline(file, line)) {
        count++;
    }
    return count;
}

#endif
