#include "MyChunkyList.h"
#include <iostream>

// TODO: Member Function Implementation
MyChunkyList::MyChunkyList(int chunksize){
    start = nullptr;
    end = nullptr;
    counter = 0;
    size = chunksize;
    
}
int MyChunkyList::count() const{
   /* MyChunkyNode* h = start;
    int counter = 0;
    while(h !=NULL){
        h = h->after;
       counter+=h->numberOfItems;
    }*/
    return counter; 

}
MyChunkyNode* MyChunkyList::head() const{
    return start;
}
MyChunkyNode* MyChunkyList::tail() const{
    return end; 
}
void MyChunkyList::insert(int index, const std::string& item){
     if(index <0 || (index>count())){
        throw std::out_of_range("invalid index");
    }
    else if(index == 0 && counter == 0){
           MyChunkyNode* newStart = new MyChunkyNode(nullptr, nullptr,size);
           newStart->items()[0] = item;
           start = newStart;
           end = newStart;
           counter++;
           newStart->increment();
       }
    else if(index == 0 && start->count() == size ){
        
            MyChunkyNode* newStart = new MyChunkyNode(start, nullptr, size);
            newStart->items()[0]= item;
            start->setprev(newStart);
            start = newStart;
            counter++;
            newStart->increment();

    } 
    else if(index==counter && end->count() == size){
            MyChunkyNode* newEnd = new MyChunkyNode(nullptr,end, size);
            newEnd->items()[0] = item;
            end->setnext(newEnd);
            end = newEnd;
            counter++;
            newEnd->increment();
    }else{
        MyChunkyNode* n = start;
        MyChunkyNode* track;
        int tracker = 0;
        while(n!=nullptr){
            
            tracker+=n->count();
            if(tracker >= index){
                track = n;
                break;
            }
            n = n->next();
        }
        if(track->count()< size){
            int priorAmount = tracker - track->count();
            int currentIndex = index- priorAmount;
            if(n->items()[currentIndex]== ""){
                n->items()[currentIndex] = item;
                counter++;
                n->increment();

            }else{
                for(int i = currentIndex; i<size;i++ ){
                    std::string temp;
                    temp = n->items()[i+1];
                    n->items()[i+1] = n->items()[i]; 

                }
                n->items()[currentIndex] = item;
                counter++;
                n->increment();
            }


        }
        else{
            if((track->count()+1)%2 == 0){
                MyChunkyNode* split = new MyChunkyNode(track->next(),track, size);
                for(int k = (track->count()+1)/2; k<size;k++){
                    /*for(int g = 0; g<splitArray->length();g++){
                        splitArray[g] = track->items()[k];

                    }*/
                    int g = 0;
                    split->items()[g] = track->items()[k];
                    track->items()[k] = "";
                    g++;
                     

                }
                track->next()->setprev(split);
                track->setnext(split);
                counter++;
                split->countItems();
                track->countItems();
           }
            if((track->count()+1)%2!=0){
                MyChunkyNode* splitOdd = new MyChunkyNode(track->next(),track, size);
                for(int i = ((track->count()+1)/2)+1;i<size;i++){
                    int k = 0;
                    splitOdd->items()[k] = track->items()[i];
                    track->items()[i] = "";
                    k++;
                }
                track->next()->setprev(splitOdd);
                track->setnext(splitOdd);
                
                counter++;
                splitOdd->countItems();
                track->countItems();
            }
        }
            
                
        }
}

  
std::string& MyChunkyList::lookup(int index){
     if(index <0 || index>count()){
        throw std::out_of_range("invalid index");
    }
    MyChunkyNode* h = start;
     
    MyChunkyNode* track;
    int tracker = 0;
    while(h!=nullptr){
            
        tracker+=h->count();
        if(tracker >= index){
            track = h;
            break;
        }
            h = h->next();
    }
    int prior = tracker - track->count();
    index = index - prior;

    return h->items()[index]; 

}
void MyChunkyList::remove(int index){
     if(index <0 || index>count()){
        throw std::out_of_range("invalid index");
    }
    MyChunkyNode* d;
    if(index ==0){
        d = start;
        start = d->next();
        d->setprev(nullptr); 
    }else{
         MyChunkyNode* h = start;
         for(int i = 0; i<index-1;i++){
             h = h->next();
    }
    d = h->next();
    h->setnext(d->next());
   

    } 
     d->setnext(nullptr);
   
    delete(d); 
    counter-=1;

}
/*MyChunkyList::~ChunkyList() {

}*/