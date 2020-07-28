#include <bits/stdc++.h>
#include <stdio.h>
#include <io.h>
#include <urlmon.h>                 //Needed for the URLDownloadToFile() function
#pragma comment(lib, "urlmon.lib")  //Needed for the URLDownloadToFile() function
using namespace std;

char* getFileName(char* str) {
	int index = strlen(str)-1;
	while (str[index] != '/')
		index--;
	return (str + index + 1);
}

void download(char* url, char* id, char* dir) {
	typedef int * (*MyDownloadToUrl)(void*,char*,char*,DWORD,void*);
	HINSTANCE LibHnd = LoadLibrary("Urlmon.dll");
	MyDownloadToUrl MyDownloadFunction =  (MyDownloadToUrl)GetProcAddress(LibHnd,"URLDownloadToFileA");
	
	string sdir = string(dir) + "/" + string(id);
	string sname(getFileName(url));
	
	mkdir(sdir.c_str());
	MyDownloadFunction( NULL, url, (char*)((sdir + "/" + sname).c_str()), 0, NULL );
}

int main () {
	ifstream myfile;
	char s[10000];
	char *tok;
	
	char csvpath[1000];
	char outpath[1000];
	
	cout << "Insert the path of the csv file (default: directory of the program) + the name of the file:  ";
	cin >> csvpath;
	
	cout << "Insert the path of the EXISTING directory where you want to store the data:  ";
	cin >> outpath;
	
	// CHANGE THE FILENAME TO THE ONE YOU WANT
	myfile.open(csvpath);

	myfile >> s;
	myfile >> s;
	
	while (!myfile.eof()) {
		tok = strtok (s,";");
		char *id = tok;
		tok = strtok (NULL,";");
		
		while ((tok = strtok (NULL,";"))  != NULL) {
			if (tok[0] == '"')
				tok = tok+1;
			if (tok[strlen(tok)-1] == '"')
				tok[strlen(tok)-1] = 0;
			
			download(tok,id,outpath);
		}
		
		myfile >> s;
	}

	myfile.close();

	return 0;
}
