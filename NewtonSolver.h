

#ifndef __NonLinearSystems__NewtonSolver__
#define __NonLinearSystems__NewtonSolver__

#include <stdio.h>
#include "NonLinearSolver.h"

template<unsigned int dim>
class NewtonSolver: public NonLinearSolver<dim>{
public:
    void Solve();
    virtual NewtonSolver& operator= (NonLinearSolver<dim> const&);


};

#endif