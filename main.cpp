//
//  main.cpp
//  search
//
//  Created by WU,MENG-TING on 2020/7/1.
//  Copyright © 2020 WU,MENG-TING. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include "execute.hpp"

using namespace std;

void prompt(const int Algo,const int runs,const int iterations,const int bits);

int main(int argc, const char * argv[]) {
    const string algo = argv[1];
    const int runs = stoi(argv[2]);
    const int iterations = stoi(argv[3]);
    const int bits = stoi(argv[4]);
    string filename = argv[5];
    cout<<"filename: "<<filename<<endl;
    const double temperature = stod(argv[6]);
    const double alpha = stod(argv[7]);
    if (algo=="sa"){
        prompt(1, runs, iterations, bits);
        execute(1, runs, iterations, bits, filename,temperature, alpha);
    }
    else{
        cerr<<"No such algorithm!"<<endl;
    }
    return 0;
}

void prompt(const int Algo,const int runs,const int iterations,const int bits){
    cout<<"----------------------------------------"<<endl;
    switch (Algo) {
        case 1:
            cout<<"Simulated Annealing Algorithm:"<<endl;
            break;
        default:
            break;
    }
    cout<<"runs: "<<runs<<endl;
    cout<<"iterations: "<<iterations<<endl;
    cout<<"bits: "<<bits<<endl;
    cout<<"----------------------------------------"<<endl;
}
