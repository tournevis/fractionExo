//
//  FractionZ.cpp
//  FractionZ
//
//  Created by Arthur Robert on 03/09/2015.
//  Copyright (c) 2015 Arthur Robert. All rights reserved.
//


#include <iostream>
#include "FractionZ.h"
using namespace std;



FractionZ::FractionZ( int firstNumber , int secondNumber) : m_firstNumber(firstNumber), m_secondNumber(secondNumber){
    simplify()  ;
}
/*FractionZ::FractionZ( int entier ) : m_firstNumber(entier), m_secondNumber(1){
}
FractionZ::FractionZ( ) : m_firstNumber(0), m_secondNumber(1){
}*/


void FractionZ::display(ostream& flux) const
{
    if(m_secondNumber == 1)
    {
        flux << m_firstNumber;
    }
    else
    {
        flux << m_firstNumber << '/' << m_secondNumber;
    }
}

ostream& operator<<(ostream& flux, FractionZ const& fraction)
{
    fraction.display(flux);
    return flux;
}

/****  COMPARAISON  *****/


bool FractionZ::estEgal(FractionZ const& autre) const{
    return (m_firstNumber == autre.m_firstNumber && m_secondNumber == autre.m_secondNumber);

}
bool operator==(FractionZ const& a, FractionZ const& b){
    return a.estEgal(b);
}
bool operator!=(FractionZ const& a, FractionZ const& b){
    return !(a.estEgal(b));
}

bool FractionZ::estPlusPetitQue(FractionZ const& autre)const{
    if(m_firstNumber * autre.m_secondNumber < m_secondNumber * autre.m_firstNumber)
        return true;
    else
        return false;
}

bool operator<(FractionZ const& a, FractionZ const& b){
    return a.estPlusPetitQue(b);
}
bool operator>(FractionZ const& a, FractionZ const& b){
    return b.estPlusPetitQue(a);
}
bool operator<=(FractionZ const& a, FractionZ const& b){
    return !(b.estPlusPetitQue(a));
}
bool operator>=(FractionZ const& a, FractionZ const& b){
    return !(a.estPlusPetitQue(b));
}
/**** LES + *****/

FractionZ operator+(FractionZ const& a, FractionZ const& b)
{
    FractionZ copie(a);
    copie+=b;
    return copie;
}
    // operation raccourci avec des this
FractionZ& FractionZ::operator+=(FractionZ const& autre){
    
    m_firstNumber = autre.m_secondNumber * m_firstNumber + m_secondNumber *autre.m_firstNumber;
    m_secondNumber = m_secondNumber * autre.m_secondNumber;
    
    return *this;
    
}
/**** LES - *****/
FractionZ operator-(FractionZ const& a, FractionZ const& b){
    FractionZ copie(a);
    copie-=b;
    return copie;
}

FractionZ& FractionZ::operator-=(FractionZ const& autre){
    m_firstNumber = m_firstNumber* autre.m_secondNumber - autre.m_firstNumber * m_secondNumber;
    m_secondNumber *= autre.m_secondNumber;
    return *this;
}

/* MULTIPLICATION */
FractionZ operator*(FractionZ const& a, FractionZ const& b){
    FractionZ copie(a);
    copie *= b;
    return copie;
}

FractionZ& FractionZ::operator*=( FractionZ const& autre){
    
    m_firstNumber *= autre.m_firstNumber;
    m_secondNumber *= autre.m_secondNumber;
    
    return *this;
}

int pgcd(int a, int b)
{
    while (b != 0)
    {
        const int t = b;
        b = a%b;
        a=t;
    }
    return a;
};

void FractionZ::simplify(){
    int nb = pgcd(m_firstNumber, m_secondNumber);
    m_firstNumber/= nb ;
    m_secondNumber /= nb;
}