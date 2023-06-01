#include "pch.h"
#include "gd.h"
#include "steepestdescent.h"
#include "newtonstep.h"
#include "matmul.h"
#define EPSILON 0.00001

clock_t start, finish;
double duration;
vector<double> initX = {100, 100, 100};

int gradientDescentTest(){
    vector<double> oldSol = initX;
    start = clock();
    vector<double> sol = gradientDescent(initX);
    while((f(oldSol) - f(sol)) > EPSILON){
        oldSol = sol;
        sol = gradientDescent(sol);
    }
    finish = clock();
    cout << "Gradient Descent: ";
    for(auto s: sol){
        cout << s << " ";
    }
    cout << "z = " << f(sol) << " time : " << (double) (finish - start) / CLOCKS_PER_SEC <<"\n";
}

int steepestDescentTest(){
    vector<double> oldSol = initX;
    start = clock();
    vector<double> sol = steepestDescent(initX);

    while((f(oldSol) - f(sol)) > EPSILON){
        oldSol = sol;
        sol = steepestDescent(sol);
    }
    finish = clock();
    cout << "Steepest Descent: ";
    for(auto s: sol){
        cout << s << " ";
    }
    cout << "z = " << f(sol) << " time : " << (double) (finish - start) / CLOCKS_PER_SEC <<"\n";
}

int newtonStepTest(){

    vector<double> oldSol = initX;
    start = clock();
    vector<double> sol = newtonStep(initX);

    while((f(oldSol) - f(sol)) > EPSILON){
        oldSol = sol;
        sol = newtonStep(sol);
    }
    finish = clock();
    cout << "Newton Step: ";
    for(auto s: sol){
        cout << s << " ";
    }
    cout << "z = " << f(sol) << " time : " << (double) (finish - start) / CLOCKS_PER_SEC <<"\n";
}

int linearEquationTest(){
    vector<vector<double>> A;
    vector<double> b;
//    generateProblem(A, b, "test2");
    loadProblem(A, b, "test2");
    cout << A[0][0] << endl;
    cout << A[1][1] << endl;
    cout << A[2][2] << endl;
    cout << A[3][3] << endl;
}


int main() {
    linearEquationTest();
    return 0;
}
