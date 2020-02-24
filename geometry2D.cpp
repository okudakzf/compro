#include <bits/stdc++.h>

double EPS = 1e-10;
struct Point2D {
    Point2D(){}
    Point2D(double x, double y): x(x), y(y) { }

    bool operator ==(const Point2D p){ return abs(p.x - x) < EPS && abs(p.y - y) < EPS; }
    Point2D operator +(const Point2D p){ return Point2D(x + p.x, y + p.y); }
    Point2D operator -(const Point2D p){ return Point2D(x - p.x, y - p.y); }
    Point2D operator *(const double d){ return Point2D(d*x, d*y); }
    double operator *(const Point2D p){ return x*p.x + y*p.y; }
    Point2D operator /(const double d){ return Point2D(x/d, y/d); }
    double norm(){ return sqrt(x*x + y*y); }

    double x, y;
};

struct Line2D {
    //ax + by + c = 0
    Line2D(){}
    Line2D(double a, double b, double c): a(a), b(b), c(c) { }
    Line2D(Point2D p0, Point2D p1){
        if(p0.x == p1.x){
            a = 1;  b = 0;  c = -p1.x;
        }else if(p0.y == p1.y){
            a = 0;  b = 1;  c = -p1.y;
        }else{
            a = p1.y - p0.y;
            b = -(p1.x - p0.x);
            c = p1.x * p0.y - p0.x * p1.y;
        }
    }
    double distance(Point2D p){
        return abs(a * p.x + b * p.y + c)/sqrt(a*a + b*b);
    }

    double a, b, c;
};

struct Circle {
    Circle(){}
    Circle(Point2D center, double radius): center(center), radius(radius) { }
    Circle(Point2D p0, Point2D p1){
        // 2点を直径とする円
        center = (p0 + p1)/2;
        radius = (p0 - p1).norm();
    }
    Circle(Point2D p0, Point2D p1, Point2D p2){
        // 3点の外接円
        double a = (p2 - p1).norm();
        double b = (p0 - p2).norm();
        double c = (p1 - p0).norm();
        double A = a*a*(b*b + c*c - a*a);
        double B = b*b*(c*c + a*a - b*b);
        double C = c*c*(a*a + b*b - c*c);
        
        center = (p0*A + p1*B + p2*C)/(A+B+C);
        radius = a*b*c/sqrt((a+b+c)*(-a+b+c)*(a-b+c)*(a+b-c));
    }

    bool operator ==(const Circle c){ return center == c.center && radius == c.radius; }

    Point2D center;
    double radius;
};
