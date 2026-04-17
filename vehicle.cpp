#include "globals.h"

void drawServiceVehicle(float x, float y) {
        // Cab of the truck
        setColor(125, 170, 188);
        drawQuad(x + 20.0f, y + 15.0f, x + 60.0f, y + 35.0f);
        drawQuad(x, y + 15.0f, x + 20.0f, y + 50.0f);

        setColor(40, 40, 40, 0.7f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x + 20.0f, y + 15.0f);
        glVertex2f(x + 60.0f, y + 15.0f);
        glVertex2f(x + 60.0f, y + 35.0f);
        glVertex2f(x + 20.0f, y + 35.0f);
        glEnd();
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, y + 15.0f);
        glVertex2f(x + 20.0f, y + 15.0f);
        glVertex2f(x + 20.0f, y + 50.0f);
        glVertex2f(x, y + 50.0f);
        glEnd();

        // Box/equipment on the back
        setColor(200, 160, 100);
        drawQuad(x + 5.0f, y + 50.0f, x + 55.0f, y + 60.0f);
        setColor(40, 40, 40, 0.7f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x + 5.0f, y + 50.0f);
        glVertex2f(x + 55.0f, y + 50.0f);
        glVertex2f(x + 55.0f, y + 60.0f);
        glVertex2f(x + 5.0f, y + 60.0f);
        glEnd();

        // Wheels
        drawWheel(x + 10.0f, y + 13.0f, 6.0f);
        drawWheel(x + 50.0f, y + 13.0f, 6.0f);
    }

