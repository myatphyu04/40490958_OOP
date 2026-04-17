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

// cell formatting function
string TruthTable::fitCell(string text, int width) const {
    if ((int)text.size() < width) {
        text += makeSpaces(width - (int)text.size());   // add spaces to the end of the text to fit the cell width
    }

    return text;
}

// function to build the headers of the truth table
vector<string> TruthTable::buildHeaders(const BooleanExpression& expression) const {
    vector<string> headers;
    vector<string> steps = expression.stepLabels();     // get step labels from expression

    // adding variable headers first in the order of A, B, C
    headers.push_back("A");
    headers.push_back("B");
    headers.push_back("C");

    for (int i = 0; i < (int)steps.size(); i++) {
        headers.push_back(steps[i]);    // add the expression step labels after the input columns
    }

    return headers;
}

// function to build the widths of the columns in the truth table
vector<int> TruthTable::buildWidths(const vector<string>& headers) const {
    vector<int> widths;

    for (int i = 0; i < (int)headers.size(); i++) {
        widths.push_back((int)headers[i].size());   // set the initial width of each column to the length of its header
    }

    return widths;
}