#include <iostream>
#include <cmath>

enum COLOR
{
    RED = 1,
    BLUE,
    GREEN,
    NONE
};

enum FIGURE
{
    CIRCLE = 1,
    SQUARE,
    TRIANGLE,
    RECTANGLE
};

class Figure
{
public:
    double x{0};
    double y{0};
    std::string colorFigure;

    void setParameter()
    {
        int answerColor;
        std::cout << "Enter the coordinates of the center of the shape (x,y):\n<- ";
        std::cin >> x >> y;
        std::cout << "Enter the shape color:\n1. Red\n2. Blue\n3. Green\n4. None\n<- ";
        std::cin >> answerColor;
        switch (answerColor)
        {
            case RED:
                colorFigure = "Red";
                break;
            case BLUE:
                colorFigure = "Blue";
                break;
            case GREEN:
                colorFigure = "Green";
                break;
            case NONE:
                colorFigure = "None";
            default:
                break;
        }
    }
};

class Circle: public Figure
{
public:
    double radius{0};

    void setParameterCircle()
    {
        setParameter();
        std::cout << "Enter the radius:\n<- ";
        std::cin >> radius;
    }

    void showCircleInfo()
    {
        std::cout << "Area circle: " << atan(1) * 4 * radius << " Color: " << colorFigure << std::endl;
        std::cout << "The figure is described by a rectangle with the coordinates of the vertices: A(" << x - radius << "," << y + radius << ") B(" << x + radius << ","
                    << y + radius << ") C(" << x + radius << "," << y - radius << ") D(" << x - radius << "," << y - radius << ")" << std::endl;
    }
};

class Square: public Figure
{
public:
    double side{0};

    void setParameterSquare()
    {
        setParameter();
        std::cout << "Enter the side length:\n<- ";
        std::cin >> side;
    }
    void showSquareInfo()
    {
        std::cout << "Area square: " << side * side << " Color: " << colorFigure << std::endl;
        std::cout << "The figure is described by a rectangle with the coordinates of the vertices: A(" << x - side / 2 << "," << y + side / 2 << ") B(" << x + side / 2 << ","
                  << y + side / 2 << ") C(" << x + side / 2 << "," << y - side / 2 << ") D(" << x - side / 2 << "," << y - side / 2 << ")" << std::endl;
    }
};

class Triangle: public Figure
{
public:
    double side{0};

    void setParameterTriangle()
    {
        setParameter();
        std::cout << "Enter the side length:\n<- ";
        std::cin >> side;
    }
    void showTriangleInfo()
    {
        std::cout << "Area square: " << side * side * sqrt(3) / 4 << " Color: " << colorFigure << std::endl;
        std::cout << "The figure is described by a rectangle with the coordinates of the vertices: A(" << x - side / 2 << "," << y + side / 2 << ") B(" << x + side / 2 << ","
                  << y + side / 2 << ") C(" << x + side / 2 << "," << y - side / 2 << ") D(" << x - side / 2 << "," << y - side / 2 << ")" << std::endl;
    }
};

class Rectangle: public Figure
{
public:
    double sideA{0};
    double sideB{0};

    void setParameterRectangle()
    {
        setParameter();
        std::cout << "Enter the side length(A,B):\n<- ";
        std::cin >> sideA >> sideB;
    }
    void showRectangleInfo()
    {
        std::cout << "Area square: " << sideA * sideB << " Color: " << colorFigure << std::endl;
        std::cout << "The figure is described by a rectangle with the coordinates of the vertices: A(" << x - sideA / 2 << "," << y + sideB / 2 << ") B(" << x + sideA / 2 << ","
                  << y + sideB / 2 << ") C(" << x + sideA / 2 << "," << y - sideB / 2 << ") D(" << x - sideA / 2 << "," << y - sideB / 2 << ")" << std::endl;
    }
};

int main()
{
    int answer;
    std::cout << "Enter the shape:\n1. circle\n2. square\n3. triangle\n4. rectangle\n<- ";
    std::cin >> answer;
    switch (answer)
    {
        Circle* circle;
        Square* square;
        Triangle* triangle;
        Rectangle* rectangle;
        case CIRCLE:
            circle = new Circle();
            circle->setParameterCircle();
            circle->showCircleInfo();
            delete circle;
            break;
        case SQUARE:
            square = new Square;
            square->setParameterSquare();
            square->showSquareInfo();
            delete square;
            break;
        case TRIANGLE:
            triangle = new Triangle();
            triangle->setParameterTriangle();
            triangle->showTriangleInfo();
            delete triangle;
            break;
        case RECTANGLE:
            rectangle = new Rectangle();
            rectangle->setParameterRectangle();
            rectangle->showRectangleInfo();
            delete rectangle;
            break;
        default:
            break;
    }
}
