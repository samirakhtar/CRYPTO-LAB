#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main() {
    string message = "The quick brown fox jumps over the lazy dog";
    int messageLength = message.length() * 8; // length of message in bits
    int paddingLength = (448 - (messageLength + 1) % 512) % 512; // length of padding in bits
    int paddedLength = messageLength + 1 + paddingLength + 64; // length of padded message in bits

    // create padded message as a bitset
    bitset<512> paddedMessage;
    for (int i = 0; i < messageLength; i++) {
        if (message[i/8] & (1 << (i%8))) {
            paddedMessage.set(i);
        }
    }
    paddedMessage.set(messageLength);

    // add padding bits
    for (int i = messageLength + 1; i < paddedLength - 64; i++) {
        paddedMessage.set(i, 0);
    }

    // add length of original message
    for (int i = 0; i < 64; i++) {
        paddedMessage.set(paddedLength - 64 + i, (messageLength >> (i*8)) & 0xff);
    }

    cout << "Original message: " << message << endl;
    cout << "Padded message: ";
    for (int i = 0; i < paddedLength; i++) {
        cout << paddedMessage[i];
    }
    cout << endl;

    return 0;
}

