#include "polynomial.h"
#include "integralTaktentu.h"
#include <math.h>
#include <iostream>
#include <sstream>
using namespace std;

string integralTaktentu(Polynomial poly) {
    stringstream ss;
    int i, j;
    ss << endl;

    ss << endl;
    ss << "Hasil integral tak tentunya adalah: ";
    for (i = poly.suku; i > 0; i--) {
        int panginteg = poly.pang[i] + 1;
        if (poly.pang[i] != -1) {
            if (poly.koef[i] != 0) {
                if (poly.koef[i] % panginteg != 0) {
                    ss << "(" << poly.koef[i] << "/" << poly.pang[i] + 1 << ")";
                    if (poly.pang[i] != -1) {
                        ss << poly.var << "^" << poly.pang[i] + 1;
                    }
                }
                else {
                    if (poly.koef[i] % panginteg != 1) {
                        ss << poly.koef[i] / (poly.pang[i] + 1);
                    }
                    if (poly.pang[i] != -1) {
                        ss << poly.var << "^" << poly.pang[i] + 1;
                    }
                }

            }
        }

        if (poly.pang[i] == -1) {
            ss << poly.koef[i] << "ln(|" << poly.var << "|)";
        }

        if (poly.koef[i - 1] != 0) {
            ss << "+";
        }
    }
    ss << "C";

    return  ss.str();
}