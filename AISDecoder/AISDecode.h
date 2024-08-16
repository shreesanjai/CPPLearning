#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <sstream>
#include <cmath>
using namespace std;

string decodeAISName(const string &binaryMessage,int size)
{
    string decodedName;
    const string AIS_CHARSET = " ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^- !\"#$%&'()*+,-./0123456789:;<=>?";

    for (size_t i = 0; i < size; i += 6)
    {
        string chunk = binaryMessage.substr(i, 6);
        bitset<6> bits(chunk);
        int value = static_cast<int>(bits.to_ulong());
        char decodedChar = AIS_CHARSET[value];
        if (decodedChar != ' ')

            decodedName += decodedChar;
    }

    return decodedName;
}

struct AISMessage19
{
    unsigned long messageType;
    unsigned long repeatIndicator;
    unsigned long mmsi;
    unsigned long spare0;
    unsigned long sog;
    unsigned long positionAccuracy;
    double longitude;
    double latitude;
    double cog;
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
};

AISMessage19 decodeAISMessage19(const string &binaryMessage)
{
    AISMessage19 message;

    message.messageType = bitset<6>(binaryMessage.substr(0, 6)).to_ulong();
    message.repeatIndicator = bitset<2>(binaryMessage.substr(6, 2)).to_ulong();
    message.mmsi = bitset<30>(binaryMessage.substr(8, 30)).to_ulong();
    message.spare0 = bitset<8>(binaryMessage.substr(38, 8)).to_ulong();
    message.sog = bitset<10>(binaryMessage.substr(46, 10)).to_ulong();
    message.positionAccuracy = bitset<1>(binaryMessage.substr(56, 1)).to_ulong();
    message.longitude = bitset<28>(binaryMessage.substr(57, 28)).to_ulong()/600000.0;
    message.latitude = bitset<27>(binaryMessage.substr(85, 27)).to_ulong()/600000.0;
    message.cog = bitset<12>(binaryMessage.substr(112, 12)).to_ulong() / 10.0;
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
    message.spare = bitset<4>(binaryMessage.substr(308, 4)).to_ulong();

    while(abs(message.longitude) > 180)
    {
        message.longitude -= 180;
        message.longitude = -message.longitude;
    }


    while(abs(message.latitude) > 90)
    {
        message.latitude -= 90;
        message.latitude = -message.latitude;
    }


    return message;
}

void displayAISMessage19(const AISMessage19 &message)
{
    cout << "Message Type: " << message.messageType << endl;
    cout << "Repeat Indicator: " << message.repeatIndicator << endl;
    cout << "MMSI: " << message.mmsi << endl;
    cout << "Speed Over Ground (SOG): " << message.sog << " knots" << endl;
    cout << "Position Accuracy: " << message.positionAccuracy << endl;
    cout << "Longitude: " << abs(message.longitude) << " deg" << ((message.longitude < 0) ? " W" : " E") << endl;
    cout << "Latitude: " << abs(message.latitude) << " deg" << ((message.latitude < 0) ? " S" : " N") << endl;
    cout << "Course Over Ground (COG): " << message.cog << " deg" << endl;
    cout << "True Heading: " << message.trueHeading << " deg" << endl;
    cout << "Timestamp: " << message.timestamp << " seconds" << endl;
    cout << "Regional Reserved: " << message.regionalReserved << endl;
    cout << "Name: " << decodeAISName(message.name.to_string(),120) << endl;
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

    
}



struct AISMessage24typeA{
    unsigned long messageType;
    unsigned long repeatIndicator;
    unsigned long mmsi;
    unsigned long partNumber;
    bitset<120> name;
    unsigned long spare0;
};

AISMessage24typeA decodeAISMessage24A(const string& binaryMessage)
{
    AISMessage24typeA message;

    message.messageType = bitset<6>(binaryMessage.substr(0, 6)).to_ulong();
    message.repeatIndicator = bitset<2>(binaryMessage.substr(6, 2)).to_ulong();
    message.mmsi = bitset<30>(binaryMessage.substr(8, 30)).to_ulong();
    message.partNumber = bitset<2>(binaryMessage.substr(38, 2)).to_ulong();
    message.name = bitset<120>(binaryMessage.substr(40, 120));
    message.spare0 = bitset<8>(binaryMessage.substr(160, 8)).to_ulong();

    return message;
}

void displayAISMessage24A(const AISMessage24typeA &message)
{
    cout << "Message Type: " << message.messageType << endl;
    cout << "Repeat Indicator: " << message.repeatIndicator << endl;
    cout << "MMSI: " << message.mmsi << endl;
    cout << "Part Number: " << message.partNumber << endl;
    cout << "Name: " << decodeAISName(message.name.to_string(),120) << endl;
    cout << "Spare: " << message.spare0 << endl;
}



struct AISMessage24typeB{
    unsigned long messageType;
    unsigned long repeatIndicator;
    unsigned long mmsi;
    unsigned long partNumber;
    unsigned long ShipType;
    bitset<42> vendorID;
    unsigned long ModelCode;
    unsigned long SerialNumber;
    bitset<42> callSign;
    unsigned long dimensionToBow;
    unsigned long dimensionToStern;
    unsigned long dimensionToPort;
    unsigned long dimensionToStarboard;
    unsigned long vessal_length;
    unsigned long vessal_beam;
    unsigned long motherShip_mmsi;
    unsigned long spare0;
};

AISMessage24typeB decodeAISMessage24B(const string& binaryMessage)
{
    AISMessage24typeB message;

    message.messageType = bitset<6>(binaryMessage.substr(0, 6)).to_ulong();
    message.repeatIndicator = bitset<2>(binaryMessage.substr(6, 2)).to_ulong();
    message.mmsi = bitset<30>(binaryMessage.substr(8, 30)).to_ulong();
    message.partNumber = bitset<2>(binaryMessage.substr(38, 2)).to_ulong();
    //message.name = bitset<120>(binaryMessage.substr(40, 120));
    message.ShipType = bitset<8>(binaryMessage.substr(40, 8)).to_ulong();
    message.vendorID = bitset<42>(binaryMessage.substr(48, 42));
    message.ModelCode = bitset<4>(binaryMessage.substr(66, 4)).to_ulong();
    message.SerialNumber = bitset<20>(binaryMessage.substr(70, 20)).to_ulong();
    message.callSign = bitset<42>(binaryMessage.substr(90, 42));
    
    message.dimensionToBow = bitset<9>(binaryMessage.substr(132, 9)).to_ulong();
    message.dimensionToStern = bitset<9>(binaryMessage.substr(141, 9)).to_ulong();
    message.dimensionToPort = bitset<6>(binaryMessage.substr(150, 6)).to_ulong();
    message.dimensionToStarboard = bitset<6>(binaryMessage.substr(156, 6)).to_ulong();
    message.motherShip_mmsi = bitset<30>(binaryMessage.substr(132, 30)).to_ulong();
    message.spare0 = bitset<6>(binaryMessage.substr(162, 6)).to_ulong();

    message.vessal_length = message.dimensionToBow + message.dimensionToStern;
    message.vessal_beam = message.dimensionToPort + message.dimensionToStarboard;
    
    return message;
}

void displayAISMessage24B(const AISMessage24typeB &message)
{
    cout << "Message Type: " << message.messageType << endl;
    cout << "Repeat Indicator: " << message.repeatIndicator << endl;
    cout << "MMSI: " << message.mmsi << endl;
    cout << "Part Number: " << message.partNumber << endl;
    cout << "Ship Type: " << message.ShipType << endl;
    cout << "Vendor ID: " << decodeAISName(message.vendorID.to_string(),42) << endl;
    cout << "Model Code: " << message.ModelCode << endl;
    cout << "Serial Number: " << message.SerialNumber << endl;
    cout << "Call Sign : " << decodeAISName(message.callSign.to_string(),42) << endl;
    cout << "Dimension to Bow: " << message.dimensionToBow << " meters" << endl;
    cout << "Dimension to Stern: " << message.dimensionToStern << " meters" << endl;
    cout << "Dimension to Port: " << message.dimensionToPort << " meters" << endl;
    cout << "Dimension to Starboard: " << message.dimensionToStarboard << " meters" << endl;
    cout << "Vessal Length: " << message.vessal_length <<endl;
    cout << "Vessal Beam: " << message.vessal_beam <<endl;
    cout << "MotherShip MMSI : " << message.motherShip_mmsi << endl;
    cout << "Spare: " << message.spare0 << endl;

    
}
