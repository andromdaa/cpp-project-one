//
// Created by Cole on 7/20/2021.
//

#include "../headers/Rule.h"

Rule::Rule(int ruleNum) {
    if (ruleNum > 255) ruleNum = 255;
    else if (ruleNum < 0) ruleNum = 0;

    Rule::ruleNum = ruleNum;

    fillRuleStates();
    fillHashmap();
}

void Rule::fillRuleStates() {
    std::string binaryStr = toBinary(ruleNum);
    std::string padded = std::string(8 - binaryStr.size(), '0').append(binaryStr);

    for(int i{0}; i < padded.size(); i++) {
        if(padded.at(i) == TRUE) ruleStates[i] = true;
        else ruleStates[i] = false;
    }
}

void Rule::fillHashmap() {
    binaryValues = {
            {"111", ruleStates[0]},
            {"110", ruleStates[1]},
            {"101", ruleStates[2]},
            {"100", ruleStates[3]},
            {"011", ruleStates[4]},
            {"010", ruleStates[5]},
            {"001", ruleStates[6]},
            {"000", ruleStates[7]}
    };
}

bool Rule::evolve(const std::vector<bool>& neighborhood) {
    std::string intNeighborhood;
    for(bool b : neighborhood) {
        if (b) intNeighborhood += TRUE;
        else intNeighborhood += FALSE;
    }
    return binaryValues[intNeighborhood];
}

 Generation Rule::evolve(Generation gen) {
    std::vector<bool> generationBools = gen.getStates();
    std::vector<bool> newGen;
    //optimization for memory allocation
    newGen.reserve(generationBools.size());

    for(int i {0}; i < generationBools.size(); i++) {
        newGen.push_back(evolve( Rule::getNeighborhood(i, gen)));
    }

    return Generation(newGen);
}

std::vector<bool> Rule::getNeighborhood(int idx, Generation gen) {
    std::vector<bool> generationBools = gen.getStates();
    std::vector<bool> neighbors = {false, false, false};

    neighbors.reserve(3);

    if (generationBools.size() == 1) {
        //if the array only has one value, the only neighbors it has are itself.
        std::fill(neighbors.begin(), neighbors.end(), generationBools[0]);
    } else if (idx == 0) {
        //if the index is 0, the left neighbor is the last index
        neighbors[0] = generationBools[generationBools.size() - 1];
        neighbors[1] = generationBools[idx];
        neighbors[2] = generationBools[idx + 1];
    } else if (idx == generationBools.size() - 1) {
        //if the index is the last index, the right neighbor is the first index
        neighbors[0] = generationBools[idx - 1];
        neighbors[1] = generationBools[idx];
        neighbors[2] = generationBools[0];
    } else {
        //fill in the neighborhood properly with its left neighbor, the index, then the right neighbor values
        neighbors[0] = generationBools[idx - 1];
        neighbors[1] = generationBools[idx];
        neighbors[2] = generationBools[idx + 1];
    }

    return neighbors;
}

int Rule::getRuleNum() const {
    return Rule::ruleNum;
}

std::string Rule::toBinary(int n) {
    std::string r;

    while(n!=0) {
        r = ( n % 2 == 0 ? "0" : "1" ) + r ;
        n/=2;
    }

    return r;
}







