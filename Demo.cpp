#include <bits/stdc++.h>
#include "MegerSortTemplate.h"

using namespace std;

class Wraper {
public:
    Wraper() : val(0) {}
    explicit Wraper(int i) : val(i) {}
    Wraper(const Wraper& another) : val(another.val) {}
    Wraper(Wraper&& another) : val(another.val) {another.val = 0;}
    Wraper& operator= (const Wraper& another) {
        val = another.val;
        return *this;
    }
    Wraper& operator= (Wraper&& another) {
        val = another.val;
        another.val = 0;
        return *this;
    }
    bool operator< (const Wraper& another) {
        return val < another.val;
    }
    friend istream& operator>> (istream& input, Wraper& item) {
        input >> item.val;
        return input;
    }
    friend ostream& operator<< (ostream& output, Wraper& item) {
        output << item.val;
        return output;
    }
private:
    int val;
};

void FirstSegCallback(MergeSort<Wraper>::CallbackInfomation& info, const vector<Wraper>& arr) {
    cout << "Sorting from " << info.firstSegStart << " to " << info.secondSegEnd <<
            " by merge 2 segments: (From " << info.firstSegStart << " to " << info.firstSegEnd <<
            ") And (From " << info.secondSegStart << " to " << info.secondSegEnd << "). Pushing element with index " <<
            info.firstSegIndex << " to result\n";

}

void SecSegCallback(MergeSort<Wraper>::CallbackInfomation& info, const vector<Wraper>& arr) {
    cout << "Sorting from " << info.firstSegStart << " to " << info.secondSegEnd <<
            " by merge 2 segments: (From " << info.firstSegStart << " to " << info.firstSegEnd <<
            ") And (From " << info.secondSegStart << " to " << info.secondSegEnd << "). Pushing element with index " <<
            info.secondSegIndex << " to result\n";
}

int main()
{
    size_t len = 0U; cin >> len;
    MergeSort<Wraper> obj;
    obj.SetFirstSegItemMergeCallback(FirstSegCallback);
    obj.SetSecSegItemMergeCallback(SecSegCallback);
    for(size_t i = 0U; i < len; ++i) {
        Wraper n; cin >> n;
        obj.push_back(n);
    }
    obj.Sort();
    for(size_t i = 0U; i < len; ++i) {
        cout << obj.Get(i) << " ";
    }
	cout << "\n"
}