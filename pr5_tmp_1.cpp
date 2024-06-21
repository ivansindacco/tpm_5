#include <iostream>

class Shape {
public:
    virtual void draw() = 0;
};

class ShapeFactory {
public:
    virtual Shape* createShape() = 0;
};

class Circle : public Shape {
public:
    void draw() {
        std::cout << "Circle" << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() {
        std::cout << "Square" << std::endl;
    }
};

class CircleFactory : public ShapeFactory {
public:
    Shape* createShape() {
        return new Circle();
    }
};

class SquareFactory : public ShapeFactory {
public:
    Shape* createShape() {
        return new Square();
    }
};

class FactoryProducer {
public:
    static ShapeFactory* getFactory(std::string factoryType) {
        if (factoryType == "CIRCLE") {
            return new CircleFactory();
        }
        else if (factoryType == "SQUARE") {
            return new SquareFactory();
        }
        return nullptr;
    }
};

int main() {
    ShapeFactory* circleFactory = FactoryProducer::getFactory("CIRCLE");
    Shape* circle = circleFactory->createShape();
    circle->draw();

    ShapeFactory* squareFactory = FactoryProducer::getFactory("SQUARE");
    Shape* square = squareFactory->createShape();
    square->draw();

    return 0;
}