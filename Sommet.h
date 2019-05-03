#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "svgfile.h"
#include "Couleur.h"


class Sommet
{
    public:
Sommet(int id,double x,double y);
void dessiner(Svgfile& a);
void afficher();

Sommet();

int getId();
double getX();
double getY();
void setId(int id);


    private:

int m_id; // Identifiant
double m_x, m_y; // Position





};



#endif // SOMMET_H_INCLUDED
