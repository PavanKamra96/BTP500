/**
* Name: Pavan Kumar Kamr
* Student Id: 019384148
* Course: BTP500
* Purpose: To explore singly vs. doubly linked list; and explore the use of sentinel nodes. 
**/

#include <iostream>

template <typename T>
class SList
{
	struct Node{
		T data_;
		Node* next_;
		Node(const T& data=T{},Node* next=nullptr){
			data_=data;
			next_=next;
		}
	};
	Node* front_;
	Node* back_;
public:
	SList(){
		front_=nullptr;
		back_=nullptr;
	}
	void push_front(const T& data);
	void push_back(const T& data);
	void pop_front();
	void pop_back();
	void print() const;
	~SList();
};

template <typename T>
void SList<T>::push_front(const T& data)
{
     Node* filler = new Node(data, front_); 
     if (!front_)
         back_ = filler; 
     front_ = filler; 
}

template <typename T>
void SList<T>::push_back(const T& data)
{
     Node* filler = new Node(data); 
     if (!front_)
     {
         front_ = filler; 
         back_ = filler; 
     }
     else 
     {
         back_->next_ = filler; 
         back_ = filler;  
     }
}

template <typename T>
void SList<T>::pop_front()
{  
     if (front_)
     {
         Node* filler = front_; 
         if(front_ != back_)
             front_ = front_->next_;
         else
         {
              front_ = NULL;
              back_ = NULL;
         }
         delete filler; 
     }
}

template <typename T>
void SList<T>::pop_back(){
     if (front_)
     {
         if(front_ != back_)
         {
             Node* prev = front_;
             while (prev->next_!=back_)
                   prev=prev->next_;
             prev->next_=NULL;
             delete back_;
             back_ = prev;  
         }
         else
         {
               delete back_;
               back_ = front_ = NULL;
         }
     }
}

template <typename T>
void SList<T>::print() const{
       	Node* curr=front_;
       	while(curr){
       		std::cout << curr->data_ << " ";
       		curr=curr->next_;
       	}
       	std::cout << std::endl;
}

template <typename T>
SList<T>::~SList(){
       	Node* curr=front_;
       	while(curr){
       		Node* rm=curr;
       		curr=curr->next_;
       		delete rm;
       	}
}

template <typename T>
class Sentinel{
	struct Node{
		T data_;
		Node* next_;
		Node* prev_;
		Node(const T& data=T{},Node* next=nullptr, Node* prev=nullptr){
			data_=data;
			next_=next;
			prev_=prev;
		}
	};
	Node* front_;
	Node* back_;
public:
	Sentinel(){
		front_=new Node();
		back_=new Node();
		front_->next_=back_;
		back_->prev_=front_;
	}
	void push_front(const T& data);
	void push_back(const T& data);
	void pop_front();
	void pop_back();
	void print() const;
	void reversePrint() const;
	~Sentinel();
};


template <typename T>
void Sentinel<T>::push_front(const T& data)
{
     Node* ss = new Node(data, front_->next_, front_);
     front_->next_->prev_ = ss; 
     front_->next_ = ss;  
}

template <typename T>
void Sentinel<T>::push_back(const T& data)
{
     Node* ss = new Node(data, back_, back_->prev_); 
     back_->prev_->next_ = ss;
     back_->prev_ = ss; 
}

template <typename T>
void Sentinel<T>::pop_front()
{
     Node* sc = front_->next_;
     if (back_ != front_->next_) 
     { 
         front_->next_ = sc->next_;
         sc->next_->prev_ = front_; 
         delete sc;
     }
}

template <typename T>
void Sentinel<T>::pop_back()
{
    Node* ss = back_->prev_;    
    if (back_->prev_!= front_)
    {
        back_->prev_=ss->prev_;
        ss->prev_->next_=back_;
        delete ss; 
    }
} 

template <typename T>
void Sentinel<T>::print() const
{
	Node* curr=front_->next_;
	while(curr!=back_){
		std::cout << curr->data_ << " ";
		curr=curr->next_;
	}
	std::cout << std::endl;
}

template <typename T>
void Sentinel<T>::reversePrint() const
{
	Node* curr=back_->prev_;
	while(curr!=front_){
		std::cout << curr->data_ << " ";
		curr=curr->prev_;
	}
	std::cout << std::endl;
}

template <typename T>
Sentinel<T>::~Sentinel()
{
	Node* curr=front_;
	while(curr){
		Node* rm=curr;
		curr=curr->next_;
		delete rm;
	}
}
