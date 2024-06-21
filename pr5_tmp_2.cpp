#include <iostream>
#include <string>

class House {
public:
    void setWalls(std::string walls) {
        walls_ = walls;
    }

    void setRoof(std::string roof) {
        roof_ = roof;
    }

    void setWindows(std::string windows) {
        windows_ = windows;
    }

    void showInfo() {
        std::cout << "House built with " << walls_ << " walls, " << roof_ << " roof, and " << windows_ << " windows." << std::endl;
    }

private:
    std::string walls_;
    std::string roof_;
    std::string windows_;
};

class HouseBuilder {
public:
    virtual void buildWalls() = 0;
    virtual void buildRoof() = 0;
    virtual void buildWindows() = 0;
    virtual House* getHouse() = 0;
};

class WoodenHouseBuilder : public HouseBuilder {
public:
    void buildWalls() override {
        house_->setWalls("wooden");
    }

    void buildRoof() override {
        house_->setRoof("wooden");
    }

    void buildWindows() override {
        house_->setWindows("glass");
    }

    House* getHouse() override {
        return house_;
    }

private:
    House* house_ = new House();
};

class HouseDirector {
public:
    HouseDirector(HouseBuilder* builder) : builder_(builder) {}

    void constructHouse() {
        builder_->buildWalls();
        builder_->buildRoof();
        builder_->buildWindows();
    }

private:
    HouseBuilder* builder_;
};

int main() {
    HouseBuilder* woodenHouseBuilder = new WoodenHouseBuilder();
    HouseDirector director(woodenHouseBuilder);

    director.constructHouse();
    House* woodenHouse = woodenHouseBuilder->getHouse();
    woodenHouse->showInfo();

    delete woodenHouseBuilder;
    delete woodenHouse;

    return 0;
}