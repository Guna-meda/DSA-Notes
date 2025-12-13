#include <stdio.h>
#include <stdlib.h>

#define ALPHABET 26

// Trie node structure
struct Trie {
    struct Trie* children[ALPHABET];
    int isEnd;
};

// Create a new Trie node
struct Trie* createNode() {
    struct Trie* node = (struct Trie*)malloc(sizeof(struct Trie));
    node->isEnd = 0;

    for (int i = 0; i < ALPHABET; i++)
        node->children[i] = NULL;

    return node;
}

// Insert a word into Trie
void insert(struct Trie* root, char word[]) {
    struct Trie* curr = root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (curr->children[index] == NULL)
            curr->children[index] = createNode();

        curr = curr->children[index];
    }
    curr->isEnd = 1;   // mark word end
}

// Search a word in Trie
int search(struct Trie* root, char word[]) {
    struct Trie* curr = root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (curr->children[index] == NULL)
            return 0;   // letter path not found

        curr = curr->children[index];
    }
    return curr->isEnd;   // must be exact word end
}

int main() {
    struct Trie* root = createNode();

    insert(root, "apple");
    insert(root, "app");
    insert(root, "bat");

    printf("%d\n", search(root, "apple"));  // 1 (found)
    printf("%d\n", search(root, "app"));    // 1
    printf("%d\n", search(root, "apply"));  // 0 (not found)
    printf("%d\n", search(root, "bat"));    // 1
    printf("%d\n", search(root, "bad"));    // 0

    return 0;
}