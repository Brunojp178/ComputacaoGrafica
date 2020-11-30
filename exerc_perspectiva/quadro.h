#ifndef QUADRO_H_
#define QUADRO_H_

class Quadro {
public:
    float pi_x;
    float pi_y;
    float tamanho;
public:
    Quadro();
    Quadro(float piX, float piY, float tam);
    void draw();
    float myrand(float R);
    void tree(float x1, float y1, float length1, float angle1, int depth);
    virtual ~Quadro();
};
#endif
