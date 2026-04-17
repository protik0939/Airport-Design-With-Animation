#include "globals.h"

void drawTerminal() {
        setColor(236, 242, 248);
        drawQuad(560.0f, 170.0f, 915.0f, 307.0f);

        setColor(40, 40, 40, 0.7f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(560.0f, 170.0f);
        glVertex2f(915.0f, 170.0f);
        glVertex2f(915.0f, 307.0f);
        glVertex2f(560.0f, 307.0f);
        glEnd();

        setColor(214, 226, 237);
        drawQuad(560.0f, 170.0f, 915.0f, 182.0f);

        // Left wing block
        setColor(245, 248, 252);
        drawQuad(520.0f, 170.0f, 615.0f, 255.0f);
        setColor(40, 40, 40, 0.7f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(520.0f, 170.0f);
        glVertex2f(615.0f, 170.0f);
        glVertex2f(615.0f, 255.0f);
        glVertex2f(520.0f, 255.0f);
        glEnd();

        drawGlassPanel(530.0f, 184.0f, 603.0f, 244.0f);

        // Main glass facade
        drawGlassPanel(630.0f, 182.0f, 895.0f, 294.0f);

        // Structural white frame like the reference image
        setColor(248, 250, 253);
        drawQuad(620.0f, 170.0f, 630.0f, 307.0f);
        drawQuad(895.0f, 170.0f, 905.0f, 307.0f);
        drawQuad(620.0f, 294.0f, 905.0f, 307.0f);

        // Glass dividers
        setColor(180, 208, 226, 0.9f);
        drawQuad(718.0f, 182.0f, 723.0f, 294.0f);
        drawQuad(804.0f, 182.0f, 809.0f, 294.0f);
        drawQuad(630.0f, 235.0f, 895.0f, 240.0f);

        // Outlines for glass dividers
        setColor(40, 40, 40, 0.7f);
        glBegin(GL_LINES);
        glVertex2f(718.0f, 182.0f); glVertex2f(718.0f, 294.0f);
        glVertex2f(804.0f, 182.0f); glVertex2f(804.0f, 294.0f);
        glVertex2f(630.0f, 235.0f); glVertex2f(895.0f, 235.0f);
        glEnd();

        // Roof sign
        setColor(244, 248, 252);
        drawQuad(705.0f, 312.0f, 822.0f, 340.0f);
        setColor(40, 40, 40, 0.7f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(705.0f, 312.0f);
        glVertex2f(822.0f, 312.0f);
        glVertex2f(822.0f, 340.0f);
        glVertex2f(705.0f, 340.0f);
        glEnd();

        setColor(32, 78, 118);
        drawText(738.0f, 322.0f, GLUT_BITMAP_HELVETICA_18, "AIRPORT");
    }

