#include <vector>

void tridiagonal_algorithm(
    const std::vector<double> &a, 
    const std::vector<double> &b, 
    const std::vector<double> &c, 
    const std::vector<double> &d, 
    std::vector<double> &result, 
    int n)
{
    std::vector<double> b_(n);
    std::vector<double> d_(n);
    b_[0] = b[0];
    d_[0] = d[0];
    for (int i = 1; i < n; i++)
    {
        b_[i] = b[i] - a[i] * c[i - 1]  / b_[i - 1];
        d_[i] = d[i] - a[i] * d_[i - 1] / b_[i - 1];
    }

    result[n - 1] = d_[n - 1] / b_[n - 1];
    for (int i = n - 2; i >= 0; i--)
        result[i] = (d_[i] - c[i] * result[i + 1]) / b_[i];
}


void tridiagonal_algorithm_mutable(
    std::vector<double> &a, 
    std::vector<double> &b, 
    std::vector<double> &c, 
    std::vector<double> &d, 
    std::vector<double> &result, 
    int n)
{
    for (int i = 1; i < n; i++)
    {
        b[i] -= a[i] * c[i - 1] / b[i - 1];
        d[i] -= a[i] * d[i - 1] / b[i - 1];
    }
    result[n - 1] = d[n - 1] / b[n - 1];
    for (int i = n - 2; i >= 0; i--)
        result[i] = (d[i] - c[i] * result[i + 1] ) / b[i];
}