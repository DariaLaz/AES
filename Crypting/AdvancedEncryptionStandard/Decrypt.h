#pragma once
//REVERSED RIJNDAEL KEY SHEDULE/EXPANSION
void ReverseRotate(int* row);
void InverseSBox(int& element);
void DecryptRijndaelKeyShedule(int key[4][4]);

//REMOVE ROUND KEY
void RemoveRoundKey(int key[4][4], int text[4][4]);

//REVERSED BYTE SUBSTITUTION
void ReversedByteSubstitution(int text[4][4]);

//REVERSED SHIFT ROWS
void ReversedShiftElements(int row[4], int count);
void ReversedShiftRows(int text[4][4]);

//REVERSED MIXING COLUMNS
void ReversedMixSingleColumn(int col[4]);
void ReversedMixColumns(int text[4][4]);


void DecryptCurrentMatrix(int text[4][4], int key[4][4]);