#ifndef bison_h
#define bison_h
#include "lexicalAnalyzer.cpp"
#include <bits/stdc++.h>
using namespace std;

class bison
{
public:
    bison(string fileName)
    {
        ifstream sourceCode(fileName);
        string line;
        string buffer;
        LexicalAnalyzer Athena;
        if (!sourceCode)
        {

            cout << "Error in reading Code.us\n";
        }
        int lineNumber = 0;

        do
        {

            stringstream s(line);

            while (s >> buffer)
            {
                if (buffer[0] == '"')
                {
                    string temp;
                    while (buffer[buffer.size() - 1] != '"')
                    {
                        s >> temp;
                        buffer = buffer + ' ' + temp;
                    }
                }
                if (Athena.isKeyword(buffer, lineNumber))
                {
                    if (!(s >> buffer))
                    {
                        cout << "Error at line " << lineNumber << " " << line << endl;
                        continue;
                    }

                    if (buffer[0] == '"')
                    {
                        string temp;
                        while (buffer[buffer.size() - 1] != '"')
                        {
                            s >> temp;
                            buffer = buffer + ' ' + temp;
                        }
                    }

                    if (Athena.isNumber(buffer, lineNumber))
                    {
                        continue;
                    }
                    else if (Athena.isIdentifier(buffer, lineNumber))
                    {
                        continue;
                    }
                    else if (Athena.isTerminator(buffer, lineNumber))
                    {
                        continue;
                    }
                    else if (Athena.isString(buffer, lineNumber))
                    {
                        continue;
                    }
                    else
                    {
                        cout << line << endl;
                        cout << "ERROR at line " << buffer << " Excepted an identifier" << endl;
                    }
                }

                if (Athena.isNumber(buffer, lineNumber))
                {
                   
                    if (!(s >> buffer))
                    {
                        cout << "Error at line " << lineNumber << " " << line << endl;
                    }else
                    if (Athena.isNumber(buffer, lineNumber))
                    {
                        cout << "ERROR at line " << lineNumber << " Excepted an operator" << endl;
                    }
                    else if (Athena.isIdentifier(buffer, lineNumber))
                    {
                        cout << "ERROR at line " << lineNumber << " Excepted an operator" << endl;
                    }
                    if (Athena.isOperator(buffer, lineNumber))
                    {
                        continue;
                    }
                      if (Athena.isTerminator(buffer, lineNumber))
                    {
                        continue;
                    }
                }

                if (Athena.isIdentifier(buffer, lineNumber))
                {
                    if (!(s >> buffer))
                    {
                        cout << "Error at line " << lineNumber << " " << line << endl;
                        continue;
                    }
                    if (Athena.isOperator(buffer, lineNumber))
                    {
                        continue;
                    }
                    else if (Athena.isTerminator(buffer, lineNumber))
                    {
                        continue;
                    }
                    else if (Athena.isNumber(buffer, lineNumber))
                    {
                        cout << "ERROR at line " << lineNumber << " Excepted an operator" << endl;
                    }
                    else if (Athena.isIdentifier(buffer, lineNumber))
                    {
                        cout << "ERROR at line " << lineNumber << " Excepted an operator" << endl;
                    }
                }
            }
            lineNumber++;
        } while (getline(sourceCode, line));
    }
};
#endif