#include <stdio.h>
#include <stdlib.h>

//先跳到对应年的11月12日
//然后求月差

int jizhun[4],daipan[4];
jizhun[4]={2025,11,12,3};
int nian=365;
int yue[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int week=3;

int gaponeyear(int year1,int year2){
        //每年的11月12日到下一年11月12日
        if(366==panyear(year1)||366==panyear(year2))gaponeyear=366;
        else gaponeyear=365;
        if(year1>year2)gaponyear=gaponeyear*(-1);
        return gaponeyear;//使数值为year2-year1
}



int panyear(int a){
        int c=365;
        if ((0==a%4 && 0!=a%100) || 0==a%400){
                c=366;
        }
        return c;
}
int panyue(int a){
        int b=28;
        if(a==366){
                b=29;
        }
        return b;
}

int panweek(int richa){
        int b=(week+richa)%7;
        if(b>0)return b;
        if(b<=0)return (7-(-b));
}

int panricha_yue(int month,day){
//下方已排除当年当月的情况
        int z,b=0;int x=0,y=0;
        for(z=0;z<month-1;z++){
                x+=yue[z];
        }
        for(z=0;z<10;z++){
                y+=yue[z];
        }
        y+=12;
        b=z-y;//做差统一用待判定的-11.12
        return b;
}

int panricha_nian(int daipan[0]){
        int sum=0;
        if(daipan[0]>2025){
                for(i=2025;i<daipan[0];i++){
                        sum+=gaponeyear(i,i+1);
                }
        }
        else if(2025==daipan[0])sum=0;
        else{
                for(i=2025;i>daipan[0];i--){
                        sum+=gaponeyear(i,i+1);
                }
        }
        return sum;
}

//int richa=richa_yue+richa_nian;

int main(){
        int i,j,k,a,b;

        for(i=0;i<4;i++){
                scanf("%d ",&daipan[i]);
        }


        //先判定星期

        //简单情况入手,本月开始

        a=panricha_yue(daipan[1],daipan[2]);
        b=panricha_nian(daipan[0]);
       int richa;
        richa=a+b;
        week=panweek(richa);
        if(2025==daipan[0]&&11==daipan[1]){
                week=panweek(daipan[2]-12);
                printf("该日子为星期%d\n",week);
                return 0;
        }
        //当月考虑完
        //
        //考虑当年
        printf("该日子为星期%d\n",week);
        exit(0);

int panriyu(){
        if(daipan[0]>=jizhun[0]&&daipan[1]>11){
                //未来
                riyu=daipan[2];
        }

        if(daipan[0]<=2025&&daipan[1]<11){
                //过去
                int d=panyear(daipan[0]);
                if(daipan[1]==2){
                        if(366==d)
                                riyu=(29-daipan[2]+1);
                        else riyu=(28-daipan[2]+1);
                }
                else riyu=(yue[daipan[1]]-daipan[2]+1);
        }
       if(daipan[0]==2025)riyu=
        int yuecha=(daipan[1]-jizhun[1]);

        int derta_tian=();

        year=panyear(diapan[0]);
        if(366==year) yue[1]=29;
}



        return 0;
}
