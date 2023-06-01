//
// Created by yoonsikjung on 2023/06/01.
//

#ifndef IME806_MATMUL_H
#define IME806_MATMUL_H


#include "pch.h"

void generateProblem(vector<vector<double>> &AA, vector<double> &bb, string fname){
    // save csv initialization
    ofstream myFileA(fname + "_A.csv");
    ofstream myFileb(fname + "_b.csv");

    // random engin initialization
    random_device rand_dev;
    mt19937 generator(rand_dev());
    uniform_real_distribution<double> distr(-1000, 1000);

    bernoulli_distribution bd(0.15);

    vector<vector<double>> A;
    A.resize(10000);

    // generate matrix randomly
    for(int i = 0; i < 10000; i++){
        vector<double> temp;
        temp.resize(10000);
        for(int j = 0; j < 10000; j++){
            if(bd(generator) || i == j){
                temp[j] = distr(generator);
            }
            else{
                temp[j] = 0;
            }
            if(j != 0){
                myFileA << ",";
            }
            myFileA << temp[j];

        }
        myFileA << "\n";
        A[i] = temp;
    }
    uniform_real_distribution<double> distrb(10, 1000);
    // generate rhs randomly
    vector<double> b;
    b.resize(10000);
    for(int i = 0; i < 10000; i++){
        b[i] = distr(generator);
        myFileb << b[i] << "\n";
    }

    // assign A and b
    AA = A;
    bb = b;

}

vector<vector<double>> loadA(string fname){
    vector<vector<double>> A;
    A.resize(10000);
    ifstream fileA(fname + "_A.csv");
    if(fileA.is_open()){
        string line;
        int j = 0;
        while(getline(fileA, line)){
            istringstream iss(line);
            string buffer = "";
            double buffer_d = 0;
            vector<double> temp;
            temp.resize(10000);
            int i = 0;

            while(getline(iss, buffer, ',')){
                buffer_d = stod(buffer);
                temp[i] = buffer_d;
                i++;
            }
            A[j] = temp;
            j++;
        }
        fileA.close();
    }

    return A;
}

vector<double> loadb(string fname){
    vector<double> b;
    b.resize(10000);
    ifstream fileb(fname+"_b.csv");
    if(fileb.is_open()){
        string line;
        double buffer_d = 0;
        int i = 0;
        while(getline(fileb, line)){
            buffer_d = stod(line);
            b[i] = buffer_d;
            i++;
        }
    }

    return b;
}

void loadProblem(vector<vector<double>> &A, vector<double> &b, string fname){
    A = loadA(fname);
    b = loadb(fname);
}




#endif //IME806_MATMUL_H
