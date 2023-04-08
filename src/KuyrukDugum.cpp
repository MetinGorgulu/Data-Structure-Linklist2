/**
* @file           KuyrukDugum.cpp
* @description    Programım Veri.txt dosyasından okuduğu Sayıları Organizma Oluşturarak Ekrana Belli Kurallara Göre Yazdırma Yapar. 
* @course         1.öğretim C grubu
* @assignment     2.ödev
* @date           10.12.2022 - 20.12.2022
* @author         Metin Görgülü - metin.gorgulu@ogr.sakarya.edu.tr
*/
#include "KuyrukDugum.h"
KuyrukDugum::KuyrukDugum(int veri)
{
    this->veri = veri;  // veri ye parametre ile gelen int veri atanır.
    sonraki = 0;
}
KuyrukDugum::~KuyrukDugum()
{
 
}