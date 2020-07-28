This is a cpp downloader.
You can do one thing with this program: download files from URL that are in a very specific CSV file.
The program will download the files of the third column in the directory indicated in the first column.

Each line of the file is in the following form: [ "id";"timestamp";"array_of_URL" ]:
- the timestamp doesn't get used, so you can also use [ "id";;"array_of_URL" ];
- array_of_URL is a string in which two URLs are separeted by a ';';
- there must be no other ';' in the line except the ones i've said above.

In order to use the program, you must run the .exe and tell the program the path of the input file and output directory.
Don't forget to have the urlmon.dll in the same directory of the program. 