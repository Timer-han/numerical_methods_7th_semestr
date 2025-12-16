#include <vector>
#include <string>

class matrix
{
private:
    std::vector<double> m;
    std::vector<double> f;
    size_t n;
    size_t nn;
public:
    matrix (int size);
    matrix (int size, double a);
    ~matrix () = default;

    inline std::vector<double> get_m ()                        {return m;}
    inline std::vector<double> get_f ()                        {return f;}
    inline       double& operator() (size_t i, size_t j)       {return m[i * n + j];}
    inline const double& operator() (size_t i, size_t j) const {return m[i * n + j];}
    inline       double& operator() (size_t i)                 {return f[i];}
    inline const double& operator() (size_t i)           const {return f[i];}
    inline size_t size  ()                                     {return m.size ();}
    inline size_t get_n ()                                     {return n;}

    int read_from_file (std::string fname);
    int inicialize ();

    int print ();
    int print_m ();
    int print_f ();


    int tridiagonal_alg ();
};