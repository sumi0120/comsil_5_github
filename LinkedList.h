#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
using namespace std;

// Linked List Node
template<typename T>
class Node{
public:
    T data;
    Node *link;
    Node(T element){
        data = element;
        link = 0; }
};

// Linked List Class
template<typename T>
class LinkedList
{
protected:
    Node<T> *first;
    int current_size;
public:
    LinkedList(){
        first = 0;
        current_size = 0; };
    int GetSize() { return current_size; }; // 노드 개수를 리턴
    void Insert(T element); // 맨 앞에 원소를 삽입
    virtual bool Delete(T &element); // 맨 뒤의 원소를 삭제
    void Print();    // 리스트를 출력
};

template<typename T>
void LinkedList<T>::Insert(T element){ // 새 노드를 맨 앞에 붙임
    Node<T> *newnode = new Node<T>(element);
    newnode->link = first;
    first = newnode;
    current_size++;
}

template<typename T>
bool LinkedList<T>::Delete(T &element){
    // 마지막 노드의 값을 리턴하면서, 메모리에서 할당 해제
    if(first == 0) return false;
    Node<T> *current = first, *previous = 0;
    while(1){    // 마지막 노드까지 찾아가는 반복문
        if(current->link == 0)    // find end node
        {
            if(previous) previous->link = current->link;
            else first = first->link;
            break;
        }
        previous = current;
        current = current->link;
    }
    element = current->data;
    delete current;
    current_size--;
    return true;
}

//리스트를 출력하는 Print 함수
template<typename T>
void LinkedList<T>::Print(){
    Node<T> *i;
    int index = 1;

    if (current_size != 0){
        for( i = first; i != NULL; i=i->link){
            if (index == current_size){
                cout << "[" << index << "|";
                cout << i -> data <<"]";
            }
            
            else {
                cout << "[" << index << "|";
                cout << i -> data << "]->";
                index++;
            }
        }
        cout << endl;
    }

}


#endif
