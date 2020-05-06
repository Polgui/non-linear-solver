#ifndef BisectionSolver_cpp
#define BisectionSolver_cpp

#include "BisectionSolver.h"
#include "Variables.cpp"
#include "Functions.cpp"
#include <cassert>
#include <cmath>




BisectionSolver& BisectionSolver::operator=(ScalarNonLinearSolver const& autre)
{
    ScalarNonLinearSolver::operator=(autre);
    return (*this);
}

BisectionSolver& BisectionSolver::operator=(NonLinearSolver const& autre)
{
    NonLinearSolver::operator=(autre);
    return (*this);
}

void BisectionSolver::Solve(){
    cout << "BisectionSolver: Looking for zeros of the function, between " << xmin << " and " << xmax << endl;
    
    if (xmin > xmax) {
        throw string("Error: xmin > xmax at the beginning of Solve() for BisectionSolver");
        return;
    }
    else if(Evaluate(xmin)*Evaluate(xmax) > 0){
        throw string("Error: f(xmin) and f(xmax) have the same sign");
        return;
    }
    else if (abs(Evaluate(xmin)) == 0) {
        FinalSolution = xmin;
        cout << "Zero found at x = " << xmin << endl;
        return;
    }
    else if (abs(Evaluate(xmax)) == 0) {
        FinalSolution = xmax;
        cout << "Zero found at x = " << xmax << endl;
        return;
    }
    else{
        assert(NConvergence > 0);
        assert(Epsilon > 0);
        assert(Size() > 0);
        
        double xlow = xmin;
        double xhigh = xmax;
        
        double c=0;
        
        unsigned int i=0;
        do{
            c = (xlow + xhigh)/2;
            if (Evaluate(xlow)*Evaluate(c) > 0) xlow = c;
            else if (Evaluate(xhigh)*Evaluate(c) > 0) xhigh = c;
            else if (Evaluate(c) == 0) {
                cout << "Zero found at x = " << c << endl;
                FinalSolution = c;
                return;
            }
            ++i;
            cout << "Iteration " << i << ", xlow = " << xlow << ", xhigh = " << xhigh << endl;
            AddVecIterations((xlow+xhigh)/2);
            
        }while(abs(xlow-xhigh) > Epsilon and i < NConvergence);
        
        FinalSolution = (xlow + xhigh)/2;
        
        if (abs(xlow-xhigh) > Epsilon and i == NConvergence){
            throw string("BisectionSolver did not converge sufficiently");
            return;}
        else {
            cout << "Zero found at x = " << FinalSolution << endl;
            return;
        }
    }
}

#endif