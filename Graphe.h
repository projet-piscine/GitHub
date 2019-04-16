#include "Arete.h"
#include "Sommet.h"
#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED

class Graphe
{
public:

Graphe();

void dessiner(Svgfile& a);
void charger();
//void Kruskal(Cout);



private:

    std::vector<Sommet*> m_sommets;
    std::vector<Arete*> m_aretes;
    std::vector<Graphe*> m_graphes;

//    float m_cout;

#endif // GRAPHE_H_INCLUDED
};
