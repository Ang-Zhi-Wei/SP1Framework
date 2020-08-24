
#pragma once
#include "Entities.h"
#include <Windows.h>
#include "game.h"
#include "Framework/console.h"

class firehydrant : public Entity
{
protected:
	static int total_no_of_hydrant;

	COORD position;
public:

	firehydrant(int x = 10, int y = 10);
	~firehydrant();

	COORD get_coord(void);

	static void SetTotalHydrant(int SetTotalHr);
	static int GetTotalHydrant();

	void EVERYTHINGUPDATE();


	
};

