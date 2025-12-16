#pragma once

#include <vector>

void tridiagonal_algorithm(
    const std::vector<double> &a, 
    const std::vector<double> &b, 
    const std::vector<double> &c, 
    const std::vector<double> &d, 
    std::vector<double> &result, 
    int n);


void tridiagonal_algorithm_mutable(
    std::vector<double> &a, 
    std::vector<double> &b, 
    std::vector<double> &c, 
    std::vector<double> &d, 
    std::vector<double> &result, 
    int n); 