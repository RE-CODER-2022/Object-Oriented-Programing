#include <iostream>
#include <cstring>
using namespace std;

class Node 
{
private:
	Node* next;
	string word; // 단어

public:
	Node()
	{
		this->next = NULL;
	}
	void setNext(Node* nextNode) { this->next = nextNode; }
	Node* getNext() { return next; }
	void setWord(string Word) { this->word = Word; }
	string getWord() { return word; }
};

class Dictionary
{
private:
	Node* head;

public:
	Dictionary()
	{
		head == NULL;
	}
	Node* insertWord(string Word)
	{
		if (head == NULL)
		{
			head = new Node;
			head->setWord(Word);

			return NULL;
		}

		Node* curWord = head;

		while (curWord->getNext() != NULL)
			curWord = curWord->getNext();

		curWord->setNext(new Node); 
		curWord = curWord->getNext();
		curWord->setWord(Word); 
		//curWord->setNext(NULL);

		return curWord;
	}

	bool findWord(string Word)
	{
		Node* curWord = head;

		while (curWord)
		{
			if (curWord->getWord() == Word)
				return true;
			curWord = curWord->getNext();
		}
		return false;
	}

	void Print()
	{
		Node* curNode = head;
		for (int i = 0; curNode != nullptr; i++)
		{
			cout << i <<"."<< curNode->getWord() << endl;
			curNode = curNode->getNext();
		}
	}

	//Node* deleteWord(string Word)
	//{

	//}

};

int main(void)
{
	Dictionary* dictionary = new Dictionary;

	string command, word;
	int num = 0;

	while (1)
	{
		cin >> command;

		if (command == "INSERT")
		{
			cin >> word;

			dictionary->insertWord(word);
			dictionary->Print();
		}
		else if (command == "FIND")
		{
			cin >> word;

			if (dictionary->findWord(word) == true) // 입력한 단어가 있을 때(true)
			{
				//cout << dictionary->curWord->getNum() << "." << dictionary->curWord->getWord();
			}
			else
				cout << "Not Found" << endl;
		}
		else if (command == "DELETE")
		{
			cin >> word;

			/*dictionary->deleteWord(word);*/
		}
		else if (command == "END")
		{
			cout << "END" << endl;

			break;
		}
		else
			cout << "confirm the command!" << endl;
	}

	delete dictionary;

	return 0;
}