#include <iostream>
#include <list>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		string log;
		list<char> editor;
		auto cursor = editor.begin();

		cin >> log;
		
		for(char c : log) {
			if(c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9') {
				editor.insert(cursor, c);
			} else if(c == '<') {
				if(cursor != editor.begin()) {
					cursor--;
				}
			} else if(c == '>') {
				if(cursor != editor.end()) {
					cursor++;
				}
			} else if(c == '-') {
				if(cursor != editor.begin()) {
					cursor--;
					cursor = editor.erase(cursor);
				}
			}
		}

		for(char c : editor)
			cout << c;
		cout << '\n';

	}
}

