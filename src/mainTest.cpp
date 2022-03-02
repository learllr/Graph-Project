#include <iostream>
#include "Graphe.h"

using namespace std;

int main ()
{
    int l,c;

    Graphe g("./data/graphe2.txt", 2, 1);
    g.affichageGraphe();
    g.coordonneesSommet(&l, &c, 6);
    cout << "L'indice 6 a pour ligne : " << l << " et pour colonne : " << c << endl;
    cout << "Le sommet de coordonnées (1;3) est à l'indice : " << g.indiceSommet(1, 3) << endl;
    cout << "L'altitude à l'indice 11 est : " << g.altitudeSommet(11) << endl;
    cout << "Modification de l'altitude à l'indice 0 en 5 : " << endl;
    g.modificationAltitudeIndice(0, 5);
    g.affichageGraphe();
    cout << "Modification de l'altitude aux coordonnées (2;2) en 1 : " << endl;
    g.modificationAltitudeLigneColonne(2, 2, 1);
    g.affichageGraphe();
    cout << "Le voisin nord de l'indice 8 est : " << g.voisinNordSommet(8) << endl;
    cout << "Le voisin sud de l'indice 2 est : " << g.voisinSudSommet(2) << endl;
    cout << "Le voisin ouest de l'indice 3 est : " << g.voisinOuestSommet(3) << endl;
    cout << "Le voisin est de l'indice 6 est : " << g.voisinEstSommet(6) << endl;
    cout << "La distance entre l'indice 8 et son sommet nord est : " << g.distanceSommetNord(8) << endl;
    cout << "La distance entre l'indice 2 et son sommet sud est : " << g.distanceSommetSud(2) << endl;
    cout << "La distance entre l'indice 3 et son sommet ouest est : " << g.distanceSommetOuest(3) << endl;
    cout << "La distance entre l'indice 6 et son sommet est est : " << g.distanceSommetEst(6) << endl;
    cout << "La distance (3D) entre l'indice 3 et l'indice 6 est : " << g.distanceEntreDeuxSommets3D(3, 6) << endl;
    cout << "La distance (2D) entre l'indice 3 et l'indice 6 est : " << g.distanceEntreDeuxSommets2D(3, 6) << endl;
    cout << "La distance (2D) entre l'indice 5 et l'indice 6 est : " << g.distanceEntreDeuxSommets2D(5, 6) << endl;
    cout << endl;
    cout << "Chemin pour aller de 0 à 5 :"<<endl;
    g.algorithmeAetoile(0, 5);
}