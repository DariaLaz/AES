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

void CharArrToIntArray(char* text, int* result) {
	int len = GetArrayLen(text);
	size_t i = 0;
	for (i = 0; i < len; i++)
	{
		result[i] = text[i];
	}
	int paddingNum = (16 - len % 16);
	while (len % 16 != 0)
	{
		result[i] = paddingNum;
		i++;
		len++;
	}
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
void IntMatrixToCharArray(int* decryted, char* result, int size) {
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
	if (shouldCut)
	{
		size -= lastDigit;
	}
	for (size_t i = 0; i < size; i++)
	{
		result[i] = (int)decryted[i];
	}
	result[size] = '\0';
}
void clearConsole() {
	std::cout << "\033[;H"; // Moves cursor to the top left
	std::cout << "\033[J"; // Clears the console
}

void IntMatrixToIntArray(int matrix[4][4], int* arr) {
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