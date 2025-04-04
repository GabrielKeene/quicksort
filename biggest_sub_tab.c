struct sub_tab{
    int start;
    int end ;
    int sum;
};

typedef struct sub_tab sub_tab;


sub_tab biggest_sub_tab(sub_tab biggest,sub_tab biggest_j,int* tab, int j, int N){
    if(j==N){
        return biggest;
    }

    biggest_j.end=j+1;
     biggest_j.sum+= tab[j+1];
    if(biggest_j.sum<tab[j+1] &&  tab[j+1]>=0){    //if cur_sum <0 but new element > 0 we replace by single element tab 
        biggest_j.start=j+1;
        biggest_j.end=j+1;
        biggest_j.sum=tab[j+1];
    }else if (tab[biggest_j.start]<0){    // first element can be removed
        biggest_j.sum-=tab[biggest_j.start];
        biggest_j.start++;
        biggest_j.end=j+1;
        biggest_j.sum+=tab[j+1];
    }
    

    if(tab[j+1]>0 && biggest.end==j){ //if new element>0 we add it
        biggest.end=j+1;
        biggest.sum+= tab[j+1];
    }
     if (tab[biggest.start]<0){       //if first element <0 then we remove it
        biggest.sum-=tab[biggest.start];
        biggest.start++;
        biggest.end=j+1;
        biggest.sum+=tab[j+1];
    }
    if(biggest_j.sum>biggest.sum){
        biggest.start=biggest_j.start;
        biggest.end=biggest_j.end;
        biggest.sum=biggest_j.sum;
    }
    
    
    return biggest_sub_tab(biggest,biggest_j,tab,j+1,N);
    
}

int main()
{
    int* a =malloc(sizeof(int)*8);
    a[0]=1000;
    a[1]=1000;
    a[2]=-9000;
    a[3]=800;
    a[4]=-300;
    a[5]=1000;
    a[6]=100;
    a[7]=-200;
    
    //a=[12,58,-64,-87,12,1258,-85];
    
    sub_tab biggest_j;
    sub_tab biggest;
    biggest.start=0;
    biggest.end= 0;
    biggest.sum=0;
    
    biggest_j.start=0;
    biggest_j.end= 0;
    biggest_j.sum=0;
    
    sub_tab out = biggest_sub_tab(biggest,biggest_j,a,0,7);
    printf("start:%i \nend:%i \nsum:%i",out.start, out.end, out.sum);

