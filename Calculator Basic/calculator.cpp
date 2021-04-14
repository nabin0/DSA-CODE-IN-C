#include <iostream>
#include <cmath>
using namespace std;

class SimpleCalculator
{
private:
    float num1, num2;
    char op;
    friend void runSimpleCalc(SimpleCalculator obj);

public:
    SimpleCalculator(char op)
    {
        this->op = op;
    }
    void set_data();
    float sum();
    float sub();
    float mult();
    float div();
};
void SimpleCalculator ::set_data()
{
    cout << "Please enter the value of first number: " << endl;
    cin >> num1;
    cout << "Please enter the value of second number: " << endl;
    cin >> num2;
}
float SimpleCalculator ::sum()
{   
    cout<<"The Sum is: ";
    return (num1 + num2);
}
float SimpleCalculator ::sub()
{
    cout<<"The Difference is: ";
    return (num1 - num2);
}
float SimpleCalculator ::mult()
{
    cout<<"The Multiplication is: ";
    return (num1 * num2);
}
float SimpleCalculator ::div()
{
    cout<<"The Division is: ";
    return (num1 / num2);
}

class SciCalculator
{
private:
    char op;
    double num;

public:
    SciCalculator(char op)
    {
        this->op = op;
    }
    void setData();
    void funcHandler();
};

void SciCalculator ::setData()
{
    cout << "Please enter the number: " << endl;
    cin >> num;
}
void SciCalculator::funcHandler()
{
    if (op == '1')
    {
        cout <<"The Sine Value is: "<< (sin(num));
    }
    else if (op == '2')
    {
        cout <<"The Cos Value is: "<< cos(num)<<endl;
    }
    else if (op == '3')
    {
        cout <<"The Tan Value is: "<< tan(num)<<endl;
    }
    else if (op == '4')
    {
        float sqt = sqrt(num);
        cout <<"The Square Root is: "<< sqt<<endl;
    }
    else if (op == '5')
    {
        cout <<"The Square is: "<< (num * num)<<endl;
    }
    else if (op == '6')
    {
        cout <<"The Cube is: "<< (num * num * num)<<endl;
    }
    else if (op == '7')
    {
        cout <<"The Log value is: "<< log(num)<<endl;
    }
}

void runSimpleCalc(SimpleCalculator obj)
{
    switch (obj.op)
    {
    case '+':
        cout << obj.sum() << endl;
        break;
    case '-':
        cout << obj.sub() << endl;
        break;
    case '*':
        cout << obj.mult() << endl;
        break;
    case '/':
        cout << obj.div() << endl;
        break;

    default:
        break;
    }
}

int main()
{

    cout <<endl<< "*****************CALCULATOR**************" << endl<<endl;
    while (true)
    {
        cout << "Choose The Operation You Want To Perform:" << endl
             << "       '+' : For Addition"<<endl
             << "       '-' : For Addition"<<endl
             << "       '*' : For Addition"<<endl
             << "       '/' : For Addition"<<endl
             << "       '1' : For Sine Operation"<<endl
             << "       '2' : For Cos Operation"<<endl
             << "       '3' : For Tan Operation"<<endl
             << "       '4' : For Square Root "<<endl
             << "       '5' : For Square Of a Number"<<endl
             << "       '6' : For Cube Of a Number"<<endl
             << "       '7' : For log Value Of a Number"<<endl;
        char op;
        cin >> op;
        char sciArr[] = {'1', '2', '3', '4', '5', '6', '7'};
        char simpleArr[] = {'+', '-', '*', '/'};

        for (int i = 0; i < (sizeof(sciArr) / sizeof(sciArr[0])); i++)
        {
            if (op == sciArr[i])
            {
                SciCalculator obj(op);
                obj.setData();
                obj.funcHandler();
            }

            else if (op == simpleArr[i])
            {
                SimpleCalculator ob1(op);
                ob1.set_data();
                runSimpleCalc(ob1);
            }
        }
        cout << "Enter q to quit or c to continue: " << endl;
        char cmd;
        cin >> cmd;
        if (cmd == 'q')
        {
            break;
        }
        else if (cmd == 'c')
        {
            continue;
        }
        else
        {
            cout << "your Input is wrong Please try Putting correct input." << endl;
        }
    }
    return 0;
}