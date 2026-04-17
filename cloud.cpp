#include "globals.h"

void drawCloud(float x, float y, float scale) {
        setColor(242, 251, 255, 0.95f);
        drawCircle(x, y, 18.0f * scale);
        drawCircle(x + 16.0f * scale, y + 8.0f * scale, 16.0f * scale);
        drawCircle(x + 34.0f * scale, y, 20.0f * scale);
        drawCircle(x + 52.0f * scale, y + 6.0f * scale, 14.0f * scale);

        setColor(227, 243, 252, 0.9f);
        drawEllipse(x + 24.0f * scale, y - 8.0f * scale, 40.0f * scale, 12.0f * scale);

        setColor(40, 40, 40, 0.7f);
        glLineWidth(2.0f);
        drawCircleOutline(x, y, 18.0f * scale);
        drawCircleOutline(x + 16.0f * scale, y + 8.0f * scale, 16.0f * scale);
        drawCircleOutline(x + 34.0f * scale, y, 20.0f * scale);
        drawCircleOutline(x + 52.0f * scale, y + 6.0f * scale, 14.0f * scale);
    }

