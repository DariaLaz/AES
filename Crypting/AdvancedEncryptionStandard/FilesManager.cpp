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

void readCharArrayWithSpaces() {
	std::ofstream out("../test.txt");

	char test[] = "abc de";
	out << test;

	out.close();

	std::ifstream in("PractFiles.cpp");

	char test2[1024];
	in.getline(test2, 1024);

	in.close();
}