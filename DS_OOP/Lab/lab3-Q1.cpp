#include <cstdlib>
#include <iostream>
#define PI 3.14
using namespace std;

class Shape
{
protected:
    float volume;
public:
    Shape() { volume = 0; }
    virtual void computeVolume() = 0;
    void printVolume()
    {
        cout << volume << endl;
    }
};


class Cuboid : public Shape
{  
private:
    float length,width,height;
public:
    Cuboid(){}
    Cuboid(float length , float width , float height){
        this->length = length;
        this->width = width;
        this->height = height;
    }
    void computeVolume(){
        volume = length*width*height;
    }
};


class Pyramid : public Shape
{
private:
    float area, height;
public:
    Pyramid(){}
    Pyramid(float area,float height){
        this->area = area;
        this->height = height;
    }
    void computeVolume(){
        volume = area*height/3;
    }
};


class Sphere : public Shape
{
private:
    float radius;
public:
    Sphere(){}
    Sphere(float radius){
        this->radius = radius;
    }
    void computeVolume(){
        volume = (4.0/3.0)*radius*radius*radius*(3.14);
    }
};

int main()
{
    float a, b, c;
    Shape *shape;

    cin >> a >> b >> c; // Enter the height and width of Rectangle
    Cuboid cub(a, b, c);

    cin >> a >> b; // Enter the bottom and height of Triangle
    Pyramid pyr(a, b);

    cin >> a; // Enter the radius of Circle
    Sphere sph(a);

    shape = &cub;
    shape->computeVolume();
    shape->printVolume();

    shape = &pyr;
    shape->computeVolume();
    shape->printVolume();

    shape = &sph;
    shape->computeVolume();
    shape->printVolume();

    return 0;
}