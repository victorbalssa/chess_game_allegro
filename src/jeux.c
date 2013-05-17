#include <stdio.h>
#include <stdlib.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>

#include "../prototype.h"

#define BLANC 0
#define NOIR 1
#define VIDE 2

int jeu_b(struct_plt plat[8][8], ALLEGRO_BITMAP *plateau, ALLEGRO_BITMAP *pion_b_n, ALLEGRO_BITMAP *pion_b_b,
          ALLEGRO_BITMAP *pion_n_b, ALLEGRO_BITMAP *pion_n_n,
          ALLEGRO_BITMAP *cheval_b_n, ALLEGRO_BITMAP *cheval_b_b, ALLEGRO_BITMAP *cheval_n_b,
          ALLEGRO_BITMAP *cheval_n_n,
          ALLEGRO_BITMAP *tour_b_n, ALLEGRO_BITMAP *tour_b_b, ALLEGRO_BITMAP *tour_n_b, ALLEGRO_BITMAP *tour_n_n,
          ALLEGRO_BITMAP *fou_b_n, ALLEGRO_BITMAP *fou_b_b, ALLEGRO_BITMAP *fou_n_b, ALLEGRO_BITMAP *fou_n_n,
          ALLEGRO_BITMAP *reine_b_n, ALLEGRO_BITMAP *reine_b_b, ALLEGRO_BITMAP *reine_n_b, ALLEGRO_BITMAP *reine_n_n,
          ALLEGRO_BITMAP *roi_b_n, ALLEGRO_BITMAP *roi_b_b, ALLEGRO_BITMAP *roi_n_b,
          ALLEGRO_BITMAP *roi_n_n) {/* fonction permettant le tour des pions blancs */

    ALLEGRO_MOUSE_STATE state;
    ALLEGRO_KEYBOARD_STATE *key_state = NULL;
    ALLEGRO_FONT *font = al_load_font("font/blackWolf.ttf", 20, 0);
    int i = -1, j = -1, fin = 1, f = 0, a, b, g = 1, n = 0;// variable position, quitter.
    al_draw_textf(font, al_map_rgb(255, 255, 255), 475, 20, -1, "C'est aux pions Blancs de jouer !");
    al_flip_display();
    do {
        al_get_mouse_state(&state);
        f = 0;
        if (state.buttons & 1 && plat[cases_y(state.y)][cases_x(state.x)].piece != '0') {
            j = cases_x(state.x);// J COLONNE
            i = cases_y(state.y);// I LIGNE
            switch (plat[i][j].piece) {
                case 'p':
                    plat[i][j].surbrillance = 3;
                    if (plat[i + 1][j].piece == '0') { plat[i + 1][j].surbrillance = 1; }
                    if (plat[i + 2][j].piece == '0' && i == 1 && plat[i + 1][j].piece == '0') {
                        plat[i + 2][j].surbrillance = 1;
                    }
                    if (plat[i + 1][j - 1].piece != '0' && (j - 1 > -1) &&
                        plat[i + 1][j - 1].couleur == NOIR) { plat[i + 1][j - 1].surbrillance = 2; }
                    if (plat[i + 1][j + 1].piece != '0' && (j + 1 < 8) && plat[i + 1][j + 1].couleur == NOIR) {
                        plat[i + 1][j + 1].surbrillance = 2;
                    }
                    affichage_jeux(plat, plateau, pion_b_n, pion_b_b, pion_n_b, pion_n_n,
                                   cheval_b_n, cheval_b_b, cheval_n_b, cheval_n_n,
                                   tour_b_n, tour_b_b, tour_n_b, tour_n_n,
                                   fou_b_n, fou_b_b, fou_n_b, fou_n_n,
                                   reine_b_n, reine_b_b, reine_n_b, reine_n_n,
                                   roi_b_n, roi_b_b, roi_n_b, roi_n_n);
                    al_draw_textf(font, al_map_rgb(255, 255, 255), 475, 20, -1, "I: %i J: %i", i, j);
                    al_flip_display();
                    do {
                        al_get_mouse_state(&state);
                        if (state.buttons & 1 && plat[cases_y(state.y)][cases_x(state.x)].surbrillance == 1) {
                            plat[i][j].piece = '0';
                            plat[i][j].couleur = VIDE;
                            plat[cases_y(state.y)][cases_x(state.x)].piece = 'p';
                            plat[cases_y(state.y)][cases_x(state.x)].couleur = BLANC;
                            f = 2;
                        }
                        if (state.buttons & 1 && plat[cases_y(state.y)][cases_x(state.x)].surbrillance == 2) {
                            plat[i][j].piece = '0';
                            plat[i][j].couleur = VIDE;
                            plat[cases_y(state.y)][cases_x(state.x)].piece = 'p';
                            plat[cases_y(state.y)][cases_x(state.x)].couleur = BLANC;
                            f = 2;
                        }
                        if (state.buttons & 1 && echap(state.x, state.y) == 0) {
                            raz_surbrillance(plat);
                            affichage_jeux(plat, plateau, pion_b_n, pion_b_b, pion_n_b, pion_n_n, cheval_b_n,
                                           cheval_b_b, cheval_n_b, cheval_n_n,
                                           tour_b_n, tour_b_b, tour_n_b, tour_n_n,
                                           fou_b_n, fou_b_b, fou_n_b, fou_n_n,
                                           reine_b_n, reine_b_b, reine_n_b, reine_n_n,
                                           roi_b_n, roi_b_b, roi_n_b, roi_n_n);
                            f = 1;
                        }
                    } while (f == 0);
                    raz_surbrillance(plat);
                    break;
                case 'c':
                    plat[i][j].surbrillance = 3;

                    if (plat[i + 1][j + 2].piece == '0' && (j + 2 < 8)) { plat[i + 1][j + 2].surbrillance = 1; }
                    if (plat[i + 2][j + 1].piece == '0' && (j + 1 < 8)) { plat[i + 2][j + 1].surbrillance = 1; }
                    if (plat[i + 1][j - 2].piece == '0' && (j - 2 > -1)) { plat[i + 1][j - 2].surbrillance = 1; }
                    if (plat[i + 2][j - 1].piece == '0' && (j - 1 > -1)) { plat[i + 2][j - 1].surbrillance = 1; }
                    if (plat[i - 1][j + 2].piece == '0' && (j + 2 < 8)) { plat[i - 1][j + 2].surbrillance = 1; }
                    if (plat[i - 2][j + 1].piece == '0' && (j + 2 < 8)) { plat[i - 2][j + 1].surbrillance = 1; }
                    if (plat[i - 1][j - 2].piece == '0' && (j - 2 > -1)) { plat[i - 1][j - 2].surbrillance = 1; }
                    if (plat[i - 2][j - 1].piece == '0' && (j - 1 > -1)) { plat[i - 2][j - 1].surbrillance = 1; }

                    if (plat[i + 1][j + 2].piece != '0' && plat[i + 1][j + 2].couleur == NOIR && (j + 2 < 8)) {
                        plat[i + 1][j + 2].surbrillance = 2;
                    }
                    if (plat[i + 2][j + 1].piece != '0' && plat[i + 2][j + 1].couleur == NOIR && (j + 1 < 8)) {
                        plat[i + 2][j + 1].surbrillance = 2;
                    }
                    if (plat[i + 1][j - 2].piece != '0' && plat[i + 1][j - 2].couleur == NOIR &&
                        (j - 2 > -1)) { plat[i + 1][j - 2].surbrillance = 2; }
                    if (plat[i + 2][j - 1].piece != '0' && plat[i + 2][j - 1].couleur == NOIR &&
                        (j - 1 > -1)) { plat[i + 2][j - 1].surbrillance = 2; }
                    if (plat[i - 1][j + 2].piece != '0' && plat[i - 1][j + 2].couleur == NOIR && (j + 2 < 8)) {
                        plat[i - 1][j + 2].surbrillance = 2;
                    }
                    if (plat[i - 2][j + 1].piece != '0' && plat[i - 2][j + 1].couleur == NOIR && (j + 1 < 8)) {
                        plat[i - 2][j + 1].surbrillance = 2;
                    }
                    if (plat[i - 1][j - 2].piece != '0' && plat[i - 1][j - 2].couleur == NOIR &&
                        (j - 2 > -1)) { plat[i - 1][j - 2].surbrillance = 2; }
                    if (plat[i - 2][j - 1].piece != '0' && plat[i - 2][j - 1].couleur == NOIR &&
                        (j - 1 > -1)) { plat[i - 2][j - 1].surbrillance = 2; }

                    affichage_jeux(plat, plateau, pion_b_n, pion_b_b, pion_n_b, pion_n_n, cheval_b_n, cheval_b_b,
                                   cheval_n_b, cheval_n_n,
                                   tour_b_n, tour_b_b, tour_n_b, tour_n_n,
                                   fou_b_n, fou_b_b, fou_n_b, fou_n_n,
                                   reine_b_n, reine_b_b, reine_n_b, reine_n_n,
                                   roi_b_n, roi_b_b, roi_n_b, roi_n_n);
                    al_draw_textf(font, al_map_rgb(255, 255, 255), 475, 20, -1, "I: %i J: %i", i, j);
                    al_flip_display();
                    do {
                        al_get_mouse_state(&state);
                        if (state.buttons & 1 && plat[cases_y(state.y)][cases_x(state.x)].surbrillance == 1) {
                            plat[i][j].piece = '0';
                            plat[i][j].couleur = VIDE;
                            plat[cases_y(state.y)][cases_x(state.x)].piece = 'c';
                            plat[cases_y(state.y)][cases_x(state.x)].couleur = BLANC;
                            f = 2;
                        }
                        if (state.buttons & 1 && plat[cases_y(state.y)][cases_x(state.x)].surbrillance == 2) {
                            plat[i][j].piece = '0';
                            plat[i][j].couleur = VIDE;
                            plat[cases_y(state.y)][cases_x(state.x)].piece = 'c';
                            plat[cases_y(state.y)][cases_x(state.x)].couleur = BLANC;
                            f = 2;
                        }
                        if (state.buttons & 1 && echap(state.x, state.y) == 0) {
                            raz_surbrillance(plat);
                            affichage_jeux(plat, plateau, pion_b_n, pion_b_b, pion_n_b, pion_n_n, cheval_b_n,
                                           cheval_b_b, cheval_n_b, cheval_n_n,
                                           tour_b_n, tour_b_b, tour_n_b, tour_n_n,
                                           fou_b_n, fou_b_b, fou_n_b, fou_n_n,
                                           reine_b_n, reine_b_b, reine_n_b, reine_n_n,
                                           roi_b_n, roi_b_b, roi_n_b, roi_n_n);
                            f = 1;
                        }

                    } while (f == 0);
                    raz_surbrillance(plat);
                    break;

                case 't':
                    plat[i][j].surbrillance = 3;
                    a = i;
                    b = j;
                    while (a < 7 && g == 1) {
                        a++;
                        if (plat[a][b].piece == '0') { plat[a][b].surbrillance = 1; }
                        if (plat[a][b].couleur == BLANC) { g = 0; }
                        if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) {
                            plat[a][b].surbrillance = 2;
                            g = 0;
                        }
                    }
                    a = i;
                    b = j;
                    g = 1;
                    while (a > 0 && g == 1) {
                        a--;
                        if (plat[a][b].piece == '0') { plat[a][b].surbrillance = 1; }
                        if (plat[a][b].couleur == BLANC) { g = 0; }
                        if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) {
                            plat[a][b].surbrillance = 2;
                            g = 0;
                        }
                    }
                    a = i;
                    b = j;
                    g = 1;
                    while (b < 7 && g == 1) {
                        b++;
                        if (plat[a][b].piece == '0') { plat[a][b].surbrillance = 1; }
                        if (plat[a][b].couleur == BLANC) { g = 0; }
                        if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) {
                            plat[a][b].surbrillance = 2;
                            g = 0;
                        }
                    }
                    a = i;
                    b = j;
                    g = 1;
                    while (b > 0 && g == 1) {
                        b--;
                        if (plat[a][b].couleur == BLANC) { g = 0; }
                        if (plat[a][b].piece == '0') { plat[a][b].surbrillance = 1; }
                        if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) {
                            plat[a][b].surbrillance = 2;
                            g = 0;
                        }
                    }

                    affichage_jeux(plat, plateau, pion_b_n, pion_b_b, pion_n_b, pion_n_n, cheval_b_n, cheval_b_b,
                                   cheval_n_b, cheval_n_n,
                                   tour_b_n, tour_b_b, tour_n_b, tour_n_n,
                                   fou_b_n, fou_b_b, fou_n_b, fou_n_n,
                                   reine_b_n, reine_b_b, reine_n_b, reine_n_n,
                                   roi_b_n, roi_b_b, roi_n_b, roi_n_n);
                    al_draw_textf(font, al_map_rgb(255, 255, 255), 475, 20, -1, "I: %i J: %i", i, j);
                    al_flip_display();
                    do {
                        if (state.buttons & 1 && plat[cases_y(state.y)][cases_x(state.x)].surbrillance == 1) {
                            plat[i][j].piece = '0';
                            plat[i][j].couleur = VIDE;
                            plat[cases_y(state.y)][cases_x(state.x)].piece = 't';
                            plat[cases_y(state.y)][cases_x(state.x)].couleur = BLANC;
                            f = 2;
                        }
                        if (state.buttons & 1 && plat[cases_y(state.y)][cases_x(state.x)].surbrillance == 2) {
                            plat[i][j].piece = '0';
                            plat[i][j].couleur = VIDE;
                            plat[cases_y(state.y)][cases_x(state.x)].piece = 't';
                            plat[cases_y(state.y)][cases_x(state.x)].couleur = BLANC;
                            f = 2;
                        }
                        if (state.buttons & 1 && echap(state.x, state.y) == 0) {
                            raz_surbrillance(plat);
                            affichage_jeux(plat, plateau, pion_b_n, pion_b_b, pion_n_b, pion_n_n, cheval_b_n,
                                           cheval_b_b, cheval_n_b, cheval_n_n,
                                           tour_b_n, tour_b_b, tour_n_b, tour_n_n,
                                           fou_b_n, fou_b_b, fou_n_b, fou_n_n,
                                           reine_b_n, reine_b_b, reine_n_b, reine_n_n,
                                           roi_b_n, roi_b_b, roi_n_b, roi_n_n);
                            f = 1;
                        }


                    } while (f == 0);
                    raz_surbrillance(plat);
                    break;
                case 'f':
                    plat[i][j].surbrillance = 3;
                    a = i;
                    b = j;
                    while (a < 7 && b < 7 && g == 1) {
                        a++;
                        b++;
                        if (plat[a][b].piece == '0') { plat[a][b].surbrillance = 1; }
                        if (plat[a][b].couleur == BLANC) { g = 0; }
                        if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) {
                            plat[a][b].surbrillance = 2;
                            g = 0;
                        }
                    }
                    a = i;
                    b = j;
                    g = 1;
                    while (a > 0 && b > 0 && g == 1) {
                        a--;
                        b--;
                        if (plat[a][b].piece == '0') { plat[a][b].surbrillance = 1; }
                        if (plat[a][b].couleur == BLANC) { g = 0; }
                        if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) {
                            plat[a][b].surbrillance = 2;
                            g = 0;
                        }
                    }
                    a = i;
                    b = j;
                    g = 1;
                    while (a < 7 && b > 0 && g == 1) {
                        a++;
                        b--;
                        if (plat[a][b].piece == '0') { plat[a][b].surbrillance = 1; }
                        if (plat[a][b].couleur == BLANC) { g = 0; }
                        if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) {
                            plat[a][b].surbrillance = 2;
                            g = 0;
                        }
                    }
                    a = i;
                    b = j;
                    g = 1;
                    while (a > 0 && b < 7 && g == 1) {
                        b++;
                        a--;
                        if (plat[a][b].couleur == BLANC) { g = 0; }
                        if (plat[a][b].piece == '0') { plat[a][b].surbrillance = 1; }
                        if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) {
                            plat[a][b].surbrillance = 2;
                            g = 0;
                        }
                    }

                    affichage_jeux(plat, plateau, pion_b_n, pion_b_b, pion_n_b, pion_n_n, cheval_b_n, cheval_b_b,
                                   cheval_n_b, cheval_n_n,
                                   tour_b_n, tour_b_b, tour_n_b, tour_n_n,
                                   fou_b_n, fou_b_b, fou_n_b, fou_n_n,
                                   reine_b_n, reine_b_b, reine_n_b, reine_n_n,
                                   roi_b_n, roi_b_b, roi_n_b, roi_n_n);
                    al_draw_textf(font, al_map_rgb(255, 255, 255), 475, 20, -1, "I: %i J: %i", i, j);
                    al_flip_display();
                    do {
                        al_get_mouse_state(&state);
                        if (state.buttons & 1 && plat[cases_y(state.y)][cases_x(state.x)].surbrillance == 1) {
                            plat[i][j].piece = '0';
                            plat[i][j].couleur = VIDE;
                            plat[cases_y(state.y)][cases_x(state.x)].piece = 'f';
                            plat[cases_y(state.y)][cases_x(state.x)].couleur = BLANC;
                            f = 2;
                        }
                        if (state.buttons & 1 && plat[cases_y(state.y)][cases_x(state.x)].surbrillance == 2) {
                            plat[i][j].piece = '0';
                            plat[i][j].couleur = VIDE;
                            plat[cases_y(state.y)][cases_x(state.x)].piece = 'f';
                            plat[cases_y(state.y)][cases_x(state.x)].couleur = BLANC;
                            f = 2;
                        }
                        if (state.buttons & 1 && echap(state.x, state.y) == 0) {
                            raz_surbrillance(plat);
                            affichage_jeux(plat, plateau, pion_b_n, pion_b_b, pion_n_b, pion_n_n, cheval_b_n,
                                           cheval_b_b, cheval_n_b, cheval_n_n,
                                           tour_b_n, tour_b_b, tour_n_b, tour_n_n,
                                           fou_b_n, fou_b_b, fou_n_b, fou_n_n,
                                           reine_b_n, reine_b_b, reine_n_b, reine_n_n,
                                           roi_b_n, roi_b_b, roi_n_b, roi_n_n);
                            f = 1;
                        }


                    } while (f == 0);
                    raz_surbrillance(plat);
                    break;

                case 'r':
                    plat[i][j].surbrillance = 3;
                    a = i;
                    b = j;
                    while (a < 7 && b < 7 && g == 1) {
                        a++;
                        b++;
                        if (plat[a][b].piece == '0') { plat[a][b].surbrillance = 1; }
                        if (plat[a][b].couleur == BLANC) { g = 0; }
                        if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) {
                            plat[a][b].surbrillance = 2;
                            g = 0;
                        }
                    }
                    a = i;
                    b = j;
                    g = 1;
                    while (a > 0 && b > 0 && g == 1) {
                        a--;
                        b--;
                        if (plat[a][b].piece == '0') { plat[a][b].surbrillance = 1; }
                        if (plat[a][b].couleur == BLANC) { g = 0; }
                        if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) {
                            plat[a][b].surbrillance = 2;
                            g = 0;
                        }
                    }
                    a = i;
                    b = j;
                    g = 1;
                    while (a < 7 && b > 0 && g == 1) {
                        a++;
                        b--;
                        if (plat[a][b].piece == '0') { plat[a][b].surbrillance = 1; }
                        if (plat[a][b].couleur == BLANC) { g = 0; }
                        if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) {
                            plat[a][b].surbrillance = 2;
                            g = 0;
                        }
                    }
                    a = i;
                    b = j;
                    g = 1;
                    while (a > 0 && b < 7 && g == 1) {
                        b++;
                        a--;
                        if (plat[a][b].couleur == BLANC) { g = 0; }
                        if (plat[a][b].piece == '0') { plat[a][b].surbrillance = 1; }
                        if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) {
                            plat[a][b].surbrillance = 2;
                            g = 0;
                        }
                    }
                    a = i;
                    b = j;
                    while (a < 7 && g == 1) {
                        a++;
                        if (plat[a][b].piece == '0') { plat[a][b].surbrillance = 1; }
                        if (plat[a][b].couleur == BLANC) { g = 0; }
                        if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) {
                            plat[a][b].surbrillance = 2;
                            g = 0;
                        }
                    }
                    a = i;
                    b = j;
                    g = 1;
                    while (a > 0 && g == 1) {
                        a--;
                        if (plat[a][b].piece == '0') { plat[a][b].surbrillance = 1; }
                        if (plat[a][b].couleur == BLANC) { g = 0; }
                        if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) {
                            plat[a][b].surbrillance = 2;
                            g = 0;
                        }
                    }
                    a = i;
                    b = j;
                    g = 1;
                    while (b < 7 && g == 1) {
                        b++;
                        if (plat[a][b].piece == '0') { plat[a][b].surbrillance = 1; }
                        if (plat[a][b].couleur == BLANC) { g = 0; }
                        if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) {
                            plat[a][b].surbrillance = 2;
                            g = 0;
                        }
                    }
                    a = i;
                    b = j;
                    g = 1;
                    while (b > 0 && g == 1) {
                        b--;
                        if (plat[a][b].couleur == BLANC) { g = 0; }
                        if (plat[a][b].piece == '0') { plat[a][b].surbrillance = 1; }
                        if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) {
                            plat[a][b].surbrillance = 2;
                            g = 0;
                        }
                    }

                    affichage_jeux(plat, plateau, pion_b_n, pion_b_b, pion_n_b, pion_n_n, cheval_b_n, cheval_b_b,
                                   cheval_n_b, cheval_n_n,
                                   tour_b_n, tour_b_b, tour_n_b, tour_n_n,
                                   fou_b_n, fou_b_b, fou_n_b, fou_n_n,
                                   reine_b_n, reine_b_b, reine_n_b, reine_n_n,
                                   roi_b_n, roi_b_b, roi_n_b, roi_n_n);
                    al_draw_textf(font, al_map_rgb(255, 255, 255), 475, 20, -1, "I: %i J: %i", i, j);
                    al_flip_display();
                    do {
                        al_get_mouse_state(&state);
                        if (state.buttons & 1 && plat[cases_y(state.y)][cases_x(state.x)].surbrillance == 1) {
                            plat[i][j].piece = '0';
                            plat[i][j].couleur = VIDE;
                            plat[cases_y(state.y)][cases_x(state.x)].piece = 'r';
                            plat[cases_y(state.y)][cases_x(state.x)].couleur = BLANC;
                            f = 2;
                        }
                        if (state.buttons & 1 && plat[cases_y(state.y)][cases_x(state.x)].surbrillance == 2) {
                            plat[i][j].piece = '0';
                            plat[i][j].couleur = VIDE;
                            plat[cases_y(state.y)][cases_x(state.x)].piece = 'r';
                            plat[cases_y(state.y)][cases_x(state.x)].couleur = BLANC;
                            f = 2;
                        }
                        if (state.buttons & 1 && echap(state.x, state.y) == 0) {
                            raz_surbrillance(plat);
                            affichage_jeux(plat, plateau, pion_b_n, pion_b_b, pion_n_b, pion_n_n, cheval_b_n,
                                           cheval_b_b, cheval_n_b, cheval_n_n,
                                           tour_b_n, tour_b_b, tour_n_b, tour_n_n,
                                           fou_b_n, fou_b_b, fou_n_b, fou_n_n,
                                           reine_b_n, reine_b_b, reine_n_b, reine_n_n,
                                           roi_b_n, roi_b_b, roi_n_b, roi_n_n);
                            f = 1;
                        }

                    } while (f == 0);
                    raz_surbrillance(plat);
                    break;

                case '0':
                    plat[i][j].surbrillance = 3;
                    if (echec_roi(plat, BLANC, i, j) == 1) { n++; }
                    if (echec_roi(plat, BLANC, i - 1, j) == 0 && plat[i - 1][j].piece == '0') {
                        plat[i - 1][j].surbrillance = 1;
                    }
                    if (echec_roi(plat, BLANC, i - 1, j - 1) == 0 && plat[i - 1][j - 1].piece == '0') {
                        plat[i - 1][j - 1].surbrillance = 1;
                    }
                    if (echec_roi(plat, BLANC, i, j - 1) == 0 && plat[i][j - 1].piece == '0') {
                        plat[i][j - 1].surbrillance = 1;
                    }
                    if (echec_roi(plat, BLANC, i + 1, j - 1) == 0 && plat[i + 1][j - 1].piece == '0') {
                        plat[i + 1][j - 1].surbrillance = 1;
                    }
                    if (echec_roi(plat, BLANC, i + 1, j) == 0 && plat[i + 1][j].piece == '0') {
                        plat[i + 1][j].surbrillance = 1;
                    }
                    if (echec_roi(plat, BLANC, i + 1, j + 1) == 0 && plat[i + 1][j + 1].piece == '0') {
                        plat[i + 1][j + 1].surbrillance = 1;
                    }
                    if (echec_roi(plat, BLANC, i, j + 1) == 0 && plat[i][j + 1].piece == '0') {
                        plat[i][j + 1].surbrillance = 1;
                    }
                    if (echec_roi(plat, BLANC, i - 1, j + 1) == 0 && plat[i - 1][j + 1].piece == '0') {
                        plat[i - 1][j + 1].surbrillance = 1;
                    }


                    affichage_jeux(plat, plateau, pion_b_n, pion_b_b, pion_n_b, pion_n_n, cheval_b_n, cheval_b_b,
                                   cheval_n_b, cheval_n_n,
                                   tour_b_n, tour_b_b, tour_n_b, tour_n_n,
                                   fou_b_n, fou_b_b, fou_n_b, fou_n_n,
                                   reine_b_n, reine_b_b, reine_n_b, reine_n_n,
                                   roi_b_n, roi_b_b, roi_n_b, roi_n_n);
                    al_draw_textf(font, al_map_rgb(255, 255, 255), 475, 20, -1, "I: %i J: %i", i, j);
                    al_flip_display();

                    do {
                        al_get_mouse_state(&state);
                        if (state.buttons & 1 && plat[cases_y(state.y)][cases_x(state.x)].surbrillance == 1) {
                            plat[i][j].piece = '0';
                            plat[i][j].couleur = VIDE;
                            plat[cases_y(state.y)][cases_x(state.x)].piece = '0';
                            plat[cases_y(state.y)][cases_x(state.x)].couleur = BLANC;
                            f = 2;
                        }
                        if (state.buttons & 1 && plat[cases_y(state.y)][cases_x(state.x)].surbrillance == 2) {
                            plat[i][j].piece = '0';
                            plat[i][j].couleur = VIDE;
                            plat[cases_y(state.y)][cases_x(state.x)].piece = '0';
                            plat[cases_y(state.y)][cases_x(state.x)].couleur = BLANC;
                            f = 2;
                        }
                        if (state.buttons & 1 && echap(state.x, state.y) == 0) {
                            raz_surbrillance(plat);
                            affichage_jeux(plat, plateau, pion_b_n, pion_b_b, pion_n_b, pion_n_n, cheval_b_n,
                                           cheval_b_b, cheval_n_b, cheval_n_n,
                                           tour_b_n, tour_b_b, tour_n_b, tour_n_n,
                                           fou_b_n, fou_b_b, fou_n_b, fou_n_n,
                                           reine_b_n, reine_b_b, reine_n_b, reine_n_n,
                                           roi_b_n, roi_b_b, roi_n_b, roi_n_n);
                            f = 1;
                        }

                    } while (f == 0);
                    raz_surbrillance(plat);
                    break;
                default:
                    break;
            }
        }
    } while (f != 2);
    if (n != 0) { return 7; }
    if (f == 2) { return 0; }
    else { return (1); }
}

int jeu_n(struct_plt plat[8][8], ALLEGRO_BITMAP *plateau, ALLEGRO_BITMAP *pion_b_n,
          ALLEGRO_BITMAP *pion_b_b, ALLEGRO_BITMAP *pion_n_b, ALLEGRO_BITMAP *pion_n_n,
          ALLEGRO_BITMAP *cheval_b_n, ALLEGRO_BITMAP *cheval_b_b, ALLEGRO_BITMAP *cheval_n_b,
          ALLEGRO_BITMAP *cheval_n_n,
          ALLEGRO_BITMAP *tour_b_n, ALLEGRO_BITMAP *tour_b_b, ALLEGRO_BITMAP *tour_n_b, ALLEGRO_BITMAP *tour_n_n,
          ALLEGRO_BITMAP *fou_b_n, ALLEGRO_BITMAP *fou_b_b, ALLEGRO_BITMAP *fou_n_b, ALLEGRO_BITMAP *fou_n_n,
          ALLEGRO_BITMAP *reine_b_n, ALLEGRO_BITMAP *reine_b_b, ALLEGRO_BITMAP *reine_n_b, ALLEGRO_BITMAP *reine_n_n,
          ALLEGRO_BITMAP *roi_b_n, ALLEGRO_BITMAP *roi_b_b, ALLEGRO_BITMAP *roi_n_b,
          ALLEGRO_BITMAP *roi_n_n) {/* fonction permettant le tour des pions noirs */

    ALLEGRO_MOUSE_STATE state;
    ALLEGRO_KEYBOARD_STATE *key_state = NULL;
    ALLEGRO_FONT *font = al_load_font("font/blackWolf.ttf", 20, 0);
    int i = -1, j = -1, fin = 1, f = 0, a, b, g = 1, n = 0;// variables: position, quitter.
    al_draw_textf(font, al_map_rgb(255, 255, 255), 475, 20, -1, "C'est aux pions Noirs de jouer !");
    al_flip_display();
    do {
        al_get_mouse_state(&state);
        f = 0;
        if (state.buttons & 1 && plat[cases_y(state.y)][cases_x(state.x)].piece != '0') {
            j = cases_x(state.x);// J COLONNE
            i = cases_y(state.y);// I LIGNE
            switch (plat[i][j].piece) {
                case 'P':
                    plat[i][j].surbrillance = 3;
                    if (plat[i - 1][j].piece == '0') { plat[i - 1][j].surbrillance = 1; }
                    if (plat[i - 2][j].piece == '0' && i == 6 && plat[i - 1][j].piece == '0') {
                        plat[i - 2][j].surbrillance = 1;
                    }
                    if (plat[i - 1][j - 1].piece != '0' && (j - 1 > -1) &&
                        plat[i - 1][j - 1].couleur == BLANC) { plat[i - 1][j - 1].surbrillance = 2; }
                    if (plat[i - 1][j + 1].piece != '0' && (j + 1 < 8) &&
                        plat[i - 1][j + 1].couleur == BLANC) { plat[i - 1][j + 1].surbrillance = 2; }
                    affichage_jeux(plat, plateau, pion_b_n, pion_b_b, pion_n_b, pion_n_n,
                                   cheval_b_n, cheval_b_b, cheval_n_b, cheval_n_n,
                                   tour_b_n, tour_b_b, tour_n_b, tour_n_n,
                                   fou_b_n, fou_b_b, fou_n_b, fou_n_n,
                                   reine_b_n, reine_b_b, reine_n_b, reine_n_n,
                                   roi_b_n, roi_b_b, roi_n_b, roi_n_n);
                    al_draw_textf(font, al_map_rgb(255, 255, 255), 475, 20, -1, "I: %i J: %i", i, j);
                    al_flip_display();
                    do {
                        al_get_mouse_state(&state);
                        if (state.buttons & 1 && plat[cases_y(state.y)][cases_x(state.x)].surbrillance == 1) {
                            plat[i][j].piece = '0';
                            plat[i][j].couleur = VIDE;
                            plat[cases_y(state.y)][cases_x(state.x)].piece = 'P';
                            plat[cases_y(state.y)][cases_x(state.x)].couleur = NOIR;
                            f = 2;
                        }
                        if (state.buttons & 1 && plat[cases_y(state.y)][cases_x(state.x)].surbrillance == 2) {
                            plat[i][j].piece = '0';
                            plat[i][j].couleur = VIDE;
                            plat[cases_y(state.y)][cases_x(state.x)].piece = 'P';
                            plat[cases_y(state.y)][cases_x(state.x)].couleur = NOIR;
                            f = 2;
                        }
                        if (state.buttons & 1 && echap(state.x, state.y) == 0) {
                            raz_surbrillance(plat);
                            affichage_jeux(plat, plateau, pion_b_n, pion_b_b, pion_n_b, pion_n_n, cheval_b_n,
                                           cheval_b_b, cheval_n_b, cheval_n_n,
                                           tour_b_n, tour_b_b, tour_n_b, tour_n_n,
                                           fou_b_n, fou_b_b, fou_n_b, fou_n_n,
                                           reine_b_n, reine_b_b, reine_n_b, reine_n_n,
                                           roi_b_n, roi_b_b, roi_n_b, roi_n_n);
                            f = 1;
                        }
                    } while (f == 0);
                    raz_surbrillance(plat);
                    break;
                case 'C':
                    plat[i][j].surbrillance = 3;

                    if (plat[i + 1][j + 2].piece == '0' && (j + 2 < 8)) { plat[i + 1][j + 2].surbrillance = 1; }
                    if (plat[i + 2][j + 1].piece == '0' && (j + 1 < 8)) { plat[i + 2][j + 1].surbrillance = 1; }
                    if (plat[i + 1][j - 2].piece == '0' && (j - 2 > -1)) { plat[i + 1][j - 2].surbrillance = 1; }
                    if (plat[i + 2][j - 1].piece == '0' && (j - 1 > -1)) { plat[i + 2][j - 1].surbrillance = 1; }
                    if (plat[i - 1][j + 2].piece == '0' && (j + 2 < 8)) { plat[i - 1][j + 2].surbrillance = 1; }
                    if (plat[i - 2][j + 1].piece == '0' && (j + 2 < 8)) { plat[i - 2][j + 1].surbrillance = 1; }
                    if (plat[i - 1][j - 2].piece == '0' && (j - 2 > -1)) { plat[i - 1][j - 2].surbrillance = 1; }
                    if (plat[i - 2][j - 1].piece == '0' && (j - 1 > -1)) { plat[i - 2][j - 1].surbrillance = 1; }

                    if (plat[i + 1][j + 2].piece != '0' && plat[i + 1][j + 2].couleur == BLANC &&
                        (j + 2 < 8)) { plat[i + 1][j + 2].surbrillance = 2; }
                    if (plat[i + 2][j + 1].piece != '0' && plat[i + 2][j + 1].couleur == BLANC &&
                        (j + 1 < 8)) { plat[i + 2][j + 1].surbrillance = 2; }
                    if (plat[i + 1][j - 2].piece != '0' && plat[i + 1][j - 2].couleur == BLANC &&
                        (j - 2 > -1)) { plat[i + 1][j - 2].surbrillance = 2; }
                    if (plat[i + 2][j - 1].piece != '0' && plat[i + 2][j - 1].couleur == BLANC &&
                        (j - 1 > -1)) { plat[i + 2][j - 1].surbrillance = 2; }
                    if (plat[i - 1][j + 2].piece != '0' && plat[i - 1][j + 2].couleur == BLANC &&
                        (j + 2 < 8)) { plat[i - 1][j + 2].surbrillance = 2; }
                    if (plat[i - 2][j + 1].piece != '0' && plat[i - 2][j + 1].couleur == BLANC &&
                        (j + 1 < 8)) { plat[i - 2][j + 1].surbrillance = 2; }
                    if (plat[i - 1][j - 2].piece != '0' && plat[i - 1][j - 2].couleur == BLANC &&
                        (j - 2 > -1)) { plat[i - 1][j - 2].surbrillance = 2; }
                    if (plat[i - 2][j - 1].piece != '0' && plat[i - 2][j - 1].couleur == BLANC &&
                        (j - 1 > -1)) { plat[i - 2][j - 1].surbrillance = 2; }

                    affichage_jeux(plat, plateau, pion_b_n, pion_b_b, pion_n_b, pion_n_n, cheval_b_n, cheval_b_b,
                                   cheval_n_b, cheval_n_n,
                                   tour_b_n, tour_b_b, tour_n_b, tour_n_n,
                                   fou_b_n, fou_b_b, fou_n_b, fou_n_n,
                                   reine_b_n, reine_b_b, reine_n_b, reine_n_n,
                                   roi_b_n, roi_b_b, roi_n_b, roi_n_n);
                    al_draw_textf(font, al_map_rgb(255, 255, 255), 475, 20, -1, "I: %i J: %i", i, j);
                    al_flip_display();
                    do {
                        al_get_mouse_state(&state);
                        if (state.buttons & 1 && plat[cases_y(state.y)][cases_x(state.x)].surbrillance == 1) {
                            plat[i][j].piece = '0';
                            plat[i][j].couleur = VIDE;
                            plat[cases_y(state.y)][cases_x(state.x)].piece = 'C';
                            plat[cases_y(state.y)][cases_x(state.x)].couleur = NOIR;
                            f = 2;
                        }
                        if (state.buttons & 1 && plat[cases_y(state.y)][cases_x(state.x)].surbrillance == 2) {
                            plat[i][j].piece = '0';
                            plat[i][j].couleur = VIDE;
                            plat[cases_y(state.y)][cases_x(state.x)].piece = 'C';
                            plat[cases_y(state.y)][cases_x(state.x)].couleur = NOIR;
                            f = 2;
                        }
                        if (state.buttons & 1 && echap(state.x, state.y) == 0) {
                            raz_surbrillance(plat);
                            affichage_jeux(plat, plateau, pion_b_n, pion_b_b, pion_n_b, pion_n_n, cheval_b_n,
                                           cheval_b_b, cheval_n_b, cheval_n_n,
                                           tour_b_n, tour_b_b, tour_n_b, tour_n_n,
                                           fou_b_n, fou_b_b, fou_n_b, fou_n_n,
                                           reine_b_n, reine_b_b, reine_n_b, reine_n_n,
                                           roi_b_n, roi_b_b, roi_n_b, roi_n_n);
                            f = 1;
                        }

                    } while (f == 0);
                    raz_surbrillance(plat);
                    break;

                case 'T':
                    plat[i][j].surbrillance = 3;
                    a = i;
                    b = j;
                    while (a < 7 && g == 1) {
                        a++;
                        if (plat[a][b].piece == '0') { plat[a][b].surbrillance = 1; }
                        if (plat[a][b].couleur == NOIR) { g = 0; }
                        if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) {
                            plat[a][b].surbrillance = 2;
                            g = 0;
                        }
                    }
                    a = i;
                    b = j;
                    g = 1;
                    while (a > 0 && g == 1) {
                        a--;
                        if (plat[a][b].piece == '0') { plat[a][b].surbrillance = 1; }
                        if (plat[a][b].couleur == NOIR) { g = 0; }
                        if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) {
                            plat[a][b].surbrillance = 2;
                            g = 0;
                        }
                    }
                    a = i;
                    b = j;
                    g = 1;
                    while (b < 7 && g == 1) {
                        b++;
                        if (plat[a][b].piece == '0') { plat[a][b].surbrillance = 1; }
                        if (plat[a][b].couleur == NOIR) { g = 0; }
                        if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) {
                            plat[a][b].surbrillance = 2;
                            g = 0;
                        }
                    }
                    a = i;
                    b = j;
                    g = 1;
                    while (b > 0 && g == 1) {
                        b--;
                        if (plat[a][b].couleur == NOIR) { g = 0; }
                        if (plat[a][b].piece == '0') { plat[a][b].surbrillance = 1; }
                        if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) {
                            plat[a][b].surbrillance = 2;
                            g = 0;
                        }
                    }

                    affichage_jeux(plat, plateau, pion_b_n, pion_b_b, pion_n_b, pion_n_n, cheval_b_n, cheval_b_b,
                                   cheval_n_b, cheval_n_n,
                                   tour_b_n, tour_b_b, tour_n_b, tour_n_n,
                                   fou_b_n, fou_b_b, fou_n_b, fou_n_n,
                                   reine_b_n, reine_b_b, reine_n_b, reine_n_n,
                                   roi_b_n, roi_b_b, roi_n_b, roi_n_n);
                    al_draw_textf(font, al_map_rgb(255, 255, 255), 475, 20, -1, "I: %i J: %i", i, j);
                    al_flip_display();
                    do {
                        al_get_mouse_state(&state);
                        if (state.buttons & 1 && plat[cases_y(state.y)][cases_x(state.x)].surbrillance == 1) {
                            plat[i][j].piece = '0';
                            plat[i][j].couleur = VIDE;
                            plat[cases_y(state.y)][cases_x(state.x)].piece = 'T';
                            plat[cases_y(state.y)][cases_x(state.x)].couleur = NOIR;
                            f = 2;
                        }
                        if (state.buttons & 1 && plat[cases_y(state.y)][cases_x(state.x)].surbrillance == 2) {
                            plat[i][j].piece = '0';
                            plat[i][j].couleur = VIDE;
                            plat[cases_y(state.y)][cases_x(state.x)].piece = 'T';
                            plat[cases_y(state.y)][cases_x(state.x)].couleur = NOIR;
                            f = 2;
                        }
                        if (state.buttons & 1 && echap(state.x, state.y) == 0) {
                            raz_surbrillance(plat);
                            affichage_jeux(plat, plateau, pion_b_n, pion_b_b, pion_n_b, pion_n_n, cheval_b_n,
                                           cheval_b_b, cheval_n_b, cheval_n_n,
                                           tour_b_n, tour_b_b, tour_n_b, tour_n_n,
                                           fou_b_n, fou_b_b, fou_n_b, fou_n_n,
                                           reine_b_n, reine_b_b, reine_n_b, reine_n_n,
                                           roi_b_n, roi_b_b, roi_n_b, roi_n_n);
                            f = 1;
                        }
                    } while (f == 0);
                    raz_surbrillance(plat);
                    break;

                case 'F':
                    plat[i][j].surbrillance = 3;
                    a = i;
                    b = j;
                    while (a < 7 && b < 7 && g == 1) {
                        a++;
                        b++;
                        if (plat[a][b].piece == '0') { plat[a][b].surbrillance = 1; }
                        if (plat[a][b].couleur == NOIR) { g = 0; }
                        if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) {
                            plat[a][b].surbrillance = 2;
                            g = 0;
                        }
                    }
                    a = i;
                    b = j;
                    g = 1;
                    while (a > 0 && b > 0 && g == 1) {
                        a--;
                        b--;
                        if (plat[a][b].piece == '0') { plat[a][b].surbrillance = 1; }
                        if (plat[a][b].couleur == NOIR) { g = 0; }
                        if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) {
                            plat[a][b].surbrillance = 2;
                            g = 0;
                        }
                    }
                    a = i;
                    b = j;
                    g = 1;
                    while (a < 7 && b > 0 && g == 1) {
                        a++;
                        b--;
                        if (plat[a][b].piece == '0') { plat[a][b].surbrillance = 1; }
                        if (plat[a][b].couleur == NOIR) { g = 0; }
                        if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) {
                            plat[a][b].surbrillance = 2;
                            g = 0;
                        }
                    }
                    a = i;
                    b = j;
                    g = 1;
                    while (a > 0 && b < 7 && g == 1) {
                        b++;
                        a--;
                        if (plat[a][b].couleur == NOIR) { g = 0; }
                        if (plat[a][b].piece == '0') { plat[a][b].surbrillance = 1; }
                        if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) {
                            plat[a][b].surbrillance = 2;
                            g = 0;
                        }
                    }

                    affichage_jeux(plat, plateau, pion_b_n, pion_b_b, pion_n_b, pion_n_n, cheval_b_n, cheval_b_b,
                                   cheval_n_b, cheval_n_n,
                                   tour_b_n, tour_b_b, tour_n_b, tour_n_n,
                                   fou_b_n, fou_b_b, fou_n_b, fou_n_n,
                                   reine_b_n, reine_b_b, reine_n_b, reine_n_n,
                                   roi_b_n, roi_b_b, roi_n_b, roi_n_n);
                    al_draw_textf(font, al_map_rgb(255, 255, 255), 475, 20, -1, "I: %i J: %i", i, j);
                    al_flip_display();
                    do {
                        al_get_mouse_state(&state);
                        if (state.buttons & 1 && plat[cases_y(state.y)][cases_x(state.x)].surbrillance == 1) {
                            plat[i][j].piece = '0';
                            plat[i][j].couleur = VIDE;
                            plat[cases_y(state.y)][cases_x(state.x)].piece = 'F';
                            plat[cases_y(state.y)][cases_x(state.x)].couleur = NOIR;
                            f = 2;
                        }
                        if (state.buttons & 1 && plat[cases_y(state.y)][cases_x(state.x)].surbrillance == 2) {
                            plat[i][j].piece = '0';
                            plat[i][j].couleur = VIDE;
                            plat[cases_y(state.y)][cases_x(state.x)].piece = 'F';
                            plat[cases_y(state.y)][cases_x(state.x)].couleur = NOIR;
                            f = 2;
                        }
                        if (state.buttons & 1 && echap(state.x, state.y) == 0) {
                            raz_surbrillance(plat);
                            affichage_jeux(plat, plateau, pion_b_n, pion_b_b, pion_n_b, pion_n_n, cheval_b_n,
                                           cheval_b_b, cheval_n_b, cheval_n_n,
                                           tour_b_n, tour_b_b, tour_n_b, tour_n_n,
                                           fou_b_n, fou_b_b, fou_n_b, fou_n_n,
                                           reine_b_n, reine_b_b, reine_n_b, reine_n_n,
                                           roi_b_n, roi_b_b, roi_n_b, roi_n_n);
                            f = 1;
                        }


                    } while (f == 0);
                    raz_surbrillance(plat);
                    break;


                case 'R':
                    plat[i][j].surbrillance = 3;
                    a = i;
                    b = j;
                    while (a < 7 && b < 7 && g == 1) {
                        a++;
                        b++;
                        if (plat[a][b].piece == '0') { plat[a][b].surbrillance = 1; }
                        if (plat[a][b].couleur == NOIR) { g = 0; }
                        if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) {
                            plat[a][b].surbrillance = 2;
                            g = 0;
                        }
                    }
                    a = i;
                    b = j;
                    g = 1;
                    while (a > 0 && b > 0 && g == 1) {
                        a--;
                        b--;
                        if (plat[a][b].piece == '0') { plat[a][b].surbrillance = 1; }
                        if (plat[a][b].couleur == NOIR) { g = 0; }
                        if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) {
                            plat[a][b].surbrillance = 2;
                            g = 0;
                        }
                    }
                    a = i;
                    b = j;
                    g = 1;
                    while (a < 7 && b > 0 && g == 1) {
                        a++;
                        b--;
                        if (plat[a][b].piece == '0') { plat[a][b].surbrillance = 1; }
                        if (plat[a][b].couleur == NOIR) { g = 0; }
                        if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) {
                            plat[a][b].surbrillance = 2;
                            g = 0;
                        }
                    }
                    a = i;
                    b = j;
                    g = 1;
                    while (a > 0 && b < 7 && g == 1) {
                        b++;
                        a--;
                        if (plat[a][b].couleur == NOIR) { g = 0; }
                        if (plat[a][b].piece == '0') { plat[a][b].surbrillance = 1; }
                        if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) {
                            plat[a][b].surbrillance = 2;
                            g = 0;
                        }
                    }
                    a = i;
                    b = j;
                    while (a < 7 && g == 1) {
                        a++;
                        if (plat[a][b].piece == '0') { plat[a][b].surbrillance = 1; }
                        if (plat[a][b].couleur == NOIR) { g = 0; }
                        if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) {
                            plat[a][b].surbrillance = 2;
                            g = 0;
                        }
                    }
                    a = i;
                    b = j;
                    g = 1;
                    while (a > 0 && g == 1) {
                        a--;
                        if (plat[a][b].piece == '0') { plat[a][b].surbrillance = 1; }
                        if (plat[a][b].couleur == NOIR) { g = 0; }
                        if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) {
                            plat[a][b].surbrillance = 2;
                            g = 0;
                        }
                    }
                    a = i;
                    b = j;
                    g = 1;
                    while (b < 7 && g == 1) {
                        b++;
                        if (plat[a][b].piece == '0') { plat[a][b].surbrillance = 1; }
                        if (plat[a][b].couleur == NOIR) { g = 0; }
                        if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) {
                            plat[a][b].surbrillance = 2;
                            g = 0;
                        }
                    }
                    a = i;
                    b = j;
                    g = 1;
                    while (b > 0 && g == 1) {
                        b--;
                        if (plat[a][b].couleur == NOIR) { g = 0; }
                        if (plat[a][b].piece == '0') { plat[a][b].surbrillance = 1; }
                        if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) {
                            plat[a][b].surbrillance = 2;
                            g = 0;
                        }
                    }

                    affichage_jeux(plat, plateau, pion_b_n, pion_b_b, pion_n_b, pion_n_n, cheval_b_n, cheval_b_b,
                                   cheval_n_b, cheval_n_n,
                                   tour_b_n, tour_b_b, tour_n_b, tour_n_n,
                                   fou_b_n, fou_b_b, fou_n_b, fou_n_n,
                                   reine_b_n, reine_b_b, reine_n_b, reine_n_n,
                                   roi_b_n, roi_b_b, roi_n_b, roi_n_n);
                    al_draw_textf(font, al_map_rgb(255, 255, 255), 475, 20, -1, "I: %i J: %i", i, j);
                    al_flip_display();
                    do {
                        al_get_mouse_state(&state);
                        if (state.buttons & 1 && plat[cases_y(state.y)][cases_x(state.x)].surbrillance == 1) {
                            plat[i][j].piece = '0';
                            plat[i][j].couleur = VIDE;
                            plat[cases_y(state.y)][cases_x(state.x)].piece = 'R';
                            plat[cases_y(state.y)][cases_x(state.x)].couleur = NOIR;
                            f = 2;
                        }
                        if (state.buttons & 1 && plat[cases_y(state.y)][cases_x(state.x)].surbrillance == 2) {
                            plat[i][j].piece = '0';
                            plat[i][j].couleur = VIDE;
                            plat[cases_y(state.y)][cases_x(state.x)].piece = 'R';
                            plat[cases_y(state.y)][cases_x(state.x)].couleur = NOIR;
                            f = 2;
                        }
                        if (state.buttons & 1 && echap(state.x, state.y) == 0) {
                            raz_surbrillance(plat);
                            affichage_jeux(plat, plateau, pion_b_n, pion_b_b, pion_n_b, pion_n_n,
                                           cheval_b_n, cheval_b_b, cheval_n_b, cheval_n_n,
                                           tour_b_n, tour_b_b, tour_n_b, tour_n_n,
                                           fou_b_n, fou_b_b, fou_n_b, fou_n_n,
                                           reine_b_n, reine_b_b, reine_n_b, reine_n_n,
                                           roi_b_n, roi_b_b, roi_n_b, roi_n_n);
                            f = 1;
                        }
                    } while (f == 0);
                    raz_surbrillance(plat);
                    break;

                case '1':
                    plat[i][j].surbrillance = 3;
                    if (echec_roi(plat, NOIR, i, j) == 1) { n++; }
                    if (echec_roi(plat, NOIR, i - 1, j) == 0 && plat[i - 1][j].piece == '0') {
                        plat[i - 1][j].surbrillance = 1;
                    }
                    if (echec_roi(plat, NOIR, i - 1, j - 1) == 0 && plat[i - 1][j - 1].piece == '0') {
                        plat[i - 1][j - 1].surbrillance = 1;
                    }
                    if (echec_roi(plat, NOIR, i, j - 1) == 0 && plat[i][j - 1].piece == '0') {
                        plat[i][j - 1].surbrillance = 1;
                    }
                    if (echec_roi(plat, NOIR, i + 1, j - 1) == 0 && plat[i + 1][j - 1].piece == '0') {
                        plat[i + 1][j - 1].surbrillance = 1;
                    }
                    if (echec_roi(plat, NOIR, i + 1, j) == 0 && plat[i + 1][j].piece == '0') {
                        plat[i + 1][j].surbrillance = 1;
                    }
                    if (echec_roi(plat, NOIR, i + 1, j + 1) == 0 && plat[i + 1][j + 1].piece == '0') {
                        plat[i + 1][j + 1].surbrillance = 1;
                    }
                    if (echec_roi(plat, NOIR, i, j + 1) == 0 && plat[i][j + 1].piece == '0') {
                        plat[i][j + 1].surbrillance = 1;
                    }
                    if (echec_roi(plat, NOIR, i - 1, j + 1) == 0 && plat[i - 1][j + 1].piece == '0') {
                        plat[i - 1][j + 1].surbrillance = 1;
                    }


                    affichage_jeux(plat, plateau, pion_b_n, pion_b_b, pion_n_b, pion_n_n, cheval_b_n, cheval_b_b,
                                   cheval_n_b, cheval_n_n,
                                   tour_b_n, tour_b_b, tour_n_b, tour_n_n,
                                   fou_b_n, fou_b_b, fou_n_b, fou_n_n,
                                   reine_b_n, reine_b_b, reine_n_b, reine_n_n,
                                   roi_b_n, roi_b_b, roi_n_b, roi_n_n);
                    al_draw_textf(font, al_map_rgb(255, 255, 255), 475, 20, -1, "I: %i J: %i", i, j);
                    al_draw_textf(font, al_map_rgb(255, 255, 255), 475, 38, -1, "Echec");
                    al_flip_display();

                    do {
                        al_get_mouse_state(&state);
                        if (state.buttons & 1 && plat[cases_y(state.y)][cases_x(state.x)].surbrillance == 1) {
                            plat[i][j].piece = '0';
                            plat[i][j].couleur = VIDE;
                            plat[cases_y(state.y)][cases_x(state.x)].piece = '1';
                            plat[cases_y(state.y)][cases_x(state.x)].couleur = NOIR;
                            f = 2;
                        }
                        if (state.buttons & 1 && plat[cases_y(state.y)][cases_x(state.x)].surbrillance == 2) {
                            plat[i][j].piece = '0';
                            plat[i][j].couleur = VIDE;
                            plat[cases_y(state.y)][cases_x(state.x)].piece = '1';
                            plat[cases_y(state.y)][cases_x(state.x)].couleur = NOIR;
                            f = 2;
                        }
                        if (state.buttons & 1 && echap(state.x, state.y) == 0) {
                            raz_surbrillance(plat);
                            affichage_jeux(plat, plateau, pion_b_n, pion_b_b, pion_n_b, pion_n_n, cheval_b_n,
                                           cheval_b_b, cheval_n_b, cheval_n_n,
                                           tour_b_n, tour_b_b, tour_n_b, tour_n_n,
                                           fou_b_n, fou_b_b, fou_n_b, fou_n_n,
                                           reine_b_n, reine_b_b, reine_n_b, reine_n_n,
                                           roi_b_n, roi_b_b, roi_n_b, roi_n_n);
                            f = 1;
                        }

                    } while (f == 0);
                    raz_surbrillance(plat);
                    break;


                default:
                    break;
            }
        }
    } while (f != 2);
    if (n != 0) { return 7; }
    if (f == 2) { return 0; }
    else { return (1); }
}

int echec_roi(struct_plt plat[8][8], int couleur, int i, int j) {
    int echec = 0;
    int g, a, b;
    if (couleur == NOIR) {
        /* pions */
        if (plat[i - 1][j - 1].piece == 'p') { echec = 1; }
        if (plat[i - 1][j + 1].piece == 'p') { echec = 1; }

        /*chevaux */
        if (plat[i + 1][j + 2].piece == 'c') { echec = 1; }
        if (plat[i + 2][j + 1].piece == 'c') { echec = 1; }
        if (plat[i + 1][j - 2].piece == 'c') { echec = 1; }
        if (plat[i + 2][j - 1].piece == 'c') { echec = 1; }
        if (plat[i - 1][j + 2].piece == 'c') { echec = 1; }
        if (plat[i - 2][j + 1].piece == 'c') { echec = 1; }
        if (plat[i - 1][j - 2].piece == 'c') { echec = 1; }
        if (plat[i - 2][j - 1].piece == 'c') { echec = 1; }

        /* tours */
        a = i;
        b = j;
        g = 1;
        while (a < 7 && g == 1) {
            a++;
            if (plat[a][b].piece == 't') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == NOIR) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (a > 0 && g == 1) {
            a--;
            if (plat[a][b].piece == 't') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == NOIR) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (b < 7 && g == 1) {
            b++;
            if (plat[a][b].piece == 't') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == NOIR) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (b > 0 && g == 1) {
            b--;
            if (plat[a][b].piece == 't') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == NOIR) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) { g = 0; }
        }

        /* fou */
        a = i;
        b = j;
        g = 1;
        while (a < 7 && b < 7 && g == 1) {
            a++;
            b++;
            if (plat[a][b].piece == 'f') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == NOIR) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (a > 0 && b > 0 && g == 1) {
            a--;
            b--;
            if (plat[a][b].piece == 'f') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == NOIR) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (a < 7 && b > 0 && g == 1) {
            a++;
            b--;
            if (plat[a][b].piece == 'f') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == NOIR) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (a > 0 && b < 7 && g == 1) {
            b++;
            a--;
            if (plat[a][b].couleur == NOIR) { g = 0; }
            if (plat[a][b].piece == 'f') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) { g = 0; }
        }
        /* Reine N */
        a = i;
        b = j;
        g = 1;
        while (a < 7 && g == 1) {
            a++;
            if (plat[a][b].piece == 'r') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == NOIR) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (a > 0 && g == 1) {
            a--;
            if (plat[a][b].piece == 'r') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == NOIR) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (b < 7 && g == 1) {
            b++;
            if (plat[a][b].piece == 'r') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == NOIR) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (b > 0 && g == 1) {
            b--;
            if (plat[a][b].piece == 'r') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == NOIR) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) { g = 0; }
        }

        a = i;
        b = j;
        g = 1;
        while (a < 7 && b < 7 && g == 1) {
            a++;
            b++;
            if (plat[a][b].piece == 'r') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == NOIR) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (a > 0 && b > 0 && g == 1) {
            a--;
            b--;
            if (plat[a][b].piece == 'r') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == NOIR) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (a < 7 && b > 0 && g == 1) {
            a++;
            b--;
            if (plat[a][b].piece == 'r') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == NOIR) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (a > 0 && b < 7 && g == 1) {
            b++;
            a--;
            if (plat[a][b].couleur == NOIR) { g = 0; }
            if (plat[a][b].piece == 'r') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) { g = 0; }
        }
    }
    if (couleur == BLANC) {
        /* pions */
        if (plat[i + 1][j - 1].piece == 'P') { echec = 1; }
        if (plat[i + 1][j + 1].piece == 'P') { echec = 1; }

        /*chevaux */
        if (plat[i + 1][j + 2].piece == 'C') { echec = 1; }
        if (plat[i + 2][j + 1].piece == 'C') { echec = 1; }
        if (plat[i + 1][j - 2].piece == 'C') { echec = 1; }
        if (plat[i + 2][j - 1].piece == 'C') { echec = 1; }
        if (plat[i - 1][j + 2].piece == 'C') { echec = 1; }
        if (plat[i - 2][j + 1].piece == 'C') { echec = 1; }
        if (plat[i - 1][j - 2].piece == 'C') { echec = 1; }
        if (plat[i - 2][j - 1].piece == 'C') { echec = 1; }

        /* tours */
        a = i;
        b = j;
        g = 1;
        while (a < 7 && g == 1) {
            a++;
            if (plat[a][b].piece == 'T') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == BLANC) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (a > 0 && g == 1) {
            a--;
            if (plat[a][b].piece == 'T') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == BLANC) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (b < 7 && g == 1) {
            b++;
            if (plat[a][b].piece == 'T') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == BLANC) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (b > 0 && g == 1) {
            b--;
            if (plat[a][b].piece == 'T') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == BLANC) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) { g = 0; }
        }

        /* fou */
        a = i;
        b = j;
        g = 1;
        while (a < 7 && b < 7 && g == 1) {
            a++;
            b++;
            if (plat[a][b].piece == 'F') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == BLANC) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (a > 0 && b > 0 && g == 1) {
            a--;
            b--;
            if (plat[a][b].piece == 'F') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == BLANC) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (a < 7 && b > 0 && g == 1) {
            a++;
            b--;
            if (plat[a][b].piece == 'F') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == BLANC) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (a > 0 && b < 7 && g == 1) {
            b++;
            a--;
            if (plat[a][b].couleur == BLANC) { g = 0; }
            if (plat[a][b].piece == 'F') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) { g = 0; }
        }
        /* Reine B */
        a = i;
        b = j;
        g = 1;
        while (a < 7 && g == 1) {
            a++;
            if (plat[a][b].piece == 'R') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == BLANC) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (a > 0 && g == 1) {
            a--;
            if (plat[a][b].piece == 'R') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == BLANC) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (b < 7 && g == 1) {
            b++;
            if (plat[a][b].piece == 'R') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == BLANC) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (b > 0 && g == 1) {
            b--;
            if (plat[a][b].piece == 'R') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == BLANC) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) { g = 0; }
        }

        a = i;
        b = j;
        g = 1;
        while (a < 7 && b < 7 && g == 1) {
            a++;
            b++;
            if (plat[a][b].piece == 'R') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == BLANC) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (a > 0 && b > 0 && g == 1) {
            a--;
            b--;
            if (plat[a][b].piece == 'R') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == BLANC) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (a < 7 && b > 0 && g == 1) {
            a++;
            b--;
            if (plat[a][b].piece == 'R') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == BLANC) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (a > 0 && b < 7 && g == 1) {
            b++;
            a--;
            if (plat[a][b].couleur == BLANC) { g = 0; }
            if (plat[a][b].piece == 'R') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) { g = 0; }
        }
    }
    return echec;
}

int echec_mat(struct_plt plat[8][8], int couleur) {
    int echec = 0;
    int i, j;
    int g, a, b;
    if (couleur == NOIR) {
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                if (plat[i][j].piece == '1') {
                    a = i;
                    b = j;
                }
            }
        }
        i = a;
        j = b;
        a = 0;
        b = 0;
        /* pions */
        if (plat[i - 1][j - 1].piece == 'p') { echec = 1; }
        if (plat[i - 1][j + 1].piece == 'p') { echec = 1; }

        /*chevaux */
        if (plat[i + 1][j + 2].piece == 'c') { echec = 1; }
        if (plat[i + 2][j + 1].piece == 'c') { echec = 1; }
        if (plat[i + 1][j - 2].piece == 'c') { echec = 1; }
        if (plat[i + 2][j - 1].piece == 'c') { echec = 1; }
        if (plat[i - 1][j + 2].piece == 'c') { echec = 1; }
        if (plat[i - 2][j + 1].piece == 'c') { echec = 1; }
        if (plat[i - 1][j - 2].piece == 'c') { echec = 1; }
        if (plat[i - 2][j - 1].piece == 'c') { echec = 1; }

        /* tours */
        a = i;
        b = j;
        g = 1;
        while (a < 7 && g == 1) {
            a++;
            if (plat[a][b].piece == 't') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == NOIR) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (a > 0 && g == 1) {
            a--;
            if (plat[a][b].piece == 't') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == NOIR) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (b < 7 && g == 1) {
            b++;
            if (plat[a][b].piece == 't') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == NOIR) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (b > 0 && g == 1) {
            b--;
            if (plat[a][b].piece == 't') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == NOIR) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) { g = 0; }
        }

        /* fou */
        a = i;
        b = j;
        g = 1;
        while (a < 7 && b < 7 && g == 1) {
            a++;
            b++;
            if (plat[a][b].piece == 'f') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == NOIR) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (a > 0 && b > 0 && g == 1) {
            a--;
            b--;
            if (plat[a][b].piece == 'f') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == NOIR) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (a < 7 && b > 0 && g == 1) {
            a++;
            b--;
            if (plat[a][b].piece == 'f') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == NOIR) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (a > 0 && b < 7 && g == 1) {
            b++;
            a--;
            if (plat[a][b].couleur == NOIR) { g = 0; }
            if (plat[a][b].piece == 'f') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) { g = 0; }
        }
        /* Reine N */
        a = i;
        b = j;
        g = 1;
        while (a < 7 && g == 1) {
            a++;
            if (plat[a][b].piece == 'r') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == NOIR) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (a > 0 && g == 1) {
            a--;
            if (plat[a][b].piece == 'r') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == NOIR) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (b < 7 && g == 1) {
            b++;
            if (plat[a][b].piece == 'r') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == NOIR) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (b > 0 && g == 1) {
            b--;
            if (plat[a][b].piece == 'r') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == NOIR) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) { g = 0; }
        }

        a = i;
        b = j;
        g = 1;
        while (a < 7 && b < 7 && g == 1) {
            a++;
            b++;
            if (plat[a][b].piece == 'r') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == NOIR) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (a > 0 && b > 0 && g == 1) {
            a--;
            b--;
            if (plat[a][b].piece == 'r') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == NOIR) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (a < 7 && b > 0 && g == 1) {
            a++;
            b--;
            if (plat[a][b].piece == 'r') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == NOIR) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (a > 0 && b < 7 && g == 1) {
            b++;
            a--;
            if (plat[a][b].couleur == NOIR) { g = 0; }
            if (plat[a][b].piece == 'r') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == BLANC) { g = 0; }
        }
    }

    if (couleur == BLANC) {
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                if (plat[i][j].piece == 'x') {
                    a = i;
                    b = j;
                }
            }
        }
        i = a;
        j = b;
        a = 0;
        b = 0;
        /* pions */
        if (plat[i + 1][j - 1].piece == 'P') { echec = 1; }
        if (plat[i + 1][j + 1].piece == 'P') { echec = 1; }

        /*chevaux */
        if (plat[i + 1][j + 2].piece == 'C') { echec = 1; }
        if (plat[i + 2][j + 1].piece == 'C') { echec = 1; }
        if (plat[i + 1][j - 2].piece == 'C') { echec = 1; }
        if (plat[i + 2][j - 1].piece == 'C') { echec = 1; }
        if (plat[i - 1][j + 2].piece == 'C') { echec = 1; }
        if (plat[i - 2][j + 1].piece == 'C') { echec = 1; }
        if (plat[i - 1][j - 2].piece == 'C') { echec = 1; }
        if (plat[i - 2][j - 1].piece == 'C') { echec = 1; }

        /* tours */
        a = i;
        b = j;
        g = 1;
        while (a < 7 && g == 1) {
            a++;
            if (plat[a][b].piece == 'T') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == BLANC) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (a > 0 && g == 1) {
            a--;
            if (plat[a][b].piece == 'T') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == BLANC) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (b < 7 && g == 1) {
            b++;
            if (plat[a][b].piece == 'T') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == BLANC) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (b > 0 && g == 1) {
            b--;
            if (plat[a][b].piece == 'T') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == BLANC) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) { g = 0; }
        }

        /* fou */
        a = i;
        b = j;
        g = 1;
        while (a < 7 && b < 7 && g == 1) {
            a++;
            b++;
            if (plat[a][b].piece == 'F') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == BLANC) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (a > 0 && b > 0 && g == 1) {
            a--;
            b--;
            if (plat[a][b].piece == 'F') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == BLANC) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (a < 7 && b > 0 && g == 1) {
            a++;
            b--;
            if (plat[a][b].piece == 'F') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == BLANC) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (a > 0 && b < 7 && g == 1) {
            b++;
            a--;
            if (plat[a][b].couleur == BLANC) { g = 0; }
            if (plat[a][b].piece == 'F') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) { g = 0; }
        }
        /* Reine B */
        a = i;
        b = j;
        g = 1;
        while (a < 7 && g == 1) {
            a++;
            if (plat[a][b].piece == 'R') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == BLANC) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (a > 0 && g == 1) {
            a--;
            if (plat[a][b].piece == 'R') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == BLANC) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (b < 7 && g == 1) {
            b++;
            if (plat[a][b].piece == 'R') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == BLANC) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (b > 0 && g == 1) {
            b--;
            if (plat[a][b].piece == 'R') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == BLANC) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) { g = 0; }
        }

        a = i;
        b = j;
        g = 1;
        while (a < 7 && b < 7 && g == 1) {
            a++;
            b++;
            if (plat[a][b].piece == 'R') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == BLANC) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (a > 0 && b > 0 && g == 1) {
            a--;
            b--;
            if (plat[a][b].piece == 'R') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == BLANC) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (a < 7 && b > 0 && g == 1) {
            a++;
            b--;
            if (plat[a][b].piece == 'R') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].couleur == BLANC) { g = 0; }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) { g = 0; }
        }
        a = i;
        b = j;
        g = 1;
        while (a > 0 && b < 7 && g == 1) {
            b++;
            a--;
            if (plat[a][b].couleur == BLANC) { g = 0; }
            if (plat[a][b].piece == 'R') {
                echec = 1;
                g = 0;
            }
            if (plat[a][b].piece != '0' && plat[a][b].couleur == NOIR) { g = 0; }
        }
    }
    return echec;
}
