#pragma once
#include "Execute.h"
class ResimAynala : public ResimIslemBase, public Execute
{
public:
	void execute();
	ResimAynala();
	~ResimAynala();
};

