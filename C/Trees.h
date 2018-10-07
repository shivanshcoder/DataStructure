#pragma once
#include<stdlib.h>
#include<stdio.h>

typedef struct tagnode {
	int Value;
	struct tagnode *left;
	struct tagnode *right;
}Node;

Node* InitNode(int data) {
	Node *New = (Node*)malloc(sizeof(Node));
	New->Value = data;
	New->right = NULL;
	New->left = NULL;

	return New;
}
									
void Insert(Node **root, int data) {
	if ((*root) == NULL) {
		(*root) = InitNode(data);
		return;
	}
	else if ((*root)->Value > data) {
		Insert(&(*root)->left, data);
	}
	else {
		Insert(&(*root)->right, data);
	}
	
}

void Search(Node *Root, int Item, Node **ItemAddr) {
	if (Root->Value == Item)
		*ItemAddr = Root;

	else if (Root->Value > Item)
		Search(Root->left, Item, ItemAddr);
	else
		Search(Root->right, Item, ItemAddr);
}

void FindMinValue(Node **Root, Node **MinNode) {
	*MinNode = *Root;
	while ((*MinNode)->left->left) {
		(*MinNode) = (*MinNode)->left;
	} 
}

void Delete(Node **Root, int Value) {
	Node *DelNode = *Root;
	Node *Parent = *Root;
	Node *Temp = *Root;

	if ((Root) == NULL)
		return;

	


	while (DelNode) {
		Parent = DelNode;

		if (DelNode->Value == Value)
			break;
		else if (DelNode->Value > Value)
			DelNode = DelNode->right;
		else
			DelNode = DelNode->left;
	}

	if (DelNode->Value == Value) {
		if ((DelNode->right == NULL) && (DelNode->left == NULL)) {
			free(*Root);
			*Root = NULL;
			return;
		}
		else if (DelNode->left == NULL) {
			Parent = DelNode->right;
			free(DelNode);
		}
		else if (DelNode->right == NULL) {
			if (Parent == *Root)
				*Root = NULL;
			Parent = DelNode->left;
			free(DelNode);
		}
		else {
			FindMinValue(&(DelNode->right), &Temp);

			DelNode->Value = Temp->left->Value;

			free(Temp->left);
			Temp->left = NULL;
		}
	}
	else {
		printf("Value not found!");
		
	}
	
}


//Node* deleteNode(Node* root, int key)
//{
//	if (root == NULL) return root;
//
//	if (key < root->Value)
//		root->left = deleteNode(root->left, key);
//
//	else if (key > root->Value)
//		root->right = deleteNode(root->right, key);
//
//	else
//	{
//		if (root->left == NULL)
//		{
//			Node *temp = root->right;
//			free(root);
//			return temp;
//		}
//		else if (root->right == NULL)
//		{
//			Node *temp = root->left;
//			free(root);
//			return temp;
//		}
//
//		Node* temp = minValueNode(root->right);
//
//		root->Value = temp->Value;
//
//		root->right = deleteNode(root->right, temp->Value);
//	}
//	return root;
//}

void TraversalInorder(Node *Root) {
	if (Root == NULL)
		return;

	TraversalInorder(Root->left);
	printf(" %d ", Root->Value);
	TraversalInorder(Root->right);
}

void TraversalPreorder(Node *Root) {
	if (Root == NULL)
		return;

	printf(" %d ", Root->Value);
	TraversalInorder(Root->left);
	TraversalInorder(Root->right);
}

void TraversalPostOrder(Node *Root) {
	if (Root == NULL)
		return;

	TraversalInorder(Root->left);
	TraversalInorder(Root->right);
	printf(" %d ", Root->Value);
}


void MainMenu() {
	int choice, Value;
	Node *Root = NULL;

	Node *Temp;
	while (1) {
		printf("Trees Operation\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Print\n");
		printf("4. Search\n");
		printf("5. Exit");

		scanf("%d", &choice);

		switch (choice) {
		case 1: {
			printf("\nEnter the Value");
			scanf("%d", &Value);

			Insert(&Root, Value);
		}
				break;

		case 2: {
			printf("\nEnter the Value to be deleted");
			scanf("%d", &Value);

			Delete(&Root, Value);

		}
				break;

		case 3: {
			printf("\nInorder :");
			TraversalInorder(Root);

			printf("\nPreOrder :");
			TraversalPreorder(Root);

			printf("\nPostOrder :");
			TraversalPostOrder(Root);

		}
				break;

		case 4: {

			printf("\nEnter the Value to Searched");
			scanf("%d", &Value);

			Search(Root, Value, &Temp);

			if (Temp == NULL) {
				printf("Item not found");
			}
			else {
				printf("Item found at Address: %u", Temp);
			}
		}
				break;

		case 5:
			exit(0);
		}
	}
}

void test() {
	MainMenu();
}