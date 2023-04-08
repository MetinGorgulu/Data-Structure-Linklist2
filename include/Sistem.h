/**
* @file           Sistem.h
* @description    Programım Veri.txt dosyasından okuduğu Sayıları Organizma Oluşturarak Ekrana Belli Kurallara Göre Yazdırma Yapar. 
* @course         1.öğretim C grubu
* @assignment     2.ödev
* @date           10.12.2022 - 20.12.2022
* @author         Metin Görgülü - metin.gorgulu@ogr.sakarya.edu.tr
*/
#ifndef Sistem_hpp
#define Sistem_hpp
#include "Organ.h"
using namespace std;
class Sistem
{
public:
	Sistem();	//Kurucu Fonksiyon
	~Sistem();	// Yok edici Fonksiyon
	void organEkle(Organ* yeniOrgan);	// Organ pointer ı parametre alan OrganEkle Fonksiyonu
	Sistem* sonraki;
	Sistem* onceki;
	Organ* ilk;
private:
};
#endif
