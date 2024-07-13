#include "Node.hpp"

class LinkedList{
    private:
        Node _find_node(std::string);

    protected:
        Node head;

    public:
        LinkedList(std::string new_data = NULL);
        std::string search(std::string data);
        void push_to_head(std::string data);
        void push_to_tail(std::string data);
        void display();
};