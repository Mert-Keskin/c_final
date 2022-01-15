#include <stdio.h>
#include <string.h>
struct mac{
        char b_isim[20];char s_isim[20];char kazanan[20];char acilis[20];int b_sure;int s_sure;int hamle_say;
    }mac1,mac2,mac3,mac4,mac5,mac6,mac7,mac8;
void create_file(FILE* fptr);
void renk(struct mac **maclar);
void siralama(struct mac **maclar);
int main()
{
    
    struct mac *maclar[20];
    maclar[0]=&mac1;maclar[1]=&mac2;
    maclar[2]=&mac3;maclar[3]=&mac4;
    maclar[4]=&mac5;maclar[5]=&mac6;maclar[6]=&mac7;
    maclar[7]=&mac8;
    FILE *fptr;
    create_file(fptr);
    fptr = fopen("kaynak.txt","r");
    fseek(fptr, 53,SEEK_SET);

    int i;
    for(i=0;i<8;i++){
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
        int sure;
        int hamle;
        int mean_move_speed;
    }mert,zeynep,umur,ali,izzet;
    mert.kaz[0]=0;mert.kaz[1]=0;mert.sure=0;mert.hamle=0;
    zeynep.kaz[0]=0;zeynep.kaz[1]=0;zeynep.sure=0;zeynep.hamle=0;
    umur.kaz[0]=0;umur.kaz[1]=0;umur.sure=0;umur.hamle=0;
    ali.kaz[0]=0;ali.kaz[1]=0;ali.sure=0;ali.hamle=0;
    izzet.kaz[0]=0;izzet.kaz[1]=0;izzet.sure=0;izzet.hamle=0;
    int i = 0;
    for(i=0;i<8;i++){
        if(!strcmp("b",maclar[i]->kazanan)){
            if(!strcmp("Mert-Keskin",maclar[i]->b_isim)){
                mert.kaz[0]++;mert.sure+=maclar[i]->b_sure;mert.hamle+=maclar[i]->hamle_say;
            }
            else if(!strcmp("Zeynep-Turgut",maclar[i]->b_isim)){
                zeynep.kaz[0]++;zeynep.sure+=maclar[i]->b_sure;zeynep.hamle+=maclar[i]->hamle_say;
            }
            else if(!strcmp("Umur-Kiris",maclar[i]->b_isim)){
                umur.kaz[0]++;umur.sure+=maclar[i]->b_sure;umur.hamle+=maclar[i]->hamle_say;
            }
            else if(!strcmp("Ali-Murat",maclar[i]->b_isim)){
                ali.kaz[0]++;ali.sure+=maclar[i]->b_sure;ali.hamle+=maclar[i]->hamle_say;
            }
            else if(!strcmp("Izzet-Korkmaz",maclar[i]->b_isim)){
                izzet.kaz[0]++;izzet.sure+=maclar[i]->b_sure;izzet.hamle+=maclar[i]->hamle_say;
            }
        }
        else if(!strcmp("s",maclar[i]->kazanan)){
            if(!strcmp("Mert-Keskin",maclar[i]->s_isim)){
                mert.kaz[1]++;mert.sure+=maclar[i]->s_sure;mert.hamle+=maclar[i]->hamle_say;
            }
            else if(!strcmp("Zeynep-Turgut",maclar[i]->s_isim)){
                zeynep.kaz[1]++;zeynep.sure+=maclar[i]->s_sure;zeynep.hamle+=maclar[i]->hamle_say;
            }
            else if(!strcmp("Umur-Kiris",maclar[i]->s_isim)){
                umur.kaz[1]++;umur.sure+=maclar[i]->s_sure;umur.hamle+=maclar[i]->hamle_say;
            }
            else if(!strcmp("Ali-Murat",maclar[i]->s_isim)){
                ali.kaz[1]++;ali.sure+=maclar[i]->s_sure;ali.hamle+=maclar[i]->hamle_say;
            }
            else if(!strcmp("Izzet-Korkmaz",maclar[i]->s_isim)){
                izzet.kaz[1]++;izzet.sure+=maclar[i]->s_sure;izzet.hamle+=maclar[i]->hamle_say;
            }
        }
    }
    struct kisiler *ptrkisiler[5];
    ptrkisiler[0]=&mert;ptrkisiler[1]=&ali;ptrkisiler[2]=&umur;
    ptrkisiler[3]=&zeynep;ptrkisiler[4]=&izzet;
    int a;
    for(a=0;a<5;a++){
        int puan = (ptrkisiler[a]->kaz[0]+ptrkisiler[a]->kaz[1])*2;
        int orthiz = (60*10-ptrkisiler[a]->sure)/(ptrkisiler[a]->hamle/2);
        printf("\nPuan\tBeyazlarda kazanc\tSiyahlarda Kazanc\tOrtalama hamle hizi\n%d\t%d\t%d\t%d\n",puan,ptrkisiler[a]->kaz[0],ptrkisiler[a]->kaz[1],orthiz);
    }
    
}


void renk(struct mac **maclar){
    int b=0;
    int s=0;
    int i=0;
    for(i=0;i<8;i++){
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
    fputs("Izzet-Korkmaz\tAli-Murat\tb\tsah-hint-savunmasi\t34\t32\t30\n",fptr);
    fputs("Ali-Murat\tIzzet-Korkmaz\tb\tvezir-gambiti\t34\t32\t30\n",fptr);
    fputs("Izzet-Korkmaz\tZeynep-Turgut\ts\tvezir-gambiti\t34\t32\t30\n",fptr);
    //fputs("Ali-Murat\tMert-Keskin\tb\titalyan-oyunu\t34\t32\t30\n",fptr);
    fclose(fptr);
}