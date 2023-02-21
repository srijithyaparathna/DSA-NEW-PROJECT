#pragma once
#include <list>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;
class Ingredient {
public:
	string ingredientName;
	int ingredientPrice;
	string shopName;

	Ingredient(){
		ingredientName = "0";
		ingredientPrice = 0;
		shopName = "0";
	}

	Ingredient(string iName, int iPrice, string sName) {
		transform(iName.begin(), iName.end(), iName.begin(), ::toupper);
		ingredientName = iName;
		ingredientPrice = iPrice;
		shopName = sName;
	}
};

class Ingredients {
public:
	unordered_map<string, Ingredient*> hashTable;
	
	Ingredients() {
		hashTable = {};
		
	};
	
	void insertNewIngredient(Ingredient* newIng) {
		hashTable.insert(make_pair(newIng->ingredientName, newIng));
		//cout << "Successfully added" << endl;
	}

	void printIngredients()
	{
		int i = 1;
		for (auto const& pair : hashTable) {
			std::cout << i << " " << pair.first << ": Rs. " << pair.second->ingredientPrice << "\n";
			i++;
		}
	}

	void printIngredientsOnly()
	{
		int i = 1;
		for (auto const& pair : hashTable) {
			std::cout << i << " " << pair.first  << "\n";
			i++;
		}
	}

	void printIngredientsFull()
	{
		int i = 1;
		for (auto const& pair : hashTable) {
			std::cout << i << " "  << "Buy  " << pair.first << " for Rs.  " << pair.second->ingredientPrice << " from " << pair.second->shopName << "\n";
			i++;
		}
	}


	int getPriceFromKey(string key) {
		if (hashTable.find(key) == hashTable.end())
			return -1;
		else
			return hashTable.find(key)->second->ingredientPrice;

	}

	int getPriceFromKeyByTraversal(string key) {
		int i = 0;
		for (auto const& pair : hashTable) {
			if (pair.first == key)
			{
				return pair.second->ingredientPrice;
			}
			i++;
		}
		return i;

	}

	string selectIngredientAsKey(int pos) 
	{
		string key;
		int i = 1;
		for (auto const& pair : hashTable) {
			if (i == pos)
			{
				key = pair.first;
			}
			
			//std::cout << i << " " << pair.first << ": " << pair.second->ingredientPrice << "\n";
			i++;
		}
		return key;

	}



};