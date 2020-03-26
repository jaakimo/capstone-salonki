# Capstone-salonki

*Capstone projektin koodit: Backend*

## Projektin esittely

Tällä projektin toteutuksella haettiin ratkaisuja ilmanlaadun mittaamiseen, datan keruun eri mahdollisuuksiin, ja tutkittiin miten havaittua dataa pystyttäisiin käyttämään hyödyksi Salon Kaupungin kehittämiseksi. 

Tämä projekti oli osa Turun Yliopiston Capstone Project -kurssia ja Salon Älykäs Kaupunki hanketta. Yhteistyötä tehtiin sekä Salon Kaupungin, että Lounea Oy:n kanssa.

## Käytetyt tekniikat

Projektin backend toteutuksessa käytettiin seuraavia tekniikoita:

* Javascript
* Node
* ExpressJS
* MongoDB Atlas
* Heroku
* Arduino (C, C++)

Näistä kaksi viimeisintä ovat pilvipalveluita, joiden kanssa hoituivat datan tallennus ja backend serverin pystytys. Haluttaessa nämä palvelut voidaan vaihtaa.


## ESP8266 ja sensori
 
 Saatavilla olevien resurssien nojalla prototyyppi toteutettiin käyttäen ESP-8266 moduulia, sillä langattoman yhteyden muodostaminen internettiin osoittautui järkevimmäksi ratkaisuksi projektin kannalta.

Ilmanlaadun mittaamiseen käytetiin lähinnä TVoC-arvoja mittaavaa CCS811-anturia. Muita varteenotettavia mittalaitteita voisivat olla pienhiukkassensorit.

## Kytkentäkaavio ja arkkitehtuuri 

![Kytkentäkaavio ja arkkitehtuuri](/images/circuit&architecture.png)
