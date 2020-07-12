#include "MyChunkyNode.h"

// TODO: Member Function Implementation
MyChunkyNode::MyChunkyNode(MyChunkyNode* next, MyChunkyNode* prev, int chunksize){
    objects = new std::string[chunksize];
    numberOfItems = 0;
    after = next;
    mchunk = chunksize;
    previous = prev;
    for(int i = 0; i<mchunk;i++){
        objects[i] = "";
        
    }
}
int MyChunkyNode::count() const{
    
    return numberOfItems; 
}
void MyChunkyNode::increment(){
    /*for(int i = 0; i<mchunk;i++){
        if(!objects[i].empty()){
            numberOfItems++;
        }
    }*/
    numberOfItems++;

}
int MyChunkyNode::countItems(){
    for(int i = 0; i<mchunk;i++){
        if(objects[i]!=""){
            numberOfItems++;
        }
    
}
    return numberOfItems;
}
std::string* MyChunkyNode::items() const{
    /*std::string* str = new std::string[numberOfItems];
    for(std::string::size_type i = 0;i<objects.size();i++){
        str[i] = objects[i];
    }
    return str;*/
    return objects;

}
MyChunkyNode* MyChunkyNode::prev() const{
    return previous;
}

MyChunkyNode* MyChunkyNode::next() const{
    return after;
}
void MyChunkyNode::setnext(MyChunkyNode* next){
    after = next;
}
void MyChunkyNode::setprev(MyChunkyNode* prev){
    previous = prev;
}

MyChunkyNode::~MyChunkyNode() {
    
}