#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;
uint32_t active_theme_index = 0;

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // label1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label1 = obj;
            lv_obj_set_pos(obj, 142, 9);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Pelin");
        }
        {
            // gumb1
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.gumb1 = obj;
            lv_obj_set_pos(obj, 109, 127);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, action_switch_screen, LV_EVENT_CLICKED, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Button");
                }
            }
        }
    }
    
    tick_screen_main();
}

void tick_screen_main() {
}

void create_screen_amulet_screen() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.amulet_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // amuletLogo
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.amulet_logo = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 240);
            lv_image_set_src(obj, &img_amulet_bigger);
            lv_image_set_scale(obj, 160);
        }
    }
    
    tick_screen_amulet_screen();
}

void tick_screen_amulet_screen() {
}

void create_screen_vegova_screen() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.vegova_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // vegovaLogo
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.vegova_logo = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 240);
            lv_image_set_src(obj, &img_vegova);
        }
    }
    
    tick_screen_vegova_screen();
}

void tick_screen_vegova_screen() {
}

void create_screen_spellcaster_screen() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.spellcaster_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // spellcasterLogo
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.spellcaster_logo = obj;
            lv_obj_set_pos(obj, 94, 54);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_spellcaster);
        }
        {
            // spellcasterText
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.spellcaster_text = obj;
            lv_obj_set_pos(obj, 113, 187);
            lv_obj_set_size(obj, 114, 23);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "spellcaster.si");
        }
    }
    
    tick_screen_spellcaster_screen();
}

void tick_screen_spellcaster_screen() {
}



typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_amulet_screen,
    tick_screen_vegova_screen,
    tick_screen_spellcaster_screen,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
    create_screen_amulet_screen();
    create_screen_vegova_screen();
    create_screen_spellcaster_screen();
}
