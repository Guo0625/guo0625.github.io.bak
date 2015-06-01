---
layout: post
title: "C语言点滴之extern关键字"
categories: 编程
tags: C语言点滴
---

假如a.h中有 int a=10; t1.cpp和t2.cpp同时include "a.h"则编译不成功，因为a重复定义；

如果 a.h中是 static int a=10;则可以，因为t1和t2中的a只是名字相同，地址空间不同；

如果a.h中是 extern int a; 并且在a.cpp中 int a=10; 则t1和t2中的a指向同一个地址空间。

通过如下例子学习extern：

```
//
//  test.h
//  Ctest
//
//  Created by bo li on 15-5-13.
//  Copyright (c) 2015年 zxtw. All rights reserved.
//

#ifndef Ctest_test_h
#define Ctest_test_h

extern int a;

#endif

```

```
//
//  test.c
//  Ctest
//
//  Created by bo li on 15-5-13.
//  Copyright (c) 2015年 zxtw. All rights reserved.
//

#include "test.h"

int a = 10;
```

```
//
//  foo.h
//  Ctest
//
//  Created by bo li on 15-5-13.
//  Copyright (c) 2015年 zxtw. All rights reserved.
//

#ifndef Ctest_foo_h
#define Ctest_foo_h

void print_a();

#endif
```

```
//
//  test.c
//  Ctest
//
//  Created by bo li on 15-5-13.
//  Copyright (c) 2015年 zxtw. All rights reserved.
//

#include <stdio.h>
#include "test.h"

void print_a()
{
    printf("foo a = %d\n", a);
}
```

```
//
//  foo1.h
//  Ctest
//
//  Created by bo li on 15-5-13.
//  Copyright (c) 2015年 zxtw. All rights reserved.
//

#ifndef Ctest_foo1_h
#define Ctest_foo1_h

void print_b();

#endif

```

```
//
//  foo1.c
//  Ctest
//
//  Created by bo li on 15-5-13.
//  Copyright (c) 2015年 zxtw. All rights reserved.
//

#include <stdio.h>
#include "test.h"

//extern int a;

void print_b()
{
    printf("foo1 a = %d\n", a);
}
```

```
//
//  main.c
//  Ctest
//
//  Created by bo li on 15-5-13.
//  Copyright (c) 2015年 zxtw. All rights reserved.
//

#include <stdio.h>
#include "foo.h"
#include "foo1.h"

int main(int argc, const char * argv[])
{

    // insert code here...
    
    print_a();
    print_b();
    
    return 0;
}
```

运行结果：

![6](/public/img/learn-c-extern.png)


下面是网上的[回答](http://stackoverflow.com/questions/496448/how-to-correctly-use-the-extern-keyword-in-c)

```

extern tells the compiler that this data is defined somewhere and will be connected with the linker.

With the help of the responses here and talking to a few friends here is the practical example of a use of extern.

Example 1 - to show a pitfall:

File stdio.h:

int errno;
/* other stuff...*/
myCFile1.c:
#include <stdio.h>

Code...
myCFile2.c:
#include <stdio.h>

Code...
If myCFile1.o and myCFile2.o are linked, each of the c files have separate copies of errno. This is a problem as errno is suppose to be constant over all linked files.

Example 2 - The fix.

File stdio.h:

extern int errno;
/* other stuff...*/
File stdio.c

int errno;
myCFile1.c:
#include <stdio.h>

Code...
myCFile2.c:
#include <stdio.h>

Code...
Now if both myCFile1.o and MyCFile2.o are linked by the linker they will both point to the same errno. Thus, solving the implementation with extern.
```


