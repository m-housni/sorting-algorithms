``` c++
// tri à bulle
#define TRUE 1
#define FALSE 0
void tri_a_bulle(int *t, int n)
{
 int j = 0;
 int tmp = 0;
 int en_desordre = 1;
 while(en_desordre)
 {
 en_desordre = FALSE;
   for(j = 0 ; j < n- 1 ; j++){
    if(t[j] > t[j+1]){
      tmp = t[j+1];
      t[j+1] = t[j];
      t[j] = tmp;
       en_desordre = TRUE;
    }
   }
 }
}

// tri par sélection
void tri_selection(int *t, int n)
{
 int i, min, j , tmp;
 for(i = 0 ; i < n - 1 ; i++)
 {
   min = i;
   for(j = i+1 ; j < n ; j++)
   if(t[j] < t[min])
   min = j;
   if(min != i)
   {
     tmp = t[i];
     t[i] = t[min];
     t[min] = tmp;
   }
  }
}
```
