//
// Created by yoonsikjung on 2023/05/08.
//

#ifndef IME806_GD_H
#define IME806_GD_H
#include "pch.h"


vector<double> gradientDescent(vector<double> x, double alpha=0.3, double beta=0.5){
    vector<double> dir = getGradient(x);
    double z = f(x);
    double t = 1;
    // backtracking line search
    while((f({x[0] + t * dir[0], x[1] + t * dir[1], x[2] + t * dir[2]}) >=
           (z + alpha * t * (pow(dir[0],2) + pow(dir[1], 2) + pow(dir[2],2))))){
        t = beta * t;
    }
    return {x[0] + t * dir[0], x[1] + t *dir[1], x[2] + t* dir[2]};
}


#endif //IME806_GD_H
