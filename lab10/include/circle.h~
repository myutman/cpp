#pragma once

#include "figure.h"
#include <cstring>
#include <cstdio>

class Circle : public Figure {
  public:
    Circle(int id, int x, int y, int radius, const char* label);
    ~Circle();
    void print() const;
    bool is_inside(int px, int py) const;
    void zoom(int factor);

  protected:
    int radius;
    char* label_;
};
