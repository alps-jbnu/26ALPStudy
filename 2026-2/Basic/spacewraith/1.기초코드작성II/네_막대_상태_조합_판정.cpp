#include <iostream>

using namespace std;

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for(int i = 0; i < 3; i++) {
		int n;
		int o_count = 0;

		for(int j = 0; j < 4; j++) {
			cin >> n;
			
			if(n == 0)	
				o_count++;
		}	


		if(o_count >= 1 && o_count <= 4) {
			cout << static_cast<char>('A' + o_count - 1) << '\n';
		} else if(o_count == 0) {
			cout << 'E' << '\n';
		}
	}

	return 0;
}
