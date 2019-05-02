#include "stdafx.h"

void ResimHistogramGer::execute()
{
	int satirUzunlugu = ResimNesne::getNesne()->getAnaImg()->rows;
	int sutunUzunlugu = ResimNesne::getNesne()->getAnaImg()->cols;

	int *buyuk = this->enBuyukPikselBul(satirUzunlugu, sutunUzunlugu);
	int *kucuk = this->enKucukPikselBul(satirUzunlugu, sutunUzunlugu);

	for (int satir = 0; satir < satirUzunlugu; satir++)
		for (int sutun = 0; sutun < sutunUzunlugu; sutun++)
			for (int index = 0; index < 3; index++)
				ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun)[index] =  ( (250 - 50 )* ( (ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun)[index] - kucuk[index]) / (buyuk[index] - kucuk[index])) ) + 50;
	this->goster();
}


