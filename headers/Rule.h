#include "Generation.h"
#include <map>
#include <iostream>

class Rule {
private:
    int ruleNum;
    bool ruleStates[8];
    std::map<std::string, bool> binaryValues;
    const static char TRUE {'1'};
    const static char FALSE {'0'};

public:
    explicit Rule(int ruleNum);
    void fillHashmap();
    Generation evolve(Generation gen);
    static std::vector<bool> getNeighborhood(int idx, Generation gen);
    bool evolve(const std::vector<bool>& neighborhood);
    int getRuleNum() const;
    static std::string toBinary(int n);

    void fillRuleStates();
};


