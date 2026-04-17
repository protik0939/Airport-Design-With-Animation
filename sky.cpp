#include "globals.h"

void drawSky() {
        glBegin(GL_QUADS);
        setColor(220, 244, 255);
        glVertex2f(0.0f, 150.0f);
        glVertex2f(static_cast<float>(kWorldWidth), 150.0f);
        setColor(95, 194, 236);
        glVertex2f(static_cast<float>(kWorldWidth), static_cast<float>(kWorldHeight));
        glVertex2f(0.0f, static_cast<float>(kWorldHeight));
        glEnd();

        drawSun();

        setColor(100, 169, 187);
        glBegin(GL_POLYGON);
        glVertex2f(0.0f, 170.0f);
        glVertex2f(120.0f, 245.0f);
        glVertex2f(240.0f, 170.0f);
        glEnd();

        setColor(240, 248, 255);
        glBegin(GL_POLYGON);
        glVertex2f(90.0f, 226.0f);
        glVertex2f(120.0f, 245.0f);
        glVertex2f(150.0f, 226.0f);
        glVertex2f(125.0f, 220.0f);
        glVertex2f(110.0f, 224.0f);
        glEnd();

        setColor(40, 40, 40, 0.7f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(0.0f, 170.0f);
        glVertex2f(120.0f, 245.0f);
        glVertex2f(240.0f, 170.0f);
        glEnd();

        glBegin(GL_LINE_STRIP);
        glVertex2f(90.0f, 226.0f);
        glVertex2f(110.0f, 224.0f);
        glVertex2f(125.0f, 220.0f);
        glVertex2f(150.0f, 226.0f);
        glEnd();

        setColor(114, 184, 203);
        glBegin(GL_POLYGON);
        glVertex2f(170.0f, 170.0f);
        glVertex2f(330.0f, 280.0f);
        glVertex2f(500.0f, 170.0f);
        glEnd();

        setColor(240, 248, 255);
        glBegin(GL_POLYGON);
        glVertex2f(280.0f, 245.0f);
        glVertex2f(330.0f, 280.0f);
        glVertex2f(380.0f, 245.0f);
        glVertex2f(355.0f, 235.0f);
        glVertex2f(340.0f, 247.0f);
        glVertex2f(320.0f, 240.0f);
        glVertex2f(300.0f, 248.0f);
        glEnd();

        setColor(40, 40, 40, 0.7f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(170.0f, 170.0f);
        glVertex2f(330.0f, 280.0f);
        glVertex2f(500.0f, 170.0f);
        glEnd();

        glBegin(GL_LINE_STRIP);
        glVertex2f(280.0f, 245.0f);
        glVertex2f(300.0f, 248.0f);
        glVertex2f(320.0f, 240.0f);
        glVertex2f(340.0f, 247.0f);
        glVertex2f(355.0f, 235.0f);
        glVertex2f(380.0f, 245.0f);
        glEnd();

        setColor(130, 196, 214);
        glBegin(GL_POLYGON);
        glVertex2f(430.0f, 170.0f);
        glVertex2f(620.0f, 255.0f);
        glVertex2f(820.0f, 170.0f);
        glEnd();

        setColor(40, 40, 40, 0.7f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(430.0f, 170.0f);
        glVertex2f(620.0f, 255.0f);
        glVertex2f(820.0f, 170.0f);
        glEnd();

        drawCloud(80.0f + gState.cloudSlowX, 410.0f, 1.2f);
        drawCloud(480.0f + gState.cloudSlowX, 445.0f, 1.05f);
        drawCloud(230.0f + gState.cloudFastX, 360.0f, 0.95f);
        drawCloud(760.0f + gState.cloudFastX, 390.0f, 1.1f);
    }

