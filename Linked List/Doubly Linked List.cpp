#include<iostream>
using namespace std;

struct node{
    node *prev; //a pointer pointing to the previous node
    int data;
    node *next; //a pointer pointing to the next node
};

node *start = NULL; // a global pointer pointing to the start of the list

node *create_node(){
    node *temp;
    temp = new node;
    cout << "Please enter the Data: " << endl;
    cin >> temp->data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void insert_node(){
    node *temp, *traverse;
    temp = create_node();
    if(start == NULL){
        start = temp;
    }
    else{
        traverse = start;
        while(traverse->next != NULL){
            traverse = traverse->next;
        }
        traverse->next = temp;
        temp->prev = traverse;
    }
}

void add_begin(){
    node *temp;
    temp = create_node();
    temp->next = start;
    start->prev = temp;
    start = temp;
}

void add_after(){
    node *temp, *traverse;
    temp = create_node();
    int value;
    cout << "Enter the value after which the data has to be inserted: " << endl;
    cin >> value;
    traverse = start;
    while(traverse->data != value){
        traverse = traverse->next;
    }
    temp->prev = traverse;
    temp->next = traverse->next;
    traverse->next->prev = temp;
    traverse->next = temp;
}

void display(){
    node *traverse;
    traverse = start;
    while(traverse != NULL){
        cout << traverse->data << " ";
        traverse = traverse->next;
    }
}

void delete_begin(){
    node *temp;
    temp = start;
    start = start->next;
    cout << temp->data << " has been deleted" << endl;
    delete(temp);
}

void delete_end(){
    node *traverse;
    traverse = start;
    while(traverse->next != NULL){
        traverse = traverse->next;
    }
    traverse->prev->next = NULL;
    cout << traverse->data << " has been deleted" << endl;
    delete(traverse);
}

void delete_after(){
    int value;
    cout << "Enter the value after which the node has to be deleted: " << endl;
    cin >> value;
    node *temp, *traverse;
    traverse = start;
    while(traverse->data != value){
        traverse = traverse->next;
    }
    temp = traverse->next;
    traverse->next = temp->next;
    temp->next->prev = traverse;
    cout << temp->data << " has been deleted" << endl;
    delete(temp);
    
}

int main(){
    int option;
    do{
        cout << "\nEnter -1 If You want to exit" << endl;
        cout << "---------------------------------" << endl;
        cout << "1 Add Node" << endl;
        cout << "2 Insert Node at First Position" << endl;
        cout << "3 Add Node After a given Node" << endl;
        cout << "4 Delete Last Node" << endl;
        cout << "5 Delete First Node" << endl;
        cout << "6 Delete Node After a given Node" << endl;
        cout << "7 Display" << endl;
        cout << "---------------------------------" << endl;
        
        cin>>option;
        switch(option){
            case 1: insert_node();
                break;
            case 2: add_begin();
                break;
            case 3: add_after();
                break;
            case 4: delete_end();
                break;
            case 5: delete_begin();
                break;
            case 6: delete_after();
                break;
            case 7: display();
                break;
        }
    }while(option != -1);
    
    return 0;
}