/**
* @file           Radix.cpp
* @description    Programım Veri.txt dosyasından okuduğu Sayıları Organizma Oluşturarak Ekrana Belli Kurallara Göre Yazdırma Yapar. 
* @course         1.öğretim C grubu
* @assignment     2.ödev
* @date           10.12.2022 - 20.12.2022
* @author         Metin Görgülü - metin.gorgulu@ogr.sakarya.edu.tr
*/
#include "Radix.h"
#include<iomanip>

Radix::Radix(int* sayilar, int adet)    
{
    this->sayiAdedi = adet; // sayiAdedine adet i atar.

    this->sayilar = new int[sayiAdedi]; // sayilar a heapden sayiAdedi kadar alan alarak int tipinde oluşturulur ve atar.

    for (int i = 0; i < sayiAdedi; i++) // sayiadeti kadar döner.
        this->sayilar[i] = sayilar[i];  // parametre olarak gelen sayıların her elemanını sayılara atar.

    kuyruklar = new Kuyruk * [10];  // heapden 10 adet alan alarak kuyruk pointerı oluşturur ve kuyruklara atar.
    for (int i = 0; i < 10; i++)    //10 kere döner
        kuyruklar[i] = new Kuyruk();    // kuyrukların her bir elemanı için heapdenn alan alarak kuyruk oluşturur.


}

Radix::~Radix()
{
    for (int i = 0; i < 10; i++)    // 10 kere döner
        delete kuyruklar[i];    // bütün kuyrukları siler.

    delete[] kuyruklar; // bütü kuyruk pointerlerini de siler heapden.


}

int* Radix::sirala()
{

    for (int i = 0; i < sayiAdedi; i++) // sayiAdeti kadar döner.
    {
        int sonBasamak = sayilar[i] % 10;   // sayilar i ninci elemanı 10 a bölünerek sonBasamak a atanır

        kuyruklar[sonBasamak]->ekle(sayilar[i]);    // kuyruklar ın sonBasamak elemanı için ekle fonksiyonu sayiların i nci elemanı için çağırlır.

    }
    int maxBasamakSayisi = maxBasamakSayisiGetir(); // maxBasamakSayisina maxBasamakSayisiGetir Fonksiyonundan getirilen veri atanır.


    int basamakCarpani = 10;    

    for (int i = 1; i < maxBasamakSayisi; i++)  // maxbasamaksayisindan 1 eksiği kadar döner.
    {
        int uzunluklar[10]; 

        kuyrukUzunluklariGetir(uzunluklar); // uzunluklar için kuyrukUzunluklariGetir fonksiyonu çağılır.

        for (int j = 0; j < 10; j++)    // 10 kere döner
        {
            int es = uzunluklar[j]; //es int ine uzunlukların j ninci elemanı atanır.

            while (es)  // es 0 dan farklı oldukça döner
            {
                int siradakiSayi = kuyruklar[j]->getir();   //siradakiSayi int ine kuyrukların j ninci elemanı için getir fonksiyonundan dönen değer atanır.

                kuyruklar[j]->cikar();  //  kuyruklar j ninci elemanı için çıkar fonksiyonu çağırılır.
                int basamak = (siradakiSayi / basamakCarpani) % 10; 
                kuyruklar[basamak]->ekle(siradakiSayi);
                es--;
            }
        }
        basamakCarpani *= 10;
    }
    int diziIndex = 0;
    for (int i = 0; i < 10; i++)    // 10 kere döner.
    {
        while (!kuyruklar[i]->bosmu())  // kuyruklar i ninci elemanı için bosmu fonksiyonunda gelen değer true oldukça girer.
        {
            sayilar[diziIndex] = kuyruklar[i]->getir(); //sayilar diziindex inci ye kuyrukların i ninci elemanı için getir fonksiyonunu çağırır dönen değeri atar.
            kuyruklar[i]->cikar(); // kuyruklar i ninci elemanı için çıkar fonksiyonunu çağırır.
            diziIndex++;
        }
    }

    return sayilar;
}

int Radix::maxBasamakSayisiGetir()  
{
    int maxBasamakSayisi = basamakSayisiGetir(sayilar[0]); // sayılar 0. index için basamak sayısı getir fonksiyonundan dönen değeri maxBasamakSayısına atar.

    for (int i = 1; i < sayiAdedi; i++) //sayı adeti kadar döner.
    {
        int siradakiBasamakSayisi = basamakSayisiGetir(sayilar[i]);     // siradakiBasamakSayisina basamakSayisiGetir fonksiyonu sayilar i ninci index için çağırılır ve atanır
        if (maxBasamakSayisi < siradakiBasamakSayisi)   // eğer max basamaka sayisi siradaki basamak sayisindan küçükse girer.
            maxBasamakSayisi = siradakiBasamakSayisi;   // max basamak sayısına siradaki basamak sayisini atar.
    }
    return maxBasamakSayisi;
}
int Radix::basamakSayisiGetir(int sayi)
{
    int basamakSayisi = 0;
    while (sayi)    // sayi 0 dan farklı olduğu sürece girer.
    {
        sayi = sayi / 10;   // sayıyı 10 böler ve sayıya atar
        basamakSayisi++;
    }
    return basamakSayisi;

}

void Radix::kuyrukUzunluklariGetir(int* uzunluklar)
{
    for (int i = 0; i < 10; i++)    // 10 kere döner
    {
        uzunluklar[i] = kuyruklar[i]->elemanSayisiGetir();  //uzunlukların i ninci elemanına kuyrukların i ninci elemanı için eleman Sayisi Getir fonksiyonunu çağırır ve atar.
    }
}