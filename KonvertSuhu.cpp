#include <iostream>
using namespace std;

double celciusToReamur(double cel){return  (4.0/5.0)* cel;}
double celciusToFahrenheit(double cel){return  (9.0/5.0) * cel + 32;}
double celciusToKelvin(double cel){return  cel + 273.15;}

double reamurToCelcius(double ream){return ream * (5.0/4.0);}
double reamurToFahrenheit(double ream){return (ream * 2.25) + 32;}
double reamurToKelvin(double ream){return  (ream / 0.8) + 273.15;}

double fahrenheitToCelcius(double fahren){return (fahren - 32) * 5.0/9.0;}
double fahrenheitToReamur(double fahren){return 4.0/9.0 *(fahren -32);}
double fahrenheitToKelvin(double fahren){return (fahren + 459.67) * 5.0/9.0;}

double kelvinToCelcius(double kel){return kel - 273.15;}
double kelvinToFahrenheit(double kel){return (kel - 273.15) * 9.0/5.0 + 32;}
double kelvinToReamur(double kel){return (kel - 273.15) * 4.0/5.0;}

int main(){
    int pilihAwal, pilihKonversi;
    
    double suhuAwal;

    cout<<"\n=====PROGRAM KONVERSI SUHU=====\n\n";
    cout<<"Pilih satuan awal nilai yang ingin di konversi : \n";

    string menuSuhu[4] = {"Celcius", "Fahrenheit", "Reamur", "Kelvin"};
    string *ptrMenu = menuSuhu; 

    for(int i = 0; i < 4; i++ ){
        cout<<(i+1)<<"."<<*ptrMenu<<endl;
        ptrMenu++;
    }

    cout<<"Masukkan pilihan (1-4) : ";
    cin>>pilihAwal;
    if(pilihAwal <1 || pilihAwal > 4){
        cout<<"Pilihan tidak valid, harap masukan angka antara 1-4. ";
        return 1;
    }
    
    cout<<"\nMasukkan nilai suhu : ";
    cin>>suhuAwal;

    cout<<"\nMasukkan satuan yang di tuju : \n";

    string menuKonversi[4] = {"Celcius", "Fahrenheit", "Reamur", "Kelvin"};
    string *ptrKonversi = menuKonversi;

    for(int i = 0; i < 4; i++){
        cout<<(i+1)<<"."<<*ptrKonversi<<endl;
        ptrKonversi++;
    }
    cout<<"Masukkan pilihan (1-4) : ";
    cin>>pilihKonversi;

    if(pilihKonversi <1 || pilihKonversi > 4){
        cout<<"Pilihan tidak valid, harap masukan angka antara 1-4. ";
        return 1;
    }

    double (*konversiFungsi[4][4])(double) = {
        {nullptr, celciusToFahrenheit, celciusToReamur, celciusToKelvin},
        {fahrenheitToCelcius, nullptr, fahrenheitToReamur, fahrenheitToKelvin},
        {reamurToCelcius, reamurToFahrenheit, nullptr, reamurToKelvin},
        {kelvinToCelcius, kelvinToFahrenheit, kelvinToReamur, nullptr}};

    
    double hasilKonversi = suhuAwal;
    if (pilihAwal != pilihKonversi) {
        hasilKonversi = konversiFungsi[pilihAwal - 1][pilihKonversi - 1](suhuAwal);
    }

    cout << "\nHasil konversi ke " << menuSuhu[pilihKonversi - 1] << " = " << hasilKonversi << endl;

    return 0;
}




