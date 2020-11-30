#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "quarto.h"

Quarto::Quarto(){
    // Empty builder
}

Quarto::Quarto(float piX, float piY, float pfX, float pfY){
    pi_x = piX;
    pi_y = piY;
    pf_x = pfX;
    pf_y = pfY;

    maxim_x = 100;
    maxim_y = 100;

    //1.000, 0.980, 0.804
    wallcolor_r = 1.000;
    wallcolor_g = 0.980;
    wallcolor_b = 0.804;
    color_degree = 0.15;
}

void Quarto::walls(){
    // Floor
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
        glColor3f((wallcolor_r - color_degree), (wallcolor_g - color_degree), (wallcolor_b - color_degree));
        // first point in the right (close to the escape point)
        glVertex2f(pi_x, pi_y);
        // The two points farest to the escape point
        glColor3f(wallcolor_r, wallcolor_g, wallcolor_g);
        glVertex2f(maxim_x, -maxim_y);
        glVertex2f(-maxim_x, -maxim_y);

        glColor3f(wallcolor_r - color_degree, wallcolor_g - color_degree, wallcolor_b - color_degree);
        glVertex2f(-pi_x, pi_y);
    glEnd();


    // Right wall
    // Change the value of the inicial point to go to positive position
    pi_y = -pi_y;

    glBegin(GL_QUADS);
        glColor3f(wallcolor_r - color_degree, wallcolor_g - color_degree, wallcolor_b - color_degree);
        // first point in the right (close to the escape point)
        glVertex2f(pi_x, pi_y);
        // The two points farest to the escape point
        glColor3f(wallcolor_r, wallcolor_g, wallcolor_g);
        glVertex2f(maxim_x, maxim_y);
        glVertex2f(maxim_x, -maxim_y);

        glColor3f(wallcolor_r - color_degree, wallcolor_g - color_degree, wallcolor_b - color_degree);
        glVertex2f(pi_x, -pi_y);
    glEnd();

    // Roof
    pi_x = -pi_x;

    glBegin(GL_QUADS);
        glColor3f(wallcolor_r - color_degree, wallcolor_g - color_degree, wallcolor_b - color_degree);
        // first point in the right (close to the escape point)
        glVertex2f(pi_x, pi_y);
        // The two points farest to the escape point
        glColor3f(wallcolor_r, wallcolor_g, wallcolor_g);
        glVertex2f(-maxim_x, maxim_y);
        glVertex2f(maxim_x, maxim_y);

        glColor3f(wallcolor_r - color_degree, wallcolor_g - color_degree, wallcolor_b - color_degree);
        glVertex2f(-pi_x, pi_y);
    glEnd();

    // Left wall
    pi_y = -pi_y;

    glBegin(GL_QUADS);
        glColor3f(wallcolor_r - color_degree, wallcolor_g - color_degree, wallcolor_b - color_degree);
        // first point in the right (close to the escape point)
        glVertex2f(pi_x, pi_y);
        // The two points farest to the escape point
        glColor3f(wallcolor_r, wallcolor_g, wallcolor_g);
        glVertex2f(-maxim_x, -maxim_y);
        glVertex2f(-maxim_x, maxim_y);

        glColor3f(wallcolor_r - color_degree, wallcolor_g - color_degree, wallcolor_b - color_degree);
        glVertex2f(pi_x, -pi_y);
    glEnd();

    // Escape point wall
    pi_x = -pi_x;

    glBegin(GL_QUADS);
        glColor3f(wallcolor_r - color_degree, wallcolor_g - color_degree, wallcolor_b - color_degree);
        // first point in the right (close to the escape point)
        glVertex2f(pi_x, pi_y);
        // The two points farest to the escape point
        glVertex2f(-pi_x, pi_y);
        glVertex2f(-pi_x, -pi_y);

        glVertex2f(pi_x, -pi_y);
    glEnd();

    // Start of the borders
    glColor3f(wallcolor_r - 0.3, wallcolor_g - 0.3, wallcolor_g - 0.3);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_QUADS);
        // first point in the right (close to the escape point)
        glVertex2f(pi_x, pi_y);
        // The two points farest to the escape point
        glVertex2f(-pi_x, pi_y);
        glVertex2f(-pi_x, -pi_y);

        glVertex2f(pi_x, -pi_y);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(pi_x, pi_y);
        glVertex2f(maxim_x, -maxim_y);

        glVertex2f(pi_x, -pi_y);
        glVertex2f(maxim_x, maxim_y);

        glVertex2f(-pi_x, -pi_y);
        glVertex2f(-maxim_x, maxim_y);

        glVertex2f(-pi_x, pi_y);
        glVertex2f(-maxim_x, -maxim_y);
    glEnd();

}

void Quarto::door(){
    // 0.871, 0.722, 0.529
    glColor3f(0.87 - 0.2, 0.72 - 0.2, 0.52 - 0.2);
    float px, py, pfX, pfY;
    // -80, -80
    px = -(maxim_x - 20);
    py = -(maxim_y - 20);

    pfX = -(maxim_x);
    pfY = -(maxim_y);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
        glVertex2f(px, py);
        glVertex2f(pfX, pfY);
        // up side
        glVertex2f(pfX, -(pfY + 30));
        glVertex2f(px, -(py + 28));
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_QUADS);
        glColor3f(0, 0, 0);
        glVertex2f(px, py);
        glVertex2f(pfX, pfY);
        // up side
        glVertex2f(pfX, -(pfY + 30));
        glVertex2f(px, -(py + 28));
    glEnd();
}

void Quarto::draw(){
    walls();
    door();
}

Quarto::~Quarto() {
	// TODO Auto-generated destructor stub
}
