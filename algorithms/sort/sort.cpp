#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;

void print(int *d, int len){
    for (int i=0; i<len; i++){
        cout<<d[i]<<" ";
    }
    cout<<'\n';
}

//冒泡排序
void bubble_sort(int *data, int len){
    for(int i=0; i<len; i++){
        for(int j=0; j<len-i-1; j++){
            if (data[j] > data[j+1]){ // 升序； 降序需要改成 < 
                data[j] = data[j] ^ data[j+1];
                data[j+1] = data[j+1] ^ data[j];
                data[j] = data[j] ^ data[j+1];
            }
        }
    }
}

//插入排序
void insertion_sort(int *d, int len){
    for (int i=1; i<len; i++){
        int value = d[i];
        int j = i-1;
        for(;j>=0; j--){
            if(d[j]>value){ //升序
                d[j+1] = d[j];
            }
            else{
                break;
            }
        }
        d[j+1] = value;
    }
}

//选择排序
void selection_sort(int *d, int len){
    for (int i=0; i<len; i++){
        int idx = i;
        for(int j=i+1; j<len; j++){
            if(d[j]<d[idx]){
                idx = j;
            }
        }
        if(i!=idx){
            d[i] = d[i] ^ d[idx];
            d[idx] = d[idx] ^ d[i];
            d[i] = d[i] ^ d[idx];
        }
    }
}

//归并排序
void merge(int *l, int llen, int *r, int rlen, int * o){
    int li = 0, ri = 0, oi = 0;
    while(li<llen || ri<rlen){
        if (!(li<llen)){
            o[oi] = r[ri];
            ri++;
        }
        else if (!(ri<rlen)){
            o[oi] = l[li];
            li++;
        }
        else if (l[li] <= r[ri]){
            o[oi] = l[li];
            li++;
        }else{
            o[oi] = r[ri];
            ri++;
        }
        oi++;
    }
}

void merge_sort(int *d, int start, int end){
    
    
    if(start>=end) return;
    int mid = (end + start)/2;
    
    merge_sort(d, start, mid);
    merge_sort(d, mid+1, end);
    
    int * o = new int[end-start+1];
    int i = start;
    int j = mid+1;
    int k = 0;
    while(i<=mid && j<=end){
        o[k++] = d[i]>d[j]?d[j++]:d[i++];
    }
    while(i<=mid){
        o[k++] = d[i++];
    }
    while(j<=end){
        o[k++] = d[j++];
    }
    for(k=0; k<end-start+1; k++){
        d[k+start] = o[k];
        
    }
    delete o;
    
}


template <typename T>
void gen_data(T *& d, int len){
    d = new T[len];
    srand(int(time(0)));
    for (int i=0; i<len; i++){
        (d)[i] = rand()%len;
    }
}

template <typename T>
void copy(T *d, T * s, int len){
    for (int i=0; i<len; i++)
    {
        d[i] = s[i];
    }
}

clock_t  start(){
    return clock();
}

clock_t  end(clock_t start){
    return clock() - start;
}

int main(int argc, char **argv){
    clock_t st=0;
    const int len =20;
    int * d;
    int * dt = new int[len];
    gen_data(d, len);    
    print(d, len);  

    merge_sort(d, 0, len-1);
    print(d, len); 
/*
    copy(dt, d, len);
    st = start();
    bubble_sort(dt, len);    
    clock_t e1 = end(st);
    //print(dt, len);   

    copy(dt, d, len);
    st = start();
    insertion_sort(dt, len);   
    clock_t e2 = end(st); 
    //print(dt, len);    

    copy(dt, d, len);
    st = start();
    selection_sort(dt, len);
    clock_t e3 = end(st); 
    //print(dt, len);

    printf ("bubble_sort(%f ms).\n",((float)e1)/CLOCKS_PER_SEC*1000);
    printf ("insertion_sort(%f ms).\n",((float)e2)/CLOCKS_PER_SEC*1000);
    printf ("selection_sort(%f ms).\n",((float)e3)/CLOCKS_PER_SEC*1000);
    */
}

