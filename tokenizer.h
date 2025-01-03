#include <string> 
#include <fstream>
#include <vector>
using namespace std;
class Tokenizer { 
    public: 
    string filename;
    string line;
    ifstream myFile;
    vector <string> tokens; 
    int myTokens;
    void tokenizeLine(string line); 
     ~Tokenizer(); 
     void printNumberOfTokens(); 
     void printFrequencyAnalysis(); 
     void printFrequencyAnalysis(string word); 
     void removeStopWords(); 
     void printTopN(string word, int n);
     //additional function will go here
     

}; 
