// point.h : ��ũ��, ����ü, typedef�� ���Ǵ� ��� ���Ͽ� �־��ش�.
#pragma once
typedef struct point {      // �Լ� ���𺸴� �տ� point ����ü�� ���ǵǾ�� �Ѵ�.
    int x, y;
} point_t;

void print_point(const point_t* ptr);       // point ����ü�� ���õ� �Լ��� ����
void move_point(point_t* ptr, int offset);