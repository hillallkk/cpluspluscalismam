#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <iostream>

using namespace std;

struct Otomobil
{
	string marka;
	string model;
	int yil;
	char yakit;
	int km;
	double fiyat;
	
	
};
int main()
{
	setlocale(LC_ALL,"Turkish");
	
Otomobil binek;
binek.marka="ford";
binek.model="focus";
binek.yil=2010;
binek.yakit='B';
binek.km=1000;
binek.fiyat=700000;


cout<<"binek araç için bilgiler aþaðýdaki gibidir;"<<endl;
cout<<"marka:"<<binek.marka<<endl;
cout<<"model:"<<binek.model<<endl;
cout<<"yil:"<<binek.yil<<endl;
cout<<"yakit:"<<binek.yakit<<endl;
cout<<"km:"<<binek.km<<endl;
cout<<"fiyat:"<<binek.fiyat<<endl;

Otomobil ticari;
ticari.marka="fiat";
ticari.model="doblo";
ticari.yil=2005;
ticari.yakit='D';
ticari.km=50000;
ticari.fiyat=500000;


cout<<"ticari araç için bilgiler aþaðýdaki gibidir; "<<endl;
cout<<"marka:"<<ticari.marka<<endl;
cout<<"model:"<<ticari.model<<endl;
cout<<"yil:"<<ticari.yil<<endl;
cout<<"yakit:"<<ticari.yakit<<endl;
cout<<"km:"<<ticari.km<<endl;
cout<<"fiyat:"<<ticari.fiyat<<endl;


Otomobil suv;
suv.marka="volkswagen";
suv.model="tiguan";
suv.yil=2020;
suv.yakit='G';
suv.km=80000;
suv.fiyat=900000;

cout<<"suv araç için bilgiler aþaðýdaki gibidir; "<<endl;
cout<<"marka:"<<suv.marka<<endl;
cout<<"model:"<<suv.model<<endl;
cout<<"yil:"<<suv.yil<<endl;
cout<<"yakit:"<<suv.yakit<<endl;
cout<<"km:"<<suv.km<<endl;
cout<<"fiyat:"<<suv.fiyat<<endl;


	
	
	
	
	
	
	
	
	
	
	return 0;
}
