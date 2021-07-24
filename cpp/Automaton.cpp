//
// Created by Cole on 7/20/2021.
//

#include "../headers/Automaton.h"

Automaton::Automaton(int ruleNum, const Generation& initial) : rule(ruleNum){
    generations.push_back(initial);
    trueSymbol = '1';
    falseSymbol = '0';
}

int Automaton::getRuleNum() {
    return rule.getRuleNum();
}

void Automaton::evolve(int numSteps) {
    if(numSteps <= 0) return;

    for (int i = 0; i < numSteps; i++) {
        Generation lastGeneration = generations.back();
        generations.push_back(rule.evolve(lastGeneration));
    }

}

Generation Automaton::getGeneration(int stepNum) {
    if(stepNum > generations.size() - 1) evolve(stepNum - getTotalSteps());
    return generations.at(stepNum);
}

int Automaton::getTotalSteps() {
    return (int) generations.size() - 1;
}

std::string Automaton::toString() {
    std::string automatonStr;
    bool first = true;

    for(Generation gen : generations) {

        if(first) first = false;
        else automatonStr += "\n";

        for(bool b : gen.getStates()) {
            if(b) automatonStr += trueSymbol;
            else automatonStr += falseSymbol;
        }
    }

    automatonStr += "\n";

    return automatonStr;

}

void Automaton::saveEvolution(const std::string& fileName) {
    std::ofstream evolution;
    evolution.open(fileName);
    evolution << toString();
    evolution.close();
}



