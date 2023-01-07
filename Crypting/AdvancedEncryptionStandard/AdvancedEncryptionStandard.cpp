#include <iostream>

//RijndaelKeyShedule

char*** EncryptRijndaelKeyShedule(char key[4][4]) {
    for (size_t row = 0; row < 4; row++)
    {
        for (size_t col = 0; col < 4; col++)
        {

        }
    }
}

void Encrypt(char text[4][4], char key[4][4]) {
    char result = ' ';
    char*** keyMatrix = EncryptRijndaelKeyShedule(key);
    std::cout << result;
}
//void Decrypt(char* text) {
//    char result;
//
//    std::cout << result;
//}


int main()
{
    char text[4][4] = { 'm', 'y', ' ', 't',
                        'e', 'x', 't', ' ',
                        'i', 's', ' ', 'n',
                        'i', 'c', 'e', '.' };
    char key[4][4] = { 'e', 'x', 't', 'r',
                       'a', 't', 'e', 'r',
                       'r', 'e', 's', 't',
                       'r', 'i', 'a', 'l' };
    Encrypt(text, key);
}

