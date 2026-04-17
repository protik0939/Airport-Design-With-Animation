#include "globals.h"

void drawRunway() {
        setColor(65, 78, 88);
        drawQuad(0.0f, 0.0f, static_cast<float>(kWorldWidth), 150.0f);

        setColor(53, 64, 73);
        drawQuad(0.0f, 0.0f, static_cast<float>(kWorldWidth), 20.0f);

        setColor(99, 124, 132);
        drawQuad(0.0f, 150.0f, static_cast<float>(kWorldWidth), 170.0f);

        setColor(240, 240, 240);
        for (int x = 30; x < kWorldWidth; x += 85) {
            drawQuad(static_cast<float>(x), 72.0f, static_cast<float>(x + 45), 80.0f);
        }

        setColor(255, 210, 85);
        drawQuad(0.0f, 132.0f, static_cast<float>(kWorldWidth), 136.0f);

        setColor(255, 255, 255, 0.75f);
        drawText(30.0f, 30.0f, GLUT_BITMAP_HELVETICA_18, "09");
        drawText(940.0f, 30.0f, GLUT_BITMAP_HELVETICA_18, "27");

        for (int i = 0; i < 20; ++i) {
            const float x = 20.0f + static_cast<float>(i) * 50.0f;
            const float pulse = 0.35f + 0.65f * (0.5f + 0.5f * sinf(gState.beaconPhase + static_cast<float>(i) * 0.5f));

            glColor4f(1.0f, 0.88f * pulse, 0.22f * pulse, 1.0f);
            drawCircle(x, 145.0f, 4.0f, 24);

            glColor4f(0.2f + 0.7f * pulse, 0.6f + 0.4f * pulse, 1.0f, 1.0f);
            drawCircle(x + 25.0f, 10.0f, 3.5f, 24);
        }
    }

void drawForeground() {
        setColor(90, 126, 134);
        drawQuad(0.0f, 150.0f, 430.0f, 170.0f);

        setColor(108, 147, 157);
        drawQuad(530.0f, 150.0f, 1000.0f, 170.0f);

        for (int i = 0; i < 7; ++i) {
            const float x = 80.0f + static_cast<float>(i) * 130.0f;
            setColor(44, 69, 73);
            drawQuad(x, 166.0f, x + 4.0f, 200.0f);

            setColor(230, 170, 61);
            drawCircle(x + 2.0f, 203.0f, 5.0f, 18);
        }
    }

