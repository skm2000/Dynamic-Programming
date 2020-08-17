#include<bits/stdc++.h>
using namespace std;

// problem : https://www.lintcode.com/problem/flip-game-ii/
// very good question

class Solution {
public:
    bool canWin(string &s) {
        // write your code here
        if(s.length()<2) return false;
        return flipGame(s);
    }
    
    bool flipGame(string &s){
        for(int i=0;i<s.length()-1;i++){
            if(s[i]=='+' && s[i+1]=='+'){
                // find the next state of the string and see if the other player can win
                // with the next state
                string nextState = s.substr(0,i)+"--"+s.substr(i+2);
                // if the player can't win with the next state, i will win the flipGame
                // and hence return true
                if(!flipGame(nextState)){
                    return true;
                }
            }
        }
        return false;
    }
};