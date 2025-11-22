#include <iostream>
using namespace std;

class Node {
public:
    string key,value;
    Node* next;
    Node(string k,string v){key=k;value=v;next=nullptr;}
};

class HashTable {
private:
    static const int SIZE=10;
    Node* table[SIZE];
    int hashFunction(string key){int s=0;for(char c:key)s+=c;return s%SIZE;}
public:
    HashTable(){for(int i=0;i<SIZE;i++)table[i]=nullptr;}
    void insert(string key,string value){
        int index=hashFunction(key);
        Node* n=new Node(key,value);
        n->next=table[index];
        table[index]=n;
    }
    void display(){
        for(int i=0;i<SIZE;i++){
            cout<<"Bucket "<<i<<": ";
            Node* t=table[i];
            while(t){cout<<"("<<t->key<<","<<t->value<<") ";t=t->next;}
            cout<<endl;
        }
    }
};

int main(){
    HashTable h;
    h.insert("A","aaaaa");
    h.insert("B","bbbbb");
    h.insert("C","ccccc");
    h.insert("A","zzzzz");
    h.display();
}
