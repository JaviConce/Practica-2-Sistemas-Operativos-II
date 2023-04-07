#include <iostream>
#include <thread>
#include <fstream>
#include <iostream>
#include <fstream>

std::fstream openFileRead(std::string file_path) {
    std::fstream file;
    file.open(file_path, std::ios::in);
    

    if (!file) {
        std::cout << "Error opening file" << std::endl;
        file.close();
    }

    return file;
}

//Cuenta líneas
int countLines(std::fstream& file) {
    int count = 0;
    std::string line;
    while (std::getline(file, line)) {
        count++;
    }
    return count;
}

int main(int argc, char *argv[])
{
    int lines;

    if (argc != 4)
    {
        std::cerr << "Use: /program file_name word thread_number\n";
        return EXIT_FAILURE;
    }

    std::fstream file = openFileRead(argv[1]);
    if (!file)
        return EXIT_FAILURE;

    lines = countLines(file);
    std::cerr << lines;




}


