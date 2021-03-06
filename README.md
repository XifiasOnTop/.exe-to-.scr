# .exe to .scr
made a program that renames every exe in a directory you specify into scr files :D

requires c++17 or higher

usage `exe2scr.exe <-rs if you want to enable rename self> <path to directory for example ./>`

example `exe2scr.exe -rs ./`

example `exe2scr.exe C:/Windows/System32` * *
* don't reccommend doing that
* must run cmd as administrator and have changed ownership of system32

# .scr to .exe
reverses actions made by .exe to .scr

requires c++17 or higher

usage `scr2exe.exe path to directory`

example `scr2exe.exe c:/Windows/System32` (if you renamed all exe files from system32 into scr files) *
* must run cmd as administrator and have changed ownership of system32
