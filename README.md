# Sorting Algorithms

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

// tri par permutation
void tri_permutation(int *t, int n)
{
  int i,s=0,k;
  int nb[n];
  int res [n];
  for(i=0;i<n;i++)
  {
   for(k=0;k<n;k++){
    if(t[i]>t[k]) s++;
    nb[i]=s;
   }
   res[s]=t[i];
   s=0;
  }
  for( i=0;i<n;i++)
   t[i]=res[i];
}

// tri par insertion
void tri_insertion(int *t, int n)
{
 int i,p,j;
 int x;
 for (i = 1; i < n; i++)
 {
  x = t[i];
  p = i-1;
  while (t[p] > x && p-- > 0) {}
  p++;
  for (j = i-1; j >= p; j--) {
   t[j+1] = t[j];
  }
  t[p] = x;
 }
}

// tri par fusion
void fusion(int *t,int deb1,int fin1,int fin2)
{
  int *table1;
  int deb2=fin1+1;
  int compt1=deb1;
  int compt2=deb2;
  int i;
  table1=(int *)malloc((fin1-deb1+1)*sizeof(int));
  for(i=deb1;i<=fin1;i++)
   table1[i-deb1]=t[i];
  for(i=deb1;i<=fin2;i++){
   if (compt1==deb2) break;
   else if (compt2==(fin2+1)) {
   t[i]=table1[compt1-deb1];
   compt1++;
  }
  else if (table1[compt1-deb1]<t[compt2]){
   t[i]=table1[compt1-deb1];
   compt1++;
  }
  else{
   t[i]=t[compt2];
   compt2++;
  }
 }
 free(table1);
}
void tri_fusion_bis(int *t,int deb,int fin)
{
if (deb!=fin){
 int milieu=(fin+deb)/2;
 tri_fusion_bis(t,deb,milieu);
 tri_fusion_bis(t,milieu+1,fin);
 fusion(t,deb,milieu,fin);
 }
}
void tri_fusion(int *t,int n)
{
 if (n>0) tri_fusion_bis(t,0,n-1);
}

// tri rapide
void echanger(int *t, int i, int j)
{
 int tmp;
 tmp=t[i];
 t[i]=t[j];
 t[j]=tmp;
}
int partition(int *t, int deb, int fin)
{
 int compt=deb;
 int pivot=t[deb];
 int i;
 for(i=deb+1;i<=fin;i++){
  if(t[i]<pivot){
  compt++;
  echanger(t,compt,i);
  }
 }
 echanger(t,compt,deb);
 return(compt);
 }
void tri_rapide_bis(int *t, int debut,int fin)
 {
  if(debut<fin)
  {
   int pivot=partition(t,debut,fin);
   tri_rapide_bis(t,debut,pivot-1);
   tri_rapide_bis(t,pivot+1,fin);
  }
 }
void tri_rapide(int *t,int n)
 {
  tri_rapide_bis(t,0,n-1);
 }
```
