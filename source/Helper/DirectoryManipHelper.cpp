#include "DirectoryManipHelper.h"

#include <iostream>
#include <cstring>
#include "Texture/TextureManager.h"

void DirectoryManipHelper::getDirectoryListing(string directoryName, vector<string> *directoryListing)
{
	DIR *pDIR;
    struct dirent *entry;
    string dir = TextureManager::getResourcePath();
    if( pDIR = opendir(dir.c_str()) )
	{
        while(entry = readdir(pDIR))
		{
			string currentFileName = entry->d_name;
			if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 
				&& currentFileName.find(FILE_FORMAT_BMP) != string::npos)
			{
				directoryListing->push_back(entry->d_name);
				cout << entry->d_name << "\n";
			}
        }
        closedir(pDIR);
    }        
}