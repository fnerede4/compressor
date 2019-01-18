#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string CODE[4096];

unsigned index = 256;


void insertDecoded(string decoded) {
	CODE[index] = decoded;
	index++;
}

void appendDecoded(int nextC, string & decoded) {

	if(CODE[nextC] == "")
		decoded += decoded[0];
	else {
		if(CODE[nextC] != "") {
			decoded += CODE[nextC][0];
		}
		else {
			decoded = "";
		}
	}
}

string decodeCode(int prefixC, int nextC) {

	string decoded = CODE[prefixC];

	appendDecoded(nextC,decoded);
	insertDecoded(decoded);
	return CODE[nextC];
}

int main() {

	for (int i = 0; i < 256; i++)
		CODE[i] = i;

	ofstream output("decompout.txt");

	ifstream input("compout.txt");

	int code;
	input>>code;

	output<<CODE[code];



	for(int newcode;input>>newcode;code = newcode) {

		output<<decodeCode(code,newcode);
	}

	return 0;
}



