#include <bits/stdc++.h>
using namespace std;

double EPS = 1e-7;
struct Vector2D {
    Vector2D() {}
    Vector2D(double x, double y) : x(x), y(y) {}

    bool operator==(const Vector2D p) {
        return abs(p.x - x) < EPS && abs(p.y - y) < EPS;
    }
    Vector2D operator+(const Vector2D p) { return Vector2D(x + p.x, y + p.y); }
    Vector2D operator-(const Vector2D p) { return Vector2D(x - p.x, y - p.y); }
    Vector2D operator*(const double d) { return Vector2D(d * x, d * y); }
    Vector2D operator/(const double d) { return Vector2D(x / d, y / d); }
    double norm() { return sqrt(x * x + y * y); }
    Vector2D rotate(double theta) {
        return Vector2D(x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta));
    }

    static double dot(Vector2D p0, Vector2D p1) {
        return p0.x * p1.x + p0.y * p1.y;
    }

    double x, y;
};

struct Line2D {
    // ax + by + c = 0
    Line2D() {}
    Line2D(double a, double b, double c) : a(a), b(b), c(c) {}
    Line2D(Vector2D p0, Vector2D p1) {
        if (p0.x == p1.x) {
            a = 1;
            b = 0;
            c = -p1.x;
        } else if (p0.y == p1.y) {
            a = 0;
            b = 1;
            c = -p1.y;
        } else {
            a = p1.y - p0.y;
            b = -(p1.x - p0.x);
            c = p1.x * p0.y - p0.x * p1.y;
        }
    }

    static Vector2D getIntersection(Line2D l1, Line2D l2) {
        return Vector2D(l1.b * l2.c - l2.b * l1.c, l2.a * l1.c - l1.a * l2.c) / (l1.a * l2.b - l1.b * l2.a);
    }

    static bool isParallel(Line2D l1, Line2D l2) {
        return l1.a * l2.b == l1.b * l2.a;
    }

    double getDistance(Vector2D p) {
        return abs(a * p.x + b * p.y + c) / sqrt(a * a + b * b);
    }

    double a, b, c;
};

struct Circle {
    Circle() {}
    Circle(Vector2D center, double radius) : center(center), radius(radius) {}
    Circle(Vector2D p0, Vector2D p1) {
        // 2点を直径とする円
        center = (p0 + p1) / 2;
        radius = (p0 - p1).norm();
    }
    Circle(Vector2D p0, Vector2D p1, Vector2D p2) {
        // 3点の外接円
        double a = (p2 - p1).norm();
        double b = (p0 - p2).norm();
        double c = (p1 - p0).norm();

        double A = a * a * (b * b + c * c - a * a);
        double B = b * b * (c * c + a * a - b * b);
        double C = c * c * (a * a + b * b - c * c);
        center = (p0 * A + p1 * B + p2 * C) / (A + B + C);

        radius = a * b * c / sqrt((a + b + c) * (-a + b + c) * (a - b + c) * (a + b - c));
    }

    bool hasPoint(Vector2D p) {
        return (center - p).norm() <= radius + EPS;
    }
    static vector<Vector2D> getCommonPoint(Circle C0, Circle C1) {
        double d = (C1.center - C0.center).norm();
        double rc = (C0.radius * C0.radius + d * d - C1.radius * C1.radius) / (2 * d);
        double rs = sqrt(C0.radius * C0.radius - rc * rc);
        Vector2D unit = (C1.center - C0.center) / d;
        Vector2D p0 = C0.center + unit * rc + unit.rotate(M_PI / 2) * rs;
        Vector2D p1 = C0.center + unit * rc + unit.rotate(-M_PI / 2) * rs;
        return {p0, p1};
    }
    static bool hasCommonPoint(Circle C0, Circle C1) {
        double d = (C0.center - C1.center).norm();
        return abs(C0.radius - C1.radius) - EPS <= d && d <= (C0.radius + C1.radius) + EPS;
    }

    bool operator==(const Circle c) {
        return center == c.center && radius == c.radius;
    }

    Vector2D center;
    double radius;
};
