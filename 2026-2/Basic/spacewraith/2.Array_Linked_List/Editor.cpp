#include <iostream>
#include <list>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	list<char> editor;
	string init_str;

	cin >> init_str;
	for(char c : init_str) {
		editor.push_back(c);
	}

	int M;
	cin >> M;

	auto cursor = editor.end();
	while(M--) {
		char cmd;

		cin >> cmd;

		if(cmd == 'L') {
			if(cursor != editor.begin()){
				cursor--;
			}
		} else if(cmd == 'D') {
			if(cursor != editor.end()){
				cursor++;
			}
		} else if(cmd == 'B') {
			if(cursor != editor.begin()) {
				cursor--;
				cursor = editor.erase(cursor);
			}
		} else if(cmd == 'P') {
			char c;

			cin >> c;
			editor.insert(cursor, c);	
		}
	}
	
	for(char c : editor){
		cout << c;
	}
	
	cout << '\n';
}
