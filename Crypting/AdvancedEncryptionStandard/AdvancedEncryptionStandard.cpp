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
void PrintMatrix(char** matrix) {
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void PrintMatrix(char matrix[4][4]) {
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void PrintMatrix(int** matrix) {
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void PrintMatrix(int matrix[4][4]) {
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

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
    bool isEncryption = IsEncryptionInput();

    //File Reading
    char readFileName[BUFFER_SIZE];
    char writeFileName[BUFFER_SIZE];
    char keyFileName[17];
    readFileName[BUFFER_SIZE-1] = '\0';
    writeFileName[BUFFER_SIZE-1] = '\0';
    keyFileName[16] = '\0';

    
    std::cout << "Enter the name of the file you want to get your text from: ";

    GetFileName(readFileName, (!isEncryption ? "Encrypted" : "Decrypted"), true);

    std::cout << "Enter the your key: ";

    GetFileName(keyFileName, "Keys", (isEncryption ? false : true));

    std::cout << "Enter the name of the file you want to save your text in: ";
    GetFileName(writeFileName, (isEncryption ? "Encrypted" : "Decrypted"), false);



    /*char readPath[50];
    GetPath((!isEncryption ? "Encrypted" : "Decrypted"), readFileName, readPath);
    char keyPath[50];
    GetPath("Keys", keyFileName, keyPath);
    char writePath[50];
    GetPath((isEncryption ? "Encrypted" : "Decrypted"), writeFileName, writePath);
    
    char* text = ReadTextFromText(readPath);

    if (isEncryption)
    {
        int size = 0;
        int* textToIntArr = CharArrayToIntArray(text, size);
        char* keyStr = keyFileName;
        int key[4][4];
        int keySize = 16;
        CharKeyToIntMatrixKey(keyStr, key);
        int* ecrypted = EncryptOrDecryptTheWholeText(textToIntArr, key, true, size);
        int keyArr[16]; 
        IntMatrixToIntArray(key, keyArr);
        PrintMatrix(key);
        WriteTextInFile(keyArr, keyPath, keySize);
        WriteTextInFile(ecrypted, writePath, size);
    }
    else
    {
        int size = 0;
        int keySize = 0;
        int* keyArr = ReadIntArrayFromFile(keyPath, keySize);
        int key[4][4];
        IntArrayToIntMatrix(keyArr, key);
        int* textToIntArr = ReadIntArrayFromFile(readPath, size);
        int* crypted = EncryptOrDecryptTheWholeText(textToIntArr, key, false, size);
        char* result = new char[size];
        IntMatrixToCharArray(crypted,result, size);
        WriteTextInFile(result, writePath); 
    }*/
}