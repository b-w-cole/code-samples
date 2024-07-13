#include <string>


class Node{
    public:
        std::string data;
        Node* next;
        Node* prev;

        Node(std::string data = NULL);
};