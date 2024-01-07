#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void decrypt(char* text, char* key, char* decryptedText);

int main(int argc, char *argv[]) {
    if (argc > 1) {
        char *key = argv[1];
        printf("The key is: %s\n", key);

        char text[1024];  // Assuming the text won't be longer than 1023 characters
        printf("plaintext: ");
        scanf("%1023s", text); 

        char decryptedText[strlen(text) + 1];
        decrypt(text, key, decryptedText);

        printf("Decrypted text: %s\n", decryptedText);
    } else {
        printf("No command-line arguments were provided.\n");
    }

    return 0;
}

void decrypt(char* text, char* key, char* decryptedText) {
    int keyIndex = 0, keyLength = strlen(key), textLength = strlen(text);

    for (int i = 0; i < textLength; i++) {
        char character = text[i];

        if (keyIndex == keyLength) {
            keyIndex = 0;
        }

        if (isupper(character)) {
            decryptedText[i] = ((character - 'A') - (toupper(key[keyIndex]) - 'A') + 26) % 26 + 'A';
        } else if (islower(character)) {
            decryptedText[i] = ((character - 'a') - (tolower(key[keyIndex]) - 'a') + 26) % 26 + 'a';
        } else {
            decryptedText[i] = character;
        }

        keyIndex++;
    }
    decryptedText[textLength] = '\0'; // Null-terminating the decrypted text
}
