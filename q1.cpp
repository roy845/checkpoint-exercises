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


int solution1(vector<int> A,vector<string> D) {

    int noOfMonthsToPay = 12;
    int balanceInAccountAfterYear = 0;
    vector<int> monthlyPayments(12,0);
    vector<int> noOfWithdrawsPerMonth(12,0);
   

    for (int i = 0; i < A.size(); i++) {

        balanceInAccountAfterYear += A[i];

        if (A[i] < 0) {
            string month = "";
            month += D[i].at(5);
            month += D[i].at(6);

            int monthInt = stringToInteger(month);
           
            monthlyPayments[monthInt - 1] += absoluteValue(A[i]);
            noOfWithdrawsPerMonth[monthInt - 1]++;
        }
    }

    for (int i = 0; i < 12; i++) {
        if (noOfWithdrawsPerMonth[i] >= 3 && monthlyPayments[i] >= 100)
            noOfMonthsToPay--;
    }

    balanceInAccountAfterYear = balanceInAccountAfterYear - noOfMonthsToPay * 5;

    return balanceInAccountAfterYear;
}





