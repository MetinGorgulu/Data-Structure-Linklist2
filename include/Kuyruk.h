/**
* @file           Kuyruk.h
* @description    Programım Veri.txt dosyasından okuduğu Sayıları Organizma Oluşturarak Ekrana Belli Kurallara Göre Yazdırma Yapar. 
* @course         1.öğretim C grubu
* @assignment     2.ödev
* @date           10.12.2022 - 20.12.2022
* @author         Metin Görgülü - metin.gorgulu@ogr.sakarya.edu.tr
*/
#ifndef Kuyruk_hpp
#define Kuyruk_hpp
#include<iostream>
#include "KuyrukDugum.h"
using namespace std;

class Kuyruk
{
public:
	Kuyruk();	// kurucu fonksiyon
	~Kuyruk();	// yok edici fonksiyon
	void ekle(int veri);	//int parametre alan ekle fonksiyonu	
	void cikar();	// çıkar fonksiyonu
	bool bosmu(); 	// bosmu bool döndüren fonksiyon
	int getir();	// int döndüren getir fonksiyonu
	int elemanSayisiGetir();	// int döndüren elemansayisigetirme fonksiyonu
private:
	KuyrukDugum* ilk;
	KuyrukDugum* son;
	int elemanSayisi;
};

#endif