#pragma once

char* GetPath(const char* action, char* fileName, char* path);

//Write in a file
void WriteTextInFile(char* text, char* path);
void WriteTextInFile(int* text, char* path, int size);

//Read from a file
char* ReadTextFromText(char* path);
int* ReadIntArrayFromFile(char* path, int& size);

bool IsFileExisting(char* name, const char* folder);