#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void AnaMenu();
void MusteriEkle();
void HesapAcma();
void ParaCekme();
void ParaYatirma();
void Havale();
void HesapOzeti();
void HesapKapama();
double RandSayiAtama();



typedef struct
{
    char Ad[50];
    char Soyad[50];
    int MusteriNo;
    char DogumYeri[50];
    char DogumTarihi[50];
    int HesapNo;
    float Bakiye;
    int MusteriTuru;
}musteri;


void AnaMenu()
{
	int secim;
    printf("\n\t\t\tHOSGELDINIZ\t\t\t\n\n\tLutfen yapmak istediginiz islemi seciniz:\n\n\t1)Yeni Musteri Ekleme\n\t2)Yeni Hesap Actirma\n\t3)Para Cekme\n\t4)Para Yatirma\n\t5)Havale yapmak\n\t6)Hesap Ozeti Goruntuleme\n\t7)Hesap Kapatma\n\t8)Cikis:");
	scanf("%d",&secim);

	switch(secim)
	{
        case 1:
        	{
        		MusteriEkle();
        		break;
			}

    	case 2:
    		{
    			HesapAcma();
    			break;

			}

		case 3:
			{
			    ParaCekme();
			    break;
			}

        case 4:
        	{
        	    ParaYatirma();
        	    break;
			}

        case 5:
        	{
        		Havale();
        		break;
			}

        case 6:
        	{
        		HesapOzeti();
        		break;
			}

        case 7:
        	{
        	    HesapKapama();
        	    break;
			}
		case 8:
		    {
		    	printf("Cikis yapiliyor...");
		    	exit(1);
		    	break;
			}	
	}
}

int main()
{
  AnaMenu();
    return 0;
}

void MusteriEkle()
{
	int secim;
	FILE *fpBireysel, *fpTicari;

	printf("Eklemek istediginiz musteri turunu seciniz:\n1)Bireysel Musteri bilgileri:\n2)Ticari Musteri bilgileri:");
	scanf("%d",&secim);

	if(secim==1)
	{
	    musteri bireysel;

		printf("Bankamiza hos geldiniz.Lutfen bilgilerinizi giriniz.\n");
		printf("Ad:");
		scanf("%s",bireysel.Ad);
		printf("Soyad:");
		scanf("%s",bireysel.Soyad);
		printf("Dogum yeri:");
		scanf("%s",bireysel.DogumYeri);
		printf("Dogum tarihi ../../....:");
		scanf("%s",bireysel.DogumTarihi);
		printf("Musteri numarasi:");
		bireysel.MusteriNo=RandSayiAtama();
		printf("%d",bireysel.MusteriNo);

		if((fpBireysel=fopen("bireysel.txt","a"))==NULL)
		{
			printf("Dosya acma hatasi");
			exit(1);
		}

		fprintf(fpBireysel,"\n%d %s %s %s %s",bireysel.MusteriNo,bireysel.Ad,bireysel.Soyad,bireysel.DogumYeri,bireysel.DogumTarihi);
		fclose(fpBireysel);
	}

    if(secim==2)
	{
	    musteri ticari;

		printf("Bankamiza hos geldiniz.Lutfen bilgilerinizi giriniz.\n");
		printf("Ad:");
		scanf("%s",ticari.Ad);
		printf("Soyad:");
		scanf("%s",ticari.Soyad);
		printf("Dogum yeri:");
		scanf("%s",ticari.DogumYeri);
		printf("Dogum tarihi ../../....:");
		scanf("%s",ticari.DogumTarihi);
		printf("Musteri numarasi:");
		ticari.MusteriNo=RandSayiAtama();
		printf("%d",ticari.MusteriNo);

		if((fpTicari=fopen("ticari.txt","a"))==NULL)
		{
			printf("Dosya acma hatasi");
			exit(1);
		}

		fprintf(fpTicari,"\n%d %s %s %s %s ",ticari.MusteriNo,ticari.Ad,ticari.Soyad,ticari.DogumYeri,ticari.DogumTarihi);
		fclose(fpTicari);
	}
    AnaMenu();
}


void HesapAcma()
{
    musteri Hesap;
    musteri bireysel;
    musteri ticari;
    int secim,musteriNo;
    FILE *fpHesap,*fp1,*fp2;

    if((fpHesap=fopen("hesaplar.txt","a"))==NULL)
    {
        printf("hesap acma hatasi");
        exit(1);
    }

    printf("\nIslem yapmak istediginiz hesap turunu secin:\n1)Bireysel\n2)Ticari");
    scanf("%d",&secim);

    if(secim==1)
    {
        int say=0;
        fp1=fopen("bireysel.txt","r");
        printf("Lutfen musteri no girin:");
        scanf("%d",&musteriNo);

	    while(!feof(fp1))
	    {
	        fscanf(fp1,"\n%d %s %s %s %s ",&bireysel.MusteriNo,bireysel.Ad,bireysel.Soyad,bireysel.DogumYeri,bireysel.DogumTarihi);
		    if(bireysel.MusteriNo==musteriNo)
            {
                printf("\n%d %s %s %s %s ",bireysel.MusteriNo,bireysel.Ad,bireysel.Soyad,bireysel.DogumYeri,bireysel.DogumTarihi);
		        ++say;

                printf("\nHesabiniz dogrulandi.Hesap acma islemi devam ediyor.");

                Hesap.HesapNo=RandSayiAtama();
                printf("\nHesap numaraniz: %d",Hesap.HesapNo);

                printf("\nIlk bakiyenizi giriniz:");
                scanf("%f",&Hesap.Bakiye);

                printf("\nIslem tamamlandi.Iyi gunler dileriz.");

                fprintf(fpHesap,"\n%d %s %s %f",Hesap.HesapNo,bireysel.Ad,bireysel.Soyad,Hesap.Bakiye);
            }
	    }
		fclose(fp1);
	    if(say==0)
	    {
	    	printf("\nHesap dogrulanamadi!!!");

		}
	}

    if(secim==2)
    {
        int say=0;
        fp2=fopen("ticari.txt","r");
        printf("Lutfen musteri no girin:");
        scanf("%d",&musteriNo);

	    while(!feof(fp2))
	    {
	        fscanf(fp2,"\n%d %s %s %s %s ",&ticari.MusteriNo,ticari.Ad,ticari.Soyad,ticari.DogumYeri,ticari.DogumTarihi);
		    if(ticari.MusteriNo==musteriNo)
		    {
		        printf("\n%d %s %s %s %s ",ticari.MusteriNo,ticari.Ad,ticari.Soyad,ticari.DogumYeri,ticari.DogumTarihi);
		        ++say;

                printf("\nHesabiniz dogrulandi.Hesap acma islemi devam ediyor.");

                Hesap.HesapNo=RandSayiAtama();
                printf("\nHesap numaraniz: %d",Hesap.HesapNo);

                printf("\nIlk bakiyenizi giriniz:");
                scanf("%f",&Hesap.Bakiye);

                printf("\nIslem tamamlandi.Iyi gunler dileriz.");
                fprintf(fpHesap,"\n%d %s %s %f",Hesap.HesapNo,ticari.Ad,ticari.Soyad,Hesap.Bakiye);
           }
        }
		fclose(fp2);
        if(say==0)
        {
        	printf("Hesap dogrulanamadi!!!");
		}
   }
   fclose(fpHesap);

   AnaMenu();
}


void ParaCekme()
{
    musteri Hesap;
    musteri Hesap2;
    
    time_t t = time(NULL); // dekont dosyasýna tarih katdetmek için kullandýk
    struct tm tm = *localtime(&t);

    float tutar,bakiye1,bakiye2;
    int HesapNumarasi,HesapNumarasi2,HesapNumarasi3,HesapNumarasi4,say1=0,say2=0;
	int karar,satir=0,satir2,temp=0,temp2=0,satir3=0,satir4;
	char secim,*ad,*soyad,*yazi1,*yazi2;
    ad=(char*)malloc(sizeof(char)*100);
	soyad=(char*)malloc(sizeof(char)*100);
    yazi1=(char*)malloc(sizeof(char)*20);
    yazi2=(char*)malloc(sizeof(char)*20);

    strcpy(yazi1,"HesapNo:");
    strcpy(yazi2,"Cekilen:");

    printf("Lutfen islem yapacaginiz hesap turunu secin:\n1)Bireysel\n2)Ticari");
    scanf("%d",&karar);

    if(karar==1)
    {
        FILE *fpHesap,*fpHesap2,*fpGecici,*fpGecici2;

        fpHesap=fopen("hesaplar.txt","r");

        printf("\nLutfen hesap numarasi girin:");
        scanf("%d",&HesapNumarasi);
        while(!feof(fpHesap))
	    {
	        satir++;
		    fscanf(fpHesap,"\n%d %s %s %f",&Hesap.HesapNo,Hesap.Ad,Hesap.Soyad,&Hesap.Bakiye);

	    	if(Hesap.HesapNo==HesapNumarasi)
	    	{
		        say1++;
                satir2=satir;
                HesapNumarasi2=Hesap.HesapNo;
		        bakiye1=Hesap.Bakiye;
		        ad=Hesap.Ad;
		        soyad=Hesap.Soyad;
		    	printf("\n%d %s %s %f",Hesap.HesapNo,Hesap.Ad,Hesap.Soyad,bakiye1);
		    	printf("\nHesap numarasi dogrulandi.Isleminiz devam ediyor.");
            }
        }
		fclose(fpHesap);
        if(say1==0)
        {
            printf("Hesap dogrulanamadi!!!");
            printf("\nAna menuye yonlendiriliyorsunuz.");
            AnaMenu();
        }

	    printf("\nCekmek istediginiz tutari giriniz:");
        scanf("%f",&tutar);
        if(tutar>750)
        {
            printf("\nCekebileceginiz maximum tutar 750 TL'dir.\nAna menuye yonlendiriliyorsunuz.");
            AnaMenu();
        }

        if(tutar<=bakiye1)
        {
            bakiye1=bakiye1-tutar;
            printf("\n%.2f TL para cekildi.Kalan bakiye:%.2f",tutar,bakiye1);

            FILE *fpdekont=fopen("dekont.txt","a");
            fprintf(fpdekont,"%s %d %s %f %d %02d %02d %02d:%02d:%02d\n",yazi1,HesapNumarasi2,yazi2,tutar,tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
            fprintf(fpdekont,"\n");
            fclose(fpdekont);

            fpHesap=fopen("hesaplar.txt","r");
            fpGecici=fopen("gecici.txt","a");
            while(!feof(fpHesap))
            {
                temp++;
                fscanf(fpHesap,"\n%d %s %s %f",&Hesap.HesapNo,Hesap.Ad,Hesap.Soyad,&Hesap.Bakiye);

                if(satir2!=temp)
                {
                    fprintf(fpGecici,"\n%d %s %s %f",Hesap.HesapNo,Hesap.Ad,Hesap.Soyad,Hesap.Bakiye);
                }

                if(satir2==temp)
                {
                    fprintf(fpGecici,"\n%d %s %s %f",HesapNumarasi2,ad,soyad,bakiye1);
                }
            }
            fclose(fpGecici);
            fclose(fpHesap);
            remove("hesaplar.txt");
            rename("gecici.txt","hesaplar.txt");

            printf("\nIslem basarili.");
            printf("\nAna menuye yonlendiriliyorsunuz.");
            AnaMenu();
        }

        else if(tutar>bakiye1)
        {
            printf("\nHesabinizda yeterli bakiye yoktur.");
            printf("Diger hesabinizdan para cekilecektir");

            printf("\nLutfen hesap numarasi girin:");
            scanf("%d",&HesapNumarasi4);

            fpHesap2=fopen("hesaplar.txt","r");

            while(!feof(fpHesap2))
            {
                satir3++;
                fscanf(fpHesap2,"\n%d %s %s %f",&Hesap2.HesapNo,Hesap2.Ad,Hesap2.Soyad,&Hesap2.Bakiye);

                if(Hesap2.HesapNo==HesapNumarasi4)
                {
				    say2++;
                    satir4=satir3;
                    bakiye2=Hesap2.Bakiye;
                    HesapNumarasi3=Hesap2.HesapNo;
                    ad=Hesap2.Ad;
                    soyad=Hesap2.Soyad;
                    printf("\n%d %s %s %f",Hesap2.HesapNo,Hesap2.Ad,Hesap2.Soyad,Hesap2.Bakiye);
			        printf("\nHesap numarasi dogrulandi.Isleminiz devam ediyor.");
                }
            }
			fclose(fpHesap2);

            if(say2==0)
            {
                printf("\nHesap dogrulanamdi!!!\nAna menuye yonlendiriliyorsunuz.");
                AnaMenu();
            }
            printf("\nLutfen cekmek istediginiz tutari girin:");
            scanf("%f",&tutar);
            if(tutar>750)
            {
                printf("\nCekebileceginiz maximum tutar 750 TL'dir.\nAna menuye yonlendiriliyorsunuz.");
                AnaMenu();
            }

            if(tutar<=bakiye2)
            {
                bakiye2=bakiye2-tutar;
                printf("\n%.2f TL cekildi. Kalan bakiye %.2f. ",tutar,bakiye2);
                FILE *fpdekont=fopen("dekont.txt","a");
                fprintf(fpdekont,"%s %d %s %f %d %02d %02d %02d:%02d:%02d\n",yazi1,HesapNumarasi3,yazi2,tutar,tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
                fprintf(fpdekont,"\n");
                fclose(fpdekont);
                fpHesap2=fopen("hesaplar.txt","r");
                fpGecici2=fopen("gecici2.txt","a");
                while(!feof(fpHesap2))
                {
                    temp2++;
                    fscanf(fpHesap,"\n%d %s %s %f",&Hesap2.HesapNo,Hesap2.Ad,Hesap2.Soyad,&Hesap2.Bakiye);

                    if(satir4!=temp2)
                    {
                        fprintf(fpGecici2,"\n%d %s %s %f",Hesap2.HesapNo,Hesap2.Ad,Hesap2.Soyad,Hesap2.Bakiye);
                    }

                    if(satir4==temp2)
                    {
                        fprintf(fpGecici2,"\n%d %s %s %f",HesapNumarasi3,ad,soyad,bakiye2);
                    }
                }
                fclose(fpGecici2);
                fclose(fpHesap2);
                remove("hesaplar.txt");
                rename("gecici2.txt","hesaplar.txt");

                printf("\nIslem basarili");
                printf("\nAna menuye yonlendiriliyorsunuz.");
                AnaMenu();
            }
            else
            {
                printf("Yeterli bakiyeniz bulunmamaktadir.");
                printf("\nAna menuye yonlendiriliyorsunuz.");
                AnaMenu();
            }
        }
    }


    if(karar==2)
    {
        FILE *fpHesap,*fpHesap2,*fpGecici,*fpGecici2;

        fpHesap=fopen("hesaplar.txt","r");

        printf("\nLutfen hesap numarasi girin:");
        scanf("%d",&HesapNumarasi);
        while(!feof(fpHesap))
	    {
	        satir++;
		    fscanf(fpHesap,"\n%d %s %s %f",&Hesap.HesapNo,Hesap.Ad,Hesap.Soyad,&Hesap.Bakiye);

	    	if(Hesap.HesapNo==HesapNumarasi)
	    	{
			    say1++;
                satir2=satir;
                HesapNumarasi2=Hesap.HesapNo;
		        bakiye1=Hesap.Bakiye;
		        ad=Hesap.Ad;
		        soyad=Hesap.Soyad;
		    	printf("\n%d %s %s %f",Hesap.HesapNo,Hesap.Ad,Hesap.Soyad,bakiye1);
		    	printf("\nHesap numarasi dogrulandi.Isleminiz devam ediyor.");
            }
        }
		fclose(fpHesap);
        if(say1==0)
        {
            printf("Hesap dogrulanamadi!!!");
            printf("\nAna menuye yonlendiriliyorsunuz.");
            AnaMenu();
        }

	    printf("\nCekmek istediginiz tutari giriniz:");
        scanf("%f",&tutar);
        if(tutar>1500)
        {
            printf("\nCekebileceginiz maximum tutar 1500 TL'dir.\nAna menuye yonlendiriliyorsunuz.");
            AnaMenu();
        }

        if(tutar<=bakiye1)
        {
            bakiye1=bakiye1-tutar;
            printf("\n%.2f TL para cekildi.Kalan bakiye:%.2f",tutar,bakiye1);

            FILE *fpdekont=fopen("dekont.txt","a");
            fprintf(fpdekont,"%s %d %s %f %d %02d %02d %02d:%02d:%02d\n",yazi1,HesapNumarasi2,yazi2,tutar,tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
            fprintf(fpdekont,"\n");
            fclose(fpdekont);

            fpHesap=fopen("hesaplar.txt","r");
            fpGecici=fopen("gecici.txt","a");
            while(!feof(fpHesap))
            {
                temp++;
                fscanf(fpHesap,"\n%d %s %s %f",&Hesap.HesapNo,Hesap.Ad,Hesap.Soyad,&Hesap.Bakiye);

                if(satir2!=temp)
                {
                    fprintf(fpGecici,"\n%d %s %s %f",Hesap.HesapNo,Hesap.Ad,Hesap.Soyad,Hesap.Bakiye);
                }

                if(satir2==temp)
                {
                    fprintf(fpGecici,"\n%d %s %s %f",HesapNumarasi2,ad,soyad,bakiye1);
                }
            }
            fclose(fpGecici);
            fclose(fpHesap);
            remove("hesaplar.txt");
            rename("gecici.txt","hesaplar.txt");

            printf("\nIslem basarili.");
            printf("\nAna menuye yonlendiriliyorsunuz.");
            AnaMenu();
        }

        else if(tutar>bakiye1)
        {
            printf("\nHesabinizda yeterli bakiye yoktur.");
            printf("Diger hesabinizdan para cekilecektir");

            printf("\nLutfen hesap numarasi girin:");
            scanf("%d",&HesapNumarasi4);

            fpHesap2=fopen("hesaplar.txt","r");

            while(!feof(fpHesap2))
            {
                satir3++;
                fscanf(fpHesap2,"\n%d %s %s %f",&Hesap2.HesapNo,Hesap2.Ad,Hesap2.Soyad,&Hesap2.Bakiye);

                if(Hesap2.HesapNo==HesapNumarasi4)
                {
				    say2++;
                    satir4=satir3;
                    bakiye2=Hesap2.Bakiye;
                    HesapNumarasi3=Hesap2.HesapNo;
                    ad=Hesap2.Ad;
                    soyad=Hesap2.Soyad;
                    printf("\n%d %s %s %f",Hesap2.HesapNo,Hesap2.Ad,Hesap2.Soyad,Hesap2.Bakiye);
			        printf("\nHesap numarasi dogrulandi.Isleminiz devam ediyor.");
                }
            }
			fclose(fpHesap2);

            if(say2==0)
            {
                printf("\nHesap dogrulanamdi!!!\nAna menuye yonlendiriliyorsunuz.");
                AnaMenu();
            }
            printf("\nLutfen cekmek istediginiz tutari girin:");
            scanf("%f",&tutar);
            if(tutar>1500)
            {
                printf("\nCekebileceginiz maximum tutar 1500 TL'dir.\nAna menuye yonlendiriliyorsunuz.");
                AnaMenu();
            }

            if(tutar<=bakiye2)
            {
                bakiye2=bakiye2-tutar;
                printf("\n%.2f TL cekildi. Kalan bakiye %.2f. ",tutar,bakiye2);
                FILE *fpdekont=fopen("dekont.txt","a");
                fprintf(fpdekont,"%s %d %s %f %d %02d %02d %02d:%02d:%02d\n",yazi1,HesapNumarasi3,yazi2,tutar,tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
                fprintf(fpdekont,"\n");
                fclose(fpdekont);
                fpHesap2=fopen("hesaplar.txt","r");
                fpGecici2=fopen("gecici2.txt","a");
                while(!feof(fpHesap2))
                {
                    temp2++;
                    fscanf(fpHesap,"\n%d %s %s %f",&Hesap2.HesapNo,Hesap2.Ad,Hesap2.Soyad,&Hesap2.Bakiye);

                    if(satir4!=temp2)
                    {
                        fprintf(fpGecici2,"\n%d %s %s %f",Hesap2.HesapNo,Hesap2.Ad,Hesap2.Soyad,Hesap2.Bakiye);
                    }

                    if(satir4==temp2)
                    {
                        fprintf(fpGecici2,"\n%d %s %s %f",HesapNumarasi3,ad,soyad,bakiye2);
                    }
                }
                fclose(fpGecici2);
                fclose(fpHesap2);
                remove("hesaplar.txt");
                rename("gecici2.txt","hesaplar.txt");

                printf("\nIslem basarili");
                printf("\nAna menuye yonlendiriliyorsunuz.");
                AnaMenu();

            }
            else
            {
                printf("Yeterli bakiyeniz bulunmamaktadir.");
                printf("\nAna menuye yonlendiriliyorsunuz.");
                AnaMenu();

            }
        }
    }
}


void ParaYatirma()
{
    musteri Hesap;
    
    time_t t = time(NULL); // dekont dosyasýna tarih katdetmek için kullandýk
    struct tm tm = *localtime(&t);
    
    float tutar,bakiye;
    int HesapNumarasi,HesapNumarasi1,say=0,satir=0,temp=0,satir2;
    time_t tarih;
    char *ad,*soyad;
    char *yazi1,*yazi2;
    yazi1=(char*)malloc(sizeof(char)*20);
    yazi2=(char*)malloc(sizeof(char)*20);
	ad=(char*)malloc(sizeof(char)*100);
	soyad=(char*)malloc(sizeof(char)*100);
    strcpy(yazi1,"HesapNo:");
    strcpy(yazi2,"Yatirilan:");

    printf("\nHesap numaranizi giriniz:");
    scanf("%d",&HesapNumarasi);

    FILE *fpHesap, *fpGecici;

    fpHesap=fopen("hesaplar.txt","r+");
    fpGecici=fopen("gecici.txt","a");

	while(!feof(fpHesap))
	{
        satir++;
		fscanf(fpHesap,"%d %s %s %f",&Hesap.HesapNo,Hesap.Ad,Hesap.Soyad,&Hesap.Bakiye);

		if(Hesap.HesapNo==HesapNumarasi)
		{
		    satir2=satir;
            say++;
			printf("\n%d %s %s %f",Hesap.HesapNo,Hesap.Ad,Hesap.Soyad,Hesap.Bakiye);

            HesapNumarasi1=Hesap.HesapNo;
            bakiye=Hesap.Bakiye;
            ad=Hesap.Ad;
            soyad=Hesap.Soyad;

            printf("\nHesap dogrulandi.Islem devam ediyor.");

            printf("\nLutfen yatirmak istediginiz tutari girin:");
            scanf("%f",&tutar);

            bakiye=bakiye+tutar;
            printf("\n%.2f tl yatirildi yeni bakiye %.2f",tutar,bakiye);

			FILE *fpdekont=fopen("dekont.txt","a");
            fprintf(fpdekont,"%s %d %s %f %d %02d %02d %02d:%02d:%02d\n",yazi1,HesapNumarasi1,yazi2,tutar,tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
            fprintf(fpdekont,"\n");
            fclose(fpdekont);
            }
    }
    rewind(fpHesap);

	if(say==0)
    {
        printf("Hesap dogrulanamadi!!!");
    }

    while(!feof(fpHesap))
    {
        temp++;
        fscanf(fpHesap,"\n%d %s %s %f",&Hesap.HesapNo,Hesap.Ad,Hesap.Soyad,&Hesap.Bakiye);
        if(temp!=satir2)
        {
            fprintf(fpGecici,"\n%d %s %s %f",Hesap.HesapNo,Hesap.Ad,Hesap.Soyad,Hesap.Bakiye);

        }
        else if(temp==satir2)
        {
            fprintf(fpGecici,"\n%d %s %s %f",HesapNumarasi1,ad,soyad,bakiye);
        }

    }
    fclose(fpHesap);
    fclose(fpGecici);

    remove("hesaplar.txt");
    rename("gecici.txt","hesaplar.txt");

    AnaMenu();
}


void Havale()
{
	time_t t = time(NULL); // dekont dosyasýna tarih katdetmek için kullandýk
    struct tm tm = *localtime(&t);
	
    int say1=0,say2=0,satir1=0,satir2,satir3=0,satir4,temp1=0,temp2=0;
	int secilen,x,y;
	int gonderen,alan;
	float HavaleYapilacakPara, havaleucreti;
    char *yazi1,*yazi2,*yazi3;
    yazi1=(char*)malloc(sizeof(char)*20);
    yazi2=(char*)malloc(sizeof(char)*20);
    yazi3=(char*)malloc(sizeof(char)*20);
    strcpy(yazi1,"HesapNo1:");
    strcpy(yazi2,"HesapNo2:");
    strcpy(yazi3,"Havale:");
    


	musteri Hesap1,Hesap2;
	FILE *fpHesap,*fpdekont,*fpGecici;


    printf("\t\t\t*HAVALE  ISLEMI*\t\t\t\n\\n");

	printf("Hesap turunuzu seciniz:\n1)Bireysel Hesap\n2)Ticari Hesap\n");
	scanf("%d",&secilen);

	printf("Lutfen hesap numaranizi giriniz: ");
    scanf("%d",&gonderen);

    if(secilen==1)
    {
    	fpHesap=fopen("hesaplar.txt","r+");
    	fpGecici=fopen("gecici.txt","a");

        rewind(fpHesap);
        while (!feof(fpHesap))
        {
        	satir1++;
	        fscanf(fpHesap,"\n%d %s %s %f",&Hesap1.HesapNo,Hesap1.Ad,Hesap1.Soyad,&Hesap1.Bakiye);
	    	if(Hesap1.HesapNo==gonderen)
	    	{
	    		satir2=satir1;
	    		say1++;
	    	    x=0;
			}
        }
        rewind(fpHesap);

        if(x==0)
        {
        	printf("Havale yapmak istediginiz hesap numarasini giriniz: ");
    		scanf("%d",&alan);

         	rewind(fpHesap);
            while (!feof(fpHesap))
            {
            	satir3++;
	            fscanf(fpHesap,"\n%d %s %s %f",&Hesap2.HesapNo,Hesap2.Ad,Hesap2.Soyad,&Hesap2.Bakiye);
	            if(Hesap2.HesapNo==alan)
	            {
	            	satir4=satir3;
	            	say2++;
	            	y=0;
				}
            }
	    	rewind(fpHesap);

        	if(y==0)
    		{
    			printf("Havale yapmak istediginiz miktari giriniz: ");
    			scanf("%f",&HavaleYapilacakPara);
    			havaleucreti=HavaleYapilacakPara*2/100;

    			if(HavaleYapilacakPara<=Hesap1.Bakiye)
    			{
					printf("Bankamiz bu islem icin %f lira tahsil edecektir.\n",havaleucreti);
					printf("%f lira havale yapilacaktir.\n",(HavaleYapilacakPara-havaleucreti));

					fscanf(fpHesap,"\n%d %s %s %f",&Hesap1.HesapNo,Hesap1.Ad,Hesap1.Soyad,&Hesap1.Bakiye);
                	fscanf(fpHesap,"\n%d %s %s %f",&Hesap2.HesapNo,Hesap2.Ad,Hesap2.Soyad,&Hesap2.Bakiye);

					Hesap1.Bakiye-=HavaleYapilacakPara;
					Hesap2.Bakiye+=(HavaleYapilacakPara-havaleucreti);

					printf("%d nolu bireysel hesabinizdan %d nolu hesaba %.2f lira havale yapilmistir.\n",Hesap1.HesapNo,Hesap2.HesapNo,(HavaleYapilacakPara-havaleucreti));

					FILE *fpdekont=fopen("dekont.txt","a");
					fprintf(fpdekont, "%s %d %s %d %s %f %d %02d %02d %02d:%02d:%02d\n",yazi1,Hesap1.HesapNo,yazi2,Hesap2.HesapNo,yazi3,(HavaleYapilacakPara-havaleucreti),tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
					fprintf(fpdekont,"\n");
					fclose(fpdekont);

					if(say1==0)
					{
						 printf("Hesap dogrulanamadi!!!");
					}

					if(say2==0)
					{
	    				printf("Hesap dogrulanamadi!!!");
					}

					while(!feof(fpHesap))
					{
						temp1++;
                        fscanf(fpHesap,"\n%d %s %s %f",&Hesap1.HesapNo,Hesap1.Ad,Hesap1.Soyad,&Hesap1.Bakiye);
					}

                    if(temp1!=satir2)
                    {
                        fprintf(fpGecici,"\n%d %s %s %f",Hesap1.HesapNo,Hesap1.Ad,Hesap1.Soyad,Hesap1.Bakiye);
                    }
                    else if(temp1==satir2)
                    {
                        fprintf(fpGecici,"\n%d %s %s %f",Hesap1.HesapNo,Hesap1.Ad,Hesap1.Soyad,Hesap1.Bakiye);
                    }

					while(!feof(fpHesap))
					{
						temp2++;
                        fscanf(fpHesap,"\n%d %s %s %f",&Hesap2.HesapNo,Hesap2.Ad,Hesap2.Soyad,&Hesap2.Bakiye);
					}

                    if(temp2!=satir4)
                    {
                        fprintf(fpGecici,"\n%d %s %s %f",Hesap2.HesapNo,Hesap2.Ad,Hesap2.Soyad,Hesap2.Bakiye);
                    }
                    else if(temp2==satir4)
                    {
                        fprintf(fpGecici,"\n%d %s %s %f",Hesap2.HesapNo,Hesap2.Ad,Hesap2.Soyad,Hesap2.Bakiye);
                    }

				    fclose(fpHesap);
                    fclose(fpGecici);

				    remove("hesaplar.txt");
                    rename("gecici.txt","hesaplar.txt");
		     	}
	        }
    	}
	    AnaMenu();
    }

    if(secilen==2)
    {
    	fpHesap=fopen("hesaplar.txt","r+");
    	fpGecici=fopen("gecici.txt","a");

        rewind(fpHesap);
        while (!feof(fpHesap))
        {
        	satir1++;
	        fscanf(fpHesap,"\n%d %s %s %f",&Hesap1.HesapNo,Hesap1.Ad,Hesap1.Soyad,&Hesap1.Bakiye);
	    	if(Hesap1.HesapNo==gonderen)
	    	{
	    		satir2=satir1;
	    		say1++;
	    	    x=0;
			}
        }
        rewind(fpHesap);

        if(x==0)
        {
        	printf("Havale yapmak istediginiz hesap numarasini giriniz: ");
    		scanf("%d",&alan);

         	rewind(fpHesap);
            while (!feof(fpHesap))
            {
            	satir3++;
	            fscanf(fpHesap,"\n%d %s %s %f",&Hesap2.HesapNo,Hesap2.Ad,Hesap2.Soyad,&Hesap2.Bakiye);
	            if(Hesap2.HesapNo==alan)
	            {
	            	satir4=satir3;
	            	say2++;
	            	y=0;
				}
            }
	    	rewind(fpHesap);

           	if(y==0)
    		{
            	printf("Havale yapmak istediginiz miktari giriniz: ");
    			scanf("%f",&HavaleYapilacakPara);

            	if(HavaleYapilacakPara<=Hesap1.Bakiye)
				{
			    	printf("Bankamiz bu islem icin sizden herhangi bir ucret tahsil etmeyecktir.\n");

					fscanf(fpHesap,"\n%d %s %s %f",&Hesap1.HesapNo,Hesap1.Ad,Hesap1.Soyad,&Hesap1.Bakiye);
                	fscanf(fpHesap,"\n%d %s %s %f",&Hesap2.HesapNo,Hesap2.Ad,Hesap2.Soyad,&Hesap2.Bakiye);

					Hesap1.Bakiye-=HavaleYapilacakPara;
					Hesap2.Bakiye+=HavaleYapilacakPara;

			    	printf("%d nolu ticari hesabinizdan %d nolu hesaba %.2f lira havale yapilmistir.\n",Hesap1.HesapNo,Hesap2.HesapNo,HavaleYapilacakPara);

					FILE *fpdekont=fopen("dekont.txt","a");
				    fprintf(fpdekont, "%s %d %s %d %s %f %d %02d %02d %02d:%02d:%02d\n",yazi1,Hesap1.HesapNo,yazi2,Hesap2.HesapNo,yazi3,HavaleYapilacakPara,tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
			        fprintf(fpdekont,"\n");
					fclose(fpdekont);

    				if(say1==0)
					{
				    	printf("Hesap dogrulanamadi!!!");
					}

					if(say2==0)
					{
	    		    	printf("Hesap dogrulanamadi!!!");
					}

					while(!feof(fpHesap))
					{
						temp1++;
                        fscanf(fpHesap,"\n%d %s %s %f",&Hesap1.HesapNo,Hesap1.Ad,Hesap1.Soyad,&Hesap1.Bakiye);
					}

                    if(temp1!=satir2)
                    {
                        fprintf(fpGecici,"\n%d %s %s %f",Hesap1.HesapNo,Hesap1.Ad,Hesap1.Soyad,Hesap1.Bakiye);
                    }
                    else if(temp1==satir2)
                    {
                        fprintf(fpGecici,"\n%d %s %s %f",Hesap1.HesapNo,Hesap1.Ad,Hesap1.Soyad,Hesap1.Bakiye);
                    }

					while(!feof(fpHesap))
					{
						temp2++;
                        fscanf(fpHesap,"\n%d %s %s %f",&Hesap2.HesapNo,Hesap2.Ad,Hesap2.Soyad,&Hesap2.Bakiye);
					}

                    if(temp2!=satir4)
                    {
                        fprintf(fpGecici,"\n%d %s %s %f",Hesap2.HesapNo,Hesap2.Ad,Hesap2.Soyad,Hesap2.Bakiye);
                    }
                    else if(temp2==satir4)
                    {
                        fprintf(fpGecici,"\n%d %s %s %f",Hesap2.HesapNo,Hesap2.Ad,Hesap2.Soyad,Hesap2.Bakiye);
                    }

				    fclose(fpHesap);
                    fclose(fpGecici);

				    remove("hesaplar.txt");
                    rename("gecici.txt","hesaplar.txt");
                }
            }
        }
        AnaMenu();
    }
}

void HesapOzeti()
{
    musteri Hesap;

    FILE *fpHesap,*fpDekont;
    fpHesap=fopen("hesaplar.txt","r");
    fpDekont=fopen("dekont.txt","r");

    int hesapNumarasi1,hesapNumarasi2,hesapNumarasi3,hesapNumarasi4,say=0;
    float miktar,miktar2;

    char *yazi1,*yazi2,*yazi3,*yazi4,*yazi5;
    yazi1=(char*)malloc(sizeof(char)*20);
    yazi2=(char*)malloc(sizeof(char)*20);
    yazi3=(char*)malloc(sizeof(char)*20);
    yazi4=(char*)malloc(sizeof(char)*20);
    yazi5=(char*)malloc(sizeof(char)*20);


    printf("Lutfen hesap ozetini gormek istediginiz hesap numarasini girin:");
    scanf("%d",&hesapNumarasi1);

    while(!feof(fpHesap))
    {
        fscanf(fpHesap,"%d %s %s %f",&Hesap.HesapNo,Hesap.Ad,Hesap.Soyad,&Hesap.Bakiye);
        if(Hesap.HesapNo==hesapNumarasi1)
        { 
		    say++;
		    while(!feof(fpDekont))
		    { 
			    fscanf(fpDekont,"%s %d %s %f",yazi1,&hesapNumarasi2,yazi2,&miktar);
                if(hesapNumarasi1==hesapNumarasi2)
               {
                    printf("%s %d %s %f\n ",yazi1,hesapNumarasi2,yazi2,miktar);
                  
               }
              

			}
		}
        rewind(fpDekont);
        if(Hesap.HesapNo==hesapNumarasi1)
        { 
		    say++;
			while(!feof(fpDekont))
            {
               fscanf(fpDekont,"%s %d %s %d %s %f",yazi3,&hesapNumarasi3,yazi4,&hesapNumarasi4,yazi5,&miktar2);
               if((hesapNumarasi1==hesapNumarasi3)|| (hesapNumarasi1==hesapNumarasi4))
               {
                    printf("%s %d %s %d %s %f\n",yazi3,hesapNumarasi3,yazi4,hesapNumarasi4,yazi5,miktar2);
               }
			}

		}

        
        fclose(fpDekont);
    }
    fclose(fpHesap);
    if(say==0)
    {
        printf("Hesap dogrulanamadi!!!");
    }
    printf("\nIslem tamamlandi ana menuye yonlendiriliyorsunuz.");
    AnaMenu();



}



void HesapKapama()
{
    musteri Hesap;
    FILE *fphesap,*fpgecici;
    int hesapNumarasi,satir=0,satir2,temp=0,say=0;

    fphesap=fopen("hesaplar.txt","r");
    fpgecici=fopen("gecici.txt","a");

    printf("Kapanacak hesap numarasi giriniz:");
    scanf("%d",&hesapNumarasi);

    while(!feof(fphesap))
    {   satir++;

        fscanf(fphesap,"%d %s %s %f",&Hesap.HesapNo,Hesap.Ad,Hesap.Soyad,&Hesap.Bakiye);
        if(hesapNumarasi==Hesap.HesapNo)
        {
            say++;
            satir2=satir;
        }

    }
    rewind(fphesap);
        if(say==0)
    {
        printf("Hesap dogrulanamadi!!");
    }
    while(!feof(fphesap))
    {   temp++;
        fscanf(fphesap,"%d %s %s %f",&Hesap.HesapNo,Hesap.Ad,Hesap.Soyad,&Hesap.Bakiye);
        if(temp!=satir2)
        {
           fprintf(fpgecici,"\n%d %s %s %f",Hesap.HesapNo,Hesap.Ad,Hesap.Soyad,Hesap.Bakiye);
        }
        else if(temp==satir2)
        {
            temp++;
            printf("\nHesap kapatma islemi gerceklestirildi.Ana menuye yonlendiriliyorsunuz.");
        }
    }
    fclose(fphesap);
    fclose(fpgecici);

    remove("hesaplar.txt");
    rename("gecici.txt","hesaplar.txt");
    AnaMenu();


}



double RandSayiAtama()
{
    double hane;
    srand(time(NULL));
	hane=1+rand()%9;
	if(hane<2)
	{
		hane+=1000+rand()%9000;
	}
	else if(hane<3)
	{
		hane+=2000+rand()%8000;
	}
	else if(hane<4)
	{
		hane+=3000+rand()%7000;
	}
	else if(hane<5)
	{
		hane+=4000+rand()%6000;
	}
	else if(hane<6)
	{
		hane+=5000+rand()%5000;
	}
	else if(hane<7)
	{
		hane+=6000+rand()%4000;
	}
	else if(hane<8)
	{
		hane+=7000+rand()%3000;
	}
	else if(hane<9)
	{
		hane+=8000+rand()%2000;
	}
	else
	{
		hane+=9000+rand()%1000;
	}
	return hane;
}
