

#ifndef __NonLinearSystems__ChordSolver__
#define __NonLinearSystems__ChordSolver__

#include <stdio.h>
#include "BisectionSolver.h"

class ChordSolver:public ScalarNonLinearSolver{
    
public:
    virtual ChordSolver& operator= (ScalarNonLinearSolver const&);
    virtual ChordSolver& operator= (NonLinearSolver const&);
    virtual void Solve();

};

#endif
