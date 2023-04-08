/**
* @file           Hucre.cpp
* @description    Programım Veri.txt dosyasından okuduğu Sayıları Organizma Oluşturarak Ekrana Belli Kurallara Göre Yazdırma Yapar. 
* @course         1.öğretim C grubu
* @assignment     2.ödev
* @date           10.12.2022 - 20.12.2022
* @author         Metin Görgülü - metin.gorgulu@ogr.sakarya.edu.tr
*/
#include "Hucre.h"
Hucre::Hucre(int veri)
{
	this->dnaVeri = veri; // bu hücrenin dnaVeri değerine gelen veriyi atar.
	onceki = sonraki = 0; // önceki ve sonraki pointerlara 0 atar.

};
Hucre::~Hucre()
{

}

