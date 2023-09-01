#pragma once
#include  <iostream>
#include "balanced_BST_cl.h"
#include "binary_search_tree_cl.h"
#include <list>
#include <cstdlib>
#include <chrono>
#include <vector>

using namespace std::chrono;
using namespace std;


using namespace std;

class ApplicationMenu
{

private:
    string searchList(vector<int> data, int number)
    {
        bool numberFound = false;
        string result;
        int vectorSize = data.size();
        for (int i = 0; i < vectorSize; i++)
        {
            if (data[i] == number && numberFound == false)
            {
                numberFound = true;
                cout << "Number Found in List : " << number << endl;
                return "Completed";
            }
        }
        
        cout << "Number not found in list" << endl;
        return "Completed";
    }


public:
	void ApplicationEntry_point()
	{
        int NumberMax = 150000;
        
        vector<int> NumberList;
        binary_search_tree_cl binary_search_tree_cl;
        RedBlackTree RedBlackTree;
        
        for (int i = 0; i < NumberMax; i++)
        {
            //Inserting into all trees.
            int randomNumber = rand() % NumberMax;
            
            NumberList.push_back(randomNumber);
            binary_search_tree_cl.insert_data(randomNumber);
            RedBlackTree.insert_data(randomNumber);
        }
        cout << "Inserting numbers complete." << endl;


        string selection;
        cout << "Hello Welcome to the Algorithm App Test." << endl;
        cout << "Select an option : \n1) Search for a number in all the data structures\n2) Exit\nEnter your option (1-2) : " << endl;
        cin >> selection;
       
        if (selection == "1")
        {
            int Number = 0;
            cout << "Enter a Number : " << endl;
            cin >> Number;
            
            cout << "\n" << endl;
            int listSize = NumberList.size();


            //List search
            auto start = std::chrono::steady_clock::now();  
            searchList(NumberList, Number);
            auto end = std::chrono::steady_clock::now();
            std::cout << "Time Elasped for list search: " << std::chrono::duration_cast <std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;
            cout << "\n" << endl;

            //Binary Search Tree 
            start = std::chrono::steady_clock::now();
            binary_search_tree_cl.search_binary_search_tree(Number);  
            end = std::chrono::steady_clock::now();
            std::cout << "Time Elasped for Binary search Tree: " << std::chrono::duration_cast <std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;
            cout << "\n" << endl;

            //Red Black tree search
            start = std::chrono::steady_clock::now();
            RedBlackTree.search_tree(Number);
            end = std::chrono::steady_clock::now();
            std::cout << "Time Elasped for Balance Binary search Tree (Red Black Tree): " << std::chrono::duration_cast <std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;
            cout << "\n" << endl;
        }
        else if (selection == "2")
        {
            cout << "App closing, thanks." << endl;
            exit(0);
        }
        else
        {
            cout << "Invalid Entry\nTry Again" << endl;
        }
	}
};

