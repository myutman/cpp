#include "figure.h"
#include <cstdio>

class Rectangle : public Figure {
  public:
    Rectangle(int id, int x, int y, int width, int height);
    void print() const;
    bool is_inside(int px, int py) const;
    void zoom(int factor);
    
  protected:
    int width, height;

};
