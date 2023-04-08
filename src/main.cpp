#include <iostream>
#include <thread>
#include <fstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

#include "../include/word.h"
#include "../include/myfiles.h"

void buscarPalabra(std::string ruta, std::string palabra, int linea_inicial, int linea_final);
std::string getRelativeWord(std::string line, int pos, bool previous);
std::string getLineByPosition(std::string path, int position);

std::vector<Word> words_found;
std::vector<std::thread> vhilos;
std::vector<std::pair<int, int>> resultados;
std::vector<std::pair<std::string, std::string>> last_previous;

int main(int argc, char *argv[])
{
    int lines;

    if (argc != 4)
    {
        std::cerr << "Use: /program file_name word thread_number\n";
        return EXIT_FAILURE;
    }

    std::string file_path = argv[1];
    std::string word = argv[2];
    int num_threads = std::stoi(argv[3]);

    //int total_lines = countLines(file);
    //std::cerr << lines;

    // for (unsigned i = 0; i < num_threads; i++)
    // {

    // }

    buscarPalabra(file_path, word, 1, 12);
    std::sort(words_found.begin(), words_found.end());


    for (auto word : words_found) {
         std::cout << word;
     }

    // for (auto resultado : resultados) {
    //     std::cout << "Palabra encontrada en la línea " << resultado.first << ", posición " << resultado.second << std::endl;
    // }

    // for (const auto& pair : last_previous) {
    // std::cout << "Primera: " << pair.first << " Segunda: " << pair.second << std::endl;
    // }

    // for (const auto& resultado : resultados) {
    // std::cout << "Linea " << std::get<0>(resultado) << ", posicion " << std::get<1>(resultado) 
    //           << ": palabra anterior '" << std::get<2>(resultado) << "', palabra posterior '" << std::get<3>(resultado) << "'" << std::endl;
    // }


}

// Función para buscar una palabra en un archivo.
void buscarPalabra(std::string ruta, std::string palabra, int linea_inicial, int linea_final) {

    //Convertir palabra a minuscula
    std::transform(palabra.begin(), palabra.end(), palabra.begin(), [](unsigned char c){ return std::tolower(c); });
    
    //Comprobamos si el fichero se abre
    std::fstream archivo = openFileRead(ruta);
    if (!archivo)
        exit(1);

    
    std::string linea;
    int num_linea = 1;

    while (std::getline(archivo, linea)) {
        if (num_linea >= linea_inicial && num_linea <= linea_final) {

            // Convertir la línea a minúsculas
            std::string line_lower = linea;
            std::transform(line_lower.begin(), line_lower.end(), line_lower.begin(), [](unsigned char c){ return std::tolower(c); });

            // Buscar la palabra en la línea
            int pos = 0;
            while ((pos = line_lower.find(palabra, pos)) != std::string::npos) {
                resultados.push_back(std::make_pair(num_linea, pos + 1));
                
                std::string previous = getRelativeWord(linea, pos, false);
                std::string last = getRelativeWord(linea, pos, true);

                //std::cout << "dedf" << num_linea + 1;
                //if (last == "") last = getRelativeWord(getLineByPosition(ruta, num_linea + 1), 0, true);
                
                pos += palabra.length();

                Word word(1,1,1, num_linea, previous, last, pos);
                words_found.emplace_back(word);
            }
            
        }
        
        num_linea++;
        
    }
    
    // Cerrar el archivo
    archivo.close();

}

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
        if (charac == ' ') first_white = true;

        //Encuentra el inicio de la siguiente palabra
        if (first_white)
            if (charac != ' ' && std::isalpha(charac)){
                last_white = true;
                long_word++;
            } 

        if (last_white)
        {
            if (charac == ' ') end = true;
        }

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



    
   


