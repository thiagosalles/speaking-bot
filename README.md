# speaking-robot
Source code for a robot made with Arduino that speaks using morse code language

## Installing the IDE

You can download and install the IDE from arduino.cc: https://www.arduino.cc/en/Main/Software

Or using Homebrew on Mac:

```brew cask install Caskroom/cask/arduino```

If you don't have Homebrew: http://brew.sh

## Installing the Driver

If you are using a Arduino clone that uses the USB controler CH340G, you need to install the drivers:

- [Driver for Mac](drivers/CH34x_Install.zip)

## Using the IDE

After connecting the Arduino to the computer using the USB cable, you need to select the port for the IDE to use.

```Menu > Tools > Port > [arduino port]```

Port example: `/dev/cu.wchusbserial1410`
