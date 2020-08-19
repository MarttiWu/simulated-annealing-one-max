//
//  SA.hpp
//  search
//
//  Created by WU,MENG-TING on 2020/7/8.
//  Copyright © 2020 WU,MENG-TING. All rights reserved.
//

#ifndef SA_hpp
#define SA_hpp

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;

class SA{
public:
    SA();
    SA(int bits,int iter,double temperature,double alpha);
    void Initialization();
    void run();
    vector<int> select_neighbor(vector<int> str);
    double Pa(int current,int neighbor);
    void anneal();
    int FitnessFunction(vector<int> str);
    vector<int> get_record_bitstr(int it){return record_bitstr[it];}
    int get_record_value(int it){return record_value[it];}
private:
    int bits;
    int iter;
    double temperature;
    double alpha;
    vector<int> bitstr;
    int value;
    vector<int> best_bitstr;
    int best_value;
    vector<vector<int> > record_bitstr;
    vector<int> record_value;
};

#endif /* SA_hpp */
