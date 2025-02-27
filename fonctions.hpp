#ifndef FONCTIONS_HPP
#define FONCTIONS_HPP

#include <vector>
#include <iostream>

class LOTO_CARTES {
    private:
        std::vector<std::vector<int>> cartes;
    public:
        LOTO_CARTES(); // Déclaration du constructeur
        void chargerCartes(int n, const std::string& filename); // Déclaration de la fonction pour générer les cartes
        void afficherCartes(int n);
};

#endif