#include "Graphe.h"
#include "algorithm"
#include <iostream>
#include <fstream>
Graphe::Graphe(int taille)
    :m_taille{taille}
{

    for(size_t i=0; i<taille; ++i)
    {
        m_affichage.push_back(1);
    }
}



Graphe::Graphe(std::vector<bool> affichage)
    :m_affichage{affichage}
{}

void Graphe::allGraphe()
{
/// on aura deja chargé m_sommets et m_aretes
/// compteur binaire
/// pour chaque valeur de ce compteur, on crée un nouveau graphe différent et on le stock dans un vector<Graphe*>

    unsigned int taille = m_aretes.size();
    //unsigned int taille = 12;
    unsigned int cpt=0;
    unsigned int cpt1=0;
    unsigned int cpt2=0;




    copie_m_affichage = m_affichage;

    for(size_t n=0; n<pow(2,taille); ++n) /// nombre d'etapes
    {


        for(size_t i=0; i<taille; ++i)              /// Un tour de compteur binaire, on change ou non bit par bit
        {
            if(i==0)
            {

                if(m_affichage[i]==0)
                {
                    copie_m_affichage[i]=1;
                }
                else
                {
                    copie_m_affichage[i]=0;
                }

            }
            else if(i==1)
            {
                if(m_affichage[0]==1)
                {
                    if(m_affichage[i]==0)
                    {
                        copie_m_affichage[i]=1;
                    }
                    else
                    {
                        copie_m_affichage[i]=0;
                    }
                }
            }



            else
            {
                for(size_t j=0; j<i; ++j)
                {
                    if(m_affichage[j]==1)
                    {
                        cpt+=1;
                    }

                }

                if(cpt==i)
                {
                    if(m_affichage[i]==0)
                    {
                        copie_m_affichage[i]=1;
                    }
                    else
                    {
                        copie_m_affichage[i]=0;
                    }
                    cpt=0;
                }
                else
                {
                    copie_m_affichage[i]=m_affichage[i];
                    cpt=0;
                }

            }

        }


        m_affichage=copie_m_affichage;



        ///ICI on garde uniquement les graphes avec le bon nbr d'arete
        for(size_t i=0; i<m_affichage.size(); ++i)
        {
            if(m_affichage[i]==1)
            {
                cpt1+=1;
            }
        }
        if(cpt1==m_sommets.size()-1)
        {
            //m_graphes.push_back(new Graphe(m_affichage));


            ///ICI on verif si il y a un cycle
            std::vector<int> Connex;
            int idA,idB,valA,valB;


            for(size_t k=0; k<m_aretes.size(); ++k) //tableau de connexité
            {
                Connex.push_back(k);
            }

            for(size_t i=0; i<m_aretes.size(); i++)
            {

                if(m_affichage[i]==1)
                {
                    idA = m_aretes[i]->getA().getId();
                    idB = m_aretes[i]->getB().getId();
                    valA = Connex[idA];
                    valB = Connex[idB];

                    if(valA!=valB)
                    {
                        for(size_t j=0; j<Connex.size(); ++j) //tout ce qui a cette valeur2 prend la valeur1
                        {
                            if(Connex[j]==valB) //tout ce qui a cette valeur2 prend la valeur1
                            {
                                Connex[j]=valA;
                            }
                        }

                        cpt2+=1; //compte le nbr d'arete qui ne forment pas de cycle

                        if(cpt2==m_sommets.size()-1)
                        {
                            m_graphes.push_back(new Graphe(m_affichage));
                        }

                    }

                }
            }


        }
        cpt1 =0;
        cpt2 =0;


    }




}

std::vector<bool> Graphe::getAffichage()
{
    return m_affichage;
}

void Graphe::charger(std::string nomFichier,std::string nomFichierPoids)
{
    int indiceS,indiceA;
    double sommet_X, sommet_Y;
    double nb_Sommet, nb_Arete, nb_cout;
    double indiceSommetA, indiceSommetB, cout1, cout2;
    Sommet* sommetA;
    Sommet* sommetB;
    Sommet SommetA, SommetB;
    int cpt=0;
    int cpt1=0;
    double tampon;


    std::ifstream monFlux(nomFichier.c_str());


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
            std::ifstream monFlux(nomFichier.c_str());


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



            std::ifstream monFlux1(nomFichierPoids.c_str());

            if(monFlux1)
            {
                monFlux1 >> nb_Arete;
                monFlux1 >> nb_cout;


                for(int i=0; i< cpt1; ++i)
                {
                    monFlux1 >> tampon;
                }
                monFlux1 >> indiceA;
                ++cpt1;
                monFlux1 >> cout1;
                ++cpt1;
                monFlux1 >> cout2;
                ++cpt1;



                m_aretes.push_back(new Arete(indiceA, SommetA, SommetB, cout1, cout2, m_affichage[i]));






            }

            else
                std::cout << "ERREUR :IMPOSSIBLE D'OUVRIR LE FICHIER 2" << std::endl;
        }
    }

    else
        std::cout << "ERREUR :IMPOSSIBLE D'OUVRIR LE FICHIER 1" << std::endl;

}





void Graphe::trierPoids1()
{
    std::sort(m_aretes.begin(), m_aretes.end(),[](Arete* a, Arete* b)
    {
        return a->getCout1() < b->getCout1();
    });
}

void Graphe::trierPoids2()
{
    std::sort(m_aretes.begin(), m_aretes.end(), [](Arete* a, Arete* b)
    {
        return a->getCout2() < b->getCout2();
    });
}

float Graphe::sommeCout1(std::vector<bool> affichage)
{
    m_sommeCout1=0;

    for(size_t i=0; i<affichage.size(); ++i)
    {

        if(affichage[i]==1)
        {
            m_sommeCout1 += m_aretes[i]->getCout1();
        }

    }

    return m_sommeCout1;
}


float Graphe::sommeCout2(std::vector<bool> affichage)
{
    m_sommeCout2=0;

    for(size_t i=0; i<affichage.size(); ++i)
    {

        if(affichage[i]==1)
        {
            m_sommeCout2 += m_aretes[i]->getCout2();
        }

    }

    return m_sommeCout2;
}


void Graphe::StockerAllGraphe ()
{
    std::string const nomFichier("pareto.txt");
    std::ofstream monFlux(nomFichier.c_str());
    std::vector<bool> binaire;



    if(monFlux)
    {

        for(size_t i=0; i<m_graphes.size(); ++i)
        {
            monFlux << "'" ;
            binaire = m_graphes[i]->getAffichage();
            for(size_t i=0; i<binaire.size(); ++i)
            {
                monFlux << binaire[i];
            }

            sommeCout1(binaire);
            sommeCout2(binaire);
            monFlux << "\t";
            monFlux << m_sommeCout1;
            monFlux << "\t";
            monFlux << m_sommeCout2 << std::endl;




        }
    }
}
void Graphe::ParetoOpti()
{
    std::vector<bool> binaire;
    std::vector<bool> binaireMini;
    std::vector<bool> binaireOpti;
    std::vector < std::vector <bool> >Pareto;
    float sommeTotale,m_sommeCout1Mini,m_sommeCout2Mini, m_sommeCout1Opti,m_sommeCout2Opti;
    float sommeTotaleMini=999999999;
    bool estMeilleur;


    for(size_t i=0; i<m_graphes.size(); ++i) //tour de boucle pour determiner la solution optimale
    {
        binaire = m_graphes[i]->getAffichage();
        sommeCout1(binaire);
        sommeCout2(binaire);
        sommeTotale = m_sommeCout1+m_sommeCout2;

        if(sommeTotale<sommeTotaleMini)
        {
            sommeTotaleMini=sommeTotale;
            m_sommeCout1Opti = m_sommeCout1;
            m_sommeCout2Opti = m_sommeCout2;
            binaireOpti= binaire;

        }
    }

    Pareto.push_back(binaireOpti); //solution optimale

    for(unsigned int m=0; m<binaireOpti.size();  ++m)
    {
        std::cout << binaireOpti[m];
    }
    std::cout << "  (" << m_sommeCout1Opti << "," << m_sommeCout2Opti << ")" << std::endl;

    for(size_t i=0; i<m_graphes.size(); ++i)
    {
        binaire = m_graphes[i]->getAffichage();
        sommeCout1(binaire);
        sommeCout2(binaire);
        estMeilleur = 0;

        if(m_sommeCout1 < m_sommeCout1Opti)  //si cout 1 plus petit que la solution optimale
        {
            std::cout << m_sommeCout1 << std::endl;
            m_sommeCout1Mini = m_sommeCout1;
            m_sommeCout2Mini = m_sommeCout2;
            binaireMini = binaire;

            for(size_t j=0; j<m_graphes.size(); ++j)
            {

                binaire = m_graphes[j]->getAffichage();
                sommeCout1(binaire);
                sommeCout2(binaire);

                if(m_sommeCout1 == m_sommeCout1Mini)
                {

                    if(m_sommeCout2 < m_sommeCout2Mini) //il y a meilleur pour le Cout1
                    {
                        estMeilleur = 0;
                        break;
                    }
                    else                               //il y a pas mieux que m_cout2Mini
                    {
                        if(m_sommeCout2 == m_sommeCout2Mini && binaireMini==binaire)
                        {
                                    estMeilleur = 1;
                                    for(unsigned int m=0; m<binaireMini.size();  ++m)
                                    {
                                        std::cout << binaireMini[m];
                                    }
                                    std::cout << "  (" << m_sommeCout1Mini << "," << m_sommeCout2Mini << ")" << std::endl;
                                    break;
                        }
                    }
                }

            }

            if(estMeilleur)
                Pareto.push_back(binaireMini);
        }

        else if(m_sommeCout2 < m_sommeCout2Opti)
        {
            m_sommeCout1Mini = m_sommeCout1;
            m_sommeCout2Mini = m_sommeCout2;
            binaireMini=binaire;

            for(size_t j=0; j<m_graphes.size(); ++j)
            {
                binaire = m_graphes[j]->getAffichage();
                sommeCout1(binaire);
                sommeCout2(binaire);

                if(m_sommeCout2 == m_sommeCout2Mini)
                {
                    if(m_sommeCout1 < m_sommeCout1Mini) //il y a meilleur pour le Cout1
                    {
                        estMeilleur = 0;
                        break;
                    }

                    else                                //il y a pas mieux que m_cout2Mini
                    {
                        if(m_sommeCout1 == m_sommeCout1Mini && binaireMini == binaire)
                        {

                                    estMeilleur = 1;

                                    for(unsigned int m=0; m<binaireMini.size();  ++m)
                                    {
                                        std::cout << binaireMini[m];
                                    }
                                    std::cout << "  (" << m_sommeCout1Mini << "," << m_sommeCout2Mini << ")" << std::endl;
                                    break;



                        }
                    }
                }


            }

            if(estMeilleur) Pareto.push_back(binaireMini);
        }
    }

}


        void Graphe::dessinerKruskal(Svgfile& a)
        {
            std::vector<Arete*> copie_m_aretes;
            std::vector<int> Connex;
            int idA,idB,valA,valB;


            for(size_t i=0; i<m_aretes.size(); i++)
            {
                Connex.push_back(i);
            }

            for(size_t i=0; i<m_aretes.size(); i++)
            {


                for(size_t i=0; i<Connex.size(); i++)
                {
                    //    std::cout << "i"<<i<<" = "<<Connex[i]<< std::endl;
                }


                idA = m_aretes[i]->getA().getId();
                idB = m_aretes[i]->getB().getId();
                //   std::cout << std::endl<<"idA = "<<idA  ;
                //  std::cout << "      idB = "<<idB;
                valA = Connex[idA];
                valB = Connex[idB];


                if(valA!=valB)
                {
                    for(size_t j=0; j<Connex.size(); ++j) //tout ce qui a cette valeur2 prend la valeur1
                    {
                        if(Connex[j]==valB) //tout ce qui a cette valeur2 prend la valeur1
                        {
                            Connex[j]=valA;
                        }
                    }

                    copie_m_aretes.push_back(m_aretes[i]);
                    //std::cout << "       OK"<< std::endl<< std::endl;

                }
                //else  std::cout << "    NOK"<< std::endl<< std::endl;

            }





            for(size_t i=0; i < copie_m_aretes.size(); ++i)
            {
                copie_m_aretes[i]->dessinerKruskal(a);
            }


            for(size_t i=0; i < m_sommets.size(); ++i)
            {
                m_sommets[i]->dessiner(a);
            }

        }


        void Graphe::dessiner(Svgfile& a)
        {

            for(size_t i=0; i < m_aretes.size(); ++i)
            {

                if(m_aretes[i]->getAffiche()==1)
                {
                    m_aretes[i]->dessiner(a);
                }
            }

            for(size_t i=0; i < m_sommets.size(); ++i)
            {
                m_sommets[i]->dessiner(a);
            }
        }



