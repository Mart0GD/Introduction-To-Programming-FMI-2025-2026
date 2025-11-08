    #include <stdio.h>

    int main(){

        unsigned int n;
        printf("Insert n: "); 
        if(scanf("%u", &n) != 1){
            printf("Invalid input!");
            return -1;
        }

        if(n == 0) printf("0\n");
        else if(n == 1) printf("1\n");
        else if(n == 2) printf("1\n");
        else {
            const int START_NUMBER = 2; // we should be at the third number
            int prev_1 = 1, prev_2 = 1; 


            int temp;
            for (int i = START_NUMBER; i < n; i++)
            {
                temp = prev_1;

                prev_1 = prev_2;
                prev_2 = prev_2 + temp;        
            }

            printf("%d\n", prev_2);
        }

        return 0;
    }