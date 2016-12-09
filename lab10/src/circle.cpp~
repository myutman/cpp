#include "circle.h"

Circle::Circle(int id, int x, int y, int radius, const char* label): Figure(id, x, y), radius(radius){
    label_ = new char[std::strlen(label) + 1];
    std::strcpy(label_, label);
}

Circle::~Circle(){
    delete[] label_;
}

void Circle::print() const{
    std::printf("Circle %d: x = %d y = %d radius = %d label = %s\n", id, x, y, radius, label_);
}

int sqr(int x){
    return x * x;
}

bool Circle::is_inside(int px, int py) const{
    return sqr(x - px) + sqr(y - py) <= sqr(radius);
}

void Circle::zoom(int factor){
    radius *= factor;
}
