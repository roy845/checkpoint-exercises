int stringLength(string s) {
    int i = 0;
    int length = 0;

    while (s[i] != '\0') {
        length++;
        i++;
    }
    return length;
}


int absoluteValue(int a) {

    a < 0 ? a =  -1 * a : a;

    return a;
  
}


void swapCharacters(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

string integerToString(int num) {
    string num_str= "";
    string res = "";

    int originalValue = num;
    int number = absoluteValue(num);
 
    for (int i = 0; number > 0; i++) {
        int remainder = number % 10;
        char c = remainder + '0';
        num_str += c;
        number /= 10;
    }
    
    int len = stringLength(num_str);

    int i = len - 1;
    int j = 0;
    while (i > 0 && j < i) {
        swapCharacters(num_str[i], num_str[j]);
        i--;
        j++;
    }

    originalValue < 0 ?  res = '-'+num_str : res = num_str;

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


bool checkIfCanSeat(vector<string> seats, set<string> reservedSeats, int rowNumberSeat) {

    bool canSeat = true;

    for (int i = 0; i < seats.size();i++){
         string finalSeat = "";
        // string rowNumberString = to_string(rowNumber);
         string rowNumberSeatString = integerToString(rowNumberSeat);
         finalSeat += rowNumberSeatString;
         finalSeat += seats[i];

        if (reservedSeats.find(finalSeat) != reservedSeats.end())
            canSeat = false;
    }

    return canSeat;
}


int solution2(int N, string S) {
   
    if (stringLength(S) == 0) {
        return 2 * N;
    }

    char spaceCharacter = ' ';
    set<string> reservedSeatSet;
    int numberOfFamilies = 0;
    
   //B C D E F G H J =>
  // B C D E => L 
 //  D E F G => M
//   F G H J => R
   

    //vector<string> L = {"B","C","D","E"};
    //vector<string> M = {"D","E","F","G"};
    //vector<string> R = {"F","G","H","J"};
   
    vector<vector<string>> seats = {{"B","C","D","E"},
                                    {"D","E","F","G"},
                                    {"F","G","H","J"}};
    
   
    vector<string> reservedSeats = splitSentenceByDelimiter(S,spaceCharacter);

    for (string reservedSeat : reservedSeats)
        reservedSeatSet.insert(reservedSeat);

    N += 1;
    for (int i = 1; i < N ; i++) {

        bool r = true , m = true , l = true;

        l = checkIfCanSeat(seats[0],reservedSeatSet,i);
        m = checkIfCanSeat(seats[1],reservedSeatSet,i);
        r = checkIfCanSeat(seats[2],reservedSeatSet,i);
       

        if ((l == true || r == true)) {
            if (l == true && r == true)
            {numberOfFamilies += 2;}
                
            else if((l == true || r == false) || (l == false || r == true))
            {numberOfFamilies += 1;}

        }else if (m == true) 
        {numberOfFamilies += 1;}
    }
    
    return numberOfFamilies;
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


