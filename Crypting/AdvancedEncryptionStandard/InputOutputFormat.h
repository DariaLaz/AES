#pragma once
#include <iostream>
const int FILENAME_SIZE = 30;
const int BUFFER_SIZE = 1024;


int GetArrayLen(char* str);
void IntMatrixToCharArray(int* decryted, char* result, int& size);
void clearConsole();
void IntMatrixToIntArray(int matrix[4][4], int arr[16]);
bool IsEncryptionInput();

int* CharArrayToIntArray(char* arr, int& size);
void CharKeyToIntMatrixKey(char* text, int result[4][4]);
char* IntMatrixToCharNum(int key[4][4]);
char* IntArrayToCharArr(int* arr, int size);
void IntArrayToIntMatrix(int* arr, int matrix[4][4]);

bool IsValidFileName(char* name, const char* folder);

void ToLower(char* a);

bool CompareCharArrays(char* arr1, const char* arr2);

bool ShouldStop();