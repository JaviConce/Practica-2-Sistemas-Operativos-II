#include <iostream>
#include <thread>
#include <fstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


#include "../include/word.h"
#include "../include/myfiles.h"

int buscarPalabra(std::string ruta, std::string palabra, int linea_inicial, int linea_final);

std::vector<Word> word_found;
std::vector<std::thread> vhilos;
std::vector<std::pair<int, int>> resultados;

int main(int argc, char *argv[])
{
    int lines;

    if (argc != 4)
    {
        std::cerr << "Use: /program file_name word thread_number\n";
        return EXIT_FAILURE;
    }

    std::string word = argv[2];
    int num_threads = std::stoi(argv[3]);

    

    //int total_lines = countLines(file);
    //std::cerr << lines;

    // for (unsigned i = 0; i < num_threads; i++)
    // {

    // }

    buscarPalabra(argv[1], "david", 1, 10);

    for (auto resultado : resultados) {
        std::cout << "Palabra encontrada en la línea " << resultado.first << ", posición " << resultado.second << std::endl;
    }


}

// Función para buscar una palabra en un archivo.
int buscarPalabra(std::string ruta, std::string palabra, int linea_inicial, int linea_final) {

    std::fstream archivo = openFileRead(ruta);
    if (!archivo)
        return EXIT_FAILURE;
        
    std::string linea;
    int num_linea = 1;

    while (std::getline(archivo, linea)) {
        if (num_linea >= linea_inicial && num_linea <= linea_final) {
            // Convertir la línea a minúsculas
            std::transform(linea.begin(), linea.end(), linea.begin(), [](unsigned char c){ return std::tolower(c); });
            
            // Buscar la palabra en la línea
            size_t pos = 0;
            while ((pos = linea.find(palabra, pos)) != std::string::npos) {
                resultados.push_back(std::make_pair(num_linea, pos));
                pos += palabra.length();
            }
            
        }
        
        num_linea++;
        
    }
    
    // Cerrar el archivo y devolver los resultados
    archivo.close();
    return 1;

}
    
   


