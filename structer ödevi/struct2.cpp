#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <iostream>

using namespace std;

struct Kumas
{
string iplik_tipi;
float dm2agirlik;
string dokuma_tipi;
string renk;
int miktar;
       
};

struct Iskelet
{
	string malzeme;
	string birlestirme;
	string tarz;
	float boyut;
	int miktar;
	      
};


struct Mobilya 
{
Iskelet malzeme;
Kumas kaplama;
int fiyat;
int adet;	
	
	
	
};

int main()
{
	setlocale(LC_ALL, "Turkish");
	for(int i=0;i<10;i++)
	{
	
	Mobilya mobilya;
	 
	 cout<<" mobilya kuma�� i�in dokuma tipi giriniz:"<<mobilya.kaplama.dokuma_tipi<<endl;
	 cin>>mobilya.kaplama.dokuma_tipi;
	 cout<<" mobilya kuma�� i�in a��rl�k giriniz:"<<mobilya.kaplama.dm2agirlik<<endl;
	 cin>>mobilya.kaplama.dm2agirlik;
	 cout<<" mobilya kuma�� i�in iplik tipi giriniz:"<<mobilya.kaplama.iplik_tipi<<endl;
	 cin>>mobilya.kaplama.iplik_tipi;
	 cout<<" mobilya kuma�� i�in renk giriniz: "<<mobilya.kaplama.renk<<endl;
	 cin>>mobilya.kaplama.renk;
	 
	 
	 
	 
	
	cout<< " mobilya iskeleti i�in birle�tirme giriniz:"<<mobilya.malzeme.birlestirme<<endl;
	cin>>mobilya.malzeme.birlestirme;
	cout<<" mobilya iskeleti i�in boyut giriniz: "<<mobilya.malzeme.boyut<<endl;
	cin>>mobilya.malzeme.boyut;
	cout<<" mobilya iskeleti i�in malzeme giriniz:"<<mobilya.malzeme.malzeme<<endl;
	cin>>mobilya.malzeme.malzeme;
	cout<<"mobilya iskeleti i�in tarz giriniz:"<<mobilya.malzeme.tarz<<endl;
	cin>>mobilya.malzeme.tarz;
	

	 cout<<"mobilya i�in fiyat giniz:"<<mobilya.fiyat<<endl;
	 cin>>mobilya.fiyat;
	 cout<<"mobilya i�in adet giriniz:"<<mobilya.adet<<endl;
	 cin>>mobilya.adet;
	
	
	
	
	
	
	
	
	
	
}
	
	return 0;
}
