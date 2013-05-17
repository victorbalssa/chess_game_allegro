#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

typedef struct piece {
    int couleur;
    int co_graph[2];
    char piece;
    int surbrillance;
} struct_plt;

int echec_mat(struct_plt plat[8][8], int couleur);

int echec_roi(struct_plt plat[8][8], int couleur, int i, int j);

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
                    ALLEGRO_BITMAP *roi_n_n);

int cases_x(int x);

int cases_y(int y);

int echap(int x, int y);

int jouer(ALLEGRO_MOUSE_STATE state);

void initialisation_plt(struct_plt plt[8][8]);

int menu_pause(ALLEGRO_BITMAP *pause);

void raz_surbrillance(struct_plt plat[8][8]);

int jeu_n(struct_plt plat[8][8], ALLEGRO_BITMAP *plateau, ALLEGRO_BITMAP *pion_b_n,
          ALLEGRO_BITMAP *pion_b_b, ALLEGRO_BITMAP *pion_n_b, ALLEGRO_BITMAP *pion_n_n,
          ALLEGRO_BITMAP *cheval_b_n, ALLEGRO_BITMAP *cheval_b_b, ALLEGRO_BITMAP *cheval_n_b,
          ALLEGRO_BITMAP *cheval_n_n,
          ALLEGRO_BITMAP *tour_b_n, ALLEGRO_BITMAP *tour_b_b, ALLEGRO_BITMAP *tour_n_b, ALLEGRO_BITMAP *tour_n_n,
          ALLEGRO_BITMAP *fou_b_n, ALLEGRO_BITMAP *fou_b_b, ALLEGRO_BITMAP *fou_n_b, ALLEGRO_BITMAP *fou_n_n,
          ALLEGRO_BITMAP *reine_b_n, ALLEGRO_BITMAP *reine_b_b, ALLEGRO_BITMAP *reine_n_b, ALLEGRO_BITMAP *reine_n_n,
          ALLEGRO_BITMAP *roi_b_n, ALLEGRO_BITMAP *roi_b_b, ALLEGRO_BITMAP *roi_n_b,
          ALLEGRO_BITMAP *roi_n_n);

int jeu_b(struct_plt plat[8][8], ALLEGRO_BITMAP *plateau, ALLEGRO_BITMAP *pion_b_n, ALLEGRO_BITMAP *pion_b_b,
          ALLEGRO_BITMAP *pion_n_b, ALLEGRO_BITMAP *pion_n_n,
          ALLEGRO_BITMAP *cheval_b_n, ALLEGRO_BITMAP *cheval_b_b, ALLEGRO_BITMAP *cheval_n_b,
          ALLEGRO_BITMAP *cheval_n_n,
          ALLEGRO_BITMAP *tour_b_n, ALLEGRO_BITMAP *tour_b_b, ALLEGRO_BITMAP *tour_n_b, ALLEGRO_BITMAP *tour_n_n,
          ALLEGRO_BITMAP *fou_b_n, ALLEGRO_BITMAP *fou_b_b, ALLEGRO_BITMAP *fou_n_b, ALLEGRO_BITMAP *fou_n_n,
          ALLEGRO_BITMAP *reine_b_n, ALLEGRO_BITMAP *reine_b_b, ALLEGRO_BITMAP *reine_n_b, ALLEGRO_BITMAP *reine_n_n,
          ALLEGRO_BITMAP *roi_b_n, ALLEGRO_BITMAP *roi_b_b, ALLEGRO_BITMAP *roi_n_b,
          ALLEGRO_BITMAP *roi_n_n);
