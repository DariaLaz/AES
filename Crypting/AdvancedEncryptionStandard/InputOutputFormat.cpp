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
* <file with functions that format the input and output>
*
*/

#include "InputOutputFormat.h"

int GetArrayLen(char* str) {
	int counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	return counter;
}

void TextToIntMatrixes(char* text, int* matrix) {
	int size = GetArrayLen(text);
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
void CharKeyToIntMatrixKey(char* text, int result[4][4]) {
    int i = 0;
	for (size_t row = 0; row < 4; row++)
	{
		for (size_t col = 0; col < 4; col++)
		{
			result[row][col] = text[i] - '0';
			i++;
		}
	}
}
int* CharArrayToIntArray(char* text, int& size) {
	size = GetArrayLen(text);

	int* result = new int[size % 16 == 0 ? size : size + (16 - size % 16)];
	int i = 0;
	while (text[i] != '\0')
	{
		result[i] = text[i];
		i++;
	}
	int paddingNum = 16 - (size % 16);
	while (size % 16 != 0)
	{
		result[size] = paddingNum;
		size++;
	}
	return result;
}


void CharArrToIntMatrix(char* text, int matrix[4][4]) {
	int i = 0;
	for (size_t row = 0; row < 4; row++)
	{
		for (size_t col = 0; col < 4; col++)
		{
			matrix[row][col] = text[i];
			i++;
		}
	}
}



char* IntMatrixToCharNum(int key[4][4]) {
	char result[64];
	int i = 0;
	for (size_t row = 0; row < 4; row++)
	{
		for (size_t col = 0; col < 4; col++)
		{
			result[i] = 0;
			int k = key[row][col];
			while (k % 10 != 0)
			{
				result[i] *= 10 + (k% 10);
				k /= 10;
			}
			result[i] += '0';
			i++;
			result[i] = ' ';
			i++;
		}

	}
	return result;
}

char* IntArrayToCharArr(int* arr, int size) {
	char* result = new char[size];
	for (size_t i = 0; i < size; i++)
	{
		result[i] = arr[i] + '0';
	}
	return result;
}



void IntMatrixToCharArray(int* decryted, char* result, int& size) {
	int lastDigit = decryted[size - 1];
	bool shouldCut = true;

	for (size_t i = size - 1; i > size - lastDigit + 1; i--)
	{
		if (decryted[i] != decryted[i - 1])
		{
			shouldCut = false;
			break;
		}
	}
	if (lastDigit == 0 || lastDigit > size)
	{
		shouldCut = false;
	}
	if (shouldCut)
	{
		size -= lastDigit;
	}
	for (size_t i = 0; i < size; i++)
	{
		result[i] = (decryted[i]);
	}
	result[size] = '\0';
}
void clearConsole() {
	std::cout << "\033[;H"; // Moves cursor to the top left
	std::cout << "\033[J"; // Clears the console
}
void IntMatrixToIntArray(int matrix[4][4], int arr[16]) {
	int i = 0;
	for (size_t row = 0; row < 4; row++)
	{
		for (size_t col = 0; col < 4; col++)
		{
			arr[i] = matrix[row][col];
			i++;
		}
	}
}
void CharArrayToIntMatric(int matrix[4][4], char* arr) {
	int i = 0;
	for (size_t row = 0; row < 4; row++)
	{
		for (size_t col = 0; col < 4; col++)
		{
			matrix[row][col] = arr[i];
			i++;
		}
	}
}
bool IsEncryptionInput() {
	int action;
	std::cout << "Select action: (enter 1 or 2)" << std::endl << " 1. Encryption" << std::endl << " 2. Decryption";
	std::cin >> action;
	while (action != 1 && action != 2)
	{
		std::cout << "Invalid input. Try again! ";
		std::cin >> action;
	}
	if (action == 2)
	{
		return false;
	}
	return true;
}