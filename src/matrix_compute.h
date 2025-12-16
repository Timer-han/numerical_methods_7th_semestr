#pragma once

#include <vector>

double get_f();
double get_mu(double t, double h, int m, std::vector<double> &g);
double get_p(double gi);

int get_g0(double t, double h, int m, std::vector<double> &g, std::vector<double> &v,
           std::vector<double> &a, std::vector<double> &b, std::vector<double> &c, std::vector<double> &d);
int get_gM(double t, double h, int m, std::vector<double> &g, std::vector<double> &v,
           std::vector<double> &a, std::vector<double> &b, std::vector<double> &c, std::vector<double> &d);
int get_g(double t, double h, int m, std::vector<double> &g, std::vector<double> &v,
          std::vector<double> &a, std::vector<double> &b, std::vector<double> &c, std::vector<double> &d);
int get_v(double t, double h, int m, std::vector<double> &g, std::vector<double> &v,
          std::vector<double> &a, std::vector<double> &b, std::vector<double> &c, std::vector<double> &d);

int find_g(double t, double h, int m, std::vector<double> &g, std::vector<double> &v,
           std::vector<double> &a, std::vector<double> &b, std::vector<double> &c, std::vector<double> &d);
int find_v(double t, double h, int m, std::vector<double> &g, std::vector<double> &v,
           std::vector<double> &a, std::vector<double> &b, std::vector<double> &c, std::vector<double> &d);

int get_g_begin(double h, int m, std::vector<double> g);
int get_u_begin(double h, int m, std::vector<double> v);

int find_for_tN(double t, double h, int tN, int m,
                std::vector<double> &g, std::vector<double> &v,
                std::vector<double> &a, std::vector<double> &b,
                std::vector<double> &c, std::vector<double> &d);