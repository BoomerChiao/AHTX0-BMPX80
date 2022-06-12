# AHTX0-BMPX80
##  Summary　（概要）
Arduino Nano「Weather station 」

This is a AHTX0 and BMPX80 arduino nano case.

Some basic code will be provided here.

OLED_PC_temp_B folder will provide AHT10 + BMP180 code 

OLED_PC_temp_x_bmp_B folder will provide AHT20 + BMP280 code 

###  中文
這是由 AHTX0、BMPX80感測器和 arduino nano V3 控制器，編譯而成代碼

OLED_PC_temp_B 文件夾將提供 AHT10 + BMP180 code

OLED_PC_temp_x_bmp_B 文件夾將提供 AHT20 + BMP280 code

##  Installation　（安裝）
Install Arduino software
- Arduino software downloads：https://www.arduino.cc/en/software
																				LOGO
###  中文
安裝 Arduino 軟體
- Arduino 軟體下載：https://www.arduino.cc/en/software

##  Import data　（導入資料）
Downloads GitHub data or create a new arduino project.

Move in the necessary Arduino library provide extra functionality. 
The function library part can be download from the GitHub “Library” folder.
You can also open the IDE and click to the "Sketch" menu and then Include Library > Manage Libraries.

After importing the function library.
Select the project you want to make and input project.


###  中文
下載本網 GitHub 資料或自行創建新Arduino專安

導入必要的程式函數庫至Arduino，函數庫部分可選擇 GitHub “Library” 資料夾中下載，並安裝置指定位子又或自行至Arduino 「草稿碼 → 匯入程式庫 → 管理程式庫...」 下載 

函數庫導入完成後，選擇你想要製作的專案直接開啟即可


##  Illustration 圖文

A2
按照步驟１先開啟 「草稿碼 → 匯入程式庫 → 加入ZIP...」 

，接著來到步驟２點選需要導入Library

A3
正常導入成功會出現，加入完成警示標語

若出現紅色警示標語，則表示已有函數庫又或者導入資料有誤
####  PS.若出現『函數庫已存在』可以不用再次導入，反之亦然

A1
函數庫導入完成之後

可進行導入 Arduino 草稿碼，選擇你想要製作專案導入至Arduino

A5
導入完畢後，直接點擊「A5-1」

然後開啟 「A5-2」 監控視窗，即可看見目前感測器回傳數據

###  函數庫其他導入方式
A4
函數庫也能從Arduino內部進行下載
####  PS.切記要下載一樣的函數庫，免得無法順利完成作業

##  BMP280 Special access app settings (BMP280特殊設定)
B1
本文採用Library I2C BMP280 ，若出現 BMP280 無法順利顯示時，請先確認購買的 BMP280 I2C 通訊
####  PS.可使用查詢 Arduino I2C掃描程式來偵測I2C裝置的位置
This article uses the library I2C BMP280. If the BMP280 cannot display smoothly, please confirm the I2C communication of the BMP280 you purchased.
####  PS.The location of the I2C device can be detected using the Arduino I2C Scanner program.

B2
經過實驗過程中發現，部分 BMP280 i2c 通訊並非預設值

請將 I2C_ADDRESS 更改成你購買的 BMP280 i2c

During the experiment, it was found that some BMP280 i2c communication is not the default value.
Please change I2C_ADDRESS to the BMP280 i2c you purchased.

範例如下   (假設購買 BMP280 I2C 0x77)
``` r
static const uint8_t I2C_ADDRESS = (0x77); //
```
