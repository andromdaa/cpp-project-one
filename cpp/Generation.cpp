#include "../headers/Generation.h"

Generation::Generation(std::vector<bool> cellStates) {
    if(cellStates.empty()) {
        cellStates = {false};
    }

    Generation::cellStates = cellStates;
}

int Generation::size() {
    return (int) Generation::cellStates.size();
}

Generation::Generation(const std::string& states, const char trueSymbol) {
    //optimization, will not cause reallocation
    Generation::cellStates.reserve(states.size());

    if(states.empty()) {
        Generation::cellStates = {false};
        return;
    }

    for(auto i{0}; i < states.size(); i++) {
        if(states.at(i) == trueSymbol) {
            Generation::cellStates.push_back(true);
        } else {
            Generation::cellStates.push_back(false);
        }
    }
}

bool Generation::getState(int idx) {
    return Generation::cellStates.at(idx);
}

std::vector<bool> Generation::getStates() {
    return std::vector<bool>(Generation::cellStates);
}

std::string Generation::getStates(char falseSymbol, char trueSymbol) {
    std::string stateString;

    for(bool s : getStates()) {
        if (s) stateString += trueSymbol;
        else stateString += falseSymbol;
    }

    return stateString;
}







