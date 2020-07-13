#include<gtk/gtk.h>
#include<stdio.h>
#include<unistd.h>

// #define MAX_Series 5
#define rep(i,n) for(i=0;i<n;i++)
typedef long long ll;
struct glow{int n;int a,b;};
pthread_attr_t attr;

int lazy[100];
long int catalan[100];
int sq[5000],tri[5000],pen[5000],hexo[5000];


pthread_t tid_fab,tid_figureate;
	pthread_t tid_count;
void * fib(void * arg);
void * checker(void * arg);
void * magic(void * arg);
int fact(int n);
void * lazy_caterer(void * param);
void * _catalan_(void * param);
void *sqpr (void *parameter);
void *Square (void *parameter);
void *trpr (void *parameter);
void *Triangle (void *parameter);
void *pnpr (void *parameter);
void *Pentagon (void *parameter);
void *hxpr (void *parameter);
void *Hexagon (void *parameter);
void * countandSay(void * arg);
void * figureate(void * arg);

GtkWidget *magic_button;
GtkWidget *fib_button;
GtkWidget *count_button;
GtkWidget *cat_button;
GtkWidget *lazy_button;
GtkWidget *square_button;
GtkWidget *tri_button;
GtkWidget *pent_button;
GtkWidget *hex_button;

GtkWidget *magic_box;
GtkWidget *fib_box;
GtkWidget *count_box;
GtkWidget *cat_box;
GtkWidget *lazy_box;
GtkWidget *square_box;
GtkWidget *tri_box;
GtkWidget *pent_box;
GtkWidget *hex_box;

GtkWidget *magic_entry;
GtkWidget *fib_entry;
GtkWidget *count_entry;
GtkWidget *cat_entry;
GtkWidget *lazy_entry;
GtkWidget *square_entry;
GtkWidget *tri_entry;
GtkWidget *pent_entry;
GtkWidget *hex_entry;

GtkTextBuffer *magic_buff;
GtkTextBuffer *fib_buff;
GtkTextBuffer *count_buff;
GtkTextBuffer *cat_buff;
GtkTextBuffer *lazy_buff;
GtkTextBuffer *square_buff;
GtkTextBuffer *tri_buff;
GtkTextBuffer *pent_buff;
GtkTextBuffer *hex_buff;

int magic_button_status=0;
int fib_button_status=0;
int count_button_status=0;
int catalen_button_status=0;
int lazy_button_status=0;
int square_button_status=0;
int tri_button_status=0;
int pent_button_status=0;
int hex_button_status=0;

void magic_button_clicked()
{
	magic_buff=gtk_text_view_get_buffer(GTK_TEXT_VIEW(magic_box));
	if(magic_button_status==0){
		magic_button_status=1;
		gtk_button_set_label(GTK_BUTTON(magic_button),"Stop");
		g_print("Magic Square Started\n");
		const char *tt=gtk_entry_get_text((GtkEntry *)magic_entry);
		int x=atoi(tt),count=0;
		g_print("%d\n",x);
		pthread_t tid_magic[x*x];
		
		// gtk_text_buffer_set_text(magic_buff,(const gchar *)tt,(gint)-1);
		// gtk_text_buffer_insert_at_cursor(magic_buff,"\nhello",(gint)-1);
		for(int a=0;a<x;a++){
			for(int b=0;b<x;b++){
				struct glow loc;
				loc.n=x;
				loc.b=b;
				loc.a=a;
				pthread_create(&tid_magic[count],NULL,magic,&loc);
				// magic(&loc);
				// pthread_join(tid_magic[count],NULL);
			 	count++;
			}
		}
		for(int i=0;i<count;i++){
		 	pthread_join(tid_magic[i],NULL);
		}
		// sleep(1);
		// magic_button_status=0;
		// gtk_button_set_label(GTK_BUTTON(magic_button),"Start");
	}
	else{
		magic_button_status=0;
		gtk_button_set_label(GTK_BUTTON(magic_button),"Start");
		// gtk_text_buffer_set_text(magic_buff,(const gchar *)"",(gint)-1);
		g_print("Magic Square Stopped\n");
	}
}
void fib_button_clicked(){
	fib_buff=gtk_text_view_get_buffer(GTK_TEXT_VIEW(fib_box));
	if(fib_button_status==0){
		fib_button_status=1;
		gtk_button_set_label(GTK_BUTTON(fib_button),"Stop");
		const char *tt=gtk_entry_get_text((GtkEntry *)fib_entry);
		int x=atoi(tt);
		g_print("%d\n",x);
		gtk_text_buffer_set_text(fib_buff,(const gchar *)"",(gint)-1);
		// gtk_text_buffer_set_text(fib_buff,(const gchar *)"\nkkkkk",(gint)-1);
		g_print("Fab Started \n");
		pthread_create(&tid_fab,&attr,fib,&x);
		pthread_join(tid_fab,NULL);
	}
	else{
		fib_button_status=0;
		gtk_button_set_label(GTK_BUTTON(fib_button),"Start");
		// gtk_text_buffer_set_text(fib_buff,(const gchar *)"",(gint)-1);
		// pthread_cancel(tid_fab);
		g_print("Fab Stopped\n");
	}
}
void count_button_clicked(){
	count_buff=gtk_text_view_get_buffer(GTK_TEXT_VIEW(count_box));
	if(count_button_status==0){
		count_button_status=1;
		gtk_button_set_label(GTK_BUTTON(count_button),"Stop");
		const char *tt=gtk_entry_get_text((GtkEntry *)count_entry);
		int x=atoi(tt);
		g_print("%d\n",x);
		gtk_text_buffer_set_text(count_buff,(const gchar *)"",(gint)-1);
		g_print("Count And Say Started \n");
		pthread_create(&tid_count,&attr,countandSay,&x);
		pthread_join(tid_count,NULL);
	}
	else{
		count_button_status=0;
		gtk_button_set_label(GTK_BUTTON(count_button),"Start");
		// gtk_text_buffer_set_text(count_buff,(const gchar *)"",(gint)-1);
		g_print("Count And Say Stopped \n");
	}
}
void cat_button_clicked(){
	cat_buff=gtk_text_view_get_buffer(GTK_TEXT_VIEW(cat_box));
	if(catalen_button_status==0){
		catalen_button_status=1;
		gtk_button_set_label(GTK_BUTTON(cat_button),"Stop");
		g_print("Catalen Series Started \n");
		const char *tt=gtk_entry_get_text((GtkEntry *)cat_entry);
		int x=atoi(tt);
		g_print("%d\n",x);
		pthread_t tid_catalan[x];
		gtk_text_buffer_set_text(cat_buff,(const gchar *)"",(gint)-1);
		for(int i=1;i<=x;i++){
			long int *local=(long int*)malloc(sizeof(int*));
		 	*local=i;
		 	pthread_create(&tid_catalan[i],&attr,_catalan_,local);	
		}
		for(int i=1;i<=x;i++){
			pthread_join(tid_catalan[i],NULL);
		}
		// printf("\ncatalan  ");
		char local[100];
		strcpy(local,"");
		for(int i=1;i<=x;i++){
			// printf("%ld\n",catalan[i]);
			char loc[5];
			sprintf(loc,"%ld\n",catalan[i]);
			strcat(local,loc);
		}
		// printf("%s",local);
		gtk_text_buffer_set_text(cat_buff,(const gchar *)local,(gint)-1);
	}
	else{
		catalen_button_status=0;
		gtk_button_set_label(GTK_BUTTON(cat_button),"Start");
		// gtk_text_buffer_set_text(cat_buff,(const gchar *)"",(gint)-1);
		g_print("Cataalen Series Stopped \n");
	}
}
void lazy_button_clicked(){
	lazy_buff=gtk_text_view_get_buffer(GTK_TEXT_VIEW(lazy_box));
	if(lazy_button_status==0){
		lazy_button_status=1;
		gtk_button_set_label(GTK_BUTTON(lazy_button),"Stop");
		g_print("Lazy Started \n");
		const char *tt=gtk_entry_get_text((GtkEntry *)lazy_entry);
		int x=atoi(tt);
		g_print("%d\n",x);
		pthread_t tid_lazy[x];
		gtk_text_buffer_set_text(lazy_buff,(const gchar *)"",(gint)-1);
		for(int i=1;i<=x;i++){
			long int *local=(long int*)malloc(sizeof(int*));
		 	*local=i;
		 	pthread_create(&tid_lazy[i],&attr,lazy_caterer,local);	
		}
		for(int i=1;i<=x;i++){
			pthread_join(tid_lazy[i],NULL);
		}
		char local[100000];
		strcpy(local,"");
		for(int i=1;i<=x;i++){
			// printf("%ld\n",lazy[i]);
			char loc[5];
			sprintf(loc,"%d\n",lazy[i]);
			strcat(local,loc);
		}
		// printf("%s",local);
		gtk_text_buffer_set_text(lazy_buff,(const gchar *)local,(gint)-1);

	}
	else{
		lazy_button_status=0;
		gtk_button_set_label(GTK_BUTTON(lazy_button),"Start");
		// gtk_text_buffer_set_text(lazy_buff,(const gchar *)"",(gint)-1);
		g_print("Lazy Stopped \n");
	}
}
void square_button_clicked(){
	square_buff=gtk_text_view_get_buffer(GTK_TEXT_VIEW(square_box));
	if(square_button_status==0){
		square_button_status=1;
		gtk_button_set_label(GTK_BUTTON(square_button),"Stop");
		g_print("Square Started \n");
		const char *tt=gtk_entry_get_text((GtkEntry *)square_entry);
		int x=atoi(tt);
		g_print("%d\n",x);
		gtk_text_buffer_set_text(square_buff,(const gchar *)"",(gint)-1);
		pthread_t tid3;
		pthread_create(&tid3, &attr, Square, &x);
		pthread_join(tid3,NULL);
		
		char local[100000];
		strcpy(local,"");
		for(int i=1;i<=x;i++){
			// printf("%ld\n",sq[i]);
			char loc[20];
			sprintf(loc,"%d\n",sq[i]);
			strcat(local,loc);
		}
		// printf("%s",local);
		gtk_text_buffer_set_text(square_buff,(const gchar *)local,(gint)-1);
	}
	else{
		square_button_status=0;
		gtk_button_set_label(GTK_BUTTON(square_button),"Start");
		// gtk_text_buffer_set_text(square_buff,(const gchar *)"",(gint)-1);
		g_print("Square Stopped \n");
	}
}
void tri_button_clicked(){
	tri_buff=gtk_text_view_get_buffer(GTK_TEXT_VIEW(tri_box));
	if(tri_button_status==0){
		tri_button_status=1;
		gtk_button_set_label(GTK_BUTTON(tri_button),"Stop");
		g_print("Triangle Started \n");
		const char *tt=gtk_entry_get_text((GtkEntry *)tri_entry);
		int x=atoi(tt);
		g_print("%d\n",x);
		gtk_text_buffer_set_text(tri_buff,(const gchar *)"",(gint)-1);
		pthread_t tid3;
		pthread_create(&tid3, &attr, Triangle, &x);
		pthread_join(tid3,NULL);
		
		char local[100000];
		strcpy(local,"");
		for(int i=1;i<=x;i++){
			// printf("%ld\n",sq[i]);
			char loc[20];
			sprintf(loc,"%d\n",tri[i]);
			strcat(local,loc);
		}
		// printf("%s",local);
		gtk_text_buffer_set_text(tri_buff,(const gchar *)local,(gint)-1);
	}
	else{
		tri_button_status=0;
		gtk_button_set_label(GTK_BUTTON(tri_button),"Start");
		// gtk_text_buffer_set_text(tri_buff,(const gchar *)"",(gint)-1);
		g_print("Triangle Stopped \n");
	}
}void pentagon_button_clicked(){
	pent_buff=gtk_text_view_get_buffer(GTK_TEXT_VIEW(pent_box));
	if(pent_button_status==0){
		pent_button_status=1;
		gtk_button_set_label(GTK_BUTTON(pent_button),"Stop");
		g_print("Pentagon Started \n");
		const char *tt=gtk_entry_get_text((GtkEntry *)pent_entry);
		int x=atoi(tt);
		g_print("%d\n",x);
		gtk_text_buffer_set_text(pent_buff,(const gchar *)"",(gint)-1);
		pthread_t tid3;
		pthread_create(&tid3, &attr, Pentagon, &x);
		pthread_join(tid3,NULL);
		
		char local[100000];
		strcpy(local,"");
		for(int i=1;i<=x;i++){
			// printf("%ld\n",sq[i]);
			char loc[20];
			sprintf(loc,"%d\n",pen[i]);
			strcat(local,loc);
		}
		// printf("%s",local);
		gtk_text_buffer_set_text(pent_buff,(const gchar *)local,(gint)-1);
	}
	else{
		pent_button_status=0;
		gtk_button_set_label(GTK_BUTTON(pent_button),"Start");
		// gtk_text_buffer_set_text(pent_buff,(const gchar *)"",(gint)-1);
		g_print("Pantagone Series Stopped \n");
	}
}
void hexagon_button_clicked(){
	hex_buff=gtk_text_view_get_buffer(GTK_TEXT_VIEW(hex_box));
	if(hex_button_status==0){
		hex_button_status=1;
		gtk_button_set_label(GTK_BUTTON(hex_button),"Stop");
		g_print("Hexagon Started \n");
		const char *tt=gtk_entry_get_text((GtkEntry *)hex_entry);
		int x=atoi(tt);
		g_print("%d\n",x);
		gtk_text_buffer_set_text(hex_buff,(const gchar *)"",(gint)-1);
		pthread_t tid3;
		pthread_create(&tid3, &attr, Hexagon, &x);
		pthread_join(tid3,NULL);
		
		char local[100000];
		strcpy(local,"");
		for(int i=1;i<=x;i++){
			// printf("%ld\n",sq[i]);
			char loc[20];
			sprintf(loc,"%d\n",hexo[i]);
			strcat(local,loc);
		}
		// printf("%s",local);
		gtk_text_buffer_set_text(hex_buff,(const gchar *)local,(gint)-1);
	}
	else{
		hex_button_status=0;
		gtk_button_set_label(GTK_BUTTON(hex_button),"Start");
		// gtk_text_buffer_set_text(hex_buff,(const gchar *)"",(gint)-1);
		g_print("Hexagone Series Stopped \n");
	}
}
void on_magic_clear_clicked()
{
	magic_buff=gtk_text_view_get_buffer(GTK_TEXT_VIEW(magic_box));
	if(magic_button_status==0){
		gtk_entry_set_text((GtkEntry *)magic_entry,"");
		gtk_text_buffer_set_text(magic_buff,(const gchar *)"",(gint)-1);
		g_print("Magic Clearing\n");
	}
	else{
		g_print("Still Running\n");
	}	
}
void on_fib_clear_clicked()
{
	fib_buff=gtk_text_view_get_buffer(GTK_TEXT_VIEW(fib_box));
	if(fib_button_status==0){
		gtk_entry_set_text((GtkEntry *)fib_entry,"");
		gtk_text_buffer_set_text(fib_buff,(const gchar *)"",(gint)-1);
		g_print("fib Clearing\n");
	}
	else{
		g_print("Still Running\n");
	}

}
void on_count_clear_clicked()
{
	count_buff=gtk_text_view_get_buffer(GTK_TEXT_VIEW(count_box));
	if(count_button_status==0){
		gtk_entry_set_text((GtkEntry *)count_entry,"");
		gtk_text_buffer_set_text(count_buff,(const gchar *)"",(gint)-1);
		g_print("count Clearing\n");
	}
	else{
		g_print("Still Running\n");
	}
}
void on_cat_clear_clicked()
{
	cat_buff=gtk_text_view_get_buffer(GTK_TEXT_VIEW(cat_box));
	if(catalen_button_status==0){
		gtk_entry_set_text((GtkEntry *)cat_entry,"");
		gtk_text_buffer_set_text(cat_buff,(const gchar *)"",(gint)-1);
		g_print("cat Clearing\n");
	}
	else{
		g_print("Still Running\n");
	}
}
void on_lazy_clear_clicked()
{
	lazy_buff=gtk_text_view_get_buffer(GTK_TEXT_VIEW(lazy_box));
	if(lazy_button_status==0){
		gtk_entry_set_text((GtkEntry *)lazy_entry,"");
		gtk_text_buffer_set_text(lazy_buff,(const gchar *)"",(gint)-1);
		g_print("lazy Clearing\n");
	}
	else{
		g_print("Still Running\n");
	}
}
void on_square_clear_clicked()
{
	square_buff=gtk_text_view_get_buffer(GTK_TEXT_VIEW(square_box));
	if(square_button_status==0){
		gtk_entry_set_text((GtkEntry *)square_entry,"");
		gtk_text_buffer_set_text(square_buff,(const gchar *)"",(gint)-1);
		g_print("square Clearing\n");
	}
	else{
		g_print("Still Running\n");
	}
}
void on_tri_clear_clicked()
{
	tri_buff=gtk_text_view_get_buffer(GTK_TEXT_VIEW(tri_box));
	if(tri_button_status==0){
		gtk_entry_set_text((GtkEntry *)tri_entry,"");
		gtk_text_buffer_set_text(tri_buff,(const gchar *)"",(gint)-1);
		g_print("tri Clearing\n");
	}
	else{
		g_print("Still Running\n");
	}
}
void on_pent_clear_clicked()
{
	pent_buff=gtk_text_view_get_buffer(GTK_TEXT_VIEW(pent_box));
	if(pent_button_status==0){
		gtk_entry_set_text((GtkEntry *)pent_entry,"");
		gtk_text_buffer_set_text(pent_buff,(const gchar *)"",(gint)-1);
		g_print("pent Clearing\n");
	}
	else{
		g_print("Still Running\n");
	}
}
void on_hex_clear_clicked()
{
	hex_buff=gtk_text_view_get_buffer(GTK_TEXT_VIEW(hex_box));
	if(hex_button_status==0){
		gtk_entry_set_text((GtkEntry *)hex_entry,"");
		gtk_text_buffer_set_text(hex_buff,(const gchar *)"",(gint)-1);
		g_print("hex Clearing\n");
	}
	else{
		g_print("Still Running\n");
	}
}
// called when window is closed
void on_window_destroy()
{
	g_print("Exiting\n");
    gtk_main_quit();
}


int main (int argc,char * argv[]){
	pthread_attr_init(&attr);
	
	GtkWidget * window;
	GtkBuilder * builder;
	gtk_init(&argc,&argv);
	builder=gtk_builder_new();
	gtk_builder_add_from_file(builder,"test3.glade",NULL);
	// gtk_builder_add_from_file(builder,"test.glade",NULL);
	
	window=GTK_WIDGET(gtk_builder_get_object(builder,"window"));
	gtk_builder_connect_signals(builder,NULL);
	magic_button=GTK_WIDGET(gtk_builder_get_object(builder,"magic_button"));
	fib_button=GTK_WIDGET(gtk_builder_get_object(builder,"fib_button"));
	cat_button=GTK_WIDGET(gtk_builder_get_object(builder,"cat_button"));
	count_button=GTK_WIDGET(gtk_builder_get_object(builder,"count_button"));
	lazy_button=GTK_WIDGET(gtk_builder_get_object(builder,"lazy_button"));
	square_button=GTK_WIDGET(gtk_builder_get_object(builder,"square_button"));
	tri_button=GTK_WIDGET(gtk_builder_get_object(builder,"tri_button"));
	pent_button=GTK_WIDGET(gtk_builder_get_object(builder,"pent_button"));
	hex_button=GTK_WIDGET(gtk_builder_get_object(builder,"hex_button"));

	magic_box=GTK_WIDGET(gtk_builder_get_object(builder,"magic_box"));
	fib_box=GTK_WIDGET(gtk_builder_get_object(builder,"fib_box"));
	cat_box=GTK_WIDGET(gtk_builder_get_object(builder,"cat_box"));
	count_box=GTK_WIDGET(gtk_builder_get_object(builder,"count_box"));
	lazy_box=GTK_WIDGET(gtk_builder_get_object(builder,"lazy_box"));
	square_box=GTK_WIDGET(gtk_builder_get_object(builder,"square_box"));
	tri_box=GTK_WIDGET(gtk_builder_get_object(builder,"tri_box"));
	pent_box=GTK_WIDGET(gtk_builder_get_object(builder,"pent_box"));
	hex_box=GTK_WIDGET(gtk_builder_get_object(builder,"hex_box"));

	magic_entry=GTK_WIDGET(gtk_builder_get_object(builder,"magic_input"));
	fib_entry=GTK_WIDGET(gtk_builder_get_object(builder,"fib_input"));
	cat_entry=GTK_WIDGET(gtk_builder_get_object(builder,"cat_input"));
	count_entry=GTK_WIDGET(gtk_builder_get_object(builder,"count_input"));
	lazy_entry=GTK_WIDGET(gtk_builder_get_object(builder,"lazy_input"));
	square_entry=GTK_WIDGET(gtk_builder_get_object(builder,"square_input"));
	tri_entry=GTK_WIDGET(gtk_builder_get_object(builder,"tri_input"));
	pent_entry=GTK_WIDGET(gtk_builder_get_object(builder,"pent_input"));
	hex_entry=GTK_WIDGET(gtk_builder_get_object(builder,"hex_input"));

	g_object_unref(builder);
	gtk_widget_show(window);
	gtk_main();
	return 0;
}

void * fib(void * arg){
	int n=*(int *)arg;
	printf("\nFib\n");
	ll a=0;
	ll b=1;
	// printf("%lld  ",a);
	char local[50];
	sprintf(local,"%lld\n",a);
	gtk_text_buffer_insert_at_cursor(fib_buff,local,(gint)-1);
	// printf("%lld  ",b);
	char local1[50];
	sprintf(local1,"%lld\n",b);
	gtk_text_buffer_insert_at_cursor(fib_buff,local1,(gint)-1);
	for(int i=0;i<n;i++){
		int tmp=a;
		a=b;
		b=b+tmp;
		// printf("%lld  ",b);
		char local2[50];
		sprintf(local2,"%lld\n",b);
		gtk_text_buffer_insert_at_cursor(fib_buff,local2,(gint)-1);
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
	printf("Magic\n");
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
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<n;j++){
	// 		printf("%d\t",array[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("Hello");
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
		// printf("row(%d)\n",sum);
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
	// printf("-ve Digonal(",sum,")\n");
	int chk=1;
	int cloacl=0,dlocal=0;
	check_array[check_array_counter++]=sum;
	for(int i=0;i<check_array_counter;i++){
		// printf("%d ",check_array[i]);
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
		gtk_text_buffer_insert_at_cursor(magic_buff,"\nYes\n",(gint)-1);
		for(int i=0;i<check_array_counter;i++){
			printf("%d  ",check_array[i]);
			char local[100];
			sprintf(local,"%d  ",check_array[i]);
			gtk_text_buffer_insert_at_cursor(magic_buff,local,(gint)-1);

		}
	}
	// printf("\n");
	// gtk_text_buffer_insert_at_cursor(magic_buff,(const gchar *)"\n",(gint)-1);
	if(chk==1){
		printf("\n------------\n");
		gtk_text_buffer_insert_at_cursor(magic_buff,(const gchar *)"\n-----------------\n",(gint)-1);
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				printf("%d\t",array[i][j]);
				char local[100];
				sprintf(local,"%d\t",array[i][j]);
				gtk_text_buffer_insert_at_cursor(magic_buff,(const gchar *)local,(gint)-1);

			}
			gtk_text_buffer_insert_at_cursor(magic_buff,(const gchar *)"\n",(gint)-1);
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
	// printf("%lld ",q);
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
	pthread_t sid[n];
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
	pthread_t tid[n];
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
	pthread_t peid[n];
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
	pthread_t hid[n];
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
void * countandSay(void * arg){
	int n=*(int *)arg;	
	char *a = malloc(2), *b = 0, *x, c;
	int cnt, len = 1;
 	int count=0;
	for (sprintf(a, "1"); (b = realloc(b, len * 2 + 1)); a = b, b = x) {
		x = a;
		// puts(x);
		// printf("%s\n",x);
		char local[100000];
		sprintf(local,"%s\n",x);
		// printf("%s",local);
		gtk_text_buffer_insert_at_cursor(count_buff,(const gchar *)&local,(gint)-1);
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
	pthread_exit(NULL);
	return NULL;
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