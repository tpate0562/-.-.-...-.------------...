//
//  main.cpp
//  Project 4P
//
//  Created by Tejas Patel on 2/19/23.
//

#include <iostream>
using namespace std;

const int LOWEST_NUM = 2;
const int HIGHEST_NUM = 9;
const int HAND_SIZE = 5;
const int PAIR = 2;
const int THREE_OF_A_KIND = 3;

void findHands(int hand[]);
bool containsPair(const int hand[]);
bool containsTwoPair(const int hand[]);
bool containsThreeOfaKind(const int hand[]);
bool containsStraight(const int hand[]);
bool containsFullHouse(const int hand[]);
bool containsFourOfaKind(const int hand[]);

int main() {
    int hand[HIGHEST_NUM + 1] = {0};
    int input;
    cout << "Enter " << HAND_SIZE;
    cout << " numeric cards, no face cards. Use 2 - 9." << endl;
    for (int i = 0; i < HAND_SIZE; i++){
        cout << "Card " << i + 1 << ": ";
        cin >> input;
        hand[input - LOWEST_NUM]++;
    }
    findHands(hand);
}






void findHands(int hand[]){
    string outputText;
    outputText = "High card!";
    if (containsPair(hand) == true){
        outputText = "Pair!";
    }
    if (containsTwoPair(hand) == true){
        outputText = "Two Pair!";
    }
    if (containsThreeOfaKind(hand) == true){
        outputText = "Three of a Kind!";
    }
    if (containsStraight(hand) == true){
        outputText = "Straight!";
    }
    if (containsFullHouse(hand) == true){
        outputText = "Full House!";
    }
    if (containsFourOfaKind(hand) == true){
        outputText = "Four of a kind!";
    }
    cout << outputText << endl;
    /*cout << containsPair(hand) << endl;
    cout << containsTwoPair(hand) << endl;
    cout << containsThreeOfaKind(hand) << endl;
    cout << containsStraight(hand) << endl;
    cout << containsFullHouse(hand) << endl;
    cout << containsFourOfaKind(hand) << endl;*/
}






bool containsPair(const int hand[]){
    for(int i = LOWEST_NUM; i <= HIGHEST_NUM; i++){
        if(hand[i] == PAIR){
            return true;
        }
    }
}






bool containsTwoPair(const int hand[]) {
    int numPairs = 0;
    for(int i = LOWEST_NUM; i <= HIGHEST_NUM; i++){
        for(int j = LOWEST_NUM; j <= HIGHEST_NUM; j++){
            if(hand[i] == PAIR && hand[j] == PAIR && i != j){
                numPairs++;
                if(numPairs == 2){
                    return true;
                }
            }
        }
    }
}





bool containsThreeOfaKind(const int hand[]) {
    for(int i = LOWEST_NUM; i <= HIGHEST_NUM; i++){
        if(hand[i] == THREE_OF_A_KIND){
            return true;
        }
    }
}








bool containsStraight(const int hand[]) {
    for (int i = 0; i <= HIGHEST_NUM - LOWEST_NUM - 3; i++) {
        if(hand[i] >= 1 && hand[i + 1] >= 1){
            if(hand[i + 2] >= 1 && hand[i + 3] >= 1){
                if(hand[i + 4] >= 1){
                    return true;
                }
            }
        }
    }

}









bool containsFullHouse(const int hand[]) {
    bool hasThreeOfAKind = false;
    bool hasPair = false;
    bool hasTwoPair = false;

    for (int i = LOWEST_NUM; i <= HIGHEST_NUM; i++) {
        if (hand[i] == THREE_OF_A_KIND) {
            hasThreeOfAKind = true;
        } else if (hand[i] == PAIR) {
            if (hasPair) {
                hasTwoPair = true;
            } else {
                hasPair = true;
            }
        }
    }
}







bool containsFourOfaKind(const int hand[]){
    for(int i = LOWEST_NUM; i <= HIGHEST_NUM; i++){
        if(hand[i] >= 4){
            return true;
        }
    }
}





/*bool containsPair(const int hand[]){
    for(int i = LOWEST_NUM; i <= HIGHEST_NUM; i++){
        if(hand[i] == PAIR){
            return true;
        }
    }
    return false;
}

bool containsTwoPair(const int hand[]) {
    int numPairs = 0;
    for (int i = LOWEST_NUM; i <= HIGHEST_NUM; i++) {
        if (hand[i] == PAIR) {
            numPairs++;
        }
    }
    return numPairs == 2;
}


bool containsThreeOfaKind(const int hand[]) {
    if (containsFourOfaKind(hand)) {
        return false;
    }
    
    for(int i = 0; i < HIGHEST_NUM - LOWEST_NUM + 1 ; i++){
        if(hand[i] == THREE_OF_A_KIND){
            return true;
        }
    }
    return false;
}


bool containsStraight(const int hand[]) {
    for (int i = LOWEST_NUM; i <= HIGHEST_NUM - HAND_SIZE + 1; i++) {
        bool isStraight = true;
        for (int j = i; j < i + HAND_SIZE; j++) {
            if (hand[j] == 0) {
                isStraight = false;
                break;
            }
        }
        if (isStraight) {
            return true;
        }
    }
    return false;
}

bool containsFullHouse(const int hand[]) {
    int numPairs = 0;
    int numThreeOfAKind = 0;
    for(int i = LOWEST_NUM; i <= HIGHEST_NUM; i++){
        if(hand[i] == PAIR){
            numPairs++;
        } else if(hand[i] == THREE_OF_A_KIND){
            numThreeOfAKind++;
        }
    }
    return numPairs == 1 && numThreeOfAKind == 1;
}

bool containsFourOfaKind(const int hand[]){
    for(int i = LOWEST_NUM; i <= HIGHEST_NUM; i++){
        if(hand[i] == 4){
            return true;
        }
    }
    return false;
}
*/
