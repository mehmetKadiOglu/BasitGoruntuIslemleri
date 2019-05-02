#pragma once
#include "Execute.h"
class ResimTersCevir : public ResimIslemBase, public Execute
{

public:
	void execute();
	ResimTersCevir();
	~ResimTersCevir();
};

