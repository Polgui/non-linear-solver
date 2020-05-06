#ifndef ChordSolver_cpp
#define ChordSolver_cpp

#include "ChordSolver.h"
#include <cmath>
#include <cassert>

ChordSolver& ChordSolver::operator=(NonLinearSolver const& autre)
{
    NonLinearSolver::operator=(autre);
    return (*this);
}

ChordSolver& ChordSolver::operator=(ScalarNonLinearSolver const& autre)
{
    ScalarNonLinearSolver::operator=(autre);
    return (*this);
}

void ChordSolver::Solve(){

    
    cout << "ChordSolver: Looking for zeros of the function, between " << xmin << " and " << xmax << endl;
    cout << "Iteration 0, x = " << InitialGuess << endl;
    if (xmin > xmax) {
        throw string("Error: xmin > xmax at the beginning of Solve() for ChordSolver");
        return;
    }
    else if(Evaluate(xmin)*Evaluate(xmax) > 0){
        throw string("Error: f(xmin) and f(xmax) have the same sign");
        return;
    }
    else if (abs(Evaluate(xmin)) == 0) {
        
        SetFinalSolution(xmin);
        cout << "Zero found at x = " << xmin << endl;
        return;
    }
    else if (abs(Evaluate(xmax)) == 0) {
        
        SetFinalSolution(xmax);
        cout << "Zero found at x = " << xmax << endl;
        return;
    }
    else{
        assert(NConvergence > 0);
        assert(Epsilon > 0);
        assert(GetInitialGuess() <= xmax && GetInitialGuess() >= xmin);
        assert(Size() == 1);
        
        double q = (Evaluate(xmax)-Evaluate(xmin))/(xmax-xmin);
        
        double c=GetInitialGuess();
        double prev;
        
        unsigned int i=0;
        do{
            prev = c;
            c = prev - Evaluate(prev)/q;
            if (Evaluate(c) == 0) {
                cout << "Zero found at x = " << c << endl;
                
                SetFinalSolution(c);
                return;
            }
            ++i;
            cout << "Iteration " << i << ", x = " << c << endl;
            AddVecIterations(c);
            
        }while(abs(c-prev) > Epsilon and i < NConvergence);
        
        SetFinalSolution(c);
        
        if (abs(c-prev) > Epsilon and i == NConvergence){
            throw string("ChordSolver did not converge sufficiently");
            return;}
        else {
            cout << "Zero found at x = " << FinalSolution << endl;
            return;
        }
    }
}

#endif