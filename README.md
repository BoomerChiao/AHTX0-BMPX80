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
									
###  中文
安裝 Arduino 軟體
- Arduino 軟體下載：https://www.arduino.cc/en/software

![image](https://user-images.githubusercontent.com/107128781/173234852-6a2b32c5-e615-419b-9bea-7cbe7ea3a297.png)

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

![image](https://user-images.githubusercontent.com/107128781/173234879-32a637df-706e-4fe7-aef7-49ca6642edca.png)

按照步驟１先開啟 「草稿碼 → 匯入程式庫 → 加入ZIP...」 

，接著來到步驟２點選需要導入Library

![image](https://user-images.githubusercontent.com/107128781/173234885-5a8a3c51-feff-4438-844c-57205359d37b.png)

正常導入成功會出現，加入完成警示標語

若出現紅色警示標語，則表示已有函數庫又或者導入資料有誤
####  PS.若出現『函數庫已存在』可以不用再次導入，反之亦然

![image](https://user-images.githubusercontent.com/107128781/173234871-ac0d9d48-8a86-4861-9d82-48c990112f04.png)

函數庫導入完成之後

可進行導入 Arduino 草稿碼，選擇你想要製作專案導入至Arduino

![image](https://user-images.githubusercontent.com/107128781/173234895-48d564a7-6d1e-4d32-9d93-5f7dfe668286.png)

導入完畢後，直接點擊「![image](https://user-images.githubusercontent.com/107128781/173234908-5769d9ca-f67b-43ba-8254-fd79fd524e35.png)
」

然後開啟 「![image](https://user-images.githubusercontent.com/107128781/173234914-6b1be4c0-3855-4c34-86ce-fa7820cd922a.png)
」 監控視窗，即可看見目前感測器回傳數據

###  函數庫其他導入方式
![image](https://user-images.githubusercontent.com/107128781/173234889-444505fd-e1f6-4489-b570-918bc3be5d00.png)

函數庫也能從Arduino內部進行下載
####  PS.切記要下載一樣的函數庫，免得無法順利完成作業

##  BMP280 Special access app settings (BMP280特殊設定)
![image](https://user-images.githubusercontent.com/107128781/173234937-02e03a92-4957-4d4f-b0da-26d57c44eab1.png)

本文採用Library I2C BMP280 ，若出現 BMP280 無法順利顯示時，請先確認購買的 BMP280 I2C 通訊
####  PS.可使用查詢 Arduino I2C掃描程式來偵測I2C裝置的位置
This article uses the library I2C BMP280. If the BMP280 cannot display smoothly, please confirm the I2C communication of the BMP280 you purchased.
####  PS.The location of the I2C device can be detected using the Arduino I2C Scanner program.

![image](https://user-images.githubusercontent.com/107128781/173234946-fe45294e-781d-4c23-9bd3-5634b7464514.png)

經過實驗過程中發現，部分 BMP280 i2c 通訊並非預設值

請將 I2C_ADDRESS 更改成你購買的 BMP280 i2c

During the experiment, it was found that some BMP280 i2c communication is not the default value.
Please change I2C_ADDRESS to the BMP280 i2c you purchased.

範例如下   (假設購買 BMP280 I2C 0x77)
``` r
static const uint8_t I2C_ADDRESS = (0x77); //Modify it to the BMP I2C you use.
```
