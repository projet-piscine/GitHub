#include "couleur.h"
#include "svgfile.h"
#include "util.h"
#include <iostream>

Couleur::Couleur(uint8_t rouge, uint8_t vert, uint8_t bleu) //Une couleur est un triplet RGB
    : m_rouge{rouge}, m_vert{vert}, m_bleu{bleu}
{ }


Couleur::Couleur()
    : Couleur(0, 0, 0) // Délégation de constructeur
{ }

uint8_t Couleur::Getm_rouge() //pour recuperer la valeur en rouge d'un objet
{
    return m_rouge;
}
uint8_t Couleur::Getm_vert() //pour recuperer la valeur en vert d'un objet
{
    return m_vert;
}
uint8_t Couleur::Getm_bleu() //pour recuperer la valeur en bleu d'un objet
{
    return m_bleu;
}

void Couleur::Setm_rouge(uint8_t rouge) //pour changer la valeur en rouge d'un objet
{
    m_rouge = rouge;
}
void Couleur::Setm_vert(uint8_t vert) //pour changer la valeur en vert d'un objet
{
    m_vert= vert;

}
void Couleur::Setm_bleu(uint8_t bleu) //pour changer la valeur en bleu d'un objet
{
    m_bleu= bleu;
}
void Couleur::afficher() const //affichage du triplet de couleur
{
    std::cout << "(" << (int)m_rouge << ", " << (int)m_vert << ", " << (int)m_bleu << ")" <<  std::endl;
}

uint8_t saisirCanal()//blindage de la saisie
{
    int val;
    std::cin >> val;
    while (val<0 || val>255)
    {
        std::cout << "Mauvaise valeur couleur, recommencer : ";
       // util::videCin();
        std::cin >> val;
    }

    return (uint8_t)val;
}

void Couleur::saisir()
{
    std::cout << "Veuillez saisir rouge vert et bleu SVP : "; //saisie du triplet
    m_rouge = saisirCanal();
    m_vert = saisirCanal();
    m_bleu = saisirCanal();
}

Couleur::operator std::string() const
{
    return Svgfile::makeRGB(m_rouge, m_vert, m_bleu);
}
