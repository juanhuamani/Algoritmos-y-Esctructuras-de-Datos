#include <iostream>

using namespace std;

class Nodo{
public:
    int dato;
    int coef;
    Nodo *sig;
    Nodo(){
        sig=NULL;
    }
};

class Lista{
    Nodo *inicio;
public:
    Lista (){
        inicio=NULL;
    }
    void insertar(int dato,int coef){
        Nodo *new_nodo = new Nodo();
        new_nodo->dato =dato;
        new_nodo->coef =coef;
        
        if(inicio == NULL){
            inicio = new_nodo;
        }
        else{
            Nodo *ptr = inicio;
            Nodo *ptr_aux = NULL;
            
            while (ptr->coef > coef){
                ptr_aux = ptr;
                ptr = ptr ->sig;
            }
            
            ptr_aux->sig = new_nodo;
            new_nodo->sig = ptr;
        }
    }
    void insertar_inicio(int dato,int coef){
        Nodo *new_nodo = new Nodo();
        new_nodo->dato =dato;
        new_nodo->coef =coef;
        
        if(inicio == NULL){
            inicio = new_nodo;
        }
        else{
            new_nodo->sig = inicio;
            inicio = new_nodo;
        }
    }

    void imprimir() {
        Nodo *nodoactual = this->inicio;
        if (nodoactual != nullptr) {
            for(nodoactual=inicio;nodoactual != nullptr;nodoactual=nodoactual->sig){
                cout<<" ( "<< nodoactual->dato << " , "<< nodoactual->coef <<" ) ->";

            }
        }
        
    }
};

int main(){
    Lista lista ;
    lista.insertar(8,7);
    lista.insertar(3,8);
    lista.imprimir();
}