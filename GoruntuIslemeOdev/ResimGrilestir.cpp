#include "stdafx.h"


void ResimGrilestir::execute() {
	//		// 0 mavi
	//		//1 yeþil
	//		// 2 kýrmýzý
	int renk;
	for (int satir = 0; satir < ResimNesne::getNesne()->getAnaImg()->rows; satir++)
	{
		for (int sutun = 0; sutun < ResimNesne::getNesne()->getAnaImg()->cols; sutun++)
		{
			renk = 0;
			renk +=  0.114 * ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun)[0];
			renk += 0.587 * ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun)[1];
			renk += 0.299 * ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun)[2];
			ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun)[0] = renk;
			ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun)[1] = renk;
			ResimNesne::getNesne()->getAnaImg()->at<Vec3b>(satir, sutun)[2] = renk;

		}
	}

	this->goster();
}
ResimGrilestir::ResimGrilestir()
{
}


ResimGrilestir::~ResimGrilestir()
{
}
