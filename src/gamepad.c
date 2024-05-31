#include <pigpio.h>
#include <iostream>
#include <linux/input.h>
#include <fcntl.h>
#include <unistd.h>

void handleGamepad() {
  while (true){
      if (gpioRead(Up) == 0) {
              struct input_event event;
              event.type = EV_KEY;
              event.code = B_UP;
              event.value = 1;
              write(fd, &event, sizeof(event));
              event.value = 0;
              write(fd, &event, sizeof(event));
          }
      if (gpioRead(Down) == 0) {
              struct input_event event;
              event.type = EV_KEY;
              event.code = B_DOWN;
              event.value = 1;
              write(fd, &event, sizeof(event));
              event.value = 0;
              write(fd, &event, sizeof(event));
          }
      if (gpioRead(Left) == 0) {
              struct input_event event;
              event.type = EV_KEY;
              event.code = B_LEFT;
              event.value = 1;
              write(fd, &event, sizeof(event));
              event.value = 0;
              write(fd, &event, sizeof(event));
          }
      if (gpioRead(Right) == 0) {
              struct input_event event;
              event.type = EV_KEY;
              event.code = B_RIGHT;
              event.value = 1;
              write(fd, &event, sizeof(event));
              event.value = 0;
              write(fd, &event, sizeof(event));
          }
      if (gpioRead(A) == 0) {
              struct input_event event;
              event.type = EV_KEY;
              event.code = B_A;
              event.value = 1;
              write(fd, &event, sizeof(event));
              event.value = 0;
              write(fd, &event, sizeof(event));
          }
      if (gpioRead(B) == 0) {
              struct input_event event;
              event.type = EV_KEY;
              event.code = B_B;
              event.value = 1;
              write(fd, &event, sizeof(event));
              event.value = 0;
              write(fd, &event, sizeof(event));
          }
      if (gpioRead(X) == 0) {
              struct input_event event;
              event.type = EV_KEY;
              event.code = B_X;
              event.value = 1;
              write(fd, &event, sizeof(event));
              event.value = 0;
              write(fd, &event, sizeof(event));
          }
      if (gpioRead(Y) == 0) {
              struct input_event event;
              event.type = EV_KEY;
              event.code = B_Y;
              event.value = 1;
              write(fd, &event, sizeof(event));
              event.value = 0;
              write(fd, &event, sizeof(event));
          }
      if (gpioRead(L) == 0) {
              struct input_event event;
              event.type = EV_KEY;
              event.code = B_L;
              event.value = 1;
              write(fd, &event, sizeof(event));
              event.value = 0;
              write(fd, &event, sizeof(event));
          }
      if (gpioRead(R) == 0) {
              struct input_event event;
              event.type = EV_KEY;
              event.code = B_R;
              event.value = 1;
              write(fd, &event, sizeof(event));
              event.value = 0;
              write(fd, &event, sizeof(event));
          }
      if (gpioRead(Start) == 0) {
              struct input_event event;
              event.type = EV_KEY;
              event.code = B_STR;
              event.value = 1;
              write(fd, &event, sizeof(event));
              event.value = 0;
              write(fd, &event, sizeof(event));
          }
      if (gpioRead(Select) == 0) {
              struct input_event event;
              event.type = EV_KEY;
              event.code = B_SLC;
              event.value = 1;
              write(fd, &event, sizeof(event));
              event.value = 0;
              write(fd, &event, sizeof(event));
          }
  }
}
void handlePWR() {
  int countTime = 0;
  while (true){
    if (!Pwr) {
            system("sudo shutdown -h now");
            gpioTerminate();
            i2cClose(i2cHandle);
            Pwr = !Pwr;
        } 
    
  }
}
void handleStandby() {
  bool StandbyStatus = false;
  while (true) {
        if (gpioRead(Standby) == 0) {
            if (!StandbyStatus) {
                system("sudo systemctl suspend");
                StandbyStatus = true;
            }
        } else {
            if (StandbyStatus) {
                
                system("sudo systemctl resume");
                StandbyStatus = false;
            }
        }
        gpioDelay(300000);
  }
}
void initgpio() {
  //gpioSetMode(GPIO6, PI_OUTPUT);
  gpioSetMode(VolUp, PI_INPUTPULLUP);
  gpioSetMode(VolDown, PI_INPUTPULLUP);
  gpioSetMode(Pwr, PI_INPUTPULLUP);
  gpioSetMode(Standby, PI_INPUTPULLUP);
  gpioSetMode(GPIO22, PI_INPUTPULLUP);
  gpioSetMode(GPIO23, PI_INPUTPULLUP);
  gpioSetMode(GPIO24, PI_INPUTPULLUP);
  gpioSetMode(GPIO25, PI_INPUTPULLUP);
  gpioSetMode(GPIO26, PI_INPUTPULLUP);
  gpioSetMode(GPIO27, PI_INPUTPULLUP);
  gpioInitialise()
  int fd = open("/dev/input/event1", O_RDWR);
  while (true) {
    if (fd == -1) {
        system("sudo ./../SH/GPIO6_ON.sh");
    } else {
        system("sudo ./../SH/GPIO6_OFF.sh")
        break;
    }
  }
  
}
void handleVolume() {
  while (true) {
    if (gpioRead(VolUp) == 0) {
              struct input_event event;
              event.type = EV_KEY;
              event.code = B_VOLUP;
              event.value = 1;
              write(fd, &event, sizeof(event));
              event.value = 0;
              write(fd, &event, sizeof(event));
          }
    if (gpioRead(VolDown) == 0) {
              struct input_event event;
              event.type = EV_KEY;
              event.code = B_VOLDOWN;
              event.value = 1;
              write(fd, &event, sizeof(event));
              event.value = 0;
              write(fd, &event, sizeof(event));
          }
  }
}