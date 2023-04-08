/**
* @file           Organ.h
* @description    Programım Veri.txt dosyasından okuduğu Sayıları Organizma Oluşturarak Ekrana Belli Kurallara Göre Yazdırma Yapar. 
* @course         1.öğretim C grubu
* @assignment     2.ödev
* @date           10.12.2022 - 20.12.2022
* @author         Metin Görgülü - metin.gorgulu@ogr.sakarya.edu.tr
*/
#ifndef Organ_hpp
#define Organ_hpp
#include "Doku.h"
#include "IkiliAramaAgaci.h"
using namespace std;
class Organ
{
public:

	Organ();	// kurucu fonksiyon
	~Organ();	// yok edici fonksiyon
	void dokuEkle(Doku* dokuveri);	// Doku pointerı parametre olarak alan dokuEkle fonksiyonu
	Organ* sonraki;
	Organ* onceki;
	IkiliAramaAgaci* organAgac;	// Organ içerisine Oluşturulan İkili Arama Agacı
	Doku* ilk; 	// Organ İçerisindeki Dokuların ilk ini tutan ilk pointerı 
private:
	
};
#endif
