#include <iostream>
#include <string.h>
using namespace std;

class FiguraGeometrica{
public: int base, altezza;
public: int calcolaAreaRettangolo();
public: int calcolaAreaTriangolo();
};

class Rettangolo : public FiguraGeometrica{
public: int calcolaAreaRettangolo(){
int areaRettengolo;
cout <<"Inserisci il valore di una base per il rettangolo \n";
cin >> base;
cout <<"Inserisci il valore dell\'altezza per il rettangolo \n";
cin >> altezza;
areaRettengolo = base * altezza;
cout << areaRettengolo;
}
};

class Triangolo : public FiguraGeometrica{
public: int calcolaAreaTriangolo(){
int areaTriangolo;
cout <<"Inserisci un valore di una base per il triangolo \n";
cin >> base;
cout <<"Inserisci un valore altezza per il triangolo \n";
cin >> altezza;
areaTriangolo = (base * altezza)/2;
cout << areaTriangolo;
}
};

int main(){
Rettangolo r1,r2;
Triangolo t1;

r1.calcolaAreaRettangolo();
r2.calcolaAreaRettangolo();

t1.calcolaAreaTriangolo();
return 0;
}

