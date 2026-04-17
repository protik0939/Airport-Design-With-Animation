#include "globals.h"

// Draw the large main airplane, referencing x and y parameters for position
void drawMainAirplane(float x, float y) {
    // Condition to drop the gear if the plane is approaching the runway
    const bool gearDown = (x < 560.0f) || (y < 130.0f);

    // ==========================================
    // 1. Subtle drop shadow for depth
    // ==========================================
    // Color arguments: R, G, B, Alpha (opacity) - values are 0-255 for RGB (handled by utility), 0.0-1.0 for Alpha
    setColor(0, 0, 0, 0.15f); // Semi-transparent black shadow
    glBegin(GL_POLYGON); // Begin drawing a multi-sided shaded shape
    // Define vertices of the shadow, x+ offset determines horizontal width, y+ determines height
    glVertex2f(x + 30.0f, y + 36.0f);   // Bottom left
    glVertex2f(x + 250.0f, y + 36.0f);  // Bottom right
    glVertex2f(x + 280.0f, y + 46.0f);  // Nose curve up
    glVertex2f(x + 250.0f, y + 66.0f);  // Top right
    glVertex2f(x + 30.0f, y + 66.0f);   // Top left
    glEnd(); // End shape

    // ==========================================
    // 2. Landing Gear (drawn behind the fuselage & wings)
    // ==========================================
    if (gearDown) {
        glLineWidth(3.0f); // Make lines thicker
        setColor(100, 105, 110); // Dark grey for the metal struts
        glBegin(GL_LINES); // Begin drawing straight lines
        // Back wheels strut (Line from plane body down to wheel)
        glVertex2f(x + 100.0f, y + 40.0f); // Top part connected to body
        glVertex2f(x + 100.0f, y + 12.0f); // Bottom part connected to wheel
        // Front wheel strut (Line from plane nose down to wheel)
        glVertex2f(x + 240.0f, y + 42.0f); // Top part connected to nose
        glVertex2f(x + 240.0f, y + 14.0f); // Bottom part connected to wheel
        glEnd(); // End lines

        // Wheels: (x coordinate, y coordinate, radius)
        drawWheel(x + 97.0f, y + 12.0f, 6.0f);   // Back wheel 1
        drawWheel(x + 103.0f, y + 12.0f, 6.0f);  // Back wheel 2
        drawWheel(x + 240.0f, y + 14.0f, 5.0f);  // Front wheel
    }

    // ==========================================
    // 3. Fuselage (Main Body) - White
    // ==========================================
    setColor(240, 242, 245); // Off-white color for the main body
    glBegin(GL_POLYGON);
    glVertex2f(x + 10.0f, y + 54.0f);   // Tail tip (far left)
    glVertex2f(x + 40.0f, y + 40.0f);   // Bottom rear curve
    glVertex2f(x + 240.0f, y + 40.0f);  // Belly straight line to front
    glVertex2f(x + 265.0f, y + 43.0f);  // Nose bottom curve starting up
    glVertex2f(x + 280.0f, y + 50.0f);  // Nose tip (far right)
    glVertex2f(x + 270.0f, y + 60.0f);  // Nose top curve up towards cockpit
    glVertex2f(x + 240.0f, y + 64.0f);  // Roof line front
    glVertex2f(x + 60.0f, y + 64.0f);   // Roof line moving back
    glVertex2f(x + 30.0f, y + 60.0f);   // Roof tapering into the tail
    glEnd();

    // ==========================================
    // 4. Grey underbelly shade (Adds depth below the fuselage)
    // ==========================================
    setColor(210, 215, 220); // Light Grey
    glBegin(GL_POLYGON);
    glVertex2f(x + 20.0f, y + 50.0f);  // Start at bottom rear
    glVertex2f(x + 40.0f, y + 40.0f);  // Wrap to the bottom flat belly
    glVertex2f(x + 240.0f, y + 40.0f); // Stretch across bottom belly
    glVertex2f(x + 265.0f, y + 43.0f); // Curve under the nose
    glVertex2f(x + 280.0f, y + 50.0f); // Connect up to the tip
    glVertex2f(x + 200.0f, y + 45.0f); // Move inward, setting shade thickness
    glVertex2f(x + 50.0f, y + 45.0f);  // Move backward across the belly outline
    glEnd();

    // ==========================================
    // 5. Red Tail Fin (Vertical Stabilizer)
    // ==========================================
    setColor(230, 40, 40); // Bright Red
    glBegin(GL_POLYGON); // The large fin at the back of the plane
    glVertex2f(x + 35.0f, y + 62.0f);  // Base front
    glVertex2f(x + 55.0f, y + 64.0f);  // Base back
    glVertex2f(x + 65.0f, y + 64.0f);  // Further back connection
    glVertex2f(x + 35.0f, y + 110.0f); // Top rear corner of the fin
    glVertex2f(x + 15.0f, y + 110.0f); // Top front corner of the fin
    glVertex2f(x + 25.0f, y + 70.0f);  // Connecting slanted edge
    glEnd();

    // ==========================================
    // 6. Far Horizontal stabilizer (Background tail wing)
    // ==========================================
    setColor(200, 205, 210); // Shaded Grey (because it's in the background)
    glBegin(GL_POLYGON);
    glVertex2f(x + 45.0f, y + 54.0f);
    glVertex2f(x + 65.0f, y + 54.0f);
    glVertex2f(x + 50.0f, y + 65.0f);
    glVertex2f(x + 20.0f, y + 65.0f);
    glEnd();

    // ==========================================
    // 7. Near Horizontal stabilizer (Foreground tail wing)
    // ==========================================
    setColor(235, 238, 240); // White
    glBegin(GL_POLYGON);
    glVertex2f(x + 25.0f, y + 52.0f); // Attach to fuselage
    glVertex2f(x + 65.0f, y + 52.0f); // Attach
    glVertex2f(x + 35.0f, y + 35.0f); // Tip extending out and down
    glVertex2f(x + 15.0f, y + 35.0f); // Return to fuselage
    glEnd();

    // ==========================================
    // 8. Red Engine (Under the wing)
    // ==========================================
    setColor(230, 40, 40); // Bright Red body of engine
    // drawQuad arguments: (xLeft, yBottom, xRight, yTop)
    drawQuad(x + 130.0f, y + 20.0f, x + 160.0f, y + 34.0f);
    // drawEllipse arguments: (xCenter, yCenter, radiusX, radiusY)
    drawEllipse(x + 130.0f, y + 27.0f, 5.0f, 7.0f); // Rounded back cap of engine 

    // White engine front air intake
    setColor(250, 250, 250);
    drawQuad(x + 160.0f, y + 20.0f, x + 168.0f, y + 34.0f); // Engine front band
    drawEllipse(x + 168.0f, y + 27.0f, 4.0f, 7.0f); // Rounded forward cap

    // ==========================================
    // 9. Main Wing (Foreground)
    // ==========================================
    // Lower shadowed side of the wing
    setColor(200, 205, 210); // Shaded Grey
    glBegin(GL_POLYGON);
    glVertex2f(x + 120.0f, y + 45.0f); // Attach root back
    glVertex2f(x + 160.0f, y + 45.0f); // Attach root front
    glVertex2f(x + 105.0f, y + 6.0f);  // Wingtip front (extending out and down)
    glVertex2f(x + 75.0f, y + 6.0f);   // Wingtip back
    glEnd();

    // Top bright part of the wing
    setColor(235, 238, 240); // White
    glBegin(GL_POLYGON);
    glVertex2f(x + 120.0f, y + 45.0f);
    glVertex2f(x + 155.0f, y + 45.0f);
    glVertex2f(x + 100.0f, y + 10.0f);
    glVertex2f(x + 75.0f, y + 10.0f);
    glEnd();

    // ==========================================
    // 10. Cockpit Window (Front cabin)
    // ==========================================
    setColor(45, 80, 110); // Dark Blue Glass
    glBegin(GL_POLYGON);
    glVertex2f(x + 275.0f, y + 50.0f); // Pointy tip at the nose
    glVertex2f(x + 258.0f, y + 50.0f); // Bottom left frame
    glVertex2f(x + 258.0f, y + 56.0f); // Top left frame
    glVertex2f(x + 268.0f, y + 56.0f); // Top curve right
    glEnd();

    // ==========================================
    // 11. Passenger Windows (Capsules)
    // ==========================================
    setColor(45, 80, 110); // Dark Blue Glass
    for (int i = 0; i < 16; ++i) { // Loop exactly 16 times to array windows along body
        // Calculate the base X position of the current window by shifting forward
        float wx = x + 80.0f + i * 10.0f; // 10.0f defines spacing between windows

        // Draw the window as a long rectangle with two circular caps on the sides
        drawQuad(wx, y + 49.0f, wx + 4.0f, y + 55.0f); // Middle rectangular body
        drawEllipse(wx, y + 52.0f, 2.0f, 3.0f);        // Left rounded edge
        drawEllipse(wx + 4.0f, y + 52.0f, 2.0f, 3.0f); // Right rounded edge
    }
}

void drawMiniAirplane(float x, float y) {
    setColor(233, 243, 251, 0.35f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex2f(x + 95.0f, y + 8.0f);
    glVertex2f(x + 145.0f, y + 8.0f);
    glEnd();

    setColor(56, 80, 100);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + 84.0f, y);
    glVertex2f(x + 108.0f, y + 15.0f);
    glVertex2f(x + 24.0f, y + 15.0f);
    glVertex2f(x + 8.0f, y + 9.0f);
    glEnd();

    setColor(167, 216, 247);
    glBegin(GL_POLYGON);
    glVertex2f(x + 18.0f, y + 7.0f);
    glVertex2f(x + 30.0f, y + 7.0f);
    glVertex2f(x + 30.0f, y + 15.0f);
    glEnd();

    setColor(41, 63, 79);
    glBegin(GL_POLYGON);
    glVertex2f(x + 40.0f, y - 10.0f);
    glVertex2f(x + 65.0f, y - 10.0f);
    glVertex2f(x + 75.0f, y);
    glVertex2f(x + 65.0f, y + 10.0f);
    glVertex2f(x + 40.0f, y + 10.0f);
    glEnd();

    setColor(41, 63, 79);
    glBegin(GL_POLYGON);
    glVertex2f(x + 74.0f, y + 15.0f);
    glVertex2f(x + 103.0f, y + 15.0f);
    glVertex2f(x + 99.0f, y + 30.0f);
    glVertex2f(x + 84.0f, y + 22.0f);
    glVertex2f(x + 77.0f, y + 22.0f);
    glEnd();
}

void drawPlaneShadow(float planeX, float planeY) {
    float shadowY = 70.0f; // On the road
    float scaleY = 0.3f; // Flattened perspective

    setColor(40, 50, 60, 0.4f); // Dark shadow color

    // Fuselage shadow
    drawEllipse(planeX + 140.0f, shadowY, 110.0f, 25.0f * scaleY);

    // Wings shadow
    glBegin(GL_POLYGON);
    glVertex2f(planeX + 110.0f, shadowY + 5.0f);
    glVertex2f(planeX + 150.0f, shadowY + 60.0f * scaleY);
    glVertex2f(planeX + 180.0f, shadowY + 60.0f * scaleY);
    glVertex2f(planeX + 140.0f, shadowY - 5.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(planeX + 110.0f, shadowY - 5.0f);
    glVertex2f(planeX + 140.0f, shadowY - 60.0f * scaleY);
    glVertex2f(planeX + 170.0f, shadowY - 60.0f * scaleY);
    glVertex2f(planeX + 140.0f, shadowY + 5.0f);
    glEnd();

    // Horizontal tail shadow
    glBegin(GL_POLYGON);
    glVertex2f(planeX + 26.0f, shadowY + 2.0f);
    glVertex2f(planeX + 40.0f, shadowY + 30.0f * scaleY);
    glVertex2f(planeX + 55.0f, shadowY + 30.0f * scaleY);
    glVertex2f(planeX + 40.0f, shadowY - 2.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(planeX + 26.0f, shadowY - 2.0f);
    glVertex2f(planeX + 35.0f, shadowY - 30.0f * scaleY);
    glVertex2f(planeX + 50.0f, shadowY - 30.0f * scaleY);
    glVertex2f(planeX + 40.0f, shadowY + 2.0f);
    glEnd();
}

