#include "arete.h"

Arete::Arete(int id, Sommet A, Sommet B, float cout1, float cout2, bool affiche)
        :m_id{id}, m_A{A}, m_B{B}, m_cout1{cout1} , m_cout2{cout2}, m_affiche{affiche}

{}

int Arete::getId()
{
return m_id;
}

Sommet Arete::getA()
{
    return m_A;
}

Sommet Arete::getB()
{
    return m_B;
}

 float Arete::getCout1()
{
return m_cout1;
}

 float Arete::getCout2()
{
return m_cout2;
}

bool Arete::getAffiche()
{
    return m_affiche;
}
void Arete::setAffiche(bool affiche)
{
    m_affiche = affiche;
}
void Arete::afficherData()
{
    /*std::cout << "coord S1:" << "\n";
    std::cout << "id:" << m_A.getId() << "\n";
    std::cout << "Y:" << m_A.getY() << "\n";
    std::cout << "X:" << m_A.getX() << "\n" << std::endl;

    std::cout << "coord S2:" << "\n";
    std::cout << "id:" << m_B.getId() << "\n";
    std::cout << "Y:" << m_B.getY() << "\n";
    std::cout << "X:" << m_B.getX() << "\n" << std::endl;*/

    std::cout << "donnees Arete:" << "\n";
    std::cout << "id:" << m_id << "\n";
    /*std::cout << "poid 1:" << m_coutA << "\n";
    std::cout << "poid 2:" << m_coutB << "\n" << std::endl;*/
}

void Arete::dessiner(Svgfile& a)
{

    a.addLine(m_A.getX(), m_A.getY(), m_B.getX(), m_B.getY(), Couleur(0,0,0)); //ligne
    a.addText((m_A.getX()+ m_B.getX())/2,((m_A.getY()+ m_B.getY())/2)-5,m_id,Couleur(0,0,0)); //indice arete

    a.addText(((m_A.getX()+ m_B.getX())/2)-10,((m_A.getY()+ m_B.getY())/2)+15,m_cout1,Couleur(125,125,125)); //coutA
    a.addText(((m_A.getX()+ m_B.getX())/2)+10,((m_A.getY()+ m_B.getY())/2)+15,m_cout2,Couleur(125,125,125)); //coutB
    a.addText(((m_A.getX()+ m_B.getX())/2)-15,((m_A.getY()+ m_B.getY())/2)+15,"( ",Couleur(125,125,125)); //parenthese
    a.addText(((m_A.getX()+ m_B.getX())/2),((m_A.getY()+ m_B.getY())/2)+15," ,",Couleur(125,125,125));  //virgule
    a.addText(((m_A.getX()+ m_B.getX())/2)+15,((m_A.getY()+ m_B.getY())/2)+15," )",Couleur(125,125,125)); //parenthese
  /*
    a.addText(500,500," Somme Cout1 = ",Couleur(0,0,0));
    a.addText(500,500,m_cout1,Couleur(0,0,0));
    a.addText(500,520," Somme Cout2 = ",Couleur(0,0,0));
    a.addText(500,500,m_cout2,Couleur(0,0,0));
    */

}

void Arete::dessinerKruskal(Svgfile& a)
{
    a.addLine(m_A.getX(), m_A.getY(), m_B.getX(), m_B.getY(), Couleur(255,0,0));
}
