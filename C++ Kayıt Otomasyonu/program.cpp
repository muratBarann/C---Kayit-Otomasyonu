#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <string.h>

using namespace std;



class teknik_servis{
	private :
			int f,g,h,k,l;
	public :
		string servisID,servis_neden,kayit_tarih;
		void teknik_servis_veri_ekleme();
		void teknik_servis_veri_listeleme();
		void teknik_servis_veri_arama();
		void teknik_servis_veri_guncelleme();
		void teknik_servis_veri_silme();
		void set_f(int sayi);
		void set_g(int sayi);
		void set_h(int sayi);
		void set_k(int sayi);
		void set_l(int sayi);
		int get_f();
		int get_g();
		int get_h();
		int get_k();
		int get_l();
	
	
};
		
		void teknik_servis::set_f(int sayi)
		{
			f=sayi;
		}
		int teknik_servis:: get_f()
		{
			return f;	
		}
		void teknik_servis::set_g(int sayi)
		{
			g=sayi;
		}
		int teknik_servis::get_g()
		{
			return g;
		}
		void teknik_servis::set_h(int sayi)
		{
			h=sayi;
		}
		int teknik_servis::get_h()
		{
			return h;
		}
		void teknik_servis::set_k(int sayi)
		{
			k=sayi;
		}
		int teknik_servis:: get_k()
		{
			return k;
		}
		void teknik_servis::set_l(int sayi)
		{
			l=sayi;
		}
		int teknik_servis::get_l()
		{
			return l;
		}
		
		void teknik_servis::teknik_servis_veri_ekleme()
		{
			ofstream dosya;
			dosya.open("teknik servis .txt",ios::app);
			teknik_servis tk1;
			cout<<"Servis ID giriniz : "<<endl;
			cin>>tk1.servisID;
			cout<<"Servis Kayit Tarihi giriniz "<<endl;
			cin>>tk1.kayit_tarih;
			cout<<"Teknik Servis Nedenini giriniz \n-Anakart\n-Ram\n-Islemci\n-Ekran\n-EkranKarti\n-Monitor\n-Disket\n-Sabitdisk\n-Kasa\n-Diger"<<endl;
			cin>>tk1.servis_neden;
			dosya<<tk1.servisID<<"       "<<tk1.kayit_tarih<<"       "<<tk1.servis_neden<<endl;
			cout<<"Teknik Servis Kayit Bilgileri Dosyaya Yazildi"<<endl;
			dosya.close();
		}
		
		void teknik_servis:: teknik_servis_veri_listeleme()
		{
			ifstream dosya;
			dosya.open("teknik servis .txt",ios::in);
			string okunan;
			cout<<"Teknik Servis Kayit Verileri \nServisID      Kayit Tarih      Servis Nedeni \n----------------------------------------"<<endl;
			while(!dosya.eof())
			{
				getline(dosya,okunan);
				cout<<okunan<<endl;
			}
			dosya.close();
		}
		
		void teknik_servis:: teknik_servis_veri_arama()
		{
			string okunan,aranan;
			int uzunluk1,uzunluk2;
			ifstream dosya;
			dosya.open("teknik servis .txt",ios::in);
			cout<<"Aramak istediginiz veriyi giriniz "<<endl;
			cin>>aranan;
			
			while(!dosya.eof())
			{
				getline(dosya,okunan);
				uzunluk1=okunan.length();
				uzunluk2=aranan.length();
				for(int i=0 ; i<(uzunluk1-uzunluk2) ; i++)
				{
					if(aranan.compare(okunan.substr(i,uzunluk2))==0)
					{
						cout<<"Aranan Veri : \nServisID      Kayit Tarih      Servis Nedeni \n----------------------------------------"<<endl;
						cout<<okunan<<endl<<endl;
						break;
					}
				}
			}
			dosya.close();
		}
	
	
	void teknik_servis:: teknik_servis_veri_guncelleme()
		{
			string servisID_2;
			int a=0;
			string bosluk=" ";
			cout<<"Guncellemek Istediginiz ServisID giriniz "<<endl;
			cin>>servisID_2;
			ifstream dosya;
			dosya.open("teknik servis .txt",ios::in);
			ofstream dosyaiki;
			dosyaiki.open("gecici.txt",ios::app);
			
			while(!dosya.eof())
			{
				dosya>>servisID>>kayit_tarih>>servis_neden;
				
				if(servisID == servisID_2 && servisID != bosluk)
				{
					cout<<" Eski Servis Bilgileri : \n"<<endl;
					cout<<"Servis ID : "<<servisID<<endl;
					cout<<"Servis Kayit Tarihi : "<<kayit_tarih<<endl;
					cout<<"Servis Nedeni : "<<servis_neden<<endl;
					cout<<endl;
					cout<<"Guncellemek istediginiz bilgileri giriniz : \n"<<endl;
					cout<<"Servis Kayit tarih :";
					cin>>kayit_tarih;
					cout<<"Servis Nedeni giriniz \n-Anakart\n-Ram\n-Islemci\n-Ekran\n-EkranKarti\n-Monitor";
					cout<<"\n-Disket\n-Sabitdisk\n-Kasa\n-Diger"<<endl;
					cin>>servis_neden;
					dosyaiki<<servisID<<"       "<<kayit_tarih<<"       "<<servis_neden<<endl;
					a=1;
					bosluk=servisID;	
					continue;				
				
				}
					if(servisID != servisID_2 && servisID != bosluk)
				{
					dosyaiki<<servisID<<"       "<<kayit_tarih<<"      "<<servis_neden<<endl;
					bosluk=servisID;
									
				}	
				
			}	
			dosya.close();
			dosyaiki.close();
			remove("teknik servis .txt");
			rename("gecici.txt","teknik servis .txt");
				
			if(a==0)
			{
				cout<<"Boyle bir Servis ID si bulunamadi "<<endl;
			}
			
			if(a==1)
			{
				cout<<"Servis Kayit Guncellendi "<<endl;
			}
			
		}


		void teknik_servis:: teknik_servis_veri_silme()
		{
			string servisID_2;
			int a=0;
			string bosluk=" ";
			cout<<"Silmek istediginiz Teknik Servis Kayitin Servis ID sini giriniz "<<endl;
			cin>>servisID_2;
			
			ifstream dosya;
			dosya.open("teknik servis .txt",ios::in);
			ofstream dosyaiki;
			dosyaiki.open("gecici silme.txt",ios::app);
			
			while(!dosya.eof())
			{
				dosya>>servisID>>kayit_tarih>>servis_neden;

				if(servisID != servisID_2 && servisID != bosluk)
				{
					dosyaiki<<servisID<<"       "<<kayit_tarih<<"       "<<servis_neden<<endl;
					bosluk=servisID;
						
				}
				
				if(servisID == servisID_2 && servisID !=bosluk)
				{
					bosluk=servisID;
					a=1;
					cout<<"Kayit Silinidi "<<endl;
				}
						
			}
			
			
			dosya.close();
			dosyaiki.close();
			remove("teknik servis .txt");
			rename("gecici silme.txt","teknik servis .txt");
			if(a == 0)
			{
				cout<<"Boyle Bir Servis ID si bulunamadi "<<endl;
			}			
		}

		
					



class bilgisayar{
	
	public:
		string pcID,pcmarka,musteriad,pcucret;
		void bilgisayar_veri_ekleme();
		void bilgisayar_veri_listeleme();
		void bilgisayar_veri_arama();
		void bilgisayar_veri_guncelleme();
		void bilgisayar_veri_silme();
		
};
		
		void bilgisayar::bilgisayar_veri_ekleme()
		{
			ofstream dosya;
			dosya.open("bilgisayar kayýt .txt",ios::app);
			bilgisayar p1;
			cout<<"Bilgisayar ID sini giriniz :"<<endl;
			cin>>p1.pcID;
			cout<<"Bilgisayarin Markasini giriniz :"<<endl;
			cin>>p1.pcmarka;
			cout<<"Bilgisayar Sahibinin Adini Soyadini giriniz :"<<endl;
			cin>>p1.musteriad;
			cout<<"Bilgisayar Ucreti giriniz :"<<endl;
			cin>>p1.pcucret;
			dosya<<p1.pcID<<"     "<<p1.pcmarka<<"     "<<p1.musteriad<<"     "<<p1.pcucret<<endl;	
			cout<<"Bilgisayar Verileri dosyaya yazildi "<<endl;
			dosya.close();
		}
		
		void bilgisayar::bilgisayar_veri_listeleme()
		{
			ifstream dosya;
			dosya.open("bilgisayar kayýt .txt",ios::in);
			string okunan;
			cout<<"PCID       PC MARKA       PC UCRET       MUSTERI AD\n";
			cout<<"---------------------------------------------------\n";
			while(!dosya.eof())
			{
				getline(dosya,okunan);
				cout<<okunan<<endl;	
			}	
			dosya.close();
		}
		
		void bilgisayar::bilgisayar_veri_arama()
		{
			string okunan,aranan;
			int uzunluk1,uzunluk2;
			ifstream dosya;
			dosya.open("bilgisayar kayýt .txt",ios::in);
			cout<<"Aramak istediginiz veriyi giriniz :"<<endl;
			cin>>aranan;
			
			while(!dosya.eof())
			{
				getline(dosya,okunan);
				uzunluk1=okunan.length();
				uzunluk2=aranan.length();
				for(int i=0 ; i<(uzunluk1-uzunluk2) ; i++)
				{
					if(aranan.compare(okunan.substr(i,uzunluk2))==0)
					{			
						cout<<"Aranan veri \nPCID     PC MARKA     PC UCRET     MUSTERI AD"<<endl;
						cout<<"----------------------------------------"<<endl;
						cout<<okunan<<endl;
						break;
						}
					}
			}
			dosya.close();
		}
	
		
		void bilgisayar::bilgisayar_veri_guncelleme()
		{
			string pcID_2;
			int a=0;
			string bosluk=" ";
			cout<<"Guncelleme istediginiz Bilgisayar Verisinin ID sini giriniz "<<endl;
			cin>>pcID_2;
			ifstream dosya;
			dosya.open("bilgisayar kayýt .txt",ios::in);
			ofstream dosyaiki;
			dosyaiki.open("Gecici.txt",ios::app);
				while(!dosya.eof())
				{
					dosya>>pcID>>pcmarka>>musteriad>>pcucret;
					
					if(pcID == pcID_2 && pcID != bosluk)
					{
						cout<<"Eski Bilgisayar Verileri \n"<<endl;
						cout<<"Bilgisayar ID : "<<pcID<<endl;
						cout<<"Bilgisayar Marka : "<<pcmarka<<endl;
						cout<<"Bilgisayar Ucreti : "<<pcucret<<endl;
						cout<<"Bilgisayar Sahibi : "<<musteriad<<endl;
						cout<<endl;
						cout<<"Guncellemek istediginiz bilgileri giriniz "<<endl;
						cout<<"Bilgisayarin Markasini giriniz :"<<endl;
						cin>>pcmarka;
						cout<<"Bilgisayarin Ucetini giriniz : "<<endl;
						cin>>pcucret;
						cout<<"Bilgisayar Sahibinin Adini giriniz :"<<endl;
						cin>>musteriad;
						
						dosyaiki<<pcID<<"     "<<pcmarka<<"     "<<musteriad<<"     "<<pcucret<<endl;
						a=1;
						bosluk=pcID;
						continue;
					}
					
					 if(pcID != pcID_2 && pcID != bosluk)
					 {
					 	dosyaiki<<pcID<<"     "<<pcmarka<<"     "<<musteriad<<"     "<<pcucret<<endl;
					 	bosluk=pcID;
					 }
					
				}
			
				dosya.close();
				dosyaiki.close();
				remove("bilgisayar kayýt .txt");
				rename("Gecici.txt","bilgisayar kayýt .txt");
				
				if(a==0)
				{
					cout<<"Boyle bir Bilgisayar ID si bulunamadi "<<endl;
				}
				
				if(a==1)
				{
					cout<<"Kayit Guncellendi"<<endl;	
				}
		}
	


		void bilgisayar::bilgisayar_veri_silme()
		{
			string pcID_2;
			int a=0;
			string bosluk=" ";
			cout<<"Silmek istediginiz Bilgisayar Kayitin Bilgisayar ID sini giriniz :"<<endl;
			cin>>pcID_2;
			ifstream dosya;
			dosya.open("bilgisayar kayýt .txt",ios::in);
			ofstream dosyaiki;
			dosyaiki.open("Gecici silme.txt",ios::app);
			
				while(!dosya.eof())
				{
					dosya>>pcID>>pcmarka>>pcucret>>musteriad;
					
					if(pcID != pcID_2 && pcID != bosluk)
					{
						dosyaiki<<pcID<<"     "<<pcmarka<<"     "<<pcucret<<"     "<<musteriad<<endl;
						bosluk=pcID;
					}
					
					if(pcID == pcID_2 && pcID != bosluk)
					{
						bosluk=pcID;
						a=1;
						cout<<"Kayit Silindi "<<endl;
					}
				}
			
			dosya.close();
			dosyaiki.close();
			remove("bilgisayar kayýt .txt");
			rename("Gecici silme.txt","bilgisayar kayýt .txt");
			if (a==0)
			{
				cout<<"Boyle Bir Bilgisayar ID si bulunamadi "<<endl;
			}
				
		}
	




class musteri : public bilgisayar{
	
	private :
		int a,b,c,d,e;
		
		public:
			
			string musteriID,musteri_telefon;
			musteri();
			~musteri();
			void musteri_veri_ekleme();
			void musteri_veri_listeleme();	
			void musteri_veri_arama();
			void musteri_veri_guncelleme();
			void musteri_veri_silme();
			int get_a();
			int get_b();
			int get_c();
			int get_d();
			int get_e();
};
	 
			musteri::musteri()
			{
				a=1;
				b=2;
				c=3;
				d=4;
				e=5;	
			}
				
			int musteri::get_a()
			{
				return a;	
			}	
				
			int musteri::get_b()
			{
				return b;
			}	
			
			int musteri::get_c()
			{
				return c;
			}
			
			int musteri::get_d()
			{
				return d;
			}
			
			int musteri::get_e()
			{
				return e;
			}
			
			musteri::~musteri()
			{}
			
			void musteri::musteri_veri_ekleme()
			{
				ofstream dosya;
				dosya.open("musteri bilgi .txt",ios::app);
				musteri m1;
				cout<<"Musteri ID giriniz :"<<endl;
				cin>>m1.musteriID;
				cout<<"Musteri Ad Soyad giriniz : "<<endl;
				cin>>m1.musteriad;
				cout<<"Musteri Telefon numarasi giriniz Numarinin basinda olan 0 ve 5 girmeyiniz : "<<endl;
				cin>>m1.musteri_telefon;
				cout<<"Bilgisayar ID sini giriniz :"<<endl;
				cin>>m1.pcID;
				dosya<<m1.musteriID<<"       "<<m1.musteriad<<"     "<<m1.musteri_telefon<<"     "<<m1.pcID<<endl;
				cout<<"Musteri Veriler dosyaya yazildi "<<endl;
				dosya.close();	
			}
	
				
			void musteri::musteri_veri_listeleme()
			{
				ifstream dosya;
				dosya.open("musteri bilgi .txt",ios::in);
				string okunan;
				cout<<"ID     AD-SOYAD     TELEFON NO       PC ID "<<endl;
				cout<<"---------------------------------------"<<endl;
				while(!dosya.eof())
				{
					getline(dosya,okunan);
					cout<<okunan<<endl;
				}
				dosya.close();
			}	
	
	
			void musteri::musteri_veri_arama()
			{
				string okunan,aranan;
				int uzunluk1,uzunluk2;
				ifstream dosya;
				dosya.open("musteri bilgi .txt",ios::in);
				cout<<"Aramak istediginiz veriyi giriniz : "<<endl;
				cin>>aranan;
				
				while(!dosya.eof())
				{
					getline(dosya,okunan);
					uzunluk1=okunan.length();
					uzunluk2=aranan.length();
					for(int i=0 ; i<(uzunluk1-uzunluk2); i++)
					{
						
						if(aranan.compare(okunan.substr(i,uzunluk2))==0)
						{
							cout<<"Aranan Kayit \nID     AD-SOYAD     TELEFON NO   PC ID "<<endl;
							cout<<"---------------------------------------"<<endl;
							cout<<okunan<<endl;
							break;
						}
					}
				}
				
				dosya.close();	
			}

		void musteri::musteri_veri_guncelleme()
		{
			string musteriID_2;
			int a=0;
			string bosluk=" ";
			cout<<"Guncellemek istediginiz Musteri Verisinin Musteri ID sini giriniz :"<<endl;
			cin>>musteriID_2;
			ifstream dosya;
			dosya.open("musteri bilgi .txt",ios::in);
			ofstream dosyaiki;
			dosyaiki.open("Gecici musteri.txt",ios::app);
				while(!dosya.eof())
				{
					dosya>>musteriID>>musteriad>>musteri_telefon>>pcID;
					
					if(musteriID == musteriID_2 && musteriID != bosluk)
					{
						cout<<"Eski Musteri Bilgileri \n"<<endl;
						cout<<"Musteri ID : "<<musteriID<<endl;
						cout<<"Musteri AD :"<<musteriad<<endl;
						cout<<"Musteri Telefon : "<<musteri_telefon<<endl;
						cout<<"Bilgisayar ID : "<<pcID<<endl;
						cout<<endl;
						cout<<"Guncellemek istediginiz Verileri giriniz :"<<endl;
						cout<<"Musteri AdSoyad giriniz :"<<endl;
						cin>>musteriad;
						cout<<"Musteri telefon numarasi giriniz :"<<endl;
						cin>>musteri_telefon;
						cout<<"Bilgisayar ID sini giriniz :"<<endl;
						cin>>pcID;
						
						dosyaiki<<musteriID<<"       "<<musteriad<<"     "<<musteri_telefon<<"     "<<pcID<<endl;
						a=1;
						bosluk=musteriID;
						continue;
					}
					if(musteriID != musteriID_2 && musteriID != bosluk)
					{
						dosyaiki<<musteriID<<"       "<<musteriad<<"        "<<musteri_telefon<<"     "<<pcID<<endl;
						bosluk=musteriID;
					}
				}
				dosya.close();
				dosyaiki.close();
				remove("musteri bilgi .txt");
				rename("Gecici musteri.txt","musteri bilgi .txt");
				if(a==0)
				{
					cout<<"Boyle Bir Musteri ID si bulunamadi"<<endl;
				}
				
				if(a==1)
				{
					cout<<"Kayit Guncellendi"<<endl;
				}
		}
		
		void musteri::musteri_veri_silme()
		{
			string musteriID_2;
			int a=0;
			string bosluk=" ";
			cout<<"Silmek Istediginiz Musteri Kayitin Musteri ID sini giriniz "<<endl;
			cin>>musteriID_2;
			ifstream dosya;
			dosya.open("musteri bilgi .txt",ios::in);
			ofstream dosyaiki;
			dosyaiki.open("Gecici musteri silme.txt",ios::app);
				
				while(!dosya.eof())
				{
					dosya>>musteriID>>musteriad>>musteri_telefon>>pcID;
					
					if(musteriID != musteriID_2 && musteriID != bosluk)
					{
						dosyaiki<<musteriID<<"       "<<musteriad<<"        "<<musteri_telefon<<"     "<<pcID<<endl;
						bosluk=musteriID;				
					}
					if(musteriID == musteriID_2 && musteriID != bosluk)
					{
						bosluk=musteriID;
						a=1;
						cout<<"Kayit Silindi "<<endl;
					}
				}
			
			dosya.close();
			dosyaiki.close();
			remove("musteri bilgi .txt");
			rename("Gecici musteri silme.txt","musteri bilgi .txt");
			if(a==0)
			{
				cout<<"Boyle Bir Musteri ID si Bulunamadi"<<endl;
			}
		}
	




int main()
{
	int secim,karar,istek,karari;
	teknik_servis tk1;
	bilgisayar p1;
	musteri m1;
	tk1.set_f(1);
	tk1.set_g(2);
	tk1.set_h(3);
	tk1.set_k(4);
	tk1.set_l(5);
	cout<<"Hangi Islemi Yapmak Istersiniz\n1-Bilgisayar Islemleri\n2-Musteri Islemleri\n3-Teknik Servis Islemleri "<<endl;
	cin>>secim;
	switch(secim)
	{
		case 1:
			
				cout<<"Hangi Islemi Yapmak Istersiniz \n1-Bilgisayar Kayit Ekleme\n2-Bilgisayar Kayit Listeleme\n";
				cout<<"3-Bilgisayar Kayit Arama\n4-Bilgisayar Kayit Guncelleme\n5-Bilgisayar Kayit Silme"<<endl;
				cin>>karar;
				if(karar == 1)
				{
					p1.bilgisayar_veri_ekleme();
				}
				
				else if(karar == 2)
				{
					p1.bilgisayar_veri_listeleme();
				}
				
				else if(karar == 3)
				{
					p1.bilgisayar_veri_arama();
				}
				
				else if(karar == 4)
				{
					p1.bilgisayar_veri_guncelleme();
				}
				
				else if(karar == 5)
				{
					p1.bilgisayar_veri_silme();
				}
				
				else 
				{
				cout<<"Yanlis Secim Yaptiniz "<<endl;
				}
				
					break;
					
									
		case 2:
			
				cout<<"Hangi Islemi Yapmak Istersiniz\n1-Musteri Kayit Ekleme\n2-Musteri Kayit Listeleme\n";
				cout<<"3-Musteri Kayit Arama\n4-Musteri Kayit Guncelleme\n5-Musteri Kayit Silme \n";
				cin>>istek;	
				if(istek == m1.get_a())
				{
					m1.musteri_veri_ekleme();
				}
				
				else if(istek == m1.get_b())
				{
					m1.musteri_veri_listeleme();
				}
				
				else if(istek == m1.get_c())
				{
					m1.musteri_veri_arama();
				}
				
				else if(istek == m1.get_d())
				{
					m1.musteri_veri_guncelleme();
				}
				
				else if(istek == m1.get_e())
				{
					m1.musteri_veri_silme();
				}
				
				else
				{
					cout<<"Yanlis Secim Yaptiniz "<<endl;
				}
				
					break;
				
				
		case 3:
			 
			 cout<<"Hangi Islemi Yapmak Istersiniz\n1-Teknik Servis Kayit Ekleme\n2-Teknik Servis Kayit Listeleme\n";
			 cout<<"3-Teknik Servis Kayit Arama\n4-Teknik Servis Kayit Guncelleme\n5-Teknik Servis Kayit Silme\n";
			 cin>>karari;
			 if(karari == tk1.get_f())
			 {
				tk1.teknik_servis_veri_ekleme(); 	
			 }	
			 
			 else if(karari ==tk1.get_g())
			 {
			 	tk1.teknik_servis_veri_listeleme();
			 }
			 
			 else if(karari == tk1.get_h())
			 {
			 	tk1.teknik_servis_veri_arama();
			 }
			 
			 else if(karari == tk1.get_k())
			 {
			 	tk1.teknik_servis_veri_guncelleme();
			 }
			 
			 else if(karari == tk1.get_l())
			 {
			 	tk1.teknik_servis_veri_silme();
			 }
			 
			 else
			 {
			 	cout<<"Yanlis Secim Yaptiniz "<<endl;
			 }
			 
			 	break;
			 	
			 	
		default :
			
				cout<<"Yanlis Secim Yaptiniz "<<endl;
				break;
			 	
	}
	
	
	
	
	
}



