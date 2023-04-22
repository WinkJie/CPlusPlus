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
    /* //ԭʼ
    for(unsigned int i=array.size()-1; i>=0; --i)
    {
        cout << array[i] << endl;
    }*/
    //�޸�
    //ԭ�򣺵�i=0��--i�������������ΪUINT_MAX���Ӷ����³������
    for (unsigned int i = 0; i < array.size(); ++i)
    {
        cout << array[i] << endl;
    }
}
//////////////////////////////////////////////////////////////////////////
// (2) �Ĵ���
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
//Ҫ��ָ��p�����ڴ�ԭʼ����ֻ�Ǹ�ָ��p�ĸ����������ڴ棬Ҫ��str�����ڴ�ֱ�Ӵ���ָ��p�ĵ�ַ�����ڴ�
//ͨ�������������ڴ��ʱ��Ҫע��ʲô
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
        cout << str << endl; //��ӻس�����
        delete[] str; // �ͷ��ڴ�
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

    //���Ե�������vector���Ԫ��ʱ�����Ǳ�����Ϊvector�е��¶��󡣶��ң��ڴ�֮���޸�ԭʼ���󲻻�Ӱ�츴��Ʒ��
    //��ˣ��⽫����������PrintShape����ʱ�������壬��Ϊ����Ҫ 'Shape*' ���͵Ĳ�������ʵ���ϴ����� 'Shape' ����ĵ�ַ��
    //�����������Ҫʹ��ָ�� 'Shape' ������ָ������ʵ��ĸ��ķ�ʽ��
    vector<Shape*> shapes;
    shapes.push_back(new Shape("1", "Rect: "));
    shapes.push_back(new Shape("2", "Circle: "));

    for (size_t i = 0; i < shapes.size(); ++i)
    {
        //PrintShape(&shapes[i]);
        PrintShape(shapes[i]);  //������Ѿ���ָ�����ʽ
    }

    //�¼��ͷ��ڴ�
    for (size_t i = 0; i < shapes.size(); ++i)
    {
        //delete &shapes[i];
        delete[] shapes[i];  //ͬ���ͷŶ�̬������ڴ�
    }

    shapes.clear();
}
void SuZhouTongYuan::CreateInputDataB(vector<int>& input)
{
    // ���Ե����˺������룬������ͬ����������������

    //Test1�������ά����

    input.clear();
    input.push_back(2);
    input.push_back(3);


    //Test2: ������ά����
    /*
    input.clear();
    input.push_back(3);
    input.push_back(2);
    input.push_back(3);
    input.push_back(5);
    */

    //Test3���ڴ˹���Nά���飬���в���
    //...
}

//�ݹ麯��
void SuZhouTongYuan::printArray(const string& array_name, const vector<int>& input, vector<int>& indexes, int currDim)
{
    if (currDim == input.size())
    { // ������
        cout << array_name << "[";
        int flag = 0;
        for (int i = 0; i < input.size(); ++i)
        { // ����±��ӦԪ��ֵ
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
        { // ѭ����ǰά�ȵĴ�С
            indexes[currDim] = i; // ���õ�ǰά�ȵ��±�
            printArray(array_name, input, indexes, currDim + 1); // �ݹ鵽��һά
        }
        //cout << endl;  //ÿѭ��һά����
    }
}

void SuZhouTongYuan::PrintArray(const std::string& array_name, const vector<int>& input)
{
    //�˴����⣺
    vector<int> indexes(input.size(), 0);
    cout << "���������з���Ϊ��" << endl;
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
    shapeName = new char[strlen(name) + strlen(id) + 1];  // ��һ���ֽ����ڱ����ַ���������\0
    //strcpy(shapeName, name);
    strncpy_s(shapeName, sizeof(shapeName), name, _TRUNCATE);

    //strcpy(shapeName + strlen(name), id);
    strncpy_s(shapeName + strlen(name), sizeof(shapeName + strlen(name)), id, _TRUNCATE);

}
