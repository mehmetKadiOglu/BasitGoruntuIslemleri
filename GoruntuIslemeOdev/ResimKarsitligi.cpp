#include "stdafx.h"


void ResimKarsitligi::execute() {

	char deger;
	int karsitlikMiktari, katMiktari;
	cout << endl << endl << "Artirmak icin + eksiltmek icin -";
	cin >> deger;
	deger == '-' ? karsitlikMiktari = -0.1 : karsitlikMiktari = 0.1;
	cout << endl << "Kat miktarini Giriniz";
	cin >> katMiktari;

	int rgbDeger;
	for (int satir = 0; satir < ResimNesne::getNesne()->getAnaImg()->rows; satir++)
		for (int sutun = 0; sutun < ResimNesne::getNesne()->getAnaImg()->cols; sutun++)
			for (int i = 0; i < ResimNesne::getNesne()->getAnaImg()->channels(); i++)
			{
				rgbDeger = ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun)[i];
				rgbDeger += rgbDeger * katMiktari * karsitlikMiktari;

				if ( rgbDeger > 255)
					ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun)[i] = 255;
				else if ( rgbDeger < 0)
					ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun)[i] = 0;
				else
					ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun)[i] += rgbDeger;

				rgbDeger = 0;

			}
	this->goster();
}

ResimKarsitligi::ResimKarsitligi()
{
}


ResimKarsitligi::~ResimKarsitligi()
{
}
