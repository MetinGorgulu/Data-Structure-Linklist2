/**
* @file           Doku.h
* @description    Programım Veri.txt dosyasından okuduğu Sayıları Organizma Oluşturarak Ekrana Belli Kurallara Göre Yazdırma Yapar. 
* @course         1.öğretim C grubu
* @assignment     2.ödev
* @date           10.12.2022 - 20.12.2022
* @author         Metin Görgülü - metin.gorgulu@ogr.sakarya.edu.tr
*/
#ifndef Doku_h
#define Doku_h
#include "Hucre.h"
using namespace std;
class Doku 
{
public:
	Doku(); // Kurucu Fonksiyon
	~Doku(); // Yok Edici Fonksiyon
	void ekle(int veri); // Doku içerisine Hücre Ekleme Fonksiyonu
	Hucre* ortancaHucreyiGetir(); 	// Hücredeki ortanca veriyi getiren fonksiyon
	Doku* sonraki;	// sonraki pointer ı
	Doku* onceki;	// önceki pointer ı
	int hucreSayisi;
	Hucre* ilk; // İlk düğümün Adresini Tutacak Pointer.
private:
	
};

#endif