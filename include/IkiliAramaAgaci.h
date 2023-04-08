/**
* @file           IkiliAramaAgaci.h
* @description    Programım Veri.txt dosyasından okuduğu Sayıları Organizma Oluşturarak Ekrana Belli Kurallara Göre Yazdırma Yapar. 
* @course         1.öğretim C grubu
* @assignment     2.ödev
* @date           10.12.2022 - 20.12.2022
* @author         Metin Görgülü - metin.gorgulu@ogr.sakarya.edu.tr
*/
#include  "AgacDugum.h"
#include "Radix.h"
class IkiliAramaAgaci
{
public:
	
	IkiliAramaAgaci();	//	Kurucu Fonksiyon
	~IkiliAramaAgaci();	// 	Yok edici Fonksiyon
	void ekle(Doku* dokuAdres, AgacDugum* aktifDugum);	// Agaç İçerisine AgacDüğüm ekleme Fonksiyonu.
	void agaciSil();	// Agacı silme Fonksiyonu.
	bool denge;		// Ağacın dengeli mi dengesiz mi verisini tutan bool.
	void dengeliMi(); // dengeli mi değil mi bulan fonksiyon
	AgacDugum* kok;	// Agacın kök adresini tutan pointer.
	void mutasyonaUgradi();	// Ağac mutasyona uğradı ise ağacı değiştiren fonksiyon.
private:
	void	agaciSil(AgacDugum* agacdugumu);	// Aşırı Yükleme ile agacı silme fonksiyonu.
	void	postOrder(AgacDugum* aktif);	// PostOrder ile Agacı gezen fonksiyon.
	Doku**	yedekAgac;	
	int		yedekAgacSayaci;
	int		radixSortIleSirala(Doku* adres); //	Radix sor ile sıralayan fonksiyon.
	int		yukseklik(AgacDugum* aktifDugum);	// Aşırı Yükleme ile Agacın yüksekliğini bulan fonksiyon.
	int		yukseklik();	//Agacın yüksekliğini bulan fonksiyon.
	void	yedektenAgacYap();	//Oluşturulan yedekagactan tekrardan agac yapma fonksiyonu.
	void	dengeliMi(AgacDugum* aktifDugum);	//Aşırı yükleme İle Dengeli mi fonksiyonu.
	void	ekle(Doku* dokuAdres, AgacDugum* aktifDugum, int ortanca);	//AŞırı yükleme ile ekleme fonksiyonu.
};

