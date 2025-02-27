#include "fonctions_gen.hpp"

#include <iostream>
#include <thread>

using namespace std;

int main(int argc, char **argv) {
    /*thread serverThread(startServer);
    
    cout << "Serveur démarré..." << endl;
    
    serverThread.join();*/

    if (argc != 2) {
        cout << "Veuillez entrer le nombre de cartes souhaitées : ./main <nombre_de_cartes>" << endl;
        return 0;
    }

    // deuxième élément est le nombre de cartes
    int nbCartes = atoi(argv[1]);

    LOTO_CARTES jeu;

    jeu.genererCartes(nbCartes);
    jeu.afficherCartes(1);
    jeu.sauvCartes("db.txt");

    return 0;
}