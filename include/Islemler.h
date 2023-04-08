/**
* @file           Islemler.h
* @description    Programım Veri.txt dosyasından okuduğu Sayıları Organizma Oluşturarak Ekrana Belli Kurallara Göre Yazdırma Yapar. 
* @course         1.öğretim C grubu
* @assignment     2.ödev
* @date           10.12.2022 - 20.12.2022
* @author         Metin Görgülü - metin.gorgulu@ogr.sakarya.edu.tr
*/
#include <iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<algorithm>
#include<fstream>
#include <sstream>
#include <vector>
#include "Organizma.h"
#include "Radix.h"
using namespace std;
class Islemler
{
public:
    Islemler(); //kurucu fonksiyon
    ~Islemler();    //yok edici fonksiyon
	void Okuma();   // Dosya Okuma Fonksiyonu
	void Yazdir();  // Organizmayı Yazdırma Fonksiyonu
    void Mutasyon();    // Mutasyona Uğratan Fonksiyon
    void EnterTus();    // Enter Tuşuna Bastığında Devam Sağlayan Fonksiyon
private:
    int dokuSayac;
    int organSayac;
    bool yeniorgan;
    int sistemisay;
    Organizma* buyukOrganizma;
    bool mutasyon;
};

