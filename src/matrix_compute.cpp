#include <cmath>
#include <vector>

#include "tridiagonal_algorithm.h"

constexpr double mu = 0.1;

double get_f () {
    return 0;
}

double get_mu_tilde ( std::vector<double> &g, int n_nodes ) {
    double mx = std::exp(-g[0]);
    for (int i = 1; i < n_nodes; ++i)
        mx = std::max(std::exp(-g[i]), mx);
    return mu * mx;
}


double get_p (double gi) {
    return std::exp(0.4 * gi) * 1.4;
}

int get_g0 (
    double t, double h, int m,
    std::vector<double> &g,
    std::vector<double> &v,
    std::vector<double> &a,
    std::vector<double> &b,
    std::vector<double> &c,
    std::vector<double> &d
) {
    b[0] = 4 * h / t - 2 * v[0];
    c[0] = 2 * v[1];
    d[0] = 4.0 * h / t * g[0]
           - 2.0 * g[0] * v[0] + 7.0 * g[0] * v[1] - 4.0 * g[0] * v[2] + 1.0 * g[0] * v[3]
           - 5.0 * g[1] * v[1] + 4.0 * g[2] * v[2] - 1.0 * g[3] * v[3]
           + 8.0 * v[0] - 14.0 * v[1] + 8.0 * v[2] - 2.0 * v[3];
    
    return 0;
}


int get_gM (
    double t, double h, int m,
    std::vector<double> &g,
    std::vector<double> &v,
    std::vector<double> &a,
    std::vector<double> &b,
    std::vector<double> &c,
    std::vector<double> &d
) {
    m -= 1;
    b[m] = 4 * h / t + 2 * v[m];
    a[m] = 2 * v[m-1];
    d[m] = 4.0*h/t * g[m]
           + 2.0*g[m]*v[m] - 7.0*g[m]*v[m-1] + 4.0*g[m]*v[m-2] - 1.0*g[m]*v[m-3]
           + 5.0*g[m-1]*v[m-1] - 4.0*g[m-2]*v[m-2] + 1.0*g[m-3]*v[m-3]
           - 8.0*v[m] + 14.0*v[m-1] - 8.0*v[m-2] + 2.0*v[m-3];
    return 0;
}

int get_g (
    double t, double h, int m,
    std::vector<double> &g,
    std::vector<double> &v,
    std::vector<double> &a,
    std::vector<double> &b,
    std::vector<double> &c,
    std::vector<double> &d
) {
    for (int i = 1; i < m - 1; i++)
    {
        a[i-1] = -v[i] - v[i-1];
        b[i] = 4 * h / t;
        c[i] = v[i] + v[i+1];
        d[i] = g[i] * (4 * h / t + v[i+1] - v[i-1]) - 2 * (v[i+1] - v[i-1]);
    }
    return 0;
}

int get_v (
    double t, double h, int m,
    std::vector<double> &g,
    std::vector<double> &v,
    std::vector<double> &a,
    std::vector<double> &b,
    std::vector<double> &c,
    std::vector<double> &d
) { 
    double muu = get_mu_tilde (g, m);
    for (int i = 1; i < m - 1; i++)
    {
        a[i] = -(v[i]+v[i-1]) / 6 - muu / h;
        c[i] =  (v[i] + v[i+1]) / 6 - muu / h;
        b[i] = h / t + 2 * muu / h;
        d[i] = h * v[i] / t - 
               get_p(g[i]) * (g[i + 1]- g[i - 1]) / 2 -
               (muu - mu * std::exp(-g[i])) * (v[i + 1] + v[i - 1] - 2 * v[i]) / h +
               get_f () * h;
    }
    b[0] = 1;
    b[m-1] = 1;
    d[0] = 0;
    d[m-1] = 0;
    return 0;
}

int find_g (
    double t, double h, int m,
    std::vector<double> &g,
    std::vector<double> &v,
    std::vector<double> &a,
    std::vector<double> &b,
    std::vector<double> &c,
    std::vector<double> &d
) {
    get_g0 (t, h, m, g, v, a, b, c, d);
    get_gM (t, h, m, g, v, a, b, c, d);
    get_g (t, h, m, g, v, a, b, c, d);

    tridiagonal_algorithm (a, b, c, d, g, m);
    return 0;
}


int find_v (
    double t, double h, int m,
    std::vector<double> &g,
    std::vector<double> &v,
    std::vector<double> &a,
    std::vector<double> &b,
    std::vector<double> &c,
    std::vector<double> &d
) {
    get_v (t, h, m, g, v, a, b, c, d);
    tridiagonal_algorithm (a, b, c, d, v, m);
    return 0;
}

int get_g_begin (
    double h, int m, std::vector<double> &g
) {
    for (int i = 0; i < m; i++) 
        g[i] = std::log(std::cos(3 * M_PI * (h * i)) + 1.5);
    
    return 0;
}

int get_u_begin (
    double h, int m, std::vector<double> &v
) {
    for (int i = 0; i < m; i++) 
        v[i] = std::sin(4 * M_PI * (h * i));
    
    return 0;
}

int find_for_tN (
    double t, double h, int tN, int m,
    std::vector<double> &g,
    std::vector<double> &v,
    std::vector<double> &a,
    std::vector<double> &b,
    std::vector<double> &c,
    std::vector<double> &d
) {
    get_g_begin (h, m, g);
    get_u_begin (h, m, v);
    for (int i = 1; i <= tN; i++)
    {
        find_g(t, h, m, g, v, a, b, c, d);
        find_v(t, h, m, g, v, a, b, c, d);
    }
    return 0;
}