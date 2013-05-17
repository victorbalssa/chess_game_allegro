#include <stdio.h>
#include <stdlib.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/allegro_image.h>

#include "../prototype.h"

#define BLANC 0
#define NOIR 1
#define VIDE 2

ALLEGRO_DISPLAY *display = NULL;

int main() {
    char buf[80];//buffer pour sprite menu
    struct_plt plat[8][8];// plateau de jeu
    ALLEGRO_BITMAP *plateau, *pion_b_n, *pion_b_b, *pion_n_b, *pion_n_n, *cheval_b_n, *cheval_b_b, *cheval_n_b, *cheval_n_n,
            *tour_b_n, *tour_b_b, *tour_n_b, *tour_n_n, *fou_b_n, *fou_b_b, *fou_n_b, *fou_n_n,
            *reine_b_n, *reine_b_b, *reine_n_b, *reine_n_n, *roi_b_n, *roi_b_b, *roi_n_b, *roi_n_n, *menu, *pause, *win_n, *win_b;// toutes les images du prog
    int choix, i, n = 0, l, h = 0;// variables pour les differents choix de l'utilisateur

    al_init();//Initialisation obligatoire d'allegro.
    al_install_keyboard();//Initialisation du clavier.
    al_install_mouse();//Instalation de la souris.
    display = al_create_display(1200, 675);//On ouvre une fenetre graphique de 1200 par 750.
    al_show_mouse_cursor(display); //affiche la souris
    al_set_window_title(display, "CHESS");
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();

    // on initialise toutes les variables images
    plateau = al_load_bitmap("bmp/plateau.bmp");
    pion_n_b = al_load_bitmap("bmp/pion_n_b.bmp");
    pion_n_n = al_load_bitmap("bmp/pion_n_n.bmp");
    pion_b_b = al_load_bitmap("bmp/pion_b_b.bmp");
    pion_b_n = al_load_bitmap("bmp/pion_b_n.bmp");
    cheval_n_b = al_load_bitmap("bmp/cheval_n_b.bmp");
    cheval_n_n = al_load_bitmap("bmp/cheval_n_n.bmp");
    cheval_b_b = al_load_bitmap("bmp/cheval_b_b.bmp");
    cheval_b_n = al_load_bitmap("bmp/cheval_b_n.bmp");
    tour_n_b = al_load_bitmap("bmp/tour_n_b.bmp");
    tour_n_n = al_load_bitmap("bmp/tour_n_n.bmp");
    tour_b_b = al_load_bitmap("bmp/tour_b_b.bmp");
    tour_b_n = al_load_bitmap("bmp/tour_b_n.bmp");
    fou_n_b = al_load_bitmap("bmp/fou_n_b.bmp");
    fou_n_n = al_load_bitmap("bmp/fou_n_n.bmp");
    fou_b_b = al_load_bitmap("bmp/fou_b_b.bmp");
    fou_b_n = al_load_bitmap("bmp/fou_b_n.bmp");
    reine_n_b = al_load_bitmap("bmp/reine_n_b.bmp");
    reine_n_n = al_load_bitmap("bmp/reine_n_n.bmp");
    reine_b_b = al_load_bitmap("bmp/reine_b_b.bmp");
    reine_b_n = al_load_bitmap("bmp/reine_b_n.bmp");
    roi_n_b = al_load_bitmap("bmp/roi_n_b.bmp");
    roi_n_n = al_load_bitmap("bmp/roi_n_n.bmp");
    roi_b_b = al_load_bitmap("bmp/roi_b_b.bmp");
    roi_b_n = al_load_bitmap("bmp/roi_b_n.bmp");
    menu = al_load_bitmap("bmp/menu.bmp");
    if (!menu) {
        printf("error loading bmp");
        return 0;
    }
    win_b = al_load_bitmap("bmp/win_b.bmp");
    win_n = al_load_bitmap("bmp/win_n.bmp");
    pause = al_load_bitmap("bmp/pause.bmp");
    //AUDIO *ambiance=al_load_mid("sound/ambiance.mid");
    ALLEGRO_KEYBOARD_STATE key_state;
    do {
        initialisation_plt(plat);
        al_set_target_backbuffer(display);
        al_draw_bitmap(menu, 0, 0, 0);
        al_flip_display();
        //play_midi(ambiance, 0);
        ALLEGRO_MOUSE_STATE state;
        do {
            al_get_mouse_state(&state);
        } while (jouer(state) != 0);
        do {
            do {
                affichage_jeux(plat, plateau, pion_b_n, pion_b_b, pion_n_b, pion_n_n,
                               cheval_b_n, cheval_b_b, cheval_n_b, cheval_n_n,
                               tour_b_n, tour_b_b, tour_n_b, tour_n_n,
                               fou_b_n, fou_b_b, fou_n_b, fou_n_n,
                               reine_b_n, reine_b_b, reine_n_b, reine_n_n,
                               roi_b_n, roi_b_b, roi_n_b, roi_n_n);
                h = jeu_b(plat, plateau, pion_b_n, pion_b_b, pion_n_b, pion_n_n,
                          cheval_b_n, cheval_b_b, cheval_n_b, cheval_n_n,
                          tour_b_n, tour_b_b, tour_n_b, tour_n_n,
                          fou_b_n, fou_b_b, fou_n_b, fou_n_n,
                          reine_b_n, reine_b_b, reine_n_b, reine_n_n,
                          roi_b_n, roi_b_b, roi_n_b, roi_n_n);
                if (h == 1) { h = menu_pause(pause); }
            } while (h == 1);

            if (echec_mat(plat, BLANC) == 1) {
                al_draw_bitmap(win_n, 0, 0, 0);
                al_flip_display();
                //do {} while (!al_key_down(key_state, ALLEGRO_KEY_ESCAPE));
                h = 5;
            }
            affichage_jeux(plat, plateau, pion_b_n, pion_b_b, pion_n_b, pion_n_n,
                           cheval_b_n, cheval_b_b, cheval_n_b, cheval_n_n,
                           tour_b_n, tour_b_b, tour_n_b, tour_n_n,
                           fou_b_n, fou_b_b, fou_n_b, fou_n_n,
                           reine_b_n, reine_b_b, reine_n_b, reine_n_n,
                           roi_b_n, roi_b_b, roi_n_b, roi_n_n);

            if (h == 5) { exit(0); }
            do {
                affichage_jeux(plat, plateau, pion_b_n, pion_b_b, pion_n_b, pion_n_n,
                               cheval_b_n, cheval_b_b, cheval_n_b, cheval_n_n,
                               tour_b_n, tour_b_b, tour_n_b, tour_n_n,
                               fou_b_n, fou_b_b, fou_n_b, fou_n_n,
                               reine_b_n, reine_b_b, reine_n_b, reine_n_n,
                               roi_b_n, roi_b_b, roi_n_b, roi_n_n);
                h = jeu_n(plat, plateau, pion_b_n, pion_b_b, pion_n_b, pion_n_n,
                          cheval_b_n, cheval_b_b, cheval_n_b, cheval_n_n,
                          tour_b_n, tour_b_b, tour_n_b, tour_n_n,
                          fou_b_n, fou_b_b, fou_n_b, fou_n_n,
                          reine_b_n, reine_b_b, reine_n_b, reine_n_n,
                          roi_b_n, roi_b_b, roi_n_b, roi_n_n);
                if (h == 1) { h = menu_pause(pause); }
            } while (h == 1);

            if (echec_mat(plat, NOIR) == 1) {
                al_draw_bitmap(win_b, 0, 0, 0);
                al_flip_display();
                //do {} while (!al_key_down(key_state, ALLEGRO_KEY_ESCAPE));
                h = 5;
            }
            affichage_jeux(plat, plateau, pion_b_n, pion_b_b, pion_n_b, pion_n_n,
                           cheval_b_n, cheval_b_b, cheval_n_b, cheval_n_n,
                           tour_b_n, tour_b_b, tour_n_b, tour_n_n,
                           fou_b_n, fou_b_b, fou_n_b, fou_n_n,
                           reine_b_n, reine_b_b, reine_n_b, reine_n_n,
                           roi_b_n, roi_b_b, roi_n_b, roi_n_n);
        } while (h != 5);
    } while (h != 9);

    return 0;
}
