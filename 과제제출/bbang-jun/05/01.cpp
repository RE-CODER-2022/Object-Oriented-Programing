#include <iostream>
#include <cstring>
using namespace std;

class Node {

private:
	int value; // 노드의 데이터
	Node* leftChild = NULL; // 왼쪽 자식
	Node* rightChild = NULL; // 오른쪽 자식
	Node* next = NULL;

public:
	void setValue(int data) { this->value = data; }
	int getValue() { return this->value; }
	void setNext(Node* nextNode) { next = nextNode; } // 다음 노드를 동적할당으로 만들어줌
	Node* getNext(){ return next; }
	void setLeftChild(Node* leftNode) { leftChild = leftNode; } // 왼쪽 자식
	Node* getLeftChild() { return leftChild; }
	void setRightChild(Node* rightNode) { rightChild = rightNode; } // 오른쪽 자식
	Node* getRightChild() { return rightChild; }
};


class Tree {
private:
	Node* root;
public:
	Tree() {
		root = NULL;
	}
	Node* getRoot() { return root; }
	void INSERT(Node*curNode, int dequeue_num);
	bool SEARCH(int data);
	void PRINT(string command); // 출력 함수
	void PRE(Node* curNode); // 전위 순회 함수
	void POST(Node* curNode); // 후위 순회 함수
	void IN(Node* curNode); // 중위 순회 함수
};

void Tree::INSERT(Node*curNode, int dequeue_num) {
	if (root == NULL) { // 루트 노드가 없는 경우
		Node* newNode = new Node;
		newNode->setValue(dequeue_num);
		newNode->setLeftChild(NULL);
		newNode->setRightChild(NULL);
		root = curNode = newNode;
	}
	else if (curNode->getValue()>dequeue_num) { 
		if (curNode->getLeftChild() == NULL) {
			Node* newNode = new Node;
			newNode->setValue(dequeue_num);
			newNode->setLeftChild(NULL);
			newNode->setRightChild(NULL);
			curNode->setLeftChild(newNode);
		}
		else { // 왼쪽 자식이 있을 경우 INSERT 함수를 다시 실행함으로써 현재 노드의 위치를 왼쪽 자식으로 이동
			INSERT(curNode->getLeftChild(), dequeue_num);
		}
	}
	else if (curNode->getValue()<dequeue_num) { // 오른쪽 자식이 없는 경우
		if (curNode->getRightChild() == NULL) {
			Node* newNode = new Node;
			newNode->setValue(dequeue_num);
			newNode->setLeftChild(NULL);
			newNode->setRightChild(NULL);
			curNode->setRightChild(newNode);
		}
		else {
			INSERT(curNode->getRightChild(), dequeue_num);
		}
	}
}

bool Tree::SEARCH(int data) {
	Node* curNode = root;
	while (curNode != NULL) {
		if (curNode->getValue() == data) {
			return true;
		}
		else if (curNode->getValue() != data) {
			if (curNode->getValue() > data) {
				curNode = curNode->getLeftChild();
			}
			else if (curNode->getValue() < data) {
				curNode = curNode->getRightChild();
			}
		}
	}
	return false;
}

void Tree::PRINT(string command) { // 출력 형식
	if (root == NULL) {
		cout << "Error 700";
	}
	if (command == "PRE") {
		PRE(root);
	}
	else if (command == "POST") {
		POST(root);
	}
	else if (command == "IN") {
		IN(root);
	}
}

void Tree::PRE(Node* curNode) {

	if (curNode != NULL) {
		cout << curNode->getValue() << "\t";
		PRE(curNode->getLeftChild());
		PRE(curNode->getRightChild());
	}
}

void Tree::POST(Node* curNode) {

	if (curNode!=NULL) {
		POST(curNode->getLeftChild());
		POST(curNode->getRightChild());
		cout << curNode->getValue() << "\t";
	}
}

void Tree::IN(Node* curNode) {

	if (curNode != NULL) {
		IN(curNode->getLeftChild());
		cout << curNode->getValue() << "\t";
		IN(curNode->getRightChild());
	}
}

class Queue {
public:
	int size;
	Node* front; // 프론트(선출)
	Node* rear; // 리어(후출)
	Queue() {
		front = NULL;
		rear = NULL;
		size = 0;
	}
	bool enqueue(int value);
	bool dequeue(int value, Tree* tree);
	bool empty() {
		if (this->size == 0)
			return true;
		else
			return false;
	}
	void Print_Queue();
};

bool Queue::enqueue(int value) {
	Node* newNode = new Node; // 동적 할당
	newNode->setValue(value); // setValue 함수를 통한 Node의 값 설정
	if (size < 5) {
		if (empty()) // empty=true일때 처음으로 하나가 삽입되므로 front임과 동시에 rear이다.
			front = rear = newNode;

		else { // empty=false 1개 이상 존재할 때
			rear->setNext(newNode); // rear 다음 새로운 노드 생성
			rear = rear->getNext(); // rear는 맨 마지막에 위치해야 하므로 rear의 위치를 새로 생성한 끝 노드로 이동
		}
	}
	else {
		cout << "Error 300" << endl;
		return false;
	}
	size++;

	return true;
}

bool Queue::dequeue(int value, Tree* tree) {
	Node* curNode = front;
	Node* temp;
	if (size > 0) {
		if(value>size){
			value = size; 
		}
		for (int i = 0; i < value; i++) {
			tree->INSERT(tree->getRoot(), curNode->getValue());
			temp = curNode;
			curNode = curNode->getNext();
			front = curNode;
			delete temp;
			size--;
		}
	}
	else
		return false;

	return true;
}

void Queue::Print_Queue() {
	Node* curNode = front;
	if (curNode == NULL)
		cout << "Error 500" << endl;
	else {
		while (curNode != NULL) {
			cout << curNode->getValue() << "\t";
			curNode = curNode->getNext();
		}
		cout << endl;
	}
}

int main(void)
{
	string command=" ";
	string print_way;
	int data = 0;
	char str[50];
	char commandStr[15];
	Queue* queue = new Queue;
	Tree* tree = new Tree;

	while (1)
	{
		cout << "CMD>> ";
		/*cin >> command;*/
		cin.getline(str, 20);
		strcpy(commandStr, str);
		char* commandPtr = strtok(commandStr, " \n"); // 공백, 개행(엔터)를 만날 시 토큰화 진행

		if (commandPtr == NULL) { // strtok로 잘라낸 토큰이 아무 것도 없을 경우(아예 아무것도 입력되지 않았을 때)
			cout << "Error 100" << endl;
			continue;
		}
		else 
			command = commandPtr;

		if (command == "Enqueue") {
			commandPtr = strtok(NULL, " "); // 공백을 만나지 못했을 때(Enqueue만 입력했을 때)
			if (commandPtr == NULL) // 아무것도 입력하지 않았을 때
				cout << "Error 200" << endl;
			else {
				data = atoi(commandPtr); // 문자열을 정수로 변환하여 int형 변수 data에 넣어줌
				commandPtr = strtok(NULL, " "); // 처음에 자른 문자 이후 다시 공백을 만날 때 까지 토큰화

				if (commandPtr != NULL) // Enqueue 이후 아무것도 없을 때
					cout << "Error 200" << endl;
				else {
					if (!data) { // 정수가 아닌 경우 (출력시 0이 나옴)
						cout << "Error 200" << endl;
					}
					else // 정수 일때 enqueue 실행
						queue->enqueue(data);
				}
			}
		}
		else if (command == "Dequeue") {
			commandPtr = strtok(NULL, " ");
			if (commandPtr == NULL)
				cout << "Error 200" << endl;
			else {
				data = atoi(commandPtr);
				commandPtr = strtok(NULL, " ");

				if (commandPtr != NULL)
					cout << "Error 200" << endl;
				else {
					if (!data) 
						cout << "Error 200" << endl;
					else {
						if (!queue->dequeue(data, tree))
							cout << "Error 400" << endl;
					}
						

				}
			}	
		}
		else if (command == "Print_Queue") {
			queue->Print_Queue();
		}
		else if (command == "SEARCH") {
			commandPtr = strtok(NULL, " ");

			if (commandPtr == NULL)
				cout << "Error 200" << endl;
			else {
				data = atoi(commandPtr);
				commandPtr = strtok(NULL, " ");

				if (commandPtr != NULL)
					cout << "Error 200" << endl;
				else
					if (!data)
						cout << "Error 200" << endl;
					else {
						if (tree->SEARCH(data))
							cout << data << " is exists" << endl;
						else
							cout << "Error 600" << endl;
					}
			}
		}
		else if (command == "PRINT") {
			commandPtr = strtok(NULL, " ");
			if (commandPtr == NULL)
				cout << "Error 200" << endl;
			else {
				print_way = commandPtr;
				commandPtr = strtok(NULL, " ");
				if (commandPtr != NULL)
					cout << "Error 200" << endl;
				else {
					tree->PRINT(print_way);
					cout << endl;
				}
			}
		}
		else if (command == "EXIT") {
			break;
		}
		else
			cout << "Error 100" << endl;
	}

	delete queue;
	delete tree;
	return 0;
}