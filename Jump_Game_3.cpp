class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int N = arr.size();
        vector<int> tab(N, 0);
        return help(arr, start, tab, N);
    }
    bool help(vector<int>& arr, int start, vector<int>& tab, int N) {
        if ((start < 0 || start > N - 1) || tab[start] == 1) {
            return false;
        }
        if (arr[start] == 0) {
            return true;
        }
        tab[start] = 1;
        if (help(arr, start-arr[start], tab, N)) {
            return true;
        }
        if (help(arr, start+arr[start], tab, N)) {
            return true;
        }
        return false;
    }
};
