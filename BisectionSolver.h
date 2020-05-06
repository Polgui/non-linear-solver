

#ifndef __NonLinearSystems__BisectionSolver__
#define __NonLinearSystems__BisectionSolver__

#include <stdio.h>
#include "ScalarNonLinearSolver.h"

class BisectionSolver:public ScalarNonLinearSolver{

public:
    
    virtual BisectionSolver& operator= (ScalarNonLinearSolver const&);
    virtual BisectionSolver& operator= (NonLinearSolver const&);
    virtual void Solve();

};

#endif