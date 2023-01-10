#pragma once
#include <iostream>

int GetArrayLen(char* str);
int GetArrayLen(int* str);
void IntMatrixToString(int text[4][4], char* result);
void CharArrToIntArray(char* text, int* result);
void CharArrToIntMatrix(char* text, int matrix[4][4]);
void KeyToIntMatrix(char* key, int intKey[4][4]);
void IntMatrixToCharArray(int* decryted, char* result, int size);
void clearConsole();
void IntMatrixToIntArray(int matrix[4][4], int* arr);
void CharArrayToIntMatric(int matrix[4][4], char* arr);
bool IsEncryptionInput();