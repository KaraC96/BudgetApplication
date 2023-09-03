#include "TextFile.h"

bool TextFile::isFileEmpty(fstream &textFile)
{
    textFile.seekg(0, ios::end);

    if (textFile.tellg() == 0)
        return true;
    else
        return false;
}

string TextFile::getFileName()
{
    return FILE_NAME;
}
