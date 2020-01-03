#include <bits/stdc++.h>
using namespace std;
bool isKeyword(string buffer, int lineNumber)
{
    if (buffer == "bolo" | buffer == "pocho" | buffer == "dobara" | buffer == "agar" | buffer == "warna" | buffer == "ruko" | buffer == "khatam" | buffer == "kam")
    {

        cout << buffer << " is a keyword " << endl;
        return true;
    }
    return false;
}
bool isNumber(string buffer, int lineNumber)
{
  
    for (int i = 0; i < buffer.length(); i++)
    {
        if (buffer[i] >= '0' && buffer[i] <= '9')
            continue;
        else
            return false;
    }
    cout<<buffer<<" is a number "<< endl;
    return true;
}
bool isString(string buffer, int lineNumber)
{

    bool first = false;
    int stringStart, stringEnd;
    for (int i = 0; i < buffer.length(); i++)
    {

        if (buffer[i] == '"' && first == false)
        {

            first = true;
            stringStart = i+1;
        }
        else if (buffer[i] == '"' && first == true)
        {
            stringEnd = i-1;
        }
        cout << buffer.substr(stringStart, stringEnd) << " is a string \n";
        return true;
    }
    return false;
}
bool isOperator(string buffer, int lineNumber)
{
    if (buffer == "+" | buffer == "-" | buffer == "/" | buffer == "*" | buffer == "%")
    {

        cout << buffer << " is a Operator " << endl;
        return true;
    }
    return false;
}
bool isIdentifier(string buffer, int lineNumber){
    
}
void Tokenization(string fileName)
{
    ifstream sourceCode(fileName);
    string line;
    string buffer;
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
            
            if (isKeyword(buffer, lineNumber))
            {
            }
            if (isNumber(buffer, lineNumber))
            {
            }
         
            if (isOperator(buffer, lineNumber))
            {
            }

            lineNumber++;
        }

    } while (getline(sourceCode, line));
}
int main()
{
    string fileName = "code.us";
    //cin >> fileName;
    Tokenization(fileName);

    return 0;
}