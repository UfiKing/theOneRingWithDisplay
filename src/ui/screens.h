#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *amulet_screen;
    lv_obj_t *vegova_screen;
    lv_obj_t *spellcaster_screen;
    lv_obj_t *label1;
    lv_obj_t *gumb1;
    lv_obj_t *amulet_logo;
    lv_obj_t *vegova_logo;
    lv_obj_t *spellcaster_logo;
    lv_obj_t *spellcaster_text;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
    SCREEN_ID_AMULET_SCREEN = 2,
    SCREEN_ID_VEGOVA_SCREEN = 3,
    SCREEN_ID_SPELLCASTER_SCREEN = 4,
};

void create_screen_main();
void tick_screen_main();

void create_screen_amulet_screen();
void tick_screen_amulet_screen();

void create_screen_vegova_screen();
void tick_screen_vegova_screen();

void create_screen_spellcaster_screen();
void tick_screen_spellcaster_screen();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/