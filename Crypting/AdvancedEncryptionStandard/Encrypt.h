#pragma once

void PrintMatrix(int key[4][4]);

//KEY SHEDULE/EXPANSION
void Rotate(int* row);
void SubstituteSBox(int& element);
void EncryptRijndaelKeyShedule(int key[4][4]);
void KeyExpansion(int key[4][4], int round);

//ADD ROUND KEY
void AddRoundKey(int key[4][4], int text[4][4]);

//BYTE SUBSTITUTION
void ByteSubstitution(int text[4][4]);

//SHIFT ROWS
void ShiftElements(int row[4], int count);
void ShiftRows(int text[4][4]);

//MIXING COLUMNS
void EncryptCurrentMatrix(int text[4][4], int key[4][4]);

