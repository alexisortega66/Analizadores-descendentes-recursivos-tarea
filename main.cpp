/*
Manuel Alexis Ortega Macias
Sistemas Computacionales
Semestre 6
trabajo de analizadores recursivos descendientes
*/
#include<iostream>
using namespace std;

/*
  E -> E + T | T
  T -> T*F | F
  F -> (E)
*/

void E();
void T();
void F();

//cadenas que acepta
//string cadena ="+*()";
string cadena ="+*()()+*()";

//cadenas que no acepta
//string cadena ="+++*()()+*()";


int posicion=0;
bool cadenaValida=false;
int t=0, e=0;


int main(){
    cout<<"Ingresa una cadena"<<endl;
 //   cin>>cadena;

    E();
    if(cadenaValida){
        cout<<"La cadena ingresada fue Aceptada"<<endl;
    } else {
        cout<<"La cadena ingresada no fue Aceptada"<<endl;
    }

    return 0;
}

//valida que el signo de suma este bien colado dentro de la cadena
void E(){
    if(cadena.substr(posicion,1)!="+"){
        cadenaValida=false;
    } else if(cadena.substr(posicion,1) == "+"){
        e=1;
        cadenaValida=true;
        posicion++;
        T();
    } else {
        posicion++;
        T();
        E();
    }
}
//valida que haya signos de multiplicacion para que la cadena sea aceptada
void T(){
    if(cadena.substr(posicion,1)!="*"){
        cadenaValida=false;
    } else if(cadena.substr(posicion,1) == "*"){
        t=1;
        cadenaValida=true;
        posicion++;
        F();
    } else {
        posicion++;
        F();
        T();
    }
}

//valida que los parentesis esten uno seguido del otro para que la cadena pueda ser valida
void F(){
    if(cadena.substr(posicion,1) == "("){
        posicion++;
        if(cadenaValida && cadena.substr(posicion,1)==")"){
            cadenaValida=true;
        } else if(cadena.substr(posicion,1) == "i") {
            cadenaValida=true;
        } else {
            cadenaValida=false;
            F();
        }
    } else {
        cadenaValida = false;
        F();
    }
}
