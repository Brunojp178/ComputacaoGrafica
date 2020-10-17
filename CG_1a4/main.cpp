#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>


#define origX 50
#define origY 50

/* EXERCICIO 1 ************************************************
// Função para desenhar ponto
void Draw(void){

    // Resetar tela
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);

    float x = 0.5f;
    float y = 50.0f;
    float tamanho = 1;

    for (int i = 0; i < 20; i++){
        // Define point size and position
        glPointSize(tamanho);

        glBegin(GL_POINTS);
            glColor3f(1,0,0);
            glVertex2f(x , y);    //Posição do ponto
        glEnd();

        // increase the next position of the size and X position of the next point
        x += 5;
        tamanho += 1;
    }

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
*/ // EXERCICIO 1 FIM ************************************************

/* // EXERCICIO 2 ***************************************************
// Função de desenhar
void Draw(void){

    // Resetar tela
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);

    // Comprimento da linha
    glLineWidth(5.0);
    glBegin(GL_LINES);
        glColor3f(1.0, 0.0, 0.0);//vermelho
        glVertex2f(20.0, 20.0);
        glColor3f(0.0, 1.0, 0.0);// verde
        glVertex2f(80, 20.0);
    glEnd();

    glPointSize(20);
    glBegin(GL_POINTS);
        glVertex2f(50.0, 35.0);
    glEnd();

    glFlush();
}
*/ // EXERCICIO 2 FIM ************************************************


/* // EXERCICIO 3 *******************************************
void linhas(void){
    // Paredes
    glBegin(GL_LINES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(10, 5);
        glVertex2f(30, 5);

        glVertex2f(10,5);
        glVertex2f(10, 25);

        glVertex2f(10, 25);
        glVertex2f(30, 25);

        glVertex2f(30, 25);
        glVertex2f(30, 5);
    glEnd();
}

void triang(void){
    // Telhado
    glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(10, 25);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(30, 25);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(20, 35);
    glEnd();
}

void quadrs(void){
    // Porta
    glBegin(GL_QUADS);
        glColor3f(0, 1, 0);
        glVertex2f(18.5, 5);
        glColor3f(1,1,1);
        glVertex2f(18.5, 13);
        glVertex2f(22, 13);
        glColor3f(0, 1, 0);
        glVertex2f(22, 5);
    glEnd();

    glPointSize(6);
    glBegin(GL_POINTS);
        glColor3f(0, 0, 0);
        glVertex2f(21, 9.5);
    glEnd();

    // Janelas
    glPointSize(17);
    glBegin(GL_POINTS);
        glColor3f(0, 0, 1);
        glVertex2f(13.5, 13);
        glVertex2f(26.5, 13);
    glEnd();
}


void Draw(void){

    // Resetar tela
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);

    // Paredes
    linhas();
    // Telhado
    triang();
    // Porta e janelas
    quadrs();

    glFlush();
}

*/ // EXERCICIO 3 ******************************

/* // EXERCICIO 4 PARTE 1 **********************
void Eixos(void){
    glLineWidth(1);
    glBegin(GL_LINES);
        glColor3f(1, 1, 1);
        // Eixo X
        glVertex2f((origX - 50), (origY));
        glVertex2f((origX + 50), (origY));

        // Eixo Y
        glVertex2f(origX, (origY - 50));
        glVertex2f(origX, (origY + 50));
    glEnd();
}

void Figuras(void){

    // Primeiro quadrante (75, 75)
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_TRIANGLE_STRIP);
        glColor3f(1, 1, 1);
        glVertex3f(60,60, 0);
        glVertex3f(65,95, 0);
        glVertex3f(70,60, 0);
        glVertex3f(76,80, 0);
        glVertex3f(90,65, 0);
    glEnd();

    // Segundo quadrante (25, 75)
    float tamanho = 200;
    int alt = 1;

    for (int i = 0; i < 70; i++){
        glPointSize(tamanho - (i * 4));
        glBegin(GL_POINTS);
            glColor3f(1 * alt, 1 * alt, 1 * alt);
            glVertex2f(25, 75);
        glEnd();

        if(alt == 1) alt--;
        else alt++;
    }

    // Terceiro quadrante (25, 25)
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINES);
    glBegin(GL_TRIANGLE_STRIP);
        // branco
        glColor3f(1, 1, 1);
        glVertex2f(15, 15);
        // azul
        glColor3f(0, 0, 1);
        glVertex2f(35, 15);
        // azul com verde
        glColor3f(0, 1, 1);
        glVertex2f(15, 35);
        // vermelho com azul
        glColor3f(1, 0, 1);
        glVertex2f(35, 35);
    glEnd();

    // Quarto quadrante
    glLineWidth(5);
    glBegin(GL_LINES);
        for(int i = 0; i < 10; i++){
            glColor3f(1 * alt, 1 * alt, 1 * alt);
            glVertex2f(65, 15 + (i * 2));
            glVertex2f(85, 15 + (i * 2));
        }
    glEnd();

}

void Draw(void){
    // Resetar tela
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    // Draw the axis
    Eixos();

    Figuras();

    glFlush();
}

*/ // EXERCICIO 4 PARTE 1 FIM **********************

 // EXERCICIO 4 PARTE 2 *************************
void Eixos(void){
    glLineWidth(1);
    glBegin(GL_LINES);
        glColor3f(1, 1, 1);
        // Eixo X
        glVertex2f((origX - 50), (origY));
        glVertex2f((origX + 50), (origY));

        // Eixo Y
        glVertex2f(origX, (origY - 50));
        glVertex2f(origX, (origY + 50));
    glEnd();
}

void Figuras(void){

    // Primeiro quadrante (75, 75)
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
        glColor3f(0, 1, 1);
        glVertex2f(65 , 65);
        glColor3f(1, 0, 0);
        glVertex2f(85, 65);
        glColor3f(0, 1, 0);
        glVertex2f(85, 85);
        glColor3f(0, 0, 1);
        glVertex2f(65, 85);
    glEnd();

    // Segundo quadrante (25, 75)
    glBegin(GL_QUADS);
        glColor3f(1, 0, 0);
        glVertex2f(15 , 65);
        glColor3f(0, 1, 1);
        glVertex2f(35, 65);
        glColor3f(0, 0, 1);
        glVertex2f(35, 85);
        glColor3f(0, 1, 0);
        glVertex2f(15, 85);
    glEnd();

    // Terceiro quadrante (25, 25)
    glBegin(GL_QUADS);
        glColor3f(0, 1, 0);
        glVertex2f(15 , 15);
        glColor3f(0, 0, 1);
        glVertex2f(35, 15);
        glColor3f(0, 1, 1);
        glVertex2f(35, 35);
        glColor3f(1, 0, 0);
        glVertex2f(15, 35);
    glEnd();

    // Quarto quadrante
    glBegin(GL_QUADS);
        glColor3f(0, 0, 1);
        glVertex2f(65 , 15);
        glColor3f(0, 1, 0);
        glVertex2f(85, 15);
        glColor3f(1, 0, 0);
        glVertex2f(85, 35);
        glColor3f(0, 1, 1);
        glVertex2f(65, 35);
    glEnd();

}

void Draw(void){
    // Resetar tela
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    // Draw the axis
    Eixos();

    Figuras();

    glFlush();
}

 // EXERCICIO 4 PARTE 2 FIM  ************************


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
    gluOrtho2D(0,100,0,100); // Valores máximos dos eixos
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv){
    // Glut init
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Glut windows size & position
    glutInitWindowSize(720, 640);
    glutInitWindowPosition(50, 0);
    glutCreateWindow("Atividade 2 - Bruno José Placides");
    // Func to draw, initialize and key pressed event
    glutDisplayFunc(Draw);
    Init();
    glutKeyboardFunc(EvtKeyDown);
    glutMainLoop();
}
