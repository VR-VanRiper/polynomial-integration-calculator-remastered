#include "polynomial.h"
#include "integralTaktentu.h"
#include "integralTentu.h"
#include "validasiInput.h"
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;



int main()
{
    cout << endl;
    cout << "********************************************************** \n";
    cout << "******* SELAMAT DATANG DI KALKULATOR KELOMPOK KAMI! ****** \n";
    cout << "******************** BY KELOMPOK 1 *********************** \n";
    int pilInteg;
    char ulangpilInteg;

pilpolIntegral:
    do {
        cout << endl;
        cout << "Masukkan pilihan Integral untuk bentuk polinomial satu variabel: \n";
        cout << "1. Integral tak tentu \n";
        cout << "2. Integral tentu \n";
        cout << "Masukkan 0 untuk membatalkan pilihan. \n";
        cout << "Masukkan 69 untuk mengakses riwayat perhitungan. \n";
        cout << "Pilihan anda: "; cin >> pilInteg;

        while (cin.fail()) {
            cout << endl;
            validasiInput();
            cout << "Masukkan invalid, coba kembali \n";
            goto pilpolIntegral;
        }


        switch (pilInteg) {
        case 1:
        {
            cout << endl;
            cout << "Anda memilih *Integral tentu*";
            integralTaktentu(polynomial());
            break;
        }
        case 2:
        {
            cout << endl;
            cout << "Anda memilih *Integral tentu*";
            integralTentu(polynomial());
            break;
        }
        case 69:
            {
            cout << endl;
            cout << "Anda memilih untuk mengakses perhitungan.";
            cout << endl << endl;
            ifstream myFile;
            char text;
            myFile.open("history.txt");
            while (!myFile.eof()) {
                myFile.get(text);
                cout << text;
            }
            myFile.close();
            break;
        }
        case 0:
            cout << endl;
            cout << "Anda membatalkan pilihan. \n";
            goto akhirkalkulasi;
        default:
            cout << endl;
            cout << "Masukkan invalid, coba kembali.";
            goto pilpolIntegral;
        }
      
        cout << endl;

    ulangkalkulasi:
        cout << endl;
        cout << "Ulangi pilihan (y/t)? ";
        cin >> ulangpilInteg;
        switch (ulangpilInteg) {
        case 'y':
            system("cls");
            break;
        case 't':
            break;
        default:
            cout << "Mohon untuk menjawab kembali dengan benar." << endl;
            goto ulangkalkulasi;
        }

    } while (ulangpilInteg != 't');


akhirkalkulasi:
    cout << endl;
    cout << "Terima kasih telah menggunakan kalkulator kami!";
    cout << endl;

    return 0;
}

