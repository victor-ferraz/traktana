/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package main;

import gnu.io.SerialPort;

/**
 *
 * @author victor
 */
public class ParametersSerial {

    public ParametersSerial() {
        // default configuration
        this.PortName = "/dev/ttyS0";
        this.Baud = 9600;
        this.DataBits = SerialPort.DATABITS_8;
        this.FlowControl = SerialPort.FLOWCONTROL_NONE;
        this.Parity = SerialPort.PARITY_NONE;
        this.StopBits = SerialPort.STOPBITS_1;
    }

    public int getBaud() {
        return Baud;
    }

    public void setBaud(int Baud) {
        this.Baud = Baud;
    }

    public void setDataBits(int DataBits) {
        this.DataBits = DataBits;
    }

    public void setFlowControl(int FlowControl) {
        this.FlowControl = FlowControl;
    }

    public void setParity(int Parity) {
        this.Parity = Parity;
    }

    public void setPortName(String PortName) {
        this.PortName = PortName;
    }

    public void setStopBits(int StopBits) {
        this.StopBits = StopBits;
    }

    public int getDataBits() {
        return DataBits;
    }

    public int getFlowControl() {
        return FlowControl;
    }

    public int getParity() {
        return Parity;
    }

    public String getPortName() {
        return PortName;
    }

    public int getStopBits() {
        return StopBits;
    }

    private String PortName;
    private int Baud;
    private int DataBits;
    private int StopBits;
    private int FlowControl;
    private int Parity;
}
