//
//  FractionZ.h
//  FractionZ
//
//  Created by Arthur Robert on 03/09/2015.
//  Copyright (c) 2015 Arthur Robert. All rights reserved.
//

#ifndef __FractionZ__FractionZ__
#define __FractionZ__FractionZ__

#include <stdio.h>
#include <iostream>

class FractionZ{
public:
    FractionZ(int firstNumber  , int secondNumber );
    
    void display(std::ostream& flux) const;
    
    
    bool estEgal(FractionZ const& autre) const;
    bool estPlusPetitQue(FractionZ const& autre) const;
    double nombreReel() const;
    
    FractionZ& operator+=(const FractionZ &Fraction);
    FractionZ& operator-=(FractionZ const& autre);
    FractionZ& operator*=(FractionZ const& autre);
    FractionZ& operator/=(FractionZ const& autre);
    
private:
    void simplify();
    void sign();
    
    int m_firstNumber;
    int m_secondNumber;
    
};
std::ostream& operator<<(std::ostream& flux, FractionZ const& frac);
bool operator==(FractionZ const& a, FractionZ const& b);
bool operator!=(FractionZ const& a, FractionZ const& b);
bool operator<(FractionZ const& a, FractionZ const& b);
bool operator>(FractionZ const& a, FractionZ const& b);
bool operator<=(FractionZ const& a, FractionZ const& b);
bool operator>=(FractionZ const& a, FractionZ const& b);

FractionZ operator+(FractionZ const& a,FractionZ const& b);
FractionZ operator*(FractionZ const& a,FractionZ const& b);
FractionZ operator-(FractionZ const& a,FractionZ const& b);
FractionZ operator/(FractionZ const& a,FractionZ const& b);

int pgcd(int a , int b);
#endif /* defined(__FractionZ__FractionZ__) */
