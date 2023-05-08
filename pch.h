// PreCompiledHeader
// this file is included only .cpp file
#ifndef IME806_PCH_H
#define IME806_PCH_H

#include <iostream>
#include "vector"
#include "string"
#include "math.h"
#include <time.h>

using namespace std;

double f(vector<double> x){
    return 15 * pow(x[0] - 1, 2) + 10 * pow(x[1]+3, 2) + 5 * pow(x[2]-4, 2);
}

double dfdx1(vector<double> x){
    return 30 * x[0] - 30;
}

double dfdx2(vector<double> x){
    return 20 * x[1] + 60;
}

double dfdx3(vector<double> x){
    return 10 * x[2] - 40;
}

vector<double> getGradient(vector<double> x){
    return vector<double>{-dfdx1(x), -dfdx2(x), -dfdx3(x)};
}

vector<vector<double>> getHessian(vector<double> x){
    return {{30, 0, 0}, {0, 20, 0}, {0,0,10}};
}

#endif //IME806_PCH_H
