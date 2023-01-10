# AES - 128
<h2>Introduction</h2>
This is an implementation of the AES algorithm for encryption and decryption of data in C++.
<h2>How does it work?</h2>

1. The user should choose action (encrypt/decrypt);
2. The input text and key are being read from files;
3. The chosen action (encrypt/decrypt) is being performed with the given key and the result is returned;

<h2>Encryption</h2>
Encryption consists of several main stepts:

1. Block separation (4x4 matrix)
2. Key Expansion
3. Adding round key

Then 9 iterations the following:

4. Byte substitution
5. Shift Rows
6. Mixing colums
3. Adding round key
2. Key Expansion

And after that:

4. Byte substitution
5. Shift Rows
3. Adding round key 
<h2>Decryption</h2>
The decryption has pretty much the same steps but in reverse order.
