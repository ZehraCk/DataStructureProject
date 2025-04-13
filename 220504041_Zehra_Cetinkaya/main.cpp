#include <iostream>
#include <fstream>
#include <string>
#include <time.h>


using namespace std;
struct Sarki{
	public:
	int id,calmaSuresi;
	int dinlenmeSayisi=0;
	int favoriSarkiPuani=0;

	string sarkiAd;
	string muzisyen;
	
	
	struct  Sarki *next;
	
};
	
	class Liste{	
		private:
			struct  Sarki *head;
			string dataFile;
				int sarkiSayisi=0;
		public:
			Liste():head(NULL),dataFile("sarkilar.txt"){}
			
				void sarkiEkle();	
				void sarkiKaydet();
				
					
			
			void tumSarkilariListele();
			void calmaListesiOlustur();
			void calmaListesindenSarkiOynat();
			void favoriSarkiListesi();
			void calmaListesiniGoruntuleyin();
			
			};
			void Liste::sarkiEkle(){
				bool durum=true;
				Sarki * sarki=new Sarki;
				
				if(durum){
				
			cout<<"Asagidaki listede secilecek sarkilarin listeleri bulunmaktadir"<<endl;
				tumSarkilariListele();
			
				cout<<" calma listesine eklemek istediginiz sarkinin numarasi: ";
				cin>>sarki->id;
				
					cout<< " calma listesine eklemek istediginiz sarkinin adi: ";
					cin>>sarki->sarkiAd;
					
					cout<<" calma listesine eklemek istediginiz sarkinin muzisyeni: ";
					cin>>sarki->muzisyen;
				
					
					if(head==NULL){
						head=sarki;
						
					}else{
						Sarki* current=head;
				
						
							while(current->next!=NULL){
							current=current->next;
						}
						current->next=sarki;
					}
					cout<<" yeni sarki listeye eklendi"<<endl;
				sarkiKaydet();
				
						
					}}
						void Liste::sarkiKaydet(){
				
				ofstream outputFile("sarkilar.txt",ios::app);
	
				if(outputFile.is_open()){
					Sarki *current=head;
						outputFile<<head->id<<","<<head->sarkiAd<<","<<head->muzisyen<<endl;
					while(current!=NULL){
						outputFile<<current->id<<","<<current->sarkiAd<<","<<current->muzisyen<<endl;
						current=current->next;
					}
					
					outputFile.close();
					cout<<"\nsarki dosyaya kaydedildi: "<<endl;
					
				}
				else{
					cout<<"kaydedilemedi"<<endl;}
					}
					void Liste:: tumSarkilariListele(){
			ifstream oku("sarkilar.txt");
			string line;
			if(oku.is_open()){
				while(getline(oku,line)){
					cout<<line<<endl;
				}
				oku.close();
			}
		
			}
			void Liste::calmaListesiOlustur(){
				system("cls");
				Sarki *sarki2=new Sarki;
				
				tumSarkilariListele();
				cout<<"calma listesine eklenecek sarkinin adi: ";
				cin>>sarki2->sarkiAd;
				cout<<"calma listesine eklenecek sarkinin muzisyeni: ";
				cin>>sarki2->muzisyen;
				sarki2->next=NULL;
				if(head==NULL){
					head=sarki2;
				}
				else{
					Sarki *temp=head;
					while(temp!=NULL){
						temp=temp->next;
						
					}
					temp=head;
					while(temp->next!=NULL){
						temp=temp->next;
					}
					temp->next=sarki2;
				}
				cout<< "sarki calma listesine kaydedildi"<<endl;
				sarkiSayisi++;	
			}
				void Liste::calmaListesindenSarkiOynat(){
				system("cls");
				int found=0;
				string sarkiAd;
				if(head==NULL){
					cout<<"calma Listesi Bos"<<endl;
				}
				else{
					cout<<" dinlemek istediginiz sarkinin adi : "<<endl;
					cin>>sarkiAd;
					Sarki *temp=head;
					
					while(temp!=NULL){
						if(sarkiAd==temp->sarkiAd){
							system("cls");
							cout<<temp->sarkiAd<<endl;
							cout<<temp->muzisyen<<endl;
						
							temp->dinlenmeSayisi++;
							
							found++;	
						}
						temp=temp->next;
						
					}
					if(found==0){
						cout<<"sarki bulunamadi"<<endl;
					}
				}
			}
				void Liste::calmaListesiniGoruntuleyin(){
				system("cls");
				if(head==NULL){
					cout<<"liste bos"<<endl;
				}
				else{
					Sarki *temp=head;
					while(temp!=NULL){
						
						cout<<"sarki adi: "<<temp->sarkiAd<<" , muzisyeni: "<<temp->muzisyen<<" , calma suresi: "<<temp->calmaSuresi<<" , dinlenme sayisi: "<<temp->dinlenmeSayisi<<" , favori sarki puani: "<<temp->favoriSarkiPuani<<endl;
						temp=temp->next;
					}
						cout<<"sarki adi: "<<temp->sarkiAd<<" , muzisyeni: "<<temp->muzisyen<<" , calma suresi: "<<temp->calmaSuresi<<" , dinlenme sayisi: "<<temp->dinlenmeSayisi<<" , favori sarki puani: "<<temp->favoriSarkiPuani<<endl;
				}	
			}
			void Liste::favoriSarkiListesi(){
				Sarki *temp=head;
				
		
				srand(time(NULL));
				while(temp!=NULL){
					
					temp->calmaSuresi=rand()%(100)+1;
					temp->favoriSarkiPuani=temp->calmaSuresi + temp->dinlenmeSayisi;
					
					cout<<"sarki adi: "<<temp->sarkiAd<<" , muzisyeni: "<<temp->muzisyen<<" , calma suresi: "<<temp->calmaSuresi<<" , dinlenme sayisi: "<<temp->dinlenmeSayisi<<" , favori sarki puani: "<<temp->favoriSarkiPuani<<endl;
					temp=temp->next;
				
				}
				cout<<"sarki adi: "<<temp->sarkiAd<<" , muzisyeni: "<<temp->muzisyen<<" , calma suresi: "<<temp->calmaSuresi<<" , dinlenme sayisi: "<<temp->dinlenmeSayisi<<" , favori sarki puani: "<<temp->favoriSarkiPuani<<endl;
			}				
int main(){
	int secim;
	Liste l;
	while(1){
		
cout<<" 1- Sarki Listesine Eleman Ekleyin: "<<endl;
cout<<" 2- Calma Listesi Olusturun: "<<endl;
cout<<" 3- Calma listesinden sarki oynatin: "<<endl;
cout<<" 4- Calma listesini goruntuleyin: "<<endl;
cout<<" 5- Tum Sarkilari Listeleyin: "<<endl;
cout<<" 6- Favori Sarki Listesi: "<<endl;
cout<<" Seciminiz: ";
cin>>secim;

switch(secim){
	case 1: l.sarkiEkle();
	break;
	case 2: l.calmaListesiOlustur();
	break;
	case 3: l.calmaListesindenSarkiOynat();
	break;
	case 4: l.calmaListesiniGoruntuleyin();
	break;
	case 5: l.tumSarkilariListele();
	break;
	case 6: l.favoriSarkiListesi();
	break;
			}
		}	
	return 0;
}