#include<iostream>
using namespace std;

struct node{
  int data;
  struct node *next; //a pointer pointing to node
};

node *start = NULL; // a global pointer pointing to the start of the list

node *createNode(){
  node *temp;
  temp = new node;
  return temp;
}

void insertNode(){
  node *temp, *traverse;
  int n;
  cout << "Enter -1 to end" << endl;
  cout << "Enter the value to be added in list" << endl;
  cin >> n;
  while(n != -1){
    temp = createNode();
    temp->data = n;
    temp->next = NULL;
  
    if(start == NULL){
      start = temp;
    }
    else{
      traverse = start;
      while(traverse->next != NULL){
        traverse = traverse->next;
      }
      traverse->next = temp;
    }
    cout << "Enter the value to be added in the list" << endl;
    cin >> n;
  }
}

void printlist(){
  node *traverse2 = start;
  cout << "Your linklist: ";
  while(traverse2 != NULL){
    cout << traverse2->data << " ";
    traverse2 = traverse2->next;
  }
  cout << "" << endl;
}

int main(){
  int option;
  do{
    cout << "\n-------Start-------" << endl;
    cout << "1: Create List" << endl;
    cout << "2: Print List" << endl;
    cout << "3: Exit" << endl;
    cout << "" << endl;
    cin>>option;
    
    switch(option){
      case 1: insertNode();
        break;
      case 2: printlist();
        break;
    }
  }while(option != 3);
}