#include<iostream>
#include<cmath>
#include "Function.h"
#include "RootBiss.h"
#include "RootNR.h"

int main(){
    Function *f = new Function();
    RootBiss *biss = new RootBiss(f);
    std::cout << "RAIZ BISS:    " << biss -> findRoot() << std::endl;
    RootNR *n = new RootNR(f);
    std::cout << "RAIZ NR:    " << n -> findRoot() << std::endl;
}

