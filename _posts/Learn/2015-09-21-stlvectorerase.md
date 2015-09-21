---
layout: post
title: "C++: vector容器"
categories: 编程
tags: vector STL C++
---

```

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vec_int;
    
    vec_int.push_back(0);
    vec_int.push_back(1);
    vec_int.push_back(2);
    vec_int.push_back(3);
    vec_int.push_back(4);
    vec_int.push_back(5);
    
    for (vector<int>::iterator iter = vec_int.begin(); iter!=vec_int.end();)
    {
        if (*iter == 3 || *iter == 2) {
            iter = vec_int.erase(iter);
        }
        else
        {
            iter++;
        }
    }
    
    for (vector<int>::iterator iter = vec_int.begin(); iter!=vec_int.end();iter++)
    {
        cout<<*iter<<" ";
    }
    cout<<endl;
    return 0;
}

```

执行上面代码输出结果：

```

0 1 4 5 
Program ended with exit code: 0

```

对比下面的代码

```

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vec_int;
    
    vec_int.push_back(0);
    vec_int.push_back(1);
    vec_int.push_back(2);
    vec_int.push_back(3);
    vec_int.push_back(4);
    vec_int.push_back(5);
    
    for (vector<int>::iterator iter = vec_int.begin(); iter!=vec_int.end();iter++)
    {
        if (*iter == 3 || *iter == 2)
        {
            vec_int.erase(iter);
        }
    }
    for (vector<int>::iterator iter = vec_int.begin(); iter!=vec_int.end();iter++)
    {
        cout<<*iter<<" ";
    }
    cout<<endl;
    return 0;
}

```

执行上面代码输出结果：

```

0 1 3 4 5 
Program ended with exit code: 0

```

vector的删除(erase)操作,由于vector需要能以下标方式取数据，所以必须时刻保证连续的存储空间，对应于实现上，即，当删除vector中间的一个成员时，这个成员后面的所有成员，会以原顺序向前全部拷贝过来。