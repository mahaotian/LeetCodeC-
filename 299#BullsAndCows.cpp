#include <iostream>
#include <map>
#include <stdio.h>
#include <string>
using namespace std;

class Solution {
  public:
    string getHint(string secret, string guess) {
        int bull = 0, cow = 0;
        map<char, int> cowSecret;
        map<char, int> cowGuess;
        for (int i = 0; i < secret.size() && i < guess.size(); i++) {
            if (secret[i] == guess[i]) {
                bull++;
                continue;
            }
            if (cowSecret.find(secret[i]) == cowSecret.end())
                cowSecret[secret[i]] = 1;
            else
                cowSecret[secret[i]]++;
            if (cowGuess.find(guess[i]) == cowGuess.end())
                cowGuess[guess[i]] = 1;
            else
                cowGuess[guess[i]]++;
        }
        for (map<char, int>::iterator secretIt = cowSecret.begin();
             secretIt != cowSecret.end(); secretIt++) {
            for (map<char, int>::iterator guessIt = cowGuess.begin();
                 guessIt != cowGuess.end(); guessIt++) {
                if (secretIt->first == guessIt->first)
                    cow +=
                        (secretIt->second < guessIt->second ? secretIt->second
                                                            : guessIt->second);
            }
        }
        char res[10];
        sprintf(res, "%dA%dB", bull, cow);
        return string(res);
    }
};

int main() {
    string secretNumber1 = "1807";
    string guessNumber1 = "7810";
    string secretNumber2 = "1123";
    string guessNumber2 = "0111";
    Solution solution;
    string hint1 = solution.getHint(secretNumber1, guessNumber1);
    string hint2 = solution.getHint(secretNumber2, guessNumber2);
    cout << hint1 << endl;
    cout << hint2 << endl;
    return 0;
}
