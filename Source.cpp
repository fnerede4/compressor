#include "header.h"
#include <fstream>
#include <sstream>

BST<string> bst_tree;

string readAll() {
	ifstream input("compin.txt");
    return static_cast<std::stringstream const&>(stringstream() << input.rdbuf()).str();
}

void createCompress() {
	string compin = readAll();

	ofstream output("compout.txt");

	static int length = 2;
	static int code = 256;

	while( compin.length() >= length) {

		string newtext = compin.substr(0,length);
		int location = bst_tree.searchRoot(newtext);

		if(location == -1) {
			bst_tree.addToRoot(newtext,code);
			output << bst_tree.searchRoot(compin.substr(0,length-1));

			if(bst_tree.searchRoot(compin))  {

				//output<<compin<<" ";

			}
			else {

				//length++;
			}
			output << " ";
			compin = compin.substr(length-1);
			length=2;
			code++;
		}
		else {
			length++;
		}
	}
	if(compin.length() > 0) {
		output<<bst_tree.searchRoot(compin);
	}
	output<< " ";
	output.close();
}

void fillfirst256() {

	static int code = 0;
	string key;
	key = code;
	bst_tree.addToRoot(key,code++);
}

int main() {

	int i = 0;
	while(i < 256) {
		fillfirst256();
		i++;
	}
	createCompress();

	return 0;
}