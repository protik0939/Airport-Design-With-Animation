#include "globals.h"

void drawSun() {
    setColor(255, 232, 170, 0.30f);
    drawCircle(140.0f, 420.0f, 65.0f);
    setColor(255, 214, 120, 0.85f);
    drawCircle(140.0f, 420.0f, 38.0f);

    setColor(40, 40, 40, 0.7f);
    glLineWidth(2.0f);
    drawCircleOutline(140.0f, 420.0f, 38.0f);
    drawCircleOutline(140.0f, 420.0f, 65.0f);
}

