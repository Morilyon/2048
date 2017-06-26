#ifndef TZFE_H
#define TZFE_H


int rando();
int randx();

class Tzfe{
public:
    Tzfe();
    ~Tzfe() = default;
    void print() const;
    int control();

private:
    //control
    void upper();
    void under();
    void left();
    void right();
    int win() const;
    //generate
    int generate();

    int value[4][4];
};

#endif
