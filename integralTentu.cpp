#include <sstream> 
#include "polynomial.h"
#include "integralTentu.h"
#include <math.h>
#include "validasiInput.h"
string integralTentu(Polynomial poly) {
	stringstream ss;
    int i, j;

batasInteg:
    cout << endl;
    cout << endl;
    double valBawah, valAtas;
    cout << "Masukkan batas bawah: "; cin >> valBawah;

    cout << "Masukkan batas atas: ";  cin >> valAtas;

    while (cin.fail()) {
        cout << endl;
        validasiInput();
        cout << "Masukkan invalid, coba kembali \n";
        goto batasInteg;
    }


    ss << endl << endl;
    cout << "Hasil integral tentunya untuk batas bawah = " << valBawah << " dan batas atas = " << valAtas << " adalah: ";
    for (i = poly.suku; i > 0; i--) {
        int pangInteg = poly.pang[i] + 1;

       ss << "(" << poly.koef[i] << "/" << pangInteg << ")" << poly.var << "^" << pangInteg;

        if (poly.koef[i - 1] > 0) {
            ss  << "+";
        }
    }


    ss  << " = ";
    for (i = poly.suku; i > 0; i--) {
        int pangInteg = poly.pang[i] + 1;
        if (poly.pang[i] != -1) {
            ss  << "(" << poly.koef[i] << "/" << pangInteg << ")" << "(" << valAtas << ")" << "^" << pangInteg;
        }
        if (poly.pang[i] == -1) {
            ss  << poly.koef[i] << "ln" << "(" << "|" << valAtas << "|" << ")";

        }

        if (poly.koef[i - 1] > 0) {
            ss << "+";
        }
    }
    ss  << "-";
    for (i = poly.suku; i > 0; i--) {
        int pangInteg = poly.pang[i] + 1;
        if (poly.pang[i] != -1) {
            ss  << "(" << "(" << poly.koef[i] << "/" << pangInteg << ")" << "(" << valBawah << ")" << "^" << pangInteg << ")";
        }
        if (poly.pang[i] == -1) {
            ss  << poly.koef[i] << "ln" << "(" << "|" << valBawah << "|" << ")";
        }

        if (poly.koef[i - 1] > 0) {
            ss  << "+";
        }
    }


	ss  << " = ";
    double hasilIntegTentu;
    hasilIntegTentu = 0;


    for (i = poly.suku; i > 0; i--) {

        if (poly.pang[i] != -1) {
            poly.koef[i] = (poly.koef[i] / (poly.pang[i] + 1)) * pow(valAtas, poly.pang[i] + 1) - (poly.koef[i] / (poly.pang[i] + 1)) * pow(valBawah, poly.pang[i] + 1);
        }
        if (poly.pang[i] == -1) {
            poly.koef[i] = poly.koef[i] * log(valAtas) - (poly.koef[i] * log(valBawah));
        }
    }
    for (i = poly.suku; i > 0; i--) {
        hasilIntegTentu = hasilIntegTentu + poly.koef[i];
    }

    ss  << hasilIntegTentu;
	
	 return ss.str();
}