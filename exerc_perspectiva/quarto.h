#ifndef QUARTO_H_
#define QUARTO_H_


class Quarto {
public:
    float pi_x;
    float pi_y;
    float pf_x;
    float pf_y;

    float maxim_x;
    float maxim_y;

    float wallcolor_r;
    float wallcolor_g;
    float wallcolor_b;
    float color_degree;

public:
	Quarto();
	Quarto(float piX, float piY, float pfX, float pfY);
	void walls();
	void door();
	void draw();
	virtual ~Quarto();
};

#endif
