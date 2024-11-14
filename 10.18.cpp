#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define FACES 13
#define SUITS 4

struct card {
    const char *face;
    const char *suit;
};

void fillDeck(struct card *deck, const char *faces[], const char *suits[]) {
    for (int i = 0; i < CARDS; ++i) {
        deck[i].face = faces[i % FACES];
        deck[i].suit = suits[i / FACES];
    }
}

void fisherYatesShuffle(struct card *deck) {
    for (int i = CARDS - 1; i > 0; --i) {
        int j = rand() % (i + 1); // Random index from 0 to i
        struct card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void printDeck(const struct card *deck) {
    for (int i = 0; i < CARDS; ++i) {
        printf("%s of %s\n", deck[i].face, deck[i].suit);
    }
}

int main() {
    struct card deck[CARDS];
    const char *faces[] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", 
                           "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    srand(time(NULL)); // Seed random-number generator
    fillDeck(deck, faces, suits);
    
    printf("Original deck:\n");
    printDeck(deck);

    fisherYatesShuffle(deck);

    printf("\nShuffled deck:\n");
    printDeck(deck);

    return 0;
}
