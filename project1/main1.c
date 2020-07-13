#include<stdio.h>
#include<unistd.h>
#include<gtk/gtk.h>

// #define MAX_Series 5
#define rep(i,n) for(i=0;i<n;i++)
typedef long long ll;
struct glow{int n;int a,b;};
pthread_attr_t attr;

int lazy[100];
long int catalan[100];
int sq[40],tri[40],pen[40],hexo[40];

void * fib(void * arg){
	int n=*(int *)arg;
	printf("\nFib\n");
	ll a=0;
	ll b=1;
	printf("%lld  ",a);
	printf("%lld  ",b);
	for(int i=0;i<n;i++){
		int tmp=a;
		a=b;
		b=b+tmp;
		printf("%lld  ",b);
	}
	printf("\n\n");
	return NULL;
}
void * checker(void * arg){
	int **n=(int**)arg;
	pthread_exit(NULL);
	return NULL;
}
void * magic(void * arg){
	struct glow *pack=(struct glow *)arg;
	int n;
	n=pack->n;
	int a=pack->a,b=pack->b;
	// a=3;
	// b=2;
	// printf("Magic\n");
	int array[n][n];
    memset(array, 0, sizeof(array)); 
	array[a][b]=1;
	int count=0;
	int i=a,j=b;
	while(count!=((n*n)-1))
	{
		int local=array[i][j];
		// printf("(%d,%d,%d)\n",i,j,array[i][j]);
		int lo=(i-1);
			if(lo<0){
				lo=n+lo;
			}
			lo=lo%n;
		if(array[lo][(j+1)%n]==0){
			i=(i-1);
			if(i<0){
				i=n+i;
			}
			i=i%n;
			j=(j+1)%n;
		}
		else{
			j=(j-1);
			if(j<0){
				j=n+j;
			}
			i=i%n;
		}
		array[i][j]=local+1;
		count++;
	}
	int check_array[(n*2)+2],check_array_counter=0;
	// pthread_t tid1;
	// pthread_create(&tid1,NULL,checker,array);
	// ====Row check
	int p=0,q=0;
	rep(p,n){
		int sum=0;
		rep(q,n){
			sum+=array[p][q];
		}
		// printf("row("<<sum<<")\n");
		check_array[check_array_counter++]=sum;
	}
	// =====Column check
	p=0,q=0;
	rep(p,n){
		int sum=0;
		rep(q,n){
			sum+=array[q][p];
		}
		// printf("column("<<sum<<")\n");
		check_array[check_array_counter++]=sum;
	}
	// =====Digonal check
	p=0;
	int sum=0;
	rep(p,n){
		sum+=array[p][p];
	}
	// printf("+ve Digonal("<<sum<<")\n");
	check_array[check_array_counter++]=sum;
	p=0,q=0;
	sum=0;
	rep(p,n){
		rep(q,n){
			if(p+q==n-1){
			sum+=array[q][p];}
		}
	}
	// printf("-ve Digonal("<<sum<<")\n");

	int chk=1;
	int cloacl=0,dlocal=0;
	check_array[check_array_counter++]=sum;
	for(int i=0;i<check_array_counter;i++){
		// printf(check_array[i]<<" ");
		if(i==0){
			cloacl=check_array[i];
			dlocal++;
		}
		else{
			if(cloacl!=check_array[i]){
				// printf("Not a Magic Square\n");
				chk--;
				break;
			}
			else{
				dlocal++;
			}
		}
	}
	if(dlocal==check_array_counter){
		printf("\nYes \n");
		for(int i=0;i<check_array_counter;i++){
			printf("%d  ",check_array[i]);
		}
	}
	// printf("\n");
	
	if(chk==1){
		printf("\n------------\n");
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				printf("%d\t",array[i][j]);
			}
			printf("\n");
		}
	}
	pthread_exit(NULL);
	return NULL;
}

int fact(int n){
	int f=1;
	for(int i=1;i<=n;i++)
		f*=i;
	return f;
}
void * lazy_caterer(void * param){
	int n1=*(int* )param;
	lazy[n1]=((n1*n1)+n1+2)/2;

	pthread_exit(NULL);
	return NULL;
}
void * _catalan_(void * param){
	ll x=*(ll *)param;
	ll y=fact(2*x);
	//printf(" %d\n",x,y);
	ll z=fact(x);
	ll w=fact(x+1);
	ll q=y/z;
	q=q/w;
	catalan[x]=q;
	pthread_exit(NULL);
	return NULL;
}
void *sqpr (void *parameter){
	int i=*(int*)parameter;
	int it=i*i;
	sq[i]=it;
	pthread_exit(0);
}
void *Square (void *parameter){
	int n=*(int*)parameter;
	pthread_t sid[20];
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	for(int i=0;i<=n;i++){
		int *local=(int*)malloc(sizeof(int*));
		*local=i;
		pthread_create(&sid[i], &attr,sqpr,local);
		//sleep(1);
	}
	for(int i=0;i<=n;i++)
		pthread_join(sid[i],NULL);
	pthread_exit(0);
}
void *trpr (void *parameter){
	int i=*(int*)parameter;
	tri[i]=(i*(i+1))/2;
	pthread_exit(0);
}
void *Triangle (void *parameter){
	int n=*(int*)parameter;
	pthread_t tid[20];
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	for(int i=1;i<=n;i++){
		int *local=(int*)malloc(sizeof(int*));
		*local=i;
		pthread_create(&tid[i], &attr,trpr,local);
		//sleep(1);
	}
	for(int i=0;i<=n;i++)
		pthread_join(tid[i],NULL);
	pthread_exit(0);
}
void *pnpr (void *parameter){
	int i=*(int*)parameter;
	pen[i]=(i*((3*i)-1))/2;
	pthread_exit(0);
}
void *Pentagon (void *parameter){
	int n=*(int*)parameter;
	pthread_t peid[20];
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	for(int i=1;i<=n;i++){
		int *local=(int*)malloc(sizeof(int*));
		*local=i;
		pthread_create(&peid[i], &attr,pnpr,local);
		//sleep(1);
	}
	for(int i=0;i<=n;i++)
		pthread_join(peid[i],NULL);
	pthread_exit(0);
}
void *hxpr (void *parameter){
	int i=*(int*)parameter;
	hexo[i]=((2*i)*((2*i)-1))/2;
	pthread_exit(0);
}
void *Hexagon (void *parameter){
	int n=*(int*)parameter;
	pthread_t hid[20];
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	for(int i=1;i<=n;i++){
		int *local=(int*)malloc(sizeof(int*));
		*local=i;
		pthread_create(&hid[i], &attr,hxpr,local);
		//sleep(1);
	}
	for(int i=0;i<=n;i++)
		pthread_join(hid[i],NULL);
	pthread_exit(0);
}
void * countnndSay(void * arg){
	
	int n=*(int *)arg;	
	char *a = malloc(2), *b = 0, *x, c;
	int cnt, len = 1;
 	int count=0;
	for (sprintf(a, "1"); (b = realloc(b, len * 2 + 1)); a = b, b = x) {
		puts(x = a);
		count++;
		if(count== n)
			break;
		for (len = 0, cnt = 1; (c = *a); ) {
			if (c == *++a)
				cnt++;
			else if (c) {
				len += sprintf(b + len, "%d%c", cnt, c);
				cnt = 1;
			}
		}
	}

}

void * figureate(void * arg){
	int n=*(int *)arg;
	// printf(n;
	pthread_t tid3,tid4,tid5,tid6;
	pthread_create(&tid3, &attr, Square, &n);
	pthread_create(&tid4, &attr, Triangle, &n);
	pthread_create(&tid5, &attr, Pentagon, &n);
	pthread_create(&tid6, &attr, Hexagon, &n);
	pthread_join(tid3,NULL);
	pthread_join(tid4,NULL);
	pthread_join(tid5,NULL);
	pthread_join(tid6,NULL);
	printf("\nSquare: ");
	for(int i=1;i<n;i++)
		printf("%d ",sq[i]);
	
	printf("\n");
	printf("Triangle: ");
	for(int i=1;i<n;i++)
		printf("%d ",tri[i]);
	printf("\n");

	printf("Pentagon: ");
	for(int i=1;i<n;i++)
		printf("%d  ",pen[i]);
	printf("\n");
	
	printf("Hexagonal: ");
	for(int i=1;i<n;i++)
		printf("%d ",hexo[i]);
	printf("\n");
	pthread_exit(NULL);
	return NULL;
}

void on_window_main_destroy()
 {
     printf("hello \n");
     gtk_main_quit();
 }
 
 
int main(int argc,char **argv)
{
	GtkBuilder * builder;
	GtkWidget * window;
	gtk_init(&argc,&argv);
	builder=gtk_builder_new();
	gtk_builder_add_from_file(builder,"test.glade",NULL);
	
	window=GTK_WIDGET(gtk_builder_get_object(builder,"window"));
	gtk_builder_connect_signals(builder,NULL);
	g_object_unref(builder);
	gtk_widget_show(window);
	gtk_main();
	return 0;	
	
	int N,count=0;
	printf("Enter the Number (MAX 47):- ");
	scanf("%d",&N);
	pthread_attr_init(&attr);
	pthread_t tid_magic[N*N];
	pthread_t tid_fab,tid_figureate;
	pthread_t tid_lazy[N];
	pthread_t tid_catalan[N];
	pthread_t tid_count;

/*	for(int a=0;a<N;a++){*/
/*	 	for(int b=0;b<N;b++){*/
/*	 		struct glow loc;*/
/*	 		loc.n=N;*/
/*	 		loc.b=b;*/
/*	 		loc.a=a;*/
/*	 		pthread_create(&tid_magic[count],NULL,magic,&loc);*/
/*			pthread_join(tid_magic[count],NULL);*/
/*	 		count++;*/
/*	 	}*/
/*	 }*/

	 pthread_create(&tid_fab,NULL,fib,&N);
	 for(int i=1;i<=N;i++){
	 	long int *local=(long int*)malloc(sizeof(int*));
	 	*local=i;
	 	pthread_create(&tid_lazy[i],&attr,lazy_caterer,local);
	 	pthread_create(&tid_catalan[i],&attr,_catalan_,local);	
	 }

	 pthread_create(&tid_figureate,&attr,figureate,&N);

	pthread_create(&tid_count,&attr,countnndSay,&N);


	 for(int i=1;i<=N;i++){
	 	pthread_join(tid_lazy[i],NULL);
	 	pthread_join(tid_catalan[i],NULL);
	 }

/*	 for(int i=0;i<count;i++){*/
/*	 	pthread_join(tid_magic[i],NULL);*/
/*	 }*/

	 pthread_join(tid_figureate,NULL);

	pthread_join(tid_count,NULL);

	 pthread_join(tid_fab,NULL);

	 printf("\nlazy  caterer ");
	 for(int i=1;i<=N;i++){
	 	printf("%d ",lazy[i]);
	 }
	 printf("\ncatalan  ");
	 for(int i=1;i<=N;i++){
	 	printf("%ld ",catalan[i]);
	 }
	 printf("\n");
	
  	return 0;
}
