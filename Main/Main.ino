#include "uKitExplore2En.h"

void izquierda() {
    setMotorTurnAdj(1,40,0xffff);
    setMotorTurnAdj(2,40,0xffff);
}

void parar() {
    setMotorTurnAdj(1,0,0xffff);
    setMotorTurnAdj(2,0,0xffff);
}

void derechaLinea() {
    setMotorTurnAdj(1,0,0xffff);
    setMotorTurnAdj(2,-30,0xffff);
}

void avanzar() {
    setMotorTurnAdj(1,40,0xffff);
    setMotorTurnAdj(2,-40,0xffff);
}

void izquierdaLinea() {
    setMotorTurnAdj(1,30,0xffff);
    setMotorTurnAdj(2,0,0xffff);
}

void atrasar() {
    setMotorTurnAdj(1,30,0xffff);
    setMotorTurnAdj(2,-30,0xffff);
}

void calibracion() {
    setServoAngle(13,0,1000);
    setServoAngle(14,0,1000);
    setServoAngle(15,0,1000);
    setServoAngle(16,0,1000);
    delay(1000);
}

void derecha() {
    setMotorTurnAdj(1,-40,0xffff);
    setMotorTurnAdj(2,-40,0xffff);
}

void bajar() {
    setServoAngle(14,-100,1000);
    setServoAngle(15,-100,1000);
    delay(1000);
}

void pararServos() {
    setServoStop(13);
    setServoStop(14);
    setServoStop(15);
    setServoStop(16);
}

void subir() {
    setServoAngle(14,100,1000);
    setServoAngle(15,100,1000);
    delay(1000);
}

void abrir() {
    setServoAngle(14,100,1000);
    setServoAngle(15,100,1000);
    delay(1000);
}

void cerrar() {
    setServoAngle(14,-100,1000);
    setServoAngle(15,-100,1000);
    delay(1000);
}

void seguidor() {
    while (true) {
        if (readGrayValue(4,0) && (readGrayValue(3,0) && readGrayValue(2,0))) {
            avanzar();

        } else if (readGrayValue(3,0) && !(readGrayValue(2,0) && readGrayValue(4,0))) {
            avanzar();
        } else if (!readGrayValue(3,0)) {
            if (readGrayValue(2,0) && readGrayValue(4,0)) {
                stop();

            } else if (readGrayValue(2,0)) {
                izquierda();
                delay(200);
            } else {
                derecha();
                delay(200);

            }
        }
    }
}

void setup() {
    Initialization();
}

void loop() {
    seguidor();


}
