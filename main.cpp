#include <iostream>
#include <string>
#include <inttypes.h>
#include <cstring>
#include <bitset>
#include <math.h>

using namespace std;

class IpType 
{
    public:
        IpType() {

        };
        string octet(string ip, int position);
        string ipType(string ipd);

        int dot_number(char num);
        int stringToNumber(string number);
        
    private:
        string ip;
        int prefix;
};

int main () {
    // This program use to determine the class of the IP address
    // Enter Ip Address
    string ip_address;
    int prefix;
    cout << "Enter IP Address: ";
    cin >> ip_address;
    cout << "Enter prefix number: ";
    cin >> prefix;

    IpType ip = IpType();
    string one = ip.ipType(ip_address);
    cout << one;
    return 0;
}


string IpType::octet(string ip, int position) {
    string dot;
    int three;
    string dot_position;


    for (int i = 0; i < size(ip); i++) {
        if (ip[i] == '.') {
            dot_position += to_string(i);
        }
    }

    int one = dot_number(dot_position[0]);
    int two = dot_number(dot_position[1]);

    if ( size(dot_position) > 3) {
        for( size_t i = 2; i < 4; i++) {
            dot += dot_position[i];
        }
        three = stringToNumber(dot);
    } else {
        three = dot_number(dot_position[2]);
    }

    string octet;

    switch (position) {
        case 1:
            for ( size_t i {}; i < one; i++) {
                octet += ip[i];
            }
            break;
        case 2:
            for ( size_t i = one + 1; i < two; i++) {
                octet += ip[i];
            }
            break;
        case 3:
            for ( size_t i = two + 1; i < three; i++) {
                octet += ip[i];
            }
            break;
        case 4:
            for ( size_t i = three + 1; i < size(ip); i++) {
                octet += ip[i];
            }
            break;
        default:
            cout << "out of range";
    }
    return octet;
}

string IpType::ipType(string ipd) {
    string type;
    int first = stringToNumber(octet(ipd, 1));

    if ( first < 128) {
        type = "Class A";
    } else if ( first < 192 ) {
        type = "class B";
    } else if ( first < 224 ) {
        type = "Class C";
    }
    return type; 
}



int IpType::stringToNumber(string number) {
    int num {0};
    int length = size(number);

    for (int i = length - 1; i >= 0; i--) {
        num += (pow(10, (length - 1) - i) * dot_number(number[i]));
    }

    return num;
}

int IpType::dot_number(char num) {
    if (num == '1') {
        return 1;
    } else if (num == '2') {
        return 2;
    } else if (num == '3') {
        return 3;
    } else if (num == '4') {
        return 4;
    } else if (num == '5') {
        return 5;
    } else if (num == '6') {
        return 6;
    } else if (num == '7') {
        return 7;
    } else if (num == '8') {
        return 8;
    } else if (num == '9') {
        return 9;
    } else if (num == 'a') {
        return 10;
    } else if (num == 'b') {
        return 11;
    } else if (num == 'c') {
        return 12;
    } else {
        return 0;
    }
}