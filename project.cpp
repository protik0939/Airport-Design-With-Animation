#include "globals.h"

const float kPi = 3.1415926f;
const int kWorldWidth = 1000;
const int kWorldHeight = 500;

SceneState gState = { -260.0f, 85.0f, 0.0f, 0.0f, 0.0f, 1100.0f, 1250.0f, 0.0f, 0.0f };

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawSky();
    drawTerminal();
    drawControlTower();
    drawRunway();
    drawForeground();
    drawPlaneShadow(gState.planeX, gState.planeY);
    drawServiceVehicle(gState.serviceCarX, 98.0f);
    drawMiniAirplane(gState.miniPlaneX, 424.0f);
    drawMainAirplane(gState.planeX, gState.planeY);
    glutSwapBuffers();
}

void updateScene(int) {
    gState.cloudSlowX -= 0.18f;
    gState.cloudFastX -= 0.32f;

    if (gState.cloudSlowX < -650.0f) {
        gState.cloudSlowX = 200.0f;
    }
    if (gState.cloudFastX < -1000.0f) {
        gState.cloudFastX = 300.0f;
    }

    gState.serviceCarX -= 1.25f;
    if (gState.serviceCarX < -120.0f) {
        gState.serviceCarX = 1100.0f;
    }

    gState.miniPlaneX -= 1.75f;
    if (gState.miniPlaneX < -180.0f) {
        gState.miniPlaneX = 1220.0f;
    }

    gState.planeX += 1.5f;
    if (gState.planeX > 450.0f) {
        gState.planeLift += 0.008f;
        gState.planeY += gState.planeLift;
    }

    if (gState.planeX > 1220.0f) {
        gState.planeX = -260.0f;
        gState.planeY = 85.0f;
        gState.planeLift = 0.0f;
    }

    gState.wheelPhase += 0.18f;
    gState.beaconPhase += 0.07f;

    glutPostRedisplay();
    glutTimerFunc(16, updateScene, 0);
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, static_cast<double>(kWorldWidth), 0.0, static_cast<double>(kWorldHeight), -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void initScene() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    reshape(1000, 500);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1400, 680);
    glutCreateWindow("Airport Scenario");

    initScene();

    glutDisplayFunc(drawScene);
    glutReshapeFunc(reshape);
    glutTimerFunc(16, updateScene, 0);
    glutMainLoop();
    return 0;
}
