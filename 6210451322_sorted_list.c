#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int a ; //keepdata
    struct node *b,*o ; //keepadd 
};
void listnumber(struct node *f){
    while(f->b != NULL){ //ไม่เท่ากับช่องว่าง
        int g ; //keepสลับที่
        if(f->a <(f->b)->a){ //checkลำดับdataว่ามากกว่าหรือน้อยกว่า
            g = f->a ;
            f->a = (f->b)->a ;
            (f->b)->a = g ; //ตัวปัจจุบันแทนตัวก่อนหน้า
        }
        f = f->b ;
    }
}
int main() {
    int r = 0,number ; //keepround
    struct node *d , *e,*head,*tmp; //node
    while(scanf("%d",&number)==1){
        if(number == -1){
            break ;
        }
        if(number >=0 ){
            d = (struct node*)malloc(sizeof(struct node)) ; //จองช่อง
            if(r == 0){
                d -> a = number ; 
                d->o = NULL;
                d -> b = NULL ; //addค่าทีหลังเชื่อมnode
                e = d;//แก้ค่าNULLในLoopถัดไป
                head = d ; 
                r++ ;
            }
            else {
                d -> a = number ;
                d -> b = e ;//เก็บaddก่อนหน้าไว้
                d-> o = NULL; 
                e -> o =d;
                e = d ; 
                listnumber(d) ;
            }
        }

    }
    for(tmp=head;tmp;tmp=tmp->o){
        printf("%d\n",tmp->a);
    }
    

}