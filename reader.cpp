#include <iostream>
#include <fstream>
#include <vector>

enum class sort_order{
    NAME = 1,
    SURNAME = 2,
    P_NUMBER = 3
};

typedef class PB{
    std::string name;
    std::string surname;
    std::string p_number;    
} PB;

int main(int argc, char* argv[]){
    if(argc < 2 || argc > 3){
        std::cout << "Usage:\nreader <path> <sort_option>\n\n";
        std::cout << "path - absolute file path to the file to be read\n";
        std::cout << "sort options:\n";
        std::cout << "1 / name - sort by name:\n";
        std::cout << "2 / surename - sort by surname:\n";
        std::cout << "3 / phone - sort by phone number:\n";
        return 0;
    }
    
    
}