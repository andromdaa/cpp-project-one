//
// Created by Cole on 7/20/2021.
//

#include "Rule.h"
#include <fstream>

class Automaton {
private:
    Rule rule;
    std::vector<Generation> generations;

public:
    char falseSymbol;
    char trueSymbol;
    Automaton(int ruleNum, const Generation& initial);
    int getRuleNum();
    void evolve(int numSteps);
    Generation getGeneration(int stepNum);
    int getTotalSteps();
    std::string toString();
    void saveEvolution(const std::string& fileName);
};


