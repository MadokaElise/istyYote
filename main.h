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

	//suggestion
	#define TAILLE_CASE 80
	#define RESERVE 3
	#define PLATEAU 4
	#define JOUEUR1 1
	#define JOUEUR2 2

	// Type booléen
	typedef int bool;
	#define TRUE (1)
	#define FALSE (0)

	/* Largeur et hauteur du plateau
	en terme de nombre de cases */
	#define LARGEUR 6
	#define HAUTEUR 5

	#define LARGEUR_FENETRE 1110 //600
	#define HAUTEUR_FENETRE 800//600


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

	// L'état d'une case:
	typedef enum {
		DEFAULT,
		SELECTED, // une case séléctionné
		ACCESSIBLE, // une casse accessible par un pion sur le plateau
		CAPTURE, // un pion adverse qui peut être pris
	} typeStatus;

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
		SDL_Surface* spritefond;
		SDL_Surface* spritenuage;
	} Sprites;

	// Le plateau, accès avec plateau[x][y] avec l'origine en haut à gauche
	// comme en SDL, SVG, canvas
	square board[LARGEUR][HAUTEUR] ;

	// Déclaration de la variable globale permettant d'utiliser les sprites
	Sprites sprites;
	
	#include "display/display.h"
	#include "modele/mod.h"

#endif
