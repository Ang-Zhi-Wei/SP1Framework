#include "GlobalVar.h"
#include "Entities.h"
#include "firehydrant.h"

Entity* lvlmanager[20] = {nullptr,};  //creates an array of 20 and fills it up with nullptr

Entity* tut_objects[20] = { new firehydrant(27,12), new firehydrant(51,12), nullptr, };

Entity** lvl_array[5] = { tut_objects, nullptr, };