#include "stdafx.h"


int * RGBYay::enBuyukPikselBul(int satirUzunlugu, int sutunUzunlugu) {


	int buyukSatir = 0;
	int buyukSutun = 0;
	int buyuk = 0;
	int toplamDeger = 0;

	for (int satir = 0; satir < satirUzunlugu; satir++)
		for (int sutun = 0; sutun < sutunUzunlugu; sutun++)
		{
			toplamDeger = 0;
			for (int i = 0; i < ResimNesne::getNesne()->getAnaImg()->channels(); i++)
				toplamDeger += ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun)[i];

			if (buyuk < toplamDeger)
			{
				buyukSatir = satir;
				buyukSutun = sutun;
				buyuk = toplamDeger;
			}
		}
	int *bgr = new int[3];
	bgr[0] = ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(buyukSatir, buyukSutun)[0];
	bgr[1] = ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(buyukSatir, buyukSutun)[1];
	bgr[2] = ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(buyukSatir, buyukSutun)[2];
	return bgr;

}

int * RGBYay::enKucukPikselBul(int satirUzunlugu, int sutunUzunlugu) {

	int kucukSatir = 0;
	int kucukSutun = 0;
	int kucuk = 765;
	int toplamDeger = 0;

	for (int satir = 0; satir < satirUzunlugu; satir++)
		for (int sutun = 0; sutun < sutunUzunlugu; sutun++)
		{
			toplamDeger = 0;
			for (int i = 0; i < ResimNesne::getNesne()->getAnaImg()->channels(); i++)
				toplamDeger += ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun)[i];

			if (kucuk > toplamDeger) {
				kucukSatir = satir;
				kucukSutun = sutun;
				kucuk = toplamDeger;
			}
		}

	int *bgr = new int[3];
	bgr[0] = ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(kucukSatir, kucukSutun)[0];
	bgr[1] = ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(kucukSatir, kucukSutun)[1];
	bgr[2] = ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(kucukSatir, kucukSutun)[2];
	return bgr;

}
