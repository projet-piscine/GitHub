#include "Graphe.h"

Graphe::Graphe()
{}


void Graphe::charger()
{
    std::string indiceS,indiceA;
    double sommet_X, sommet_Y;
    double nb_Sommet, nb_Arete, nb_cout;
    double indiceSommetA, indiceSommetB, cout1, cout2;
    Sommet* sommetA;
    Sommet* sommetB;
    Sommet SommetA, SommetB;
    int cpt=0;
    int cpt1=0;
    double tampon;


    std::ifstream monFlux("manhattan.txt");

    if(monFlux)
    {
        monFlux >> nb_Sommet;
        ++cpt;

        for (int i=0; i<nb_Sommet; i++)
        {
            monFlux >> indiceS;
            ++cpt;
            monFlux >> sommet_X;
            ++cpt;
            monFlux >> sommet_Y;
            ++cpt;

            m_sommets.push_back(new Sommet(indiceS, sommet_X, sommet_Y));

        }

        monFlux >> nb_Arete;
        ++cpt;

        std::vector <int> lien;


        for(int i=0; i<nb_Arete; i++)

        {
            std::ifstream monFlux1("manhattan_weights_0.txt");
            std::ifstream monFlux("manhattan.txt");

            for(int i=0; i< cpt; ++i)
            {
                monFlux >> tampon; ///revenir à l'endroit ou on avait quitté le ficher
            }




            monFlux >> indiceA;
            ++cpt;
            monFlux >> indiceSommetA;
            ++cpt;
            monFlux >> indiceSommetB;
            ++cpt;

            sommetA = m_sommets[indiceSommetA];
            SommetA = *sommetA;
            sommetB = m_sommets[indiceSommetB];
            SommetB = *sommetB;





            if(monFlux1)
            {
                std::ifstream monFlux1("manhattan_weights_0.txt");
                monFlux1 >> nb_Arete;
                monFlux1 >> nb_cout;


            for(int i=0; i< cpt1; ++i)
            {
                monFlux1 >> tampon;
            }
                    monFlux1 >> tampon;
                    ++cpt1;
                    monFlux1 >> cout1;
                    ++cpt1;
                    monFlux1 >> cout2;
                    ++cpt1;

                    m_aretes.push_back(new Arete(indiceA, SommetA, SommetB, cout1, cout2));

            }

            else
                std::cout << "ERREUR :IMPOSSIBLE D'OUVRIR LE FICHIER 2" << std::endl;
        }


     }

else
    std::cout << "ERREUR :IMPOSSIBLE D'OUVRIR LE FICHIER 1" << std::endl;

}

void Graphe::Kruskal()
{


/// tri de m_aretes par cout croissant

std::vector<Arete*> copie_m_arete = m_aretes;
std::vector<Arete*> m_arete_trie;


for(size_t i=0; i<sizeof m_sommets-1;i++)
{
 //   m_arete[i].getID
}

}
void Graphe::dessiner(Svgfile& a)
{
    for(size_t i=0; i < m_aretes.size(); ++i)
    {
        m_aretes[i]->dessiner(a);
    }

    for(size_t i=0; i < m_sommets.size(); ++i)
    {
        m_sommets[i]->dessiner(a);
    }
}
