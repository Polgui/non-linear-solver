#ifndef AitkenSolver_cpp
#define AitkenSolver_cpp

#include "AitkenSolver.h"
#include "Variables.cpp"
#include <cassert>
#include <cmath>




AitkenSolver& AitkenSolver::operator=(ScalarNonLinearSolver const& autre)
{
    ScalarNonLinearSolver::operator=(autre);
    return (*this);
}

AitkenSolver& AitkenSolver::operator=(NonLinearSolver const& autre)
{
    NonLinearSolver::operator=(autre);
    return (*this);
}

void AitkenSolver::Solve(){
    cout << "AitkenSolver: Looking for fixed point of the function" << endl;
    cout << "Iteration 0, x = " << GetInitialGuess() << endl;
    
    assert(NConvergence > 0);
    assert(Epsilon > 0);
    assert(Size() == 1);
    
    double x0=GetInitialGuess();
    double prev;
    
    unsigned int i=0;
        do{
            prev = x0;
            double x1 = Evaluate(x0);
            double x2 = Evaluate(x1);
            x0 = (x0*x2 - x1*x1)/(x2 - 2*x1+x0);
            ++i;
            cout << "Iteration " << i << ", x = " << x0 << endl;
            AddVecIterations(x0);
            
        }while(abs(x0-prev) > Epsilon and i < NConvergence);
        
        FinalSolution = x0;
        
        if (abs(x0-prev) > Epsilon and i == NConvergence){
            throw string("AitkenSolver did not converge sufficiently");
            return;}
        else {
            cout << "Zero found at x = " << FinalSolution << endl;
            return;
        }
}
#endif