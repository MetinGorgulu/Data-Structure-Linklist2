/**
* @file           IkiliAramaAgaci.cpp
* @description    Programım Veri.txt dosyasından okuduğu Sayıları Organizma Oluşturarak Ekrana Belli Kurallara Göre Yazdırma Yapar. 
* @course         1.öğretim C grubu
* @assignment     2.ödev
* @date           10.12.2022 - 20.12.2022
* @author         Metin Görgülü - metin.gorgulu@ogr.sakarya.edu.tr
*/
#include "IkiliAramaAgaci.h"
#include <iostream>

using namespace std;
IkiliAramaAgaci::IkiliAramaAgaci()
{
    kok = 0;
    denge = true;
    yedekAgac = new Doku*[20];  //Doku pointerlerını tutan 20 adet heapden alan oluşturulur ve yedekagac pointerı içerisine atanır.
    yedekAgacSayaci=0;
};

IkiliAramaAgaci :: ~IkiliAramaAgaci()
{
    agaciSil(); //agacisil fonksiyonu çağırılır.
    delete[] yedekAgac; //Heapden alınan 20 adet doku pointerı tutan alan silinir.
};
void IkiliAramaAgaci::agaciSil()
{
    AgacDugum* gec = kok;   // gecici pointer oluşturarak kök bu pointer a atanır.
    if (gec->sol !=0 ||gec->sag!=0 )    // kökün sağı veya solu dolu ise girer.
    {

        agaciSil(gec); // gec pointerını agacisil fonksiyonuna parametre ile çağırır.
    }
    else
    {
        delete gec;    
    }
    kok = 0;    // kök artık silindiği için pointer ı sıfır/Null a eşitler.
}
void IkiliAramaAgaci::agaciSil(AgacDugum* agacdugumu)
{
    AgacDugum* gec = agacdugumu;    //  gec adında gecici pointer oluşturulur.
    AgacDugum* sil = agacdugumu;    //  sil adında pointer oluşturulur.
    if (gec->sol != 0 || gec->sag != 0) // gec in sağı veya solu varsa girer.
    {
        if (gec->sol != 0 && gec->sag == 0) // gecin solu varsa ve sağı yoksa.
        {
            sil = gec->sol; // sil e gec in solunu atar.
            agaciSil(sil); // agacisil fonksiyonun sil parameteresi ile çağırır.
            gec->sol = 0; // gec in sol u silindiği için pointerına sıfır/null atanır.
        }
        else if (gec->sol == 0 && gec->sag != 0) // gecin solu yok ve sağı var ise girer.
        {
            sil = gec->sag; // sile gec in sağı atanır.
            agaciSil(sil);  // agacisil fonksiyonun sil parametresi ile çağırır.
            gec->sag = 0;   // gec in sağ ı silindiği için pointerına sıfır/null atanır.
        }
        else
        {
            sil = gec->sol; // sile gecin solu atanır.
            agaciSil(sil);  // agacisil fonksiyonu sil parametresi ile çağırılır.
            gec->sol = 0;   // gec in solu silindiği için pointerına 0/null atanır.
            return agaciSil(gec);   // agacısil fonksiyonu gec parametresi ile çağırılır ve return edilir.
        }
        return agaciSil(gec); // agacısil fonksiyonu gec parametresi ile çağırılır ve return edilir.
    }
    delete sil; 
    
}
void IkiliAramaAgaci::ekle(Doku* dokuAdres, AgacDugum* aktifDugum)
{
    if (kok == 0)   // kök yoksa girer.
    {

        kok = new AgacDugum(dokuAdres); //  Heap de alan alınarak Agacdüğüm oluşturulur Ve kök e atanır.
        kok->ortancaHucre = dokuAdres->ortancaHucreyiGetir()->dnaVeri;  // kök ün ortancahücresi ne dokuadresinin ortancahücresi atanır.
        return;
    }
    else if (aktifDugum->ortancaHucre >= dokuAdres->ortancaHucreyiGetir()->dnaVeri) // eğer aktif düğümün ortancahücresi dokuadresin ortancahücresinden büyük veya eşitse girer.
    {
        if (aktifDugum->sol != 0)   // Eğer aktifdüğümün solu varsa 
        {
            ekle(dokuAdres, aktifDugum->sol);   // ekle fonksiyonunu çağırır.
        }
        else {
            aktifDugum->sol = new AgacDugum(dokuAdres); // heap de alan oluşturularak ağacın soluna atanır.
            aktifDugum->sol->ortancaHucre = dokuAdres->ortancaHucreyiGetir()->dnaVeri;  // ağacın solunun ortancahucresine dokuadresinin ortancahücresinin dnaverisi atanır.
        }
        return;
    }
    else if(aktifDugum->ortancaHucre < dokuAdres->ortancaHucreyiGetir()->dnaVeri)   // eğer aktif düğümün ortancahücresi dokuadresin ortancahücresinden küçükse girer.
    {
        if (aktifDugum->sag != 0)   // aktifdüğümün sağı varsa girer.
        {
            ekle(dokuAdres, aktifDugum->sag);   // ekle fonksiyonun çağırır.
        }
        else {
            aktifDugum->sag = new AgacDugum(dokuAdres); // heap de alan oluşturularak ağacın ssağına atanır.
            aktifDugum->sag->ortancaHucre = dokuAdres->ortancaHucreyiGetir()->dnaVeri;  // ağacın sağının ortancahucresine dokuadresinin ortancahücresinin dnaverisi atanır.
        }
        return;
    }
    
}
int IkiliAramaAgaci::yukseklik()
{
    return yukseklik(kok);  // kök parametresi yükseklik fonksyionu çağırılır.
}
int IkiliAramaAgaci::yukseklik(AgacDugum* aktifDugum)
{
    if (aktifDugum) // aktifdugum 0 dan farklıysa girer.
    {
        aktifDugum->yukseklik = 1 + max(yukseklik(aktifDugum->sol),yukseklik(aktifDugum->sag));// aktif dugumun yüksekliğine aktif düğümünün solunun ve sağının en yükeseğine 1 eklenerek atanır.
        return aktifDugum->yukseklik;
    }
    return -1;
}
void IkiliAramaAgaci::dengeliMi()
{
    yukseklik();    //  yukseklik fonksiyonunu çağırır.
    dengeliMi(kok); //  dengelimi fonksiyonunu kök parametrsei ile çağırır.
}
void IkiliAramaAgaci:: dengeliMi(AgacDugum* aktifDugum)
{
    
    if (aktifDugum->sol != 0 && aktifDugum->sag != 0)   //aktif düğümün solu varsa ve sağı varsa girer.
    {
        if (abs(aktifDugum->sol->yukseklik - aktifDugum->sag->yukseklik) > 1)   //aktifin solunun yüksekliğinden sağının yüksekliğini çıkarıp mutlak değerini alır ve 1 den büyükse girer.
            denge = false;  // denge yi false yapar.
    }
    else if(aktifDugum->sol == 0 && aktifDugum->sag != 0)   // aktifin solu yok ve sağı varsa girere.
    {
        if (aktifDugum->sag->yukseklik +1 > 1)  //aktifin sağının yüksekliğine 1 ekler ve 1 den büyükkse girer.
            denge = false; // dengeyi false yapar.
    }
    else if (aktifDugum->sag == 0 && aktifDugum->sol != 0)  // aktifin sağı yoksa ve solu sıfırdan farklıysa girer.
    {
        if (aktifDugum->sol->yukseklik +1 > 1)  //aktifin solunun yükseklğine 1 ekler ve 1 den yüksekse girer.
        denge = false;  // dengeyi false yapar.
    }
            
    if (!denge) // denge false ise girer.
        return; // return eder.
    if (aktifDugum->sol != 0)      // eğer aktifin solu varsa girer.
        dengeliMi(aktifDugum->sol); // dengelimi fonksyionunu aktifin solu için çağırır.
    if (aktifDugum->sag != 0)   // eğer aktifin sağı var girer
        dengeliMi(aktifDugum->sag); // aktifin sağı için dengelimi fonksiyonunu çağırır.
    
}
void IkiliAramaAgaci::mutasyonaUgradi() 
{
    postOrder(kok); // kök için postOrder fonksiyonunu çağırır
    agaciSil(); // agacisil fonksiyonunu çağırır
    yedektenAgacYap();  // yedekten agac yapar



}
void IkiliAramaAgaci::postOrder(AgacDugum* aktif)
{
    
    if (aktif)  //aktif dugum varsa
    {
        postOrder(aktif->sol);  // postorder fonksiyonunu aktifin solu için çağırır
        postOrder(aktif->sag);  // postorder fonksiyonunu aktifin Sağı için çağırır
        yedekAgac[yedekAgacSayaci] = aktif->dokuAdres;  // yedekagac ın yedekagacsayaci nci index ine aktif in dokuadresini atar.
        yedekAgacSayaci++;  // yedekagacsayacini 1 artırır.


    }
}
int IkiliAramaAgaci::radixSortIleSirala(Doku* adres)
{
    int* siralanmamisDoku = new int[adres->hucreSayisi];    // heap den adres in hücresayısı kadar int alan alınır
    Hucre* gec = adres->ilk;    // gecici Hucre pointer ı oluşturur ve adres in ilkini atar.
    int sayac = 0;  
    for (int i = 0; i < adres->hucreSayisi; ++i)    // gelen adresin hücre sayısı kere döner.
    {
        siralanmamisDoku[i] = gec->dnaVeri; // siralanmamis dokunun i nincisine gec in dnaverisi atanır.
        sayac++;
        if (gec->sonraki == 0)  // gecin sonraki yoksa girer
            break;
        gec = gec->sonraki; // geci gecin sonrakine eşitler.

        
    }
    Radix* radixx = new Radix(siralanmamisDoku, sayac); // heap den sıralanmamisDoku ve sayac parametresi ile alan alarak radix sınıfından nesne oluşturur.
    int* siraliSayilar = radixx->sirala();  // int pointerına oluşturulan radixx in sırala fonksiyonunu çağırarak atama yapanır.
    delete[] siralanmamisDoku;  // siralanmamisDokunun heap deki alanını siler.
    delete radixx;  // radixx i n heapdeki alanlarını silen fonksiyonu çağırır.
    int ortancaHucreKacinci = 0;   
    for (int i = 0; i < adres->hucreSayisi; i++)    //adresin hucresayısı kadar döner.
    {
        ortancaHucreKacinci++;
    }
    int ortancaHucre = siraliSayilar[ortancaHucreKacinci];     
    delete[] siraliSayilar; // siralisayilar dizisini siler
    return ortancaHucre;    
}
void IkiliAramaAgaci::yedektenAgacYap()
{
    for (int i = 0; i < yedekAgacSayaci; i++)   // yedekagac içerisindeki doku sayısı kadar döner
    {
        ekle (yedekAgac[i], kok , radixSortIleSirala(yedekAgac[i]));    //  yedekagac içerisindeki her doku için ekle fonksiyonunu çağırır.
    }
}
void IkiliAramaAgaci::ekle(Doku* dokuAdres, AgacDugum* aktifDugum , int ortanca)
{
    if (kok == 0)   // Eğer kök yoksa girer
    {

        kok = new AgacDugum(dokuAdres); // heap den yeni alan alarak agacdugum oluşsturur ve kök e atar.
        kok->ortancaHucre = ortanca;    // kök ün ortancahücresine ortancayı atar.
        return;
    }
    else if (aktifDugum->ortancaHucre >= dokuAdres->ortancaHucreyiGetir()->dnaVeri) // aktifin ortanca hücresi gelen dokunun ortancahücresinden büyük eşitse girer.
    {
        if (aktifDugum->sol != 0)   //aktifin solu varsa girer
        {
            ekle(dokuAdres, aktifDugum->sol, ortanca); // ekle fonksiyonunu çağırır
        }
        else {
            aktifDugum->sol = new AgacDugum(dokuAdres); // aktifin soluna heapden aldığı alana agacdüğüm oluşturarak atar.
            aktifDugum->sol->ortancaHucre = ortanca; //aktifin solunun ortancahücresine ortancayı atar
        }
        return;
    }
    else if(aktifDugum->ortancaHucre < dokuAdres->ortancaHucreyiGetir()->dnaVeri) //aktifin ortancahücresi dokuadresin ortancahücresinden kücükse girer.
    {
        if (aktifDugum->sag != 0) //eğer aktifin sağı varsa girer.
        {
            ekle(dokuAdres, aktifDugum->sag ,ortanca); // ekle fonksiyonunu çağırır.
        }
        else {
            aktifDugum->sag = new AgacDugum(dokuAdres); // aktifin sağına heapden aldığı alanda agacdüğüm oluşturarak atar.
            aktifDugum->sag->ortancaHucre = ortanca;    // aktifin sağının ortancahücresine ortancayı atar.
        }
        return;
    }
    
}
