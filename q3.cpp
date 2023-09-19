int stringLength(string s) {
    int i = 0;
    int length = 0;

    while (s[i] != '\0') {
        length++;
        i++;
    }
    return length;
}


int stringToInteger(string s) {
    int num=0;
    int len = stringLength(s);
    bool negative=false;
    int res=0;
    int j = 0;

    if (s[0] == '-') {
        negative = true;
        j++;  
    }
    else {
        negative = false;
        j=0;
    }

    for (int i = j; i < len; i++) {
        
        int digit = s[i] - '0';
        num += digit;
        num *= 10;
    }
    num /= 10;

    negative ? res = -num : res =  num;

    return res;

}


vector<string> splitSentenceByDelimiter(string stringToSplit,char delimiter) {
    
    string currentWord = "";
    vector<string>strings={};
    int len = stringLength(stringToSplit);

    for (int i = 0; i < len; i++) {
      
        if (stringToSplit.at(i) != delimiter) {
            char currentCharacter = stringToSplit.at(i);
            currentWord += currentCharacter;
        }
        else {
            strings.push_back(currentWord);
            currentWord = "";
        }
    }

    strings.push_back(currentWord);

    return strings;
}



string toLowerCase(string s) {
    string lowerCaseString="";
    int len = stringLength(s);

    for (int i = 0; i < len; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            lowerCaseString += s[i] + 32;
        }
        else if (s[i] >= 'a' && s[i] <= 'z') {
            lowerCaseString += s[i];
        }
    }

    return lowerCaseString;
}



int solution3(string S, string C) {

    if (S.length() == 0) {
        cout << "Empty string ! please enter non empty string.";
        return 0;
    }
      
    int maximumValue = INT_MIN;
    int columnNumber = -1;
    char newLineCharacter = '\n';
    char commaCharacter = ',';

    vector<string> allRows = splitSentenceByDelimiter(S,newLineCharacter);
    vector<string> ColumnNames = splitSentenceByDelimiter(allRows[0],commaCharacter);

    for (int i = 0; i < ColumnNames.size(); i++) {

        C = toLowerCase(C);
        ColumnNames[i] = toLowerCase(ColumnNames[i]);
        
        if (ColumnNames[i] == C)
            columnNumber = i;
    }

    if (columnNumber == -1){
        cout << "Invalid Column ! please enter valid column.";
        return 0;
    }
     

    //vector<string> firstRowValues = splitSentenceByDelimiter(allRows[1],commaCharacter);
    //maximumValue = stoi(firstRowValues[columnNumber]);

    for (int i = 1; i < allRows.size(); i++) {
        vector<string> rowValues = splitSentenceByDelimiter(allRows[i],commaCharacter);
        int rowValue = stringToInteger(rowValues[columnNumber]);
        if (rowValue > maximumValue)
            maximumValue = rowValue;
    }

    return maximumValue;
}
