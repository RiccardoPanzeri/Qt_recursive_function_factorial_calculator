#include "fattoriale.h"
#include <cctype>
using namespace std;
Fattoriale::Fattoriale() {}

int Fattoriale::calcola(int n){
    if(n == 1 || n == 0){ //per convenzione, il fattoriale di 0 è 1, e il fattoriale di 1 è sempre 1.
        return 1;
    }else{
        return n * calcola(n - 1);//se n non è 1 o 0, verrà
                                  //restituito il numero passato per parametro
                                  //moltiplicato per il fattoriale del numero precedente a n.
                                  //per esempio, calcola(4) restituirà 4 (che è n) * il fattoriale di 3 ( ovvero calcola(4-1))
                                  //quindi restituirà 4 * (3*2*1);
    }
}


bool Fattoriale::isInt(char c){

    if(isdigit(c)){
        return true;
    }else{
        return false;
    }
}
