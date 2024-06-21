#include <iostream>
#include <vector>

class Mediator;

class Colleague {
protected:
    Mediator* mediator;
    int id;

public:
    Colleague(Mediator* mediator, int id) : mediator(mediator), id(id) {}

    int getId() {
        return id;
    }

    virtual void sendMessage(int receiverId, const std::string& message) = 0;
    virtual void receiveMessage(int senderId, const std::string& message) = 0;
};

class Mediator {
public:
    virtual void sendMessage(int senderId, int receiverId, const std::string& message) = 0;
};

class ConcreteMediator : public Mediator {
private:
    std::vector<Colleague*> colleagues;

public:
    void addColleague(Colleague* colleague) {
        colleagues.push_back(colleague);
    }

    void sendMessage(int senderId, int receiverId, const std::string& message) override {
        for (auto colleague : colleagues) {
            if (colleague->getId() == receiverId) {
                colleague->receiveMessage(senderId, message);
                break;
            }
        }
    }
};

class ConcreteColleague : public Colleague {
public:
    ConcreteColleague(Mediator* mediator, int id) : Colleague(mediator, id) {}

    void sendMessage(int receiverId, const std::string& message) override {
        mediator->sendMessage(id, receiverId, message);
    }

    void receiveMessage(int senderId, const std::string& message) override {
        std::cout << "Colleague " << id << " received message from Colleague " << senderId << ": " << message << std::endl;
    }
};

int main() {
    ConcreteMediator mediator;
    ConcreteColleague colleague1(&mediator, 1);
    ConcreteColleague colleague2(&mediator, 2);

    mediator.addColleague(&colleague1);
    mediator.addColleague(&colleague2);

    colleague1.sendMessage(2, "Hello, colleague 2!");
    colleague2.sendMessage(1, "Hi, colleague 1!");

    return 0;
}