#include <bits/stdc++.h>
#include "prisonlib.h"

int play(int i) {
	int cur = i;
	for(int xx = 1; xx <= 64; xx++) {
		int x = watch(cur);
		if (x == i) return cur;
		cur = x;
	}
	return 1;
}
