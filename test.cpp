#include <iostream>
#include <ctime>
#include <string>

using namespace std;

int main(){
	time_t rawtime;
	tm * timeinfo;

	time (&rawtime);
	timeinfo = localtime (&rawtime);
	cout<<timeinfo<<endl;
	cout<<timeinfo->tm_sec<<endl;
	cout<<timeinfo->tm_min<<endl;
	cout<<timeinfo->tm_hour<<endl;
	cout<<timeinfo->tm_mday<<endl;
	cout<<timeinfo->tm_mon<<endl;
	cout<<timeinfo->tm_year<<endl;
	cout<<asctime(timeinfo)<<endl;

	tm hola;
	hola.tm_sec=timeinfo->tm_sec;
	hola.tm_min=timeinfo->tm_min;
	hola.tm_hour=timeinfo->tm_hour;
	hola.tm_mday=timeinfo->tm_mday;
	hola.tm_mon=timeinfo->tm_mon;
	hola.tm_year=timeinfo->tm_year;
	
	cout<<hola.tm_sec<<endl;
	cout<<hola.tm_min<<endl;
	cout<<hola.tm_hour<<endl;
	cout<<hola.tm_mday<<endl;
	cout<<hola.tm_mon<<endl;
	cout<<hola.tm_year<<endl;
	delete timeinfo;
	
	return 0;
}