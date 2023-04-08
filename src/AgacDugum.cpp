/**
* @file           AgacDugum.cpp
* @description    Programım Veri.txt dosyasından okuduğu Sayıları Organizma Oluşturarak Ekrana Belli Kurallara Göre Yazdırma Yapar. 
* @course         1.öğretim C grubu
* @assignment     2.ödev
* @date           10.12.2022 - 20.12.2022
* @author         Metin Görgülü - metin.gorgulu@ogr.sakarya.edu.tr
*/
#include "AgacDugum.h"
#include <iostream>
using namespace std;
AgacDugum::AgacDugum(Doku* dokuAdres)
{
	this->dokuAdres = dokuAdres; // parametre olarak gelen adresi oluşturulan düğümün dokuadres pointerina atar.
	sol = 0;
	sag = 0;
	ortancaHucre = 0;
}

AgacDugum::~AgacDugum()
{


}
