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

std::string colorChange(COLOR inSwitch)
{
    switch (inSwitch)
    {
        case 1: return "Red";
        case 2: return "Blue";
        case 3: return "Green";
        case 4: return "None";
    }
    return "Not defined";
}

class Figure
{
public:
    double x{0};
    double y{0};
    double areaFigure{0};

    double pointXminus{}, pointXplus{};     // Point A,D and B,C: x - coordinates
    double pointYminus{}, pointYplus{};     // Point D,C and A,B: y - coordinates
    COLOR colorFigure;

    Figure()
    {
        int answerColor;
        std::cout << "Enter the coordinates of the center of the shape (x,y):\n<- ";
        std::cin >> x >> y;
        std::cout << "Enter the shape color:\n1. Red\n2. Blue\n3. Green\n4. None\n<- ";
        std::cin >> answerColor;
        switch (answerColor)
        {
            case RED:
                colorFigure = RED;
                break;
            case BLUE:
                colorFigure = BLUE;
                break;
            case GREEN:
                colorFigure = GREEN;
                break;
            case NONE:
                colorFigure = NONE;
            default:
                break;
        }
    }
};

class Circle: public Figure
{
    double radius{0};

public:

    Circle() : Figure()
    {
        std::cout << "Enter the radius:\n<- ";
        std::cin >> radius;

        areaFigure = atan(1) * 4 * radius;
        pointXminus = x - radius;
        pointXplus = x + radius;
        pointYminus = y - radius;
        pointYplus = y + radius;
    }

    void showCircleInfo()
    {
        std::cout << "Area circle: " << areaFigure << " Color: " << colorChange(colorFigure) << std::endl;
        std::cout << "The figure is described by a rectangle with the coordinates of the vertices: A(" << pointXminus << "," << pointYplus << ") B(" << pointXplus << ","
                    << pointYplus << ") C(" << pointXplus << "," << pointYminus << ") D(" << pointXminus << "," << pointYminus << ")" << std::endl;
    }
};

class Square: public Figure
{
    double side{0};

public:

    Square() : Figure()
    {
        std::cout << "Enter the side length:\n<- ";
        std::cin >> side;

        areaFigure = side * side;
        pointXminus = x - side / 2;
        pointXplus = x + side / 2;
        pointYminus = y - side / 2;
        pointYplus = y + side / 2;
    }

    void showSquareInfo()
    {
        std::cout << "Area square: " << areaFigure << " Color: " << colorChange(colorFigure) << std::endl;
        std::cout << "The figure is described by a rectangle with the coordinates of the vertices: A(" << pointXminus << "," << pointYplus << ") B(" << pointXplus << ","
                  << pointYplus << ") C(" << pointXplus << "," << pointYminus << ") D(" << pointXminus << "," << pointYminus << ")" << std::endl;
    }
};

class Triangle: public Figure
{
    double side{0};

public:

    Triangle() : Figure()
    {
        std::cout << "Enter the side length:\n<- ";
        std::cin >> side;

        areaFigure = side * side * sqrt(3) / 4;
        pointXminus = x - side / 2;
        pointXplus = x + side / 2;
        pointYminus = y - side / 2;
        pointYplus = y + side / 2;
    }

    void showTriangleInfo()
    {
        std::cout << "Area triangle: " << areaFigure << " Color: " << colorChange(colorFigure) << std::endl;
        std::cout << "The figure is described by a rectangle with the coordinates of the vertices: A(" << pointXminus << "," << pointYplus << ") B(" << pointXplus << ","
                  << pointYplus << ") C(" << pointXplus << "," << pointYminus << ") D(" << pointXminus << "," << pointYminus << ")" << std::endl;
    }
};

class Rectangle: public Figure
{
    double sideA{0};
    double sideB{0};

public:

    Rectangle() : Figure()
    {
        std::cout << "Enter the side length(A,B):\n<- ";
        std::cin >> sideA >> sideB;

        areaFigure = sideA * sideB;
        pointXminus = x - sideB / 2;
        pointXplus = x + sideB / 2;
        pointYminus = y - sideA / 2;
        pointYplus = y + sideA / 2;
    }

    void showRectangleInfo()
    {
        std::cout << "Area square: " << areaFigure << " Color: " << colorChange(colorFigure) << std::endl;
        std::cout << "The figure is described by a rectangle with the coordinates of the vertices: A(" << pointXminus << "," << pointYplus << ") B(" << pointXplus << ","
                  << pointYplus << ") C(" << pointXplus << "," << y - sideB / 2 << ") D(" << pointXminus << "," << pointYminus << ")" << std::endl;
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
            circle->showCircleInfo();
            delete circle;
            break;
        case SQUARE:
            square = new Square;
            square->showSquareInfo();
            delete square;
            break;
        case TRIANGLE:
            triangle = new Triangle();
            triangle->showTriangleInfo();
            delete triangle;
            break;
        case RECTANGLE:
            rectangle = new Rectangle();
            rectangle->showRectangleInfo();
            delete rectangle;
            break;
        default:
            break;

    }

}
