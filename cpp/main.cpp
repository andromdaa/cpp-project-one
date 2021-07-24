#include "../headers/Automaton.h"

int main() {

    Automaton eca(2, Generation(("100001000010"), '1'));

    eca.evolve(50);

    eca.trueSymbol = '$';
    eca.falseSymbol = ';';

    std::cout << eca.toString();

    eca.saveEvolution("rule2.txt");

}
