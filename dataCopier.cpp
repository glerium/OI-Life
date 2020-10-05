#include <cstdio>
#include <ctime>
#include <string>
#include <iostream>
#include <Windows.h>
using namespace std;
int main(int argc,char* argv[]){
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);	//hide console window
	if(argc!=2) exit(1);
	char run[10000]="";
	sprintf(run,"copy %s \"D:\\¿Î¼þ\"",argv[1]);
	system(run);
	if(strstr(argv[1],".ppt")){
		sprintf(run,"\"C:\\Program Files\\Microsoft Office\\Office11\\POWERPNT.EXE\" %s",argv[1]);
		system(run);
	}else if(strstr(argv[1],".doc")){
		sprintf(run,"\"C:\\Program Files\\Microsoft Office\\Office11\\WINWORD.EXE\" %s",argv[1]);
		system(run);
	}
	
	::ShowWindow(::GetConsoleWindow(), SW_SHOW);
	system("pause");
	exit(0);
	return 0;
}
