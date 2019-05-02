#pragma once
#include "Execute.h"
#include "RGBYay.h"
class ResimKarsitYay : public RGBYay, public Execute
{
public:
	void execute();
	ResimKarsitYay();
	~ResimKarsitYay(); 
};

