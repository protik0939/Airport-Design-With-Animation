#include "globals.h"

void drawControlTower() {
        setColor(54, 130, 186);
        glBegin(GL_POLYGON);
        glVertex2f(452.0f, 170.0f);
        glVertex2f(506.0f, 170.0f);
        glVertex2f(494.0f, 306.0f);
        glVertex2f(464.0f, 306.0f);
        glEnd();

        setColor(40, 40, 40, 0.7f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(452.0f, 170.0f);
        glVertex2f(506.0f, 170.0f);
        glVertex2f(494.0f, 306.0f);
        glVertex2f(464.0f, 306.0f);
        glEnd();

        setColor(36, 79, 126);
        glBegin(GL_POLYGON);
        glVertex2f(430.0f, 306.0f);
        glVertex2f(528.0f, 306.0f);
        glVertex2f(502.0f, 358.0f);
        glVertex2f(456.0f, 358.0f);
        glEnd();

        setColor(40, 40, 40, 0.7f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(430.0f, 306.0f);
        glVertex2f(528.0f, 306.0f);
        glVertex2f(502.0f, 358.0f);
        glVertex2f(456.0f, 358.0f);
        glEnd();

        // Tower glass panel
        setColor(26, 77, 118);
        glBegin(GL_POLYGON);
        glVertex2f(444.0f, 314.0f);
        glVertex2f(514.0f, 314.0f);
        glVertex2f(496.0f, 351.0f);
        glVertex2f(462.0f, 351.0f);
        glEnd();

        setColor(40, 40, 40, 0.7f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(444.0f, 314.0f);
        glVertex2f(514.0f, 314.0f);
        glVertex2f(496.0f, 351.0f);
        glVertex2f(462.0f, 351.0f);
        glEnd();

        // Cross bracing like sketch
        glBegin(GL_LINES);
        glVertex2f(444.0f, 314.0f); glVertex2f(496.0f, 351.0f);
        glVertex2f(514.0f, 314.0f); glVertex2f(462.0f, 351.0f);
        glVertex2f(479.0f, 314.0f); glVertex2f(479.0f, 351.0f);
        glEnd();

        setColor(76, 161, 212);
        drawQuad(476.0f, 358.0f, 482.0f, 412.0f);
        setColor(40, 40, 40, 0.7f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(476.0f, 358.0f);
        glVertex2f(482.0f, 358.0f);
        glVertex2f(482.0f, 412.0f);
        glVertex2f(476.0f, 412.0f);
        glEnd();

        const float pulse = 0.55f + 0.45f * (0.5f + 0.5f * sinf(gState.beaconPhase * 2.0f));
        glColor4f(1.0f, 0.2f * pulse, 0.2f * pulse, 1.0f);
        drawCircle(479.0f, 416.0f, 6.0f, 24);
        setColor(40, 40, 40, 0.7f);
        drawCircleOutline(479.0f, 416.0f, 6.0f, 24);
    }

