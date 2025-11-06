#ifndef MONSTER_H_
#define MONSTER_H_

class Monster
{
public:
    enum Element{FIRE = 0, WATER = 1, GROUND = 2, WIND = 3};

private:
    static const float relation[4][4];      // 상성표
    
    char name[256];                         // 이름
    int health;                             // 생명력
    int attack;                             // 공격력
    int defense;                            // 방어력
    Element element;                        // 속성

    public:
    Monster();
    Monster(const char * s, int h, int a, int d, Element e);
    ~Monster();
    
    Monster(const Monster & monster);
    Monster& operator=(const Monster & monster);

    void SelfAttack(int damage);
    void Attack(Monster & monster);
    void CalculateDamage(const Monster & monster);

    int GetHealth() const { return health; }
    const char * GetName() const { return name; }
};

#endif