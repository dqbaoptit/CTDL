#include<iostream>
using namespace std;

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

    void add(T val)     // Hàm chèn phần tử vào trước danh sách
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
        char get_name(){
            return *hoten_;
        }
        int get_code(){
            return mssv_;
        }
        void ShowInfo(){
            cout <<mssv_<<"\t|\t\t" << hoten_ << '\n';
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

void SaveFile(LinkedList<Student> sv, char *filename){
    FILE * f;
    if((f=fopen(filename,"wb"))==NULL){
        cout <<"Mo file bi loi\n"; 
        return;
    }
    Node<Student>* head = sv.head();
        if (f!=NULL){
    while(head){
            fwrite(head,sizeof(Node<Student>),1,f);
            fclose (f);
        }
        head=head->get_next();
    }
    fclose(f);
    cout << "Da ghi xong danh sach vao file\n";
}
void SaveAs(LinkedList<Student> &sv, char *filename){
    FILE *f;
    Node<Student>* head = sv.head();
    if((f=fopen(filename,"rb"))==NULL){
        cout << " Loi khi mo file...\n";
        return;
    }
    if (f != NULL) {
       while(head){
              fread(&head, sizeof (Node<Student>),1,f);
              head=head->get_next();         
       }
    }
    fclose(f);
}
void showAll(LinkedList<Student> sv){
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

void Scan(LinkedList<Student> &sv){
    int mssv;
    char hoten[30];
    while(1){
        cout << " Nhap ma so (<=0 la ket thuc) : " ;
        cin >> mssv;
        if(mssv <= 0) break;

        if(findInList(sv, mssv)){
            cout << "Ma so sinh vien trung \n";
            continue;
        }
        cin >> hoten;
        Student tmp(hoten,mssv);
        sv.add(tmp);
    }    
}

int main(){
    LinkedList<Student> sv;
    Scan(sv);
    showAll(sv);
}