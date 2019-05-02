#pragma once
class ResimKarsitligi : public ResimIslemBase, public Execute
{
private:
	void girdiAl(int *, int*);
public:
	void execute();
	ResimKarsitligi();
	~ResimKarsitligi();

};

