
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void merge_sorted(int *dest, int list1[], int len1, int list2[], int len2)
{
  // Merge together two sorted lists.
  int idx1 = 0;
  int idx2 = 0;
  while((idx1 < len1) && (idx2 < len2)){
    if(list1[idx1] < list2[idx2]){
      *(dest++) = list1[idx1++];
    }else{
      *(dest++) = list2[idx2++];
    }
  }
  while(idx1 < len1){
    *(dest++) = list1[idx1++];
  }
  while(idx2 < len2){
    *(dest++) = list2[idx2++];
  }
}

void merge_sort(int *list, int len){
  // 1. Break apart list into two halves
  // 2. Sort them
  // 3. merge sorted
  if(len == 1){
    return;
  }
  // Break apart list.
  int len_a = len/2;
  int *list_a = malloc(len_a*sizeof(int));
  memcpy(list_a, list, len_a*sizeof(int));
  merge_sort(list_a,len_a);
  int *list_b = malloc((len-len_a)*sizeof(int));
  memcpy(list_b, list + len_a, sizeof(int)*(len-len_a));
  merge_sort(list_b,len - len_a);
  merge_sorted(list,list_a,len_a,list_b,len - len_a);
  free(list_a);
  free(list_b);
}

int main(int argc, char *argv[])
{
  if(argc != 2){
    fprintf(stderr, "format: mergesort <len>\n");
    return 1;
  }

  int len;
  
  sscanf(argv[1], "%d", &len);
  
  int *l = malloc(len*sizeof(int));

  printf("unsorted:\t");
  for(int i = 0; i < len; i++){
    l[i] = rand() % len;
    printf("%02d ", l[i]);
  }
  printf("\n");

  merge_sort(l,len);

  printf("sorted:\t\t");
  for(int i = 0; i < len; i++){
    printf("%02d ", l[i]);
  }
  printf("\n");
  
  return 0;

}
