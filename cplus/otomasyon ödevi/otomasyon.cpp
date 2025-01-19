#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <iomanip>

using namespace std;


struct Tup {
    char marka[9];           
    int numara;               
    char dolulukDurumu[10];   
    float fiyat;              
    int adet;                 
};


void TupEkle();
void TupListeleme();
void TupArama();
void TupSil();
void TupDuzenle();


int main() {
    char anamenu;
    do {
        system("cls");
        
        cout << "|-------Hosgeldiniz T�p�� Otomasyonu------|" << endl;
        cout << "|           Secim Yapiniz                |" << endl;
        cout << "|   1- T�p Ekleme                        |" << endl;
        cout << "|   2- T�p Listeleme                     |" << endl;
        cout << "|   3- T�p Arama                         |" << endl;
        cout << "|   4- T�p Silme                         |" << endl;
        cout << "|   5- T�p D�zenleme                     |" << endl;
        cout << "|----------------------------------------|" << endl;
        
        char secim;
        cin >> secim;

        switch (secim) {
            case '1': TupEkle();
			 break;
            case '2': TupListeleme(); 
			break;
            case '3': TupArama(); 
			break;
            case '4': TupSil(); 
			break;
            case '5': TupDuzenle(); 
			break;
            default: cout << "Ge�ersiz se�im." << endl; 
			break;
        }

        cout << "Ana menuye d�nmek i�in: a bas�n, ��kmak i�in: c" << endl;
        cin >> anamenu;
        
    } while (anamenu == 'a');

    return 0;
}

Tup tup;


void TupEkle() {
    ofstream yaz("tupverileri.dat", ios::binary | ios::app);
    char secim;
    int adet = 0;

    do {
        cout << "T�p Markas�n� Giriniz: ";
        cin >> tup.marka;
        cout << "T�p Numaras�n� Giriniz: ";
        cin >> tup.numara;
        cout << "T�p Doluluk Durumunu Giriniz (Tam/Yarim): ";
        cin >> tup.dolulukDurumu;
        cout << "T�p Fiyat�n� Giriniz: ";
        cin >> tup.fiyat;
        cout << "T�p Adetini Giriniz: ";
        cin >> tup.adet;
        
        yaz.write((char*)&tup, sizeof(tup));
        adet++;

        cout << "Ba�ka t�p eklemek ister misiniz? (E/H): ";
        cin >> secim;
        cout << endl;
    } while (secim == 'e' || secim == 'E');
    
    cout << adet << " adet t�p eklendi.." << endl;
    yaz.close();
}


void TupListeleme() {
    ifstream oku("tupverileri.dat", ios::binary);
    oku.seekg(0, ios::end);
    int kayits = oku.tellg() / sizeof(tup);
    
    cout << "Toplam T�p Say�s�: " << kayits << endl;

    if (kayits > 0) {
        for (int i = 0; i < kayits; i++) {
            oku.seekg(i * sizeof(tup));
            oku.read((char*)&tup, sizeof(tup));

            cout << i + 1 << ". T�p Bilgileri" << endl;
            cout << "Marka: " << tup.marka << endl;
            cout << "Numara: " << tup.numara << endl;
            cout << "Doluluk Durumu: " << tup.dolulukDurumu << endl;
            cout << "Fiyat: " << tup.fiyat << " TL" << endl;
            cout << "Adet: " << tup.adet << " adet" << endl;
        }
    } else {
        cout << "Kay�t bulunamad�..." << endl;
    }

    oku.close();
}


void TupArama() {
    ifstream oku("tupverileri.dat", ios::binary);
    oku.seekg(0, ios::end);
    int kayits = oku.tellg() / sizeof(tup);
    
    cout << "Aramak istedi�iniz t�p numaras�n� giriniz: ";
    int arananNumara;
    cin >> arananNumara;

    if (kayits > 0) {
        int bulundu = 0;
        for (int i = 0; i < kayits; i++) {
            oku.seekg(i * sizeof(tup));
            oku.read((char*)&tup, sizeof(tup));

            if (tup.numara == arananNumara) {
                cout << "Bulunan T�p Bilgileri" << endl;
                cout << "Marka: " << tup.marka << endl;
                cout << "Numara: " << tup.numara << endl;
                cout << "Doluluk Durumu: " << tup.dolulukDurumu << endl;
                cout << "Fiyat: " << tup.fiyat << " TL" << endl;
                cout << "Adet: " << tup.adet << " adet" << endl;
                bulundu = 1;
                break;
            }
        }
        if (bulundu == 0) {
            cout << "T�p bulunamad�." << endl;
        }
    } else {
        cout << "Kay�t bulunamad�..." << endl;
    }

    oku.close();
}


void TupSil() {
    ifstream oku("tupverileri.dat", ios::binary);
    ofstream yaz("temp.dat", ios::binary);
    oku.seekg(0, ios::end);
    int kayits = oku.tellg() / sizeof(tup);
    
    cout << "Silmek istedi�iniz t�p numaras�n� giriniz: ";
    int silinecekNumara;
    cin >> silinecekNumara;

    bool bulundu = false;
    for (int i = 0; i < kayits; i++) {
        oku.seekg(i * sizeof(tup));
        oku.read((char*)&tup, sizeof(tup));

        if (tup.numara != silinecekNumara) {
            yaz.write((char*)&tup, sizeof(tup)); 
        } else {
            bulundu = true;
        }
    }

    oku.close();
    yaz.close();

    if (bulundu) {
        remove("tupverileri.dat"); 
        rename("temp.dat", "tupverileri.dat"); 
        cout << "T�p ba�ar�yla silindi." << endl;
    } else {
        cout << "T�p bulunamad�." << endl;
    }
}


void TupDuzenle() {
    ifstream oku("tupverileri.dat", ios::binary);
    ofstream yaz("temp.dat", ios::binary);
    oku.seekg(0, ios::end);
    int kayits = oku.tellg() / sizeof(tup);
    
    cout << "D�zenlemek istedi�iniz t�p numaras�n� giriniz: ";
    int duzenlenecekNumara;
    cin >> duzenlenecekNumara;

    bool bulundu = false;
    for (int i = 0; i < kayits; i++) {
        oku.seekg(i * sizeof(tup));
        oku.read((char*)&tup, sizeof(tup));

        if (tup.numara == duzenlenecekNumara) {
            cout << "Mevcut T�p Bilgileri" << endl;
            cout << "Marka: " << tup.marka << endl;
            cout << "Numara: " << tup.numara << endl;
            cout << "Doluluk Durumu: " << tup.dolulukDurumu << endl;
            cout << "Fiyat: " << tup.fiyat << " TL" << endl;
            cout << "Adet: " << tup.adet << " adet" << endl;

           
            cout << "\nYeni T�p Bilgilerini Giriniz" << endl;
            cout << "Yeni Marka: ";
            cin >> tup.marka;
            cout << "Yeni Doluluk Durumu: ";
            cin >> tup.dolulukDurumu;
            cout << "Yeni Fiyat: ";
            cin >> tup.fiyat;
            cout << "Yeni Adet: ";
            cin >> tup.adet;

            bulundu = true;
        }
        
        yaz.write((char*)&tup, sizeof(tup)); 
    }

    oku.close();
    yaz.close();

    if (bulundu) {
        remove("tupverileri.dat");
        rename("temp.dat", "tupverileri.dat");
        cout << "T�p bilgileri ba�ar�yla g�ncellendi." << endl;
    } else {
        cout << "T�p bulunamad�." << endl;
    }
}

