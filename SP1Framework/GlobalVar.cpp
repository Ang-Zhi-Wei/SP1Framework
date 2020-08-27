#include "GlobalVar.h"
#include "Entities.h"
#include "firehydrant.h"
#include "Enemy.h"
#include "MiniBoss.h"

Entity* lvlmanager[20] = {nullptr,};  //creates an array of 20 and fills it up with nullptr

Entity* tut_objects[20] = { new firehydrant(27,12),new firehydrant(51,12), new Enemy(23,15),new Enemy(50,15),new Enemy(57,4),new Enemy(20,7), new MiniBoss(20,10),nullptr, };
Entity* lvl1_objects[20] = { new firehydrant(20,15),new firehydrant(20,8), new Enemy(76,12),new Enemy(74,13),new Enemy(63,17),new Enemy(68,7),nullptr, };
Entity*lvl2_objects[20]= { new firehydrant(20,15),new firehydrant(60,8), new Enemy(7,3),new Enemy(74,15),new Enemy(63,17),new Enemy(72,9),new Enemy(23,22) ,nullptr, };
Entity** lvl_array[6] = { tut_objects, lvl1_objects,lvl2_objects,nullptr };


