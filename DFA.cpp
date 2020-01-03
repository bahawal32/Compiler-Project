#include <bits/stdc++.h>
#include "lexicalAnalyzer.cpp"
using namespace std;

int main()
{
    
    string fileName = "code.us";
    
    //cin >> fileName;
    
    LexicalAnalyzer Athena;

    Athena.Tokenization(fileName);

    return 0;
}