/**
* @file           main.cpp
* @description    Programım Veri.txt dosyasından okuduğu Sayıları Organizma Oluşturarak Ekrana Belli Kurallara Göre Yazdırma Yapar. 
* @course         1.öğretim C grubu
* @assignment     2.ödev
* @date           10.12.2022 - 20.12.2022
* @author         Metin Görgülü - metin.gorgulu@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <string>
#include "Islemler.h"
#include "Organizma.h"
using namespace std;

int main()
{
    Islemler* islem = new Islemler();   // islem Pointer ına Heap de Islemler sınıfından nesne oluşturularak atanır.
    islem->Okuma();                     // islem in Okuma fonksiyonu çağırılır.
    islem->Yazdir();                    // islem in Yazdır fonksiyonu çağırılır.
    islem->EnterTus();                  // islem in EnterTus fonksiyonu çağırılır.
    islem->Mutasyon();                  // islem in Mutasyon fonksiyonu çağırılır.
    islem->Yazdir();                    // islem in Yazdir fonksiyonu çağırılır.
    delete islem;   // islem pointerının gösterdiği alan için YOK EDİCİ fonksiyon çağırılarak heap den alınan tüm alan hiyerarşik şekilde serbest bırakılır.
    
    
}