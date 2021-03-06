// Projet Yoté -- IATIC 3 ISTY
// See the authors in AUTHOR.md

#ifndef MAIN_H
	#define MAIN_H

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <time.h>
	#include <SDL.h>
	#include <SDL_ttf.h>
	#include <unistd.h>

	

	// Type booléen
	typedef int bool;
	#define TRUE (1)
	#define FALSE (0)

	/* Largeur et hauteur du plateau
	en terme de nombre de cases */
	#define LARGEUR 6
	#define HAUTEUR 5

	#define LARGEUR_FENETRE 1110
	#define HAUTEUR_FENETRE 800

	#define TAILLE_CASE 80

	// Coordonées d'une case du plateau (board).
	typedef struct {
		int x;
		int y;
	} coord;

	// La race d'un pion
	typedef enum {
		VIDE,
		ORC,
		DEMON,
	} raceJoueur;

	//joueur
	typedef struct {  
		raceJoueur race;
		int reserve; //nb pion du joueur dans sa reserve
		int plateau; // nb pion du joueur sur le plateau
		coord c1Anc; // coordonnée de l'ancienne position c1 ( sert pour que le joueur ne joue pas un tour inverse au precedent)
		coord c2Anc; // coordonnée de l'ancienne position c2 ( sert pour que le joueur ne joue pas un tour inverse au precedent)
	} Joueur;

	// L'état d'une case:
	typedef enum {
		DEFAULT,
		SELECTED, // une case séléctionné
		ACCESSIBLE, // une casse accessible par un pion sur le plateau
		CAPTURE, // un pion adverse qui peut être pris
	} typeStatus;

	typedef enum {
		HOME, // Menu d'accueil du jeu
		GAMEMODE, // Menu de choix de jeu
		OTHER // Autre interface
	} typeMenu;

	// une case du plateau
	typedef struct {
		raceJoueur race;
		typeStatus status ;
	} square;

	// Sprites
	typedef struct {
		SDL_Surface* spriteCase;
		SDL_Surface* spriteDemon;
		SDL_Surface* spriteOrc;
		SDL_Surface* spriteFond;
		SDL_Surface* spriteNuage;
		SDL_Surface* spriteCarreBleu;
		SDL_Surface* spriteCaisse;
		SDL_Surface* spriteBoutonRetour;
	} Sprites;

	// Le plateau, accès avec plateau[x][y] avec l'origine en haut à gauche
	// comme en SDL, SVG, canvas
	square board[LARGEUR][HAUTEUR] ;

	// Déclaration de la variable globale permettant d'utiliser les sprites
	Sprites sprites;

	void end(SDL_Event _);

	#include "control/event.h"
	#include "control/score.h"
	#include "control/control.h"
	#include "display/display.h"
	#include "display/displayScore.h"
	#include "modele/mod.h"

#endif
