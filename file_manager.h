#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>

using namespace std;

// creating a class to handle the saving of the generated report to a file
class FileManager {
public:
    bool saveReport(const string& filename, const string& report) const;
};

#endif
