
#ifndef Variables_cpp
#define Variables_cpp

#include "Variables.h"
#include <cassert>

template<unsigned int dim> Variables<dim>::Variables():array<double,dim>(){}
template<unsigned int dim> Variables<dim>::Variables(array<double,dim> autre):array<double,dim>(autre){}

template<unsigned int dim> Variables<dim>& Variables<dim>::operator=(array<double,dim> autre){
    (*this).array<double,dim>::operator=(autre);
    return(*this);
}

template<unsigned int dim> double& Variables<dim>::operator[](unsigned int k){
    assert(k>=0 && k < dim);
    return (*this).array<double,dim>::operator[](k);
}
template<unsigned int dim> Variables<dim> Variables<dim>::operator+(array<double,dim>  autre){
    Variables<dim> x;
    for(unsigned int i(0); i < dim; ++i) x[i] = (*this)[i] + autre[i];
    return x;}
template<unsigned int dim> Variables<dim> Variables<dim>::operator-(Variables<dim> autre){
    Variables<dim> x;
    for(unsigned int i(0); i < dim; ++i) x[i] = (*this)[i] - autre[i];
    return x;}
template<unsigned int dim> Variables<dim> Variables<dim>::operator/(Variables<dim>  autre){
    Variables<dim> x;
    for(unsigned int i(0); i < dim; ++i) x[i] = (*this)[i] / autre[i];
    return x;}
template<unsigned int dim> Variables<dim> Variables<dim>::operator*(Variables<dim> autre){
    Variables<dim> x;
    for(unsigned int i(0); i < dim; ++i) x[i] = (*this)[i] * autre[i];
    return x;}
template<unsigned int dim> bool Variables<dim>::operator==(Variables<dim> const& autre){
    for(unsigned int i(0); i < dim; ++i) if((*this)[i] != autre[i]) return false;
    return true;}
template<unsigned int dim> Variables<dim>& Variables<dim>::operator=(Variables<dim> autre){
    for(unsigned int i(0); i<dim; ++i) (*this)[i] = autre[i];
    return (*this);
}

template<unsigned int dim> Variables<dim> Variables<dim>::operator+(double const& autre){
    Variables<dim> x;
    for(unsigned int i(0); i < dim; ++i) x[i] = (*this)[i] + autre;
    return x;}
template<unsigned int dim> Variables<dim> Variables<dim>::operator-(double const& autre){
    Variables<dim> x;
    for(unsigned int i(0); i < dim; ++i) x[i] = (*this)[i] - autre;
    return x;}
template<unsigned int dim> Variables<dim> Variables<dim>::operator/(double const& autre){
    Variables<dim> x;
    for(unsigned int i(0); i < dim; ++i) x[i] = (*this)[i] / autre;
    return x;}
template<unsigned int dim> Variables<dim> Variables<dim>::operator*(double const& autre){
    Variables<dim> x;
    for(unsigned int i(0); i < dim; ++i) x[i] = (*this)[i] * autre;
    return x;}
template<unsigned int dim> bool Variables<dim>::operator==(double const& autre){
    for(unsigned int i(0); i < dim; ++i) if((*this)[i] != autre) return false;
    return true;}
template<unsigned int dim> Variables<dim>& Variables<dim>::operator=(double const& autre){
    for(unsigned int i(0); i<dim; ++i) (*this)[i] = autre;
    return (*this);
}

template<unsigned int dim>
ostream& operator<<(ostream& ou, Variables<dim> var){
    if (dim < 2) {
        for (auto elem:var) ou << elem;
        return ou;
    }
    else {
        ou << "(";
        for (unsigned int i(0); i < dim-1; ++i) ou << var[i] << ";";
        ou << var[dim-1] << ")";
        return ou;
    }
}

#endif