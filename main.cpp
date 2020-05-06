
#include <iostream>
#include "NonLinearSolver.h"
#include "ChordSolver.h"
#include "AitkenSolver.h"
#include "Variables.cpp"
#include "Functions.cpp"
#include "IterationSolver.cpp"
#include "NewtonSolver.cpp"

double f1(Variables<3> var){return sqrt((var[0]+2)/var[1]);}
double f2(Variables<3> var){return sqrt((var[0]+2)/var[2]);}
double f3(Variables<3> var){return sqrt(var[1]/(var[0] + 2));}
double g(Variables<1> var){return var[0]*var[0]*5-1;}

double h1(Variables<2> var){return exp(var[0]*var[0] + var[1]*var[1]) - 1;}
double h2(Variables<2> var){return exp(var[0]*var[0] - var[1]*var[1]) - 1;}

double h11(Variables<2> var){return 2*var[0]*exp(var[0]*var[0] + var[1]*var[1]);}
double h12(Variables<2> var){return 2*var[1]*exp(var[0]*var[0] + var[1]*var[1]);}
double h21(Variables<2> var){return 2*var[0]*exp(var[0]*var[0] - var[1]*var[1]);}
double h22(Variables<2> var){return -2*var[1]*exp(var[0]*var[0] - var[1]*var[1]);}

using namespace std;

int main(int argc, const char * argv[]) {
    
    Variables<3> y({3,0,2});
    Variables<2> x;
    x = x+3;
    x= x*2;
    x= x+x;
    cout << x << endl;
    
    BisectionSolver fun3;
    fun3.Add(&g,0);
    fun3.SetNConvergence(2000);
    fun3.SetEpsilon(1e-5);
    fun3.SetInterval(0, 10.95);
    fun3.SetInitialGuess(0.5);
    fun3.Solve();
    
    ChordSolver fun4;
    fun4.Add(&g,0);
    fun4 = fun3;
    fun4.Solve();
    cout << fun4.GetVecIerations().size() << endl;
    
    AitkenSolver fun5;
    fun5 = fun4;
    fun5.Solve();
    
    IterationSolver<3> fun6, fun7;
    fun6.SetInitialGuess( Variables<3>({1, 2, 3}));
    fun6.SetNConvergence(3000);
    fun6.SetEpsilon(1e-10);
    fun6.Add(&f1,0);
    fun6.Add(&f2,1);
    fun6.Add(&f3,2);
    fun6.Solve();
    
    NewtonSolver<3> fun8;
    fun8 = fun6;
    
    NewtonSolver<2> fun9;
    fun9.Add(&h1, 0);
    fun9.Add(&h2, 1);
    fun9.AddJacobian(&h11, 0, 0);
    fun9.AddJacobian(&h12, 0, 1);
    fun9.AddJacobian(&h21, 1, 0);
    fun9.AddJacobian(&h22, 1, 1);
    fun9.SetEpsilon(1e-6);
    fun9.SetNConvergence(2000);
    fun9.SetInitialGuess(Variables<2>({10,10}));
    fun9.Solve();
    
    return 0;
}
