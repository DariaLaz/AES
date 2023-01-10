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
* <file with functions related with reading/writing in files>
*
*/

#include "FilesManager.h"
#include <fstream>

char* GetPath(const char* action, char* fileName, char* path) {
	int size = 3;
	path[0] = '.';
	path[1] = '.';
	path[2] = '/';
	int i = 0;
	while (action[i] != '\0')
	{
		path[size] = action[i];
		i++;
		size++;
	}
	path[size] = '/';
	size++;
	i = 0;
	while (fileName[i] != '\0')
	{
		path[size] = fileName[i];
		i++;
		size++;
	}
	path[size++] = '.';
	path[size++] = 't';
	path[size++] = 'x';
	path[size++] = 't';
	path[size] = '\0';
	return path;
}

void WriteTextInFile(char* text, char* path) {
	std::ofstream out(path);

	out << text;

	out.close();
}
void WriteTextInFile(int* text, char* path, int size) {
	std::ofstream out(path);
	for (size_t i = 0; i < size; i++)
	{
		out << text[i];
		out << " ";
	}

	out.close();
}

char* ReadTextFromText(char* path) {
	std::ifstream in(path);

	char text[2048];
	in.getline(text, 2048);

	in.close();

	return text;
}

int* ReadIntArrayFromFile(char* path, int size ) {
	int* arr = new int[size];
	std::ifstream in(path);
	for (size_t i = 0; i < size; i++)
	{
		in >> arr[i];
	}
	in.close();
	return arr;
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