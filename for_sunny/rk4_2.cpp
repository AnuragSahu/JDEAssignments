/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

float f(float t,float y,float z)
{
    if(1+y < 0.0005)
        return 40 - (((1.8/(1-1)) + 0.9*z)/0.02)*y;
    else
        return 40 - (((1.8/(1+y)) + 0.9*z)/0.02)*y;
}

float g(float t,float y,float z)
{
    return -9*y*z;
}

int main()
{
    bool Debug = true;
    bool print_intermediacte = true;
    
    float h = 0.1; // Subinterval
    float t = 0;
    float i = 0.8;
    float s = 1;
    
    cout << "Enter i : ";
    //cin >> i;
    
    cout << "Enter s : ";
    //cin >>  s;
    
    cout << "Enter time interval : ";
    //cin >>  h;
    
    
    
    vector<float> times;
    for(int looper = 0; looper < 5; looper++){
        times.push_back(looper * h);
    }
    
    if(Debug){
        for(int looper = 0; looper < 5; looper++){
            cout << times[looper] << " ";
        }
        cout << "\n";
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








/************************************* OUTPUT **************************************************
Enter i : Enter s : Enter time interval : 0 0.1 0.2 0.3 0.4                                                                                                      
i = 0.8, s = 1,t = 0                                                                                                                                             
k1 : -3.6 ,l1 : -0.72                                                                                                                                            
k2 : inf ,l2 : 0.576                                                                                                                                             
k3 : -inf ,l3 : -inf                                                                                                                                             
k4 : -nan ,l4 : -inf                                                                                                                                             
I1 : -inf, S1 : -nan                                                                                                                                             
                                                                                                                                                                 
                                                                                                                                                                 
i = -inf, s = -nan,t = 0.1                                                                                                                                       
k1 : -nan ,l1 : -nan                                                                                                                                             
k2 : -nan ,l2 : -nan                                                                                                                                             
k3 : -nan ,l3 : -nan                                                                                                                                             
k4 : -nan ,l4 : -nan                                                                                                                                             
I1 : -nan, S1 : -nan                                                                                                                                             
                                                                                                                                                                 
                                                                                                                                                                 
i = -nan, s = -nan,t = 0.2                                                                                                                                       
k1 : -nan ,l1 : -nan                                                                                                                                             
k2 : -nan ,l2 : -nan                                                                                                                                             
k3 : -nan ,l3 : -nan                                                                                                                                             
k4 : -nan ,l4 : -nan                                                                                                                                             
I1 : -nan, S1 : -nan                                                                                                                                             
                                                                                                                                                                 
                                                                                                                                                                 
i = -nan, s = -nan,t = 0.3                                                                                                                                       
k1 : -nan ,l1 : -nan                                                                                                                                             
k2 : -nan ,l2 : -nan                                                                                                                                             
k3 : -nan ,l3 : -nan                                                                                                                                             
k4 : -nan ,l4 : -nan                                                                                                                                             
I1 : -nan, S1 : -nan                                                                                                                                             
                                                                                                                                                                 
                                                                                                                                                                 
i = -nan, s = -nan,t = 0.4                                                                                                                                       
k1 : -nan ,l1 : -nan                                                                                                                                             
k2 : -nan ,l2 : -nan                                                                                                                                             
k3 : -nan ,l3 : -nan                                                                                                                                             
k4 : -nan ,l4 : -nan                                                                                                                                             
I1 : -nan, S1 : -nan                                                                                                                                             
                        
*********************/
