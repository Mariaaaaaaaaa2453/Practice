никсик💖, [24. 4. 2024, 09:16:50]:
#include <iostream>
#include <string>

using namespace std;

// Base class for all animal types
class BaseCreature {
protected:
    string _identifier;
    double _weightKg;
    string _nativeRegion;

public:
    BaseCreature(string id, double weight, string region)
        : _identifier(id), _weightKg(weight), _nativeRegion(region) {}

    virtual void consumeFood() = 0;
    virtual void restMode() = 0;
    virtual void navigate() = 0;
    virtual void communicate() = 0;
};

// Interfaces for different behaviors
class IWaterActivity {
public:
    virtual void swim() = 0;
};

class IAirActivity {
public:
    virtual void fly() = 0;
};

// Specific classes implementing the behaviors
class CatSpecies : public BaseCreature {
public:
    CatSpecies(string id, double weight, string region)
        : BaseCreature(id, weight, region) {}

    void consumeFood() override {
        cout << _identifier << " consumes a mouse." << endl;
    }

    void restMode() override {
        cout << _identifier << " lies in the sun." << endl;
    }

    void navigate() override {
        cout << _identifier << " stalks its territory." << endl;
    }

    void communicate() override {
        cout << _identifier << " purrs contentedly." << endl;
    }
};

class DogSpecies : public BaseCreature, public IWaterActivity {
public:
    DogSpecies(string id, double weight, string region)
        : BaseCreature(id, weight, region) {}

    void consumeFood() override {
        cout << _identifier << " devours a large bone." << endl;
    }

    void restMode() override {
        cout << _identifier << " sleeps in its kennel." << endl;
    }

    void navigate() override {
        cout << _identifier << " patrols the yard." << endl;
    }

    void communicate() override {
        cout << _identifier << " barks at a passerby." << endl;
    }

    void swim() override {
        cout << _identifier << " enjoys a dip in the lake." << endl;
    }
};

class BirdSpecies : public BaseCreature, public IAirActivity {
public:
    BirdSpecies(string id, double weight, string region)
        : BaseCreature(id, weight, region) {}

    void consumeFood() override {
        cout << _identifier << " pecks at a piece of fruit." << endl;
    }

    void restMode() override {
        cout << _identifier << " nests in a high tree." << endl;
    }

    void navigate() override {
        cout << _identifier << " hops along the branch." << endl;
    }

    void communicate() override {
        cout << _identifier << " sings a morning song." << endl;
    }

    void fly() override {
        cout << _identifier << " glides across the sky." << endl;
    }
};

class WaterfowlSpecies : public BaseCreature, public IWaterActivity, public IAirActivity {
public:
    WaterfowlSpecies(string id, double weight, string region)
        : BaseCreature(id, weight, region) {}

    void consumeFood() override {
        cout << _identifier << " digs for worms near the pond." << endl;
    }

    void restMode() override {
        cout << _identifier << " rests on one leg at the water's edge." << endl;
    }

    void navigate() override {
        cout << _identifier << " wades through shallow waters." << endl;
    }

    void communicate() override {
        cout << _identifier << " quacks during the early hours." << endl;
    }

    void swim() override {
        cout << _identifier << " paddles smoothly in the water." << endl;
    }

    void fly() override {
        cout << _identifier << " takes off from the pond with ease." << endl;
    }
};

int main() {
    CatSpecies cat("Milo", 4.2, "Urban areas");
    DogSpecies dog("Max", 20.5, "Rural areas");
    BirdSpecies parrot("Charlie", 0.9, "Tropical forests");
    WaterfowlSpecies duck("Daisy", 3.5, "Lakes and rivers");

    cat.consumeFood();
    cat.restMode();
    cat.navigate();
    cat.communicate();

    dog.consumeFood();
    dog.restMode();
    dog.navigate();
    dog.communicate();
    dog.swim();

    parrot.consumeFood();
    parrot.restMode();
    parrot.navigate();
    parrot.communicate();
    parrot.fly();

duck.consumeFood();
    duck.restMode();
    duck.navigate();
    duck.communicate();
    duck.swim();
    duck.fly();

    return 0;
}