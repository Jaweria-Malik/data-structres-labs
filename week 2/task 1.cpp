#include<iostream>
using namespace std;
class shape
{
public:
	virtual double area() = 0;
};
class circle :public shape {
private :
	double radius;
public:
	circle(double r) {
		radius = r;

	}
	double area()
	{
		return 3.14 * radius * radius;
	}
};
class rectangle :public shape
{
private:
	double length;
	double width;
public:
	rectangle(double l, double w) {
		length = l;
		width = w;
	}
	double area() {
		return length * width;

	}

};
int main(){
	circle c(5);
	rectangle r(4, 6);
	cout << "Circle Area: " << c.area() << endl;
	cout << "Rectangle Area: " << r.area() << endl;

	return 0;
}

