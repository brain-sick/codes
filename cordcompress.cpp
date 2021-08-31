void compress(vector<int> &a) {
    vector<pair<int, int>> v;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        v.push_back({a[i], i});
    }
    sort(v.begin(), v.end(), [](const pii & a, const pii & b) {
        return a.first < b.first;
    });
    a[v[0].second] = 1;
    for (int i = 1; i < n; i++) {
        if (v[i - 1].first == v[i].first)
            a[v[i].second] = a[v[i - 1].second];
        else
            a[v[i].second] = a[v[i - 1].second] + 1;
    }
}