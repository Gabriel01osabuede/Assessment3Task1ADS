#pragma once
#include <iostream>
#include "binary_search_tree_cl.h"

using namespace std;

//Implementing RedBalck tree

struct Node {
	int data;
	Node* parent;
	Node* left_child;
	Node* right_child;
	int color;
};

typedef Node* NodePtr;

class RedBlackTree : binary_search_tree_cl
{
private:

	NodePtr root;
	NodePtr TNULL;

	void initializeNULLNode(NodePtr node, NodePtr parent)
	{
		node->data = 0;
		node->parent = parent;
		node->left_child = nullptr;
		node->right_child = nullptr;
		node->color = 0;
	}

	//pre-order traversal
	void pre_order_helper(NodePtr node)
	{
		if (node != TNULL)
		{
			cout << node->data << " ";
			pre_order_helper(node->left_child);
			pre_order_helper(node->right_child);
		}
	}


	//InOrder traversal
	void in_order_helper(NodePtr node)
	{
		if (node != TNULL)
		{
			in_order_helper(node->left_child);
			cout << node->data << " ";
			in_order_helper(node->right_child);
		}
	}

	//post_order traversal
	void post_order_helper(NodePtr node)
	{
		if (node != TNULL)
		{
			post_order_helper(node->left_child);
			post_order_helper(node->right_child);
			cout << node->data << " ";
		}
	}

	NodePtr search_tree_helper(NodePtr node, int Key)
	{
		if (node == TNULL || Key == node->data)
		{
			return node;
		}
		if (Key < node->data)
		{
			return search_tree_helper(node->left_child, Key);
		}
		return search_tree_helper(node->right_child, Key);
	}

	//balance the tree after inseertion if the red black tree rules are not followed
	void insert_fix_helper(NodePtr input_node)
	{
		NodePtr temp_node;
		while (input_node->parent->color == 1)
		{
			if (input_node->parent == input_node->parent->parent->right_child)
			{
				temp_node = input_node->parent->left_child;
				if (temp_node->color == 1)
				{
					temp_node->color = 0;
					input_node->parent->color = 0;
					input_node->parent->parent->color = 1;
					input_node = input_node->parent->parent;
				}
				else
				{
					if (input_node == input_node->parent->left_child)
					{
						input_node = input_node->parent;
						right_rotate(input_node);
					}

					input_node->parent->color = 0;
					input_node->parent->parent->color = 1;
					left_rotate(input_node->parent->parent);
				}
			}
			else
			{
				temp_node = input_node->parent->parent->right_child;

				if (temp_node->color == 1)
				{
					temp_node->color = 0;
					input_node->parent->color = 0;
					input_node->parent->parent->color = 1;
					input_node = input_node->parent->parent;
				}
				else
				{
					if (input_node == input_node->parent->right_child)
					{
						input_node = input_node->parent;
						left_rotate(input_node);
					}

					input_node->parent->color = 0;
					input_node->parent->parent->color = 1;
					right_rotate(input_node->parent->parent);
				}
			}

			if (input_node == root)
			{
				break;
			}
		}

		root->color = 0;
	}


	void print_helper(NodePtr root, string indent, bool last_node)
	{
		if (root != TNULL)
		{
			cout << indent;
			if (last_node)
			{
				cout << "R-----";
				indent += "     ";
			}
			else
			{
				cout << "L------";
				indent += "|     ";
			}

			string s_color = root->color ? "RED" : "BLACK";
			cout << root->data << "(" << s_color << ")" << endl;
			print_helper(root->left_child, indent, false);
			print_helper(root->right_child, indent, true);
		}
	}


	//Rotate right if tree is not balance
	void right_rotate(NodePtr right_rotate_node)
	{
		NodePtr y = right_rotate_node->left_child;
		right_rotate_node->left_child = y->right_child;
		if (y->right_child != TNULL)
		{
			y->right_child->parent = right_rotate_node;
		}

		y->parent = right_rotate_node->parent;
		if (right_rotate_node->parent == nullptr)
		{
			this->root = y;

		}
		else if(right_rotate_node == right_rotate_node->parent->right_child)
		{
			right_rotate_node->parent->right_child = y;
		}
		else
		{
			right_rotate_node->parent->left_child = y;
		}

		y->right_child = right_rotate_node;
		right_rotate_node->parent = y;
	}

	//rotate left if tree is not  balance
	void left_rotate(NodePtr left_node_rotate)
	{
		NodePtr y = left_node_rotate->right_child;
		left_node_rotate->right_child = y->left_child;
		if (y->left_child != TNULL)
		{
			y->left_child->parent = left_node_rotate;
		}

		y->parent = left_node_rotate->parent;
		if (left_node_rotate->parent == nullptr)
		{
			this->root = y;
		}
		else if (left_node_rotate == left_node_rotate->parent->left_child)
		{
			left_node_rotate->parent->left_child = y;
		}
		else
		{
			left_node_rotate->parent->right_child = y;
		}

		y->left_child = left_node_rotate;
		left_node_rotate->parent = y;
	}

	  public:
		  RedBlackTree() {
			  TNULL = new Node;
			  TNULL->color = 0;
			  TNULL->left_child = nullptr;
			  TNULL->right_child = nullptr;
			  root = TNULL;
		  }


	//Inserting a node
	void insert_data(int key) override
	{
		NodePtr node = new Node;
		node->parent = nullptr;
		node->data = key;
		node->left_child = TNULL;
		node->right_child = TNULL;
		node->color = 1;



		NodePtr y = nullptr;
		NodePtr x = this->root;


		while (x != TNULL)
		{
			y = x; 
			
			if (node->data < x->data)
			{
				x = x->left_child;
			}
			else
			{
				x = x->right_child;
			}
		}


		node->parent = y;
		if (y == nullptr)
		{
			root = node;
		}
		else if (node->data < y->data)
		{
			y->left_child = node;
		}
		else
		{
			y->right_child = node;
		}

		if (node->parent == nullptr)
		{
			node->color == 0;
			return;
		}

		if (node->parent->parent == nullptr)
		{
			return;
		}

		insert_fix_helper(node);
	}


	void print_tree()
	{
		if (root)
		{
			print_helper(this->root, "", true);
		}
	}
	
public:
	NodePtr search_tree(int data)
	{
		NodePtr result;
		result = search_tree_helper(this->root, data);
		if (result->data == data)
		{
			cout << "Search Found : " << result->data << endl;
			return result;
		}
		else
		{
			cout << "Value Not Found" << endl;
			return result;
		}
	}


	void Test_balanced_bst_tree()
	{
		RedBlackTree red_black_tree;

		red_black_tree.insert_data(55);
		red_black_tree.insert_data(40);
		red_black_tree.insert_data(65);
		red_black_tree.insert_data(60);
		red_black_tree.insert_data(75);
		red_black_tree.insert_data(57);
		red_black_tree.insert_data(66);
		red_black_tree.insert_data(72);


		red_black_tree.print_tree();

		cout << endl; 
		cout << "Searching for 66" << endl;
		red_black_tree.search_tree(66);

		NodePtr result = red_black_tree.search_tree(66);
		if (result != NULL)
		{
			cout << "Search for value : " << result->data << "was found." << endl;
		}
		else
		{
			cout << "Search for 66 not found";
		}

	}
};

