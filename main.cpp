#include <iostream>
#include <fstream>
#include <string>
#include <list>

//#define cout std::cout //lol
//#define endl std::endl

using std::cout;
using std::endl;
using std::cin;

int main() {
    std::ifstream file ("WordList.txt");
    std::list<std::string> WordList; //Wordlist size will be 14854 roughly
    std::string Word;
    while (file >> Word) { //idk how this works but it works!
        WordList.push_back(Word);
    }
    file.close();

    std::string Letters;
    cout << "Enter letters below:" << endl;
    cin >> Letters;

    std::list<std::string> NewList {WordList};
    for (char Letter:Letters) {
        for (std::string Word:WordList) {
            if (Word.find(Letter) == std::string::npos) { //letter not found
                NewList.remove(Word);
            }
        }
    }
    WordList = NewList;
    //Output
    std::ofstream Outputfile ("Output.txt");
    for (std::string Word:WordList) {
        Word+="\n";
        Outputfile << Word;
    }
    
    return 0;
}