#include<stdio.h>
int main ()
{
	int matA[3][3];
	int matB[3][3];
	int result[3][3];
		int i,j;
	
    for( i=0;i<3;i++){
		for( j=0;j<3;j++){
			printf("enter the value of element at %d row and %d coloumn",i+1,j+1);
			scanf("%d",&matA[i][j]);}
		}
			 for( i=0;i<3;i++){
		for( j=0;j<3;j++){
			printf("enter the value of element at %d row and %d coloumn",i+1,j+1);
			scanf("%d",&matB[i][j]);}


}
	
	for( i=0;i<3;i++){
		for( j=0;j<3;j++){
			result[i][j]=0;
			
		
		for( int k=0;k<3;k++){
		result[i][j]+=matA[i][k]*matB[k][j];}
}
}
	
		for( i=0;i<3;i++){
		for( int j=0;j<3;j++){
			printf("%d\t",result[i][j]);}
			printf("\n");
	
}
}
	
	
	
	
	
	
