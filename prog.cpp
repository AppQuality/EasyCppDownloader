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

void download(char* url, char* dir) {
	typedef int * (*MyDownloadToUrl)(void*,char*,char*,DWORD,void*);
	HINSTANCE LibHnd = LoadLibrary("Urlmon.dll");
	MyDownloadToUrl MyDownloadFunction =  (MyDownloadToUrl)GetProcAddress(LibHnd,"URLDownloadToFileA");
	
	string sdir(dir);
	string sname(getFileName(url));
	
	MyDownloadFunction( NULL, url, (char*)((sdir + "/" + sname).c_str()), 0, NULL );
}

int main () {
	ifstream myfile;
	char s[10000];
	char *tok;
	myfile.open("data.csv");

	myfile >> s;
	myfile >> s;
	
	while (!myfile.eof()) {
		tok = strtok (s,";");
		mkdir(tok);
		char *dir = tok;
		tok = strtok (NULL,";");
		cout << dir << "\n";
		
		while ((tok = strtok (NULL,";"))  != NULL) {
			if (tok[0] == '"')
				tok = tok+1;
			if (tok[strlen(tok)-1] == '"')
				tok[strlen(tok)-1] = 0;
			
			download(tok,dir);
		}
		
		myfile >> s;
	}

	myfile.close();

	return 0;
}
