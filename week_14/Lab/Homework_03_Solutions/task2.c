#include "stdio.h"
#include "stdlib.h"

void crop(int color, int** image, int* width, int* height);

void cut_first_rows(int color, int** image, int width, int* height);
void cut_last_rows(int color, int** image, int width, int* height);

void cut_first_cols(int color, int** image, int* width, int height);
void cut_last_cols(int color, int** image, int* width, int height);

void print(const int* image, const int width, const int height);

int main(){

    int color;
    printf("Insert color: ");
    if(scanf("%d", &color) != 1) return -1;

    int width, height;
    printf("Insert width and height: ");
    if(scanf("%d %d", &width, &height) != 2){
        puts("Invalid input!");
        return -1;
    } 

    int* image = (int*)malloc((width * height) * sizeof(int));
    if(!image) return -1;

    printf("Insert image: \n");
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; j++)
        {
            if(scanf("%d", &image[i * width + j]) != 1){
                return -1;
            }
        }
        
    }
    
    crop(color, &image, &width, &height);

    puts("Cropped image:");
    print(image, width, height);

    free(image);
    return 0;
}   

void crop(int color, int** image, int* width, int* height){
    if (!image || !*image || !width || !height || *width <= 0 || *height <= 0) return;

    cut_first_rows(color, image, *width, height);
    cut_last_rows(color, image, *width, height);

    cut_first_cols(color, image, width, *height);         
    cut_last_cols(color, image, width, *height); 
}


void cut_first_rows(int color, int** image, int width, int* height){
    if(!image || !height || *height == 0) return;

    int size = width * (*height);

    int cut;
    do
    {
        cut = 1;
        for (int i = 0; i < width; i++)
        {
            if((*image)[i] != color){
                cut = 0;
                break;
            }
        }

        if(!cut) break;

        for (int i = 0; i < size - width; i++)
        {
            (*image)[i] = (*image)[i + width];
        }

        --(*height);
    } while (*height > 0);
    
    
}

void cut_last_rows(int color, int** image, int width, int* height){
    if(!image || !height || *height == 0) return;

    int size = width * (*height);

    int cut;
    do
    {
        cut = 1;
        for (int i = 0; i < width; i++)
        {
            if((*image)[i + size - width] != color){
                cut = 0;
                break;
            }
        }

        if(!cut) break;

        --(*height);
    } while (*height > 0);
    
    
}

void cut_first_cols(int color, int** image, int* width, int height){
    if(!image || !width || *width <= 0 || height <= 0) return;

    int size = (*width) * height;
    int cut;

    do
    {
        cut = 1;
        for (int i = 0; i < height; i++)
        {
            if((*image)[i * (*width)] != color){
                cut = 0;
                break;
            }
        }

        if(!cut) return;

        for (int i = 0; i < height; i++)
        {
            for (int j = 1; j < *width; j++)
            {
                (*image)[i * (*width - 1) + (j - 1)] = (*image)[i * *width + j];
            }
        }

        --(*width);
    } while (*width > 0);
    
}

void cut_last_cols(int color, int** image, int* width, int height){
    if(!image || !width || *width <= 0 || height <= 0) return;

    int size = (*width) * height;
    int cut;

    do
    {
        cut = 1;
        for (int i = 0; i < height; i++)
        {
            if ((*image)[i * *width + (*width - 1)] != color)
            {
                cut = 0;
                break;
            }
        }

        if (!cut) break;

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < *width - 1; j++)
            {
                (*image)[i * (*width - 1) + j] =
                    (*image)[i * *width + j];
            }
        }

        --(*width);

    } while (*width > 0);

}

void print(const int* image, const int width, const int height){
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            printf("%d ", image[i * width + j]);
        }
        putchar('\n');
    }
    
}