/**
* @file           Hucre.h
* @description    Programım Veri.txt dosyasından okuduğu Sayıları Organizma Oluşturarak Ekrana Belli Kurallara Göre Yazdırma Yapar. 
* @course         1.öğretim C grubu
* @assignment     2.ödev
* @date           10.12.2022 - 20.12.2022
* @author         Metin Görgülü - metin.gorgulu@ogr.sakarya.edu.tr
*/
#ifndef Hucre_h
#define Hucre_h
#include <iostream>
class Hucre
{
public:
	Hucre(int veri); // int alan kurucu fonksiyon.
	~Hucre(); // Yok edici fonksiyon.
	int dnaVeri;
	Hucre* sonraki; //sonraki pointer ı
	Hucre* onceki; // onceki pointer ı.
private:

};


#endif