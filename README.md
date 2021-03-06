# Terminal

  Terminal, GTK-3.0 kullanılarak tasarlanmış bir pencere üzerine eklenen VTE sanal terminal emulatörüdür.

  Standart olarak sistemin kendi pencere teması kullanır. Terminal renk şeması, siyah(%90 opak) arkaplan üzerine beyaz metindir. Tasarlanırken oldukça hafif olması ve sistemi kasmadan terminal ihtiyacını karşılaması amaçlanmıştır.
  
  Aşağıda ekran görüntüsünü görebilirsiniz.
  
![Alt text](https://github.com/fuxprojesi/terminal/blob/master/terminal.png "Terminal Ekran Görüntüsü")

# Terminal'in özellikleri:

*  Özel klavye kısayolları.
*  Oturum açan kullanıcıya göre değişken başlık.
*  Sürükle-Bırak ile dizin, dosya konumlarını terminale aktarma.
*  Fare sağ tuş menüsü (Terminal Aç, Kopyala, Yapıştır, Ekranı Temizle, Komut Geçmişi, Terminali Kapat)
*  Fare ile seçilerek kopyalanan metni önbelleğe alır. Metni ister terminale isterseniz herhangi bir belgeye yapıştırabilirsiniz.
*  Standart bir terminaldir ve diğer tüm terminallerde yapılan herşey yapılabilir.

# Klavye Kısayolları:

| Kombinasyon | Açıklama |
| --- | --- |
|  Ctrl + Shift + T | Terminal Aç |
|  Ctrl + Shift + C | Kopyala |
|  Ctrl + Shift + V | Yapıştır |
|  Ctrl + Shift + E | Ekranı Temizle |
|  Ctrl + Shift + H | Komut Geçmişi |
|  Ctrl + Shift + Q | Terminali Kapat |
|  Ctrl + Shift + R | Geçmiş Komutlardan Tamamla (Arama) |
|  Ctrl + Shift + Up | Çıktıyı Yukarı Kaydır (Satır) |
|  Ctrl + Shift + DOWN | Çıktıyı Aşağı Kaydır (Satır) |
|  Ctrl + Shift + PgUP | Çıktıyı Yukarı Kaydır (Sayfa) |
|  Ctrl + Shift + PgDn | Çıktıyı Aşağı Kaydır (Sayfa) |
|  Ctrl + Shift + HOME | En Başa Git |
|  Ctrl + Shift + End | En Sona Git |
  
# Detaylı açıklama:  

  Fux İşletim Sistemi'nin standart terminalidir.
  
  Terminal Genel Kamu Lisansı ile birlikte dağıtılan özgür bir yazılımdır.
  
 # Yazılım Gereksinimleri
 
 * gtk3-devel
 * vte291-devel
 * coreutils
 * bash
 * gcc
  
 # Derleme ve Çalıştırma
 
 * Derleme dizini'nin fuat kullanıcısına ait ev dizininde ki terminal-master olduğu varsayılmıştır!
 
 ## Komut
 
 * gcc `pkg-config --cflags --libs gtk+-3.0 vte-2.91` -o terminal /home/fuat/terminal-master/src/terminal.c
 
 * Derleme tamamlanınca bulunduğunuz dizinde terminal adı ile bir ikili dosya oluşacaktır. Bu dosyayı /usr/bin dizini içine kopyalayın.
 * /home/fuat/terminal-master/terminal.desktop dosyasını da /usr/share/applications dizinine kopyalayın.
 * Dilerseniz LICENSE ve README.md dosyalarını /usr/share/doc dizini içerisinde terminal adında bir dizin oluşturarak içine kopyalayabilirsiniz.
