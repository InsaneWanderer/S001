#include <iostream>

int main()

{

    std::cout << "Hello World!\n";
    char s1[256];
    char s2[256];
    char s[512];
    char f[] = "%s";
    _asm {
        //���������� ������ ������
        lea ebx, s1
        push ebx
        lea ecx, f
        push ecx
        call scanf
        add esp, 8
        //���������� ������ ������
        lea ebx, s2
        push ebx
        lea ecx, f
        push ecx
        call scanf
        add esp, 8
        //���������� � ����� ������ ������ ������
        lea ebx, s1
        mov ecx, -1
        dec ebx
        lea edx, s
        dec edx
        //���� ������ ������ ������ � ���������
        b1:
        inc ecx
        inc ebx
        inc edx
        mov al, [ebx]
        mov [edx], al
        cmp al, 0
        jnz b1
        //���������� � ����� ������ ������ ������
        lea ebx, s2
        dec ebx
        dec edx
        //���� ������ ������ ������ � ���������
        b2:
        inc ebx
        inc edx
        mov al, [ebx]
        mov [edx], al
        cmp al, 0
        jnz b2
        //����� ���������� ������
        lea ebx, s
        push ebx
        lea ecx, f
        push ecx
        call printf
        add esp, 8
    }
}