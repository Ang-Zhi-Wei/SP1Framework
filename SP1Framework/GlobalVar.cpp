#include "GlobalVar.h"
#include "Entities.h"
#include "firehydrant.h"
#include "Enemy.h"
#include "MiniBoss.h"

Entity* lvlmanager[20] = {nullptr,};  //creates an array of 20 and fills it up with nullptr

Entity* tut_objects[20] = { new firehydrant(27,12),new firehydrant(51,12), new Enemy(23,15),new Enemy(50,15),new Enemy(57,4),nullptr, };
Entity* lvl1_objects[20] = { new firehydrant(20,15),new firehydrant(20,8), new Enemy(76,12),new Enemy(74,13),new Enemy(63,17),new Enemy(68,7),nullptr, };
Entity*lvl2_objects[20]= { new firehydrant(20,15),new firehydrant(60,8), new Enemy(7,3),new Enemy(74,15),new Enemy(63,17), new MiniBoss(20,10),nullptr, };
Entity* lvl3_objects[20] = { new firehydrant(20,12),new Enemy(60,10),new Enemy(60,13),new Enemy(72,15),new Enemy(63,7),new Enemy(48,12),nullptr };
Entity* mumlvl_objects[20] = { new firehydrant(20,12),new firehydrant(66,12),new Enemy(54,19),new Enemy(25,19),new Enemy(54,5),new Enemy(25,5),new MiniBoss(39,11),nullptr };
Entity* Dadlvl_objects[20] = { new firehydrant(10,14),new firehydrant(44,12),new Enemy(15,3),new Enemy(17,12),new Enemy(28,12),new Enemy(47,3),new MiniBoss(69,17),nullptr };
Entity** lvl_array[6] = { tut_objects, lvl1_objects,lvl2_objects,lvl3_objects,mumlvl_objects,Dadlvl_objects};




Entity playerstats(100, 1);
