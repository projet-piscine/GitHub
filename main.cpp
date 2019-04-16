#include <iostream>
#include "graphe.h"
#include "svgfile.h"
#include <cstdlib>
#include <fstream>



int main()
{
Svgfile svgout;


Graphe a;
a.charger();
a.dessiner(svgout);

    return 0;
}
