#include <iostream>

using namespace std;

struct node{

    int data;
    node*next;
};

void printlist(node *head){
    node *next = head;
    while(next != nullptr){
        cout<<"Data = "<< next->data <<endl;
        next = next->next;
    }
}

node *reverselist(node* head){
node *prev = nullptr;
node *current = head;
node *next = nullptr;

while(current != nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main(){

    int nodes;
    cout<<"Input the number of nodes: ";
    cin>>nodes;

    node*head = nullptr;
    node*next = nullptr;

    for(int i = 1; i <= nodes; i++){
        node* newnode = new node();
        cout<<"Input data for node " << i << " : ";
        cin>>newnode->data;
        newnode->next = nullptr;

        if(head == nullptr){
            head = newnode;
            next = head;

        }else{
        next->next = newnode;
        next = newnode;
        }
    }

    next = head;

    cout<<" " << endl;
    cout<<"Data entered list are: "<< endl;
    while(next != nullptr){

        cout<<"Data = " << next->data<<endl;
        next = next ->next;
    }

    cout<<" " << endl;
    head = reverselist(head);

    cout<<"The list in reverse are: "<< endl;
    printlist(head);

    return 0;
}
