#include "InputOutputFormat.h"

int GetStringLen(std::string str) {
	int counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	return counter;
}

void PKCS7(std::string& str) {
	int len = GetStringLen(str);

	std::string s(1, (char)(len % 16));
	while (len % 16 != 0)
	{
		str.append(s);
		len++;
	}
}


