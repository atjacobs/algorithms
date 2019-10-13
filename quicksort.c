
#include <stdio.h>
#include <stdlib.h>

static inline void swap(int *a, int *b)
{
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

static int *partition(int *start, int *end)
{
  int *dst = start;
  int *check = start;
  while(check < end){
    if(*check < *end){
      swap(dst++,check);
    }
    check++;
  }
  swap(dst,end);
  return dst;
}

void quick_sort(int *list, int *end)
{
  int *p;
  if(end > list){
    p = partition(list,end);
    quick_sort(list,p - 1);
    quick_sort(p+1,end);
  }
}


int main(int argc, char *argv[])
{
  int *l;
  int len;
  int i = 0;

  if(argc != 2){
    fprintf(stderr, "Format: quick_sort <len>\n");
    return 1;
  }
  
  sscanf(argv[1],"%d",&len);
  
  l = malloc(len*sizeof(l));
  
  printf("unsorted:\t");
  for(i = 0; i < len; i++){
    l[i] = rand() % len;
    printf("%02d ",l[i]);
  }
  printf("\n");

  quick_sort(l,l+len-1);
  printf("sorted:\t\t");
  for(i = 0; i < len; i++){
    printf("%02d ",l[i]);
  }
  printf("\n");
  return 0;

}
