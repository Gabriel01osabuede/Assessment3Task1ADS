#pragma once
#include <iostream>

using namespace std;

class binary_search_tree_cl
{

	struct node
	{
		int data;
		struct node *left_child, *right_child;
	};

	struct node* root = NULL;

	struct node* new_node(int item)
	{
		struct node* temp = (struct node*)malloc(sizeof(struct node));
		temp->data = item;
		temp->left_child = temp->right_child = NULL;
		return temp;
	}


public:
	virtual void insert_data(int data)
	{
		struct node *temp_node = (struct  node*)malloc(sizeof(struct node));
		struct node *current;
		struct node *parent;

		temp_node->data = data;
		temp_node->left_child = NULL;
		temp_node->right_child = NULL;

		
		//if tree is empty
		if (root == NULL)
		{
			root = temp_node;
		}
		else
		{
			current = root;
			parent = NULL;
			while (1)
			{
				parent = current;

				//go to the left of the tree
				if (data < parent-> data)
				{
					current = current->left_child;

					//insert to the left
					if (current == NULL)
					{
						parent->left_child = temp_node;
						return;
					}
				}//go to the right
				else
				{
					current = current->right_child;

					//insert to the right
					if (current == NULL)
					{
						parent->right_child = temp_node;
						return;
					}
				}
			}
		}

	}

public:
	struct node* search_binary_search_tree(int number)
	{
		struct node* current = root;
		//printf("\nVisiting elements : ");
		while (current->data != number)
		{
			if (current != NULL)
			{
				//printf("%d ", current->data);

				//go to the left tree
				if (current->data > number)
				{
					current = current->left_child;
				}//else go to the right tree
				else
				{
					current = current->right_child;
				}

				//if number not found
				if (current == NULL)
				{
					cout << "Number not Found" << endl;
					return NULL;
				}
			}
		}
		cout << "Number Found : " << current->data << endl;
		return current;
	}


	private:
	//print tree using in_order_traversal.
	void print_tree(struct node* Node)
	{
		if (Node == NULL)
		{
			return;
		}

		print_tree(Node->left_child);
		printf("---%d", Node->data);
		print_tree(Node->right_child);
	}

	private:
	void test_binary_search_tree()
	{
		binary_search_tree_cl binary_search_tree_cl;

		binary_search_tree_cl.insert_data(55);
		binary_search_tree_cl.insert_data(40);
		binary_search_tree_cl.insert_data(65);
		binary_search_tree_cl.insert_data(60);
		binary_search_tree_cl.insert_data(75);
		binary_search_tree_cl.insert_data(57);
		binary_search_tree_cl.insert_data(66);
		binary_search_tree_cl.insert_data(72);


		binary_search_tree_cl.print_tree(binary_search_tree_cl.root);

		cout << endl;
		cout << "Searching for 66" << endl;
		node *node = binary_search_tree_cl.search_binary_search_tree(66);

		
		if (node->data != NULL)
		{
			cout << "Search for value : " << node->data << " was found." << endl;
		}
		else
		{
			cout << "Search for 66 not found";
		}

	}
};




