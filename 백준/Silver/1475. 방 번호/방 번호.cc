#include <stdio.h>

int arr[10];
int main()
{
	int n;
	scanf("%d", &n);
	while (n){
		arr[n%10]++;
		n /= 10; // n=n/10;
	}
	
	int tmp=(arr[6]+arr[9]+1)/2; //6과 9의 갯수를 반으로 나눔/ +1은 홀,짝 모두 맞는 값이 나오도록 
	
	for(int i=0; i<10; i++){
		if(i !=9 && i !=6){
			if(arr[i] > tmp)
			tmp = arr[i];
		}
	} 
	printf("%d\n",tmp);
}