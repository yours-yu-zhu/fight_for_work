#include "15_5.h"

void ex15_21(){
    //test three class
    Shape *p1 = new Rectangle("rectangle", 2, 3);
    Shape *p2 = new Square("square", 2);
    Shape *p3 = new Circle("circle", 2);
    cout << p1->getName() << " area: " << p1->area() << " perimeter: " << p1->perimeter() << endl;
    cout << p2->getName() << " area: " << p2->area() << " perimeter: " << p2->perimeter() << endl;
    cout << p3->getName() << " area: " << p3->area() << " perimeter: " << p3->perimeter() << endl;
}
 
int main() {
    ex15_21();

    return 0;

}
