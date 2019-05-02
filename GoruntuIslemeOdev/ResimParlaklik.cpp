#include "stdafx.h"



void ResimParlaklik::execute() {

	char deger;
	int parlaklikMiktari, katMiktari;
	cout << endl << endl << "Artırmak icin + eksiltmek icin -";
	cin>> deger;
	deger == '-' ? parlaklikMiktari = -5 : parlaklikMiktari = 5;
	cout << endl << "Kat miktarini Giriniz";
	cin >> katMiktari;

	for (int satir = 0; satir < ResimNesne::getNesne()->getAnaImg()->rows; satir++)
		for (int sutun = 0; sutun < ResimNesne::getNesne()->getAnaImg()->cols; sutun++)
			for (int i = 0; i < ResimNesne::getNesne()->getAnaImg()->channels(); i++)
			{
				if (ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun)[i] + (parlaklikMiktari*katMiktari) > 255)
					ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun)[i] = 255;
				else if (ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun)[i] + (parlaklikMiktari*katMiktari) < 0)
					ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun)[i] = 0;
				else
					ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun)[i] += parlaklikMiktari*katMiktari;

			}
	this->goster();

}

ResimParlaklik::ResimParlaklik()
{
}


ResimParlaklik::~ResimParlaklik()
{
}
