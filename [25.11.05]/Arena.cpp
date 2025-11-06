#include "Arena.h"
#include <iostream>

Arena::Arena(int c)
{
    capacity = c;
    count = 0;
    monsters = new Monster[c + 1];
}

Arena::Arena()
{
    capacity = 0;
    count = 0;
    monsters = nullptr;
}

Arena::~Arena()
{
    delete [] monsters;
}

void Arena::AddMonster(Monster & monster)
{
    if(count == capacity)
    {
        std::cout << "몬스터를 등록할 수 없습니다.\n";
        return;
    }

    count++;
    monsters[count] = monster;
    
    std::cout << monsters[count].GetName() << "이 등록 되었습니다.\n";
}

void Arena::ShowMaxHP() const
{
    int maxHP = -1, idx = 0;
    for(int i = 1; i <= count; i++)
    {
        if(maxHP <= monsters[i].GetHealth()) 
        {
            maxHP = monsters[i].GetHealth();
            idx = i;
        }
    }
    std::cout << monsters[idx].GetName() << "의 생명력이 " << maxHP << "로 제일 높습니다.\n";
}

void Arena::GoToRound()
{
    if(count <= 1) return;

    // 차례대로 공격
    for(int i = 1; i <= count; i++) 
    { 
        if(monsters[i].GetHealth() <= 0) continue;

        if(i != count) monsters[i].Attack(monsters[i + 1]);
        else monsters[i].Attack(monsters[1]);
    }

    // 생명력이 0이면 삭제
    int shift = 0;
    for(int i = 1; i <= count; i++)
    {
        if(monsters[i].GetHealth() <= 0)
        {
            shift++;
            continue;
        }
        monsters[i - shift] = monsters[i];
    }

    count -= shift;
}

int Arena::GetCount() const
{
    return count;
}

void Arena::FindWinner()
{
    while(count > 1) GoToRound();
}