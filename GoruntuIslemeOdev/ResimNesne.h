#pragma once
class ResimNesne
{
private:
	static ResimNesne* nesne;
	ResimNesne();


	char * resimAdi = nullptr;
	cv::Mat anaImg; // resmi tutan degiskenimiz
	char * getResimAdi();
	
	
public:
	
	void setAnaImg();
	void setAnaImg(cv::Mat);
	void setResimAdi(char *);

	static ResimNesne* getNesne();
	cv::Mat* getAnaImg();
};
