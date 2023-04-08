/**
* @file           AgacDugum.h
* @description    Programım Veri.txt dosyasından okuduğu Sayıları Organizma Oluşturarak Ekrana Belli Kurallara Göre Yazdırma Yapar. 
* @course         1.öğretim C grubu
* @assignment     2.ödev
* @date           10.12.2022 - 20.12.2022
* @author         Metin Görgülü - metin.gorgulu@ogr.sakarya.edu.tr
*/
#ifndef AgacDugum_hpp
#define AgacDugum_hpp

#include <iostream>
#include  "Doku.h"
using namespace std;
class AgacDugum {

public:
    AgacDugum(Doku* dokuAdres); //Doku adresi alan kurucu fonksiyon.
    ~AgacDugum(); // Yok edici fonksiyon.
    Doku* dokuAdres;
    AgacDugum* sol; // sol un adresini tutan pointer.
    AgacDugum* sag; // sağ ın adresini tutan pointer.
    int yukseklik;  
    int ortancaHucre;
};


#endif