#include "stdafx.h"

Mat *ResimNesne::getAnaImg()
{
    return &(this->anaImg);
}
void ResimNesne::setAnaImg()
{
    if (this->getResimAdi() == nullptr)
        cout << "Resim Adi Boş";
    else
        this->anaImg = imread(this->getResimAdi());
}
void ResimNesne::setAnaImg(cv::Mat resimNesnesi)
{
	
	(this->anaImg) = resimNesnesi;
}

char *ResimNesne::getResimAdi()
{
    return this->resimAdi;
}
void ResimNesne::setResimAdi(char *resimAdi)
{
    this->resimAdi = resimAdi;
}

ResimNesne* ResimNesne:: nesne = nullptr;

ResimNesne* ResimNesne::getNesne()
{

	if (ResimNesne::nesne == nullptr)
		ResimNesne::nesne = new ResimNesne();

	return ResimNesne::nesne;
}
ResimNesne::ResimNesne()
{
}
