// changeVolume - Linux system specific version
// 100% WORKING, Tested on Linux Mint 6.8.0-58-generic (Ubuntu sub-system)
// Complie via: g++ linux.cpp -o DESIRED_NAME
// Run via: ./DESIRED_NAME

#include <iostream>
#include <cstdlib>

int main() 
{
    while (true)
    {
        int volume;

        std::cout << "changeVolume - Linux Version \n";
        std::cout << "Change Volume from 0 to 100:";
        std::cin >> volume;
        std::cout << "\n";

        std::string command = "amixer set Master " + std::to_string(volume) + "%";
        system(command.c_str());
    }
    return 0;
}