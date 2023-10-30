#include <iostream>
#include <string>

class Hero {
public:
    virtual std::string attack() = 0;
};

class Archer : public Hero {
public:
    std::string attack() override {
        return "Archer is attacking with arrows";
    }
};

class Knight : public Hero {
public:
    std::string attack() override {
        return "Knight is attacking with a sword";
    }
};

class Enemy {
public:
    virtual std::string defense() = 0;
};

class Witch : public Enemy {
public:
    std::string defense() override {
        return "Witch is defending with magic";
    }
};

class Goblin : public Enemy {
public:
    std::string defense() override {
        return "Goblin is defending by running away";
    }
};

class GameFactory {
public:
    virtual Hero* createHero() = 0;
    virtual Enemy* createEnemy() = 0;
};

class LowRangeGameFactory : public GameFactory {
public:
    Hero* createHero() override {
        return new Knight();
    }

    Enemy* createEnemy() override {
        return new Goblin();
    }
};

class LongRangeGameFactory : public GameFactory {
public:
    Hero* createHero() override {
        return new Archer();
    }

    Enemy* createEnemy() override {
        return new Witch();
    }
};

int main() {
    GameFactory* longRange = new LongRangeGameFactory();
    GameFactory* lowRange = new LowRangeGameFactory();

    Hero* hero1 = longRange->createHero();
    Enemy* enemy1 = longRange->createEnemy();

    Hero* hero2 = lowRange->createHero();
    Enemy* enemy2 = lowRange->createEnemy();

    std::cout << hero1->attack() << std::endl;
    std::cout << enemy2->defense() << std::endl;

    std::cout << hero2->attack() << std::endl;
    std::cout << enemy1->defense() << std::endl;

    delete hero1;
    delete enemy1;
    delete hero2;
    delete enemy2;

    delete longRange;
    delete lowRange;

    return 0;
}
