/**
* @file           Islemler.cpp
* @description    Programım Veri.txt dosyasından okuduğu Sayıları Organizma Oluşturarak Ekrana Belli Kurallara Göre Yazdırma Yapar. 
* @course         1.öğretim C grubu
* @assignment     2.ödev
* @date           10.12.2022 - 20.12.2022
* @author         Metin Görgülü - metin.gorgulu@ogr.sakarya.edu.tr
*/
#include "Islemler.h"

Islemler::Islemler()
{
    dokuSayac = 19;
    organSayac = 99;
    yeniorgan = false;
    sistemisay = 0;
    buyukOrganizma = 0;
    mutasyon = false;
}
Islemler::~Islemler()
{
    delete buyukOrganizma;
}
void Islemler::Okuma()
{
    ifstream file("doc/Veri.txt"); //okunacak dosyanın tutulduğu yer.
    string line;
    Organ* geciciOrgan = 0; // geciciOrgan pointer ı oluşturup 0 atar.
    Sistem* geciciSistem = 0;   // gecici sistem pointer ı olışturup 0 atar
    buyukOrganizma = new Organizma; // heap den alan alarak Organizma Oluşturur ve buyukorganizma pointer ına atar.
    while (getline(file, line)) //dosyadaki sayıları okumak için getline komutu ile satır oldukça while içerisine girmeye devam ediyor.
    {
        Doku* pDoku = new Doku; // Heap den alınan alana Doku oluşturur ve pDoku pointerına atar.
        dokuSayac++;

        string str = line; // str stringinin içerisine satırdaki atr.
        int uzunluk = str.length(); // satırın uzunluğunu bulur.
        
        istringstream is(line);
        int numberOnLine;
        is >> numberOnLine;
        vector<int> myvec;
        int* siralanmamisDoku = new int[uzunluk];   // heapden uzunluk kadar alan alır ve sıralanmamışdoku pointerına atar.
        int sayac = 0;
        while (is)
        {
            myvec.push_back(numberOnLine);
            is >> numberOnLine;

        }

        for (int i = 0; i < myvec.size(); ++i)
        {
            siralanmamisDoku[sayac] = myvec.at(i);  
            sayac++;
        }
        Radix* radixx = new Radix(siralanmamisDoku, sayac); //siralanmamisDoku ve sayac parametreleri ile heap den alan alarak radix oluşturulur. 
        int* siraliSayilar = radixx->sirala();  //siraliSayilar pointer ına radixx i sirala çağırarak atanır.
        delete[] siralanmamisDoku;    // siralanmamisDoku silinir.
        delete radixx;  // radix in içerisindeki tüm alınan heap alanı temizlenir.

        for (int i = 0; i < sayac; i++) //sayac kadar döner
        {
            pDoku->ekle(siraliSayilar[i]);  // pDoku ekle fonksiyonunu siraliSayiların tüm elemanları için çağırır

        }
        delete[] siraliSayilar; // sirali sayilarla işimiz bittiği için heapden siler.
        if (dokuSayac == 20)    // dokuSayac eğer ki 20 ye eşitse girer.
        {
            organSayac++;   //organ sayacı 1 artırır.
            Organ* yeniOrgan = new Organ;   // Heapden yeni alan alarak Organ Oluşturulur.
            geciciOrgan = yeniOrgan;    //geciciorgana yeniOrgan Atanır.
            yeniorgan = true; 
        }
        if (organSayac == 100)  // organ sayac 100 eşitse girer.
        {
            Sistem* yeniSistem = new Sistem;    // Heapden yeni alan alarak Sistem Oluştrurulur.
            geciciSistem = yeniSistem;  // gecicisisteme Yeni sistem atanır
            organSayac = 0;
            sistemisay++;
            buyukOrganizma->SistemEkle(geciciSistem);   // buyukorganizma sistemekle fonksiyonunu gecicisistem parametresi ile çağırır

        }

        if (yeniorgan)  // yeni organ true ise girer
        {
            dokuSayac = 0;
            geciciSistem->organEkle(geciciOrgan); //gecicisisteme organ ekle fonksiyonunu geciciorgan ile çağırır
            yeniorgan = false;
        }
        geciciOrgan->dokuEkle(pDoku); // geciciorganın doku ekle fonksiyonunu pDoku ile çağırır.
        
    }
    
}
void Islemler::Yazdir()
{
    system("cls");
    Organ* gec = 0 ;    // gec Organ pointer ı oluşturulur ve 0/null atanır.
    Sistem* gecsistem = buyukOrganizma->ilk;    //gecici sistem pointerı oluşturulup buyuk organizmanın ilk sisteminin adresi atanır.
    cout << setw(20) << " " << "ORGANIZMA ";    
    if (mutasyon)   //  Mutasyon ture ise girer.
        cout << " (MUTASYONA UGRADI) ";
    cout << endl;
    for (int i = 0; i < sistemisay; i++)   // Sistem sayısı kadar döner.
    {
        gec = gecsistem->ilk;   // gec Organ pointerına gecsistemin ilkini atar.
        while (true)   //sürekli döner break return vs görene kadar.
        {
            gec->organAgac->dengeliMi();    // gec in organagaci için dengeliMi fonksiyonunu çağırır.
            if (gec->sonraki == 0)  // gec in sonraki 0/null sa girer.
                break;  // while dan çıkarır.
            gec = gec->sonraki; // gec e gec in sonrakini atar.
        }
        if (gecsistem->sonraki == 0)    // gecsistemin sonraki 0 ise girer.
            break;  // for dan çıkarır
        gecsistem = gecsistem->sonraki; // gecsistem e gecsistemin sonrakini atar.
    }
    gecsistem = buyukOrganizma->ilk;    // gecissteme buyukorganizmanın ilkini atar.

    for (int i = 0; i < sistemisay; i++)    // sistem sayısı kere döner.
    {
        gec = gecsistem->ilk;   // gec e gecsistemin ilkini atar.
        for (int j = 0; j < 100; j++)   // 100 kere döner
        {

            if (gec->organAgac->denge)  // gecin organagacının dengesi true ise girer.
                cout << " ";
            else
            {
                cout << "#";
            }
            if (gec->sonraki == 0)  // gecin sonraki 0/null sa girer
                break;  // for döndürmeyi durdurur.
            gec = gec->sonraki; // gece gecin sonrakini atar 
        }
        cout << endl;
        if (gecsistem->sonraki == 0)    // gecsistemin sonraki 0/null sa girer.
            break;
        gecsistem = gecsistem->sonraki; // gecsisteme gecsistemin sonrakini atar
    }
}
void Islemler::Mutasyon()
{
    Sistem* geciciSistem = buyukOrganizma->ilk; // gecicisistem adındaki sistem pointerı oluşturularak buyukorganizmanın ilkinin adresi atanır.
    Organ* geciciOrgan = 0; // geciciOrgan adında Organ pointerı oluşturularak 0/null atanır.
    for (int i = 0; i < sistemisay; i++)    // sistem sayısı kere döner.
    {
        geciciOrgan = geciciSistem->ilk; // geciciorgan a gecicisistemin ilkini atar.
        for (int j = 0; j < 100; j++)   // 100 kere döndürür.
        {

            if (!(geciciOrgan->organAgac->kok->ortancaHucre % 50))  // geciciorganın organagacındaki kökün ortancahücresi 50 ye bölünüyorsa girer.
            {
                Doku* geciciDoku = geciciOrgan->ilk;    //gecicidoku adında doku pointerı oluşturarak geciciOrganın ilkini atar.
                Hucre* geciciHucre = 0; // geciciHucre Adında Hucre Pointer ı atayarak 0/null atar.
                for (int k = 0; k < 20; k++)    // 20 kere döndürür
                {
                    geciciHucre = geciciDoku->ilk;  // geciciHucre ye geciciDokunun ilkini atar.
                    for (int l = 0; l < geciciDoku->hucreSayisi; l++)   // geciciDokunun hücresayisi kadar döner
                    {
                        if (!(geciciHucre->dnaVeri % 2))    // geciciHucrenin dnaverisi 2 ye tam bölünüyorsa girer.
                        {
                            geciciHucre->dnaVeri = geciciHucre->dnaVeri / 2;    // geciciHucre nin dnaverisine geciciHucrenin dnaverisinin yarısı atanır.
                        }
                        if (geciciHucre->sonraki == 0)  // geciciHucrenin sonraki 0/null sa girer.
                            break;
                        geciciHucre = geciciHucre->sonraki; // geciciHucreye geciciHucrenin sonraki atanır
                    }
                    if (geciciDoku->sonraki == 0)   //geciciDokunun sonraki 0/null sa girer.
                        break;
                    geciciDoku = geciciDoku->sonraki;   //geciciDokuya geciciDokunun sonraki atanır.
                }
                
               geciciOrgan->organAgac->mutasyonaUgradi(); //geciciOrganın organAgacı için mutasyonaUgradi fonksiyonunu çağırır.
            }
            if (geciciOrgan->sonraki == 0)  // geciciOrganın sonraki 0/null sa girer.
                break;
            geciciOrgan = geciciOrgan->sonraki; //geciciOrgana geciciOrgana sonrakini atar.
        }
        
        if (geciciSistem->sonraki == 0) // geciciSistemin sonraki 0/null sa girer.
            break;
        geciciSistem = geciciSistem->sonraki;   //geciciSistem e gecicisistemin sonraki atanır
    }
    system("cls");
    mutasyon = true;    // mutasyon bool una true atanır
}
void Islemler::EnterTus()
{
    for (int i = 0; i < 1; i++)	//	Enter Tuşuna Basınca Devam Eden Kod.
    {
        const int a = getchar();
        if (a == 1) break;
    }
}