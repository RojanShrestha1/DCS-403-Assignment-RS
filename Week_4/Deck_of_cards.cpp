#include <iostream>
using namespace std;

using std::cout;
using std::endl;
void printDeck(string deck[], int size) {
    for (int i = 0; i < size; i++) {
        cout << deck[i] << " ";
    }
    cout << endl;
}

int main() {
    string deck[52] = {
        "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "10H", "JH", "QH", "KH", "AH",
        "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "10D", "JD", "QD", "KD", "AD",
        "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "10C", "JC", "QC", "KC", "AC",
        "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "10S", "JS", "QS", "KS", "AS"
    };

    cout << "Original Deck:" << endl;
    printDeck(deck, 52);

    // Simple Shuffle Logic (Fisher-Yates Shuffle)
    for (int i = 51; i > 0; i--) {
        int j = rand() % (i + 1); // Random index from 0 to i
        // Swap deck[i] with the element at random index
        string temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }

    cout << "\nShuffled Deck:" << endl;
    printDeck(deck, 52);

    return 0;
}