#include <bits/stdc++.h>
using namespace std;
int CheckKnight (string str1, string str2)
{
    int x1,x2,y1,y2;
    x1=str1[0]-64;
    y1=str1[1]-48;
    x2=str2[0]-64;
    y2=str2[1]-48;
   if(x1<=8 && x1>=1 && y1<=8 && y1>=1 && x2<=8 && x2>=1 && y2<=8 && y2>=1)
   {
    
    if ((x2==x1+1 && y2==y1+2) || (x2==x1+2 && y2==y1+1) || (x2==x1+1 && y2==y1-2) || (x2==x1+2 && y2==y1-1)) return 1;
                                        
    else
    {
      if ((x2==x1-1 && y2==y1+2) || (x2==x1-2 && y2==y1+1) || (x2==x1-1 && y2==y1-2) || (x2==x1-2 && y2==y1-1)) return 1;
      else return 2;  
    }
   }
   else return 3;  
    //scanf("%d %d %d %d",&x1,&y1,&x2,&y2);        
    return 0;
}
