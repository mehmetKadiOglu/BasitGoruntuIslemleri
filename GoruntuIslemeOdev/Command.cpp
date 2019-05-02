#include "stdafx.h"

void Command::setNesneHavuzu(Execute * nesne, char * nesneAdi)
{
	this->nesneHavuzu.push_back(nesne);
	this->nesneHavuzuEleman.push_back(nesneAdi);
	
}
char * Command::getNesneHavuzuEleman(int index)
{
	return this->nesneHavuzuEleman.at(index);
}
int Command::getNesneHavuzUzunluk()
{
	return this->nesneHavuzu.size();
}
void Command::calistir(int index)
{
	this->nesneHavuzu.at(index)->execute();
}
Command::Command()
{
	this->setNesneHavuzu(new GoruntuOtele(), "Resim Otele");
	this->setNesneHavuzu(new ResimAynala(), "Resim Aynala");
	this->setNesneHavuzu(new ResimBuyut(), "Resim Buyut");
	this->setNesneHavuzu(new ResimKucult(), "Resim Kucult");
	this->setNesneHavuzu(new ResimDondur(), "Resim Dondur");
	this->setNesneHavuzu(new ResimGrilestir(), "Resim Grilestir");
	this->setNesneHavuzu(new ResimKarsitligi(), "Resim Karsitligi");
	this->setNesneHavuzu(new ResimKarsitYay(), "Resim Karsit Yay");
	this->setNesneHavuzu(new ResimParlaklik(), "Resim Parlaklik");
	this->setNesneHavuzu(new ResimTersCevir(), "Resim Ters Cevir");
	this->setNesneHavuzu(new ResimTersle(), "Resim Tersle");
	this->setNesneHavuzu(new ResimHistogramGer(), "Histogram Ger");
}


Command::~Command()
{
}
