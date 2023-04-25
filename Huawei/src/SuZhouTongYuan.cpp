#include "SuZhouTongYuan.h"
#include "SuZhouTongYuan.h"

SuZhouTongYuan::SuZhouTongYuan()
{
    Do();
}

void SuZhouTongYuan::Do()
{
    cout << "Case1: TestVectorTraversor()..." << endl;
    TestVectorTraversor();

    cout << "Case2: TestGetMemory()..." << endl;
    TestGetMemory();

    cout << "Case3: TestTheShapeClass()..." << endl;
    TestTheShapeClass();

    //cout << "Case4-A: TestCombineAlgorithm()..." << endl;
    //TestCombineAlgorithm();

    cout << "Case4-B: TestArrayAlgorithm()..." << endl;
    TestArrayAlgorithm();
}

void SuZhouTongYuan::TestVectorTraversor()
{
    vector<int> array;
    array.push_back(1);
    array.push_back(2);
    array.push_back(3);
    /* //原始
    for(unsigned int i=array.size()-1; i>=0; --i)
    {
        cout << array[i] << endl;
    }*/
    //修改
    //原因：当i=0，--i操作将导致其变为UINT_MAX，从而导致程序出错。
    for (unsigned int i = 0; i < array.size(); ++i)
    {
        cout << array[i] << endl;
    }
}
//////////////////////////////////////////////////////////////////////////
// (2) 改错题
//////////////////////////////////////////////////////////////////////////
/*
void Get100Memory(char *p)
{
    p = new char[100];
}

void TestGetMemory()
{
    char *str = NULL;
    Get100Memory(str);
    strcpy(str,"hello world");
    cout << str;
}
*/
//要给指针p分配内存原始函数只是给指针p的副本分配了内存，要给str分配内存直接传参指针p的地址分配内存
//通过传参来分配内存的时候要注意什么
void SuZhouTongYuan::Get100Memory(char*& p)
{
    p = new char[100];
}

void SuZhouTongYuan::TestGetMemory()
{
    char* str = NULL;
    Get100Memory(str);
    if (str != NULL) 
    {
        //strcpy(str, "hello world");
        strncpy_s(str, sizeof(str), "hello world", _TRUNCATE);

        //size_t len = strlen(str);
        //strncpy(str, "hello world!",len);
        cout << str << endl; //添加回车换行
        delete[] str; // 释放内存
    }
}

void PrintShape(Shape* shape)
{
    cout << "name: " << shape->getName() << endl;
}

void SuZhouTongYuan::TestTheShapeClass()
{
    /*
    vector<Shape> shapes;
    shapes.push_back(Shape("1", "Rect: "));
    shapes.push_back(Shape("2", "Circle: "));*/

    //所以当我们向vector添加元素时，它们被复制为vector中的新对象。而且，在此之后修改原始对象不会影响复制品。
    //因此，这将导致在运行PrintShape函数时出现歧义，因为它需要 'Shape*' 类型的参数，但实际上传递了 'Shape' 对象的地址。
    //所以在这里，需要使用指向 'Shape' 类对象的指针进行适当的更改方式。
    vector<Shape*> shapes;
    shapes.push_back(new Shape("1", "Rect: "));
    shapes.push_back(new Shape("2", "Circle: "));

    for (size_t i = 0; i < shapes.size(); ++i)
    {
        //PrintShape(&shapes[i]);
        PrintShape(shapes[i]);  //本身就已经是指针的形式
    }

    //新加释放内存
    for (size_t i = 0; i < shapes.size(); ++i)
    {
        //delete &shapes[i];
        delete[] shapes[i];  //同上释放动态分配的内存
    }

    shapes.clear();
}
void SuZhouTongYuan::CreateInputDataB(vector<int>& input)
{
    // 可以调整此函数代码，创建不同的输入数据来测试

    //Test1：构造二维数组

    input.clear();
    input.push_back(2);
    input.push_back(3);


    //Test2: 构造三维数组
    /*
    input.clear();
    input.push_back(3);
    input.push_back(2);
    input.push_back(3);
    input.push_back(5);
    */

    //Test3：在此构造N维数组，进行测试
    //...
}

//递归函数
void SuZhouTongYuan::printArray(const string& array_name, const vector<int>& input, vector<int>& indexes, int currDim)
{
    if (currDim == input.size())
    { // 输出完毕
        cout << array_name << "[";
        int flag = 0;
        for (int i = 0; i < input.size(); ++i)
        { // 输出下标对应元素值
            cout << indexes[i];
            if (i != input.size() - 1)
            {
                cout << "][";
            }
            flag = i;
        }
        cout << "],";
    }
    else
    {
        for (int i = 0; i < input[currDim]; ++i)
        { // 循环当前维度的大小
            indexes[currDim] = i; // 设置当前维度的下标
            printArray(array_name, input, indexes, currDim + 1); // 递归到下一维
        }
        //cout << endl;  //每循环一维换行
    }
}

void SuZhouTongYuan::PrintArray(const std::string& array_name, const vector<int>& input)
{
    //此处答题：
    vector<int> indexes(input.size(), 0);
    cout << "该数组所有分量为：" << endl;
    printArray(array_name, input, indexes, indexes[0]);
}
//
void SuZhouTongYuan::TestArrayAlgorithm()
{
    vector<int> input;
    CreateInputDataB(input);

    std::string array_name = "A";
    PrintArray(array_name, input);
}

Shape::Shape(const char* id, const char* name)
{
    //shapeName = new char[strlen(name) + strlen(id)];
    shapeName = new char[strlen(name) + strlen(id) + 1];  // 加一个字节用于保存字符串结束符\0
    //strcpy(shapeName, name);
    strncpy_s(shapeName, sizeof(shapeName), name, _TRUNCATE);

    //strcpy(shapeName + strlen(name), id);
    strncpy_s(shapeName + strlen(name), sizeof(shapeName + strlen(name)), id, _TRUNCATE);

}
