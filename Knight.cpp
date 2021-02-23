#include <stdio.h>
#include<string>
int main ()
{
    int x1,x2,y1,y2;
    char a[10];
    scanf("%s",&a);
    x1=a[0]-64;
    y1=a[1]-48;
    x2=a[3]-64;
    y2=a[4]-48;
   if(x1<=8 && x1>=1 && y1<=8 && y1>=1 && x2<=8 && x2>=1 && y2<=8 && y2>=1 && a[2]=='-')
   {
    
    if ((x2==x1+1 && y2==y1+2) || (x2==x1+2 && y2==y1+1) || (x2==x1+1 && y2==y1-2) || (x2==x1+2 && y2==y1-1)) printf ("YES");
                                        
    else
    {
      if ((x2==x1-1 && y2==y1+2) || (x2==x1-2 && y2==y1+1) || (x2==x1-1 && y2==y1-2) || (x2==x1-2 && y2==y1-1)) printf ("YES");
      else printf("NO");  
    }
   }
   else printf("ERROR");  
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);        
    return 0;
}
