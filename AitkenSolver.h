

#ifndef __NonLinearSystems__AitkenSolver__
#define __NonLinearSystems__AitkenSolver__

#include <stdio.h>
#include "ScalarNonLinearSolver.h"

class AitkenSolver:public ScalarNonLinearSolver{
    
public:
    
    virtual AitkenSolver& operator= (ScalarNonLinearSolver const&);
    virtual AitkenSolver& operator= (NonLinearSolver const&);
    virtual void Solve();
    
};

#endif
