#include "truth_table.h"

#include <string>
#include <vector>

using namespace std;

// spacing formatting function
string TruthTable::makeSpaces(int count) const {
    string text = "";

    for (int i = 0; i < count; i++) {
        text += " ";    // adding spaces to fit the cell width
    }

    return text;    // return the final string of spaces
}

// dashes formatting function
string TruthTable::makeDashes(int count) const {
    string text = "";

    for (int i = 0; i < count; i++) {
        text += "-";    // create a line separator using dashes
    }

    return text;
}
