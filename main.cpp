#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility> 

using namespace std;

map<pair<string, string>, float> bigram_counts;
map<string, float> unigram_counts;

void calc_bigrams(const string&);
void lookup_bigram(const string&, const string&);
void process(string&);

int main(int argc, char* argv[]) {
	
	
	if (argc != 2) {
		cout << "Usage: ./calc_bigrams <FILENAME>\n";
		return 0;
	}

	calc_bigrams(argv[1]);

	vector<pair<string, string>> words = {
		{ "with", "me" },
		{ "the", "grass" },
		{ "the", "king" },
		{ "to", "you" }
	};

	for (auto p : words) {
		lookup_bigram(p.first, p.second);
	}
}

// Given filename fn, read in the file word by word
// for each word:
// 1. process(word)
// 2. increment count of that word in unigram_counts
// 3. increment count of (prevword, word) in bigram_counts
void calc_bigrams(const string& fn) {


	     	std::ifstream file;
		    file.open(fn);
			std::string words;
	     	std::string prevwords;
	     	
	     	
	    	while(file >> words){
	     	
            process(words);
            
            unigram_counts[words]++; // increment it.
			bigram_counts[make_pair(prevwords, words)]++ ;  
			prevwords == words;
}
file.close();
}

// Given words w1 and w2,
// 0. process the words 
// 1. print the words
// 2. if bigram (w1, w2) is not found, print "Bigram not found"
// 3. print how many times w1 appears
// 4. print how many times (w1, w2) appears
// 5. print count(w1, w2)/count(w1)
// (see example output)

void lookup_bigram(const string& w1, const string& w2) {
float count;
float county; 

string m1 = w1;
string m2 = w2 ;
map<pair<string, string>, float> ::iterator it1;

	process(m1);
    process(m2);
    

   //pair <string, string> ss_pair;
   //ss_pair = std::make_pair(m1, m2);
   //m1 = ss_pair.first;
   //m2 = ss_pair.second;
   
   	
   std:: cout << m1 << ", " <<m2  << " : " << std ::endl ;
	

if(bigram_counts.find(make_pair(m1, m2)) == bigram_counts.end())
std :: cout << "Bigram not found" ;
	

	cout << m1 << " " <<  "appears " << " " << unigram_counts[m1]<< " times"  << std ::endl;
	
	it1 = bigram_counts.begin();
    
    
    while(it1 != bigram_counts.end()){
    	county = it1->second ;
    	count = (it1->second) /unigram_counts[it1->first.first];
    	it1 ++ ;
	}   
	
//	count = (bigram_counts[make_pair(m1,m2)])/unigram_counts[m1]; 
	
	
	cout << m1 <<"," << m2 << " appears " << county<< " times"  << std ::endl;
	cout << count << endl;

return;

}


void process(string& str) {
	for (int i = 0; i < str.length(); ++i) {
		if(isalpha(str[i])) {
			str[i] = tolower(str[i]);
		}
		else {
			str[i] = '*';
		}
	}
	str.erase(remove(str.begin(), str.end(), '*'), str.end());
}
