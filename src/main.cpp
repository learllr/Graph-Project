#include <iostream>
#include "Graphe.h"
#include <fstream>

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRNI "\e[1;32m"
#define GRN "\e[0;32m"
#define JN "\e[0;33m"
#define CYNI "\e[1;36m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"
#define JNCLAIR "\e[1;33m"

using namespace std;

int main()
{
    unsigned int reponseGraphe, reponseDistance, reponseBavard;

    cout << endl << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "|" << GRNI << "                BIENVENUE SUR LE PROJET DES GRAPHES                " << NC << "|" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "| Voulez-vous créer un graphe manuellement (1) ou à partir d'un     |" << endl;
    cout << "| fichier (2) ?                                                     |" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << GRN << "  Votre réponse : " << NC;
    do 
    {
        cin >> reponseGraphe;

        if ( (reponseGraphe != 1) && (reponseGraphe != 2) )
        {
            cout << RED << "  /!\\ Attention, il faut choisir soit 1 soit 2 /!\\ " << NC << endl;
            cout << GRN << "  Votre réponse : " << NC;
        }

    } while ( (reponseGraphe != 1) && (reponseGraphe != 2) );
    cout << "---------------------------------------------------------------------" << endl;
    cout << "| Voulez-vous calculer la distance Euclidienne entre les positions  |" << endl;
    cout << "| 2D (1) ou 3D (2) ?                                                |" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << GRN << "  Votre réponse : " << NC;
    do 
    {
        cin >> reponseDistance;

        if ( (reponseDistance != 1) && (reponseDistance != 2) )
        {
            cout << RED << "  /!\\ Attention, il faut choisir soit 1 soit 2 /!\\ " << NC << endl;
            cout << GRN << "  Votre réponse : " << NC;
        }

    } while ( (reponseDistance != 1) && (reponseDistance != 2) );

    cout << "---------------------------------------------------------------------" << endl;
    cout << "| Voulez-vous activer le mode bavard? Oui (1) ou Non (2)            |" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << GRN << "  Votre réponse : " << NC;
    do 
    {
        cin >> reponseBavard;

        if ( (reponseBavard != 1) && (reponseBavard != 2) )
        {
            cout << RED << "  /!\\ Attention, il faut choisir soit 1 soit 2 /!\\ " << NC << endl;
            cout << GRN << "  Votre réponse : " << NC;
        }

    } while ( (reponseBavard != 1) && (reponseBavard != 2) );

    cout << "---------------------------------------------------------------------" << NC << endl;

    if (reponseGraphe == 1)
    {
        Graphe g1(reponseDistance, reponseBavard);
        g1.affichageGraphe();

        int indiceDepart, indiceDestination;
        cout << "---------------------------------------------------------------------" << endl;
        cout << "|" << CYNI << "                           ALGORITHME A*                           " << NC << "|" << endl;
        cout << "---------------------------------------------------------------------" << endl;
        do
        {      
            do
            {
                cout << CYN << "Indice de départ : " << NC;
                cin >> indiceDepart;

                if (indiceDepart >= g1.hauteur * g1.largeur)
                {
                    cout << RED << "/!\\ Attention, il faut choisir un indice entre 0 et " << (g1.hauteur * g1.largeur) - 1  << " /!\\" << NC << endl;
                }

            } while (indiceDepart >= g1.hauteur * g1.largeur);
            
            do
            {
                cout << CYN << "Indice de destination : " << NC;
                cin >> indiceDestination;

                if (indiceDestination >= g1.hauteur * g1.largeur)
                {
                    cout << RED << "/!\\ Attention, il faut choisir un indice entre 0 et " << (g1.hauteur * g1.largeur) - 1  << " /!\\" << NC << endl;
                }

            } while (indiceDestination >= g1.hauteur * g1.largeur);

            if (indiceDepart == indiceDestination)
            {
                cout << RED << "/!\\ Attention, l'indice de destination ne doit pas être égal à celui de départ /!\\" << NC << endl;
            }

        } while (indiceDepart == indiceDestination);
        cout << "---------------------------------------------------------------------" << endl;
        
        g1.algorithmeAetoile(indiceDepart, indiceDestination);
    }
    else if (reponseGraphe == 2)
    {
        Graphe g2("./data/graphe.txt", reponseDistance, reponseBavard);
        g2.affichageGraphe();
        
        int indiceDepart, indiceDestination;
        cout << "---------------------------------------------------------------------" << endl;
        cout << "|" << CYNI << "                           ALGORITHME A*                           " << NC << "|" << endl;
        cout << "---------------------------------------------------------------------" << endl;
        do
        {      
            do
            {
                cout << CYN << "Indice de départ : " << NC;
                cin >> indiceDepart;

                if (indiceDepart >= g2.hauteur * g2.largeur)
                {
                    cout << RED << "/!\\ Attention, il faut choisir un indice entre 0 et " << (g2.hauteur * g2.largeur) - 1  << " /!\\" << NC << endl;
                }

            } while (indiceDepart >= g2.hauteur * g2.largeur);
            
            do
            {
                cout << CYN << "Indice de destination : " << NC;
                cin >> indiceDestination;

                if (indiceDestination >= g2.hauteur * g2.largeur)
                {
                    cout << RED << "/!\\ Attention, il faut choisir un indice entre 0 et " << (g2.hauteur * g2.largeur) - 1  << " /!\\" << NC << endl;
                }

            } while (indiceDestination >= g2.hauteur * g2.largeur);

            if (indiceDepart == indiceDestination)
            {
                cout << RED << "/!\\ Attention, l'indice de destination ne doit pas être égal à celui de départ /!\\" << NC << endl;
            }

        } while (indiceDepart == indiceDestination);
        cout << "---------------------------------------------------------------------" << endl;

        g2.algorithmeAetoile(indiceDepart, indiceDestination);
    }

    return 0;
}