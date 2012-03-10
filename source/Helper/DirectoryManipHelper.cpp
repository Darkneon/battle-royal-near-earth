#include "DirectoryManipHelper.h"

#include <iostream>

void DirectoryManipHelper::getDirectoryListing(string directoryName, vector<string> *directoryListing)
{
	//string type = ".bmp";
	DIR *pDIR;
    struct dirent *entry;

    if( pDIR=opendir(".") )
	{
        while(entry = readdir(pDIR))
		{
			string currentFileName = entry->d_name;
			if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 
				&& !S_ISDIR(entry->d_type) && currentFileName.find(FILE_FORMAT_BMP) != string::npos)
			{
				directoryListing->push_back(entry->d_name);
				cout << entry->d_name << "\n";
			}
        }
        closedir(pDIR);
    }
}