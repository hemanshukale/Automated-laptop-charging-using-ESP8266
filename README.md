# Automated-laptop-charging-using-ESP8266
Optimize your battery life by automating it's charging cycles between 30% - 80% 


Many laptop users face this problem of battery dying - usually because of always keeping charging on, hence damaging battery 
And it might be problematic to turn off the charger and risk the chance of laptop shutting down during a critical time if forgot to turn it back on 

Here's an automated version of that -  
currently made for Windows 10 (powershell) & bash on linux  

Electronics needed -   
  ESP8266  
  Relay Moudle or Relay, Transistor (BC547) & Diodes  
  Resistors  
  5V supply for relays  
  AMS1117 Voltage regulator    
  Wires   
  Plug and socket  
  
Pinouts - 
  
  ESP8266 -
  
  VCC, EN,  - 3.3V  
  GPIO 2    - Pulled up  
  GND       - GND  
  GPIO15    - Pulled Down  
  GPIO 12   - Transistor base with around 1K resistor in between ; can be pulled down for additional safety  
  GPPIO 0   - GND for flashing  
  
  Connect 1 terminal of relay to 5V and other to collector of VCC  
  Emmitter  - GND  
  also connect a reverse biased diode to act as flyback diode between the terminals of the relay   
  
  Direct the power to charger through relay  
  Mains Live - relay T1 ; relay T2 - Charger Live  
  Mains Neutral - Charger Neutral  
  
