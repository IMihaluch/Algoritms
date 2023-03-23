#include <stdio.h>
#include <string.h>

// Функция для шифрования сообщения с использованием метода шифрования Цезаря
void encrypt_caesar(char message[], int key) {
    int i;
    char ch;

    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];

        if(ch >= 'a' && ch <= 'z'){
            ch = ch + key;

            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }

            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key;

            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }

            message[i] = ch;
        }
    }
}

// Функция расшифровки сообщения с использованием метода шифрования Цезаря
void decrypt_caesar(char message[], int key) {
    int i;
    char ch;

    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];

        if(ch >= 'a' && ch <= 'z'){
            ch = ch - key;

            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }

            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch - key;

            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }

            message[i] = ch;
        }
    }
}

// Функция для шифрования сообщения методом перестановки
void encrypt_permutation(char message[], int columns) {
    int i, j, k = 0;
    char matrix[100][100];

    for(i = 0; message[i] != '\0'; ++i) {
        matrix[k][i % columns] = message[i];
        if(i % columns == columns - 1) {
            k++;
        }
    }

    
    for(j = 0; j < columns; j++) {
        for(i = 0; i < k + 1; i++) {
            printf("%c", matrix[i][j]);
        }
    }
}

// Функция для расшифровки сообщения с помощью метода перестановки
void decrypt_permutation(char message[], int columns) {
    int i, j, k = 0;
    char matrix[100][100];

    
    for(i = 0; message[i] != '\0'; ++i) {
        matrix[k][i % columns] = message[i];
        if(i % columns == columns - 1) {
            k++;
        }
    }

    
    for(i = 0; i < k + 1; i++) {
        for(j = 0; j < columns; j++) {
            printf("%c", matrix[i][j]);
        }
    }
}

int main() {
    char message[] = "secret message";
    int caesar_key = 3;
    int permutation_columns = 5;

    // Шифрую сообщение, используя метод шифрования Цезаря
    encrypt_caesar(message, caesar_key);
    printf("Encrypted message using Caesar's encryption method: %s\n", message);

    // Дешифрую сообщение, используя метод шифрования Цезаря
    decrypt_caesar(message, caesar_key);
printf("Decrypted message using Caesar's encryption method: %s\n", message);
// Шифрую сообщение с помощью метода перестановки
printf("Encrypted message using permutation method: ");
encrypt_permutation(message, permutation_columns);
printf("\n");

// Дешифрую сообщения с помощью метода перестановки
printf("Decrypted message using permutation method: ");
decrypt_permutation(message, permutation_columns);
printf("\n");

return 0;
}
