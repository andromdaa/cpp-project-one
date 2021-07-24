#include <string>
#include <iostream>
#include <vector>


class Generation {

private:
    std::vector<bool> cellStates;
public:
     explicit Generation(std::vector<bool> cellStates);
     explicit Generation(const std::string& states, const char trueSymbol);
     bool getState(int idx);
     std::vector<bool> getStates();
     std::string getStates(char falseSymbol, char trueSymbol);
     int size();
};
