#include "InputOutputFormat.h"



int GetCharArrayLen(char* str) {
	int counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	return counter;
}

void TextToIntMatrixes(char* text, int* matrix) {
	int size = GetCharArrayLen(text);
	int textIndex = 0;
	size_t i = 0;
	for (i = 0; i < size; i++)
	{
		matrix[i] = (int)text[i];
	}
	int paddingNum = (size % 16);
	while (size % 16 != 0)
	{
		matrix[i] = paddingNum;
		i++;
	}
}
void KeyToIntMatrix(char* key, int intKey[4][4]) {
	int i = 0;
	for (size_t row = 0; row < 4; row++)
	{
		for (size_t col = 0; col < 4; col++)
		{
			intKey[row][col] = key[i];
			i++;
		}
	}
}
void IntKeyToText(char* key, int intKey[4][4]) {
	int i = 0;
	for (size_t row = 0; row < 4; row++)
	{
		for (size_t col = 0; col < 4; col++)
		{
			key[i] = (char)intKey[row][col];
			i++;
		}
	}
}


void PKCS7(char* str) {
	int len = GetCharArrayLen(str);

	std::string s(1, (char)(len % 16));
	/*while (len % 16 != 0)
	{
		str.append(s);
		len++;
	}*/
}

void IntMatrixToString(int text[4][4], char* result) {
	int i = 0;
	for (size_t row = 0; row < 4; row++)
	{
		for (size_t col = 0; col < 4; col++)
		{
			result[i] = (char)text[row][col];
			i++;
		}
	}
}
void StringToIntArray(std::string key, int result[4][4]) {
	int i = 0;
	for (size_t row = 0; row < 4; row++)
	{
		for (size_t col = 0; col < 4; col++)
		{
			result[row][col] = (int)key[i];
			i++;
		}
	}
}
