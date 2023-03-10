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

int MAX_TEXT_LEN = 1024;

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
            size_t index = 0;
            size_t start = size - (i + 1) * 16;
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

//Input
void GetFileName(char* fileName, const char* folder, bool IsReading) {
    std::cin >> fileName;
    bool d = IsFileExisting(fileName, folder);

    bool k = IsFileExisting(fileName, folder);
    bool s = IsValidFileName(fileName, folder);

    while (!IsValidFileName(fileName, folder)
        || (IsReading && !IsFileExisting(fileName, folder))
        || (!IsReading && IsFileExisting(fileName, folder) && folder != "Keys"))
    {
        std::cout << "Invalid file name! Try again: ";
        std::cin >> fileName;
    }
}

int main()
{
    while (true)
    {
        //Choose action
        bool isEncryption = IsEncryptionInput();

        //File Reading
        char readFileName[FILENAME_SIZE];
        char writeFileName[FILENAME_SIZE];
        char keyFileName[17];
        readFileName[FILENAME_SIZE - 1] = '\0';
        writeFileName[FILENAME_SIZE - 1] = '\0';
        keyFileName[16] = '\0';


        std::cout << "Enter the name of the file you want to get your text from: ";
        GetFileName(readFileName, (!isEncryption ? "Encrypted" : "Decrypted"), true);

        std::cout << "Enter your key: ";
        GetFileName(keyFileName, "Keys", (isEncryption ? false : true));

        std::cout << "Enter the name of the file you want to save your text in: ";
        GetFileName(writeFileName, (isEncryption ? "Encrypted" : "Decrypted"), false);

        char readPath[50];
        GetPath((!isEncryption ? "Encrypted" : "Decrypted"), readFileName, readPath);
        char keyPath[50];
        GetPath("Keys", keyFileName, keyPath);
        char writePath[50];
        GetPath((isEncryption ? "Encrypted" : "Decrypted"), writeFileName, writePath);

        //Text to be decrypted/encrypted
        char* text = ReadTextFromFile(readPath);
        int size = 0;
        int key[4][4];

        if (GetArrayLen(text) > MAX_TEXT_LEN)
        {
            std::cout << "The text is more than "<< MAX_TEXT_LEN <<" symbols. Try Again: " << std::endl;
            clearConsole();

            continue;
        }

        if (isEncryption)
        {
            int* textToIntArr = CharArrayToIntArray(text, size);
            char* keyStr = keyFileName;
            int keySize = 16;
            CharKeyToIntMatrixKey(keyStr, key);
            int* encrypted = EncryptOrDecryptTheWholeText(textToIntArr, key, true, size);
            int keyArr[16];
            IntMatrixToIntArray(key, keyArr);
            WriteTextInFile(keyArr, keyPath, keySize);
            WriteTextInFile(encrypted, writePath, size);
            delete[] encrypted;
        }
        else
        {
            int keySize = 0;
            int* keyArr = ReadIntArrayFromFile(keyPath, keySize);

            IntArrayToIntMatrix(keyArr, key);
            int* textToIntArr = ReadIntArrayFromFile(readPath, size);
            int* decrypted = EncryptOrDecryptTheWholeText(textToIntArr, key, false, size);
            char* result = new char[size];
            IntMatrixToCharArray(decrypted, result, size);
            WriteTextInFile(result, writePath);
            delete[] decrypted;
        }

        if (ShouldStop())
        {
            return 0;
        }
        clearConsole();
    }
}