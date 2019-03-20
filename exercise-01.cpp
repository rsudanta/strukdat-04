/*
*Author:M Risqullah Sudanta G
*NPM: 140810180066
*Deskripsi: Program ini dibuat untuk mendata pegawai
*Tahun: 2019
*/
#include<iostream>
using namespace std;

struct ElementList{
	char nama[100];
	char bidang[10];
	int gaji;
	ElementList*next;
	};
	
	typedef ElementList* pointer;
	typedef pointer list;
	
	void createlist(list& first){
		first=NULL;
	}
	
	void createElement(pointer& pBaru){
		pBaru=new ElementList;
		cout<<"Nama : ";cin.ignore();cin.getline(pBaru->nama, 50);
		cout<<"Divisi/Bidang : ";cin.getline(pBaru->bidang,50);
		cout<<"Gaji : ";cin>>pBaru->gaji;
		pBaru->next=NULL;
		}


void insertFirst(list& first,pointer pBaru){
	if(first==NULL){
		first=pBaru;
	}
	else{
		pBaru->next=first;
		first=pBaru;
	}
}
void deleteFirst(list& first, pointer& pHapus){
	if (first==NULL){
		pHapus=NULL;
		cout << "List kosong, tidak ada yang dihapus" << endl;
	}
	else if (first->next==NULL){
		pHapus=first;
		first=NULL;
	}
	else {
		pHapus=first;
		first=first->next;
		pHapus->next=NULL;
	}
}

void insertLast(list& first, pointer pBaru){
	pointer last;
	if (first==NULL){
		first=pBaru;
	}
	else {
		last=first;
		while (last->next!=NULL){
			last=last->next;
		}
		last->next=pBaru;
	}
}

void deleteLast(list& first, pointer& pHapus){

	pointer last,precLast;
	if (first==NULL){
		pHapus=NULL;
		cout << "List kosong" << endl;
	}
	else if (first->next==NULL){
		pHapus=first;
		first=NULL;
	}
	else {
		last=first;
		precLast=NULL;
		while (last->next!=NULL){
			precLast=last;
			last=last->next;
	}
	pHapus=last;
	precLast->next=NULL;
	}
}
	void traversal(list first){
	pointer pBantu;
	pBantu=first;
	while(pBantu != NULL) {
		cout << "Nama : " << pBantu->nama << endl;
		cout << "Bidang/Divisi : " << pBantu->bidang << endl;
		cout << "Gaji : " << pBantu->gaji << endl;
		pBantu = pBantu->next;
	}
}

main(){
	pointer pHapus,p;
	int x,n;
	list list;
	createlist(list);
	while(x!=6){
		cout << "Menu " << endl;
		cout << "[1] Insert First" << endl;
		cout << "[2] Insert Last" << endl;
		cout << "[3] Delete First" << endl;
		cout << "[4] Delete Last" << endl;
		cout << "[5] Traversal" << endl;
		cout << "[6] Exit" << endl;
		cout << "Masukkan pilihan : ";
		cin >> x;
	switch(x){
		case 1:
			cout<<"Masukan banyak pegawai : ";
			cin>>n;
			cout<<endl;
			for(int i=0;i<n;i++){
				cout<<"\nMasukkan data pegawai ke-"<<i+1<<endl;
				createElement(p);
				insertFirst(list,p);
			}
			traversal(list);
			cout<< endl;
			break;

		case 2:
			cout<<"Masukan banyak pegawai : ";
			cin>>n;
			cout<<endl;
			for(int i=0;i<n;i++){
				cout<<"\nMasukkan data pegawai ke-"<<i+1<<endl;
				createElement(p);
				insertLast(list,p);
				cout<<endl;
			}
			traversal(list);
			cout<<endl;
			break;
		case 3:
			deleteFirst(list,pHapus);
			break;
		case 4:
			deleteLast(list,pHapus);
			break;
		case 5:
			traversal(list);
			break;
	}	
}	
}


