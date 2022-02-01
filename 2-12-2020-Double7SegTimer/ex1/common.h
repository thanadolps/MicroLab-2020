typedef u8 uint_8t; // 8bit unsigned

/// Mapping from number digital (up to 16) to 7 segment display (in hex)
const int HEX_DIGIT_7SEG[] ={
  0x3F,
  0x06,
  0x5B,
  0x4F,
  0x66,
  0x6D,
  0x7D,
  0x07,
  0x7F,
  0x6F,
  0x77,
  0x7C,
  0x39,
  0x5E,
  0x79,
  0x71
};

/// Represent Slave 7segment
class SevenSegment {
private:
  u8 pin;
  
public:
  SevenSegment(u8 data_pin) {
    this->pin = data_pin;
    pinMode(pin, OUTPUT);
  }

  /// display data to this 7segment
  /// bit_field: bit field represent state (on/off) of each segment in 7 segment 
  void emit(u8 bit_field) {
    SPI.transfer(bit_field);
  	digitalWrite(this->pin, HIGH);
  	digitalWrite(this->pin, LOW);
  }
  
  /// display hex digit to this 7segment
  /// hex_digit: hex number to be display, any number greater than 16 will be truncate
  void emit_hex_digit(u8 hex_digit) {
    this->emit(HEX_DIGIT_7SEG[hex_digit & 0b1111]);
  }
};

/// Represent 2legged arduino button
class Button {
private:
    u8 btn_pin;
    bool pressed;
public:
    Button(u8 btn_pin) {
        pinMode(btn_pin, INPUT);
        this->btn_pin = btn_pin;
        this->pressed = false;
    }

    /// is button is pressed at this moment (equivanlant to digitalRead)
    bool is_pressing() {
        return digitalRead(this->btn_pin) == LOW;
    }

    /// is the button starting to be pressed
    /// this will return true if and only if button is pressed now but previously isn't
    
    /// this function must be call frequency and regulary to be correct,
    /// since the internal state keeping track of button state only update in this function 
    bool is_newly_press() {
        bool is_pressing = this->is_pressing();
        if(!this->pressed) {
            // button not previsly press, update it
            this->pressed = is_pressing;
            return is_pressing;
        }
        else {
            this->pressed = is_pressing;
            return false;
        }
    }
};

/// display hexadecimal number [n] in 7segment [l] and [r]
/// [l] will be use as most significant digit (digit on the left when written)
/// [r] will be use as least significant digit (digit on the right when written)
/// number greater than 0xFF will be truncate
void hex_display(SevenSegment& l, SevenSegment& r, u8 n) {
  	r.emit_hex_digit(n);
    l.emit_hex_digit(n >> 4);
}


/// display decimal number [n] in 7segment [l] and [r]
/// [l] will be use as most significant digit (digit on the left when written)
/// [r] will be use as least significant digit (digit on the right when written)
/// number greater than 99 will be truncate
void dec_display(SevenSegment& l, SevenSegment& r, u8 n) {
    r.emit_hex_digit(n % 10);
    l.emit_hex_digit(n / 10);
}