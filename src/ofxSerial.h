#pragma once

#include "ofMain.h"

typedef enum parity {
	OFXSERIAL_PARITY_NONE,
	OFXSERIAL_PARITY_EVEN,
	OFXSERIAL_PARITY_ODD
} _parity;

typedef enum stop_bits {
	OFXSERIAL_STOPBIT_1,
	OFXSERIAL_STOPBIT_2
} _stop_bits;

typedef enum data_bits {
    OFXSERIAL_DATABIT_5 = 5,
    OFXSERIAL_DATABIT_6,
	OFXSERIAL_DATABIT_7,
    OFXSERIAL_DATABIT_8
} _data_bits;

class ofxSerial : public ofSerial
{
public:
	void setParity(parity p)
	{
#if defined( TARGET_OSX ) || defined( TARGET_LINUX )
        
        struct termios options;
        tcgetattr(fd, &oldoptions);
        options = oldoptions;
        
        switch (p)
        {
            case OFXSERIAL_PARITY_NONE:
                options.c_cflag &= ~PARENB;
                break;
                
            case OFXSERIAL_PARITY_EVEN:
                options.c_cflag |= PARENB;
                options.c_cflag &= ~PARODD;
                break;
                
            case OFXSERIAL_PARITY_ODD:
                options.c_cflag |= PARENB;
                options.c_cflag |= PARODD;
                break;
                
            default:
                options.c_cflag &= ~PARENB;
                break;
        }
        
        tcsetattr(fd, TCSANOW, &options);
        
#elif defined( TARGET_WIN32 )
        
        // now try the settings:
        COMMCONFIG cfg;
        DWORD cfgSize;
        WCHAR buf[80];
        
        cfgSize = sizeof(cfg);
        GetCommConfig(hComm, &cfg, &cfgSize);
        
        // get current COMMCONFIG
        if(!BuildCommDCBW(buf, &cfg.dcb)){
            ofLogError("ofxSerial") << "unable to build comm dcb, (" << buf << ")";
        }
        
        switch (p)
        {
            case OFXSERIAL_PARITY_NONE:
                cfg.dcb.fParity = FALSE;
                cfg.dcb.Parity = NOPARITY;
                break;
                
            case OFXSERIAL_PARITY_EVEN:
                cfg.dcb.fParity = TRUE;
                cfg.dcb.Parity = EVENPARITY;
                break;
                
            case OFXSERIAL_PARITY_ODD:
                cfg.dcb.fParity = TRUE;
                cfg.dcb.Parity = ODDPARITY;
                break;
                
            default:
                cfg.dcb.fParity = FALSE;
                cfg.dcb.Parity = NOPARITY;
                break;
        }
        
        // set new COMMCONFIG
        if(!SetCommState(hComm, &cfg.dcb)){
            ofLogError("ofxSerial") << "couldn't set comm state: " << cfg.dcb.BaudRate << " bps, xio " << cfg.dcb.fInX << "/" << cfg.dcb.fOutX;
        }
        
#else
        
        ofLogError("ofxSerial") << "not implemented in this platform";
        
#endif
	}
	
	void setStopBits(stop_bits s)
	{
#if defined( TARGET_OSX ) || defined( TARGET_LINUX )
        
		struct termios options;
		tcgetattr(fd, &oldoptions);
		options = oldoptions;
		
		switch (s)
		{
			case OFXSERIAL_STOPBIT_1:
				options.c_cflag &= ~CSTOPB;
				break;
				
			case OFXSERIAL_STOPBIT_2:
				options.c_cflag |= CSTOPB;
				break;
				
			default:
				options.c_cflag &= ~CSTOPB;
				break;
		}
		
		tcsetattr(fd, TCSANOW, &options);
        
#elif defined( TARGET_WIN32 )
        
        // now try the settings:
        COMMCONFIG cfg;
        DWORD cfgSize;
        WCHAR buf[80];
        
        cfgSize = sizeof(cfg);
        GetCommConfig(hComm, &cfg, &cfgSize);
        
        // get current COMMCONFIG
        if(!BuildCommDCBW(buf, &cfg.dcb)){
            ofLogError("ofxSerial") << "unable to build comm dcb, (" << buf << ")";
        }
        
        switch (s)
        {
            case OFXSERIAL_STOPBIT_1:
                cfg.dcb.StopBits = ONESTOPBIT;
                break;
                
            case OFXSERIAL_STOPBIT_2:
                cfg.dcb.StopBits = TWOSTOPBITS;
                break;
                
            default:
                cfg.dcb.StopBits = ONESTOPBIT;
                break;
        }
        
        // set new COMMCONFIG
        if(!SetCommState(hComm, &cfg.dcb)){
            ofLogError("ofxSerial") << "couldn't set comm state: " << cfg.dcb.BaudRate << " bps, xio " << cfg.dcb.fInX << "/" << cfg.dcb.fOutX;
        }
        
#else
        
        ofLogError("ofxSerial") << "not implemented in this platform";
        
#endif
	}
	
	void setDataBits(data_bits d)
	{
#if defined( TARGET_OSX ) || defined( TARGET_LINUX )

        struct termios options;
		tcgetattr(fd, &oldoptions);
		options = oldoptions;
		
		switch (d)
		{
			case OFXSERIAL_DATABIT_8:
				options.c_cflag &= ~CSIZE;
				options.c_cflag |= CS8;
				break;
				
			case OFXSERIAL_DATABIT_7:
				options.c_cflag |= CSIZE;
				options.c_cflag |= CS7;
				break;
				
			case OFXSERIAL_DATABIT_6:
				options.c_cflag |= CSIZE;
				options.c_cflag |= CS6;
				break;
				
			case OFXSERIAL_DATABIT_5:
				options.c_cflag |= CSIZE;
				options.c_cflag |= CS5;
				break;
				
			default:
				options.c_cflag &= ~CSIZE;
				options.c_cflag |= CS8;
				break;
		}
		
		tcsetattr(fd, TCSANOW, &options);
        
#elif defined( TARGET_WIN32 )
        
        // now try the settings:
        COMMCONFIG cfg;
        DWORD cfgSize;
        WCHAR buf[80];
        
        cfgSize = sizeof(cfg);
        GetCommConfig(hComm, &cfg, &cfgSize);
        
        // get current COMMCONFIG
        if(!BuildCommDCBW(buf, &cfg.dcb)){
            ofLogError("ofxSerial") << "unable to build comm dcb, (" << buf << ")";
        }
        
        cfg.dcb.ByteSize = d;
        
        // set new COMMCONFIG
        if(!SetCommState(hComm, &cfg.dcb)){
            ofLogError("ofxSerial") << "couldn't set comm state: " << cfg.dcb.BaudRate << " bps, xio " << cfg.dcb.fInX << "/" << cfg.dcb.fOutX;
        }
        
#else
        
        ofLogError("ofxSerial") << "not implemented in this platform";
        
#endif
	}
private:
	
};

