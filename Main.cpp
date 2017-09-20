#include <iostream>
#include <fstream>
#include "JobShop.h"

/* TODO
- Check break at end of algorithm
- Short check at algorithm
- Parse file with tabs
- Return task by reference GetFirstUnscheduledTask()
- Delete PrintAllConfigData()
- Doxygen and comments
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
