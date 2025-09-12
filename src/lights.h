#ifndef LED_STRIP_EFFECTS_LIB_H
#define LED_STRIP_EFFECTS_LIB_H
//void allOn(void* pvParamaters);
#define NUM_LEDS 71
#define LED_PIN 21
#include <FastLED.h>
#include <stdbool.h>
#define LED_COUNT 71
bool breatheB = false;
bool spinB = false;
bool lavaV1B = false;
bool lavaV2B = false;
bool lavaV3B = false;
bool flickerV1B = false;
bool allOnB = false;
bool allOffB = false;

void allOn(CRGB leds[]){
    
  for(uint8_t i = 0; i < NUM_LEDS; i++){
    leds[i] = CRGB(255,255,255);
  }
  FastLED.show();
  Serial.println("allOn");
  
}

void allOff(CRGB leds[]){
    
  for(uint8_t i = 0; i < NUM_LEDS; i++){
    leds[i] = CRGB(0,0,0);

  }
  FastLED.show();
  Serial.println("allOff");
  
}

void spin(CRGB leds[]){
  for(uint8_t i = 0; i < LED_COUNT; i++){
    leds[i] = CRGB(255,255,255);

    if(i - 1 == -1 ){
      leds[LED_COUNT -1] = CRGB(200,200,150);
      leds[LED_COUNT -2] = CRGB(150,150,100);
      leds[LED_COUNT -3] = CRGB(100,100,050);
      leds[LED_COUNT -4] = CRGB(050,050,000);
      leds[LED_COUNT -5] = CRGB(000,000,000);
    }else if(i - 2 == -1 ){
      leds[LED_COUNT -1] = CRGB(150,150,100);
      leds[LED_COUNT -2] = CRGB(100,100,050);
      leds[LED_COUNT -3] = CRGB(050,050,000);
      leds[LED_COUNT -4] = CRGB(000,000,000);
      leds[LED_COUNT -5] = CRGB(000,000,000);
    }else if(i - 3 == -1 ){
      leds[LED_COUNT -1] = CRGB(100,100,050);
      leds[LED_COUNT -2] = CRGB(050,050,000);
      leds[LED_COUNT -3] = CRGB(000,000,000);
    }else if(i - 4 == -1 ){
      leds[LED_COUNT -1] = CRGB(050,050,000);
      leds[LED_COUNT -2] = CRGB(000,000,000);
    }else if(i - 5 == 0 ){
      leds[LED_COUNT -1] = CRGB(000,000,000);
    }else if(i + 1 == LED_COUNT){
      leds[0] = CRGB(200,200,150);
      leds[1] = CRGB(150,150,100);
      leds[2] = CRGB(100,100,050);
      leds[3] = CRGB(050,050,000);
      leds[4] = CRGB(000,000,000);
    }else if(i + 2 == LED_COUNT){
      leds[0] = CRGB(150,150,100);
      leds[1] = CRGB(100,100,050);
      leds[2] = CRGB(050,050,000);
      leds[3] = CRGB(000,000,000);
    }else if(i + 3 == LED_COUNT){
      leds[0] = CRGB(100,100,050);
      leds[1] = CRGB(050,050,000);
      leds[2] = CRGB(000,000,000);
    }else if(i + 4 == LED_COUNT){
      leds[0] = CRGB(050,050,000);
      leds[1] = CRGB(000,000,000);
    }
      leds[i-1] = CRGB(200,200,150);
      leds[i-2] = CRGB(150,150,100);
      leds[i-3] = CRGB(100,100,050);
      leds[i-4] = CRGB(050,050,000);
      leds[i-5] = CRGB(000,000,000);

      leds[i+1] = CRGB(200,200,150);
      leds[i+2] = CRGB(150,150,100);
      leds[i+3] = CRGB(100,100,050);
      leds[i+4] = CRGB(050,050,000);
      leds[i+5] = CRGB(000,000,000);

      FastLED.show();
      if(spinB == false){
        break;
      }
      delay(50);
  }
  
}


void breathe(CRGB leds[], uint16_t delayMS){
  for(uint8_t i = 1; i != 0; i++){
    for(uint8_t j = 0; j < NUM_LEDS; j++){
      leds[j] = CRGB(i,i,i);
    }
    FastLED.show();
    if(breatheB == false){
      break;
    }
    delay(delayMS);
  }

  for(uint8_t i = 255; i != 0; i--){
    for(uint8_t j = 0; j < NUM_LEDS; j++){
      leds[j] = CRGB(i,i,i);
    }
    if(breatheB == false){
      break;
    }
    FastLED.show();
    delay(delayMS);
  }
}

void lavaV1(CRGB leds[], uint16_t delayMS){
  for(uint8_t i = 0; i < LED_COUNT; i++){
    long rand = random();
    leds[i] = CRGB(rand & 0b11111111, (rand >> 8) & 0b11111111, (rand >> 16) & 0b11111111);
  }
  FastLED.show();
  delay(delayMS);
}

void lavaV2(CRGB leds[], uint16_t delayMS, uint8_t steps, uint32_t repetitions){
  uint8_t targets[LED_COUNT][3];
  for(uint8_t i = 0; i < LED_COUNT; i++){
    targets[i][0] = random(256);
    targets[i][1] = targets[i][0];
    targets[i][2] = random(256);
    leds[i] = CRGB(targets[i][1], targets[i][1], targets[i][1]);
  }
  FastLED.show();
  for (uint32_t x = 0; x < repetitions; x++) {
    for (uint8_t i = 0; i < LED_COUNT; i++) {
      targets[i][0] = targets[i][1];
      targets[i][2] = random(256);
      leds[i] = CRGB(targets[i][1], targets[i][1], targets[i][1]);
    }
    FastLED.show();
    for (uint8_t j = 0; j < steps; j++) {
      for (uint8_t i = 0; i < LED_COUNT; i++) {
        int16_t change = targets[i][2] - targets[i][0];
        change = change / steps;
        targets[i][1] += change;
        leds[i] = CRGB(targets[i][1], targets[i][1], targets[i][1]);
      }
      FastLED.show();
      if(lavaV2B == false){
        break;
      }
      delay(delayMS);
    }
    if(lavaV2B == false){
        break;
    }
  }
}

void lightsTask(void* pvParamaters){
  CRGB leds[NUM_LEDS + 6];
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  for(;;){
    if(allOnB){
      allOn(leds);
    }else if(allOffB){
      allOff(leds);
      allOffB = false;
    }else if(breatheB){
      breathe(leds, 10);
    }else if(spinB){
      spin(leds);
    }else if(lavaV1B){
      lavaV1(leds, 100);
    }else if(lavaV2B){
      lavaV2(leds, 60, 10, 0-1);
    }else{
      allOff(leds);
    }

    delay(10);
  }
   
}


#endif
