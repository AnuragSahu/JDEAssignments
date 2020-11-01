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

/**********************************
Enter i : 0                                                                                                                                                      
Enter s : 300                                                                                                                                                    
Enter time interval : 0.02                                                                                                                                       
i = 0, s = 300,t = 0                                                                                                                                             
k1 : -564 ,l1 : 6                                                                                                                                                
k2 : 112230 ,l2 : 6                                                                                                                                              
k3 : -2.24466e+07 ,l3 : 6                                                                                                                                        
k4 : 8.97866e+09 ,l4 : 6                                                                                                                                         
I1 : 6, S1 : 1.489e+09                                                                                                                                           
                                                                                                                                                                 
                                                                                                                                                                 
i = 6, s = 1.489e+09,t = 0.02                                                                                                                                    
k1 : -2.79932e+09 ,l1 : 6                                                                                                                                        
k2 : 5.57064e+11 ,l2 : 6                                                                                                                                         
k3 : -1.11416e+14 ,l3 : 6                                                                                                                                        
k4 : 4.45663e+16 ,l4 : 6                                                                                                                                         
I1 : 12, S1 : 7.39076e+15                                                                                                                                        
                                                                                                                                                                 
                                                                                                                                                                 
i = 12, s = 7.39076e+15,t = 0.04                                                                                                                                 
k1 : -1.38946e+16 ,l1 : 6                                                                                                                                        
k2 : 2.76503e+18 ,l2 : 6                                                                                                                                         
k3 : -5.5302e+20 ,l3 : 6                                                                                                                                         
k4 : 2.21208e+23 ,l4 : 6                                                                                                                                         
I1 : 18, S1 : 3.66846e+22                                                                                                                                        
                                                                                                                                                                 
                                                                                                                                                                 
i = 18, s = 3.66846e+22,t = 0.06                                                                                                                                 
k1 : -6.8967e+22 ,l1 : 6                                                                                                                                         
k2 : 1.37244e+25 ,l2 : 6                                                                                                                                         
k3 : -2.74496e+27 ,l3 : 6                                                                                                                                        
k4 : 1.09798e+30 ,l4 : 6                                                                                                                                         
I1 : 24, S1 : 1.82087e+29                                                                                                                                        
                                                                                                                                                                 
                                                                                                                                                                 
i = 24, s = 1.82087e+29,t = 0.08                                                                                                                                 
k1 : -3.42323e+29 ,l1 : 6                                                                                                                                        
k2 : 6.81223e+31 ,l2 : 6                                                                                                                                         
k3 : -1.36248e+34 ,l3 : 6                                                                                                                                        
k4 : 5.44992e+36 ,l4 : 6                                                                                                                                         
I1 : 30, S1 : 9.03801e+35                                                                                                                                        
                              
***********************/
