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

    bool puoi_continuare(){
        if(hai_vinto || numero_mosse >= NUMERO_MOSSE_CONSENTITE)
            return false;
        return true;
    }

    void situazione_finale(){
        if(hai_vinto)
            std::cout << "Hai vinto in " << numero_mosse << " mosse!" << std::endl;
        else{
            std::cout << "Hai perso, il codice segreto e': ";
            for (id_t i = 0; i < DIM_GIOCATA_VALIDA; i++)
            {
                std::cout << codice_segreto[i];
            }
            std::cout << std::endl;
        }
            
    }


};