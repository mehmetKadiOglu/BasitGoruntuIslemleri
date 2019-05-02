#include "stdafx.h"

void ResimKucult::execute() {
	//		// 0 mavi
	//		//1 yeþil
	//		// 2 kýrmýzý
	int kirmizi = 0;
	int mavi = 0;
	int yesil = 0;


	Mat yeniResim( (ResimNesne::getNesne()->getAnaImg()->rows / 2), (ResimNesne::getNesne()->getAnaImg()->cols / 2), CV_8UC3, Scalar(0, 0, 255));



	for (int satir = 0, yeniResimSatir = 0; yeniResimSatir < ResimNesne::getNesne()->getAnaImg()->rows / 2; satir+=2, yeniResimSatir++)
		for (int sutun = 0, yeniResimSutun = 0; yeniResimSutun < ResimNesne::getNesne()->getAnaImg()->cols / 2; sutun+=2, yeniResimSutun++)
		{
			for (int kucukMatrisSatir = satir; (kucukMatrisSatir < satir + 2); kucukMatrisSatir++)
				for (int kucukMatrisSutun = sutun; (kucukMatrisSutun < sutun+2); kucukMatrisSutun++)
				{
					mavi += ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(kucukMatrisSatir, kucukMatrisSutun)[0];
					yesil += ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(kucukMatrisSatir, kucukMatrisSutun)[1];
					kirmizi += ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(kucukMatrisSatir, kucukMatrisSutun)[2];
				}
			
			yeniResim.at<Vec3b>(yeniResimSatir, yeniResimSutun)[0] = (mavi / 4);
			yeniResim.at<Vec3b>(yeniResimSatir, yeniResimSutun)[1] = (yesil / 4);
			yeniResim.at<Vec3b>(yeniResimSatir, yeniResimSutun)[2] = (kirmizi / 4);

			mavi = 0;
			yesil = 0;
			kirmizi = 0;
		}
	
	ResimNesne::getNesne()->setAnaImg(yeniResim);

	this->goster();
}

ResimKucult::ResimKucult()
{
}


ResimKucult::~ResimKucult()
{
}
