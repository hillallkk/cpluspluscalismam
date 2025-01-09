#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <iostream>

using namespace std;
 
struct Bilgi
{
	string ad_soyad;
	string adres;
	string telefon_no;
	
	
	
};
	struct Gonderi
	{
		string gonderi_no;
		float agirlik;
		float hacim;
		bool garanti;
		double ucret;
		
		
		
	};
	



int main()
{
setlocale(LC_ALL, "Turkish");

	
		for(int i=0;i<5;i++)
		{
		
	Bilgi gonderen;
				
	gonderen.ad_soyad;
	gonderen.adres;
	gonderen.telefon_no;
		
	cout<<"gönderici için ad soyad bilgisi giriniz:"<<gonderen.ad_soyad<<endl;
	cin>>gonderen.ad_soyad;
	cout<<"gönderici için adres giriniz:"<<gonderen.adres<<endl;
	cin>>gonderen.adres;
	cout<<"gönderici için telefon numarasý giriniz:"<<gonderen.telefon_no<<endl;
	cin>>gonderen.telefon_no;


	
	
	Bilgi alici;
	
	alici.ad_soyad;
	alici.adres;
	alici.telefon_no;
	
    cout<<"alýcý için ad soyad bilgisi giriniz:"<<gonderen.ad_soyad<<endl;
	cin>>alici.ad_soyad;
	cout<<"alýcý için adres giriniz:"<<gonderen.adres<<endl;
	cin>>alici.adres;
	cout<<"alýcý için telefon numarasý giriniz:"<<gonderen.telefon_no<<endl;
	cin>>alici.telefon_no;
	
	Bilgi kurye;
	
	kurye.ad_soyad;
	kurye.telefon_no;
	
    cout<<"kurye için ad soyad bilgisi giriniz:"<<gonderen.ad_soyad<<endl;
	cin>>kurye.ad_soyad;
	cout<<"kurye için telefon numarasý giriniz:"<<gonderen.telefon_no<<endl;
	cin>>kurye.telefon_no;
	
 	Gonderi bilgi;
 	
 	bilgi.gonderi_no;
 	bilgi.agirlik;
 	bilgi.hacim;
 	bilgi.garanti;
 	bilgi.ucret;
 	
 	cout<<"gönderi numarasý giriniz:"<<bilgi.gonderi_no<<endl;
 	cin>>bilgi.gonderi_no;
 	cout<<"gönderi aðýrlýðý giriniz:"<<bilgi.agirlik<<endl;
 	cin>>bilgi.agirlik;
 	cout<<"gönderi hacmi giriniz:"<<bilgi.hacim<<endl;
 	cin>>bilgi.hacim;
 	cout<<"gönderi garantisi var mý?:"<<bilgi.garanti<<endl;
 	cin>>bilgi.agirlik;
 	cout<<"gönderi ücreti giriniz:"<<bilgi.ucret<<endl;
 	cin>>bilgi.ucret;
	
	


}
	
	
	
	return 0;
}
