#ifndef ScalarNonLinearSolver_cpp
#define ScalarNonLinearSolver_cpp

#include "ScalarNonLinearSolver.h"
#include "NonLinearSolver.cpp"
#include "Variables.cpp"

ScalarNonLinearSolver& ScalarNonLinearSolver::operator=(const ScalarNonLinearSolver& autre) {
    NonLinearSolver<1>::operator=(autre);
    xmin = autre.xmin;
    xmax = autre.xmax;
    return *this;
}

ScalarNonLinearSolver& ScalarNonLinearSolver::operator=(const NonLinearSolver<1>& autre) {
    NonLinearSolver<1>::operator=(autre);
    return *this;
}

double ScalarNonLinearSolver::Getxmin() const{return xmin;}
double ScalarNonLinearSolver::Getxmax() const{return xmax;}

void ScalarNonLinearSolver::SetInterval(const double& x_min, const double& x_max){
    xmin = x_min;
    xmax = x_max;
    if (xmin> xmax) {
        cerr << "Warning: xmin > xmax during initialization of BisectionSolver" << endl;
    }
}

void ScalarNonLinearSolver::SetInitialGuess(double const& x){InitialGuess = x;}
double ScalarNonLinearSolver::GetInitialGuess(){return InitialGuess[0];}


void ScalarNonLinearSolver::SetFinalSolution(double const& x){

    FinalSolution = {x};
}

double ScalarNonLinearSolver::GetFinalSolution(){return FinalSolution[0];}

double ScalarNonLinearSolver::Evaluate(double const& x) const{
    Variables<1> y;
    y[0] = x;
    return NonLinearSolver<1>::Evaluate(y)[0];}


vector<double> ScalarNonLinearSolver::GetVecIterations()const{
    vector<double> vec;
    for (auto elem:VecIterations) {
        vec.push_back(elem[0]);
    }
    return vec;}

void ScalarNonLinearSolver::AddVecIterations(double const& x) {
    Variables<1>y;
    y = x;
    NonLinearSolver::AddVecIterations(y);
}

#endif


