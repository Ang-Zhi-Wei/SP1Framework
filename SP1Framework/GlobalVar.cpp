#include "GlobalVar.h"
#include "Entities.h"
#include "firehydrant.h"
#include "Enemy.h"

Entity* lvlmanager[20] = {nullptr,};  //creates an array of 20 and fills it up with nullptr

Entity* tut_objects[20] = { new firehydrant(27,12), new firehydrant(51,12), new Enemy(23,15),new Enemy(50,15),new Enemy(57,4),nullptr, };

Entity** lvl_array[5] = { tut_objects, nullptr, };