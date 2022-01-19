/*
#include <stdio.h>
#include <math.h>       // �������� ���ϴ� sqrt �Լ��� ȣ���Ϸ��� �ʿ��ϴ�.

struct point {          // point ����ü�� line ����ü���� �տ� ���ǵǾ�� �Ѵ�.
    int x, y;
};
struct line {           // point ����ü�� �̿��ؼ� line ����ü�� �����Ѵ�.
    struct point start, end;    
};
void print_point(const struct point* ptr);
double get_length(const struct line* ptr);

void main()
{
    struct line ln1 = { 
        {10, 20}, {30, 40}      // start�� {10, 20}���� end�� {30, 40}���� �ʱ�ȭ
    };   
    printf("���� ����: ");
    print_point(&ln1.start);    // ln1.start�� point ����ü ������ ����� �� �ִ�.                    
    print_point(&ln1.end);      // ln1.end�� point ����ü ������ ����� �� �ִ�.  
    printf("\n����: %f\n", get_length(&ln1));     // line ����ü�� �ּҸ� �����Ѵ�.
}

void print_point(const struct point* ptr)
{
    printf("(%d, %d) ", ptr->x, ptr->y);
}

double get_length(const struct line* ptr)   // ptr�� �Է� �Ű�����
{
    int dx = ptr->end.x - ptr->start.x;     // ���� �� �����ؼ� ����� ������ �� �ִ�.
    int dy = ptr->end.y - ptr->start.y;
    return sqrt(dx * dx + dy * dy);     // sqrt�� �������� ���ϴ� ǥ�� C ���̺귯�� �Լ�
}
*/