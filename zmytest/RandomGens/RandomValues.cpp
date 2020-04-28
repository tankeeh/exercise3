//
// Created by Antonio on 15/04/2020.
//

#include <random>
#include "RandomValues.hpp"

int IntValueGenerator(){
    std::default_random_engine RandGen(std::random_device{}());
    std::uniform_int_distribution<> RandIntDistribution(-500, 500);
    return (RandIntDistribution(RandGen));
}

float FloatValueGenerator(){
    std::default_random_engine RandGen(std::random_device{}());
    std::uniform_real_distribution<> RandFloatDistribution(-500, 500);
    float temp = (RandFloatDistribution(RandGen));
    temp = round(temp*1000)/1000;
    return temp;
}

std::string CharValueGenerator(){
    std::string returnstring = "";
    std::default_random_engine RandGen(std::random_device{}());
    std::uniform_int_distribution<> RandCharDistribution(33,126);
    for(int i=0; i<5; i++) returnstring += (RandCharDistribution(RandGen));
    return returnstring;
}