#include "fonctions.hpp"

#include <string>
#include <fstream>
#include <sstream>

LOTO_CARTES::LOTO_CARTES() {
    std::cout << "Objet créé" << std::endl;

    // Vider la liste des cartes
    cartes.clear();
}

// Chargement des cartes à partir du fichier filename, sous la forme : n1;n2;...n27
void LOTO_CARTES::chargerCartes(int n, const std::string& filename) {
    // Vérifier si n est valide
    if (n <= 0) {
        std::cout << "Erreur : n doit être supérieur à 0" << std::endl;
        return;
    }

    std::ifstream fichier(filename); // Ouvrir le fichier
    if (!fichier) {
        std::cout << "Erreur : Impossible d'ouvrir le fichier " << filename << std::endl;
        return;
    }

    cartes.clear(); // Vider l'ancien contenu
    std::string ligne;
    int compteur = 0;

    while (std::getline(fichier, ligne) && compteur < n) {
        std::vector<int> carte;
        std::stringstream ss(ligne);
        std::string nombre;

        while (std::getline(ss, nombre, ';')) {
            carte.push_back(std::stoi(nombre));
        }

        cartes.push_back(carte);
        compteur++;
    }

    fichier.close();
    std::cout << "Chargement de " << cartes.size() << " cartes réussi." << std::endl;
}

// Affichage de la carte n dans le terminal
void LOTO_CARTES::afficherCartes(int n) {
    // Vérifier si n est inférieur à 1
    if (n < 1) {
        std::cout << "Erreur : n doit être supérieur ou égal à 1"<< std::endl;
        return;
    }

    for (int i = 0; i < 27; i++) {
        std::cout << cartes[n-1][i] << " ";
    }
    std::cout << std::endl;

    // Afficher la carte n
    std::cout << "Carte " << n << " : " << std::endl;
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 9; i++) {
            std::cout << cartes[n-1][i+9*j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}