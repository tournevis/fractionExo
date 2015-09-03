//
//  main.cpp
//  FractionZ
//
//  Created by Arthur Robert on 03/09/2015.
//  Copyright (c) 2015 Arthur Robert. All rights reserved.
//

#include <iostream>
#include "FractionZ.h"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    
    FractionZ a(28,5);      //Déclare une fraction valant 4/5
    FractionZ b(5,10);        //Déclare une fraction valant 2/1 (ce qui vaut 2)      //Déclare deux fractions valant 0
    FractionZ c(0,0);
    FractionZ d(2,0);
    
    c = a+b;               //Calcule 4/5 + 2/1 = 14/5
    
    d = a*b;               //Calcule 4/5 * 2/1 = 8/5
    
    cout << a << " + " << b << " = " << c << endl;
    
    cout << a << " * " << b << " = " << d << endl;
    
    if(a > b)
        cout << "a est plus grand que b." << endl;
    else if(a==b)
        cout << "a est egal a b." << endl;
    else
        cout << "a est plus petit que b." << endl;
   
    return 0;
}
