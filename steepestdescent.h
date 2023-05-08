//
// Created by yoonsikjung on 2023/05/08.
//

#ifndef IME806_STEEPESTDESCENT_H
#define IME806_STEEPESTDESCENT_H
#include "pch.h"

vector<double> getSteepestDirection(vector<double> x){
    vector<double> d = {-dfdx1(x), -dfdx2(x), -dfdx3(x)};
    int argmax = min_element(d.begin(), d.end()) - d.begin();
    for(int i = 0; i < d.size(); i++){
        if(i == argmax){
            d[i] = d[i] > 0 ? 1 : -1;
        }else{
            d[i] = 0;
        }
    }
    return d;
}

vector<double> steepestDescent(vector<double> x, double alpha=0.5, double beta=0.5){
    vector<double> dir = getSteepestDirection(x);
    double z = f(x);
    double t = 1;
    // backtracking line search
    while((f({x[0] + t * dir[0], x[1] + t * dir[1], x[2] + t * dir[2]}) >=
           (z + alpha * t * (pow(dir[0],2) + pow(dir[1], 2) + pow(dir[2],2))))){
        t = beta * t;
    }
    return {x[0] + t * dir[0], x[1] + t *dir[1], x[2] + t* dir[2]};
}



#endif //IME806_STEEPESTDESCENT_H
