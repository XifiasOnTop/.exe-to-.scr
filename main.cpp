//c++ 17

#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

std::string file_path = "./";
std::string file_name;
std::string new_file_name;
bool rename_self = false; //if false does not rename itself to exe2scr.scr
std::string arg;

inline bool ends_with(std::string const & value, std::string const & ending) {
    if (ending.size() > value.size()) return false;
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

int main(int argc, char** argv){

    for (int i = 0; i < argc; i++) {
        arg = argv[i];
        if (arg == "-rs") {
            rename_self = true;
        } else {
            file_path = arg;
        }
    }

    std::cout <<"Searching "+file_path+"..."<< std::endl;

    for (auto & file : fs::directory_iterator(file_path)) {

        file_name = file.path().string();

        if (ends_with(file_name, "exe") == true) {

            if (file_name != "./exe2scr.exe" || (file_name == "./exe2scr.exe" && rename_self == true)) {

                new_file_name=file_name.substr(0,file_name.find_last_of('.'))+".scr";
                
                try {
                    fs::rename(file_name, new_file_name);
                    std::cout <<"renamed "+file_name+" to "+new_file_name << std::endl;
                } catch (...) {
                    std::cout <<"could not rename "+file_name+" to "+new_file_name<< std::endl;
                }
            }
        }

    }
} 
