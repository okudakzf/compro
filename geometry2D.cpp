#include <bits/stdc++.h>
using namespace std;

struct Point2D {
    Point2D(double A, double B){
        x = A;  y = B;
    }
    bool operator ==(const Point2D &p){
        return p.x == this->x && p.y == this->y;
    }
    double x, y;
};

struct Line2D {
    //ax + by + c = 0
    Line2D(double A, double B, double C){
        a = A;  b = B;  c = C;
    }
    Line2D(Point2D* p0, Point2D* p1){
        if(p0->x == p1->x){
            a = 1;  b = 0;  c = -p1->x;
        }else if(p0->y == p1->y){
            a = 0;  b = 1;  c = -p1->y;
        }else{
            a = p1->y - p0->y;
            b = -(p1->x - p0->x);
            c = p1->x*p0->y - p0->x*p1->y;
        }
    }
    double distance(Point2D* p){
        return abs(a * p->x + b * p->y + c)/sqrt(a*a + b*b);
    }
    double a, b, c;
};
