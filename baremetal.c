/*DOC
NAME:Neethukrishna K
DATE:10/10/24
DESCRIPTION:
SAMPLE INPUT:
SAMPLE OUTPUT:
DOC*/
#include<stdio.h>
typedef struct
{
    float i,j,k;
}vector;

vector vect_creation(float i,float j,float k)
{
    vector v = {i,j,k};
    return v;
}

typedef struct 
{
    float m;
    vector v;
}quaternion;

quaternion quat(float m,float i,float j,float k)
{
    quaternion q = {m,vect_creation(i,j,k)};
    return q;
}

quaternion complement_quat(quaternion q)
{
    quaternion q_bar = {q.m,complement(q.v)};
    vector n = {-(v.i),-(v.j),-(v.k)};
    return q_bar;
}

float dot_quat(quaternion q,quaternion q_bar)
{
    float dot = (q.m * q_bar.m) + ((q.v.i) * (q_bar.v.i)) + ((q.v.j) * (q_bar.v.j)) * ((q.v.k) * (q_bar.v.k));
    return dot;
}

quaternion mult_quat(quaternion q,quaternion q_bar)
{
    float m,a,b,c;
    m = (q.m * q_bar.m) - ((q.v.i) * (q_bar.v.i)) - ((q.v.j) * (q_bar.v.j)) - ((q.v.k) * (q_bar.v.k));
    a = (q.m * (q_bar.v.i)) + ((q.v.i) * q_bar.m) - ((q.v.j) * (q_bar.v.i)) - ((q.v.k) * ( q_bar.v.j));
    b = (q.m * (q_bar.v.j)) + ((q.v.j) * q_bar.m) + ((q.v.k) * (q_bar.v.k)) - ((q.v.i) * ( q_bar.v.k));
    c = (q.m * (q_bar.v.k)) + ((q.v.k) * q_bar.m) + ((q.v.i) * (q_bar.v.j)) - ((q.v.j) * ( q_bar.v.i));
    quaternion res = {m,vect_creation(a,b,c)};
    return res;
}

int main()
{
    quaternion q,q_bar,a;
    q = quat(0,1,1,1);
    q_bar = complement_quat(q);
    a = mult_quat(q,q_bar);
    float b = dot_quat(q,q_bar);

    return 0;
}







