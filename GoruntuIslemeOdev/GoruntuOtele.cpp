#include "stdafx.h"

void GoruntuOtele::execute() {

	int tasincakSatir = 200;
	int tasincakSutun = 200;

	int satirUzunlugu = ResimNesne::getNesne()->getAnaImg()->rows;
	int sutunUzunlugu = ResimNesne::getNesne()->getAnaImg()->cols;

	Mat yeniResim(satirUzunlugu, sutunUzunlugu, CV_8UC3, Scalar(0, 0, 0));

	for (int satir = 0; satir < satirUzunlugu; satir++)
		for (int sutun = 0; sutun < sutunUzunlugu; sutun++)
			if( (satir + tasincakSatir < satirUzunlugu) && (sutun + tasincakSutun < sutunUzunlugu) )
				yeniResim.at<Vec3b>(satir + tasincakSatir, sutun + tasincakSutun) = ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun);
		
	ResimNesne::getNesne()->setAnaImg(yeniResim);
	this->goster();
}

GoruntuOtele::GoruntuOtele()
{
}


GoruntuOtele::~GoruntuOtele()
{
}
