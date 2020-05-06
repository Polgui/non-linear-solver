
#ifndef __NonLinearSystems__LinearSystemSolve__
#define __NonLinearSystems__LinearSystemSolve__

#include <stdio.h>
#include "Matrix.h"
#include "Variables.h"

template<unsigned int dim>
Variables<dim> SolveLinearSystem(Matrix<dim>, Variables<dim>);

#endif