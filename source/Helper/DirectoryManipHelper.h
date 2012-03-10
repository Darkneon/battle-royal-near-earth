#ifndef DIRECTORY_MANIP_HELPER_H
#define DIRECTORY_MANIP_HELPER_H

#include<string>
#include<vector>
#include<fstream>
#include "..\..\include\WinDirent\dirent.h"
#include<cstdlib>

using namespace std;

const string FILE_FORMAT_BMP = ".bmp";

class DirectoryManipHelper
{
public:
	static void getDirectoryListing(string directoryName, vector<string> *directoryListing);
};

#endif