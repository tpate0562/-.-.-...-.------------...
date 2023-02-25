//
//  main.cpp
//  Project 4P
//
//  Created by Tejas Patel on 2/13/23.
//
//Collects input of integers 2-9 with the quantity HAND_SIZE from the user.
//Doesn't matter how large HAND_SIZE is it works with any quantity because
//the cards are binned upon input. Then the findHands() function is called
//where it calls all the hand checking functions in order of importance
//making sure all the hands are checked and only the most important one is
//printed onto the console.

#include <iostream>
using namespace std;

const int LOWEST_NUM = 1;
const int HIGHEST_NUM = 13;
const int HAND_SIZE = 8;
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
    cout << " numeric cards, no face cards. Use 1 - 13." << endl;
    for (int i = 0; i < HAND_SIZE; i++){
        cout << "Card " << i + 1 << ": ";
        cin >> input;
        hand[input]++;
    }
    findHands(hand);
}


/* This function calls all the hand checking functions to find matches
If there is a match found, the function returns true the the outputText
is updated. This happens in order from lowest importance to highest importance
so four of a kind is checked last as it is of highest value
*/
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
    /*cout << "Pair has returned " << containsPair(hand) << endl;
    cout << "Two Pair has returned " << containsTwoPair(hand) << endl;
    cout << "Three of a Kind has returned " << containsThreeOfaKind(hand) << endl;
    cout << "Full House has returned " << containsFullHouse(hand) << endl; //THESE SIX LINES ARE FOR DEBUGGING
    cout << "Four of a kind has returned " << containsFourOfaKind(hand) << endl;//IF FUNCTIONS RETURN TRUE OR NOT,
    cout << "Straight has returned " << containsStraight(hand) << endl; //THEY RETURN 1 OR 0*/
}




/*Since quantities and not vlaues are stored in hand[], we can check to see if
any values in hand[] are equal to two and if so, return true. Very simple*/
bool containsPair(const int hand[]){
    if(containsTwoPair(hand) == true){
        return true;
    }
    for(int i = LOWEST_NUM; i <= HIGHEST_NUM; i++){
        if(hand[i] == PAIR){
            return true;
        }
    }

    return false;
}




/*Checks to see if there are two values in hand[] that are equal to two and that
those values are not the same index value. If so, returns true else false*/
bool containsTwoPair(const int hand[]){
    
    for(int i = LOWEST_NUM; i <= HIGHEST_NUM; i++){
        for(int j = LOWEST_NUM; j <= HIGHEST_NUM; j++){
            if(hand[i] == PAIR){
                if(hand[j] == PAIR && i != j){
                    return true;
                }
            }
        }
    }

    return false;
    
}




/*Almost the exact same algorithm as containsPair(). Checks to see if any
numbers in hand[] is equal to three, and if so returns true else false*/
bool containsThreeOfaKind(const int hand[]){
    /*takes measures against false positives for redundancy
    next three lines typically not necessary but added for insurance*/
    if(containsFourOfaKind(hand) == true){
        return false;
    }
    
    for(int i = LOWEST_NUM; i <= HIGHEST_NUM; i++){
        if(hand[i] == THREE_OF_A_KIND){
            return true;
        }
    }

    return false;
    
}



/*Checks to see if all values 5 in a row above the value i are 1 or more
If so, then it returns true. The measures against 7 8 9 10 11 coming
back as straight are in memory allocation as hand[] only goes to 9*/
bool containsStraight(const int hand[]){
    
    for (int i = LOWEST_NUM; i <= HIGHEST_NUM; i++){
        if(hand[i] >= 1 && hand[i + 1] >= 1 && hand[i + 2] >= 1){
            if (hand[i + 3] >= 1 && hand[i + 4] >= 1){
                return true;
            }
        }
    }
    return false;
}




/*Full house code is comparable to the containsTwoPair() func
the nested loops check for a pair and a three of a kind, and
if both are found, then the program returns true. The
preventative measure against double dipping is that
a pair can't also be a three of a kind, so no need to check
that i and j are different*/
bool containsFullHouse(const int hand[]){
    for(int i = LOWEST_NUM; i <= HIGHEST_NUM; i++){
        for(int j = LOWEST_NUM; j <= HIGHEST_NUM; j++){
            if(hand[i] == PAIR && hand[j] == THREE_OF_A_KIND){
                return true;
            }
        }
    }
    return false;
}




/*Exactly like containsPair() and containsThreeOfaKind()
Checks to see if there are 4 or more in the quantities
if so, returns true else false */
bool containsFourOfaKind(const int hand[]){
    
    for(int i = LOWEST_NUM; i <= HIGHEST_NUM; i++){
        if(hand[i] > THREE_OF_A_KIND){
            return true;
        }
    }

    return false;
}
