#include <bits/stdc++.h>
using namespace std;

template <typename T, typename cmp = less<T&>>
class MergeSort {
public:
    struct CallbackInfomation {
        size_t firstSegIndex;
        size_t secondSegIndex;
        size_t firstSegStart;
        size_t firstSegEnd;
        size_t secondSegStart;
        size_t secondSegEnd;
        CallbackInfomation(size_t fsi, size_t ssi, size_t fss, size_t fse, size_t sss, size_t sse) :
            firstSegIndex(fsi), secondSegIndex(ssi), firstSegStart(fss), firstSegEnd(fse), secondSegStart(sss), secondSegEnd(sse) {}
    };
    typedef void (*MergeCallback)(CallbackInfomation&, const vector<T>&);
    MergeSort() : arr(new vector<T>()) {
        before_merge_first_segment_item = MergeSort::DoNothing;
        before_merge_second_segment_item = MergeSort::DoNothing;
    }
    explicit MergeSort(const vector<T> &orgArr, MergeCallback firstSegItemMerge = MergeSort::DoNothing, MergeCallback secondSegItemMerge = MergeSort::DoNothing) : arr(new vector<T>()) {
        size_t len = arr->size();
        for(size_t i = 0U; i < len; ++i) {
            arr->push_back(orgArr[i]);
        }
        before_merge_first_segment_item = firstSegItemMerge;
        before_merge_second_segment_item = secondSegItemMerge;
    }

    MergeSort(const MergeSort& another) = delete ;
    MergeSort(MergeSort&& another) = delete ;
    MergeSort& operator= (const MergeSort& another) = delete ;
    MergeSort& operator= (MergeSort&& another) = delete ;

    virtual ~MergeSort() {
        if(arr != NULL) {
            delete arr;
        }
    }

    void Sort() {
        if(arr->size() > 0) {
            _SortUtil(0U, arr->size() - 1U);
        }
    }

    void SetFirstSegItemMergeCallback(MergeCallback func) { before_merge_first_segment_item = func; }
    void SetSecSegItemMergeCallback(MergeCallback func) { before_merge_second_segment_item = func; }
    void push_back(const T& item) { arr->push_back(item); }
    T& operator[] (const size_t index) { return (*arr)[index]; }
    T& Get(const size_t index) { return (*arr)[index]; }
    size_t size() const { return arr->size();}

private:
    vector<T> *arr;
    MergeCallback before_merge_second_segment_item;
    MergeCallback before_merge_first_segment_item;
    cmp compare;

    static void DoNothing(CallbackInfomation &info, const vector<T>& arr) {}

    void _SortUtil(size_t start, size_t end) {
        if(start == end) {
            return;
        }
        size_t endOfFirst = start + (end - start) / 2U;
        size_t startOfSec = endOfFirst + 1U;
        _SortUtil(start, endOfFirst);
        _SortUtil(startOfSec, end);
        vector<T> temp;
        size_t fi = start, si = startOfSec, ti = 0U;
        while(fi <= endOfFirst || si <= end) {
            if(si > end || (fi <= endOfFirst && compare((*arr)[fi], (*arr)[si]) == true)) {
                CallbackInfomation info(fi, si, start, endOfFirst, startOfSec, end);
                before_merge_first_segment_item(info , *arr);
                temp.push_back((*arr)[fi]);
                fi++;
            } else {
                CallbackInfomation info(fi, si, start, endOfFirst, startOfSec, end);
                before_merge_second_segment_item(info, *arr);
                temp.push_back((*arr)[si]);
                si++;
            }
        }
        size_t tempLen = temp.size();
        for(size_t i = 0; i < tempLen; ++i) {
            (*arr)[i+start] = temp[i];
        }
    }
};

















