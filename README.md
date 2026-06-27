# About
This repo contains the KiCad 6 design files for the DC-34-Countdown-To-Singularity DEFCON badge, which allows users to display their estimate for when the AI singularity will occur. Buttons on the front will allow the user to shift their time estimate.

## Board Features
- Eight 7-segment display
- Real-Time clock 

## Project Structure
The structure of this repo is organized as such:

| Directory                | About                                                                    |
|:-------------------------|:-------------------------------------------------------------------------|
| BillOfMaterials.fods     | Bill of Materials                                                        |
| DC-34-Countdown-To-Singularity-Board | KiCad 6 Design files                                                     |
| libraries                | Symbol libraries and footprints downloaded from digikey                  |

## Running
### Board Design
To view schematics, please run KiCad 6.0.11 or later. Change directory into 
DC-34-Badge and run
```
$ kicad DC-34-Badge.kicad_pro &
```

Please note: please run kicad from the same directory as the .kicad_pro file 
is stored because the fp-lib-table and sym-lib-table use relative paths 
so that this project is portable between computers.

# Links
May make use of this code for the segment 
https://github.com/untr0py/SevSeg
