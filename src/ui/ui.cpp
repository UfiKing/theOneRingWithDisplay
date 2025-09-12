#if defined(EEZ_FOR_LVGL)
#include <eez/core/vars.h>
#endif

#include "ui.h"
#include "screens.h"
#include "images.h"
#include "actions.h"
#include "vars.h"

#include "../lights.h"
void lightsTaskCreate(){
  TaskHandle_t lightTask;

  xTaskCreatePinnedToCore(
      lightsTask,
      "allOn",
      10000,
      NULL,
      1,
      &lightTask,
      1
  );
  Serial.println("created lights Task");
}





#if defined(EEZ_FOR_LVGL)

void ui_init() {
    eez_flow_init(assets, sizeof(assets), (lv_obj_t **)&objects, sizeof(objects), images, sizeof(images), actions);
}

void ui_tick() {
    eez_flow_tick();
    tick_screen(g_currentScreen);
}

#else

#include <string.h>

static int16_t currentScreen = -1;

static lv_obj_t *getLvglObjectFromIndex(int32_t index) {
    if (index == -1) {
        return 0;
    }
    return ((lv_obj_t **)&objects)[index];
}

void loadScreen(enum ScreensEnum screenId) {
    currentScreen = screenId - 1;
    lv_obj_t *screen = getLvglObjectFromIndex(currentScreen);
    lv_scr_load_anim(screen, LV_SCR_LOAD_ANIM_FADE_IN, 200, 0, false);
}

void ui_init() {
    create_screens();
    loadScreen(SCREEN_ID_MAIN);
    lightsTaskCreate();

}

void ui_tick() {
    tick_screen(currentScreen);
}

void action_switch_screen(lv_event_t *e) {
    loadScreen(SCREEN_ID_AMULET_SCREEN);
}

void action_switch_to_ring(lv_event_t * e){
  loadScreen(SCREEN_ID_RING_SCREEN); 
}
void action_switch_to_mountian(lv_event_t * e){}
void action_all_on(lv_event_t * e){
  allOnB = true;
  breatheB = false;
  spinB = false;
  lavaV1B = false;
  lavaV2B = false;
  lavaV3B = false;
  flickerV1B = false;
  allOffB = false;
 
}
void action_all_off(lv_event_t * e){
  breatheB = false;
  spinB = false;
  lavaV1B = false;
  lavaV2B = false;
  lavaV3B = false;
  flickerV1B = false;
  allOnB = false;
  allOffB = true;
}
void action_breathe(lv_event_t * e){
  breatheB = true;
  spinB = false;
  lavaV1B = false;
  lavaV2B = false;
  lavaV3B = false;
  flickerV1B = false;
  allOnB = false;
  allOffB = true;
}
void action_spin(lv_event_t * e){
  breatheB = false;
  spinB = true;
  lavaV1B = false;
  lavaV2B = false;
  lavaV3B = false;
  flickerV1B = false;
  allOnB = false;
  allOffB = true;
}
void action_lava_v1(lv_event_t * e){
  breatheB = false;
  spinB = false;
  lavaV1B = true;
  lavaV2B = false;
  lavaV3B = false;
  flickerV1B = false;
  allOnB = false;
  allOffB = true;
}
void action_lava_v2(lv_event_t * e){
  breatheB = false;
  spinB = false;
  lavaV1B = false;
  lavaV2B = true;
  lavaV3B = false;
  flickerV1B = false;
  allOnB = false;
  allOffB = true;
}
void action_lava_v3(lv_event_t * e){}
void action_flicker_v1(lv_event_t * e){}
void action_back(lv_event_t * e){
  loadScreen(SCREEN_ID_MAIN);
}
void action_next_screen(lv_event_t * e){
  loadScreen(SCREEN_ID_RING_SCREEN2);
}
void action_previous_screen(lv_event_t * e){
  loadScreen(SCREEN_ID_RING_SCREEN);
}



#endif
