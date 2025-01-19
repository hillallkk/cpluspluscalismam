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
        
        cout << "|-------Hosgeldiniz Tüpçü Otomasyonu------|" << endl;
        cout << "|           Secim Yapiniz                |" << endl;
        cout << "|   1- Tüp Ekleme                        |" << endl;
        cout << "|   2- Tüp Listeleme                     |" << endl;
        cout << "|   3- Tüp Arama                         |" << endl;
        cout << "|   4- Tüp Silme                         |" << endl;
        cout << "|   5- Tüp Düzenleme                     |" << endl;
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
            default: cout << "Geçersiz seçim." << endl; 
			break;
        }

        cout << "Ana menuye dönmek için: a basýn, çýkmak için: c" << endl;
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
        cout << "Tüp Markasýný Giriniz: ";
        cin >> tup.marka;
        cout << "Tüp Numarasýný Giriniz: ";
        cin >> tup.numara;
        cout << "Tüp Doluluk Durumunu Giriniz (Tam/Yarim): ";
        cin >> tup.dolulukDurumu;
        cout << "Tüp Fiyatýný Giriniz: ";
        cin >> tup.fiyat;
        cout << "Tüp Adetini Giriniz: ";
        cin >> tup.adet;
        
        yaz.write((char*)&tup, sizeof(tup));
        adet++;

        cout << "Baþka tüp eklemek ister misiniz? (E/H): ";
        cin >> secim;
        cout << endl;
    } while (secim == 'e' || secim == 'E');
    
    cout << adet << " adet tüp eklendi.." << endl;
    yaz.close();
}


void TupListeleme() {
    ifstream oku("tupverileri.dat", ios::binary);
    oku.seekg(0, ios::end);
    int kayits = oku.tellg() / sizeof(tup);
    
    cout << "Toplam Tüp Sayýsý: " << kayits << endl;

    if (kayits > 0) {
        for (int i = 0; i < kayits; i++) {
            oku.seekg(i * sizeof(tup));
            oku.read((char*)&tup, sizeof(tup));

            cout << i + 1 << ". Tüp Bilgileri" << endl;
            cout << "Marka: " << tup.marka << endl;
            cout << "Numara: " << tup.numara << endl;
            cout << "Doluluk Durumu: " << tup.dolulukDurumu << endl;
            cout << "Fiyat: " << tup.fiyat << " TL" << endl;
            cout << "Adet: " << tup.adet << " adet" << endl;
        }
    } else {
        cout << "Kayýt bulunamadý..." << endl;
    }

    oku.close();
}


void TupArama() {
    ifstream oku("tupverileri.dat", ios::binary);
    oku.seekg(0, ios::end);
    int kayits = oku.tellg() / sizeof(tup);
    
    cout << "Aramak istediðiniz tüp numarasýný giriniz: ";
    int arananNumara;
    cin >> arananNumara;

    if (kayits > 0) {
        int bulundu = 0;
        for (int i = 0; i < kayits; i++) {
            oku.seekg(i * sizeof(tup));
            oku.read((char*)&tup, sizeof(tup));

            if (tup.numara == arananNumara) {
                cout << "Bulunan Tüp Bilgileri" << endl;
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
            cout << "Tüp bulunamadý." << endl;
        }
    } else {
        cout << "Kayýt bulunamadý..." << endl;
    }

    oku.close();
}


void TupSil() {
    ifstream oku("tupverileri.dat", ios::binary);
    ofstream yaz("temp.dat", ios::binary);
    oku.seekg(0, ios::end);
    int kayits = oku.tellg() / sizeof(tup);
    
    cout << "Silmek istediðiniz tüp numarasýný giriniz: ";
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
        cout << "Tüp baþarýyla silindi." << endl;
    } else {
        cout << "Tüp bulunamadý." << endl;
    }
}


void TupDuzenle() {
    ifstream oku("tupverileri.dat", ios::binary);
    ofstream yaz("temp.dat", ios::binary);
    oku.seekg(0, ios::end);
    int kayits = oku.tellg() / sizeof(tup);
    
    cout << "Düzenlemek istediðiniz tüp numarasýný giriniz: ";
    int duzenlenecekNumara;
    cin >> duzenlenecekNumara;

    bool bulundu = false;
    for (int i = 0; i < kayits; i++) {
        oku.seekg(i * sizeof(tup));
        oku.read((char*)&tup, sizeof(tup));

        if (tup.numara == duzenlenecekNumara) {
            cout << "Mevcut Tüp Bilgileri" << endl;
            cout << "Marka: " << tup.marka << endl;
            cout << "Numara: " << tup.numara << endl;
            cout << "Doluluk Durumu: " << tup.dolulukDurumu << endl;
            cout << "Fiyat: " << tup.fiyat << " TL" << endl;
            cout << "Adet: " << tup.adet << " adet" << endl;

           
            cout << "\nYeni Tüp Bilgilerini Giriniz" << endl;
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
        cout << "Tüp bilgileri baþarýyla güncellendi." << endl;
    } else {
        cout << "Tüp bulunamadý." << endl;
    }
}

