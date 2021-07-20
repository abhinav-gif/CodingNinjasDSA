#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

class Polynomial
{
    int *degreeCoeff;
    int capacity;

public:
    Polynomial()
    {
        capacity = 1;
        for (int i = 0; i < capacity; i++)
        {
            degreeCoeff[i] = 0;
        }
    }
    Polynomial(Polynomial const &p)
    {
        this->capacity = p.capacity;
        int *newP = new int[p.capacity];
        for (int i = 0; i < p.capacity; i++)
        {
            newP[i] = degreeCoeff[i];
        }
        this->degreeCoeff = newP;
    }
    void operator=(Polynomial const &p)
    {
        this->capacity = p.capacity;
        int *newP = new int[p.capacity];
        for (int i = 0; i < p.capacity; i++)
        {
            newP[i] = degreeCoeff[i];
        }
        this->degreeCoeff = newP;
    }

    void setCoeff(int *pDegree, int *pCoeff, int pSize)
    {
        int max = INT_MIN;
        for (int i = 0; i < pSize; i++)
        {
            if (max < pDegree[i])
            {
                max = pDegree[i];
            }
        }

        while (max >= capacity)
        {
            capacity = 2 * capacity;
        }
        degreeCoeff = new int[capacity];

        for (int i = 0; i < capacity; i++)
        {
            degreeCoeff[i] = 0;
        }

        for (int i = 0; i < pSize; i++)
        {
            degreeCoeff[pDegree[i]] = pCoeff[i];
        }
    }
    Polynomial operator+(Polynomial const &p)
    {
        int max1 = max(p.capacity, this->capacity);
        int *newDegCoeff = new int[max1];
        for (int i = 0; i < capacity; i++)
        {
            newDegCoeff[i] = 0;
        }
        for (int i = 0; i < max1; i++)
        {
            newDegCoeff[i] = this->degreeCoeff[i] + p.degreeCoeff[i];
        }
        Polynomial newP;
        newP.degreeCoeff = newDegCoeff;
        return newP;
    }
    Polynomial operator-(Polynomial const &p)
    {
        int max1 = max(p.capacity, this->capacity);
        int *newDegCoeff = new int[max1];
        for (int i = 0; i < capacity; i++)
        {
            newDegCoeff[i] = 0;
        }
        for (int i = 0; i < max1; i++)
        {
            newDegCoeff[i] = this->degreeCoeff[i] - p.degreeCoeff[i];
        }
        Polynomial newP;
        newP.degreeCoeff = newDegCoeff;
        return newP;
    }
    void print()
    {
        for (int i = 0; i < capacity; i++)
        {
            if (degreeCoeff[i] != 0)
            {
                cout << degreeCoeff[i] << "x" << i << " ";
            }
        }
        cout << endl;
    }
    int *getDegCoeff()
    {
        return degreeCoeff;
    }
};

int main()
{
    int n;
    cin >> n;
    int *p1Degree = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p1Degree[i];
    }
    int *p1Coef = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p1Coef[i];
    }
    int m;
    cin >> m;
    int *p2Degree = new int[m];
    for (int i = 0; i < n; i++)
    {
        cin >> p2Degree[i];
    }
    int *p2Coef = new int[m];
    for (int i = 0; i < m; i++)
    {
        cin >> p2Coef[i];
    }
    Polynomial first;
    first.setCoeff(p1Degree, p1Coef, n);
    Polynomial second;
    second.setCoeff(p2Degree, p2Coef, m);
    
    int choice;
    cin >> choice;

    switch (choice)
    {
        // Add
    case 1:
    {
        Polynomial result1 = first + second;
        result1.print();
        break;
    }
        // Subtract
    case 2:
    {
        Polynomial result2 = first - second;
        result2.print();
        break;
    }
        // Multiply
    // case 3:
    // {
    //     Polynomial result3 = first * second;
    //     result3.print();
    //     break;
    // }
    case 4: // Copy constructor
    {
        Polynomial third(first);
        if (third.getDegCoeff() == first.getDegCoeff())
        {
            cout << "false" << endl;
        }
        else
        {
            cout << "true" << endl;
        }
        break;
    }

    case 5: // Copy assignment operator
    {
        Polynomial fourth(first);
        if (fourth.getDegCoeff() == first.getDegCoeff())
        {
            cout << "false" << endl;
        }
        else
        {
            cout << "true" << endl;
        }
        break;
    }
    }
}