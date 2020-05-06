

#ifndef __NonLinearSystems__NonLinearSystem__
#define __NonLinearSystems__NonLinearSystem__

#include <stdio.h>
#include <array>
#include "Variables.h"
#include "Functions.h"
#include "Matrix.h"
#include <vector>

using namespace std;

template <unsigned int dim> class NonLinearSolver:public Functions<dim>{
    
protected:
    
    array<Functions<dim>, dim> Jacobian;
    
    double Epsilon;
    unsigned int NConvergence;
    Variables<dim> InitialGuess;
    Variables<dim> FinalSolution;
    vector<Variables<dim>> VecIterations;

public:
    
    NonLinearSolver();
    void SetEpsilon(double const&);
    void SetNConvergence(unsigned int const&);
    void SetInitialGuess(Variables<dim> const&);
    void SetFinalSolution(Variables<dim> const&);
    double GetEpsilon()const;
    unsigned int GetNConvergence() const;
    Variables<dim> GetInitialGuess()const;
    Variables<dim> GetFinalSolution()const;
    vector<Variables<dim>> GetVecIerations()const;
    void AddVecIterations(Variables<dim> const&);
    void ClearVecIterations ();
    
    
    Variables<dim> Evaluate(Variables<dim> const& x) const;
    
    
    Matrix<dim> EvaluateJacobian(Variables<dim> const& x) const;
    void AddJacobian(double (*)(Variables<dim>), unsigned int const& NumEq, unsigned int const& NumVar);
    unsigned int JacobianSize();
    void JacobianClear();
    
    virtual NonLinearSolver& operator= (NonLinearSolver const&); // Does NOT copy FinalSolution or VecIterations
    virtual void Solve() =0;

    
};


#endif