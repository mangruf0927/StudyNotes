#include <iostream>
#include "Arena.h"

using namespace std;

int main()
{
   Arena arena(5);
   Monster goblin("Goblin", 100, 30, 20, Monster::FIRE);
   Monster orc("Orc", 50, 15, 5, Monster::WATER);
   Monster slime("Slime", 60, 20, 10, Monster::GROUND);

   cout << "[몬스터 등록]\n";
   arena.AddMonster(goblin);
   arena.AddMonster(orc);
   arena.AddMonster(slime);

   cout << "\n현재 등록된 몬스터 수 : " << arena.GetCount() << "\n";

   cout << "\n[생명력 가장 높은 몬스터]\n";
   arena.ShowMaxHP();
   
   cout << "\n[최종 생존자]\n";
   arena.FindWinner();
   arena.ShowMaxHP();

   cout << "\n[몬스터 등록]\n";
   Monster skeleton("Skeleton", 50, 15, 5, Monster::WATER);
   Monster genie("Genie", 120, 50, 20, Monster::WIND);
   Monster dragon("Dragon", 150, 30, 12, Monster::WIND);
   Monster troll("Troll", 40, 8, 3, Monster::FIRE);
   Monster zombie("Zombie", 100, 30, 8, Monster::GROUND);

   arena.AddMonster(skeleton);
   arena.AddMonster(genie);
   arena.AddMonster(dragon);
   arena.AddMonster(troll);
   arena.AddMonster(zombie);

   cout << "\n[생명력 가장 높은 몬스터]\n";
   arena.ShowMaxHP();

   cout << "\n[공격 한 바퀴 후]\n";
   arena.GoToRound();
   arena.ShowMaxHP();

   return 0;
}
