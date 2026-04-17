#include "file_manager.h"

#include <fstream>

using namespace std;

// implementing the function to save the generated report
bool FileManager::saveReport(const string& filename, const string& report) const {
    ofstream outFile(filename.c_str());     // open the file for writing using the provided filename

    // check if the file was opened successfully
    if (!outFile) {
        return false;
    }

    outFile << report;  // write the report content to the file
    outFile.close();
    return true;
}
