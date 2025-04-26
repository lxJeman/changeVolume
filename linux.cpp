// changeVolume - Linux system specific version
// 100% WORKING, Tested on Linux Mint 6.8.0-58-generic (Ubuntu sub-system)
// Compliation via: g++ linux.cpp -o DESIRED_NAME
// Run via: ./DESIRED_NAME

#include <iostream>
#include <cstdlib>

int main() 
{
    while (true)
    {
        int volume;

        std::cout << "changeVolume - Linux Verision \n";
        std::cout << "Change Volume from 0 to 100 \n";
        std::cin >> volume;

        std::string command = "amixer set Master " + std::to_string(volume) + "%";
        system(command.c_str());
    }
}