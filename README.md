# Capstone-salonki

*Capstone projektin koodit: Backend ja sensori*

## Projektin esittely

Tällä projektin toteutuksella haettiin ratkaisuja ilmanlaadun mittaamiseen, datan keruun eri mahdollisuuksiin, ja tutkittiin miten havaittua dataa pystyttäisiin käyttämään hyödyksi Salon Kaupungin kehittämiseksi. 

Tämä projekti oli osa Turun Yliopiston Capstone Project -kurssia ja Salon Älykäs Kaupunki hanketta. Yhteistyötä tehtiin sekä Salon Kaupungin, että Lounea Oy:n kanssa.

## Käytetyt tekniikat

Projektin backend toteutuksessa käytettiin seuraavia tekniikoita:

* Javascript
* Node
* ExpressJS
* Arduino (C, C++)
* MongoDB Atlas
* Heroku

Näistä kaksi viimeisintä ovat pilvipalveluita, joiden kanssa hoituivat datan tallennus ja backend serverin pystytys. Haluttaessa nämä palvelut voidaan vaihtaa.


## ESP8266 ja sensori
 
 Saatavilla olevien resurssien nojalla prototyyppi toteutettiin käyttäen ESP-8266 moduulia, sillä langattoman yhteyden muodostaminen internettiin osoittautui järkevimmäksi ratkaisuksi projektin kannalta.

Ilmanlaadun mittaamiseen käytetiin lähinnä TVoC-arvoja mittaavaa CCS811-anturia. Muita varteenotettavia mittalaitteita voisivat olla esimerkiksi pienhiukkassensorit.

## Kytkentäkaavio ja arkkitehtuuri 

![Kytkentäkaavio ja arkkitehtuuri](/images/circuit&architecture.png)

## Projektin ajaminen
### Ohjelmien asennus
Projektin ajamiseen tarvitaan seuraavat ohjelmat:
 - [NodeJS](https://nodejs.org/)
 - [(GIT)](https://git-scm.com/) suositeltava, muttei pakollinen
 
### Backend:n ajaminen (NPM)
Projektin ajamiseen käytetään npm paketinhallitsijaa (engl. package manager). NodeJS asennus asentaa myös npm:n asennuksen.

Siirry komentokehotteessa oikeaan kansioon, jonka jälkeen seuraavat komennot asentavat ja ajavat backendin kehitysympäristössä 

    npm install
    npm start

Tuotantoon koonti:

    npm build
