/**
* @file           Radix.h
* @description    Programım Veri.txt dosyasından okuduğu Sayıları Organizma Oluşturarak Ekrana Belli Kurallara Göre Yazdırma Yapar. 
* @course         1.öğretim C grubu
* @assignment     2.ödev
* @date           10.12.2022 - 20.12.2022
* @author         Metin Görgülü - metin.gorgulu@ogr.sakarya.edu.tr
*/
#ifndef Radix_hpp
#define Radix_hpp
#include "Kuyruk.h"
#include "AgacDugum.h"
#include <iostream>


using namespace std;

class Radix
{
public:
    Radix(int* sayilar, int adet);  //int pointer ve int parametre alan kurucu fonksiyon
    Radix(Doku** dokuAdres , int adet); // Doku pointerını gösteren pointer ve int parametre alan aşırı yükleme yapılmış kurucu fonksiyon.
    ~Radix();   //Yok edici Fonksiyon.
    int*    sirala();   // int pointerı döndüren sirala fonksiyonu

private:
    int     maxBasamakSayisiGetir();    // int döndüren max basamak sayısını döndüren fonksiyon.
    int     basamakSayisiGetir(int sayi);   // basamak sayısını int olarak döndüren int parametre alan fonksyion.
    void    kuyrukUzunluklariGetir(int* uzunluklar);    // int pointerı parametre alan Kuyruk uzunluklarını getiren fonksiton
    Kuyruk**kuyruklar;
    int*    sayilar;
    int     sayiAdedi;
};

#endif