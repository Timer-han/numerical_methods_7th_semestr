#include <iostream>
#include <vector>

#include "matrix.h"

matrix::matrix (int size) {
    n = size;
    nn = n * n;
    m = std::vector<double>(nn, 0);
    f = std::vector<double>(n, 0);
}

matrix::matrix (int size, double a) {
    n = size;
    nn = n * n;
    m = std::vector<double>(nn, a);
    f = std::vector<double>(n, a);
}

int matrix::read_from_file (std::string fname) {
    auto *fin = fopen(fname.c_str(), "r");

    if (!fin)
    {
        std::cout << "Can't open file!\n";
        return -1;
    }
    auto &mtx = *this;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (fscanf(fin, "%lf", &mtx(i, j)) != 1)
            {
                std::cout << "Can't read the file!\n";
                return -2;
            }
        if (fscanf(fin, "%lf", &mtx(i)) != 1)
        {
            std::cout << "Can't read the file!\n";
            return -2;
        }
    }

    fclose(fin);
    return 0;
}

int matrix::print () {
    auto& mtx = *this;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%8.2e ", mtx(i, j));
        printf("%8.2e\n", mtx(i));
    }
    return 0;
}


int matrix::print_m () {
    auto& mtx = *this;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%8.2e ", mtx(i, j));
        printf("\n");
    }
    return 0;
}


int matrix::print_f () {
    auto& mtx = *this;
    for (int i = 0; i < n; i++)
        printf("%8.2e\n", mtx(i));
    return 0;
}