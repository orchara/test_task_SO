#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

enum class sort_order{
    NAME = 1,
    SURNAME = 2,
    P_NUMBER = 3
};

typedef struct PB{
    std::string name;
    std::string surname;
    std::string p_number;
} PB;

bool by_name(PB a, PB b){
	return a.name < b.name;
}

bool by_surname(PB a, PB b){
	return a.surname < b.surname;
}

bool by_phone(PB a, PB b){
	return a.p_number < b.p_number;
}


int main(int argc, char* argv[]){
    if(argc < 2 || argc > 3){
        std::cout << "Usage:\nreader <path> <sort_option>\n\n";
        std::cout << "path - absolute file path to the file to be read\n";
        std::cout << "sort options:\n";
        std::cout << "1 / name - sort by name(default)\n";
        std::cout << "2 / surename - sort by surname\n";
        std::cout << "3 / phone - sort by phone number\n";
        return 0;
    }
    std::string path = argv[1];
    std::string sort_by = "name";
    std::fstream fs;
    std::vector<PB> lst;
    
    if(argc == 3){
    	sort_by = argv[2];
    }    
    fs.open(path);
    if(!fs){
    	std::cout << "file not found\nget valid file path\n";
    }    
    while(!fs.eof()){
    	std::string name, surname, phone;
    	fs >> surname >> name >> phone;
        name.pop_back();
    	lst.push_back({name, surname, phone});
    }
    std::sort(lst.begin(), lst.end(), by_phone);
    for(auto x : lst){
    	std::cout << x.name << " " << x.surname << ": " << x.p_number << std::endl;
    }
}