#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::ostream;
class Packet {
private:
	int length;
	string message;
public:
	Packet(int mLength=0, string m="") {
		length = mLength;
		for (int i = 0; i < mLength; i++) {
			message[i] = m[i];
		}
	}
	friend ostream &operator<<(ostream &lhs, const Packet &rhs);
};
ostream &operator<<(ostream &lhs, const Packet &rhs) {
	lhs << "Packet length of: " << rhs.length << " | Packet message: "<<rhs.message << std::endl;
}