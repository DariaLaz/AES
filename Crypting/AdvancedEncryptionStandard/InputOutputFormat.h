#pragma once
#include <iostream>

int GetCharArrayLen(char* str);
void PKCS7(std::string& str);
void IntMatrixToString(int text[4][4], char* result);
void StringToIntArray(std::string key, int result[4][4]);
void TextToIntMatrixes(char* text, int* matrix);
void KeyToIntMatrix(char* key, int intKey[4][4]);
void IntKeyToText(char* key, int intKey[4][4]);

