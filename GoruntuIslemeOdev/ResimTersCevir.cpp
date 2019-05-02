#include "stdafx.h"



void ResimTersCevir::execute()
{
	Mat piksel(1, 1, CV_8UC3, Scalar(0, 0, 255));
	int satirUzunlugu = ResimNesne::getNesne()->getAnaImg()->rows;
	int sutunUzunlugu = ResimNesne::getNesne()->getAnaImg()->cols;
	cout << satirUzunlugu << " satirr" << endl;
	cout << sutunUzunlugu << " sutun" << endl;
	for (int satir = 0; satir < satirUzunlugu/2; satir++)
		for (int sutun = 0; sutun < sutunUzunlugu; sutun++)
		{
			piksel.at<Vec3b>(0, 0) = ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun);
			ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun) = ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satirUzunlugu - (satir+1), sutun);
			ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satirUzunlugu - (satir + 1), sutun) = piksel.at<Vec3b>(0, 0);
		}

	this->goster();
}

ResimTersCevir::ResimTersCevir()
{

}


ResimTersCevir::~ResimTersCevir()
{
}
