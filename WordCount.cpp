#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char *argv[])
{
    if( argc == 3 ){
        //���Զ�ȡ�ļ�������
        char data;
        FILE *fp = fopen(argv[2],"r");

        if(!fp){
            printf("�����ļ���ȡʧ��\n");
            return -1;
        }

        //�Բ��������ж�

        if( !strcmp(argv[1],"-c") ){
			//�ַ���
            char temp;
            int num = 0;
            temp = fgetc(fp);
            while( temp != EOF ){
                //putchar(temp);
                temp = fgetc(fp);
                num++;
            }
            printf("���ı��ļ����ַ���Ϊ��%d\n",num);
        }
        else if( !strcmp(argv[1],"-w") ){
			//������
            int w = 0;
            char a = fgetc(fp);
            while( a != EOF){
                if( (a >='a' && a <='z') || ( a >='A' && a <='Z') || ( a >='0' && a <='9') ){
                    while( (a >='a' && a <='z') || ( a >='A' && a <='Z') || ( a >='0' && a <='9') )
                        a =fgetc(fp);
                    w++;
                    a =fgetc(fp);
                }
                else
                    a =fgetc(fp);
            }
            printf("���ı��ļ��ĵ�����Ϊ��%d\n",w);
        }
        else{
            printf("���󣺲���������Χ��\n");
            printf("����������-c��-w\n");
        }
        int n=fclose(fp);
    }
    else{
        printf("�������в�������Ҫ3��\n");
        printf("�÷���WordCount.exe [parameter] [file_name]\n");
    }
    system("pause");
    return 0;
}