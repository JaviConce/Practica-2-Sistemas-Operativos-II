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
int countLines(std::string path) {
    std::fstream file;
    file.open(path, std::ios::in);
    
    if (!file) {
        std::cout << "Error opening file" << std::endl;
        file.close();
    }

    int count = 0;
    std::string line;
    while (std::getline(file, line)) {
        count++;
    }
    return count;
}

//Devuelve la palabra adyacente la indicada en la posicion. La posicion de la palabra debe ser la primera letra que la compone
std::string getRelativeWord(std::string line, int pos, bool previous)
{
    bool end = false;
    bool first_white = false;
    bool last_white = false;

    int long_word = 0;

    if (pos < 0 || pos > line.size() || line.size() == 0)
    {
        std::cout << "Error en getRelativeWord, pos se sale de los limites o la línea está vacia\n";
        exit(1);
    }


    while (!end)
    {
        char charac = line[pos];
        //Acaba la palabra en la que estabamos
        if (charac == ' ') first_white = true;

        
        if (first_white)
            //Encuentra el inicio de la siguiente palabra
            if (charac != ' ' && std::isalpha(charac)){
                last_white = true;
                long_word++; //Empieza a contar el tamaño de la palabra
            } 

        
        if (last_white)
        {
            //Acaba la nueva palabra
            if (charac == ' ') end = true;
        }

        //Control de errores
        if (!previous && (pos-1) > 0)
            pos--;
        else if (previous && (pos+1) < line.size())
            pos++;
        else
            end = true;
        
    }

    if (!previous)
            return line.substr(pos + 2, long_word);
        else
            return line.substr(pos - long_word - 1, long_word);
    
}

//Devuelve el contenido de la linea indicada de un fichero
std::string getLineByPosition(std::string path, int position)
{
    //Comprobamos si el fichero se abre
    std::fstream inputFile = openFileRead(path);
    if (!inputFile)
        exit(1);

    std::string line;
    int currentPos = 1;
    while (std::getline(inputFile, line))
    {
        if (currentPos == position) // si se encuentra la posición buscada
        {
            return line; // devuelve la línea actual
        }

        currentPos++;
    }
    std::cout << "Line does not exist";
    return ""; // si no se encuentra la posición, devuelve una cadena vacía
}



#endif
