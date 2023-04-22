#include "DailyBase.h"


DailyBase::DailyBase()
{
}

DailyBase::~DailyBase()
{
}

void DailyBase::opOne(vector<int>& op)
{
    ops.clear();
    if (op.size() > 0)
    {
        cout << "op为：" << endl;
        for (int i=0;i<op.size();i++)
        {
            ops.push_back(op[i]);
            cout << ops[i] << "       " << endl;
        }            
    }
}
range DailyBase::MaxSum(int a[], range e)
{
    range d = e;
    int i;
    range left = e, right = e;
    int sum = 0, rsum = 0, lsum = 0;
    if (e.x == e.y)
    {
        e.sum = a[e.x];
        return e;
    }
    else
    {
        left.y = (e.x + e.y) / 2;
        right.x = left.y + 1;
        left = MaxSum(a, left);
        right = MaxSum(a, right);
        int s1 = 0;
        for (i = left.x; i <= left.y; i++)
        {
            lsum += a[i];
            if (s1 < lsum)
                s1 = lsum;
        }
        int s2 = 0;
        for (i = right.x; i <= right.y; i++)
        {
            rsum += a[i];
            if (s2 < rsum)
                s2 = rsum;
        }
        int midsum = s1 + s2;
        if (midsum < lsum) {
            sum = lsum;
            d = left;
            d.sum = sum;
        }
        else {
            sum = midsum;
            d = e;
            d.sum = sum;
        }
        if (sum < rsum) {
            sum = rsum;
            d = right;
            d.sum = sum;
        }
        cout << d.sum << d.x << " " << d.y << endl;
        return d;
    }
}
void DailyBase::begin4()
{
    int N, i;
    cout << "请输入序列大小 ：\n";
    cin >> N;
    int a[100];
    for (i = 0; i < N; i++)
        cin >> a[i];
    range zhi;
    zhi.x = 0;
    zhi.y = N - 1;
    range Max = DailyBase::MaxSum(a, zhi);
    int sum = 0;
    for (i = Max.x; i <= Max.y; i++)
    {
        cout << a[i] << " ";
        sum += a[i];
    }
    cout << sum << endl;
    return;
}

