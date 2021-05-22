
// // ==> Abstract Data types: ADT is the way of classifying data structures by providing a minimal expected interface(minimal required functionality) and set of methods (operations)

// // ==> Array ADT : An Array ADT is user defined array having minimal functionality and operations and array is collection of given elements accessible by index.

// // ADT Using Class

#include <iostream>
using namespace std;
class MyArr
{
    int total_size;
    int used_size;
    int *ptr;

public:
    MyArr(MyArr *pointer_obj, int tSize, int uSize)
    {
        this->total_size = tSize;
        this->used_size = uSize;
        this->ptr = new int(tSize * sizeof(int)); //creates the array of given size e.g: tsize = 5 then size of int depends upon ths system you are using let we have 4 bytes int here then it will reserve 5*4 = 20bytes for our array.
    }

    void setValues(MyArr *pointer_obj)
    {
        for (int i = 0; i < pointer_obj->used_size; i++)
        {
            cout << "Please enter the value for element at position " << i << ":  " << endl;
            cin >> pointer_obj->ptr[i];
        }
    }
    void show(MyArr *pointer_obj)
    {
        for (int i = 0; i < pointer_obj->used_size; i++)
        {
            cout << "The Value in " << i << "th element is" << pointer_obj->ptr[i] << endl;
        }
    }
};

int main()
{
    {
        MyArr obj(&obj, 20, 5);
        cout << "Setting Values..." << endl;
        obj.setValues(&obj);
        cout << "Displaying Values..." << endl;
        obj.show(&obj);
    }

    return 0;
}

// // ADT Using Structures

#include <iostream>
using namespace std;
struct myArr
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArr *a, int tSize, int uSize)
{
    (*a).total_size = tSize;
    a->used_size = uSize;
    a->ptr = new int(tSize * sizeof(int));
}

void setValue(struct myArr *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        cout << "Please Enter the value For " << i + 1 << "th Element." << endl;
        cin >> a->ptr[i];
    }
}
void show(struct myArr *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        cout << a->ptr[i] << endl;
    }
}

int main()
{
    struct myArr test;
    cout << "Creating Array" << endl;
    createArray(&test, 20, 5);
    cout << "Set Values in array" << endl;
    setValue(&test);
    cout << "Displaying Values Values in array" << endl;
    show(&test);
    return 0;
}