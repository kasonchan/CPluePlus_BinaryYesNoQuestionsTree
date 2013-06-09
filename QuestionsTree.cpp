/**
 * File: QuestionsTree.cpp
 * Created Date: November 11, 2010
 * Status: Completed 
 * Programmer: Ka-Son Chan
 * Description: This file contains the definition of the Questions Tree class
 * functions.
 */ 

#include "QuestionsTree.h"
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

//--- Definition of constructor
QuestionsTree::QuestionsTree() : root(0) 
{}


//--- Definition of destructor
QuestionsTree::~QuestionsTree()
{
	QuestionsTree::destroySubtree(this->root);
}

//--- Definition of destroySubtree
void QuestionsTree::destroySubtree(Node * tree)
{
       if (tree)
		   return;
	   {
		   destroySubtree(tree->yes);
		   destroySubtree(tree->no);
	   }
       // Delete the node at the root.
       delete tree;
}


//--- Definition of empty()
bool QuestionsTree::empty() const 
{
	return root == 0;
}

//--- Definition of askMove()
void QuestionsTree::askMove(Node *& currentPtr)
{
	string answer;
	cout << currentPtr->questionGuess;
	cout << " Please answer\n";
	cin >> answer;
	if (answer == "yes")
	{
		currentPtr = currentPtr->yes;
	}
	if (answer == "no")
	{
		currentPtr = currentPtr->no;
	}
}

//--- Definition of learn
void QuestionsTree::learn(Node *& currentPtr)
{
	string guessAnimal;
	string correctAnimal;
	string newQuestion;
	string answer; // for yes or no

	guessAnimal = currentPtr->questionGuess;
	cout << "I give up. What is it?" << endl;
	cin.ignore();
	getline(cin, correctAnimal); // enter the correct animal
	
	cout << "What can I ask to tell " << correctAnimal << " from "
		 << guessAnimal << "?\n";
	getline(cin, newQuestion); // enter the correct question
	currentPtr->questionGuess = newQuestion;
	cout << "Is that answer to that question yes or no for " << guessAnimal
		 << "?\n";
	cin >> answer; // enter yes/no
	
	currentPtr->questionGuess = newQuestion;

	Node * newYes = new Node;
	Node * newNo = new Node;
	
	
	if (answer == "yes")
	{
		newYes->questionGuess = guessAnimal;
		newNo->questionGuess = correctAnimal;
		currentPtr->yes = newYes;
		currentPtr->no = newNo;
	}
	if (answer == "no")
	{
		newYes->questionGuess = correctAnimal;
		newNo->questionGuess = guessAnimal;
		currentPtr->yes = newYes;
		currentPtr->no = newNo;
	}
}

//--- Definition of play()
void QuestionsTree::play() 
{
	// Set the beginning tree
	const string rootQuestion("Is it an animal?"); 
	const string YGuess("a bear");
	const string NGuess("a carrot");

	Node * rootPtr = new Node;
	Node * YchildPtr = new Node;
	Node * NchildPtr = new Node;
	
	Node * currentPtr;

	rootPtr->questionGuess = rootQuestion;
	root = rootPtr;
	currentPtr = root;
	YchildPtr->questionGuess = YGuess;
	root->yes = YchildPtr;
	NchildPtr->questionGuess = NGuess;
	root->no = NchildPtr;

	for (int i=0; i<20; i++)
	{
		// Asking questions
		cout << "Think of a noun...\n";
		currentPtr = root;
		
		while ((currentPtr->no) && (currentPtr->yes))
			askMove(currentPtr); // move current pointer
		
		while (!(currentPtr->no) && !(currentPtr->yes))
		{
			string answer;
			cout << "My guess is " 
				 << currentPtr->questionGuess << endl; // programm guess
			cout << "Am i right?" << endl;
			cin >> answer;
			if (answer == "no")
				learn(currentPtr); // put new answer and question into the tree
			else
				cout << "I knew it all along!" << endl;
			break;
		}
			cout << endl;
			string cont;
			cout << "Do you want to continue?" << endl;
			cin >> cont;
			if (cont == "no")
				break;
	}

	delete rootPtr;
	delete YchildPtr;
	delete NchildPtr;
}
