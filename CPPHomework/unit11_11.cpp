/*
 * @Author: KendrickKan 
 * @Date: 2020-11-01 13:32:19 
 * @Last Modified by:   KendrickKan 
 * @Last Modified time: 2020-11-01 13:32:19 
 */
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repp(i, a, b) for (int i = a; i <= b; i++)
#define rep1(i, a, b) for (int i = a; i >= b; i--)
#define mem0(a) memset(a, 0, sizeof(a))
#define memfu1(a) memset(a, -1, sizeof(a))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define EPS 1e-10
#define MOD 1e9 + 7
#define PI acos(-1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
class Point
{
public:
    int x;
    int y;
};
class ClosedShape
{
public:
    virtual void moveOff(int xoff, int yoff);
    virtual double getArea();
    virtual double getPerimeter();
    virtual void show();
};
class Circle : ClosedShape
{
private:
    Point p;
    int r;

public:
    virtual void moveOff(int xoff, int yoff);
    virtual double getArea();
    virtual double getPerimeter();
    virtual void show();
};
void Circle::moveOff(int xoff, int yoff)
{
    p.x += xoff;
    p.y += yoff;
}
double Circle::getArea()
{
    return r * r * PI;
}
double Circle::getPerimeter()
{
    return 2 * PI * r;
}
void Circle::show()
{
    cout << "Circle (" << p.x << "," << p.y << ") R=" << r << endl;
}
class Rectangle : ClosedShape
{
private:
    Point topLeft;
    int wide;
    int high;

public:
    virtual void moveOff(int xoff, int yoff);
    virtual double getArea();
    virtual double getPerimeter();
    virtual void show();
};
void Rectangle::moveOff(int xoff, int yoff)
{
    topLeft.x += xoff;
    topLeft.y += yoff;
}
double Rectangle::getArea()
{
    return wide * high;
}
double Rectangle::getPerimeter()
{
    return 2 * (wide + high);
}
void Rectangle::show()
{
    cout << "Rectangle (" << topLeft.x << "," << topLeft.y << ") wide=" << wide << " high=" << high << endl;
}
class Triangle : ClosedShape
{
private:
    Point vertexes[3];

public:
    virtual void moveOff(int xoff, int yoff);
    virtual double getArea();
    virtual double getPerimeter();
    virtual void show();
};
void Triangle::moveOff(int xoff, int yoff)
{
    for (int i = 0; i < 3; i++)
    {
        vertexes[i].x += xoff;
        vertexes[i].y += yoff;
    }
}
double Triangle::getArea()
{
    double a = sqrt((vertexes[0].x - vertexes[1].x) * (vertexes[0].x - vertexes[1].x) + (vertexes[0].y - vertexes[1].y) * (vertexes[0].y - vertexes[1].y));
    double b = sqrt((vertexes[2].x - vertexes[1].x) * (vertexes[2].x - vertexes[1].x) + (vertexes[2].y - vertexes[1].y) * (vertexes[2].y - vertexes[1].y));
    double c = sqrt((vertexes[0].x - vertexes[2].x) * (vertexes[0].x - vertexes[2].x) + (vertexes[0].y - vertexes[2].y) * (vertexes[0].y - vertexes[2].y));
    double p = (a + b + c) * 1.0 / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
double Triangle::getPerimeter()
{
    double a = sqrt((vertexes[0].x - vertexes[1].x) * (vertexes[0].x - vertexes[1].x) + (vertexes[0].y - vertexes[1].y) * (vertexes[0].y - vertexes[1].y));
    double b = sqrt((vertexes[2].x - vertexes[1].x) * (vertexes[2].x - vertexes[1].x) + (vertexes[2].y - vertexes[1].y) * (vertexes[2].y - vertexes[1].y));
    double c = sqrt((vertexes[0].x - vertexes[2].x) * (vertexes[0].x - vertexes[2].x) + (vertexes[0].y - vertexes[2].y) * (vertexes[0].y - vertexes[2].y));
    return a + b + c;
}
void Triangle::show()
{
    cout << "Triangle" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "(" << vertexes[i].x << "," << vertexes[i].y << ")" << endl;
    }
}
int main()
{
    FastIO;

    return 0;
}