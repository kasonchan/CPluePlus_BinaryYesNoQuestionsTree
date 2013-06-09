QT:	QuestionsTree.o TreeTester.cpp
	g++ QuestionsTree.o TreeTester.cpp -o QT
	rm -f *.o

QuestionsTree.o:	QuestionsTree.h QuestionsTree.cpp

clean:
	rm -f *.o