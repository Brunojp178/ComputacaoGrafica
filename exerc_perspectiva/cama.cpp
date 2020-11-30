#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "cama.h"

Cama::Cama(){
    // Empty like my soul
}

Cama::Cama(float piX, float piY, float larg){
    pi_x = piX;
    pi_y = piY;
    largura = larg;

    cor_r = 0.37;
    cor_g = 0.22;
    cor_b = 0.02;

    offset = 1.5;
    altura = 45;

    comprimento = 50;
}

void Cama::cabeceira(){
    // Cabeceira da cama
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
        glColor3f(cor_r, cor_g, cor_b);
        glVertex2f(pi_x, pi_y);
        glVertex2f(pi_x + largura, pi_y);
        glVertex2f(pi_x + largura, pi_y - altura);
        glVertex2f(pi_x, pi_y - altura);
    glEnd();
    // border
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glLineWidth(1);
    glBegin(GL_QUADS);
        glColor3f(0, 0, 0);
        glVertex2f(pi_x, pi_y);
        glVertex2f(pi_x + largura, pi_y);
        glVertex2f(pi_x + largura, pi_y - altura);
        glVertex2f(pi_x, pi_y - altura);
    glEnd();

    // Volume effect
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
        glColor3f(cor_r, cor_g, cor_b);
        glVertex2f(pi_x + offset, pi_y - offset);
        glVertex2f((pi_x + largura) + offset, pi_y - offset);
        glVertex2f((pi_x + largura) + offset, (pi_y - altura) - offset);
        glVertex2f(pi_x + offset, (pi_y - altura) - offset);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glLineWidth(1);
    glBegin(GL_QUADS);
        glColor3f(0, 0, 0);
        glVertex2f(pi_x + offset, pi_y - offset);
        glVertex2f((pi_x + largura) + offset, pi_y - offset);
        glVertex2f((pi_x + largura) + offset, (pi_y - altura) - offset);
        glVertex2f(pi_x + offset, (pi_y - altura) - offset);
    glEnd();

    // Volume effect sides
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
        glColor3f(cor_r, cor_g, cor_b);
        glVertex2f(pi_x, pi_y);
        glVertex2f(pi_x + largura, pi_y);
        glVertex2f((pi_x + largura) + offset, (pi_y - offset));
        glVertex2f(pi_x + offset, (pi_y - offset));
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
        glColor3f(cor_r, cor_g, cor_b);
        glVertex2f(pi_x, pi_y);
        glVertex2f(pi_x + largura, pi_y);
        glVertex2f((pi_x + largura) + offset, (pi_y - offset));
        glVertex2f(pi_x + offset, (pi_y - offset));
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_QUADS);
        glColor3f(0, 0, 0);
        glVertex2f(pi_x, pi_y);
        glVertex2f(pi_x + largura, pi_y);
        glVertex2f((pi_x + largura) + offset, (pi_y - offset));
        glVertex2f(pi_x + offset, (pi_y - offset));
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
        glColor3f(cor_r, cor_g, cor_b);
        glVertex2f(pi_x, pi_y);
        glVertex2f(pi_x + offset, (pi_y - offset));
        glVertex2f(pi_x + offset, (pi_y - altura) - offset);
        glVertex2f(pi_x, (pi_y - altura));
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_QUADS);
        glColor3f(0, 0, 0);
        glVertex2f(pi_x, pi_y);
        glVertex2f(pi_x + offset, (pi_y - offset));
        glVertex2f(pi_x + offset, (pi_y - altura) - offset);
        glVertex2f(pi_x, (pi_y - altura));
    glEnd();
}

void Cama::colchao(){
    float altura_colchao = 30;
    float pc_x, pc_y;

    float offset_colchao = offset;

    float colchao_r = 0.85;
    float colchao_g = 0.85;
    float colchao_b = 0.85;






    // ponto inicial do colchão
    pc_x = pi_x;
    // Levando que a cama se encontra no 4 quadrante, y é negativo
    pc_y = (pi_y - altura_colchao);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
        glColor3f(colchao_r, colchao_g, colchao_b);
        glVertex2f(pc_x, pc_y);
        glVertex2f(pc_x + largura + offset_colchao, pc_y);
        glVertex2f(pc_x + largura + comprimento, pc_y - comprimento);
        glVertex2f(pc_x + largura, pc_y - comprimento);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glLineWidth(1);
    glBegin(GL_QUADS);
        glColor3f(0, 0, 0);
        glVertex2f(pc_x, pc_y);
        glVertex2f(pc_x + largura + offset_colchao, pc_y);
        glVertex2f(pc_x + largura + comprimento, pc_y - comprimento);
        glVertex2f(pc_x + largura, pc_y - comprimento);
    glEnd();

    // Draw the same quad, with different height
    pc_y = pc_y + 5;

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
        glColor3f(colchao_r, colchao_g, colchao_b);
        glVertex2f(pc_x, pc_y);
        glVertex2f(pc_x + largura + offset_colchao, pc_y);
        glVertex2f(pc_x + largura + comprimento, pc_y - comprimento);
        glVertex2f(pc_x + largura, pc_y - comprimento);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glLineWidth(1);
    glBegin(GL_QUADS);
        glColor3f(0, 0, 0);
        glVertex2f(pc_x, pc_y);
        glVertex2f(pc_x + largura + offset_colchao, pc_y);
        glVertex2f(pc_x + largura + comprimento, pc_y - comprimento);
        glVertex2f(pc_x + largura, pc_y - comprimento);
    glEnd();


    // canto do colchao
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
        glColor3f(cor_r, cor_g, cor_b);
        glVertex2f(pc_x, pc_y);
        glVertex2f(pc_x + largura, pc_y - comprimento);
        glVertex2f(pc_x + largura, (pc_y - comprimento) - 5);
        glVertex2f(pc_x, pc_y - 5);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_QUADS);
        glColor3f(0, 0, 0);
        glVertex2f(pc_x, pc_y);
        glVertex2f(pc_x + largura, pc_y - comprimento);
        glVertex2f(pc_x + largura, (pc_y - comprimento) - 5);
        glVertex2f(pc_x, pc_y - 5);
    glEnd();

    // parte de baixo do canto do colchao
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
        glColor3f(cor_r, cor_g, cor_b);
        glVertex2f(pc_x + largura, pc_y - comprimento);
        glVertex2f(pc_x + largura + comprimento, pc_y - comprimento);
        glVertex2f(pc_x + largura + comprimento, (pc_y - comprimento) - 5);
        glVertex2f(pc_x + largura, (pc_y - comprimento) - 5);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_QUADS);
        glColor3f(0, 0, 0);
        glVertex2f(pc_x + largura, pc_y - comprimento);
        glVertex2f(pc_x + largura + comprimento, pc_y - comprimento);
        glVertex2f(pc_x + largura + comprimento, (pc_y - comprimento) - 5);
        glVertex2f(pc_x + largura, (pc_y - comprimento) - 5);
    glEnd();


    // Pé esquerdo da cama
    largura -= 2;
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
        glColor3f(cor_r, cor_g, cor_b);
        glVertex2f(pc_x + largura, (pc_y - comprimento));
        glVertex2f(pc_x + largura + 8, (pc_y - comprimento));
        glVertex2f(pc_x + largura + 8, (pc_y - comprimento) - 10);
        glVertex2f(pc_x + largura, (pc_y - comprimento) - 10);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_QUADS);
        glColor3f(0, 0, 0);
        glVertex2f(pc_x + largura, (pc_y - comprimento));
        glVertex2f(pc_x + largura + 8, (pc_y - comprimento));
        glVertex2f(pc_x + largura + 8, (pc_y - comprimento) - 10);
        glVertex2f(pc_x + largura, (pc_y - comprimento) - 10);
    glEnd();

    largura += 2;
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
        glColor3f(cor_r, cor_g, cor_b);
        glVertex2f(pc_x + largura, (pc_y - comprimento) - 5);
        glVertex2f(pc_x + largura + 8, (pc_y - comprimento) - 5);
        glVertex2f(pc_x + largura + 8, (pc_y - comprimento) - 10);
        glVertex2f(pc_x + largura, (pc_y - comprimento) - 10);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_QUADS);
        glColor3f(0, 0, 0);
        glVertex2f(pc_x + largura, (pc_y - comprimento) - 5);
        glVertex2f(pc_x + largura + 8, (pc_y - comprimento) - 5);
        glVertex2f(pc_x + largura + 8, (pc_y - comprimento) - 10);
        glVertex2f(pc_x + largura, (pc_y - comprimento) - 10);
    glEnd();

    // borda do pé da cama
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
        glColor3f(cor_r, cor_g, cor_b);
        glVertex2f(pc_x + largura, (pc_y - comprimento) - 5);
        glVertex2f(pc_x + largura, (pc_y - comprimento) - 10);
        glVertex2f(pc_x + largura - 2, (pc_y - comprimento) - 10);
        glVertex2f(pc_x + largura - 2, pc_y - comprimento);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_QUADS);
        glColor3f(0, 0, 0);
        glVertex2f(pc_x + largura, (pc_y - comprimento) - 5);
        glVertex2f(pc_x + largura, (pc_y - comprimento) - 10);
        glVertex2f(pc_x + largura - 2, (pc_y - comprimento) - 10);
        glVertex2f(pc_x + largura - 2, pc_y - comprimento);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
        glColor3f(cor_r, cor_g, cor_b);
        glVertex2f(pc_x + largura - 2, (pc_y - comprimento));
        glVertex2f(pc_x + largura + 6, (pc_y - comprimento));
        glVertex2f(pc_x + largura + 8, (pc_y - comprimento) - 5);
        glVertex2f(pc_x + largura, (pc_y - comprimento) - 5);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_QUADS);
        glColor3f(0, 0, 0);
        glVertex2f(pc_x + largura - 2, (pc_y - comprimento));
        glVertex2f(pc_x + largura + 6, (pc_y - comprimento));
        glVertex2f(pc_x + largura + 8, (pc_y - comprimento) - 5);
        glVertex2f(pc_x + largura, (pc_y - comprimento) - 5);
    glEnd();


    // Pé direito da cama
    pc_x += comprimento;
    largura -= 2;
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
        glColor3f(cor_r, cor_g, cor_b);
        glVertex2f(pc_x + largura, (pc_y - comprimento));
        glVertex2f(pc_x + largura + 8, (pc_y - comprimento));
        glVertex2f(pc_x + largura + 8, (pc_y - comprimento) - 10);
        glVertex2f(pc_x + largura, (pc_y - comprimento) - 10);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_QUADS);
        glColor3f(0, 0, 0);
        glVertex2f(pc_x + largura, (pc_y - comprimento));
        glVertex2f(pc_x + largura + 8, (pc_y - comprimento));
        glVertex2f(pc_x + largura + 8, (pc_y - comprimento) - 10);
        glVertex2f(pc_x + largura, (pc_y - comprimento) - 10);
    glEnd();

    largura += 2;
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
        glColor3f(cor_r, cor_g, cor_b);
        glVertex2f(pc_x + largura, (pc_y - comprimento) - 5);
        glVertex2f(pc_x + largura + 8, (pc_y - comprimento) - 5);
        glVertex2f(pc_x + largura + 8, (pc_y - comprimento) - 10);
        glVertex2f(pc_x + largura, (pc_y - comprimento) - 10);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_QUADS);
        glColor3f(0, 0, 0);
        glVertex2f(pc_x + largura, (pc_y - comprimento) - 5);
        glVertex2f(pc_x + largura + 8, (pc_y - comprimento) - 5);
        glVertex2f(pc_x + largura + 8, (pc_y - comprimento) - 10);
        glVertex2f(pc_x + largura, (pc_y - comprimento) - 10);
    glEnd();

    // borda do pé da cama
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
        glColor3f(cor_r, cor_g, cor_b);
        glVertex2f(pc_x + largura, (pc_y - comprimento) - 5);
        glVertex2f(pc_x + largura, (pc_y - comprimento) - 10);
        glVertex2f(pc_x + largura - 2, (pc_y - comprimento) - 10);
        glVertex2f(pc_x + largura - 2, pc_y - comprimento);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_QUADS);
        glColor3f(0, 0, 0);
        glVertex2f(pc_x + largura, (pc_y - comprimento) - 5);
        glVertex2f(pc_x + largura, (pc_y - comprimento) - 10);
        glVertex2f(pc_x + largura - 2, (pc_y - comprimento) - 10);
        glVertex2f(pc_x + largura - 2, pc_y - comprimento);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
        glColor3f(cor_r, cor_g, cor_b);
        glVertex2f(pc_x + largura - 2, (pc_y - comprimento));
        glVertex2f(pc_x + largura + 6, (pc_y - comprimento));
        glVertex2f(pc_x + largura + 8, (pc_y - comprimento) - 5);
        glVertex2f(pc_x + largura, (pc_y - comprimento) - 5);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_QUADS);
        glColor3f(0, 0, 0);
        glVertex2f(pc_x + largura - 2, (pc_y - comprimento));
        glVertex2f(pc_x + largura + 6, (pc_y - comprimento));
        glVertex2f(pc_x + largura + 8, (pc_y - comprimento) - 5);
        glVertex2f(pc_x + largura, (pc_y - comprimento) - 5);
    glEnd();
}

void Cama::draw(){
    cabeceira();
    colchao();
}

Cama::~Cama(){
    // Empty
}
