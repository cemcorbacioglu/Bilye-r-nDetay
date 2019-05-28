#include <stdio.h>
#include <stdlib.h>

int main()
{

    float iade_kutu=0;
    float toplam_kutu=0;

    float hafif_bilyeli_kutu_say=0;
    float agir_bilyeli_kutu_say=0;
    float esit_bilyeli_kutu_say=0;
    int iade_bilye_say=0;
    int kabul_bilye_say=0;
    int agir_bilye_fark_toplam=0;
    int hafif_bilye_fark_toplam=0;
    int max_bilyeli_kutu_bilye_sayisi=0;
    int max_bilyeli_kutu_bilye_agirligi=0;

    float hafif_bilyeli_fark_yuzdesi_toplami=0;
    float agir_bilyeli_fark_yuzdesi_toplami=0;
    int en_hafif_bilyeli_kutu_bilye_agirligi;
    int en_hafif_bilyeli_kutu_bilye_sayisi;

    int fark_degeri;
    float fark_yuzdesi;
    int en_buyuk_fark_degeri=0;
    int en_buyuk_fark_degeri_deger=0;
    float en_buyuk_fark_degeri_yuzde=0;
    char en_buyuk_fark_degeri_isaret;
    float en_buyuk_fark_yuzdesi=0;
    int en_buyuk_fark_yuzdesi_deger=0;
    float en_buyuk_fark_yuzdesi_yuzde=0;
    char en_buyuk_fark_yuzdesi_isaret;
    char devam;

    do
    {
        int basa_don=0;
        int agirlik;
        int agirlik1;
        int agirlik2;
        int agirlik3;
        int i;
        int kutu_bilye_say;
        int standart_agirlik;
        int farkli_agirlik;
        int farkli_agirlik_say=0;

        do
        {
            printf("\nkutuya agirligi girilecek toplam bilye sayisini giriniz.\n");
            scanf("%d",&kutu_bilye_say);
        }
        while (kutu_bilye_say<10);
        printf("\n1.bilyenin agirligini giriniz.\n");
        scanf("%d",&agirlik1);

        printf("\n2.bilyenin agirligini giriniz.\n");
        scanf("%d",&agirlik2);


        if (agirlik2 == agirlik1)
        {

            standart_agirlik = agirlik1;

            printf("\n3.bilyenin agirligini giriniz.\n");
            scanf("%d",&agirlik3);
            if (agirlik3!=standart_agirlik)
            {
                farkli_agirlik_say++;
                farkli_agirlik=agirlik3;
            }
        }
        else
        {
            printf("\n3.bilyenin agirligini giriniz.\n");
            scanf("%d",&agirlik3);
            if (agirlik3 == agirlik1 )
            {
                standart_agirlik = agirlik3;

                farkli_agirlik_say++;
                farkli_agirlik=agirlik2;
            }
            else if (agirlik3 == agirlik2 )
            {
                standart_agirlik = agirlik3;
                farkli_agirlik_say++;
                farkli_agirlik=agirlik1;
            }
            else
            {
                printf("\nKutuda kabul edilenden fazla sayida farkli agirlikta bilye var.\nKutu iade edilecek.\n");
                iade_kutu++;
                basa_don = 1;
                iade_bilye_say=iade_bilye_say+kutu_bilye_say;
            }
        }
        if (basa_don!=1)
        {
            for (i=4; i<=kutu_bilye_say; i++)
            {
                if (basa_don!=1)
                {
                    printf("\n%d.bilyenin agirligini giriniz.\n",i);
                    scanf("%d",&agirlik);
                    if (agirlik!=standart_agirlik)
                    {
                        farkli_agirlik_say++;
                        farkli_agirlik=agirlik;

                        if (farkli_agirlik_say>1)
                        {
                            printf("\nKutuda kabul edilenden fazla sayida farkli agirlikta bilye var.\nKutu iade edilecek.\n");
                            iade_kutu++;
                            basa_don = 1;
                            iade_bilye_say=iade_bilye_say+kutu_bilye_say;

                        }
                    }
                }
            }
        }
        if (basa_don!=1)
        {
            printf("\ntum bilyelerin agirligi girildi.\n");
            kabul_bilye_say=kabul_bilye_say+kutu_bilye_say;
            if (farkli_agirlik_say>0)
            {
                if (farkli_agirlik<standart_agirlik)
                {
                    hafif_bilyeli_kutu_say++;
                    fark_degeri=standart_agirlik-farkli_agirlik;
                    hafif_bilye_fark_toplam=hafif_bilye_fark_toplam+(fark_degeri);

                    fark_yuzdesi=fark_degeri*100/standart_agirlik;
                    hafif_bilyeli_fark_yuzdesi_toplami=hafif_bilyeli_fark_yuzdesi_toplami+fark_yuzdesi;
                }
                else
                {
                    agir_bilyeli_kutu_say++;
                    fark_degeri=farkli_agirlik-standart_agirlik;
                    agir_bilye_fark_toplam=agir_bilye_fark_toplam+(fark_degeri);

                    fark_yuzdesi=fark_degeri*100/standart_agirlik;
                    agir_bilyeli_fark_yuzdesi_toplami=agir_bilyeli_fark_yuzdesi_toplami+fark_yuzdesi;
                }

                if (fark_degeri>en_buyuk_fark_degeri)
                {
                    en_buyuk_fark_degeri=fark_degeri;
                    en_buyuk_fark_degeri_deger=fark_degeri;
                    en_buyuk_fark_degeri_yuzde=fark_yuzdesi;
                    if(hafif_bilyeli_kutu_say>0)
                    {
                        en_buyuk_fark_degeri_isaret='-';
                    }
                    else
                    {
                        en_buyuk_fark_degeri_isaret='+';
                    }

                }
                if (fark_yuzdesi>en_buyuk_fark_yuzdesi)
                {
                    en_buyuk_fark_yuzdesi=fark_yuzdesi;
                    en_buyuk_fark_yuzdesi_deger=fark_degeri;
                    en_buyuk_fark_yuzdesi_yuzde=fark_yuzdesi;
                    if(agir_bilyeli_kutu_say>0)
                    {
                        en_buyuk_fark_yuzdesi_isaret='+';
                    }
                    else
                    {
                        en_buyuk_fark_yuzdesi_isaret='-';
                    }
                }
             }
            else
            {
                esit_bilyeli_kutu_say++;

                if(kutu_bilye_say>max_bilyeli_kutu_bilye_sayisi)
                {
                    max_bilyeli_kutu_bilye_sayisi=kutu_bilye_say;
                    max_bilyeli_kutu_bilye_agirligi=standart_agirlik;
                }
                if(standart_agirlik<en_hafif_bilyeli_kutu_bilye_agirligi)
                {
                    en_hafif_bilyeli_kutu_bilye_agirligi=standart_agirlik;
                    en_hafif_bilyeli_kutu_bilye_sayisi=kutu_bilye_say;
                }
            }
        }
        do
        {
            printf("\ntekrar girmek istermisiniz?(e/E/h/H)\n");
            scanf("%c",&devam);
            fflush(stdin);
            devam=getchar();
        }
        while (devam!='e' && devam!='E' && devam!='h' && devam!='H');
        toplam_kutu++;
    }
    while (devam == 'e' || devam == 'E');

    printf("\n\n\ntoplam girilen kutu sayisi:%.0f\n",toplam_kutu);

    printf("uretim hatasi olan ve iade edilen kutu sayisi:%.0f\n",iade_kutu);
    printf("uretim hatasi olan kutularin tum kutular icindeki yuzdesi:%.2f%%\n\n",100*iade_kutu/toplam_kutu );

    printf("iade edilen bilye sayisi:%d\n",iade_bilye_say);
    printf("kabul edilen bilye sayisi:%d\n\n",kabul_bilye_say);

    printf("her bilyesi esit agirlikta olan kutu sayisi:%.0f\n",esit_bilyeli_kutu_say);
    if(toplam_kutu-iade_kutu!=0)
    {
        printf("kabul edilen tum kutular icindeki yuzdesi:%.2f%%\n\n",esit_bilyeli_kutu_say*100/(toplam_kutu-iade_kutu));
    }

    printf("1 adet bilyesi hafif olan kutu sayisi:%.0f\n",hafif_bilyeli_kutu_say);
    if(toplam_kutu-iade_kutu!=0)
    {
        printf("kabul edilen tum kutular icindeki yuzdesi:%.2f%%\n\n",hafif_bilyeli_kutu_say/(toplam_kutu-iade_kutu)*100);
    }
    printf("1 adet bilyesi agir olan kutu sayisi:%.0f\n",agir_bilyeli_kutu_say);
    if(toplam_kutu-iade_kutu!=0)
    {
        printf("kabul edilen tum kutular icindeki yuzdesi:%.2f%%\n\n",agir_bilyeli_kutu_say/(toplam_kutu-iade_kutu)*100);
    }
    if (agir_bilyeli_kutu_say>0)
    {
        printf("agir bilyelerin agirliklarinin farklari ortalamasi:%.2f\n",agir_bilye_fark_toplam/agir_bilyeli_kutu_say);
        printf("agir bilyelerin agirlik farki yuzdeleri ortalamasi:%.2f%%\n\n",agir_bilyeli_fark_yuzdesi_toplami/agir_bilyeli_kutu_say);
    }
    if (hafif_bilyeli_kutu_say>0)
    {
        printf("hafif bilyelerin agirliklarinin farklari ortalamasi:%.2f\n",hafif_bilye_fark_toplam/hafif_bilyeli_kutu_say);
        printf("hafif bilyelerin agirlik farki yuzdeleri ortalamasi:%.2f%%\n\n",hafif_bilyeli_fark_yuzdesi_toplami/hafif_bilyeli_kutu_say);

    }
    if (esit_bilyeli_kutu_say>0)
    {
        printf("tum bilyelerin esit agirlikta oldugu kutular arasinda,\n icinde en cok bilye olan kutudaki bilye sayisi:%d\n",max_bilyeli_kutu_bilye_sayisi);
        printf("tum bilyelerin esit agirlikta oldugu kutular arasinda,\n icinde en cok bilye olan kutudaki bilye agirligi:%d\n\n",max_bilyeli_kutu_bilye_agirligi);

        printf("tum bilyelerin esit agirlikta oldugu kutular arasinda,\n icinde en hafif bilyeler olan kutudaki bilye sayisi:%d\n",en_hafif_bilyeli_kutu_bilye_sayisi);
        printf("tum bilyelerin esit agirlikta oldugu kutular arasinda,\n icinde en hafif bilyeler olan kutudaki bilye agirligi:%d\n\n",en_hafif_bilyeli_kutu_bilye_agirligi);
    }
    if(agir_bilyeli_kutu_say>0 || hafif_bilyeli_kutu_say>0)
    {

        printf("farkli olan bilye agirliklarindan, \ndiger bilyelerin agirligiyla arasindaki farkin degerinin\n en buyuk oldugu bilyenin farkinin;\n");
        printf("degeri:%d\n",en_buyuk_fark_degeri_deger);
        printf("yuzdesi:%.2f%%\n",en_buyuk_fark_degeri_yuzde);
        printf("isareti:%c\n\n",en_buyuk_fark_degeri_isaret);

        printf("farkli olan bilye agirliklarindan, \ndiger bilyelerin agirligiyla arasindaki farkin yuzdesinin\n en buyuk oldugu bilyenin farkinin;\n");
        printf("degeri:%d\n",en_buyuk_fark_yuzdesi_deger);
        printf("yuzdesi:%.2f%%\n",en_buyuk_fark_yuzdesi_yuzde);
        printf("isareti:%c\n",en_buyuk_fark_yuzdesi_isaret);
    }
    printf("\n\n\n\n");
    return 0;
}

