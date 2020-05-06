
#ifndef __NonLinearSystems__IterationSolver__
#define __NonLinearSystems__IterationSolver__

#include <stdio.h>
#include "NonLinearSolver.h"

template <unsigned int dim> class IterationSolver: public NonLinearSolver<dim>{
public:
    virtual IterationSolver& operator= (NonLinearSolver<dim> const&);
    virtual void Solve();

};

#endif