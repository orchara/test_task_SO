#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>


typedef struct PB{
    std::string name;
    std::string surname;
    std::string p_number;

    std::string to_string(std::string order_by){
        if(order_by == "surname"){
            return surname + " " + name + ": " + p_number;
        }
        if(order_by == "phone"){
            return p_number + ": " + name + " " + surname;
        }
        if(order_by == "name"){
            return name + " " + surname + ": " + p_number;
        }
        return surname + " " + name + ": " + p_number;
        
    }
} PB;


std::function<bool (PB, PB)> compare(std::string sort_by){    
    if(sort_by == "surname"){
        return [](PB a, PB b){return a.surname < b.surname;};
    }
    if(sort_by == "phone"){
        return [](PB a, PB b){return a.p_number < b.p_number;};
    }
    if(sort_by == "name"){
        return [](PB a, PB b){return a.name < b.name;};
    }
    return nullptr;
}

void print_help(){
    std::cout << "Usage:\nreader <path> [sort_option]\n\n";
    std::cout << "path - file path to the file to be read\n";
    std::cout << "sort options:\n";
    std::cout << "name - sort by name\n";
    std::cout << "surname - sort by surname\n";
    std::cout << "phone - sort by phone number\n";
}

int main(int argc, char* argv[]){
    if(argc < 2 || argc > 3){        
        print_help();
        exit(1);
    }
    std::string path = argv[1];
    std::string sort_by = "def";
    std::fstream fs;
    std::vector<PB> lst;
    
    if(argc == 3){
        sort_by = argv[2];
        if(sort_by != "name" && sort_by != "surname" && sort_by != "phone"){
            std::cerr << "not valid sort_option\n\n";
            print_help();
            exit(1);
        }
        
    }    
    fs.open(path);
    if(!fs){
    	std::cerr << "file not found\nget valid file path\n";
        exit(1);
    }    
    while(!fs.eof()){
    	std::string name, surname, phone;
    	fs >> surname >> name >> phone;
        name.pop_back();
    	lst.push_back({name, surname, phone});
    }
    if(sort_by != "def"){
        std::sort(lst.begin(), lst.end(), compare(sort_by));
    }
    for(auto x : lst){
    	std::cout << x.to_string(sort_by) << std::endl;
    }
    return 0;
}