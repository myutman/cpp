#include "rectangle.h"

Rectangle::Rectangle(int id, int x, int y, int width, int height): Figure(id, x, y), width(width), height(height){
}

void Rectangle::print() const{
    std::printf("Rectangle %d: x = %d y = %d width = %d height = %d\n", id, x, y, width, height);
}

bool Rectangle::is_inside(int px, int py) const{
    return 2 * px >= 2 * x - width && 2 * px <= 2 * x + width && 2 * py >= 2 * y - height && 2 * py <= 2 * y + height;
}

void Rectangle::zoom(int factor){
    height *= factor;
    width *= factor;
}
