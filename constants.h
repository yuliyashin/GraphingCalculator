#ifndef CONSTANTS_H
#define CONSTANTS_H
const float SCREEN_WIDTH = 2400; //800
const float SCREEN_HEIGHT = 1400; //800
const float WORK_PANEL = SCREEN_WIDTH*4/5;
const float SIDE_BAR = SCREEN_WIDTH*1/5;

const int SB_MOUSE_POSITION = 0;
const int SB_MOUSE_CLICKED = SB_MOUSE_POSITION + 1;
const int SB_KEY_PRESSED = SB_MOUSE_CLICKED + 1;

const int NUMOFPOINTS = 5000;

const int ZOOMIN = 1;
const int ZOOMOUT = 2;
const int PANLEFT = 3;
const int PANRIGHT = 4;
const int PANUP = 5;
const int PANDOWN = 6;
const int INPUT = 7;

const int SPEED = 1;    // positive number

#endif // CONSTANTS_H
