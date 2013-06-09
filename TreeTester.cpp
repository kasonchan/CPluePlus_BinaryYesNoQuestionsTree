/**
 * File: Treetester.cpp
 * Created Date: November 11, 2010
 * Status: Completed 
 * Programmer: Ka-Son Chan
 * Description: This file contains the testings of the Questions Tree class.
 */ 

#include "QuestionsTree.h"
#include <iostream>
#include <string>
using namespace std;

void instruction()
{
	// Show instructions
	cout << "Instructions: " << endl;
	cout << "1.\tThink of a thing (a noun of some kind).\n"
			 << "2.\tThen the game will try to guess what you are thinking.\n"
			 << "\tIf the program cannot guess what you are thinking, it will ask you\n"
			 << "\tto enter the correct answer followed by a question to tell apart\n"
			 << "\tthe last guessed animal and your animal.\n"
			 << "3.\tYou can play again or exit.\n\n";
}

int main() {

	QuestionsTree QuestionsTree;

	// Testing empty()
	cout << "Is the Question tree empty? " << boolalpha << QuestionsTree.empty() << endl << endl;

	// Show instructions
	instruction();

	// Testing play()
	QuestionsTree.play();

	cout << endl;
}