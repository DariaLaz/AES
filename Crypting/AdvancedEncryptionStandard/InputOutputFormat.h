#pragma once
#include <iostream>

int GetArrayLen(char* str);
void CharArrToIntMatrix(char* text, int matrix[4][4]);
void KeyToIntMatrix(char* key, int intKey[4][4]);
void IntMatrixToCharArray(int* decryted, char* result, int& size);
void clearConsole();
void IntMatrixToIntArray(int matrix[4][4], int arr[16]);
bool IsEncryptionInput();

int* CharArrayToIntArray(char* arr, int& size);
void CharKeyToIntMatrixKey(char* text, int result[4][4]);
char* IntMatrixToCharNum(int key[4][4]);
char* IntArrayToCharArr(int* arr, int size);

void GetFileName(char* fileName, const char* folder, bool IsReading);
bool IsValidFileName(char* name, const char* folder);