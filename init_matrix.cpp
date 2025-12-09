#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int read_matrix_from_file(
    std::vector<double> &a, int n,
    std::string filename
)
{
    std::fstream file(filename);
    
    if (!file)
    {
        std::cout << "Can't open the file";
        return -1;
    }

    for (int i = 0; i < n * n; i++)
    {
        if (!(file >> a[i]))
        {
            std::cout << "Can't read the file";
            return -2;
        }
    }
}

int gen_matrix(std::vector<double> &a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            
        }
    }
}
