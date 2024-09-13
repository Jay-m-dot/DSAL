

#include<iostream>
#include<stdlib.h>
using namespace std;
#include <queue>

struct treeNode {
	int data;
	treeNode *left;
	treeNode *right;
};

treeNode *insert(treeNode *node, int data) {
	if(node==NULL) {
		treeNode *temp;
		temp = new treeNode;
		temp->data=data;
		temp->left,temp->right=NULL;
		return temp;

	}
	else if(data > (node->data)) {
		node->right=insert(node->right,data);
	}
	else if(data < (node->data)) {
		node->left= insert(node->left,data);
	}
	return node;
}


treeNode *findMin(treeNode *node) {
	if(node==NULL) {
		return NULL;
	}
	else if(node->left) {
		return  findMin(node->left);
	}
	else
		return node;
}


treeNode *Delet(treeNode *node, int data) {
	treeNode *temp;

	if(node == NULL) {
		cout<<"element not found";
	}
	else if(data > node->data) {
		node->right=Delet(node->right,data);

	}
	else if(data < node->data) {
		node->left=Delet(node->left,data);

	}
	else {
		if(node->right && node->left) {
			temp = findMin(node->right);
			node->data=temp->data;
			node->right=Delet(node->right,temp->data);
		}
		else {
			temp=node;
			if(node->left==NULL)
				node=node->right;

			else if(node->right==NULL)
				node=node->left;
			free(temp);

		}

	}

	return node;
}

treeNode *findMax(treeNode *node) {
	if(node==NULL) {
		return NULL;

	}
	else if(node->right) {
		return findMax(node->right);
	}
	else
		return node;
}

treeNode *search(treeNode *node , int data){
    if (node == NULL || node->data == data){
        return node;
    }
    else if(data < node->data)
            return search(node->left , data);
    
    return search(node->right ,data);
}




void inOrder(treeNode *node) {
	if(node==NULL) {
		return ;
	}

	inOrder(node->left);
	cout<<node->data<<" ";
	inOrder(node->right);

}

void preOrder(treeNode *node) {
	if(node==NULL) {
		return  ;
	}

	cout<<node->data<<" ";
	preOrder(node->left);
	preOrder(node->right);


}

void postOrder(treeNode *node) {
	if(node==NULL) {
		return ;
	}

	postOrder(node->left);
	postOrder(node->right);
	cout<<node->data<<" ";


}


void printlevelwise(treeNode *node) {
    if (node == NULL) {
        return;
    }

    queue<treeNode*> q;
    q.push(node);
    q.push(NULL); 

    while (!q.empty()) {
        treeNode* temp = q.front();
        q.pop();
        if (temp != NULL) {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        } else {
            cout << endl;
            if (!q.empty()) {
                
                q.push(NULL);
            }
        }
    }
}


int main() {
	treeNode *root = NULL, *temp;
	int ch ;
	while(1) {

		cout<<"\n\n\n 1.Insert \n 2.Delete \n 3.findMin \n 4.findMax \n 5.Inorder \n 6.Preorder \n 7.Postorder \n 8.Search \n 9.Print level Wise\n ";
		cout<<"Enter Your Choice : ";
		cin>>ch;

		switch(ch) {
		case 1:
			cout<<"Enter a value to be inserted : ";
			cin>>ch;
			root = insert(root, ch);
			cout<<"BST: ";
			inOrder(root);
			break;
		case 2:
			cout<<"Enter element to be delete : ";
			cin>>ch;
			root= Delet(root, ch);
			cout<<"BST: ";
			inOrder(root);
			break;
		case 3:
			temp = findMin(root);
			cout<<temp->data<<" ";
			break;
		case 4:
			temp = findMax(root);
			cout<<temp->data<<" ";
			break;
		case 5:
		    cout<<"Inorder BST : ";
			inOrder(root);
			break;
		case 6:
		    cout<<"Preorder BST : ";
			preOrder(root);
			break;
		case 7:
		    cout<<"Postorder BST : ";
			postOrder(root);
			break;
		case 8:
		    cout<<"Enter element to be searched : ";
		    cin>>ch;
		    temp = search(root ,ch);
		    cout<<"Searched element : ";
		    cout<<temp->data<<" ";
		    break;
		case 9:
		    printlevelwise(root);
		    break;
		case 10:
			cout<<"Exitting";
			break;
		}
	}

}





