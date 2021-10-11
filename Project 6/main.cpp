/*
This program will grab a word from words.txt,
using the characters in the word once, it will spell other words in the text document
*/









#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <random>
#include <algorithm>
using namespace std;



bool comparison(string selectedWord, string wordFromList)
{
	vector<bool> hasCharacter;
	//This is a flag that will terminate this method early
	bool charMatched = true;

	//Look at each of the characters of the word from the list as long as the previous character matched
	for (int i = 0; i < wordFromList.size(); i++)
	{
		if (!charMatched)
		{
			break;
		}

		//Compare each character of the word from the list to the randomly selected word
		for (int j = 0; j < selectedWord.size(); j++)
		{
			//Set the flag to false
			charMatched = false;
			//See if the character mathes
			if (selectedWord.at(j) == wordFromList.at(i))
			{
				//Keep record that the letter was included
				hasCharacter.push_back(true);
				//Set the flag to true
				charMatched = true;

				//Erase that character from the string
				if (j == selectedWord.size())
				{
					selectedWord.erase(j);
				}
				else
				{
					selectedWord.erase(j, 1);
				}


				//Break out of this loop, no point if we found a match
				break;
			}
		}
	}

	//Compare the size of hasCharacter to the size of wordFromList
	if (hasCharacter.size() == wordFromList.size())
	{
		return 1;
	}
	else
		return 0;
}




int main()
{
	//word vector
	vector <string> words;
	vector <string> subsetOfWord;

	//Open file
	fstream file;
	file.open("words.txt");

	//Read words from file into a vector
	while (file)
	{
		string word;
		getline(file, word);
		words.push_back(word);
	}

	//Close teh file
	file.close();

	//get a random word from the vector
	default_random_engine dre(time(nullptr));// Seed the engine
	uniform_int_distribution<int> di(0,words.size());
	int n = di(dre);// Get a random int


	//State the word that we will be using
	string randomlySelectedWord = words.at(n);
	cout << "Randomly selected word: " + randomlySelectedWord << endl;
	cout << "Please wait while magic happens..." << endl;
	cout << "BRRRRRRRR" << endl;
	cout << "=-=-=-=-=" << endl;



	//Go through the words
	for (unsigned long long i = 0; i < words.size(); i++)
	{
		//See if the characters in the currently inspected word is in the randomlySelectedWord
		if (words.at(i).size() <= randomlySelectedWord.size() && comparison(randomlySelectedWord , words.at(i)))
		{
			//Save subset of word
			subsetOfWord.push_back(words.at(i));
		}
	}


	cout << "Magic Done... Now sorting..." << endl;
	cout << "BRRRRRRRR" << endl;

	//sort the subset of word
	auto subsetSize = subsetOfWord.size();
	sort(subsetOfWord.begin(), subsetOfWord.end());


	cout << endl << endl;
	cout << "Results: " << endl;

	cout << "Randomly selected word: " + randomlySelectedWord << endl;

	for (unsigned long long i = 0; i < subsetOfWord.size(); i++)
	{
		cout << subsetOfWord.at(i) << endl;
	}

	return 1;
}