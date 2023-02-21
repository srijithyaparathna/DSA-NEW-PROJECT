#pragma once
#include <iostream>
#include <string>
#include "Ingredients.h"
#include "Shops.h"

using namespace std;
class Recipie
{
public:
	string recipieName;
	Ingredients* currentList;
	Ingredients* bestOption = new Ingredients();

	Recipie()
	{
		recipieName = "";

	}
	Recipie(string rN, Ingredients* CL) {
		recipieName = rN;
		currentList = CL;
	}
};

class RecipieNode {
public:
	Recipie* elem;
	RecipieNode* next;

	RecipieNode() {
		elem = NULL;
		next = NULL;
	}

	RecipieNode(Recipie* val) {
		elem = val;
		next = NULL;
	}
};

class Recipies {
protected:
	RecipieNode* head;
	RecipieNode* tail;
	

public:
	int size;
	Recipies() {
		head = NULL;
		tail = NULL;
		size = 0;
	}

	void insertFirst(Recipie* val) {
		// Create a RecipieNode
		RecipieNode* temp = new RecipieNode(val);

		if (head == NULL) {
			head = temp;
			tail = temp;
			size++;
		}
		else {
			temp->next = head;
			head = temp;
			size++;
		}
	}

	//void insertLast(int val) {
	//    // Create a RecipieNode
	//    RecipieNode* temp = new RecipieNode(val);

	//    if (tail == NULL) {
	//        head = temp;
	//        tail = temp;
	//        size++;
	//    }
	//    else {
	//        tail->next = temp;
	//        tail = temp;
	//        size++;
	//    }
	//}

	//void insertAt(int pos, int elem) {
	//    if (pos < 0 || pos > size)
	//        std::cout << "Invalid Index" << std::endl;
	//    else if (pos == 0)
	//        insertFirst(elem);
	//    else if (pos == size)
	//        insertLast(elem);
	//    else {
	//        RecipieNode* temp = new RecipieNode(elem);
	//        RecipieNode* current = head;

	//        for (int i = 0; i < pos - 1; i++)
	//            current = current->next;

	//        temp->next = current->next;
	//        current->next = temp;
	//        size++;
	//    }
	//}

	void deleteFirst() {
		if (head == NULL)
			std::cout << "Empty List" << std::endl;
		else {
			RecipieNode* temp = head;
			if (size == 1) {
				delete temp;
				head = NULL;
				tail = NULL;
			}
			else {
				head = head->next;
				delete temp;
			}
			size--;
		}
	}

	void deleteLast() {
		if (head == NULL)
			std::cout << "Empty List" << std::endl;
		else {
			RecipieNode* temp = tail;
			if (size == 1) {
				delete temp;
				head = NULL;
				tail = NULL;
			}
			else {
				RecipieNode* current = head;
				for (int i = 0; i < size - 2; i++) {
					current = current->next;
				}
				tail = current;
				tail->next = NULL;
				delete temp;
			}
			size--;
		}
	}

	void deleteAt(int pos) {
		if (pos < 0 || pos >= size)
			std::cout << "Invalid position" << std::endl;
		else if (pos == 0)
			deleteFirst();
		else if (pos = size - 1)
			deleteLast();
		else {
			RecipieNode* current = head;
			for (int i = 0; i < pos - 1; i++) {
				current = current->next;
			}
			RecipieNode* temp = current->next;
			current->next = temp->next;
			delete temp;
			size--;
		}
	}
	Recipie* getRecipieAt(int pos) {
		if (pos < 0 || pos >= size) {
			std::cout << "Invalid position" << std::endl;
			return new Recipie();
		}
		else 
		{
			RecipieNode* current = head;
			for (int i = 0; i < pos; i++) {
				current = current->next;
			}
			//ShopeNode* temp = current->next;
			return current->elem;
		}
	}

	void getRecipieNames() {
		RecipieNode* current = head;
		int i = 1;
		while (current != NULL) {
			std::cout << i << " " << current->elem->recipieName << "\n";
			//current->elem->currentList->printIngredients();
			current = current->next;
			i++;
		}
		std::cout << std::endl;
	}

	// traverse
	void print() {
		RecipieNode* current = head;

		while (current != NULL) {
			std::cout << current->elem->recipieName << " ";
			current->elem->currentList->printIngredients();
			current = current->next;
		}
		std::cout << std::endl;
	}


	void calculateBestOption(Shops* shopList)
	{
		shopList->budgetListGen();
		Ingredients* currentListBestForShopList = shopList->budgetList;

		RecipieNode* currentNode = head;
		
		while (currentNode != NULL)
		{
			for (auto const& pair : currentNode->elem->currentList->umap)
			{
				currentNode->elem->bestOption = new Ingredients();
				if (currentListBestForShopList->umap.find(pair.first) != currentListBestForShopList->umap.end())
				{
					currentNode->elem->bestOption->insertNewIngredient(new Ingredient(pair.first ,currentListBestForShopList->getPriceFromKey(pair.first) ,pair.second->shopName));			
				}
				//currentNode->elem->bestOption->insertNewIngredient(new Ingredient("asdas",55,"asdasd"));
			}
			//cout << "Beset Option to Buy the Recipie is " << endl;

			//currentNode->elem->bestOption->printIngredientsFull();
		
			currentNode = currentNode->next;

		}
			}

};

