#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED
#include <string>
#include "Sommet.h"

class Arete
{
public:

Arete(std::string id, Sommet A, Sommet B, float coutA, float coutB);

void dessiner(Svgfile& a);

std::string getId();

private:


std::string m_id;
std::string testK;
Sommet m_A;
Sommet m_B;
float m_coutA;
float m_coutB;
Couleur m_C;
};

#endif // ARETE_H_INCLUDED
