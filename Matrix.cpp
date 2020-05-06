#ifndef Matrix_cpp
#define Matrix_cpp

#include "Matrix.h"


template<unsigned int dim> Matrix<dim>::Matrix():array<Variables<dim>, dim>(){}
template<unsigned int dim> Matrix<dim>::Matrix(array<Variables<dim>, dim> autre):array<Variables<dim>,dim> (autre){}

template<unsigned int dim> Matrix<dim>& Matrix<dim>::operator=(array<Variables<dim>,dim> autre){
    (*this).array<array<double,dim>,dim>::operator=(autre);
    return(*this);
}


template<unsigned int dim> Matrix<dim> Matrix<dim>::operator+(Matrix<dim>  autre){
    Matrix<dim> x;
    for(unsigned int i(0); i < dim; ++i)
        for (unsigned int j(0); j < dim; ++ j)
            x[i][j] = (*this)[i][j] + autre[i][j];
    return x;}
template<unsigned int dim> Matrix<dim> Matrix<dim>::operator-(Matrix<dim>  autre){
    Matrix<dim> x;
    for(unsigned int i(0); i < dim; ++i)
        for (unsigned int j(0); j < dim; ++ j)
            x[i][j] = (*this)[i][j] - autre[i][j];
    return x;}
template<unsigned int dim> Matrix<dim> Matrix<dim>::operator*(Matrix<dim>  autre){
    Matrix<dim> x;
    for(unsigned int i(0); i < dim; ++i)
        for (unsigned int j(0); j < dim; ++ j)
            for (unsigned int c(0); c < dim; ++c) {
                x[i][j] = (*this)[i][c] * autre[c][j];
            }
    return x;}

template<unsigned int dim> bool Matrix<dim>::operator==(Matrix<dim> const& autre){
    for(unsigned int i(0); i < dim; ++i)
        for(unsigned int j(0); j < dim;++j)
            if((*this)[i][j] != autre[i][j]) return false;
    return true;}

template<unsigned int dim> Matrix<dim>& Matrix<dim>::operator=(Matrix<dim> autre){
    for(unsigned int i(0); i<dim; ++i)
        for(unsigned int j(0); j<dim; ++j)
            (*this)[i][j] = autre[i][j];
    return (*this);
}

template<unsigned int dim> Matrix<dim> Matrix<dim>::operator+(double const& autre){
    Variables<dim> x;
    for(unsigned int i(0); i < dim; ++i)
        for(unsigned int j(0); j < dim;++j) x[i][j] = (*this)[i][j] + autre;
    return x;}

template<unsigned int dim> Matrix<dim> Matrix<dim>::operator-(double const& autre){
    Variables<dim> x;
    for(unsigned int i(0); i < dim; ++i)
        for(unsigned int j(0); j < dim;++j) x[i][j] = (*this)[i][j] - autre;
    return x;}

template<unsigned int dim> Matrix<dim> Matrix<dim>::operator/(double const& autre){
    Variables<dim> x;
    for(unsigned int i(0); i < dim; ++i)
        for(unsigned int j(0); j < dim;++j) x[i][j] = (*this)[i][j] /autre;
    return x;}

template<unsigned int dim> Matrix<dim> Matrix<dim>::operator*(double const& autre){
    Variables<dim> x;
    for(unsigned int i(0); i < dim; ++i)
        for(unsigned int j(0); j < dim;++j) x[i][j] = (*this)[i][j] * autre;
    return x;}
template<unsigned int dim> bool Matrix<dim>::operator==(double const& autre){
    for(unsigned int i(0); i < dim; ++i)
        for(unsigned int j(0); j < dim; ++j)if((*this)[i][j] != autre) return false;
    return true;}
template<unsigned int dim> Matrix<dim>& Matrix<dim>::operator=(double const& autre){
    for(unsigned int i(0); i<dim; ++i)
        for(unsigned int j(0); j < dim; ++j)(*this)[i][j] = autre;
    return (*this);
}

#endif