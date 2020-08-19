//
//  SA.cpp
//  search
//
//  Created by WU,MENG-TING on 2020/7/8.
//  Copyright © 2020 WU,MENG-TING. All rights reserved.
//

#include "SA.hpp"

SA::SA():bits(10),iter(5),temperature(2),alpha(0.9){
    vector<int> temp1(bits,0);
    vector<vector<int> > temp2(iter,vector<int>(bits,0));
    vector<int> temp3(iter,0);
    bitstr = temp1;
    best_bitstr = temp1;
    record_bitstr = temp2;
    record_value = temp3;
}

SA::SA(int bits,int iter,double temperature,double alpha):bits(bits),iter(iter),temperature(temperature),alpha(alpha){
    vector<int> temp1(bits,0);
    vector<vector<int> > temp2(iter,vector<int>(bits,0));
    vector<int> temp3(iter,0);
    bitstr = temp1;
    best_bitstr = temp1;
    record_bitstr = temp2;
    record_value = temp3;
}

void SA::Initialization(){
    for (int i=bits-1;i>=0;i--){
        bitstr[i] = rand()%2;
    }
}

int SA::FitnessFunction(vector<int> str){
    int sum=0;
    for (int i=0;i<bits;i++)
        sum+=str[i];
    return sum;
}

double SA::Pa(int current,int neighbor){
    return exp((double)(neighbor-current)/temperature);
}

void SA::anneal(){
    temperature *= alpha;
}

vector<int> SA::select_neighbor(vector<int> str){
    vector<int> temp(bits,0);
    temp = str;
    int index = rand()%bits;
    temp[index] = str[index]==0?1:0;
    return temp;
}

void SA::run(){
    Initialization();
    best_value = value = FitnessFunction(bitstr);
    best_bitstr = bitstr;
    record_bitstr[0] = best_bitstr;
    record_value[0] = best_value;
    int it=1;
    //stopping condition
    while (it<iter&&best_value<bits){
        vector<int> neighbor = select_neighbor(bitstr);
        int neighbor_value = FitnessFunction(neighbor);
        //accept better solution
        if (neighbor_value>value){
            bitstr = neighbor;
            value = neighbor_value;
        }
        else{
            //accept worse solution for probability of Pa
            if ( ((double)rand()/RAND_MAX) < Pa(value,neighbor_value) ){
                bitstr = neighbor;
                value = neighbor_value;
            }
            //doesn't accept for probability (1-Pa)
        }
        
        value = FitnessFunction(bitstr);
        
        if (value>best_value){
            best_value = value;
            best_bitstr = bitstr;
        }
        
        record_bitstr[it] = best_bitstr;
        record_value[it] = best_value;
        
        anneal();
        it++;
    }
    
    for (int i=it;i<record_value.size();i++){
        record_bitstr[i] = best_bitstr;
        record_value[i] = best_value;
    }
}
