int a,b,c=0;
scanf("%d%d%d",&a,&b,&c);
int min3(){
if (a<=b)
        if(a<=c)
                printf("%d\n",a);
        else
                printf("%d\n",c);
else
        if(b<=c)
                printf("%d\n",b);
        else
                printf("%d\n",c);

}
min3();
return 0;
}
~  
