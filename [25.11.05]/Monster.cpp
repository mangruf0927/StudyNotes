#include "Monster.h"
#include <iostream>

const float Monster::relation[4][4] = {
    {1.0, 0.5, 0.5, 1.5},                   // 불
    {1.5, 1.0, 1.0, 0.5},                   // 물
    {1.5, 1.0, 1.0, 0.5},                   // 땅
    {0.5, 1.5, 1.5, 1.0}                    // 바람
};

Monster::Monster()
{
    name[0] = '\0';
    health = 0;
    attack = 0;
    defense = 0;
    element = FIRE;
}

Monster::Monster(const char * s, int h, int a, int d, Element e)
{
    int idx = 0; 
    while(idx < 255 && s[idx] != '\0') 
    { 
        name[idx] = s[idx]; 
        idx++; 
    }
    name[idx] = '\0';

    health = h;
    attack = a;
    defense = d;
    element = e;
}

Monster::~Monster()
{
    
}

Monster::Monster(const Monster & monster)
{
    int idx = 0; 
    while(idx < 255 && monster.name[idx] != '\0') 
    { 
        name[idx] = monster.name[idx]; 
        idx++; 
    }
    name[idx] = '\0';

    health = monster.health;
    attack = monster.attack;
    defense = monster.defense;
    element = monster.element;
}

Monster & Monster::operator=(const Monster & monster)
{
    if(this == & monster) return *this;

    int idx = 0; 
    while(idx < 255 && monster.name[idx] != '\0') 
    { 
        name[idx] = monster.name[idx]; 
        idx++; 
    }
    name[idx] = '\0';

    health = monster.health;
    attack = monster.attack;
    defense = monster.defense;
    element = monster.element;

    return *this;
}

void Monster::SelfAttack(int damage)    
{
    if(damage < 1) damage = 1;
    health -= damage;         

    if(health <= 0) health = 0;

    // std::cout << "자기 공격 후 hp : " << health << "\n";
}

void Monster::Attack(Monster & monster)
{
    // std::cout << name << "이 " << monster.name << " 공격 ! \n";

    monster.CalculateDamage(*this);
}  

void Monster::CalculateDamage(const Monster & monster)
{
    int damage = (monster.attack - defense) * relation[monster.element][element];
    if(damage < 1) damage = 1;

    health -= damage;
    if(health <= 0) health = 0;

    // std::cout << name << "의 hp : " << health << "\n";
}
