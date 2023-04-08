/**
* @file           Organizma.h
* @description    Programım Veri.txt dosyasından okuduğu Sayıları Organizma Oluşturarak Ekrana Belli Kurallara Göre Yazdırma Yapar. 
* @course         1.öğretim C grubu
* @assignment     2.ödev
* @date           10.12.2022 - 20.12.2022
* @author         Metin Görgülü - metin.gorgulu@ogr.sakarya.edu.tr
*/
#ifndef Organizma_hpp
#define Organizma_hpp
#include "Sistem.h"
using namespace std;

class Organizma
{
public:
	Organizma();	// Kurucu fonksiyon 	
	~Organizma();	// Yok edici Fonksiton
	void SistemEkle(Sistem* sist);	// Sistem pointer parametresi alan SistemEkle fonkssiyonu
	Sistem* ilk;

private:
};
#endif

