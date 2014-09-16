/*
 * bitree.cpp
 *
 *  Created on: Sep 16, 2014
 *      Author: eric
 */
#include <iostream>
using namespace std;
struct tree{
	int data;
	tree *left,*right;
};

class Btree{
public:
	tree *root;
	Btree();
	void createBtree(int);
	void preOrder(tree *node);
	void inOrder(tree *node);
	void postOrder(tree *node);
	void findLeaf(tree*);
	tree* findNode(tree*,int);
};

Btree::Btree(){

}

void Btree::createBtree(int data){
	tree *newnode = new tree;
	newnode->data = data;
	if(root == NULL){
		root = newnode;
	}else{
		tree *p = root;
		tree *prev;
		while(p != 0){
			prev = p;
			if(p->data > data){
				p = p->left;
			}else{
				p = p->right;
			}
		}
		if(prev->data >data)
			prev->left = newnode;
		else
			prev->right = newnode;
	}
}

void Btree::preOrder(tree *node){
	if(node != NULL){
		cout<<node->data<<" ";
		preOrder(node->left);
		preOrder(node->right);
	}
}

void Btree::postOrder(tree *node){
	if(node){
		postOrder(node->left);
		postOrder(node->right);
//		cout<<node->data<<" ";
	}
}

void Btree::inOrder(tree *node){
	if(node){
//		inOrder(node->left);
		cout<<node->data<<" ";
		inOrder(node->right);
	}
}

void Btree::findLeaf(tree *node){
	if(node)return ;
	else{
		if(node->left == NULL && node->right == NULL){
		}else{
			findLeaf(node->left);
			findLeaf(node->right);
		}
	}
}

tree* Btree::findNode(tree *node,int data){
	if(node == 0)return NULL;
	if(node->data == data )
		return node;
	else{
		if(node->left && node->right){
			findNode(node->left,data);
			findNode(node->right,data);
		}
		else if(node->left == NULL && node->right){
			findNode(node->right,data);
		}
		else if(node->left && node->right == NULL){

			findNode(node->left,data);
		}
	}
}

int main()
{
    Btree A;
    int array[]={7,4,2,3,15,35,6,45,55,20,1,14,56,57,58};
    int k;
    k=sizeof(array)/sizeof(array[0]);
    cout<<"建立排序二叉树顺序: "<<endl;
    for(int i=0;i<k;i++){
//    	cout<<array[i]<<" ";
    	A.createBtree(array[i]);
	}
    cout<<endl;
	cout<<"前序遍历序列: "<<endl;
    A.preOrder(A.root);
}

