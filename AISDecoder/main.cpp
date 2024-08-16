#include "AISDecode.h"

vector<string> split(const string &str, char delimiter)
{
    vector<string> tokens;
    string token;
    stringstream ss(str);

    while (getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }

    return tokens;
}

string decToBinary(int decimal)
{

    bitset<6> binary(decimal);
    return binary.to_string();
}

int main()
{

    // sample : Type 19 : !AIVDM,1,1,,B,C5N3SRgPEnJGEBT>NhWAwwo862PaLELTBJ:V00000000S0D:R220,0*0B
    // sample : Type 24 A : !AIVDM,1,1,,A,H42O55i18tMET00000000000000,2*6D
    // sample : Type 24 B : !AIVDM,1,1,,A,H42O55lti4hhhilD3nink000?050,0*40

    string str;
    string AISInput = "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVW`abcdefghijklmnopqrstuvw";
    vector<char> AISCharacter(AISInput.begin(), AISInput.end());
    string binary;

    cin >> str;
    vector<string> literals = split(str, ',');

    // converting to binary Literal
    string part = literals[5];

    for (char c : part)
    {
        int value = AISInput.find(c);
        binary += decToBinary(value);
    }
    // cout << binary << endl;

    int msgType;
    msgType = bitset<6>(binary.substr(0, 6)).to_ulong();

    cout << " ----------------------------------------------- " << endl;
    cout << " \t\t Ship Message " << endl;
    cout << " ----------------------------------------------- " << endl;
    switch (msgType)
    {
    case 19:
    {

        AISMessage19 msg = decodeAISMessage19(binary);
        displayAISMessage19(msg);
        break;
    }
    case 24:
    {
        int type = bitset<2>(binary.substr(38, 2)).to_ulong();
        // cout << type << endl;
        if (type == 1)
        {
            AISMessage24typeB msg = decodeAISMessage24B(binary);
            displayAISMessage24B(msg);
        }
        else
        {
            AISMessage24typeA msg = decodeAISMessage24A(binary);
            displayAISMessage24A(msg);
        }
        break;
    }
    default:
        cout << "Message Type :" << msgType << endl;
        cout << "Not Coded Yet." << endl;
        break;
    }

    // Checksum Validation
    cout << ((verifyChecksum(str)) ? "Valid" : "Invalid");

    return 0;
}
