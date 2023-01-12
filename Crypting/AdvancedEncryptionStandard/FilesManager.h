#pragma once
char* GetPath(const char* action, char* fileName, char* path);
void WriteTextInFile(char* text, char* path);
void WriteTextInFile(int* text, char* path, int size);
char* ReadTextFromText(char* path);
int* ReadIntArrayFromFile(char* path, int& size);
void IntArrayToIntMatrix(int* array, int matrix[4][4]);
