
  

Voici le site pour visualiser le langage md du read me : https://stackedit.io/app#

  

  

# Graphe (grille)

  

  

Notre projet porte sur les graphes sous forme de grilles. Il a été réalisé dans le cadre de l'unité d'enseignement LIFAP6 de 2021-2022.

  

  

## Organisation de l'archive

  

  

**./ :** Contient le Makefile permettant de compiler le projet en créant deux exécutables contenus dans le dossier bin.

  

  

**bin/ :** Contient les exécutables main et mainTest.

  

  

**data/ :** Tous les fichiers (.txt) contenant les informations des graphes.

  

  

**obj/ :** Les fichiers objets (.o) : main.o, mainTest.o, Graphe.o.

  

  

**src/ :** Les fichiers sources .cpp et header .h : Graphe.cpp, Graphe.h, main.cpp, mainTest.cpp.

  

  

## Utilisation et Exécutables

  

  

Pour compiler et créer les exécutables, on utilise la commande make dans le terminal Linux suivi de ./bin/nomExecutable depuis le dossier.

  

  

Notre projet contient deux exécutables :

  

  

- main : exécutable permettant de créer soit un graphe manuellement en choisissant la hauteur, la largeur ainsi que les altitudes de chaque sommet ou un graphe à partir d'un fichier. Il est ensuite possible de choisir le type de calcul de distance (2D ou 3D) et si l'on souhaite activer le mode bavard. Il faut ensuite choisir l'indice de départ et de destination pour l'algorithme A*.

  
- mainTest : exécutable permettant de tester les fonctions de la classe Graphe.
  

## Module

  

- Sommet : type correspondant à un sommet d'un graphe.

- Graphe : classe qui correspond à un graphe.

## Créateurs

  

  

BEN JEMIA Boran (p1924945)

  

  

ROULLIER LEA (p1911736)
