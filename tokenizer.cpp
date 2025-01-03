//Tokenizer and Text Analysis Tool 
#include <iostream>
#include <string>
#include <fstream> 
#include "tokenizer.h"
#include <sstream>
#include <map> 
#include <queue>
using namespace std; 

void Tokenizer::tokenizeLine(string line) {  
    //what do we need to pass in function? 
    //answer: we need to pass in the line that we want to tokenize
    //tokenize the line and store it in a vector
    //logic to tokenize the line
    //we need to create a vector of strings
    //we need to create a string variable to store the token
    //we need to create a for loop to iterate through the line
    stringstream check1(line); 
    string intermediate;
    while(getline(check1, intermediate, ' ')) { 
        //only using space as a delimiter, this does not take into account punctuation
        tokens.push_back(intermediate); 
    }


};



//definition for destructor 
Tokenizer::~Tokenizer() { 
}

void Tokenizer::printNumberOfTokens(){
    cout << "##############################################" << endl;
    cout << endl; 
    cout << "Number of tokens: " << tokens.size() << endl;
    cout << endl; 
    cout << "##############################################" << endl;
}

void Tokenizer::printFrequencyAnalysis(string word) { 
    //we need to iterate through the vector and count the number of times the word appears 
    int count = 0; 
    for (int i = 0; i < tokens.size(); i++) { 
        if (tokens[i] == word) { 
            count++; 
        }
    }
    cout << "##############################################" << endl;
    cout << endl; 
    cout << "Frequency Analysis for \"" << word << "\":" << endl; 
    cout << endl; 
    cout << "Number of times " << word << " appears: " << count << endl; 
    cout << endl; 
    cout << "##############################################" << endl;    
}


void Tokenizer::printFrequencyAnalysis() { 
    map<string, int> frequency;
    for (int i = 0; i < tokens.size(); i++) { 
        frequency[tokens[i]]++;
    }

    using FreqPair = pair<string, int>;
    auto comp = [](const FreqPair &a, const FreqPair &b) {
        return a.second < b.second;
    };

    priority_queue<FreqPair, vector<FreqPair>, decltype(comp)> pq(comp);

    for (const auto &pair : frequency) {
        pq.push(FreqPair(pair.first, pair.second));
    }

    for (int i = 0; i < 10 && !pq.empty(); ++i) {
        cout << pq.top().first << ": " << pq.top().second << '\n';
        pq.pop();
    }
}

void Tokenizer::removeStopWords() { 
    //this implementation takes very long to execute, need to find a quicker way
    
    vector<string> stopWords = {"a", "an", "and", "are", "as", "at", "be", "by", "for", "from", "has", "he", "in", "is", "it", "its", "of", "on", "that", "the", "to", "was", "were", "will", "with"};
string stopWord; 
for (int i = 0; i < stopWords.size(); i++) { 
    stopWord = stopWords[i]; 
    for (int j = 0; j < tokens.size(); j++) { 
        if (tokens[j] == stopWord) { 
            tokens.erase(tokens.begin() + j);
        }
    }
}
cout << "##############################################" << endl;
cout << endl; 
cout << "Stop Words Removed" << endl; 
cout << endl; 
cout << "##############################################" << endl;
}

void Tokenizer::printTopN(string word, int n) { 
    int halfN = n / 2;
    for (int i = 0; i < tokens.size(); i++) { 
        if (tokens[i] == word) { 
            // Print halfN words before the word
            for (int j = max(0, i - halfN); j < i; j++) { 
                cout << tokens[j] << " ";
            }
            // Print the word
            cout << tokens[i] << " ";
            // Print halfN words after the word
            for (int j = i + 1; j <= min(i + halfN, (int)tokens.size() - 1); j++) { 
                cout << tokens[j] << " ";
            }
            cout << endl; 
        }
    }
}





