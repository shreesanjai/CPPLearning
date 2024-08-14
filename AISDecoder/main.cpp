#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <sstream>
#include <cmath>
using namespace std;


int binaryToDecimal(const std::string& binary) {
    int decimal = 0;
    cout<<binary<<endl;
    int length = binary.length();

    for (int i = 0; i < length; ++i) {
        if (binary[length - i - 1] == '1') {
            decimal += std::pow(2, i);
        }
    }
    return decimal;
}


vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    string token;
    stringstream ss(str);

    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}


string decToBinary(int decimal) {
    
    bitset<6> binary(decimal); 
    return binary.to_string();
}

unsigned long long binaryToDecimalManual(const string& binaryString) {
    unsigned long long decimalValue = 0;

    for (size_t i = 0; i < binaryString.size(); ++i) {
        if (binaryString[binaryString.size() - i - 1] == '1') {
            decimalValue += (1ULL << i);
        }
    }

    return decimalValue;
}


int main() {

    //sample : !AIVDM,1,1,,B,C5N3SRgPEnJGEBT>NhWAwwo862PaLELTBJ:V00000000S0D:R220,0*0B
    string str;
    cin >> str;

    //Seperated the AIS Message
    vector<string> literals = split(str, ',');


    //converting to binary Literal
    string binary;
    string part = literals[5];  

    
    for (char c : part) {
        int value = c - '0';
        cout<<value<<endl;  
        binary += decToBinary(value);  
    }
    cout << binary << endl;

    int seperationArray[] = {-1, 5, 7, 37, 45, 55, 56, 84, 111, 123, 132, 138, 142, 262, 270, 279, 288, 294, 300, 304, 305, 306, 307, 311};
    string entities[] = {"","Message Type","Repeat Indicator","MMSI","Regional Reserved","Speed Over Ground","Position Accuracy","Longtitude","Latitude","Course Over Ground","True Heading","Time Stamp","Regional reserved","Name","Type of Ship and Cargo","Dimension to bow","Dimension to stern","Dimension to port","Dimension to starboard","Position Fix Type","RAIM Flag","DTE","Assigned mode Flag","Spare"};

    for(int i=1;i<23;i++)
    {
        cout << entities[i] << "\t\t : " << binaryToDecimalManual(binary.substr(seperationArray[i-1]+1,seperationArray[i])) << endl ;
    }
    
    return 0;
}
