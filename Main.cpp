#include <iostream>
#include <fstream>
#include "JobShop.h"

/* TODO
- Short check at algorithm
- Parse file with tabs
- =0 check
- Return task by reference GetFirstUnscheduledTask()
- Delete PrintAllConfigData()
*/

int main(int argc, char **argv)
{
    std::ifstream file(argv[1], std::ifstream::binary);
    if (file.fail())
    {
        std::cerr << "The file does not exist or no arguments are given!" << std::endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        const std::string config((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        JobShop mJobShop(config);
    }
    return 0;
}
