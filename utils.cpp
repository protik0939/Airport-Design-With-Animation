#include "globals.h"

float rgb(int value) {
        return static_cast<float>(value) / 255.0f;
    }

void setColor(int r, int g, int b, float a) {
        glColor4f(rgb(r), rgb(g), rgb(b), a);
    }

void drawQuad(float left, float bottom, float right, float top) {
        glBegin(GL_QUADS);
        glVertex2f(left, bottom);
        glVertex2f(right, bottom);
        glVertex2f(right, top);
        glVertex2f(left, top);
        glEnd();
    }

void drawCircle(float cx, float cy, float radius, int segments) {
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);
        for (int i = 0; i <= segments; ++i) {
            const float angle = (2.0f * kPi * static_cast<float>(i)) / static_cast<float>(segments);
            glVertex2f(cx + radius * cosf(angle), cy + radius * sinf(angle));
        }
        glEnd();
    }

void drawCircleOutline(float cx, float cy, float radius, int segments) {
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < segments; ++i) {
            const float angle = (2.0f * kPi * static_cast<float>(i)) / static_cast<float>(segments);
            glVertex2f(cx + radius * cosf(angle), cy + radius * sinf(angle));
        }
        glEnd();
    }

void drawEllipse(float cx, float cy, float rx, float ry, int segments) {
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);
        for (int i = 0; i <= segments; ++i) {
            const float angle = (2.0f * kPi * static_cast<float>(i)) / static_cast<float>(segments);
            glVertex2f(cx + rx * cosf(angle), cy + ry * sinf(angle));
        }
        glEnd();
    }

void drawText(float x, float y, void* font, const char* text) {
        glRasterPos2f(x, y);
        for (const char* ch = text; *ch != '\0'; ++ch) {
            glutBitmapCharacter(font, *ch);
        }
    }

void drawGlassPanel(float left, float bottom, float right, float top) {
        // ... (this is just the anchor)
        setColor(26, 77, 118);
        drawQuad(left, bottom, right, top);

        setColor(42, 103, 148, 0.9f);
        drawQuad(left + 3.0f, bottom + 3.0f, right - 3.0f, top - 3.0f);

        glLineWidth(2.0f);
        glBegin(GL_LINES);
        glColor4f(rgb(191), rgb(226), rgb(247), 0.40f);
        for (float sx = left - 32.0f; sx < right + 28.0f; sx += 22.0f) {
            glVertex2f(sx, bottom + 3.0f);
            glVertex2f(sx + 44.0f, top - 3.0f);
        }
        glEnd();

        // Add outline to glass panel
        setColor(40, 40, 40, 0.7f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(left, bottom);
        glVertex2f(right, bottom);
        glVertex2f(right, top);
        glVertex2f(left, top);
        glEnd();
    }

void drawWheel(float cx, float cy, float r) {
        setColor(47, 54, 59);
        drawCircle(cx, cy, r, 28);

        setColor(159, 174, 182);
        drawCircle(cx, cy, r * 0.32f, 22);

        glLineWidth(1.5f);
        glBegin(GL_LINES);
        setColor(212, 224, 230);
        for (int i = 0; i < 6; ++i) {
            const float angle = gState.wheelPhase + static_cast<float>(i) * (kPi / 3.0f);
            glVertex2f(cx, cy);
            glVertex2f(cx + (r - 1.0f) * cosf(angle), cy + (r - 1.0f) * sinf(angle));
        }
        glEnd();
    }

