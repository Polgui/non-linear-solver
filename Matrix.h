
#ifndef __NonLinearSystems__Matrix__
#define __NonLinearSystems__Matrix__

#include <stdio.h>
#include <array>
#include "Variables.h"

template<unsigned int dim>

class Matrix: public array<Variables<dim>, dim>{
public:
    Matrix();
    Matrix(array< Variables<dim>, dim> autre);
    Matrix<dim>& operator=(array<Variables<dim>, dim> autre);
    
    Matrix<dim> operator+(Matrix<dim>  autre);
    Matrix<dim> operator-(Matrix<dim>  autre);
    Matrix<dim> operator*(Matrix<dim>  autre);
    Matrix<dim>& operator=(Matrix<dim> autre);
    bool operator==(Matrix<dim> const& autre);
    
    Matrix<dim> operator+(double const& autre);
    Matrix<dim> operator-(double const& autre);
    Matrix<dim> operator/(double const& autre);
    Matrix<dim> operator*(double const& autre);
    Matrix<dim>& operator=(double const& autre);
    bool operator==(double const& autre);



};


#endif