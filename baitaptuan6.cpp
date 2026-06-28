#include <iostream>
#include <string>
using namespace std;
struct File {
    string name;
    int size;
    long time;
};
struct Node {
    File data;
    Node* next;
};
