#include <stdio.h>
#include <string.h>
struct mac{
        char b_isim[20];char s_isim[20];char kazanan[20];char acilis[20];int b_sure;int s_sure;int hamle_say;
    }mac1,mac2,mac3,mac4,mac5,mac6,mac7;
void create_file(FILE* fptr);
void renk(struct mac **maclar);
void siralama(struct mac **maclar);
int main()
{
    
    struct mac *maclar[20];
    maclar[0]=&mac1;maclar[1]=&mac2;
    maclar[2]=&mac3;maclar[3]=&mac4;
    maclar[4]=&mac5;maclar[5]=&mac6;maclar[6]=&mac7;
    FILE *fptr;
    create_file(fptr);
    fptr = fopen("kaynak.txt","r");
    fseek(fptr, 53,SEEK_SET);

    int i;
    for(i=0;i<7;i++){
       fscanf(fptr,"%s%s%s%s%d%d%d",maclar[i]->b_isim,maclar[i]->s_isim,maclar[i]->kazanan,maclar[i]->acilis,&maclar[i]->b_sure,&maclar[i]->s_sure,&maclar[i]->hamle_say);
       printf("%s%s%s%s%d%d%d",maclar[i]->b_isim,maclar[i]->s_isim,maclar[i]->kazanan,maclar[i]->acilis,maclar[i]->b_sure,maclar[i]->s_sure,maclar[i]->hamle_say);
    }
    renk(maclar);
    siralama(maclar);
    fclose(fptr);
    return 0;
}

void siralama(struct mac **maclar){
    struct kisiler{
        int kaz[2];
        int kayip[2];
        int draw[2];
        int point;
        int mean_move_speed;
    }mert;
    mert.kaz[0]=0;mert.kaz[1]=0;
    int i = 0;
    for(i=0;i<7;i++){
        if(!strcmp("b",maclar[i]->kazanan)){
            if(!strcmp("Mert-Keskin",maclar[i]->b_isim)){
                mert.kaz[0]++;
                mert.mean_move_speed=((10*60-maclar[i]->b_sure)/(maclar[i]->hamle_say/2));
                printf("%d%d",mert.kaz[0],mert.mean_move_speed);
            }
        }
    }
}


void renk(struct mac **maclar){
    int b=0;
    int s=0;
    int i=0;
    for(i=0;i<7;i++){
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
    fputs("b_isim\ts_isim\tkazanan\tvaryant\tb_sure\ts_sure\thamle_say\n",fptr);
    fputs("Mert-Keskin\tAli-Murat\tb\titalyan-oyunu\t34\t32\t30\n",fptr);
    fputs("Zeynep-Turgut\tUmur-Kiris\ts\tfransiz-savunmasi\t34\t32\t30\n",fptr);
    fputs("Zeynep-Turgut\tMert-Keskin\ts\tsicilya-defansi\t34\t32\t30\n",fptr);
    fputs("Umur-Kiris\tAli-Murat\tb\truy-lopez-acilisi\t34\t32\t30\n",fptr);
    fputs("Ali-Murat\tUmur-Kiris\tb\truy-lopez-acilisi\t34\t32\t30\n",fptr);
    fputs("Izzet-Korkmaz\tEge-Kuzu\td\tsah-hint-savunmasi\t34\t32\t30\n",fptr);
    fputs("Ege-Kuzu\tIzzet-Korkmaz\tb\tvezir-gambiti\t34\t32\t30\n",fptr);
    fclose(fptr);
}