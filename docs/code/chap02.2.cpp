#include <iostream>
#include <vector>

using namespace std;

static int m = 0;
static int pinum = 1;

//check v[v[i]] ==i，if true, output v
void checkdualpermutation(vector<int> & v) {
    for (size_t i = 1; i < v.size(); i++)
    {
        if (v[v[i]] != i)
        {
            return;
        }
    }
    if (v.size() - 1 != m)
    {
        m = v.size() - 1;
        pinum = 1;
    }
    cout<<"pi"<<pinum++<<':';

    for (size_t i = 1; i <= m; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void creatpremutation(vector<int> & v, int l) {
    //排列生成完成，检查是否满足条件
    if (l == v.size())
    {
        checkdualpermutation(v);
    }
    
    for (size_t i = l; i < v.size(); i++)
    {
        swap(v[l], v[i]);
        creatpremutation(v, l+1);
        swap(v[l], v[i]);
    }
}

int main() {

    //m from 2 to 6
    for (size_t i = 2; i < 7; i++)
    {
        //构建vector
        vector<int> v;

        for (int j = 0; j <= i; j++)
        {
            v.push_back(j);
        }

        cout<<"x: ";

        //输出vector
        for (size_t j = 1; j < v.size(); j++)
        {
            cout << v[j] << " ";
        }
        cout<<endl;
        creatpremutation(v,1);
        
    }
    
}