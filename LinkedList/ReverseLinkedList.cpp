#include<iostream>

struct Node{
 int data;
 Node* link;
};


int main(){
    Node* head = NULL;

    Node* temp = new Node();
    temp->data = 7;
    temp->link = NULL;
    head = temp;

    Node* temp2 = new Node();
    temp2->data = 8;
    temp2->link = NULL;
    temp->link = temp2;

    Node* temp3 = new Node();
    temp3->data = 20;
    temp3->link = NULL;
    temp2->link = temp3;

    std::cout << "Printing Linked List" << std::endl;
    Node* newNode = head;
    while(newNode!=NULL){
        std::cout << newNode->data <<std::endl;
        newNode = newNode->link;
    }

    Node* curr = head;
    Node* next = NULL;
    Node* prev = NULL;

    while(curr!=NULL){
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    std::cout << "Printing in Reverse" << std::endl;
    newNode = head;
    while(newNode!=NULL){
        std::cout << newNode->data <<std::endl;
        newNode = newNode->link;
    }

}