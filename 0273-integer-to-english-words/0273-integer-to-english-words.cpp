class Solution {
public:
        vector<string> belowTen = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> belowTwenty = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> belowHundred = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string numberToWords(int num)
    {
        // If the number is zero then simply return "Zero"
        if (num == 0)
        {
            return "Zero";
        }

        // Single digit case
        if (num < 10)
        {
            return belowTen[num];
        }
        // Below 20 case
        if (num < 20)
        {
            // for 10 it is present at index 0, so subtract the number by 10
            return belowTwenty[num - 10];
        }
        // Below 100 case
        if (num < 100) // 74, 70
        {
            return belowHundred[num / 10] + (num % 10 != 0 ? " " + belowTen[num % 10] : "");
        }
        // Below 1000 case
        if (num < 1000) // 900
        {
            return belowTen[num / 100] + " Hundred" + (num % 100 != 0 ? " " + numberToWords(num % 100) : "");
        }
        // Below 1 Million Case
        if (num < 1000000)
        { // 9000, 999000
            return numberToWords(num / 1000) + " Thousand" + (num % 1000 != 0 ? " " + numberToWords(num % 1000) : "");
        }
        // Below Billion Case
        if (num < 1000000000)
        { // 999 129786
            return numberToWords(num / 1000000) + " Million" + (num % 1000000 != 0 ? " " + numberToWords(num % 1000000) : "");
        }

        // Case for Billion
        return numberToWords(num / 1000000000) + " Billion" + (num % 1000000000 != 0 ? " " + numberToWords(num % 1000000000) : "");
    }
};