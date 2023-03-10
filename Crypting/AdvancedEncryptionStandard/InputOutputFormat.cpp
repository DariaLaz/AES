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

const int BUFF_SIZE = 10;

int GetArrayLen(char* str) {
	int counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	return counter;
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
void IntArrayToIntMatrix(int* arr, int matrix[4][4]) {
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

//Input
bool IsEncryptionInput() {
	char action[BUFF_SIZE];
	std::cout << "Select action: (enter 1 or 2)" << std::endl << " 1. Encryption" << std::endl << " 2. Decryption" << std::endl;
	std::cin >> action;
	while ((action[0] != '1' && action[0] != '2') || action[1] != '\0')
	{
		std::cout << "Invalid input. Try again! " << std::endl;
		std::cin >> action;
	}
	return action[0] == '1';
}
bool IsValidFileName(char* name, const char* folder) {
	if ((folder == "Keys" && GetArrayLen(name) != 16)
		|| (folder != "Keys" && name[FILENAME_SIZE - 1] != '\0'))
	{
		return false;
	}
	int i = 0;

	while (name[i] != '\0')
	{
		if (!((name[i] >= 'a' && name[i] <= 'z')
			|| (name[i] >= 'A' && name[i] <= 'Z')
			|| (name[i] >= '0' && name[i] <= '9')))
		{
			return false;
		}
		i++;
	}
	return true;
}

void ToLower(char* a) {
	int i = 0;
	while (a[i] != '\0')
	{
		if (a[i] >= 'A' && a[i] <= 'Z')
		{
			a[i] += ('a' - 'A');
		}
		i++;
	}
}
bool CompareCharArrays(char* arr1, const char* arr2) {
	int i = 0;
	while (arr1[i] != '\0' && arr2[i] != '\0')
	{
		if (arr1[i] != arr2[i])
		{
			return false;
		}
		i++;
	}
	return (arr1[i] == '\0' && arr2[i] == '\0');
}
bool ShouldStop() {
	std::cout << "Do you want to continue? (yes/no) ";
	char ans[4];
	std::cin >> ans;
	ToLower(ans);
	while (!(CompareCharArrays(ans, "yes")) && !(CompareCharArrays(ans, "no")))
	{
		std::cout << "Invalid answear. Try again ";

		std::cin >> ans;
		ToLower(ans);
	}

	return (CompareCharArrays(ans, "no"));
}