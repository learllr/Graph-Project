#ifndef Graphe_H
#define Graphe_H

#include <string>
#include <queue>

using namespace std;

class Sommet
{
    friend class Graphe;

private:
    int altitude;
    float longueurChemin;
    float longueurDestination;
    float longueurDestinationRestante;
    int predecesseur;
    char * couleur;

public:
    Sommet();
    ~Sommet();
};

class Graphe
{
private:
    Sommet * grille;

public:
    int largeur;
    int hauteur;
    priority_queue<pair<float, int> > file;

    Graphe(unsigned int reponseDistance, unsigned int reponseBavard);
    Graphe(string cheminFichier, unsigned int reponseDistance, unsigned int reponseBavard);
    ~Graphe();

    void affichageGraphe();
    void coordonneesSommet(int *ligne, int *colonne, int indice);
    int indiceSommet(int ligne, int colonne);
    int altitudeSommet(int indice);
    void modificationAltitudeIndice(int indice, int altitude);
    void modificationAltitudeLigneColonne(int ligne, int colonne, int altitude);
    int voisinNordSommet(int indice);
    int voisinSudSommet(int indice);
    int voisinOuestSommet(int indice);
    int voisinEstSommet(int indice);
    float distanceSommetNord(int indice);
    float distanceSommetSud(int indice);
    float distanceSommetOuest(int indice);
    float distanceSommetEst(int indice);
    float distanceEntreDeuxSommets3D(int indice, int indice2);
    float distanceEntreDeuxSommets2D(int indice, int indice2);
    void algorithmeAetoile(int indiceNoeud, int indiceDestination);
    void algorithmeAetoileNonBavard(int indiceNoeud, int indiceDestination);
    void algorithmeAetoileBavard(int indiceNoeud, int indiceDestination);
    void mettreVoisinGrisEtRelacher(int indiceNoeud, int indiceDestination);
    void cheminSuivi(int indiceDestination, int indiceDepart);
    float distanceCheminSuivi(int indiceDepart, int indiceDestination);
    float (Graphe::*pointeurDistance)(int indiceNoeud, int indiceDestination);
    void (Graphe::*pointeurBavard)(int indiceNoeud, int indiceDestination);
};

#endif
