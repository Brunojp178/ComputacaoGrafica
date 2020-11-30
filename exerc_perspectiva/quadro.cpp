#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "quadro.h"

#define ANGLE 0.3
#define SCALE 0.9
#define RAND 0.06

Quadro::Quadro(){
    // Empty
}

Quadro::Quadro(float piX, float piY, float tam){
    pi_x = piX;
    pi_y = piY;
    tamanho = tam;
}

float Quadro::myrand(float R){
    return (2 * R * rand()) / RAND_MAX - R;
}

void Quadro::tree(float x1, float y1, float length1, float angle1, int depth){
    if (depth > 0){
        // desenho o segmento de linha
        float x2 = x1 + length1 * cos(angle1);
        float y2 = y1 + length1 * sin(angle1);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        // faz duas chamadas recursivas
        float length2 = length1 * (SCALE + myrand(RAND));
        float angle2 = angle1 + ANGLE + myrand(RAND);
        tree(x2, y2, length2, angle2, depth-1);
        length2 = length1 * (SCALE + myrand(RAND));
        angle2 = angle1 - ANGLE + myrand(RAND);
        tree(x2, y2, length2, angle2, depth-1);
    }
}

void Quadro::draw(){
    float pf_x, pf_y;
    pf_x = abs(pi_x) + tamanho;
    pf_y = abs(pi_y) + tamanho;
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
        glColor3f(0.9, 0.9, 0.9);
        glVertex2f(pi_x, pi_y);
        glVertex2f(-pf_x, pi_y);
        glVertex2f(-pf_x, pf_y);
        glVertex2f(pi_x, pf_y);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glLineWidth(3);
    glBegin(GL_QUADS);
        glColor3f(0.87 - 0.5, 0.72 - 0.5, 0.52 - 0.5);
        glVertex2f(pi_x, pi_y);
        glVertex2f(-pf_x, pi_y);
        glVertex2f(-pf_x, pf_y);
        glVertex2f(pi_x, pf_y);
    glEnd();

    glColor3f(0.2, 0.9, 0.2);
    glBegin(GL_LINES);
        tree(-(pi_x + 33), (pi_y + 4), 2, 1.5, 10);
    glEnd();
}

Quadro::~Quadro(){
    // Empty
}
