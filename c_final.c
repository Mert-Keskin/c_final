#include <stdio.h>
#include <string.h>
struct mac{
        char b_isim[20];char s_isim[20];char kazanan[20];
    }mac1,mac2,mac3,mac4;
void create_file(FILE* fptr);
void renk(struct mac **maclar);

int main()
{
    
    struct mac *maclar[20];
    maclar[0]=&mac1;maclar[1]=&mac2;
    maclar[2]=&mac3;maclar[3]=&mac4;
    FILE *fptr;
    create_file(fptr);
    fptr = fopen("kaynak.txt","r");
    fseek(fptr, 21,SEEK_SET);

    int i;
    for(i=0;i<4;i++){
       fscanf(fptr,"%s%s%s",maclar[i]->b_isim,maclar[i]->s_isim,maclar[i]->kazanan);
    }
    renk(maclar);
    fclose(fptr);
    return 0;
}

void renk(struct mac **maclar){
    int b=0;
    int s=0;
    int i=0;
    for(i=0;i<4;i++){
        if(!strcmp("b",maclar[i]->kazanan)){
            b++;
        }
        else if(!strcmp("s",maclar[i]->kazanan))
            s++;
    }
    printf("toplam siyah galibiyeti = %d\ntoplam beyaz galibiyeti = %d",s,b);
}

void create_file(FILE* fptr){
    fptr = fopen("kaynak.txt","w");
    fputs("b_isim\ts_isim\tkazanan\n",fptr);
    fputs("mert-keskin\tali-murat\tb\n",fptr);
    fputs("zeynep-turgut\tumur-kiris\ts\n",fptr);
    fputs("zeynep-turgut\tmert-keskin\ts\n",fptr);
    fputs("umur-kiris\tali-murat\tb\n",fptr);
    fclose(fptr);
}