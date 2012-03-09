#include "DirectoryManipHelper.h"

//#include <iostream>
//static const char* FILE_FORMAT_USED = ".bmp";

void DirectoryManipHelper::getDirectoryListing(string directoryName, vector<string> *directoryListing)
{
	DIR *pDIR;
    struct dirent *entry;

    if( pDIR=opendir(".") )
	{
        while(entry = readdir(pDIR))
		{
			string currentFileName = entry->d_name;
			if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
				if (directoryListing != NULL)
					directoryListing->push_back(entry->d_name);
				//cout << entry->d_name << "\n";
        }
        closedir(pDIR);
    }
}