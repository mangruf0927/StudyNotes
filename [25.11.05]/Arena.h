#ifndef ARENA_H_
#define ARENA_H_

#include "Monster.h"

class Arena
{
private:    
    int capacity;                   // 최대 등록 가능한 몬스터 수
    int count;                      // 현재 등록된 몬스터 수
    Monster * monsters;             // 등록된 몬스터 배열

public:
    Arena(int c);
    Arena();
    ~Arena();

    Arena(const Arena & arena) = delete;
    Arena& operator=(const Arena & arena) = delete;

    void AddMonster(Monster & monster);
    void ShowMaxHP() const;
    void GoToRound();
    int GetCount() const;
    void FindWinner();
};

#endif