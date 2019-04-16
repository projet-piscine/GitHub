#include "arete.h"

Arete::Arete(std::string id, Sommet A, Sommet B, float coutA, float coutB)
        :m_id{id}, m_A{A}, m_B{B}, m_coutA{coutA} , m_coutB{coutB}

{
testK = m_id;
}

std::string Arete::getId()
{
return m_id;
}

void Arete::dessiner(Svgfile& a)
{
    a.addLine(m_A.getX(), m_A.getY(), m_B.getX(), m_B.getY(), Couleur(0,0,0));
    a.addText((m_A.getX()+ m_B.getX())/2,((m_A.getY()+ m_B.getY())/2)-5,m_id,Couleur(0,0,0)); //indice arete
    a.addText(((m_A.getX()+ m_B.getX())/2)-20,((m_A.getY()+ m_B.getY())/2)+20,m_coutA,Couleur(0,0,0)); //coutA
    a.addText(((m_A.getX()+ m_B.getX())/2)+20,((m_A.getY()+ m_B.getY())/2)+20,m_coutB,Couleur(0,0,0)); //coutB

}
