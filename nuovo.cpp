#include <iostream>
#include <string.h>
using namespace std;

class FiguraGeometrica{

public: void inserisciBase(){ cout <<"Inserisci la base della figura geometrica da analizzare\n"; }
public: void inserisciAltezza(){ cout <<"Inserisci l\' altezza della figura\n"; }

};

class Rettangolo : public FiguraGeometrica{
int base, altezza;
public: int stampaBase(int base){ return base; }
public: int stampaAltezza(int altezza){ return altezza; }
};

int main(){
Rettangolo f1;
int b,h;
int ba,al;

f1.inserisciBase();
cin >> b;
f1.inserisciAltezza();
cin >> h;

ba = f1.stampaBase(b);
al = f1.stampaAltezza(h);
cout <<ba*al;

return 0;
}

