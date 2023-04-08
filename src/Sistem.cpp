/**
* @file           Sistem.cpp
* @description    Programım Veri.txt dosyasından okuduğu Sayıları Organizma Oluşturarak Ekrana Belli Kurallara Göre Yazdırma Yapar. 
* @course         1.öğretim C grubu
* @assignment     2.ödev
* @date           10.12.2022 - 20.12.2022
* @author         Metin Görgülü - metin.gorgulu@ogr.sakarya.edu.tr
*/
#include "Sistem.h"

Sistem::Sistem()
{
	onceki = 0;
	sonraki = 0;
	ilk = 0;
}
Sistem::~Sistem()
{	
	Organ* gec = ilk;	// gec Organ pointer ına ilk atanır.
	bool kontrol = true;
	while (kontrol)	// kontrol true oldukça döner.
	{
		Organ* sil = gec;	// sil Organ pointerına gec atanır.
		if (gec->sonraki != 0)	// gec in sonraki 0/null olmadıkça girer.
			gec = gec->sonraki;	// gec e gecin sonraki atanır.
		else
			kontrol = false;
		delete sil;
	}
}

void Sistem::organEkle(Organ* yeniOrgan) 
{
	Organ* yeni = yeniOrgan;	// yeni Organ Pointerına YeniOrgan atanır.

	if (ilk == 0)	// ilk 0/null ise girer.
	{
		ilk = yeni;	// ilk e yeniyi atar.
	}

	else
	{
		Organ* gec = ilk;
		while (gec->sonraki != 0) // son organı bulana kadar ilerler.
		{
			gec = gec->sonraki;
		}
		yeniOrgan->onceki = gec; // oluşturulan yeni organı sona ekler ve önceki ve sonrakini ayarlar.
		gec->sonraki = yeniOrgan;
	}
}