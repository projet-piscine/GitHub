#include "Sommet.h"

Sommet::Sommet(std::string id,double x,double y)
        :m_id{id},m_x{x},m_y{y}
{}

Sommet::Sommet()
{}

std::string Sommet::getId()
{
return m_id;
}

double Sommet::getX()
{
return m_x;
}

double Sommet::getY()
{
return m_y;
}

void Sommet::dessiner(Svgfile& a)
{
    a.addDisk(m_x, m_y, 20, Couleur(255,255,255));
    a.addCircle(m_x, m_y, 20,1, Couleur(0,0,0));
    a.addText(m_x-4.5,m_y+5,m_id,Couleur(0,0,0));
}
