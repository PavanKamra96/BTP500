/**
*Name: Pavan Kumar Kamra
*Date: 12/21/2017
*Course: BTP500
*Purpose: Working with BST 
**/
#include "arrayqueue.h"
#include<iostream>
template <typename T>
class BST{
	struct Node{
		T data_;
		Node* left_;
		Node* right_;
		Node(const T& data,Node* left=nullptr,Node* right=nullptr){
			data_=data;
			left_=left;
			right_=right;
			}
	};
	Node* root_;
	//this function inserts data into the tree with root
	//subRoot
	void insert(const T& data, Node*& subRoot){
		if(subRoot==nullptr){
			subRoot=new Node(data);
		}
		else{
			if(data < subRoot->data_){
				insert(data,subRoot->left_);
			}
			else{
				insert(data,subRoot->right_);
			}
		}
	}
	//this function will receive a pointer to a node
	//and detach and remove the smallest node in this subtree
	Node* detachInorderSuccessor(Node*& subRoot){
	if(subRoot->left_ == nullptr)
		{
			Node* rc = subRoot;
			subRoot = subRoot->right_;
			return rc; 
		}
		else
			return detachInorderSuccessor(subRoot->left_); 
	}
	
	
	void remove(const T& data, Node*& subRoot){
		if(subRoot!=nullptr){
			if(data == subRoot->data_){
				Node* rm=subRoot;   //make a temp to subRoot so I 
				                    //don't lose it by accident
				//subroot is a leaf node
				if(subRoot->left_==nullptr && subRoot->right_==nullptr){
					//null out pointer from parent
					subRoot=nullptr;
				}
				else if(subRoot->left_!=nullptr && subRoot->right_==nullptr){
					//one child on left
					subRoot=subRoot->left_;
				}
				else if(subRoot->right_!=nullptr && subRoot->left_==nullptr){
					//one child on right
					subRoot=subRoot->right_;
				}
				else{
					Node* inorderSuccesor = detachInorderSuccessor(subRoot->right_);
					inorderSuccesor->left_=subRoot->left_;
					inorderSuccesor->right_=subRoot->right_;
					subRoot=inorderSuccesor;
				}


				delete rm;
			}
			else if(data < subRoot->data_){
				remove(data,subRoot->left_);
			}
			else{
				remove(data,subRoot->right_);
			}
		}

	}
	void printPreOrder(const Node* subRoot) const{
		if(subRoot!=nullptr){
			std::cout << subRoot->data_ << " ";
			printPreOrder(subRoot->left_);
			printPreOrder(subRoot->right_);
		}
	}
	void printInOrder(const Node* subRoot) const{
		if(subRoot!=nullptr){
			printInOrder(subRoot->left_);
			std::cout << subRoot->data_ << " ";
			printInOrder(subRoot->right_);
		}
	}
	void printPostOrder(const Node* subRoot) const {
		if (subRoot != nullptr) {
			printPostOrder(subRoot->left_); 
			printPostOrder(subRoot->right_); 
			std::cout << subRoot->data_ << " ";
		}
	}
	
	int getDepth(Node* n, const T& data, int level)
	{
        	if(n != nullptr){
                                                
               	if(n->data_ == data)
               	{
                        return level;
                }
                                                
                int downlevel = getDepth(n->left_, data, level+1);
                if (downlevel > 0)
                        return downlevel;
                                                
                downlevel = getDepth(n->right_, data, level+1);
                if (downlevel > 0)
                        return downlevel;
                }
          	return -1;
        }  

	void destroy(Node* subRoot){
		if(subRoot!=nullptr){
			destroy(subRoot->left_);
			destroy(subRoot->right_);
			delete subRoot;
		}
	}

	Node* cNode(Node*& currentRoot, Node* cpyRoot)
	{
		if(cpyRoot != nullptr)
		{
			currentRoot = new Node(cpyRoot->data_); 
			cNode(currentRoot->right_, cpyRoot->right_); 
			cNode(currentRoot->left_, cpyRoot->left_);
			return currentRoot; 
		}
		else 
			return nullptr; 
	}

public:
	// default constructor
	BST(){
		root_=nullptr;
	}

	// copy constructor 
	BST(const BST& rhs)
	{
	  root_ = cNode(root_, rhs.root_);
	}
	
	void insert(const T& data){
		insert(data,root_);
	}

	void iterativeInsert(const T& data){
		if(root_==nullptr){
			root_=new Node(data);
		}
		else{
			Node* curr=root_;
			bool inserted=false;
			while(!inserted){
				if(data < curr->data_){
					if(curr->left_ == nullptr){
						curr->left_=new Node(data);
						inserted=true;
					}
					else{
						curr=curr->left_;
					}
				}
				else{
					if(curr->right_==nullptr){
						curr->right_=new Node(data);
						inserted=true;
					}
					else{
						curr=curr->right_;
					}
				}
			}
		}
	}	

	void remove(const T& data){
		remove(data,root_);
	}

	 int depth(const T& data)
        {
		return getDepth(root_, data, 0);   
        }

	//preOrder is depth first
	void printPreOrder() const{
		printPreOrder(root_);
	}
	//inOrder is depth first
	void printInOrder() const{
		printInOrder(root_);
	}	
	//postOrder is depth first
	void printPostOrder() const{

	}
	
	//breadthFirst
	void printBreadthFirst() const{
		Queue<Node*> q;
		q.enqueue(root_);
		while(!q.empty()){
			Node* curr=q.front();
			q.dequeue();
			if(curr!=nullptr){
				std::cout << curr->data << " " << std::endl;
				q.enqueue(curr->left_);
				q.enqueue(curr->right_);
			}
		}
	}
	
	// deconstructor 
	~BST(){
		destroy(root_);
	}
};











					





