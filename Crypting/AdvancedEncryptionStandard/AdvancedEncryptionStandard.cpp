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


void PrintMatrix(int matrix[4][4]) {
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            std::cout << matrix[i][j];
        }
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

bool isValid(char* text) {
    return true;
}
int main()
{
    char readPath[] = "../Encrypted/roro.txt";
    char* str = ReadTextFromText(readPath);
    int i = 0;
    while (str[i] != '\0')
    {
        std::cout << str[i];
        i++;
    }
    int* text = ReadIntArrayFromFile(readPath, i);
    for (size_t j = 0; j < i; j++)
    {
        std::cout << text[j] << " ";
    }
    ////Choose action
    //bool isEncryption = IsEncryptionInput();
    //
    ////File Reading
    //char readFileName[100];
    //char writeFileName[100];
    //char keyFileName[17] = "keykeykeykeykeyk";

    //
    //std::cout << "Enter the name of the file you want to get your text from: ";
    //std::cin >> readFileName;
    //while (!isValid(readFileName))
    //{
    //    std::cout << "Invalid file name! Try again: ";
    //    std::cin >> readFileName;
    //}
    //std::cout << "Enter the your key: ";
    //std::cin >> keyFileName;
    //while (!isValid(readFileName))
    //{
    //    std::cout << "Invalid key! Try again: ";
    //    std::cin >> keyFileName;
    //}
    //std::cout << "Enter the name of the file you want to save your text in: ";
    //std::cin >> writeFileName;
    //while (!isValid(writeFileName))
    //{
    //    std::cout << "Invalid file name! Try again: ";
    //    std::cin >> writeFileName;
    //}
    //char readPath[50];
    //GetPath((!isEncryption ? "Encrypted" : "Decrypted"), readFileName, readPath);
    //char keyPath[50];
    //GetPath("Keys", keyFileName, keyPath);
    //char writePath[50];
    //GetPath((isEncryption ? "Encrypted" : "Decrypted"), writeFileName, writePath);
    //
    //char* str = ReadTextFromText(readPath);
    //int key[4][4];
    //if (isEncryption)
    //{
    //    char* keyStr = keyFileName;
    //    CharArrToIntMatrix(keyStr, key);

    //}
    //else
    //{
    //    char* keyStr = ReadTextFromText(keyPath);
    //    int keyArr[16];
    //    CharArrToIntArray(keyStr, keyArr);
    //    IntArrayToIntMatrix(keyArr, key);
    //}
    //     
    //int size = 1;
    //int i = 0;
    //while (str[i] != '\0')
    //{
    //    if (str[i] == ' ')
    //    {
    //        size++;
    //    }
    //    i++;
    //}
    //int* text = ReadIntArrayFromFile(readPath, size);
    ////CharArrToIntArray(str, text);

    //int* crypted = EncryptOrDecryptTheWholeText(text, key, isEncryption, size);

    //char* result = new char[size];
    //if (isEncryption)
    //{
    //    int saveKey[16];
    //    IntMatrixToIntArray(key, saveKey);
    //    char path[50];
    //    GetPath("Keys", keyFileName, path);
    //    
    //    WriteTextInFile(saveKey, keyPath, 16);
    //    WriteTextInFile(crypted, writePath, size);

    //}
    //else
    //{
    //    IntMatrixToCharArray(crypted, result, size);
    //    WriteTextInFile(result, writePath);
    //}


    ////TODO: Save result in writeFileName
}