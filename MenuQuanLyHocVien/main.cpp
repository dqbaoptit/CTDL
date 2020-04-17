#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <string.h>
#include <windows.h>
#include "mylib.h"

using namespace std;

const int so_item = 10;
const int dong =5;
const int cot = 20 ;
const int Up = 72;
const int Down = 80;
// UI UX 
char thucdon [so_item][50] = {"1. Nhap danh sach hoc vien",
			                  "2. Liet ke danh sach      ",
			                  "3. Tong so hoc vien trong danh sach",
			                  "4. Chen them hoc vien vao danh sach",
			                  "5. In mot sinh vien theo MSSV ",
			                  "6. Xoa mot sinh vien theo MSSV",
			                  "7. Sap xep danh sach",
			                  "8. Ghi danh sach vao file",
							  "9. Nap danh sach tu file",
							  "10. Ket thuc chuong trinh"};
void Normal () {
	SetColor(15);
	SetBGColor(0);
}
void HighLight () {
	SetColor(15);
	SetBGColor(1);
}
int MenuDong(char td [so_item][50]){
  Normal();
  
  system("cls");   int chon =0;
  int i; 
  for ( i=0; i< so_item ; i++)
  { gotoxy(cot, dong +i);
    cout << td[i];
  }
  HighLight();
  gotoxy(cot,dong+chon);
  cout << td[chon];
  char kytu;
do {
  kytu = getch();
  if (kytu==0) kytu = getch();
  switch (kytu) {
    case Up :if (chon+1 >1)
  			  {
  		              	Normal();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
              	chon --;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case Down :if (chon+1 <so_item)
  			  {
  		        Normal();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
              	chon ++;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case 13 : return chon+1;
  }  // end switch
  } while (1);
}

// CORE

template <typename T>

class Node{

    private:

        T       data_;

        Node<T>* next_;

    public:

        Node() : next_(NULL){;};

        void set_data(T value){data_ = value;}

        T get_data(){return data_;}

        void set_next(Node<T>* next){next_ = next;}

        Node<T>* get_next(){return next_;}

};



template <typename T>

class LinkedList{

    public:

    Node<T>* p_head_;  

    Node<T>* p_tail_;

    int cnt;



    //

    public:

    LinkedList() {

        p_head_ = NULL ;

        p_tail_ = NULL;

        cnt=0;

    };



    ~LinkedList() {;};



    void add(T val)   
    {

        cnt++;

        Node<T>* tmp = new Node<T>();

        tmp->set_data(val);

        tmp->set_next(NULL);



        if(p_head_ == NULL){

            p_head_ = tmp;

            p_tail_ = tmp;

        }

        else{

            p_tail_->set_next(tmp);

            p_tail_ = p_tail_ -> get_next();

        }



    }

    void insertFront(T val){

        Node<T>* temp = new Node<T>();

        temp->set_data(val);

        temp->set_next(p_head_);

        p_head_ = temp;

    }

    void add_at(T val, int pos){

        if(pos == 0 || p_head_ ==NULL){

            insertFront(val);

        }

        else{

            int k=1;

            Node<T>* p = p_head_;

            while(p!=NULL && k!=pos){

                p = p->get_next();

                ++k;

            }

            if(k!=pos){add(val);}

            

            else{

                Node<T>* temp = new Node<T>();

                temp->set_data(val);

                temp->set_next(p->get_next());

                p->set_next(temp);

            }

        }

    }

    void remove(int pos){

        if(pos==0){

            if(p_head_==NULL){

                cout<<"Danh sach dang trong\n";

            }else{

                p_head_ = p_head_->get_next();

            }

        }else{

            int k=1;

            Node<T>* p = p_head_;

            while(p->get_next()->get_next()!=NULL && k!=pos){

                p = p->get_next();

                ++k;

            }

            if(k!=pos){

                cout << "Vi tri vuot qua vi tri cuoi cung cua danh sach\n";

            }

            else{

                p->set_next(p->get_next()->get_next());

            }

        }



    }

    int Reccount(){

        return cnt;

    }



    Node<T>* head() {return p_head_;};

};



class Student{

    public:
        Student(){;};
        Student(char hoten[], int mssv);
        ~Student(){;};

        char get_name(){return *hoten_;}
        int get_code(){return mssv_;}
        
        void ShowInfo(){
            cout <<mssv_<<"\t|\t\t" << hoten_ << '\n';
        }
		void set_name(char hoten[]){
			hoten_ = hoten;
		}
		void set_code(int code){
			mssv_ = code;
		}


    private:

        int mssv_;

        char* hoten_;

};



Student::Student(char hoten[],int mssv){

    mssv_ = mssv;

    hoten_ = hoten;

};


	
void delete_sv(LinkedList<Student> sv, int mssv){

    char choice;

    cout<< "Ban chac chan xoa sinh vien nay chu ? Y/N\n";

    cin >> choice;

    if(choice == 'Y'|| choice =='y'){

        Node<Student>* p_head = sv.head();

        if(p_head!=NULL){

            Node<Student>* tmp = p_head;

            int pos=0;

            while(tmp != NULL){

                if(tmp->get_data().get_code() == mssv){

                    sv.remove(pos);

                    break;

                }

                ++pos;

                tmp = tmp->get_next();

            }

        }

    }   

    

}

void showStudentByCode(LinkedList<Student> sv, int mssv){

    Node<Student>* p_head = sv.head();

        if(p_head!=NULL){

            Node<Student>* tmp = p_head;

            int pos=0;

            while(tmp != NULL){

                if(tmp->get_data().get_code() == mssv){

                    tmp->get_data().ShowInfo();

                    break;

                }

                ++pos;

                tmp = tmp->get_next();

            }

        }

}

void swap(Node<Student>* a, Node<Student>* b){

    Node<Student>* tmp = new Node<Student>();

    tmp->set_data(a->get_data());

    a->set_data(b->get_data());

    b->set_data(tmp->get_data());

}

void sort(LinkedList<Student> sv){

    Node<Student>* head = sv.head();

    Node<Student>* node = NULL;

   for (Node<Student> *index = head; index->get_next() != NULL; index= index->get_next()) {

        for (Node<Student> *selection = index->get_next(); selection != NULL; selection = selection->get_next()) {

        if (index->get_data().get_code() > selection->get_data().get_code()) {

            swap(index, selection);

        }

    }

}

}
void delAll(LinkedList<Student> &sv){
	int total = sv.cnt;
	while(total--){
		sv.remove(total);
	}
	
}


void SaveFile(LinkedList<Student> sv, char *filename){

    FILE * f;

    if((f=fopen(filename,"wb"))==NULL){

        cout <<"Mo file bi loi\n"; 

        return;

    }
    Node<Student>* head = sv.head();
	for(Node<Student>* index=head;index!=NULL; index= index->get_next()){
		fwrite(index, sizeof(Student),1,f);
	}
    fclose(f);
    cout << "Da ghi xong danh sach vao file\n";
}

void SaveAs(LinkedList<Student> &sv, char *filename){
	FILE* f;
	if((f=fopen(filename,"rb"))==NULL){
		cout << " Loi khi co gang mo file ";
		return;
	}
			delAll(sv);
	Student tmp;
	while(fread(&tmp,sizeof(Student),1,f)!=0){
		sv.add(tmp);
	}
	fclose(f);
	cout << "Da nap danh sach vao bo nho \n";
	
}

void showAll(LinkedList<Student> sv){
	cout << "MSSV\t\t\tHo va ten\n";
	cout << "----\t\t\t--------\n";
    Node<Student>* p_head = sv.head();

    if(p_head!=NULL){

        Node<Student>* tmp = p_head;

        while(tmp != NULL){

                tmp->get_data().ShowInfo();

                tmp = tmp->get_next();

        }

    }

}

bool findInList(LinkedList<Student> sv, int code){

    Node<Student>* head = sv.head();

    if(head ==NULL) return false;

    else{

        Node<Student>* tmp = head;

        while(tmp != NULL){

            if(tmp->get_data().get_code()==code)

                return true;

            tmp = tmp->get_next();

        }

    }

}
void Scan(LinkedList<Student> &ds){
	do{
		int tmpcode;
		char* tmphoten= new char[30];
		cout << "Nhap MSSV : "; cin >> tmpcode;
		fflush(stdin);
		if(tmpcode <= 0) return;
		if(findInList(ds,tmpcode)){
			cout << "MSSV bi trung.\n";
			continue;
		}
		cout << "Nhap ho ten SV : ";
		cin.getline(tmphoten,30);
		Student sv(tmphoten,tmpcode);
		ds.add(sv);
		fflush(stdin);
	}while(1);
}
void Getch(){
	cout << "Enter de quay tro lai man hinh chinh.";
	getch();
}
int main() {
	system("cls");
	char filename[80]="DSSV.TXT";
	int choice, mssv;
			
	LinkedList<Student> sv;
	do{	
		choice = MenuDong(thucdon);
		system("cls");
		
		switch(choice){
			case 1:
				{
				
			 	cout << "Task : Nhap vao sinh vien\n";
				Scan(sv);
				Getch();
				break;
			}
			case 2:
				{
				cout << "Task : Danh sach sinh vien\n";
				showAll(sv);
				Getch();
				break;
			}
			case 3:
				{
				cout << "Task : Tong so NODE\n";
				cout << "Tong so sinh vien la : " << sv.cnt<<"\n";
				Getch();
				break;
			}
			case 4:
				{
				int pos;
				Student tmp;
				char hoten[30];
				cout << "Task : Chen phan tu\n";
				cout << "Nhap vao MSSV ( <=0 la ket thuc ) : "; cin  >> mssv;
				if(mssv <=0) break;
				while(findInList(sv, mssv)){
					cout << "MSSV da ton tai, moi nhap lai. ";
					cin >> mssv;
				}
				fflush(stdin);
				cout << "Nhap vao ho va ten SV : "; cin.getline(hoten,30);
				fflush(stdin);
				tmp.set_code(mssv);
				tmp.set_name(hoten);
				cout << "Nhap vao vi tri can chen :";
				cin >> pos;
				sv.add_at(tmp,pos);
				Getch();
				break;
			}
			case 5:{
				cout << "Task : In ra sinh vien theo MSSV\n";
				cout << "Nhap vao MSSV : "; cin >> mssv;
				showStudentByCode(sv,mssv);
				Getch();
				break;
			}
			case 6:
				{
				cout << "Task : Delete sinh vien\n";
				cout << "Nhap vao MSSV muon xoa "; cin >> mssv;
				delete_sv(sv,mssv);
				Getch();
				break;
			}
			case 7:
				{
				cout << "Task : Sap xep danh sach sinh vien\n";
				sort(sv);
				char c;
				cout << "Ban co muon in ra lai danh sach ? Y/N ";
				cin >> c;
				if(c=='Y'||c=='y')
					showAll(sv);
					Getch();
				break;
			}
			case 8:
				{
				cout << "Task : Ghi danh sach vao file\n";
				SaveFile(sv, filename);
				Getch();
				
				break;
			}
			case 9:
				{
				cout << "Task : Nap file vao danh sach\n";
				SaveAs(sv, filename);
				Getch();
				break;
			}
			case so_item : return 0;
		}
	}while(1);
	return 0;
}
