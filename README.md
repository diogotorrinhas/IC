# Information and Coding
## Comandos de Compilação e Resultados


### Ex2:
#### Comandos de compilação:
>../sndfile-example-bin/ex2 sample.wav Avg > hist.txt 

>../sndfile-example-bin/ex2 sample.wav Difference > histDiff.txt 

>- gnuplot -p -e ‘set sty d hist;set xtic rot; plot “hist.txt” u 2:xtic(1)’ 

- gnuplot -p -e ‘set sty d hist;set xtic rot; plot “histDiff.txt” u 2:xtic(1)’ 

### Ex3:
#### Comandos de compilação:
move 10 bits
> ../sndfile-example-bin/wav_quant sample.wav 10 samplebits.wav


### Ex4:
#### Comandos de compilação:
> g++ wav_cmp.cpp -o wav_cmp

> ./wav_cmp sample.wav out.wav

#### Resultado (SNR da audiofile sample.wav em relação à out.wav):
![ex4](https://user-images.githubusercontent.com/84578738/198879260-b746c277-8c7e-4ff9-bc36-415ef973be2d.png)

#### Resultado (SNR da audiofile sample.wav em relação à copy.wav(audiofile igual)):
![ex42](https://user-images.githubusercontent.com/84578738/198881115-240eca30-6ec8-463e-b017-7a110be98b28.png)

### Ex5:
#### Comandos de compilação:
> g++ wav_effects.cpp -o wav_effects

>./wav_effects sample.wav sampleEco.wav

#### Resultado (Se quisermos Eco Simples descomentar a parte "Eco", linha60 no ficheiro wav_effects e correr comandos):
- Ouvir audiofile sampleEco.wav resultante

#### Resultado (Se quisermos Eco Múltiplo descomentar a parte "Eco Múltiplo", linha63 no ficheiro wav_effects e correr comandos):
- Ouvir audiofile sampleEco.wav resultante

### Ex7:
#### Comandos de compilação:
Para o Encoder (converter ficheiro txt num ficheiro binário):
> g++ BitStream.cpp encoder.cpp -o ex7encoder

>./ex7encoder ex7.txt ex7convertido.bin

#### Resultado (Exemplo de conteúdo ficheiro bin):
Ficheiro txt:

![ficheirotxt](https://user-images.githubusercontent.com/84578738/198882818-88bde658-04b5-4f57-a6b0-21f0dbbdedad.png)

Depois de usar encoder:

![ex7enc](https://user-images.githubusercontent.com/84578738/198882568-c9459840-91b9-442d-8bd2-329d30c7317b.png)

![ex7bin](https://user-images.githubusercontent.com/84578738/198882611-9a6914cd-cac9-45ac-8a32-43f21a316f45.png)

Para o Decoder (converter o ficheiro bin anterior, em ficheiro txt (ficheiro resultante igual ao original antes de usado o encoder)):
> g++ BitStream.cpp decoder.cpp -o ex7decoder

>./ex7decoder ex7convertido.bin ex7desconvertido.txt
#### Resultado (Usar decoder em ficheiro bin , resultando ficheiro txt, igual ao original antes de ter usado o encoder):
![ex7desconv](https://user-images.githubusercontent.com/84578738/198883000-aedf0623-997f-454b-b116-47c8db7ac075.png)

Ficheiro resultante após usar decoder:

![ex7txtdesconv](https://user-images.githubusercontent.com/84578738/198883119-116f63c8-8a15-470b-80ef-f644ac6f8402.png)



