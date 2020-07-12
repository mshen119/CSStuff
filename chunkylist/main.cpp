#include <iostream>
#include "MyChunkyList.h"
#include "MyChunkyNode.h"
using namespace std;

/*std::string MyChunkyList::listToString(){
    std::string str = "";
    MyChunkyNode* next;
    for(MyChunkyNode* node = _head; node!=nullptr; node = next){
        str+=node->nodeToString();
        next = node->next();
    }
    return str;
}
.
.
.
std::string MyChunkyNode::nodeToString(){
    std::string str = "";
    str+="[";
        for(int i = 0; i<this->_size; i++){
            if((this->items()[i].empty()) || this->items()[i].compare("")==0)
                str+="_,";
            else
                str += this->items()[i]+ ",";
        }
    str+="]";
    return str;
}*/

int main(){
    MyChunkyList list(3);
    //list.insert(0,"bob");
    list.insert(0,"alice");
    list.insert(1,"bob");
    list.insert(2,"cow");
    list.insert(0,"bruh");
    list.insert(1,"hello");
    list.insert(2,"doode");
    list.insert(3,"yeet");
    //list.insert(0,"john");
    cout<<list.listToString()<<endl;

     
}
