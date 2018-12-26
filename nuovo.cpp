#include <iostream>
#include <string>
using namespace std;

class FiguraGeometrica{
public: int base, altezza;
public: int getBase();
public: int getAltezza();
};

int FiguraGeometrica :: getBase(){
cout <<"Inserisci la base\n";
cin >> base;
cout << "per la base hai inserito il valore : "<<base<<endl;
return base;
}

int FiguraGeometrica :: getAltezza(){
cout <<"Inserisci l altezza\n";
cin >> altezza;
cout <<"Per l altezza hai inserito il valore : "<<altezza<<endl;
return altezza;
}

int main(){
FiguraGeometrica f1;
int area;
area = f1.getBase() * f1.getAltezza();
cout <<"L area risulta essere di: "<<area;
return 0;
}
