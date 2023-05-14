#include "polynomial.h"
#include "validasiInput.h"
#include <sstream>
#include <fstream>

Polynomial polynomial() {
    Polynomial poly;
    cout << endl;
    int i, j;

kalkIntegraltaktentu:
    cout << endl;
    cout << "Masukkan jumlah suku dalam polinomial: ";
    cin >> poly.suku;
    while (cin.fail() || poly.suku <= 0) {
        validasiInput();
        cout << "Masukkan invalid, coba kembali \n";
        goto kalkIntegraltaktentu;
    }

variabelpers:
    cout << endl;
    cout << "Masukkan variabel dari polinomial: ";
    cin >> poly.var;

    if ((poly.var >= 65 && poly.var <= 90) || (poly.var >= 97 && poly.var <= 122)) {
        goto kalkulasiinter;
    }
    else {
        cout << "Masukkan invalid, coba kembali \n";
        cout << "Variabel hanya bisa berupa huruf!\n";
        cout << endl;
        goto variabelpers;
    }

kalkulasiinter:
    for (i = poly.suku; i > 0; i--) {
        cout << endl;
        cout << "Masukkan koefesien dari suku ke-" << i << " untuk variabel " << poly.var << " : ";
        cin >> poly.koef[i];
        cout << "Masukkan eksponen dari suku ke-" << i << " untuk variabel " << poly.var << " : ";
        cin >> poly.pang[i];
        while (cin.fail()) {
            cout << endl;
            validasiInput();
            cout << "Invalid input, coba kembali \n";
            cout << "Mohon untuk mengulang masukkan dari awal dengan benar! \n";
            goto kalkulasiinter;
        }
    }

    cout << endl;
    poly.ss << "Bentuk polinomialnya adalah: ";
    for (i = poly.suku; i > 0; i--) {
        if (poly.koef[i] != 0) {
            poly.ss << poly.koef[i];
            if (poly.pang[i] != 0) {
                poly.ss << poly.var << "^" << poly.pang[i];
            }
        }
        if (poly.koef[i - 1] > 0) {
            poly.ss << "+";
        }
    }

    string hasil = poly.ss.str();
    cout << hasil << endl;
    ofstream outfile("history.txt", ios::app);
    outfile << hasil;
    outfile.close();
    return poly;
}
