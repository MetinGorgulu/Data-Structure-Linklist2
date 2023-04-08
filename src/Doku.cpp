/**
* @file           Doku.cpp
* @description    Programım Veri.txt dosyasından okuduğu Sayıları Organizma Oluşturarak Ekrana Belli Kurallara Göre Yazdırma Yapar. 
* @course         1.öğretim C grubu
* @assignment     2.ödev
* @date           10.12.2022 - 20.12.2022
* @author         Metin Görgülü - metin.gorgulu@ogr.sakarya.edu.tr
*/
#include "Doku.h"
#include <iomanip>
#include <iostream>

Doku::Doku()
{
    hucreSayisi = 0;
    ilk = 0;
    onceki = 0;
    sonraki = 0;

}
Doku::~Doku()
{
    Hucre* gec = ilk;       // Oluşturulan Hücre pointer ına Doku içerisindeki ilk hücreynin adresini atar.
    bool kontrol = true;    
    while (kontrol)     //  kontrol true oldukça while döner.
    {
        Hucre* sil = gec;   // Hucre pointer ı sil e gec pointer ı atanır.
        if (gec->sonraki != 0)  // Eğer gec in sonraki 0 dan farklıysa girer.
            gec = gec->sonraki; // gec i gec in sonrakine eşitler.
        else
            kontrol = false; 
        delete sil;     // sil pointerının gösterdiği alanı siler.
    }
}
void Doku::ekle(int veri)
{
    hucreSayisi = hucreSayisi + 1; // Doku içerisindeki Hucre sayısını tutan int değerini 1 artırır.
    Hucre* yeniHucre = new Hucre(veri); // Heap de Hucre Sınıfında veri oluşturur. 
    if (ilk == 0) // Oluşturulan hücre ilk hücre ise buraya girer.
    {
        ilk = yeniHucre; // ilk pointer ına oluşturulan yeni hücreyi atar.

    }
    else
    {
        Hucre* gec = ilk;   // gecici Hücre pointerı oluşturur.
        while (gec->sonraki != 0) // son Hücreyi bulana kadar ilerler.
        {
            gec = gec->sonraki;     // gecici yi gecicinin sonrakine eşitler
        }
        yeniHucre->onceki = gec; // oluşturulan yeni hücrein önceki ve sonrakisini ayarlar.
        gec->sonraki = yeniHucre;
    }

}
Hucre* Doku::ortancaHucreyiGetir()
{
    Hucre* gec = ilk;   //gec adında Hücre pointer ı oluşturup doku içerisindeki ilk hücreyi atar.
    for (int i = 0; i<hucreSayisi/2;i++)    // ortanca hücreyi bulana kadar döner.
    {
        gec = gec->sonraki;
    }
    return gec;     // gec döndürür.
}