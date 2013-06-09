/**
 * File: QuestionsTree.h
 * Created Date: November 11, 2010
 * Status: Completed 
 * Programmer: Ka-Son Chan
 * Description: This file contains the declaration of the Questions Tree class.
 */ 

#include <iostream>
using namespace std;

#ifndef QUESTIONSTREE_H
#define QUESTIONSTREE_H

class QuestionsTree 
{
private:
	/***** Node class *****/
	class Node 
	{
	public:
		string questionGuess;
		Node * no;
		Node * yes;
		// Node constructors
		Node() : no(0), yes(0) {}
		Node(string questionGuess, Node * no = NULL, Node * yes = NULL) 
		{
			this->questionGuess = questionGuess;
			this->no = no;
			this->yes = yes;
		}
	}; // end of class Node declaration

public:
	/***** Function Members *****/
	QuestionsTree();
	~QuestionsTree();
	void destroySubtree(Node *);
	bool empty() const;
	void askMove(Node *& currentPtr);
	void learn(Node *& currentPtr);
	void play();


private:
	/***** Data Members *****/
	Node * root;
}; // end of class QuestionsTree declaration

#endif