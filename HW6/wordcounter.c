/*

print out the DISTINCT words sorted into increasing order of frequency of 
occurrence. Precede each word by its count. 
Do this by creating a struct that holds the word as a string, and the frequency of the word
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


#define GETTYIN 1500
#define MAXWORD 200

typedef struct {
    char word[MAXWORD];
    int count;
} WordCounter;

// Function to compare two WordCounter strcts 
int compareWordCounters(const void *a, const void *b) {
    return ((WordCounter *)b)->count - ((WordCounter *)a)->count;
}

int main() {
    char c;
    WordCounter wordLog[GETTYIN];
    int distinct = 0; // to keep track of the distinct entries

    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            ungetc(c, stdin);
            if (scanf("%s", wordLog[distinct].word) != 1) {
                break;  // Stop reading if there's an issue with scanf
            }

            // Ensure the last character is alphanumeric
            int len = strlen(wordLog[distinct].word);
            if (len > 0 && !isalpha(wordLog[distinct].word[len - 1])) {
                wordLog[distinct].word[len - 1] = '\0';
            }

            // Convert the word to lowercase for case-insensitive comparison
            for (int i = 0; wordLog[distinct].word[i]; i++) {
                wordLog[distinct].word[i] = tolower(wordLog[distinct].word[i]);
            }

            wordLog[distinct].count = 1;

            // Check if the word is already in the wordLog, if yes, update the count
            for (int i = 0; i < distinct; i++) {
                if (strcmp(wordLog[distinct].word, wordLog[i].word) == 0) {
                    wordLog[i].count++;
                    distinct--; // Decrement size to overwrite duplicate entry
                    break;  // Break after updating count to avoid unnecessary iterations
                }
            }

            distinct++; // Increment the size of the wordLog
        }
    }

    // Sort the wordLog array based on word frequency using qsort
    qsort(wordLog, distinct, sizeof(WordCounter), compareWordCounters);

    // Print the sorted wordLog
    for (int i = 0; i < distinct; i++) {
        printf("%d %s\n", wordLog[i].count, wordLog[i].word);
    }

    return 0;
}

