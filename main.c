#include <stdio.h>
#include <stdlib.h>
//Ýlk olarak düðüm yapýsýný oluþturuyoruz.
struct dugum {
	int degerler;
	struct dugum *sonraki;
	
};
struct dugum *onKisim = NULL;
struct dugum *ucKisim = NULL;

//Daha sonra kuruktaki elemanlarý göstermek için fonskiyonumuzu yazýyoruz.
void gostermeFonksiyonu() {
    if (onKisim == NULL) {
        printf("Kuyrukta eleman bulunmamakta.\n");
        return;
    }
    
    struct dugum *suanGosterilen = onKisim;
    
    printf("Kuyruk: \n");
    while (suanGosterilen != NULL) {
        printf("%d ", suanGosterilen->degerler);
        suanGosterilen = suanGosterilen->sonraki;
        printf("\n");
    }
    
}
//Ekleme fonksiyonunu yazýyoruz.
void eklemeFonksiyonu(int deger) {
    struct dugum* yeniDugum = (struct dugum*)malloc(sizeof(struct dugum));
    yeniDugum->degerler = deger;
    yeniDugum->sonraki = NULL;
    
    if (ucKisim == NULL) {
        onKisim = ucKisim = yeniDugum;
    } else {
        ucKisim->sonraki = yeniDugum;
        ucKisim = yeniDugum;
    }
    
    printf("%d kuyruga eklendi.\n", deger);
}
//Silme fonksiyonunu yazýyoruz.Kuyruk yapýlarý FIFO yapýsýnda çalýþtýðý için ilk eklenen eleman ilk siliniyor.
void silmeFonksiyonu() {
    if (onKisim == NULL) {
        printf("Kuyrukta eleman bulunmamakta.\n");
        return;
    }
    
    struct dugum  *gecici = onKisim;
    
    onKisim = onKisim->sonraki;
    
    printf("%d kuyruktan cikarildi.\n", gecici->degerler);
    free(gecici);
}


int main(int argc, char *argv[]) {
	
	
	printf("Bahar Urundiker,1220505018,KLU\n");
	printf("Kuyruklarin baglantili liste uygulamasini gosteren kod dizisi.\n");
	printf("Kullanicinin secimleriyle ekleme,silme ve goruntuleme islemleri yapabilir.\n");
	printf("************************************************\n");
	
	//Programýn çýkýþ seçeneðini seçmeden sonlanmamasý için while döngüsüne 1 deðerini atayarak iþlemleri döngüye sokuyoruz.
	
	int kullaniciSecim,islemYapilanEleman;
	while(1){
	
	printf("Kuyruk Islemleri\n");
	printf("1 - Kuyrugu goruntulemek icin seciniz.\n");
	printf("2 - Kuyruga eleman eklemek icin seciniz.\n");
	printf("3 - Kuyrutan eleman cikarmak icin seciniz.\n");
	printf("4 - Uygulamayi sonlandirmak icin\n");
	printf("Istediginiz islemin rakamini giriniz.\n");
	scanf("%d",&kullaniciSecim);
	
    //Switch-case yapýsýný kullanarak iþlemlerimizi yaptýrýyoruz.
	switch(kullaniciSecim){
		case 1:
			gostermeFonksiyonu();
			break;
			
		case 2:
			printf("Eklemek istediginiz elemani giriniz\n");
			scanf("%d",&islemYapilanEleman);
			eklemeFonksiyonu(islemYapilanEleman);
			break;
		case 3:
			silmeFonksiyonu();
			break;
			
		case 4:
		    printf("Uygulama kapatiliyor...\n");	
		    return 0;
		
		default:
			printf("Gecersiz secenek!!!\n");
			break;	
	}
}	
	return 0;
}
