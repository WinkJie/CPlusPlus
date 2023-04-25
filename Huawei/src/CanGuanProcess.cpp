#include "CanGuanProcess.h"



int CanGuanProcess::Do()
{
   
    int n, m;//n是桌子数，m是批次
    cin >> n >> m;
    vector<int>n_num;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        n_num.push_back(x);
    }
    vector<node>m_num;
    for (int i = 0; i < m; i++)
    {
        int x1, x2;
        cin >> x1 >> x2;
        node temp;
        temp.x = x1;
        temp.y = x2;
        m_num.push_back(temp);
    }
    CanGuanProcess r;
    cout << r.maxprofit(n_num, m_num) << endl;
    //system("pause");
    return 0;
}


bool CanGuanProcess::mycomp(node a, node b)
{
    if (a.y == b.y)
        return a.x - b.x < 0;
    return a.y - b.y > 0;
}

long long CanGuanProcess::maxprofit(vector<int> n_num, vector<node> m_num)
{
    long long profit = 0;
    sort(m_num.begin(), m_num.end(), &mycomp);
    sort(n_num.begin(), n_num.end());
    for (int i = 0; i < m_num.size(); i++)
    {
        vector<int>::iterator it = n_num.begin();
        while (it != n_num.end())
        {
            if (*it >= m_num[i].x)
                break;
            it++;
        }
        if (it != n_num.end())
        {
            n_num.erase(it);
            profit = profit + m_num[i].y;
        }
    }
    return profit;
}

void CanGuanProcess::vec()
{
    global.clear();
    for (int i = 0; i < 6; i++)
    {
        global.push_back(i);
    }
}
