#include "Node.hpp"
#include "LinkedList.hpp"
#include <string>

LinkedList::LinkedList(std::string new_data){
    Node new_head(new_data);
    head = new_head;
};

Node LinkedList::_find_node(std::string data_to_be_found){
    Node current_node = head;
    if(head.data.empty()){
        return;
    }
    else if(head.data == data_to_be_found){
        return head;
    }
    else{
        while(current_node.next != nullptr){
            
            current_node = *current_node.next;
        }
    }

    return current_node;
};

std::string LinkedList::search(std::string data){
    return _find_node(data).data;
}

void LinkedList::push_to_head(std::string data){
    Node node = _find_node(data);

};

void LinkedList::push_to_tail(std::string data){

};

void LinkedList::display(){

}