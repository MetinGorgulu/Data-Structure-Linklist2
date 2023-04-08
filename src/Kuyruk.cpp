/**
* @file           Kuyruk.cpp
* @description    Programım Veri.txt dosyasından okuduğu Sayıları Organizma Oluşturarak Ekrana Belli Kurallara Göre Yazdırma Yapar. 
* @course         1.öğretim C grubu
* @assignment     2.ödev
* @date           10.12.2022 - 20.12.2022
* @author         Metin Görgülü - metin.gorgulu@ogr.sakarya.edu.tr
*/
#include "Kuyruk.h"
#include <iomanip>
#include<stdexcept>
Kuyruk::Kuyruk()
{
    ilk = son = 0;
    elemanSayisi = 0;
}
Kuyruk::~Kuyruk()
{
    while (ilk != 0)    // ilk 0/null olmadıkça girer.
    {
        KuyrukDugum* gec = ilk; // gecici pointer oluşturulup ilk atanır
        ilk = ilk->sonraki; // ilk i ilkin sonraki atanır.
        delete gec; //gec in heap alanı silinir.
    }
}
bool Kuyruk::bosmu()
{
    if (ilk == 0)   // ilk 0/null ise girer.
        return true; 
    return false;
}

void Kuyruk::ekle(int veri)
{
    if (ilk == 0)   //ilk 0/null sa girer.
    {
        ilk = new KuyrukDugum(veri); // ilk e heap den aldığı alana KuyrukDugum oluşturarak atar.
        son = ilk;  

    }
    else
    {
        KuyrukDugum* yeni = new KuyrukDugum(veri);  // yeni pointerına heapden aldığı alana KuyrukDugum oluşturarak atar.
        son->sonraki = yeni;    // sonun sonrakine yeni yi atar.
        son = yeni;

    }
    elemanSayisi++; 
}
void Kuyruk::cikar()
{
    if (ilk != 0)   // ilk 0/null dan farklıysa girer.
    {
        KuyrukDugum* gec = ilk->sonraki;    // gec pointerına ilk in sonraki atanır.
        delete ilk; // ilk in heapdeki alanı silinir.
        ilk = gec;  
        if (ilk == 0)   // ilk 0/null sa girer.
            son = 0;    
        elemanSayisi--;
    }
}
int Kuyruk::getir()
{
    if (ilk != 0)   // ilk 0/null değilse girer.
        return ilk->veri;
}

int Kuyruk::elemanSayisiGetir()
{
    return elemanSayisi;
}