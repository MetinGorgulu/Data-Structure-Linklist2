/**
* @file           Organ.cpp
* @description    Programım Veri.txt dosyasından okuduğu Sayıları Organizma Oluşturarak Ekrana Belli Kurallara Göre Yazdırma Yapar. 
* @course         1.öğretim C grubu
* @assignment     2.ödev
* @date           10.12.2022 - 20.12.2022
* @author         Metin Görgülü - metin.gorgulu@ogr.sakarya.edu.tr
*/
#include "Organ.h"
Organ::Organ() 
{
	ilk = 0;
	onceki = 0;
	sonraki = 0;
	organAgac = new IkiliAramaAgaci();		//Organ İçerisindeki organAgac pointerına Heapden Alan alınarak IkiliAramaAgaci oluşturulru ve adresi atanır.
};
Organ ::~Organ() 
{
	Doku* gec = ilk;	// gecici Doku pointer ı oluşturularak ilk in adresi atanır.
	bool kontrol = true;
	while (kontrol) 	// Kontrol true olduğu sürece döner.
	{
		Doku* sil = gec;	// Sil Doku pointer ı oluşturarak bu pointer a gec atanır.
		if (gec->sonraki != 0)	// gecin sonraki 0/null değilse girer.
			gec = gec->sonraki;	// gec e gecin sonraki atanrır.
		else
			kontrol = false; 
		delete sil;	
	}
	delete organAgac;
}
void Organ::dokuEkle(Doku* yeniDoku)
{
	Doku* yeni = yeniDoku;	// yeni Doku pointerına yeniDoku adresi atanır.
	organAgac->ekle(yeni, organAgac->kok); // organAgac için ekle fonksiyonu çağırılır.
	if (ilk == 0)	// ilk 0/null sa girer.
	{
		ilk = yeni;	// ilk e yeni atanır.
	}
	else
	{
		Doku* gec = ilk;	// gec Doku pointerına ilk atanır.
		while (gec->sonraki != 0) // gecin sonraki 0/null olmadıkça girer
		{
			gec = gec->sonraki;	// gec e gecin sonrakini atar.
		}
		yeniDoku->onceki = gec; // olu�turulan yeni dokuyu sona ekler ve önceki ve sonrakini ayarlar.
		gec->sonraki = yeniDoku;
	}
};