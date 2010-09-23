/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package main;

/**
 *
 * @author victor
 */
public class ParametersConfig {

    public ParametersConfig() {
        serialConfigDevice = new ParametersSerial();
        serialConfigDebug = new ParametersSerial();
    }

    public ParametersSerial getSerialConfigDebug() {
        return serialConfigDebug;
    }

    public ParametersSerial getSerialConfigDevice() {
        return serialConfigDevice;
    }

    public void setSerialConfigDebug(ParametersSerial serialConfigDebug) {
        this.serialConfigDebug = serialConfigDebug;
    }

    public void setSerialConfigDevice(ParametersSerial serialConfigDevice) {
        this.serialConfigDevice = serialConfigDevice;
    }

    private ParametersSerial serialConfigDevice;
    private ParametersSerial serialConfigDebug;
}
