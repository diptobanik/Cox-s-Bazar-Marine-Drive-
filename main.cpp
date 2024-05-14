#include <iostream>
#include <cmath>
#include <GL/glut.h>
#include <math.h>
#include "glutil.h"

GLfloat i = 0.0f;
GLfloat position_car1x = 0.0f;
GLfloat position_car1y = 0.0f;
GLfloat position_busx = 0.0f;
GLfloat position_busy = 0.0f;
GLfloat position_train1x = 0.0f;
GLfloat position_train2x = 0.0f;
GLfloat position_cloud1x = 0.0f;
GLfloat position_cloud2x = 0.0f;
GLfloat position_cloud3x = 0.0f;
GLfloat position_rainY = 0.0f;
GLfloat position_boat1x = 0.0f;
GLfloat position_boat2x = 0.0f;

GLfloat speed = 0.01f;
GLfloat speed1 = 0.001f;
GLfloat speed2 = 0.01f;
GLfloat speedTrain = 0.03f;
GLfloat speedBoat = 0.02f;

// GLfloat speed2 = 0.001f;
#define PI 3.14159265358979323846
using namespace std;

//////////
void drawText(const char* text, float x, float y,float scale, float r, float g, float b,int fontSize) {
    glColor3f(r, g, b); // Set text color
    glRasterPos2f(x, y); // Set raster position for text rendering
    glScalef(scale, scale, 1.0f);
    if (fontSize == 24)
        for (const char* c = text; *c != '\0'; ++c) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c); // Render each character
        }
    else if (fontSize == 18)
        for (const char* c = text; *c != '\0'; ++c) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // Render each character
        }
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3d(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();

    // Draw the rectangle with the applied texture
    glColor3d(1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslatef(0.010f, 0.70f, 0.0f);  // Adjust the translation to match the texture coordinates
    glBegin(GL_QUADS);
    glVertex2f(-0.50f, 0.0f);
    glVertex2f(0.5f, 0.0f);
    glVertex2f(0.5f, 0.3f);
    glVertex2f(-0.50f, 0.30f);
    glEnd();

    ApplyTexture(-0.50f, 0.0f, 0.5f,0.0f,  0.50f, 0.30f, -0.50f, 0.30f, textures[0].textureID); // Adjusted texture coordinates
    glPopMatrix();

    drawText("American International University-Bangladesh", -0.3f, 0.67f, 1.0f, 0.0f, 0.0f, 0.0f, 24);
    drawText("Spring 2023-24", -0.080f, 0.6f, 1.0f, 0.0f, 0.0f, 0.0f, 18);
    drawText("Cox's Bazar Marine Drive", -0.130f, 0.55f, 1.0f, 0.0f, 0.0f, 0.0f, 18);
    drawText("Computer Graphics Project", -0.1380f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 18);
    drawText("Course Teacher: Mahfujur Rahman", -0.17f, 0.45f, 1.0f, 0.0f, 0.0f, 0.0f, 18);
    /**drawText("Group Members:", -0.08f, 0.4f, 1.0f, 0.0f, 0.0f, 0.0f, 18);
    drawText("Mushfika Ikfat 21-45498-3", -0.17f, 0.35f, 1.0f, 0.0f, 0.0f, 0.0f, 18);
    drawText("Ahmed Hossain 21-45578-3", -0.17f, 0.3f, 1.0f, 0.0f, 0.0f, 0.0f, 18);
    drawText("Asif Mahamud Shaon 21-45965-3", -0.17f, 0.25f, 1.0f, 0.0f, 0.0f, 0.0f, 18);
    drawText("Dipta Banik 21-45520-3", -0.17f, 0.20f, 1.0f, 0.0f, 0.0f, 0.0f, 18);
    drawText("Annan Kumar Saha 22-46753-1", -0.17f, 0.15f, 1.0f, 0.0f, 0.0f, 0.0f, 18);**/
    drawText("Group Members:", -0.8f, 0.4f, 1.0f, 0.0f, 0.0f, 0.0f, 18);
    drawText("Mushfika Ikfat 21-45498-3", -0.8f, 0.35f, 1.0f, 0.0f, 0.0f, 0.0f, 18);
    drawText("Ahmed Hossain 21-45578-3", -0.8f, 0.3f, 1.0f, 0.0f, 0.0f, 0.0f, 18);
    drawText("Asif Mahamud Shaon 21-45965-3", -0.8f, 0.25f, 1.0f, 0.0f, 0.0f, 0.0f, 18);
    drawText("Dipta Banik 21-45520-3", -0.8f, 0.20f, 1.0f, 0.0f, 0.0f, 0.0f, 18);
    drawText("Annan Kumar Saha 22-46753-1", -0.8f, 0.15f, 1.0f, 0.0f, 0.0f, 0.0f, 18);


    glutSwapBuffers();

}
//////////

/**.................................... Cox's bazar Marine Drive ..........................................**/

/**....................................... Flower up ..........................................**/

GLfloat flowerP = 0.0f;
GLfloat flowerS = 0.005f;

void flowerUp(int value)
{
    if (flowerP > 0.2)
        flowerS = -0.0f;
    flowerP += flowerS;
    glutPostRedisplay();
    glutTimerFunc(100, flowerUp, 0);
}

GLfloat flowerP1 = 0.0f;
GLfloat flowerS1 = 0.005f;

void flowerUp1(int value)
{
    if (flowerP1 > 0.2)
        flowerS1 = -0.0f;
    flowerP1 += flowerS1;
    glutPostRedisplay();
    glutTimerFunc(100, flowerUp1, 0);
}

/**....................................... Rain fall ..........................................**/

GLfloat rainP = 0.0f;
GLfloat rainSpeed = 0.05f;
void rainUp(int value)
{

    if (rainP < -1.0)
        rainP = -0.9f;
    rainP -= rainSpeed;
    glutPostRedisplay();
    glutTimerFunc(100, rainUp, 0);
}
/**....................................... Snow Fall ..........................................**/

GLfloat snowP = 3.0f;

GLfloat snowS = 0.0105f;

void snowUp(int value)
{

    if (snowP < -.50)
        snowP = 1.0f;
    snowP -= snowS;
    glutPostRedisplay();
    glutTimerFunc(100, snowUp, 0);
}
/**....................................... Rain Cloud ..........................................**/

GLfloat RcloudP = 3.5f;
GLfloat RcloudS = 0.02f;

void RcloudUp(int value)
{
    if (RcloudP < -0.1)
        RcloudP = .4f;
    RcloudP -= RcloudS;
    glutPostRedisplay();
    glutTimerFunc(100, RcloudUp, 0);
}

GLfloat treeP1 = 0.0;
GLfloat treeP2 = 0.0;
GLfloat treeP3 = 0.0;
GLfloat treeP4 = 0.0;
GLfloat treeP5 = 0.0;
GLfloat treeP6 = 0.0;
GLfloat treeP7 = 0.0;
GLfloat treeP8 = 0.0;
GLfloat treeP9 = 0.0;
GLfloat treeP10 = 0.0;
GLfloat treeP11 = 0.0;
GLfloat treeP12 = 0.0;
GLfloat treeS1 = 0.03;
GLfloat treeS2 = 0.03;
GLfloat treeS3 = 0.03;
GLfloat treeS4 = 0.03;
GLfloat treeS5 = 0.03;
GLfloat treeS6 = 0.03;
GLfloat treeS7 = 0.03;
GLfloat treeS8 = 0.03;
GLfloat treeS9 = 0.03;
GLfloat treeS10 = 0.03;
GLfloat treeS11 = 0.03;
GLfloat treeS12 = 0.03;
void treeUp(int value)
{

    if (treeP1 < -1.0)
    {
        treeS1 = 0.0f;

        if (treeP2 < -.4)
        {
            treeS2 = 0.0f;

            if (treeP3 < -.4)
            {
                treeS3 = 0.0f;

                if (treeP4 < -1.0)
                {
                    treeS4 = 0.0f;

                    if (treeP5 < -.5)
                    {
                        treeS5 = 0.0f;

                        if (treeP6 < -.5)
                        {
                            treeS6 = 0.0f;

                            if (treeP7 < -1.0)
                            {
                                treeS7 = 0.0f;

                                if (treeP8 < -.6)
                                {
                                    treeS8 = 0.0f;

                                    if (treeP9 < -1.0)
                                    {
                                        treeS9 = 0.0f;

                                        if (treeP10 < -1.0)
                                        {
                                            treeS10 = 0.0f;

                                            if (treeP11 < -.5)
                                            {
                                                treeS11 = 0.0f;

                                                if (treeP12 < -.6)
                                                {
                                                    treeS12 = 0.0f;
                                                }
                                                treeP12 -= treeS12;
                                            }
                                            treeP11 -= treeS11;
                                        }
                                        treeP10 -= treeS10;
                                    }
                                    treeP9 -= treeS9;
                                }
                                treeP8 -= treeS8;
                            }
                            treeP7 -= treeS7;
                        }
                        treeP6 -= treeS6;
                    }
                    treeP5 -= treeS5;
                }
                treeP4 -= treeS4;
            }
            treeP3 -= treeS3;
        }
        treeP2 -= treeS2;
    }
    treeP1 -= treeS1;

    glutPostRedisplay();
    glutTimerFunc(100, treeUp, 0);
}

void circle(float a, float b, float r)
{

    int i;
    int triangleAmount = 100;
    GLfloat twicePi = 2.0f * PI;
    GLfloat x = a;
    GLfloat y = b;
    GLfloat radius = r;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}

void motion_vehicle(int value)
{
    if (position_car1x < -1.5)
        position_car1x = 1.5f;

    if (position_busx > 1.5)
        position_busx = -1.5f;

    if (position_car1y > 0.2)
        position_car1y = -0.1f;


    if (position_busy < -0.2)
        position_busy = 0.1f;

    if (position_train1x < -1.5)
        position_train1x = 1.5f;

    if (position_train2x > 1.5)
        position_train2x = -1.5f;

    if (position_cloud1x < -1.5)
        position_cloud1x = 1.5f;

    if (position_cloud2x > 1.5)
        position_cloud2x = -1.5f;

    if (position_cloud3x > 1.5)
        position_cloud3x = -1.5f;

    if (position_boat1x < -1.5)
        position_boat1x = 1.5f;

    if (position_boat2x > 1.5)
        position_boat2x = -1.5f;

    position_car1x -= speed;
    position_busx += speed;
    position_car1y += speed1;
    position_busy -= speed1;
    position_train1x -= speedTrain;
    position_train2x += speedTrain;
    position_cloud1x -= speed2;
    position_cloud2x += speed2;
    position_cloud3x += speed2;
    position_boat1x -= speedBoat;
    position_boat2x += speedBoat;
    glutPostRedisplay();
    glutTimerFunc(100, motion_vehicle, 0);
}

void motion2_vehicle(int value)
{
    if (position_car1x > 1.5)
        position_car1x = -1.5f;



    if (position_busx < -1.5)
        position_busx = 1.5f;

    if (position_car1y < -0.2)
        position_car1y = 0.1f;

    if (position_busy > 0.2)
      position_busy = -0.1f;

    if (position_train1x > 1.5)
        position_train1x = -1.5f;

    if (position_train2x < -1.5)
        position_train2x = 1.5f;

    if (position_cloud1x > 1.5)
        position_cloud1x = -1.5f;

    if (position_cloud2x < -1.5)
        position_cloud2x = 1.5f;

    if (position_cloud3x < -1.5)
        position_cloud3x = 1.5f;

    if (position_boat1x > 1.5)
        position_boat1x = -1.5f;

    if (position_boat2x < -1.5)
        position_boat2x = 1.5f;

    position_car1x += speed;
    position_busx -= speed;
    position_car1y -= speed1;
    position_busy += speed1;
    position_train1x += speedTrain;
    position_train2x -= speedTrain;
    position_cloud1x += speed2;
    position_cloud2x -= speed2;
    position_cloud3x -= speed2;
    position_boat1x += speedBoat;
    position_boat2x -= speedBoat;

    glutPostRedisplay();
    glutTimerFunc(100, motion2_vehicle, 0);
}

void motion_rain(int value)
{
    if (position_rainY < -0.1)
        position_rainY = 0.1f;

    position_rainY -= speed;

    glutPostRedisplay();
    glutTimerFunc(100, motion_rain, 0);
}

void SpecialInput(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        speed = speed + 0.01;
        speed1 = speed1 + 0.001;
        speed2 = speed2 + 0.001;
        speedTrain = speedTrain + 0.003;
        speedBoat = speedBoat + 0.002;
        break;

    case GLUT_KEY_DOWN:
        speed = speed - 0.01;
        speed1 = speed1 - 0.001;
        speedTrain = speedTrain - 0.003;
        speedBoat = speedBoat - 0.002;

        break;

    case GLUT_KEY_LEFT:
        glutTimerFunc(100, motion_vehicle, 0);

        // train_sound();
        break;

    case GLUT_KEY_RIGHT:
        glutTimerFunc(100, motion2_vehicle, 0);

        break;

    case GLUT_KEY_F1:

        glutTimerFunc(100, motion_rain, 0);
        break;
    case GLUT_KEY_INSERT:

        speedTrain = 0.0;

        break;

    default:
        break;
    }
    glutPostRedisplay();
}

void rainCloud()    // rrain
{

    circle(-2.03, .95, .1);
    circle(-1.84, .93, .15);
    circle(-1.54, .93, .18);
    circle(-1.28, .93, .15);
    circle(-1.0, .93, .17);
    circle(-.93, .95, .1);
    circle(-.72, .93, .15);
    circle(-.5, .93, .18);
    circle(-.28, .93, .15);
    circle(0.0, .95, .17);
    circle(.2, .93, .15);
    circle(.43, .93, .2);
    circle(.65, .93, .13);
    circle(.8, .95, .15);
    circle(.95, .95, .08);
}

void snowball()     // s
{
    // circle(-1.5,.95,.01);
    circle(-.95, .75, .005);
    circle(-.65, 0.55, .005);
    circle(-.35, 0.46, .005);
    circle(-.05, 0.648, .005);
    circle(.25, .83, .005);
    circle(.55, 0.8, .005);
    circle(.75, 0.35, .005);
    circle(1., 0.26, .005);
    circle(-.45, 0.148, .005);
    circle(.2, .83, .005);
    circle(.45, 0.8, .005);
    circle(.65, 0.35, .005);
    circle(1., 0.2, .005);
    circle(-.4, 0.18, .005);
    circle(-.9, .75, .005);
    circle(-.65, 0.5, .005);
    circle(-.5, 0.6, .005);
    circle(-.05, 0.64, .005);
    circle(.25, .83, .005);
    circle(.52, 0.6, .005);
    circle(.75, 0.35, .005);
    circle(1., 0.6, .005);
    circle(-.5, 0.14, .005);
    circle(.2, .3, .005);
    circle(.45, 0.87, .005);
    circle(.6, 0.35, .005);
    circle(.88, 0.2, .005);
    circle(-.4, 0.18, .005);

    circle(-.75, .75, .005);
    circle(-.5, 0.5, .005);
    circle(-.3, 0.46, .005);
    circle(-.05, 0.648, .005);
    circle(.25, .83, .005);
    circle(.55, 0.8, .005);
    circle(.75, 0.5, .005);
    circle(1., 0.67, .005);
    circle(-.56, 0.148, .005);
    circle(.223, .83, .005);
    circle(.97, 0.332, .005);
    circle(.65, 0.87, .005);
    circle(.912, 0.2323, .005);
    circle(-.4, 0.4, .005);
    circle(-.9, .543, .005);
    circle(-.686, 0.5, .005);
    circle(-.5, 0.86, .005);
    circle(-.525, 0.6, .005);
    circle(.2434, .685, .005);
    circle(.756, 0.9786, .005);
    circle(.7, 0.68, .005);
    circle(.12, 0.23, .005);
    circle(-.131, 0.14, .005);
    circle(.2, .121, .005);
    circle(.4343, 0.23, .005);
    circle(.6, 0.687, .005);
    circle(.143, 0.6867, .005);
    circle(-.4, 0.876, .005);

    circle(-.94, 0.7, .005);
    circle(-.92, 0.687, .005);
    circle(-.91, 0.79, .005);
    circle(-.88, 0.56, .005);
}

void sea()      // Sea
{
    /**.......................................Sea ..........................................**/

    glBegin(GL_QUADS);
    glColor3f(0.49, 0.824, 0.871);
    glVertex2f(-1.0f, 0.66f);
    glColor3f(0.49, 0.824, 0.871);
    glVertex2f(-1.0f, 0.76f);
    glColor3f(0.49, 0.824, 0.871);
    glVertex2f(1.0f, 0.76f);
    glColor3f(0.49, 0.824, 0.871);
    glVertex2f(1.0f, 0.55f);
    glEnd();

    circle(0.1, 0.7, 0.1);

    /**.......................................Sea Wave ..........................................**/
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.5f, 0.68f);
    glVertex2f(-.5f, 0.689f);
    glVertex2f(-0.36f, 0.687f);
    glVertex2f(-0.34f, 0.686f);
    glVertex2f(-0.56f, 0.687f);
    glVertex2f(-0.54f, 0.686f);
    glEnd();

    glPushMatrix();
    glTranslated(0.9f, -0.07f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.5f, 0.68f);
    glVertex2f(-.5f, 0.689f);
    glVertex2f(-0.36f, 0.687f);
    glVertex2f(-0.34f, 0.686f);
    glVertex2f(-0.56f, 0.687f);
    glVertex2f(-0.54f, 0.686f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(1.4f, 0.05f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.5f, 0.68f);
    glVertex2f(-.5f, 0.689f);
    glVertex2f(-0.36f, 0.687f);
    glVertex2f(-0.34f, 0.686f);
    glVertex2f(-0.56f, 0.687f);
    glVertex2f(-0.54f, 0.686f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.6f, 0.06f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.5f, 0.68f);
    glVertex2f(-.5f, 0.689f);
    glVertex2f(-0.36f, 0.687f);
    glVertex2f(-0.34f, 0.686f);
    glVertex2f(-0.56f, 0.687f);
    glVertex2f(-0.54f, 0.686f);
    glEnd();
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.99f, 0.7f);
    glVertex2f(-0.85f, 0.71f);
    glVertex2f(-0.79f, 0.7f);
    glVertex2f(-0.87f, 0.71f);
    glVertex2f(-0.88f, 0.7f);
    glVertex2f(-0.93f, 0.7f);
    glVertex2f(-1.1f, 0.69f);
    glEnd();

    glPushMatrix();
    glTranslated(0.7f, -0.03f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.99f, 0.7f);
    glVertex2f(-0.85f, 0.71f);
    glVertex2f(-0.79f, 0.7f);
    glVertex2f(-0.87f, 0.71f);
    glVertex2f(-0.88f, 0.7f);
    glVertex2f(-0.93f, 0.7f);
    glVertex2f(-1.1f, 0.69f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(1.4f, 0.02f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.99f, 0.7f);
    glVertex2f(-0.85f, 0.71f);
    glVertex2f(-0.79f, 0.7f);
    glVertex2f(-0.87f, 0.71f);
    glVertex2f(-0.88f, 0.7f);
    glVertex2f(-0.93f, 0.7f);
    glVertex2f(-1.1f, 0.69f);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(1.6f, -0.08f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.99f, 0.7f);
    glVertex2f(-0.85f, 0.71f);
    glVertex2f(-0.79f, 0.7f);
    glVertex2f(-0.87f, 0.71f);
    glVertex2f(-0.88f, 0.7f);
    glVertex2f(-0.93f, 0.7f);
    glVertex2f(-1.1f, 0.69f);
    glEnd();
    glPopMatrix();
}

void beach()        // Beach
{
    /**....................................... Beach Sand  ..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.58, 0.404, 0.298);
    glVertex2f(-1.0f, 0.65f);
    glColor3f(0.882, 0.714, 0.522);
    glVertex2f(-1.0f, 0.66f);
    glColor3f(0.58, 0.404, 0.298);
    glVertex2f(1.0f, 0.55f);
    glColor3f(0.882, 0.714, 0.522);
    glVertex2f(1.0f, 0.48f);
    glEnd();
}

void sky()      // Sky1-sk1
{
    /**.......................................Sky ..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.576, 0.831, 0.949);
    glVertex2f(-1.0f, 0.76f);
    glColor3f(0.478, 0.78, 0.925);
    glVertex2f(-1.0f, 1.0f);
    glColor3f(0.478, 0.78, 0.925);
    glVertex2f(1.0f, 1.0f);
    glColor3f(0.576, 0.831, 0.949);
    glVertex2f(1.0f, 0.76f);
    glEnd();
}


 void sun ()      // Sun
{
    /**.......................................Sun...........................................**/

    GLfloat x = 0.7f;
    GLfloat y = 0.85f;
    GLfloat radius = 0.055f;
    int triangleAmount = 100; // # of lines used to draw circle
    GLfloat twicePi = 2.0f * PI;
    glColor3f(1.0f, 1.0f, 0.680f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {

        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));

        glColor3f(1.0f, 1.0f, 0.0f);
    }
    glEnd();
}

void sun1()     // Sun1
{
    /**.......................................Sun...........................................**/

    GLfloat x = 0.7f;
    GLfloat y = 0.85f;
    GLfloat radius = 0.055f;
    int triangleAmount = 100; // # of lines used to draw circle
    GLfloat twicePi = 2.0f * PI;

    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {

        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
        glColor3f(1.0f, 1.0f, 0.680f);
    }
    glEnd();
}

void sun_shadow()       //sunshadow
{
    glColor3f(1.0f, 1.0f, 0.680f);
    circle(0.7, 0.68, 0.055);
}

void cloud1()   //Cloud  1
{
    /**........................................Cloud Middle..........................................**/
    glPushMatrix();
    glTranslated(position_cloud1x, 0.0f, 0.0f);
    glPushMatrix();
    glTranslated(0.0f, 0.05f, 0.0f);
    GLfloat x = 0.0f;
    GLfloat y = 0.88f;
    GLfloat radius = .04f;
    int triangleAmount = 100;
    GLfloat twicePi = 2.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    x = 0.05f;
    y = 0.88f;
    radius = .04f;
    twicePi = 2.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle

    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = -0.05f;
    y = 0.88f;
    radius = .04f;
    twicePi = 2.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = -0.04f;
    y = 0.92f;
    radius = .03f;
    twicePi = 2.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle

    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = -0.013f;
    y = 0.85f;
    radius = .03f;
    twicePi = 2.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle

    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = 0.053f;
    y = 0.85f;
    radius = .036f;
    twicePi = 2.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle

    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void cloud2()       // Cloud 2 - 21
{

    /**........................................Cloud Left...........................................**/
    glPushMatrix();
    glTranslated(position_cloud2x, 0.0f, 0.0f);
    GLfloat x = -0.5f;
    GLfloat y = 0.85f;
    GLfloat radius = .058f;
    int triangleAmount = 100;
    GLfloat twicePi = 1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle

    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = -0.57f;
    y = 0.85f;
    radius = .037f;
    twicePi = 1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {

        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = -0.43f;
    y = 0.85f;
    radius = .04f;
    twicePi = 1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle

    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = -0.55f;
    y = 0.86f;
    radius = .03f;
    twicePi = 1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle

    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = -0.61f;
    y = 0.85f;
    radius = .02f;
    twicePi = 1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle

    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = -0.39f;
    y = 0.85f;
    radius = .02f;
    twicePi = 1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle

    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }

    glEnd();
    glPopMatrix();
}

void cloud3()   //Cloud 3
{
    /**........................................Cloud Right...........................................**/
    glPushMatrix();
    glTranslated(position_cloud3x, 0.0f, 0.0f);
    GLfloat x = 0.45f;
    GLfloat y = 0.85f;
    GLfloat radius = .035f;
    int triangleAmount = 100;
    GLfloat twicePi = 1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle

    for (float i = 0; i <= triangleAmount; i++)
    {

        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),

                   y + (radius * sin(i * twicePi / triangleAmount)));
    }

    glEnd();

    x = 0.48f;
    y = 0.85f;
    radius = .03f;
    twicePi = 1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle

    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = 0.42f;
    y = 0.85f;
    radius = .028f;
    twicePi = 1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    glPopMatrix();
}

void road()     // Road
{

    /**.......................................Road ..........................................**/
    /**....................................... Road color  ..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.301, 0.355, 0.35);
    glVertex2f(-1.0f, 0.65f);
    glColor3f(0.301, 0.33, 0.35);
    glVertex2f(1.0f, 0.48f);
    glColor3f(0.302, 0.32, 0.32);
    glVertex2f(1.0f, 0.3f);
    glColor3f(0.301, 0.355, 0.35);
    glVertex2f(-1.0f, 0.55f);
    glEnd();
    /**....................................... Side Divider  ..........................................**/
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-1.0f, 0.64f);
    glVertex2f(1.0f, 0.47f);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-1.0f, 0.56f);
    glVertex2f(1.0f, 0.31f);
    glEnd();

    /**....................................... Divider  ..........................................**/
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();
    /**....................................... Continuous Road divider  ..........................................**/
    glPushMatrix();

    glTranslated(0.175f, -0.019f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();

    glTranslated(0.175f, -0.019f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();

    glTranslated(0.175f, -0.019f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();

    glTranslated(0.175f, -0.019f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();

    glTranslated(0.175f, -0.015f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();

    glTranslated(0.175f, -0.015f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();

    glTranslated(0.175f, -0.015f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();

    glTranslated(0.175f, -0.018f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();

    glTranslated(0.175f, -0.018f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();

    glTranslated(0.175f, -0.018f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();

    glTranslated(0.175f, -0.018f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();

    glPopMatrix();
}

void car()  //
{
    /**....................................... Car  ..........................................**/
    glPushMatrix();
    glTranslated(position_car1x, position_car1y, 0.0f);

    glLineWidth(2);
    glTranslated(0.9f, 0.15f, 0.0f);
    glScalef(0.5f, 0.5f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.269, 0.541, 0.467);
    glVertex2f(0.9f, 0.35f);
    glVertex2f(0.650f, 0.38f);
    glVertex2f(0.650f, 0.44f);
    glVertex2f(0.7f, 0.440f);
    glVertex2f(0.725f, 0.475f);
    glVertex2f(0.850f, 0.461f);
    glVertex2f(0.880f, 0.416f);
    glVertex2f(0.9f, 0.41f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.753, 0.792, 0.82);
    glVertex2f(0.7f, 0.440f);
    glVertex2f(0.725f, 0.475f);
    glVertex2f(0.850f, 0.461f);
    glVertex2f(0.880f, 0.416f);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.7f, 0.440f);
    glVertex2f(0.880f, 0.416f);
    glVertex2f(0.787f, 0.474f);
    glVertex2f(0.782f, 0.36f);
    glEnd();

    /**....................................... Car Tire 1  ..........................................**/

    GLfloat x = 0.724f;
    GLfloat y = 0.38f;
    GLfloat radius = .02f;
    int triangleAmount = 100; // # of lines used to draw circle
    GLfloat twicePi = 2.0f * PI;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    x = 0.724f;
    y = 0.38f;
    radius = .008f;
    triangleAmount = 100; // # of lines used to draw circle
    twicePi = 2.0f * PI;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    /**....................................... Car Tire 2  ..........................................**/
    x = 0.825f;
    y = 0.37f;
    radius = .02f;
    triangleAmount = 100; // # of lines used to draw circle
    twicePi = 2.0f * PI;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    x = 0.825f;
    y = 0.37f;
    radius = .008f;
    triangleAmount = 100; // # of lines used to draw circle

    // GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    glPopMatrix();
}


void bus()     // Bus
{
    ///*-------------------------------------------Bus -------------------------------------------------*///

    glPushMatrix();
    glPushMatrix();
    glTranslated(position_busx, position_busy, 0.0f);
    glTranslated(-0.4f, -0.025f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.3f, 0.6f);
    glVertex2f(0.625f, 0.575f);
    glVertex2f(0.625f, 0.475f);
    glVertex2f(0.3f, 0.5f);

    glEnd();
     ///*-------------------------------------------Bus  upper side-------------------------------------------------*///
    ////
  /**  glBegin(GL_POLYGON);
      glColor3f(0.941, 0.859, 0.141);
    //glColor3f(0.196, 0.66, 0.64);
    glVertex2f(0.3f, 0.575f + 0.05f); // Shifted upward by 0.1f
    glVertex2f(0.6f, 0.575f + 0.05f); // Shifted upward by 0.1f
    glVertex2f(0.625f, 0.475f + 0.1f); // Shifted upward by 0.1f
    glVertex2f(0.3f, 0.5f + 0.1f); // Shifted upward by 0.1f
    glEnd();**/
    /////




    glBegin(GL_POLYGON);
    glColor3f(0.941, 0.859, 0.141);
    glVertex2f(0.3f, 0.6f);
    glVertex2f(0.625f, 0.575f);
    glVertex2f(0.625f, 0.50f);
    glVertex2f(0.3f, 0.575f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.941, 0.859, 0.141);
    glVertex2f(0.3f, 0.551f);
    glVertex2f(0.625f, 0.525f);
    glVertex2f(0.625f, 0.48f);
    glVertex2f(0.3f, 0.5f);
    glEnd();




    ///*-------------------------------------------Bus  inner lower box-------------------------------------------------*///
    ////
    glBegin(GL_POLYGON);
    glColor3f(0.941, 0.859, 0.141);
    glVertex2f(0.3f, 0.5f); // Shifted upward by 0.1f
    glVertex2f(0.4f, 0.49f); // Shifted upward by 0.1f
    glVertex2f(0.4f, 0.545f); // Shifted upward by 0.1f
    glVertex2f(0.3f, 0.55); // Shifted upward by 0.1f
    glEnd();
    glPushMatrix();
    glTranslated(0.1f, -0.01f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0.3f, 0.5f); // Shifted upward by 0.1f
    glVertex2f(0.4f, 0.49f); // Shifted upward by 0.1f
    glVertex2f(0.4f, 0.545f); // Shifted upward by 0.1f
    glVertex2f(0.3f, 0.555); // Shifted upward by 0.1f
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.2f, -0.02f, 0.0f);
    glBegin(GL_POLYGON);
     glColor3f(0.941, 0.859, 0.141);
    glVertex2f(0.3f, 0.5f); // Shifted upward by 0.1f
    glVertex2f(0.428f, 0.49f); // Shifted upward by 0.1f
    glVertex2f(0.428f, 0.545f); // Shifted upward by 0.1f
    glVertex2f(0.3f, 0.555); // Shifted upward by 0.1f
    glEnd();
    glPopMatrix();
    ///*-------------------------------------------Bus  middle box-------------------------------------------------*///
    ////
    glBegin(GL_POLYGON);
    glColor3f(0.929, 0.902, 0.902);
    glVertex2f(0.3f, 0.5455f); // Shifted upward by 0.1f
     glVertex2f(0.4f, 0.534f); // Shifted upward by 0.1f
    glVertex2f(0.4f, 0.5669f); // Shifted upward by 0.1f
    glVertex2f(0.3f, 0.575f); // Shifted upward by 0.1f
    glEnd();
    glPushMatrix();
    glTranslated(0.1f, -0.009f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.929, 0.902, 0.902);
    glVertex2f(0.3f, 0.5455f); // Shifted upward by 0.1f
     glVertex2f(0.4f, 0.534f); // Shifted upward by 0.1f
    glVertex2f(0.4f, 0.5669f); // Shifted upward by 0.1f
    glVertex2f(0.3f, 0.575f); // Shifted upward by 0.1f
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.2f, -0.018f, 0.0f);
    glBegin(GL_POLYGON);
     glColor3f(0.929, 0.902, 0.902);
    glVertex2f(0.3f, 0.5455f); // Shifted upward by 0.1f
     glVertex2f(0.428f, 0.534f); // Shifted upward by 0.1f
    glVertex2f(0.428f, 0.5669f); // Shifted upward by 0.1f
    glVertex2f(0.3f, 0.575f); // Shifted upward by 0.1f
    glEnd();
    glPopMatrix();

///light//
    glPushMatrix();
    glTranslated(0.33f, -0.0090f, 0.0f);
    glBegin(GL_POLYGON);
     glColor3f(0.478, 0.478, 0.451);
    glVertex2f(0.3f, 0.54f); // Shifted upward by 0.1f
     glVertex2f(0.315f, 0.54f); // Shifted upward by 0.1f
    glVertex2f(0.315f, 0.57f); // Shifted upward by 0.1f
    glVertex2f(0.3f, 0.57f); // Shifted upward by 0.1f
    glEnd();
    glPopMatrix();


    ////

    /**....................................... Bus  Tire 1  ..........................................**/
    GLfloat x = 0.350f;
    GLfloat y = 0.5f;
    GLfloat radius = .02f;
    int triangleAmount = 100; // # of lines used to draw circle
    GLfloat twicePi = 2.0f * PI;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    x = 0.350f;
    y = 0.5f;
    radius = .008f;
    triangleAmount = 100; // # of lines used to draw circle
    twicePi = 2.0f * PI;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    /**....................................... Bus Tire 2  ..........................................**/
    x = 0.575f;
    y = 0.475f;
    radius = .02f;
    triangleAmount = 100; // # of lines used to draw circle
    twicePi = 2.0f * PI;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    x = 0.575f;
    y = 0.475f;
    radius = .008f;
    triangleAmount = 100; // # of lines used to draw circle
    twicePi = 2.0f * PI;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    /**....................................... Bus  Windows  ..........................................**/
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.54f);
    glEnd();
    glPushMatrix();
    glTranslated(0.025f, -0.002f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.54f);
    glEnd();
    glTranslated(0.025f, -0.002f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.54f);
    glEnd();
    glTranslated(0.025f, -0.002f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.54f);
    glEnd();
    glTranslated(0.025f, -0.0021f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.54f);
    glEnd();
    glTranslated(0.025f, -0.0021f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.54f);
    glEnd();
    glTranslated(0.025f, -0.0021f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.54f);
    glEnd();
    glTranslated(0.025f, -0.0021f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.54f);
    glEnd();
    glTranslated(0.025f, -0.0021f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.54f);
    glEnd();
    glTranslated(0.025f, -0.0021f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.54f);
    glEnd();
    glTranslated(0.025f, -0.0021f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.54f);
    glEnd();
    glTranslated(0.025f, -0.0021f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.54f);
    glEnd();

    glPopMatrix();

    /**glBegin(GL_POLYGON);
    glColor3f(0.89, 0.886, 0.871);
    glVertex2f(0.4f, 0.567f);
    glVertex2f(0.425f, 0.566f);
    glVertex2f(0.425f, 0.4911f);
    glVertex2f(0.4f, 0.4911f);
    glEnd();
    **/


    /**....................................... Bus Door  ..........................................

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.4f, 0.567f);
    glVertex2f(0.425f, 0.4911f);
    glEnd();
    **/
    ///windowline//
    glPushMatrix();
    glTranslated(-0.001f, -0.06f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.3f, 0.605);
    glVertex2f(0.626f, 0.575f);
    glEnd();
    glPopMatrix();
    ///windowline//
    glPushMatrix();
    glTranslated(-0.001f, -0.02f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.3f, 0.599);
    glVertex2f(0.626f, 0.570f);
    glEnd();
    glPopMatrix();

    ///upper windowline//
    glPushMatrix();
    glTranslated(-0.001f, 0.02f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.3f, 0.605);
    glVertex2f(0.6f, 0.606f);
    glEnd();
    glPopMatrix();

    ///side line//
    glPushMatrix();
    glTranslated(-0.001f, 0.02f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.3f, 0.605);
    glVertex2f(0.3f, 0.58f);
    glEnd();
    glPopMatrix();

    ///side line//
    glPushMatrix();
    glTranslated(0.099f, 0.02f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.3f, 0.605);
    glVertex2f(0.3f, 0.57f);
    glEnd();
    glPopMatrix();

    ///side line//
    glPushMatrix();
    glTranslated(0.2f, 0.02f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.3f, 0.605);
    glVertex2f(0.3f, 0.56f);
    glEnd();
    glPopMatrix();

    ///side line//
    glPushMatrix();
    //glTranslated(-0.001f, 0.02f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    //glVertex2f(0.6f, 0.605);
    //glVertex2f(0.3f, 0.58f);

    glVertex2f(0.6f, 0.575f + 0.05f);
    glVertex2f(0.625f, 0.475f + 0.1f);
    glEnd();
    glPopMatrix();

///driver window
     glPushMatrix();
    glTranslated(0.275f, -0.018f, 0.0f);
    glBegin(GL_POLYGON);
     glColor3f(0.29, 0.282, 0.282);
    glVertex2f(0.3f, 0.538f); // Shifted upward by 0.1f
     glVertex2f(0.35f, 0.5345f); // Shifted upward by 0.1f
    glVertex2f(0.35f, 0.59f); // Shifted upward by 0.1f
    glVertex2f(0.3f, 0.595f); // Shifted upward by 0.1f
    glEnd();
    glPopMatrix();


    ///uper window lower line
    ///windowline//
    glPushMatrix();
    glTranslated(-0.001f, -0.005f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.3f, 0.605);
    glVertex2f(0.626f, 0.5755f);
    glEnd();
    glPopMatrix();

 ///seat
    glPushMatrix();
    glTranslated(0.02f, 0.02f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.3f, 0.59);
    glVertex2f(0.3f, 0.58f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.06f, 0.002f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.3f, 0.592);
    glVertex2f(0.3f, 0.603f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.15f, -0.004f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.3f, 0.592);
    glVertex2f(0.3f, 0.603f);
    glEnd();
    glPopMatrix();

     glPushMatrix();
    glTranslated(0.25f, -0.015f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.3f, 0.592);
    glVertex2f(0.3f, 0.603f);
    glEnd();
    glPopMatrix();

     glPushMatrix();
    glTranslated(0.3f, -0.02f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.3f, 0.592);
    glVertex2f(0.3f, 0.603f);
    glEnd();
    glPopMatrix();
    ////////////////////////////////
    /// Passenger of the bus....................
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.555f);
    glVertex2f(0.325f, 0.545f);
    glVertex2f(0.345f, 0.545f);
    glVertex2f(0.325f, 0.555f);
    glVertex2f(0.325f, 0.575f);
    glEnd();
    /// Passenger of the bus(Head)....................
    x = 0.331f;
    y = 0.557f;
    radius = .0068f;
    triangleAmount = 100; // # of lines used to draw circle
    twicePi = 2.0f * PI;

    glColor3f(0.902, 0.714, 0.475);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    ///
     ///...............................................
    glPushMatrix();
    glTranslated(0.025f, -0.005f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.467, 0.627, 0.667);
    glVertex2f(0.325f, 0.555f);
    glVertex2f(0.325f, 0.545f);
    glVertex2f(0.345f, 0.545f);
    glVertex2f(0.325f, 0.555f);
    glVertex2f(0.325f, 0.575f);
    glEnd();
    /// Passenger of the bus(Head)....................
    x = 0.331f;
    y = 0.557f;
    radius = .0068f;
    triangleAmount = 100; // # of lines used to draw circle
    twicePi = 2.0f * PI;

    glColor3f(0.902, 0.714, 0.475);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    ///.........................................

    glPushMatrix();
    glTranslated(0.025f, -0.002f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.835, 0.282, 0.337);
    glVertex2f(0.325f, 0.555f);
    glVertex2f(0.325f, 0.545f);
    glVertex2f(0.345f, 0.545f);
    glVertex2f(0.325f, 0.555f);
    glVertex2f(0.325f, 0.575f);
    glEnd();
    /// Passenger of the bus(Head)....................
    x = 0.331f;
    y = 0.557f;
    radius = .0068f;
    triangleAmount = 100; // # of lines used to draw circle
    twicePi = 2.0f * PI;

    glColor3f(0.902, 0.714, 0.475);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    ///............................

    glTranslated(0.025f, -0.002f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.522, 0.18, 0.145);
    glVertex2f(0.325f, 0.555f);
    glVertex2f(0.325f, 0.545f);
    glVertex2f(0.345f, 0.545f);
    glVertex2f(0.325f, 0.555f);
    glVertex2f(0.325f, 0.575f);
    glEnd();

    /// Passenger of the bus(Head)....................
    x = 0.331f;
    y = 0.557f;
    radius = .0068f;
    triangleAmount = 100; // # of lines used to draw circle
    twicePi = 2.0f * PI;

    glColor3f(0.902, 0.714, 0.475);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    ///.........................................

    glTranslated(0.025f, -0.002f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.816, 0.541, 0.694);
    glVertex2f(0.325f, 0.555f);
    glVertex2f(0.325f, 0.545f);
    glVertex2f(0.345f, 0.545f);
    glVertex2f(0.325f, 0.555f);
    glVertex2f(0.325f, 0.575f);
    glEnd();
    /// Passenger of the bus(Head)....................
    x = 0.331f;
    y = 0.557f;
    radius = .0068f;
    triangleAmount = 100; // # of lines used to draw circle
    twicePi = 2.0f * PI;

    glColor3f(0.902, 0.714, 0.475);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    ///.................................

    glTranslated(0.025f, -0.002f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.439, 0.435, 0.353);
    glVertex2f(0.325f, 0.555f);
    glVertex2f(0.325f, 0.545f);
    glVertex2f(0.345f, 0.545f);
    glVertex2f(0.325f, 0.555f);
    glVertex2f(0.325f, 0.575f);
    glEnd();
    /// Passenger of the bus(Head)....................
    x = 0.331f;
    y = 0.557f;
    radius = .0068f;
    triangleAmount = 100; // # of lines used to draw circle
    twicePi = 2.0f * PI;

    glColor3f(0.902, 0.714, 0.475);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    glTranslated(0.025f, -0.002f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.555f);
    glVertex2f(0.325f, 0.545f);
    glVertex2f(0.345f, 0.545f);
    glVertex2f(0.325f, 0.555f);
    glVertex2f(0.325f, 0.575f);
    glEnd();
    ///...................................
    /// Passenger of the bus(Head)....................
    x = 0.331f;
    y = 0.557f;
    radius = .0068f;
    triangleAmount = 100; // # of lines used to draw circle
    twicePi = 2.0f * PI;

    glColor3f(0.902, 0.714, 0.475);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    glTranslated(0.025f, -0.002f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(0.325f, 0.555f);
    glVertex2f(0.325f, 0.545f);
    glVertex2f(0.345f, 0.545f);
    glVertex2f(0.325f, 0.555f);
    glVertex2f(0.325f, 0.575f);
    glEnd();
    /// Passenger of the bus(Head)....................
    x = 0.331f;
    y = 0.557f;
    radius = .0068f;
    triangleAmount = 100; // # of lines used to draw circle
    twicePi = 2.0f * PI;

    glColor3f(0.902, 0.714, 0.475);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    ///........................
    glTranslated(0.025f, -0.002f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.1);
    glVertex2f(0.325f, 0.555f);
    glVertex2f(0.325f, 0.545f);
    glVertex2f(0.345f, 0.545f);
    glVertex2f(0.325f, 0.555f);
    glVertex2f(0.325f, 0.575f);
    glEnd();
    /// Passenger of the bus(Head)....................
    x = 0.331f;
    y = 0.557f;
    radius = .0068f;
    triangleAmount = 100; // # of lines used to draw circle
    twicePi = 2.0f * PI;

    glColor3f(0.902, 0.714, 0.475);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    ///..................................
    glTranslated(0.025f, -0.002f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 1.0);
    glVertex2f(0.325f, 0.555f);
    glVertex2f(0.325f, 0.545f);
    glVertex2f(0.345f, 0.545f);
    glVertex2f(0.325f, 0.555f);
    glVertex2f(0.325f, 0.575f);
    glEnd();
    /// Passenger of the bus(Head)....................
    x = 0.331f;
    y = 0.557f;
    radius = .0068f;
    triangleAmount = 100; // # of lines used to draw circle
    twicePi = 2.0f * PI;

    glColor3f(0.902, 0.714, 0.475);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    ///.....................
    glPopMatrix();
    glPopMatrix();
    ///...............................................
     /////upper seat people///
     ////////////////////////////////
    /// Passenger of the bus....................

    //  error

  /*  glPushMatrix();
    glTranslated(0.0f, 0.05f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.555f);
    glVertex2f(0.325f, 0.545f);
    glVertex2f(0.345f, 0.545f);
    glVertex2f(0.325f, 0.555f);
    glVertex2f(0.325f, 0.575f);
    glEnd();
    /// Passenger of the bus(Head)....................
    x = 0.331f;
    y = 0.557f;
    radius = .0068f;
    triangleAmount = 100; // # of lines used to draw circle
    twicePi = 2.0f * PI;

    glColor3f(0.361, 0.184, 0.051);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    glPopMatrix();
    ///
    /// Passenger of the bus....................
    glPushMatrix();
    glTranslated(0.038f, 0.05f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.555f);
    glVertex2f(0.325f, 0.545f);
    glVertex2f(0.345f, 0.545f);
    glVertex2f(0.325f, 0.555f);
    glVertex2f(0.325f, 0.575f);
    glEnd();
    /// Passenger of the bus(Head)....................
   x = 0.331f;
    y = 0.557f;
    radius = .0068f;
    triangleAmount = 100; // # of lines used to draw circle
    twicePi = 2.0f * PI;

    glColor3f(0.361, 0.184, 0.051);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    glPopMatrix();
    ///
    ///
    /// Passenger of the bus....................
    glPushMatrix();
    glTranslated(0.13f, 0.04f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.555f);
    glVertex2f(0.325f, 0.545f);
    glVertex2f(0.345f, 0.545f);
    glVertex2f(0.325f, 0.555f);
    glVertex2f(0.325f, 0.575f);
    glEnd();
    /// Passenger of the bus(Head)....................
    x = 0.331f;
    y = 0.557f;
    radius = .0068f;
    triangleAmount = 100; // # of lines used to draw circle
    twicePi = 2.0f * PI;

    glColor3f(0.361, 0.184, 0.051);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    glPopMatrix();
    ///
    ///
    /// Passenger of the bus....................
    glPushMatrix();
    glTranslated(0.23f, 0.03f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.555f);
    glVertex2f(0.325f, 0.545f);
    glVertex2f(0.345f, 0.545f);
    glVertex2f(0.325f, 0.555f);
    glVertex2f(0.325f, 0.575f);
    glEnd();
    /// Passenger of the bus(Head)....................
    x = 0.331f;
    y = 0.557f;
    radius = .0068f;
    triangleAmount = 100; // # of lines used to draw circle
    twicePi = 2.0f * PI;

    glColor3f(0.361, 0.184, 0.051);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    glPopMatrix();
    ///
     ///
    /// Passenger of the bus....................
    glPushMatrix();
    glTranslated(0.275f, 0.031f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.555f);
    glVertex2f(0.325f, 0.545f);
    glVertex2f(0.345f, 0.545f);
    glVertex2f(0.325f, 0.555f);
    glVertex2f(0.325f, 0.575f);
    glEnd();
    /// Passenger of the bus(Head)....................
    x = 0.331f;
    y = 0.557f;
    radius = .0068f;
    triangleAmount = 100; // # of lines used to draw circle
    twicePi = 2.0f * PI;

    glColor3f(0.361, 0.184, 0.051);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    glPopMatrix();*/
    ///



    glPopMatrix();

    glPopMatrix();

}
void hills()    // Hill
{
    /**....................................... Hills ..........................................**/

    /**....................................... Hill 1 ..........................................**/
    glBegin(GL_POLYGON);
    glColor3f(0.192, 0.459, 0.192);
    glVertex2f(-0.902f, 0.582f);
    glVertex2f(-0.846f, 0.621f);
    glVertex2f(-0.867f, 0.670f);
    glVertex2f(-0.789f, 0.711f);
    glVertex2f(-0.765f, 0.805f);
    glVertex2f(-0.686f, 0.724f);
    glVertex2f(-0.659f, 0.716f);
    glVertex2f(-0.635f, 0.659f);
    glVertex2f(-0.588f, 0.621f);
    glVertex2f(-0.576f, 0.542f);
    glVertex2f(-0.549f, 0.556f);
    glVertex2f(-0.498f, 0.482f);
    glVertex2f(-0.412f, 0.221f);
    glVertex2f(-0.917f, 0.221f);
    glEnd();

    /**....................................... Hill 1 Shadow  ..........................................**/
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.791f, 0.714f);
    glVertex2f(-0.763f, 0.742f);
    glVertex2f(-0.776f, 0.761f);
    glVertex2f(-0.744f, 0.756f);
    glVertex2f(-0.713f, 0.718f);
    glVertex2f(-0.746f, 0.722f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.744f, 0.756f);
    glVertex2f(-0.746f, 0.722f);
    glVertex2f(-0.736f, 0.663f);
    glVertex2f(-0.83f, 0.631f);
    glVertex2f(-0.78f, 0.666f);
    glVertex2f(-0.815f, 0.679f);
    glVertex2f(-0.815f, 0.679f);
    glVertex2f(-0.767f, 0.716f);
    glVertex2f(-0.791f, 0.714f);
    glEnd();

    glPushMatrix();
    glTranslated(0.15f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.967f, 0.514f);
    glVertex2f(-0.952f, 0.546f);
    glVertex2f(-0.949f, 0.588f);
    glVertex2f(-0.929f, 0.601f);
    glVertex2f(-0.922f, 0.558f);
    glVertex2f(-0.933f, 0.522f);
    glEnd();

    glTranslated(0.01f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.952f, 0.546f);
    glVertex2f(-0.971f, 0.553f);
    glVertex2f(-0.972f, 0.5694f);
    glVertex2f(-0.990f, 0.581f);
    glVertex2f(-0.979f, 0.642f);
    glVertex2f(-0.96f, 0.632f);
    glVertex2f(-0.949f, 0.588f);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslated(0.3f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.967f, 0.514f);
    glVertex2f(-0.952f, 0.546f);
    glVertex2f(-0.949f, 0.588f);
    glVertex2f(-0.929f, 0.601f);
    glVertex2f(-0.922f, 0.558f);
    glVertex2f(-0.933f, 0.522f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.952f, 0.546f);
    glVertex2f(-0.971f, 0.553f);
    glVertex2f(-0.972f, 0.5694f);
    glVertex2f(-0.990f, 0.581f);
    glVertex2f(-0.979f, 0.642f);
    glVertex2f(-0.96f, 0.632f);
    glVertex2f(-0.949f, 0.588f);
    glEnd();
    glPopMatrix();


    /**....................................... Hill 2  ..........................................**/
    glBegin(GL_POLYGON);
    glColor3f(0.161, 0.4, 0.169);
    glVertex2f(-1.0f, 0.22f);
    glVertex2f(-1.0f, 0.685f);
    glVertex2f(-0.94f, 0.633f);
    glVertex2f(-0.944f, 0.624f);
    glVertex2f(-0.928f, 0.624f);
    glVertex2f(-0.925f, 0.635f);
    glVertex2f(-0.895f, 0.571f);
    glVertex2f(-0.872f, 0.568f);
    glVertex2f(-0.854f, 0.555f);
    glVertex2f(-0.855f, 0.547f);
    glVertex2f(-0.804f, 0.491f);
    glVertex2f(-0.807f, 0.448f);
    glVertex2f(-0.786f, 0.458f);
    glVertex2f(-0.764f, 0.468f);
    glVertex2f(-0.758f, 0.443f);
    glVertex2f(-0.738f, 0.44f);
    glVertex2f(-0.719f, 0.379f);
    glVertex2f(-0.681f, 0.32f);
    glVertex2f(-0.641f, 0.286f);
    glVertex2f(-0.624f, 0.245f);
    glVertex2f(-0.583f, 0.22f);
    glEnd();

    /**....................................... Hill 2 Shadow  ..........................................**/
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.982f, 0.436f);
    glVertex2f(-0.979f, 0.470f);
    glVertex2f(-0.938f, 0.485f);
    glVertex2f(-0.928f, 0.5224f);
    // glVertex2f(-0.905f, 0.506f);
    glVertex2f(-0.941f, 0.471f);
    glVertex2f(-0.943f, 0.447f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.967f, 0.514f);
    glVertex2f(-0.952f, 0.546f);
    glVertex2f(-0.949f, 0.588f);
    glVertex2f(-0.929f, 0.601f);
    glVertex2f(-0.922f, 0.558f);
    glVertex2f(-0.933f, 0.522f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.952f, 0.546f);
    glVertex2f(-0.971f, 0.553f);
    glVertex2f(-0.972f, 0.5694f);
    glVertex2f(-0.990f, 0.581f);
    glVertex2f(-0.979f, 0.642f);
    glVertex2f(-0.96f, 0.632f);
    glVertex2f(-0.949f, 0.588f);

    glEnd();

    /**....................................... Hill 3  ..........................................**/

    glPushMatrix();

    glTranslated(0.25f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.02, 0.357, 0.02);

    glVertex2f(-1.0f, 0.22f);
    glVertex2f(-1.0f, 0.38f);
    glVertex2f(-0.903f, 0.468f);
    glVertex2f(-0.889f, 0.465f);
    glVertex2f(-0.835f, 0.555f);
    glVertex2f(-0.816f, 0.594f);
    glVertex2f(-0.759f, 0.547f);
    glVertex2f(-0.758f, 0.557f);
    glVertex2f(-0.724f, 0.521f);
    glVertex2f(-0.7f, 0.526f);
    glVertex2f(-0.697f, 0.503f);
    glVertex2f(-0.661f, 0.482f);
    glVertex2f(-0.66f, 0.475f);
    glVertex2f(-0.64f, 0.474f);
    glVertex2f(-0.559f, 0.354f);
    glVertex2f(-0.528f, 0.347f);
    glVertex2f(-0.462f, 0.218f);
    glEnd();
    glPopMatrix();

    /**....................................... Hill 3 Shadow  ..........................................**/

    glPushMatrix();
    glTranslated(0.1f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.692f, 0.326f);
    glVertex2f(-0.68f, 0.346f);
    glVertex2f(-0.696f, 0.362f);
    glVertex2f(-0.665f, 0.415f);
    glVertex2f(-0.68f, 0.448f);
    glVertex2f(-0.652f, 0.441f);
    glVertex2f(-0.629f, 0.432f);
    glVertex2f(-0.640f, 0.408f);
    glVertex2f(-0.665f, 0.376f);
    glVertex2f(-0.636f, 0.395f);
    glVertex2f(-0.617f, 0.339f);
    glVertex2f(-0.592f, 0.323f);
    glVertex2f(-0.597f, 0.274f);
    glVertex2f(-0.521f, 0.263f);
    glVertex2f(-0.544f, 0.227f);
    glEnd();

    glPopMatrix();
    glPushMatrix();
    glTranslated(0.2f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.98f, 0.26f);
    glVertex2f(-0.92f, 0.36f);
    glVertex2f(-0.76f, 0.48f);
    glVertex2f(-0.74f, 0.44f);
    glVertex2f(-0.76f, 0.44f);
    glVertex2f(-0.74f, 0.4f);
    glVertex2f(-0.76f, 0.36f);
    glVertex2f(-0.74f, 0.34f);
    glVertex2f(-0.88f, 0.3f);
    glVertex2f(-0.9f, 0.26f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.46f, -0.1f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.967f, 0.514f);
    glVertex2f(-0.952f, 0.546f);
    glVertex2f(-0.949f, 0.588f);
    glVertex2f(-0.929f, 0.601f);
    glVertex2f(-0.922f, 0.558f);
    glVertex2f(-0.933f, 0.522f);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.56f, -0.2f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.952f, 0.546f);
    glVertex2f(-0.971f, 0.553f);
    glVertex2f(-0.972f, 0.5694f);
    glVertex2f(-0.990f, 0.581f);
    glVertex2f(-0.979f, 0.642f);
    glVertex2f(-0.96f, 0.632f);
    glVertex2f(-0.949f, 0.588f);

    glEnd();
    glPopMatrix();

    /**....................................... Hill 4  ..........................................**/
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.412, 0.102);
    glVertex2f(-1.0f, 0.22f);
    glVertex2f(-1.0f, 0.38f);
    glVertex2f(-0.903f, 0.468f);
    glVertex2f(-0.889f, 0.465f);
    glVertex2f(-0.835f, 0.555f);
    glVertex2f(-0.816f, 0.594f);
    glVertex2f(-0.759f, 0.547f);
    glVertex2f(-0.758f, 0.557f);
    glVertex2f(-0.724f, 0.521f);
    glVertex2f(-0.7f, 0.526f);
    glVertex2f(-0.697f, 0.503f);
    glVertex2f(-0.661f, 0.482f);
    glVertex2f(-0.66f, 0.475f);
    glVertex2f(-0.64f, 0.474f);
    glVertex2f(-0.559f, 0.354f);
    glVertex2f(-0.528f, 0.347f);
    glVertex2f(-0.462f, 0.218f);
    glEnd();

    /**....................................... Hill 4 Shadow  ..........................................**/
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.98f, 0.26f);
    glVertex2f(-0.92f, 0.36f);
    glVertex2f(-0.76f, 0.48f);
    glVertex2f(-0.74f, 0.44f);
    glVertex2f(-0.76f, 0.44f);
    glVertex2f(-0.74f, 0.4f);
    glVertex2f(-0.76f, 0.36f);
    glVertex2f(-0.74f, 0.34f);
    glVertex2f(-0.88f, 0.3f);
    glVertex2f(-0.9f, 0.26f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.835f, 0.52f);
    glVertex2f(-0.822f, 0.527f);
    glVertex2f(-0.821f, 0.545f);
    glVertex2f(-0.815f, 0.544f);
    glVertex2f(-0.792f, 0.554f);
    glVertex2f(-0.786f, 0.533f);
    glVertex2f(-0.803f, 0.528f);
    glVertex2f(-0.818f, 0.511f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.692f, 0.326f);
    glVertex2f(-0.68f, 0.346f);
    glVertex2f(-0.696f, 0.362f);
    glVertex2f(-0.665f, 0.415f);
    glVertex2f(-0.68f, 0.448f);
    glVertex2f(-0.652f, 0.441f);
    glVertex2f(-0.629f, 0.432f);
    glVertex2f(-0.640f, 0.408f);
    glVertex2f(-0.665f, 0.376f);
    glVertex2f(-0.636f, 0.395f);
    glVertex2f(-0.617f, 0.339f);
    glVertex2f(-0.592f, 0.323f);
    glVertex2f(-0.597f, 0.274f);
    glVertex2f(-0.521f, 0.263f);
    glVertex2f(-0.544f, 0.227f);
    glEnd();
}

void rail_Line()    // RL
{
    /**....................................... Rail Line Stone ..........................................**/
    glBegin(GL_QUADS);
    ///    Upper
    glColor3f(0.537, 0.569, 0.592);
    glVertex2f(-1.0f, 0.03f);
    glColor3f(0.553, 0.584, 0.635);
    glVertex2f(-1.0f, 0.09f);
    glColor3f(0.235, 0.365, 0.459);
    glVertex2f(1.0f, 0.09f);
    glColor3f(0.486, 0.388, 0.267);
    glVertex2f(1.0f, 0.03f);
    ///     lower
    glColor3f(0.537, 0.569, 0.592);
    glVertex2f(-1.0f, 0.11f);
    glColor3f(0.553, 0.584, 0.635);
    glVertex2f(-1.0f, 0.17f);
    glColor3f(0.235, 0.365, 0.459);
    glVertex2f(1.0f, 0.17f);
    glColor3f(0.486, 0.388, 0.267);
    glVertex2f(1.0f, 0.11f);
    glEnd();

    /**....................................... Rail Line Soil ..........................................**/
    glBegin(GL_QUADS);
    ///      Middle
    glColor3f(0.663, 0.447, 0.29);
    glVertex2f(-1.0f, 0.09f);
    glColor3f(0.322, 0.22, 0.188);
    glVertex2f(-1.0f, 0.11f);
    glColor3f(0.855, 0.686, 0.4940);
    glVertex2f(1.0f, 0.11f);
    glColor3f(0.678, 0.467, 0.294);
    glVertex2f(1.0f, 0.09f);
    ///    Lower
    glColor3f(0.855, 0.686, 0.4940);
    glVertex2f(-1.0f, 0.0f);
    glColor3f(0.678, 0.467, 0.294);
    glVertex2f(-1.0f, 0.03f);
    glColor3f(0.322, 0.22, 0.188);
    glVertex2f(1.0f, 0.03f);
    glColor3f(0.663, 0.447, 0.29);
    glVertex2f(1.0f, 0.00f);
    ///    Upper
    glColor3f(0.678, 0.467, 0.294);
    glVertex2f(-1.0f, 0.17f);
    glColor3f(0.855, 0.686, 0.4940);
    glVertex2f(-1.0f, 0.22f);
    glColor3f(0.322, 0.22, 0.188);
    glVertex2f(1.0f, 0.22f);
    glColor3f(0.663, 0.447, 0.29);
    glVertex2f(1.0f, 0.17f);

    glEnd();

    /**....................................... Rail Line ..........................................**/
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    ///     Lower Line
    glVertex2f(-1.0f, 0.04f);
    glVertex2f(1.0f, 0.04f);
    glVertex2f(-1.0f, 0.08f);
    glVertex2f(1.0f, 0.08f);
    ///     Upper Line
    glVertex2f(-1.0f, 0.12f);
    glVertex2f(1.0f, 0.12f);
    glVertex2f(-1.0f, 0.16f);
    glVertex2f(1.0f, 0.16f);
    glEnd();

    /**....................................... Lower Line Joiner ..........................................**/
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-1.01f, 0.04f);
    glVertex2f(-0.98f, 0.08f);

    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);

    glEnd();
    glPushMatrix();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);

    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();

    glPopMatrix();

    /**....................................... Upper Line Joiner ..........................................**/
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-1.01f, 0.12f);
    glVertex2f(-0.98f, 0.16f);

    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);

    glEnd();
    glPushMatrix();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);

    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();

    glPopMatrix();
}

void tree1() /// small tree // Tree 1 - 7001
{
    /**....................................... Small Tree (right) ..........................................**/

    /**....................................... Small Tree (right) Stem ..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.314, 0.184, 0.149);
    glVertex2f(0.54f, 0.20f);
    glVertex2f(0.54f, 0.25f);
    glVertex2f(0.56f, 0.25f);
    glVertex2f(0.56f, 0.20f);
    glEnd();
    /**....................................... Small Tree (right) Leaf ..........................................**/
    glBegin(GL_TRIANGLES);
    glColor3f(0, 0.235, 0.039);
    glVertex2f(0.47f, 0.25f);
    glVertex2f(0.63f, 0.25f);
    glVertex2f(0.55f, 0.34f);

    glColor3f(0.008, 0.357, 0.063);
    glVertex2f(0.48f, 0.30f);
    glVertex2f(0.62f, 0.30f);
    glVertex2f(0.55f, 0.38f);

    glColor3f(0.024, 0.451, 0.086);
    glVertex2f(0.50f, 0.35f);
    glVertex2f(0.6f, 0.35f);
    glVertex2f(0.55f, 0.42f);
    glEnd();
    /**....................................... Small Tree (Left) ..........................................**/
    glPushMatrix();
    glTranslated(-1.1f, 0.0f, 0.0f);
    /**....................................... Small Tree (Left) Stem ..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.314, 0.184, 0.149);
    glVertex2f(0.54f, 0.20f);
    glVertex2f(0.54f, 0.25f);
    glVertex2f(0.56f, 0.25f);
    glVertex2f(0.56f, 0.20f);
    glEnd();
    /**....................................... Small Tree (Left) Leaf ..........................................**/
    glBegin(GL_TRIANGLES);
    glColor3f(0, 0.235, 0.039);
    glVertex2f(0.47f, 0.25f);
    glVertex2f(0.63f, 0.25f);
    glVertex2f(0.55f, 0.34f);

    glColor3f(0.008, 0.357, 0.063);
    glVertex2f(0.48f, 0.30f);
    glVertex2f(0.62f, 0.30f);
    glVertex2f(0.55f, 0.38f);

    glColor3f(0.024, 0.451, 0.086);
    glVertex2f(0.50f, 0.35f);
    glVertex2f(0.6f, 0.35f);
    glVertex2f(0.55f, 0.42f);
    glEnd();
    glPopMatrix();
}

void tree2()        // Tree 2
{
    /**....................................... Big Tree (Right) ..........................................**/

    /**....................................... Big Tree (Right) Stem ..........................................**/

    glBegin(GL_QUADS);
    glColor3f(0.314, 0.184, 0.149);
    glVertex2f(0.73f, 0.19f);
    glVertex2f(0.744f, 0.472f);
    glVertex2f(0.754f, 0.472f);
    glVertex2f(0.764f, 0.19f);

    glVertex2f(0.738f, 0.255f);
    glVertex2f(0.736f, 0.274f);
    glVertex2f(0.684f, 0.303f);
    glVertex2f(0.680f, 0.298f);

    glVertex2f(0.759f, 0.303f);
    glVertex2f(0.759f, 0.319f);
    glVertex2f(0.815f, 0.350f);
    glVertex2f(0.824f, 0.347f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.314, 0.184, 0.149);
    glVertex2f(0.744f, 0.408f);
    glVertex2f(0.687f, 0.460f);
    glVertex2f(0.744f, 0.424f);

    glVertex2f(0.755f, 0.421f);
    glVertex2f(0.815f, 0.493f);
    glVertex2f(0.755f, 0.439f);
    glEnd();

    /**....................................... Big Tree (Left) ..........................................**/

    /**....................................... Big Tree (Left) Stem ..........................................**/

    glPushMatrix();
    glTranslated(-1.7f, -0.02f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.314, 0.184, 0.149);
    glVertex2f(0.73f, 0.19f);
    glVertex2f(0.744f, 0.472f);
    glVertex2f(0.754f, 0.472f);
    glVertex2f(0.764f, 0.19f);

    glVertex2f(0.738f, 0.255f);
    glVertex2f(0.736f, 0.274f);
    glVertex2f(0.684f, 0.303f);
    glVertex2f(0.680f, 0.298f);

    glVertex2f(0.759f, 0.303f);
    glVertex2f(0.759f, 0.319f);
    glVertex2f(0.815f, 0.350f);
    glVertex2f(0.824f, 0.347f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.314, 0.184, 0.149);
    glVertex2f(0.744f, 0.408f);
    glVertex2f(0.687f, 0.460f);
    glVertex2f(0.744f, 0.424f);

    glVertex2f(0.755f, 0.421f);
    glVertex2f(0.815f, 0.493f);
    glVertex2f(0.755f, 0.439f);
    glEnd();
    glPopMatrix();
}

void tree_leaf1()   // TL001
{
    /**....................................... Big Tree (Right) Top Leaf ..........................................**/

    glColor3f(0.549, 0.639, 0.153);
    circle(0.644, 0.532, 0.06);

    glColor3f(0.549, 0.639, 0.153);
    circle(0.644, 0.477, 0.05);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.691, 0.568, 0.07);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.771, 0.563, 0.06);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.814, 0.562, 0.045);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.835, 0.543, 0.05);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.839, 0.508, 0.05);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.749, 0.457, 0.06);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.796, 0.485, 0.05);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.709, 0.442, 0.05);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.695, 0.457, 0.055);

    /**....................................... Big Tree (Right) Right Leaf ..........................................**/

    glColor3f(0.549, 0.639, 0.153);
    circle(0.865, 0.376, 0.035);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.896, 0.390, 0.025);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.835, 0.406, 0.03);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.802, 0.384, 0.03);

    glColor3f(0.549, 0.639, 0.153);
    circle(0.836, 0.366, 0.035);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.881, 0.408, 0.03);

    /**....................................... Big Tree (Right) Left Leaf ..........................................**/

    glPushMatrix();
    glTranslated(-0.18f, -0.055f, 0.0f);

    glColor3f(0.549, 0.639, 0.153);
    circle(0.865, 0.376, 0.035);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.896, 0.390, 0.025);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.835, 0.406, 0.03);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.802, 0.384, 0.03);

    glColor3f(0.549, 0.639, 0.153);
    circle(0.836, 0.366, 0.035);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.881, 0.408, 0.03);
    glPopMatrix();
}

void tree_leaf2()       // TL002
{
    /**....................................... Big Tree (Left) Top Leaf ..........................................**/
    glPushMatrix();
    glTranslated(-1.7f, -0.02f, 0.0f);

    glColor3f(0.549, 0.639, 0.153);
    circle(0.644, 0.532, 0.06);

    glColor3f(0.549, 0.639, 0.153);
    circle(0.644, 0.477, 0.05);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.691, 0.568, 0.07);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.771, 0.563, 0.06);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.814, 0.562, 0.045);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.835, 0.543, 0.05);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.839, 0.508, 0.05);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.749, 0.457, 0.06);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.796, 0.485, 0.05);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.709, 0.442, 0.05);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.695, 0.457, 0.055);

    /**....................................... Big Tree (Left) Right Leaf ..........................................**/

    glColor3f(0.549, 0.639, 0.153);
    circle(0.865, 0.376, 0.035);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.896, 0.390, 0.025);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.835, 0.406, 0.03);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.802, 0.384, 0.03);

    glColor3f(0.549, 0.639, 0.153);
    circle(0.836, 0.366, 0.035);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.881, 0.408, 0.03);

    /**....................................... Big Tree (Left) Left Leaf ..........................................**/

    glPushMatrix();
    glTranslated(-0.18f, -0.055f, 0.0f);

    glColor3f(0.549, 0.639, 0.153);
    circle(0.865, 0.376, 0.035);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.896, 0.390, 0.025);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.835, 0.406, 0.03);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.802, 0.384, 0.03);

    glColor3f(0.549, 0.639, 0.153);
    circle(0.836, 0.366, 0.035);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.881, 0.408, 0.03);

    glPopMatrix();

    glPopMatrix();
}

void train1()   // Train1
{
    /**....................................... Train ..........................................**/
    /**....................................... Train 1 ..........................................**/
    glPushMatrix();
    glTranslatef(position_train1x, 0.0f, 0.0f);
    /// Wheel of the train(Right Side);
    GLfloat x = 0.12f;
    GLfloat y = 0.14f;
    GLfloat radius = .022f;
    int triangleAmount = 100; /// # of lines used to draw circle
    GLfloat twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    /// Wheel of the train(Left Side);
    x = -0.01f;
    y = 0.14f;
    radius = .022f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    /**....................................... Train 1 Cabin ..........................................**/
    glBegin(GL_POLYGON);
    glColor3f(0.227f, 0.4f, 0.259f);
    glVertex2f(-0.05f, 0.14f);
    glVertex2f(-0.05f, 0.25f);
    glVertex2f(-0.02f, 0.28f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glVertex2f(0.16f, 0.14f);
    glEnd();
    /// Cabin(Front);
    glBegin(GL_QUADS);
    glColor3f(0.114f, 0.251f, 0.141f);
    glVertex2f(0.16f, 0.14f);
    glVertex2f(0.16f, 0.25f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glEnd();
    /// Left Window(Cabin);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.02f, 0.18f);
    glVertex2f(-0.02f, 0.22f);
    glVertex2f(0.02f, 0.22f);
    glVertex2f(0.02f, 0.18f);
    glEnd();

    /// Left Window(Passenger_Body);
    glBegin(GL_QUADS);
    glColor3f(0.471f, 0.227f, 0.58f);
    glVertex2f(-0.02f, 0.18f);
    glVertex2f(-0.02f, 0.19f);
    glVertex2f(-0.01f, 0.19f);
    glVertex2f(0.0f, 0.18f);
    glEnd();

    /// Left Window(Passenger_Head);
    x = -0.01f;
    y = 0.20f;
    radius = .01f;
    triangleAmount = 100; /// # of lines used to draw circle

    twicePi = 2.0f * PI;

    glColor3f(0.902f, 0.714f, 0.475f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// Right Window(Cabin);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.08f, 0.18f);
    glVertex2f(0.08f, 0.22f);
    glVertex2f(0.12f, 0.22f);
    glVertex2f(0.12f, 0.18f);
    glEnd();

    /// Right Window(Passenger_Body)
    glBegin(GL_POLYGON);
    glColor3f(0.471f, 0.227f, 0.58f);
    glVertex2f(0.10f, 0.18f);
    glVertex2f(0.12f, 0.18f);
    glVertex2f(0.12f, 0.19f);
    glVertex2f(0.11f, 0.19f);
    glVertex2f(0.10f, 0.18f);
    glEnd();

    /// Right Window(Passenger_Passenger_Head)
    x = 0.11f;
    y = 0.20f;
    radius = .01f;
    triangleAmount = 100; /// # of lines used to draw circle

    twicePi = 2.0f * PI;

    glColor3f(0.902f, 0.714f, 0.475f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glPushMatrix();
    glTranslated(-0.24f, 0.0f, 0.0f);
    x = 0.12f;
    y = 0.14f;
    radius = .022f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    /// Wheel of the train(Left Side);
    x = -0.01f;
    y = 0.14f;
    radius = .022f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.227f, 0.4f, 0.259f);
    glVertex2f(-0.05f, 0.14f);
    glVertex2f(-0.05f, 0.25f);
    glVertex2f(-0.02f, 0.28f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glVertex2f(0.16f, 0.14f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.114f, 0.251f, 0.141f);
    glVertex2f(0.16f, 0.14f);
    glVertex2f(0.16f, 0.25f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glEnd();
    /// Left Window(Cabin);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.02f, 0.18f);
    glVertex2f(-0.02f, 0.22f);
    glVertex2f(0.02f, 0.22f);
    glVertex2f(0.02f, 0.18f);
    glEnd();

    /// Left Window(Passenger_Body);
    glBegin(GL_QUADS);
    glColor3f(0.471f, 0.227f, 0.58f);
    glVertex2f(-0.02f, 0.18f);
    glVertex2f(-0.02f, 0.19f);
    glVertex2f(-0.01f, 0.19f);
    glVertex2f(0.0f, 0.18f);
    glEnd();

    /// Left Window(Passenger_Head);
    x = -0.01f;
    y = 0.20f;
    radius = .01f;
    triangleAmount = 100; /// # of lines used to draw circle

    twicePi = 2.0f * PI;

    glColor3f(0.902f, 0.714f, 0.475f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// Right Window(Cabin);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.08f, 0.18f);
    glVertex2f(0.08f, 0.22f);
    glVertex2f(0.12f, 0.22f);
    glVertex2f(0.12f, 0.18f);
    glEnd();

    /// Right Window(Passenger_Body)
    glBegin(GL_POLYGON);
    glColor3f(0.471f, 0.227f, 0.58f);
    glVertex2f(0.10f, 0.18f);
    glVertex2f(0.12f, 0.18f);
    glVertex2f(0.12f, 0.19f);
    glVertex2f(0.11f, 0.19f);
    glVertex2f(0.10f, 0.18f);
    glEnd();

    /// Right Window(Passenger_Passenger_Head)
    x = 0.11f;
    y = 0.20f;
    radius = .01f;
    triangleAmount = 100; /// # of lines used to draw circle

    twicePi = 2.0f * PI;

    glColor3f(0.902f, 0.714f, 0.475f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glTranslated(-0.24f, 0.0f, 0.0f);
    x = 0.12f;
    y = 0.14f;
    radius = .022f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    /// Wheel of the train(Left Side);
    x = -0.01f;
    y = 0.14f;
    radius = .022f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.227f, 0.4f, 0.259f);
    glVertex2f(-0.05f, 0.14f);
    glVertex2f(-0.05f, 0.25f);
    glVertex2f(-0.02f, 0.28f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glVertex2f(0.16f, 0.14f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.114f, 0.251f, 0.141f);
    glVertex2f(0.16f, 0.14f);
    glVertex2f(0.16f, 0.25f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glEnd();
    /// Left Window(Cabin);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.02f, 0.18f);
    glVertex2f(-0.02f, 0.22f);
    glVertex2f(0.02f, 0.22f);
    glVertex2f(0.02f, 0.18f);
    glEnd();

    /// Left Window(Passenger_Body);
    glBegin(GL_QUADS);
    glColor3f(0.471f, 0.227f, 0.58f);
    glVertex2f(-0.02f, 0.18f);
    glVertex2f(-0.02f, 0.19f);
    glVertex2f(-0.01f, 0.19f);
    glVertex2f(0.0f, 0.18f);
    glEnd();

    /// Left Window(Passenger_Head);
    x = -0.01f;
    y = 0.20f;
    radius = .01f;
    triangleAmount = 100; /// # of lines used to draw circle

    twicePi = 2.0f * PI;

    glColor3f(0.902f, 0.714f, 0.475f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// Right Window(Cabin);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.08f, 0.18f);
    glVertex2f(0.08f, 0.22f);
    glVertex2f(0.12f, 0.22f);
    glVertex2f(0.12f, 0.18f);
    glEnd();

    /// Right Window(Passenger_Body)
    glBegin(GL_POLYGON);
    glColor3f(0.471f, 0.227f, 0.58f);
    glVertex2f(0.10f, 0.18f);
    glVertex2f(0.12f, 0.18f);
    glVertex2f(0.12f, 0.19f);
    glVertex2f(0.11f, 0.19f);
    glVertex2f(0.10f, 0.18f);
    glEnd();

    /// Right Window(Passenger_Passenger_Head)
    x = 0.11f;
    y = 0.20f;
    radius = .01f;
    triangleAmount = 100; /// # of lines used to draw circle

    twicePi = 2.0f * PI;

    glColor3f(0.902f, 0.714f, 0.475f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glPopMatrix();
    /**....................................... Train 1 Engine ..........................................**/

    /// First wheel of left side;
    x = 0.22f;
    y = 0.14f;
    radius = .022f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// Seocond wheel of Left side;
    x = 0.27f;
    y = 0.14f;
    radius = .022f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// First wheel of Right side;
    x = 0.45f;
    y = 0.14f;
    radius = .022f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    /// Second wheel of Right side;
    x = 0.415f;
    y = 0.14f;
    radius = .022f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.839f, 0.467f, 0.114f);
    glVertex2f(0.19f, 0.14f);
    glVertex2f(0.19f, 0.25f);
    glVertex2f(0.22f, 0.28f);
    glVertex2f(0.27f, 0.28f);
    glVertex2f(0.27f, 0.27f);
    glVertex2f(0.50f, 0.27f);
    glVertex2f(0.50f, 0.17f);
    glVertex2f(0.48f, 0.15f);
    glVertex2f(0.25f, 0.15f);
    glVertex2f(0.24f, 0.14f);
    glVertex2f(0.17f, 0.14f);
    glEnd();

    /// Back of the engine(Front);
    glBegin(GL_QUADS);
    glColor3f(0.839f, 0.294f, 0.114f);
    glVertex2f(0.24f, 0.14f);
    glVertex2f(0.24f, 0.25f);
    glVertex2f(0.25f, 0.25f);
    glVertex2f(0.25f, 0.15f);
    glEnd();

    /// Back of the engine(Front_Upper);
    glBegin(GL_QUADS);
    glColor3f(0.839f, 0.294f, 0.114f);
    glVertex2f(0.24f, 0.25f);
    glVertex2f(0.27f, 0.28f);
    glVertex2f(0.27f, 0.27f);
    glVertex2f(0.25f, 0.25f);
    glEnd();

    /// Front of the engine(Front);
    glBegin(GL_POLYGON);
    glColor3f(0.839f, 0.294f, 0.114f);
    glVertex2f(0.48f, 0.15f);
    glVertex2f(0.48f, 0.25f);
    glVertex2f(0.50f, 0.27f);
    glVertex2f(0.50f, 0.17f);
    glEnd();

    /// Front of the engine(Back_Step);
    glBegin(GL_QUADS);
    glColor3f(0.82f, 0.816f, 0.451f);
    glVertex2f(0.19f, 0.20f);
    glVertex2f(0.19f, 0.23f);
    glVertex2f(0.24f, 0.23f);
    glVertex2f(0.24f, 0.20f);
    glEnd();

    /// Front of the engine(Stape);
    glBegin(GL_QUADS);
    glColor3f(0.722f, 0.714f, 0.322f);
    glVertex2f(0.24f, 0.20f);
    glVertex2f(0.24f, 0.23f);
    glVertex2f(0.25f, 0.24f);
    glVertex2f(0.25f, 0.21f);
    glEnd();

    /// Front of the engine(Stape);
    glBegin(GL_QUADS);
    glColor3f(0.82f, 0.816f, 0.451f);
    glVertex2f(0.25f, 0.21f);
    glVertex2f(0.25f, 0.24f);
    glVertex2f(0.48f, 0.24f);
    glVertex2f(0.48f, 0.21f);
    glEnd();

    /// Front of the engine(Stape_Front);
    glBegin(GL_QUADS);
    glColor3f(0.722f, 0.714f, 0.322f);
    glVertex2f(0.48f, 0.21f);
    glVertex2f(0.48f, 0.24f);
    glVertex2f(0.50f, 0.25f);
    glVertex2f(0.50f, 0.23f);
    glEnd();

    /// Front of the engine(Side Black Side);
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.24f, 0.14f);
    glVertex2f(0.25f, 0.15f);
    glVertex2f(0.48f, 0.15f);
    glVertex2f(0.47f, 0.14f);
    glEnd();

    /// Front of the engine(Side Black Side(Upper));
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.38f, 0.19f);
    glVertex2f(0.38f, 0.24f);
    glVertex2f(0.46f, 0.24f);
    glVertex2f(0.46f, 0.19f);
    glEnd();

    /// Back of the Engine(Window)......................................................
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.195f, 0.18f);
    glVertex2f(0.195f, 0.22f);
    glVertex2f(0.235f, 0.22f);
    glVertex2f(0.235f, 0.18f);
    glEnd();

    /// 1st Engine Driver(Window)......................................................
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.195f, 0.18f);
    glVertex2f(0.195f, 0.19f);
    glVertex2f(0.205f, 0.19f);
    glVertex2f(0.215f, 0.18f);
    glVertex2f(0.195f, 0.18f);
    glEnd();

    /// 1st Engine(Driver_Head);
    x = 0.205f;
    y = 0.20f;
    radius = .01f;
    triangleAmount = 100; /// # of lines used to draw circle

    twicePi = 2.0f * PI;

    glColor3f(0.902f, 0.714f, 0.475f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// Front of the engine(Side Black Side(White line));
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.38f, 0.19f);
    glVertex2f(0.38f, 0.24f);
    glEnd();

    glPushMatrix();
    glTranslated(0.01f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.38f, 0.19f);
    glVertex2f(0.38f, 0.24f);
    glEnd();

    glTranslated(0.01f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.38f, 0.19f);
    glVertex2f(0.38f, 0.24f);
    glEnd();

    glTranslated(0.01f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.38f, 0.19f);
    glVertex2f(0.38f, 0.24f);
    glEnd();

    glTranslated(0.01f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.38f, 0.19f);
    glVertex2f(0.38f, 0.24f);
    glEnd();

    glTranslated(0.01f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.38f, 0.19f);
    glVertex2f(0.38f, 0.24f);
    glEnd();

    glTranslated(0.01f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.38f, 0.19f);
    glVertex2f(0.38f, 0.24f);
    glEnd();

    glTranslated(0.01f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.38f, 0.19f);
    glVertex2f(0.38f, 0.24f);
    glEnd();

    glTranslated(0.01f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.38f, 0.19f);
    glVertex2f(0.38f, 0.24f);
    glEnd();

    glPopMatrix();
    glPopMatrix();
    /// End Of the train-1..................................................................
}

void train2()   // Train2
{
    /**....................................... Train 2 ..........................................**/
    glPushMatrix();
    glTranslatef(position_train2x, 0.0f, 0.0f);
    glPushMatrix();
    glTranslated(0.1f, -0.08f, 0.0f);
    GLfloat x = 0.12f;
    GLfloat y = 0.14f;
    GLfloat radius = .022f;
    int triangleAmount = 100; /// # of lines used to draw circle
    GLfloat twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    /// Wheel of the train(Left Side);

    x = -0.01f;
    y = 0.14f;
    radius = .022f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.118f, 0.227f, 0.333f);
    glVertex2f(-0.05f, 0.14f);
    glVertex2f(-0.05f, 0.25f);
    glVertex2f(-0.02f, 0.28f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glVertex2f(0.16f, 0.14f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.02f, 0.102f, 0.18f);
    glVertex2f(0.16f, 0.14f);
    glVertex2f(0.16f, 0.25f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glEnd();

    /// Left Window(Cabin);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.02f, 0.18f);
    glVertex2f(-0.02f, 0.22f);
    glVertex2f(0.02f, 0.22f);
    glVertex2f(0.02f, 0.18f);
    glEnd();

    /// Left Window(Passenger_Body);
    glBegin(GL_QUADS);
    glColor3f(0.471f, 0.227f, 0.58f);
    glVertex2f(-0.02f, 0.18f);
    glVertex2f(-0.02f, 0.19f);
    glVertex2f(-0.01f, 0.19f);
    glVertex2f(0.0f, 0.18f);
    glEnd();

    /// Left Window(Passenger_Head);
    x = -0.01f;
    y = 0.20f;
    radius = .01f;
    triangleAmount = 100; /// # of lines used to draw circle

    twicePi = 2.0f * PI;

    glColor3f(0.902f, 0.714f, 0.475f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// Right Window(Cabin);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.08f, 0.18f);
    glVertex2f(0.08f, 0.22f);
    glVertex2f(0.12f, 0.22f);
    glVertex2f(0.12f, 0.18f);
    glEnd();

    /// Right Window(Passenger_Body)
    glBegin(GL_POLYGON);
    glColor3f(0.471f, 0.227f, 0.58f);
    glVertex2f(0.10f, 0.18f);
    glVertex2f(0.12f, 0.18f);
    glVertex2f(0.12f, 0.19f);
    glVertex2f(0.11f, 0.19f);
    glVertex2f(0.10f, 0.18f);
    glEnd();

    /// Right Window(Passenger_Passenger_Head)
    x = 0.11f;
    y = 0.20f;
    radius = .01f;
    triangleAmount = 100; /// # of lines used to draw circle

    twicePi = 2.0f * PI;

    glColor3f(0.902f, 0.714f, 0.475f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glTranslated(-0.24f, 0.00f, 0.0f);
    x = 0.12f;
    y = 0.14f;
    radius = .022f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// Wheel of the train(Left Side);
    x = -0.01f;
    y = 0.14f;
    radius = .022f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.118f, 0.227f, 0.333f);
    glVertex2f(-0.05f, 0.14f);
    glVertex2f(-0.05f, 0.25f);
    glVertex2f(-0.02f, 0.28f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glVertex2f(0.16f, 0.14f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.02f, 0.102f, 0.18f);
    glVertex2f(0.16f, 0.14f);
    glVertex2f(0.16f, 0.25f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glEnd();

    /// Left Window(Cabin);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.02f, 0.18f);
    glVertex2f(-0.02f, 0.22f);
    glVertex2f(0.02f, 0.22f);
    glVertex2f(0.02f, 0.18f);
    glEnd();

    /// Left Window(Passenger_Body);
    glBegin(GL_QUADS);
    glColor3f(0.471f, 0.227f, 0.58f);
    glVertex2f(-0.02f, 0.18f);
    glVertex2f(-0.02f, 0.19f);
    glVertex2f(-0.01f, 0.19f);
    glVertex2f(0.0f, 0.18f);
    glEnd();

    /// Left Window(Passenger_Head);
    x = -0.01f;
    y = 0.20f;
    radius = .01f;
    triangleAmount = 100; /// # of lines used to draw circle

    twicePi = 2.0f * PI;

    glColor3f(0.902f, 0.714f, 0.475f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// Right Window(Cabin);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.08f, 0.18f);
    glVertex2f(0.08f, 0.22f);
    glVertex2f(0.12f, 0.22f);
    glVertex2f(0.12f, 0.18f);
    glEnd();

    /// Right Window(Passenger_Body)
    glBegin(GL_POLYGON);
    glColor3f(0.471f, 0.227f, 0.58f);
    glVertex2f(0.10f, 0.18f);
    glVertex2f(0.12f, 0.18f);
    glVertex2f(0.12f, 0.19f);
    glVertex2f(0.11f, 0.19f);
    glVertex2f(0.10f, 0.18f);
    glEnd();

    /// Right Window(Passenger_Passenger_Head)
    x = 0.11f;
    y = 0.20f;
    radius = .01f;
    triangleAmount = 100; /// # of lines used to draw circle

    twicePi = 2.0f * PI;

    glColor3f(0.902f, 0.714f, 0.475f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glTranslated(-0.24f, 0.00f, 0.0f);
    x = 0.12f;
    y = 0.14f;
    radius = .022f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// Wheel of the train(Left Side);
    x = -0.01f;
    y = 0.14f;
    radius = .022f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.118f, 0.227f, 0.333f);
    glVertex2f(-0.05f, 0.14f);
    glVertex2f(-0.05f, 0.25f);
    glVertex2f(-0.02f, 0.28f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glVertex2f(0.16f, 0.14f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.02f, 0.102f, 0.18f);
    glVertex2f(0.16f, 0.14f);
    glVertex2f(0.16f, 0.25f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glEnd();

    /// Left Window(Cabin);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.02f, 0.18f);
    glVertex2f(-0.02f, 0.22f);
    glVertex2f(0.02f, 0.22f);
    glVertex2f(0.02f, 0.18f);
    glEnd();

    /// Left Window(Passenger_Body);
    glBegin(GL_QUADS);
    glColor3f(0.471f, 0.227f, 0.58f);
    glVertex2f(-0.02f, 0.18f);
    glVertex2f(-0.02f, 0.19f);
    glVertex2f(-0.01f, 0.19f);
    glVertex2f(0.0f, 0.18f);
    glEnd();

    /// Left Window(Passenger_Head);
    x = -0.01f;
    y = 0.20f;
    radius = .01f;
    triangleAmount = 100; /// # of lines used to draw circle

    twicePi = 2.0f * PI;

    glColor3f(0.902f, 0.714f, 0.475f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// Right Window(Cabin);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.08f, 0.18f);
    glVertex2f(0.08f, 0.22f);
    glVertex2f(0.12f, 0.22f);
    glVertex2f(0.12f, 0.18f);
    glEnd();
    glPopMatrix();

    /**....................................... Train 2 Engine ..........................................**/

    /// Wheel of the 2nd engine(1st right side)
    x = -0.49f;
    y = 0.06f;
    radius = .022f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// Wheel of the 2nd engine(2nd right side)
    x = -0.53f;
    y = 0.06f;
    radius = .022f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// Wheel of the 2nd engine(1st left side)
    x = -0.66f;
    y = 0.06f;
    radius = .022f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// Wheel of the 2nd engine(1st left side)
    x = -0.70f;
    y = 0.06f;
    radius = .022f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// Polygon of second engine.............................................
    glBegin(GL_POLYGON);
    glColor3f(0.671f, 0.369f, 0.259f);
    glVertex2f(-0.46f, 0.06f);
    glVertex2f(-0.46f, 0.17f);
    glVertex2f(-0.43f, 0.20f);
    glVertex2f(-0.50f, 0.20f);
    glVertex2f(-0.51f, 0.19f);
    glVertex2f(-0.70f, 0.19f);
    glVertex2f(-0.73f, 0.16f);
    glVertex2f(-0.73f, 0.07f);
    glVertex2f(-0.54f, 0.07f);
    glVertex2f(-0.53f, 0.06f);
    glVertex2f(-0.46f, 0.06f);
    glEnd();

    /// Back Of The Engine.......................................................
    glBegin(GL_QUADS);
    glColor3f(0.663f, 0.235f, 0.141f);
    glVertex2f(-0.46f, 0.06f);
    glVertex2f(-0.46f, 0.17f);
    glVertex2f(-0.43f, 0.20f);
    glVertex2f(-0.43f, 0.10f);
    glEnd();

    /// Upper Rooftoof of the Engine...............................................
    glBegin(GL_QUADS);
    glColor3f(0.663f, 0.235f, 0.141f);
    glVertex2f(-0.73f, 0.16f);
    glVertex2f(-0.70f, 0.19f);
    glVertex2f(-0.51f, 0.19f);
    glVertex2f(-0.54f, 0.16f);
    glEnd();

    /// 2nd Train left side design...........................................
    glBegin(GL_QUADS);
    glColor3f(0.663f, 0.235f, 0.141f);
    glVertex2f(-0.55f, 0.07f);
    glVertex2f(-0.55f, 0.16f);
    glVertex2f(-0.53f, 0.17f);
    glVertex2f(-0.53f, 0.06f);
    glEnd();

    /// 2nd Train engine front of the black...........................................
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.72f, 0.06f);
    glVertex2f(-0.73f, 0.07f);
    glVertex2f(-0.54f, 0.07f);
    glVertex2f(-0.53f, 0.06f);
    glEnd();

    /// Front engine yellow design........................................................
    glBegin(GL_QUADS);
    glColor3f(0.769f, 0.702f, 0.576f);
    glVertex2f(-0.73f, 0.12f);
    glVertex2f(-0.73f, 0.15f);
    glVertex2f(-0.55f, 0.15f);
    glVertex2f(-0.55f, 0.12f);
    glEnd();

    /// Front engine yellow design(Back side)........................................................
    glBegin(GL_QUADS);
    glColor3f(0.741f, 0.62f, 0.51f);
    glVertex2f(-0.55f, 0.12f);
    glVertex2f(-0.55f, 0.15f);
    glVertex2f(-0.53f, 0.14f);
    glVertex2f(-0.53f, 0.11f);
    glEnd();

    /// Back engine yellow design(Back Left side)................................
    glBegin(GL_QUADS);
    glColor3f(0.769f, 0.702f, 0.576f);
    glVertex2f(-0.53f, 0.11f);
    glVertex2f(-0.53f, 0.14f);
    glVertex2f(-0.46f, 0.14f);
    glVertex2f(-0.46f, 0.11f);
    glEnd();

    /// Back of the engine yellow design(Back side)........................................................
    glBegin(GL_QUADS);
    glColor3f(0.741f, 0.62f, 0.51f);
    glVertex2f(-0.46f, 0.11f);
    glVertex2f(-0.46f, 0.14f);
    glVertex2f(-0.43f, 0.16f);
    glVertex2f(-0.43f, 0.13f);
    glEnd();

    /// Back of the Engine(Window)......................................................
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.52f, 0.10f);
    glVertex2f(-0.52f, 0.14f);
    glVertex2f(-0.48f, 0.14f);
    glVertex2f(-0.48f, 0.10f);
    glEnd();

    /// 2nd Engine Driver
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.50f, 0.10f);
    glVertex2f(-0.49f, 0.11f);
    glVertex2f(-0.48f, 0.11f);
    glVertex2f(-0.48f, 0.10f);
    glVertex2f(-0.50f, 0.10f);
    glEnd();

    /// 2ndEngine Window(Passenger_Head);
    x = -0.49f;
    y = 0.12f;
    radius = .01f;
    triangleAmount = 100; /// # of lines used to draw circle

    twicePi = 2.0f * PI;

    glColor3f(0.902f, 0.714f, 0.475f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// Front of the engine side black design........................................................
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glVertex2f(-0.64f, 0.15f);
    glVertex2f(-0.64f, 0.10f);
    glEnd();

    /// Front of the engine side black design(Outside Line)........................................................
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void grass()        // Grass
{
    /**....................................... Grass ..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.271, 0.463, 0.043);
    glVertex2f(-1.0f, 0.22f);
    glColor3f(0.643, 0.753, 0.227);
    glVertex2f(-1.0f, 0.55f);
    glColor3f(0.643, 0.753, 0.227);
    glVertex2f(1.0f, 0.3f);
    glColor3f(0.271, 0.463, 0.043);
    glVertex2f(1.0f, 0.22f);
    glEnd();
}

void kashPhulStructure()        // kashphul
{
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    /// KashPhul Stems
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.925f, 0.0f);
    glVertex2f(0.950f, 0.125f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.775f, 0.0f);
    glVertex2f(0.850f, 0.175f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.85f, 0.0f);
    glVertex2f(0.750f, 0.175f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.65f, 0.0f);
    glVertex2f(0.625f, 0.150f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.725f, 0.0f);
    glVertex2f(0.675f, 0.125f);
    glEnd();

    /// KashPhuls
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.950f, 0.125f);
    glVertex2f(0.975f, 0.150f);
    glVertex2f(0.975f, 0.250f);
    glVertex2f(0.925f, 0.175f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.85f, 0.175f);
    glVertex2f(0.9f, 0.250f);
    glVertex2f(0.9f, 0.3f);
    glVertex2f(0.85f, 0.25f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.75f, 0.175f);
    glVertex2f(0.750f, 0.2f);
    glVertex2f(0.7f, 0.250f);
    glVertex2f(0.725f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.625f, 0.15f);
    glVertex2f(0.625f, 0.150f);
    glVertex2f(0.625f, 0.250f);
    glVertex2f(0.6f, 0.175f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.675f, 0.125f);
    glVertex2f(0.675f, 0.150f);
    glVertex2f(0.65f, 0.175f);
    glVertex2f(0.65f, 0.150f);
    glEnd();

    /// Green Bushes
    GLfloat x = 0.9f;
    GLfloat y = 0.0f;
    GLfloat radius = .1f;
    int triangleAmount = 100; /// # of lines used to draw circle
    GLfloat twicePi = 2.0f * PI;
    glColor3f(0.373, 0.69, 0.349);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = 0.7f;
    y = 0.0f;
    radius = .15f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.161, 0.541, 0.137);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// Kashphul In front of the bush
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.675f, 0.125f);
    glVertex2f(0.675f, 0.150f);
    glVertex2f(0.65f, 0.175f);
    glVertex2f(0.65f, 0.150f);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.725f, 0.0f);
    glVertex2f(0.675f, 0.125f);
    glEnd();

    x = 0.6f;
    y = 0.0f;
    radius = .07f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.373, 0.69, 0.349);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = 0.7f;
    y = 0.003f;
    radius = .05f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.373, 0.6, 0.349);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    /// Leaves
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.722, 0.082);
    glVertex2f(0.9f, 0.0f);
    glVertex2f(0.925f, 0.0f);
    glVertex2f(0.85f, 0.125f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.722, 0.082);
    glVertex2f(0.925f, 0.0f);
    glVertex2f(0.95f, 0.0f);
    glVertex2f(1.0f, 0.125f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.722, 0.082);
    glVertex2f(0.775f, 0.0f);
    glVertex2f(0.8f, 0.0f);
    glVertex2f(0.7f, 0.150f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.722, 0.082);
    glVertex2f(0.8f, 0.0f);
    glVertex2f(0.825f, 0.0f);
    glVertex2f(0.825f, 0.1f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.722, 0.082);
    glVertex2f(0.7f, 0.0f);
    glVertex2f(0.650f, 0.075f);
    glVertex2f(0.725f, 0.0f);
    glVertex2f(0.75f, 0.125f);
    glVertex2f(0.750f, 0.0f);
    glEnd();
    /// Bush In front of the KashPhul
    x = 0.8f;
    y = 0.001f;
    radius = .05f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.373, 0.62, 0.349);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.722, 0.082);
    glVertex2f(0.650f, 0.0f);
    glVertex2f(0.675f, 0.0f);
    glVertex2f(0.55f, 0.125f);
    glEnd();
    glPopMatrix();
}

void kashPhul() // Kashphul
{
    glPushMatrix();
    glScalef(0.4f, 0.4f, 0.0f);
    glTranslatef(0.5f, -0.002f, 0.0f);
    kashPhulStructure();
    glTranslatef(0.5f, -0.002f, 0.0f);
    kashPhulStructure();
    glTranslatef(0.5f, -0.002f, 0.0f);
    kashPhulStructure();
    glTranslatef(0.5f, -0.002f, 0.0f);
    kashPhulStructure();
    glTranslatef(-0.4f, -0.002f, 0.0f);
    kashPhulStructure();
    glTranslatef(-0.4f, -0.002f, 0.0f);
    kashPhulStructure();
    glTranslatef(-0.4f, -0.002f, 0.0f);
    kashPhulStructure();
    glTranslatef(-0.4f, -0.002f, 0.0f);
    kashPhulStructure();
    glTranslatef(-0.4f, -0.002f, 0.0f);
    kashPhulStructure();
    glTranslatef(-0.4f, -0.002f, 0.0f);
    kashPhulStructure();
    glTranslatef(-0.3f, -0.002f, 0.0f);
    kashPhulStructure();
    glTranslatef(-0.4f, -0.002f, 0.0f);
    kashPhulStructure();
    glTranslatef(-0.3f, -0.002f, 0.0f);
    kashPhulStructure();
    glTranslatef(-0.4f, -0.002f, 0.0f);
    kashPhulStructure();
    glTranslatef(-0.3f, -0.002f, 0.0f);
    kashPhulStructure();
    glTranslatef(-0.3f, -0.002f, 0.0f);
    kashPhulStructure();
    glTranslatef(-0.4f, -0.002f, 0.0f);
    kashPhulStructure();
    glTranslatef(-0.4f, -0.002f, 0.0f);
    kashPhulStructure();
    glPopMatrix();
}

void rain()
{

    glPointSize(1000.0);

    glPushMatrix();
    glTranslated(0.0f, position_rainY, 0.0f);

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.2f, 0.22f);
    glVertex2f(-0.21f, 0.2f);
    glVertex2f(-0.1f, 0.12f);
    glVertex2f(-0.11f, 0.1f);
    glVertex2f(-0.4f, 0.42f);
    glVertex2f(-0.41f, 0.4f);
    glVertex2f(-0.35f, 0.36f);
    glVertex2f(-0.355f, 0.35f);
    glVertex2f(-0.31f, 0.36f);
    glVertex2f(-0.315f, 0.35f);
    glVertex2f(-0.29f, 0.36f);
    glVertex2f(-0.299f, 0.35f);
    glVertex2f(-0.31f, 0.36f);
    glVertex2f(-0.315f, 0.35f);
    glVertex2f(-0.41f, 0.36f);
    glVertex2f(-0.415f, 0.35f);
    glVertex2f(-0.42f, 0.36f);
    glVertex2f(-0.433f, 0.35f);
    glVertex2f(-0.439f, 0.36f);
    glVertex2f(-0.448f, 0.35f);
    glVertex2f(-0.55f, 0.36f);
    glVertex2f(-0.555f, 0.35f);
    glVertex2f(-0.65f, 0.36f);
    glVertex2f(-0.655f, 0.35f);
    glVertex2f(-0.75f, 0.36f);
    glVertex2f(-0.755f, 0.35f);
    glVertex2f(-0.55f, 0.38f);
    glVertex2f(-0.555f, 0.37f);
    glVertex2f(-0.65f, 0.38f);
    glVertex2f(-0.655f, 0.37f);
    glVertex2f(-0.75f, 0.38f);
    glVertex2f(-0.755f, 0.37f);
    glVertex2f(-0.55f, 0.39f);
    glVertex2f(-0.555f, 0.38f);
    glVertex2f(-0.57f, 0.39f);
    glVertex2f(-0.576f, 0.38f);
    glVertex2f(-0.8f, 0.22f);
    glVertex2f(-0.81f, 0.2f);
    glVertex2f(-0.8f, 0.52f);
    glVertex2f(-0.81f, 0.5f);
    glVertex2f(-0.8f, 0.54f);
    glVertex2f(-0.81f, 0.52f);
    glVertex2f(-0.82f, 0.56f);
    glVertex2f(-0.83f, 0.557f);
    glVertex2f(-0.84f, 0.58f);
    glVertex2f(-0.85f, 0.56f);
    glVertex2f(-0.89f, 0.58f);
    glVertex2f(-0.90f, 0.56f);
    glVertex2f(-0.92f, 0.58f);
    glVertex2f(-0.93f, 0.56f);
    glVertex2f(-0.92f, 0.38f);
    glVertex2f(-0.93f, 0.36f);
    glVertex2f(-0.92f, 0.38f);
    glVertex2f(-0.93f, 0.36f);
    glVertex2f(-0.45f, 0.88f);
    glVertex2f(-0.455f, 0.87f);
    glVertex2f(-0.55f, 0.82f);
    glVertex2f(-0.555f, 0.81f);
    glVertex2f(-0.45f, 0.62f);
    glVertex2f(-0.455f, 0.61f);
    glVertex2f(-0.55f, 0.65f);
    glVertex2f(-0.555f, 0.64f);
    glVertex2f(-0.45f, 0.63f);
    glVertex2f(-0.455f, 0.62f);
    glVertex2f(-0.62f, 0.66f);
    glVertex2f(-0.63f, 0.65f);
    glVertex2f(-0.62f, 0.56f);
    glVertex2f(-0.63f, 0.55f);
    glVertex2f(-0.64f, 0.51f);
    glVertex2f(-0.65f, 0.50f);
    glVertex2f(-0.67f, 0.48f);
    glVertex2f(-0.68f, 0.47f);
    glVertex2f(-0.62f, 0.54f);
    glVertex2f(-0.628f, 0.53f);
    glVertex2f(-0.54f, 0.51f);
    glVertex2f(-0.55f, 0.50f);
    glVertex2f(-0.57f, 0.48f);
    glVertex2f(-0.58f, 0.47f);
    glVertex2f(-0.52f, 0.54f);
    glVertex2f(-0.528f, 0.53f);
    glVertex2f(-0.56f, 0.51f);
    glVertex2f(-0.57f, 0.50f);
    glVertex2f(-0.58f, 0.48f);
    glVertex2f(-0.59f, 0.47f);
    glVertex2f(-0.53f, 0.54f);
    glVertex2f(-0.538f, 0.53f);
    glVertex2f(-0.77f, 0.51f);
    glVertex2f(-0.78f, 0.50f);
    glVertex2f(-0.42f, 0.51f);
    glVertex2f(-0.43f, 0.50f);
    glVertex2f(-0.45f, 0.51f);
    glVertex2f(-0.46f, 0.50f);
    glVertex2f(-0.45f, 0.48f);
    glVertex2f(-0.46f, 0.47f);
    glVertex2f(-0.51f, 0.48f);
    glVertex2f(-0.52f, 0.47f);
    glVertex2f(-0.51f, 0.51f);
    glVertex2f(-0.52f, 0.50f);
    glVertex2f(-0.47f, 0.51f);
    glVertex2f(-0.48f, 0.50f);
    glVertex2f(-0.47f, 0.54f);
    glVertex2f(-0.48f, 0.53f);
    glVertex2f(-0.47f, 0.54f);
    glVertex2f(-0.48f, 0.53f);
    glVertex2f(-0.65f, 0.88f);
    glVertex2f(-0.655f, 0.87f);
    glVertex2f(-0.75f, 0.88f);
    glVertex2f(-0.755f, 0.87f);
    glVertex2f(-0.85f, 0.88f);
    glVertex2f(-0.855f, 0.87f);
    glVertex2f(-0.95f, 0.88f);
    glVertex2f(-0.955f, 0.87f);
    glVertex2f(-0.84f, 0.88f);
    glVertex2f(-0.844f, 0.87f);
    glVertex2f(-0.92f, 0.88f);
    glVertex2f(-0.922f, 0.87f);
    glVertex2f(-0.84f, 0.85f);
    glVertex2f(-0.844f, 0.84f);
    glVertex2f(-0.92f, 0.91f);
    glVertex2f(-0.922f, 0.90f);
    glVertex2f(-0.95f, 0.45f);
    glVertex2f(-0.955f, 0.44f);
    glVertex2f(-0.95f, 0.55f);
    glVertex2f(-0.955f, 0.54f);
    glVertex2f(-0.95f, 0.65f);
    glVertex2f(-0.955f, 0.64f);
    glVertex2f(-0.95f, 0.75f);
    glVertex2f(-0.955f, 0.74f);
    glVertex2f(-0.92f, 0.75f);
    glVertex2f(-0.93f, 0.74f);
    glVertex2f(-0.87f, 0.75f);
    glVertex2f(-0.877f, 0.74f);
    glVertex2f(-0.44f, 0.75f);
    glVertex2f(-0.45f, 0.74f);
    glVertex2f(-0.52f, 0.75f);
    glVertex2f(-0.533f, 0.74f);
    glVertex2f(-0.48f, 0.75f);
    glVertex2f(-0.488f, 0.74f);
    glVertex2f(-0.58f, 0.75f);
    glVertex2f(-0.588f, 0.74f);
    glVertex2f(-0.62f, 0.75f);
    glVertex2f(-0.626f, 0.74f);
    glVertex2f(-0.72f, 0.75f);
    glVertex2f(-0.726f, 0.74f);
    glVertex2f(-0.72f, 0.72f);
    glVertex2f(-0.726f, 0.71f);
    glVertex2f(-0.72f, 0.67f);
    glVertex2f(-0.726f, 0.66f);
    glVertex2f(-0.72f, 0.61f);
    glVertex2f(-0.726f, 0.60f);
    glVertex2f(-0.72f, 0.68f);
    glVertex2f(-0.726f, 0.67f);
    glVertex2f(-0.74f, 0.68f);
    glVertex2f(-0.746f, 0.67f);
    glVertex2f(-0.77f, 0.68f);
    glVertex2f(-0.776f, 0.67f);
    glVertex2f(-0.77f, 0.66f);
    glVertex2f(-0.776f, 0.65f);
    glVertex2f(-0.73f, 0.69f);
    glVertex2f(-0.736f, 0.68f);
    glVertex2f(-0.75f, 0.70f);
    glVertex2f(-0.757f, 0.69f);
    glVertex2f(-0.81f, 0.68f);
    glVertex2f(-0.82f, 0.67f);
    glVertex2f(-0.83f, 0.68f);
    glVertex2f(-0.835f, 0.67f);
    glVertex2f(-0.85f, 0.68f);
    glVertex2f(-0.856f, 0.67f);
    glVertex2f(-0.87f, 0.68f);
    glVertex2f(-0.876f, 0.67f);
    glVertex2f(-0.89f, 0.68f);
    glVertex2f(-0.897f, 0.67f);
    glVertex2f(-0.83f, 0.63f);
    glVertex2f(-0.835f, 0.62f);
    glVertex2f(-0.85f, 0.63f);
    glVertex2f(-0.856f, 0.62f);
    glVertex2f(-0.87f, 0.63f);
    glVertex2f(-0.876f, 0.62f);
    glVertex2f(-0.89f, 0.63f);
    glVertex2f(-0.897f, 0.62f);
    glVertex2f(-0.79f, 0.63f);
    glVertex2f(-0.795f, 0.62f);
    glVertex2f(-0.74f, 0.63f);
    glVertex2f(-0.746f, 0.62f);
    glVertex2f(-0.71f, 0.63f);
    glVertex2f(-0.726f, 0.62f);
    glVertex2f(-0.70f, 0.63f);
    glVertex2f(-0.705f, 0.62f);
    glVertex2f(-0.7f, 0.56f);
    glVertex2f(-0.71f, 0.54f);
    glVertex2f(-0.73f, 0.56f);
    glVertex2f(-0.74f, 0.54f);
    glVertex2f(-0.79f, 0.56f);
    glVertex2f(-0.795f, 0.55f);
    glVertex2f(-0.76f, 0.56f);
    glVertex2f(-0.766f, 0.55f);
    glVertex2f(-0.72f, 0.56f);
    glVertex2f(-0.726f, 0.55f);
    glVertex2f(-0.76f, 0.59f);
    glVertex2f(-0.766f, 0.58f);
    glVertex2f(-0.79f, 0.59f);
    glVertex2f(-0.795f, 0.58f);
    glVertex2f(-0.66f, 0.59f);
    glVertex2f(-0.666f, 0.58f);
    glVertex2f(-0.64f, 0.59f);
    glVertex2f(-0.646f, 0.58f);
    glVertex2f(-0.54f, 0.59f);
    glVertex2f(-0.546f, 0.58f);
    glVertex2f(-0.51f, 0.59f);
    glVertex2f(-0.516f, 0.58f);
    glVertex2f(-0.57f, 0.59f);
    glVertex2f(-0.576f, 0.58f);
    glVertex2f(-0.51f, 0.62f);
    glVertex2f(-0.516f, 0.61f);
    glVertex2f(-0.51f, 0.65f);
    glVertex2f(-0.516f, 0.64f);
    glVertex2f(-0.51f, 0.70f);
    glVertex2f(-0.516f, 0.69f);
    glVertex2f(-0.53f, 0.70f);
    glVertex2f(-0.536f, 0.69f);
    glVertex2f(-0.55f, 0.70f);
    glVertex2f(-0.556f, 0.69f);
    glVertex2f(-0.57f, 0.70f);
    glVertex2f(-0.576f, 0.69f);
    glVertex2f(-0.59f, 0.70f);
    glVertex2f(-0.6f, 0.69f);
    glVertex2f(-0.62f, 0.70f);
    glVertex2f(-0.626f, 0.69f);
    glVertex2f(-0.64f, 0.70f);
    glVertex2f(-0.646f, 0.69f);
    glVertex2f(-0.66f, 0.70f);
    glVertex2f(-0.666f, 0.69f);
    glVertex2f(-0.68f, 0.70f);
    glVertex2f(-0.689f, 0.69f);
    glVertex2f(-0.41f, 0.70f);
    glVertex2f(-0.416f, 0.69f);
    glVertex2f(-0.43f, 0.70f);
    glVertex2f(-0.436f, 0.69f);
    glVertex2f(-0.45f, 0.67f);
    glVertex2f(-0.456f, 0.66f);
    glVertex2f(-0.47f, 0.70f);
    glVertex2f(-0.476f, 0.69f);
    glVertex2f(-0.49f, 0.70f);
    glVertex2f(-0.5f, 0.69f);
    glVertex2f(-0.11f, 0.70f);
    glVertex2f(-0.116f, 0.69f);
    glVertex2f(-0.13f, 0.70f);
    glVertex2f(-0.136f, 0.69f);
    glVertex2f(-0.15f, 0.68f);
    glVertex2f(-0.156f, 0.67f);
    glVertex2f(-0.17f, 0.70f);
    glVertex2f(-0.176f, 0.69f);
    glVertex2f(-0.19f, 0.70f);
    glVertex2f(-0.2f, 0.69f);
    glVertex2f(-0.23f, 0.70f);
    glVertex2f(-0.236f, 0.69f);
    glVertex2f(-0.25f, 0.70f);
    glVertex2f(-0.256f, 0.69f);
    glVertex2f(-0.27f, 0.70f);
    glVertex2f(-0.276f, 0.69f);
    glVertex2f(-0.29f, 0.70f);
    glVertex2f(-0.3f, 0.69f);
    glVertex2f(-0.35f, 0.70f);
    glVertex2f(-0.356f, 0.69f);
    glVertex2f(-0.37f, 0.70f);
    glVertex2f(-0.376f, 0.69f);
    glVertex2f(-0.39f, 0.70f);
    glVertex2f(-0.4f, 0.69f); ///
    glVertex2f(-0.11f, 0.67f);
    glVertex2f(-0.116f, 0.66f);
    glVertex2f(-0.15f, 0.67f);
    glVertex2f(-0.156f, 0.66f);
    glVertex2f(-0.18f, 0.67f);
    glVertex2f(-0.186f, 0.66f);
    glVertex2f(-0.21f, 0.67f);
    glVertex2f(-0.216f, 0.66f);
    glVertex2f(-0.25f, 0.67f);
    glVertex2f(-0.256f, 0.66f);
    glVertex2f(-0.28f, 0.67f);
    glVertex2f(-0.286f, 0.66f);
    glVertex2f(-0.31f, 0.67f);
    glVertex2f(-0.316f, 0.66f);
    glVertex2f(-0.35f, 0.67f);
    glVertex2f(-0.356f, 0.66f);
    glVertex2f(-0.38f, 0.67f);
    glVertex2f(-0.386f, 0.66f);
    glVertex2f(-0.41f, 0.67f);
    glVertex2f(-0.416f, 0.66f);
    glVertex2f(-0.45f, 0.67f);
    glVertex2f(-0.456f, 0.66f);
    glVertex2f(-0.48f, 0.67f);
    glVertex2f(-0.486f, 0.66f);
    glVertex2f(-0.11f, 0.64f);
    glVertex2f(-0.116f, 0.63f);
    glVertex2f(-0.15f, 0.64f);
    glVertex2f(-0.156f, 0.63f);
    glVertex2f(-0.18f, 0.64f);
    glVertex2f(-0.186f, 0.63f);
    glVertex2f(-0.21f, 0.64f);
    glVertex2f(-0.216f, 0.63f);
    glVertex2f(-0.25f, 0.64f);
    glVertex2f(-0.256f, 0.63f);
    glVertex2f(-0.28f, 0.61f);
    glVertex2f(-0.286f, 0.6f);
    glVertex2f(-0.31f, 0.61f);
    glVertex2f(-0.316f, 0.6f);
    glVertex2f(-0.35f, 0.61f);
    glVertex2f(-0.356f, 0.6f);
    glVertex2f(-0.38f, 0.61f);
    glVertex2f(-0.386f, 0.6f);
    glVertex2f(-0.41f, 0.62f);
    glVertex2f(-0.416f, 0.61f);
    glVertex2f(-0.45f, 0.62f);
    glVertex2f(-0.456f, 0.61f);
    glVertex2f(-0.48f, 0.63f);
    glVertex2f(-0.486f, 0.62f);
    glVertex2f(-0.11f, 0.54f);
    glVertex2f(-0.116f, 0.53f);
    glVertex2f(-0.15f, 0.58f);
    glVertex2f(-0.156f, 0.57f);
    glVertex2f(-0.21f, 0.55f);
    glVertex2f(-0.216f, 0.54f);
    glVertex2f(-0.28f, 0.58f);
    glVertex2f(-0.286f, 0.57f);
    glVertex2f(-0.33f, 0.55f);
    glVertex2f(-0.336f, 0.54f);
    glVertex2f(-0.35f, 0.58f);
    glVertex2f(-0.356f, 0.57f);
    glVertex2f(-0.39f, 0.56f);
    glVertex2f(-0.396f, 0.55f);
    glVertex2f(-0.41f, 0.53f);
    glVertex2f(-0.416f, 0.52f);
    glVertex2f(-0.45f, 0.58f);
    glVertex2f(-0.456f, 0.57f);
    glVertex2f(-0.48f, 0.56f);
    glVertex2f(-0.486f, 0.55f); //
    glVertex2f(-0.11f, 0.48f);
    glVertex2f(-0.116f, 0.47f);
    glVertex2f(-0.15f, 0.48f);
    glVertex2f(-0.156f, 0.47f);
    glVertex2f(-0.18f, 0.53f);
    glVertex2f(-0.186f, 0.52f);
    glVertex2f(-0.21f, 0.48f);
    glVertex2f(-0.216f, 0.47f);
    glVertex2f(-0.25f, 0.51f);
    glVertex2f(-0.256f, 0.5f);
    glVertex2f(-0.28f, 0.48f);
    glVertex2f(-0.286f, 0.47f);
    glVertex2f(-0.31f, 0.51f);
    glVertex2f(-0.316f, 0.5f);
    glVertex2f(-0.35f, 0.48f);
    glVertex2f(-0.356f, 0.47f);
    glVertex2f(-0.38f, 0.48f);
    glVertex2f(-0.386f, 0.47f);
    glVertex2f(-0.41f, 0.48f);
    glVertex2f(-0.416f, 0.47f);
    glVertex2f(-0.45f, 0.43f);
    glVertex2f(-0.456f, 0.42f);
    glVertex2f(-0.48f, 0.48f);
    glVertex2f(-0.486f, 0.47f);

    glVertex2f(-0.11f, 0.41f);
    glVertex2f(-0.116f, 0.4f);
    glVertex2f(-0.15f, 0.41f);
    glVertex2f(-0.156f, 0.4f);
    glVertex2f(-0.18f, 0.41f);
    glVertex2f(-0.186f, 0.4f);
    glVertex2f(-0.28f, 0.41f);
    glVertex2f(-0.286f, 0.4f);
    glVertex2f(-0.31f, 0.38f);
    glVertex2f(-0.316f, 0.37f);
    glVertex2f(-0.35f, 0.41f);
    glVertex2f(-0.356f, 0.4f);
    glVertex2f(-0.38f, 0.41f);
    glVertex2f(-0.386f, 0.4f);
    glVertex2f(-0.41f, 0.41f);
    glVertex2f(-0.416f, 0.4f);
    glVertex2f(-0.45f, 0.35f);
    glVertex2f(-0.456f, 0.34f);
    glVertex2f(-0.48f, 0.42f);
    glVertex2f(-0.486f, 0.41f); ///

    glVertex2f(-0.11f, 0.29f);
    glVertex2f(-0.116f, 0.28f);
    glVertex2f(-0.13f, 0.29f);
    glVertex2f(-0.136f, 0.28f);
    glVertex2f(-0.15f, 0.26);
    glVertex2f(-0.156f, 0.25f);
    glVertex2f(-0.17f, 0.29f);
    glVertex2f(-0.176f, 0.28f);
    glVertex2f(-0.19f, 0.27f);
    glVertex2f(-0.2f, 0.26f);
    glVertex2f(-0.23f, 0.29f);
    glVertex2f(-0.236f, 0.28f);
    glVertex2f(-0.25f, 0.28f);
    glVertex2f(-0.256f, 0.27f);
    glVertex2f(-0.27f, 0.26f);
    glVertex2f(-0.276f, 0.25f);
    glVertex2f(-0.29f, 0.29f);
    glVertex2f(-0.3f, 0.28f);
    glVertex2f(-0.35f, 0.27f);
    glVertex2f(-0.356f, 0.26f);
    glVertex2f(-0.37f, 0.25f);
    glVertex2f(-0.376f, 0.24f);
    glVertex2f(-0.39f, 0.29f);
    glVertex2f(-0.4f, 0.28f);
    glVertex2f(-0.41f, 0.29f);
    glVertex2f(-0.416f, 0.28f);
    glVertex2f(-0.43f, 0.29f);
    glVertex2f(-0.436f, 0.28f);
    glVertex2f(-0.45f, 0.26);
    glVertex2f(-0.456f, 0.25f);
    glVertex2f(-0.47f, 0.29f);
    glVertex2f(-0.476f, 0.28f);
    glVertex2f(-0.49f, 0.27f);
    glVertex2f(-0.5f, 0.26f);
    glVertex2f(-0.53f, 0.29f);
    glVertex2f(-0.536f, 0.28f);
    glVertex2f(-0.55f, 0.28f);
    glVertex2f(-0.556f, 0.27f);
    glVertex2f(-0.57f, 0.26f);
    glVertex2f(-0.576f, 0.25f);
    glVertex2f(-0.59f, 0.29f);
    glVertex2f(-0.6f, 0.28f);
    glVertex2f(-0.65f, 0.27f);
    glVertex2f(-0.656f, 0.26f);
    glVertex2f(-0.67f, 0.25f);
    glVertex2f(-0.676f, 0.24f);
    glVertex2f(-0.69f, 0.29f);
    glVertex2f(-0.7f, 0.28f);
    glVertex2f(-0.71f, 0.29f);
    glVertex2f(-0.716f, 0.28f);
    glVertex2f(-0.73f, 0.29f);
    glVertex2f(-0.736f, 0.28f);
    glVertex2f(-0.75f, 0.26);
    glVertex2f(-0.756f, 0.25f);
    glVertex2f(-0.77f, 0.29f);
    glVertex2f(-0.776f, 0.28f);
    glVertex2f(-0.79f, 0.27f);
    glVertex2f(-0.8f, 0.26f);
    glVertex2f(-0.83f, 0.29f);
    glVertex2f(-0.836f, 0.28f);
    glVertex2f(-0.85f, 0.26);
    glVertex2f(-0.856f, 0.25f);
    glVertex2f(-0.87f, 0.29f);
    glVertex2f(-0.876f, 0.28f);
    glVertex2f(-0.89f, 0.27f);
    glVertex2f(-0.9f, 0.26f);
    glVertex2f(-0.91f, 0.29f);
    glVertex2f(-0.916f, 0.28f);
    glVertex2f(-0.93f, 0.29f);
    glVertex2f(-0.936f, 0.28f);
    glVertex2f(-0.95f, 0.26);
    glVertex2f(-0.956f, 0.25f);
    glVertex2f(-0.97f, 0.29f);
    glVertex2f(-0.976f, 0.28f); ///////////

    glVertex2f(-0.11f, 0.2f);
    glVertex2f(-0.116f, 0.19f);
    glVertex2f(-0.13f, 0.2f);
    glVertex2f(-0.136f, 0.19f);
    glVertex2f(-0.15f, 0.16);
    glVertex2f(-0.156f, 0.15f);
    glVertex2f(-0.17f, 0.19f);
    glVertex2f(-0.176f, 0.18f);
    glVertex2f(-0.19f, 0.17f);
    glVertex2f(-0.2f, 0.16f);
    glVertex2f(-0.21f, 0.2f);
    glVertex2f(-0.216f, 0.19f);
    glVertex2f(-0.23f, 0.2f);
    glVertex2f(-0.236f, 0.19f);
    glVertex2f(-0.25f, 0.16);
    glVertex2f(-0.256f, 0.15f);
    glVertex2f(-0.27f, 0.19f);
    glVertex2f(-0.276f, 0.18f);
    glVertex2f(-0.29f, 0.17f);
    glVertex2f(-0.3f, 0.16f);
    glVertex2f(-0.31f, 0.2f);
    glVertex2f(-0.316f, 0.19f);
    glVertex2f(-0.33f, 0.2f);
    glVertex2f(-0.336f, 0.19f);
    glVertex2f(-0.35f, 0.16);
    glVertex2f(-0.356f, 0.15f);
    glVertex2f(-0.37f, 0.19f);
    glVertex2f(-0.376f, 0.18f);
    glVertex2f(-0.39f, 0.17f);
    glVertex2f(-0.4f, 0.16f);
    glVertex2f(-0.41f, 0.2f);
    glVertex2f(-0.416f, 0.19f);
    glVertex2f(-0.43f, 0.2f);
    glVertex2f(-0.436f, 0.19f);
    glVertex2f(-0.45f, 0.16);
    glVertex2f(-0.456f, 0.15f);
    glVertex2f(-0.47f, 0.19f);
    glVertex2f(-0.476f, 0.18f);
    glVertex2f(-0.49f, 0.17f);
    glVertex2f(-0.5f, 0.16f);
    glVertex2f(-0.51f, 0.2f);
    glVertex2f(-0.516f, 0.19f);
    glVertex2f(-0.53f, 0.2f);
    glVertex2f(-0.536f, 0.19f);
    glVertex2f(-0.55f, 0.16);
    glVertex2f(-0.556f, 0.15f);
    glVertex2f(-0.57f, 0.19f);
    glVertex2f(-0.576f, 0.18f);
    glVertex2f(-0.59f, 0.17f);
    glVertex2f(-0.6f, 0.16f);
    glVertex2f(-0.71f, 0.2f);
    glVertex2f(-0.716f, 0.19f);
    glVertex2f(-0.65f, 0.16);
    glVertex2f(-0.656f, 0.15f);
    glVertex2f(-0.85f, 0.16);
    glVertex2f(-0.856f, 0.15f);
    glVertex2f(-0.89f, 0.16);
    glVertex2f(-0.9f, 0.15f);
    glVertex2f(-0.75f, 0.16);
    glVertex2f(-0.756f, 0.15f);
    glVertex2f(-0.77f, 0.19f);
    glVertex2f(-0.776f, 0.18f);
    glVertex2f(-0.79f, 0.17f);
    glVertex2f(-0.8f, 0.16f);
    glVertex2f(-0.91f, 0.2f);
    glVertex2f(-0.916f, 0.19f);
    glVertex2f(-0.93f, 0.2f);
    glVertex2f(-0.936f, 0.19f);
    glVertex2f(-0.95f, 0.16);
    glVertex2f(-0.956f, 0.15f);
    glVertex2f(-0.97f, 0.19f);
    glVertex2f(-0.976f, 0.18f);
    glVertex2f(-0.99f, 0.17f);
    glVertex2f(-0.999f, 0.16f);

    glVertex2f(-0.11f, 0.12f);
    glVertex2f(-0.116f, 0.11f);
    glVertex2f(-0.13f, 0.13f);
    glVertex2f(-0.136f, 0.11f);
    glVertex2f(-0.15f, 0.11);
    glVertex2f(-0.156f, 0.10f);
    glVertex2f(-0.17f, 0.12f);
    glVertex2f(-0.176f, 0.11f);
    glVertex2f(-0.19f, 0.13f);
    glVertex2f(-0.2f, 0.12f);
    glVertex2f(-0.21f, 0.09f);
    glVertex2f(-0.216f, 0.08f);
    glVertex2f(-0.23f, 0.11f);
    glVertex2f(-0.236f, 0.10f);
    glVertex2f(-0.25f, 0.13);
    glVertex2f(-0.256f, 0.12f);
    glVertex2f(-0.27f, 0.12f);
    glVertex2f(-0.276f, 0.11f);
    glVertex2f(-0.29f, 0.08f);
    glVertex2f(-0.3f, 0.07f);
    glVertex2f(-0.31f, 0.13f);
    glVertex2f(-0.316f, 0.12f);
    glVertex2f(-0.33f, 0.14f);
    glVertex2f(-0.336f, 0.13f);
    glVertex2f(-0.35f, 0.08);
    glVertex2f(-0.356f, 0.07f);
    glVertex2f(-0.37f, 0.11f);
    glVertex2f(-0.376f, 0.10f);
    glVertex2f(-0.39f, 0.07f);
    glVertex2f(-0.4f, 0.06f);
    glVertex2f(-0.41f, 0.10f);
    glVertex2f(-0.416f, 0.09f);
    glVertex2f(-0.43f, 0.12f);
    glVertex2f(-0.436f, 0.11f);
    glVertex2f(-0.45f, 0.06);
    glVertex2f(-0.456f, 0.05f);
    glVertex2f(-0.47f, 0.11f);
    glVertex2f(-0.476f, 0.10f);
    glVertex2f(-0.49f, 0.13f);
    glVertex2f(-0.5f, 0.12f);
    glVertex2f(-0.51f, 0.12f);
    glVertex2f(-0.516f, 0.11f);
    glVertex2f(-0.53f, 0.13f);
    glVertex2f(-0.536f, 0.11f);
    glVertex2f(-0.55f, 0.11);
    glVertex2f(-0.556f, 0.10f);
    glVertex2f(-0.57f, 0.12f);
    glVertex2f(-0.576f, 0.11f);
    glVertex2f(-0.59f, 0.13f);
    glVertex2f(-0.6f, 0.12f);
    glVertex2f(-0.61f, 0.09f);
    glVertex2f(-0.616f, 0.08f);
    glVertex2f(-0.63f, 0.11f);
    glVertex2f(-0.636f, 0.10f);
    glVertex2f(-0.65f, 0.13);
    glVertex2f(-0.656f, 0.12f);
    glVertex2f(-0.67f, 0.12f);
    glVertex2f(-0.676f, 0.11f);
    glVertex2f(-0.69f, 0.08f);
    glVertex2f(-0.7f, 0.07f);
    glVertex2f(-0.71f, 0.13f);
    glVertex2f(-0.716f, 0.12f);
    glVertex2f(-0.73f, 0.14f);
    glVertex2f(-0.736f, 0.13f);
    glVertex2f(-0.75f, 0.08);
    glVertex2f(-0.756f, 0.07f);
    glVertex2f(-0.77f, 0.11f);
    glVertex2f(-0.776f, 0.10f);
    glVertex2f(-0.79f, 0.07f);
    glVertex2f(-0.8f, 0.06f);
    glVertex2f(-0.81f, 0.10f);
    glVertex2f(-0.816f, 0.09f);
    glVertex2f(-0.83f, 0.12f);
    glVertex2f(-0.836f, 0.11f);
    glVertex2f(-0.85f, 0.06);
    glVertex2f(-0.856f, 0.05f);
    glVertex2f(-0.87f, 0.11f);
    glVertex2f(-0.876f, 0.10f);
    glVertex2f(-0.89f, 0.13f);
    glVertex2f(-0.9f, 0.12f);
    glVertex2f(-0.91f, 0.10f);
    glVertex2f(-0.916f, 0.09f);
    glVertex2f(-0.93f, 0.12f);
    glVertex2f(-0.936f, 0.11f);
    glVertex2f(-0.95f, 0.06);
    glVertex2f(-0.956f, 0.05f);
    glVertex2f(-0.97f, 0.11f);
    glVertex2f(-0.976f, 0.10f);
    glVertex2f(-0.99f, 0.13f);
    glVertex2f(-0.999f, 0.12f); ////////////main/////////////*****************

    glVertex2f(-0.01f, 0.43f);
    glVertex2f(-0.016f, 0.42f);
    glVertex2f(-0.03f, 0.44f);
    glVertex2f(-0.036f, 0.43f);
    glVertex2f(-0.05f, 0.38);
    glVertex2f(-0.056f, 0.37f);
    glVertex2f(-0.07f, 0.41f);
    glVertex2f(-0.076f, 0.4f);
    glVertex2f(-0.09f, 0.37f);
    glVertex2f(-0.1f, 0.36f);
    glVertex2f(-0.11f, 0.43f);
    glVertex2f(-0.116f, 0.42f);
    glVertex2f(-0.13f, 0.44f);
    glVertex2f(-0.136f, 0.43f);
    glVertex2f(-0.15f, 0.38);
    glVertex2f(-0.156f, 0.37f);
    glVertex2f(-0.17f, 0.41f);
    glVertex2f(-0.176f, 0.4f);
    glVertex2f(-0.19f, 0.37f);
    glVertex2f(-0.2f, 0.36f);
    glVertex2f(-0.25f, 0.38);
    glVertex2f(-0.256f, 0.37f);
    glVertex2f(-0.27f, 0.41f);
    glVertex2f(-0.276f, 0.4f);
    glVertex2f(-0.29f, 0.37f);
    glVertex2f(-0.3f, 0.36f);

    glVertex2f(-0.51f, 0.43f);
    glVertex2f(-0.516f, 0.42f);
    glVertex2f(-0.53f, 0.44f);
    glVertex2f(-0.536f, 0.43f);
    glVertex2f(-0.55f, 0.38);
    glVertex2f(-0.556f, 0.37f);
    glVertex2f(-0.57f, 0.41f);
    glVertex2f(-0.576f, 0.4f);
    glVertex2f(-0.59f, 0.37f);
    glVertex2f(-0.6f, 0.36f);
    glVertex2f(-0.61f, 0.43f);
    glVertex2f(-0.616f, 0.42f);
    glVertex2f(-0.63f, 0.44f);
    glVertex2f(-0.636f, 0.43f);
    glVertex2f(-0.65f, 0.38);
    glVertex2f(-0.656f, 0.37f);
    glVertex2f(-0.67f, 0.41f);
    glVertex2f(-0.676f, 0.4f);
    glVertex2f(-0.69f, 0.37f);
    glVertex2f(-0.7f, 0.36f);
    glVertex2f(-0.71f, 0.43f);
    glVertex2f(-0.716f, 0.42f);
    glVertex2f(-0.73f, 0.44f);
    glVertex2f(-0.736f, 0.43f);
    glVertex2f(-0.75f, 0.38);
    glVertex2f(-0.756f, 0.37f);
    glVertex2f(-0.77f, 0.41f);
    glVertex2f(-0.776f, 0.4f);
    glVertex2f(-0.79f, 0.37f);
    glVertex2f(-0.8f, 0.36f);
    glVertex2f(-0.81f, 0.4f);
    glVertex2f(-0.816f, 0.39f);
    glVertex2f(-0.83f, 0.42f);
    glVertex2f(-0.836f, 0.41f);
    glVertex2f(-0.85f, 0.36);
    glVertex2f(-0.856f, 0.35f);
    glVertex2f(-0.87f, 0.41f);
    glVertex2f(-0.876f, 0.4f);
    glVertex2f(-0.89f, 0.43f);
    glVertex2f(-0.9f, 0.42f);
    glVertex2f(-0.91f, 0.4f);
    glVertex2f(-0.916f, 0.39f);
    glVertex2f(-0.93f, 0.42f);
    glVertex2f(-0.936f, 0.41f);
    glVertex2f(-0.95f, 0.36);
    glVertex2f(-0.956f, 0.35f);
    glVertex2f(-0.97f, 0.41f);
    glVertex2f(-0.976f, 0.4f);
    glVertex2f(-0.99f, 0.43f);
    glVertex2f(-0.999f, 0.42f); /////

    glVertex2f(-0.01f, 0.47f);
    glVertex2f(-0.016f, 0.46f);
    glVertex2f(-0.03f, 0.47f);
    glVertex2f(-0.036f, 0.46f);
    glVertex2f(-0.05f, 0.44);
    glVertex2f(-0.056f, 0.43f);
    glVertex2f(-0.07f, 0.44f);
    glVertex2f(-0.076f, 0.43f);
    glVertex2f(-0.09f, 0.4f);
    glVertex2f(-0.1f, 0.39f);
    glVertex2f(-0.01f, 0.51f);
    glVertex2f(-0.016f, 0.5f);
    glVertex2f(-0.03f, 0.56f);
    glVertex2f(-0.036f, 0.55f);
    glVertex2f(-0.05f, 0.47);
    glVertex2f(-0.056f, 0.46f);
    glVertex2f(-0.07f, 0.46f);
    glVertex2f(-0.076f, 0.45f);
    glVertex2f(-0.09f, 0.48f);
    glVertex2f(-0.1f, 0.47f);
    glVertex2f(-0.01f, 0.6f);
    glVertex2f(-0.016f, 0.59f);
    glVertex2f(-0.03f, 0.58f);
    glVertex2f(-0.036f, 0.57f);
    glVertex2f(-0.05f, 0.66);
    glVertex2f(-0.056f, 0.65f);
    glVertex2f(-0.07f, 0.7f);
    glVertex2f(-0.076f, 0.69f);
    glVertex2f(-0.09f, 0.72f);
    glVertex2f(-0.1f, 0.71f);
    glVertex2f(-0.01f, 0.85f);
    glVertex2f(-0.016f, 0.84f);
    glVertex2f(-0.03f, 0.8f);
    glVertex2f(-0.036f, 0.79f);
    glVertex2f(-0.05f, 0.83);
    glVertex2f(-0.056f, 0.82f);
    glVertex2f(-0.07f, 0.88f);
    glVertex2f(-0.076f, 0.87f);
    glVertex2f(-0.09f, 0.84f);
    glVertex2f(-0.1f, 0.83f);

    glVertex2f(-0.11f, 0.85f);
    glVertex2f(-0.116f, 0.84f);
    glVertex2f(-0.13f, 0.8f);
    glVertex2f(-0.136f, 0.79f);
    glVertex2f(-0.15f, 0.83);
    glVertex2f(-0.156f, 0.82f);
    glVertex2f(-0.17f, 0.88f);
    glVertex2f(-0.176f, 0.87f);
    glVertex2f(-0.19f, 0.84f);
    glVertex2f(-0.2f, 0.83f);
    glVertex2f(-0.21f, 0.85f);
    glVertex2f(-0.216f, 0.84f);
    glVertex2f(-0.23f, 0.8f);
    glVertex2f(-0.236f, 0.79f);
    glVertex2f(-0.25f, 0.83);
    glVertex2f(-0.256f, 0.82f);
    glVertex2f(-0.27f, 0.88f);
    glVertex2f(-0.276f, 0.87f);
    glVertex2f(-0.29f, 0.84f);
    glVertex2f(-0.3f, 0.83f);
    glVertex2f(-0.31f, 0.85f);
    glVertex2f(-0.316f, 0.84f);
    glVertex2f(-0.33f, 0.8f);
    glVertex2f(-0.336f, 0.79f);
    glVertex2f(-0.35f, 0.83);
    glVertex2f(-0.356f, 0.82f);
    glVertex2f(-0.37f, 0.88f);
    glVertex2f(-0.376f, 0.87f);
    glVertex2f(-0.39f, 0.84f);
    glVertex2f(-0.4f, 0.83f);
    glVertex2f(-0.41f, 0.85f);
    glVertex2f(-0.416f, 0.84f);
    glVertex2f(-0.43f, 0.8f);
    glVertex2f(-0.436f, 0.79f);
    glVertex2f(-0.45f, 0.83);
    glVertex2f(-0.456f, 0.82f);
    glVertex2f(-0.47f, 0.88f);
    glVertex2f(-0.476f, 0.87f);
    glVertex2f(-0.51f, 0.85f);
    glVertex2f(-0.516f, 0.84f);
    glVertex2f(-0.53f, 0.8f);
    glVertex2f(-0.536f, 0.79f);
    glVertex2f(-0.55f, 0.83);
    glVertex2f(-0.556f, 0.82f);
    glVertex2f(-0.57f, 0.88f);
    glVertex2f(-0.576f, 0.87f);
    glVertex2f(-0.59f, 0.84f);
    glVertex2f(-0.6f, 0.83f);
    glVertex2f(-0.71f, 0.85f);
    glVertex2f(-0.716f, 0.84f);
    glVertex2f(-0.73f, 0.8f);
    glVertex2f(-0.736f, 0.79f);
    glVertex2f(-0.75f, 0.83);
    glVertex2f(-0.756f, 0.82f);
    glVertex2f(-0.77f, 0.88f);
    glVertex2f(-0.776f, 0.87f);
    glVertex2f(-0.79f, 0.84f);
    glVertex2f(-0.8f, 0.83f);
    glVertex2f(-0.91f, 0.85f);
    glVertex2f(-0.916f, 0.84f);
    glVertex2f(-0.93f, 0.8f);
    glVertex2f(-0.936f, 0.79f);
    glVertex2f(-0.95f, 0.83);
    glVertex2f(-0.956f, 0.82f);
    glVertex2f(-0.97f, 0.88f);
    glVertex2f(-0.976f, 0.87f);
    glVertex2f(-0.99f, 0.84f);
    glVertex2f(-0.999f, 0.83f);

    glVertex2f(-0.01f, 0.89f);
    glVertex2f(-0.016f, 0.88f);
    glVertex2f(-0.03f, 0.9f);
    glVertex2f(-0.036f, 0.89f);
    glVertex2f(-0.05f, 0.93);
    glVertex2f(-0.056f, 0.92f);
    glVertex2f(-0.07f, 0.98f);
    glVertex2f(-0.076f, 0.97f);
    glVertex2f(-0.09f, 0.94f);
    glVertex2f(-0.1f, 0.93f);
    glVertex2f(-0.11f, 0.89f);
    glVertex2f(-0.116f, 0.88f);
    glVertex2f(-0.13f, 0.9f);
    glVertex2f(-0.136f, 0.89f);
    glVertex2f(-0.15f, 0.93);
    glVertex2f(-0.156f, 0.92f);
    glVertex2f(-0.17f, 0.98f);
    glVertex2f(-0.176f, 0.97f);
    glVertex2f(-0.19f, 0.94f);
    glVertex2f(-0.2f, 0.93f);
    glVertex2f(-0.21f, 0.89f);
    glVertex2f(-0.216f, 0.88f);
    glVertex2f(-0.23f, 0.9f);
    glVertex2f(-0.236f, 0.89f);
    glVertex2f(-0.25f, 0.93);
    glVertex2f(-0.256f, 0.92f);
    glVertex2f(-0.27f, 0.98f);
    glVertex2f(-0.276f, 0.97f);
    glVertex2f(-0.29f, 0.94f);
    glVertex2f(-0.3f, 0.93f);
    glVertex2f(-0.31f, 0.89f);
    glVertex2f(-0.316f, 0.88f);
    glVertex2f(-0.33f, 0.9f);
    glVertex2f(-0.336f, 0.89f);
    glVertex2f(-0.35f, 0.93);
    glVertex2f(-0.356f, 0.92f);
    glVertex2f(-0.37f, 0.98f);
    glVertex2f(-0.376f, 0.97f);
    glVertex2f(-0.39f, 0.94f);
    glVertex2f(-0.4f, 0.93f);
    glVertex2f(-0.41f, 0.89f);
    glVertex2f(-0.416f, 0.88f);
    glVertex2f(-0.43f, 0.9f);
    glVertex2f(-0.436f, 0.89f);
    glVertex2f(-0.45f, 0.93);
    glVertex2f(-0.456f, 0.92f);
    glVertex2f(-0.47f, 0.98f);
    glVertex2f(-0.476f, 0.97f);
    glVertex2f(-0.49f, 0.94f);
    glVertex2f(-0.5f, 0.93f);
    glVertex2f(-0.51f, 0.89f);
    glVertex2f(-0.516f, 0.88f);
    glVertex2f(-0.53f, 0.9f);
    glVertex2f(-0.536f, 0.89f);
    glVertex2f(-0.55f, 0.93);
    glVertex2f(-0.556f, 0.92f);
    glVertex2f(-0.57f, 0.98f);
    glVertex2f(-0.576f, 0.97f);
    glVertex2f(-0.59f, 0.94f);
    glVertex2f(-0.6f, 0.93f);
    glVertex2f(-0.61f, 0.89f);
    glVertex2f(-0.616f, 0.88f);
    glVertex2f(-0.63f, 0.9f);
    glVertex2f(-0.636f, 0.89f);
    glVertex2f(-0.65f, 0.93);
    glVertex2f(-0.656f, 0.92f);
    glVertex2f(-0.67f, 0.98f);
    glVertex2f(-0.676f, 0.97f);
    glVertex2f(-0.69f, 0.94f);
    glVertex2f(-0.7f, 0.93f);
    glVertex2f(-0.71f, 0.89f);
    glVertex2f(-0.716f, 0.88f);
    glVertex2f(-0.73f, 0.9f);
    glVertex2f(-0.736f, 0.89f);
    glVertex2f(-0.75f, 0.93);
    glVertex2f(-0.756f, 0.92f);
    glVertex2f(-0.77f, 0.98f);
    glVertex2f(-0.776f, 0.97f);
    glVertex2f(-0.79f, 0.94f);
    glVertex2f(-0.8f, 0.93f);
    glVertex2f(-0.81f, 0.89f);
    glVertex2f(-0.816f, 0.88f);
    glVertex2f(-0.83f, 0.9f);
    glVertex2f(-0.836f, 0.89f);
    glVertex2f(-0.85f, 0.93);
    glVertex2f(-0.856f, 0.92f);
    glVertex2f(-0.87f, 0.98f);
    glVertex2f(-0.876f, 0.97f);
    glVertex2f(-0.89f, 0.94f);
    glVertex2f(-0.9f, 0.93f);

    glVertex2f(-0.01f, 0.09f);
    glVertex2f(-0.016f, 0.08f);
    glVertex2f(-0.03f, 0.1f);
    glVertex2f(-0.036f, 0.09f);
    glVertex2f(-0.05f, 0.13);
    glVertex2f(-0.056f, 0.12f);
    glVertex2f(-0.07f, 0.18f);
    glVertex2f(-0.076f, 0.17f);

    glVertex2f(-0.01f, 0.02f);
    glVertex2f(-0.016f, 0.01f);
    glVertex2f(-0.03f, 0.05f);
    glVertex2f(-0.036f, 0.04f);
    glVertex2f(-0.05f, 0.03);
    glVertex2f(-0.056f, 0.02f);
    glVertex2f(-0.07f, 0.07f);
    glVertex2f(-0.076f, 0.06f);
    glVertex2f(-0.1f, 0.02f);
    glVertex2f(-0.116f, 0.01f);
    glVertex2f(-0.13f, 0.05f);
    glVertex2f(-0.136f, 0.04f);
    glVertex2f(-0.15f, 0.03);
    glVertex2f(-0.156f, 0.02f);
    glVertex2f(-0.17f, 0.07f);
    glVertex2f(-0.176f, 0.06f);
    glVertex2f(-0.21f, 0.02f);
    glVertex2f(-0.216f, 0.01f);
    glVertex2f(-0.33f, 0.05f);
    glVertex2f(-0.336f, 0.04f);
    glVertex2f(-0.35f, 0.03);
    glVertex2f(-0.356f, 0.02f);
    glVertex2f(-0.37f, 0.07f);
    glVertex2f(-0.376f, 0.06f);
    glVertex2f(-0.41f, 0.02f);
    glVertex2f(-0.416f, 0.01f);
    glVertex2f(-0.43f, 0.05f);
    glVertex2f(-0.436f, 0.04f);
    glVertex2f(-0.5f, 0.03);
    glVertex2f(-0.516f, 0.02f);
    glVertex2f(-0.57f, 0.07f);
    glVertex2f(-0.576f, 0.06f);

    glVertex2f(-0.01f, 0.12f);
    glVertex2f(-0.016f, 0.11f);
    glVertex2f(-0.03f, 0.15f);
    glVertex2f(-0.036f, 0.14f);
    glVertex2f(-0.05f, 0.13);
    glVertex2f(-0.056f, 0.12f);
    glVertex2f(-0.07f, 0.17f);
    glVertex2f(-0.076f, 0.16f);

    glVertex2f(-0.01f, 0.32f);
    glVertex2f(-0.016f, 0.31f);
    glVertex2f(-0.03f, 0.35f);
    glVertex2f(-0.036f, 0.34f);
    glVertex2f(-0.05f, 0.33);
    glVertex2f(-0.056f, 0.32f);
    glVertex2f(-0.07f, 0.37f);
    glVertex2f(-0.076f, 0.36f);

    glVertex2f(-0.01f, 0.22f);
    glVertex2f(-0.016f, 0.21f);
    glVertex2f(-0.03f, 0.25f);
    glVertex2f(-0.036f, 0.24f);
    glVertex2f(-0.05f, 0.23);
    glVertex2f(-0.056f, 0.22f);
    glVertex2f(-0.07f, 0.27f);
    glVertex2f(-0.076f, 0.26f);

    glVertex2f(-0.01f, 0.72f);
    glVertex2f(-0.016f, 0.71f);
    glVertex2f(-0.03f, 0.75f);
    glVertex2f(-0.036f, 0.74f);
    glVertex2f(-0.05f, 0.73);
    glVertex2f(-0.056f, 0.72f);
    glVertex2f(-0.07f, 0.77f);
    glVertex2f(-0.076f, 0.76f);
    glVertex2f(-0.11f, 0.72f);
    glVertex2f(-0.116f, 0.71f);
    glVertex2f(-0.13f, 0.75f);
    glVertex2f(-0.136f, 0.74f);
    glVertex2f(-0.15f, 0.73);
    glVertex2f(-0.156f, 0.72f);
    glVertex2f(-0.17f, 0.77f);
    glVertex2f(-0.176f, 0.76f);
    glVertex2f(-0.21f, 0.72f);
    glVertex2f(-0.216f, 0.71f);
    glVertex2f(-0.23f, 0.75f);
    glVertex2f(-0.236f, 0.74f);
    glVertex2f(-0.25f, 0.73);
    glVertex2f(-0.256f, 0.72f);
    glVertex2f(-0.27f, 0.77f);
    glVertex2f(-0.276f, 0.76f);
    glVertex2f(-0.41f, 0.72f);
    glVertex2f(-0.416f, 0.71f);
    glVertex2f(-0.43f, 0.75f);
    glVertex2f(-0.436f, 0.74f);
    glVertex2f(-0.45f, 0.73);
    glVertex2f(-0.456f, 0.72f);
    glVertex2f(-0.47f, 0.77f);
    glVertex2f(-0.476f, 0.76f);
    glVertex2f(-0.51f, 0.72f);
    glVertex2f(-0.516f, 0.71f);
    glVertex2f(-0.55f, 0.73);
    glVertex2f(-0.56f, 0.72f);
    glVertex2f(-0.57f, 0.77f);
    glVertex2f(-0.576f, 0.76f);
    glVertex2f(-0.71f, 0.72f);
    glVertex2f(-0.716f, 0.71f);
    glVertex2f(-0.73f, 0.75f);
    glVertex2f(-0.736f, 0.74f);
    glVertex2f(-0.75f, 0.73);
    glVertex2f(-0.756f, 0.72f);
    glVertex2f(-0.77f, 0.77f);
    glVertex2f(-0.776f, 0.76f);
    glVertex2f(-0.91f, 0.72f);
    glVertex2f(-0.916f, 0.71f);
    glVertex2f(-0.93f, 0.75f);
    glVertex2f(-0.936f, 0.74f);
    glVertex2f(-0.95f, 0.73);
    glVertex2f(-0.956f, 0.72f);
    glVertex2f(-0.97f, 0.77f);
    glVertex2f(-0.976f, 0.76f);

    glVertex2f(-0.99f, 0.68f);
    glVertex2f(-0.999f, 0.67f);

    glVertex2f(-0.99f, 0.64f);
    glVertex2f(-0.999f, 0.63f);
    glVertex2f(-0.95f, 0.63f);
    glVertex2f(-0.956f, 0.62f);

    glVertex2f(-0.99f, 0.56f);
    glVertex2f(-0.999f, 0.55f);

    glVertex2f(-0.99f, 0.49f);
    glVertex2f(-0.999f, 0.48f);
    glVertex2f(-0.97f, 0.49f);
    glVertex2f(-0.976f, 0.48f);
    glVertex2f(-0.95f, 0.45f);
    glVertex2f(-0.956f, 0.44f);
    glVertex2f(-0.93f, 0.49f);
    glVertex2f(-0.936f, 0.48f);
    glVertex2f(-0.91f, 0.49f);
    glVertex2f(-0.916f, 0.48f);

    glVertex2f(-0.89f, 0.49f);
    glVertex2f(-0.899f, 0.48f);
    glVertex2f(-0.87f, 0.49f);
    glVertex2f(-0.876f, 0.48f);
    glVertex2f(-0.85f, 0.45f);
    glVertex2f(-0.856f, 0.44f);
    glVertex2f(-0.83f, 0.49f);
    glVertex2f(-0.836f, 0.48f);
    glVertex2f(-0.81f, 0.47f);
    glVertex2f(-0.816f, 0.46f);

    glVertex2f(-0.89f, 0.03f);
    glVertex2f(-0.899f, 0.02f);
    glVertex2f(-0.87f, 0.03f);
    glVertex2f(-0.876f, 0.02f);
    glVertex2f(-0.85f, 0.03f);
    glVertex2f(-0.856f, 0.02f);
    glVertex2f(-0.83f, 0.05f);
    glVertex2f(-0.836f, 0.04f);
    glVertex2f(-0.81f, 0.04f);
    glVertex2f(-0.816f, 0.03f);

    glVertex2f(-0.79f, 0.03f);
    glVertex2f(-0.799f, 0.02f);
    glVertex2f(-0.77f, 0.03f);
    glVertex2f(-0.776f, 0.02f);
    glVertex2f(-0.75f, 0.03f);
    glVertex2f(-0.756f, 0.02f);
    glVertex2f(-0.73f, 0.05f);
    glVertex2f(-0.736f, 0.04f);
    glVertex2f(-0.71f, 0.03f);
    glVertex2f(-0.716f, 0.02f);

    glVertex2f(-0.59f, 0.03f);
    glVertex2f(-0.599f, 0.02f);
    glVertex2f(-0.57f, 0.03f);
    glVertex2f(-0.576f, 0.02f);
    glVertex2f(-0.55f, 0.03f);
    glVertex2f(-0.556f, 0.02f);
    glVertex2f(-0.53f, 0.03f);
    glVertex2f(-0.536f, 0.02f);

    glVertex2f(-0.69f, 0.04f);
    glVertex2f(-0.699f, 0.03f);
    glVertex2f(-0.67f, 0.03f);
    glVertex2f(-0.676f, 0.02f);
    glVertex2f(-0.65f, 0.06f);
    glVertex2f(-0.656f, 0.05f);
    glVertex2f(-0.63f, 0.03f);
    glVertex2f(-0.636f, 0.02f);
    glVertex2f(-0.61f, 0.07f);
    glVertex2f(-0.616f, 0.06f);

    glVertex2f(-0.39f, 0.04f);
    glVertex2f(-0.399f, 0.03f);
    glVertex2f(-0.37f, 0.03f);
    glVertex2f(-0.376f, 0.02f);
    glVertex2f(-0.35f, 0.06f);
    glVertex2f(-0.356f, 0.05f);
    glVertex2f(-0.33f, 0.03f);
    glVertex2f(-0.336f, 0.02f);
    glVertex2f(-0.31f, 0.03f);
    glVertex2f(-0.316f, 0.02f);

    glVertex2f(-0.29f, 0.04f);
    glVertex2f(-0.299f, 0.03f);
    glVertex2f(-0.27f, 0.03f);
    glVertex2f(-0.276f, 0.02f);
    glVertex2f(-0.25f, 0.06f);
    glVertex2f(-0.256f, 0.05f);
    glVertex2f(-0.23f, 0.03f);
    glVertex2f(-0.236f, 0.02f);
    glVertex2f(-0.21f, 0.03f);
    glVertex2f(-0.216f, 0.02f); ////////////////////////XXYY////////

    glVertex2f(0.2f, 0.2f);
    glVertex2f(0.21f, 0.22f);
    glVertex2f(0.1f, 0.1f);
    glVertex2f(0.11f, 0.12f);
    glVertex2f(0.4f, 0.4f);
    glVertex2f(0.41f, 0.42f);
    glVertex2f(0.35f, 0.35f);
    glVertex2f(0.355f, 0.356f);
    glVertex2f(0.31f, 0.35f);
    glVertex2f(0.315f, 0.36f);
    glVertex2f(0.29f, 0.35f);
    glVertex2f(0.299f, 0.36f);
    glVertex2f(0.31f, 0.35f);
    glVertex2f(0.315f, 0.36f);
    glVertex2f(0.41f, 0.35f);
    glVertex2f(0.415f, 0.36f);
    glVertex2f(0.42f, 0.35f);
    glVertex2f(0.433f, 0.36f);
    glVertex2f(0.439f, 0.35f);
    glVertex2f(0.448f, 0.36f);
    glVertex2f(0.55f, 0.35f);
    glVertex2f(0.555f, 0.36f);
    glVertex2f(0.65f, 0.35f);
    glVertex2f(0.655f, 0.36f);
    glVertex2f(0.75f, 0.35f);
    glVertex2f(0.755f, 0.36f);
    glVertex2f(0.55f, 0.37f);
    glVertex2f(0.555f, 0.38f);
    glVertex2f(0.65f, 0.37f);
    glVertex2f(0.655f, 0.38f);
    glVertex2f(0.75f, 0.37f);
    glVertex2f(0.755f, 0.38f);
    glVertex2f(0.55f, 0.38f);
    glVertex2f(0.555f, 0.39f);

    glVertex2f(0.57f, 0.38f);
    glVertex2f(0.576f, 0.39f);
    glVertex2f(0.8f, 0.2f);
    glVertex2f(0.81f, 0.22f);

    glVertex2f(0.8f, 0.5f);
    glVertex2f(0.81f, 0.52f);
    glVertex2f(0.8f, 0.52f);
    glVertex2f(0.81f, 0.54f);
    glVertex2f(0.82f, 0.557f);
    glVertex2f(0.83f, 0.56f);
    glVertex2f(0.84f, 0.56f);
    glVertex2f(0.85f, 0.58f);
    glVertex2f(0.89f, 0.56f);
    glVertex2f(0.90f, 0.58f);
    glVertex2f(0.92f, 0.56f);
    glVertex2f(0.93f, 0.56f);
    glVertex2f(0.92f, 0.36f);
    glVertex2f(0.93f, 0.38f);
    glVertex2f(0.92f, 0.36f);
    glVertex2f(0.93f, 0.38f);
    glVertex2f(0.45f, 0.87f);
    glVertex2f(0.455f, 0.88f);
    glVertex2f(0.55f, 0.81f);
    glVertex2f(0.555f, 0.82f); ///////////
    glVertex2f(0.45f, 0.61f);
    glVertex2f(0.455f, 0.62f);
    glVertex2f(0.55f, 0.64f);
    glVertex2f(0.555f, 0.64f);
    glVertex2f(0.45f, 0.62f);
    glVertex2f(0.455f, 0.63f);
    glVertex2f(0.62f, 0.65f);
    glVertex2f(0.63f, 0.66f);
    glVertex2f(0.62f, 0.55f);
    glVertex2f(0.63f, 0.56f); ///
    glVertex2f(0.64f, 0.50f);
    glVertex2f(0.65f, 0.51f);
    glVertex2f(0.67f, 0.47f);
    glVertex2f(0.68f, 0.48f);
    glVertex2f(0.62f, 0.53f);
    glVertex2f(0.628f, 0.54f); ///
    glVertex2f(0.54f, 0.50f);
    glVertex2f(0.55f, 0.51f);
    glVertex2f(0.57f, 0.47f);
    glVertex2f(0.58f, 0.48f);
    glVertex2f(0.52f, 0.53f);
    glVertex2f(0.528f, 0.54f); ///
    glVertex2f(0.56f, 0.50f);
    glVertex2f(0.57f, 0.51f);
    glVertex2f(0.58f, 0.47f);
    glVertex2f(0.59f, 0.48f);
    glVertex2f(0.53f, 0.53f);
    glVertex2f(0.538f, 0.54f); ///
    glVertex2f(0.77f, 0.50f);
    glVertex2f(0.78f, 0.51f);
    glVertex2f(0.42f, 0.50f);
    glVertex2f(0.43f, 0.51f);
    glVertex2f(0.45f, 0.50f);
    glVertex2f(0.46f, 0.51f); ///
    glVertex2f(0.45f, 0.47f);
    glVertex2f(0.46f, 0.48f);
    glVertex2f(0.51f, 0.47f);
    glVertex2f(0.52f, 0.48f); //
    glVertex2f(0.51f, 0.50f);
    glVertex2f(0.52f, 0.51f);
    glVertex2f(0.47f, 0.50f);
    glVertex2f(0.48f, 0.51f);
    glVertex2f(0.47f, 0.53f);
    glVertex2f(0.48f, 0.54f); ///

    glVertex2f(0.47f, 0.53f);
    glVertex2f(0.48f, 0.54f);
    glVertex2f(0.65f, 0.87f);
    glVertex2f(0.655f, 0.88f);
    glVertex2f(0.75f, 0.87f);
    glVertex2f(0.755f, 0.88f); //
    glVertex2f(0.85f, 0.87f);
    glVertex2f(0.855f, 0.88f);
    glVertex2f(0.95f, 0.87f);
    glVertex2f(0.955f, 0.88f); //
    glVertex2f(0.84f, 0.87f);
    glVertex2f(0.844f, 0.88f);
    glVertex2f(0.92f, 0.87f);
    glVertex2f(0.922f, 0.88f); //
    glVertex2f(0.84f, 0.84f);
    glVertex2f(0.844f, 0.85f);
    glVertex2f(0.92f, 0.90f);
    glVertex2f(0.922f, 0.91f); //
    glVertex2f(0.95f, 0.44f);
    glVertex2f(0.955f, 0.45f);
    glVertex2f(0.95f, 0.54f);
    glVertex2f(0.955f, 0.55f);
    glVertex2f(0.95f, 0.64f);
    glVertex2f(0.955f, 0.65f);
    glVertex2f(0.95f, 0.74f);
    glVertex2f(0.955f, 0.75f); ///
    glVertex2f(0.92f, 0.74f);
    glVertex2f(0.93f, 0.75f);
    glVertex2f(0.87f, 0.74f);
    glVertex2f(0.877f, 0.75f);
    glVertex2f(0.44f, 0.74f);
    glVertex2f(0.45f, 0.75f); ///
    glVertex2f(0.52f, 0.74f);
    glVertex2f(0.533f, 0.75f);
    glVertex2f(0.48f, 0.74f);
    glVertex2f(0.488f, 0.75f);
    glVertex2f(0.58f, 0.74f);
    glVertex2f(0.588f, 0.75f);
    glVertex2f(0.62f, 0.74f);
    glVertex2f(0.626f, 0.75f);

    glVertex2f(0.72f, 0.74f);
    glVertex2f(0.726f, 0.75f);
    glVertex2f(0.72f, 0.71f);
    glVertex2f(0.726f, 0.72f);
    glVertex2f(0.72f, 0.66f);
    glVertex2f(0.726f, 0.67f);
    glVertex2f(0.72f, 0.60f);
    glVertex2f(0.726f, 0.61f); //
    glVertex2f(0.72f, 0.67f);
    glVertex2f(0.726f, 0.68f);
    glVertex2f(0.74f, 0.67f);
    glVertex2f(0.746f, 0.68f);
    glVertex2f(0.77f, 0.67f);
    glVertex2f(0.776f, 0.68f); /////[main]
    glVertex2f(0.77f, 0.65f);
    glVertex2f(0.776f, 0.66f);
    glVertex2f(0.73f, 0.68f);
    glVertex2f(0.736f, 0.69f);
    glVertex2f(0.75f, 0.69f);
    glVertex2f(0.757f, 0.70f);
    glVertex2f(0.81f, 0.67f);
    glVertex2f(0.82f, 0.68f);

    glVertex2f(0.83f, 0.67f); ///
    glVertex2f(0.835f, 0.68f);
    glVertex2f(0.85f, 0.67f);
    glVertex2f(0.856f, 0.68f);
    glVertex2f(0.87f, 0.67f);
    glVertex2f(0.876f, 0.68f);
    glVertex2f(0.89f, 0.67f);
    glVertex2f(0.897f, 0.68f);

    glVertex2f(0.83f, 0.62f);
    glVertex2f(0.835f, 0.63f);
    glVertex2f(0.85f, 0.62f);
    glVertex2f(0.856f, 0.63f);
    glVertex2f(0.87f, 0.62f);
    glVertex2f(0.876f, 0.63f);
    glVertex2f(0.89f, 0.62f);
    glVertex2f(0.897f, 0.63f); ///

    glVertex2f(0.79f, 0.62f);
    glVertex2f(0.795f, 0.623f);
    glVertex2f(0.74f, 0.62f);
    glVertex2f(0.746f, 0.63f);
    glVertex2f(0.71f, 0.62f);
    glVertex2f(0.726f, 0.63f);
    glVertex2f(0.70f, 0.62f);
    glVertex2f(0.705f, 0.63f); //

    glVertex2f(0.7f, 0.54f);
    glVertex2f(0.71f, 0.56f);
    glVertex2f(0.73f, 0.54f);
    glVertex2f(0.74f, 0.56f);

    glVertex2f(0.79f, 0.55f);
    glVertex2f(0.795f, 0.56f);
    glVertex2f(0.76f, 0.55f);
    glVertex2f(0.766f, 0.56f);
    glVertex2f(0.72f, 0.55f);
    glVertex2f(0.726f, 0.56f);
    glVertex2f(0.76f, 0.58f);
    glVertex2f(0.766f, 0.59f); ///
    glVertex2f(0.79f, 0.58f);
    glVertex2f(0.795f, 0.59f);
    glVertex2f(0.66f, 0.58f);
    glVertex2f(0.666f, 0.59f);
    glVertex2f(0.64f, 0.58f);
    glVertex2f(0.646f, 0.59f);
    glVertex2f(0.54f, 0.58f);
    glVertex2f(0.546f, 0.59f);
    glVertex2f(0.51f, 0.58f);
    glVertex2f(0.516f, 0.59f);
    glVertex2f(0.57f, 0.58f);
    glVertex2f(0.576f, 0.59f);
    glVertex2f(0.51f, 0.61f);
    glVertex2f(0.516f, 0.62f);
    glVertex2f(0.51f, 0.64f);
    glVertex2f(0.516f, 0.65f); ///

    glVertex2f(0.51f, 0.69f);
    glVertex2f(0.516f, 0.70f);
    glVertex2f(0.53f, 0.69f);
    glVertex2f(0.536f, 0.70f);
    glVertex2f(0.55f, 0.69f);
    glVertex2f(0.556f, 0.70f);
    glVertex2f(0.57f, 0.69f);
    glVertex2f(0.576f, 0.70f);
    glVertex2f(0.59f, 0.69f);
    glVertex2f(0.6f, 0.70f);
    glVertex2f(0.62f, 0.69f);
    glVertex2f(0.626f, 0.70f);
    glVertex2f(0.64f, 0.69f);
    glVertex2f(0.646f, 0.70f);
    glVertex2f(0.66f, 0.69f);
    glVertex2f(0.666f, 0.70f);
    glVertex2f(0.68f, 0.69f);
    glVertex2f(0.689f, 0.70f);
    glVertex2f(0.41f, 0.69f);
    glVertex2f(0.416f, 0.70f);
    glVertex2f(0.43f, 0.69f);
    glVertex2f(0.436f, 0.70f);
    glVertex2f(0.45f, 0.66f);
    glVertex2f(0.456f, 0.67f);
    glVertex2f(0.47f, 0.69f);
    glVertex2f(0.476f, 0.70f);
    glVertex2f(0.49f, 0.69f);
    glVertex2f(0.5f, 0.70f);
    glVertex2f(0.11f, 0.69f);
    glVertex2f(0.116f, 0.70f);
    glVertex2f(0.13f, 0.69f);
    glVertex2f(0.136f, 0.70f);
    glVertex2f(0.15f, 0.67f);
    glVertex2f(0.156f, 0.68f);
    glVertex2f(0.17f, 0.69f);
    glVertex2f(0.176f, 0.70f);
    glVertex2f(0.19f, 0.69f);
    glVertex2f(0.2f, 0.70f);
    glVertex2f(0.23f, 0.69f);
    glVertex2f(0.236f, 0.70f);
    glVertex2f(0.25f, 0.69f);
    glVertex2f(0.256f, 0.70f);
    glVertex2f(0.27f, 0.69f);
    glVertex2f(0.276f, 0.70f);
    glVertex2f(0.29f, 0.69f);
    glVertex2f(0.3f, 0.70f);
    glVertex2f(0.35f, 0.69f);
    glVertex2f(0.356f, 0.70f);
    glVertex2f(0.37f, 0.69f);
    glVertex2f(0.376f, 0.70f);
    glVertex2f(0.39f, 0.69f);
    glVertex2f(0.4f, 0.70f); ///

    glVertex2f(0.11f, 0.66f);
    glVertex2f(0.116f, 0.67f);
    glVertex2f(0.15f, 0.66f);
    glVertex2f(0.156f, 0.67f);
    glVertex2f(0.18f, 0.66f);
    glVertex2f(0.186f, 0.67f);
    glVertex2f(0.21f, 0.66f);
    glVertex2f(0.216f, 0.67f);
    glVertex2f(0.25f, 0.66f);
    glVertex2f(0.256f, 0.67f);
    glVertex2f(0.28f, 0.66f);
    glVertex2f(0.286f, 0.67f);
    glVertex2f(0.31f, 0.66f);
    glVertex2f(0.316f, 0.67f);
    glVertex2f(0.35f, 0.66f);
    glVertex2f(0.356f, 0.67f);
    glVertex2f(0.38f, 0.66f);
    glVertex2f(0.386f, 0.67f);
    glVertex2f(0.41f, 0.66f);
    glVertex2f(0.416f, 0.67f);
    glVertex2f(0.45f, 0.66f);
    glVertex2f(0.456f, 0.67f);
    glVertex2f(0.48f, 0.66f);
    glVertex2f(0.486f, 0.67f);

    glVertex2f(0.11f, 0.63f);
    glVertex2f(0.116f, 0.64f);
    glVertex2f(0.15f, 0.63f);
    glVertex2f(0.156f, 0.64f);
    glVertex2f(0.18f, 0.63f);
    glVertex2f(0.186f, 0.64f);
    glVertex2f(0.21f, 0.63f);
    glVertex2f(0.216f, 0.64f);
    glVertex2f(0.25f, 0.63f);
    glVertex2f(0.256f, 0.64f);
    glVertex2f(0.28f, 0.6f);
    glVertex2f(0.286f, 0.61f);
    glVertex2f(0.31f, 0.6f);
    glVertex2f(0.316f, 0.61f);
    glVertex2f(0.35f, 0.6f);
    glVertex2f(0.356f, 0.61f);
    glVertex2f(0.38f, 0.6f);
    glVertex2f(0.386f, 0.61f);
    glVertex2f(0.41f, 0.61f);
    glVertex2f(0.416f, 0.62f);
    glVertex2f(0.45f, 0.621f);
    glVertex2f(0.456f, 0.62f);
    glVertex2f(0.48f, 0.62f);
    glVertex2f(0.486f, 0.63f); //

    glVertex2f(0.11f, 0.53f);
    glVertex2f(0.116f, 0.54f);
    glVertex2f(0.15f, 0.57f);
    glVertex2f(0.156f, 0.58f);

    glVertex2f(0.21f, 0.54f);
    glVertex2f(0.216f, 0.55f);

    glVertex2f(0.28f, 0.57f);
    glVertex2f(0.286f, 0.58f);
    glVertex2f(0.33f, 0.54f);
    glVertex2f(0.336f, 0.55f);
    glVertex2f(0.35f, 0.57f);
    glVertex2f(0.356f, 0.58f);
    glVertex2f(0.39f, 0.55f);
    glVertex2f(0.396f, 0.56f);
    glVertex2f(0.41f, 0.52f);
    glVertex2f(0.416f, 0.53f);
    glVertex2f(0.45f, 0.57f);
    glVertex2f(0.456f, 0.58f);
    glVertex2f(0.48f, 0.55f);
    glVertex2f(0.486f, 0.56f); //

    glVertex2f(0.11f, 0.47f);
    glVertex2f(0.116f, 0.48f);
    glVertex2f(0.15f, 0.47f);
    glVertex2f(0.156f, 0.48f);
    glVertex2f(0.18f, 0.52f);
    glVertex2f(0.186f, 0.53f);
    glVertex2f(0.21f, 0.47f);
    glVertex2f(0.216f, 0.48f);
    glVertex2f(0.25f, 0.5f);
    glVertex2f(0.256f, 0.51f);
    glVertex2f(0.28f, 0.47f);
    glVertex2f(0.286f, 0.48f);
    glVertex2f(0.31f, 0.5f);
    glVertex2f(0.316f, 0.51f);
    glVertex2f(0.35f, 0.47f);
    glVertex2f(0.356f, 0.48f);
    glVertex2f(0.38f, 0.47f);
    glVertex2f(0.386f, 0.48f);
    glVertex2f(0.41f, 0.47f);
    glVertex2f(0.416f, 0.48f);
    glVertex2f(0.45f, 0.42f);
    glVertex2f(0.456f, 0.43f);
    glVertex2f(0.48f, 0.47f);
    glVertex2f(0.486f, 0.48f);

    glVertex2f(0.11f, 0.4f);
    glVertex2f(0.116f, 0.41f);
    glVertex2f(0.15f, 0.4f);
    glVertex2f(0.156f, 0.41f);
    glVertex2f(0.18f, 0.4f);
    glVertex2f(0.186f, 0.41f);
    glVertex2f(0.28f, 0.4f);
    glVertex2f(0.286f, 0.41f);
    glVertex2f(0.31f, 0.37f);
    glVertex2f(0.316f, 0.38f);
    glVertex2f(0.35f, 0.4f);
    glVertex2f(0.356f, 0.41f);
    glVertex2f(0.38f, 0.4f);
    glVertex2f(0.386f, 0.41f);
    glVertex2f(0.41f, 0.4f);
    glVertex2f(0.416f, 0.41f);
    glVertex2f(0.45f, 0.34f);
    glVertex2f(0.456f, 0.34f);
    glVertex2f(0.48f, 0.41f);
    glVertex2f(0.486f, 0.42f); ///

    glVertex2f(0.11f, 0.28f);
    glVertex2f(0.116f, 0.29f);
    glVertex2f(0.13f, 0.28f);
    glVertex2f(0.136f, 0.29f);
    glVertex2f(0.15f, 0.25);
    glVertex2f(0.156f, 0.26f);
    glVertex2f(0.17f, 0.28f);
    glVertex2f(0.176f, 0.29f);
    glVertex2f(0.19f, 0.26f);
    glVertex2f(0.2f, 0.27f);
    glVertex2f(0.23f, 0.28f);
    glVertex2f(0.236f, 0.29f);
    glVertex2f(0.25f, 0.27f);
    glVertex2f(0.256f, 0.28f);
    glVertex2f(0.27f, 0.25f);
    glVertex2f(0.276f, 0.26f);
    glVertex2f(0.29f, 0.28f);
    glVertex2f(0.3f, 0.29f);
    glVertex2f(0.35f, 0.26f);
    glVertex2f(0.356f, 0.27f);
    glVertex2f(0.37f, 0.24f);
    glVertex2f(0.376f, 0.25f);
    glVertex2f(0.39f, 0.28f);
    glVertex2f(0.4f, 0.29f);
    glVertex2f(0.41f, 0.28f);
    glVertex2f(0.416f, 0.29f);
    glVertex2f(0.43f, 0.28f);
    glVertex2f(0.436f, 0.29f);
    glVertex2f(0.45f, 0.25);
    glVertex2f(0.456f, 0.26f);
    glVertex2f(0.47f, 0.28f);
    glVertex2f(0.476f, 0.29f);
    glVertex2f(0.49f, 0.26f);
    glVertex2f(0.5f, 0.27f);
    glVertex2f(0.53f, 0.28f);
    glVertex2f(0.536f, 0.29f);
    glVertex2f(0.55f, 0.27f);
    glVertex2f(0.556f, 0.28f);
    glVertex2f(0.57f, 0.25f);
    glVertex2f(0.576f, 0.26f);
    glVertex2f(0.59f, 0.28f);
    glVertex2f(0.6f, 0.29f);
    glVertex2f(0.65f, 0.26f);
    glVertex2f(0.656f, 0.27f);
    glVertex2f(0.67f, 0.24f);
    glVertex2f(0.676f, 0.25f);
    glVertex2f(0.69f, 0.28f);
    glVertex2f(0.7f, 0.29f);
    glVertex2f(0.71f, 0.28f);
    glVertex2f(0.716f, 0.29f);
    glVertex2f(0.73f, 0.28f);
    glVertex2f(0.736f, 0.29f);
    glVertex2f(0.75f, 0.25);
    glVertex2f(0.756f, 0.26f);
    glVertex2f(0.77f, 0.28f);
    glVertex2f(0.776f, 0.29f);
    glVertex2f(0.79f, 0.26f);
    glVertex2f(0.8f, 0.27f);
    glVertex2f(0.83f, 0.28f);
    glVertex2f(0.836f, 0.29f);
    glVertex2f(0.85f, 0.25);
    glVertex2f(0.856f, 0.26f);
    glVertex2f(0.87f, 0.28f);
    glVertex2f(0.876f, 0.29f);
    glVertex2f(0.89f, 0.26f);
    glVertex2f(0.9f, 0.27f);
    glVertex2f(0.91f, 0.28f);
    glVertex2f(0.916f, 0.29f);
    glVertex2f(0.93f, 0.28f);
    glVertex2f(0.936f, 0.29f);
    glVertex2f(0.95f, 0.25);
    glVertex2f(0.956f, 0.26f);
    glVertex2f(0.97f, 0.28f);
    glVertex2f(0.976f, 0.29f); ///////////

    glVertex2f(0.11f, 0.19f);
    glVertex2f(0.116f, 0.2f);
    glVertex2f(0.13f, 0.19f);
    glVertex2f(0.136f, 0.2f);
    glVertex2f(0.15f, 0.15);
    glVertex2f(0.156f, 0.16f);
    glVertex2f(0.17f, 0.18f);
    glVertex2f(0.176f, 0.19f);
    glVertex2f(0.19f, 0.16f);
    glVertex2f(0.2f, 0.17f);
    glVertex2f(0.21f, 0.19f);
    glVertex2f(0.216f, 0.2f);
    glVertex2f(0.23f, 0.19f);
    glVertex2f(0.236f, 0.2f);
    glVertex2f(0.25f, 0.15);
    glVertex2f(0.256f, 0.16f);
    glVertex2f(0.27f, 0.18f);
    glVertex2f(0.276f, 0.19f);
    glVertex2f(0.29f, 0.16f);
    glVertex2f(0.3f, 0.17f);
    glVertex2f(0.31f, 0.19f);
    glVertex2f(0.316f, 0.2f);
    glVertex2f(0.33f, 0.19f);
    glVertex2f(0.336f, 0.2f);
    glVertex2f(0.35f, 0.15);
    glVertex2f(0.356f, 0.16f);
    glVertex2f(0.37f, 0.18f);
    glVertex2f(0.376f, 0.19f);
    glVertex2f(0.39f, 0.16f);
    glVertex2f(0.4f, 0.17f);
    glVertex2f(0.41f, 0.19f);
    glVertex2f(0.416f, 0.2f);
    glVertex2f(0.43f, 0.19f);
    glVertex2f(0.436f, 0.2f);
    glVertex2f(0.45f, 0.15);
    glVertex2f(0.456f, 0.16f);
    glVertex2f(0.47f, 0.18f);
    glVertex2f(0.476f, 0.19f);
    glVertex2f(0.49f, 0.16f);
    glVertex2f(0.5f, 0.17f);
    glVertex2f(0.51f, 0.19f);
    glVertex2f(0.516f, 0.2f);
    glVertex2f(0.53f, 0.19f);
    glVertex2f(0.536f, 0.2f);
    glVertex2f(0.55f, 0.15);
    glVertex2f(0.556f, 0.16f);
    glVertex2f(0.57f, 0.18f);
    glVertex2f(0.576f, 0.19f);
    glVertex2f(0.59f, 0.16f);
    glVertex2f(0.6f, 0.17f);
    glVertex2f(0.71f, 0.19f);
    glVertex2f(0.716f, 0.2f);
    glVertex2f(0.65f, 0.15);
    glVertex2f(0.656f, 0.16f);
    glVertex2f(0.85f, 0.15);
    glVertex2f(0.856f, 0.16f);
    glVertex2f(0.89f, 0.15);
    glVertex2f(0.9f, 0.16f);
    glVertex2f(0.75f, 0.15);
    glVertex2f(0.756f, 0.16f);
    glVertex2f(0.77f, 0.18f);
    glVertex2f(0.776f, 0.19f);
    glVertex2f(0.79f, 0.16f);
    glVertex2f(0.8f, 0.17f);
    glVertex2f(0.91f, 0.19f);
    glVertex2f(0.916f, 0.2f);
    glVertex2f(0.93f, 0.19f);
    glVertex2f(0.936f, 0.2f);
    glVertex2f(0.95f, 0.15);
    glVertex2f(0.956f, 0.16f);
    glVertex2f(0.97f, 0.18f);
    glVertex2f(0.976f, 0.19f);
    glVertex2f(0.99f, 0.16f);
    glVertex2f(0.999f, 0.17f);

    glVertex2f(0.11f, 0.11f);
    glVertex2f(0.116f, 0.12f);
    glVertex2f(0.13f, 0.11f);
    glVertex2f(0.136f, 0.13f);
    glVertex2f(0.15f, 0.10);
    glVertex2f(0.156f, 0.11f);
    glVertex2f(0.17f, 0.11f);
    glVertex2f(0.176f, 0.12f);
    glVertex2f(0.19f, 0.12f);
    glVertex2f(0.2f, 0.13f);
    glVertex2f(0.21f, 0.08f);
    glVertex2f(0.216f, 0.09f);
    glVertex2f(0.23f, 0.10f);
    glVertex2f(0.236f, 0.11f);
    glVertex2f(0.25f, 0.12);
    glVertex2f(0.256f, 0.13f);
    glVertex2f(0.27f, 0.11f);
    glVertex2f(0.276f, 0.12f);
    glVertex2f(0.29f, 0.07f);
    glVertex2f(0.3f, 0.08f);
    glVertex2f(0.31f, 0.12f);
    glVertex2f(0.316f, 0.13f);
    glVertex2f(0.33f, 0.13f);
    glVertex2f(0.336f, 0.14f);
    glVertex2f(0.35f, 0.07);
    glVertex2f(0.356f, 0.08f);
    glVertex2f(0.37f, 0.10f);
    glVertex2f(0.376f, 0.11f);
    glVertex2f(0.39f, 0.06f);
    glVertex2f(0.4f, 0.07f);
    glVertex2f(0.41f, 0.09f);
    glVertex2f(0.416f, 0.10f);
    glVertex2f(0.43f, 0.11f);
    glVertex2f(0.436f, 0.12f);
    glVertex2f(0.45f, 0.05);
    glVertex2f(0.456f, 0.06f);
    glVertex2f(0.47f, 0.10f);
    glVertex2f(0.476f, 0.11f);
    glVertex2f(0.49f, 0.12f);
    glVertex2f(0.5f, 0.13f);
    glVertex2f(0.51f, 0.11f);
    glVertex2f(0.516f, 0.12f);
    glVertex2f(0.53f, 0.11f);
    glVertex2f(0.536f, 0.13f);
    glVertex2f(0.55f, 0.10);
    glVertex2f(0.556f, 0.11f);
    glVertex2f(0.57f, 0.11f);
    glVertex2f(0.576f, 0.12f);
    glVertex2f(0.59f, 0.12f);
    glVertex2f(0.6f, 0.13f);
    glVertex2f(0.61f, 0.08f);
    glVertex2f(0.616f, 0.09f);
    glVertex2f(0.63f, 0.10f);
    glVertex2f(0.636f, 0.11f);
    glVertex2f(0.65f, 0.12);
    glVertex2f(0.656f, 0.13f);
    glVertex2f(0.67f, 0.11f);
    glVertex2f(0.676f, 0.12f);
    glVertex2f(0.69f, 0.07f);
    glVertex2f(0.7f, 0.08f);
    glVertex2f(0.71f, 0.12f);
    glVertex2f(0.716f, 0.13f);
    glVertex2f(0.73f, 0.13f);
    glVertex2f(0.736f, 0.14f);
    glVertex2f(0.75f, 0.07);
    glVertex2f(0.756f, 0.08f);
    glVertex2f(0.77f, 0.10f);
    glVertex2f(0.776f, 0.11f);
    glVertex2f(0.79f, 0.06f);
    glVertex2f(0.8f, 0.07f);
    glVertex2f(0.81f, 0.09f);
    glVertex2f(0.816f, 0.10f);
    glVertex2f(0.83f, 0.11f);
    glVertex2f(0.836f, 0.12f);
    glVertex2f(0.85f, 0.05);
    glVertex2f(0.856f, 0.06f);
    glVertex2f(0.87f, 0.10f);
    glVertex2f(0.876f, 0.11f);
    glVertex2f(0.89f, 0.12f);
    glVertex2f(0.9f, 0.13f);
    glVertex2f(0.91f, 0.09f);
    glVertex2f(0.916f, 0.10f);
    glVertex2f(0.93f, 0.11f);
    glVertex2f(0.936f, 0.12f);
    glVertex2f(0.95f, 0.05);
    glVertex2f(0.956f, 0.06f);
    glVertex2f(0.97f, 0.10f);
    glVertex2f(0.976f, 0.11f);
    glVertex2f(0.99f, 0.12f);
    glVertex2f(0.999f, 0.13f); ////////////main/////////////*****************

    glVertex2f(0.01f, 0.42f);
    glVertex2f(0.016f, 0.43f);
    glVertex2f(0.03f, 0.43f);
    glVertex2f(0.036f, 0.44f);
    glVertex2f(0.05f, 0.37);
    glVertex2f(0.056f, 0.38f);
    glVertex2f(0.07f, 0.4f);
    glVertex2f(0.076f, 0.41f);
    glVertex2f(0.09f, 0.36f);
    glVertex2f(0.1f, 0.37f);
    glVertex2f(0.11f, 0.42f);
    glVertex2f(0.116f, 0.43f);
    glVertex2f(0.13f, 0.43f);
    glVertex2f(0.136f, 0.44f);
    glVertex2f(0.15f, 0.37f);
    glVertex2f(0.156f, 0.38f);
    glVertex2f(0.17f, 0.4f);
    glVertex2f(0.176f, 0.41f);
    glVertex2f(0.19f, 0.36f);
    glVertex2f(0.2f, 0.37f);
    glVertex2f(0.25f, 0.37);
    glVertex2f(0.256f, 0.38f);
    glVertex2f(0.27f, 0.4f);
    glVertex2f(0.276f, 0.41f);
    glVertex2f(0.29f, 0.36f);
    glVertex2f(0.3f, 0.37f);

    glVertex2f(0.51f, 0.42f);
    glVertex2f(0.516f, 0.43f);
    glVertex2f(0.53f, 0.43f);
    glVertex2f(0.536f, 0.44f);
    glVertex2f(0.55f, 0.37);
    glVertex2f(0.556f, 0.38f);
    glVertex2f(0.57f, 0.4f);
    glVertex2f(0.576f, 0.41f);
    glVertex2f(0.59f, 0.36f);
    glVertex2f(0.6f, 0.37f);
    glVertex2f(0.61f, 0.42f);
    glVertex2f(0.616f, 0.43f);
    glVertex2f(0.63f, 0.43f);
    glVertex2f(0.636f, 0.44f);
    glVertex2f(0.65f, 0.37);
    glVertex2f(0.656f, 0.38f);
    glVertex2f(0.67f, 0.4f);
    glVertex2f(0.676f, 0.41f);
    glVertex2f(0.69f, 0.36f);
    glVertex2f(0.7f, 0.37f);
    glVertex2f(0.71f, 0.42f);
    glVertex2f(0.716f, 0.43f);
    glVertex2f(0.73f, 0.43f);
    glVertex2f(0.736f, 0.44f);
    glVertex2f(0.75f, 0.37);
    glVertex2f(0.756f, 0.38f);
    glVertex2f(0.77f, 0.4f);
    glVertex2f(0.776f, 0.41f);
    glVertex2f(0.79f, 0.36f);
    glVertex2f(0.8f, 0.37f);
    glVertex2f(0.81f, 0.39f);
    glVertex2f(0.816f, 0.4f);
    glVertex2f(0.83f, 0.41f);
    glVertex2f(0.836f, 0.42f);
    glVertex2f(0.85f, 0.35);
    glVertex2f(0.856f, 0.36f);
    glVertex2f(0.87f, 0.4f);
    glVertex2f(0.876f, 0.41f);
    glVertex2f(0.89f, 0.42f);
    glVertex2f(0.9f, 0.43f);
    glVertex2f(0.91f, 0.39f);
    glVertex2f(0.916f, 0.4f);
    glVertex2f(0.93f, 0.41f);
    glVertex2f(0.936f, 0.42f);
    glVertex2f(0.95f, 0.35);
    glVertex2f(0.956f, 0.36f);
    glVertex2f(0.97f, 0.4f);
    glVertex2f(0.976f, 0.41f);
    glVertex2f(0.99f, 0.42f);
    glVertex2f(0.999f, 0.43f); /////

    glVertex2f(0.01f, 0.46f);
    glVertex2f(0.016f, 0.47f);
    glVertex2f(0.03f, 0.46f);
    glVertex2f(0.036f, 0.47f);
    glVertex2f(0.05f, 0.43);
    glVertex2f(0.056f, 0.44f);
    glVertex2f(0.07f, 0.43f);
    glVertex2f(0.076f, 0.44f);
    glVertex2f(0.09f, 0.39f);
    glVertex2f(0.1f, 0.4f);
    glVertex2f(0.01f, 0.5f);
    glVertex2f(0.016f, 0.51f);
    glVertex2f(0.03f, 0.55f);
    glVertex2f(0.036f, 0.56f);
    glVertex2f(0.05f, 0.46);
    glVertex2f(0.056f, 0.47f);
    glVertex2f(0.07f, 0.45f);
    glVertex2f(0.076f, 0.46f);
    glVertex2f(0.09f, 0.47f);
    glVertex2f(0.1f, 0.48f);
    glVertex2f(0.01f, 0.59f);
    glVertex2f(0.016f, 0.6f);
    glVertex2f(0.03f, 0.57f);
    glVertex2f(0.036f, 0.58f);
    glVertex2f(0.05f, 0.65f);
    glVertex2f(0.056f, 0.66f);
    glVertex2f(0.07f, 0.69f);
    glVertex2f(0.076f, 0.7f);
    glVertex2f(0.09f, 0.71f);
    glVertex2f(0.1f, 0.72f);
    glVertex2f(0.01f, 0.84f);
    glVertex2f(0.016f, 0.85f);
    glVertex2f(0.03f, 0.79f);
    glVertex2f(0.036f, 0.8f);
    glVertex2f(0.05f, 0.82);
    glVertex2f(0.056f, 0.83f);
    glVertex2f(0.07f, 0.87f);
    glVertex2f(0.076f, 0.88f);
    glVertex2f(0.09f, 0.83f);
    glVertex2f(0.1f, 0.84f);

    glVertex2f(0.11f, 0.84f);
    glVertex2f(0.116f, 0.85f);
    glVertex2f(0.13f, 0.79f);
    glVertex2f(0.136f, 0.8f);
    glVertex2f(0.15f, 0.82);
    glVertex2f(0.156f, 0.83f);
    glVertex2f(0.17f, 0.87f);
    glVertex2f(0.176f, 0.88f);
    glVertex2f(0.19f, 0.83f);
    glVertex2f(0.2f, 0.84f);
    glVertex2f(0.21f, 0.84f);
    glVertex2f(0.216f, 0.85f);
    glVertex2f(0.23f, 0.8f);
    glVertex2f(0.236f, 0.79f);
    glVertex2f(0.25f, 0.83);
    glVertex2f(0.256f, 0.82f);
    glVertex2f(0.27f, 0.88f);
    glVertex2f(0.276f, 0.87f);
    glVertex2f(0.29f, 0.84f);
    glVertex2f(0.3f, 0.83f);
    glVertex2f(0.31f, 0.85f);
    glVertex2f(0.316f, 0.84f);
    glVertex2f(0.33f, 0.8f);
    glVertex2f(0.336f, 0.79f);
    glVertex2f(0.35f, 0.83);
    glVertex2f(0.356f, 0.82f);
    glVertex2f(0.37f, 0.88f);
    glVertex2f(0.376f, 0.87f);
    glVertex2f(0.39f, 0.84f);
    glVertex2f(0.4f, 0.83f);
    glVertex2f(0.41f, 0.85f);
    glVertex2f(0.416f, 0.84f);
    glVertex2f(0.43f, 0.78f);
    glVertex2f(0.436f, 0.8f);
    glVertex2f(0.45f, 0.82);
    glVertex2f(0.456f, 0.83f);
    glVertex2f(0.47f, 0.87f);
    glVertex2f(0.476f, 0.88f);
    glVertex2f(0.51f, 0.84f);
    glVertex2f(0.516f, 0.85f);
    glVertex2f(0.53f, 0.79f);
    glVertex2f(0.536f, 0.8f);
    glVertex2f(0.55f, 0.82);
    glVertex2f(0.556f, 0.83f);
    glVertex2f(0.57f, 0.87f);
    glVertex2f(0.576f, 0.88f);
    glVertex2f(0.59f, 0.83f);
    glVertex2f(0.6f, 0.84f);
    glVertex2f(0.71f, 0.84f);
    glVertex2f(0.716f, 0.85f);
    glVertex2f(0.73f, 0.79f);
    glVertex2f(0.736f, 0.8f);
    glVertex2f(0.75f, 0.82);
    glVertex2f(0.756f, 0.83f);
    glVertex2f(0.77f, 0.87f);
    glVertex2f(0.776f, 0.88f);
    glVertex2f(0.79f, 0.83f);
    glVertex2f(0.8f, 0.84f);
    glVertex2f(0.91f, 0.84f);
    glVertex2f(0.916f, 0.85f);
    glVertex2f(0.93f, 0.79f);
    glVertex2f(0.936f, 0.8f);
    glVertex2f(0.95f, 0.82);
    glVertex2f(0.956f, 0.83f);
    glVertex2f(0.97f, 0.87f);
    glVertex2f(0.976f, 0.88f);
    glVertex2f(0.99f, 0.83f);
    glVertex2f(0.999f, 0.84f);

    glVertex2f(0.01f, 0.88f);
    glVertex2f(0.016f, 0.89f);
    glVertex2f(0.03f, 0.89f);
    glVertex2f(0.036f, 0.9f);
    glVertex2f(0.05f, 0.92);
    glVertex2f(0.056f, 0.93f);
    glVertex2f(0.07f, 0.97f);
    glVertex2f(0.076f, 0.98f);
    glVertex2f(0.09f, 0.93f);
    glVertex2f(0.1f, 0.94f);
    glVertex2f(0.11f, 0.88f);
    glVertex2f(0.116f, 0.89f);
    glVertex2f(0.13f, 0.89f);
    glVertex2f(0.136f, 0.9f);
    glVertex2f(0.15f, 0.92);
    glVertex2f(0.156f, 0.93f);
    glVertex2f(0.17f, 0.97f);
    glVertex2f(0.176f, 0.98f);
    glVertex2f(0.19f, 0.93f);
    glVertex2f(0.2f, 0.94f);
    glVertex2f(0.21f, 0.88f);
    glVertex2f(0.216f, 0.89f);
    glVertex2f(0.23f, 0.89f);
    glVertex2f(0.236f, 0.9f);
    glVertex2f(0.25f, 0.92);
    glVertex2f(0.256f, 0.93f);
    glVertex2f(0.27f, 0.97f);
    glVertex2f(0.276f, 0.98f);
    glVertex2f(0.29f, 0.93f);
    glVertex2f(0.3f, 0.94f);
    glVertex2f(0.31f, 0.88f);
    glVertex2f(0.316f, 0.89f);
    glVertex2f(0.33f, 0.89f);
    glVertex2f(0.336f, 0.9f);
    glVertex2f(0.35f, 0.92);
    glVertex2f(0.356f, 0.93f);
    glVertex2f(0.37f, 0.97f);
    glVertex2f(0.376f, 0.98f);
    glVertex2f(0.39f, 0.93f);
    glVertex2f(0.4f, 0.94f);
    glVertex2f(0.41f, 0.88f);
    glVertex2f(0.416f, 0.89f);
    glVertex2f(0.43f, 0.89f);
    glVertex2f(0.436f, 0.9f);
    glVertex2f(0.45f, 0.92);
    glVertex2f(0.456f, 0.93f);
    glVertex2f(0.47f, 0.97f);
    glVertex2f(0.476f, 0.98f);
    glVertex2f(0.49f, 0.93f);
    glVertex2f(0.5f, 0.94f);
    glVertex2f(0.51f, 0.88f);
    glVertex2f(0.516f, 0.89f);
    glVertex2f(0.53f, 0.89f);
    glVertex2f(0.536f, 0.9f);
    glVertex2f(0.55f, 0.92);
    glVertex2f(0.556f, 0.93f);
    glVertex2f(0.57f, 0.97f);
    glVertex2f(0.576f, 0.98f);
    glVertex2f(0.59f, 0.93f);
    glVertex2f(0.6f, 0.94f);
    glVertex2f(0.61f, 0.88f);
    glVertex2f(0.616f, 0.89f);
    glVertex2f(0.63f, 0.89f);
    glVertex2f(0.636f, 0.9f);
    glVertex2f(0.65f, 0.92);
    glVertex2f(0.656f, 0.93f);
    glVertex2f(0.67f, 0.97f);
    glVertex2f(0.676f, 0.98f);
    glVertex2f(0.69f, 0.93f);
    glVertex2f(0.7f, 0.94f);
    glVertex2f(0.71f, 0.88f);
    glVertex2f(0.716f, 0.89f);
    glVertex2f(0.73f, 0.89f);
    glVertex2f(0.736f, 0.9f);
    glVertex2f(0.75f, 0.92);
    glVertex2f(0.756f, 0.93f);
    glVertex2f(0.77f, 0.97f);
    glVertex2f(0.776f, 0.98f);
    glVertex2f(0.79f, 0.93f);
    glVertex2f(0.8f, 0.94f);
    glVertex2f(0.81f, 0.88f);
    glVertex2f(0.816f, 0.89f);
    glVertex2f(0.83f, 0.89f);
    glVertex2f(0.836f, 0.9f);
    glVertex2f(0.85f, 0.92);
    glVertex2f(0.856f, 0.93f);
    glVertex2f(0.87f, 0.97f);
    glVertex2f(0.876f, 0.98f);
    glVertex2f(0.89f, 0.93f);
    glVertex2f(0.9f, 0.94f);

    glVertex2f(0.01f, 0.08f);
    glVertex2f(0.016f, 0.09f);
    glVertex2f(0.03f, 0.09f);
    glVertex2f(0.036f, 0.1f);
    glVertex2f(0.05f, 0.12);
    glVertex2f(0.056f, 0.13f);
    glVertex2f(0.07f, 0.17f);
    glVertex2f(0.076f, 0.18f);

    glVertex2f(0.01f, 0.01f);
    glVertex2f(0.016f, 0.02f);
    glVertex2f(0.03f, 0.04f);
    glVertex2f(0.036f, 0.05f);
    glVertex2f(0.05f, 0.02);
    glVertex2f(0.056f, 0.03f);
    glVertex2f(0.07f, 0.06f);
    glVertex2f(0.076f, 0.07f);
    glVertex2f(0.1f, 0.01f);
    glVertex2f(0.116f, 0.02f);
    glVertex2f(0.13f, 0.04f);
    glVertex2f(0.136f, 0.05f);
    glVertex2f(0.15f, 0.02);
    glVertex2f(0.156f, 0.03f);
    glVertex2f(0.17f, 0.06f);
    glVertex2f(0.176f, 0.07f);
    glVertex2f(0.21f, 0.01f);
    glVertex2f(0.216f, 0.02f);
    glVertex2f(0.33f, 0.04f);
    glVertex2f(0.336f, 0.05f);
    glVertex2f(0.35f, 0.02);
    glVertex2f(0.356f, 0.03f);
    glVertex2f(0.37f, 0.06f);
    glVertex2f(0.376f, 0.07f);
    glVertex2f(0.41f, 0.01f);
    glVertex2f(0.416f, 0.02f);
    glVertex2f(0.43f, 0.04f);
    glVertex2f(0.436f, 0.05f);
    glVertex2f(0.5f, 0.02);
    glVertex2f(0.516f, 0.03f);
    glVertex2f(0.57f, 0.06f);
    glVertex2f(0.576f, 0.07f);

    glVertex2f(0.01f, 0.11f);
    glVertex2f(0.016f, 0.12f);
    glVertex2f(0.03f, 0.14f);
    glVertex2f(0.036f, 0.15f);
    glVertex2f(0.05f, 0.12);
    glVertex2f(0.056f, 0.13f);
    glVertex2f(0.07f, 0.16f);
    glVertex2f(0.076f, 0.17f);

    glVertex2f(0.01f, 0.31f);
    glVertex2f(0.016f, 0.32f);
    glVertex2f(0.03f, 0.34f);
    glVertex2f(0.036f, 0.35f);
    glVertex2f(0.05f, 0.32);
    glVertex2f(0.056f, 0.33f);
    glVertex2f(0.07f, 0.36f);
    glVertex2f(0.076f, 0.37f);

    glVertex2f(0.01f, 0.21f);
    glVertex2f(0.016f, 0.22f);
    glVertex2f(0.03f, 0.24f);
    glVertex2f(0.036f, 0.25f);
    glVertex2f(0.05f, 0.22);
    glVertex2f(0.056f, 0.23f);
    glVertex2f(0.07f, 0.26f);
    glVertex2f(0.076f, 0.27f);

    glVertex2f(0.01f, 0.71f);
    glVertex2f(0.016f, 0.72f);
    glVertex2f(0.03f, 0.74f);
    glVertex2f(0.036f, 0.75f);
    glVertex2f(0.05f, 0.72);
    glVertex2f(0.056f, 0.73f);
    glVertex2f(0.07f, 0.76f);
    glVertex2f(0.076f, 0.77f);
    glVertex2f(0.11f, 0.71f);
    glVertex2f(0.116f, 0.72f);
    glVertex2f(0.13f, 0.74f);
    glVertex2f(0.136f, 0.75f);
    glVertex2f(0.15f, 0.72);
    glVertex2f(0.156f, 0.73f);
    glVertex2f(0.17f, 0.76f);
    glVertex2f(0.176f, 0.77f);
    glVertex2f(0.21f, 0.71f);
    glVertex2f(0.216f, 0.72f);
    glVertex2f(0.23f, 0.74f);
    glVertex2f(0.236f, 0.75f);
    glVertex2f(0.25f, 0.72);
    glVertex2f(0.256f, 0.73f);
    glVertex2f(0.27f, 0.76f);
    glVertex2f(0.276f, 0.77f);
    glVertex2f(0.41f, 0.71f);
    glVertex2f(0.416f, 0.72f);
    glVertex2f(0.43f, 0.74f);
    glVertex2f(0.436f, 0.75f);
    glVertex2f(0.45f, 0.72);
    glVertex2f(0.456f, 0.73f);
    glVertex2f(0.47f, 0.76f);
    glVertex2f(0.476f, 0.77f);
    glVertex2f(0.51f, 0.71f);
    glVertex2f(0.516f, 0.72f);
    glVertex2f(0.55f, 0.72);
    glVertex2f(0.56f, 0.73f);
    glVertex2f(0.57f, 0.76f);
    glVertex2f(0.576f, 0.77f);
    glVertex2f(0.71f, 0.71f);
    glVertex2f(0.716f, 0.72f);
    glVertex2f(0.73f, 0.74f);
    glVertex2f(0.736f, 0.75f);
    glVertex2f(0.75f, 0.72);
    glVertex2f(0.756f, 0.73f);
    glVertex2f(0.77f, 0.76f);
    glVertex2f(0.776f, 0.77f);
    glVertex2f(0.91f, 0.71f);
    glVertex2f(0.916f, 0.72f);
    glVertex2f(0.93f, 0.74f);
    glVertex2f(0.936f, 0.75f);
    glVertex2f(0.95f, 0.72);
    glVertex2f(0.956f, 0.73f);
    glVertex2f(0.97f, 0.76f);
    glVertex2f(0.976f, 0.77f);

    glVertex2f(0.99f, 0.67f);
    glVertex2f(0.999f, 0.68f);

    glVertex2f(0.99f, 0.63f);
    glVertex2f(0.999f, 0.64f);
    glVertex2f(0.95f, 0.62f);
    glVertex2f(0.956f, 0.63f);

    glVertex2f(0.99f, 0.55f);
    glVertex2f(0.999f, 0.56f);

    glVertex2f(0.99f, 0.48f);
    glVertex2f(0.999f, 0.49f);
    glVertex2f(0.97f, 0.48f);
    glVertex2f(0.976f, 0.49f);
    glVertex2f(0.95f, 0.44f);
    glVertex2f(0.956f, 0.45f);
    glVertex2f(0.93f, 0.48f);
    glVertex2f(0.936f, 0.49f);
    glVertex2f(0.91f, 0.48f);
    glVertex2f(0.916f, 0.49f);

    glVertex2f(0.89f, 0.48f);
    glVertex2f(0.899f, 0.49f);
    glVertex2f(0.87f, 0.48f);
    glVertex2f(0.876f, 0.49f);
    glVertex2f(0.85f, 0.44f);
    glVertex2f(0.856f, 0.45f);
    glVertex2f(0.83f, 0.48f);
    glVertex2f(0.836f, 0.49f);
    glVertex2f(0.81f, 0.46f);
    glVertex2f(0.816f, 0.47f);

    glVertex2f(0.89f, 0.02f);
    glVertex2f(0.899f, 0.03f);
    glVertex2f(0.87f, 0.02f);
    glVertex2f(0.876f, 0.03f);
    glVertex2f(0.85f, 0.02f);
    glVertex2f(0.856f, 0.03f);
    glVertex2f(0.83f, 0.03f);
    glVertex2f(0.836f, 0.04f);
    glVertex2f(0.81f, 0.03f);
    glVertex2f(0.816f, 0.04f);

    glVertex2f(0.79f, 0.02f);
    glVertex2f(0.799f, 0.03f);
    glVertex2f(0.77f, 0.02f);
    glVertex2f(0.776f, 0.03f);
    glVertex2f(0.75f, 0.02f);
    glVertex2f(0.756f, 0.03f);
    glVertex2f(0.73f, 0.04f);
    glVertex2f(0.736f, 0.05f);
    glVertex2f(0.71f, 0.02f);
    glVertex2f(0.716f, 0.03f);

    glVertex2f(0.59f, 0.02f);
    glVertex2f(0.599f, 0.03f);
    glVertex2f(0.57f, 0.02f);
    glVertex2f(0.576f, 0.03f);
    glVertex2f(0.55f, 0.02f);
    glVertex2f(0.556f, 0.03f);
    glVertex2f(0.53f, 0.02f);
    glVertex2f(0.536f, 0.03f);

    glVertex2f(0.69f, 0.03f);
    glVertex2f(0.699f, 0.04f);
    glVertex2f(0.67f, 0.02f);
    glVertex2f(0.676f, 0.03f);
    glVertex2f(0.65f, 0.05f);
    glVertex2f(0.656f, 0.06f);
    glVertex2f(0.63f, 0.02f);
    glVertex2f(0.636f, 0.03f);
    glVertex2f(0.61f, 0.06f);
    glVertex2f(0.616f, 0.07f);

    glVertex2f(0.39f, 0.03f);
    glVertex2f(0.399f, 0.04f);
    glVertex2f(0.37f, 0.02f);
    glVertex2f(0.376f, 0.03f);
    glVertex2f(0.35f, 0.05f);
    glVertex2f(0.356f, 0.06f);
    glVertex2f(0.33f, 0.02f);
    glVertex2f(0.336f, 0.03f);
    glVertex2f(0.31f, 0.02f);
    glVertex2f(0.316f, 0.03f);

    glVertex2f(0.29f, 0.03f);
    glVertex2f(0.299f, 0.04f);
    glVertex2f(0.27f, 0.02f);
    glVertex2f(0.276f, 0.03f);
    glVertex2f(0.25f, 0.05f);
    glVertex2f(0.256f, 0.06f);
    glVertex2f(0.23f, 0.02f);
    glVertex2f(0.236f, 0.03f);
    glVertex2f(0.21f, 0.02f);
    glVertex2f(0.216f, 0.03f); ////////////////////////XXYY////////

    glVertex2f(-0.75f, 0.75f);
    glVertex2f(-0.756f, 0.74f);
    glVertex2f(-0.82f, 0.75f);
    glVertex2f(-0.826f, 0.74f);
    glEnd();
    glPopMatrix();
}

void boat1()        // Boat
{
    /**.......................................Boat 1 ..........................................**/

    glPushMatrix();
    glTranslated(position_boat1x, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.463, 0.486, 0.502);
    glVertex2f(-0.38f, 0.76f);
    glVertex2f(-0.16f, 0.76f);
    glVertex2f(-0.19f, 0.747f);
    glVertex2f(-0.35f, 0.747f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1, 0.969, 0.49);
    glVertex2f(-0.26f, 0.83f);
    glVertex2f(-0.33f, 0.77f);
    glVertex2f(-0.26f, 0.77f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.988f, 0.961f, 0.149f);
    glVertex2f(-0.26f, 0.86f);
    glVertex2f(-0.22f, 0.77f);
    glVertex2f(-0.26f, 0.76f);

    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.26f, 0.84f);
    glVertex2f(-0.26f, 0.76f);

    glEnd();
    glPopMatrix();
}

void boat2()        // Boat2
{
    /**.......................................Boat 2 ..........................................**/

    glPushMatrix();
    glTranslated(position_boat2x, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.525, 0.286, 0.282);
    glVertex2f(0.6f, 0.71f);
    glVertex2f(0.36f, 0.71f);
    glVertex2f(0.39f, 0.69f);
    glVertex2f(0.57f, 0.69f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.961, 0.58, 0.122);
    glVertex2f(0.48f, 0.78f);
    glVertex2f(0.56f, 0.72f);
    glVertex2f(0.48f, 0.72f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.961, 0.58, 0.122);
    glVertex2f(0.48f, 0.82f);
    glVertex2f(0.44f, 0.72f);
    glVertex2f(0.48f, 0.71f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.48f, 0.79f);
    glVertex2f(0.48f, 0.71f);

    glEnd();
    glPopMatrix();
}

void flowerStructure()  // Flower -fl099
{
    /// Bushes 1
    glPushMatrix();
    glScalef(0.4f, 0.4f, 0.0f);
    glTranslatef(0.5f, 0.0f, 0.0f);
    GLfloat x = 0.9f;
    GLfloat y = 0.0f;
    GLfloat radius = .1f;
    int triangleAmount = 100; /// # of lines used to draw circle
    GLfloat twicePi = 2.0f * PI;
    glColor3f(0.373, 0.69, 0.349);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = 0.7f;
    y = 0.0f;
    radius = .15f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.161, 0.541, 0.137);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = 0.6f;
    y = 0.0f;
    radius = .07f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.373, 0.69, 0.349);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = 0.7f;
    y = 0.003f;
    radius = .05f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.373, 0.6, 0.349);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    x = 0.5f;
    y = 0.0f;
    radius = .07f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.373, 0.69, 0.349);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    glPopMatrix();
    /// Bushes 3
    glPushMatrix();
    glScalef(0.4f, 0.4f, 0.0f);
    glTranslatef(1.4f, 0.0f, 0.0f);
    x = 0.9f;
    y = 0.0f;
    radius = .1f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.373, 0.69, 0.349);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = 0.7f;
    y = 0.0f;
    radius = .15f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.161, 0.541, 0.137);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = 0.6f;
    y = 0.0f;
    radius = .07f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.373, 0.69, 0.349);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = 0.7f;
    y = 0.003f;
    radius = .05f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.373, 0.6, 0.349);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    x = 0.5f;
    y = 0.0f;
    radius = .07f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.373, 0.69, 0.349);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    glPopMatrix();

    /// Bushes 2
    glPushMatrix();
    glScalef(0.4f, 0.4f, 0.0f);
    glTranslatef(0.9f, 0.0f, 0.0f);
    x = 0.9f;
    y = 0.0f;
    radius = .1f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.373, 0.69, 0.349);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = 0.7f;
    y = 0.0f;
    radius = .15f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.161, 0.541, 0.137);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = 0.6f;
    y = 0.0f;
    radius = .07f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.373, 0.69, 0.349);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = 0.7f;
    y = 0.003f;
    radius = .05f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.373, 0.6, 0.349);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    x = 0.5f;
    y = 0.0f;
    radius = .07f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.373, 0.69, 0.349);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    glPopMatrix();

    /// --------------------Flower 1-------------------
    glPushMatrix();
    glTranslatef(+0.3f, 0.0f, 0.0f);
    glScalef(0.76f, 0.76f, 0.0f);
    glPushMatrix();
    glScalef(0.6f, 0.6f, 0.0f);
    glTranslatef(0.3f, 0.0f, 0.0f);
    /// leaves
    glBegin(GL_POLYGON);
    glColor3f(0.047, 0.38, 0);
    glVertex2f(0.9f, 0.0f);
    glVertex2f(0.925f, 0.0f);
    glVertex2f(0.85f, 0.125f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.047, 0.38, 0);
    glVertex2f(0.925f, 0.0f);
    glVertex2f(0.95f, 0.0f);
    glVertex2f(1.0f, 0.125f);
    glEnd();
    /// Stem
    glBegin(GL_LINES);
    glColor3f(0.0, 0., 0.0);
    glVertex2f(0.925f, 0.0f);
    glVertex2f(0.925f, 0.15f);
    glEnd();
    /// Papri
    x = 0.950f;
    y = 0.15f;
    radius = 0.03f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.651, 0.643, 0.133);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    x = 0.925f;
    y = 0.125f;
    radius = 0.03f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.651, 0.643, 0.133);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    x = 0.9f;
    y = 0.15f;
    radius = 0.03f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.651, 0.643, 0.133);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    x = 0.925f;
    y = 0.175f;
    radius = .03f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.651, 0.643, 0.133);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = 0.925f;
    y = 0.15f;
    radius = .02f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glPopMatrix();
    /// --------------------Flower 2-------------------
    /// leaves
    glTranslatef(-0.2f, 0.0f, 0.0f);
    glScalef(0.8f, 0.8f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.047, 0.38, 0);
    glVertex2f(0.9f, 0.0f);
    glVertex2f(0.925f, 0.0f);
    glVertex2f(0.85f, 0.125f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.047, 0.38, 0);
    glVertex2f(0.925f, 0.0f);
    glVertex2f(0.95f, 0.0f);
    glVertex2f(1.0f, 0.125f);
    glEnd();
    /// Stem
    glBegin(GL_LINES);
    glColor3f(0.0, 0., 0.0);
    glVertex2f(0.925f, 0.0f);
    glVertex2f(0.925f, 0.15f);
    glEnd();
    /// Papri
    x = 0.950f;
    y = 0.15f;
    radius = 0.03f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.651, 0.643, 0.133);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    x = 0.925f;
    y = 0.125f;
    radius = 0.03f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.651, 0.643, 0.133);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    x = 0.9f;
    y = 0.15f;
    radius = 0.03f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.651, 0.643, 0.133);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    x = 0.925f;
    y = 0.175f;
    radius = .03f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.651, 0.643, 0.133);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = 0.925f;
    y = 0.15f;
    radius = .02f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    /// --------------------Flower 3-------------------
    glTranslatef(-0.2f, 0.0f, 0.0f);
    glScalef(0.8f, 0.8f, 0.0f);
    /// leaves
    glBegin(GL_POLYGON);
    glColor3f(0.047, 0.38, 0);
    glVertex2f(0.9f, 0.0f);
    glVertex2f(0.925f, 0.0f);
    glVertex2f(0.85f, 0.125f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.047, 0.38, 0);
    glVertex2f(0.925f, 0.0f);
    glVertex2f(0.95f, 0.0f);
    glVertex2f(1.0f, 0.125f);
    glEnd();
    /// Stem
    glBegin(GL_LINES);
    glColor3f(0.0, 0., 0.0);
    glVertex2f(0.925f, 0.0f);
    glVertex2f(0.925f, 0.15f);
    glEnd();
    /// Papri
    x = 0.950f;
    y = 0.15f;
    radius = 0.03f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.651, 0.643, 0.133);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    x = 0.925f;
    y = 0.125f;
    radius = 0.03f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.651, 0.643, 0.133);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    x = 0.9f;
    y = 0.15f;
    radius = 0.03f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.651, 0.643, 0.133);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    x = 0.925f;
    y = 0.175f;
    radius = .03f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.651, 0.643, 0.133);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = 0.925f;
    y = 0.15f;
    radius = .02f;
    triangleAmount = 100; /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glPopMatrix();
}

void flower()     // flower
{
    glPushMatrix();
    glTranslatef(0.1f, -0.001f, 0.0f);
    flowerStructure();
    glTranslatef(-0.25f, -0.001f, 0.0f);
    flowerStructure();
    glTranslatef(-0.4f, -0.001f, 0.0f);
    flowerStructure();
    glTranslatef(-0.4f, -0.001f, 0.0f);
    flowerStructure();
    glTranslatef(-0.27f, -0.001f, 0.0f);
    flowerStructure();
    glTranslatef(-0.4f, -0.001f, 0.0f);
    flowerStructure();
    glTranslatef(-0.65f, -0.001f, 0.0f);
    flowerStructure();
    glTranslatef(-0.2f, -0.001f, 0.0f);
    flowerStructure();
    glPopMatrix();
}

void tree_flower()      // TF
{
    ///..........................Left Tree Flower.....................
    /// Big tree flower........
    /// 1st Leaf..............
    GLfloat x = 0.644f;
    GLfloat y = 0.532f;
    GLfloat radius = .012f;
    int triangleAmount = 100;
    GLfloat twicePi = 2.0f * PI;
    glColor3f(0.847, 0.675, 0.702);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// 2nd Leaf..............
    x = 0.664f;
    y = 0.532f;
    radius = .012f;
    triangleAmount = 100;
    twicePi = 2.0f * PI;
    glColor3f(0.847, 0.675, 0.702);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// 3nd Leaf..............
    x = 0.654f;
    y = 0.522f;
    radius = .012f;
    triangleAmount = 100;
    twicePi = 2.0f * PI;
    glColor3f(0.847, 0.675, 0.702);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// 4th Leaf..............
    x = 0.654f;
    y = 0.542f;
    radius = .012f;
    triangleAmount = 100;
    twicePi = 2.0f * PI;
    glColor3f(0.847, 0.675, 0.702);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// Flower central black portion......
    x = 0.654f;
    y = 0.532f;
    radius = .01f;
    triangleAmount = 100;
    twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    ///...........................................
    glPushMatrix();
    glTranslated(0.06f, 0.0f, 0.0f);
    /// 1st Leaf..............
    x = 0.644f;
    y = 0.532f;
    radius = .012f;
    triangleAmount = 100;
    twicePi = 2.0f * PI;
    glColor3f(0.847, 0.675, 0.702);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// 2nd Leaf..............
    x = 0.664f;
    y = 0.532f;
    radius = .012f;
    triangleAmount = 100;
    twicePi = 2.0f * PI;
    glColor3f(0.847, 0.675, 0.702);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// 3nd Leaf..............
    x = 0.654f;
    y = 0.522f;
    radius = .012f;
    triangleAmount = 100;
    twicePi = 2.0f * PI;
    glColor3f(0.847, 0.675, 0.702);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// 4th Leaf..............
    x = 0.654f;
    y = 0.542f;
    radius = .012f;
    triangleAmount = 100;
    twicePi = 2.0f * PI;
    glColor3f(0.847, 0.675, 0.702);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// Flower central black portion......
    x = 0.654f;
    y = 0.532f;
    radius = .01f;
    triangleAmount = 100;
    twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glPopMatrix();
    ///.............................

    ///...........................................
    glPushMatrix();
    glTranslated(0.03f, 0.06f, 0.0f);
    /// 1st Leaf..............
    x = 0.644f;
    y = 0.532f;
    radius = .012f;
    triangleAmount = 100;
    twicePi = 2.0f * PI;
    glColor3f(0.847, 0.675, 0.702);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// 2nd Leaf..............
    x = 0.664f;
    y = 0.532f;
    radius = .012f;
    triangleAmount = 100;
    twicePi = 2.0f * PI;
    glColor3f(0.847, 0.675, 0.702);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// 3nd Leaf..............
    x = 0.654f;
    y = 0.522f;
    radius = .012f;
    triangleAmount = 100;
    twicePi = 2.0f * PI;
    glColor3f(0.847, 0.675, 0.702);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// 4th Leaf..............
    x = 0.654f;
    y = 0.542f;
    radius = .012f;
    triangleAmount = 100;
    twicePi = 2.0f * PI;
    glColor3f(0.847, 0.675, 0.702);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// Flower central black portion......
    x = 0.654f;
    y = 0.532f;
    radius = .01f;
    triangleAmount = 100;
    twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glPopMatrix();
    ///.........................
    ///...........................................
    glPushMatrix();
    glTranslated(0.03f, -0.06f, 0.0f);
    /// 1st Leaf..............
    x = 0.644f;
    y = 0.532f;
    radius = .012f;
    triangleAmount = 100;
    twicePi = 2.0f * PI;
    glColor3f(0.847, 0.675, 0.702);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// 2nd Leaf..............
    x = 0.664f;
    y = 0.532f;
    radius = .012f;
    triangleAmount = 100;
    twicePi = 2.0f * PI;
    glColor3f(0.847, 0.675, 0.702);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// 3nd Leaf..............
    x = 0.654f;
    y = 0.522f;
    radius = .012f;
    triangleAmount = 100;
    twicePi = 2.0f * PI;
    glColor3f(0.847, 0.675, 0.702);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// 4th Leaf..............
    x = 0.654f;
    y = 0.542f;
    radius = .012f;
    triangleAmount = 100;
    twicePi = 2.0f * PI;
    glColor3f(0.847, 0.675, 0.702);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// Flower central black portion......
    x = 0.654f;
    y = 0.532f;
    radius = .01f;
    triangleAmount = 100;
    twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glPopMatrix();
    ///...................
    ///...........................................
    glPushMatrix();
    glTranslated(0.14f, 0.01f, 0.0f);
    /// 1st Leaf..............
    x = 0.644f;
    y = 0.532f;
    radius = .012f;
    triangleAmount = 100;
    twicePi = 2.0f * PI;
    glColor3f(0.847, 0.675, 0.702);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// 2nd Leaf..............
    x = 0.664f;
    y = 0.532f;
    radius = .012f;
    triangleAmount = 100;
    twicePi = 2.0f * PI;
    glColor3f(0.847, 0.675, 0.702);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// 3nd Leaf..............
    x = 0.654f;
    y = 0.522f;
    radius = .012f;
    triangleAmount = 100;
    twicePi = 2.0f * PI;
    glColor3f(0.847, 0.675, 0.702);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// 4th Leaf..............
    x = 0.654f;
    y = 0.542f;
    radius = .012f;
    triangleAmount = 100;
    twicePi = 2.0f * PI;
    glColor3f(0.847, 0.675, 0.702);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// Flower central black portion......
    x = 0.654f;
    y = 0.532f;
    radius = .01f;
    triangleAmount = 100;
    twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glPopMatrix();

    ///......................................
    ///...........................................
    glPushMatrix();
    glTranslated(0.09f, 0.06f, 0.0f);
    /// 1st Leaf..............
    x = 0.644f;
    y = 0.532f;
    radius = .012f;
    triangleAmount = 100;
    twicePi = 2.0f * PI;
    glColor3f(0.847, 0.675, 0.702);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// 2nd Leaf..............
    x = 0.664f;
    y = 0.532f;
    radius = .012f;
    triangleAmount = 100;
    twicePi = 2.0f * PI;
    glColor3f(0.847, 0.675, 0.702);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// 3nd Leaf..............
    x = 0.654f;
    y = 0.522f;
    radius = .012f;
    triangleAmount = 100;
    twicePi = 2.0f * PI;
    glColor3f(0.847, 0.675, 0.702);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// 4th Leaf..............
    x = 0.654f;
    y = 0.542f;
    radius = .012f;
    triangleAmount = 100;
    twicePi = 2.0f * PI;
    glColor3f(0.847, 0.675, 0.702);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// Flower central black portion......
    x = 0.654f;
    y = 0.532f;
    radius = .01f;
    triangleAmount = 100;
    twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.0, -0.2, 0.0);
    glColor3f(0.847, 0.675, 0.702);
    circle(0.644, 0.532, 0.012);
    circle(0.664, 0.532, 0.012);
    circle(0.654, 0.522, 0.012);
    circle(0.654, 0.542, 0.012);
    glColor3f(0.0, 0.0, 0.0);
    circle(0.654, 0.532, 0.01);

    glTranslated(0.2, 0.08, 0.0);
    glColor3f(0.847, 0.675, 0.702);
    circle(0.644, 0.532, 0.012);
    circle(0.664, 0.532, 0.012);
    circle(0.654, 0.522, 0.012);
    circle(0.654, 0.542, 0.012);
    glColor3f(0.0, 0.0, 0.0);
    circle(0.654, 0.532, 0.01);

    glTranslated(-0.01, 0.07, 0.0);
    glColor3f(0.847, 0.675, 0.702);
    circle(0.644, 0.532, 0.012);
    circle(0.664, 0.532, 0.012);
    circle(0.654, 0.522, 0.012);
    circle(0.654, 0.542, 0.012);
    glColor3f(0.0, 0.0, 0.0);
    circle(0.654, 0.532, 0.01);

    glTranslated(-0.03, -0.1, 0.0);
    glColor3f(0.847, 0.675, 0.702);
    circle(0.644, 0.532, 0.012);
    circle(0.664, 0.532, 0.012);
    circle(0.654, 0.522, 0.012);
    circle(0.654, 0.542, 0.012);
    glColor3f(0.0, 0.0, 0.0);
    circle(0.654, 0.532, 0.01);

    glPopMatrix();
    ///.........................................End........................
}

void tree_flower2()     // TF
{
    ///..........................Right Tree Flower.....................
    glPushMatrix();
    glTranslated(-1.7, -0.03, 0.0f);
    ///..........................Flower.....................
    /// 1st Leaf...........
    GLfloat x = 0.865f;
    GLfloat y = 0.376f;
    GLfloat radius = .01f;
    int triangleAmount = 100;
    /// # of lines used to draw circle
    GLfloat twicePi = 2.0f * PI;
    glColor3f(0.867, 0.224, 0.122);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    /// 2nd Leaf...........
    x = 0.885f;
    y = 0.376f;
    radius = .01f;
    /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.867, 0.224, 0.122);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// 3rd Leaf...........
    x = 0.875f;
    y = 0.386f;
    radius = .01f;
    /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.867, 0.224, 0.122);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    /// 4th Leaf...........
    x = 0.875f;
    y = 0.366f;
    radius = .01f;
    /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.867, 0.224, 0.122);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    /// Flower(Center black portion)...................
    x = 0.875f;
    y = 0.374f;
    radius = .008f;
    /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    ///.........................................................
    glPushMatrix();
    glTranslated(-0.05f, 0.03f, 0.0f);
    /// 1st Leaf...........
    x = 0.865f;
    y = 0.376f;
    radius = .01f;
    /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.867, 0.224, 0.122);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    /// 2nd Leaf...........
    x = 0.885f;
    y = 0.376f;
    radius = .01f;
    /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.867, 0.224, 0.122);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// 3rd Leaf...........
    x = 0.875f;
    y = 0.386f;
    radius = .01f;
    /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.867, 0.224, 0.122);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    /// 4th Leaf...........
    x = 0.875f;
    y = 0.366f;
    radius = .01f;
    /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.867, 0.224, 0.122);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    /// Flower(Center black portion)...................
    x = 0.875f;
    y = 0.374f;
    radius = .008f;
    /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    glPopMatrix();
    ///.........................................................

    glPushMatrix();
    glTranslated(-0.08f, 0.12f, 0.0f);
    /// 1st Leaf...........
    x = 0.865f;
    y = 0.376f;
    radius = .01f;
    /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.867, 0.224, 0.122);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    /// 2nd Leaf...........
    x = 0.885f;
    y = 0.376f;
    radius = .01f;
    /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.867, 0.224, 0.122);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// 3rd Leaf...........
    x = 0.875f;
    y = 0.386f;
    radius = .01f;
    /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.867, 0.224, 0.122);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    /// 4th Leaf...........
    x = 0.875f;
    y = 0.366f;
    radius = .01f;
    /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.867, 0.224, 0.122);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    /// Flower(Center black portion)...................
    x = 0.875f;
    y = 0.374f;
    radius = .008f;
    /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    glPopMatrix();
    ///.........................................................

    glPushMatrix();
    glTranslated(-0.08f, 0.18f, 0.0f);
    /// 1st Leaf...........
    x = 0.865f;
    y = 0.376f;
    radius = .01f;
    /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.867, 0.224, 0.122);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    /// 2nd Leaf...........
    x = 0.885f;
    y = 0.376f;
    radius = .01f;
    /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.867, 0.224, 0.122);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// 3rd Leaf...........
    x = 0.875f;
    y = 0.386f;
    radius = .01f;
    /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.867, 0.224, 0.122);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    /// 4th Leaf...........
    x = 0.875f;
    y = 0.366f;
    radius = .01f;
    /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.867, 0.224, 0.122);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    /// Flower(Center black portion)...................
    x = 0.875f;
    y = 0.374f;
    radius = .008f;
    /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    glPopMatrix();
    ///.........................................................
    glPushMatrix();
    glTranslated(-0.14f, 0.20f, 0.0f);
    /// 1st Leaf...........
    x = 0.865f;
    y = 0.376f;
    radius = .01f;
    /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.867, 0.224, 0.122);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    /// 2nd Leaf...........
    x = 0.885f;
    y = 0.376f;
    radius = .01f;
    /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.867, 0.224, 0.122);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    /// 3rd Leaf...........
    x = 0.875f;
    y = 0.386f;
    radius = .01f;
    /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.867, 0.224, 0.122);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    /// 4th Leaf...........
    x = 0.875f;
    y = 0.366f;
    radius = .01f;
    /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.867, 0.224, 0.122);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    /// Flower(Center black portion)...................
    x = 0.875f;
    y = 0.374f;
    radius = .008f;
    /// # of lines used to draw circle
    twicePi = 2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    glPopMatrix();
    ///.........................................................
    glPopMatrix();
}

void summer()
{
    glClearColor(0.929f, 0.925f, 0.831f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);               // Clear the color buffer (background)
    sea();      //mushfika
   beach();    // mushfika
   sky();      //Asif
   sun();      //mushfika
   sun_shadow();   //mushfika
   cloud1();       //Asif
   cloud2();       //Asif
   cloud3();       //Asif
   road();         //Ahmed
   grass();    //dipta
   car();      //Ahmed
   bus();     //Ahmed
   boat1();       //Ahmed
   boat2();       //Ahmed
   hills();       //Mushfika
   rail_Line();   //Annan
   tree1();        //dipta
   tree_leaf1();   //dipta
   tree_leaf2();   //dipta
   tree2();        //dipta
   train1();       //Annan
   train2();       //Annan

    i += 0.2f;

    glFlush(); /// Render now
}

void sea2()     //
{
    /**.......................................Sea ..........................................**/

    glBegin(GL_QUADS);
    glColor3f(0.633, 0.765, 0.831);
    glVertex2f(-1.0f, 0.66f);
    glColor3f(0.075, 0.18, 0.251);

    glVertex2f(-1.0f, 0.76f);
    glColor3f(0.075, 0.18, 0.251);
    glVertex2f(1.0f, 0.80f);

    glColor3f(0.633, 0.765, 0.831);
    glVertex2f(1.0f, 0.55f);
    glEnd();

    /**.......................................Sea Wave ..........................................**/
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.5f, 0.68f);
    glVertex2f(-.5f, 0.689f);
    glVertex2f(-0.36f, 0.687f);
    glVertex2f(-0.34f, 0.686f);
    glVertex2f(-0.56f, 0.687f);
    glVertex2f(-0.54f, 0.686f);
    glEnd();

    glPushMatrix();
    glTranslated(0.9f, -0.07f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.5f, 0.68f);
    glVertex2f(-.5f, 0.689f);
    glVertex2f(-0.36f, 0.687f);
    glVertex2f(-0.34f, 0.686f);
    glVertex2f(-0.56f, 0.687f);
    glVertex2f(-0.54f, 0.686f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(1.4f, 0.05f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.5f, 0.68f);
    glVertex2f(-.5f, 0.689f);
    glVertex2f(-0.36f, 0.687f);
    glVertex2f(-0.34f, 0.686f);
    glVertex2f(-0.56f, 0.687f);
    glVertex2f(-0.54f, 0.686f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.6f, 0.06f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.5f, 0.68f);
    glVertex2f(-.5f, 0.689f);
    glVertex2f(-0.36f, 0.687f);
    glVertex2f(-0.34f, 0.686f);
    glVertex2f(-0.56f, 0.687f);
    glVertex2f(-0.54f, 0.686f);
    glEnd();
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.99f, 0.7f);
    glVertex2f(-0.85f, 0.71f);
    glVertex2f(-0.79f, 0.7f);
    glVertex2f(-0.87f, 0.71f);
    glVertex2f(-0.88f, 0.7f);
    glVertex2f(-0.93f, 0.7f);
    glVertex2f(-1.1f, 0.69f);
    glEnd();

    glPushMatrix();
    glTranslated(0.7f, -0.03f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.99f, 0.7f);
    glVertex2f(-0.85f, 0.71f);
    glVertex2f(-0.79f, 0.7f);
    glVertex2f(-0.87f, 0.71f);
    glVertex2f(-0.88f, 0.7f);
    glVertex2f(-0.93f, 0.7f);
    glVertex2f(-1.1f, 0.69f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(1.4f, 0.02f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.99f, 0.7f);
    glVertex2f(-0.85f, 0.71f);
    glVertex2f(-0.79f, 0.7f);
    glVertex2f(-0.87f, 0.71f);
    glVertex2f(-0.88f, 0.7f);
    glVertex2f(-0.93f, 0.7f);
    glVertex2f(-1.1f, 0.69f);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(1.6f, -0.08f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.99f, 0.7f);
    glVertex2f(-0.85f, 0.71f);
    glVertex2f(-0.79f, 0.7f);
    glVertex2f(-0.87f, 0.71f);
    glVertex2f(-0.88f, 0.7f);
    glVertex2f(-0.93f, 0.7f);
    glVertex2f(-1.1f, 0.69f);
    glEnd();
    glPopMatrix();
}

void sky2()     // Sky1
{

    /**.......................................Sky ..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.322, 0.494, 0.560);
    glVertex2f(-1.0f, 0.76f);

    glColor3f(0.086, 0.2, 0.31);
    glVertex2f(-1.0f, 1.0f);

    glColor3f(0.086, 0.2, 0.31);
    glVertex2f(1.0f, 1.0f);

    glColor3f(0.322, 0.494, 0.560);
    glVertex2f(1.0f, 0.76f);

    glColor3f(0.318, 0.490, 0.554);
    glVertex2f(1.0f, 0.762f);
    glEnd();
}

void cloud1rain()   // Cloud_Rain-3001
{
    /**........................................Cloud Middle..........................................**/
    glPushMatrix();
    glTranslated(position_cloud1x, 0.0f, 0.0f);
    glPushMatrix();
    glTranslated(0.0f, 0.05f, 0.0f);
    GLfloat x = 0.0f;
    GLfloat y = 0.88f;
    GLfloat radius = .04f;
    int triangleAmount = 100;
    GLfloat twicePi = 2.0f * PI;
    glColor3f(0.373, 0.369, 0.388);
    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    x = 0.05f;
    y = 0.88f;
    radius = .04f;
    twicePi = 2.0f * PI;
    glColor3f(0.373, 0.369, 0.388);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle

    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = -0.05f;
    y = 0.88f;
    radius = .04f;
    twicePi = 2.0f * PI;
    glColor3f(0.373, 0.369, 0.388);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = -0.04f;
    y = 0.92f;
    radius = .03f;
    twicePi = 2.0f * PI;
    glColor3f(0.373, 0.369, 0.388);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle

    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = -0.013f;
    y = 0.85f;
    radius = .03f;
    twicePi = 2.0f * PI;
    glColor3f(0.373, 0.369, 0.388);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle

    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = 0.053f;
    y = 0.85f;
    radius = .036f;
    twicePi = 2.0f * PI;
    glColor3f(0.373, 0.369, 0.388);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle

    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void cloud2rain()       // Cloud_Rain-3002
{
    /**........................................Cloud Left...........................................**/
    glPushMatrix();
    glTranslated(position_cloud2x, 0.0f, 0.0f);
    GLfloat x = -0.5f;
    GLfloat y = 0.85f;
    GLfloat radius = .058f;
    int triangleAmount = 100;
    GLfloat twicePi = 1.0f * PI;
    glColor3f(0.573, 0.565, 0.549);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle

    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = -0.57f;
    y = 0.85f;
    radius = .037f;
    twicePi = 1.0f * PI;
    glColor3f(0.573, 0.565, 0.549);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {

        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = -0.43f;
    y = 0.85f;
    radius = .04f;
    twicePi = 1.0f * PI;
    glColor3f(0.573, 0.565, 0.549);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle

    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = -0.55f;
    y = 0.86f;
    radius = .03f;
    twicePi = 1.0f * PI;
    glColor3f(0.573, 0.565, 0.549);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle

    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = -0.61f;
    y = 0.85f;
    radius = .02f;
    twicePi = 1.0f * PI;
    glColor3f(0.573, 0.565, 0.549);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle

    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = -0.39f;
    y = 0.85f;
    radius = .02f;
    twicePi = 1.0f * PI;
    glColor3f(0.573, 0.565, 0.549);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle

    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }

    glEnd();
    glPopMatrix();
}

void cloud3rain()       // Cloud_Rain-3003
{
    /**........................................Cloud Right...........................................**/
    glPushMatrix();
    glTranslated(position_cloud3x, 0.0f, 0.0f);
    GLfloat x = 0.45f;
    GLfloat y = 0.85f;
    GLfloat radius = .035f;
    int triangleAmount = 100;
    GLfloat twicePi = 1.0f * PI;
    glColor3f(0.373, 0.369, 0.388);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle

    for (float i = 0; i <= triangleAmount; i++)
    {

        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),

                   y + (radius * sin(i * twicePi / triangleAmount)));
    }

    glEnd();

    x = 0.48f;
    y = 0.85f;
    radius = .03f;
    twicePi = 1.0f * PI;
    glColor3f(0.373, 0.369, 0.388);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle

    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = 0.42f;
    y = 0.85f;
    radius = .028f;
    twicePi = 1.0f * PI;
    glColor3f(0.373, 0.369, 0.388);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for (float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    glPopMatrix();
}

void rainy()
{
    glClearColor(0.929f, 0.925f, 0.831f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);               // Clear the color buffer (background)
    glColor3f(0.633, 0.765, 0.831);

    sea2();
    beach();
    sky2();
    // sun();
    glColor3ub(158, 161, 163);
    glPushMatrix();
    glTranslatef(RcloudP, 0.0f, 0.0f);
    glScalef(0.7, 0.7, 0.0);
    glTranslated(0.0f, 0.55, 0.0);

    rainCloud();
    glPopMatrix();
    cloud1rain();
    cloud2rain();
    cloud3rain();
    road();
    grass();
    car();

    bus();
    boat2();
    hills();
    rail_Line();

    tree1();
    tree_leaf1();
    tree_leaf2();
    tree2();
    train1();
    train2();
    glPushMatrix();
    glTranslatef(0.0f, rainP, 0.0f);

    glTranslated(0.0f, 1.0f, 0.0f);

    rain();

    glLoadIdentity();

    glPopMatrix();

    i += 0.2f;

    glFlush(); /// Render now
}

void autumn()
{
    glClearColor(0.929f, 0.925f, 0.831f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);               // Clear the color buffer (background)
    sea();
    beach();
    sky();
    sun1();
    cloud1();
    cloud2();
    cloud3();
    road();
    grass();
    car();
    bus();
    boat1();
    boat2();
    hills();
    rail_Line();

    tree1();
    tree_leaf1();
    tree_leaf2();
    tree2();
    train1();
    train2();
    glPushMatrix();
    glTranslatef(0.0f, flowerP, 0.0f);
    glTranslated(0.0f, -0.2f, 0.0f);
    kashPhul();

    glLoadIdentity();

    glPopMatrix();

    i += 0.2f;

    glFlush(); /// Render now
}

void winter()
{
    glClearColor(0.929f, 0.925f, 0.831f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);               // Clear the color buffer (background)
    sea();
    beach();
    sky();
    sun1();
    cloud1();
    cloud2();
    cloud3();
    road();
    grass();
    car();
    bus();
    boat1();
    boat2();
    hills();
    rail_Line();
    tree1();
    tree_leaf1();
    tree_leaf2();

    tree2();

    /**....................................... Snow drop ..........................................**/
    glPushMatrix();
    glTranslated(0.0f, snowP, 0.0f);
    glColor3ub(255, 255, 255);
    glTranslated(0.0, 0.4, 0.0);
    snowball();
    glTranslated(0.2, -0.5, 0);
    snowball();
    glTranslated(-0.1, -0.45, 0);
    snowball();
    glTranslated(0.0, -0.5, 0);
    snowball();
    glTranslated(0.2, -0.5, 0);
    snowball();
    glTranslated(-0.1, -0.5, 0);
    snowball();
    glPopMatrix();

    /**....................................... leaf Drop ..........................................**/

    glPushMatrix();
    glTranslatef(0.0f, treeP3, 0.0f);
    glColor3f(0.549, 0.639, 0.153);
    circle(0.644, 0.532, 0.06);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, treeP2, 0.0f);
    glColor3f(0.549, 0.639, 0.153);
    circle(0.644, 0.477, 0.05);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, treeP1, 0.0f);
    glColor3f(0.647, 0.745, 0.184);
    circle(0.691, 0.568, 0.07);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, treeP4, 0.0f);
    glColor3f(0.647, 0.745, 0.184);
    circle(0.771, 0.563, 0.06);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, treeP5, 0.0f);
    glColor3f(0.647, 0.745, 0.184);
    circle(0.771, 0.563, 0.06);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, treeP6, 0.0f);
    glColor3f(0.694, 0.78, 0.294);
    circle(0.814, 0.562, 0.045);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, treeP7, 0.0f);
    glColor3f(0.694, 0.78, 0.294);
    circle(0.835, 0.543, 0.05);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, treeP8, 0.0f);
    glColor3f(0.694, 0.78, 0.294);
    circle(0.839, 0.508, 0.05);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, treeP9, 0.0f);
    glColor3f(0.647, 0.745, 0.184);
    circle(0.749, 0.457, 0.06);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, treeP10, 0.0f);
    glColor3f(0.694, 0.78, 0.294);
    circle(0.796, 0.485, 0.05);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, treeP11, 0.0f);
    glColor3f(0.647, 0.745, 0.184);
    circle(0.709, 0.442, 0.05);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, treeP12, 0.0f);
    glColor3f(0.647, 0.745, 0.184);
    circle(0.695, 0.457, 0.055);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, treeP1, 0.0f);
    glColor3f(0.549, 0.639, 0.153);
    circle(0.865, 0.376, 0.035);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, treeP5, 0.0f);
    glColor3f(0.647, 0.745, 0.184);
    circle(0.896, 0.390, 0.025);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, treeP2, 0.0f);
    glColor3f(0.694, 0.78, 0.294);
    circle(0.835, 0.406, 0.03);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, treeP6, 0.0f);
    glColor3f(0.694, 0.78, 0.294);
    circle(0.802, 0.384, 0.03);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, treeP9, 0.0f);
    glColor3f(0.549, 0.639, 0.153);
    circle(0.836, 0.366, 0.035);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, treeP3, 0.0f);
    glColor3f(0.647, 0.745, 0.184);
    circle(0.881, 0.408, 0.03);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.18f, -0.055f, 0.0f);

    glPushMatrix();
    glTranslatef(0.0f, treeP1, 0.0f);
    glColor3f(0.549, 0.639, 0.153);
    circle(0.865, 0.376, 0.035);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, treeP5, 0.0f);
    glColor3f(0.647, 0.745, 0.184);
    circle(0.896, 0.390, 0.025);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, treeP2, 0.0f);
    glColor3f(0.694, 0.78, 0.294);
    circle(0.835, 0.406, 0.03);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, treeP6, 0.0f);
    glColor3f(0.694, 0.78, 0.294);
    circle(0.802, 0.384, 0.03);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, treeP9, 0.0f);
    glColor3f(0.549, 0.639, 0.153);
    circle(0.836, 0.366, 0.035);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, treeP3, 0.0f);
    glColor3f(0.647, 0.745, 0.184);
    circle(0.881, 0.408, 0.03);
    glPopMatrix();

    glPopMatrix();

    train1();
    train2();

    i += 0.2f;

    glFlush(); /// Render now
}

void spring()
{
    glClearColor(0.929f, 0.925f, 0.831f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);               // Clear the color buffer (background)
    sea();
    beach();
    sky();
    sun1();
    cloud1();
    cloud2();
    cloud3();
    road();
    grass();
    car();
    bus();
    boat1();
    boat2();
    hills();
    rail_Line();
    tree1();
    tree_leaf1();
    tree_leaf2();
    tree2();
    train1();
    train2();
    tree_flower();
    tree_flower2();

    glPushMatrix();
    glTranslatef(0.0f, flowerP1, 0.0f);

    glTranslated(0.0f, -0.2f, 0.0f);
    flower();
    glPopMatrix();

    i += 0.2f;

    glFlush(); /// Render now
}

void myKeyboard(unsigned char key, int x, int y)
{
    switch (key)
    {

    case 's':

        glutDisplayFunc(summer);

        glutPostRedisplay();

        /// PlaySound("horn.wav",NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
        break;

    case 'r':

        glutDisplayFunc(rainy);

        glutPostRedisplay();

        break;

    case 'a':

        glutDisplayFunc(autumn);

        glutPostRedisplay();

        break;

    case 'w':

        glutDisplayFunc(winter);

        glutPostRedisplay();

        break;

    case 'q':

        glutDisplayFunc(spring);
        glutPostRedisplay();

        break;

    default:
        break;
    }
}

void init(void)
{
    /// initialize viewing values
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, 0.0, 1.0, -10.0, 10.0);
}

/** Main function: GLUT runs as a console application starting at main() **/
int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1520, 800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Cox's bazar MARIN DRIVE"); // Create a window with the given title
    loadImageAndStore("C:/Users/ASUS-PC/OneDrive/Desktop/Cox's Bazar mArine drive/aaaa.bmp");
    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(myKeyboard);
    glutSpecialFunc(SpecialInput);

    glutTimerFunc(205, RcloudUp, 0);  /// Rainy
    glutTimerFunc(500, rainUp, 0);    /// rainy
    glutTimerFunc(900, flowerUp, 0);  /// autumn
    glutTimerFunc(120, treeUp, 0);   /// winter
    glutTimerFunc(150, snowUp, 0);   /// winter
    glutTimerFunc(200, flowerUp1, 0); /// spring

    glutMainLoop(); /// Enter the event-processing loop
    return 0;
}

