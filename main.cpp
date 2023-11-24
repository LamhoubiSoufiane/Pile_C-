#include "main.hpp"
#include "pile2.cpp"

int main()
{
    int x=0;
    pile2 p1(5);
    pile2 p11(5);
    pile2 p2(8);
    pile2 p3(13);
    p1<<2;
    p1<<3;
    p1<<4;
    p1<<9;
    p1<<25;
    cout<<"\n/******************** p 1 *************/  \n";
    p1.afficher(p1);
    p2<<20;
    p2<<33;
    p2<<40;
    cout<<"\n/******************** p 2 *************/  \n";
    p2.afficher(p2);
    cout<<"\n/*************** p11 = p 1******************/\n";
    p11=p1;
    p11.afficher(p11);
    cout<<"\n/************ p3 = p1+p2*********************/\n";
    p3=p1+p2;
    p3.afficher(p3);
}