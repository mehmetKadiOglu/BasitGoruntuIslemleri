#include "stdafx.h"



void ResimIslemBase::goster()
{
	string resimAd = "image";

	namedWindow(resimAd, WINDOW_AUTOSIZE);
	imshow(resimAd, *(ResimNesne::getNesne()->getAnaImg()));
	waitKey(0);
	destroyWindow(resimAd);
}

ResimIslemBase::ResimIslemBase()
{
	
}
ResimIslemBase::~ResimIslemBase()
{
}
