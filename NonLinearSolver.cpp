#ifndef NonLinearSolver_cpp
#define NonLinearSolver_cpp

#include "NonLinearSolver.h"
#include <cmath>
#include <cassert>

template<unsigned int dim> NonLinearSolver<dim>::NonLinearSolver():Functions<dim>(){}
template <unsigned int dim> void NonLinearSolver<dim>::SetInitialGuess(Variables<dim> const& x){InitialGuess = x;}
template <unsigned int dim> void NonLinearSolver<dim>::SetFinalSolution(Variables<dim> const& x){FinalSolution = x;}
template <unsigned int dim> void NonLinearSolver<dim>::SetEpsilon(double const& x){Epsilon = abs(x);}
template <unsigned int dim> void NonLinearSolver<dim>::SetNConvergence(unsigned int const& x){NConvergence = x;}

template <unsigned int dim> Variables<dim> NonLinearSolver<dim>::GetInitialGuess()const{return InitialGuess;}
template <unsigned int dim> Variables<dim> NonLinearSolver<dim>::GetFinalSolution()const{return FinalSolution;}
template <unsigned int dim> double NonLinearSolver<dim>::GetEpsilon()const {return Epsilon;}
template <unsigned int dim> unsigned int NonLinearSolver<dim>::GetNConvergence() const {return NConvergence;}

template <unsigned int dim> Variables<dim> NonLinearSolver<dim>::Evaluate(Variables<dim> const& x)const
{
    assert(Functions<dim>::Size() == dim);

    Variables<dim> y;
    for (unsigned int i(0); i < dim; ++i) {
        y[i] = (*this)[i](x);
    }
    return y;
}

template <unsigned int dim> NonLinearSolver<dim>& NonLinearSolver<dim>::operator=(NonLinearSolver<dim> const& autre)
{
    Functions<dim>::operator=(autre);
    Jacobian = autre.Jacobian;
    Epsilon = autre.Epsilon;
    NConvergence = autre.NConvergence;
    InitialGuess = autre.InitialGuess;
    return (*this);
}

template<unsigned int dim>     vector<Variables<dim>> NonLinearSolver<dim>::GetVecIerations()const{
    return VecIterations;}


template<unsigned int dim> void NonLinearSolver<dim>::AddVecIterations(Variables<dim> const& var ){VecIterations.push_back(var);}
template<unsigned int dim> void NonLinearSolver<dim>::ClearVecIterations(){VecIterations.clear();}

template<unsigned int dim>
Matrix<dim> NonLinearSolver<dim>::EvaluateJacobian(Variables<dim> const& x) const{
    Matrix<dim> y;
    for (unsigned int i(0); i < dim; ++i) {
        for (unsigned int j(0); j<dim; ++j)
        y[i][j] = Jacobian[i][j](x);
    }
    return y;
}

template<unsigned int dim>
void NonLinearSolver<dim>::AddJacobian(double (*fun)(Variables<dim>), unsigned int const& NumEq, unsigned int const& NumVar){Jacobian[NumEq].Add(fun, NumVar);}
template<unsigned int dim>
unsigned int NonLinearSolver<dim>::JacobianSize(){
    unsigned int c=0;
    for (auto& elem:Jacobian) c += elem.Size();
    return c;
}

template<unsigned int dim>
void NonLinearSolver<dim>::JacobianClear(){
    for (auto& elem:Jacobian) elem.Clear();
}

#endif