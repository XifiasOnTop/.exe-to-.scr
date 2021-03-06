//c++ 17

#include <iostream>
#include <string>
#include <filesystem>
#ifdef __cplusplus__
  #include <cstdlib>
#else
  #include <stdlib.h>
#endif

namespace fs = std::filesystem;

std::string file_path = "./";
std::string file_name;
std::string new_file_name;
bool rename_self = false; //if false does not rename itself to exe2scr.scr
std::string arg;

inline bool ends_with(std::string const & value, std::string const & ending) { //function to check if file ends with for example .exe
    if (ending.size() > value.size()) return false;
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}
using namespace std;
int main(int argc, char** argv) {
    
    cout << "Enter Path: " << std::endl; //Ask for file path
    cin >> file_path;

    string renameself;
    cout << "Rename Self? (y/n)" << std::endl; //Ask if user wants to rename the file itself
    cin >> renameself;
    if(renameself == "y") {
        rename_self = true;
    }
    string reverse;
    cout << "Do you want to rename all exe's to scr's \ny=I want to rename all exe's to scr's \nn=I want to rename all scr's to exe's\na=abort" << std::endl;
    cin >> reverse;

    if(reverse == "y") {
        std::cout <<"Searching "+file_path+"..."<< std::endl;

        for (auto & file : fs::directory_iterator(file_path)) { //scan directory

            file_name = file.path().string();

            if (ends_with(file_name, "exe") == true) { //check if exe

                if (file_name != "./exe2scr.exe" || (file_name == "./exe2scr.exe" && rename_self == true)) { //if rename self is turned off doesn't rename itself

                    new_file_name=file_name.substr(0,file_name.find_last_of('.'))+".scr"; 
                
                    try { //try to rename file
                         fs::rename(file_name, new_file_name);
                        std::cout <<"renamed "+file_name+" to "+new_file_name << std::endl;
                    } catch (...) {
                        std::cout <<"could not rename "+file_name+" to "+new_file_name+" Maybe you dont have permissions to access the folder or you didn't run the program as admin?"<< std::endl;
                        system("PAUSE");  
                    }
                }
            }
        }
        

    }
    if(reverse == "n") {
        std::cout <<"Searching "+file_path+"..."<< std::endl;

        for (auto & file : fs::directory_iterator(file_path)) { //scan directory

            file_name = file.path().string();

            if (ends_with(file_name, "scr") == true) { //check if scr

                if (file_name != "./exe2scr.exe" || (file_name == "./exe2scr.exe" && rename_self == true)) { //if rename self is turned off doesn't rename itself

                    new_file_name=file_name.substr(0,file_name.find_last_of('.'))+".exe"; 
                
                    try { //try to rename file
                         fs::rename(file_name, new_file_name);
                        std::cout <<"renamed "+file_name+" to "+new_file_name << std::endl;
                    } catch (...) {
                        std::cout <<"could not rename "+file_name+" to "+new_file_name+" Maybe you dont have permissions to access the folder or you didn't run the program as admin?"<< std::endl;
                        system("PAUSE");
                    }
                }
            }
        }

    }
}