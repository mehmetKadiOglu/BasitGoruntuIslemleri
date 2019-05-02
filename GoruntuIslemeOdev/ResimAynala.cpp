#include "stdafx.h"

void ResimAynala::execute()
{
	Mat piksel(1, 1, CV_8UC3, Scalar(0, 0, 255));
	int satirUzunlugu = ResimNesne::getNesne()->getAnaImg()->rows;
	int sutunUzunlugu = ResimNesne::getNesne()->getAnaImg()->cols;

	for (int satir = 0; satir < satirUzunlugu; satir++)
		for (int sutun = 0; sutun < sutunUzunlugu/2; sutun++)
		{
			piksel.at<Vec3b>(0, 0) = ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun);
			ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun) = ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutunUzunlugu - (sutun + 1));
			ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutunUzunlugu - (sutun + 1)) = piksel.at<Vec3b>(0, 0);
		}

	this->goster();
}

ResimAynala::ResimAynala()
{

}


ResimAynala::~ResimAynala()
{
}
