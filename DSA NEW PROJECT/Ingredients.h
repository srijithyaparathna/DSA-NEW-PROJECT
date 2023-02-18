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
	unordered_map<string, Ingredient*> umap;
	
	Ingredients() {
		umap = {};
		
	};
	void insertNewIngredient(Ingredient* newIng) {
		umap.insert(make_pair(newIng->ingredientName, newIng));
		//cout << "Successfully added" << endl;
	}

	void printIngredients()
	{
		int i = 1;
		for (auto const& pair : umap) {
			std::cout << i << " " << pair.first << ": " << pair.second->ingredientPrice << "\n";
			i++;
		}
	}

	void printIngredientsOnly()
	{
		int i = 1;
		for (auto const& pair : umap) {
			std::cout << i << " " << pair.first  << "\n";
			i++;
		}
	}

	void printIngredientsFull()
	{
		int i = 1;
		for (auto const& pair : umap) {
			std::cout << i << " "  << "Buy  " << pair.first << " for " << pair.second->ingredientPrice << " from " << pair.second->shopName << "\n";
			i++;
		}
	}


	int getPriceFromKey(string key) {
		if (umap.find(key) == umap.end())
			return -1;
		else
			return umap.find(key)->second->ingredientPrice;

	}

	string selectIngredientAsKey(int pos) 
	{
		string key;
		int i = 1;
		for (auto const& pair : umap) {
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