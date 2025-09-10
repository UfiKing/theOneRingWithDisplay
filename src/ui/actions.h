#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void action_switch_screen(lv_event_t * e);
extern void action_switch_to_ring(lv_event_t * e);
extern void action_switch_to_mountian(lv_event_t * e);
extern void action_all_on(lv_event_t * e);
extern void action_all_off(lv_event_t * e);
extern void action_breathe(lv_event_t * e);
extern void action_spin(lv_event_t * e);
extern void action_lava_v1(lv_event_t * e);
extern void action_lava_v2(lv_event_t * e);
extern void action_lava_v3(lv_event_t * e);
extern void action_flicker_v1(lv_event_t * e);
extern void action_back(lv_event_t * e);
extern void action_next_screen(lv_event_t * e);
extern void action_previous_screen(lv_event_t * e);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/