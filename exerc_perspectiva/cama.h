#ifndef CAMA_H_
#define CAMA_H_

class Cama{
public:
    float pi_x, pi_y, largura, offset, altura, comprimento;
    float cor_r, cor_g, cor_b;
public:
    Cama();
    Cama(float piX, float piY, float largura);
    void cabeceira();
    void colchao();
    void draw();
    virtual ~Cama();
};

#endif
