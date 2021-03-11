#include<stdio.h>
#include <math.h>

typedef struct rectangleVertices {
    float x1,y1;
    float x2,y2;
    float x3,y3;
    float area;

}Rectangle;

Rectangle input_one_rectangle() {
    Rectangle temp;
    scanf("%f%f%f%f%f%f",&temp.x1,&temp.y1,&temp.x2,&temp.y2,&temp.x3,&temp.y3);
    return temp;
}

void input_n_rectangles(int size, Rectangle rectangle[size]) {
    for(int i=0;i< size;i++) {
        rectangle[i]=input_one_rectangle();
    }
}

float compute_distance(float x1, float y1, float x2, float y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

float compute_area(float l, float b) {
    return l*b;
}

void cyclicSwap(float* a, float* b, float* c) 
{ 
    float temp = *b; 
    *b = *a; 
    *a = *c; 
    *c = temp; 
} 

void compute_one_rectangle(Rectangle *rectangle) {
    float l=compute_distance(rectangle->x1,rectangle->y1,rectangle->x2,rectangle->y2);
    float b=compute_distance(rectangle->x1,rectangle->y1,rectangle->x3,rectangle->y3);
    float h=compute_distance(rectangle->x2,rectangle->y2,rectangle->x3,rectangle->y3);

    if (l>b && l>h) {
        rectangle->area=compute_area(b,h);
    }
    else if ( b>l && b>h) {
        rectangle->area=compute_area(l,h);
    }
    else {
        rectangle->area=compute_area(l,b);
    }    
}

void compute_n_rectangles(int size, Rectangle rectangle[size]) {
    for(int i=0;i< size;i++) {
        compute_one_rectangle(&rectangle[i]);
    }
}

void print_one_rectangle(Rectangle rectangle) {
    printf("Area of rectangle with vertices (%.1f,%.1f), (%.1f,%.1f), (%.1f,%.1f) is %.1f\n", rectangle.x1,rectangle.y1,rectangle.x2,rectangle.y2,rectangle.x3,rectangle.y3,rectangle.area);
}

void print_n_rectangles(int size, Rectangle rectangle[size]){
    for(int i=0;i< size;i++) {
        print_one_rectangle(rectangle[i]);
    }
}

int main() {
    int n_points;
    scanf("%d",&n_points);
    Rectangle rectangles[n_points];
    input_n_rectangles(n_points, rectangles);
    compute_n_rectangles(n_points, rectangles);
    print_n_rectangles(n_points, rectangles);

    return 0;
}