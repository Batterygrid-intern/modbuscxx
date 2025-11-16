# libmodbus

jag sätter ett slave_id för att 

modbus master slave arkitektur
# modbus rtu /serial
modbusstandard = osi layer 7(application layer)

modbus serial line specification = osi layer 1 - 2

# PEM353
Float IEEE754 32-bit (single precision floating point number) = vad menas med single precision?

ett register i modbus är sparat som uint_16 (2 bytes) så för float data (float=4bytes) så sparas datan på 2 register.
läser dom 2 registrerna och gör om datan till floats genom att ora ihop dom.
# client =  master
skickar förfrågan om att läsa data från olika register får svar med data på det registret
**set_slave_id** definierar id på varje slave jag vill kommunicera med. kommunicerar jag med olika så sätter jag för varje slave jag ska prata med 
# server  = slave 
lagrar data på olika register som jag kan komma åt med en master
**set_salve_id** måste vara ett unikt id inom modbus nätverket (på busen) måste initieras på varje slave används för att mastern ska kunna komma åt datan


