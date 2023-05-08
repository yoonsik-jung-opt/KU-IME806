//
// Created by yoonsikjung on 2023/05/08.
//

#ifndef IME806_NEWTONSTEP_H
#define IME806_NEWTONSTEP_H

#include "pch.h"

vector<double> newtonStep(vector<double> x){
    vector<double> dir = getGradient(x);
    vector<double> newtonDirection = {(1./30) * dir[0], (1./20) * dir[1], (1./10) * dir[2]};
    return {x[0] + newtonDirection[0], x[1] + newtonDirection[1], x[2] + newtonDirection[2]};
}

#endif //IME806_NEWTONSTEP_H
