#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

class JsonChecker {
	public:
		JsonChecker(string directory);
		bool isJson();
	private:
		ifstream openFile;
		vector<string> textlist;
};

JsonChecker::JsonChecker(string directory) {
	string line;
	openFile.open(directory.data());
	while (!openFile.eof()) {
		openFile >> line;
		cout << "readed line : " << line << endl;
		textlist.push_back(line);
	}
}

bool JsonChecker::isJson() {
	stack<char> pair;
	for (string line : textlist) {
		for (char c : line) {
			switch (c) {
			case '{' : 
				pair.push(c);
				break;
			case '[':
				if (pair.top() == ':') {
					pair.push(c);
				}
				break;
			case '"':
				if (pair.top() == '"') {
					pair.pop();
				}
				else {
					pair.push(c);
				}
				break;
			case ':':
				pair.push(c);
				break;
			case ',':
				if (pair.top() == ':') {
					pair.pop();
				}
				else {
					pair.push(c);
				}
				break;
			case ']':
				while (pair.top() == ',') {
					pair.pop();
				}
				if (pair.top() == '[') {
					pair.pop();
				}
				break;
			case '}':
				if (pair.top() == ':') {
					pair.pop();
				}
				if (pair.top() == '{') {
					pair.pop();
				}
				break;
			}
		}
	}
	return pair.empty();
}

int main(void) {
	JsonChecker json1("example/map1_default.json");
	if (json1.isJson()) {
		cout << "this is json file" << endl;
	}
	else {
		cout << "this is not json file" << endl;
	}
	return 0;
}