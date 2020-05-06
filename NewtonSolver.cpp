
#ifndef NewtonSolver_cpp
#define NewtonSolver_cpp

#include "NewtonSolver.h"
#include "NonLinearSolver.cpp"
#include <cassert>
#include "LinearSystemSolve.cpp"
#include "Matrix.cpp"
#include <cmath>


template<unsigned int dim>
NewtonSolver<dim>& NewtonSolver<dim>::operator= (NonLinearSolver<dim> const& autre){
    NonLinearSolver<dim>::operator=(autre);
    return *this;}


template<unsigned int dim>
void NewtonSolver<dim>::Solve(){

    unsigned int i(0);
    Variables<dim> x= NonLinearSolver<dim>::GetInitialGuess();
    Variables<dim> y;
    cout << "Looking for zeros of the system using Newton method, starting with x = " << x << endl;
    assert(NonLinearSolver<dim>::NConvergence > 0);
    assert(NonLinearSolver<dim>::Epsilon > 0);
    assert(NonLinearSolver<dim>::Size() == dim);
    assert(NonLinearSolver<dim>::JacobianSize() == dim*dim);

    bool conv;
    do{
        conv = true;
        y = x;
        if (NonLinearSolver<dim>::Evaluate(x) == 0) {
            NonLinearSolver<dim>::SetFinalSolution(x);
            cout << "Solution : x = " << NonLinearSolver<dim>::GetFinalSolution() << endl;
            return;
        }
        else x = x + SolveLinearSystem<dim>(NonLinearSolver<dim>::EvaluateJacobian(x), NonLinearSolver<dim>::Evaluate(x)*(-1));
        ++i;
        cout << "Iteration " << i << ", x = " << x << endl;
        NonLinearSolver<dim>::AddVecIterations(x);
        
        for (unsigned int iter(0); iter < dim; ++iter){
            if (abs(x[iter]-y[iter]) > NonLinearSolver<dim>::GetEpsilon()) conv = false;
        }
    }while(conv == false and i < NonLinearSolver<dim>::GetNConvergence());
    
    NonLinearSolver<dim>::SetFinalSolution(x);
    
    if (!conv){
        throw string("NewtonSolver did not converge sufficiently");
        return;}
    else {
        cout << "Solution : x = " << NonLinearSolver<dim>::GetFinalSolution() << endl;
        return;
        
    }

}
#endif