#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "quarto.h"
#include "quadro.h"
#include "cama.h"

// Pontos maximos e minimos do orto
#define Xmin -100
#define Xmax 100
#define Ymin -100
#define Ymax 100
// Ponto de fuga
#define pf_x 0
#define pf_y 0

void Eixos(void){
    glLineWidth(1);
    glBegin(GL_LINES);
        glColor3f(1,1,1);
        // X
        glVertex2f(-100, 0);
        glVertex2f(100, 0);
        // Y
        glVertex2f(0, -100);
        glVertex2f(0, 100);
    glEnd();
}

void Draw(void){
    // Resetar tela
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    // (float piX, float piY, float pfX, float pfY)
    Quarto quarto(45, -45, 0, 0);
    Quadro quadro(-10, 10, 25);
    Cama cama(10, -10, 40);


    quarto.draw();
    quadro.draw();
    cama.draw();
    // Desenha os eixos
    Eixos();
    glFlush();
}

// Evento de tecla pressionada
void EvtKeyDown(unsigned char key, int x, int y){
     if(key){
        if(key == 'q'){
            exit(0);
        }
    }
    glutPostRedisplay();
}

// Função de inicialização
void Init (void){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(Xmin,Xmax,Ymin,Ymax); // Valores máximos dos eixos
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv){
    //Glut init
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Glut windows size & position
    glutInitWindowSize(720, 720);
    glutInitWindowPosition(50, 0);
    glutCreateWindow("Atividade Perspectiva - Bruno José Placides");
    // Func to draw, initialize and key pressed event
    glutDisplayFunc(Draw);
    Init();
    glutKeyboardFunc(EvtKeyDown);
    glutMainLoop();
}
