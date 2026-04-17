#pragma once
#include <windows.h>
#include <GL/glut.h>
#include <cmath>

extern const float kPi;
extern const int kWorldWidth;
extern const int kWorldHeight;

struct SceneState {
    float planeX;
    float planeY;
    float planeLift;
    float cloudSlowX;
    float cloudFastX;
    float serviceCarX;
    float miniPlaneX;
    float wheelPhase;
    float beaconPhase;
};

extern SceneState gState;

float rgb(int value);
void setColor(int r, int g, int b, float a = 1.0f);
void drawQuad(float left, float bottom, float right, float top);
void drawCircle(float cx, float cy, float radius, int segments = 48);
void drawCircleOutline(float cx, float cy, float radius, int segments = 48);
void drawEllipse(float cx, float cy, float rx, float ry, int segments = 64);
void drawText(float x, float y, void* font, const char* text);
void drawGlassPanel(float left, float bottom, float right, float top);
void drawWheel(float cx, float cy, float r);

void drawSun();
void drawCloud(float x, float y, float scale);
void drawSky();
void drawRunway();
void drawTerminal();
void drawControlTower();
void drawServiceVehicle(float x, float y);
void drawPlaneShadow(float planeX, float planeY);
void drawMainAirplane(float x, float y);
void drawMiniAirplane(float x, float y);
void drawForeground();
