#ifndef FONCTIONS_GEN_HPP
#define FONCTIONS_GEN_HPP

#include <string>
#include <vector>

class LOTO_CARTES {
    private:
        std::vector<std::vector<int>> cartes;
    
    public:
        LOTO_CARTES();
        void genererCartes(int n);
        void sauvCartes(const std::string& filename);
        void afficherCartes(int n);
};

#endif