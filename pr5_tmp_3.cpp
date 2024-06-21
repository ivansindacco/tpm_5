#include <iostream>
#include <string>

class WideFormatPrinter {
public:
    void printWide(std::string text) {
        std::cout << "Printing wide: " << text << std::endl;
    }
};

class Printer {
public:
    virtual void print(std::string text) = 0;
};

class SimplePrinter : public Printer {
public:
    void print(std::string text) override {
        std::cout << "Printing: " << text << std::endl;
    }
};

class WideToSimplePrinterAdapter : public Printer {
private:
    WideFormatPrinter* widePrinter;

public:
    WideToSimplePrinterAdapter(WideFormatPrinter* printer) : widePrinter(printer) {}

    void print(std::string text) override {
        widePrinter->printWide(text);
    }
};

int main() {
    SimplePrinter simplePrinter;
    WideFormatPrinter widePrinter;

    simplePrinter.print("Work");

    WideToSimplePrinterAdapter adapter(&widePrinter);
    adapter.print("Work!");

    return 0;
}