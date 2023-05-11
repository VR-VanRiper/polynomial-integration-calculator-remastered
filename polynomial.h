#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include "validasiInput.h"
using namespace std;

struct Polynomial {
    int suku;
    int koef[100];
    int pang[100];
    char var;
};

Polynomial polynomial();


#endif // POLYNOMIAL_H
