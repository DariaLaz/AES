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

char* ReadTextFromFile(char* path) {
	std::ifstream in(path);

	char text[2048];
	in.getline(text, 2048);

	in.close();

	return text;
}

int* ReadIntArrayFromFile(char* path, int& size ) {
	size = 0;
	int arr[1024];
	std::ifstream in(path);
	while (!in.eof())
	{
		in >> arr[size];
		size++;
	}
	size--;
	/*for (size_t i = 0; i < size; i++)
	{
		in >> arr[i];
	}*/
	in.close();
	return arr;
}

bool IsFileExisting(char* name, const char* folder) {
	char path[100];
	GetPath(folder, name, path);
	std::ifstream file(path);
	if (!file)          
		return false;   
	else                
		return true;
}
