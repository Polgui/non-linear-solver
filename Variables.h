
#ifndef __NonLinearSystems__Variables__
#define __NonLinearSystems__Variables__

#include <stdio.h>
#include <iostream>
#include <array>

using namespace std;

template <unsigned int dim> class Variables:public array<double, dim>{ // It is not a vector in the usual sense, rather a list of numbers

public:
    Variables();
    Variables(array<double, dim> autre);
    Variables<dim>& operator=(array<double, dim> autre);
    
    Variables<dim> operator+(array<double,dim>  autre);
    Variables<dim> operator-(Variables<dim>  autre);
    Variables<dim> operator/(Variables<dim> autre);
    Variables<dim> operator*(Variables<dim>  autre);
    Variables<dim>& operator=(Variables<dim> autre);
    bool operator==(Variables<dim> const& autre);
    
    Variables<dim> operator+(double const& autre);
    Variables<dim> operator-(double const& autre);
    Variables<dim> operator/(double const& autre);
    Variables<dim> operator*(double const& autre);
    Variables<dim>& operator=(double const& autre);
    bool operator==(double const& autre);
    
    double& operator[](unsigned int k);
    
};

template <unsigned int dim>
ostream& operator<<(ostream& ou, Variables<dim> var);

#endif 