#include <iostream>

int main()

{

    std::cout << "Hello World!\n";
    char s1[256];
    char s2[256];
    char s[512];
    char f[] = "%s";
    _asm {
        //считывание первой строки
        lea ebx, s1
        push ebx
        lea ecx, f
        push ecx
        call scanf
        add esp, 8
        //считывание второй строки
        lea ebx, s2
        push ebx
        lea ecx, f
        push ecx
        call scanf
        add esp, 8
        //подготовка к циклу записи первой строки
        lea ebx, s1
        mov ecx, -1
        dec ebx
        lea edx, s
        dec edx
        //цикл записи первой строки в суммарную
        b1:
        inc ecx
        inc ebx
        inc edx
        mov al, [ebx]
        mov [edx], al
        cmp al, 0
        jnz b1
        //подготовка к циклу записи первой строки
        lea ebx, s2
        dec ebx
        dec edx
        //цикл записи второй строки в суммарную
        b2:
        inc ebx
        inc edx
        mov al, [ebx]
        mov [edx], al
        cmp al, 0
        jnz b2
        //вывод суммароной строки
        lea ebx, s
        push ebx
        lea ecx, f
        push ecx
        call printf
        add esp, 8
    }
}