#ifndef COULEUR_H_INCLUDED
#define COULEUR_H_INCLUDED

#include <string>
#include <cstdint>

class Couleur
{
    public :
        Couleur(uint8_t rouge, uint8_t vert, uint8_t bleu);
        Couleur();
        void afficher() const;
        void saisir();

        operator std::string() const;

        uint8_t Getm_rouge();
        uint8_t Getm_vert();
        uint8_t Getm_bleu();

        void Setm_rouge(uint8_t rouge);
        void Setm_vert(uint8_t vert);
        void Setm_bleu(uint8_t bleu);

    private :
        // uint8_t équivalent à unsigned char :
        // unsigned 8 bits (8 bits non signé)
        uint8_t m_rouge, m_vert, m_bleu;
};

#endif // COULEUR_H_INCLUDED
