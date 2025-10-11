#include <iostream>

using namespace std;

class IDamageable {
public:
    virtual void ReceiveDamage(float damage) = 0;
    virtual float getHealth() const = 0;
};

class Character : public IDamageable {
private:
    float health;
    float damage;
public:
    Character(float h, float d) : health(h), damage(d) {}
    void Attack(IDamageable& target) {
        target.ReceiveDamage(damage);
    }
    void ReceiveDamage(float damage) {
        health -= damage;
    }
    float getHealth() const {
        return health;
    }
};

class Enemy : public Character {
public:
    Enemy(float h, float d) : Character(h, d) {}
};

class Player : public Character {
public:
    Player(float h, float d) : Character(h, d) {}
};

class Barricade : public IDamageable {
private:
    float health;
public:
    Barricade(float h) : health(h) {}
    void ReceiveDamage(float damage) {
        health -= damage;
    }
    float getHealth() const {
        return health;
    }
};

int main() {
    
}
