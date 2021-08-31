const int nax = 100005;
int bit[nax];
// array is 0 indexed so i++ ( bit is always 1 indexed)
void upd(int i, int x) {
	i++;
	for (int j = i; j <= nax; j += (j & -j)) {
		bit[j] += x;
	}
}
int sum(int i) {
	i++;
	int res = 0;
	for (int j = i; j > 0; j -= (j & -j)) {
		res += bit[j];
	}
	return res;
}