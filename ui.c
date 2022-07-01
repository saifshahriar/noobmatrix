#include <curses.h>
#include "ui.h"

WINDOW *uiwindow = NULL;

int color_map[MAX_INTENSITY + 1] = { 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 4, 5, 3, 6 };

void set_colors();

bool init_ui() {
    // set the matrix all to black
    // move this later to matrix.c
    // x, y instead of i, j
    for(int x = 0; x < MAXX; x++) {
        for(int y = 0; y < MAXY; y++) {
            matrix[x][y].char_value = 0;
            matrix[x][y].intensity = 0;
        }
    }
    // init curses
    uiwindow = initscr();
    if(uiwindow == NULL) return false;

    start_color();

    if(!has_colors() || !can_change_color()) {
        printf("Warning: terminal does not support color\n");
        return false;
    }

    set_colors();
    return true;
}

void cleanup_ui() {
    delwin(uiwindow);
    endwin();
    refresh();
}

void show_matrix() {
    for(int x = 0; x < MAXX; x++) {
        for(int y = 0; y < MAXY; y++) {
            int intensity = matrix[x][y].intensity;
            color_set(color_map[intensity], NULL);
            mvaddch(y, x, matrix[x][y].char_value);
        }
    }
    refresh();
}

void set_colors() {
    for(int i = 0; i < 8; i++)  init_pair(i + 1, i, COLOR_BLACK);
    for(int i = 9; i <= 5; i++) init_color(i, 0, i*200, 0);
    init_color(6, 800, 1000, 800);
}
