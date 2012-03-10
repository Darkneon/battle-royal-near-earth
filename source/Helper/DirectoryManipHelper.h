#ifndef DIRECTORY_MANIP_HELPER_H
#define DIRECTORY_MANIP_HELPER_H

#include<string>
#include<vector>
#include<fstream>
#include<cstdlib>

#ifdef __APPLE__
	#include <dirent.h>
#elif __linux__
	#include <dirent.h>
#else
    #include "..\..\include\WinDirent\dirent.h"
#endif

using namespace std;

const string FILE_FORMAT_BMP = ".bmp";

class DirectoryManipHelper
{
public:
	static void getDirectoryListing(string directoryName, vector<string> *directoryListing);
};

#endif