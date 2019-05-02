#include "stdafx.h"

void ResimKarsitYay::execute()
{
	int satirUzunlugu = ResimNesne::getNesne()->getAnaImg()->rows;
	int sutunUzunlugu = ResimNesne::getNesne()->getAnaImg()->cols;

	int *buyuk = this->enBuyukPikselBul(satirUzunlugu, sutunUzunlugu);
	int *kucuk = this->enKucukPikselBul(satirUzunlugu, sutunUzunlugu);
	for (int satir = 0; satir < satirUzunlugu; satir++)
		for (int sutun = 0; sutun < sutunUzunlugu; sutun++)
			for (int index = 0; index < 3; index++)
				ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun)[index] = ( (ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun)[index] - kucuk[index]) / ( buyuk[index] - kucuk[index] ) ) * 255;
				//ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun)[index] = (( buyuk[index] - ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun)[index]) / ((buyuk[index] - kucuk[index]) / 1.1)) * 157;
				//ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun)[index] = ((250 / (buyuk[index] - kucuk[index]))* (ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun)[index] - kucuk[index]));
	this->goster();
}

ResimKarsitYay::ResimKarsitYay()
{
}


ResimKarsitYay::~ResimKarsitYay()
{
}
