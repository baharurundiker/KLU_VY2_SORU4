#include <stdio.h>
#include <stdlib.h>
//İlk olarak düğüm yapısını oluşturuyoruz.
struct dugum {
	int degerler;
	struct dugum *sonraki;
	
};
struct dugum *onKisim = NULL;
struct dugum *ucKisim = NULL;

//Daha sonra kuruktaki elemanları göstermek için fonskiyonumuzu yazıyoruz.
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
//Ekleme fonksiyonunu yazıyoruz.
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
//Silme fonksiyonunu yazıyoruz.Kuyruk yapıları FIFO yapısında çalıştığı için ilk eklenen eleman ilk siliniyor.
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
	
	//Programın çıkış seçeneğini seçmeden sonlanmaması için while döngüsüne 1 değerini atayarak işlemleri döngüye sokuyoruz.
	
	int kullaniciSecim,islemYapilanEleman;
	while(1){
	
	printf("Kuyruk Islemleri\n");
	printf("1 - Kuyrugu goruntulemek icin seciniz.\n");
	printf("2 - Kuyruga eleman eklemek icin seciniz.\n");
	printf("3 - Kuyrutan eleman cikarmak icin seciniz.\n");
	printf("4 - Uygulamayi sonlandirmak icin\n");
	printf("Istediginiz islemin rakamini giriniz.\n");
	scanf("%d",&kullaniciSecim);
	
    //Switch-case yapısını kullanarak işlemlerimizi yaptırıyoruz.
	switch(kullaniciSecim){
		case 1:
			printf("Secimizin 1\n");
			gostermeFonksiyonu();
			break;
			
		case 2:
			printf("Secimizin 2\n");
			printf("Eklemek istediginiz elemani giriniz\n");
			scanf("%d",&islemYapilanEleman);
			eklemeFonksiyonu(islemYapilanEleman);
			break;
		case 3:
			printf("Secimizin 3\n");
			silmeFonksiyonu();
			break;
			
		case 4:
			printf("Secimizin 4\n");
		    printf("Uygulama kapatiliyor...\n");	
		    return 0;
		
		default:
			printf("Gecersiz secenek!!!\n");
			break;	
	}
}	
	return 0;
}
