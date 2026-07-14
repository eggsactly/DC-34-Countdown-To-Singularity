# About
This repo contains the KiCad 6 design files for the DC-34-Countdown-To-Singularity DEFCON badge, which allows users to display their estimate for when the AI singularity will occur. Buttons on the front will allow the user to shift their time estimate.

## Board Features
- Eight 7-segment displays
- Real-Time clock 

## Project Structure
The structure of this repo is organized as such:

| Directory                | About                                                                    |
|:-------------------------|:-------------------------------------------------------------------------|
| BillOfMaterials.fods     | Bill of Materials, libreoffice flat XML ODS spreadsheet                  |
| DC-34-Countdown-To-Singularity-Board | KiCad 6 Design files                                                     |
| libraries                | Symbol libraries and footprints downloaded from digikey                  |

## Running
### Board Design
To view schematics, please run KiCad 6.0.11 or later. Change directory into 
DC-34-Countdown-To-Singularity-Board and run
```
$ kicad DC-34-Countdown-To-Singularity-Board.kicad_pro &
```

Please note: please run kicad from the same directory as the .kicad_pro file 
is stored because the fp-lib-table and sym-lib-table use relative paths 
so that this project is portable between computers.

### Firmware
To view and edit the embedded software for the board, change directory into 
DC-34-Countdown-To-Singularity-Firmware and run
```
$ arduino-1.8.5 DC-34-Countdown-To-Singularity-Firmware.ino & 
```

# Bill of Materials (BOM)
|Part|Symbol|Notes|Quantity per Board|Price|Link|
|:---|:-----|:----|:-----------------|:----|:---|
|PCF8523T|U4|Real-time Clock|1|$1.35|[link](https://www.digikey.com/en/products/detail/nxp-usa-inc/PCF8523T-1-118/2530422)|
|AMSRI-7805-EZ|U1|5v Regulator|1|$0.52|[link](https://www.digikey.com/en/products/detail/onsemi/MC7805CTG/919333)|
|1N4007|D1|Diode|1|$0.09|[link](https://www.digikey.com/en/products/detail/lumimax-optoelectronic-technology/1N4007/24769361)|
|100uF|C1, C2|Capacitor|2|$0.23|[link](https://www.digikey.com/en/products/detail/w%C3%BCrth-elektronik/860040573004/5727450)|
|0.1uF|C5-C11|Capacitor|7|$0.27|[link](https://www.digikey.com/en/products/detail/vishay-beyschlag-draloric-bc-components/K104K10X7RF5UH5/2356754)|
|10uF|C3, C4|Capacitor|2|$0.10|[link](https://www.digikey.com/en/products/detail/w%C3%BCrth-elektronik/860020572003/5727172)|
|22pF|C12, C13|Capacitor|2|$0.23|[link](https://www.digikey.com/en/products/detail/vishay-beyschlag-draloric-bc-components/K220J10C0GF5UH5/2821614)|
|LM317|U2|3.3v Regulator|1|$0.49|[link](https://www.digikey.com/en/products/detail/lumimax-optoelectronic-technology/LM317/29366241)|
|HC-49/U-S16000000ABJB|Y1|Arduino Crystal|1|$0.49|[link](https://www.digikey.com/en/products/detail/citizen-finedevice-co-ltd/HC-49-U-S16000000ABJB/284222)|
|240 Ohm|R1|Resistor|1|$0.10|[link](https://www.digikey.com/en/products/detail/stackpole-electronics-inc/CF14JT240R/1741355)|
|330 Ohm|R2-R9|Resistor|8|$0.10|[link](https://www.digikey.com/en/products/detail/stackpole-electronics-inc/CF14JT330R/1741399)|
|390 Ohm|R10|Resistor|1|$0.10|[link](https://www.digikey.com/en/products/detail/stackpole-electronics-inc/CF14JT390R/1741412)|
|1k Ohm|R11-R13|Resistor|3|$0.10|[link](https://www.digikey.com/en/products/detail/stackpole-electronics-inc/CF14JT10K0/1741265)|
|10k Ohm|R14-R16|Resistor|3|$0.10|[link](https://www.digikey.com/en/products/detail/stackpole-electronics-inc/CF14JT10K0/1741265)|
|ATMEGA328P-PU|U3|Arduino CPU|1|$2.89|[link](https://www.digikey.com/en/products/detail/microchip-technology/ATMEGA328P-PU/1914589)|
|DCJ200-10-A-K1-K|J1|9v Jack Connector|1|$0.74|[link](https://www.digikey.com/en/products/detail/gct/DCJ200-10-A-K1-K/9859579)|
|151031SS06000|D2, D3|Red LEDs|2|$0.17|[link](https://www.digikey.com/en/products/detail/w%C3%BCrth-elektronik/151031SS06000/4489982)|
|G43270009|Y2|Real-time Clock Crystal|1|$0.49|[link](https://www.digikey.com/en/products/detail/diodes-incorporated/G43270009/9768315)|
|BAT-HLD-012-SMT-TR|BT1|Real-time Clock Battery|1|$0.55|[link](https://www.digikey.com/en/products/detail/te-connectivity-linx/BAT-HLD-012-SMT-TR/5361776)|
|SSK04-FPH-254-B3|J4-J10|SAO Connector|7|$0.33|[link](https://www.digikey.com/en/products/detail/same-sky-formerly-cui-devices/SSK04-FPH-254-B3/28772217)|
|M20-9980346|J3|ISP Port|1|$0.26|[link](https://www.digikey.com/en/products/detail/sullins-connector-solutions/SBH11-PBPC-D05-ST-BK/1990062)|
|TL1105AF160Q|SW1-SW3|Push Button|3|$0.30|[link](https://www.digikey.com/en/products/detail/e-switch/TL1105AF160Q/80826?gclsrc=aw.ds&gad_source=1&gad_campaignid=20504615652&gbraid=0AAAAADrbLliuJu1uVwhOZx8oNThZmoftP&gclid=Cj0KCQjwxvjRBhC2ARIsAI7KJa17DjaeKU3qO8WLGJrtWiDEGZ3HZdtEaDUREVu5W3xdJPioqquFpEcaAitnEALw_wcB)|
|7 segment display|U5, U6|Note: 5 in package|2|$1.60|[link](https://www.amazon.com/uxcell-Common-Segment-Display-Digital/dp/B07GTRQYMV/ref=sr_1_10_sspa?crid=4NAL0LV9W0PX&dib=eyJ2IjoiMSJ9.sJ4vZ-fRm6skVo9AlMS6sFmeQhSCNJgU4iHs_Ng_25OMl-GpMH60i0OrJqX9XP7Oiyr0XQJDg6FJT1rgluWGHrnGZpWRy6xxFFkzOkklooHfazh9ALOKmsx2zNxXJvmv_8nMpeFfy8Gg497A-0gbJB1nZtNVCG2Y1_Jw7pObRX_1G5oVwMNVGzSLIiDwKWgFGuUTJ8msJSgrnIq2VsvIXl27kO10MDbYQWre_tWm2LI.1boDFUgrhYQLg7Gh2yKqU1fQah9ke1yF89TkQ9W7HGs&dib_tag=se&keywords=7%2Bsegment%2Bdisplay&qid=1782516534&sprefix=7%2Bsegm%2Caps%2C301&sr=8-10-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9tdGY&th=1)|
|9v Battery||12 in package|1|$1.48|[link](https://www.amazon.com/dp/B0B4RSNDPG?ref_=apb_fb_ac_d_apb_fb_asin_batteries&pd_rd_w=I5vqD&content-id=amzn1.sym.23b3cfca-3737-4a86-96a3-75e538f8c833%3Aamzn1.sym.23b3cfca-3737-4a86-96a3-75e538f8c833&pf_rd_p=23b3cfca-3737-4a86-96a3-75e538f8c833&pf_rd_r=5NSY61YKBS0D4HM433D8&pd_rd_wg=HZtc3&pd_rd_r=1c934474-5af1-49cc-8264-793227ac73c1&pd_rd_i=B0B4RSNDPG&th=1)|
|Battery to jack||5 per pack|1|1.198|[link](https://www.amazon.com/dp/B0D9VTG5V4/ref=twister_B0D9VW8HHC?_encoding=UTF8&th=1)|
|CR1220||10 pack|1|0.599|[link](https://www.amazon.com/PKCELL-CR1220-Battery-Lithium-Count/dp/B0D8T4C5PK/ref=sr_1_8?dib=eyJ2IjoiMSJ9.b2h7Ukb4oRuYiL9U7ru5Wo9-0wfVO7UgOOn_coPC0U9V8YTR7MUMXNd32A-5_l7buGLQ3sSbNN0xohPsA0QmEJfPeDZqaHF661mXDAFpEcS6Gf7I5JO_TnCWD2073snm2inmQBZL8SfQ3yfQzqubGqbs8j3InbqdE_fyDQRM83qetkl1sFunl8Drxl17hKO1ZbDNGnV7hPf0UvgZGVUcUSJvzmpKrbHLaWMH4qfujoNJUUINCThk82FHMQA-zwGWA0QHTGWPSbwI4DUzyBCLSUIWZuZynAB-DwOjPcrV_dY.0RrEy335qbLLTP8G15gIUlc_W4f1ujaYf2qcIWrT5OY&dib_tag=se&keywords=CR1220&qid=1782662524&sr=8-8)|
||||Total:|$22.293||
|CP2102 USB 2.0 to TTL||Programmer, only need one total||$7.39|[link](https://www.amazon.com/HiLetgo-CP2102-Converter-Adapter-Downloader/dp/B00LODGRV8/ref=sr_1_4?crid=3N2AAJERECNDC&dib=eyJ2IjoiMSJ9.hUJFlG217U_LnkM3KidzS3FKWJeWYSkHCn6SAL4KJ_Ib7o3mKI4v0jNeA5cj8NegSukIKK35IJS73ZcvJEuIzNtMOB0lmW4zz8h0wT2xd5O-wL5HZ1Jq-kccCZlravERYeTMUB0YvGwV5GUa5RD9rrCCEpf9qofrfsFlZo_cVybTZ4c7AimKXqeqjiBJgWlZmMxm8Yy98iMtsa1XLMk7ne8SLlJuDfjRXPhM1IbA0CQ.dZASXdFWQDhTLffimIKDTc4vLOa-gK8wn2EY_zrKvms&dib_tag=se&keywords=USB%2Bto%2BTTL&qid=1782663949&sprefix=usb%2Bto%2Bttl%2Caps%2C235&sr=8-4&th=1)|

