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
        serialconfig0 = new ParametersSerial();
        serialconfig1 = new ParametersSerial();
    }

    public void setSerialconfig0(ParametersSerial serialconfig0) {
        this.serialconfig0 = serialconfig0;
    }

    public void setSerialconfig1(ParametersSerial serialconfig1) {
        this.serialconfig1 = serialconfig1;
    }

    public ParametersSerial getSerialconfig0() {
        return serialconfig0;
    }

    public ParametersSerial getSerialconfig1() {
        return serialconfig1;
    }

    private ParametersSerial serialconfig0;
    private ParametersSerial serialconfig1;
}
