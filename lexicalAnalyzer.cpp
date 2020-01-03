#include <bits/stdc++.h>
using namespace std;
class LexicalAnalyzer{
public:
    LexicalAnalyzer()
    {

    }

    bool isKeyword(string buffer, int lineNumber)
    {
        if (buffer == "bolo" | buffer == "pocho" | buffer == "dobara" | buffer == "agar" | buffer == "warna" | buffer == "ruko" | buffer == "khatam" | buffer == "kam")
        {

            
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
        
        return true;
    }
    bool isString(string buffer, int lineNumber)
    {

        bool first = false;
        int stringStart, stringEnd,i=0;

        for ( i = 0; i < buffer.length(); i++)
        {

            if (buffer[i] == '"' )
            {
                stringStart = i;
                break;
            }
        }
        for (int j = i; j < buffer.length(); j++)
        {

            if (buffer[j] == '"' )
            {
                stringStart =j;
                true;
                break;
            }
        }
           
        
        return false;
    }
    bool isOperator(string buffer, int lineNumber)
    {
        if (buffer == "+" | buffer == "-" | buffer == "/" | buffer == "*" | buffer == "%" || buffer == "=" || buffer == "==" || buffer == "<" || buffer == ">" || buffer == "=<" || buffer == "=>" || buffer == "!=")
        {

            
            return true;
        }
        return false;
    }
    bool isTerminator(string buffer, int lineNumber){
        for (int i = 0; i < buffer.length(); i++)
            {
               if (buffer[i]==':')
               return true;
            } 
            return false;
    }
    bool isIdentifier(string buffer, int lineNumber)
    {
        if (buffer[0] >= 'a' && buffer[0] <= 'z' || (buffer[0] >= 'A' && buffer[0] <= 'Z'))
        {
            for (int i = 0; i < buffer.length(); i++)
            {
                if (isOperator(buffer, lineNumber))
                    return false;
                if (buffer[i] == '#' || buffer[i] == '@' || buffer[i] == '!' || buffer[i] == '^' || buffer[i] == '&' || buffer[i] == '$')
                    return false;
            }
            
            return true;
        }
        return false;
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
                    cout << buffer << " is a keyword " << endl;
                }
                else if (isNumber(buffer, lineNumber))
                {
                    cout << buffer << " is a number " << endl;
                }
                else

                    if (isOperator(buffer, lineNumber))
                {
                    cout << buffer << " is a Operator " << endl;
                }
                else

                    if (isIdentifier(buffer, lineNumber))
                {
                    cout << buffer << " is an identifier" << endl;
                }
                else
                    if (isTerminator(buffer, lineNumber)){
                   
                    cout << buffer << " is a Terminator" << endl;

                    }
                
                else if (isString(buffer, lineNumber)){
                    
                    cout << buffer << " is a String" << endl;

                }
                else
                {
                    cout << "Invalid syantax at line " << lineNumber << " " << buffer << " is not defined" << endl;
                }

                lineNumber++;
            }

        } while (getline(sourceCode, line));
    }
};