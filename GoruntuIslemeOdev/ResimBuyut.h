#pragma once
class ResimBuyut: public ResimIslemBase, public Execute
{
public:
	void execute();
	ResimBuyut();
	~ResimBuyut();
private:
	void ciftSatirlariDiz(cv::Mat *, int, int, int);
	void tekSatirlarDiz(cv::Mat *, int, int);
};

