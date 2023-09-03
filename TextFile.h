#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class TextFile
{
    const string FILE_NAME ;

protected:
    fstream textFile;
    bool isFileEmpty(fstream &textFile);
    string getFileName();

public:
    TextFile(string fileName) : FILE_NAME(fileName) {};
};
#endif
