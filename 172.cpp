#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

const double pi = acos(-1);

int main(){
    int a,b,c,d;
    double r,p,area,angle;
    while(cin >> a >> b >> c >> d){
        if(!(a>0 && b>0 && c>0 && d>0)){
            if(a<d) swap(a,d);
            if(b<d) swap(b,d);
            if(c<d) swap(c,d);
            if(a<c) swap(a,c);
            if(b<c) swap(b,c);
            if(a<b) swap(a,b);
        }
        //judgement
        //Illegal Polygon
        if((a==0)||(d<0))
            printf("Illegal Polygon -1\n");
        //Circle
        else if(b==0){
            r=(double)a/2/pi;
            printf("Circle %.2lf\n",r*r*pi);
        }
        //Sector
        else if(c==0){
            printf("Sector %.2lf\n",a*b/2.0);
        }
        //Triangle
        else if(d==0){
            if(a>=b+c) printf("Illegal Triangle -1\n");
            else{
                p=(a+b+c)/2.0;
                area=sqrt(p*(p-a)*(p-b)*(p-c));
                if(a*a>b*b+c*c) printf("Obtuse Triangle %.2lf\n",area);
                if(a*a==b*b+c*c) printf("Right Triangle %.2lf\n",area);
                if(a*a<b*b+c*c) printf("Acute Triangle %.2lf\n",area);
            }
        }
        //Quadrilateral
        else{
            if(a>=b+c+d || b>=a+c+d || c>=a+b+d || d>=a+b+c) printf("Illegal Quadrilateral -1\n");
            else{
                p=(a+b+c+d)/2.0;
                area=sqrt((p-a)*(p-b)*(p-c)*(p-d));
                if(a==b && b==c && c==d) printf("Rhombus %.2lf\n",area);
                else if(a==c && b==d) printf("Parallelogram %.2lf\n",area);
                else if(a==b && c==d) printf("Kite %.2lf\n",area);
                else printf("Other Quadrilateral %.2lf\n",area);
            }
        }
    }
    
    return 0;
}
