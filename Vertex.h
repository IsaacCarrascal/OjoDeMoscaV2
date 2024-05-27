#pragma once
#include <cmath>

class Vertex{ 
public:
    void setPosx(float angle, int size, int index, float originx, float rotation) {
        posx = originx + (size * cos((angle * index) + rotation));
    }
    void setPosy(float angle, int size, int index, float originy, float rotation) {
        posy = originy + (size * sin((angle * index) + rotation));
    }
    float getPosx() {
        return posx;
    }

    float getPosy() {
        return posy;
    }
private:
    float posx, posy;

};

