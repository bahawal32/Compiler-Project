#ifndef bison_h
#define bison_h
#include "lexicalAnalyzer.cpp"
#include<bits/stdc++.h>
using namespace std;

class bison{
    public:
    bison(string fileName){
        ifstream sourceCode(fileName);
        string line;
        string buffer;
        LexicalAnalyzer Athena;
        if (!sourceCode)
        {

            cout << "Error in reading Code.us\n";
        }
        int lineNumber = 1;

        do
        {

            stringstream s(line);

            while (s >> buffer)
            {

                if (Athena.isKeyword(buffer, lineNumber))
                {
                    s >> buffer;
                    if(! (Athena.isNumber(buffer, lineNumber)||Athena.isIdentifier(buffer, lineNumber)||Athena.isTerminator(buffer,lineNumber)))
                    {
                        cout<<"ERROR at line "<<lineNumber<<" Excepted an identifier"<<endl;
                        cout<<buffer<<endl;
                    }
                }
              if(Athena.isNumber(buffer, lineNumber)){
                   s >> buffer;
                    if(Athena.isNumber(buffer, lineNumber))
                    {
                        cout<<"ERROR at line "<<lineNumber<<" Excepted an operator"<<endl;
                    }
                }
              }
                
            
            lineNumber++;
        }while (getline(sourceCode, line));
    }
   
    

};
#endif