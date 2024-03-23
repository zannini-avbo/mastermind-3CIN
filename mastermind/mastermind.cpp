#include <iostream>
#include <cstdlib>
#include <ctime>

class mastermind
{
private:
    static const int NUMERO_MOSSE_CONSENTITE = 9;
    int numero_mosse;
    std::string ultima_mossa;

    static const int DIM_GIOCATA_VALIDA = 4;
    int mossa_valida[DIM_GIOCATA_VALIDA];
    int codice_segreto[DIM_GIOCATA_VALIDA];

    bool hai_vinto;

    bool sanifica_input(){
        if (DIM_GIOCATA_VALIDA != ultima_mossa.size())
            return false;
        for (int i = 0; i < ultima_mossa.size(); i++)
        {
            char c = ultima_mossa[i];
            if(c >= '0' && c <= '9')
                mossa_valida[i] = c - '0';
            else if(c == '-') // il trattino verra convertio in -1
                mossa_valida[i] = -1;
            else
                return false;            
        }
        return true;
    }

    void genera_codice_segreto(){
        srand(time(NULL));
        for (int i = 0; i < DIM_GIOCATA_VALIDA; i++)
        {
            codice_segreto[i] = rand() % 10;
            std::cout << codice_segreto[i];
        }        
        std::cout << std::endl;
    }
            
    int* copia_vettore(int vettore_originale[]){

        static int vettore_copia[DIM_GIOCATA_VALIDA];

        for (int i = 0; i < DIM_GIOCATA_VALIDA; i++)
        {
            vettore_copia[i] = vettore_originale[i];
        }
        
        return vettore_copia;
    }

    void copia_vettore_bis(int vettore_originale[], int vettore_copia[], int dim_vet){
        for (int i = 0; i < dim_vet; i++)
        {
            vettore_copia[i] = vettore_originale[i];
        }
    }

public:

    mastermind(){
        numero_mosse = 0;
        ultima_mossa = "";
        hai_vinto = false;
        genera_codice_segreto();
    };

    void nuova_giocata(){
        do{
            std::cout << numero_mosse + 1  << ": ";
            std::getline(std::cin, ultima_mossa); // std::cin >> ultima_mossa; <-- non e' in grado di leggere gli spazi
        }while (!sanifica_input());
        
        numero_mosse++;
    }

    void risultato_mossa(){
        int num_ball = 0;
        int num_strike = 0;

        for (int i = 0; i < DIM_GIOCATA_VALIDA; i++)
        {
            for (int j = 0; j < DIM_GIOCATA_VALIDA; j++)
            {
                if(codice_segreto[i] == mossa_valida[j]){
                    if(i == j)
                        num_strike++;
                    else
                        num_ball++;
                }
            }
        }

        if(num_strike == DIM_GIOCATA_VALIDA)
            hai_vinto = true;        

        std::cout << "ball: " << num_ball << std::endl;
        std::cout << "strike: " << num_strike << std::endl;
    }

    void risultato_mossa_bis(){
        int strike, ball;
        strike =0;
        ball = 0;

        // Creo una copia del vettore codice_segreto per non andare a sovrascrivere il valore originale
        // vedi riga 125

        //int *codice_segreto_bis = copia_vettore(codice_segreto);

        int codice_segreto_bis[DIM_GIOCATA_VALIDA];
        copia_vettore_bis(codice_segreto, codice_segreto_bis, DIM_GIOCATA_VALIDA);

        // Cerco quanti strike e quanti ball
        for (int i = 0; i < DIM_GIOCATA_VALIDA; i++) // Uso i per iterare su mossa_valida
        {
            for (int j = 0; j < DIM_GIOCATA_VALIDA; j++) // Uso j per iterare su codice_segreto_bis
            {
                if(mossa_valida[i] == codice_segreto_bis[j]){
                    if(i == j){
                        strike++;
                    }else{
                        ball++;
                    }
                    codice_segreto_bis[j] = -2; // vedi commento riga 107
                    break; // troviamo il valore che ci serve non abbiamo bisogno di andare oltre
                }
            }
            
        }

        // Stampo il risultato della mia ricerca sul terminale
        std::cout << "Il numero di strike e': " << strike << std::endl;
        std::cout << "Il numero di ball e': " << ball << std::endl;
        
    }
    
    bool puoi_continuare(){
        
    }

    void situazione_finale(){
            
    }


};