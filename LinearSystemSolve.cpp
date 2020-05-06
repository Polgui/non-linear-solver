#ifndef LinearSystemSolver_cpp
#define LinearSystemSolver_cpp

#include "LinearSystemSolve.h"
#include <cmath>
#include <cassert>


template<unsigned int dim>
Variables<dim> SolveLinearSystem(Matrix<dim> mat, Variables<dim> b){

    Variables<dim> m; //See description in Appendix A
    Variables<dim> solution;
    
    // forward sweep of Gaussian elimination
    for (int k=0; k<dim-1; k++)
    {
        // see if pivoting is necessary
        double max = 0.0;
        int row = -1;
        for (int i=k; i<dim; i++)
        {
            if (fabs(mat[i][k]) > max)
            {
                row = i;
                max=fabs(mat[i][k]); //NB bug in published version
            }
        }
        assert(row >= 0); //NB bug in published version
        
        // pivot if necessary
        if (row != k)
        {
            // swap matrix rows k+1 with row+1
            for (int i=0; i<dim; i++)
            {
                double temp = mat[k][i];
                mat[k][i] = mat[row][i];
                mat[row][i] = temp;
            }
            // swap vector entries k+1 with row+1
            double temp = b[k];
            b[k] = b[row];
            b[row] = temp;
        }
        
        // create zeros in lower part of column k
        for (int i=k+1; i<dim; i++)
        {
            m[i] = mat[i][k]/mat[k][k];
            for (int j=k; j<dim; j++)
            {
                mat[i][j] -= mat[k][j]*m[i];
            }
            b[i] -= b[k]*m[i];
        }
    }
    
    // back substitution
    for (int i=dim-1; i>-1; i--)
    {
        solution[i] = b[i];
        for (int j=i+1; j<dim; j++)
        {
            solution[i] -= mat[i][j]*solution[j];
        }
        solution[i] /= mat[i][i];
    }
    
    return solution;

}

#endif