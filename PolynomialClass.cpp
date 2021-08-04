#include<iostream>

using namespace std;

class Polynomial {
    public:
    int * degCoeff; // Name of your array (Don't change this)
	int capacity;
    
    
    Polynomial(){
        this->degCoeff = new int[10];
        this->capacity=10;
         for (int i = 0; i < 10; i++) {
            degCoeff[i] = 0;
        }
    }
    
    Polynomial(const Polynomial& p){
        
        this->capacity = p.capacity;
        this->degCoeff = new int[p.capacity];
        for(int i=0;i<p.capacity;i++)
        	this->degCoeff[i] = p.degCoeff[i];
    }
    
    void setCoefficient(int deg, int coeff){
        if(this->capacity<=deg){
            int *newDegCoeff = new int[deg+10];
            for (int i = 0; i < deg+10; i++) {
                newDegCoeff[i] = 0;
            }
            for(int i=0;i<this->capacity;i++){
                newDegCoeff[i] = this->degCoeff[i];
            }
            this->capacity = deg+10;
            delete [] this->degCoeff;
            this->degCoeff = newDegCoeff;            
        }       
    
        this->degCoeff[deg] = coeff;
    }
    
    Polynomial operator + (Polynomial p2){
        Polynomial result;
        
        int i=0,j=0;
        while(i<this->capacity || i<p2.capacity){
            int deg = i;
            int coeff1=0,coeff2=0;
            if(i<this->capacity)
                coeff1=this -> degCoeff[i];
            if(i<p2.capacity)
                coeff2= p2.degCoeff[i];
            int coeff =  coeff1 + coeff2;
            result.setCoefficient(deg, coeff);
            i++;
            
        }
        
        return result;
    }
    
    Polynomial operator - (Polynomial p2){
         Polynomial result;
        int i=0,j=0;
        while(i<this->capacity || j<p2.capacity){
            int deg = i;
            int coeff1=0,coeff2=0;
            if(i<this->capacity)
                coeff1=this -> degCoeff[i];
            if(j<p2.capacity)
                coeff2= p2.degCoeff[j];
            int coeff =  coeff1 - coeff2;
            result.setCoefficient(deg, coeff);
            i++;
            j++;
        }
        return result;
    }
    int getCoeff(int degree) {
        if (degree >= this->capacity) {
            return 0;
        }
        return this->degCoeff[degree];
    }
    Polynomial operator * (Polynomial p2){
        Polynomial result;
        
        for(int i=0;i<this->capacity;i++){
            for(int j=0;j<p2.capacity;j++){
                int deg = i+j;
                int coeff = result.getCoeff(deg) + this->degCoeff[i] * p2.degCoeff[j];
                result.setCoefficient(deg,coeff);
            }
        }
        return result;
    }
    
    Polynomial& operator = (const Polynomial& p2){
        
        this->capacity = p2.capacity;
		this->degCoeff = new int[p2.capacity];
        for(int i=0;i<p2.capacity;i++)
        	this->degCoeff[i] = p2.degCoeff[i];
        return *this;
    }
    
    void print(){
        if(this->capacity==0)
            return;
        for(int i=0;i<this->capacity;i++){
            if(this->degCoeff[i]!=0)
                cout<<this->degCoeff[i]<<"x"<<i<<" ";
        }
    }
    

};

int main() {
    int count1, count2, choice;
    cin >> count1;

    int * degree1 = new int[count1];
    int * coeff1 = new int[count1];

    for (int i = 0; i < count1; i++) {
        cin >> degree1[i];
    }

    for (int i = 0; i < count1; i++) {
        cin >> coeff1[i];
    }

    Polynomial first;
    for (int i = 0; i < count1; i++) {
        first.setCoefficient(degree1[i], coeff1[i]);
    }

    cin >> count2;

    int * degree2 = new int[count2];
    int * coeff2 = new int[count2];

    for (int i = 0; i < count2; i++) {
        cin >> degree2[i];
    }

    for (int i = 0; i < count2; i++) {
        cin >> coeff2[i];
    }

    Polynomial second;
    for (int i = 0; i < count2; i++) {
        second.setCoefficient(degree2[i], coeff2[i]);
    }

    cin >> choice;

    Polynomial result;
    switch (choice) {
        // Add
    case 1:
        result = first + second;
        result.print();
        break;
        // Subtract
    case 2:
        result = first - second;
        result.print();
        break;
        // Multiply
    case 3:
        result = first * second;
        result.print();
        break;

    case 4: // Copy constructor
    {
        Polynomial third(first);

        if (third.degCoeff == first.degCoeff) {
            cout << "false" << endl;
        } else {
            cout << "true" << endl;
        }
        break;
    }

    case 5: // Copy assignment operator
    {
        Polynomial fourth(first);

        if (fourth.degCoeff == first.degCoeff) {
            cout << "false" << endl;
        } else {
            cout << "true" << endl;
        }
        break;
    }

    }

    return 0;
}