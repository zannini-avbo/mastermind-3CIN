#include <iostream>

#include "mastermind.cpp"


using namespace std;

int main(int argc, char const *argv[])
{
    mastermind prova = mastermind();
    
    cout << "Benvenuto al gioco mastermind!" << endl;

    prova.nuova_giocata();
    prova.risultato_mossa_bis();

    
    do{
        prova.nuova_giocata();
        prova.risultato_mossa();
    }while (prova.puoi_continuare());
    
    prova.situazione_finale();

    return 0;
}
