#include "stdafx.h"


void ResimTersle::execute()
{
	int satirUzunlugu = ResimNesne::getNesne()->getAnaImg()->rows;
	int sutunUzunlugu = ResimNesne::getNesne()->getAnaImg()->cols;

	for (int satir = 0; satir < satirUzunlugu; satir++)
		for (int sutun = 0; sutun < sutunUzunlugu ; sutun++)
		{

			ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun)[0] = 255 - ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun)[0];
			ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun)[1] = 255 - ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun)[1];
			ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun)[2] = 255 - ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun)[2];
		}

	this->goster();
}

ResimTersle::ResimTersle()
{
}


ResimTersle::~ResimTersle()
{
}
