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
