#include "pch.h"
#include "gd.h"
#include "steepestdescent.h"
#include "newtonstep.h"
#include "matmul.h"
#include "LinAlg.h"
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

int matmulTest(){
//    vector<double> A = {1,1,1,1};
//    vector<vector<double>> B = {{13, 9,7 ,15},{8,7,4,6},{6,4,0,3}};
////    auto res = oper::matmul(A, B);
//
////    for(auto r : res){
////        for(auto v : r){
////            cout << v << " ";
////        }
////        cout << "\n";
////    }
//
//    auto v = oper::matmul(B, A);
//    for(auto vv : v){
//        cout << vv << " ";
//    }

}

int linearEquationTest(){
    vector<vector<double>> A;
    vector<double> b;
    vector<double> x(10000, 0);
// multiprocessing
//    start = clock();
    generateProblem(A, b, "test1");
    generateProblem(A, b, "test3");
    generateProblem(A, b, "test4");
    generateProblem(A, b, "test5");

//    loadProblem(A, b, "test2");
//    finish = clock();
//    cout << " time : " << (double) (finish - start) / CLOCKS_PER_SEC <<"\n";
//
//    start = clock();
//    LinearAlgebra::Matrix m(A);
//
//    vector<vector<double>> AA;
//    for(int i = 0; i < 10; i++){
//        AA.push_back(A[i]);
//    }
//
//    LinearAlgebra::Matrix mm(AA);
//    auto mmt = mm.T();
//    auto res = oper::matmul(mmt, AA);
//    auto grad = LinearAlgebra::vectorMinus( oper::matmul(res, x), oper::matmul(AA, b));
//
//
//    cout << grad.size() << " " << endl;
//    cout << grad[0] << endl;
//    cout << grad[1] << endl;


    //    oper::matmul(A, b);

//    m.QRDecomposition();
    finish = clock();
    cout << " time : " << (double) (finish - start) / CLOCKS_PER_SEC <<"\n";
    cout<< A[0][0] << endl;


}

int main() {
    linearEquationTest();
//    matmulTest();

    return 0;
}

