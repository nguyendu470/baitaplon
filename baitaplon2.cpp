#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

struct book_st{
	char ten[30];
	char theloai[30];
	int giatien;
}booklist,tempt;
void nhapsach(book_st *booklist,int n);
void hoanVi(book_st &book1, book_st &book2);
void sapxep(book_st *booklist,int n);
void xuatChiTietCuonSach(book_st *booklist, int n);
int thongke(book_st *booklist,int n);
void xuatthongke(book_st *booklist,int n);
void timsach(book_st *booklist,int n);
void xuatsachdatim(book_st *booklist,int n);


int main(){
	int n=3;
    book_st *booklist = (struct book_st *)malloc(n * sizeof(struct book_st));
	nhapsach(booklist,n);
	 //xuatChiTietCuonSach(booklist,n);
	//xuatthongke(booklist,n);
	timsach(booklist,n);
	return 0;
}
void nhapsach(book_st *booklist,int n){
	for(int i=0;i<3;i++){
		printf("\t\tNHAP THONG TIN SACH %d",i);
		fflush(stdin);
		printf("\nnhap ten sach: ");
		gets(booklist->ten);
		fflush(stdin);
		printf("\nnhap the loai: ");
		gets(booklist->theloai);
		fflush(stdin);
		printf("\nnhap gia tien: ");
		scanf("%d",&booklist->giatien);
		
	}
}

void sapxep(book_st *booklist,int n){
	book_st tempt;
	for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(strcmp(booklist[j].theloai,booklist[j+1].theloai)<0){
            	
             tempt = booklist[j];
             booklist[j]=booklist[j+1];
             booklist[j+1] = tempt;
            }
        }
	}
}

void xuatChiTietCuonSach(book_st *booklist, int n){
     sapxep(booklist,n);
     printf("STT\t ten\t theloai\t giatien\n");
    for(int i=0;i<n;i++){
    
        printf("%d\t %s\t\t %s\t\t %d\n",i,booklist[i].ten,booklist[i].theloai,booklist[i].giatien);
    }
    
}
int thongke(book_st *booklist,int n){
	char theloai[100];
	int dem=0;
    for(int i=0;i<n;i++)
    {
	 if(strcmp(theloai,booklist[i].theloai) == 1)
        {
            dem ++;
        }    
    }
    return dem;
}
void xuatthongke(book_st *booklist,int n)
{
	int dem = thongke(booklist,n);
	for(int i=0;i<n;i++){
	printf("\nthe loai %s co so %d quyen",booklist[i].theloai,dem);
}
}
void timsach(book_st *booklist,int n){
	char theloai[30];
    printf("\n Nhap the loai : ");
    fflush(stdin);
    gets(theloai);
    for(int i=0;i<n;i++)
    {
	 if(strcmp(theloai,booklist[i].theloai)==0)
 		{
		 printf("\t ten\t theloai\t giatien\n");
		 printf("\t %s\t\t %s\t\t %d\n",booklist[i].ten,booklist[i].theloai,booklist[i].giatien);
      }
	  if(strcmp(theloai,booklist[i].theloai)!=0){
  		printf("\nkhong co cuon sach thuoc the loai nay");
  	}   
    }
    
}
