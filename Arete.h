#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED
#include <string>
#include "Sommet.h"

class Arete
{
public:

    Arete(int id, Sommet A, Sommet B, float cout1, float cout2, bool affiche);

    Arete();

    void dessiner(Svgfile& a);
    void dessinerKruskal(Svgfile& a);
    void afficherData();

    int getId();
    Sommet getA();
    Sommet getB();
    float getCout1();
    float getCout2();
    bool getAffiche();

    void setAffiche(bool affiche);


private:


    int m_id;
    Sommet m_A;
    Sommet m_B;
    float m_cout1;
    float m_cout2;
    bool m_affiche;
};

#endif // ARETE_H_INCLUDED
