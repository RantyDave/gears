# A motorcycle gearbox actuator

Two 'push to close' switches are mounted on the handlebars to represent "change up" and "change down". The associated circuit pulls these low and attaches to a pair of digital inputs on an ATTiny based pseudo-arduino. A servo is provided a signal and actuates with the switches. There are two trim pots on the board, currently affecting "centre" and "amplitude".

As it stands this is extremely simplistic and I need to get a better voltage regulator from somewhere. I probably should've soldered in a supercap but didn't.
