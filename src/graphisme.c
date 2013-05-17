#include <stdio.h>
#include <stdlib.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_primitives.h>

#include "../prototype.h"

#define BLANC 0
#define NOIR 1
#define VIDE 2

void affichage_jeux(struct_plt plat[8][8], ALLEGRO_BITMAP *plateau, ALLEGRO_BITMAP *pion_b_n,
                    ALLEGRO_BITMAP *pion_b_b, ALLEGRO_BITMAP *pion_n_b, ALLEGRO_BITMAP *pion_n_n,
                    ALLEGRO_BITMAP *cheval_b_n, ALLEGRO_BITMAP *cheval_b_b, ALLEGRO_BITMAP *cheval_n_b,
                    ALLEGRO_BITMAP *cheval_n_n,
                    ALLEGRO_BITMAP *tour_b_n, ALLEGRO_BITMAP *tour_b_b, ALLEGRO_BITMAP *tour_n_b,
                    ALLEGRO_BITMAP *tour_n_n,
                    ALLEGRO_BITMAP *fou_b_n, ALLEGRO_BITMAP *fou_b_b, ALLEGRO_BITMAP *fou_n_b, ALLEGRO_BITMAP *fou_n_n,
                    ALLEGRO_BITMAP *reine_b_n, ALLEGRO_BITMAP *reine_b_b, ALLEGRO_BITMAP *reine_n_b,
                    ALLEGRO_BITMAP *reine_n_n,
                    ALLEGRO_BITMAP *roi_b_n, ALLEGRO_BITMAP *roi_b_b, ALLEGRO_BITMAP *roi_n_b,
                    ALLEGRO_BITMAP *roi_n_n) {/* cette fonction sert a afficher le plateau au cours du jeu */
    int x, y, i, j;
    y = 61;//La premiere ligne du tableau est a 61 pixels a partir du haut de l'ecran.
    x = 0;
    al_draw_bitmap(plateau, 0, 0, 0);
    for (i = 0; i < 8; i++) {//Nous traversons les 8 lignes du plateau sur ses 8 colonnes.
        for (j = 0; j < 8; j++) {
            x = j * 70 + 324;//Nous avons ici la position de la colonne de la "j i�me" case de la ligne.

/* PIONS b*/

            if ((plat[i][j].piece == 'p') && (j == 0 || j == 2 || j == 4 || j == 6) &&
                (i == 1 || i == 3 || i == 5 || i == 7))
                al_draw_bitmap(pion_b_b, x, y, 0);
            if ((plat[i][j].piece == 'p') && (j == 1 || j == 3 || j == 5 || j == 7) &&
                (i == 1 || i == 3 || i == 5 || i == 7))
                al_draw_bitmap(pion_b_n, x, y, 0);
            if ((plat[i][j].piece == 'p') && (j == 0 || j == 2 || j == 4 || j == 6) &&
                (i == 0 || i == 2 || i == 4 || i == 6))
                al_draw_bitmap(pion_b_n, x, y, 0);
            if ((plat[i][j].piece == 'p') && (j == 1 || j == 3 || j == 5 || j == 7) &&
                (i == 0 || i == 2 || i == 4 || i == 6))
                al_draw_bitmap(pion_b_b, x, y, 0);


/* CHEVAUX b*/

            if ((plat[i][j].piece == 'c') && (j == 0 || j == 2 || j == 4 || j == 6) &&
                (i == 1 || i == 3 || i == 5 || i == 7))
                al_draw_bitmap(cheval_b_b, x, y, 0);
            if ((plat[i][j].piece == 'c') && (j == 1 || j == 3 || j == 5 || j == 7) &&
                (i == 1 || i == 3 || i == 5 || i == 7))
                al_draw_bitmap(cheval_b_n, x, y, 0);
            if ((plat[i][j].piece == 'c') && (j == 0 || j == 2 || j == 4 || j == 6) &&
                (i == 0 || i == 2 || i == 4 || i == 6))
                al_draw_bitmap(cheval_b_n, x, y, 0);
            if ((plat[i][j].piece == 'c') && (j == 1 || j == 3 || j == 5 || j == 7) &&
                (i == 0 || i == 2 || i == 4 || i == 6))
                al_draw_bitmap(cheval_b_b, x, y, 0);

/* TOURS b*/

            if ((plat[i][j].piece == 't') && (j == 0 || j == 2 || j == 4 || j == 6) &&
                (i == 1 || i == 3 || i == 5 || i == 7))
                al_draw_bitmap(tour_b_b, x, y, 0);
            if ((plat[i][j].piece == 't') && (j == 1 || j == 3 || j == 5 || j == 7) &&
                (i == 1 || i == 3 || i == 5 || i == 7))
                al_draw_bitmap(tour_b_n, x, y, 0);
            if ((plat[i][j].piece == 't') && (j == 0 || j == 2 || j == 4 || j == 6) &&
                (i == 0 || i == 2 || i == 4 || i == 6))
                al_draw_bitmap(tour_b_n, x, y, 0);
            if ((plat[i][j].piece == 't') && (j == 1 || j == 3 || j == 5 || j == 7) &&
                (i == 0 || i == 2 || i == 4 || i == 6))
                al_draw_bitmap(tour_b_b, x, y, 0);

/* FOUS b*/

            if ((plat[i][j].piece == 'f') && (j == 0 || j == 2 || j == 4 || j == 6) &&
                (i == 1 || i == 3 || i == 5 || i == 7))
                al_draw_bitmap(fou_b_b, x, y, 0);
            if ((plat[i][j].piece == 'f') && (j == 1 || j == 3 || j == 5 || j == 7) &&
                (i == 1 || i == 3 || i == 5 || i == 7))
                al_draw_bitmap(fou_b_n, x, y, 0);
            if ((plat[i][j].piece == 'f') && (j == 0 || j == 2 || j == 4 || j == 6) &&
                (i == 0 || i == 2 || i == 4 || i == 6))
                al_draw_bitmap(fou_b_n, x, y, 0);
            if ((plat[i][j].piece == 'f') && (j == 1 || j == 3 || j == 5 || j == 7) &&
                (i == 0 || i == 2 || i == 4 || i == 6))
                al_draw_bitmap(fou_b_b, x, y, 0);

/* REINES b*/

            if ((plat[i][j].piece == 'r') && (j == 0 || j == 2 || j == 4 || j == 6) &&
                (i == 1 || i == 3 || i == 5 || i == 7))
                al_draw_bitmap(reine_b_b, x, y, 0);
            if ((plat[i][j].piece == 'r') && (j == 1 || j == 3 || j == 5 || j == 7) &&
                (i == 1 || i == 3 || i == 5 || i == 7))
                al_draw_bitmap(reine_b_n, x, y, 0);
            if ((plat[i][j].piece == 'r') && (j == 0 || j == 2 || j == 4 || j == 6) &&
                (i == 0 || i == 2 || i == 4 || i == 6))
                al_draw_bitmap(reine_b_n, x, y, 0);
            if ((plat[i][j].piece == 'r') && (j == 1 || j == 3 || j == 5 || j == 7) &&
                (i == 0 || i == 2 || i == 4 || i == 6))
                al_draw_bitmap(reine_b_b, x, y, 0);

/* ROIS b*/

            if ((plat[i][j].piece == 'x') && (j == 0 || j == 2 || j == 4 || j == 6) &&
                (i == 1 || i == 3 || i == 5 || i == 7))
                al_draw_bitmap(roi_b_b, x, y, 0);
            if ((plat[i][j].piece == 'x') && (j == 1 || j == 3 || j == 5 || j == 7) &&
                (i == 1 || i == 3 || i == 5 || i == 7))
                al_draw_bitmap(roi_b_n, x, y, 0);
            if ((plat[i][j].piece == 'x') && (j == 0 || j == 2 || j == 4 || j == 6) &&
                (i == 0 || i == 2 || i == 4 || i == 6))
                al_draw_bitmap(roi_b_n, x, y, 0);
            if ((plat[i][j].piece == 'x') && (j == 1 || j == 3 || j == 5 || j == 7) &&
                (i == 0 || i == 2 || i == 4 || i == 6))
                al_draw_bitmap(roi_b_b, x, y, 0);

/* PIONS n*/

            if ((plat[i][j].piece == 'P') && (j == 0 || j == 2 || j == 4 || j == 6) &&
                (i == 1 || i == 3 || i == 5 || i == 7))
                al_draw_bitmap(pion_n_b, x, y, 0);
            if ((plat[i][j].piece == 'P') && (j == 1 || j == 3 || j == 5 || j == 7) &&
                (i == 1 || i == 3 || i == 5 || i == 7))
                al_draw_bitmap(pion_n_n, x, y, 0);
            if ((plat[i][j].piece == 'P') && (j == 0 || j == 2 || j == 4 || j == 6) &&
                (i == 0 || i == 2 || i == 4 || i == 6))
                al_draw_bitmap(pion_n_n, x, y, 0);
            if ((plat[i][j].piece == 'P') && (j == 1 || j == 3 || j == 5 || j == 7) &&
                (i == 0 || i == 2 || i == 4 || i == 6))
                al_draw_bitmap(pion_n_b, x, y, 0);


/* CHEVAUX n*/

            if ((plat[i][j].piece == 'C') && (j == 0 || j == 2 || j == 4 || j == 6) &&
                (i == 1 || i == 3 || i == 5 || i == 7))
                al_draw_bitmap(cheval_n_b, x, y, 0);
            if ((plat[i][j].piece == 'C') && (j == 1 || j == 3 || j == 5 || j == 7) &&
                (i == 1 || i == 3 || i == 5 || i == 7))
                al_draw_bitmap(cheval_n_n, x, y, 0);
            if ((plat[i][j].piece == 'C') && (j == 0 || j == 2 || j == 4 || j == 6) &&
                (i == 0 || i == 2 || i == 4 || i == 6))
                al_draw_bitmap(cheval_n_n, x, y, 0);
            if ((plat[i][j].piece == 'C') && (j == 1 || j == 3 || j == 5 || j == 7) &&
                (i == 0 || i == 2 || i == 4 || i == 6))
                al_draw_bitmap(cheval_n_b, x, y, 0);

/* TOURS n*/

            if ((plat[i][j].piece == 'T') && (j == 0 || j == 2 || j == 4 || j == 6) &&
                (i == 1 || i == 3 || i == 5 || i == 7))
                al_draw_bitmap(tour_n_b, x, y, 0);
            if ((plat[i][j].piece == 'T') && (j == 1 || j == 3 || j == 5 || j == 7) &&
                (i == 1 || i == 3 || i == 5 || i == 7))
                al_draw_bitmap(tour_n_n, x, y, 0);
            if ((plat[i][j].piece == 'T') && (j == 0 || j == 2 || j == 4 || j == 6) &&
                (i == 0 || i == 2 || i == 4 || i == 6))
                al_draw_bitmap(tour_n_n, x, y, 0);
            if ((plat[i][j].piece == 'T') && (j == 1 || j == 3 || j == 5 || j == 7) &&
                (i == 0 || i == 2 || i == 4 || i == 6))
                al_draw_bitmap(tour_n_b, x, y, 0);

/* FOUS n*/

            if ((plat[i][j].piece == 'F') && (j == 0 || j == 2 || j == 4 || j == 6) &&
                (i == 1 || i == 3 || i == 5 || i == 7))
                al_draw_bitmap(fou_n_b, x, y, 0);
            if ((plat[i][j].piece == 'F') && (j == 1 || j == 3 || j == 5 || j == 7) &&
                (i == 1 || i == 3 || i == 5 || i == 7))
                al_draw_bitmap(fou_n_n, x, y, 0);
            if ((plat[i][j].piece == 'F') && (j == 0 || j == 2 || j == 4 || j == 6) &&
                (i == 0 || i == 2 || i == 4 || i == 6))
                al_draw_bitmap(fou_n_n, x, y, 0);
            if ((plat[i][j].piece == 'F') && (j == 1 || j == 3 || j == 5 || j == 7) &&
                (i == 0 || i == 2 || i == 4 || i == 6))
                al_draw_bitmap(fou_n_b, x, y, 0);

/* REINES n*/

            if ((plat[i][j].piece == 'R') && (j == 0 || j == 2 || j == 4 || j == 6) &&
                (i == 1 || i == 3 || i == 5 || i == 7))
                al_draw_bitmap(reine_n_b, x, y, 0);
            if ((plat[i][j].piece == 'R') && (j == 1 || j == 3 || j == 5 || j == 7) &&
                (i == 1 || i == 3 || i == 5 || i == 7))
                al_draw_bitmap(reine_n_n, x, y, 0);
            if ((plat[i][j].piece == 'R') && (j == 0 || j == 2 || j == 4 || j == 6) &&
                (i == 0 || i == 2 || i == 4 || i == 6))
                al_draw_bitmap(reine_n_n, x, y, 0);
            if ((plat[i][j].piece == 'R') && (j == 1 || j == 3 || j == 5 || j == 7) &&
                (i == 0 || i == 2 || i == 4 || i == 6))
                al_draw_bitmap(reine_n_b, x, y, 0);

/* ROIS n*/

            if ((plat[i][j].piece == '1') && (j == 0 || j == 2 || j == 4 || j == 6) &&
                (i == 1 || i == 3 || i == 5 || i == 7))
                al_draw_bitmap(roi_n_b, x, y, 0);
            if ((plat[i][j].piece == '1') && (j == 1 || j == 3 || j == 5 || j == 7) &&
                (i == 1 || i == 3 || i == 5 || i == 7))
                al_draw_bitmap(roi_n_n, x, y, 0);
            if ((plat[i][j].piece == '1') && (j == 0 || j == 2 || j == 4 || j == 6) &&
                (i == 0 || i == 2 || i == 4 || i == 6))
                al_draw_bitmap(roi_n_n, x, y, 0);
            if ((plat[i][j].piece == '1') && (j == 1 || j == 3 || j == 5 || j == 7) &&
                (i == 0 || i == 2 || i == 4 || i == 6))
                al_draw_bitmap(roi_n_b, x, y, 0);
            if (plat[i][j].surbrillance == 2)/*manger piece */
                al_draw_rectangle(x + 0.5f, y + 0.5f, x + 60 + 0.5f, y + 60 + 0.5f, al_map_rgb(125, 125, 125), 1);
            if (plat[i][j].surbrillance == 1)/*deplacement*/
                al_draw_filled_rectangle(x + 0.5f, y + 0.5f, x + 60 + 0.5f, y + 60 + 0.5f, al_map_rgb(125, 125, 125));
            if (plat[i][j].surbrillance == 3)/*selection*/
                al_draw_rectangle(x + 0.5f, y + 0.5f, x + 60 + 0.5f, y + 60 + 0.5f, al_map_rgb(255, 50, 100), 1);
        }
        y = y + 70;//On descend d'une ligne en incr�mentent d'une case.
    }

    //al_draw_bitmap(ecran, 0, 0, 0);//On colle notre image � l'�cran.
    //al_destroy_bitmap(ecran);
    al_flip_display();
}

int cases_x(int x) {
    /* Retourne la valeur de la case dans laquelle l'utilisateur a cliqu�. Les paramettres d'entr�e sont les coordonn�es de la souris */
    int j, x1, x0, a = -1;
    x0 = 320;// 385 et 80 sont les coordonn�es de la premi�re case.
    for (j = 1; j <
                9; j++) {// x0 et x1 sont les extr�mit�s horizontale d'une case. A chaque boucle, on incr�mente de la taille d'une case pour d�caler d'une case � droite.
        x1 = j * 70 + 320;
        if (x > x0 && x < x1) {// On regarde si le clic se trouve dans l'intervalle de la case point�e.
            a = j -
                1;//Si c'est le cas, le nombre prend la valeur de 9 fois le num�ro de ligne plus le num�ro de colonne.
        }
        x0 = x1;// pour se d�caler d'une case, la valeur de l'extr�mit� � gauche prend celle de l'extr�mit� qui �tait � droite.
    }
    return (a);
}

int cases_y(int y) {
    /* Retourne la valeur de la case dans laquelle l'utilisateur a cliqu�. Les paramettres d'entr�e sont les coordonn�es de la souris */
    int i, y0, y1, a = -1;
    y0 = 58;
    for (i = 1; i <
                9; i++) {// y0  et y1 repr�sentent les extr�mit�s verticale d'une case. A chaque boucle, on incr�mente de la taille d'une case soit 50, pour descendre � la ligne en dessous.
        y1 = i * 70 + 58;
        if (y > y0 && y < y1) {// On regarde si le clic se trouve dans l'intervalle de la case point�e.
            a = i -
                1;//Si c'est le cas, le nombre prend la valeur de 9 fois le num�ro de ligne plus le num�ro de colonne.
        }
        y0 = y1;// pour se d�caler d'une case, la valeur de l'extr�mit� � gauche prend celle de l'extr�mit� qui �tait � droite.
    }
    return (a);
}

int echap(int x, int y) {/* Retourne la valeur 0 si l'utilisateur a cliqu� sur le bouton quitter */
    int r = 1;
    //x et y sont les coordonn�es de la souris lors du clic.
    if (x > 1075 && x < 1175 && y > 25 && y < 125)//r=0 lorsque l'on clique sur ces coordonn�es
        r = 0;
    return (r);
}

int jouer(ALLEGRO_MOUSE_STATE state) {
    /* Retourne la valeur 0 si l'utilisateur a cliqu� sur le bouton jouer */
    int r = 1;
    //x et y sont les coordonn�es de la souris lors du clic.
    //r=0 lorsque l'on clique sur ces coordonn�es

    if (state.buttons & 1 && state.x > 450 && state.x < 750 && state.y > 250 && state.y < 330) { r = 0; }
    return (r);
}

void initialisation_plt(struct_plt plt[8][8]) {
    int i, j;
    for (i = 2; i < 6; i++) {
        for (j = 0; j < 8; j++) {
            plt[i][j].piece = '0';
            plt[i][j].couleur = VIDE;
            plt[i][j].surbrillance = 0;
        }
    }
    i = 1;
    for (j = 0; j < 8; j++) {
        plt[i][j].piece = 'p';
        plt[i][j].couleur = BLANC;
        plt[i][j].surbrillance = 0;
    }
    i = 6;
    for (j = 0; j < 8; j++) {
        plt[i][j].piece = 'P';
        plt[i][j].couleur = NOIR;
        plt[i][j].surbrillance = 0;
    }
    i = 0;
    j = 0;
    plt[i][j].piece = 't';
    plt[i][j].couleur = BLANC;
    plt[i][j].surbrillance = 0;
    j = 1;
    plt[i][j].piece = 'c';
    plt[i][j].couleur = BLANC;
    plt[i][j].surbrillance = 0;
    j = 2;
    plt[i][j].piece = 'f';
    plt[i][j].couleur = BLANC;
    plt[i][j].surbrillance = 0;
    j = 3;
    plt[i][j].piece = 'r';/* reine blanche */
    plt[i][j].couleur = BLANC;
    plt[i][j].surbrillance = 0;
    j = 4;
    plt[i][j].piece = 'x';/* ROI BLANC */
    plt[i][j].couleur = BLANC;
    plt[i][j].surbrillance = 0;
    j = 5;
    plt[i][j].piece = 'f';
    plt[i][j].couleur = BLANC;
    plt[i][j].surbrillance = 0;
    j = 6;
    plt[i][j].piece = 'c';
    plt[i][j].couleur = BLANC;
    plt[i][j].surbrillance = 0;
    j = 7;
    plt[i][j].piece = 't';
    plt[i][j].couleur = BLANC;
    plt[i][j].surbrillance = 0;
    i = 7;
    j = 0;
    plt[i][j].piece = 'T';
    plt[i][j].couleur = NOIR;
    plt[i][j].surbrillance = 0;
    j = 1;
    plt[i][j].piece = 'C';
    plt[i][j].couleur = NOIR;
    plt[i][j].surbrillance = 0;
    j = 2;
    plt[i][j].piece = 'F';
    plt[i][j].couleur = NOIR;
    plt[i][j].surbrillance = 0;
    j = 3;
    plt[i][j].piece = 'R';/* REINE */
    plt[i][j].couleur = NOIR;
    plt[i][j].surbrillance = 0;
    j = 4;
    plt[i][j].piece = '1';/* ROI */
    plt[i][j].couleur = NOIR;
    plt[i][j].surbrillance = 0;
    j = 5;
    plt[i][j].piece = 'F';
    plt[i][j].couleur = NOIR;
    plt[i][j].surbrillance = 0;
    j = 6;
    plt[i][j].piece = 'C';
    plt[i][j].couleur = NOIR;
    plt[i][j].surbrillance = 0;
    j = 7;
    plt[i][j].piece = 'T';
    plt[i][j].couleur = NOIR;
    plt[i][j].surbrillance = 0;

}

int menu_pause(ALLEGRO_BITMAP *pause) {
    int f = 0;
    al_draw_bitmap(pause, 0, 0, 0);
    al_flip_display();
    ALLEGRO_MOUSE_STATE state;
    do {
        al_get_mouse_state(&state);
/*        if (mouse_b & 1 && cases_y(mouse_y) == 0 && cases_x(mouse_x) == 0) { midi_resume(); }
        if (mouse_b & 1 && cases_y(mouse_y) == 1 && cases_x(mouse_x) == 1) { midi_pause(); }*/
        if (state.buttons & 1 && cases_y(state.y) == 6 && cases_x(state.x) == 0) { f = 5; }
        if (state.buttons & 1 && cases_y(state.y) == 4 && cases_x(state.x) == 6) { f = 1; }
        /* autres saves et config ...*/
    } while (f == 0);
    if (f == 5) { return 5; }
    return 1;
}

void raz_surbrillance(struct_plt plat[8][8]) {
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            plat[i][j].surbrillance = 0;
        }
    }
}
