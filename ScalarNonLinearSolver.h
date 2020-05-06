
#ifndef __NonLinearSystems__ScalarNonLinearSolver__
#define __NonLinearSystems__ScalarNonLinearSolver__

#include <stdio.h>
#include "NonLinearSolver.h"

class ScalarNonLinearSolver: public NonLinearSolver<1>{
    
protected:
    double xmin;
    double xmax;
public:
    double Getxmin()const;
    double Getxmax() const;
    void SetInterval(double const& xmin, double const& xmax);
    
    void SetInitialGuess(double const& autre);
    double GetInitialGuess();
    
    void SetFinalSolution(double const&);
    double GetFinalSolution();
    
    double Evaluate(double const& x) const;
    
    vector<double> GetVecIterations()const;
    void AddVecIterations(double const&);
    
    ScalarNonLinearSolver& operator=(ScalarNonLinearSolver const& autre);
    ScalarNonLinearSolver& operator=(NonLinearSolver<1> const& autre);

};

#endif
