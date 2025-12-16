#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include "matrix_compute.h"

int print_mtrx(std::vector<double> &v)
{
    for (int i = 0; i < v.size (); i++)
        printf ("%8.2e ", v[i]);
    printf("\n");
    return 0;
}

double find_norm (std::vector<double> &v)
{
    double mx = 0;
    for (int i = 0; i < v.size (); i++)
        mx = std::max(mx, std::abs(v[i]));
    return mx;
}

int find_sub(std::vector<double> &v, std::vector<double> &g)
{
    if (v.size () != g.size ())
    {
        std::cout << "Error in find_sub";
        return -1;
    }

    for (int i = 0; i < v.size (); i++)
        v[i] -= g[i];

    return 0;
}

int get_given_g (std::vector<double> &g, double t){
    int m = g.size();
    double h = 1. / (m-1);

    for (int i = 0; i < m; i++)
        g[i] = std::log(std::exp(t) * (std::cos(3 * M_PI * i * h) + 1.5));

    return 0;
}

int get_given_v (std::vector<double> &v, double t){
    int m = v.size();
    double h = 1. / (m-1);

    for (int i = 0; i < m; i++)
        v[i] = std::cos(2 * M_PI * t) * std::sin(4 * M_PI * h * i);

    return 0;
}

int main(int argc, char **argv)
{
    int m, tN;
    double h, t;
    
    
    for (m = 10; m < 100001; m*=10)
    {
        h = 1. / (m - 1);
        for (tN = 10; tN < 100001; tN*= 10)
        {
            std::vector<double>
                g(m, 0), v(m, 0), given_g(m, 0), given_v(m, 0),
                a(m, 0), b(m, 0),
                c(m, 0), d(m, 0);
            
            t = 1. / tN;
            find_for_tN(t, h, tN, m, g, v, a, b, c, d);

            get_given_g (given_g, 1);
            get_given_v (given_v, 1);

            find_sub (given_v, v);
            find_sub (given_g, g);

            auto norm_g = find_norm(given_g);
            auto norm_v = find_norm(given_v);

            printf("%6d %6d %8.2e %8.2e\n", m, tN, norm_g, norm_v);
        }
    }
    
    return 0;
}
