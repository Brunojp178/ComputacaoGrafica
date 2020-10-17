#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define Xmin -50
#define Xmax 50

static int retas = 9;

// Decidi alterar os limites do ortho a partir do exercicio 5
// Podia ter feito o 4 com limites de -100 a 100 mas já havia começado
// com limites de 0 a 100 então continuei

/* // EXERCICIO 5 ************************
void Draw(void){
    // Resetar tela
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_TRIANGLE_STRIP);
        // Vermelho
        glColor3f(1,0,0);
        glVertex2f(-50, 50);
        glVertex2f(-50, -50);
        glColor3f(0,0,0);
        glVertex2f(-20, -20);

        glColor3f(0, 1, 0);
        glVertex2f(20, -20);
        // Volta de vertex para n bugar
        glColor3f(1, 0, 0);
        glVertex2f(-50, -50);
        glColor3f(0,0,1);
        glVertex2f(50, -50);

        // Volta de vertex para n bugar
        glColor3f(0,1,0);
        glVertex2f(20, -20);
        glColor3f(1,1,0);
        glVertex2f(20, 20);

        glColor3f(0,0,1);
        glVertex2f(50, -50);
        glColor3f(1,0,1);
        glVertex2f(50, 50);

        // Volta de vertex para n bugar
        glColor3f(1,1,0);
        glVertex2f(20, 20);
        glColor3f(0,1,1);
        glVertex2f(-20, 20);

        // Volta de vertex para n bugar
        glColor3f(1,0,1);
        glVertex2f(50, 50);
        glColor3f(1,0,0);
        glVertex2f(-50, 50);

        glColor3f(0,1,1);
        glVertex2f(-20, 20);
        glColor3f(0,0,0);
        glVertex2f(-20, -20);

    glEnd();
    glFlush();
}
*/ // EXERCICIO 5 FIM ************************

/* // EXERCICIOS 6 PARTE 1 ************************
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
    // Desenha os eixos
    Eixos();

    int precisao = 1;

    glBegin(GL_LINE_STRIP);
        glColor3f(1,0,0);

        glVertex2f(-100, sin(-100));
        for(int x = -100; x <= 100; x+=precisao){
            glVertex2f(x, sin(x));
        }
    glEnd();

    glFlush();
}
*/ // EXERCICIO 6 PARTE 1 FIM *******************

/* // EXERCICIO 6 PARTE 2 *********************************
void Eixos(void){
    glLineWidth(1);
    glBegin(GL_LINES);
        glColor3f(1,1,1);
        // X
        glVertex2f(Xmin, 0);
        glVertex2f(Xmax, 0);
        // Y
        glVertex2f(0, Xmin);
        glVertex2f(0, Xmax);
    glEnd();
}

void Draw(void){
    // Resetar tela
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    // Desenha os eixos
    Eixos();

    int precisao = 1;

    glBegin(GL_LINE_STRIP);
        glColor3f(1,0,0);

        glVertex2f(-100, sin(-100));
        for(int x = -10; x <= 10; x+=precisao){
            glVertex2f(x, ((3 * pow(x, 2)) + (5 * x) - 6));
        }
    glEnd();

    glFlush();
}

*/ // EXERCICIO 6 PARTE 2 FIM ************************

// EXERCICIO 7 **************************************

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
    // Desenha os eixos
    Eixos();

    float angulo = 0;
    float x = 0;
    float y = 0;

    glBegin(GL_LINE_LOOP);
        glColor3f(0,1,1);

        for(int i = 0; i < retas; i++){
            angulo = (2.0 * 3.1415 * i) / retas;
            x = 20 * cos(angulo);
            y = 20 * sin(angulo);

            glVertex2f(x, y);
        }
    glEnd();
    glFlush();
}

// Evento de tecla pressionada
void EvtKeyDown(unsigned char key, int x, int y){
     if(key){
        if(key == 'q'){
            exit(0);
        }
        if(key == '+' || key == '='){
            retas++;
        }
        if(key == '-'){
            if(retas > 9) retas--;
        }
    }
    glutPostRedisplay();
}

// Função de inicialização
void Init (void){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(Xmin,Xmax,Xmin,Xmax); // Valores máximos dos eixos
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv){
    //Glut init
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Glut windows size & position
    glutInitWindowSize(720, 720);
    glutInitWindowPosition(50, 0);
    glutCreateWindow("Atividade 2 parte 2 - Bruno José Placides");
    // Func to draw, initialize and key pressed event
    glutDisplayFunc(Draw);
    Init();
    glutKeyboardFunc(EvtKeyDown);
    glutMainLoop();
}
