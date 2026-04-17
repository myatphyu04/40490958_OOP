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

// function to generate the truth table for a given boolean expression
string TruthTable::generate(const BooleanExpression& expression) const {
    string output = "Generating Truth Table...\n";
    vector<string> headers = buildHeaders(expression);
    vector<int> widths = buildWidths(headers);
    int totalRows = 8;  // total combinations of A, B, C)

    output += "|";
    for (int i = 0; i < (int)headers.size(); i++) {
        output += " " + fitCell(headers[i], widths[i]) + " |";  // format each header cell properly
    }
    output += "\n";

    output += "|";
    for (int i = 0; i < (int)headers.size(); i++) {
        output += makeDashes(widths[i] + 2) + "|";  // add a separator line of dashes under the headers
    }
    output += "\n";

    for (int row = 0; row < totalRows; row++) {
        // generate all possible combinations of A, B, and C using row index patterns
        bool aValue = (row / 4) % 2;
        bool bValue = (row / 2) % 2;
        bool cValue = row % 2;

        output += "|";
        // convert boolean values to 1 or 0 and format into table columns
        output += " " + fitCell(aValue ? "1" : "0", widths[0]) + " |";
        output += " " + fitCell(bValue ? "1" : "0", widths[1]) + " |";
        output += " " + fitCell(cValue ? "1" : "0", widths[2]) + " |";

        // evaluate the expression using the current row values of A, B, and C
        vector<int> stepValues = expression.evaluateSteps(aValue, bValue, cValue);

        for (int i = 0; i < (int)stepValues.size(); i++) {
            string valueText = "0";

            if (stepValues[i] == 1) {
                valueText = "1";
            }

            output += " " + fitCell(valueText, widths[i + 3]) + " |";   // add evaluated step values to the corresponding columns after A, B, C
        }

        output += "\n";
    }

    return output;
}
