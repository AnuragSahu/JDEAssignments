#include <iostream>
#include <vector>

using namespace std;

float f(float t,float i,float s)
{
    return (-20000*i - 94*s);
}

float g(float t,float i,float s)
{
    return 300;
}

int main()
{
    bool Debug = true;
    bool print_intermediacte = true;
    
    float h = 0.002; // Subinterval
    float t = 0;
    float i = 0;
    float s = 300;
    
    cout << "Enter i : ";
    cin >> i;
    
    cout << "Enter s : ";
    cin >>  s;
    
    cout << "Enter time interval : ";
    cin >>  h;
    
    
    
    vector<float> times;
    for(int looper = 0; looper < 5; looper++){
        times.push_back(looper * h);
    }
    
            
            
    for(int looper = 0; looper < 5; looper++){
        
        t = times[looper];
        
        if(Debug){
            cout << "i = " << i << ", s = " << s << ",t = " << t << "\n";
        }
        
        float k1 = h*f(t,i,s);
        float l1 = h*g(t,i,s);
        
        if(Debug)
            cout <<"k1 : "<< k1 << " ,l1 : " << l1 << "\n";
        
        float k2 = h*f(t+h/2,i+k1/2,s+l1/2);
        float l2 = h*g(t+h/2,i+k1/2,s+l1/2);
        
        if(Debug)
            cout <<"k2 : "<< k2 << " ,l2 : " << l2 << "\n";
        
        float k3 = h*f(t+h/2,i+k2/2,s+l2/2);
        float l3 = h*g(t+h/2,i+k2/2,s+l2/2);
        
        if(Debug)
            cout <<"k3 : "<< k3 << " ,l3 : " << l3 << "\n";
        
        float k4 = h*f(t+h,i+k3,s+l3);
        float l4 = h*g(t+h,i+k3,s+l3);
        
        if(Debug)
            cout <<"k4 : "<< k4 << " ,l4 : " << l4 << "\n";
        
        float I1 = (l1 + 2*l2 + 2*l3 + l4) / 6 + i;
        float S1 = s + ((k1 + 2*k2 + 2*k3 + k4)/6);
        
        
        if(print_intermediacte)
            cout <<"I1 : "<< I1 << ", S1 : " << S1 << "\n";
            
        i = I1;
        s = S1;
        
        cout << "\n\n";
        
    }
    return 0;
}
