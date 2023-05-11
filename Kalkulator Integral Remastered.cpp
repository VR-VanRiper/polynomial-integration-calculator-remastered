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
    cout << "******************** BY KELOMPOK 2 *********************** \n";
    int pilInteg;
    char ulangpilInteg;

pilpolIntegral:
    do {
        cout << endl;
        cout << "Masukkan pilihan Integral untuk bentuk polinomial satu variabel: \n";
        cout << "1. Integral tak tentu \n";
        cout << "2. Integral tentu \n";
        cout << "Masukkan 0 untuk membatalkan pilihan. \n";
        cout << "Masukkan 69 untuk mengakses perhitungan. \n";
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
            string result1 = integralTaktentu(polynomial());
            cout << result1;
            ofstream outfile("output.txt", ios::app);
            outfile << result1;
            outfile.close();
            break;
        }
        case 2:
        {
            cout << endl;
            cout << "Anda memilih *Integral tentu*";
            string result2 = integralTentu(polynomial());
            cout << result2;
            ofstream outfile("output.txt", ios::app);
            outfile << result2;
            outfile.close();
            break;
        }
        case 69:
            {
            cout << endl;
            cout << "Anda memilih untuk mengakses perhitungan.";
            ifstream myFile;
            char text;
            myFile.open("output.txt");
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

