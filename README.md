ofxSerial
---------

Tiny extension to set options of ofSerial communication.
Tested with Arduino & FTDI driver on Mac OSX 10.11 with FTDI and Windows 10.


## Usage

```
ofxSerial serial;
ofApp::setup()
{
	serial.setup(YOUR_SERIAL_PORT, 9600);
	
	serial.setDataBits(OFXSERIAL_DATABIT_8);
	serial.setParity(OFXSERIAL_PARITY_ODD);
	serial.setStopBits(OFXSERIAL_STOPBIT_2);
}
```


## API

```
void ofxSerial::setParity(parity p)
void ofxSerial::setStopBits(stop_bits s)
void ofxSerial::setDataBits(data_bits d)
```

Available parameters are defined as follows.

```
OFXSERIAL_PARITY_NONE
OFXSERIAL_PARITY_EVEN
OFXSERIAL_PARITY_ODD
```

```
OFXSERIAL_STOPBIT_1
OFXSERIAL_STOPBIT_2
```

```
OFXSERIAL_DATABIT_8
OFXSERIAL_DATABIT_7
OFXSERIAL_DATABIT_6
OFXSERIAL_DATABIT_5
```

## Dependencies

none (ofSerial)


## License

MIT License

