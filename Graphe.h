#include "Arete.h"
#include "Sommet.h"
#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED

class Graphe
{
public:

Graphe(int taille);
Graphe(std::vector<bool> affichage);


void allGraphe();
void dessiner(Svgfile& a);
void dessinerKruskal(Svgfile& a);
void charger(std::string nomFichier, std::string nomFichierPoids);
void trierPoids1();
void trierPoids2();
void StockerAllGraphe ();
void ParetoOpti();

float sommeCout1(std::vector<bool> affichage);
float sommeCout2(std::vector<bool> affichage);

std::vector<bool> getAffichage();

private:

    std::vector<Sommet*> m_sommets;
    std::vector<Arete*> m_aretes;
    std::vector<Arete*> copie_m_aretes;
    std::vector<bool> m_affichage;
    std::vector<bool> copie_m_affichage;
    std::vector<Graphe*> m_graphes;
    float m_sommeCout1;
    float m_sommeCout2;
    int m_taille;



#endif // GRAPHE_H_INCLUDED
};
