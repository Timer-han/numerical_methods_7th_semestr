#include <iostream>
#include <vector>
#include <string>

#include "matrix.h"

int main (int argc, char** argv) {
    int n;
    if (argc != 3)
    {
        std::cout << "Wrong arguments!\n";
        return -1;
    }

    sscanf(argv[1], "%d", &n);
    std::string fname(argv[2]);

    matrix m(n);
    m.read_from_file(fname);
    m.print();
    
    return 0;
}

