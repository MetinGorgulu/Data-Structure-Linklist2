/**
* @file           Organizma.cpp
* @description    Programım Veri.txt dosyasından okuduğu Sayıları Organizma Oluşturarak Ekrana Belli Kurallara Göre Yazdırma Yapar. 
* @course         1.öğretim C grubu
* @assignment     2.ödev
* @date           10.12.2022 - 20.12.2022
* @author         Metin Görgülü - metin.gorgulu@ogr.sakarya.edu.tr
*/
#include "Organizma.h"



Organizma::Organizma()
{
	ilk = 0;
}
Organizma::~Organizma()
{
	Sistem* gec = ilk;	// gec Sistem pointerına ilk atanır.
	bool kontrol = true;	
	while (kontrol)	// kontrol true oldukça döner
	{
		Sistem* sil = gec;	// sil Sistem pointer ına gec atanır.
		if (gec->sonraki != 0)	// gecin sonraki 0/null dan farklı oldukça girer.
			gec = gec->sonraki;	// gece gecin sonrakini atar.
		else
			kontrol = false;	
		delete sil;

	}
}


void Organizma::SistemEkle(Sistem* sist)
{
	Sistem* yeni = sist;	// yeni Sistem pointer ına parametre olarak gelen sist i atar.
	if (ilk == 0)	// ilk 0/null oldukça girer.
	{
		ilk = yeni;	// ilk e yeni yi atar.
		return;
	}

	Sistem* gec = ilk;	// gec Sistem pointerına ilki atar.

	while (gec->sonraki != 0)	// gecin sonraki 0/null dan farklı oldukça girer
	{
		gec = gec->sonraki;	// gece gecin sonrakini atar.
	}
	gec->sonraki = yeni;	// yeni düğüm ve gec in önceki ve sonrakini ayarlar.
	yeni->onceki = gec;
}