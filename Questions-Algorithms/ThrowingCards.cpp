#include <iostream>
using namespace std;

struct Link{
    int element;
    Link *next;

    Link(const int& elemVal, Link* nextVal = NULL){
        element = elemVal;
        next = nextVal;
    }

    Link(Link* nextVal = NULL){
        next = nextVal;
    }
};

class LList{

    private:
    Link *head;
    Link *tail;
    Link *curr;
    int cnt;

    void init(){
        curr = tail = head = new Link;
        cnt = 0;
    }

    void removeAll(){
        while(head != NULL){
            curr = head;
            head = head -> next;
            delete curr;
        }
    }

    public:
        LList(){
            init();
        }

        ~LList(){
            removeAll();
        }

        void clear(){
            removeAll();
            init();
        }

        void insert(const int& it){
            curr -> next = new Link(it, curr -> next);
            if(tail == curr){
                tail = curr -> next;
            }
            cnt++;
        }

        void append(const int& it){
            tail = tail -> next = new Link (it, NULL);
            cnt++;
        }

        int remove(){
            if(curr -> next != NULL){
                int it = curr -> next -> element;
                Link *ltemp = curr -> next;
                if(tail == curr -> next){
                    tail = curr;
                }
                
                curr -> next = curr -> next -> next;
                delete ltemp;
                cnt--;

                return it;
            }
            else {
                cout<<"No element";
                return -1;
            }
        }

        void moveToStart(){
            curr = head;
        }

         void moveToEnd(){
            curr = tail;
        }

        void prev(){
            if(curr != head){
                Link *temp = head;

                while(temp -> next != curr){
                    temp = temp -> next;
                }
                curr = temp;
            }
        }

        void next(){
            if(curr != tail){
                curr = curr -> next;
            }
        }

        int length(){
            return cnt;
        }

        int currPos(){
            Link *temp = head;
            int i;
            for(i = 0; curr != temp; i++){
                temp = temp -> next;
            }

            return i;
        }

        void moveToPos(int pos){
            if((pos >= 0) && (pos <= cnt)){
                curr = head;
                for(int i = 0; i < pos; i++){
                    curr = curr -> next;
                }
            } 

            else{
                cout<<"Position out of range";
            }
        }

        const int& getValue(){
            if(curr -> next != NULL){
                return curr -> next -> element;
            } 
            else{
                cout<<"No Value";
                exit(1);
            }
        }
};

int main(){
    LList* Linked = new LList;
    int entrance, i, temp;

    while(cin >> entrance && entrance != 0 ){
        for(i = 1; i <= entrance; i++){
            Linked -> append(i);
            
        }
        cout << "Discarded cards:";
        if(Linked -> length() >= 2){
            cout << " ";
        }
        while(Linked -> length() > 1){
            Linked -> moveToStart();
            cout << Linked -> getValue();
            if(Linked -> length() > 2){
                cout << ", ";
            }
            Linked -> remove();
            if(Linked -> length() >= 1){
                temp = Linked -> getValue();
            }
            Linked -> remove();
            Linked -> append(temp);
        }

        cout << "\n" << "Remaining card: "<< Linked -> getValue() << "\n";
        Linked -> clear();
    }
    delete Linked;
}
