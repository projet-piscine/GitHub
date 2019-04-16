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
Sommet(std::string id,double x,double y);
void dessiner(Svgfile& a);

Sommet();

std::string getId();
double getX();
double getY();

    private:

std::string m_id; // Identifiant
double m_x, m_y; // Position




};



#endif // SOMMET_H_INCLUDED
