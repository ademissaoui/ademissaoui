#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int romanValue(char c)
    {
        switch (c)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return -1;
        }
    }
    int romanToInt(string s)
    {
        int total = 0;

        for (int i = 0; i < s.length(); i++)
        {
            int current = romanValue(s[i]);
            if (current == -1)
            {
                cout << "Erreur : caractere romain invalide !" << endl;
                return -1;
            }

            int next = 0;
            if (i + 1 < s.length())
            {
                next = romanValue(s[i + 1]);

                if (next == -1)
                {
                    cout << "Erreur : caractere romain invalide !" << endl;
                    return -1;
                }
            }
            if (current < next)
                total -= current;
            else
                total += current;
        }

        return total;
    }
};
int main()
{
    Solution sol;

    string s = "MCMXCIVV";
    int result = sol.romanToInt(s);

    if (result != -1)
        cout << "Valeur entiere = " << result << endl;

    return 0;
}
