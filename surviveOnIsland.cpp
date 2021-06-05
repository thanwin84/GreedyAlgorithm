#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include<set>
using namespace std;
void survival(int N, int S, int M) {
	int sundays = S / 7; //checking total sunday in survival days
	int needDaysToBuy = S - sundays;
	int needFood = S * M;
	int days = needFood / N; //total days need to buy the required food
	if (needFood % N != 0) days += 1;
	if (days <= needDaysToBuy) cout << "Yes" << endl;
	else {
		cout << "No";
	}
}
int main() {
	survival(16, 10, 2);
	survival(20, 10, 30);
	
	return 0;
}
