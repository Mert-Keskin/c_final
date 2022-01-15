#include <stdio.h>
#include <string.h>
struct mac{
        char b_isim[20];char s_isim[20];char kazanan[20];char acilis[20];int b_sure;int s_sure;int hamle_say;
    }mac1,mac2,mac3,mac4,mac5,mac6,mac7,mac8,mac9,mac10,mac11,mac12,mac13,mac14,mac15,mac16,mac17,mac18,mac19,mac20;
void create_file(FILE* fptr);
void siralama(struct mac **maclar);
void renk(struct mac **maclar);
void acilis(struct mac **maclar);
int main()
{
    
    struct mac *maclar[20];
    maclar[0]=&mac1;maclar[1]=&mac2;maclar[13]=&mac14;maclar[14]=&mac15;
    maclar[2]=&mac3;maclar[3]=&mac4;maclar[15]=&mac16;maclar[16]=&mac17;
    maclar[4]=&mac5;maclar[5]=&mac6;maclar[6]=&mac7;maclar[17]=&mac18;
    maclar[7]=&mac8;maclar[8]=&mac9;maclar[9]=&mac10;maclar[18]=&mac19;
    maclar[10]=&mac11;maclar[11]=&mac12;maclar[12]=&mac13;maclar[19]=&mac20;
    FILE *fptr;
    create_file(fptr);
    fptr = fopen("kaynak.txt","r");
    fseek(fptr, 53,SEEK_SET);

    int i;
    for(i=0;i<20;i++){
       fscanf(fptr,"%s%s%s%s%d%d%d",maclar[i]->b_isim,maclar[i]->s_isim,maclar[i]->kazanan,maclar[i]->acilis,&maclar[i]->b_sure,&maclar[i]->s_sure,&maclar[i]->hamle_say);
    }
    siralama(maclar);
    renk(maclar);
    acilis(maclar);
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
    for(i=0;i<20;i++){
        if(!strcmp("b",maclar[i]->kazanan)){
            if(!strcmp("Mert-Keskin",maclar[i]->b_isim)){
                mert.kaz[0]++;mert.sure+=maclar[i]->b_sure;mert.hamle+=maclar[i]->hamle_say;
            }
            else if(!strcmp("Zeynep-Turgut",maclar[i]->b_isim)){
                zeynep.kaz[0]++;zeynep.sure+=maclar[i]->b_sure;zeynep.hamle+=maclar[i]->hamle_say;
            }
            else if(!strcmp("Umur-Kuris",maclar[i]->b_isim)){
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
            else if(!strcmp("Umur-Kuris",maclar[i]->s_isim)){
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
    ptrkisiler[0]=&zeynep;ptrkisiler[1]=&mert;ptrkisiler[2]=&umur;
    ptrkisiler[3]=&izzet;ptrkisiler[4]=&ali;
    int a;
    char isimler[5][20];
    strcpy(isimler[0],"Zeynep Turgut");strcpy(isimler[1],"Mert Keskin");strcpy(isimler[2],"Umur Kuris");
    strcpy(isimler[3],"Izzet Korkmaz");strcpy(isimler[4],"Ali Murat");
    FILE *f2ptr;
    f2ptr=fopen("hedef.txt","w");
    fprintf(f2ptr,"%s","\n-------------------------Kisilere Gore Analiz--------------------------------");
    for(a=0;a<5;a++){
        int puan = (ptrkisiler[a]->kaz[0]+ptrkisiler[a]->kaz[1])*2;
        int orthiz = (60*10*8-ptrkisiler[a]->sure)/(ptrkisiler[a]->hamle/2);
        fprintf(f2ptr,"\nIsim\t\tPuan\t\tBeyazlarda kazanc\tSiyahlarda Kazanc\tOrtalama hamle hizi\n%s\t%d\t\t\t\t\t%d\t\t\t\t\t%d\t\t\t\t\t%d\n",isimler[a],puan,ptrkisiler[a]->kaz[0],ptrkisiler[a]->kaz[1],orthiz);
    }
    fclose(f2ptr);
}


void renk(struct mac **maclar){
    FILE *f2ptr;
    f2ptr=fopen("hedef.txt","a");
    int b=0;
    int s=0;
    int i=0;
    for(i=0;i<20;i++){
        if(!strcmp("b",maclar[i]->kazanan)){
            b++;
        }
        else if(!strcmp("s",maclar[i]->kazanan))
            s++;
    }
    fprintf(f2ptr,"%s","\n------------------Renge Gore Analiz--------------------\n");
    fprintf(f2ptr,"Toplam siyah galibiyeti = %d\nToplam beyaz galibiyeti = %d",s,b);
    fclose(f2ptr);
}

void acilis(struct mac **maclar){
    int vezir[2]={0,0};int ital[2]={0,0};int hint[2]={0,0};int ruy[2]={0,0};int sic[2]={0,0};
    int*acilislar[5];
    acilislar[0]=vezir;acilislar[1]=ital;acilislar[2]=hint;acilislar[3]=ruy;acilislar[4]=sic;
    FILE *f2ptr;
    f2ptr=fopen("hedef.txt","a");
    int b=0;
    int s=0;
    int i=0;
    for(i=0;i<20;i++){
        if(!strcmp("vezir-gambiti",maclar[i]->acilis)){
            if(!strcmp("b",maclar[i]->kazanan))
                vezir[0]++;
            else
                vezir[1]++;
        }
        else if(!strcmp("italyan-oyunu",maclar[i]->acilis)){
            if(!strcmp("b",maclar[i]->kazanan))
                ital[0]++;
            else
                ital[1]++;
        }
        else if(!strcmp("sicilya-defansi",maclar[i]->acilis)){
            if(!strcmp("b",maclar[i]->kazanan))
                sic[0]++;
            else
                sic[1]++;
        }
        else if(!strcmp("ruy-lopez-acilisi",maclar[i]->acilis)){
            if(!strcmp("b",maclar[i]->kazanan))
                ruy[0]++;
            else
                ruy[1]++;
        }
        else if(!strcmp("sah-hint-savunmasi",maclar[i]->acilis)){
            if(!strcmp("b",maclar[i]->kazanan))
                hint[0]++;
            else
                hint[1]++;
        }
    }
    char isimler[5][20];
    strcpy(isimler[0],"Vezir Gambiti");strcpy(isimler[1],"Italyan Oyunu");strcpy(isimler[2],"Sicilya Defansi");
    strcpy(isimler[3],"Ruy Lopez Acilisi");strcpy(isimler[4],"Sah Hint Savunmasi");
    fprintf(f2ptr,"%s","\n\n-----------------Acilisa Gore Analiz-------------------\nAcilis ismi\t\tbeyaz galibiyet sayisi\t\tsiyah galibiyet sayisi\n\n");
    int a;
    for(a=0;a<5;a++){
        fprintf(f2ptr,"%s\t\t\t\t%d\t\t\t\t\t%d\n",isimler[a],acilislar[a][0],acilislar[a][1]);
        }
    fclose(f2ptr);
}

void create_file(FILE* fptr){
    fptr = fopen("kaynak.txt","w");
    fputs("b_isim\ts_isim\tkazanan\tvaryant\tb_sure\ts_sure\thamle_say\n",fptr);
    fputs("Mert-Keskin\tAli-Murat\tb\titalyan-oyunu\t34\t32\t30\n",fptr);
    fputs("Zeynep-Turgut\tUmur-Kuris\ts\tsah-hint-savunmasi\t34\t32\t30\n",fptr);
    fputs("Zeynep-Turgut\tMert-Keskin\ts\tsicilya-defansi\t34\t32\t30\n",fptr);
    fputs("Umur-Kuris\tAli-Murat\tb\truy-lopez-acilisi\t34\t32\t30\n",fptr);
    fputs("Ali-Murat\tUmur-Kuris\tb\truy-lopez-acilisi\t34\t32\t30\n",fptr);
    fputs("Izzet-Korkmaz\tAli-Murat\tb\tsah-hint-savunmasi\t34\t32\t30\n",fptr);
    fputs("Ali-Murat\tIzzet-Korkmaz\tb\tvezir-gambiti\t34\t32\t30\n",fptr);
    fputs("Izzet-Korkmaz\tZeynep-Turgut\ts\tvezir-gambiti\t34\t32\t30\n",fptr);
    fputs("Ali-Murat\tMert-Keskin\ts\titalyan-oyunu\t34\t32\t30\n",fptr);
    fputs("Mert-Keskin\tZeynep-Turgut\ts\tsicilya-defansi\t34\t32\t30\n",fptr);
    fputs("Mert-Keskin\tIzzet-Korkmaz\tb\tsicilya-defansi\t34\t32\t30\n",fptr);
    fputs("Izzet-Korkmaz\tMert-Keskin\tb\titalyan-oyunu\t24\t72\t12\n",fptr);
    fputs("Izzet-Korkmaz\tZeynep-Turgut\ts\tsicilya-defansi\t36\t332\t14\n",fptr);
    fputs("Zeynep-Turgut\tUmur-Kuris\tb\tsicilya-defansi\t34\t32\t30\n",fptr);
    fputs("Izzet-Korkmaz\tUmur-Kuris\tb\truy-lopez-acilisi\t26\t42\t70\n",fptr);
    fputs("Umur-Kuris\tIzzet-Korkmaz\ts\truy-lopez-acilisi\t26\t42\t70\n",fptr);
    fputs("Mert-Keskin\tUmur-Kuris\ts\truy-lopez-acilisi\t34\t32\t30\n",fptr);
    fputs("Umur-Kuris\tMert-Keskin\tb\truy-lopez-acilisi\t34\t32\t30\n",fptr);
    fputs("Zeynep-Turgut\tAli-Murat\tb\tsicilya-defansi\t34\t32\t30\n",fptr);
    fputs("Ali-Murat\tZeynep-Turgut\tb\tsicilya-defansi\t34\t32\t30\n",fptr);
    fclose(fptr);
}