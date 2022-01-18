#include <stdio.h>
#include <string.h>
struct mac{
        char b_isim[20];char s_isim[20];char kazanan[20];char acilis[20];int b_sure;int s_sure;int hamle_say;
    }mac1,mac2,mac3,mac4,mac5,mac6,mac7,mac8,mac9,mac10,mac11,mac12,mac13,mac14,mac15,mac16,mac17,mac18,mac19,mac20;
void create_file(FILE* fptr);
void siralama(struct mac **maclar);
void renk(struct mac **maclar);
void acilis(struct mac **maclar);
void say_hamle(struct mac **maclar);
void read_data(struct mac **maclar);

int main()
{
    
    struct mac *maclar[20];//tum maclar tek bir pointer listesine bağlanır boylelikle ilerde for dongusu kullanabilirim.
    maclar[0]=&mac1;maclar[1]=&mac2;maclar[13]=&mac14;maclar[14]=&mac15;
    maclar[2]=&mac3;maclar[3]=&mac4;maclar[15]=&mac16;maclar[16]=&mac17;
    maclar[4]=&mac5;maclar[5]=&mac6;maclar[6]=&mac7;maclar[17]=&mac18;
    maclar[7]=&mac8;maclar[8]=&mac9;maclar[9]=&mac10;maclar[18]=&mac19;
    maclar[10]=&mac11;maclar[11]=&mac12;maclar[12]=&mac13;maclar[19]=&mac20;
    FILE *fptr;
    create_file(fptr);
    read_data(maclar);
    siralama(maclar);
    renk(maclar);
    acilis(maclar);
    say_hamle(maclar);
    fclose(fptr);
    return 0;
}

void siralama(struct mac **maclar){
    struct kisiler{
        int kaz[2];//0.index beyazlardaki galibiyet 1.index siyahlardaki galibiyet.
        int sure;
        int hamle;
    }mert,zeynep,umur,ali,izzet;//her bir kisi icin struct yapılır

    struct kisiler* kisilerptr[5];
    kisilerptr[0]=&zeynep;kisilerptr[1]=&mert;
    kisilerptr[2]=&umur;kisilerptr[3]=&izzet;
    kisilerptr[4]=&ali;

    int j;
    for(j=0;j<5;j++){//default değerler hata çıkarabileceği icin 0 a eşitlenir.
        kisilerptr[j]->kaz[0]=0;
        kisilerptr[j]->kaz[1]=0;
        kisilerptr[j]->sure=0;
        kisilerptr[j]->hamle=0;
    }
    int i = 0;
    for(i=0;i<20;i++){
        if(!strcmp("b",maclar[i]->kazanan)){//galibiyet sayıları artan sureler ve hamle sayıları structlardaki yerlere yerlestirilir.
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
    int a;
    char isimler[5][20];//for dongusu icin isimler arraylere yerlestirilir.
    strcpy(isimler[0],"Zeynep Turgut");strcpy(isimler[1],"Mert Keskin");strcpy(isimler[2],"Umur Kuris");
    strcpy(isimler[3],"Izzet Korkmaz");strcpy(isimler[4],"Ali Murat");
    FILE *f2ptr;
    f2ptr=fopen("hedef.txt","w");
    fprintf(f2ptr,"%s","\n-------------------------Kisilere Gore Analiz--------------------------------");
    fprintf(f2ptr,"%s","\nIsim\t\t\t\tPuan\t\t\tBeyazlarda kazanc\t\t\tSiyahlarda Kazanc\t\tOrtalama hamle hizi (sn)\n");
    for(a=0;a<5;a++){
        int puan = (kisilerptr[a]->kaz[0]*2+kisilerptr[a]->kaz[1]*3);//puan hesaplanır
        int orthiz = (60*10*8-kisilerptr[a]->sure)/(kisilerptr[a]->hamle/2);//ortalama hız hesaplanır
        fprintf(f2ptr,"\n%s\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t\t%d\n",isimler[a],puan,kisilerptr[a]->kaz[0],kisilerptr[a]->kaz[1],orthiz);
    }
    fclose(f2ptr);
}


void renk(struct mac **maclar){
    FILE *f2ptr;
    f2ptr=fopen("hedef.txt","a");
    int b=0;//beyaz galibiyet sayısı
    int s=0;//siyah galibiyet sayısı
    int i=0;
    for(i=0;i<20;i++){// for ile gezerek sayma işlemi yapılır
        if(!strcmp("b",maclar[i]->kazanan)){
            b++;
        }
        else if(!strcmp("s",maclar[i]->kazanan))
            s++;
    }
    float b_yuzde = (float) b/(s+b)*100;//renklerin kazanma yüzdeleri hesaplanır.
    float s_yuzde = (float) s/(s+b)*100;
    fprintf(f2ptr,"%s","\n------------------Renge Gore Analiz--------------------\n");
    fprintf(f2ptr,"Toplam beyaz galibiyeti : %d\t\tKazanma yuzdesi : %%%.1f\nToplam siyah galibiyeti : %d\t\tKazanma yuzdesi : %%%.1f",b,b_yuzde,s,s_yuzde);
    fclose(f2ptr);
}

void acilis(struct mac **maclar){
    int vezir[2]={0,0};int ital[2]={0,0};int hint[2]={0,0};int ruy[2]={0,0};int sic[2]={0,0};//0.index beyaz galibiyet 1.index siyah.
    int*acilislar[5];//for döngüsü icin pointer.
    acilislar[0]=vezir;acilislar[1]=ital;acilislar[2]=hint;acilislar[3]=ruy;acilislar[4]=sic;
    FILE *f2ptr;
    f2ptr=fopen("hedef.txt","a");
    int b=0;
    int s=0;
    int i=0;
    for(i=0;i<20;i++){// acılıslar icin galibiyet sayıları eklenir
        if(!strcmp("vezir-gambiti",maclar[i]->acilis)){
            if(!strcmp("b",maclar[i]->kazanan))//beyaz kazandıysa 0.index ++
                vezir[0]++;
            else //siyah kazandıysa 1.index ++
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
    char isimler[5][20];//for döngusu icin isimler arraylara yerlestirilir
    strcpy(isimler[0],"Vezir Gambiti\t");strcpy(isimler[1],"Italyan Oyunu\t");strcpy(isimler[2],"Sicilya Defansi\t");
    strcpy(isimler[3],"Ruy Lopez Acilisi");strcpy(isimler[4],"Sah Hint Savunmasi");
    fprintf(f2ptr,"%s","\n\n-----------------Acilisa Gore Analiz-------------------\nAcilis ismi\t\t\tbeyaz galibiyet sayisi\t\t\t\tsiyah galibiyet sayisi\n\n");
    int a;
    for(a=0;a<5;a++){
        fprintf(f2ptr,"%s\t\t\t\t%d\t\t\t\t\t%d\n",isimler[a],acilislar[a][0],acilislar[a][1]);
        }
    fclose(f2ptr);
}

void say_hamle(struct mac **maclar){
    FILE *f2ptr;
    f2ptr=fopen("hedef.txt","a");
    float hamlesay_toplam=0;
    int i=0;
    for(i=0;i<20;i++){
        hamlesay_toplam += maclar[i]->hamle_say;
    }
    fprintf(f2ptr,"%s","\n------------------Hamle Sayisina Göre Analiz--------------------\n");
    fprintf(f2ptr,"Karsilasmalardaki ortalama hamle sayisi : %.1f\n",hamlesay_toplam/20);
    fclose(f2ptr);
}

void create_file(FILE* fptr){
    fptr = fopen("kaynak.txt","w");
    fputs("b_isim\ts_isim\tkazanan\tvaryant\tb_sure\ts_sure\thamle_say\n",fptr);
    fputs("Mert-Keskin\tAli-Murat\tb\titalyan-oyunu\t34\t32\t30\n",fptr);
    fputs("Zeynep-Turgut\tUmur-Kuris\ts\tsah-hint-savunmasi\t90\t102\t43\n",fptr);
    fputs("Zeynep-Turgut\tMert-Keskin\ts\tsicilya-defansi\t38\t5\t35\n",fptr);
    fputs("Umur-Kuris\tAli-Murat\tb\truy-lopez-acilisi\t34\t32\t43\n",fptr);
    fputs("Ali-Murat\tUmur-Kuris\tb\truy-lopez-acilisi\t94\t25\t39\n",fptr);
    fputs("Izzet-Korkmaz\tAli-Murat\tb\tsah-hint-savunmasi\t394\t32\t30\n",fptr);
    fputs("Ali-Murat\tIzzet-Korkmaz\tb\tvezir-gambiti\t234\t132\t104\n",fptr);
    fputs("Izzet-Korkmaz\tZeynep-Turgut\ts\tvezir-gambiti\t44\t67\t37\n",fptr);
    fputs("Ali-Murat\tMert-Keskin\ts\titalyan-oyunu\t132\t132\t30\n",fptr);
    fputs("Mert-Keskin\tZeynep-Turgut\ts\tsicilya-defansi\t54\t210\t45\n",fptr);
    fputs("Mert-Keskin\tIzzet-Korkmaz\tb\tsicilya-defansi\t164\t76\t35\n",fptr);
    fputs("Izzet-Korkmaz\tMert-Keskin\tb\titalyan-oyunu\t551\t172\t22\n",fptr);
    fputs("Izzet-Korkmaz\tZeynep-Turgut\ts\tsicilya-defansi\t76\t232\t24\n",fptr);
    fputs("Zeynep-Turgut\tUmur-Kuris\tb\tsicilya-defansi\t134\t62\t30\n",fptr);
    fputs("Izzet-Korkmaz\tUmur-Kuris\tb\truy-lopez-acilisi\t366\t42\t49\n",fptr);
    fputs("Umur-Kuris\tIzzet-Korkmaz\ts\truy-lopez-acilisi\t26\t92\t41\n",fptr);
    fputs("Mert-Keskin\tUmur-Kuris\ts\truy-lopez-acilisi\t0\t232\t32\n",fptr);
    fputs("Umur-Kuris\tMert-Keskin\tb\truy-lopez-acilisi\t97\t31\t37\n",fptr);
    fputs("Zeynep-Turgut\tAli-Murat\tb\tsicilya-defansi\t204\t32\t35\n",fptr);
    fputs("Ali-Murat\tZeynep-Turgut\tb\tsicilya-defansi\t67\t45\t36\n",fptr);
    fclose(fptr);
}

void read_data(struct mac **maclar){
    FILE *fptr;
    fptr = fopen("kaynak.txt","r");
    fseek(fptr, 53,SEEK_SET);//ilk satırda sütun adları olduğu icin alt satıra gecmeliyim.

    int i;
    for(i=0;i<20;i++){
       fscanf(fptr,"%s%s%s%s%d%d%d",maclar[i]->b_isim,maclar[i]->s_isim,maclar[i]->kazanan,maclar[i]->acilis,&maclar[i]->b_sure,&maclar[i]->s_sure,&maclar[i]->hamle_say);
    }
}