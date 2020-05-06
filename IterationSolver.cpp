#ifndef IterationSolver_cpp
#define IterationSolver_cpp

#include "IterationSolver.h"
#include "NonLinearSolver.cpp"

template<unsigned int dim>
IterationSolver<dim>& IterationSolver<dim>::operator= (NonLinearSolver<dim> const& autre){
    NonLinearSolver<dim>::operator=(autre);
    return *this;}

template<unsigned int dim>
void IterationSolver<dim>::Solve(){
    unsigned int i(0);
    Variables<dim> y, x;
    x = NonLinearSolver<dim>::GetInitialGuess();
    cout << "Looking for solution of the vectorial equation of the type F(x) = x " << endl;
    cout << "Iteration 0, x = " << x << endl;
    assert(NonLinearSolver<dim>::NConvergence > 0);
    assert(NonLinearSolver<dim>::Epsilon > 0);
    assert(NonLinearSolver<dim>::Size() == dim);
    bool conv;
    do{
        conv = true;
        y = x;
        x = NonLinearSolver<dim>::Evaluate(x);
        ++i;
        cout << "Iteration " << i << ", x = " << x << endl;
        NonLinearSolver<dim>::AddVecIterations(x);
        
        for (unsigned int iter(0); iter < dim; ++iter){
            if (abs(x[iter]-y[iter]) > NonLinearSolver<dim>::GetEpsilon()) conv = false;
        }
    }while(conv == false and i < NonLinearSolver<dim>::NConvergence);
    
    NonLinearSolver<dim>::SetFinalSolution(x);
    
    if (!conv){
        throw string("IterationSolver did not converge sufficiently");
        return;}
    else {
        cout << "Solution : x = " << NonLinearSolver<dim>::GetFinalSolution() << endl;
        return;
        
    }

}

#endif