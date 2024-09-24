#include<iostream>
using namespace std;
class node{
	public:
		int data;
		int ltag , rtag;
		node *right , *left;
};

class thread{
	public:
		thread();
		void insert(node * , node *);
		void create();
		void display();
	private:
		node *dummy;
		node *root , *temp , *New;
};

thread::thread(){
	root=NULL;
};

void thread::create(){
	New = new node;
	New->right = NULL;
	New->left = NULL;
	New->ltag=0;
	New->rtag=0;
	cout<<"Enter the element :";
	cin>>New->data;
	
	if(root==NULL){
		root = New;
		dummy = new node;
		dummy->data=-999;
		dummy->left=root;
		root->left=dummy;
		root->right=dummy;	
	}
	else{
		insert(root,New);
	}
};

void thread::insert(node *root , node *New){
	if(New->data<root->data){
		if(root->ltag==0){
			New->left=root->left;
			New->right=root;
			root->left=New;
			root->ltag=1;
		}
		else 
			insert(root->left,New);	
	}
	if(New->data>root->data){
		if(root->rtag==0){
			New->right=root->right;
			New->left=root;
			root->right=New;
			root->rtag=1;
		}
		else 
			insert(root->right,New);
	}
};

void thread::display(){
	void inorder(node * , node *dummy);
	void preorder(node * , node *dummy);
	if(root==NULL){
		cout<<"Tree is not created";
	}
	else{
		cout<<"Inorder Traversal : ";
		inorder(root ,dummy);
		cout<<"\nPreorder Traversal : ";
		preorder(root , dummy);
	}
};

void inorder(node *temp , node *dummy)
{
	while(temp!=dummy){
		while(temp->ltag==1)
			temp =temp->left;
			cout<<" "<<temp->data;
			while(temp->rtag==0){
				temp =temp->right;
				if(temp==dummy)
					return;
				cout<<" "<<temp->data;
			}
			temp=temp->right;
		}
	}

void preorder(node *temp , node *dummy){
	int flag =0;
	while(temp!=dummy){
		if(flag==0){
			cout<<" "<<temp->data;
		}
		if(temp->ltag==1 && flag==0){
			temp=temp->left;
		}
		else{
			while(1){
				if(temp->rtag==1)
					{
						flag=0;
						temp=temp->right;
						break;
					}
				else{
					if(temp!=dummy){
						flag=1;
						temp=temp->right;
						break;
					}
				}
			}
		}
	}
}

int main(){
	thread th;
	char ans = 'N';
	int choice;
	do{
		cout<<"\n\n1.Create\n2.Display\n";
		cout<<"Enter Your Choice : ";
		cin>>choice;
		switch(choice){
			case 1:
				do{
				
				th.create();
				do{
				cout<<"\nDo you want continue with Create Window(y/n) : ";
				cin>>ans;
				if(ans=='y'){
					continue;
				}
				else if(ans=='n'){
					break;
				}
				else{
					cout<<"Invalid choice";
				}}while(ans!='y');
			}while(ans=='y');
				break;
			case 2:
				th.display();
				break;
			default:
				cout<<"Invalid";
			
		}
		do{
				cout<<"\nDo you want continue with Main Window(y/n) : ";
				cin>>ans;
				if(ans=='y'){
					continue;
				}
				else if(ans=='n'){
					break;
				}
				else{
					cout<<"Invalid choice";
				}}while(ans!='y');
	}while(ans=='y');
	return 0;	
}


