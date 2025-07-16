#include <bits/stdc++.h>
#include "prisonlib.h"
using namespace std;


int play(int i) {
	int cur = i;
	while(1) {
		int x = watch(cur);
		if (x == i) {
			return cur;
		}
		cur = x;
	}
}
