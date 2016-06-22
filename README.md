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

## Installing the Libraries

Arduino IDE do not recognize libraries inside our projects, there is a specific place to put them.
To find it:
 - Open the IDE;
 - Go to Preferences on the menu;
 - Check the path in SketchBook Location.
Inside this path should be a folder called _libraries_. If it does not exist, create it. 

This is the correct place to put our libraries so the IDE can load it.
We can simply create a symbolic link to our project (the last parameter is the path to _libraries_ we saw before followed by the library folder name):
 ```ln -s /path/to/project/lib/MorseTalk/ ~/Documents/Arduino/libraries/MorseTalk```

## Using the IDE

After connecting the Arduino to the computer using the USB cable, you need to select the port for the IDE to use.

```Menu > Tools > Port > [arduino port]```

Port example: `/dev/cu.wchusbserial1410`
