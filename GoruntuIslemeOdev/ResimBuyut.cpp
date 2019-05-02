#include "stdafx.h"

void ResimBuyut::execute() {


	int eskiResimSatirUzunlugu = ResimNesne::getNesne()->getAnaImg()->rows;
	int eskiResimSutunUzunlugu = ResimNesne::getNesne()->getAnaImg()->cols;

	int yeniResimSatirUzungulu = (eskiResimSatirUzunlugu * 2) - 1;
	int yeniResimSutunUzungulu = (eskiResimSutunUzunlugu * 2) - 1;

	Mat yeniResim(yeniResimSatirUzungulu, yeniResimSutunUzungulu, CV_8UC3, Scalar(0, 0, 0));

	this->ciftSatirlariDiz(&yeniResim, yeniResimSutunUzungulu, eskiResimSatirUzunlugu, eskiResimSutunUzunlugu);
	this->tekSatirlarDiz(&yeniResim, yeniResimSatirUzungulu, yeniResimSutunUzungulu);

	ResimNesne::getNesne()->setAnaImg(yeniResim);
	this->goster();
}

void ResimBuyut::ciftSatirlariDiz(cv::Mat *yeniResim, int yeniResimSutunUzungulu, int eskiResimSatirUzunlugu, int eskiResimSutunUzunlugu) {

	for (int eskiResimSatir = 0, yeniResimSatir = 0; eskiResimSatir < eskiResimSatirUzunlugu; eskiResimSatir++, yeniResimSatir += 2)
	{
		for (int eskiResimSutun = 0, yeniResimSutun = 0; eskiResimSutun < eskiResimSutunUzunlugu - 1; )
		{
			(*yeniResim).at<Vec3b>(yeniResimSatir, yeniResimSutun + 1) = ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(eskiResimSatir, eskiResimSutun);
			yeniResimSutun++;

			(*yeniResim).at<Vec3b>(yeniResimSatir, yeniResimSutun + 1)[0] = (ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(eskiResimSatir, eskiResimSutun)[0] + ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(eskiResimSatir, eskiResimSutun + 1)[0]) / 2;
			yeniResim->at<Vec3b>(yeniResimSatir, yeniResimSutun + 1)[1] = (ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(eskiResimSatir, eskiResimSutun)[1] + ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(eskiResimSatir, eskiResimSutun + 1)[1]) / 2;
			yeniResim->at<Vec3b>(yeniResimSatir, yeniResimSutun + 1)[2] = (ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(eskiResimSatir, eskiResimSutun)[2] + ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(eskiResimSatir, eskiResimSutun + 1)[2]) / 2;
			yeniResimSutun++;
			eskiResimSutun++;
			

		}
		yeniResim->at<Vec3b>(yeniResimSatir, yeniResimSutunUzungulu - 1) = ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(eskiResimSatir, eskiResimSutunUzunlugu - 1);
	}
}

void ResimBuyut::tekSatirlarDiz(cv::Mat *yeniResim, int yeniResimSatirUzungulu, int yeniResimSutunUzungulu) {

	for (int yeniResimTekSatir = 1, yeniResimCiftSatir = 2; yeniResimCiftSatir < yeniResimSatirUzungulu; yeniResimTekSatir += 2, yeniResimCiftSatir += 2)
	{
		for (int sutun = 0; sutun < yeniResimSutunUzungulu; sutun++)
		{

			yeniResim->at<Vec3b>(yeniResimTekSatir, sutun)[0] = (yeniResim->at<Vec3b>(yeniResimCiftSatir, sutun)[0] + yeniResim->at<Vec3b>(yeniResimCiftSatir - 2, sutun)[0]) / 2;
			yeniResim->at<Vec3b>(yeniResimTekSatir, sutun)[1] = (yeniResim->at<Vec3b>(yeniResimCiftSatir, sutun)[1] + yeniResim->at<Vec3b>(yeniResimCiftSatir - 2, sutun)[1]) / 2;
			yeniResim->at<Vec3b>(yeniResimTekSatir, sutun)[2] = (yeniResim->at<Vec3b>(yeniResimCiftSatir, sutun)[2] + yeniResim->at<Vec3b>(yeniResimCiftSatir - 2, sutun)[2]) / 2;
		}

	}
}
ResimBuyut::ResimBuyut()
{
}


ResimBuyut::~ResimBuyut()
{
}
