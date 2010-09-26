/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package device;

import io.SerialInterface;
import main.ParametersSerial;

/**
 *
 * @author victor
 */
public class TraktanaDebug {

    public TraktanaDebug(ParametersSerial paramDevice, ParametersSerial paramDebug) {
        this.serialDevice = new SerialInterface(paramDevice);
        this.serialDebug = new SerialInterface(paramDebug);
        this.debugConnected = false;
        this.deviceConnected = false;
    }
    public boolean connectDevice(){
        deviceConnected = serialDevice.connect();
        return deviceConnected;
    }
    public boolean connectDebug(){
        debugConnected = serialDebug.connect();
        return debugConnected;
    }
    public void disconnectDevice(){
        deviceConnected = false;
        serialDevice.disconnect();
    }
    public void disconnectDebug(){
        debugConnected = false;
        serialDebug.disconnect();
    }
    public void sendCommand(String str){
        serialDevice.sendCommand(str);
    }
    public String receiveResponse(){
        return serialDevice.receiveResponse();
    }
    public void setSerialParametersDevice(ParametersSerial paramDevice){
        serialDevice.setParamConfig(paramDevice);
    }
    public void setSerialParametersDebug(ParametersSerial paramDebug){
        serialDebug.setParamConfig(paramDebug);
    }
    public void rotateStepper(long steps, double freq, boolean direction, int motor){

    }
    public void turnOnStepper(boolean on){

    }
    public void readSensor(int sensor){

    }
    public void readConfiguration(){
        
    }
    public void writeConfiguration(){

    }

    private SerialInterface serialDevice;
    private SerialInterface serialDebug;
    public boolean deviceConnected;
    public boolean debugConnected;
}