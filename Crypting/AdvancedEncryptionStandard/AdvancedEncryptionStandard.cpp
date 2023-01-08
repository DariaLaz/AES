#include <iostream>
#include "Encrypt.h"
#include "Decrypt.h"
#include "InputOutputFormat.h"


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
    //Input
    std::string text;
    std::cin >> text;/*
    PKCS7(text);
    std::cout << GetStringLen(text) << std::endl;
    std::cout << (text);*/

    int* result[4][4];
    int matrixes = 0;

    int* result[4][4] = SeparateTextIntoMatrixes(text);

    for (size_t i = 0; i < matrixes; i++)
    {
        for (size_t row = 0; row < 4; row++)
        {
            for (size_t col = 0; col < 4; col++)
            {
                std::cout << result[i][row][col] << " ";
            }
            std::cout << std::endl;
        }
    }



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
    //int text[4][4] = { 101, 120, 116, 114,
    //                   97, 116, 101, 114,
    //                   114, 103, 115, 116,
    //                   114, 105, 97, 108 };
    //int key[4][4] = { 101, 120, 116, 114,
    //                   97, 116, 101, 114,
    //                   114, 101, 115, 116,
    //                   114, 105, 97, 108 };
    //PrintMatrix(text);
    //std::cout << "-----------------------" << std::endl;
    //EncryptCurrentMatrix(text,key);
    //PrintMatrix(text);
    //std::cout << "-----------------------" << std::endl;
    //DecryptCurrentMatrix(text, key);
    //PrintMatrix(text);
    //std::cout << "-----------------------" << std::endl;
}