#include <iostream>
#include "Encrypt.h"
#include "Decrypt.h"


char* MatrixToCharArray(char text[4][4]) {
    char result[16];
    int i = 0;
    for (size_t row = 0; row < 4; row++)
    {
        for (size_t col = 0; col < 4; col++)
        {
            result[i] = text[row][col];
            i++;
        }
    }
    return result;
}

int main()
{
   /* char text[4][4] = { 'm', 'y', ' ', 't',
                        'e', 'x', 't', ' ',
                        'i', 's', ' ', 'n',
                        'i', 'c', 'e', '.' };
    char key[4][4] = { 'e', 'x', 't', 'r',
                       'a', 't', 'e', 'r',
                       'r', 'e', 's', 't',
                       'r', 'i', 'a', 'l' };
    int keyMatrix[4][4] = { 2, 3, 1, 1,
                             1, 2, 3, 1,
                             1, 1, 2, 3,
                             3, 1, 1, 2 };
    EncryptCurrentMatrix(text, key, keyMatrix);*/
    char a = (char)12;
    std::cout << (int)a << std::endl;
    SubstituteSBox(a);
    std::cout << (int)a << std::endl;
    InverseSBox(a);
    std::cout << (int)(a);
}