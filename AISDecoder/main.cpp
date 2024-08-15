#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <sstream>

using namespace std;


string decodeAISName(const string &binaryMessage) {
    string decodedName;
    const string AIS_CHARSET = " ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^- !\"#$%&'()*+,-./0123456789:;<=>?";

    for (size_t i = 0; i < 120; i += 6) {
        string chunk = binaryMessage.substr(i, 6);
        bitset<6> bits(chunk);
        int value = static_cast<int>(bits.to_ulong());
        char decodedChar = AIS_CHARSET[value];
        if(decodedChar != ' ')
            decodedName += decodedChar;
    }

    return decodedName;
}

struct AISMessageType19 {
    unsigned long messageType;
    unsigned long repeatIndicator;
    unsigned long mmsi;  
    unsigned long sog;
    unsigned long positionAccuracy;
    unsigned long longitude;  
    unsigned long latitude;   
    unsigned long cog;
    unsigned long trueHeading;
    unsigned long timestamp;
    unsigned long regionalReserved;
    bitset<120> name;
    unsigned long typeOfShipAndCargoType;
    unsigned long dimensionToBow;
    unsigned long dimensionToStern;
    unsigned long dimensionToPort;
    unsigned long dimensionToStarboard;
    unsigned long positionFixType;
    unsigned long raimFlag;
    unsigned long dte;
    unsigned long assignedModeFlag;
    unsigned long spare;
    // unsigned long raFlag;
    // unsigned long radioStatus;  
};

AISMessageType19 decodeAISMessageType19(const string &binaryMessage) {
    AISMessageType19 message;

    message.messageType = bitset<6>(binaryMessage.substr(0, 6)).to_ulong();
    message.repeatIndicator = bitset<2>(binaryMessage.substr(6, 2)).to_ulong();
    message.mmsi = bitset<30>(binaryMessage.substr(8, 30)).to_ulong();
    message.sog = bitset<10>(binaryMessage.substr(46, 10)).to_ulong();
    message.positionAccuracy = bitset<1>(binaryMessage.substr(56, 1)).to_ulong();
    message.longitude = bitset<28>(binaryMessage.substr(57, 28)).to_ulong();
    message.latitude = bitset<27>(binaryMessage.substr(85, 27)).to_ulong();
    message.cog = bitset<12>(binaryMessage.substr(112, 12)).to_ulong();
    message.trueHeading = bitset<9>(binaryMessage.substr(124, 9)).to_ulong();
    message.timestamp = bitset<6>(binaryMessage.substr(133, 6)).to_ulong();
    message.regionalReserved = bitset<4>(binaryMessage.substr(139, 4)).to_ulong();
    message.name = bitset<120>(binaryMessage.substr(143, 120));
    message.typeOfShipAndCargoType = bitset<8>(binaryMessage.substr(263, 8)).to_ulong();
    message.dimensionToBow = bitset<9>(binaryMessage.substr(271, 9)).to_ulong();
    message.dimensionToStern = bitset<9>(binaryMessage.substr(280, 9)).to_ulong();
    message.dimensionToPort = bitset<6>(binaryMessage.substr(289, 6)).to_ulong();
    message.dimensionToStarboard = bitset<6>(binaryMessage.substr(295, 6)).to_ulong();
    message.positionFixType = bitset<4>(binaryMessage.substr(301, 4)).to_ulong();
    message.raimFlag = bitset<1>(binaryMessage.substr(305, 1)).to_ulong();
    message.dte = bitset<1>(binaryMessage.substr(306, 1)).to_ulong();
    message.assignedModeFlag = bitset<1>(binaryMessage.substr(307, 1)).to_ulong();
    message.spare = bitset<3>(binaryMessage.substr(308, 3)).to_ulong();
    // message.raFlag = bitset<1>(binaryMessage.substr(315, 1)).to_ulong();
    // message.radioStatus = bitset<19>(binaryMessage.substr(316, 19)).to_ulong();

    return message;
}

void displayAISMessageType19(const AISMessageType19 &message) {
    cout << "Message Type: " << message.messageType << endl;
    cout << "Repeat Indicator: " << message.repeatIndicator << endl;
    cout << "MMSI: " << message.mmsi << endl;
    cout << "Speed Over Ground (SOG): " << message.sog << " knots" << endl;
    cout << "Position Accuracy: " << message.positionAccuracy << endl;
    cout << "Longitude: " << message.longitude / 600000.0 << " degrees" << endl;
    cout << "Latitude: " << message.latitude / 600000.0 << " degrees" << endl;
    cout << "Course Over Ground (COG): " << message.cog / 10.0 << " degrees" << endl;
    cout << "True Heading: " << message.trueHeading << " degrees" << endl;
    cout << "Timestamp: " << message.timestamp << " seconds" << endl;
    cout << "Regional Reserved: " << message.regionalReserved << endl;
    cout << "Name: " << decodeAISName(message.name.to_string()) << endl;  
    cout << "Type of Ship and Cargo Type: " << message.typeOfShipAndCargoType << endl;
    cout << "Dimension to Bow: " << message.dimensionToBow << " meters" << endl;
    cout << "Dimension to Stern: " << message.dimensionToStern << " meters" << endl;
    cout << "Dimension to Port: " << message.dimensionToPort << " meters" << endl;
    cout << "Dimension to Starboard: " << message.dimensionToStarboard << " meters" << endl;
    cout << "Position Fix Type: " << message.positionFixType << endl;
    cout << "RAIM Flag: " << message.raimFlag << endl;
    cout << "DTE: " << message.dte << endl;
    cout << "Assigned Mode Flag: " << message.assignedModeFlag << endl;
    cout << "Spare: " << message.spare << endl;
    // cout << "RA Flag: " << message.raFlag << endl;
    // cout << "Radio Status: " << message.radioStatus << endl;
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

    AISMessageType19 msg = decodeAISMessageType19(binary);

    displayAISMessageType19(msg);
    
    return 0;
}
