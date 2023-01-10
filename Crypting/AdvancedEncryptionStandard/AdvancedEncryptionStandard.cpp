/**
*
* Solution to course project #2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Daria Lazarova
* @idnumber 8MI0600140
* @compiler VC
*
* <main cpp file>
*
*/

#include <iostream>
#include "Encrypt.h"
#include "Decrypt.h"
#include "InputOutputFormat.h"
#include "FilesManager.h"

const int BUFFER_SIZE = 1024;

//Encrypts Or Decrypts the text with the given key
int* EncryptOrDecryptTheWholeText(int* text, int key[4][4], bool IsEncryption, int size) {
    int* result = new int[size]();
    int resultIndex = 0;

    //Since the text is the correct format, 16 is divisible by it's size
    int matrixesCount = (size / 16);
    
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
            EncryptCurrentMatrix(currentMatrix, key);
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
            }
           
            DecryptCurrentMatrix(currentMatrix, key);
            resultIndex = 0;
            for (size_t row = 0; row < 4; row++)
            {
                
                for (size_t col = 0; col < 4; col++)
                {
                    result[start + resultIndex] = currentMatrix[row][col];
                    resultIndex++;
                }
            }
        }
        
    }
    return result;
}


int main()
{
    //Choose action
    bool isEncryption = true;
    int action = -1;
    std::cout << "Select action: (enter 1 or 2)" << std::endl << " 1. Encryption" << std::endl << " 2. Decryption";
    std::cin >> action;
    while (action != 1 && action != 2)
    {
        std::cout << "Invalid input. Try again! ";
        std::cin >> action;
    }
    if (action == 2)
    {
        isEncryption = false;
    }

    //File Reading
    char readFileName[100], writeFileName[100], keyFileName[100];

    char str[BUFFER_SIZE];
    char keyStr[17];
    
    std::cout << "Enter the name of the file you want to get your text from: ";
    std::cin >> readFileName;
    std::cout << "Enter the name of the file you want to get your key from: ";
    std::cin >> keyFileName;
    
    //Actual Decryption/Encryption
    int size = GetArrayLen(str);
    size += (size % 16);
    int* text = new int[size];
    CharArrToIntArray(str, text);
    int key[4][4];
    CharArrToIntMatrix(keyStr, key);

    int* encrypted = EncryptOrDecryptTheWholeText(text, key, isEncryption, size);
    size = 16;
    int* decryted = EncryptOrDecryptTheWholeText(encrypted, key, isEncryption, size);
    char* result = new char[16];
    
    IntMatrixToCharArray(decryted, result, size);
    //TODO: Save result in writeFileName
}