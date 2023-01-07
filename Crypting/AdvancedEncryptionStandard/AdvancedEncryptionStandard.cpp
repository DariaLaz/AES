#include <iostream>

//RIJNDAEL KEY SHEDULE/EXPANSION
//Rot Word
void Rotate(char* row) {
    char first = row[0];
    for (size_t i = 0; i < 3; i++)
    {
        row[i] = row[i + 1];
    }
    row[3] = first;
    return;
}
//Sub Word
void SubstituteSBox(char &element) {
    element = element 
              ^ (element < 1) 
              ^ (element < 2)
              ^ (element < 3)
              ^ (element < 4)
              ^ 99;
}
//Round constants
void RoundConstantUpdate(int& c) {
    if (c < 128)
    {
        c *= 2;
    }
    else
    {
        c = (2 * c) ^ 283;
    }
}

void EncryptRijndaelKeyShedule(char key[4][4]) {
    int rountConstant = 1;

    for (size_t row = 0; row < 4; row++)
    {
        Rotate(key[row]);
        key[row][0] ^= rountConstant;
        RoundConstantUpdate(rountConstant);
        for (size_t col = 0; col < 4; col++)
        {
            SubstituteSBox(key[row][col]);
        }
    }
}
void EncryptCurrentMatrix(char text[4][4], char key[4][4]) {
    char result = ' ';

    //2. Key Expansion
    EncryptRijndaelKeyShedule(key);
    //3. Add Round Key


    for (size_t i = 0; i < 9; i++)
    {
        
        //
    }
    //char*** keyMatrix = EncryptRijndaelKeyShedule(key);
    std::cout << result;
}
//void Decrypt(char* text) {
//    char result;
//
//    std::cout << result;
//}


int main()
{
    /*char text[4][4] = { 'm', 'y', ' ', 't',
                        'e', 'x', 't', ' ',
                        'i', 's', ' ', 'n',
                        'i', 'c', 'e', '.' };
    char key[4][4] = { 'e', 'x', 't', 'r',
                       'a', 't', 'e', 'r',
                       'r', 'e', 's', 't',
                       'r', 'i', 'a', 'l' };
    Encrypt(text, key);*/
}

