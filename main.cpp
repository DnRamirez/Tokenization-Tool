#include <iostream> 
#include <fstream> 
#include "tokenizer.h"
#include <chrono> 
#include <thread> 


using namespace std; 

Tokenizer t; 
string filename; 
string word2; 
int n; 


void displayLoadingAnimation(const std::string& filename) {
    cout << "Tokenizing \"" << filename << "\"... ";
    for (int i = 0; i < 10; ++i) { // Print 10 asterisks
        cout << "*";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(500)); // Delay for 0.5 seconds
    }
    cout << endl << "Tokenized!" << endl;

}


void options() { 
				cout << "Press Enter to Return to Main Menu";
				cin.ignore(); 
				cin.get();
}



void executeAction(int c) { 
	// variables
	string line; 
	ifstream myFile; 


	// define switch cases for each menu option 
	switch(c) 
	{
		case 1:  
			cin.ignore();  
			cout << endl << "Type Filename then hit 'Enter': "; 
			getline(cin, filename); 
			myFile.open(filename); 
			if (myFile.is_open()) { 
				while (getline(myFile,line)) {	
					t.tokenizeLine(line);		
				}
				myFile.close(); 
			} else { 
				cout << "Unable to open file"; 
			} 
			 displayLoadingAnimation(filename);
			 options();
			break; 
		case 2: 
			if (t.tokens.size() == 0) { 
				cout << "No tokens to count" << endl; 
				break; 
			} else { 
				t.printNumberOfTokens(); 
				options();
				break; 
			}
			break; 
		case 3: 
			cout << "Option 3 has been chosen" << endl; 
			t.printFrequencyAnalysis();
			options();
			break; 
		case 4: 
			cout << "Enter specific word to analyze: "; 
			cin >> word2; 
			t.printFrequencyAnalysis(word2);
			options();
			break; 
		case 5: 
			cout << "What word would you like to analyze? "; 
			cin >> word2;
			cout << "What n-gram would you like to analyze? ";
			cin >> n;
			t.printTopN(word2, n);
			options();			
			break;
		case 6:
			cout << "Option 6 has been chosen" << endl; 
			break;
		case 7:
			cout << "Option 7 has been chosen" << endl;
			t.removeStopWords(); 
			break;
		case 8:
			cout << "Quitting Program..." << endl; 
			break;
		default: 
			cout << "Invalid option" << endl; 
			break;
	} 


}

int main() {



	int c = 1; // dummy value 


	do { 
		cout << "\nTokenizer and Text Analysis Tool\n"; 
		if (filename != "") { 
			cout << "Current File: " << filename << endl; 
		} else { 
			cout << "Current File: None" << endl; 
		}
		cout << "Menu Options: \n";
		cout << "\t 1: Tokenize Data from Raw File\n"; 
		cout << "\t 2: Count Tokens\n"; 
		cout << "\t 3: Frequency Analysis\n";
		cout << "\t 4: Frequency Analysis - Specific Word \n"; 
		cout << "\t 5: N-gram Analysis \n"; 
		//Notes: 
		//n gram should return number of occurences of that bigram, or trigram, etc. For example
		//'shall be' (bigram) how many times does this appear? 20 times? 60 times? 100000 times? 
		cout << "\t 6: Keyword Extraction \n"; 
		cout << "\t 7: Stop Word Removal \n";
		cout << "\t 8: Quit\n"; 
		cout << "Please enter your selection (1-8): "; 
		cin >> c;
		executeAction(c); 
	} while (c != 8); 

return 0; 

} 



 
