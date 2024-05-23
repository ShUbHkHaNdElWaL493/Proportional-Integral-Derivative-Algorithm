/*
    Shubh Khandelwal
*/

#include <bits/stdc++.h>
using namespace std;

#define Kp 0.002
#define Ki 0.005
#define Kd 0.05

void changeSpeed(float *speed, int *target_speed)
{
    float s = *speed;
    int ts = *target_speed;
    float error = 0;
    float error_sum = 0;
    float error_initial = 0;
    if (s < ts)
    {
        while (s < ts)
        {
            error_initial = error;
            error = ts - s;
            error_sum += error;
            s += Kp * error + Ki * error_sum + Kd * (error - error_initial);
            cout<<s<<endl;
            this_thread::sleep_for(chrono::milliseconds(10));
        }
        s = ts;
        cout<<s<<endl;
    } else if (s > ts)
    {
        while (s > ts)
        {
            error_initial = error;
            error = ts - s;
            error_sum += error;
            s += Kp * error + Ki * error_sum + Kd * (error - error_initial);
            cout<<s<<endl;
            this_thread::sleep_for(chrono::milliseconds(10));
        }
        s = ts;
        cout<<s<<endl;
    }
}

int main()
{
    float *speed = (float *) malloc(sizeof(float));
    int *target_speed = (int *) malloc(sizeof(float));
    *speed = 0;
    *target_speed = 0;
    while (1)
    {
        cout<<"\nEnter the speed.\n";
        *speed = *target_speed;
        cin>>*target_speed;
        cout<<endl;
        changeSpeed(speed, target_speed);
    }
    return 0;
}
