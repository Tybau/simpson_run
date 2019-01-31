# Simpson Run

## Contexte

Ce jeu a été réalisé dans le cadre d'un projet de fin de cours C++, ayant pour thème "Jaune".

## Installation et lancement du jeu :

Une fois les source du jeu téléchargées, il suffit de lancer la commande “make”
dans un terminal linux, puis d'exécuter le fichier launch.sh qui s’occupera de
faire un lien avec la librairie SFML incluse dans les sources (On peut exécuter
directement l'exécutable projet créé lors de la compilation si SFML est déjà
installé sur la machine en global).

```sh
$ make
$ ./launch.sh
```


> Le jeu a été testé sur :
> - Linux Mint 18.3 (Linux version 4.13)
> - Antergos (Linux versio 4.19)
> - Debian 9.5 via le Windows Subsystem for Linux (Linux version 4.4.0-17134-Microsoft)

> La version de SFML incluse étant pour Linux 64 bits, il faudra l'installer par vous-même, si vous utilisez une autre configuration.

## Descritption du jeu

Simpson Run est un jeu amusant et stimulant. Il plaira à coup sûr à tous les fans des Simpsons, et si vous l’êtes pas, pas d’inquiétude vous allez tomber sous le charme de notre jeu !

Le principe de Simpson Run est très simple, mais je défis d’y arriver !

Pour gagner ce jeu, le joueur doit manger tous les donuts présents dans le jeu, tout en évitant trois choses :
- Les SimpSpice (piments jaunes) : -1 point
- Les CasperSimp (fantomes) : -2 points
- Gravité : En  tombant en dessous de l'écran (les sorties de l'écran sur les côté sont autorisées), la partie est terminée

DE plus pour pimenter le jeu vous devrez réaliser le tout en 25 s.

> Homer ne peut pas avoir un nombre de points inferieur à 0

## Auteurs
- [Thibault GAUTIER](https://github.com/Tybau)
- [Farah RAEI](https://github.com/FarahRaei)
