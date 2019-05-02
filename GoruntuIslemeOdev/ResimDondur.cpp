#include "stdafx.h"

void ResimDondur::execute()
{
	
	int satirUzunlugu = ResimNesne::getNesne()->getAnaImg()->rows;
	int sutunUzunlugu = ResimNesne::getNesne()->getAnaImg()->cols;
	Mat piksel(satirUzunlugu, sutunUzunlugu, CV_8UC3, Scalar(0, 0, 255));


	for (int satir = 0; satir < satirUzunlugu; satir++)
		for (int sutun = 0; sutun < sutunUzunlugu; sutun++)
		{
			int x = (-1 * (sutun - (sutunUzunlugu / 2))) - (0 * (0 - 0)) + (sutunUzunlugu / 2);
			int y = (0 * (50 - 25)) + 1 * ((satir - 0)) + 0;
		//	int x = (-1 * (sutun - (sutunUzunlugu))) - (0 * (0 - 0)) + (sutunUzunlugu);
			//int y = (0 * (50 - 25)) + 1 * ((satir - satirUzunlugu / 2)) + satirUzunlugu/2;

			
			if (x >= sutunUzunlugu)
				piksel.at<Vec3b>(y, x - 1) = ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun);
			else if (y >= satirUzunlugu)
				piksel.at<Vec3b>(y - 1, x) = ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun);
			else if (y >= satirUzunlugu && x >= sutunUzunlugu)
				piksel.at<Vec3b>(y-1, x-1) = ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun);
			else
				piksel.at<Vec3b>(y , x ) = ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun);
		}
	
	ResimNesne::getNesne()->setAnaImg(piksel);

	this->goster();
}
