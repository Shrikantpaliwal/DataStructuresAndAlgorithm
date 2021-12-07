#include <iostream>

class LinkedListOps{
private:
    struct Node{
      int data;
      Node* link;
    };

    Node* head = NULL;
    int listIndex = 0;

public:
    int insertNodeAtBeginning(int in_data){
      if(head == NULL){
        head = new Node();
        head->data = in_data;
        head->link = NULL;
        listIndex++;
      }
      else{
        Node* tmp = new Node();
        tmp->data = in_data;
        tmp->link = head;
        head = tmp;
        listIndex++;
      }
      return 0;
    }
    
    int insertNodeAtEnd(int in_data){
      if(head == NULL){
        head = new Node();
        head->data = in_data;
        head->link = NULL;
        listIndex++;
      }
      else{
        Node* tmp = head;
        while(tmp->link != NULL){
          tmp = tmp->link;
        }
        Node* newNode = new Node();
        newNode->data = in_data;
        newNode->link = NULL;
        tmp->link = newNode;
        listIndex++;
      }
      return 0;
    }

    int insertNodeAtIndex(int nodeIndex, int in_data){
      std::cout << listIndex;
      if(listIndex<nodeIndex){
        std::cout << "Can not insert at Index:" << nodeIndex << std::endl;
        return -1;
      }
      if(head == NULL or listIndex == 0 or nodeIndex == 0){
        // First Node is not present
        return insertNodeAtBeginning(in_data);
      }
      if(listIndex == nodeIndex){
        // Insert Node at End
        return insertNodeAtEnd(in_data);
      }
      int tempIndexCouter = 1;
      Node * tempNode = head;
      while(tempIndexCouter != listIndex){
        if(tempIndexCouter == nodeIndex){
          Node* newNode = new Node();
          newNode->data = in_data;
          newNode->link = tempNode->link;
          tempNode->link = newNode;
          listIndex++;
          return 0;
        }
        tempIndexCouter++;
        tempNode = tempNode->link;
      }
      return -1;
    }


    void printLinkedList(){
      Node* itr = head;
      while(itr != NULL){
      std::cout << itr->data << "->";
      itr = itr->link;
      }
    }

};

int main(){
  LinkedListOps temp{};
  std::cout << temp.insertNodeAtBeginning(10) << std::endl;
  std::cout << temp.insertNodeAtBeginning(5) << std::endl;
  std::cout << temp.insertNodeAtEnd(15) << std::endl;
  std::cout << temp.insertNodeAtBeginning(12) << std::endl;
  std::cout << temp.insertNodeAtIndex(0, 69) << std::endl;
  std::cout << temp.insertNodeAtIndex(1, 59) << std::endl;
  std::cout << temp.insertNodeAtIndex(4,55) << std::endl;
  std::cout << temp.insertNodeAtIndex(5,505) << std::endl;
  std::cout << temp.insertNodeAtIndex(6,95) << std::endl;
  std::cout << temp.insertNodeAtIndex(3,95) << std::endl;
  temp.printLinkedList();
  return 0;

}
