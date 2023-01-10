#include <iostream>
#include "Encrypt.h"
#include "Decrypt.h"
#include "InputOutputFormat.h"

void PrintMatrix(int key[16]) {
    for (size_t i = 0; i < 4; i++)
    {
        std::cout << key[i] << " ";
    }
}

void PrintMatrix(int key[4][4]) {
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            std::cout << (int)key[i][j] << " ";
        }
        std::cout << std::endl;
    }
}




//void EncryptOrDecryptTheWholeText(int* intText, int key[4][4], bool IsEncryption, int* result, int size) {
//    int resIndex = 0;
//    for (size_t i = 0; i < size; i+=16)
//    {
//        int currentMatrix[4][4];
//        if (IsEncryption)
//        {
//            int el = 0;
//            for (size_t row = 0; row < 4; row++)
//            {
//                for (size_t col = 0; col < 4; col++)
//                {
//                    currentMatrix[row][col] = intText[i + el];
//                    el++;
//                }
//            }
//            EncryptCurrentMatrix(currentMatrix, key);
//        }
//        else
//        {
//            int start = size - i - 16;
//            int el = 0;
//
//            for (size_t row = 0; row < 4; row++)
//            {
//                for (size_t col = 0; col < 4; col++)
//                {
//                    currentMatrix[row][col] = intText[start + el];
//                    el++;
//                }
//            }
//           // DecryptCurrentMatrix(currentMatrix, key);
//        }
//        int resultIndex = 0;
//        for (size_t row = 0; row < 4; row++)
//        {
//            for (size_t col = 0; col < 4; col++)
//            {
//                result[resIndex] = currentMatrix[row][col];
//            }
//        }
//        char str[16];
//       // IntMatrixToString(currentMatrix, result + resIndex);
//    }
//}

int* EncryptOrDecryptTheWholeText(int* text, int key[4][4], bool IsEncryption, int size) {
    int* result = new int[size]();
    int resultIndex = 0;

    int matrixesCount = (size % 16 == 0) ? (size / 16) : (size / 16 + 1);
    

    for (size_t i = 0; i < matrixesCount; i++)
    {
        if (IsEncryption)
        {
            int currentMatrix[4][4];
            int index = 0;
            for (size_t row = 0; row < 4; row++)
            {
                for (size_t col = 0; col < 4; col++)
                {
                    currentMatrix[row][col] = text[i * 16 + index];
                    index++;
                }
            }
            PrintMatrix(currentMatrix);
            std::cout << "Original-------------------------";
            EncryptCurrentMatrix(currentMatrix, key);
           /* PrintMatrix(currentMatrix);
            std::cout << "Encrypted-------------------------";*/

            for (size_t row = 0; row < 4; row++)
            {
                for (size_t col = 0; col < 4; col++)
                {
                    result[resultIndex] = currentMatrix[row][col];
                    resultIndex++;
                }
            }
        } 
        else
        {
            int currentMatrix[4][4];
            int index = 0;
            int start = size - (i + 1) * 16;
            for (size_t row = 0; row < 4; row++)
            {
                for (size_t col = 0; col < 4; col++)
                {
                    currentMatrix[row][col] = text[start + index];
                    index++;
                }
            }/*
            PrintMatrix(currentMatrix);
            std::cout << "ToDecrypt-------------------------";*/

            DecryptCurrentMatrix(currentMatrix, key);
            PrintMatrix(currentMatrix);
            std::cout << "Decrypted-------------------------";
        }
        
    }
    return result;
}


int main()
{
    int text[32] = {  28 ,93, 122, 139, 161, 122, 115, 93, 161, 151, 93, 106, 123, 36 ,142, 23, 205, 142, 64, 23, 40, 64 ,115 ,142, 40, 252, 142, 36, 4, 4, 4, 4 };
    int key[4][4] = { 123, 36 ,142, 23, 205, 142, 64, 23, 40, 64 ,115 ,142, 40, 252, 142, 36 };

    int* encrypted = EncryptOrDecryptTheWholeText(text, key, true, 32);
    int* decryted = EncryptOrDecryptTheWholeText(encrypted, key, false, 32);


}