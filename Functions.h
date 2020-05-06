
#ifndef __NonLinearSystems__Functions__
#define __NonLinearSystems__Functions__

#include <stdio.h>
#include "Variables.h"
#include <array>

template <unsigned int dim> class Functions:public array<double (*)(Variables<dim>), dim>{
private:
    unsigned int N;
public:
    Functions();
    void Add(double (*)(Variables<dim>), unsigned int const&);
    unsigned int Size()const;
    Functions<dim>& operator=(array<double (*)(Variables<dim>), dim> const&);
    void Clear();
};

#endif 