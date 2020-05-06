#ifndef Functions_cpp
#define Functions_cpp

#include "Functions.h"
#include <cassert>

template<unsigned int dim> Functions<dim>::Functions(){N = 0;}

template<unsigned int dim> void Functions<dim>::Add(double (*fun) (Variables<dim>), unsigned int const& i){
    assert(N<dim);
    assert(i >= 0 and i < dim);
    (*this)[i] = fun;
    N++;
}

template<unsigned int dim> unsigned int Functions<dim>::Size()const{return N;}


template<unsigned int dim> Functions<dim>& Functions<dim>::operator=(array<double (*)(Variables<dim>), dim> const& autre){
    array<double (*)(Variables<dim>),dim>::operator=(autre);
    return (*this);}

template<unsigned int dim> void Functions<dim>::Clear(){N=0;}



#endif