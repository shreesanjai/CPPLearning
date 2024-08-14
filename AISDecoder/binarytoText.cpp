#include <iostream>
#include <string>
#include <bitset>
#include <vector>

// Function to convert a 6-bit binary string to a decimal value
int binaryToDecimal(const std::string& binary) {
    return std::bitset<6>(binary).to_ulong();
}

// Function to convert a decimal value to a character
char decimalToChar(int decimal) {
    // This function assumes a simple ASCII mapping for demonstration purposes.
    // For specific character encoding, adjust the mapping as needed.
    return static_cast<char>(decimal+'0');
}

// Function to convert a 6-bit binary string to text
std::string binaryToText(const std::string& binaryStr) {
    std::string text;
    size_t len = binaryStr.length();

    // Process the binary string in 6-bit chunks
    for (size_t i = 0; i < len; i += 6) {
        std::string binaryChunk = binaryStr.substr(i, 6);
        int decimalValue = binaryToDecimal(binaryChunk);
        text += decimalToChar(decimalValue);
    }

    return text;
}

int main() {
    // Example binary string with 6-bit groups
    std::string binaryStr = "010011000101011110000011100011100010110111100000010101111110011010010111010101010010100100001110011110111000100111010001000111000111111111001000000110000010100000110001011100010101011100100100010010011010001010100110000000000000000000000000000000000000000000000000100011000000010100001010100010000010000010000000"; // Corresponds to ASCII "ABC"

    std::string text = binaryToText(binaryStr);

    std::cout << "Binary: " << binaryStr << std::endl;
    std::cout << "Text: " << text << std::endl;

    return 0;
}
