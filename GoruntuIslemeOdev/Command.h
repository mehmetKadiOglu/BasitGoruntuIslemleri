#pragma once

class Command
{
private:
	std::vector<Execute *> nesneHavuzu;
	std::vector<char *> nesneHavuzuEleman;
	void setNesneHavuzu(Execute *, char *);
public:
	char * getNesneHavuzuEleman(int);
	void calistir(int);
	int getNesneHavuzUzunluk();
	Command();
	~Command();
};

