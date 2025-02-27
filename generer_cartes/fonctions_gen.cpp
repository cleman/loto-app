#include "fonctions_gen.hpp"

#include <iostream>
#include <fstream>

LOTO_CARTES::LOTO_CARTES() {
    std::cout << "Objet créé" << std::endl;

    // Vider la liste des cartes
    cartes.clear();
}

// Fonctions de génération de n cartes genererCartes
void LOTO_CARTES::genererCartes(int n) {
    // Vérifier si n est inférieur ou égal à 0
    if (n <= 0) {
        std::cout << "Erreur : n doit être supérieur à 0" << std::endl;
        return;
    }

    // Générer n cartes
    for (int i = 0; i < n; i++) {
        // Générer un numéro de carte aléatoire entre 1 et 90
        int l1 = rand() % 84;
        int l2 = rand() % 84;
        int l3;
        if (l1 == l2) {
            l3 = rand() % 83;
            if (l3 == l1) l3 = (l3+1)%84;
        }
        else l3 = rand() % 84;

        std::vector<int> numeros;

        int x;
        for (int j = 0; j < 3; j++) {
            for (int i = 0; i < 9; i++) {
                if (i != 8) x = rand() % 9 + 1;
                else x = rand() % 10 + 1;

                x += 10*i;

                numeros.push_back(x);
            }
        }
        
        // Ajouter la carte à la liste
        cartes.push_back(numeros);
        }

}

void LOTO_CARTES::sauvCartes(const std::string& filename) {
    std::cout << "Sauvegarde carte" << std::endl;

    std::ofstream fichier(filename); // Ouvre le fichier en écriture (écrase le contenu existant)
    if (!fichier) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier pour sauvegarde." << std::endl;
        return;
    }

    for (const auto& carte : cartes) {
        for (size_t i = 0; i < carte.size(); ++i) {
            fichier << carte[i];
            if (i < carte.size() - 1) fichier << ";"; // Ajouter ";" sauf pour le dernier nombre
        }
        fichier << std::endl; // Nouvelle ligne pour la prochaine carte
    }

    fichier.close();
    std::cout << "Sauvegarde réussie." << std::endl;
}

// Affichage de la carte n dans le terminal
void LOTO_CARTES::afficherCartes(int n) {
    // Vérifier si n est inférieur à 1
    if (n < 1) {
        std::cout << "Erreur : n doit être supérieur ou égal à 1"<< std::endl;
        return;
    }

    // Afficher la carte n
    std::cout << "Carte " << n << " : " << std::endl;
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 9; i++) {
            std::cout << cartes[n-1][3*i+j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}