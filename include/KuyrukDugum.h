/**
* @file           KuyrukDugum.h
* @description    Programım Veri.txt dosyasından okuduğu Sayıları Organizma Oluşturarak Ekrana Belli Kurallara Göre Yazdırma Yapar. 
* @course         1.öğretim C grubu
* @assignment     2.ödev
* @date           10.12.2022 - 20.12.2022
* @author         Metin Görgülü - metin.gorgulu@ogr.sakarya.edu.tr
*/
#ifndef KuyrukDugum_hpp
#define KuyrukDugum_hpp

class KuyrukDugum
{
public:
    KuyrukDugum(int veri);  // int parametre alan kurucu Fonksiyon 
    ~KuyrukDugum(); // Yok edici Fonksityon
    int veri;
    KuyrukDugum* sonraki;
};

#endif