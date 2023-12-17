String ascii1 = "          _ ._  _ , _ ._\n        (_ ' ( `  )_  .__)\n     ( (  (    )   `)  ) _)\n     (__ (_   (_ . _) _) ,__)\n         `~~`\ ' . /`~~`\n              ;   ;                \n \_____________/_ __ \_____________\n";
String catPic = "  ^~^  ,\n (\'Y\'\) )\n /   \\/ \n \(\\|||/\) hjw\n";

String batPic = "    =/\\                 /\\=\n    / \\\'._   (\\_/)   _.\'/ \\\n   / .\'\'._\'--(o.o)--\'_.\'\'. \\\n  /.\' _/ |`\'=/ \" \\=\'`| \\_ `.\\\n /` .\' `\\;-,\'\\___/\',-;/` \'. \'\\\n/.-\'       `\\(-V-)/`       `-.\\\n`            \"   \"            `\n";

String trainPic = "____\n|DD|____T_\n|_ |_____|<\n  @-@-@-oo\\\n";

String compPic = "\n     _____ \n     ||--||\n     ||__||\n     [ -=.]`)\n     ====== 0";

void setup() {
// initialize both serial ports:
Serial.begin(9600);
Serial.print(ascii1);
Serial.print("\n-------------------\n");

Serial.print(trainPic);
Serial.print("\n-------------------\n");

Serial.print(batPic);
Serial.print("\n-------------------\n");

Serial.print(catPic);
Serial.print("\n-------------------\n");

Serial.print(compPic);
Serial.print("\n-------------------\n");
pinMode(LED_BUILTIN, OUTPUT);
}
int ledState = HIGH;
void loop() {
if(ledState == HIGH) {
ledState = LOW;
}
else {
ledState = HIGH;
}
digitalWrite(5, ledState);
digitalWrite(5, ledState);
//countString = String(count);

}