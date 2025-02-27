#include "fonctions.hpp"

#include <iostream>
#include <thread>

using namespace std;

int main(int argc, char **argv) {
    /*thread serverThread(startServer);
    
    cout << "Serveur démarré..." << endl;
    
    serverThread.join();*/

    LOTO_CARTES jeu;

    jeu.chargerCartes(1000, "db.txt");
    jeu.afficherCartes(1);

    return 0;
}