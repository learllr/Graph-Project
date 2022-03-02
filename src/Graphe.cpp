#include "Graphe.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <math.h>
#include <queue>

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRNI "\e[1;32m"
#define GRN "\e[0;32m"
#define JN "\e[0;33m"
#define CYNI "\e[1;36m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"
#define JNCLAIR "\e[1;33m"
#define VIOLETI "\e[1;35m"
#define VIOLET "\e[0;35m"

using namespace std;

/* Constructeur d'un graphe manuel */
Graphe::Graphe(unsigned int reponseDistance, unsigned int reponseBavard)
{
    // Déclaration d'un flux permettant d'écrire dans le fichier.
    ofstream fichier("./grapheManuel.txt", ios::out);

    int i = 0;
    int j = 0;

    Sommet sommet;
    cout << endl
         << endl;

    cout << "---------------------------------------------------------------------" << endl;
    cout << "|" << JNCLAIR << "                        DIMENSIONS DU GRAPHE                       " << NC << "|" << endl;
    cout << "---------------------------------------------------------------------" << endl;

    do
    {
        cout << JN << " Veuillez donner la largeur du graphe : " << NC;
        cin >> largeur;
    } while (largeur <= 0);

    do
    {
        cout << JN << " Veuillez donner la hauteur du graphe : " << NC;
        cin >> hauteur;
    } while (hauteur <= 0);

    cout << "---------------------------------------------------------------------" << endl;

    if (fichier)
    {
        fichier << largeur << " " << hauteur << endl;
    }
    else
    {
        cout << RED "/!\\ Impossible d'ouvrir le fichier /!\\" NC << endl;
    }

    grille = new Sommet[hauteur * largeur];

    cout << endl
         << endl
         << "---------------------------------------------------------------------" << endl;
    cout << "|" << VIOLETI << "                        ALTITUDES DU GRAPHE                        " << NC << "|" << endl;
    cout << "---------------------------------------------------------------------" << endl;

    for (int numNoeuds = 0; numNoeuds < largeur * hauteur; numNoeuds++)
    {
        cout << VIOLET << "Altitude du noeud " << numNoeuds << " : " << NC;
        cin >> sommet.altitude;

        if (sommet.altitude < 0)
        {
            do
            {
                cout << RED "/!\\ Veuillez mettre une valeur positive /!\\ " NC;
                cout << VIOLET << "Altitude du noeud " << numNoeuds << " : " << NC;
                cin >> sommet.altitude;
            } while (sommet.altitude < 0);
        }

        grille[i * largeur + j].altitude = sommet.altitude;

        if (fichier)
        {
            fichier << sommet.altitude << " ";
        }
        else
        {
            cout << RED "/!\\ Impossible d'ouvrir le fichier /!\\" NC << endl;
        }

        if (i % largeur == 0)
        {
            i = 0;
            j++;
        }
    }

    cout << "---------------------------------------------------------------------" << endl;

    fichier.close();
    cout << endl;

    // Pointeurs de fonctions concernant le calcul de distance entre deux sommets et le mode bavard.
    if (reponseDistance == 1)
    {
        pointeurDistance = &Graphe::distanceEntreDeuxSommets2D;
    }
    else if (reponseDistance == 2)
    {
        pointeurDistance = &Graphe::distanceEntreDeuxSommets3D;
    }

    if (reponseBavard == 1)
    {
        pointeurBavard = &Graphe::algorithmeAetoileBavard;
    }
    else if (reponseBavard == 2)
    {
        pointeurBavard = &Graphe::algorithmeAetoileNonBavard;
    }
}

/* Constructeur d'un graphe à partir d'un fichier */
Graphe::Graphe(string cheminFichier, unsigned int reponseDistance, unsigned int reponseBavard)
{
    // Déclaration d'un flux permettant de lire le fichier.
    ifstream fichier(cheminFichier);

    cout << endl
         << endl;

    int i = 0;
    int j = 0;

    if (fichier)
    {
        int largeurFichier;
        fichier >> largeurFichier;
        largeur = largeurFichier;

        int hauteurFichier;
        fichier >> hauteurFichier;
        hauteur = hauteurFichier;

        grille = new Sommet[hauteur * largeur];

        for (int numNoeuds = 0; numNoeuds < largeur * hauteur; numNoeuds++)
        {
            int altitude;
            fichier >> altitude;
            grille[i * largeur + j].altitude = altitude;

            if (i % largeur == 0)
            {
                j++;
            }
        }
    }
    else
    {
        cout << "/!\\ Fichier introuvable /!\\" << endl;
    }

    fichier.close();

    // Pointeurs de fonctions concernant le calcul de distance entre deux sommets et le mode bavard.
    if (reponseDistance == 1)
    {
        pointeurDistance = &Graphe::distanceEntreDeuxSommets2D;
    }
    else if (reponseDistance == 2)
    {
        pointeurDistance = &Graphe::distanceEntreDeuxSommets3D;
    }

    if (reponseBavard == 1)
    {
        pointeurBavard = &Graphe::algorithmeAetoileBavard;
    }
    else if (reponseBavard == 2)
    {
        pointeurBavard = &Graphe::algorithmeAetoileNonBavard;
    }
}

/* Destructeur d'un graphe */
Graphe::~Graphe()
{
    delete [] grille;
    largeur = 0;
    hauteur = 0;
    file.empty();
}

/* Procédure d'affichage d'un graphe */
void Graphe::affichageGraphe()
{
    cout << endl;

    int i = 0;
    int j = 0;

    for (int numNoeuds = 1; numNoeuds <= largeur * hauteur; numNoeuds++)
    {
        if ((numNoeuds % largeur) == 0)
        {
            if (!strcmp(grille[i * largeur + j].couleur, "blanc"))
            {
                cout << NC << grille[i * largeur + j].altitude << NC;
            }

            else if (!strcmp(grille[i * largeur + j].couleur, "gris"))
            {
                cout << RED << grille[i * largeur + j].altitude << NC;
            }

            else if (!strcmp(grille[i * largeur + j].couleur, "noir"))
            {
                cout << CYN << grille[i * largeur + j].altitude << NC;
            }

            else if (!strcmp(grille[i * largeur + j].couleur, "vert"))
            {
                cout << GRN << grille[i * largeur + j].altitude << NC;
            }

            cout << endl;

            if (numNoeuds != largeur * hauteur)
            {
                for (int j = 1; j <= largeur; j++)
                {
                    cout << NC << "|     ";
                }
                cout << endl;
            }
        }
        else
        {
            if (!strcmp(grille[i * largeur + j].couleur, "blanc"))
            {
                cout << NC << grille[i * largeur + j].altitude << NC;
            }

            else if (!strcmp(grille[i * largeur + j].couleur, "gris"))
            {
                cout << RED << grille[i * largeur + j].altitude << NC;
            }

            else if (!strcmp(grille[i * largeur + j].couleur, "noir"))
            {
                cout << CYN << grille[i * largeur + j].altitude << NC;
            }

            else if (!strcmp(grille[i * largeur + j].couleur, "vert"))
            {
                cout << GRN << grille[i * largeur + j].altitude << NC;
            }

            cout << NC << " --- ";
        }

        if (i % largeur == 0)
        {
            j++;
        }
    }
    cout << endl;
}

/* Procédure pour récupérer les coordonnées d'un sommet (ligne et colonne) à partir de son indice */
void Graphe::coordonneesSommet(int *ligne, int *colonne, int indice)
{
    *ligne = indice / largeur;
    *colonne = indice % largeur;
}

/* Fonction pour récupérer l'indice d'un sommet à partir de ses coordonnées (ligne et colonne) */
int Graphe::indiceSommet(int ligne, int colonne)
{
    return (ligne * largeur + colonne);
}

/* Fonction pour récupérer l'altitude d'un sommet */
int Graphe::altitudeSommet(int indice)
{
    return grille[indice].altitude;
}

/* Procédure pour modifier l'altitude d'un sommet à partir de son indice */
void Graphe::modificationAltitudeIndice(int indice, int altitude)
{
    grille[indice].altitude = altitude;
}

/* Procédure pour modifier l'altitude d'un sommet à partir de ses coordonnées (ligne et colonne) */
void Graphe::modificationAltitudeLigneColonne(int ligne, int colonne, int altitude)
{
    grille[ligne * largeur + colonne].altitude = altitude;
}

/* Fonction pour récupérer le voisin nord d'un sommet */
int Graphe::voisinNordSommet(int indice)
{
    int ligne, colonne;
    coordonneesSommet(&ligne, &colonne, indice);

    if (ligne - 1 >= 0)
    {
        int indSommet = indiceSommet(ligne - 1, colonne);
        return indSommet;
    }
    else
    {
        return -1;
    }
}

/* Fonction pour récupérer le voisin sud d'un sommet */
int Graphe::voisinSudSommet(int indice)
{
    int ligne, colonne;
    coordonneesSommet(&ligne, &colonne, indice);

    if (ligne + 1 < hauteur)
    {
        int indSommet = indiceSommet(ligne + 1, colonne);
        return indSommet;
    }
    else
    {
        return -1;
    }
}

/* Fonction pour récupérer le voisin ouest d'un sommet */
int Graphe::voisinOuestSommet(int indice)
{
    int ligne, colonne;
    coordonneesSommet(&ligne, &colonne, indice);

    if (colonne - 1 >= 0)
    {
        int indSommet = indiceSommet(ligne, colonne - 1);
        return indSommet;
    }
    else
    {
        return -1;
    }
}

/* Fonction pour récupérer le voisin est d'un sommet */
int Graphe::voisinEstSommet(int indice)
{
    int ligne, colonne;
    coordonneesSommet(&ligne, &colonne, indice);

    if (colonne + 1 < largeur)
    {
        int indSommet = indiceSommet(ligne, colonne + 1);
        return indSommet;
    }
    else
    {
        return -1;
    }
}

/* Fonction pour récupérer la distance entre un sommet et son voisin nord */
float Graphe::distanceSommetNord(int indice)
{
    int altitudeSommet = grille[indice].altitude;
    int altitudeSommetNord = grille[voisinNordSommet(indice)].altitude;
    int soustraction = altitudeSommet - altitudeSommetNord;

    if (sqrt(1 + soustraction * soustraction) > 0)
    {
        return sqrt(1 + soustraction * soustraction);
    }
    else
    {
        return 0;
    }
}

/* Fonction pour récupérer la distance entre un sommet et son voisin sud */
float Graphe::distanceSommetSud(int indice)
{
    int altitudeSommet = grille[indice].altitude;
    int altitudeSommetSud = grille[voisinSudSommet(indice)].altitude;
    int soustraction = altitudeSommet - altitudeSommetSud;

    if (sqrt(1 + soustraction * soustraction) > 0)
    {
        return sqrt(1 + soustraction * soustraction);
    }
    else
    {
        return 0;
    }
}

/* Fonction pour récupérer la distance entre un sommet et son voisin ouest */
float Graphe::distanceSommetOuest(int indice)
{
    int altitudeSommet = grille[indice].altitude;
    int altitudeSommetOuest = grille[voisinOuestSommet(indice)].altitude;
    int soustraction = altitudeSommet - altitudeSommetOuest;

    if (sqrt(1 + soustraction * soustraction) > 0)
    {
        return sqrt(1 + soustraction * soustraction);
    }
    else
    {
        return 0;
    }
}

/* Fonction pour récupérer la distance entre un sommet et son voisin est */
float Graphe::distanceSommetEst(int indice)
{
    int altitudeSommet = grille[indice].altitude;
    int altitudeSommetEst = grille[voisinEstSommet(indice)].altitude;
    int soustraction = altitudeSommet - altitudeSommetEst;

    if (sqrt(1 + soustraction * soustraction) > 0)
    {
        return sqrt(1 + soustraction * soustraction);
    }
    else
    {
        return 0;
    }
}

/* Fonction pour récupérer la distance entre deux positions 3D de sommets */
float Graphe::distanceEntreDeuxSommets3D(int indice, int indice2)
{
    int l1, l2, c1, c2;
    coordonneesSommet(&l1, &c1, indice);
    coordonneesSommet(&l2, &c2, indice2);

    return sqrt((l1 - l2) * (l1 - l2) + (c1 - c2) * (c1 - c2) + (grille[indice].altitude - grille[indice2].altitude) * (grille[indice].altitude - grille[indice2].altitude));
}

/* Fonction pour récupérer la distance entre deux positions 2D de sommets */
float Graphe::distanceEntreDeuxSommets2D(int indice, int indice2)
{
    int l1, l2, c1, c2;
    coordonneesSommet(&l1, &c1, indice);
    coordonneesSommet(&l2, &c2, indice2);

    return sqrt((l2 - l1) * (l2 - l1) + (c2 - c1) * (c2 - c1));
}

/* Procédure pour l'algorithme A* qui permet de parcourir le graphe et mettre les voisins d'un sommet en gris */
void Graphe::mettreVoisinGrisEtRelacher(int indice, int indiceDestination)
{
    int indiceEst = voisinEstSommet(indice);
    int indiceOuest = voisinOuestSommet(indice);
    int indiceNord = voisinNordSommet(indice);
    int indiceSud = voisinSudSommet(indice);

    if ((indiceEst != -1) && (strcmp(grille[indiceEst].couleur, "noir")))
    {
        grille[indiceEst].couleur = (char *)"gris";
        if ((grille[indiceEst].longueurChemin < 0) || ((grille[indiceEst].longueurChemin > 0) && (grille[indiceEst].longueurChemin > grille[indice].longueurChemin + distanceSommetEst(indice))))
        {
            grille[indiceEst].longueurChemin = grille[indice].longueurChemin + distanceSommetEst(indice);
            grille[indiceEst].longueurDestination = grille[indiceEst].longueurChemin + (this->*pointeurDistance)(indiceEst, indiceDestination);
            grille[indiceEst].longueurDestinationRestante = (this->*pointeurDistance)(indiceEst, indiceDestination);
            grille[indiceEst].predecesseur = indice;
            file.push(make_pair(0 - grille[indiceEst].longueurDestination, indiceEst));
        }
    }

    if ((indiceOuest != -1) && (strcmp(grille[indiceOuest].couleur, "noir")))
    {
        grille[indiceOuest].couleur = (char *)"gris";
        if ((grille[indiceOuest].longueurChemin < 0) || ((grille[indiceOuest].longueurChemin > 0) && (grille[indiceOuest].longueurChemin > grille[indice].longueurChemin + distanceSommetOuest(indice))))
        {
            grille[indiceOuest].longueurChemin = grille[indice].longueurChemin + distanceSommetOuest(indice);
            grille[indiceOuest].longueurDestination = grille[indiceOuest].longueurChemin + (this->*pointeurDistance)(indiceOuest, indiceDestination);
            grille[indiceOuest].longueurDestinationRestante = (this->*pointeurDistance)(indiceOuest, indiceDestination);
            grille[indiceOuest].predecesseur = indice;
            file.push(make_pair(0 - grille[indiceOuest].longueurDestination, indiceOuest));
        }
    }

    if ((indiceNord != -1) && (strcmp(grille[indiceNord].couleur, "noir")))
    {
        grille[indiceNord].couleur = (char *)"gris";
        if ((grille[indiceNord].longueurChemin < 0) || ((grille[indiceNord].longueurChemin > 0) && (grille[indiceNord].longueurChemin > grille[indice].longueurChemin + distanceSommetNord(indice))))
        {
            grille[indiceNord].longueurChemin = grille[indice].longueurChemin + distanceSommetNord(indice);
            grille[indiceNord].longueurDestination = grille[indiceNord].longueurChemin + (this->*pointeurDistance)(indiceNord, indiceDestination);
            grille[indiceNord].longueurDestinationRestante = (this->*pointeurDistance)(indiceNord, indiceDestination);
            grille[indiceNord].predecesseur = indice;
            file.push(make_pair(0 - grille[indiceNord].longueurDestination, indiceNord));
        }
    }

    if ((indiceSud != -1) && (strcmp(grille[indiceSud].couleur, "noir")))
    {
        grille[indiceSud].couleur = (char *)"gris";
        if ((grille[indiceSud].longueurChemin < 0) || ((grille[indiceSud].longueurChemin > 0) && (grille[indiceSud].longueurChemin > grille[indice].longueurChemin + distanceSommetSud(indice))))
        {
            grille[indiceSud].longueurChemin = grille[indice].longueurChemin + distanceSommetSud(indice);
            grille[indiceSud].longueurDestination = grille[indiceSud].longueurChemin + (this->*pointeurDistance)(indiceSud, indiceDestination);
            grille[indiceSud].longueurDestinationRestante = (this->*pointeurDistance)(indiceSud, indiceDestination);
            grille[indiceSud].predecesseur = indice;
            file.push(make_pair(0 - grille[indiceSud].longueurDestination, indiceSud));
        }
    }

    grille[indice].couleur = (char *)"noir";
}

/* Procédure qui permet d'afficher le chemin suivi lors de l'algorithme A* */
void Graphe::cheminSuivi(int indiceDepart, int indiceDestination)
{
    float distance = 0;
    int nbindice = 0;
    int tabindice[largeur * hauteur];

    while (indiceDestination != grille[indiceDestination].predecesseur)
    {
        grille[indiceDestination].couleur = (char *)"vert";
        distance = distance + (this->*pointeurDistance)(grille[indiceDestination].predecesseur, indiceDestination);
        tabindice[nbindice] = indiceDestination;
        nbindice++;
        indiceDestination = grille[indiceDestination].predecesseur;
    }

    cout << "Distance parcourue : " << distance << endl;
    cout << "Chemin suivi : " << indiceDepart << " -> ";

    for (int i = nbindice - 1; i > 0; i--)
    {
        cout << tabindice[i] << " -> ";
    }

    cout << tabindice[0];
    grille[indiceDestination].couleur = (char *)"vert";
    cout << endl;
}

/* Procédure qui permet de pointer vers la fonction algorithme A* en mode bavard ou non */
void Graphe::algorithmeAetoile(int indiceNoeud, int indiceDestination)
{
    (this->*pointeurBavard)(indiceNoeud, indiceDestination);
}

/* Procédure qui permet de réaliser l'algorithme A* en mode non bavard */
void Graphe::algorithmeAetoileNonBavard(int indiceNoeud, int indiceDestination)
{
    for (int i = 0; i < largeur * hauteur; i++)
    {
        grille[i].couleur = (char *)"blanc";
    }
    grille[indiceNoeud].couleur = (char *)"gris";
    grille[indiceNoeud].longueurChemin = 0;
    grille[indiceNoeud].predecesseur = indiceNoeud;
    grille[indiceNoeud].longueurDestination = (this->*pointeurDistance)(indiceNoeud, indiceDestination);

    pair<float, int> longueurEtIndice;
    file.push(make_pair(0 - grille[indiceNoeud].longueurDestination, indiceNoeud));

    while (strcmp(grille[indiceDestination].couleur, "noir"))
    {
        longueurEtIndice = file.top();
        file.pop();

        if (strcmp(grille[longueurEtIndice.second].couleur, "noir"))
        {
            mettreVoisinGrisEtRelacher(longueurEtIndice.second, indiceDestination);
        }
    }
    cheminSuivi(indiceNoeud, indiceDestination);
    affichageGraphe();
    file.empty();
}

/* Procédure qui permet de réaliser l'algorithme A* en mode bavard */
void Graphe::algorithmeAetoileBavard(int indiceNoeud, int indiceDestination)
{
    for (int i = 0; i < largeur * hauteur; i++)
    {
        grille[i].couleur = (char *)"blanc";
    }
    grille[indiceNoeud].couleur = (char *)"gris";
    grille[indiceNoeud].longueurChemin = 0;
    grille[indiceNoeud].predecesseur = indiceNoeud;
    grille[indiceNoeud].longueurDestination = (this->*pointeurDistance)(indiceNoeud, indiceDestination);

    pair<float, int> longueurEtIndice;
    file.push(make_pair(0 - grille[indiceNoeud].longueurDestination, indiceNoeud));

    while (strcmp(grille[indiceDestination].couleur, "noir"))
    {
        longueurEtIndice = file.top();
        file.pop();

        if (strcmp(grille[longueurEtIndice.second].couleur, "noir"))
        {
            mettreVoisinGrisEtRelacher(longueurEtIndice.second, indiceDestination);
            affichageGraphe();
        }
    }
    cheminSuivi(indiceNoeud, indiceDestination);
    affichageGraphe();
    file.empty();
}

/* Constructeur d'un sommet */
Sommet::Sommet()
{
    altitude = 0;
    longueurDestination = -1;
    longueurChemin = -1;
    longueurDestinationRestante = -1;
    predecesseur = -1;
    couleur = (char *)"blanc";
}

/* Destructeur d'un sommet */
Sommet::~Sommet()
{
    altitude = 0;
    longueurDestination = -1;
    longueurChemin = -1;
    longueurDestinationRestante = -1;
    predecesseur = -1;
    couleur = nullptr;
}
