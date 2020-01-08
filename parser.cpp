#include <iostream>
#include "lexicalAnalyzer.cpp"
using namespace std;
LexicalAnalyzer Athena;
stringstream s;
void identifier(string buffer, int lineNumber);
void op(string buffer, int lineNumber);
void terminator(string buffer, int lineNumber);
void keyword(string buffer, int lineNumber);
void str(string buffer, int lineNumber);
void number(string buffer, int lineNumber);
int main()
{

    int lineNumber = 0;
    string fileName = "code.us";
    string line;
    ifstream file(fileName);
    if (!file)
    {
        cout << "Error is opening " << fileName << endl;
    }
    do
    {
        lineNumber++;
        s = stringstream(line);
        string buffer;
        s >> buffer;
        if (buffer[0] == '"')
        {
            string temp;
            while (buffer[buffer.size() - 1] != '"')
            {
                s >> temp;
                buffer = buffer + ' ' + temp;
            }
        }
        else if (Athena.isKeyword(buffer, lineNumber))
        {
            keyword(buffer, lineNumber);
        }
        else if (Athena.isIdentifier(buffer, lineNumber))
        {
            identifier(buffer, lineNumber);
        }
        else
        {
            cout << "Error at line " << lineNumber << endl;
            cout << buffer << endl;
        }

    } while (getline(file, line));
}
void keyword(string buffer, int lineNumber)
{
    s >> buffer;
    if (buffer[0] == '"')
    {
        string temp;
        while (buffer[buffer.size() - 1] != '"')
        {
            s >> temp;
            buffer = buffer + ' ' + temp;
        }
    }
    if (Athena.isString(buffer, lineNumber))
    {
        str(buffer, lineNumber);
    }
    else if (Athena.isNumber(buffer, lineNumber))
    {
        number(buffer, lineNumber);
    }
    else if (Athena.isIdentifier(buffer, lineNumber))
    {
        identifier(buffer, lineNumber);
    }
    else if (Athena.isTerminator(buffer, lineNumber)){
        terminator(buffer, lineNumber);
    } else 
    {
        cout << "Error at line " << lineNumber << endl;
        cout << buffer << endl;
    } 
}
void str(string buffer, int lineNumber)
{
    s >> buffer;
    if (buffer[0] == '"')
    {
        string temp;
        while (buffer[buffer.size() - 1] != '"')
        {
            s >> temp;
            buffer = buffer + ' ' + temp;
        }
    }
    if (Athena.isOperator(buffer, lineNumber))
    {
        op(buffer, lineNumber);
    }
    else if (Athena.isTerminator(buffer, lineNumber))
    {
        terminator(buffer, lineNumber);
    }
    else
    {
        cout << "Error at line " << lineNumber << endl;
        cout << buffer << endl;
    }
}
void number(string buffer, int lineNumber)
{
    s >> buffer;
    if (buffer[0] == '"')
    {
        string temp;
        while (buffer[buffer.size() - 1] != '"')
        {
            s >> temp;
            buffer = buffer + ' ' + temp;
        }
    }
    if (Athena.isOperator(buffer, lineNumber))
    {
        op(buffer, lineNumber);
    }
    else if (Athena.isTerminator(buffer, lineNumber))
    {
        terminator(buffer, lineNumber);
    }
    else
    {
        cout << "Error at line " << lineNumber << endl;
        cout << buffer << endl;
    }
}
void identifier(string buffer, int lineNumber)
{
    s >> buffer;
    if (buffer[0] == '"')
    {
        string temp;
        while (buffer[buffer.size() - 1] != '"')
        {
            s >> temp;
            buffer = buffer + ' ' + temp;
        }
    }
    if (Athena.isOperator(buffer, lineNumber))
    {
        op(buffer, lineNumber);
    }
    else if (Athena.isTerminator(buffer, lineNumber))
    {
        terminator(buffer, lineNumber);
    }
    else
    {
        cout << "Error at line " << lineNumber << endl;
        cout << buffer << endl;
    }
}
void op(string buffer, int lineNumber)
{
    s >> buffer;
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
        number(buffer, lineNumber);
    }
    else if (Athena.isString(buffer, lineNumber))
    {
        str(buffer, lineNumber);
    }
    else if (Athena.isIdentifier(buffer, lineNumber))
    {
        identifier(buffer, lineNumber);
    }
    else
    {
        cout << "Error at line " << lineNumber << endl;
        cout << buffer << endl;
    }
}
void terminator(string buffer, int lineNumber)
{
        cout << "Syntax ACCEPTED at line " << lineNumber << " " << endl;
}
