#include <iostream>
#include "graphe.h"
#include "svgfile.h"
#include <cstdlib>
#include <fstream>
#include <math.h>
void caseOptions2(std::string nomFichier, std::string nomFichierPoids)
{
    int choix3 = 0;

        std::ifstream monFlux(nomFichierPoids.c_str());
        int taille;

        if(monFlux)
        {
        monFlux >> taille;
        }

    Svgfile svgout;
    Graphe a(taille);
    a.charger(nomFichier,nomFichierPoids);

    std::cout<<"1: Generer graphe"<<std::endl
             <<"2: Generer graphe Kruskal cout 1"<<std::endl
             <<"3: Generer graphe Kruskal cout 2"<<std::endl
             <<"4: Generer Pareto"<<std::endl
             <<"0: Sortir"<<std::endl;
             std::cin>>choix3;
             system("cls");

switch(choix3)
        {
        case 1:
            a.charger(nomFichier,nomFichierPoids);
            a.dessiner(svgout);
            break;
        case 2:
            a.trierPoids1();
            a.dessinerKruskal(svgout);
            break;
        case 3:
            a.trierPoids2();
            a.dessinerKruskal(svgout);
            break;
        case 4:
            a.charger(nomFichier,nomFichierPoids);
            a.allGraphe();
            a.StockerAllGraphe();
            a.ParetoOpti();
            break;
        }


}

void Menu()
{

    int choix=0;
    int choix2=0;
    int taille;
    std::string nomFichier;
    std::string nomFichierPoids;


    std::cout << "IMPORTANT:" << std::endl
              << "Je n'arrive pas a afficher Pareto a partir de mon Menu." << std::endl
              << "Pour le tester et vous montrer que cela fonctionne, je vous invite a mettre" << std::endl
              << "la ligne ci-dessous ( Menu(); ) en commentaire et à remplacer le #if 0 par #if 1." << std::endl
              << "En m'excusant pour ce bug \n\n\n" << std::endl;

    std::cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" <<std::endl
             <<"Bienvenue dans notre Projet de Theorie de Graphes"<< std::endl
             <<"Quel graphe souhaitez vous afficher?"<< std::endl << std::endl
             <<"1: Broadway"<< std::endl
             <<"2: Triville"<< std::endl
             <<"3: Cubetown"<< std::endl
             <<"4: Manhattan"<< std::endl
             <<"0: Sortir"<<std::endl
             <<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" <<std::endl;

             do
             {
                 std::cin>>choix;
                 system("cls");
                 if (choix == 1)
                 {
                    nomFichier = "broadway.txt";
                    std::cout<<"Vous avez choisi Broadway"<< std::endl;
                    std::cout<<"3 differents choix de ponderations d'aretes"<< std::endl;
                    std::cout<<"Choisissez un nombre entre 1 et 3"<< std::endl;
                    std::cin>>choix2;
                    system("cls");


                    if (choix2 ==1)
                    {
                        nomFichierPoids="broadway_weights_0.txt";
                        caseOptions2(nomFichier, nomFichierPoids);


                    }
                    if (choix2 ==2)
                    {
                        nomFichierPoids="broadway_weights_1.txt";
                        caseOptions2(nomFichier, nomFichierPoids);
                    }
                    if (choix2 ==3)
                    {
                        nomFichierPoids="broadway_weights_2.txt";
                        caseOptions2(nomFichier, nomFichierPoids);
                    }


                 }

                 if (choix == 2)
                 {
                    nomFichier="triville.txt";
                    std::cout<<"Vous avez choisi Triville"<< std::endl;
                    std::cout<<"2 differents choix de ponderations d'aretes"<< std::endl;
                    std::cout<<"Choisissez un nombre entre 1 et 2"<< std::endl;
                    std::cin>>choix2;
                    taille = 18;
                    system("cls");

                    if (choix2 ==1)
                    {
                        nomFichierPoids="triville_weights_0.txt";
                        caseOptions2(nomFichier, nomFichierPoids);
                    }
                    if (choix2 ==2)
                    {
                        nomFichierPoids="triville_weights_1.txt";
                        caseOptions2(nomFichier, nomFichierPoids);
                    }
                 }

                 if (choix == 3)
                 {
                     std::cout<<"Vous avez choisi Cubetown"<< std::endl;
                     nomFichier="cubetown.txt";
                     nomFichierPoids="cubetown_weights_0.txt";
                     taille = 12;
                     caseOptions2(nomFichier, nomFichierPoids);

                 }

                 if (choix == 4)
                 {
                    nomFichier="manhattan.txt";
                    std::cout<<"Vous avez choisi Manhattan"<< std::endl;
                    std::cout<<"3 differents choix de ponderations d'aretes"<< std::endl;
                    std::cout<<"Choisissez un nombre entre 1 et 3"<< std::endl;

                    taille = 24;
                    std::cin>>choix2;
                    system("cls");


                    if (choix2 == 1)
                    {
                        nomFichierPoids="manhattan_weights_0.txt";
                        caseOptions2(nomFichier,nomFichierPoids);
                    }
                    if (choix2 == 2)
                    {
                        nomFichierPoids="manhattan_weights_1.txt";
                        caseOptions2(nomFichier,nomFichierPoids);
                    }
                    if (choix2 == 3)
                    {
                        nomFichierPoids="manhattan_weights_2.txt";
                        caseOptions2(nomFichier,nomFichierPoids);
                    }
                 }

                 else
                 {
                     break;
                 }

             }while(choix != 0);

}

int main()
{
/// IMPORTANT:
/// Je n'arrive pas a afficher Pareto à partir de mon Menu.
/// Pour le tester et vous montrer que cela fonctionne, je vous invite à mettre
/// la ligne ci-dessous ( Menu(); ) en commentaire et à remplacer le #if 0 par #if 1.
/// En m'excusant pour ce bug

Menu();

/// Pour tracer le diagramme de Pareto, nous utilisons Excel (présent dans le fichier.zip)
/// On copie le fichier "Pareto.txt" dans la feuille et le graphe se trace
/// Pour aller plus loin, on trie les solutions avec un tri peronnalisé pour avoir les valeurs optimales vers le haut.

#if 0  /// a remplacer par 1 pour tester Pareto pour Manhattan



        std::string nomFichier = "manhattan.txt";
        std::string nomFichierPoids="manhattan_weights_0.txt";

        std::ifstream monFlux(nomFichierPoids.c_str());
        int taille;

        if(monFlux)
        {
        monFlux >> taille;
        }


        Svgfile svgout;
        Graphe c(taille);
        c.charger(nomFichier,nomFichierPoids);
        c.allGraphe();
        c.StockerAllGraphe();
                    system("cls");
        std::cout << "Pour voir le graphe de Pareto, veuillez ouvrir le document Pareto.txt" << std::endl
                  << "Copiez l'ensemble de ce document et collez le dans le document Excel en A2 \n\n\n" << std::endl
                  << " Appuyez pour affichers les valeurs minimum de Pareto" << std::endl;
                  system("pause");
                  system("cls");

        c.ParetoOpti();
        c.trierPoids1(); ///remplacer le 1 par 2 pour tester le poids 2 pour Kruskal
        c.dessinerKruskal(svgout);


#endif




    return 0;
}




