#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {

	string s; // string 형 숫자 입력
 	int b;
	cin >> s >> b;
 	
 	int size = s.size();
	int ans = 0;
	
 	for(int i=0;i<size;i++){
 		int curInt;
 	
 		if(0 <= s[i]-'0' && s[i]-'0'<=9){
 			curInt = s[i]-'0';
		 }else{
		 	curInt = s[i]-'A' + 10;
		 }
// 		cout << curInt << "\n";
 	//	cout << curInt;
		ans = ans*b + curInt; 	
	 }
	 
	 cout << ans;
	 
	return 0;
}
